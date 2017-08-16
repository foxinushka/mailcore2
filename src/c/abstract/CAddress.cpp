#include <MailCore/MCCore.h>
#include "CAddress.h"
#include "CBase+Private.h"

#define nativeType mailcore::Address
#define structName CAddress

C_SYNTHESIZE_STRING(setDisplayName, displayName);
C_SYNTHESIZE_STRING(setMailbox, mailbox);
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_CONSTRUCTOR()

CAddress CAddress_init(){
    return CAddress_new(new mailcore::Address());
}

C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CAddress, addressWithDisplayName, MailCoreString, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CAddress, addressWithMailbox, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CAddress, addressWithRFC822String, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CAddress, addressWithNonEncodedRFC822String, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CArray, addressesWithRFC822String, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CArray, addressesWithNonEncodedRFC822String, MailCoreString)

C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(MailCoreString, RFC822StringForAddresses, CArray)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(MailCoreString, nonEncodedRFC822StringForAddresses, CArray)

C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, RFC822String)
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, nonEncodedRFC822String)



