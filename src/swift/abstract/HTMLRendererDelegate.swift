import Foundation

public protocol HTMLRendererDelegate {
    
    func abstractMessage(_ msg: AbstractMessage, canPreviewPart: AbstractPart) -> Bool;
    
    /** This delegate method should return YES if the part should be rendered.*/
    func abstractMessage(_ msg: AbstractMessage, shouldShowPart: AbstractPart) -> Bool;
    
    /** This delegate method returns the values to be applied to the template for the given header.
     See the content of MCHTMLRendererCallback.cpp for the default values of the header.*/
    func abstractMessage(_ msg: AbstractMessage, templateValuesForHeader: MessageHeader) -> Dictionary<String, String>;
    
    /** This delegate method returns the values to be applied to the template for the given attachment.
     See the content of MCHTMLRendererCallback.cpp for the default values of the attachment.*/
    func abstractMessage(_ msg: AbstractMessage, templateValuesForPart: AbstractPart) -> Dictionary<String, String>;
    
    /** @name Template Methods
     The following methods returns templates. They will match the syntax of ctemplate.
     See https://code.google.com/p/ctemplate/ */
    
    /** This delegate method returns the template for the main header of the message.
     See the content of MCHTMLRendererCallback.cpp for the default values of the template.*/
    func abstractMessage(_ msg: AbstractMessage, templateForMainHeader: MessageHeader) -> String;
    
    /** This delegate method returns the template an image attachment.*/
    func abstractMessage(_ msg: AbstractMessage, templateForImage: AbstractPart) -> String;
    
    /** This delegate method returns the template attachment other than images.
     See the content of MCHTMLRendererCallback.cpp for the default values of the template.*/
    func abstractMessage(_ msg: AbstractMessage, templateForAttachment: AbstractPart) -> String;
    
    /** This delegate method returns the template of the main message.
     It should include HEADER and a BODY values.
     See the content of MCHTMLRendererCallback.cpp for the default values of the template.*/
    func abstractMessageTemplateForMessage(_ msg: AbstractMessage) -> String;
    
    /** This delegate method returns the template of an embedded message (included as attachment).
     It should include HEADER and a BODY values.
     See the content of MCHTMLRendererCallback.cpp for the default values of the template.*/
    func abstractMessage(_ msg: AbstractMessage, templateForEmbeddedMessage: AbstractMessagePart) -> String;
    
    /** This delegate method returns the template for the header of an embedded message.
     See the content of MCHTMLRendererCallback.cpp for the default values of the template.*/
    func abstractMessage(_ msg: AbstractMessage, templateForEmbeddedMessageHeader: MessageHeader) -> String;
    
    /** This delegate method returns the separator between the text of the message and the attachments.*/
    func abstractMessageTemplateForAttachmentSeparator(_ msg: AbstractMessage) -> String;
    
    /** This delegate method cleans HTML content.
     For example, it could fix broken tags, add missing <html>, <body> tags.
     Default implementation uses HTMLCleaner::cleanHTML to clean HTML content. */
    func abstractMessage(_ msg: AbstractMessage, cleanHTMLForPart: String?) -> String;
    
    /** @name Filters
     
     The following methods will filter the HTML content and may apply some filters to
     change how to display the message.*/
    
    /** This delegate method will apply the filter to HTML rendered content of a given text part.
     For example, it could filter the CSS content.*/
    func abstractMessage(_ msg: AbstractMessage, filterHTMLForPart: String?) -> String;
    
    /** This delegate method will apply a filter to the whole HTML content.
     For example, it could collapse the quoted messages.*/
    func abstractMessage(_ msg: AbstractMessage, filterHTMLForMessage: String?) -> String;
}
