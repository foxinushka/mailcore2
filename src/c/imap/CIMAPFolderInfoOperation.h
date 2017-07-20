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
    };
    typedef struct CIMAPFolderInfoOperation CIMAPFolderInfoOperation;

    CIMAPFolderInfo 	CIMAPFolderInfoOperation_info(struct CIMAPFolderInfoOperation self)
    					CF_SWIFT_NAME(CIMAPFolderInfoOperation.info(self:));

    void 				CIMAPFolderInfoOperation_release(CIMAPFolderInfoOperation self)
    					CF_SWIFT_NAME(CIMAPFolderInfoOperation.release(self:));

#ifdef __cplusplus
}

CIMAPFolderInfoOperation CIMAPFolderInfoOperation_new(mailcore::IMAPFolderInfoOperation *operation);
#endif

#endif
