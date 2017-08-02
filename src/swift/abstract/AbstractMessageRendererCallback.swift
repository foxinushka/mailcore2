import Foundation


internal class MCOAbstractMessageRendererCallback {
    
    internal var message: MCOAbstractMessage;
    
    fileprivate var rendererDelegate: MCOHTMLRendererDelegate?;
    fileprivate var imapDelegate: MCOHTMLRendererIMAPDelegate?;
    private var nativeInstance: CAbstractMessageRendererCallback!;
    
    internal init(message: MCOAbstractMessage) {
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
    
    internal func setHtmlRenderDelegate(delegate: MCOHTMLRendererDelegate) {
        self.rendererDelegate = delegate;
    }
    
    internal func setHtmlRenderImapDelegate(delegate: MCOHTMLRendererIMAPDelegate) {
        self.imapDelegate = delegate;
    }
    
    internal func cast() -> CAbstractMessageRendererCallback {
        return nativeInstance;
    }
    
    internal func release() {
        self.nativeInstance.release()
    }
}

//MARK: C-Functions
func canPreviewPart(ref: UnsafeRawPointer?, part: CAbstractPart) -> UInt8 {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return 0
    }
    return rendererDelegate.abstractMessage(selfRef.message, canPreviewPart: MCOAbstractPart(part)) ? 1 : 0;
}

func shouldShowPartBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> UInt8 {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return 0
    }
    return rendererDelegate.abstractMessage(selfRef.message, shouldShowPart: MCOAbstractPart(part)) ? 1 : 0;
}

func templateValuesForHeaderBlock(ref: UnsafeRawPointer?, header: CMessageHeader) -> CDictionary {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CDictionary()
    }
    return Dictionary<String, String>.cast(rendererDelegate.abstractMessage(selfRef.message, templateValuesForHeader: MCOMessageHeader(header)));
}

func templateValuesForPartBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> CDictionary {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CDictionary()
    }
    return Dictionary<String, String>.cast(rendererDelegate.abstractMessage(selfRef.message, templateValuesForPart: MCOAbstractPart(part)));
}

func templateForMainHeaderBlock(ref: UnsafeRawPointer?, header: CMessageHeader) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, templateForMainHeader: MCOMessageHeader(header)).cast();
}

func templateForImageBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, templateForImage: MCOAbstractPart(part)).cast()
}

func templateForAttachmentBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, templateForAttachment: MCOAbstractPart(part)).cast()
}

func templateForMessageBlock(ref: UnsafeRawPointer?, msg: CAbstractMessage) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessageTemplateForMessage(selfRef.message).cast()
}

func templateForEmbeddedMessageBlock(ref: UnsafeRawPointer?, part: CAbstractMessagePart) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, templateForEmbeddedMessage: MCOAbstractMessagePart(abstractMessagePart: part)).cast();
}

func templateForEmbeddedMessageHeaderBlock(ref: UnsafeRawPointer?, header: CMessageHeader) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, templateForEmbeddedMessageHeader: MCOMessageHeader(header)).cast();
}

func templateForAttachmentSeparatorBlock(ref: UnsafeRawPointer?) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessageTemplateForAttachmentSeparator(selfRef.message).cast();
}

func cleanHTMLForPartBlock(ref: UnsafeRawPointer?, html: MailCoreString) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, cleanHTMLForPart: html.string()).cast();
}

func filterHTMLForPartBlock(ref: UnsafeRawPointer?, html: MailCoreString) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, filterHTMLForPart: html.string()).cast();
}

func filterHTMLForMessageBlock(ref: UnsafeRawPointer?, html: MailCoreString) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, filterHTMLForMessage: html.string()).cast();
}

func dataForIMAPPart(ref: UnsafeRawPointer?, folder: MailCoreString, part: CIMAPPart) -> CData {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    if let data = selfRef.imapDelegate?.abstractMessage(selfRef.message, dataForIMAPPart: MCOIMAPPart(part: part), folder: folder.string()) {
        return data.mailCoreData()
    }
    return CData();
}

func prefetchAttachmentIMAPPart(ref: UnsafeRawPointer?, folder: MailCoreString, part: CIMAPPart) {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    selfRef.imapDelegate?.abstractMessage(selfRef.message, prefetchAttachmentIMAPPart: MCOIMAPPart(part: part), folder: folder.string());
}

func prefetchImageIMAPPart(ref: UnsafeRawPointer?, folder: MailCoreString, part: CIMAPPart) {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    selfRef.imapDelegate?.abstractMessage(selfRef.message, prefetchImageIMAPPart: MCOIMAPPart(part: part), folder: folder.string());
}
