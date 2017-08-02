#ifndef MAILCORE_CDATA_H
#define MAILCORE_CDATA_H

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"

#ifdef __cplusplus

namespace mailcore {
    class Data;
}

extern "C" {
#endif
    
    struct CData {
#ifdef __cplusplus
        mailcore::Data*   instance;
#else
        void*               instance;
#endif
    };
    typedef struct CData CData;
    
    CData               CData_new(const char* bytes, unsigned int length)
                        CF_SWIFT_NAME(CData.init(bytes:length:));
    
    const char*         CData_bytes(CData self)
                        CF_SWIFT_NAME(getter:CData.bytes(self:));
    
    unsigned int        CData_length(CData self)
                        CF_SWIFT_NAME(getter:CData.length(self:));
    
#ifdef __cplusplus
}

CData CData_new(mailcore::Data* data);
#endif

#endif
