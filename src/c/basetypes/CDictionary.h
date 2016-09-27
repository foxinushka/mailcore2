#ifndef CDictionary_h
#define CDictionary_h

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"
#include "CArray.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CDictionary {
        ref nativeInstance;
        
        CArray          (*allKeys)(struct CDictionary *self);
        uint32_t        (*uintForKey)(struct CDictionary *self, uint32_t key);
    };
    typedef struct CDictionary CDictionary;
    
    CDictionary newCDictionary();
    void deleteCDictionary(CDictionary *self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCCore.h>
CDictionary newCDictionary(mailcore::HashMap *dict);
mailcore::HashMap* cast(CDictionary *dict);
#endif

#endif /* CDictionary_hpp */
