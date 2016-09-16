#include <MailCore/MCAsync.h>

extern "C" {
	#include "CIMAPFolderStatusOperation.h"

	CIMAPFolderStatusOperation wrapCIMAPFolderStatusOperation(ref operationRef){
	    CIMAPFolderStatusOperation operation;
	    operation.self = operationRef;
	    return operation;
	}

	void deleteCIMAPFolderStatusOperation(CIMAPFolderStatusOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPFolderStatusOperation *>(operation.self);
	}
}
