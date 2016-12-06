#ifndef MAILCORE_CINDEX_SET_H
#define MAILCORE_CINDEX_SET_H

#include "stdint.h"
#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus

namespace mailcore {
    class IndexSet;
}

#include <MailCore/MCBaseTypes.h>

extern "C" {
#endif
    
    struct Range {
        /** first integer of the range.*/
        uint64_t location;
        
        /** length of the range.*/
        uint64_t length;
    };
    typedef struct Range Range;

    struct CIndexSet {
#ifdef __cplusplus
        mailcore::IndexSet* instance;
#else
        void*               instance;
#endif
        
        unsigned int    (*count)(struct CIndexSet self);
        void            (*addIndex)(struct CIndexSet self, uint64_t idx);
        void            (*removeIndex)(struct CIndexSet self, uint64_t idx);
        bool            (*containsIndex)(struct CIndexSet self, uint64_t idx);
        void            (*addRange)(struct CIndexSet self, Range range);
        void            (*removeRange)(struct CIndexSet self, Range range);
        void            (*intersectsRange)(struct CIndexSet self, Range range);
        void            (*addIndexSet)(struct CIndexSet self, struct CIndexSet indexSet);
        void            (*removeIndexSet)(struct CIndexSet self, struct CIndexSet indexSet);
        void            (*intersectsIndexSet)(struct CIndexSet self, struct CIndexSet indexSet);
        Range           (*range)(struct CIndexSet self, unsigned int idx);
        unsigned int    (*rangesCount)(struct CIndexSet self);
    };
    typedef struct CIndexSet CIndexSet;

    CIndexSet newCIndexSet();
    CIndexSet newCIndexSetWithRange(Range range);
    CIndexSet newCIndexSetWithIndex(uint64_t idx);
    void deleteCIndexSet(CIndexSet self);
    

    extern Range RangeEmpty;
    Range RangeMake(uint64_t location, uint64_t length);
    Range RangeIntersection(Range range1, Range range2);
    bool RangeHasIntersection(Range range1, Range range2);
    uint64_t RangeLeftBound(Range range);
    uint64_t RangeRightBound(Range range);
    //    CIndexSet RangeRemoveRange(Range range1, Range range2);
    //    CIndexSet RangeUnion(Range range1, Range range2);
    //    const UChar* MCORangeToString(Range range);
    //    Range RangeFromString(const UChar* rangeString);

#ifdef __cplusplus
}

CIndexSet newCIndexSet(mailcore::IndexSet *set);
#endif

#endif
