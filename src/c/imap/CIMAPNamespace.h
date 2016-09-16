#ifndef MAILCORE_CIMAP_NAMESPACE_H
#define MAILCORE_CIMAP_NAMESPACE_H

#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPNamespace {
        ref self;
    };
    typedef struct CIMAPNamespace CIMAPNamespace;

    CIMAPNamespace newCIMAPNamespace();
    void deleteCIMAPNamespace(CIMAPNamespace self);

#ifdef __cplusplus
}
#endif

#endif