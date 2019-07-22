#ifndef CIMAPMessage_h
#define CIMAPMessage_h

#include "stdint.h"

#include "CBase.h"
#include "CMessageConstants.h"
#include "CAbstractPart.h"
#include "CAbstractMessage.h"
#include "CArray.h"
#include "CAbstractMessageRendererCallback.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMessage;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPMessage, mailcore::IMAPMessage)
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPMessage)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint32_t, uid, setUid)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint32_t, sequenceNumber, setSequenceNumber)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint32_t, size, setSize)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CMessageFlag, flags, setFlags)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CMessageFlag, originalFlags, setOriginalFlags)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CArray, customFlags, setCustomFlags)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint64_t, modSeqValue, setModSeqValue)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CAbstractPart, mainPart, setMainPart)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CArray, gmailLabels, setGmailLabels)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint64_t, gmailMessageID, setGmailMessageID)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint64_t, gmailThreadID, setGmailThreadID)
    

    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPMessage, CAbstractPart, partForPartID, MailCoreString)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPMessage, MailCoreString, htmlRendering, MailCoreString, CAbstractMessageRendererCallback)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPMessage, CIMAPMessage, init)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPMessage_h */
