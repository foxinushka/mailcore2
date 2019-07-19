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
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFolderInfoOperation, mailcore::IMAPFolderInfoOperation)
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFolderInfoOperation)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPFolderInfoOperation, CIMAPFolderInfo, info)

#ifdef __cplusplus
}
#endif

#endif
