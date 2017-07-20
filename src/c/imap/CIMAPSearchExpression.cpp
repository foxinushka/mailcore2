#include <MailCore/MCAsync.h>
#include "CIMAPSearchExpression.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPSearchExpression
#define structName CIMAPSearchExpression

CIMAPSearchExpression CIMAPSearchExpression_new(mailcore::IMAPSearchExpression *expr) {
    CIMAPSearchExpression self;
    self.instance = (mailcore::IMAPSearchExpression *) expr->copy();
    return self;
}

void CIMAPSearchExpression_release(CIMAPSearchExpression self) {
    C_SAFE_RELEASE(self.instance);
}

CIMAPSearchExpression CIMAPSearchExpression_SearchAll() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchAll());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchFrom(const UChar* value) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchFrom(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchRecipient(const UChar* value){
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchRecipient(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchTo(const UChar* value) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchTo(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchCc(const UChar* value) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchCc(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchBcc(const UChar* value) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchBcc(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchSubject(const UChar* value) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSubject(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchContent(const UChar* value) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchContent(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchBody(const UChar* value) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchBody(mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchUIDs(CIndexSet uids) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchUIDs(uids.instance));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchNumbers(CIndexSet numbers) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchNumbers(numbers.instance));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchHeader(const UChar* header, const UChar* value) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchHeader(mailcore::String::stringWithCharacters(header), mailcore::String::stringWithCharacters(value)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchRead() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchRead());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchUnread() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchUnread());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchFlagged() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchFlagged());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchUnflagged() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchUnflagged());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchAnswered() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchAnswered());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchUnanswered() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchUnanswered());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchDraft() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchDraft());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchUndraft() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchUndraft());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchDeleted() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchDeleted());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchSpam() {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSpam());
}

CIMAPSearchExpression CIMAPSearchExpression_SearchBeforeDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchBeforeDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchOnDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchOnDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchSinceDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSinceDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchBeforeReceivedDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchBeforeReceivedDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchOnReceivedDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchOnReceivedDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchSinceReceivedDate(time_t date) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSinceReceivedDate(date));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchSizeLargerThan(uint32_t size) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSizeLarger(size));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchSizeSmallerThan(uint32_t size) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchSizeSmaller(size));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchGmailThreadID(uint64_t number) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchGmailThreadID(number));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchGmailMessageID(uint64_t number) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchGmailMessageID(number));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchGmailRaw(const UChar* expr) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchGmailRaw(mailcore::String::stringWithCharacters(expr)));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchAnd(CIMAPSearchExpression expression, CIMAPSearchExpression other) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchAnd(expression.instance, other.instance));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchOr(CIMAPSearchExpression expression, CIMAPSearchExpression other) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchOr(expression.instance, other.instance));
}

CIMAPSearchExpression CIMAPSearchExpression_SearchNot(CIMAPSearchExpression expression) {
    return CIMAPSearchExpression_new(mailcore::IMAPSearchExpression::searchNot(expression.instance));
}
