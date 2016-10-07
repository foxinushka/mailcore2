import Foundation

internal class AbstractMessageRendererCallback {
    
    internal var message: AbstractMessage;
    
    private var rendererDelegate: HtmlRendererDelegate?;
    private var imapDelegate: HtmlRendererImapDelegate?;
    private var nativeInstance: CAbstractMessageRendererCallback;
    
    internal init(message: AbstractMessage) {
        self.message = message;
        self.nativeInstance = newCAbstractMessageRendererCallback();
    }
    
    internal func setHtmlRenderDelegate(delegate: HtmlRendererDelegate) {
        self.rendererDelegate = delegate;
        self.nativeInstance.setHtmlRendererDelegateCallbacks(self.nativeInstance, canPreviewPart, shouldShowPartBlock, templateValuesForHeaderBlock,
                                                         templateValuesForPartBlock, templateForMainHeaderBlock, templateForImageBlock, templateForAttachmentBlock,
                                                         templateForMessageBlock, templateForEmbeddedMessageBlock, templateForEmbeddedMessageHeaderBlock, templateForAttachmentSeparatorBlock,
                                                         cleanHTMLForPartBlock, filterHTMLForPartBlock,filterHTMLForMessageBlock);
    }
    
    internal func setHtmlRenderImapDelegate(delegate: HtmlRendererImapDelegate) {
        self.imapDelegate = delegate;
        self.nativeInstance.setHtmlRedererImapDelefate(self.nativeInstance, dataForIMAPPart, prefetchAttachmentIMAPPart, prefetchImageIMAPPart);
    }
    
    internal func canPreviewPart(part: CAbstractPart) -> Bool {
        return rendererDelegate!.abstractMessage(message, canPreviewPart: AbstractPart(part));
    }
    
    internal func shouldShowPartBlock(part: CAbstractPart) -> Bool {
        return rendererDelegate!.abstractMessage(message, shouldShowPart: AbstractPart(part));
    }
    
    internal func templateValuesForHeaderBlock(header: CMessageHeader) -> CDictionary {
        return Dictionary<String, String>.cast(rendererDelegate!.abstractMessage(message, templateValuesForHeader: MessageHeader(header)));
    }
    
    internal func templateValuesForPartBlock(part: CAbstractPart) -> CDictionary {
        return Dictionary<String, String>.cast(rendererDelegate!.abstractMessage(message, templateValuesForPart: AbstractPart(part)));
    }
    
    internal func templateForMainHeaderBlock(header: CMessageHeader) -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessage(message, templateForMainHeader: MessageHeader(header)).utf16CString);
    }
    
    internal func templateForImageBlock(part: CAbstractPart) -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessage(message, templateForImage: AbstractPart(part)).utf16CString);
    }
    
    internal func templateForAttachmentBlock(part: CAbstractPart) -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessage(message, templateForAttachment: AbstractPart(part)).utf16CString);
    }
    
    internal func templateForMessageBlock(msg: CAbstractMessage) -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessageTemplateForMessage(message).utf16CString);
    }
    
    internal func templateForEmbeddedMessageBlock(part: CAbstractMessagePart) -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessage(message, templateForEmbeddedMessage: AbstractMessagePart(abstractMessagePart: part)).utf16CString);
    }
    
    internal func templateForEmbeddedMessageHeaderBlock(header: CMessageHeader) -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessage(message, templateForEmbeddedMessageHeader: MessageHeader(header)).utf16CString);
    }
    
    internal func templateForAttachmentSeparatorBlock() -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessageTemplateForAttachmentSeparator(message).utf16CString);
    }
    
    internal func cleanHTMLForPartBlock(html: UnsafePointer<UInt16>?) -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessage(message, cleanHTMLForPart: String(utf16: html)).utf16CString);
    }
    
    internal func filterHTMLForPartBlock(html: UnsafePointer<UInt16>?) -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessage(message, filterHTMLForPart: String(utf16: html)).utf16CString);
    }
    
    internal func filterHTMLForMessageBlock(html: UnsafePointer<UInt16>?) -> UnsafePointer<UInt16> {
        return UnsafePointer<UInt16>(rendererDelegate!.abstractMessage(message, filterHTMLForMessage: String(utf16: html)).utf16CString);
    }
    
    internal func dataForIMAPPart(folder: UnsafePointer<UInt16>?, part: CIMAPPart) -> CData {
        let data = imapDelegate!.abstractMessage(message, dataForIMAPPart: ImapPart(part: part), folder: String(utf16: folder));
        return newCData(data.bytes(), data.length());
    }
    
    internal func prefetchAttachmentIMAPPart(folder: UnsafePointer<UInt16>?, part: CIMAPPart) {
        imapDelegate!.abstractMessage(message, prefetchAttachmentIMAPPart: ImapPart(part: part), folder: String(utf16: folder));
    }
    
    internal func prefetchImageIMAPPart(folder: UnsafePointer<UInt16>?, part: CIMAPPart) {
        imapDelegate!.abstractMessage(message, prefetchImageIMAPPart: ImapPart(part: part), folder: String(utf16: folder));
    }
}
