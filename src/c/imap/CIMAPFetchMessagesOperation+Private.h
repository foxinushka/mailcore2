#ifndef MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_PRIVATE_H
#define MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include <MailCore/CIMAPFetchMessagesOperation.h>

extern "C" CIMAPFetchMessagesOperation newCIMAPFetchMessagesOperation(mailcore::IMAPFetchMessagesOperation *operation);

#endif
