import Foundation

public protocol MCOHTMLRendererIMAPDelegate {
    
    /**
     The delegate method returns NULL if the delegate have not fetch the part yet. The opportunity can also be used to
     start fetching the attachment.
     It will return the data synchronously if it has already fetched it.
     */
    func abstractMessage(_ msg: MCOAbstractMessage, dataForIMAPPart: MCOIMAPPart, folder: String?) -> Data?
    
    /**
     The delegate method will notify the delegate to start fetching the given part.
     It will be used to render an attachment that cannot be previewed.
     */
    func abstractMessage(_ msg: MCOAbstractMessage, prefetchAttachmentIMAPPart: MCOIMAPPart, folder: String?)
    
    /**
     The delegate method will notify the delegate to start fetching the given part.
     It will be used to render an attachment that can be previewed.
     */
    func abstractMessage(_ msg: MCOAbstractMessage, prefetchImageIMAPPart: MCOIMAPPart, folder: String?)
    
}
