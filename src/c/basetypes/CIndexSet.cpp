#include <MailCore/MCCore.h>
#include "CIndexSet.h"
#include "CBase+Private.h"

Range RangeEmpty = {UINT64_MAX, 0};

Range RangeMake(uint64_t location, uint64_t length)
{
    Range result;
    result.location = location;
    result.length = length;
    return result;
}

mailcore::Range cast(Range range)
{
    return mailcore::RangeMake(range.location, range.length);
}

CIndexSet RangeRemoveRange(Range range1, Range range2)
{
    mailcore::Range mcRange1 = cast(range1);
    mailcore::Range mcRange2 = cast(range2);
    mailcore::IndexSet * indexSet = mailcore::RangeRemoveRange(mcRange1, mcRange2);
    return CIndexSet_new(indexSet);
}

CIndexSet RangeUnion(Range range1, Range range2)
{
    mailcore::Range mcRange1 = cast(range1);
    mailcore::Range mcRange2 = cast(range2);
    mailcore::IndexSet * indexSet = mailcore::RangeUnion(mcRange1, mcRange2);
    return CIndexSet_new(indexSet);
}

Range RangeWithMCRange(mailcore::Range range)
{
    Range result;
    result.location = range.location;
    result.length = range.length;
    return result;
}

Range RangeIntersection(Range range1, Range range2)
{
    mailcore::Range mcRange1 = cast(range1);
    mailcore::Range mcRange2 = cast(range2);
    mailcore::Range mcResult = mailcore::RangeIntersection(mcRange1, mcRange2);
    return RangeMake(mcResult.location, mcResult.length);
}

bool RangeHasIntersection(Range range1, Range range2)
{
    mailcore::Range mcRange1 = cast(range1);
    mailcore::Range mcRange2 = cast(range2);
    return mailcore::RangeHasIntersection(mcRange1, mcRange2);
}

uint64_t RangeLeftBound(Range range)
{
    mailcore::Range mcRange = cast(range);
    return mailcore::RangeLeftBound(mcRange);
}

uint64_t RangeRightBound(Range range)
{
    mailcore::Range mcRange = cast(range);
    return mailcore::RangeRightBound(mcRange);
}

CIndexSet CIndexSet_new() {
    return CIndexSet_new(new mailcore::IndexSet());
}

CIndexSet CIndexSet_new_WithRange(Range range) {
    return CIndexSet_new(mailcore::IndexSet::indexSetWithRange(cast(range)));
}

CIndexSet CIndexSet_new_WithIndex(uint64_t idx) {
    return CIndexSet_new(mailcore::IndexSet::indexSetWithIndex(idx));
}

CIndexSet CIndexSet_new(mailcore::IndexSet *set) {
    CIndexSet self;
    self.instance = set;
    if (self.instance != NULL) {
        self.instance->retain();
    }
    return self;
}

void CIndexSet_release(CIndexSet indexSet) {
    C_SAFE_RELEASE(indexSet.instance);
}

unsigned int CIndexSet_count(struct CIndexSet self) {
    return self.instance->count();
}

void CIndexSet_addIndex(struct CIndexSet self, uint64_t idx) {
    return self.instance->addIndex(idx);
}

void CIndexSet_removeIndex(struct CIndexSet self, uint64_t idx) {
    return self.instance->removeIndex(idx);
}

bool CIndexSet_containsIndex(struct CIndexSet self, uint64_t idx) {
    return self.instance->containsIndex(idx);
}

void CIndexSet_addRange(struct CIndexSet self, Range range) {
    return self.instance->addRange(cast(range));
}

void CIndexSet_removeRange(struct CIndexSet self, Range range) {
    return self.instance->removeRange(cast(range));
}

void CIndexSet_intersectsRange(struct CIndexSet self, Range range) {
    return self.instance->intersectsRange(cast(range));
}

void CIndexSet_addIndexSet(struct CIndexSet self, struct CIndexSet indexSet) {
    return self.instance->addIndexSet(indexSet.instance);
}

void CIndexSet_removeIndexSet(struct CIndexSet self, struct CIndexSet indexSet) {
    return self.instance->removeIndexSet(indexSet.instance);
}

void CIndexSet_intersectsIndexSet(struct CIndexSet self, struct CIndexSet indexSet) {
    return self.instance->intersectsIndexSet(indexSet.instance);
}

Range CIndexSet_range(struct CIndexSet self, unsigned int idx) {
    mailcore::Range range = self.instance->allRanges()[idx];
    return RangeMake(range.location, range.length);
}

unsigned int CIndexSet_rangesCount(struct CIndexSet self) {
    return self.instance->rangesCount();
}

CIndexSet CIndexSet_copy(struct CIndexSet self) {
    return CIndexSet_new(reinterpret_cast<mailcore::IndexSet *>(self.instance->copy()));
}


