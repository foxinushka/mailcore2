#include <MailCore/MCCore.h>
#include "CIndexSet.h"

CIndexSet newCIndexSet() {
    return newCIndexSet(new mailcore::IndexSet());
}

void    enumerateRanges(struct CIndexSet self , CIndexSetEnumerateRangesBlock block);
void    addRange(struct CIndexSet self, uint64_t location, uint64_t length);

CIndexSet newCIndexSet(mailcore::IndexSet *set) {
    CIndexSet indexSet;
    indexSet.nativeInstance = set;
    
    indexSet.enumerateRanges = &enumerateRanges;
    indexSet.addRange = &addRange;
    
    return indexSet;
}

mailcore::IndexSet* cast(CIndexSet self) {
    return reinterpret_cast<mailcore::IndexSet*>(self.nativeInstance);
}

void deleteCIndexSet(CIndexSet indexSet) {
    
}

void enumerateRanges(struct CIndexSet self , CIndexSetEnumerateRangesBlock block) {
    mailcore::Range * allRanges = cast(self)->allRanges();
    for(unsigned int i = 0 ; i < cast(self)->rangesCount() ; i ++) {
        block(allRanges[i].location, allRanges[i].length);
    }
}

void addRange(struct CIndexSet self, uint64_t location, uint64_t length) {
    cast(self)->addRange(mailcore::RangeMake(location, length));
}
