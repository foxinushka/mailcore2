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
    };
    typedef struct CIndexSet CIndexSet;
    
    unsigned int    CIndexSet_count(struct CIndexSet self)
                    CF_SWIFT_NAME(getter:CIndexSet.count(self:));
    
    void            CIndexSet_addIndex(struct CIndexSet self, uint64_t idx)
                    CF_SWIFT_NAME(CIndexSet.addIndex(self:idx:));
    
    void            CIndexSet_removeIndex(struct CIndexSet self, uint64_t idx)
                    CF_SWIFT_NAME(CIndexSet.removeIndex(self:idx:));
    
    bool            CIndexSet_containsIndex(struct CIndexSet self, uint64_t idx)
                    CF_SWIFT_NAME(CIndexSet.containsIndex(self:idx:));
    
    void            CIndexSet_addRange(struct CIndexSet self, Range range)
                    CF_SWIFT_NAME(CIndexSet.addRange(self:range:));
    
    void            CIndexSet_removeRange(struct CIndexSet self, Range range)
                    CF_SWIFT_NAME(CIndexSet.removeRange(self:range:));
    
    void            CIndexSet_intersectsRange(struct CIndexSet self, Range range)
                    CF_SWIFT_NAME(CIndexSet.intersectsRange(self:range:));
    
    void            CIndexSet_addIndexSet(struct CIndexSet self, struct CIndexSet indexSet)
                    CF_SWIFT_NAME(CIndexSet.addIndexSet(self:indexSet:));
    
    void            CIndexSet_removeIndexSet(struct CIndexSet self, struct CIndexSet indexSet)
                    CF_SWIFT_NAME(CIndexSet.removeIndexSet(self:indexSet:));
    
    void            CIndexSet_intersectsIndexSet(struct CIndexSet self, struct CIndexSet indexSet)
                    CF_SWIFT_NAME(CIndexSet.intersectsIndexSet(self:indexSet:));
    
    Range           CIndexSet_range(struct CIndexSet self, unsigned int idx)
                    CF_SWIFT_NAME(CIndexSet.range(self:idx:));
    
    unsigned int    CIndexSet_rangesCount(struct CIndexSet self)
                    CF_SWIFT_NAME(CIndexSet.rangesCount(self:));
    
    

    CIndexSet       CIndexSet_new()
                    CF_SWIFT_NAME(CIndexSet.init());
    
    CIndexSet       CIndexSet_new_WithRange(Range range)
                    CF_SWIFT_NAME(CIndexSet.init(range:));
    
    CIndexSet       CIndexSet_new_WithIndex(uint64_t idx)
                    CF_SWIFT_NAME(CIndexSet.init(idx:));
    
    void            CIndexSet_release(CIndexSet self)
                    CF_SWIFT_NAME(CIndexSet.release(self:));
    

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

CIndexSet CIndexSet_new(mailcore::IndexSet *set);
#endif

#endif
