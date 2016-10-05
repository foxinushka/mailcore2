import Foundation

/** Used to construct an IMAP search query */
public class ImapSearchExpression {
	
    private var nativeInstance:CIMAPSearchExpression;
    
    internal func cast() -> CIMAPSearchExpression {
        return nativeInstance;
    }

    private init(_ expr: CIMAPSearchExpression) {
        self.nativeInstance = expr;
	}

	deinit {
        deleteCIMAPSearchExpression(nativeInstance);
	}
    
    /**
     Creates a search expression that returns all UIDS for the mailbox
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchAll]
     */
    public static func searchAll() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchAll());
    }
    
    /**
     Creates a search expression that matches the sender of an email.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     */
    public static func searchFrom(value: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchFrom(value.utf16CString));
    }
    
    /**
     Creates a search expression that matches any recipient of an email.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchRecipient:@"ngan@etpan.org"]
     **/
    public static func searchRecipient(value: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchRecipient(value.utf16CString));
    }
    
    /**
     Creates a search expression that matches on the receiver (to) of an email. Useful to check whether the mail is directly addressed to the receiver.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchTo:@"ngan@etpan.org"]
     **/
    public static func searchTo(value: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchTo(value.utf16CString));
    }
    
    /**
     Creates a search expression that matches on the cc of an email. Useful to check whether the mail is addressed to the receiver as cc.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchCc:@"ngan@etpan.org"]
     **/
    public static func searchCc(value: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchCc(value.utf16CString));
    }
    
    /**
     Creates a search expression that matches on the bcc field of an email. Useful to check whether the mail is addressed to the receiver as bcc.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBcc:@"ngan@etpan.org"]
     **/
    public static func searchBcc(value: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchBcc(value.utf16CString));
    }
    
    /*
     Creates a search expression that matches the subject of an email.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSubject:@"airline"]
     **/
    public static func searchSubject(value: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchSubject(value.utf16CString));
    }
    
    /**
     Creates a search expression that matches the content of an email, including the headers.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchContent:@"meeting"]
     */
    public static func searchContent(value: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchContent(value.utf16CString));
    }
    
    /**
     Creates a search expression that matches the content of an email, excluding the headers.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBody:@"building"]
     */
    public static func searchBody(value: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchBody(value.utf16CString));
    }
    
    /**
     Creates a search expression that matches the uids specified.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUids:uids]
     **/
    public static func searchUIDs(uids: IndexSet) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchUIDs(uids.cast()));
    }
    
    /**
     Creates a search expression that matches the message numbers specified.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchNumbers:numbers]
     **/
    public static func searchNumbers(numbers: IndexSet) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchNumbers(numbers.cast()));
    }
    
    /**
     Creates a search expression that matches the content of a specific header.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchHeader:@"List-Id" value:@"shoes"]
     **/
    public static func searchHeader(header: String, value: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchHeader(header.utf16CString, value.utf16CString));
    }
    
    /**
     Creates a search expression that matches messages with the Read flag.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchRead]
     **/
    public static func searchRead() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchRead());
    }
    
    /**
     Creates a search expression that matches messages without the Read flag.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUnread]
     **/
    public static func searchUnread() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchUnread());
    }
    
    /**
     Creates a search expression that matches messages that have been flagged.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchFlagged]
     **/
    public static func searchFlagged() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchUnread());
    }
    
    /**
     Creates a search expression that matches messages that haven't been flagged.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUnflagged]
     **/
    public static func searchUnflagged() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchUnflagged());
    }
    
    /**
     Creates a search expression that matches messages that have the answered flag set.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchAnswered]
     **/
    public static func searchAnswered() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchAnswered());
    }
    
    /**
     Creates a search expression that matches messages that don't have the answered flag set..
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUnanswered]
     **/
    public static func searchUnanswered() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchUnanswered());
    }
    
    /**
     Creates a search expression that matches draft messages.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchDraft]
     **/
    public static func searchDraft() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchDraft());
    }
    
    /**
     Creates a search expression that matches messages that aren't drafts.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUndraft]
     **/
    public static func searchUndraft() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchUndraft());
    }
    
    /**
     Creates a search expression that matches messages that are deleted.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchDeleted]
     **/
    public static func searchDeleted() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchDeleted());
    }
    
    /**
     Creates a search expression that matches messages that are spam.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSpam]
     **/
    static func searchSpam() -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchSpam());
    }
    
    /**
     Creates a search expression that matches messages sent before a date.
     
     Example:
     
     NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-(60.0 * 60.0 * 24.0)] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBeforeDate:yesterday]
     **/
    public static func searchBeforeDate(date: Date) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchBeforeDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages sent on a date.
     
     Example:
     
     NSDate *now = [NSDate date] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchOnDate:now]
     **/
    public static func searchOnDate(date: Date) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchOnDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages sent since a date.
     
     Example:
     
     NSDate *now = [NSDate date] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSinceDate:now]
     **/
    public static func searchSinceDate(date: Date) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchSinceDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages received before a date.
     
     Example:
     
     NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-(60.0 * 60.0 * 24.0)] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBeforeReceivedDate:yesterday]
     **/
    public static func searchBeforeReceivedDate(date: Date) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchBeforeReceivedDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages received on a date.
     
     Example:
     
     NSDate *now = [NSDate date] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchOnReceivedDate:now]
     **/
    public static func searchOnReceivedDate(date: Date) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchOnReceivedDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages received since a date.
     
     Example:
     
     NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-(60.0 * 60.0 * 24.0)] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSinceReceivedDate:yesterday]
     **/
    public static func searchSinceReceivedDate(date: Date) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchSinceReceivedDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages larger than a given size in bytes.
     
     Example:
     
     uint32_t minSize = 1024 * 10 -> ImapSearchExpression { // 10 KB
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSizeLargerThan:minSize]
     **/
    public static func searchSizeLargerThan(size: UInt32) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchSizeLargerThan(size));
    }
    
    /**
     Creates a search expression that matches messages smaller than a given size in bytes.
     
     Example:
     
     uint32_t maxSize = 1024 * 10 -> ImapSearchExpression { // 10 KB
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSizeSmallerThan:maxSize]
     **/
    public static func searchSizeSmallerThan(size: UInt32) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchSizeSmallerThan(size));
    }
    
    /**
     Creates a search expression that matches emails with the given gmail thread id
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchGmailThreadID:aThreadID]
     */
    public static func searchGmailThreadID(size: UInt64) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchGmailThreadID(size));
    }
    
    
    /**
     Creates a search expression that matches emails with the given gmail message id
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchGmailMessageID:aMessageID]
     */
    public static func searchGmailMessageID(size: UInt64) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchGmailMessageID(size));
    }
    
    /**
     Creates a search expression that gets emails that match a gmail raw search
     expression.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchGmailRaw:@"from:bill has:attachment filename:cal meeting schedule"]
     */
    public static func searchGmailRaw(expr: String) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchGmailRaw(expr.utf16CString));
    }
    
    
    /**
     Creates a search expression that's a disjunction of two search expressions.
     
     Example:
     
     MCOIMAPSearchExpression * exprFrom = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     MCOIMAPSearchExpression * exprSubject = [MCOIMAPSearchExpression searchContent:@"meeting"]
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchAnd:exprFrom other:exprSubject] -> ImapSearchExpression {
     **/
    
    public static func searchAnd(expression: ImapSearchExpression, other: ImapSearchExpression) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchAnd(expression.nativeInstance, other.nativeInstance));
    }
    /**
     Creates a search expression that's a conjunction of two search expressions.
     
     Example:
     
     MCOIMAPSearchExpression * exprFrom = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     MCOIMAPSearchExpression * exprOtherFrom = [MCOIMAPSearchExpression searchRecipient:@"ngan@etpan.org"]
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchOr:exprFrom exprOtherFrom] -> ImapSearchExpression {
     */
    public static func searchOr(expression: ImapSearchExpression, other: ImapSearchExpression) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchOr(expression.nativeInstance, other.nativeInstance));
    }
    
    /**
     Creates a search expression that matches when the argument is not matched.
     
     Example:
     
     MCOIMAPSearchExpression * exprSubject = [MCOIMAPSearchExpression searchSubject:@"airline"]
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchNot:exprSubject] -> ImapSearchExpression {
     The expression will match when the subject does not contain the word airline
     
     */
    public static func searchNot(expression: ImapSearchExpression) -> ImapSearchExpression {
        return ImapSearchExpression(newCIMAPSearchExpressionSearchNot(expression.nativeInstance));
    }
    
    
}
