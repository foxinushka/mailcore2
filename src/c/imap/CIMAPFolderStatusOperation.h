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
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFolderStatusOperation, mailcore::IMAPFolderStatusOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFolderStatusOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPFolderStatusOperation, CIMAPFolderStatus, status)
    
#ifdef __cplusplus
}
#endif

#endif
