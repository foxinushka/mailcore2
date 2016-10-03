#ifndef MAILCORE_CBASE_H
#define MAILCORE_CBASE_H

#include <stdbool.h>

#include <MailCore/MCICUTypes.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CData {
        const char* bytes;
        unsigned int lenght;
    };
    typedef struct CData CData;
    
#ifdef __cplusplus
}
#endif

#endif
