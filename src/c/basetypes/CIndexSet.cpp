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
    return newCIndexSet(indexSet);
}

CIndexSet RangeUnion(Range range1, Range range2)
{
    mailcore::Range mcRange1 = cast(range1);
    mailcore::Range mcRange2 = cast(range2);
    mailcore::IndexSet * indexSet = mailcore::RangeUnion(mcRange1, mcRange2);
    return newCIndexSet(indexSet);
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

CIndexSet newCIndexSet() {
    return newCIndexSet(new mailcore::IndexSet());
}

unsigned int    count(struct CIndexSet self);
void            addIndex(struct CIndexSet self, uint64_t idx);
void            removeIndex(struct CIndexSet self, uint64_t idx);
bool            containsIndex(struct CIndexSet self, uint64_t idx);
void            addRange(struct CIndexSet self, Range range);
void            removeRange(struct CIndexSet self, Range range);
void            intersectsRange(struct CIndexSet self, Range range);
void            addIndexSet(struct CIndexSet self, struct CIndexSet indexSet);
void            removeIndexSet(struct CIndexSet self, struct CIndexSet indexSet);
void            intersectsIndexSet(struct CIndexSet self, struct CIndexSet indexSet);
Range           range(struct CIndexSet self, unsigned int idx);
unsigned int    rangesCount(struct CIndexSet self);

CIndexSet newCIndexSetWithRange(Range range) {
    return newCIndexSet(mailcore::IndexSet::indexSetWithRange(cast(range)));
}

CIndexSet newCIndexSetWithIndex(uint64_t idx) {
    return newCIndexSet(mailcore::IndexSet::indexSetWithIndex(idx));
}

CIndexSet newCIndexSet(mailcore::IndexSet *set) {
    CIndexSet self;
    self.instance = set;
    self.instance->retain();

    self.count = &count;
    self.addIndex = &addIndex;
    self.removeIndex = &removeIndex;
    self.containsIndex = &containsIndex;
    self.addRange = &addRange;
    self.removeRange = &removeRange;
    self.intersectsRange = &intersectsRange;
    self.addIndexSet = &addIndexSet;
    self.removeIndexSet = &removeIndexSet;
    self.intersectsIndexSet = &intersectsIndexSet;
    self.range = &range;
    self.rangesCount = &rangesCount;

    return self;
}

void deleteCIndexSet(CIndexSet indexSet) {
    C_SAFE_RELEASE(indexSet.instance);
}

unsigned int count(struct CIndexSet self) {
    return self.instance->count();
}

void addIndex(struct CIndexSet self, uint64_t idx) {
    return self.instance->addIndex(idx);
}

void removeIndex(struct CIndexSet self, uint64_t idx) {
    return self.instance->removeIndex(idx);
}

bool containsIndex(struct CIndexSet self, uint64_t idx) {
    return self.instance->containsIndex(idx);
}

void addRange(struct CIndexSet self, Range range) {
    return self.instance->addRange(cast(range));
}

void removeRange(struct CIndexSet self, Range range) {
    return self.instance->removeRange(cast(range));
}

void intersectsRange(struct CIndexSet self, Range range) {
    return self.instance->intersectsRange(cast(range));
}

void addIndexSet(struct CIndexSet self, struct CIndexSet indexSet) {
    return self.instance->addIndexSet(indexSet.instance);
}

void removeIndexSet(struct CIndexSet self, struct CIndexSet indexSet) {
    return self.instance->removeIndexSet(indexSet.instance);
}

void intersectsIndexSet(struct CIndexSet self, struct CIndexSet indexSet) {
    return self.instance->intersectsIndexSet(indexSet.instance);
}

Range range(struct CIndexSet self, unsigned int idx) {
    mailcore::Range range = self.instance->allRanges()[idx];
    return RangeMake(range.location, range.length);
}

unsigned int rangesCount(struct CIndexSet self) {
    return self.instance->rangesCount();
}


