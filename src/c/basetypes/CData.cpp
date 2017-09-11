#include "CData.h"
#include "MailCore/MCCore.h"
#include "CBase+Private.h"

#include <typeinfo>

#define nativeType mailcore::Data
#define structName CData

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

CData CData_dataWithBytes(const char* bytes, unsigned int length) {
    CData result;
    result.instance = mailcore::Data::dataWithBytes(bytes, length);
    return result;
}

C_SYNTHESIZE_FUNC_WITH_SCALAR(const char*, bytes)
C_SYNTHESIZE_FUNC_WITH_SCALAR(unsigned int, length)

bool CData_externallyAllocatedMemory(CData self) {
    return self.instance->mExternallyAllocatedMemory;
}

CBytesDeallocator CData_bytesDeallocator(CData self) {
    return self.instance->mBytesDeallocator;
}

CData Value_mailCoreTypeInfo() {
    return getTypeNameFromObject(&typeid(mailcore::Value));
}

CData getTypeNameFromObject(CObject obj) {
    const std::type_info * info = &typeid(* obj.instance);
    return getTypeNameFromObject(info);
}

CData getTypeNameFromObject(const std::type_info * info) {
    CData result;
#ifdef __LIBCPP_TYPEINFO
    size_t hash_value = info->hash_code();
    const char* bytes = (char*)&hash_value;
    unsigned int length = sizeof(hash_value);
    result.instance = mailcore::Data::dataWithBytes(bytes, length);
#else
    const char* bytes = info->name();
    unsigned int length = (unsigned int) strlen(info->name());
    result.instance = mailcore::Data::dataWithBytes(bytes, length);
#endif
    return result;
}

