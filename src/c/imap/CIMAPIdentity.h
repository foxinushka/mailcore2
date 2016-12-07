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
        const UChar*    (*vendor)(struct CIMAPIdentity self);
        void            (*setVendor)(struct CIMAPIdentity self, const UChar* vendor);
        const UChar*    (*name)(struct CIMAPIdentity self);
        void            (*setName)(struct CIMAPIdentity self, const UChar* name);
        const UChar*    (*version)(struct CIMAPIdentity self);
        void            (*setVersion)(struct CIMAPIdentity self, const UChar* version);
        
        CArray          (*allInfoKeys)(struct CIMAPIdentity self);
        const UChar*    (*infoForKey)(struct CIMAPIdentity self, const UChar* key);
        void            (*setInfoForKey)(struct CIMAPIdentity self, const UChar* value, const UChar* key);
        void            (*removeAllInfos)(struct CIMAPIdentity self);
    };
    typedef struct CIMAPIdentity CIMAPIdentity;
    
    CIMAPIdentity newCIMAPIdentity(const UChar* vendor, const UChar* name, const UChar* version);
    void deleteCIMAPIdentity(CIMAPIdentity self);
    
#ifdef __cplusplus
}

CIMAPIdentity newCIMAPIdentity(mailcore::IMAPIdentity *identity);
#endif

#endif /* CIMAPIdentity_hpp */
