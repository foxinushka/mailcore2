#ifndef MAILCORE_CMAIL_PROVIDER_H
#define MAILCORE_CMAIL_PROVIDER_H

#include "stdint.h"
#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus

namespace mailcore {
    class MailProvider;
}

extern "C" {
#endif
    
    typedef struct CMailProvider {
#ifdef __cplusplus
        mailcore::MailProvider*  instance;
#else
        void*                           instance;
#endif
    } CMailProvider;
    
    CArray  CMailProvider_imapServices(struct CMailProvider self)
            CF_SWIFT_NAME(getter:CMailProvider.imapServices(self:));
    
    CArray  CMailProvider_smtpServices(struct CMailProvider self)
            CF_SWIFT_NAME(getter:CMailProvider.smtpServices(self:));
    
#ifdef __cplusplus
}

CMailProvider CMailProvider_new(mailcore::MailProvider* provider);
#endif
#endif
