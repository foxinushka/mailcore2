#ifndef MAILCORE_CINDEX_SET_H
#define MAILCORE_CINDEX_SET_H

#include "stdint.h"
#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct CIndexSet {
        ref self;
    };
    typedef struct CIndexSet CIndexSet;

    CIndexSet newCIndexSetWithRange(uint64_t start, uint64_t end);
    void deleteCIndexSet(CIndexSet self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
CIndexSet newCIndexSet(mailcore::IndexSet *set);
mailcore::IndexSet* cast(CIndexSet *self);
#endif

#endif
