//
//  CIMAPFetchFoldersOperation.hpp
//  mailcore2
//
//  Created by Andrew on 12/5/16.
//  Copyright © 2016 MailCore. All rights reserved.
//

#ifndef CIMAPFetchFoldersOperation_hpp
#define CIMAPFetchFoldersOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CArray.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFetchFoldersOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFetchFoldersOperation, mailcore::IMAPFetchFoldersOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFetchFoldersOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPFetchFoldersOperation, CArray, folders)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPFetchFoldersOperation_hpp */
