#ifndef MAILCORE_MCMAINTHREADANDROID_H

#define MAILCORE_MCMAINTHREADANDROID_H

#if defined(__ANDROID) || defined(ANDROID)

#ifdef __cplusplus

namespace mailcore {
    extern void androidSetupThread(void);
    extern void androidUnsetupThread(void);
    extern void mailcore::callOnMainThreadAndWait(void (* function)(void *), void * context);
    extern void mailcore::callOnMainThread(void (* function)(void *), void * context);
}
#endif

#endif

#endif
