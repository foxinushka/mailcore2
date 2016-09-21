#ifndef MAILCORE_CIMAP_FOLDER_STATUS_OPERATION_H
#define MAILCORE_CIMAP_FOLDER_STATUS_OPERATION_H

#include <MailCore/CBase.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPFolderStatusOperation {
        ref self;
    };
    typedef struct CIMAPFolderStatusOperation CIMAPFolderStatusOperation;

    void deleteCIMAPFolderStatusOperation(CIMAPFolderStatusOperation self);

#ifdef __cplusplus
}
#endif

#endif
