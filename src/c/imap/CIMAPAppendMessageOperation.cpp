#include <MailCore/MCAsync.h>

extern "C" {
	#include "CIMAPAppendMessageOperation.h"

	CIMAPAppendMessageOperation wrapIMAPAppendMessageOperation(ref operationRef){
	    CIMAPAppendMessageOperation operation;
	    operation.self = operationRef;
	    return operation;
	}

	void deleteIMAPAppendMessageOperation(CIMAPAppendMessageOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPAppendMessageOperation *>(operation.self);
	}
}
