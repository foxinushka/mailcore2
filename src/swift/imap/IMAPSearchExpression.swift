import Foundation
import CMailCore

/** Used to construct an IMAP search query */
public class MCOIMAPSearchExpression: NSObjectCompat {
	
    private var nativeInstance:CIMAPSearchExpression;
    
    internal func cast() -> CIMAPSearchExpression {
        return nativeInstance;
    }

    private init(_ expr: CIMAPSearchExpression) {
        self.nativeInstance = CIMAPSearchExpression(cobject: expr.copy())
	}

	deinit {
        nativeInstance.release()
	}
    
    /**
     Creates a search expression that returns all UIDS for the mailbox
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchAll]
     */
    public static func searchAll() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchAll());
    }
    
    /**
     Creates a search expression that matches the sender of an email.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     */
    public static func searchFrom(_ value: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchFrom(value.mailCoreString()))
    }
    
    /**
     Creates a search expression that matches any recipient of an email.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchRecipient:@"ngan@etpan.org"]
     **/
    public static func searchRecipient(_ value: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchRecipient(value.mailCoreString()))
    }
    
    /**
     Creates a search expression that matches on the receiver (to) of an email. Useful to check whether the mail is directly addressed to the receiver.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchTo:@"ngan@etpan.org"]
     **/
    public static func searchTo(_ value: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchTo(value.mailCoreString()))
    }
    
    /**
     Creates a search expression that matches on the cc of an email. Useful to check whether the mail is addressed to the receiver as cc.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchCc:@"ngan@etpan.org"]
     **/
    public static func searchCc(_ value: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchCc(value.mailCoreString()))
    }
    
    /**
     Creates a search expression that matches on the bcc field of an email. Useful to check whether the mail is addressed to the receiver as bcc.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBcc:@"ngan@etpan.org"]
     **/
    public static func searchBcc(_ value: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchBcc(value.mailCoreString()))
    }
    
    /*
     Creates a search expression that matches the subject of an email.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSubject:@"airline"]
     **/
    public static func searchSubject(_ value: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchSubject(value.mailCoreString()))
    }
    
    /**
     Creates a search expression that matches the content of an email, including the headers.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchContent:@"meeting"]
     */
    public static func searchContent(_ value: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchContent(value.mailCoreString()))
    }
    
    /**
     Creates a search expression that matches the content of an email, excluding the headers.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBody:@"building"]
     */
    public static func searchBody(_ value: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchBody(value.mailCoreString()))
    }
    
    /**
     Creates a search expression that matches the uids specified.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUids:uids]
     **/
    public static func searchUIDs(_ uids: MCOIndexSet) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchUIDs(uids.cast()));
    }
    
    /**
     Creates a search expression that matches the message numbers specified.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchNumbers:numbers]
     **/
    public static func searchNumbers(_ numbers: MCOIndexSet) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchNumbers(numbers.cast()));
    }
    
    /**
     Creates a search expression that matches the content of a specific header.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchHeader:@"List-Id" value:@"shoes"]
     **/
    public static func searchHeader(_ header: String, value: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchHeader(header.mailCoreString(), value.mailCoreString()))
    }
    
    /**
     Creates a search expression that matches messages with the Read flag.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchRead]
     **/
    public static func searchRead() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchRead());
    }
    
    /**
     Creates a search expression that matches messages without the Read flag.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUnread]
     **/
    public static func searchUnread() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchUnread());
    }
    
    /**
     Creates a search expression that matches messages that have been flagged.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchFlagged]
     **/
    public static func searchFlagged() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchFlagged());
    }
    
    /**
     Creates a search expression that matches messages that haven't been flagged.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUnflagged]
     **/
    public static func searchUnflagged() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchUnflagged());
    }
    
    /**
     Creates a search expression that matches messages that have the answered flag set.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchAnswered]
     **/
    public static func searchAnswered() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchAnswered());
    }
    
    /**
     Creates a search expression that matches messages that don't have the answered flag set..
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUnanswered]
     **/
    public static func searchUnanswered() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchUnanswered());
    }
    
    /**
     Creates a search expression that matches draft messages.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchDraft]
     **/
    public static func searchDraft() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchDraft());
    }
    
    /**
     Creates a search expression that matches messages that aren't drafts.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchUndraft]
     **/
    public static func searchUndraft() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchUndraft());
    }
    
    /**
     Creates a search expression that matches messages that are deleted.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchDeleted]
     **/
    public static func searchDeleted() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchDeleted());
    }
    
    /**
     Creates a search expression that matches messages that are spam.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSpam]
     **/
    static func searchSpam() -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression_searchSpam());
    }
    
    /**
     Creates a search expression that matches messages sent before a date.
     
     Example:
     
     NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-(60.0 * 60.0 * 24.0)] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBeforeDate:yesterday]
     **/
    public static func searchBeforeDate(_ date: Date) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchBeforeDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages sent on a date.
     
     Example:
     
     NSDate *now = [NSDate date] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchOnDate:now]
     **/
    public static func searchOnDate(_ date: Date) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchOnDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages sent since a date.
     
     Example:
     
     NSDate *now = [NSDate date] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSinceDate:now]
     **/
    public static func searchSinceDate(_ date: Date) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchSinceDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages received before a date.
     
     Example:
     
     NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-(60.0 * 60.0 * 24.0)] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchBeforeReceivedDate:yesterday]
     **/
    public static func searchBeforeReceivedDate(_ date: Date) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchBeforeReceivedDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages received on a date.
     
     Example:
     
     NSDate *now = [NSDate date] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchOnReceivedDate:now]
     **/
    public static func searchOnReceivedDate(_ date: Date) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchOnReceivedDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages received since a date.
     
     Example:
     
     NSDate *yesterday = [NSDate dateWithTimeIntervalSinceNow:-(60.0 * 60.0 * 24.0)] -> ImapSearchExpression {
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSinceReceivedDate:yesterday]
     **/
    public static func searchSinceReceivedDate(_ date: Date) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchSinceReceivedDate(time_t(date.timeIntervalSince1970)));
    }
    
    /**
     Creates a search expression that matches messages larger than a given size in bytes.
     
     Example:
     
     uint32_t minSize = 1024 * 10 -> ImapSearchExpression { // 10 KB
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSizeLargerThan:minSize]
     **/
    public static func searchSizeLargerThan(_ size: UInt32) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchSizeLargerThan(size));
    }
    
    /**
     Creates a search expression that matches messages smaller than a given size in bytes.
     
     Example:
     
     uint32_t maxSize = 1024 * 10 -> ImapSearchExpression { // 10 KB
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchSizeSmallerThan:maxSize]
     **/
    public static func searchSizeSmallerThan(_ size: UInt32) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchSizeSmallerThan(size));
    }
    
    /**
     Creates a search expression that matches emails with the given gmail thread id
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchGmailThreadID:aThreadID]
     */
    public static func searchGmailThreadID(_ size: UInt64) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchGmailThreadID(size));
    }
    
    
    /**
     Creates a search expression that matches emails with the given gmail message id
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchGmailMessageID:aMessageID]
     */
    public static func searchGmailMessageID(_ size: UInt64) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchGmailMessageID(size));
    }
    
    /**
     Creates a search expression that gets emails that match a gmail raw search
     expression.
     
     Example:
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchGmailRaw:@"from:bill has:attachment filename:cal meeting schedule"]
     */
    public static func searchGmailRaw(_ expr: String) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchGmailRaw(expr.mailCoreString()))
    }
    
    
    /**
     Creates a search expression that's a disjunction of two search expressions.
     
     Example:
     
     MCOIMAPSearchExpression * exprFrom = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     MCOIMAPSearchExpression * exprSubject = [MCOIMAPSearchExpression searchContent:@"meeting"]
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchAnd:exprFrom other:exprSubject] -> ImapSearchExpression {
     **/
    
    public static func searchAnd(_ expression: MCOIMAPSearchExpression, other: MCOIMAPSearchExpression) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchAnd(expression.nativeInstance, other.nativeInstance));
    }
    /**
     Creates a search expression that's a conjunction of two search expressions.
     
     Example:
     
     MCOIMAPSearchExpression * exprFrom = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     MCOIMAPSearchExpression * exprOtherFrom = [MCOIMAPSearchExpression searchRecipient:@"ngan@etpan.org"]
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchOr:exprFrom exprOtherFrom] -> ImapSearchExpression {
     */
    public static func searchOr(_ expression: MCOIMAPSearchExpression, other: MCOIMAPSearchExpression) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchOr(expression.nativeInstance, other.nativeInstance));
    }
    
    /**
     Creates a search expression that matches when the argument is not matched.
     
     Example:
     
     MCOIMAPSearchExpression * exprSubject = [MCOIMAPSearchExpression searchSubject:@"airline"]
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchNot:exprSubject] -> ImapSearchExpression {
     The expression will match when the subject does not contain the word airline
     
     */
    public static func searchNot(_ expression: MCOIMAPSearchExpression) -> MCOIMAPSearchExpression {
        return MCOIMAPSearchExpression(CIMAPSearchExpression.searchNot(expression.nativeInstance));
    }
    
    
}
