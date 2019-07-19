#ifndef CIMAPMessagePart_h
#define CIMAPMessagePart_h

#include "CBase.h"
#include "CAbstractMessagePart.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMessagePart;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPMessagePart, mailcore::IMAPMessagePart)
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPMessagePart)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessagePart, MailCoreString, partID, setPartID)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPMessagePart, CIMAPMessagePart, init)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPMessagePart_h */
