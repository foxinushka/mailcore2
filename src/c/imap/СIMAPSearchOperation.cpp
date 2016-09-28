#include "СIMAPSearchOperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::IMAPSearchOperation
#define structName CIMAPSearchOperation

CIndexSet uids(struct CIMAPSearchOperation self);

CIMAPSearchOperation newCIMAPSearchOperation(mailcore::IMAPSearchOperation *operation){
    CIMAPSearchOperation self;
    self.baseOperation = newCIMAPBaseOperation(operation);
    
    self.uids = &uids;
    
    return self;
}

mailcore::IMAPSearchOperation * cast(CIMAPSearchOperation self) {
    return reinterpret_cast<mailcore::IMAPSearchOperation *>(self.baseOperation.cOperation.nativeInstance);
}

void deleteCIMAPSearchOperation(CIMAPSearchOperation operation) {

}

CIndexSet uids(CIMAPSearchOperation self) {
    return newCIndexSet(cast(self)->uids());
}
