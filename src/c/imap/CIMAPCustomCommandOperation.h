#ifndef CIMAPCustomCommandOperation_hpp
#define CIMAPCustomCommandOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CBase.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPCustomCommandOperation;
}

extern "C" {
#endif
    
    struct CIMAPCustomCommandOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPCustomCommandOperation*    instance;
#else
        void*                                   instance;
#endif
    };
    typedef struct CIMAPCustomCommandOperation CIMAPCustomCommandOperation;
    
    const UChar*    CIMAPCustomCommandOperation_response(struct CIMAPCustomCommandOperation self)
                    CF_SWIFT_NAME(CIMAPCustomCommandOperation.response(self:));
    
    void            CIMAPCustomCommandOperation_release(CIMAPCustomCommandOperation self)
                    CF_SWIFT_NAME(CIMAPCustomCommandOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPCustomCommandOperation CIMAPCustomCommandOperation_new(mailcore::IMAPCustomCommandOperation *operation);
#endif

#endif /* CIMAPCustomCommandOperation_hpp */
