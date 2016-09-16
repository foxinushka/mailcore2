#include <MailCore/MCAsync.h>

extern "C" {
	#include "СIMAPSearchOperation.h"

	CIMAPSearchOperation wrapCIMAPSearchOperation(ref operationRef){
	    CIMAPSearchOperation operation;
	    operation.self = operationRef;
	    return operation;
	}

	void deleteCIMAPSearchOperation(CIMAPSearchOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPSearchOperation *>(operation.self);
	}
}
