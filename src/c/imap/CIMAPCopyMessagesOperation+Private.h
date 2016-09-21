#ifndef MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_PRIVATE_H
#define MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include <MailCore/CIMAPCopyMessagesOperation.h>

extern "C" CIMAPCopyMessagesOperation newCIMAPCopyMessagesOperation(mailcore::IMAPCopyMessagesOperation *operation);

#endif
