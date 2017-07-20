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

const UChar* CIMAPNamespaceItem_pathForComponents(struct CIMAPNamespaceItem self, CArray components) {
    return self.instance->pathForComponents(components.instance)->unicodeCharacters();
}

CArray CIMAPNamespaceItem_componentForPath(struct CIMAPNamespaceItem self, const UChar* path) {
    return CArray_new(self.instance->componentsForPath(mailcore::String::stringWithCharacters(path)));
}

bool CIMAPNamespaceItem_containsFolder(struct CIMAPNamespaceItem self, const UChar* folder) {
    return self.instance->containsFolder(mailcore::String::stringWithCharacters(folder));
}
