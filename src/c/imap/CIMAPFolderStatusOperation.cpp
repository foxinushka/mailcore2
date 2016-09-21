#include "CIMAPFolderStatusOperation.h"
#include "CIMAPFolderStatusOperation+Private.h"

extern "C" {
    CIMAPFolderStatusOperation newCIMAPFolderStatusOperation(mailcore::IMAPFolderStatusOperation *operationRef){
        CIMAPFolderStatusOperation operation;
        operation.self = reinterpret_cast<void *>(operationRef);
        return operation;
    }

    void deleteCIMAPFolderStatusOperation(CIMAPFolderStatusOperation operation) {
        delete reinterpret_cast<mailcore::IMAPFolderStatusOperation *>(operation.self);
    }
}
