#include "CIMAPOperation.h"
#include "CIMAPOperation+Private.h"

extern "C" CIMAPOperation newIMAPOperation(mailcore::IMAPOperation *operationRef) {
    CIMAPOperation operation;
    operation.self = reinterpret_cast<void *>(operationRef);
    return operation;
}

extern "C" void deleteCIMAPOperation(CIMAPOperation operation) {
        delete reinterpret_cast<mailcore::IMAPOperation *>(operation.self);
}

