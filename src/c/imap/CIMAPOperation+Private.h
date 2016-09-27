#ifndef MAILCORE_CIMAP_OPERATION_PRIVATE_H
#define MAILCORE_CIMAP_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include "CIMAPOperation.h"

extern "C" CIMAPOperation newIMAPOperation(mailcore::IMAPOperation *operation);

#endif
