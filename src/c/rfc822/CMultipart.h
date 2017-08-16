//
//  CMultipart.hpp
//  mailcore2
//
//  Created by Andrew on 8/15/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

#ifndef MAILCORE_C_MULTIPART_H
#define MAILCORE_C_MULTIPART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CAbstractPart.h"
#include "CMessageHeader.h"
#include "CAbstractMessagePart.h"

#ifdef __cplusplus

namespace mailcore {
    class Multipart;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CMultipart, mailcore::Multipart)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CMultipart)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CMultipart, MailCoreString, partID, setPartID)
    
#ifdef __cplusplus
}
#endif

#endif /* MAILCORE_C_MULTIPART_H */
