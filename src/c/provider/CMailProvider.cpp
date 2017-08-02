#include <MailCore/MCCore.h>
#include "CMailProvider.h"
#include "CBase+Private.h"

#define nativeType mailcore::MailProvider
#define structName CMailProvider

CMailProvider CMailProvider_new(mailcore::MailProvider *provider) {
    CMailProvider self;
    self.instance = provider;
    self.instance->release();
    return self;
}

CArray  CMailProvider_imapServices(struct CMailProvider self) {
    return CArray_new(self.instance->imapServices());
}

CArray  CMailProvider_smtpServices(struct CMailProvider self) {
    return CArray_new(self.instance->smtpServices());
}
