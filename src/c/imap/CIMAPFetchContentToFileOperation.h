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
    
    struct CIMAPFetchContentToFileOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPFetchContentToFileOperation*    instance;
#else
        void*                                   instance;
#endif
    };
    typedef struct CIMAPFetchContentToFileOperation CIMAPFetchContentToFileOperation;
    
    bool        CIMAPFetchContentToFileOperation_isLoadingByChunksEnabled(struct CIMAPFetchContentToFileOperation self)
                CF_SWIFT_NAME(getter:CIMAPFetchContentToFileOperation.isLoadingByChunksEnabled(self:));
    
    uint32_t    CIMAPFetchContentToFileOperation_chunksSize(struct CIMAPFetchContentToFileOperation self)
                CF_SWIFT_NAME(getter:CIMAPFetchContentToFileOperation.chunksSize(self:));
    
    uint32_t    CIMAPFetchContentToFileOperation_estimatedSize(struct CIMAPFetchContentToFileOperation self)
                CF_SWIFT_NAME(getter:CIMAPFetchContentToFileOperation.estimatedSize(self:));
    
    void        CIMAPFetchContentToFileOperation_setLoadingByChunksEnabled(struct CIMAPFetchContentToFileOperation self, bool newValue)
                CF_SWIFT_NAME(setter:CIMAPFetchContentToFileOperation.isLoadingByChunksEnabled(self:newValue:));
    
    void        CIMAPFetchContentToFileOperation_setChunksSize(struct CIMAPFetchContentToFileOperation self, uint32_t newValue)
                CF_SWIFT_NAME(setter:CIMAPFetchContentToFileOperation.chunksSize(self:newValue:));
    
    void        CIMAPFetchContentToFileOperation_setEstimatedSize(struct CIMAPFetchContentToFileOperation self, uint32_t newValue)
                CF_SWIFT_NAME(setter:CIMAPFetchContentToFileOperation.estimatedSize(self:newValue:));
    
    void        CIMAPFetchContentToFileOperation_release(CIMAPFetchContentToFileOperation self)
                CF_SWIFT_NAME(CIMAPFetchContentToFileOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPFetchContentToFileOperation CIMAPFetchContentToFileOperation_new(mailcore::IMAPFetchContentToFileOperation *operation);
#endif


#endif /* CIMAPFetchContentToFileOperation_hpp */
