#include "СIMAPSearchOperation.h"
#include "СIMAPSearchOperation+Private.h"

extern "C" {
    CIMAPSearchOperation newCIMAPSearchOperation(mailcore::IMAPSearchOperation *op) {
	    CIMAPSearchOperation operation;
	    operation.self = reinterpret_cast<void *>(op);
	    return operation;
	}

	void deleteCIMAPSearchOperation(CIMAPSearchOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPSearchOperation *>(operation.self);
	}
}
