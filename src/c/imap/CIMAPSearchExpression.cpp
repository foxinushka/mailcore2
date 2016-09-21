#include <MailCore/MCAsync.h>
#include "CIMAPSearchExpression.h"

extern "C" {    
    СIMAPSearchExpression searchAll() {
        СIMAPSearchExpression searchExpression;
        searchExpression.self = new mailcore::IMAPSearchExpression();
        return searchExpression;
    }
    
    void deleteСIMAPSearchExpression(СIMAPSearchExpression self) {
        delete reinterpret_cast<mailcore::IMAPSearchExpression *>(self.self);
    }
}

