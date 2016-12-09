//
//  unittest.swift
//  mailcore2
//
//  Created by Andrew on 12/5/16.
//  Copyright © 2016 MailCore. All rights reserved.
//

#if os(Android)
// We use own XCTestCase for Android
import Foundation
import SwiftMailCore
#else
import XCTest
@testable import SwiftMailCore
#endif

class SwiftMailCoreTest : XCTestCase {
    
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
        _mainPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("data")
        _builderPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("builder/input")
        _builderOutputPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("builder/output")
        _parserPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("parser/input")
        _parserOutputPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("parser/output")
        _charsetDetectionPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("charset-detection")
        _summaryDetectionPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("summary/input")
        _summaryDetectionOutputPath = Bundle.init(for: SwiftMailCoreTest.self).resourceURL?.appendingPathComponent("summary/output")
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testExample() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
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
        var builder = MessageBuilder()
        builder.header.to = [Address.addressWithRFC822String(RFC822String: "Foo Bar <dinh.viet.hoa@gmail.com>")!]
        builder.header.messageID = "MyMessageID123@mail.gmail.com"
        builder.htmlBody = "<html><body>This is a HTML content</body></html>"
        var path = _builderOutputPath?.appendingPathComponent("builder1.eml")
    }
    
    func testIMAP(){
        let session = IMAPSession();
        session.username = "adruk@readdle.com"
        session.password = ""
        session.hostname = "imap.gmail.com"
        session.port = 993
        session.connectionType = ConnectionType.init(rawValue: 1 << 2)
        
        var checkOp: IMAPCheckAccountOperation? = session.checkAccountOperation()
        var foldersOp: IMAPFetchFoldersOperation?
        
        checkOp?.start(completionBlock: { err in
            print("check account done")
            if err != nil {
                print("Oh crap, an error ", err!.localizedDescription)
            }
            else {
                print("CONNECTED")
                print("fetch all folders")
                foldersOp = session.fetchAllFoldersOperation()
                foldersOp?.start(completionBlock: { err, folders in
                    if err != nil {
                        print("Oh crap, an error ", err!.localizedDescription)
                    }
                    else {
                        print("folders", folders?.map({ $0.path }) ?? "nil")
                    }
                })
            }
        })
        
        RunLoop.current.run(until: Date().addingTimeInterval(30))
        
        checkOp = nil
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
        let session = SMTPSession()
        session.username = "adruk@readdle.com"
        session.password = ""
        session.hostname = "smtp.gmail.com"
        session.port = 465
        session.connectionType = ConnectionType.init(rawValue: 1 << 2)
        
        var loginOp: SMTPOperation? = session.loginOperation()
        var sendOp: SMTPSendOperation?
        loginOp!.start(completionBlock: { err in
            if err != nil {
                print("Oh crap, an error ", err!.localizedDescription)
            }
            else {
                print("CONNECTED")
                
                sendOp = session.sendOperationWithData(messageData: "Hello".data(using: .utf8)!, from: Address.addressWithMailbox(mailbox: "adruk@readdle.com")!, recipients: [Address.addressWithMailbox(mailbox: "adruk@readdle.com")!])
                
                sendOp!.start(completionBlock: { err in
                    if err != nil {
                        print("Oh crap, an error ", err!.localizedDescription)
                    }
                    else {
                        print("COMPLETED")
                    }
                })
            }
        })
        
        RunLoop.current.run(until: Date().addingTimeInterval(30))
        
        loginOp = nil
        sendOp = nil
        
    }
    
    
    func testPerformanceExample() {
        // This is an example of a performance test case.
        self.measure {
            // Put the code you want to measure the time of here.
        }
    }
    
}
