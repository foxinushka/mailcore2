#ifndef MAILCORE_CIMAP_BASE_OPERATION_H
#define MAILCORE_CIMAP_BASE_OPERATION_H

#include <MailCore/COperation.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef struct CIMAPAsyncSession CIMAPAsyncSession;
    
    struct CIMAPBaseOperation {
        COperation                                  cOperation;
        ref                                         inheritor;
        /*CIMAPBaseOperationIMAPCallback*/ref       _callback;
        
        CIMAPAsyncSession *session;
        
        //virtual
        void (*bodyProgress)(unsigned int current, unsigned int maximum);
        void (*itemProgress)(unsigned int current, unsigned int maximum);
    };
    typedef struct CIMAPBaseOperation CIMAPBaseOperation;

    void deleteCIMAPBaseOperation(CIMAPBaseOperation *operation);

#ifdef __cplusplus
}
#endif

#endif
