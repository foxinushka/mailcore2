#ifndef MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_PRIVATE_H
#define MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include <MailCore/CIMAPFetchContentOperation.h>

extern "C" CIMAPFetchContentOperation newCIMAPFetchContentOperation(mailcore::IMAPFetchContentOperation *operation);

#endif
