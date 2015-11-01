LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := ChildProcessZombieDueToParent.cpp
LOCAL_STATIC_LIBRARIES += \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE := child-process-zombie-due-to-parent
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)
