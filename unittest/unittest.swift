//
//  unittest.swift
//  mailcore2
//
//  Created by Andrew on 12/5/16.
//  Copyright © 2016 MailCore. All rights reserved.
//

import Foundation
import Dispatch
import XCTest

import MailCore

#if os(Android)
    import CMailCore
    import CDispatch
#endif

fileprivate let TEST_EMAIL = "comscams@gmail.com"
fileprivate let TEST_PASSWORD = "l4 d3 e2 r1"

class unittest : XCTestCase {
    
    var _mainPath: URL?
    var _builderPath: URL?
    var _parserPath: URL?
    var _builderOutputPath: URL?
    var _parserOutputPath: URL?
    var _charsetDetectionPath: URL?
    var _summaryDetectionPath: URL?
    var _summaryDetectionOutputPath: URL?
    
    override func setUp() {
        super.setUp()
        // _mainPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("data")
        // _builderPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("builder/input")
        // _builderOutputPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("builder/output")
        // _parserPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("parser/input")
        // _parserOutputPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("parser/output")
        // _charsetDetectionPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("charset-detection")
        // _summaryDetectionPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("summary/input")
        // _summaryDetectionOutputPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("summary/output")
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testMessageBuilder1() {
//        MCOMessageBuilder * builder = [[MCOMessageBuilder alloc] init];
//        [[builder header] setFrom:[MCOAddress addressWithRFC822String:@"Hoà <dinh.viet.hoa@gmail.com>"]];
//        [[builder header] setTo:@[[MCOAddress addressWithRFC822String:@"Foo Bar <dinh.viet.hoa@gmail.com>"]]];
//        [[builder header] setSubject:@"testMessageBuilder1"];
//        [[builder header] setDate:[NSDate dateWithTimeIntervalSinceReferenceDate:0]];
//        [[builder header] setMessageID:@"MyMessageID123@mail.gmail.com"];
//        [builder setHTMLBody:@"<html><body>This is a HTML content</body></html>"];
//        NSString * path = [_builderOutputPath stringByAppendingPathComponent:@"builder1.eml"];
//        NSData * expectedData = [NSData dataWithContentsOfFile:path];
//        [builder _setBoundaries:@[@"1", @"2", @"3", @"4", @"5"]];
//        XCTAssertEqualObjects([[NSString alloc] initWithData:[builder data] encoding:NSUTF8StringEncoding], [[NSString alloc] initWithData:expectedData encoding:NSUTF8StringEncoding], @"Pass");
        
        var builder = MCOMessageBuilder()
        builder.header.to = MCOAddress.addressesWithRFC822String(string: "Foo Bar <dinh.viet.hoa@gmail.com>")
        builder.header.messageID = "MyMessageID123@mail.gmail.com"
        builder.htmlBody = "<html><body>This is a HTML content</body></html>"
        var path = _builderOutputPath?.appendingPathComponent("builder1.eml")
    }
    
    func testIMAP(){
        let queue = DispatchQueue.global()
        let semaphore = DispatchSemaphore(value: 0)
        
        let session = MCOIMAPSession();
        session.username = TEST_EMAIL
        session.password = TEST_PASSWORD
        session.hostname = "imap.gmail.com"
        session.port = 993
        session.connectionType = ConnectionType(rawValue: 1 << 2)
        session.dispatchQueue = queue
        
        session.checkAccountOperation().start(completionBlock: { err in
            if err != nil {
                XCTFail(err!.localizedDescription)
                semaphore.signal()
            }
            else {
                session.fetchAllFoldersOperation().start(completionBlock: { err, folders in
                    if err != nil {
                        XCTFail(err!.localizedDescription)
                    }
                    else {
                        print("folders \(folders!.map({ $0.path }))")
                    }
                    semaphore.signal()
                })
            }
        })
        semaphore.wait()
    }
    
//    func testAllWrappersIntegrity(){
//        let session = IMAPSession();
//        testMailcoreObjectWrapperIntegrity(session.session)
//        testMailcoreObjectWrapperIntegrity(session.fetchSubscribedFoldersOperation().nativeInstance)
//        testMailcoreObjectWrapperIntegrity(session.renameFolderOperation(folder: "", otherName: "").nativeInstance)
//        testMailcoreObjectWrapperIntegrity(session.disconnectOperation().nativeInstance)
//        testMailcoreObjectWrapperIntegrity(session.connectOperation().nativeInstance)
//        testMailcoreObjectWrapperIntegrity(session.noopOperation().nativeInstance)
//        testMailcoreObjectWrapperIntegrity(session.checkAccountOperation().nativeInstance)
//        testMailcoreObjectWrapperIntegrity(session.capabilityOperation().nativeInstance)
//        testMailcoreObjectWrapperIntegrity(session.quotaOperation().nativeInstance)
//        testMailcoreObjectWrapperIntegrity(session.fetchAllFoldersOperation().nativeInstance)
//        testMailcoreObjectWrapperIntegrity(session.expungeOperation(folder: "").nativeInstance)
//    }
//    
//    func testMailcoreObjectWrapperIntegrity(_ objOptional: Any?) {
//        if let obj = objOptional {
//            // Create a Mirror
//            let mirror = Mirror(reflecting: obj)
//            XCTAssertEqual(mirror.displayStyle, Mirror.DisplayStyle.struct)
//            
//            for case let (label?, anyValue) in mirror.children {
//                if label == "instance" || label == "_callback" {
//                    continue
//                }
//                // anyValue is Builtin.RawPointer, that's why is never 'nil'
////                let describingValue = String(describing: anyValue);
////                print(describingValue, "\(Mirror(reflecting: anyValue))")
////                XCTAssert(describingValue != "nil", "\(label) is nil!")
//                var opt: Any? = anyValue
//                print(opt ?? "((((((nil)")
//            }
//        }
//    }
    
    func testSMTP() {
        let queue = DispatchQueue.global()
        let semaphore = DispatchSemaphore(value: 0)
        
        let session = MCOSMTPSession()
        session.username = TEST_EMAIL
        session.password = TEST_PASSWORD
        session.hostname = "smtp.gmail.com"
        session.port = 465
        session.connectionType = ConnectionType(rawValue: 1 << 2)
        session.dispatchQueue = queue
        
        session.loginOperation().start(completionBlock: { err in
            if err != nil {
                XCTFail(err!.localizedDescription)
                semaphore.signal()
            }
            else {
                session.sendOperationWithData(messageData: "Hello".data(using: .utf8)!,
                                              from: MCOAddress(mailbox: TEST_EMAIL)!,
                                              recipients: [MCOAddress(mailbox: TEST_EMAIL)!])
                    .start(completionBlock: { err in
                        if err != nil {
                            XCTFail(err!.localizedDescription)
                            semaphore.signal()
                        }
                        else {
                            semaphore.signal()
                        }
                })
            }
        })
        
        semaphore.wait()
    }
    
}
