#ifndef MAILCORE_CBASE_PRIVATE_H
#define MAILCORE_CBASE_PRIVATE_H

#include <MailCore/MCICUTypes.h>
#include <MailCore/MCString.h>

#define C_SYNTHESIZE_SCALAR(cType, mcType, setter, getter) \
cType getter(structName self){ \
    return cast(self)->getter(); \
} \
void setter(structName self, cType getter){ \
    cast(self)->setter(getter); \
}

#define C_SYNTHESIZE_ENUM(cType, mcType, setter, getter) \
cType getter(structName self){ \
return static_cast<cType>((int)cast(self)->getter()); \
} \
void setter(structName self, cType getter){ \
cast(self)->setter(static_cast<mcType>((int)getter)); \
}

#define C_SYNTHESIZE_MAILCORE_OBJ(cType, cConstr, mcType, setter, getter) \
cType getter(structName self){ \
return cConstr(cast(self)->getter()); \
} \
void setter(structName self, cType getter){ \
cast(self)->setter(cast(getter)); \
}

#define C_SYNTHESIZE_BOOL(setter, getter) C_SYNTHESIZE_SCALAR(bool, bool, setter, getter)
#define C_SYNTHESIZE_CHAR(setter, getter) C_SYNTHESIZE_SCALAR(char, char, setter, getter)

#define C_SYNTHESIZE_STRING(setter, getter) \
const UChar* getter(structName self) \
{ \
    return cast(self)->getter()->unicodeCharacters(); \
} \
\
void setter(structName self, const UChar *getter) \
{ \
    cast(self)->setter(mailcore::String::stringWithCharacters(getter)); \
}

#define C_SYNTHESIZE_ARRAY(setter, getter) \
CArray getter(structName self) \
{ \
    return newCArray(cast(self)->getter()); \
} \
\
void setter(structName self, CArray getter) \
{ \
    cast(self)->setter(cast(getter)); \
}

#endif
