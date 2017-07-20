#ifndef MAILCORE_СIMAP_SEARCH_EXPRESSION_H
#define MAILCORE_СIMAP_SEARCH_EXPRESSION_H

#include "CBase.h"
#include "CIndexSet.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPSearchExpression;
}

extern "C" {
#endif
    
    struct CIMAPSearchExpression{
#ifdef __cplusplus
        mailcore::IMAPSearchExpression*     instance;
#else
        void*                               instance;
#endif
    };
    typedef struct CIMAPSearchExpression CIMAPSearchExpression;

    CIMAPSearchExpression   CIMAPSearchExpression_SearchAll()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchAll());
    
    CIMAPSearchExpression   CIMAPSearchExpression_SearchFrom(const UChar* value)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchFrom(_:));
    
    CIMAPSearchExpression   CIMAPSearchExpression_SearchRecipient(const UChar* value)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchRecipient(_:));
    
    CIMAPSearchExpression   CIMAPSearchExpression_SearchTo(const UChar* value)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchTo(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchCc(const UChar* value)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchCc(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchBcc(const UChar* value)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchBcc(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchSubject(const UChar* value)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchSubject(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchContent(const UChar* value)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchContent(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchBody(const UChar* value)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchBody(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchUIDs(CIndexSet uids)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchUIDs(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchNumbers(CIndexSet numbers)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchNumbers(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchHeader(const UChar* header, const UChar* value)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchHeader(_:_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchRead()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchRead());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchUnread()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchUnread());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchFlagged()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchFlagged());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchUnflagged()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchUnflagged());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchAnswered()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchAnswered());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchUnanswered()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchUnanswered());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchDraft()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchDraft());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchUndraft()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchUndraft());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchDeleted()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchDeleted());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchSpam()
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchSpam());
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchBeforeDate(time_t date)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchBeforeDate(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchOnDate(time_t date)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchOnDate(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchSinceDate(time_t date)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchSinceDate(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchBeforeReceivedDate(time_t date)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchBeforeReceivedDate(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchOnReceivedDate(time_t date)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchOnReceivedDate(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchSinceReceivedDate(time_t date)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchSinceReceivedDate(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchSizeLargerThan(uint32_t size)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchSizeLargerThan(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchSizeSmallerThan(uint32_t size)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchSizeSmallerThan(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchGmailThreadID(uint64_t number)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchGmailThreadID(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchGmailMessageID(uint64_t number)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchGmailMessageID(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchGmailRaw(const UChar* expr)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchGmailRaw(_:));
                            
    CIMAPSearchExpression   CIMAPSearchExpression_SearchAnd(CIMAPSearchExpression expression, CIMAPSearchExpression other)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchAnd(_:other:));
    
    CIMAPSearchExpression   CIMAPSearchExpression_SearchOr(CIMAPSearchExpression expression, CIMAPSearchExpression other)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchOr(_:other:));
    
    CIMAPSearchExpression   CIMAPSearchExpression_SearchNot(CIMAPSearchExpression expression)
                            CF_SWIFT_NAME(CIMAPSearchExpression.searchNot(_:));
                            
    
    void                    CIMAPSearchExpression_release(CIMAPSearchExpression self)
                            CF_SWIFT_NAME(CIMAPSearchExpression.release(self:));

#ifdef __cplusplus
}
#endif

#endif
