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
        
        CIndexSet (*capabilities)(struct CIMAPCapabilityOperation self);
        
    };
    typedef struct CIMAPCapabilityOperation CIMAPCapabilityOperation;
    
    void deleteCIMAPCapabilityOperation(CIMAPCapabilityOperation self);
    
#ifdef __cplusplus
}

CIMAPCapabilityOperation newCIMAPCapabilityOperation(mailcore::IMAPCapabilityOperation *operation);
#endif

#endif /* CIMAPCapabilityOperation_hpp */
