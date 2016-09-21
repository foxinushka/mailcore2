#include "CIMAPFolderInfoOperation.h"
#include "CIMAPFolderInfoOperation+Private.h"

extern "C" {
    CIMAPFolderInfoOperation newCIMAPFolderInfoOperation(mailcore::IMAPFolderInfoOperation *operationRef){
        CIMAPFolderInfoOperation operation;
        operation.self = reinterpret_cast<void *>(operationRef);
        return operation;
    }

    void deleteCIMAPFolderInfoOperation(CIMAPFolderInfoOperation operation) {
        delete reinterpret_cast<mailcore::IMAPFolderInfoOperation *>(operation.self);
    }
}
