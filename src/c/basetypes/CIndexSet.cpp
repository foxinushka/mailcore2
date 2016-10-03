#include <MailCore/MCCore.h>
#include "CIndexSet.h"

CIndexSet newCIndexSet() {
    return newCIndexSet(new mailcore::IndexSet());
}

void    enumerateRanges(struct CIndexSet self , CIndexSetEnumerateRangesBlock block);
void    addRange(struct CIndexSet self, uint64_t location, uint64_t length);

CIndexSet newCIndexSet(mailcore::IndexSet *set) {
    CIndexSet indexSet;
    indexSet.instance = set;
    
    indexSet.enumerateRanges = &enumerateRanges;
    indexSet.addRange = &addRange;
    
    return indexSet;
}

void deleteCIndexSet(CIndexSet indexSet) {
    
}

void enumerateRanges(struct CIndexSet self , CIndexSetEnumerateRangesBlock block) {
    mailcore::Range * allRanges = self.instance->allRanges();
    for(unsigned int i = 0 ; i < self.instance->rangesCount() ; i ++) {
        block(allRanges[i].location, allRanges[i].length);
    }
}

void addRange(struct CIndexSet self, uint64_t location, uint64_t length) {
    self.instance->addRange(mailcore::RangeMake(location, length));
}
