#ifndef MAILCORE_CABSTRACT_PART_H
#define MAILCORE_CABSTRACT_PART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CMessageConstants.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractPart;
}

extern "C" {
#endif

    struct CAbstractPart {
#ifdef __cplusplus
        mailcore::AbstractPart* instance;
#else
        void*                   instance;
#endif
    };
    typedef struct CAbstractPart CAbstractPart;
    
    PartType                CAbstractPart_partType(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.partType(self:));

    void                    CAbstractPart_setPartType(struct CAbstractPart self, PartType type)
                            CF_SWIFT_NAME(setter:CAbstractPart.partType(self:newValue:));

    MailCoreString            CAbstractPart_filename(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.filename(self:));

    void                    CAbstractPart_setFilename(struct CAbstractPart self, MailCoreString filename)
                            CF_SWIFT_NAME(setter:CAbstractPart.filename(self:newValue:));

    MailCoreString            CAbstractPart_mimeType(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.mimeType(self:));

    void                    CAbstractPart_setMimeType(struct CAbstractPart self, MailCoreString mimeType)
                            CF_SWIFT_NAME(setter:CAbstractPart.mimeType(self:newValue:));

    MailCoreString            CAbstractPart_charset(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.charset(self:));

    void                    CAbstractPart_setCharset(struct CAbstractPart self, MailCoreString charset)
                            CF_SWIFT_NAME(setter:CAbstractPart.charset(self:newValue:));

    MailCoreString            CAbstractPart_uniqueID(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.uniqueID(self:));

    void                    CAbstractPart_setUniqueID(struct CAbstractPart self, MailCoreString uniqueID)
                            CF_SWIFT_NAME(setter:CAbstractPart.uniqueID(self:newValue:));

    MailCoreString            CAbstractPart_contentID(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.contentID(self:));

    void                    CAbstractPart_setContentID(struct CAbstractPart self, MailCoreString contentID)
                            CF_SWIFT_NAME(setter:CAbstractPart.contentID(self:newValue:));

    MailCoreString            CAbstractPart_contentLocation(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.contentLocation(self:));

    void                    CAbstractPart_setContentLocation(struct CAbstractPart self, MailCoreString contentLocation)
                            CF_SWIFT_NAME(setter:CAbstractPart.contentLocation(self:newValue:));

    MailCoreString            CAbstractPart_contentDescription(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.contentDescription(self:));

    void                    CAbstractPart_setContentDescription(struct CAbstractPart self, MailCoreString contentDescription)
                            CF_SWIFT_NAME(setter:CAbstractPart.contentDescription(self:newValue:));

    bool                    CAbstractPart_isInlineAttachment(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.isInlineAttachment(self:));

    void                    CAbstractPart_setInlineAttachment(struct CAbstractPart self, bool isInlineAttachment)
                            CF_SWIFT_NAME(setter:CAbstractPart.isInlineAttachment(self:newValue:));

    bool                    CAbstractPart_isAttachment(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.isAttachment(self:));

    void                    CAbstractPart_setAttachment(struct CAbstractPart self, bool isAttachment)
                            CF_SWIFT_NAME(setter:CAbstractPart.isAttachment(self:newValue:));

    
    struct CAbstractPart    CAbstractPart_partForContentID(struct CAbstractPart self, MailCoreString contentID)
                            CF_SWIFT_NAME(CAbstractPart.part(self:forContentID:));

    struct CAbstractPart    CAbstractPart_partForUniqueID(struct CAbstractPart self, MailCoreString uniqueID)
                            CF_SWIFT_NAME(CAbstractPart.part(self:forUniqueID:));

    MailCoreString            CAbstractPart_decodedStringForData(struct CAbstractPart self, const uint8_t* bytes, uint32_t lenght)
                            CF_SWIFT_NAME(CAbstractPart.decodedStringForData(self:bytes:lenght:));

    void                    CAbstractPart_setContentTypeParameterValue(struct CAbstractPart self, MailCoreString value, MailCoreString name)
                            CF_SWIFT_NAME(CAbstractPart.setContentTypeParameterValue(self:value:name:));

    void                    CAbstractPart_removeContentTypeParameterForName(struct CAbstractPart self, MailCoreString name)
                            CF_SWIFT_NAME(CAbstractPart.removeContentTypeParameter(self:forName:));

    MailCoreString            CAbstractPart_contentTypeParameterValueForName(struct CAbstractPart self, MailCoreString name)
                            CF_SWIFT_NAME(CAbstractPart.contentTypeParameterValue(self:forName:));

    CArray                  CAbstractPart_allContentTypeParametersNames(struct CAbstractPart self)
                            CF_SWIFT_NAME(CAbstractPart.allContentTypeParametersNames(self:));

    
    CObject                 CAbstractPart_castToCObject(struct CAbstractPart self)
                            CF_SWIFT_NAME(CAbstractPart.castToCObject(self:));
                            
    CAbstractPart           CAbstractPart_castFromCObject(CObject obj)
                            CF_SWIFT_NAME(CAbstractPart.init(cObject:));
    
    void                    CAbstractPart_release(CAbstractPart self)
                            CF_SWIFT_NAME(CAbstractPart.release(self:));
    
    CData                   CAbstractPartHelper_getData(CAbstractPart part)
                            CF_SWIFT_NAME(CAbstractPart.getData(part:));
    
    
#ifdef __cplusplus
}

CAbstractPart CAbstractPart_new(mailcore::AbstractPart *part);
#endif

#endif
