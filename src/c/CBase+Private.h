#ifndef MAILCORE_CBASE_PRIVATE_H
#define MAILCORE_CBASE_PRIVATE_H

#include <MailCore/MCICUTypes.h>
#include <MailCore/MCString.h>

#define C_NATIVE_INSTANCE reinterpret_cast<nativeType*>(self->nativeInstance)
#define C_ANCESTOR_INSTANCE reinterpret_cast<nativeType*>(ancestor->nativeInstance)

#define C_SYNTHESIZE_SCALAR(cType, mcType, setter, getter) \
cType getter(structName *self){ \
    return C_NATIVE_INSTANCE->getter(); \
} \
void setter(struct structName *self, cType getter){ \
    C_NATIVE_INSTANCE->setter(getter); \
}

/*
 IMAPFolderFlag flags(struct CIMAPFolder *self){
 return static_cast<IMAPFolderFlag>((int)C_NATIVE_INSTANCE->flags());
 }
 
 void setFlags(struct CIMAPFolder *self, IMAPFolderFlag flags){
 C_NATIVE_INSTANCE->setFlags(static_cast<mailcore::IMAPFolderFlag>((int)flags));
 }
 */

#define C_SYNTHESIZE_ENUM(cType, mcType, setter, getter) \
cType getter(structName *self){ \
return static_cast<cType>((int)C_NATIVE_INSTANCE->getter()); \
} \
void setter(struct structName *self, cType getter){ \
C_NATIVE_INSTANCE->setter(static_cast<mcType>((int)getter)); \
}

/*
 CAbstractPart mainPart(CIMAPMessage *self) {
 return newCAbstractPart(C_NATIVE_INSTANCE->mainPart());
 }
 
 void setMainPart(CIMAPMessage *self, CAbstractPart *mainPart) {
 C_NATIVE_INSTANCE->setMainPart(cast(mainPart));
 }
 */

#define C_SYNTHESIZE_MAILCORE_OBJ(cType, cConstr, mcType, setter, getter) \
cType getter(structName *self){ \
return cConstr(C_NATIVE_INSTANCE->getter()); \
} \
void setter(struct structName *self, cType getter){ \
C_NATIVE_INSTANCE->setter(cast(getter)); \
}

#define C_SYNTHESIZE_BOOL(setter, getter) C_SYNTHESIZE_SCALAR(bool, bool, setter, getter)
#define C_SYNTHESIZE_CHAR(setter, getter) C_SYNTHESIZE_SCALAR(char, char, setter, getter)

#define C_SYNTHESIZE_STRING(setter, getter) \
const UChar* getter(structName *self) \
{ \
    return C_NATIVE_INSTANCE->getter()->unicodeCharacters(); \
} \
\
void setter(structName *self, const UChar *getter) \
{ \
    C_NATIVE_INSTANCE->setter(mailcore::String::stringWithCharacters(getter)); \
}

#define C_SYNTHESIZE_ARRAY(setter, getter) \
CArray getter(structName *self) \
{ \
    return newCArray2(C_NATIVE_INSTANCE->getter()); \
} \
\
void setter(structName *self, CArray *getter) \
{ \
    C_NATIVE_INSTANCE->setter(cast(getter)); \
}

#endif
