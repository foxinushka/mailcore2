#include <MailCore/MCAsync.h>
#include "CIMAPSearchExpression.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPSearchExpression
#define structName CIMAPSearchExpression

C_SYNTHESIZE_CONSTRUCTOR()

C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchAll)

C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchFrom, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchRecipient, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchTo, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchCc, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchBcc, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchSubject, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchContent, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchBody, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchUIDs, CIndexSet)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchNumbers, CIndexSet)

C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchHeader, MailCoreString, MailCoreString)

C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchRead)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchUnread)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchFlagged)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchUnflagged)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchAnswered)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchUnanswered)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchDraft)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchUndraft)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchDeleted)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchSpam)

CIMAPSearchExpression CIMAPSearchExpression_searchBeforeDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchBeforeDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_searchOnDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchOnDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_searchSinceDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSinceDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_searchBeforeReceivedDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchBeforeReceivedDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_searchOnReceivedDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchOnReceivedDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_searchSinceReceivedDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSinceReceivedDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_searchSizeLargerThan(uint32_t size) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSizeLarger(size));
}

CIMAPSearchExpression CIMAPSearchExpression_searchSizeSmallerThan(uint32_t size) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSizeSmaller(size));
}

CIMAPSearchExpression CIMAPSearchExpression_searchGmailThreadID(uint64_t number) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchGmailThreadID(number));
}

CIMAPSearchExpression CIMAPSearchExpression_searchGmailMessageID(uint64_t number) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchGmailMessageID(number));
}

C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchGmailRaw, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchAnd, CIMAPSearchExpression, CIMAPSearchExpression)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchOr, CIMAPSearchExpression, CIMAPSearchExpression)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CIMAPSearchExpression, searchNot, CIMAPSearchExpression)
