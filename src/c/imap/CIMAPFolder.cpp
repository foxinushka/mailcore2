#include "CIMAPFolder.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPFolder
#define structName CIMAPFolder

C_SYNTHESIZE_STRING(setPath, path);
C_SYNTHESIZE_CHAR(setDelimiter, delimiter);
C_SYNTHESIZE_ENUM(IMAPFolderFlag, mailcore::IMAPFolderFlag, setFlags, flags)

CIMAPFolder newCIMAPFolder(mailcore::IMAPFolder *folder) {
    CIMAPFolder self;
    folder->retain();
    self.instance = folder;
    
    self.setPath = &setPath;
    self.path = &path;
    self.setDelimiter = &setDelimiter;
    self.delimiter = &delimiter;
    self.setFlags = &setFlags;
    self.flags = &flags;

    return self;
}

void deleteCIMAPFolder(CIMAPFolder self) {
    C_SAFE_RELEASE(self);
}
