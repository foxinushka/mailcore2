#include "COperation.h"
#include "CIMAPBaseOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPOperation
#define structName CIMAPBaseOperation

class CIMAPBaseOperationIMAPCallback : public mailcore::IMAPOperationCallback {
public:
    CIMAPBaseOperationIMAPCallback(const void* userInfo, CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock)
    {
        mUserInfo = userInfo;
        mItemProgressBlock = itemProgressBlock;
        mBodyProgressBlock = bodyProgressBlock;
    }
    
    virtual ~CIMAPBaseOperationIMAPCallback()
    {
        mUserInfo = NULL;
        mItemProgressBlock = NULL;
        mBodyProgressBlock = NULL;
    }
    
    virtual void bodyProgress(mailcore::IMAPOperation * session, unsigned int current, unsigned int maximum) {
        mBodyProgressBlock(mUserInfo, current, maximum);
    }
    
    virtual void itemProgress(mailcore::IMAPOperation * session, unsigned int current, unsigned int maximum) {
        mItemProgressBlock(mUserInfo, current, maximum);
    }
    
private:
    const void* mUserInfo;
    CIMAPProgressBlock mItemProgressBlock;
    CIMAPProgressBlock mBodyProgressBlock;
};

CIMAPBaseOperation        setProgressBlocks(struct CIMAPBaseOperation self, CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock, const void* userInfo);
ErrorCode   error(struct CIMAPBaseOperation self);

CIMAPBaseOperation newCIMAPBaseOperation(mailcore::IMAPOperation* operation) {
    CIMAPBaseOperation self;
    self.cOperation = newCOperation(operation);
    self.instance = operation;
    
    self.setProgressBlocks = &setProgressBlocks;
    self.error = &error;
    
    return self;
}

ErrorCode error(struct CIMAPBaseOperation self) {
    return static_cast<ErrorCode>(self.instance->error());
}

CIMAPBaseOperation setProgressBlocks(struct CIMAPBaseOperation self, CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock, const void* userInfo) {
    CIMAPBaseOperationIMAPCallback *callback = new CIMAPBaseOperationIMAPCallback(userInfo, itemProgressBlock, bodyProgressBlock);
    self._callback = callback;
    self.instance->setImapCallback(callback);
    return self;
}

void deleteCIMAPBaseOperation(CIMAPBaseOperation operation) {
    if (operation._callback != NULL) {
        delete operation._callback;
    }
}
