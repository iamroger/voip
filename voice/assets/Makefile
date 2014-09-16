
PJSIP_DIR=../../pjproject-2.2.1
ANDROID_LDFLAGS_LIBRARY=$(ANDROID_NDK_ROOT)/platforms/android-18/arch-arm/usr/lib

PJSIP_CXXFLAGS = -I$(PJSIP_DIR)/pjsip/include -I$(PJSIP_DIR)/pjsip/include/pjsua-lib -I$(PJSIP_DIR)/pjlib/include -I$(PJSIP_DIR)/pjmedia/include -I$(PJSIP_DIR)/pjnath/include -I$(PJSIP_DIR)/pjlib-util/include 
HOST_TYPE = arm-unknown-linux-androideabi

APP_CFLAGS := -DPJ_AUTOCONF=1 -I/voip/ndk/android-ndk-r9/platforms/android-18/arch-arm/usr/include -I/voip/ndk/android-ndk-r9/sources/cxx-stl/gnu-libstdc++/4.8/include -I/voip/ndk/android-ndk-r9/sources/cxx-stl/gnu-libstdc++/4.8/libs/armeabi/include -DPJ_IS_BIG_ENDIAN=0 -DPJ_IS_LITTLE_ENDIAN=1
# -fno-rtti is essential, as it turns of RTTI, which is not supported by the bionic.
#      c++ exceptions c++ rtti standard lib
#system    no            no         no
#gabi++   no             yes         no
#stlport  no             yes         yes
#gnustl   yes            yes         yes 
CXXFLAGS = -I. -I/voip/ndk/android-ndk-r9/platforms/android-18/arch-arm/usr/include $(PJSIP_CXXFLAGS) $(APP_CFLAGS) -fno-rtti  

PJSIP_LDFLAGS = -L$(PJSIP_DIR)/pjsip/lib  -L$(PJSIP_DIR)/pjlib/lib -L$(PJSIP_DIR)/pjmedia/lib -L$(PJSIP_DIR)/pjnath/lib -L$(PJSIP_DIR)/pjlib-util/lib -L$(PJSIP_DIR)/third_party/lib -lpjsua-$(HOST_TYPE) -lpjsip-ua-$(HOST_TYPE) -lpjsip-simple-$(HOST_TYPE) -lpjsip-$(HOST_TYPE) -lpjmedia-codec-$(HOST_TYPE) -lpjmedia-$(HOST_TYPE) -lpjnath-$(HOST_TYPE) -lpjlib-util-$(HOST_TYPE) -lpj-$(HOST_TYPE) -lgsmcodec-$(HOST_TYPE) -lilbccodec-$(HOST_TYPE) -lspeex-$(HOST_TYPE) -lresample-$(HOST_TYPE) -lmilenage-$(HOST_TYPE) -lsrtp-$(HOST_TYPE) -lm 

LDFLAGS = -L$(ANDROID_LDFLAGS_LIBRARY) -Wl,-E $(PJSIP_LDFLAGS)  -llog -shared -L/voip/ndk/android-ndk-r9/sources/cxx-stl/gnu-libstdc++/4.8/libs/armeabi/ -lgnustl_static -lpjmedia-audiodev-$(HOST_TYPE) -lOpenSLES

TOOLCHAIN_PREFIX=$(ANDROID_NDK_ROOT)/toolchains/arm-linux-androideabi-4.8/prebuilt/linux-x86//bin/arm-linux-androideabi-

all : roger_jni.so

roger_jni.so : roger_jni.cpp
	$(TOOLCHAIN_PREFIX)g++ $(CXXFLAGS) -c -o roger_jni.o roger_jni.cpp -Os
	$(TOOLCHAIN_PREFIX)g++ -o roger_jni.so roger_jni.o $(LDFLAGS) --sysroot=$(ANDROID_NDK_ROOT)/platforms/android-18/arch-arm/
	$(TOOLCHAIN_PREFIX)strip roger_jni.so
clean :
	rm -f *.so *.o
