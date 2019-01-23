#include "MCAssert.h"

#include <stdio.h>
#include <stdlib.h>

static MSAssertHandler assertHadnler = NULL;

void setMCAssertHandler(MSAssertHandler handler) {
    assertHadnler = handler;
}

void MCAssertInternal(const char * filename, unsigned int line, int cond, const char * condString)
{
    if (cond) {
        return;
    }
    
    if (assertHadnler != NULL) {
        assertHadnler(filename, line, condString);
    }
    else {
        fprintf(stderr, "%s:%u: assert %s\n", filename, line, condString);
        abort();
    }
}
