import Foundation

open class XCTestCase {

    /*!
     * @property testCaseCount
     * Number of test cases. Must be overridden by subclasses.
     */
    //open var testCaseCount: UInt { get }

    
    /*!
     * @property name
     * Test's name. Must be overridden by subclasses.
     */
    //open var name: String? { get }

    
    /*!
     * @property testRunClass
     * The XCTestRun subclass that will be instantiated when the test is run to hold
     * the test's results. Must be overridden by subclasses.
     */
    //open var testRunClass: Swift.AnyClass? { get }

    
    /*!
     * @property testRun
     * The test run object that executed the test, an instance of testRunClass. If the test has not yet been run, this will be nil.
     */
    //open var testRun: XCTestRun? { get }

    
    /*!
     * @method -performTest:
     * The method through which tests are executed. Must be overridden by subclasses.
     */
    open func perform(_ run: Any){

    }

    
    /*!
     * @method -runTest
     * Creates an instance of the testRunClass and passes it as a parameter to -performTest:.
     */
    open func run() {

    }

    
    /*!
     * @method -setUp
     * Setup method called before the invocation of each test method in the class.
     */
    open func setUp() {

    }

    
    /*!
     * @method -tearDown
     * Teardown method called after the invocation of each test method in the class.
     */
    open func tearDown() {

    }

    
    /*!
     * @method -initWithInvocation:
     */
    public init(invocation: Any?) {

    }

    
    /*!
     * @method -initWithSelector:
     */
    public init(selector: Any) {

    }

    
    /*!
     * @property invocation
     * The invocation used when this test is run.
     */
    open var invocation: Any?

    
    /*!
     * @method -invokeTest
     * Invoking a test performs its setUp, invocation, and tearDown. In general this
     * should not be called directly.
     */
    open func invokeTest() {

    }

    
    /*!
     * @property continueAfterFailure
     * The test case behavior after a failure. Defaults to YES.
     */
    //open var continueAfterFailure: Bool

    
    /*!
     * @method -recordFailureWithDescription:inFile:atLine:expected:
     * Records a failure in the execution of the test and is used by all test assertions.
     *
     * @param description The description of the failure being reported.
     *
     * @param filePath The file path to the source file where the failure being reported
     * was encountered.
     *
     * @param lineNumber The line number in the source file at filePath where the
     * failure being reported was encountered.
     *
     * @param expected YES if the failure being reported was the result of a failed assertion,
     * NO if it was the result of an uncaught exception.
     *
     */
    open func recordFailure(withDescription description: String, inFile filePath: String, atLine lineNumber: UInt, expected: Bool) {

    }

    
    /*!
     * @method +testInvocations
     * Invocations for each test method in the test case.
     */
    // open class func testInvocations() -> [Any] {

    // }

    
    /*!
     * @const XCTPerformanceMetric_WallClockTime
     * Records wall clock time in seconds between startMeasuring/stopMeasuring.
     */
    
    /*!
     * @method +defaultPerformanceMetrics
     * The names of the performance metrics to measure when invoking -measureBlock:. Returns XCTPerformanceMetric_WallClockTime by default. Subclasses can override this to change the behavior of -measureBlock:
     */
    // open class func defaultPerformanceMetrics() -> [String] {

    // }

    
    /*!
     * @method -measureBlock:
     *
     * Call from a test method to measure resources (+defaultPerformanceMetrics) used by the
     * block in the current process.
    
        - (void)testPerformanceOfMyFunction {
    
                [self measureBlock:^{
                // Do that thing you want to measure.
                MyFunction();
            }];
        }
    
     * @param block A block whose performance to measure.
     */
    open func measure(_ block: @escaping () -> Swift.Void) {

    }

    
    /*!
     * @method -measureMetrics:automaticallyStartMeasuring:forBlock:
     *
     * Call from a test method to measure resources (XCTPerformanceMetrics) used by the
     * block in the current process. Each metric will be measured across calls to the block.
     * The number of times the block will be called is undefined and may change in the
     * future. For one example of why, as long as the requested performance metrics do
     * not interfere with each other the API will measure all metrics across the same
     * calls to the block. If the performance metrics may interfere the API will measure
     * them separately.
     
        - (void)testMyFunction2_WallClockTime {
            [self measureMetrics:[[self class] defaultPerformanceMetrics] automaticallyStartMeasuring:NO forBlock:^{
    
                // Do setup work that needs to be done for every iteration but you don't want to measure before the call to -startMeasuring
                SetupSomething();
                [self startMeasuring];
    
                // Do that thing you want to measure.
                MyFunction();
                [self stopMeasuring];
    
                // Do teardown work that needs to be done for every iteration but you don't want to measure after the call to -stopMeasuring
                TeardownSomething();
            }];
        }
    
     * Caveats:
     * • If YES was passed for automaticallyStartMeasuring and -startMeasuring is called
     *      anyway, the test will fail.
     * • If NO was passed for automaticallyStartMeasuring then -startMeasuring must be
     *      called once and only once before the end of the block or the test will fail.
     * • If -stopMeasuring is called multiple times during the block the test will fail.
     *
     * @param metrics An array of NSStrings (XCTPerformanceMetrics) to measure. Providing an unrecognized string is a test failure.
     *
     * @param automaticallyStartMeasuring If NO, XCTestCase will not take any measurements until -startMeasuring is called.
     *
     * @param block A block whose performance to measure.
     */
    open func measureMetrics(_ metrics: [String], automaticallyStartMeasuring: Bool, for block: @escaping () -> Swift.Void) {

    }

    
    /*!
     * @method -startMeasuring
     * Call this from within a measure block to set the beginning of the critical section.
     * Measurement of metrics will start at this point.
     */
    open func startMeasuring() {

    }

    
    /*!
     * @method -stopMeasuring
     * Call this from within a measure block to set the ending of the critical section.
     * Measurement of metrics will stop at this point.
     */
    open func stopMeasuring() {

    }

    
    /*! Adds a handler to the current context. Returns a token that can be used to unregister the handler. Handlers are invoked in the reverse order in which they are added until one of the handlers returns true, indicating that it has handled the alert.
     @param handlerDescription Explanation of the behavior and purpose of this handler, mainly used for debugging and analysis.
     @param handler Handler block for asynchronous UI such as alerts and other dialogs. Handlers should return true if they handled the UI, false if they did not. The handler is passed an XCUIElement representing the top level UI element for the alert.
     */
    // open func addUIInterruptionMonitor(withDescription handlerDescription: String, handler: @escaping (Any) -> Bool) -> Any {

    // }

    
    /*! Removes a handler using the token provided when it was added. */
    open func removeUIInterruptionMonitor(_ monitor: Any) {
        
    }


    public init() {

    }
}