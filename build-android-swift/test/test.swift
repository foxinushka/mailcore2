import Foundation

@_silgen_name("main")
public func testSwiftMailCore() -> Int {
    let test = SwiftMailCoreTest()
    
    test.setUp()
    test.testIMAP()
    test.tearDown()

    test.setUp()
    test.testSMTP()
    test.tearDown()

    return 0;
}