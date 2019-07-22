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
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPIdentity, mailcore::IMAPIdentity)
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPIdentity)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPIdentity, MailCoreString, vendor, setVendor)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPIdentity, MailCoreString, name, setName)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPIdentity, MailCoreString, version, setVersion)

    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdentity, CArray, allInfoKeys)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdentity, MailCoreString, infoForKey, MailCoreString)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdentity, void, setInfoForKey, MailCoreString, MailCoreString)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdentity, void, removeAllInfos)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPIdentity, CIMAPIdentity, init)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPIdentity_hpp */
