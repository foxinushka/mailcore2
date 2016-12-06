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
    
    internal func canPreviewPart(part: CAbstractPart) -> UInt8 {
        return rendererDelegate!.abstractMessage(message, canPreviewPart: AbstractPart(part)) ? 1 : 0;
    }
    
    internal func shouldShowPartBlock(part: CAbstractPart) -> UInt8 {
        return rendererDelegate!.abstractMessage(message, shouldShowPart: AbstractPart(part)) ? 1 : 0;
    }
    
    internal func templateValuesForHeaderBlock(header: CMessageHeader) -> CDictionary {
        return Dictionary<String, String>.cast(rendererDelegate!.abstractMessage(message, templateValuesForHeader: MessageHeader(header)));
    }
    
    internal func templateValuesForPartBlock(part: CAbstractPart) -> CDictionary {
        return Dictionary<String, String>.cast(rendererDelegate!.abstractMessage(message, templateValuesForPart: AbstractPart(part)));
    }
    
    internal func templateForMainHeaderBlock(header: CMessageHeader) -> CObject {
        return rendererDelegate!.abstractMessage(message, templateForMainHeader: MessageHeader(header)).cast();
    }
    
    internal func templateForImageBlock(part: CAbstractPart) -> CObject {
        return rendererDelegate!.abstractMessage(message, templateForImage: AbstractPart(part)).cast()
    }
    
    internal func templateForAttachmentBlock(part: CAbstractPart) -> CObject {
        return rendererDelegate!.abstractMessage(message, templateForAttachment: AbstractPart(part)).cast()
    }
    
    internal func templateForMessageBlock(msg: CAbstractMessage) -> CObject {
        return rendererDelegate!.abstractMessageTemplateForMessage(message).cast()
    }
    
    internal func templateForEmbeddedMessageBlock(part: CAbstractMessagePart) -> CObject {
        return rendererDelegate!.abstractMessage(message, templateForEmbeddedMessage: AbstractMessagePart(abstractMessagePart: part)).cast();
    }
    
    internal func templateForEmbeddedMessageHeaderBlock(header: CMessageHeader) -> CObject {
        return rendererDelegate!.abstractMessage(message, templateForEmbeddedMessageHeader: MessageHeader(header)).cast();
    }
    
    internal func templateForAttachmentSeparatorBlock() -> CObject {
        return rendererDelegate!.abstractMessageTemplateForAttachmentSeparator(message).cast();
    }
    
    internal func cleanHTMLForPartBlock(html: UnsafePointer<UInt16>?) -> CObject {
        return rendererDelegate!.abstractMessage(message, cleanHTMLForPart: String(utf16: html)).cast();
    }
    
    internal func filterHTMLForPartBlock(html: UnsafePointer<UInt16>?) -> CObject {
        return rendererDelegate!.abstractMessage(message, filterHTMLForPart: String(utf16: html)).cast();
    }
    
    internal func filterHTMLForMessageBlock(html: UnsafePointer<UInt16>?) -> CObject {
        return rendererDelegate!.abstractMessage(message, filterHTMLForMessage: String(utf16: html)).cast();
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
    
    internal func cast() -> CAbstractMessageRendererCallback {
        return nativeInstance;
    }
}
