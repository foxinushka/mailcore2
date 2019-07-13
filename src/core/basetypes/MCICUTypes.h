//
//  MCICUTypes.h
//  mailcore2
//
//  Created by DINH Viêt Hoà on 4/18/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef MAILCORE_MCICUTYPES_H

#define MAILCORE_MCICUTYPES_H

#ifdef _MSC_VER

#include <unicode/uvernum.h>

#if U_ICU_VERSION_MAJOR_NUM <= 58
typedef wchar_t UChar;
#else
typedef char16_t UChar;
#endif /* U_ICU_VERSION_MAJOR_NUM */

#elif defined(__CHAR16_TYPE__)
typedef __CHAR16_TYPE__ UChar;
#else
typedef uint16_t UChar;
#endif /* _MSC_VER */

#endif /* MAILCORE_MCICUTYPES_H */

