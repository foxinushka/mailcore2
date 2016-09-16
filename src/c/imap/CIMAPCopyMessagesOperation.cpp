#include <MailCore/MCAsync.h>

extern "C" {
	#include "CIMAPCopyMessagesOperation.h"

	CIMAPCopyMessagesOperation wrapCIMAPCopyMessagesOperation(ref operationRef){
	    CIMAPCopyMessagesOperation operation;
	    operation.self = operationRef;
	    return operation;
	}

	void deleteCIMAPCopyMessagesOperation(CIMAPCopyMessagesOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPCopyMessagesOperation *>(operation.self);
	}
}
