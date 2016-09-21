#include "CIMAPFetchContentOperation.h"
#include "CIMAPFetchContentOperation+Private.h"

extern "C" CIMAPFetchContentOperation newCIMAPFetchContentOperation(mailcore::IMAPFetchContentOperation *operationRef){
    CIMAPFetchContentOperation operation;
    operation.self = reinterpret_cast<void *>(operationRef);
    return operation;
}

extern "C" void deleteCIMAPFetchContentOperation(CIMAPFetchContentOperation operation) {
    delete reinterpret_cast<mailcore::IMAPFetchContentOperation *>(operation.self);
}
