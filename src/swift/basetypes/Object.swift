//
//  Object.swift
//  mailcore2
//
//  Created by Andrew on 8/3/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation


var typeHash: [Data: Convertible.Type] = [Data(cdata: Value_mailCoreTypeInfo())!: UInt32.self,
                                          Data(cdata: MailCoreString_mailCoreTypeInfo())!: String.self,
                                          Data(cdata: CMailProvider_mailCoreTypeInfo())!: MCOMailProvider.self,
                                          Data(cdata: CNetService_mailCoreTypeInfo())!: MCONetService.self,
                                          Data(cdata: CAttachment_mailCoreTypeInfo())!: MCOAttachment.self,
                                          Data(cdata: CMessageBuilder_mailCoreTypeInfo())!: MCOMessageBuilder.self,
                                          Data(cdata: CMessageParser_mailCoreTypeInfo())!: MCOMessageParser.self,
                                          Data(cdata: CMessagePart_mailCoreTypeInfo())!: MCOMessagePart.self,
                                          Data(cdata: CAbstractMessage_mailCoreTypeInfo())!: MCOAbstractMessage.self,
                                          Data(cdata: CAbstractMessagePart_mailCoreTypeInfo())!: MCOAbstractMessagePart.self,
                                          Data(cdata: CAbstractMultipart_mailCoreTypeInfo())!: MCOAbstractMultipart.self,
                                          Data(cdata: CAbstractPart_mailCoreTypeInfo())!: MCOAbstractPart.self,
                                          Data(cdata: CAddress_mailCoreTypeInfo())!: MCOAddress.self,
                                          Data(cdata: CMessageHeader_mailCoreTypeInfo())!: MCOMessageHeader.self,
                                          Data(cdata: CIMAPFolder_mailCoreTypeInfo())!: MCOIMAPFolder.self,
                                          Data(cdata: CIMAPFolderInfo_mailCoreTypeInfo())!: MCOIMAPFolderInfo.self,
                                          Data(cdata: CIMAPFolderStatus_mailCoreTypeInfo())!: MCOIMAPFolderStatus.self,
                                          Data(cdata: CIMAPIdentity_mailCoreTypeInfo())!: MCOIMAPIdentity.self,
                                          Data(cdata: CIMAPMessage_mailCoreTypeInfo())!: MCOIMAPMessage.self,
                                          Data(cdata: CIMAPMessagePart_mailCoreTypeInfo())!: MCOIMAPMessagePart.self,
                                          Data(cdata: CIMAPMultipart_mailCoreTypeInfo())!: MCOIMAPMultipart.self,
                                          Data(cdata: CIMAPNamespace_mailCoreTypeInfo())!: MCOIMAPNamespace.self,
                                          Data(cdata: CIMAPNamespaceItem_mailCoreTypeInfo())!: MCOIMAPNamespaceItem.self,
                                          Data(cdata: CIMAPPart_mailCoreTypeInfo())!: MCOIMAPPart.self,
                                          Data(cdata: CMultipart_mailCoreTypeInfo())!: MCOMultipart.self,
                                          Data(cdata: CDictionary_mailCoreTypeInfo())!: Dictionary<AnyHashable, Any>.self,
                                          Data(cdata: CArray_mailCoreTypeInfo())!: Array<Any>.self]

func MCORegisterType(_ type: Convertible.Type, typeInfo: Data) {
    typeHash[typeInfo] = type
}

func type(forTypeInfo typeInfo: Data) -> Convertible.Type  {
    let type = typeHash[typeInfo]
    assert(type != nil)
    return type!
}

func createMCOObject<T: Convertible>(from cobject: CObject) -> T? {
    if cobject.instance == nil {
        return nil
    }
    guard let typeInfo = Data.init(cdata: getTypeNameFromObject(cobject)), let type = typeHash[typeInfo] else {
        assert(false, "MCO Unknown type")
        return nil
    }
    return type.init(mailCoreObject: cobject) as? T
}

func createMCOObjectWithoutConversion(from cobject: CObject) -> Convertible? {
    if cobject.instance == nil {
        return nil
    }
    guard let typeInfo = Data.init(cdata: getTypeNameFromObject(cobject)), let type = typeHash[typeInfo] else {
        assert(false, "MCO Unknown type")
        return nil
    }
    return type.init(mailCoreObject: cobject)
}
