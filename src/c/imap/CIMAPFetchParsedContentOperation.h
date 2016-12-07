#ifndef CIMAPFetchParsedContentOperation_hpp
#define CIMAPFetchParsedContentOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CMessageParser.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFetchParsedContentOperation;
}

extern "C" {
#endif
    
    struct CIMAPFetchParsedContentOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPFetchParsedContentOperation*      instance;
#else
        void*                                           instance;
#endif
        
        CMessageParser (*parser)(struct CIMAPFetchParsedContentOperation self);
        
    };
    typedef struct CIMAPFetchParsedContentOperation CIMAPFetchParsedContentOperation;
    
    void deleteCIMAPFetchParsedContentOperation(CIMAPFetchParsedContentOperation self);
    
#ifdef __cplusplus
}

CIMAPFetchParsedContentOperation newCIMAPFetchParsedContentOperation(mailcore::IMAPFetchParsedContentOperation *operation);
#endif

#endif /* CIMAPFetchParsedContentOperation_hpp */
