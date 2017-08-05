#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CAbstractMessagePart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMessagePart
#define structName CAbstractMessagePart

C_SYNTHESIZE_MAILCORE_OBJ(CMessageHeader, CMessageHeader_new, setHeader, header)
C_SYNTHESIZE_MAILCORE_OBJ(CAbstractPart, CAbstractPart_new, setMainPart, mainPart)

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

