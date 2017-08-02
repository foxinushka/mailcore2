//
//  RSMLibetpanHelper.m
//  SmartMail
//
//  Created by Viktor Gedzenko on 1/27/15.
//  Copyright (c) 2015 Readdle. All rights reserved.
//

#import "RSMLibetpanHelper.h"
#include "MCLibetpan.h"
#include <libetpan/libetpan.h>

@implementation LibetpanHelper

extern "C" {
    extern int mailimap_hack_date_time_parse(char * str,
                                             struct mailimap_date_time ** result,
                                             size_t progr_rate,
                                             progress_function * progr_fun);
}

+ (NSDate *)dateFromRFC2822String:(NSString *)string {
    if (string == nil) {
        return nil;
    }
    
    const char *env_date = [string UTF8String];
    
    // next code copied from MCOMessageHeader::importIMAPEnvelope(struct mailimap_envelope * env)
    struct mailimf_date_time * date_time;
    size_t cur_token = 0;
    int r = mailimf_date_time_parse(env_date, strlen(env_date), &cur_token, &date_time);

    time_t timestamp;
    if (r == MAILIMF_NO_ERROR) {
        timestamp = mailcore::timestampFromDate(date_time);
        mailimf_date_time_free(date_time);
    }
    else {
        struct mailimap_date_time * imap_date;
        r = mailimap_hack_date_time_parse((char *)env_date, &imap_date, 0, NULL);
        if (r == MAILIMAP_NO_ERROR) {
            timestamp = mailcore::timestampFromIMAPDate(imap_date);
            mailimap_date_time_free(imap_date);
        }
        else {
            return nil;
        }
    }
    
    return [NSDate dateWithTimeIntervalSince1970:timestamp];
}

@end
