#include <MailCore/MCAsync.h>
#include "CSMTPOperation.h"

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

ErrorCode error(struct CSMTPOperation self) {
    return static_cast<ErrorCode>((int)self.instance->error());
}

CSMTPOperation setProgressBlocks(struct CSMTPOperation self, CProgressBlock progressBlock, const void* userInfo) {
    self._callback->mBlock = progressBlock;
    self._callback->mUserInfo = userInfo;
    return self;
}

const UChar* lastSMTPResponse(struct CSMTPOperation self) {
    return self.instance->lastSMTPResponse()->unicodeCharacters();
}

int lastSMTPResponseCode(struct CSMTPOperation self) {
    return self.instance->lastSMTPResponseCode();
}

CSMTPOperation newCSMTPOperation(mailcore::SMTPOperation* operation) {
    CSMTPOperation self;
    self.cOperation = newCOperation(operation);
    self.instance = operation;
    self._callback = new CSMTPOperationCallback();
    self.instance->setSmtpCallback(self._callback);
    
    self.setProgressBlocks = &setProgressBlocks;
    self.error = &error;
    self.lastSMTPResponseCode = &lastSMTPResponseCode;
    self.lastSMTPResponse = &lastSMTPResponse;
    
    return self;
}

void deleteCSMTPOperation(CSMTPOperation self) {
    delete self._callback;
}
