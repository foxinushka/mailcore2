import Foundation
import CCore

internal class AbstractMessageRendererCallback {
    
    internal var message: AbstractMessage;
    
    fileprivate var rendererDelegate: HTMLRendererDelegate?;
    fileprivate var imapDelegate: HTMLRendererImapDelegate?;
    private var nativeInstance: CAbstractMessageRendererCallback!;
    
    internal init(message: AbstractMessage) {
        self.message = message;
        self.nativeInstance = CAbstractMessageRendererCallback(canPreviewPartBlock: canPreviewPart,
                                                               shouldShowPartBlock: shouldShowPartBlock,
                                                               templateValuesForHeaderBlock: templateValuesForHeaderBlock,
                                                               templateValuesForPartBlock: templateValuesForPartBlock,
                                                               templateForMainHeaderBlock: templateForMainHeaderBlock,
                                                               templateForImageBlock: templateForImageBlock,
                                                               templateForAttachmentBlock: templateForAttachmentBlock,
                                                               templateForMessageBlock: templateForMessageBlock,
                                                               templateForEmbeddedMessageBlock: templateForEmbeddedMessageBlock,
                                                               templateForEmbeddedMessageHeaderBlock: templateForEmbeddedMessageHeaderBlock,
                                                               templateForAttachmentSeparatorBlock: templateForAttachmentSeparatorBlock,
                                                               cleanHTMLForPartBlock: cleanHTMLForPartBlock,
                                                               filterHTMLForPartBlock: filterHTMLForPartBlock,
                                                               filterHTMLForMessageBlock: filterHTMLForMessageBlock,
                                                               dataForIMAPPartBlock: dataForIMAPPart,
                                                               prefetchAttachmentIMAPPartBlock: prefetchAttachmentIMAPPart,
                                                               prefetchImageIMAPPartBlock: prefetchImageIMAPPart,
                                                               userInfo: Unmanaged.passUnretained(self).toOpaque());
    }
    
    internal func setHtmlRenderDelegate(delegate: HTMLRendererDelegate) {
        self.rendererDelegate = delegate;
    }
    
    internal func setHtmlRenderImapDelegate(delegate: HTMLRendererImapDelegate) {
        self.imapDelegate = delegate;
    }
    
    internal func cast() -> CAbstractMessageRendererCallback {
        return nativeInstance;
    }
}

//MARK: C-Functions
func canPreviewPart(ref: UnsafeRawPointer?, part: CAbstractPart) -> UInt8 {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, canPreviewPart: AbstractPart(part)) ? 1 : 0;
}

func shouldShowPartBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> UInt8 {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, shouldShowPart: AbstractPart(part)) ? 1 : 0;
}

func templateValuesForHeaderBlock(ref: UnsafeRawPointer?, header: CMessageHeader) -> CDictionary {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return Dictionary<String, String>.cast(selfRef.rendererDelegate!.abstractMessage(selfRef.message, templateValuesForHeader: MessageHeader(header)));
}

func templateValuesForPartBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> CDictionary {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return Dictionary<String, String>.cast(selfRef.rendererDelegate!.abstractMessage(selfRef.message, templateValuesForPart: AbstractPart(part)));
}

func templateForMainHeaderBlock(ref: UnsafeRawPointer?, header: CMessageHeader) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, templateForMainHeader: MessageHeader(header)).cast();
}

func templateForImageBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, templateForImage: AbstractPart(part)).cast()
}

func templateForAttachmentBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, templateForAttachment: AbstractPart(part)).cast()
}

func templateForMessageBlock(ref: UnsafeRawPointer?, msg: CAbstractMessage) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessageTemplateForMessage(selfRef.message).cast()
}

func templateForEmbeddedMessageBlock(ref: UnsafeRawPointer?, part: CAbstractMessagePart) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, templateForEmbeddedMessage: AbstractMessagePart(abstractMessagePart: part)).cast();
}

func templateForEmbeddedMessageHeaderBlock(ref: UnsafeRawPointer?, header: CMessageHeader) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, templateForEmbeddedMessageHeader: MessageHeader(header)).cast();
}

func templateForAttachmentSeparatorBlock(ref: UnsafeRawPointer?) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessageTemplateForAttachmentSeparator(selfRef.message).cast();
}

func cleanHTMLForPartBlock(ref: UnsafeRawPointer?, html: UnsafePointer<UInt16>?) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, cleanHTMLForPart: String(utf16: html)).cast();
}

func filterHTMLForPartBlock(ref: UnsafeRawPointer?, html: UnsafePointer<UInt16>?) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, filterHTMLForPart: String(utf16: html)).cast();
}

func filterHTMLForMessageBlock(ref: UnsafeRawPointer?, html: UnsafePointer<UInt16>?) -> CObject {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    return selfRef.rendererDelegate!.abstractMessage(selfRef.message, filterHTMLForMessage: String(utf16: html)).cast();
}

func dataForIMAPPart(ref: UnsafeRawPointer?, folder: UnsafePointer<UInt16>?, part: CIMAPPart) -> CData {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    let data = selfRef.imapDelegate!.abstractMessage(selfRef.message, dataForIMAPPart: IMAPPart(part: part), folder: String(utf16: folder));
    return CData(bytes: data.bytes(), length: data.length());
}

func prefetchAttachmentIMAPPart(ref: UnsafeRawPointer?, folder: UnsafePointer<UInt16>?, part: CIMAPPart) {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    selfRef.imapDelegate!.abstractMessage(selfRef.message, prefetchAttachmentIMAPPart: IMAPPart(part: part), folder: String(utf16: folder));
}

func prefetchImageIMAPPart(ref: UnsafeRawPointer?, folder: UnsafePointer<UInt16>?, part: CIMAPPart) {
    let selfRef = Unmanaged<AbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    selfRef.imapDelegate!.abstractMessage(selfRef.message, prefetchImageIMAPPart: IMAPPart(part: part), folder: String(utf16: folder));
}
