//
//  CAutoreleasePool.cpp
//  mailcore2
//
//  Created by Andriy Druk on 3/12/19.
//  Copyright © 2019 MailCore. All rights reserved.
//

#include "CAutoreleasePool.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::AutoreleasePool
#define structName CAutoreleasePool

C_SYNTHESIZE_CONSTRUCTOR()

CAutoreleasePool CAutoreleasePool_init(){
    return CAutoreleasePool_new(new mailcore::AutoreleasePool());
}
