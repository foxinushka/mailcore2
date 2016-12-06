#include <MailCore/MCAsync.h>
#include "CSMTPOperation.h"

class CSMTPOperationCallback : public mailcore::SMTPOperationCallback {
public:
    CSMTPOperationCallback(const void* userInfo, CProgressBlock block)
    {
        mBlock = block;
        mUserInfo = userInfo;
    }
    
    virtual ~CSMTPOperationCallback()
    {
        mBlock = NULL;
        mUserInfo = NULL;
    }
    
    virtual void bodyProgress(mailcore::SMTPOperation * session, unsigned int current, unsigned int maximum) {
        mBlock(mUserInfo, current, maximum);
    }
    
private:
    const void* mUserInfo;
    CProgressBlock mBlock;
};

struct CSMTPOperation setProgressBlocks(struct CSMTPOperation self, CProgressBlock progressBlock, const void* userInfo);

CSMTPOperation newCSMTPOperation(mailcore::SMTPOperation* operation) {
    CSMTPOperation self;
    self.cOperation = newCOperation(operation);
    self.instance = operation;
    
    self.setProgressBlocks = &setProgressBlocks;
    
    return self;
}

void deleteCSMTPOperation(CSMTPOperation self) {
    delete self._callback;
}

ErrorCode error(struct CSMTPOperation self) {
    return static_cast<ErrorCode>((int)self.instance->error());
}

CSMTPOperation setProgressBlocks(struct CSMTPOperation self, CProgressBlock progressBlock, const void* userInfo) {
    self._callback = new CSMTPOperationCallback(userInfo, progressBlock);
    self.instance->setSmtpCallback(self._callback);
    return self;
}
