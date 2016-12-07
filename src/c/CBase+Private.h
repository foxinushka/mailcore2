#ifndef MAILCORE_CBASE_PRIVATE_H
#define MAILCORE_CBASE_PRIVATE_H

#include <MailCore/MCICUTypes.h>
#include <MailCore/MCString.h>

#define C_SYNTHESIZE_SCALAR(cType, mcType, setter, getter) \
cType getter(structName self){ \
return self.instance->getter(); \
} \
void setter(structName self, cType getter){ \
self.instance->setter(getter); \
}

#define C_SYNTHESIZE_ENUM(cType, mcType, setter, getter) \
cType getter(structName self){ \
return static_cast<cType>((int)self.instance->getter()); \
} \
void setter(structName self, cType getter){ \
self.instance->setter(static_cast<mcType>((int)getter)); \
}

#define C_SYNTHESIZE_STRING(setter, getter) \
const UChar* getter(structName self) \
{ \
return self.instance->getter()->unicodeCharacters(); \
} \
\
void setter(structName self, const UChar *getter) \
{ \
self.instance->setter(mailcore::String::stringWithCharacters(getter)); \
}

#define C_SYNTHESIZE_MAILCORE_OBJ(cType, cConstr, setter, getter) \
cType getter(structName self){ \
return cConstr(self.instance->getter()); \
} \
void setter(structName self, cType getter){ \
self.instance->setter(getter.instance); \
}

#define C_SYNTHESIZE_BOOL(setter, getter) C_SYNTHESIZE_SCALAR(bool, bool, setter, getter)
#define C_SYNTHESIZE_CHAR(setter, getter) C_SYNTHESIZE_SCALAR(char, char, setter, getter)
#define C_SYNTHESIZE_ARRAY(setter, getter) C_SYNTHESIZE_MAILCORE_OBJ(CArray, newCArray, setter, getter)

#define C_SAFE_RETAIN(o) (o.instance != NULL ? o.instance->retain() : NULL)
#define C_SAFE_COPY(o) (o.instance != NULL ? o.instance->copy() : NULL)

#define C_SAFE_RELEASE(o) \
do { \
if (o != NULL) { \
o->release(); \
o = NULL; \
} \
} while (0)

#endif
