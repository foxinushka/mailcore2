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
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFolderInfoOperation)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPFolderInfoOperation, CIMAPFolderInfo, info)

#ifdef __cplusplus
}
#endif

#endif
