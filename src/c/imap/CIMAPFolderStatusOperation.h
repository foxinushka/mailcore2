#ifndef MAILCORE_CIMAP_FOLDER_STATUS_OPERATION_H
#define MAILCORE_CIMAP_FOLDER_STATUS_OPERATION_H

#include "CBase.h"
#include "CIMAPBaseOperation.h"
#include "CIMAPFolderStatus.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFolderStatusOperation;
}

extern "C" {
#endif
    
    struct CIMAPFolderStatusOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPFolderStatusOperation*    instance;
#else
        void*                                   instance;
#endif
        
        CIMAPFolderStatus (*status)(struct CIMAPFolderStatusOperation self);
    };
    typedef struct CIMAPFolderStatusOperation CIMAPFolderStatusOperation;
    
    void deleteCIMAPFolderStatusOperation(CIMAPFolderStatusOperation self);
    
#ifdef __cplusplus
}

CIMAPFolderStatusOperation newCIMAPFolderStatusOperation(mailcore::IMAPFolderStatusOperation *operation);
#endif

#endif
