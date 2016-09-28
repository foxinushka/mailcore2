#include <MailCore/MCCore.h>
#include "CIndexSet.h"

CIndexSet newCIndexSet(mailcore::IndexSet *set) {
    CIndexSet indexSet;
    indexSet.nativeInstance = set;
    return indexSet;
}

mailcore::IndexSet* cast(CIndexSet self) {
    return reinterpret_cast<mailcore::IndexSet*>(self.nativeInstance);
}

void deleteCIndexSet(CIndexSet indexSet) {
    
}
