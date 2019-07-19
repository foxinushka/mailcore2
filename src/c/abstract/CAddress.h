#ifndef MAILCORE_CADDRESS_H
#define MAILCORE_CADDRESS_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class Address;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CAddress, mailcore::Address)

	CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CAddress)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAddress, MailCoreString, displayName, setDisplayName)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAddress, MailCoreString, mailbox, setMailbox)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CAddress, MailCoreString, RFC822String)
	CMAILCORE_EXPORT C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CAddress, MailCoreString, nonEncodedRFC822String)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAddress, CAddress, addressWithDisplayName, MailCoreString, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAddress, CAddress, addressWithMailbox, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAddress, CAddress, addressWithRFC822String, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAddress, CAddress, addressWithNonEncodedRFC822String, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAddress, CArray, addressesWithRFC822String, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAddress, CArray, addressesWithNonEncodedRFC822String, MailCoreString)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAddress, MailCoreString, RFC822StringForAddresses, CArray)
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAddress, MailCoreString, nonEncodedRFC822StringForAddresses, CArray)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAddress, CAddress, init)
    
#ifdef __cplusplus
}
#endif

#endif
