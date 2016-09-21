#ifndef MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_PRIVATE_H
#define MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include <MailCore/CIMAPAppendMessageOperation.h>

extern "C" CIMAPAppendMessageOperation newIMAPAppendMessageOperation(mailcore::IMAPAppendMessageOperation *operation);

#endif
