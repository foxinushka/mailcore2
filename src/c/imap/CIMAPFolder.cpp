#include "CIMAPFolder.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPFolder
#define structName CIMAPFolder

C_SYNTHESIZE_STRING(setPath, path);
C_SYNTHESIZE_CHAR(setDelimiter, delimiter);
C_SYNTHESIZE_ENUM(CIMAPFolderFlag, mailcore::IMAPFolderFlag, setFlags, flags)

CIMAPFolder CIMAPFolder_new(mailcore::IMAPFolder *folder) {
    CIMAPFolder self;
    folder->retain();
    self.instance = folder;
    return self;
}

void CIMAPFolder_release(CIMAPFolder self) {
    C_SAFE_RELEASE(self.instance);
}

CIMAPFolder CIMAPFolder_castFromCObject(CObject obj) {
    return CIMAPFolder_new(reinterpret_cast<mailcore::IMAPFolder*>(obj.instance));
}

CObject CIMAPFolder_castToCObject(struct CIMAPFolder self) {
    return CObject_new(reinterpret_cast<mailcore::Object*>(self.instance));
}
