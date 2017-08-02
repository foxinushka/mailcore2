#ifndef CIMAPCheckAccountOperation_hpp
#define CIMAPCheckAccountOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CBase.h"
#include "MailCoreString.h"

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
    };
    typedef struct CIMAPCheckAccountOperation CIMAPCheckAccountOperation;
    
    MailCoreString    CIMAPCheckAccountOperation_loginResponse(struct CIMAPCheckAccountOperation self)
                    CF_SWIFT_NAME(CIMAPCheckAccountOperation.loginResponse(self:));
    
    CData           CIMAPCheckAccountOperation_loginUnparsedResponseData(struct CIMAPCheckAccountOperation self)
                    CF_SWIFT_NAME(CIMAPCheckAccountOperation.loginUnparsedResponseData(self:));
    
    void            CIMAPCheckAccountOperation_release(CIMAPCheckAccountOperation self)
                    CF_SWIFT_NAME(CIMAPCheckAccountOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPCheckAccountOperation CIMAPCheckAccountOperation_new(mailcore::IMAPCheckAccountOperation *operation);
#endif

#endif /* CIMAPCheckAccountOperation_hpp */
