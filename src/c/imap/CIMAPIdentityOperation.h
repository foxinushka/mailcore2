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
        
    };
    typedef struct CIMAPIdentityOperation CIMAPIdentityOperation;
    
    CIMAPIdentity   CIMAPIdentityOperation_serverIdentity(struct CIMAPIdentityOperation self)
                    CF_SWIFT_NAME(CIMAPIdentityOperation.serverIdentity(self:));
    
    void            CIMAPIdentityOperation_release(CIMAPIdentityOperation self)
                    CF_SWIFT_NAME(CIMAPIdentityOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPIdentityOperation CIMAPIdentityOperation_new(mailcore::IMAPIdentityOperation *operation);
#endif

#endif /* CIMAPIdentityOperation_hpp */
