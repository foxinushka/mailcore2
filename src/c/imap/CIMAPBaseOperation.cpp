#include "COperation.h"
#include "CIMAPBaseOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPOperation
#define structName CIMAPBaseOperation

class CIMAPBaseOperationIMAPCallback : public mailcore::IMAPOperationCallback {
public:
    CIMAPBaseOperationIMAPCallback(CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock)
    {
        mItemProgressBlock = itemProgressBlock;
        mBodyProgressBlock = bodyProgressBlock;
    }
    
    virtual ~CIMAPBaseOperationIMAPCallback()
    {
    }
    
    virtual void bodyProgress(mailcore::IMAPOperation * session, unsigned int current, unsigned int maximum) {
        mBodyProgressBlock(current, maximum);
    }
    
    virtual void itemProgress(mailcore::IMAPOperation * session, unsigned int current, unsigned int maximum) {
        mItemProgressBlock(current, maximum);
    }
    
private:
    CIMAPProgressBlock mItemProgressBlock;
    CIMAPProgressBlock mBodyProgressBlock;
};

void        setProgressBlocks(struct CIMAPBaseOperation self, CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock);
ErrorCode   error(struct CIMAPBaseOperation self);

CIMAPBaseOperation newCIMAPBaseOperation(mailcore::IMAPOperation* operation) {
    CIMAPBaseOperation self;
    self.cOperation = newCOperation(operation);
    
    self.setProgressBlocks = &setProgressBlocks;
    self.error = &error;
    
    return self;
}

mailcore::IMAPOperation* cast(CIMAPBaseOperation self) {
    return reinterpret_cast<mailcore::IMAPOperation*>(self.cOperation.nativeInstance);
}

ErrorCode error(struct CIMAPBaseOperation self) {
    return static_cast<ErrorCode>(cast(self)->error());
}

void setProgressBlocks(struct CIMAPBaseOperation self, CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock) {
    CIMAPBaseOperationIMAPCallback *callback = new CIMAPBaseOperationIMAPCallback(itemProgressBlock, bodyProgressBlock);
    self._callback = reinterpret_cast<void *>(callback);
    cast(self)->setImapCallback(callback);
}

extern "C" void deleteCIMAPBaseOperation(CIMAPBaseOperation *operation) {
    //TODO: check
    //delete reinterpret_cast<CIMAPBaseOperationIMAPCallback *>(operation->_callback);
}
