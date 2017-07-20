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
    };
    typedef struct CIMAPFolderStatusOperation CIMAPFolderStatusOperation;

    CIMAPFolderStatus 	CIMAPFolderStatusOperation_status(struct CIMAPFolderStatusOperation self)
    					CF_SWIFT_NAME(CIMAPFolderStatusOperation.status(self:));

    void 				CIMAPFolderStatusOperation_release(CIMAPFolderStatusOperation self)
    					CF_SWIFT_NAME(CIMAPFolderStatusOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPFolderStatusOperation CIMAPFolderStatusOperation_new(mailcore::IMAPFolderStatusOperation *operation);
#endif

#endif
