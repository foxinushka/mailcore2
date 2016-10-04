#include <MailCore/MCAsync.h>
#include "CSMTPOperation.h"

class CSMTPOperationCallback : public mailcore::SMTPOperationCallback {
public:
    CSMTPOperationCallback(CProgressBlock block)
    {
        mBlock = block;
    }
    
    virtual ~CSMTPOperationCallback()
    {
        mBlock = NULL;
    }
    
    virtual void bodyProgress(mailcore::SMTPOperation * session, unsigned int current, unsigned int maximum) {
        mBlock(current, maximum);
    }
    
private:
    CProgressBlock mBlock;
};

struct CSMTPOperation       setProgressBlocks(struct CSMTPOperation self, CProgressBlock progressBlock);

CSMTPOperation newCSMTPOperation(mailcore::SMTPOperation* operation) {
    CSMTPOperation self;
    self.cOperation = newCOperation(operation);
    self.instance = operation;
    return self;
}

void deleteCSMTPOperation(CSMTPOperation self) {
    delete self._callback;
}

ErrorCode error(struct CSMTPOperation self) {
    return static_cast<ErrorCode>((int)self.instance->error());
}

CSMTPOperation setProgressBlocks(struct CSMTPOperation self, CProgressBlock progressBlock) {
    self._callback = new CSMTPOperationCallback(progressBlock);
    self.instance->setSmtpCallback(self._callback);
    return self;
}
