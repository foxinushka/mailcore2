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

void        setProgressBlocks(struct CIMAPBaseOperation *self, CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock);
ErrorCode   error(struct CIMAPBaseOperation *self);

extern "C" CIMAPBaseOperation newCIMAPBaseOperation(mailcore::IMAPOperation* operation) {
    CIMAPBaseOperation self;
    self.cOperation = newCOperation(operation);
    
    self.setProgressBlocks = &setProgressBlocks;
    self.error = &error;
    
    return self;
}

ErrorCode error(struct CIMAPBaseOperation *self) {
    return static_cast<ErrorCode>(reinterpret_cast<nativeType*>(self->cOperation.nativeInstance)->error());
}

void setProgressBlocks(struct CIMAPBaseOperation *self, CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock) {
    CIMAPBaseOperationIMAPCallback *callback = new CIMAPBaseOperationIMAPCallback(itemProgressBlock, bodyProgressBlock);
    self->_callback = reinterpret_cast<void *>(callback);
    reinterpret_cast<nativeType*>(self->cOperation.nativeInstance)->setImapCallback(callback);
}

extern "C" void deleteCIMAPBaseOperation(CIMAPBaseOperation *operation) {
    delete reinterpret_cast<CIMAPBaseOperationIMAPCallback *>(operation->_callback);
}
