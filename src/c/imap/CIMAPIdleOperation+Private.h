#ifndef MAILCORE_CIMAP_IDLE_OPERATION_PRIVATE_H
#define MAILCORE_CIMAP_IDLE_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include <MailCore/CIMAPIdleOperation.h>

extern "C" CIMAPIdleOperation newCIMAPIdleOperation(mailcore::Operation *operation);

#endif
