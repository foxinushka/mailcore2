#include <MailCore/MCAsync.h>
#include "COperation.h"


class COperationCompletionCallback : public mailcore::Object, public mailcore::OperationCallback {
public:
    COperationCompletionCallback(COperation *op) {
        mOperation = op;
    }
    
    virtual void operationFinished(COperation * op)
    {
        mOperation->_operationCompleted(mOperation);
    }
    
private:
    COperation *mOperation;
};

extern "C" {
    bool COperationIsCanceled(COperation *operation);
    void COperationCancel(COperation *operation);
    void COperationStart(COperation *operation);
    void COperation_operationCompleted(COperation *operation);
    
	COperation initCOperation(ref operationRef) {
	    COperation operation;
	    operation.self = operationRef;
        
        COperationCompletionCallback *callback = new COperationCompletionCallback(&operation);
        operation._callback = reinterpret_cast<void *>(callback);
        reinterpret_cast<mailcore::Operation *>(operationRef)->setCallback(callback);
        
        operation.isCanceled = &COperationIsCanceled;
        operation.cancel = &COperationCancel;
        operation.start = &COperationStart;
        operation._operationCompleted = &COperation_operationCompleted;
        
	    return operation;
	}

	void deleteCOperation(COperation operation) {
        reinterpret_cast<mailcore::Operation *>(operation.self)->release();
        reinterpret_cast<COperationCompletionCallback *>(operation._callback)->release();
	}
    
    bool COperationIsCanceled(COperation *operation) {
        return reinterpret_cast<mailcore::Operation *>(operation->self)->isCancelled();
    }
    
    void COperationCancel(COperation *operation) {
        if (operation->_started) {
            operation->_started = false;
        }
        reinterpret_cast<mailcore::Operation *>(operation->self)->cancel();
    }
    
    void COperationStart(COperation *operation) {
        operation->_started = true;
        reinterpret_cast<mailcore::Operation *>(operation->self)->start();
    }
    
    void COperation_operationCompleted(COperation *operation) {
        operation->_started = false;
        operation->operationCompleted(operation);
    }
}
