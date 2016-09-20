#include <MailCore/MCAsync.h>

extern "C" {
#include "CIMAPSearchExpression.h"
    
    СIMAPSearchExpression searchAll() {
        СIMAPSearchExpression searchExpression;
        searchExpression.self = new mailcore::IMAPSearchExpression();
        return searchExpression;
    }
    
    void deleteСIMAPSearchExpression(СIMAPSearchExpression self) {
        delete reinterpret_cast<mailcore::IMAPSearchExpression *>(self.self);
    }
}

