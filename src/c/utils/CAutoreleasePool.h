//
//  CAutoreleasePool.hpp
//  mailcore2
//
//  Created by Andriy Druk on 3/12/19.
//  Copyright © 2019 MailCore. All rights reserved.
//

#ifndef MAILCORE_C_AUTORELEASEPOOL_H
#define MAILCORE_C_AUTORELEASEPOOL_H

#include "CBase.h"

#ifdef __cplusplus

namespace mailcore {
    class AutoreleasePool;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CAutoreleasePool, mailcore::AutoreleasePool)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAutoreleasePool, CAutoreleasePool, init)

    
#ifdef __cplusplus
}
#endif

#endif /* MAILCORE_C_AUTORELEASEPOOL_H */
