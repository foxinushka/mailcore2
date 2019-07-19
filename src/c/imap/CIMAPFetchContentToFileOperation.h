#ifndef CIMAPFetchContentToFileOperation_hpp
#define CIMAPFetchContentToFileOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CBase.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFetchContentToFileOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFetchContentToFileOperation, mailcore::IMAPFetchContentToFileOperation)
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFetchContentToFileOperation)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFetchContentToFileOperation, bool, isLoadingByChunksEnabled, setLoadingByChunksEnabled)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFetchContentToFileOperation, uint32_t, chunksSize, setChunksSize)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFetchContentToFileOperation, uint32_t, estimatedSize, setEstimatedSize)
    
#ifdef __cplusplus
}
#endif


#endif /* CIMAPFetchContentToFileOperation_hpp */
