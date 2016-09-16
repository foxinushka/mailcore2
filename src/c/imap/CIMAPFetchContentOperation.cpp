#include <MailCore/MCAsync.h>

extern "C" {
	#include "CIMAPFetchContentOperation.h"

	CIMAPFetchContentOperation wrapCIMAPFetchContentOperation(ref operationRef){
	    CIMAPFetchContentOperation operation;
	    operation.self = operationRef;
	    return operation;
	}

	void deleteCIMAPFetchContentOperation(CIMAPFetchContentOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPFetchContentOperation *>(operation.self);
	}
}
