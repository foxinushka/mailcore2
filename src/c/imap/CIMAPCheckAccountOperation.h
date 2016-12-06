#ifndef CIMAPCheckAccountOperation_hpp
#define CIMAPCheckAccountOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CBase.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPCheckAccountOperation;
}

extern "C" {
#endif
    
    struct CIMAPCheckAccountOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPCheckAccountOperation*    instance;
#else
        void*                                   instance;
#endif
        
        const UChar*    (*loginResponse)(struct CIMAPCheckAccountOperation self);
        CData           (*loginUnparsedResponseData)(struct CIMAPCheckAccountOperation self);
        
    };
    typedef struct CIMAPCheckAccountOperation CIMAPCheckAccountOperation;
    
    void deleteCIMAPCheckAccountOperation(CIMAPCheckAccountOperation self);
    
#ifdef __cplusplus
}

CIMAPCheckAccountOperation newCIMAPCheckAccountOperation(mailcore::IMAPCheckAccountOperation *operation);
#endif

#endif /* CIMAPCheckAccountOperation_hpp */
