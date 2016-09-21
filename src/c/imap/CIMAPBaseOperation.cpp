#include <MailCore/MCAsync.h>
#include <MailCore/COperation.h>
#include "CIMAPBaseOperation.h"

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

extern "C" {
    CIMAPBaseOperation initCIMAPBaseOperation(/*mailcore::Operation*/ref operationRef) {
	    CIMAPBaseOperation operation;
	    operation.ancestor = initCOperation(operationRef);
        //operation.ancestor.inheritor = &operation;
        
        CIMAPBaseOperationIMAPCallback *callback = new CIMAPBaseOperationIMAPCallback(&operation);
        operation._callback = reinterpret_cast<void *>(callback);
        reinterpret_cast<mailcore::IMAPOperation *>(operationRef)->setImapCallback(callback);
        
	    return operation;
	}

	void deleteCIMAPBaseOperation(CIMAPBaseOperation *operation) {
        delete reinterpret_cast<CIMAPBaseOperationIMAPCallback *>(operation->_callback);
	}
}
