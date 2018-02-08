#ifndef MAILCORE_CBASE_H
#define MAILCORE_CBASE_H

#include <stdbool.h>
#include <stdint.h>

//TODO: fix ICUBasetypes
#ifdef _MSC_VER
typedef wchar_t UChar;
#elif defined(__CHAR16_TYPE__)
typedef __CHAR16_TYPE__ UChar;
#else
typedef uint16_t UChar;
#endif

#if __has_attribute(swift_name)
# define CF_SWIFT_NAME(_name) __attribute__((swift_name(#_name)))
#else
# define CF_SWIFT_NAME(_name)
#endif

#define __GET_MACRO(_6,_5,_4,_3,_2,_1,_0,NAME,...) NAME

#ifdef __cplusplus

#define C_SYNTHESIZE_STRUCT_DEFINITION(structName, nativeType) \
typedef struct structName { \
nativeType* instance; \
} structName; \
structName structName##_##new(nativeType *obj); \
void structName##_##retain(structName self); \
void structName##_##release(structName self); \
int structName##_##retainCount(structName self); \

#else

#define C_SYNTHESIZE_STRUCT_DEFINITION(structName, nativeType) \
typedef struct structName { \
void* instance; \
} structName; \
void structName##_##retain(structName self) CF_SWIFT_NAME(structName.retain(self:)); \
void structName##_##release(structName self) CF_SWIFT_NAME(structName.release(self:)); \
int structName##_##retainCount(structName self) CF_SWIFT_NAME(structName.retainCount(self:)); \

#endif

#define C_SYNTHESIZE_COBJECT_CAST_DEFINITION(structName) \
CObject structName##_##toCObject(structName self) CF_SWIFT_NAME(structName.toCObject(self:)); \
structName structName##_##newWithCObject(CObject obj) CF_SWIFT_NAME(structName.init(cobject:)); \
CData structName##_##mailCoreTypeInfo(void); \
CObject structName##_##copy(structName self) CF_SWIFT_NAME(structName.copy(self:)); \

#define C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(structName, propertyType, getterName) \
propertyType structName##_##getterName(struct structName self) CF_SWIFT_NAME(getter:structName.getterName(self:)); \

#define C_SYNTHESIZE_PROPERTY_DEFINITION(structName, propertyType, getterName, setterName) \
propertyType structName##_##getterName(struct structName self) CF_SWIFT_NAME(getter:structName.getterName(self:)); \
void structName##_##setterName(struct structName self, propertyType port) CF_SWIFT_NAME(setter:structName.getterName(self:newValue:)); \

#define C_SYNTHESIZE_FUNC_DEFINITION_0(structName, returnType, funcName) \
returnType structName##_##funcName(struct structName self) CF_SWIFT_NAME(structName.funcName(self:)); \

#define C_SYNTHESIZE_FUNC_DEFINITION_1(structName, returnType, funcName, arg1Type) \
returnType structName##_##funcName(struct structName self, arg1Type arg1) CF_SWIFT_NAME(structName.funcName(self:_:)); \

#define C_SYNTHESIZE_FUNC_DEFINITION_2(structName, returnType, funcName, arg1Type, arg2Type) \
returnType structName##_##funcName(struct structName self, arg1Type arg1, arg2Type arg2) CF_SWIFT_NAME(structName.funcName(self:_:_:)); \

#define C_SYNTHESIZE_FUNC_DEFINITION_3(structName, returnType, funcName, arg1Type, arg2Type, arg3Type) \
returnType structName##_##funcName(struct structName self, arg1Type arg1, arg2Type arg2, arg3Type arg3) CF_SWIFT_NAME(structName.funcName(self:_:_:_:)); \

#define C_SYNTHESIZE_FUNC_DEFINITION_4(structName, returnType, funcName, arg1Type, arg2Type, arg3Type, argType4) \
returnType structName##_##funcName(struct structName self, arg1Type arg1, arg2Type arg2, arg3Type arg3, argType4 arg4) CF_SWIFT_NAME(structName.funcName(self:_:_:_:_:)); \

#define C_SYNTHESIZE_FUNC_DEFINITION_5(structName, returnType, funcName, arg1Type, arg2Type, arg3Type, argType4, argType5) \
returnType structName##_##funcName(struct structName self, arg1Type arg1, arg2Type arg2, arg3Type arg3, argType4 arg4, argType5 arg5) CF_SWIFT_NAME(structName.funcName(self:_:_:_:_:_:)); \

#define C_SYNTHESIZE_FUNC_DEFINITION_6(structName, returnType, funcName, arg1Type, arg2Type, arg3Type, argType4, argType5, argType6) \
returnType structName##_##funcName(struct structName self, arg1Type arg1, arg2Type arg2, arg3Type arg3, argType4 arg4, argType5 arg5, argType6 arg6) CF_SWIFT_NAME(structName.funcName(self:_:_:_:_:_:_:)); \

#define C_SYNTHESIZE_STATIC_FUNC_DEFINITION_0(structName, returnType, funcName) \
returnType structName##_##funcName(void); \

#define C_SYNTHESIZE_STATIC_FUNC_DEFINITION_1(structName, returnType, funcName, arg1Type) \
returnType structName##_##funcName(arg1Type arg1) CF_SWIFT_NAME(structName.funcName(_:)); \

#define C_SYNTHESIZE_STATIC_FUNC_DEFINITION_2(structName, returnType, funcName, arg1Type, arg2Type) \
returnType structName##_##funcName(arg1Type arg1, arg2Type arg2) CF_SWIFT_NAME(structName.funcName(_:_:)); \

#define C_SYNTHESIZE_STATIC_FUNC_DEFINITION_3(structName, returnType, funcName, arg1Type, arg2Type, arg3Type) \
returnType structName##_##funcName(arg1Type arg1, arg2Type arg2, arg3Type arg3) CF_SWIFT_NAME(structName.funcName(_:_:_:)); \

#define C_SYNTHESIZE_STATIC_FUNC_DEFINITION_4(structName, returnType, funcName, arg1Type, arg2Type, arg3Type, arg4Type) \
returnType structName##_##funcName(arg1Type arg1, arg2Type arg2, arg3Type arg3, arg4Type arg4) CF_SWIFT_NAME(structName.funcName(_:_:_:_:)); \

#define C_SYNTHESIZE_FUNC_DEFINITION(structName, returnType, funcName,...) __GET_MACRO(_U, ##__VA_ARGS__,C_SYNTHESIZE_FUNC_DEFINITION_6,C_SYNTHESIZE_FUNC_DEFINITION_5,C_SYNTHESIZE_FUNC_DEFINITION_4,C_SYNTHESIZE_FUNC_DEFINITION_3,C_SYNTHESIZE_FUNC_DEFINITION_2,C_SYNTHESIZE_FUNC_DEFINITION_1,C_SYNTHESIZE_FUNC_DEFINITION_0)(structName, returnType, funcName, ##__VA_ARGS__)

#define C_SYNTHESIZE_STATIC_FUNC_DEFINITION(structName, returnType, funcName,...) __GET_MACRO(_U, _U, _U, ##__VA_ARGS__, C_SYNTHESIZE_STATIC_FUNC_DEFINITION_4, C_SYNTHESIZE_STATIC_FUNC_DEFINITION_3, C_SYNTHESIZE_STATIC_FUNC_DEFINITION_2, C_SYNTHESIZE_STATIC_FUNC_DEFINITION_1, C_SYNTHESIZE_STATIC_FUNC_DEFINITION_0)(structName, returnType, funcName, ##__VA_ARGS__)

#endif
