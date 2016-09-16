#include <MailCore/MCAsync.h>

extern "C" {
	#include "CIMAPFolderInfoOperation.h"

	CIMAPFolderInfoOperation wrapCIMAPFolderInfoOperation(ref operationRef){
	    CIMAPFolderInfoOperation operation;
	    operation.self = operationRef;
	    return operation;
	}

	void deleteCIMAPFolderInfoOperation(CIMAPFolderInfoOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPFolderInfoOperation *>(operation.self);
	}
}
