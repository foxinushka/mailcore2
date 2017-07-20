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
        
    };
    typedef struct CIMAPFetchParsedContentOperation CIMAPFetchParsedContentOperation;
    
    CMessageParser  CIMAPFetchParsedContentOperation_parser(struct CIMAPFetchParsedContentOperation self)
                    CF_SWIFT_NAME(CIMAPFetchParsedContentOperation.parser(self:));
    
    void            CIMAPFetchParsedContentOperation_release(CIMAPFetchParsedContentOperation self)
                    CF_SWIFT_NAME(CIMAPFetchParsedContentOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPFetchParsedContentOperation CIMAPFetchParsedContentOperation_new(mailcore::IMAPFetchParsedContentOperation *operation);
#endif

#endif /* CIMAPFetchParsedContentOperation_hpp */
