#ifndef MAILCORE_CIMAP_FOLDER_INFO_OPERATION_PRIVATE_H
#define MAILCORE_CIMAP_FOLDER_INFO_OPERATION_PRIVATE_H

#include <MailCore/MCAsync.h>
#include "CIMAPFolderInfoOperation.h"

extern "C" CIMAPFolderInfoOperation newCIMAPFolderInfoOperation(mailcore::IMAPFolderInfoOperation *operation);

#endif
