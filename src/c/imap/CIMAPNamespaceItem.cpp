#include "CIMAPNamespaceItem.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPNamespaceItem
#define structName CIMAPNamespaceItem

C_SYNTHESIZE_STRING(setPrefix, prefix);
C_SYNTHESIZE_CHAR(setDelimiter, delimiter);

const UChar*        pathForComponents(struct CIMAPNamespaceItem self, CArray components);
CArray              componentForPath(struct CIMAPNamespaceItem self, const UChar* path);
bool                containsFolder(struct CIMAPNamespaceItem self, const UChar* folder);

CIMAPNamespaceItem newCIMAPNamespaceItem(mailcore::IMAPNamespaceItem *item) {
    CIMAPNamespaceItem self;
    item->retain();
    self.instance = item;
    
    self.pathForComponents = &pathForComponents;
	self.componentForPath = &componentForPath;
	self.containsFolder = &containsFolder;
    
    return self;
}

void deleteCIMAPNamespaceItem(CIMAPNamespaceItem self) {
    C_SAFE_RELEASE(self.instance);
}

const UChar* pathForComponents(struct CIMAPNamespaceItem self, CArray components) {
    return self.instance->pathForComponents(components.instance)->unicodeCharacters();
}

CArray componentForPath(struct CIMAPNamespaceItem self, const UChar* path) {
    return newCArray(self.instance->componentsForPath(mailcore::String::stringWithCharacters(path)));
}

bool containsFolder(struct CIMAPNamespaceItem self, const UChar* folder) {
    return self.instance->containsFolder(mailcore::String::stringWithCharacters(folder));
}
