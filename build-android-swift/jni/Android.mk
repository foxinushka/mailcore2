CURRENT_DIR := $(realpath $(call my-dir))
BASE_DIR := $(realpath $(CURRENT_DIR)/../..)

src_dir := $(realpath $(BASE_DIR)/src)
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

include $(CLEAR_VARS)
LOCAL_MODULE    := iconv
LOCAL_SRC_FILES := $(ICONV_PATH)/libs/$(TARGET_ARCH_ABI)/libiconv.a
include $(PREBUILT_STATIC_LIBRARY)

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
LOCAL_MODULE    := scuuc
LOCAL_SRC_FILES := $(SWIFT_LIB)/android/libscuuc.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := scui18n
LOCAL_SRC_FILES := $(SWIFT_LIB)/android/libscui18n.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := scudata
LOCAL_SRC_FILES := $(SWIFT_LIB)/android/libscudata.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := xml2
LOCAL_SRC_FILES := $(SWIFT_LIB)/android/libxml2.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE    := tidy
LOCAL_SRC_FILES := $(TIDY_HTML5_PATH)/libs/$(TARGET_ARCH_ABI)/libtidy.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
core_excludes = MCWin32.cpp MCStringWin32.cpp MCMainThreadWin32.cpp MCMainThreadGTK.cpp
core_src_files := $(filter-out \
	$(addprefix $(src_dir)/core/basetypes/, $(core_excludes)), \
	$(wildcard $(src_dir)/core/basetypes/*.cpp) \
	$(wildcard $(src_dir)/core/basetypes/*.c) \
)

abstract_src_files := $(wildcard $(src_dir)/core/abstract/*.cpp)
imap_src_files     := $(wildcard $(src_dir)/core/imap/*.cpp)
nntp_src_files     := $(wildcard $(src_dir)/core/nntp/*.cpp)
pop_src_files      := $(wildcard $(src_dir)/core/pop/*.cpp)
provider_src_files := $(wildcard $(src_dir)/core/provider/*.cpp)
renderer_src_files := $(wildcard $(src_dir)/core/renderer/*.cpp)
rfc822_src_files   := $(wildcard $(src_dir)/core/rfc822/*.cpp)
security_src_files := $(wildcard $(src_dir)/core/security/*.cpp)
smtp_src_files     := $(wildcard $(src_dir)/core/smtp/*.cpp)
zip_src_files      := $(wildcard $(src_dir)/core/zip/*.cpp)

async_imap_src_files := $(wildcard $(src_dir)/async/imap/*.cpp)
async_nntp_src_files := $(wildcard $(src_dir)/async/nntp/*.cpp)
async_pop_src_files  := $(wildcard $(src_dir)/async/pop/*.cpp)
async_smtp_src_files := $(wildcard $(src_dir)/async/smtp/*.cpp)

minizip_src_files := \
	$(src_dir)/core/zip/MiniZip/ioapi.c \
	$(src_dir)/core/zip/MiniZip/unzip.c \
	$(src_dir)/core/zip/MiniZip/zip.c

jni_src_files := \
	$(wildcard $(src_dir)/java/native/*.cpp) \
	$(wildcard $(src_dir)/java/*.cpp)

LOCAL_MODULE := MailCore
LOCAL_C_INCLUDES += \
	$(SWIFT_PM_EXTERNAL_INCLUDE) \
    $(CTEMPLATE_PATH)/include \
	$(SWIFT_LIB) \
    $(LIBETPAN_PATH)/include \
    $(TIDY_HTML5_PATH)/include \
    $(OPENSSL_PATH)/include \
	$(addprefix $(src_dir)/, $(subdirs))

LOCAL_SRC_FILES := \
	$(jni_src_files) \
	$(core_src_files) \
	$(abstract_src_files) \
	$(imap_src_files) \
	$(nntp_src_files) \
	$(pop_src_files) \
	$(provider_src_files) \
	$(renderer_src_files) \
	$(rfc822_src_files) \
	$(security_src_files) \
	$(smtp_src_files) \
	$(zip_src_files) \
	$(minizip_src_files) \
	$(async_imap_src_files) \
	$(async_nntp_src_files) \
	$(async_pop_src_files) \
	$(async_smtp_src_files)

LOCAL_CFLAGS := -DNOCRYPT -fblocks
LOCAL_CPPFLAGS := -frtti
LOCAL_STATIC_LIBRARIES := etpan sasl2 ssl crypto iconv ctemplate
LOCAL_SHARED_LIBRARIES := dispatch scuuc scui18n scudata xml2 tidy
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
abstract_src_files  := $(wildcard $(src_dir)/c/abstract/*.cpp)
basetypes_src_files := $(wildcard $(src_dir)/c/basetypes/*.cpp)
imap_src_files      := $(wildcard $(src_dir)/c/imap/*.cpp)
provider_src_files  := $(wildcard $(src_dir)/c/provider/*.cpp)
rfc822_src_files    := $(wildcard $(src_dir)/c/rfc822/*.cpp)
smtp_src_files      := $(wildcard $(src_dir)/c/smtp/*.cpp)
utils_src_files     := $(wildcard $(src_dir)/c/utils/*.cpp)

LOCAL_MODULE     := CMailCore
LOCAL_C_INCLUDES += $(src_dir)/c
LOCAL_C_INCLUDES += $(src_dir)/c/basetypes
LOCAL_C_INCLUDES += $(src_dir)/c/imap
LOCAL_C_INCLUDES += $(src_dir)/c/abstract
LOCAL_C_INCLUDES += $(src_dir)/c/utils
LOCAL_C_INCLUDES += $(src_dir)/c/rfc822
LOCAL_C_INCLUDES += $(SWIFT_PM_EXTERNAL_INCLUDE)
LOCAL_C_INCLUDES += $(LIBETPAN_PATH)/include

LOCAL_SRC_FILES  := \
	$(abstract_src_files) \
	$(basetypes_src_files) \
	$(imap_src_files) \
	$(provider_src_files) \
	$(rfc822_src_files) \
	$(smtp_src_files) \
	$(utils_src_files)

LOCAL_LDLIBS := -lz -llog
LOCAL_CFLAGS := -fblocks -DSWIFT
LOCAL_CPPFLAGS := -frtti
LOCAL_STATIC_LIBRARIES := MailCore
include $(BUILD_SHARED_LIBRARY)
