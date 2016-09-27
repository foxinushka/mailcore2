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

#define C_SYNTHESIZE_BOOL(setter, getter) C_SYNTHESIZE_SCALAR(bool, bool, setter, getter)

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
