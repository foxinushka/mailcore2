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
LOCAL_SRC_FILES  := ../../src/c/basetypes/CIndexSet.cpp \
					../../src/c/imap/CIMAPAsyncSession.cpp \
					
LOCAL_SHARED_LIBRARIES := mailcore
include $(BUILD_SHARED_LIBRARY)