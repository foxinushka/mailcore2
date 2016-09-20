#include <MailCore/MCAsync.h>

extern "C" {
#include "CIMAPNamespace.h"
    
    CIMAPNamespace newCIMAPNamespace() {
        CIMAPNamespace operation;
        operation.self = new mailcore::IMAPNamespace();
        return operation;
    }
    
    void deleteCIMAPNamespace(CIMAPNamespace operation) {
        delete reinterpret_cast<mailcore::IMAPNamespace *>(operation.self);
    }
}

