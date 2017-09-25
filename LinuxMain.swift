// Generated using Sourcery 0.5.9 — https://github.com/krzysztofzablocki/Sourcery
// DO NOT EDIT
import XCTest

@testable import MailCoreTests


extension unittest {
  static var allTests = [
    ("testMessageBuilder1", testMessageBuilder1),
    ("testMessageBuilder2", testMessageBuilder2),
    ("testMessageBuilder3", testMessageBuilder3),
    ("testMessageParser", testMessageParser), // FAILED
    ("testSummary", testSummary), // FAILED
    ("testCharsetDetection", testCharsetDetection),
    ("testMUTF7", testMUTF7),
    ("testIMAP", testIMAP),
    ("testSMTP", testSMTP),
  ]
}

extension LibetpanHelperTests {
  static var allTests = [
    ("testDates", testDates)
  ]
}

XCTMain([
  testCase(unittest.allTests),
  testCase(LibetpanHelperTests.allTests),
])
