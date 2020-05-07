#ifndef MAILCORE_MCMAINTHREADANDROID_H

#define MAILCORE_MCMAINTHREADANDROID_H

#if defined(__ANDROID) || defined(ANDROID)

#ifdef __cplusplus

namespace mailcore {
    extern void androidSetupThread(void);
    extern void androidUnsetupThread(void);
    extern void callOnMainThreadAndWait(void (* function)(void *), void * context);
    extern void callOnMainThread(void (* function)(void *), void * context);
}
#endif

#endif

#endif
