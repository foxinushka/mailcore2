import Foundation

//#if os(iOS) || os(OSX)
//    import CMailCore
//#endif

class ImapSearchExpression {
	
	var ref:СIMAPSearchExpression;

	init() {
 		self.ref = searchAll();
	}

	deinit {
		deleteСIMAPSearchExpression(ref);
	}
}
