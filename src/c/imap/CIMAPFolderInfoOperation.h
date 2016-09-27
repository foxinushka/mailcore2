#ifndef MAILCORE_CIMAP_FOLDER_INFO_OPERATION_H
#define MAILCORE_CIMAP_FOLDER_INFO_OPERATION_H

#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPFolderInfoOperation {
        ref self;
    };
    typedef struct CIMAPFolderInfoOperation CIMAPFolderInfoOperation;

    void deleteCIMAPFolderInfoOperation(CIMAPFolderInfoOperation self);

#ifdef __cplusplus
}
#endif

#endif
