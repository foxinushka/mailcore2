#ifndef MAILCORE_CINDEX_SET_H
#define MAILCORE_CINDEX_SET_H

#include "stdint.h"
#include "CBase.h"
#include "CArray.h"
#include "CData.h"

#ifdef __cplusplus

namespace mailcore {
    class IndexSet;
}

extern "C" {
#endif
    
    struct Range {
        /** first integer of the range.*/
        uint64_t location;
        
        /** length of the range.*/
        uint64_t length;
    };
    typedef struct Range Range;
    
    extern Range RangeEmpty;
    Range RangeMake(uint64_t location, uint64_t length);
    Range RangeIntersection(Range range1, Range range2);
    bool RangeHasIntersection(Range range1, Range range2);
    uint64_t RangeLeftBound(Range range);
    uint64_t RangeRightBound(Range range);
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIndexSet, mailcore::IndexSet)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIndexSet)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CIndexSet, uint64_t, count)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, void, addIndex, uint64_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, void, removeIndex, uint64_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, bool, containsIndex, uint64_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, void, addRange, Range)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, void, removeRange, Range)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, void, intersectsRange, Range)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, void, addIndexSet, CIndexSet)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, void, removeIndexSet, CIndexSet)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, void, intersectsIndexSet, CIndexSet)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, Range, range, unsigned int)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIndexSet, unsigned int, rangesCount)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIndexSet, CIndexSet, init)
    
    CMAILCORE_EXPORT CIndexSet CIndexSet_new_WithRange(Range range)
    CF_SWIFT_NAME(CIndexSet.init(range:));
    
    CMAILCORE_EXPORT CIndexSet CIndexSet_new_WithIndex(uint64_t idx)
    CF_SWIFT_NAME(CIndexSet.init(idx:));

#ifdef __cplusplus
}
#endif

#endif
