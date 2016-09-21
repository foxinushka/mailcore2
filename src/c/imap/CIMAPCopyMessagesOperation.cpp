#include "CIMAPCopyMessagesOperation.h"
#include "CIMAPCopyMessagesOperation+Private.h"

extern "C" CIMAPCopyMessagesOperation newCIMAPCopyMessagesOperation(mailcore::IMAPCopyMessagesOperation *ref){
    CIMAPCopyMessagesOperation operation;
    operation.self = reinterpret_cast<void *>(ref);
    return operation;
}

extern "C" void deleteCIMAPCopyMessagesOperation(CIMAPCopyMessagesOperation operation) {
    delete reinterpret_cast<mailcore::IMAPCopyMessagesOperation *>(operation.self);
}
