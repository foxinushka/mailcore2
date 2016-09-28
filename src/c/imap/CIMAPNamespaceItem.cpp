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
    self.nativeInstance = item;
    
    self.pathForComponents = &pathForComponents;
	self.componentForPath = &componentForPath;
	self.containsFolder = &containsFolder;
    
    return self;
}

mailcore::IMAPNamespaceItem * cast(CIMAPNamespaceItem self) {
    return reinterpret_cast<mailcore::IMAPNamespaceItem*>(self.nativeInstance);
}

void deleteCIMAPNamespaceItem(CIMAPNamespaceItem self) {
    cast(self)->release();
}

const UChar* pathForComponents(struct CIMAPNamespaceItem self, CArray components) {
    return cast(self)->pathForComponents(nativeInstance(components))->unicodeCharacters();
}

CArray componentForPath(struct CIMAPNamespaceItem self, const UChar* path) {
    return newCArray2(cast(self)->componentsForPath(mailcore::String::stringWithCharacters(path)));
}

bool containsFolder(struct CIMAPNamespaceItem self, const UChar* folder) {
    return cast(self)->containsFolder(mailcore::String::stringWithCharacters(folder));
}
