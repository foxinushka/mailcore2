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
    };
    typedef struct CIMAPMoveMessagesOperation CIMAPMoveMessagesOperation;
    
    CDictionary     CIMAPMoveMessagesOperation_uidMapping(struct CIMAPMoveMessagesOperation self)
                    CF_SWIFT_NAME(CIMAPMoveMessagesOperation.uidMapping(self:));
    
    void            CIMAPMoveMessagesOperation_release(CIMAPMoveMessagesOperation self)
                    CF_SWIFT_NAME(CIMAPMoveMessagesOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPMoveMessagesOperation CIMAPMoveMessagesOperation_new(mailcore::IMAPMoveMessagesOperation *operation);
#endif

#endif /* CIMAPMoveMessagesOperation_hpp */
