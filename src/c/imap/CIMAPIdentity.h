#ifndef CIMAPIdentity_hpp
#define CIMAPIdentity_hpp

#include "CBase.h"
#include "CMessageConstants.h"
#include "CObject.h"
#include "CArray.h"

#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPIdentity;
}

extern "C" {
#endif
    
    struct CIMAPIdentity {
#ifdef __cplusplus
        mailcore::IMAPIdentity*   instance;
#else
        void*                   instance;
#endif
    };
    typedef struct CIMAPIdentity CIMAPIdentity;

    MailCoreString    CIMAPIdentity_vendor(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(getter:CIMAPIdentity.vendor(self:));

    void            CIMAPIdentity_setVendor(struct CIMAPIdentity self, MailCoreString vendor)
                    CF_SWIFT_NAME(setter:CIMAPIdentity.vendor(self:newValue:));

    MailCoreString    CIMAPIdentity_name(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(getter:CIMAPIdentity.name(self:));

    void            CIMAPIdentity_setName(struct CIMAPIdentity self, MailCoreString name)
                    CF_SWIFT_NAME(setter:CIMAPIdentity.name(self:newValue:));

    MailCoreString    CIMAPIdentity_version(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(getter:CIMAPIdentity.version(self:));

    void            CIMAPIdentity_setVersion(struct CIMAPIdentity self, MailCoreString version)
                    CF_SWIFT_NAME(setter:CIMAPIdentity.version(self:newValue:));

    CArray          CIMAPIdentity_allInfoKeys(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(CIMAPIdentity.allInfoKeys(self:));

    MailCoreString    CIMAPIdentity_infoForKey(struct CIMAPIdentity self, MailCoreString key)
                    CF_SWIFT_NAME(CIMAPIdentity.infoForKey(self:key:));

    void            CIMAPIdentity_setInfoForKey(struct CIMAPIdentity self, MailCoreString value, MailCoreString key)
                    CF_SWIFT_NAME(CIMAPIdentity.setInfoForKey(self:value:key:));

    void            CIMAPIdentity_removeAllInfos(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(CIMAPIdentity.removeAllInfos(self:));

    CIMAPIdentity   CIMAPIdentity_new(MailCoreString vendor, MailCoreString name, MailCoreString version)
                    CF_SWIFT_NAME(CIMAPIdentity.init(vendor:name:version:));

    void            CIMAPIdentity_release(CIMAPIdentity self)
                    CF_SWIFT_NAME(CIMAPIdentity.release(self:));
    
#ifdef __cplusplus
}

CIMAPIdentity CIMAPIdentity_new(mailcore::IMAPIdentity *identity);
#endif

#endif /* CIMAPIdentity_hpp */
