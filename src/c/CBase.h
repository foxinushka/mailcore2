#ifndef MAILCORE_CBASE_H
#define MAILCORE_CBASE_H

#include <stdbool.h>
#include <stdint.h>
#include <MailCore/MCICUTypes.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CData {
        const char* bytes;
        unsigned int length;
    };
    typedef struct CData CData;
    
    CData newCData(const char* bytes, unsigned int length);
    
#ifdef __cplusplus
}

namespace mailcore {
    class Data;
}

CData newCData(mailcore::Data data);
#endif

#endif
