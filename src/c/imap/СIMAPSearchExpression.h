#ifndef MAILCORE_СIMAP_SEARCH_EXPRESSION_H
#define MAILCORE_СIMAP_SEARCH_EXPRESSION_H

#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct СIMAPSearchExpression {
        ref self;
    };
    typedef struct СIMAPSearchExpression СIMAPSearchExpression;

    СIMAPSearchExpression searchAll();
    void deleteСIMAPSearchExpression(СIMAPSearchExpression self);

#ifdef __cplusplus
}
#endif

#endif