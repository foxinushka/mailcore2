import Foundation
import Glibc

class ImapNamespace {
	
	var ref:CIMAPNamespace;

	init() {
 		self.ref = newCIMAPNamespace();
	}

	deinit {
		deleteCIMAPNamespace(ref);
	}
}