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
        mailcore::HashMap*  instance;
#else
        void*               instance;
#endif
    };
    typedef struct CDictionary CDictionary;
    
    CArray          CDictionary_allKeys(struct CDictionary self)
                    CF_SWIFT_NAME(CDictionary.allKeys(self:));
    
    CObject         CDictionary_getValue(struct CDictionary self, CObject key)
                    CF_SWIFT_NAME(CDictionary.getValue(self:key:));
    
    void            CDictionary_setValue(struct CDictionary self, CObject key, CObject value)
                    CF_SWIFT_NAME(CDictionary.setValue(self:key:value:));
    
    CDictionary     CDictionary_new()
                    /*CF_SWIFT_NAME(CDictionary.init())*/;
    
    void            CDictionary_release(CDictionary self)
                    CF_SWIFT_NAME(CDictionary.release(self:));
    
#ifdef __cplusplus
}

CDictionary CDictionary_new(mailcore::HashMap *dict);
#endif

#endif /* CDictionary_hpp */
