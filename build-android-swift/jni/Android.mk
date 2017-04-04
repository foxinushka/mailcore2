CURRENT_DIR := $(call my-dir)

src_dir := $(CURRENT_DIR)/../../src
subdirs = \
	core \
	core/basetypes \
	core/abstract \
	core/imap \
	core/nntp \
	core/pop \
	core/provider \
	core/renderer \
	core/rfc822 \
	core/security \
	core/smtp \
	core/zip \
	core/zip/MiniZip \
	async/imap \
	async/nntp \
	async/pop \
	async/smtp \
	java java/native
includes = \
	$(CURRENT_DIR)/../include \
    $(CTEMPLATE_PATH)/include \
    $(ICU4C_PATH)/include \
    $(LIBETPAN_PATH)/include \
    $(LIBXML2_PATH)/include \
    $(TIDY_HTML5_PATH)/include \
    $(OPENSSL_PATH)/include \
    $(ANDROID_NDK)/sources/cxx-stl/gnu-libstdc++/4.9/include \
    $(ANDROID_NDK)/sources/cxx-stl/gnu-libstdc++/4.9/libs/$(TARGET_ARCH_ABI)/include \
	$(addprefix $(src_dir)/, $(subdirs))
#     $(ANDROID_NDK)/sources/cxx-stl/llvm-libc++/libcxx/include
# $(ANDROID_NDK)/sources/cxx-stl/llvm-libc++abi/libcxxabi/include

core_excludes = MCWin32.cpp MCStringWin32.cpp MCMainThreadWin32.cpp MCMainThreadGTK.cpp
core_src_files := $(filter-out \
	$(addprefix $(src_dir)/core/basetypes/, $(core_excludes)), \
	$(wildcard $(src_dir)/core/basetypes/*.cpp) $(wildcard $(src_dir)/core/basetypes/*.c))

abstract_src_files := $(wildcard $(src_dir)/core/abstract/*.cpp)
imap_src_files := $(wildcard $(src_dir)/core/imap/*.cpp)
nntp_src_files := $(wildcard $(src_dir)/core/nntp/*.cpp)
pop_src_files := $(wildcard $(src_dir)/core/pop/*.cpp)
provider_src_files := $(wildcard $(src_dir)/core/provider/*.cpp)
renderer_src_files := $(wildcard $(src_dir)/core/renderer/*.cpp)
rfc822_src_files := $(wildcard $(src_dir)/core/rfc822/*.cpp)
security_src_files := $(wildcard $(src_dir)/core/security/*.cpp)
smtp_src_files := $(wildcard $(src_dir)/core/smtp/*.cpp)
zip_src_files := $(wildcard $(src_dir)/core/zip/*.cpp)
minizip_src_files := \
	$(src_dir)/core/zip/MiniZip/ioapi.c \
	$(src_dir)/core/zip/MiniZip/unzip.c \
	$(src_dir)/core/zip/MiniZip/zip.c
async_imap_src_files := $(wildcard $(src_dir)/async/imap/*.cpp)
async_nntp_src_files := $(wildcard $(src_dir)/async/nntp/*.cpp)
async_pop_src_files := $(wildcard $(src_dir)/async/pop/*.cpp)
async_smtp_src_files := $(wildcard $(src_dir)/async/smtp/*.cpp)
jni_src_files := $(wildcard $(src_dir)/java/native/*.cpp) $(wildcard $(src_dir)/java/*.cpp)

# include $(CLEAR_VARS)
# LOCAL_MODULE    := MailCore
# LOCAL_C_INCLUDES := $(includes)
# LOCAL_SRC_FILES := $(core_src_files) $(abstract_src_files) $(imap_src_files) $(nntp_src_files) \
# 	$(pop_src_files) $(provider_src_files) $(renderer_src_files) $(rfc822_src_files) \
# 	$(security_src_files) $(smtp_src_files) $(zip_src_files) $(minizip_src_files) \
# 	$(async_imap_src_files) $(async_nntp_src_files) $(async_pop_src_files) $(async_smtp_src_files)
# LOCAL_CPPFLAGS := -frtti
# LOCAL_CFLAGS := -DNOCRYPT
# include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := etpan
LOCAL_SRC_FILES := $(LIBETPAN_PATH)/libs/$(TARGET_ARCH_ABI)/libetpan.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := crypto
LOCAL_SRC_FILES := $(OPENSSL_PATH)/libs/$(TARGET_ARCH_ABI)/libcrypto.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := ssl
LOCAL_SRC_FILES := $(OPENSSL_PATH)/libs/$(TARGET_ARCH_ABI)/libssl.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := icu4c
LOCAL_SRC_FILES := $(ICU4C_PATH)/libs/$(TARGET_ARCH_ABI)/libicu4c.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := xml2
LOCAL_SRC_FILES := $(LIBXML2_PATH)/libs/$(TARGET_ARCH_ABI)/libxml2.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := tidy
LOCAL_SRC_FILES := $(TIDY_HTML5_PATH)/libs/$(TARGET_ARCH_ABI)/libtidy.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := ctemplate
LOCAL_SRC_FILES := $(CTEMPLATE_PATH)/libs/$(TARGET_ARCH_ABI)/libctemplate.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := sasl2
LOCAL_SRC_FILES := $(CYRUS_SASL_PATH)/libs/$(TARGET_ARCH_ABI)/libsasl2.a
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := dispatch
LOCAL_EXPORT_C_INCLUDES := $(SWIFT_LIB)
LOCAL_SRC_FILES := $(SWIFT_LIB)/android/libdispatch.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := MailCore
LOCAL_C_INCLUDES := $(includes)
LOCAL_SRC_FILES := \
	$(jni_src_files) \
	$(core_src_files) $(abstract_src_files) $(imap_src_files) $(nntp_src_files) \
	$(pop_src_files) $(provider_src_files) $(renderer_src_files) $(rfc822_src_files) \
	$(security_src_files) $(smtp_src_files) $(zip_src_files) $(minizip_src_files) \
	$(async_imap_src_files) $(async_nntp_src_files) $(async_pop_src_files) $(async_smtp_src_files)
LOCAL_CPPFLAGS := -frtti
LOCAL_CFLAGS := -DNOCRYPT -fblocks
# LOCAL_LDLIBS := -lz -llog \
#      -lc++_shared -L$(ANDROID_NDK)/sources/cxx-stl/llvm-libc++/libs/$(TARGET_ARCH_ABI)
LOCAL_LDLIBS := -lz -llog \
	 -lgnustl_shared -L$(ANDROID_NDK)/sources/cxx-stl/gnu-libstdc++/4.9/libs/$(TARGET_ARCH_ABI)
LOCAL_DISABLE_FATAL_LINKER_WARNINGS := true
LOCAL_STATIC_LIBRARIES := etpan sasl2 ssl crypto icu4c xml2 tidy ctemplate
LOCAL_SHARED_LIBRARIES := dispatch
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
NDK_TOOLCHAIN_VERSION := clang
LOCAL_MODULE     := cmailcore
LOCAL_C_INCLUDES += $(CURRENT_DIR)/../../src/c
LOCAL_C_INCLUDES += $(CURRENT_DIR)/../../src/c/basetypes
LOCAL_C_INCLUDES += $(CURRENT_DIR)/../../src/c/imap
LOCAL_C_INCLUDES += $(CURRENT_DIR)/../../src/c/abstract
LOCAL_C_INCLUDES += $(CURRENT_DIR)/../../src/c/utils
LOCAL_C_INCLUDES += $(CURRENT_DIR)/../../src/c/rfc822
LOCAL_C_INCLUDES += $(CURRENT_DIR)/../include
LOCAL_SRC_FILES  := $(src_dir)/c/utils/COperation.cpp \
					$(src_dir)/c/abstract/CAbstractPart.cpp \
					$(src_dir)/c/abstract/CMessageHeader.cpp \
					$(src_dir)/c/abstract/CAbstractMessage.cpp \
					$(src_dir)/c/abstract/CAbstractMessagePart.cpp \
					$(src_dir)/c/abstract/CAbstractMultipart.cpp \
					$(src_dir)/c/abstract/CAddress.cpp \
					$(src_dir)/c/abstract/CAbstractMessageRendererCallback.cpp \
					$(src_dir)/c/basetypes/CArray.cpp \
					$(src_dir)/c/basetypes/CObject.cpp \
					$(src_dir)/c/basetypes/CIndexSet.cpp \
					$(src_dir)/c/basetypes/CDictionary.cpp \
					$(src_dir)/c/imap/CIMAPAsyncSession.cpp \
					$(src_dir)/c/imap/CIMAPFolder.cpp \
					$(src_dir)/c/imap/CIMAPMessage.cpp \
					$(src_dir)/c/imap/CIMAPMessagePart.cpp \
					$(src_dir)/c/imap/CIMAPNamespace.cpp \
					$(src_dir)/c/imap/CIMAPNamespaceItem.cpp \
					$(src_dir)/c/imap/CIMAPPart.cpp \
					$(src_dir)/c/imap/CIMAPIdentity.cpp \
					$(src_dir)/c/imap/CIMAPFolderInfo.cpp \
					$(src_dir)/c/imap/CIMAPFolderStatus.cpp \
					$(src_dir)/c/imap/CIMAPSearchExpression.cpp \
					$(src_dir)/c/imap/CIMAPAppendMessageOperation.cpp \
					$(src_dir)/c/imap/CIMAPFetchContentOperation.cpp \
					$(src_dir)/c/imap/СIMAPSearchOperation.cpp \
					$(src_dir)/c/imap/CIMAPCopyMessagesOperation.cpp \
					$(src_dir)/c/imap/CIMAPFolderInfoOperation.cpp \
					$(src_dir)/c/imap/CIMAPFolderStatusOperation.cpp \
					$(src_dir)/c/imap/CIMAPFetchMessagesOperation.cpp \
					$(src_dir)/c/imap/CIMAPBaseOperation.cpp \
					$(src_dir)/c/imap/CIMAPIdleOperation.cpp \
					$(src_dir)/c/imap/CIMAPFetchFoldersOperation.cpp \
					$(src_dir)/c/imap/CIMAPFetchNamespaceOperation.cpp \
					$(src_dir)/c/imap/CIMAPFetchContentToFileOperation.cpp \
					$(src_dir)/c/imap/CIMAPCustomCommandOperation.cpp \
					$(src_dir)/c/imap/CIMAPCheckAccountOperation.cpp \
					$(src_dir)/c/imap/CIMAPCapabilityOperation.cpp \
					$(src_dir)/c/imap/CIMAPMoveMessagesOperation.cpp \
					$(src_dir)/c/imap/CIMAPFetchParsedContentOperation.cpp \
					$(src_dir)/c/imap/CIMAPMessageRenderingOperation.cpp \
					$(src_dir)/c/imap/CIMAPIdentityOperation.cpp \
					$(src_dir)/c/imap/CIMAPQuotaOperation.cpp \
					$(src_dir)/c/smtp/CSMTPOperation.cpp \
					$(src_dir)/c/smtp/CSMTPSession.cpp \
					$(src_dir)/c/rfc822/CAttachment.cpp \
					$(src_dir)/c/rfc822/CMessageBuilder.cpp \
					$(src_dir)/c/rfc822/CMessageParser.cpp \

					
LOCAL_CFLAGS := -fblocks
LOCAL_LDLIBS := -llog				
LOCAL_SHARED_LIBRARIES := MailCore
include $(BUILD_SHARED_LIBRARY)
