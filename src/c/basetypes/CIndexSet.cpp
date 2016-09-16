#include <MailCore/MCCore.h>

extern "C" {
	#include "CIndexSet.h"

	CIndexSet newCIndexSetWithRange(uint64_t start, uint64_t end) {
	    CIndexSet indexSet;
	    indexSet.self = reinterpret_cast<void *>(mailcore::IndexSet::indexSetWithRange(mailcore::RangeMake(start, end)));
	    return indexSet;
	}

	void deleteCIndexSet(CIndexSet indexSet) {
	    delete reinterpret_cast<mailcore::IndexSet *>(indexSet.self);
	}
}
