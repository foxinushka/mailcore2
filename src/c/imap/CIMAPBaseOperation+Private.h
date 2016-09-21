#ifndef MAILCORE_CIMAP_BASE_OPERATION_PRIVATE_H
#define MAILCORE_CIMAP_BASE_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include <MailCore/CIMAPBaseOperation.h>

extern "C" CIMAPBaseOperation newCIMAPBaseOperation(mailcore::Operation* operation);

#endif
