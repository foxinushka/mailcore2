#ifndef CIMAPCapabilityOperation_hpp
#define CIMAPCapabilityOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CIndexSet.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPCapabilityOperation;
}

extern "C" {
#endif
    
    struct CIMAPCapabilityOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPCapabilityOperation*      instance;
#else
        void*                                   instance;
#endif
    };
    typedef struct CIMAPCapabilityOperation CIMAPCapabilityOperation;
    
    CIndexSet   CIMAPCapabilityOperation_capabilities(struct CIMAPCapabilityOperation self)
                CF_SWIFT_NAME(CIMAPCapabilityOperation.capabilities(self:));
    
    void        CIMAPCapabilityOperation_release(CIMAPCapabilityOperation self)
                CF_SWIFT_NAME(CIMAPCapabilityOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPCapabilityOperation CIMAPCapabilityOperation_new(mailcore::IMAPCapabilityOperation *operation);
#endif

#endif /* CIMAPCapabilityOperation_hpp */
