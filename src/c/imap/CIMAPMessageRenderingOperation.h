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
    };
    typedef struct CIMAPMessageRenderingOperation CIMAPMessageRenderingOperation;
    
    const UChar*    CIMAPMessageRenderingOperation_result(struct CIMAPMessageRenderingOperation self)
                    CF_SWIFT_NAME(CIMAPMessageRenderingOperation.result(self:));
    
    void            CIMAPMessageRenderingOperation_release(CIMAPMessageRenderingOperation self)
                    CF_SWIFT_NAME(CIMAPMessageRenderingOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPMessageRenderingOperation CIMAPMessageRenderingOperation_new(mailcore::IMAPMessageRenderingOperation *operation);
#endif

#endif /* CIMAPMessageRenderingOperation_hpp */
