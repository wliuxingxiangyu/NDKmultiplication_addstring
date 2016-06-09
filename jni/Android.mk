LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := NDKmultiplication
LOCAL_SRC_FILES := com_example_ndkmultiplication_JniClient.c
include $(BUILD_SHARED_LIBRARY)