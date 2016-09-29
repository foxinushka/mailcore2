#ifndef CIMAPMultipart_h
#define CIMAPMultipart_h

#include "CBase.h"
#include "CAbstractMultipart.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPMultipart {
        CAbstractMultipart abstractMultipart;
        
        const UChar*    (*partID)(struct CIMAPMultipart self);
        void            (*setPartID)(struct CIMAPMultipart self, const UChar* partID);
    };
    typedef struct CIMAPMultipart CIMAPMultipart;
    
    void deleteCIMAPMultipart(CIMAPMultipart self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPMultipart newCIMAPMultipart(mailcore::IMAPMultipart *part);
mailcore::IMAPMultipart* cast(CIMAPMultipart self);
#endif

#endif /* CIMAPMultipart_h */
