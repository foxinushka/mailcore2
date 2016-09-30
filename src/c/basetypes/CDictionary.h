#ifndef CDictionary_h
#define CDictionary_h

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"
#include "CArray.h"

#ifdef __cplusplus

namespace mailcore {
    class HashMap;
}

extern "C" {
#endif
    
    struct CDictionary {
        #ifdef __cplusplus
        mailcore::HashMap* nativeInstance;
        #endif
        
        CArray          (*allKeys)(struct CDictionary self);
        CObject         (*getValue)(struct CDictionary self, CObject key);
    };
    typedef struct CDictionary CDictionary;
    
    void deleteCDictionary(CDictionary self);
    
#ifdef __cplusplus
}

CDictionary newCDictionary(mailcore::HashMap *dict);
#endif

#endif /* CDictionary_hpp */
