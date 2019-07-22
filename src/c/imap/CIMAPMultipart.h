#ifndef CIMAPMultipart_h
#define CIMAPMultipart_h

#include "CBase.h"
#include "CAbstractMultipart.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMultipart;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPMultipart, mailcore::IMAPMultipart)
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPMultipart)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMultipart, MailCoreString, partID, setPartID)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPMultipart, CIMAPMultipart, init)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPMultipart_h */
