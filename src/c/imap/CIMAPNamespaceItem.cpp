#include "CIMAPNamespaceItem.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPNamespaceItem
#define structName CIMAPNamespaceItem

C_SYNTHESIZE_STRING(setPrefix, prefix);
C_SYNTHESIZE_CHAR(setDelimiter, delimiter);

CIMAPNamespaceItem CIMAPNamespaceItem_new(mailcore::IMAPNamespaceItem *item) {
    CIMAPNamespaceItem self;
    item->retain();
    self.instance = item;
    return self;
}

void CIMAPNamespaceItem_release(CIMAPNamespaceItem self) {
    C_SAFE_RELEASE(self.instance);
}

MailCoreString CIMAPNamespaceItem_pathForComponents(struct CIMAPNamespaceItem self, CArray components) {
    return MailCoreString_new(self.instance->pathForComponents(components.instance));
}

CArray CIMAPNamespaceItem_componentForPath(struct CIMAPNamespaceItem self, MailCoreString path) {
    return CArray_new(self.instance->componentsForPath(path.instance));
}

bool CIMAPNamespaceItem_containsFolder(struct CIMAPNamespaceItem self, MailCoreString folder) {
    return self.instance->containsFolder(folder.instance);
}
