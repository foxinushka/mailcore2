#ifndef CIMAPPart_h
#define CIMAPPart_h

#include "CBase.h"
#include "CAbstractMessagePart.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPPart;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPPart, mailcore::IMAPPart)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPPart)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPPart, MailCoreString, partID, setPartID)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPPart, unsigned int, size, setSize)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPPart, Encoding, encoding, setEncoding)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPPart, unsigned int, decodedSize)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPPart, CIMAPPart, init)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPPart_h */
