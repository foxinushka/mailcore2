#include "CData.h"
#include "MailCore/MCCore.h"

CData CData_new(mailcore::Data* data) {
    CData result;
    result.instance = data;
    return result;
}

CData CData_new(const char* bytes, unsigned int length) {
    CData result;
    result.instance = mailcore::Data::dataWithBytes(bytes, length);
    return result;
}

const char* CData_bytes(CData self) {
    return self.instance->bytes();
}

unsigned int CData_length(CData self) {
    return self.instance->length();
}

