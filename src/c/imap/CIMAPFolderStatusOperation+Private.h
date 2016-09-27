#ifndef MAILCORE_CIMAP_FOLDER_STATUS_OPERATION_PRIVATE_H
#define MAILCORE_CIMAP_FOLDER_STATUS_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include "CIMAPFolderStatusOperation.h"

extern "C" CIMAPFolderStatusOperation newCIMAPFolderStatusOperation(mailcore::IMAPFolderStatusOperation *operation);

#endif
