#include <MailCore/MCAsync.h>
#include "CIMAPNamespace.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPNamespace
#define structName CIMAPNamespace

const UChar*    mainPrefix(struct CIMAPNamespace *self);
char            mainDelimiter(struct CIMAPNamespace *self);
CArray          prefixes(struct CIMAPNamespace *self);
const UChar*    pathForComponents(struct CIMAPNamespace *self, CArray components);
const UChar*    pathForComponentsAndPrefix(struct CIMAPNamespace *self, CArray components, const UChar* prefix);
CArray          componentsFromPath(struct CIMAPNamespace *self, const UChar* path);
bool            containsFolderPath(struct CIMAPNamespace *self, const UChar* path);

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

mailcore::IMAPNamespace * cast(CIMAPNamespace *self) {
    return C_NATIVE_INSTANCE;
}

void deleteCIMAPNamespace(CIMAPNamespace self) {
    reinterpret_cast<nativeType*>(self.nativeInstance)->release();
}

const UChar* mainPrefix(struct CIMAPNamespace *self) {
    return C_NATIVE_INSTANCE->mainPrefix()->unicodeCharacters();
}

char mainDelimiter(struct CIMAPNamespace *self) {
    return C_NATIVE_INSTANCE->mainDelimiter();
}

CArray prefixes(struct CIMAPNamespace *self) {
    return newCArray2(C_NATIVE_INSTANCE->prefixes());
}

const UChar* pathForComponents(struct CIMAPNamespace *self, CArray components) {
    return C_NATIVE_INSTANCE->pathForComponents(cast(&components))->unicodeCharacters();
}

const UChar* pathForComponentsAndPrefix(struct CIMAPNamespace *self, CArray components, const UChar* prefix) {
    return C_NATIVE_INSTANCE->pathForComponentsAndPrefix(cast(&components), mailcore::String::stringWithCharacters(prefix))->unicodeCharacters();
}

CArray componentsFromPath(struct CIMAPNamespace *self, const UChar* path) {
    return newCArray2(C_NATIVE_INSTANCE->componentsFromPath(mailcore::String::stringWithCharacters(path)));
}

bool containsFolderPath(struct CIMAPNamespace *self, const UChar* path) {
    return C_NATIVE_INSTANCE->containsFolderPath(mailcore::String::stringWithCharacters(path));
}



