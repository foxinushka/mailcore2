#ifndef MAILCORE_CINDEX_SET_H
#define MAILCORE_CINDEX_SET_H

#include "stdint.h"
#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef void (^CIndexSetEnumerateRangesBlock)(uint64_t location, uint64_t length);

    struct CIndexSet {
        ref nativeInstance;
        
        void    (*enumerateRanges)(struct CIndexSet self , CIndexSetEnumerateRangesBlock block);
        void    (*addRange)(struct CIndexSet self, uint64_t location, uint64_t length);
    };
    typedef struct CIndexSet CIndexSet;

    CIndexSet newCIndexSet();
    void deleteCIndexSet(CIndexSet self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCCore.h>
CIndexSet newCIndexSet(mailcore::IndexSet *set);
mailcore::IndexSet* cast(CIndexSet self);
#endif

#endif
