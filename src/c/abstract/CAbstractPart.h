#ifndef MAILCORE_CABSTRACT_PART_H
#define MAILCORE_CABSTRACT_PART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CMessageConstants.h"

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

    const UChar*            CAbstractPart_filename(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.filename(self:));

    void                    CAbstractPart_setFilename(struct CAbstractPart self, const UChar* filename)
                            CF_SWIFT_NAME(setter:CAbstractPart.filename(self:newValue:));

    const UChar*            CAbstractPart_mimeType(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.mimeType(self:));

    void                    CAbstractPart_setMimeType(struct CAbstractPart self, const UChar* mimeType)
                            CF_SWIFT_NAME(setter:CAbstractPart.mimeType(self:newValue:));

    const UChar*            CAbstractPart_charset(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.charset(self:));

    void                    CAbstractPart_setCharset(struct CAbstractPart self, const UChar* charset)
                            CF_SWIFT_NAME(setter:CAbstractPart.charset(self:newValue:));

    const UChar*            CAbstractPart_uniqueID(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.uniqueID(self:));

    void                    CAbstractPart_setUniqueID(struct CAbstractPart self, const UChar* uniqueID)
                            CF_SWIFT_NAME(setter:CAbstractPart.uniqueID(self:newValue:));

    const UChar*            CAbstractPart_contentID(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.contentID(self:));

    void                    CAbstractPart_setContentID(struct CAbstractPart self, const UChar* contentID)
                            CF_SWIFT_NAME(setter:CAbstractPart.contentID(self:newValue:));

    const UChar*            CAbstractPart_contentLocation(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.contentLocation(self:));

    void                    CAbstractPart_setContentLocation(struct CAbstractPart self, const UChar* contentLocation)
                            CF_SWIFT_NAME(setter:CAbstractPart.contentLocation(self:newValue:));

    const UChar*            CAbstractPart_contentDescription(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.contentDescription(self:));

    void                    CAbstractPart_setContentDescription(struct CAbstractPart self, const UChar* contentDescription)
                            CF_SWIFT_NAME(setter:CAbstractPart.contentDescription(self:newValue:));

    bool                    CAbstractPart_isInlineAttachment(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.isInlineAttachment(self:));

    void                    CAbstractPart_setInlineAttachment(struct CAbstractPart self, bool isInlineAttachment)
                            CF_SWIFT_NAME(setter:CAbstractPart.isInlineAttachment(self:newValue:));

    bool                    CAbstractPart_isAttachment(struct CAbstractPart self)
                            CF_SWIFT_NAME(getter:CAbstractPart.isAttachment(self:));

    void                    CAbstractPart_setAttachment(struct CAbstractPart self, bool isAttachment)
                            CF_SWIFT_NAME(setter:CAbstractPart.isAttachment(self:newValue:));

    
    struct CAbstractPart    CAbstractPart_partForContentID(struct CAbstractPart self, const UChar* contentID)
                            CF_SWIFT_NAME(CAbstractPart.part(self:forContentID:));

    struct CAbstractPart    CAbstractPart_partForUniqueID(struct CAbstractPart self, const UChar* uniqueID)
                            CF_SWIFT_NAME(CAbstractPart.part(self:forUniqueID:));

    const UChar*            CAbstractPart_decodedStringForData(struct CAbstractPart self, const uint8_t* bytes, uint32_t lenght)
                            CF_SWIFT_NAME(CAbstractPart.decodedStringForData(self:bytes:lenght:));

    void                    CAbstractPart_setContentTypeParameterValue(struct CAbstractPart self, const UChar* value, const UChar* name)
                            CF_SWIFT_NAME(CAbstractPart.setContentTypeParameterValue(self:value:name:));

    void                    CAbstractPart_removeContentTypeParameterForName(struct CAbstractPart self, const UChar* name)
                            CF_SWIFT_NAME(CAbstractPart.removeContentTypeParameter(self:forName:));

    const UChar*            CAbstractPart_contentTypeParameterValueForName(struct CAbstractPart self, const UChar* name)
                            CF_SWIFT_NAME(CAbstractPart.contentTypeParameterValue(self:forName:));

    CArray                  CAbstractPart_allContentTypeParametersNames(struct CAbstractPart self)
                            CF_SWIFT_NAME(CAbstractPart.allContentTypeParametersNames(self:));

    
    CObject                 CAbstractPart_castToCObject(struct CAbstractPart self)
                            CF_SWIFT_NAME(CAbstractPart.castToCObject(self:));
                            
    CAbstractPart           CAbstractPart_castFromCObject(CObject obj)
                            CF_SWIFT_NAME(CAbstractPart.init(cObject:));
    
    void                    CAbstractPart_release(CAbstractPart self)
                            CF_SWIFT_NAME(CAbstractPart.release(self:));
                            
    
#ifdef __cplusplus
}

CAbstractPart CAbstractPart_new(mailcore::AbstractPart *part);
#endif

#endif
