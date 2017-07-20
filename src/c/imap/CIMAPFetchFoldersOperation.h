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
    };
    typedef struct CIMAPFetchFoldersOperation CIMAPFetchFoldersOperation;
    
    CArray  CIMAPFetchFoldersOperation_folders(struct CIMAPFetchFoldersOperation self)
            CF_SWIFT_NAME(CIMAPFetchFoldersOperation.folders(self:));

    void    CIMAPFetchFoldersOperation_release(CIMAPFetchFoldersOperation self)
            CF_SWIFT_NAME(CIMAPFetchFoldersOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPFetchFoldersOperation CIMAPFetchFoldersOperation_new(mailcore::IMAPFetchFoldersOperation *operation);
#endif

#endif /* CIMAPFetchFoldersOperation_hpp */
