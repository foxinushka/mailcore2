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
    self.instance = folder;
    
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

void deleteCIMAPNamespace(CIMAPNamespace self) {
    C_SAFE_RELEASE(self.instance);
}

const UChar* mainPrefix(struct CIMAPNamespace self) {
    return self.instance->mainPrefix()->unicodeCharacters();
}

char mainDelimiter(struct CIMAPNamespace self) {
    return self.instance->mainDelimiter();
}

CArray prefixes(struct CIMAPNamespace self) {
    return newCArray(self.instance->prefixes());
}

const UChar* pathForComponents(struct CIMAPNamespace self, CArray components) {
    return self.instance->pathForComponents(components.instance)->unicodeCharacters();
}

const UChar* pathForComponentsAndPrefix(struct CIMAPNamespace self, CArray components, const UChar* prefix) {
    return self.instance->pathForComponentsAndPrefix(components.instance, mailcore::String::stringWithCharacters(prefix))->unicodeCharacters();
}

CArray componentsFromPath(struct CIMAPNamespace self, const UChar* path) {
    return newCArray(self.instance->componentsFromPath(mailcore::String::stringWithCharacters(path)));
}

bool containsFolderPath(struct CIMAPNamespace self, const UChar* path) {
    return self.instance->containsFolderPath(mailcore::String::stringWithCharacters(path));
}
