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
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPPart)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPPart, MailCoreString, partID, setPartID)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPPart, unsigned int, size, setSize)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPPart, Encoding, encoding, setEncoding)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPPart, unsigned int, decodedSize)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPPart, CIMAPPart, init)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPPart_h */
