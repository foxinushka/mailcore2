#ifndef MAILCORE_CINDEX_SET_H
#define MAILCORE_CINDEX_SET_H

#include "stdint.h"
#include "CBase.h"

#ifdef __cplusplus

namespace mailcore {
    class IndexSet;
}

extern "C" {
#endif
    
    typedef void (^CIndexSetEnumerateRangesBlock)(uint64_t location, uint64_t length);

    struct CIndexSet {
        #ifdef __cplusplus
        mailcore::IndexSet* nativeInstance;
        #endif
        
        void    (*enumerateRanges)(struct CIndexSet self , CIndexSetEnumerateRangesBlock block);
        void    (*addRange)(struct CIndexSet self, uint64_t location, uint64_t length);
    };
    typedef struct CIndexSet CIndexSet;

    CIndexSet newCIndexSet();
    void deleteCIndexSet(CIndexSet self);
    
#ifdef __cplusplus
}

CIndexSet newCIndexSet(mailcore::IndexSet *set);
#endif

#endif
