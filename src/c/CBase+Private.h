#ifndef MAILCORE_CBASE_PRIVATE_H
#define MAILCORE_CBASE_PRIVATE_H

#include "CBase.h"
#include <MailCore/MCICUTypes.h>
#include <MailCore/MCString.h>
#include <MailCore/MailCoreString.h>

#ifdef __cplusplus
#include <typeinfo>
#endif

#define PASTER(x,y) x ## _ ## y
#define EVALUATOR(x,y)  PASTER(x,y)
#define FUNCNAME(fun) EVALUATOR(structName, fun)

#define C_SYNTHESIZE_SCALAR(cType, mcType, setter, getter) \
cType FUNCNAME(getter)(structName self){ \
return self.instance->getter(); \
} \
void FUNCNAME(setter)(structName self, cType getter){ \
self.instance->setter(getter); \
}

#define C_SYNTHESIZE_ENUM(cType, mcType, setter, getter) \
cType FUNCNAME(getter)(structName self){ \
return static_cast<cType>((int)self.instance->getter()); \
} \
void FUNCNAME(setter)(structName self, cType getter){ \
self.instance->setter(static_cast<mcType>((int)getter)); \
}

#define C_SYNTHESIZE_MAILCORE_OBJ(cType, cConstr, setter, getter) \
cType FUNCNAME(getter)(structName self){ \
return cConstr(self.instance->getter()); \
} \
void FUNCNAME(setter)(structName self, cType getter){ \
self.instance->setter(getter.instance); \
}

#define C_SYNTHESIZE_COBJECT_CAST() \
CObject FUNCNAME(toCObject)(structName self){ \
return CObject_new(self.instance); \
} \
structName FUNCNAME(newWithCObject)(CObject obj){ \
return FUNCNAME(new)(reinterpret_cast<nativeType*>(obj.instance)); \
} \
CData FUNCNAME(mailCoreTypeInfo)(){ \
return getTypeNameFromObject(&typeid(nativeType)); \
} \
CObject FUNCNAME(copy)(structName self) { \
    return CObject_new(self.instance->copy()); \
} \


//#define C_SYNTHESIZE_COBJECT_CAST_DEFINITION(structName) \
//CObject FUNCNAME(toCObject)(structName self) \
//CF_SWIFT_NAME(structName.toCObject(self:)); \
//structName FUNCNAME(newWithCObject)(CObject obj) \
//CF_SWIFT_NAME(structName.init(cobject:)); \


//CObject             MailCoreString_toCObject(MailCoreString self)
//CF_SWIFT_NAME(MailCoreString.toCObject(self:));
//
//MailCoreString      MailCoreString_newWithCObject(struct CObject cobject)
//CF_SWIFT_NAME(MailCoreString.init(cobject:));

#define C_SYNTHESIZE_BOOL(setter, getter) C_SYNTHESIZE_SCALAR(bool, bool, setter, getter)
#define C_SYNTHESIZE_CHAR(setter, getter) C_SYNTHESIZE_SCALAR(char, char, setter, getter)
#define C_SYNTHESIZE_ARRAY(setter, getter) C_SYNTHESIZE_MAILCORE_OBJ(CArray, CArray_new, setter, getter)
#define C_SYNTHESIZE_STRING(setter, getter) C_SYNTHESIZE_MAILCORE_OBJ(MailCoreString, MailCoreString_new, setter, getter)

#define C_SAFE_RETAIN(o) (o.instance != NULL ? o.instance->retain() : NULL)
#define C_SAFE_COPY(o) (o.instance != NULL ? o.instance->copy() : NULL)

#define C_SAFE_RELEASE(o) \
do { \
if (o != NULL) { \
o->release(); \
o = NULL; \
} \
} while (0)

#define C_SYNTHESIZE_CONSTRUCTOR() \
structName FUNCNAME(new)(nativeType *obj) { \
structName self; \
self.instance = obj; \
return self; \
} \
void FUNCNAME(retain)(structName self) { \
if (self.instance != NULL) { \
self.instance->retain(); \
} \
} \
void FUNCNAME(release)(structName self) { \
if (self.instance != NULL) { \
self.instance->release(); \
self.instance = NULL; \
} \
} \
int FUNCNAME(retainCount)(structName self) { \
return self.instance->retainCount(); \
} \

#define C_SYNTHESIZE_FUNC_WITH_OBJ_0(returnType, funcName) \
returnType FUNCNAME(funcName)(struct structName self) { \
return EVALUATOR(returnType,new)(self.instance->funcName()); \
} \

#define C_SYNTHESIZE_FUNC_WITH_OBJ_1(returnType, funcName, arg1Type) \
returnType FUNCNAME(funcName)(struct structName self, arg1Type arg1) { \
return EVALUATOR(returnType,new)(self.instance->funcName(arg1.instance)); \
} \

#define C_SYNTHESIZE_FUNC_WITH_OBJ_2(returnType, funcName, arg1Type, arg2Type) \
returnType FUNCNAME(funcName)(struct structName self, arg1Type arg1, arg2Type arg2) { \
return EVALUATOR(returnType,new)(self.instance->funcName(arg1.instance, arg2.instance)); \
} \

#define C_SYNTHESIZE_FUNC_WITH_OBJ_3(returnType, funcName, arg1Type, arg2Type, arg3Type) \
returnType FUNCNAME(funcName)(struct structName self, arg1Type arg1, arg2Type arg2, arg3Type arg3) { \
return EVALUATOR(returnType,new)(self.instance->funcName(arg1.instance, arg2.instance, arg3.instance)); \
} \

#define C_SYNTHESIZE_FUNC_WITH_VOID_0(funcName) \
void FUNCNAME(funcName)(struct structName self) { \
self.instance->funcName(); \
} \

#define C_SYNTHESIZE_FUNC_WITH_VOID_1(funcName, arg1Type) \
void FUNCNAME(funcName)(struct structName self, arg1Type arg1) { \
    self.instance->funcName(arg1.instance); \
} \

#define C_SYNTHESIZE_FUNC_WITH_VOID_2(funcName, arg1Type, arg2Type) \
void FUNCNAME(funcName)(struct structName self, arg1Type arg1, arg2Type arg2) { \
self.instance->funcName(arg1.instance, arg2.instance); \
} \

#define C_SYNTHESIZE_FUNC_WITH_SCALAR_0(returnType, funcName) \
returnType FUNCNAME(funcName)(struct structName self) { \
return self.instance->funcName(); \
} \

#define C_SYNTHESIZE_FUNC_WITH_SCALAR_1(returnType, funcName, arg1Type) \
returnType FUNCNAME(funcName)(struct structName self, arg1Type arg1) { \
return self.instance->funcName(arg1.instance); \
} \

#define C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ_0(returnType, funcName) \
returnType FUNCNAME(funcName)() { \
return EVALUATOR(returnType,new)(nativeType::funcName()); \
} \

#define C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ_1(returnType, funcName, arg1Type) \
returnType FUNCNAME(funcName)(arg1Type arg1) { \
return EVALUATOR(returnType,new)(nativeType::funcName(arg1.instance)); \
} \

#define C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ_2(returnType, funcName, arg1Type, arg2Type) \
returnType FUNCNAME(funcName)(arg1Type arg1, arg2Type arg2) { \
return EVALUATOR(returnType,new)(nativeType::funcName(arg1.instance, arg2.instance)); \
} \

#define C_SYNTHESIZE_FUNC_WITH_OBJ(returnType, funcName,...) __GET_MACRO(_U, _U, _U, _U, ##__VA_ARGS__, C_SYNTHESIZE_FUNC_WITH_OBJ_3, C_SYNTHESIZE_FUNC_WITH_OBJ_2, C_SYNTHESIZE_FUNC_WITH_OBJ_1, C_SYNTHESIZE_FUNC_WITH_OBJ_0)(returnType, funcName, ##__VA_ARGS__)

#define C_SYNTHESIZE_FUNC_WITH_VOID(funcName,...) __GET_MACRO(_U, _U, _U, _U, ##__VA_ARGS__, C_SYNTHESIZE_FUNC_WITH_VOID_3, C_SYNTHESIZE_FUNC_WITH_VOID_2, C_SYNTHESIZE_FUNC_WITH_VOID_1, C_SYNTHESIZE_FUNC_WITH_VOID_0)(funcName, ##__VA_ARGS__)

#define C_SYNTHESIZE_FUNC_WITH_SCALAR(returnType, funcName,...) __GET_MACRO(_U, _U, _U, _U, ##__VA_ARGS__, C_SYNTHESIZE_FUNC_WITH_SCALAR_3, C_SYNTHESIZE_FUNC_WITH_SCALAR_2, C_SYNTHESIZE_FUNC_WITH_SCALAR_1, C_SYNTHESIZE_FUNC_WITH_SCALAR_0)(returnType, funcName, ##__VA_ARGS__)

#define C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(returnType, funcName,...) __GET_MACRO(_U, _U, _U, _U, ##__VA_ARGS__, C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ_3, C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ_2, C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ_1, C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ_0)(returnType, funcName, ##__VA_ARGS__)

#endif
