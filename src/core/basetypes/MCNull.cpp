//
//  MCNull.cpp
//  hermes
//
//  Created by DINH Viêt Hoà on 4/9/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#include "MCNull.h"

#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else
#import <pthread.h>
#endif

using namespace mailcore;

static Null * s_null = NULL;

static void init_null(void)
{
	s_null = new Null();
}

#ifdef _MSC_VER

INIT_ONCE s_once = INIT_ONCE_STATIC_INIT;

BOOL CALLBACK init_null_callback(PINIT_ONCE InitOnce, PVOID Parameter, PVOID * lpContext) {
	init_null();
	return TRUE;
}

#else

static pthread_once_t s_once;

#endif /* _WIN32 */



Null * Null::null()
{
#ifdef _MSC_VER
	InitOnceExecuteOnce(&s_once, init_null_callback, NULL, NULL);
#else
    pthread_once(&s_once, init_null);
#endif
    return s_null;
}
