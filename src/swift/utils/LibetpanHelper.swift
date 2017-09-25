//
//  LibetpanHelper.swift
//  mailcore2
//
//  Created by Andrew on 9/25/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation
import CMailCore

public class LibetpanHelper {
    
    public class func date(fromRFC2822String string: String?) -> Date? {
        guard let string = string else {
            return nil
        }
        
        return string.withCString({ cString in
            let env_date = UnsafeMutablePointer<Int8>.init(mutating: cString)
            
            // next code copied from MCOMessageHeader::importIMAPEnvelope(struct mailimap_envelope * env)
            var date_time: UnsafeMutablePointer<mailimf_date_time>?
            var cur_token: size_t = 0
            var r: Int = Int(mailimf_date_time_parse(env_date, Int(strlen(env_date)), &cur_token, &date_time))
            var timestamp: time_t
            if r == MAILIMF_NO_ERROR {
                timestamp = MailCoreTimestampFromDate(date_time)
                mailimf_date_time_free(date_time)
            }
            else {
                var imap_date: UnsafeMutablePointer<mailimap_date_time>?
                r = Int(mailimap_hack_date_time_parse(env_date, &imap_date, 0, nil))
                if r == MAILIMAP_NO_ERROR {
                    timestamp = MailCoreTimestampFromIMAPDate(imap_date)
                    mailimap_date_time_free(imap_date)
                }
                else {
                    return nil
                }
            }
            return Date(timeIntervalSince1970: Double(timestamp))
        })
    }

}

