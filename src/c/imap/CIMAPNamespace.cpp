#include <MailCore/MCAsync.h>
#include "CIMAPNamespace.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPNamespace
#define structName CIMAPNamespace

CIMAPNamespace CIMAPNamespace_new(mailcore::IMAPNamespace *folder) {
    CIMAPNamespace self;
    folder->retain();
    self.instance = folder;
    return self;
}

CIMAPNamespace CIMAPNamespace_new(MailCoreString prefix, char delimiter) {
    return CIMAPNamespace_new(mailcore::IMAPNamespace::namespaceWithPrefix(prefix.instance, delimiter));
}

void CIMAPNamespace_release(CIMAPNamespace self) {
    C_SAFE_RELEASE(self.instance);
}

MailCoreString CIMAPNamespace_mainPrefix(struct CIMAPNamespace self) {
    return MailCoreString_new(self.instance->mainPrefix());
}

char CIMAPNamespace_mainDelimiter(struct CIMAPNamespace self) {
    return self.instance->mainDelimiter();
}

CArray CIMAPNamespace_prefixes(struct CIMAPNamespace self) {
    return CArray_new(self.instance->prefixes());
}

MailCoreString CIMAPNamespace_pathForComponents(struct CIMAPNamespace self, CArray components) {
    return MailCoreString_new(self.instance->pathForComponents(components.instance));
}

MailCoreString CIMAPNamespace_pathForComponentsAndPrefix(struct CIMAPNamespace self, CArray components, MailCoreString prefix) {
    return MailCoreString_new(self.instance->pathForComponentsAndPrefix(components.instance, prefix.instance));
}

CArray CIMAPNamespace_componentsFromPath(struct CIMAPNamespace self, MailCoreString path) {
    return CArray_new(self.instance->componentsFromPath(path.instance));
}

bool CIMAPNamespace_containsFolderPath(struct CIMAPNamespace self, MailCoreString path) {
    return self.instance->containsFolderPath(path.instance);
}

CIMAPNamespace CIMAPNamespace_castFromCObject(CObject obj) {
    return CIMAPNamespace_new(reinterpret_cast<mailcore::IMAPNamespace*>(obj.instance));
}

CObject CIMAPNamespace_castToCObject(struct CIMAPNamespace self) {
    return CObject_new(reinterpret_cast<mailcore::Object*>(self.instance));
}
