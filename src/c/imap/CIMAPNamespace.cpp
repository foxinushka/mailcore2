#include <MailCore/MCAsync.h>
#include "CIMAPNamespace.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPNamespace
#define structName CIMAPNamespace

const UChar*    mainPrefix(struct CIMAPNamespace self);
char            mainDelimiter(struct CIMAPNamespace self);
CArray          prefixes(struct CIMAPNamespace self);
const UChar*    pathForComponents(struct CIMAPNamespace self, CArray components);
const UChar*    pathForComponentsAndPrefix(struct CIMAPNamespace self, CArray components, const UChar* prefix);
CArray          componentsFromPath(struct CIMAPNamespace self, const UChar* path);
bool            containsFolderPath(struct CIMAPNamespace self, const UChar* path);

CIMAPNamespace newCIMAPNamespace(mailcore::IMAPNamespace *folder) {
    CIMAPNamespace self;
    folder->retain();
    self.nativeInstance = folder;
    
    self.mainPrefix = &mainPrefix;
    self.mainDelimiter = &mainDelimiter;
    self.prefixes = &prefixes;
    self.pathForComponents = &pathForComponents;
    self.pathForComponentsAndPrefix = &pathForComponentsAndPrefix;
    self.componentsFromPath = &componentsFromPath;
    self.containsFolderPath = &containsFolderPath;
    
    return self;
}

CIMAPNamespace newCIMAPNamespace(const UChar* prefix, char delimiter) {
    return newCIMAPNamespace(mailcore::IMAPNamespace::namespaceWithPrefix(mailcore::String::stringWithCharacters(prefix), delimiter));
}

mailcore::IMAPNamespace * cast(CIMAPNamespace self) {
    return reinterpret_cast<mailcore::IMAPNamespace*>(self.nativeInstance);
}

void deleteCIMAPNamespace(CIMAPNamespace self) {
    C_SAFE_RELEASE(self);
}

const UChar* mainPrefix(struct CIMAPNamespace self) {
    return cast(self)->mainPrefix()->unicodeCharacters();
}

char mainDelimiter(struct CIMAPNamespace self) {
    return cast(self)->mainDelimiter();
}

CArray prefixes(struct CIMAPNamespace self) {
    return newCArray(cast(self)->prefixes());
}

const UChar* pathForComponents(struct CIMAPNamespace self, CArray components) {
    return cast(self)->pathForComponents(components.nativeInstance)->unicodeCharacters();
}

const UChar* pathForComponentsAndPrefix(struct CIMAPNamespace self, CArray components, const UChar* prefix) {
    return cast(self)->pathForComponentsAndPrefix(components.nativeInstance, mailcore::String::stringWithCharacters(prefix))->unicodeCharacters();
}

CArray componentsFromPath(struct CIMAPNamespace self, const UChar* path) {
    return newCArray(cast(self)->componentsFromPath(mailcore::String::stringWithCharacters(path)));
}

bool containsFolderPath(struct CIMAPNamespace self, const UChar* path) {
    return cast(self)->containsFolderPath(mailcore::String::stringWithCharacters(path));
}
