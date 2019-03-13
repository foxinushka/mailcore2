#include "MCAssert.h"

#include <stdio.h>
#include <stdlib.h>

static MCLogger assertHandler = NULL;

void setMCAssertHandler(MCLogger handler) {
    assertHandler = handler;
}

void MCAssertInternal(const char * filename, unsigned int line, int cond, const char * condString)
{
    if (cond) {
        return;
    }
    
    if (assertHandler != NULL) {
        assertHandler(filename, line, condString);
    }
    else {
        fprintf(stderr, "%s:%u: assert %s\n", filename, line, condString);
        abort();
    }
}
