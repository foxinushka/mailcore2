#ifndef MAILCORE_CIMAP_FOLDER_STATUS_OPERATION_H
#define MAILCORE_CIMAP_FOLDER_STATUS_OPERATION_H

#include "CBase.h"
#include "CIMAPBaseOperation.h"
#include "CIMAPFolderStatus.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPFolderStatusOperation {
        CIMAPBaseOperation baseOperation;
        CIMAPFolderStatus (*status)(struct CIMAPFolderStatusOperation self);
    };
    typedef struct CIMAPFolderStatusOperation CIMAPFolderStatusOperation;
    
    void deleteCIMAPFolderStatusOperation(CIMAPFolderStatusOperation self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

extern "C" CIMAPFolderStatusOperation newCIMAPFolderStatusOperation(mailcore::IMAPFolderStatusOperation *operation);
mailcore::IMAPFolderStatusOperation * cast(CIMAPFolderStatusOperation self);
#endif

#endif
