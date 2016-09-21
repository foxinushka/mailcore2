#include "CIMAPFetchMessagesOperation.h"
#include "CIMAPFetchMessagesOperation+Private.h"

extern "C" CIMAPFetchMessagesOperation newCIMAPFetchMessagesOperation(mailcore::IMAPFetchMessagesOperation *operationRef){
    CIMAPFetchMessagesOperation operation;
    operation.self = reinterpret_cast<void *>(operationRef);
    return operation;
}

extern "C" void deleteCIMAPFetchMessagesOperation(CIMAPFetchMessagesOperation operation) {
    delete reinterpret_cast<mailcore::IMAPFetchMessagesOperation *>(operation.self);
}
