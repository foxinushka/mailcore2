LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE	:= mailcore
LOCAL_SRC_FILES	:= ../../build-android/libs/$(TARGET_ARCH_ABI)/libMailCore.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE     := cmailcore
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../build-android/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../src/c
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../src/c/basetypes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../src/c/imap
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../src/c/abstract
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../src/c/utils
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../include
LOCAL_SRC_FILES  := ../../src/c/utils/COperation.cpp \
					../../src/c/abstract/CAbstractPart.cpp \
					../../src/c/abstract/CMessageHeader.cpp \
					../../src/c/abstract/CAbstractMessage.cpp \
					../../src/c/abstract/CAbstractMessagePart.cpp \
					../../src/c/abstract/CAbstractMultipart.cpp \
					../../src/c/abstract/CAddress.cpp \
					../../src/c/abstract/CAbstractMessageRendererCallback.cpp \
					../../src/c/basetypes/CArray.cpp \
					../../src/c/basetypes/CObject.cpp \
					../../src/c/basetypes/CIndexSet.cpp \
					../../src/c/basetypes/CDictionary.cpp \
					../../src/c/imap/CIMAPAsyncSession.cpp \
					../../src/c/imap/CIMAPFolder.cpp \
					../../src/c/imap/CIMAPMessage.cpp \
					../../src/c/imap/CIMAPMessagePart.cpp \
					../../src/c/imap/CIMAPNamespace.cpp \
					../../src/c/imap/CIMAPNamespaceItem.cpp \
					../../src/c/imap/CIMAPPart.cpp \
					../../src/c/imap/CIMAPFolderInfo.cpp \
					../../src/c/imap/CIMAPFolderStatus.cpp \
					../../src/c/imap/CIMAPSearchExpression.cpp \
					../../src/c/imap/CIMAPAppendMessageOperation.cpp \
					../../src/c/imap/CIMAPFetchContentOperation.cpp \
					../../src/c/imap/СIMAPSearchOperation.cpp \
					../../src/c/imap/CIMAPCopyMessagesOperation.cpp \
					../../src/c/imap/CIMAPFolderInfoOperation.cpp \
					../../src/c/imap/CIMAPFolderStatusOperation.cpp \
					../../src/c/imap/CIMAPFetchMessagesOperation.cpp \
					../../src/c/imap/CIMAPBaseOperation.cpp \
					../../src/c/imap/CIMAPIdleOperation.cpp \
					../../src/c/smtp/CSMTPOperation.cpp \
					../../src/c/smtp/CSMTPSession.cpp \
					../../src/c/rfc822/CAttachment.cpp \
					../../src/c/rfc822/CMessageBuilder.cpp \
					../../src/c/rfc822/CMessageParser.cpp \

					
LOCAL_CFLAGS := -fblocks					
LOCAL_SHARED_LIBRARIES := mailcore
include $(BUILD_SHARED_LIBRARY)