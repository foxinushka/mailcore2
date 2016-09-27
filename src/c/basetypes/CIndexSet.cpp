#include <MailCore/MCCore.h>

extern "C" {
	#include "CIndexSet.h"

	CIndexSet newCIndexSetWithRange(uint64_t start, uint64_t end) {
        return newCIndexSet(mailcore::IndexSet::indexSetWithRange(mailcore::RangeMake(start, end)));
	}

	void deleteCIndexSet(CIndexSet indexSet) {
	    delete reinterpret_cast<mailcore::IndexSet *>(indexSet.self);
	}
}

CIndexSet newCIndexSet(mailcore::IndexSet *set) {
    CIndexSet indexSet;
    indexSet.self = set;
    return indexSet;
}

mailcore::IndexSet* cast(CIndexSet *self) {
    return reinterpret_cast<mailcore::IndexSet*>(self->self);
}
