#ifndef MAILCORE_CMAIL_PROVIDER_H
#define MAILCORE_CMAIL_PROVIDER_H

#include "stdint.h"
#include "CBase.h"
#include "CArray.h"
#include "CData.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class MailProvider;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CMailProvider, mailcore::MailProvider)    
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CMailProvider)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CMailProvider, CArray, imapServices)
    CMAILCORE_EXPORT C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CMailProvider, CArray, smtpServices)
    CMAILCORE_EXPORT C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CMailProvider, MailCoreString, identifier)
    
#ifdef __cplusplus
}
#endif

#endif
