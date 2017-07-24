import Foundation


/** Used to construct an IMAP search query */
public class IMAPSearchExpression {
	
    private var nativeInstance:CIMAPSearchExpression;
    
    internal func cast() -> CIMAPSearchExpression {
        return nativeInstance;
    }

    private init(_ expr: CIMAPSearchExpression) {
        self.nativeInstance = expr;
	}

	deinit {
        nativeInstance.release()
	}
    
    /**
     Creates a search expression that returns all UIDS for the mailbox
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchAll]
     */
    public static func searchAll() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchAll());
    }
    
    /**
     Creates a search expression that matches the sender of an email.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     */
    public static func searchFrom(value: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(value, { CIMAPSearchExpression.searchFrom($0) }));
    }
    
    /**
     Creates a search expression that matches any recipient of an email.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchRecipient:@"ngan@etpan.org"]
     **/
    public static func searchRecipient(value: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(value, { CIMAPSearchExpression.searchRecipient($0) }));
    }
    
    /**
     Creates a search expression that matches on the receiver (to) of an email. Useful to check whether the mail is directly addressed to the receiver.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchTo:@"ngan@etpan.org"]
     **/
    public static func searchTo(value: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(value, { CIMAPSearchExpression.searchTo($0) }));
    }
    
    /**
     Creates a search expression that matches on the cc of an email. Useful to check whether the mail is addressed to the receiver as cc.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchCc:@"ngan@etpan.org"]
     **/
    public static func searchCc(value: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(value, { CIMAPSearchExpression.searchCc($0) }));
    }
    
    /**
     Creates a search expression that matches on the bcc field of an email. Useful to check whether the mail is addressed to the receiver as bcc.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBcc:@"ngan@etpan.org"]
     **/
    public static func searchBcc(value: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(value, { CIMAPSearchExpression.searchBcc($0) }));
    }
    
    /*
     Creates a search expression that matches the subject of an email.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSubject:@"airline"]
     **/
    public static func searchSubject(value: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(value, { CIMAPSearchExpression.searchSubject($0) }));
    }
    
    /**
     Creates a search expression that matches the content of an email, including the headers.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchContent:@"meeting"]
     */
    public static func searchContent(value: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(value, { CIMAPSearchExpression.searchContent($0) }));
    }
    
    /**
     Creates a search expression that matches the content of an email, excluding the headers.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBody:@"building"]
     */
    public static func searchBody(value: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(value, { CIMAPSearchExpression.searchBody($0) }));
    }
    
    /**
     Creates a search expression that matches the uids specified.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUids:uids]
     **/
    public static func searchUIDs(uids: IndexSet) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchUIDs(uids.cast()));
    }
    
    /**
     Creates a search expression that matches the message numbers specified.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchNumbers:numbers]
     **/
    public static func searchNumbers(numbers: IndexSet) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchNumbers(numbers.cast()));
    }
    
    /**
     Creates a search expression that matches the content of a specific header.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchHeader:@"List-Id" value:@"shoes"]
     **/
    public static func searchHeader(header: String, value: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(header, value, { headerPtr, valuePtr in
            CIMAPSearchExpression.searchHeader(headerPtr, valuePtr)
        }))
    }
    
    /**
     Creates a search expression that matches messages with the Read flag.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchRead]
     **/
    public static func searchRead() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchRead());
    }
    
    /**
     Creates a search expression that matches messages without the Read flag.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUnread]
     **/
    public static func searchUnread() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchUnread());
    }
    
    /**
     Creates a search expression that matches messages that have been flagged.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchFlagged]
     **/
    public static func searchFlagged() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchUnread());
    }
    
    /**
     Creates a search expression that matches messages that haven't been flagged.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUnflagged]
     **/
    public static func searchUnflagged() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchUnflagged());
    }
    
    /**
     Creates a search expression that matches messages that have the answered flag set.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchAnswered]
     **/
    public static func searchAnswered() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchAnswered());
    }
    
    /**
     Creates a search expression that matches messages that don't have the answered flag set..
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUnanswered]
     **/
    public static func searchUnanswered() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchUnanswered());
    }
    
    /**
     Creates a search expression that matches draft messages.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchDraft]
     **/
    public static func searchDraft() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchDraft());
    }
    
    /**
     Creates a search expression that matches messages that aren't drafts.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUndraft]
     **/
    public static func searchUndraft() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchUndraft());
    }
    
    /**
     Creates a search expression that matches messages that are deleted.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchDeleted]
     **/
    public static func searchDeleted() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchDeleted());
    }
    
    /**
     Creates a search expression that matches messages that are spam.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSpam]
     **/
    static func searchSpam() -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression_SearchSpam());
    }
    
    /**
     Creates a search expression that matches messages sent before a date.
     
     Example:
     
     NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-(60.0 * 60.0 * 24.0)] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBeforeDate:yesterday]
     **/
    public static func searchBeforeDate(date: Date) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchBeforeDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages sent on a date.
     
     Example:
     
     NSDate *now = [NSDate date] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchOnDate:now]
     **/
    public static func searchOnDate(date: Date) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchOnDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages sent since a date.
     
     Example:
     
     NSDate *now = [NSDate date] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSinceDate:now]
     **/
    public static func searchSinceDate(date: Date) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchSinceDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages received before a date.
     
     Example:
     
     NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-(60.0 * 60.0 * 24.0)] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBeforeReceivedDate:yesterday]
     **/
    public static func searchBeforeReceivedDate(date: Date) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchBeforeReceivedDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages received on a date.
     
     Example:
     
     NSDate *now = [NSDate date] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchOnReceivedDate:now]
     **/
    public static func searchOnReceivedDate(date: Date) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchOnReceivedDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages received since a date.
     
     Example:
     
     NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-(60.0 * 60.0 * 24.0)] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSinceReceivedDate:yesterday]
     **/
    public static func searchSinceReceivedDate(date: Date) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchSinceReceivedDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages larger than a given size in bytes.
     
     Example:
     
     uint32_t minSize = 1024 * 10 -> ImapSearchExpression { // 10 KB
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSizeLargerThan:minSize]
     **/
    public static func searchSizeLargerThan(size: UInt32) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchSizeLargerThan(size));
    }
    
    /**
     Creates a search expression that matches messages smaller than a given size in bytes.
     
     Example:
     
     uint32_t maxSize = 1024 * 10 -> ImapSearchExpression { // 10 KB
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSizeSmallerThan:maxSize]
     **/
    public static func searchSizeSmallerThan(size: UInt32) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchSizeSmallerThan(size));
    }
    
    /**
     Creates a search expression that matches emails with the given gmail thread id
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchGmailThreadID:aThreadID]
     */
    public static func searchGmailThreadID(size: UInt64) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchGmailThreadID(size));
    }
    
    
    /**
     Creates a search expression that matches emails with the given gmail message id
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchGmailMessageID:aMessageID]
     */
    public static func searchGmailMessageID(size: UInt64) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchGmailMessageID(size));
    }
    
    /**
     Creates a search expression that gets emails that match a gmail raw search
     expression.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchGmailRaw:@"from:bill has:attachment filename:cal meeting schedule"]
     */
    public static func searchGmailRaw(expr: String) -> IMAPSearchExpression {
        return IMAPSearchExpression(String.utf16(expr, { CIMAPSearchExpression.searchGmailRaw($0) }));
    }
    
    
    /**
     Creates a search expression that's a disjunction of two search expressions.
     
     Example:
     
     MCOIMAPSearchExpression * exprFrom = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     MCOIMAPSearchExpression * exprSubject = [MCOIMAPSearchExpression searchContent:@"meeting"]
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchAnd:exprFrom other:exprSubject] -> ImapSearchExpression {
     **/
    
    public static func searchAnd(expression: IMAPSearchExpression, other: IMAPSearchExpression) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchAnd(expression.nativeInstance, other: other.nativeInstance));
    }
    /**
     Creates a search expression that's a conjunction of two search expressions.
     
     Example:
     
     MCOIMAPSearchExpression * exprFrom = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     MCOIMAPSearchExpression * exprOtherFrom = [MCOIMAPSearchExpression searchRecipient:@"ngan@etpan.org"]
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchOr:exprFrom exprOtherFrom] -> ImapSearchExpression {
     */
    public static func searchOr(expression: IMAPSearchExpression, other: IMAPSearchExpression) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchOr(expression.nativeInstance, other: other.nativeInstance));
    }
    
    /**
     Creates a search expression that matches when the argument is not matched.
     
     Example:
     
     MCOIMAPSearchExpression * exprSubject = [MCOIMAPSearchExpression searchSubject:@"airline"]
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchNot:exprSubject] -> ImapSearchExpression {
     The expression will match when the subject does not contain the word airline
     
     */
    public static func searchNot(expression: IMAPSearchExpression) -> IMAPSearchExpression {
        return IMAPSearchExpression(CIMAPSearchExpression.searchNot(expression.nativeInstance));
    }
    
    
}
