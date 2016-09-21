#include "CIMAPAppendMessageOperation.h"
#include "CIMAPAppendMessageOperation+Private.h"

extern "C" CIMAPAppendMessageOperation newIMAPAppendMessageOperation(mailcore::IMAPAppendMessageOperation *op){
    CIMAPAppendMessageOperation operation;
    operation.self = reinterpret_cast<void *>(op);
    return operation;
}

extern "C" void deleteIMAPAppendMessageOperation(CIMAPAppendMessageOperation operation) {
	    delete reinterpret_cast<mailcore::IMAPAppendMessageOperation *>(operation.self);
}
