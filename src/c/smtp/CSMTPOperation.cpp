#include <MailCore/MCAsync.h>
#include "CSMTPOperation.h"
#include "MailCoreString.h"

#include "CBase+Private.h"

#define nativeType mailcore::SMTPOperation
#define structName CSMTPOperation

C_SYNTHESIZE_COBJECT_CAST()

class CSMTPOperationCallback : public mailcore::SMTPOperationCallback {
public:
    CSMTPOperationCallback()
    {

    }
    
    virtual ~CSMTPOperationCallback()
    {
        mBlock = NULL;
        mUserInfo = NULL;
    }
    
    virtual void bodyProgress(mailcore::SMTPOperation * session, unsigned int current, unsigned int maximum) {
        if (mBlock != NULL) {
            mBlock(mUserInfo, current, maximum);
        }
    }
    
    const void* mUserInfo = NULL;
    CProgressBlock mBlock = NULL;
};

ErrorCode CSMTPOperation_error(struct CSMTPOperation self) {
    return static_cast<ErrorCode>((int)self.instance->error());
}

CSMTPOperation CSMTPOperation_setProgressBlocks(struct CSMTPOperation self, CProgressBlock progressBlock, const void* userInfo) {
    self._callback->mBlock = progressBlock;
    self._callback->mUserInfo = userInfo;
    return self;
}

C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, lastSMTPResponse)
C_SYNTHESIZE_FUNC_WITH_SCALAR(int, lastSMTPResponseCode)

CSMTPOperation CSMTPOperation_new(mailcore::SMTPOperation* operation) {
    CSMTPOperation self;
    self.cOperation = COperation_new(operation);
    self.instance = operation;
    self._callback = new CSMTPOperationCallback();
    self.instance->setSmtpCallback(self._callback);
    return self;
}

void CSMTPOperation_retain(CSMTPOperation self) {
    self.instance->retain();
}

void CSMTPOperation_release(CSMTPOperation self) {
    self.instance->release();
    delete self._callback;
}
