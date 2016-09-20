import Foundation

#if os(iOS) || os(OSX)
    import CMailCore
#endif

class ImapNamespace {
	
	var ref:CIMAPNamespace;

	init() {
 		self.ref = newCIMAPNamespace();
	}

	deinit {
		deleteCIMAPNamespace(ref);
	}
}