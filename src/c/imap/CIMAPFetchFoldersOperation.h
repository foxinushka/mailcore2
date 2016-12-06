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
    
    struct CIMAPFetchFoldersOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPFetchFoldersOperation*    instance;
#else
        void*                                   instance;
#endif
        
        CArray (*folders)(struct CIMAPFetchFoldersOperation self);
        
    };
    typedef struct CIMAPFetchFoldersOperation CIMAPFetchFoldersOperation;
    
    void deleteCIMAPFetchFoldersOperation(CIMAPFetchFoldersOperation self);
    
#ifdef __cplusplus
}

CIMAPFetchFoldersOperation newCIMAPFetchFoldersOperation(mailcore::IMAPFetchFoldersOperation *operation);
#endif

#endif /* CIMAPFetchFoldersOperation_hpp */
