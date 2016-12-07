#ifndef CIMAPIdentityOperation_hpp
#define CIMAPIdentityOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CIMAPIdentity.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPIdentityOperation;
}

extern "C" {
#endif
    
    struct CIMAPIdentityOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPIdentityOperation*      instance;
#else
        void*                                 instance;
#endif
        
        CIMAPIdentity    (*serverIdentity)(struct CIMAPIdentityOperation self);
        
    };
    typedef struct CIMAPIdentityOperation CIMAPIdentityOperation;
    
    void deleteCIMAPIdentityOperation(CIMAPIdentityOperation self);
    
#ifdef __cplusplus
}

CIMAPIdentityOperation newCIMAPIdentityOperation(mailcore::IMAPIdentityOperation *operation);
#endif

#endif /* CIMAPIdentityOperation_hpp */
