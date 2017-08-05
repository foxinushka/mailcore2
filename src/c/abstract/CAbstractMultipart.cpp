#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CAbstractMultipart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMultipart
#define structName CAbstractMultipart

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_MAILCORE_OBJ(CArray, CArray_new, setParts, parts)

