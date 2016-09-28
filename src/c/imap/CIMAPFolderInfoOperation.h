#ifndef MAILCORE_CIMAP_FOLDER_INFO_OPERATION_H
#define MAILCORE_CIMAP_FOLDER_INFO_OPERATION_H

#include "CBase.h"
#include "CIMAPBaseOperation.h"
#include "CIMAPFolderInfo.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPFolderInfoOperation {
        CIMAPBaseOperation baseOperation;
        CIMAPFolderInfo (*info)(struct CIMAPFolderInfoOperation self);
    };
    typedef struct CIMAPFolderInfoOperation CIMAPFolderInfoOperation;

    void deleteCIMAPFolderInfoOperation(CIMAPFolderInfoOperation self);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

extern "C" CIMAPFolderInfoOperation newCIMAPFolderInfoOperation(mailcore::IMAPFolderInfoOperation *operation);
mailcore::IMAPFolderInfoOperation * cast(CIMAPFolderInfoOperation self);
#endif

#endif
