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
        
        const UChar*    (*response)(struct CIMAPCustomCommandOperation self);
        
    };
    typedef struct CIMAPCustomCommandOperation CIMAPCustomCommandOperation;
    
    void deleteCIMAPCustomCommandOperation(CIMAPCustomCommandOperation self);
    
#ifdef __cplusplus
}

CIMAPCustomCommandOperation newCIMAPCustomCommandOperation(mailcore::IMAPCustomCommandOperation *operation);
#endif

#endif /* CIMAPCustomCommandOperation_hpp */
