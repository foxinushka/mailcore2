#include "CIMAPFetchContentToFileOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchContentToFileOperation
#define structName CIMAPFetchContentToFileOperation

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_SCALAR(bool, bool, setLoadingByChunksEnabled, isLoadingByChunksEnabled)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setChunksSize, chunksSize)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setEstimatedSize, estimatedSize)
