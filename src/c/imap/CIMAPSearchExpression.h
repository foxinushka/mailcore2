#ifndef MAILCORE_СIMAP_SEARCH_EXPRESSION_H
#define MAILCORE_СIMAP_SEARCH_EXPRESSION_H

#include "CBase.h"
#include "CIndexSet.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPSearchExpression{
        ref nativeInstance;
    };
    typedef struct CIMAPSearchExpression CIMAPSearchExpression;

    CIMAPSearchExpression newCIMAPSearchExpressionSearchAll();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchFrom(const UChar* value);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchRecipient(const UChar* value);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchTo(const UChar* value);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchCc(const UChar* value);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchBcc(const UChar* value);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchSubject(const UChar* value);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchContent(const UChar* value);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchBody(const UChar* value);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchUIDs(CIndexSet uids);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchNumbers(CIndexSet numbers);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchHeader(const UChar* header, const UChar* value);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchRead();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchUnread();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchFlagged();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchUnflagged();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchAnswered();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchUnanswered();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchDraft();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchUndraft();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchDeleted();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchSpam();
    CIMAPSearchExpression newCIMAPSearchExpressionSearchBeforeDate(time_t date);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchOnDate(time_t date);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchSinceDate(time_t date);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchBeforeReceivedDate(time_t date);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchOnReceivedDate(time_t date);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchSinceReceivedDate(time_t date);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchSizeLargerThan(uint32_t size);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchSizeSmallerThan(uint32_t size);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchGmailThreadID(uint64_t number);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchGmailMessageID(uint64_t number);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchGmailRaw(const UChar* expr);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchAnd(CIMAPSearchExpression expression, CIMAPSearchExpression other);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchOr(CIMAPSearchExpression expression, CIMAPSearchExpression other);
    CIMAPSearchExpression newCIMAPSearchExpressionSearchNot(CIMAPSearchExpression expression);
    
    void deleteCIMAPSearchExpression(CIMAPSearchExpression self);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

mailcore::IMAPSearchExpression * cast(CIMAPSearchExpression self);
#endif

#endif
