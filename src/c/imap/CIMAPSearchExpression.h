#ifndef MAILCORE_СIMAP_SEARCH_EXPRESSION_H
#define MAILCORE_СIMAP_SEARCH_EXPRESSION_H

#include "CBase.h"
#include "CIndexSet.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPSearchExpression;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPSearchExpression, mailcore::IMAPSearchExpression)
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPSearchExpression)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchAll)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchFrom, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchRecipient, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchTo, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchCc, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchBcc, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSubject, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchContent, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchBody, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUIDs, CIndexSet)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchNumbers, CIndexSet)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchHeader, MailCoreString, MailCoreString)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchRead)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUnread)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchFlagged)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUnflagged)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchAnswered)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUnanswered)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchDraft)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUndraft)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchDeleted)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSpam)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchBeforeDate, time_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchOnDate, time_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSinceDate, time_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchBeforeReceivedDate, time_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchOnReceivedDate, time_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSinceReceivedDate, time_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSizeLargerThan, uint32_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSizeSmallerThan, uint32_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchGmailThreadID, uint64_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchGmailMessageID, uint64_t)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchGmailRaw, MailCoreString)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchAnd, CIMAPSearchExpression, CIMAPSearchExpression)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchOr, CIMAPSearchExpression, CIMAPSearchExpression)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchNot, CIMAPSearchExpression)

#ifdef __cplusplus
}
#endif

#endif
