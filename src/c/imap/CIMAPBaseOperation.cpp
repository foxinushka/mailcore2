#include "COperation+Private.h"
#include "CIMAPBaseOperation.h"
#include "CIMAPBaseOperation+Private.h"

class CIMAPBaseOperationIMAPCallback : public mailcore::IMAPOperationCallback {
public:
    CIMAPBaseOperationIMAPCallback(CIMAPBaseOperation * op)
    {
        mOperation = op;
    }
    
    virtual ~CIMAPBaseOperationIMAPCallback()
    {
    }
    
    virtual void bodyProgress(mailcore::IMAPOperation * session, unsigned int current, unsigned int maximum) {
        mOperation->bodyProgress(current, maximum);
    }
    
    virtual void itemProgress(mailcore::IMAPOperation * session, unsigned int current, unsigned int maximum) {
        mOperation->itemProgress(current, maximum);
    }
    
private:
    CIMAPBaseOperation * mOperation;
};

extern "C" CIMAPBaseOperation newCIMAPBaseOperation(mailcore::Operation* operationRef) {
    CIMAPBaseOperation operation;
    operation.cOperation = newCOperation(operationRef);
    operation.cOperation.inheritor = &operation;
    
    CIMAPBaseOperationIMAPCallback *callback = new CIMAPBaseOperationIMAPCallback(&operation);
    operation._callback = reinterpret_cast<void *>(callback);
    reinterpret_cast<mailcore::IMAPOperation *>(operationRef)->setImapCallback(callback);
    
    return operation;
}

extern "C" void deleteCIMAPBaseOperation(CIMAPBaseOperation *operation) {
    delete reinterpret_cast<CIMAPBaseOperationIMAPCallback *>(operation->_callback);
}
