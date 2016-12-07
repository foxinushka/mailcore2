#ifndef CIMAPMoveMessagesOperation_hpp
#define CIMAPMoveMessagesOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CDictionary.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMoveMessagesOperation;
}

extern "C" {
#endif
    
    struct CIMAPMoveMessagesOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPMoveMessagesOperation*      instance;
#else
        void*                                           instance;
#endif
        
        CDictionary    (*uidMapping)(struct CIMAPMoveMessagesOperation self);
        
    };
    typedef struct CIMAPMoveMessagesOperation CIMAPMoveMessagesOperation;
    
    void deleteCIMAPMoveMessagesOperation(CIMAPMoveMessagesOperation self);
    
#ifdef __cplusplus
}

CIMAPMoveMessagesOperation newCIMAPMoveMessagesOperation(mailcore::IMAPMoveMessagesOperation *operation);
#endif

#endif /* CIMAPMoveMessagesOperation_hpp */
