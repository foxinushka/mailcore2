//
//  CMultipart.cpp
//  mailcore2
//
//  Created by Andrew on 8/15/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

#include "CMultipart.h"
#include <MailCore/MCCore.h>

#include "CBase+Private.h"

#define nativeType mailcore::Multipart
#define structName CMultipart

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()
C_SYNTHESIZE_STRING(setPartID, partID);
