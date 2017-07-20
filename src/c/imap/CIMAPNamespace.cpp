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

CIMAPNamespace CIMAPNamespace_new(const UChar* prefix, char delimiter) {
    return CIMAPNamespace_new(mailcore::IMAPNamespace::namespaceWithPrefix(mailcore::String::stringWithCharacters(prefix), delimiter));
}

void CIMAPNamespace_release(CIMAPNamespace self) {
    C_SAFE_RELEASE(self.instance);
}

const UChar* CIMAPNamespace_mainPrefix(struct CIMAPNamespace self) {
    return self.instance->mainPrefix()->unicodeCharacters();
}

char CIMAPNamespace_mainDelimiter(struct CIMAPNamespace self) {
    return self.instance->mainDelimiter();
}

CArray CIMAPNamespace_prefixes(struct CIMAPNamespace self) {
    return CArray_new(self.instance->prefixes());
}

const UChar* CIMAPNamespace_pathForComponents(struct CIMAPNamespace self, CArray components) {
    return self.instance->pathForComponents(components.instance)->unicodeCharacters();
}

const UChar* CIMAPNamespace_pathForComponentsAndPrefix(struct CIMAPNamespace self, CArray components, const UChar* prefix) {
    return self.instance->pathForComponentsAndPrefix(components.instance, mailcore::String::stringWithCharacters(prefix))->unicodeCharacters();
}

CArray CIMAPNamespace_componentsFromPath(struct CIMAPNamespace self, const UChar* path) {
    return CArray_new(self.instance->componentsFromPath(mailcore::String::stringWithCharacters(path)));
}

bool CIMAPNamespace_containsFolderPath(struct CIMAPNamespace self, const UChar* path) {
    return self.instance->containsFolderPath(mailcore::String::stringWithCharacters(path));
}

CIMAPNamespace CIMAPNamespace_castFromCObject(CObject obj) {
    return CIMAPNamespace_new((mailcore::IMAPNamespace*) obj.instance);
}

CObject CIMAPNamespace_castToCObject(struct CIMAPNamespace self) {
    return CObject_new((mailcore::Object*) self.instance);
}
