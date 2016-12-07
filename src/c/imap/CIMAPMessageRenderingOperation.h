#ifndef CIMAPMessageRenderingOperation_hpp
#define CIMAPMessageRenderingOperation_hpp

#include "CIMAPBaseOperation.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMessageRenderingOperation;
}

extern "C" {
#endif
    
    struct CIMAPMessageRenderingOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPMessageRenderingOperation*      instance;
#else
        void*                                           instance;
#endif
        
        const UChar*    (*result)(struct CIMAPMessageRenderingOperation self);
        
    };
    typedef struct CIMAPMessageRenderingOperation CIMAPMessageRenderingOperation;
    
    void deleteCIMAPMessageRenderingOperation(CIMAPMessageRenderingOperation self);
    
#ifdef __cplusplus
}

CIMAPMessageRenderingOperation newCIMAPMessageRenderingOperation(mailcore::IMAPMessageRenderingOperation *operation);
#endif

#endif /* CIMAPMessageRenderingOperation_hpp */
