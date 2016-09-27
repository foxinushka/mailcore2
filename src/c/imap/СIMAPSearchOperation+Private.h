#ifndef MAILCORE_СIMAP_SEARCH_OPERATION_PRIVATE_H
#define MAILCORE_СIMAP_SEARCH_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include "СIMAPSearchOperation.h"

extern "C" CIMAPSearchOperation newCIMAPSearchOperation(mailcore::IMAPSearchOperation *operation);

#endif
