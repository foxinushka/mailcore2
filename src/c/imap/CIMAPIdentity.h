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
    
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPIdentity)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPIdentity, MailCoreString, vendor, setVendor)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPIdentity, MailCoreString, name, setName)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPIdentity, MailCoreString, version, setVersion)

    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdentity, CArray, allInfoKeys)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdentity, MailCoreString, infoForKey, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdentity, void, setInfoForKey, MailCoreString, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdentity, void, removeAllInfos)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPIdentity, CIMAPIdentity, init)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPIdentity_hpp */
