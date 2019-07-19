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
    
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPSearchExpression)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchAll)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchFrom, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchRecipient, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchTo, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchCc, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchBcc, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSubject, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchContent, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchBody, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUIDs, CIndexSet)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchNumbers, CIndexSet)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchHeader, MailCoreString, MailCoreString)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchRead)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUnread)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchFlagged)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUnflagged)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchAnswered)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUnanswered)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchDraft)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchUndraft)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchDeleted)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSpam)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchBeforeDate, time_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchOnDate, time_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSinceDate, time_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchBeforeReceivedDate, time_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchOnReceivedDate, time_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSinceReceivedDate, time_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSizeLargerThan, uint32_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchSizeSmallerThan, uint32_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchGmailThreadID, uint64_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchGmailMessageID, uint64_t)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchGmailRaw, MailCoreString)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchAnd, CIMAPSearchExpression, CIMAPSearchExpression)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchOr, CIMAPSearchExpression, CIMAPSearchExpression)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPSearchExpression, CIMAPSearchExpression, searchNot, CIMAPSearchExpression)

#ifdef __cplusplus
}
#endif

#endif
