#ifndef mailcore2_MCBasicLock_h
#define mailcore2_MCBasicLock_h

#ifdef _MSC_VER

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define MCB_LOCK_TYPE SRWLOCK
#define MCB_LOCK_INITIAL_VALUE SRWLOCK_INIT
#define MCB_LOCK_INIT(l) InitializeSRWLock(l)
#define MCB_LOCK_DESTROY(l)
#define MCB_LOCK(l) AcquireSRWLockExclusive(l)
#define MCB_UNLOCK(l) ReleaseSRWLockExclusive(l)

#else

#include <pthread.h>

#define MCB_LOCK_TYPE pthread_mutex_t
#define MCB_LOCK_INITIAL_VALUE PTHREAD_MUTEX_INITIALIZER
#define MCB_LOCK_INIT(l) pthread_mutex_init(l, NULL)
#define MCB_LOCK_DESTROY(l) pthread_mutex_destroy(l)
#define MCB_LOCK(l) pthread_mutex_lock(l)
#define MCB_UNLOCK(l) pthread_mutex_unlock(l)

#endif

#endif /* mailcore2_MCBasicLock_h */
