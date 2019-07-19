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
    
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPMessage)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint32_t, uid, setUid)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint32_t, sequenceNumber, setSequenceNumber)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint32_t, size, setSize)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CMessageFlag, flags, setFlags)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CMessageFlag, originalFlags, setOriginalFlags)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CArray, customFlags, setCustomFlags)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint64_t, modSeqValue, setModSeqValue)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CAbstractPart, mainPart, setMainPart)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, CArray, gmailLabels, setGmailLabels)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint64_t, gmailMessageID, setGmailMessageID)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPMessage, uint64_t, gmailThreadID, setGmailThreadID)
    

    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPMessage, CAbstractPart, partForPartID, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPMessage, MailCoreString, htmlRendering, MailCoreString, CAbstractMessageRendererCallback)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPMessage, CIMAPMessage, init)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPMessage_h */
