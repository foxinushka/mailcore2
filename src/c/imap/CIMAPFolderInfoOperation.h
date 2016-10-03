#ifndef MAILCORE_CIMAP_FOLDER_INFO_OPERATION_H
#define MAILCORE_CIMAP_FOLDER_INFO_OPERATION_H

#include "CBase.h"
#include "CIMAPBaseOperation.h"
#include "CIMAPFolderInfo.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFolderInfoOperation;
}

extern "C" {
#endif
    
    struct CIMAPFolderInfoOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPFolderInfoOperation*  instance;
#else
        void*                               instance;
#endif
        
        CIMAPFolderInfo (*info)(struct CIMAPFolderInfoOperation self);
    };
    typedef struct CIMAPFolderInfoOperation CIMAPFolderInfoOperation;

    void deleteCIMAPFolderInfoOperation(CIMAPFolderInfoOperation self);

#ifdef __cplusplus
}

CIMAPFolderInfoOperation newCIMAPFolderInfoOperation(mailcore::IMAPFolderInfoOperation *operation);
#endif

#endif
