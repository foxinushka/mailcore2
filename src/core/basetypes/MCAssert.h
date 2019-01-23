#ifndef MAILCORE_MCASSERT_H

#define MAILCORE_MCASSERT_H

#include <MailCore/MCUtils.h>

#define MCAssert(cond) MCAssertInternal(__FILE__, __LINE__, cond, #cond)

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef void (*MSAssertHandler)(const char * filename, unsigned int line, const char * condString);
    
    MAILCORE_EXPORT
    void setMCAssertHandler(MSAssertHandler handler) CLANG_ANALYZER_NORETURN;
    
    MAILCORE_EXPORT
	void MCAssertInternal(const char * filename, unsigned int line, int cond, const char * condString) CLANG_ANALYZER_NORETURN;
#ifdef __cplusplus
}
#endif

#endif
