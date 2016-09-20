#include <MailCore/MCCore.h>

extern "C" {
	#include "CArray.h"

	void addObject(struct CArray *array, CObject *object) {
		reinterpret_cast<mailcore::Array *>(array->self)->addObject(reinterpret_cast<mailcore::Object *>(object->self));
	}

	CArray newCArray() {
	    CArray array;
	    array.self = reinterpret_cast<void *>(new mailcore::Array());
	    array.addObject = &addObject;
	    return array;
	}

	void deleteCArray(CArray array) {
	    delete reinterpret_cast<mailcore::Array *>(array.self);
	}
}