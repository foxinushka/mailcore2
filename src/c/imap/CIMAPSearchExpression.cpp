#include <MailCore/MCAsync.h>
#include "CIMAPSearchExpression.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPSearchExpression
#define structName CIMAPSearchExpression

CIMAPSearchExpression newCIMAPSearchExpression(mailcore::IMAPSearchExpression *expr) {
    CIMAPSearchExpression self;
    self.instance = (mailcore::IMAPSearchExpression *) expr->copy();
    return self;
}

void deleteCIMAPSearchExpression(CIMAPSearchExpression self) {
    C_SAFE_RELEASE(self);
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchAll() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchAll());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchFrom(const UChar* value) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchFrom(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchRecipient(const UChar* value){
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchRecipient(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchTo(const UChar* value) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchTo(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchCc(const UChar* value) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchCc(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchBcc(const UChar* value) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchBcc(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchSubject(const UChar* value) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchSubject(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchContent(const UChar* value) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchContent(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchBody(const UChar* value) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchBody(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchUIDs(CIndexSet uids) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchUIDs(uids.instance));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchNumbers(CIndexSet numbers) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchNumbers(numbers.instance));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchHeader(const UChar* header, const UChar* value) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchHeader(mailcore::String::stringWithCharacters(header), mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchRead() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchRead());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchUnread() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchUnread());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchFlagged() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchFlagged());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchUnflagged() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchUnflagged());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchAnswered() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchAnswered());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchUnanswered() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchUnanswered());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchDraft() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchDraft());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchUndraft() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchUndraft());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchDeleted() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchDeleted());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchSpam() {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchSpam());
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchBeforeDate(time_t date) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchBeforeDate(date));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchOnDate(time_t date) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchOnDate(date));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchSinceDate(time_t date) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchSinceDate(date));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchBeforeReceivedDate(time_t date) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchBeforeReceivedDate(date));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchOnReceivedDate(time_t date) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchOnReceivedDate(date));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchSinceReceivedDate(time_t date) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchSinceReceivedDate(date));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchSizeLargerThan(uint32_t size) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchSizeLarger(size));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchSizeSmallerThan(uint32_t size) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchSizeSmaller(size));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchGmailThreadID(uint64_t number) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchGmailThreadID(number));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchGmailMessageID(uint64_t number) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchGmailMessageID(number));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchGmailRaw(const UChar* expr) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchGmailRaw(mailcore::String::stringWithCharacters(expr)));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchAnd(CIMAPSearchExpression expression, CIMAPSearchExpression other) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchAnd(expression.instance, other.instance));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchOr(CIMAPSearchExpression expression, CIMAPSearchExpression other) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchOr(expression.instance, other.instance));
}

CIMAPSearchExpression newCIMAPSearchExpressionSearchNot(CIMAPSearchExpression expression) {
    return newCIMAPSearchExpression(mailcore::IMAPSearchExpression::searchNot(expression.instance));
}
