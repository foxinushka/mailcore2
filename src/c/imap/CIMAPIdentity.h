#ifndef CIMAPIdentity_hpp
#define CIMAPIdentity_hpp

#include "CBase.h"
#include "CMessageConstants.h"
#include "CObject.h"
#include "CArray.h"

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

    const UChar*    CIMAPIdentity_vendor(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(getter:CIMAPIdentity.vendor(self:));

    void            CIMAPIdentity_setVendor(struct CIMAPIdentity self, const UChar* vendor)
                    CF_SWIFT_NAME(setter:CIMAPIdentity.vendor(self:newValue:));

    const UChar*    CIMAPIdentity_name(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(getter:CIMAPIdentity.name(self:));

    void            CIMAPIdentity_setName(struct CIMAPIdentity self, const UChar* name)
                    CF_SWIFT_NAME(setter:CIMAPIdentity.name(self:newValue:));

    const UChar*    CIMAPIdentity_version(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(getter:CIMAPIdentity.version(self:));

    void            CIMAPIdentity_setVersion(struct CIMAPIdentity self, const UChar* version)
                    CF_SWIFT_NAME(setter:CIMAPIdentity.version(self:newValue:));

    CArray          CIMAPIdentity_allInfoKeys(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(CIMAPIdentity.allInfoKeys(self:));

    const UChar*    CIMAPIdentity_infoForKey(struct CIMAPIdentity self, const UChar* key)
                    CF_SWIFT_NAME(CIMAPIdentity.infoForKey(self:key:));

    void            CIMAPIdentity_setInfoForKey(struct CIMAPIdentity self, const UChar* value, const UChar* key)
                    CF_SWIFT_NAME(CIMAPIdentity.setInfoForKey(self:value:key:));

    void            CIMAPIdentity_removeAllInfos(struct CIMAPIdentity self)
                    CF_SWIFT_NAME(CIMAPIdentity.removeAllInfos(self:));

    CIMAPIdentity   CIMAPIdentity_new(const UChar* vendor, const UChar* name, const UChar* version)
                    CF_SWIFT_NAME(CIMAPIdentity.init(vendor:name:version:));

    void            CIMAPIdentity_release(CIMAPIdentity self)
                    CF_SWIFT_NAME(CIMAPIdentity.release(self:));
    
#ifdef __cplusplus
}

CIMAPIdentity CIMAPIdentity_new(mailcore::IMAPIdentity *identity);
#endif

#endif /* CIMAPIdentity_hpp */
