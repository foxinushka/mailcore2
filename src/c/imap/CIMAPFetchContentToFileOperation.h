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
        
        bool        (*isLoadingByChunksEnabled)(struct CIMAPFetchContentToFileOperation self);
        uint32_t    (*chunksSize)(struct CIMAPFetchContentToFileOperation self);
        uint32_t    (*estimatedSize)(struct CIMAPFetchContentToFileOperation self);
        
        void        (*setLoadingByChunksEnabled)(struct CIMAPFetchContentToFileOperation self, bool newValue);
        void        (*setChunksSize)(struct CIMAPFetchContentToFileOperation self, uint32_t newValue);
        void        (*setEstimatedSize)(struct CIMAPFetchContentToFileOperation self, uint32_t newValue);
        
    };
    typedef struct CIMAPFetchContentToFileOperation CIMAPFetchContentToFileOperation;
    
    void deleteCIMAPFetchContentToFileOperation(CIMAPFetchContentToFileOperation self);
    
#ifdef __cplusplus
}

CIMAPFetchContentToFileOperation newCIMAPFetchContentToFileOperation(mailcore::IMAPFetchContentToFileOperation *operation);
#endif


#endif /* CIMAPFetchContentToFileOperation_hpp */
