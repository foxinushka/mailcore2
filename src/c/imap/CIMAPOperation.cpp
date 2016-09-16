#include <MailCore/MCAsync.h>

extern "C" {
	#include "CIMAPOperation.h"

	CIMAPOperation wrapIMAPOperation(ref operationRef) {
	    CIMAPOperation operation;
	    operation.self = operationRef;
	    return operation;
	}

	void deleteCIMAPOperation(CIMAPOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPOperation *>(operation.self);
	}
}
