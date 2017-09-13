import Foundation

#if os(Android)
    import CMailCore
#endif

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
    
    deinit {
        self.nativeInstance.release()
    }
    
    internal func setHtmlRenderDelegate(delegate: MCOHTMLRendererDelegate?) {
        self.rendererDelegate = delegate;
    }
    
    internal func setHtmlRenderImapDelegate(delegate: MCOHTMLRendererIMAPDelegate?) {
        self.imapDelegate = delegate;
    }
    
    internal func cast() -> CAbstractMessageRendererCallback {
        return nativeInstance;
    }
}

//MARK: C-Functions
func canPreviewPart(ref: UnsafeRawPointer?, part: CAbstractPart) -> UInt8 {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //guard let rendererDelegate = selfRef.rendererDelegate else {
        return 0
    //}
    //return rendererDelegate.abstractMessage(selfRef.message, canPreviewPart: createMCOObject(from: part.toCObject())) ? 1 : 0;
}

func shouldShowPartBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> UInt8 {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return 0
    }
    return rendererDelegate.abstractMessage(selfRef.message, shouldShowPart: createMCOObject(from: part.toCObject())) ? 1 : 0;
}

func templateValuesForHeaderBlock(ref: UnsafeRawPointer?, header: CMessageHeader) -> CDictionary {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //guard let rendererDelegate = selfRef.rendererDelegate else {
        return CDictionary()
    //}
    //return Dictionary<String, String>.cast(rendererDelegate.abstractMessage(selfRef.message, templateValuesForHeader: createMCOObject(from: header.toCObject())))
}

func templateValuesForPartBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> CDictionary {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //guard let rendererDelegate = selfRef.rendererDelegate else {
        return CDictionary()
    //}
    //return Dictionary<String, String>.cast(rendererDelegate.abstractMessage(selfRef.message, templateValuesForPart: createMCOObject(from: part.toCObject())));
}

func templateForMainHeaderBlock(ref: UnsafeRawPointer?, header: CMessageHeader) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, templateForMainHeader: createMCOObject(from: header.toCObject()))?.cast() ?? CObject()
}

func templateForImageBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> CObject {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    //}
    //return rendererDelegate.abstractMessage(selfRef.message, templateForImage: createMCOObject(from: part.toCObject())).cast()
}

func templateForAttachmentBlock(ref: UnsafeRawPointer?, part: CAbstractPart) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, templateForAttachment: createMCOObject(from: part.toCObject()))?.cast() ?? CObject()
}

func templateForMessageBlock(ref: UnsafeRawPointer?, msg: CAbstractMessage) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessageTemplateForMessage(selfRef.message).cast()
}

func templateForEmbeddedMessageBlock(ref: UnsafeRawPointer?, part: CAbstractMessagePart) -> CObject {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    //}
    //return rendererDelegate.abstractMessage(selfRef.message, templateForEmbeddedMessage: createMCOObject(from: part.toCObject())).cast()
}

func templateForEmbeddedMessageHeaderBlock(ref: UnsafeRawPointer?, header: CMessageHeader) -> CObject {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    //}
    //return rendererDelegate.abstractMessage(selfRef.message, templateForEmbeddedMessageHeader: createMCOObject(from: header.toCObject())).cast();
}

func templateForAttachmentSeparatorBlock(ref: UnsafeRawPointer?) -> CObject {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    //}
    //return rendererDelegate.abstractMessageTemplateForAttachmentSeparator(selfRef.message).cast();
}

func cleanHTMLForPartBlock(ref: UnsafeRawPointer?, html: MailCoreString) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    }
    return rendererDelegate.abstractMessage(selfRef.message, cleanHTMLForPart: html.string())?.cast() ?? CObject()
}

func filterHTMLForPartBlock(ref: UnsafeRawPointer?, html: MailCoreString) -> CObject {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //guard let rendererDelegate = selfRef.rendererDelegate else {
        return CObject()
    //}
    //return rendererDelegate.abstractMessage(selfRef.message, filterHTMLForPart: html.string()).cast();
}

func filterHTMLForMessageBlock(ref: UnsafeRawPointer?, html: MailCoreString) -> CObject {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    guard let rendererDelegate = selfRef.rendererDelegate else {
        assert(false)
        return CObject()
    }
    guard let result = rendererDelegate.abstractMessage(selfRef.message, filterHTMLForMessage: html.string()) else {
        assert(false)
        return CObject()
    }
    return result.cast()
}

func dataForIMAPPart(ref: UnsafeRawPointer?, folder: MailCoreString, part: CIMAPPart) -> CData {
    let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    if let data = selfRef.imapDelegate?.abstractMessage(selfRef.message, dataForIMAPPart: createMCOObject(from: part.toCObject()), folder: folder.string()) {
        return data.mailCoreData()
    }
    return CData();
}

func prefetchAttachmentIMAPPart(ref: UnsafeRawPointer?, folder: MailCoreString, part: CIMAPPart) {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //selfRef.imapDelegate?.abstractMessage(selfRef.message, prefetchAttachmentIMAPPart: createMCOObject(from: part.toCObject()), folder: folder.string());
}

func prefetchImageIMAPPart(ref: UnsafeRawPointer?, folder: MailCoreString, part: CIMAPPart) {
    //let selfRef = Unmanaged<MCOAbstractMessageRendererCallback>.fromOpaque(ref!).takeUnretainedValue()
    //selfRef.imapDelegate?.abstractMessage(selfRef.message, prefetchImageIMAPPart: createMCOObject(from: part.toCObject()), folder: folder.string());
}
