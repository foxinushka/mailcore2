import Foundation
import Glibc

class ImapSearchExpression {
	
	var ref:СIMAPSearchExpression;

	init() {
 		self.ref = searchAll();
	}

	deinit {
		deleteСIMAPSearchExpression(ref);
	}
}
