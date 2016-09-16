#include <MailCore/MCAsync.h>

extern "C" {
	#include "CIMAPFetchMessagesOperation.h"

	CIMAPFetchMessagesOperation wrapCIMAPFetchMessagesOperation(ref operationRef){
	    CIMAPFetchMessagesOperation operation;
	    operation.self = operationRef;
	    return operation;
	}

	void deleteCIMAPFetchMessagesOperation(CIMAPFetchMessagesOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPFetchMessagesOperation *>(operation.self);
	}
}
