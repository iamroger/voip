/* 
 * Copyright (C) 2009 Jurij Smakov <jurij@wooyd.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <jni.h>
//#include <JNIHelp.h>
//#include <android_runtime/AndroidRuntime.h>
#include <android/log.h>
#include <pthread.h>
#include <pjsua-lib/pjsua.h>
//#include <pjmedia/port.h>
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)

#undef LOG_TAG
#define LOG_TAG       "debug"
#define STR_SIZE      256


static pjsua_config cfg;
static int ring_slot = PJSUA_INVALID_ID;
static pjmedia_port* ring_port = 0;
static pj_pool_t* pool = 0;
static pjsua_call_id current_call_id = -1;
class CNI {
    protected:
	 static CNI* singleton;
         JNIEnv *e;
         JNIEnv* thread_env;
         JavaVM* jvm;
         jclass jc;
         jmethodID jm;
         jobject jo;
         jobject joo;
         char jfunc_class[128];
         char jfunc_method[128];
    public:
    int lasted_index_of( char* str, char c ) {
        if( str == NULL )
            return -1;
        int i = strlen(str) - 1;
        while( i > 0 && str[i] != c )
            i --;
        return i;
    }
    CNI( JNIEnv* env, jobject obj, jstring javaclassmethod ) {
        singleton = this;
        e = env;
        jvm = NULL;
        env->GetJavaVM(&jvm);
        jc = 0;
        jm = 0;
        jo = NULL;
        joo = obj;
        thread_env = NULL;
        
        jboolean iscopy;
        char* jfunc_str = (char *) env->GetStringUTFChars( javaclassmethod, &iscopy );
        int index = lasted_index_of( jfunc_str, '/' );
        memset( jfunc_class, 0, sizeof(jfunc_class) );
        memset( jfunc_method, 0, sizeof(jfunc_method) );
        memcpy( jfunc_class, jfunc_str, index );
        memcpy( jfunc_method, jfunc_str + index + 1, strlen(jfunc_str) - index );
        if( env ) {
            jo = env->NewGlobalRef(obj);
        }
    }
    ~CNI() {
        if( e && joo ) 
            e->DeleteLocalRef(joo);
    }
    static void acquire( JNIEnv* env, jobject obj, jstring javaclassmethod ) {
        if ( singleton == NULL )
            singleton = new CNI( env, obj, javaclassmethod );
    }
    static void release() {
        if( singleton ) {
            delete singleton;
            singleton = NULL;
        }
    }
    static CNI* single() {
        return singleton;
    }
    int handle( char* str ) {
        jc = 0, jm = 0, thread_env = NULL; 
        if( jvm && jo && jvm->AttachCurrentThread( &thread_env, NULL ) == JNI_OK && thread_env ) {
            jc = thread_env->GetObjectClass(jo);//FindClass( jfunc_class );
            if( jc != 0 && jc != NULL ) {
                jm = thread_env->GetMethodID( jc, jfunc_method, "(Ljava/lang/String;)I");
                         //GetMethodID( jc, jfunc_method, "(Ljava/lang/String;)I");
            }
            LOGI("class:%s,method:%s,jclass:%d,jmethod:%d == env:%x, thread_env:%x",
		jfunc_class,jfunc_method,jc,jm,(int)e,(int)thread_env); 
        }
        int ret = -1;
        if( thread_env != NULL && jc != 0 && jc != NULL && jm != 0 && jm != NULL && jo != NULL ){
            jstring js = thread_env->NewStringUTF(str);
            ret = thread_env->CallIntMethod( jo, jm, js);//CallIntMethod( jo, jm, js );
        }
        if( jvm )
            jvm->DetachCurrentThread();
        return ret;
    }
    static void ring_start() {
        LOGI("ring slot %d, %d", ring_slot, PJSUA_INVALID_ID );
        int status = pjsua_conf_connect(ring_slot, 0);
        if (status != PJ_SUCCESS){
            LOGE("failed to conn port, status %d", status);
            return;
        }
    }
    static void ring_stop() {
    	pjsua_conf_disconnect(ring_slot, 0);
    }
    void video_start() {

	}
	void video_stop() {

	}
	static void answer( pjsua_call_id call_id ) {
		pjsua_call_info call_info;

		pjsua_call_get_info(call_id, &call_info);

		int i;
		for (i=0; i<call_info.media_cnt; ++i) {
			pjsua_conf_port_id call_conf_slot;
			call_conf_slot = call_info.media[i].stream.aud.conf_slot;
			pjsua_conf_connect(call_conf_slot, 0);
			if (!0/*disconnect_mic*/)
				pjsua_conf_connect(0, call_conf_slot);
		}
                
        pjsua_call_answer(call_id, 200, NULL, NULL);
	}
	static void hangup( pjsua_call_id call_id ) {
		current_call_id = -1;
		pjsua_call_hangup(call_id, PJSIP_SC_GONE, NULL, NULL);
	}
};
CNI* CNI::singleton = NULL;

#ifdef __cplusplus
extern "C" {
#endif

/* Cached global JNI environment and class */
static JNIEnv *gEnv;
static jclass gCls;

/* Need transport id available globally to create a local account */
static pjsua_transport_id gTransId;

//static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
/* CNI called by the library upon receiving incoming call */
static void on_incoming_call(pjsua_acc_id acc_id, pjsua_call_id call_id,
                             pjsip_rx_data *rdata)
{
    pjsua_call_info ci;
    current_call_id = call_id;

    PJ_UNUSED_ARG(acc_id);
    PJ_UNUSED_ARG(rdata);

    pjsua_call_get_info(call_id, &ci);

    CNI* rcv = CNI::single();
    CNI::ring_start();
    if( rcv && rcv->handle( ci.remote_info.ptr ) != -1) {
        /* Automatically answer incoming calls with 200/OK */
    }
    LOGI("on incoming call accepted, %s", ci.remote_info.ptr);
}

/* CNI called by the library when call's state has changed */
static void on_call_state(pjsua_call_id call_id, pjsip_event *e)
{
    int status;
    char *state_str;
    JNIEnv *env;
    jstring java_state_str;
    pjsua_call_info ci; 
    PJ_UNUSED_ARG(e);
    char s1[32] = {"#disconnected#"};
    char s2[32] = {"#confirmed#"};

    pjsua_call_get_info(call_id, &ci);
    LOGI("Call %d state=%.*s", call_id, (int)ci.state_text.slen, ci.state_text.ptr);
    if (ci.state == PJSIP_INV_STATE_DISCONNECTED) {
        CNI* rcv = CNI::single();
        CNI::ring_stop(); 
        if ( rcv ) 
            rcv->handle( s1 );
    }else if ( ci.state == PJSIP_INV_STATE_CONFIRMED){
        CNI* rcv = CNI::single();
        CNI::ring_stop();
        if ( rcv )
            rcv->handle( s2 );
    }
        
}

/* CNI called by the library when call's media state has changed */
static void on_call_media_state(pjsua_call_id call_id)
{
    pjsua_call_info ci;

    pjsua_call_get_info(call_id, &ci);
    //CNI::answer( call_id );
    LOGI("on_call_media_state, call id %d, conf_slot %d, active %d %d ", call_id, ci.conf_slot, ci.media_status, PJSUA_CALL_MEDIA_ACTIVE );
    if (ci.media_status == PJSUA_CALL_MEDIA_ACTIVE) {
        // When media is active, connect call to sound device.
        pjsua_conf_connect(ci.conf_slot, 0);
        pjsua_conf_connect(0, ci.conf_slot);
    }
}

static void roger_log( int level, const char* data, int len ) {
    /*if( level == 5 ) 
       LOGI("roger level: %d, log %.*s", level, len,  data );
    else if( level <= 4 )
       LOGD("roger level: %d, log %.*s", level, len,  data );
    else
       LOGE("roger level: %d, log %.*s", level, len,  data ); */
}
/*
 * Method:    init
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_roger_android_core_core_init
    (JNIEnv *env, jobject obj, jstring proxy, jstring jfunc )
{
    pj_status_t status;
 
    /* Create pjsua first! */
    status = pjsua_create();
    if (status != PJ_SUCCESS) {
        LOGE("failed to create pjsua");
        return (jint) status;
    } 
    
    {
        CNI::acquire( env, obj, jfunc );
    }
    /* Init pjsua */
    {
        char *proxy_str;
        jboolean iscopy;
        pj_str_t proxy_pj_str;

        pjsua_media_config media_cfg;
        pjsua_logging_config log_cfg;

        pjsua_config_default(&cfg);
        cfg.cb.on_call_media_state = &on_call_media_state;
        cfg.cb.on_call_state = &on_call_state;
        cfg.cb.on_incoming_call = &on_incoming_call;
        /* Add a proxy, if we've got one. */
        proxy_str = (char *) env->GetStringUTFChars(proxy, &iscopy);
        if(strlen(proxy_str) != 0) {
            LOGI("adding proxy %s", proxy_str);
            proxy_pj_str = pj_str(proxy_str);
            cfg.outbound_proxy[0] = proxy_pj_str;
            cfg.outbound_proxy_cnt = 1;
        }

        pjsua_logging_config_default(&log_cfg);
        log_cfg.console_level = 10;
        log_cfg.cb = roger_log;

        pjsua_media_config_default(&media_cfg);
        /* Set the clock rates to 8kHz to avoid resampling */
        media_cfg.clock_rate = 8000;
        media_cfg.snd_clock_rate = 8000;
        /* Only one channel is supported */
        media_cfg.channel_count = 1;
        /* Disable echo-cancelling */
        media_cfg.ec_tail_len = 0;
        
        status = pjsua_init(&cfg, &log_cfg, &media_cfg);
        if (status != PJ_SUCCESS) {
            LOGE("failed to init pjsua, status %d", status);
            return (jint) status;
        }

        {
            /* Ring (to alert incoming call) */
            pool = pjsua_pool_create("pjsua-app", 1000, 1000);
            LOGI("audio_frame_ptime %x, clock_rate %x, chanel_count %d",media_cfg.audio_frame_ptime,media_cfg.clock_rate,media_cfg.channel_count);
            unsigned  samples_per_frame = media_cfg.audio_frame_ptime *
			    media_cfg.clock_rate *
			    media_cfg.channel_count / 1000;
            char s[5] = {"ring"};
            pj_str_t name = pj_str(s);
            status = pjmedia_tonegen_create2(pool, &name,
						 8000,
						 1,
						 160,/*samples_per_frame,*/
						 16, 0,
						 &ring_port);
            if (status != PJ_SUCCESS){
                LOGE("failed to init pjmedia, status %d", status);
                return (jint) status;
            }
            status = pjsua_conf_add_port(pool, ring_port, &ring_slot);
            if (status != PJ_SUCCESS){
                LOGE("failed to add port, status %d", status);
                return (jint) status;
            }
            status = pjsua_conf_connect(ring_slot, 0);
            if (status != PJ_SUCCESS){
                LOGE("failed to conn port, status %d", status);
                return (jint) status;
            } 
         }
    }

    /* Add UDP transport. */
    {
        pjsua_transport_config cfg;
            
        pjsua_transport_config_default(&cfg);
        cfg.port = 5060;
        status = pjsua_transport_create(PJSIP_TRANSPORT_UDP, &cfg, &gTransId);
        if (status != PJ_SUCCESS) {
            LOGE("failed to create transport, status %d", status);
            return status;
        }
    }
    
    /* Set SPEEX codec to maximum priority */
    pj_str_t speex_codec_id = pj_str((char *) "SPEEX/8000");
    pjsua_codec_set_priority(&speex_codec_id, 255);

    /* Initialization is done, now start pjsua */
    status = pjsua_start();
    if (status != PJ_SUCCESS) {
        LOGE("failed to start pjsua, status %d", status);
    }
    return status;
}

/*
 * Method:    add_account
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_roger_android_core_core_add_1account
    (JNIEnv *env, jclass cls, jstring sip_user, jstring sip_domain, jstring sip_passwd)
{
    int acc_id, ret;
    jboolean iscopy;
    char id[STR_SIZE], reg_uri[STR_SIZE];
    char *sip_user_ptr, *sip_domain_ptr, *sip_passwd_ptr;
    pj_status_t status;
    pjsua_acc_config cfg;

    //char server[64] = {"192.168.95.4"};
    sip_user_ptr = (char *) env->GetStringUTFChars(sip_user, &iscopy);
    sip_domain_ptr = (char *) env->GetStringUTFChars(sip_domain, &iscopy);
    sip_passwd_ptr = (char *) env->GetStringUTFChars(sip_passwd, &iscopy);
    snprintf(id, STR_SIZE, "sip:%s@%s", sip_user_ptr, sip_domain_ptr);
    snprintf(reg_uri, STR_SIZE, "sip:%s", sip_domain_ptr);

    pjsua_acc_config_default(&cfg);
    if(strlen(sip_user_ptr) != 0 && strlen(sip_domain_ptr) != 0) {
        LOGI("registering account %s at %s", id, reg_uri);
        LOGI("debug .... id %s, reg_uri %s, dom %s, usr %s, pwd %s",id,reg_uri,sip_domain_ptr,sip_user_ptr,sip_passwd_ptr);
        cfg.id = pj_str(id);
        cfg.reg_uri = pj_str(reg_uri);
        cfg.cred_count = 1;
        cfg.cred_info[0].realm = pj_str(sip_domain_ptr);
        cfg.cred_info[0].scheme = pj_str((char *) "digest");
        cfg.cred_info[0].username = pj_str(sip_user_ptr);
        cfg.cred_info[0].data_type = PJSIP_CRED_DATA_PLAIN_PASSWD;
        cfg.cred_info[0].data = pj_str(sip_passwd_ptr);

        status = pjsua_acc_add(&cfg, PJ_TRUE, &acc_id);
    } else {
        LOGI("no credentials given, registering local endpoint account");
        status = pjsua_acc_add_local(gTransId, PJ_TRUE, &acc_id);
    }

    if (status != PJ_SUCCESS) {
        LOGE("failed to register account, status %d", status);
        /* Negative return value indicates failure to Java */
        ret = -status;
    } else {
        ret = acc_id;
    }

    return (jint) ret;
}

/*
 * Method:    acc_get_default
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_roger_android_core_core_acc_1get_1default
    (JNIEnv *env, jclass cls)
{
    int ret = pjsua_acc_get_default();
    return (jint) ret;
}

/*
 * Method:    make_call
 * Signature: (ILjava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_org_roger_android_core_core_make_1call
    (JNIEnv *env, jclass cls, jint acc_id, jstring url)
{
     char *url_ptr;
     char addr[128] = {"sip:"};
     jboolean iscopy;
     pj_status_t status;

     url_ptr = (char *) env->GetStringUTFChars(url, &iscopy);
     strcpy(addr+4, url_ptr);
     status = pjsua_verify_sip_url(addr);
     if (status != PJ_SUCCESS) {
        LOGE("invalid SIP URL %s", addr);
        return status;
     }
     LOGI("make call %s",addr);
     pj_str_t _url = pj_str(addr);
     status = pjsua_call_make_call(acc_id, &_url, 0, NULL, NULL, NULL);
     if (status != PJ_SUCCESS) {
        LOGE("failed to make a call to %s", addr);
     }
     return status;
}

/*
 * Method:    hangup
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_roger_android_core_core_hangup
    (JNIEnv *env, jclass cls) {
    pjsua_call_hangup_all();
}

JNIEXPORT void JNICALL Java_org_roger_android_core_core_answer
    (JNIEnv *env, jclass cls) {
    CNI::answer( current_call_id );
}


/*
 * Method:    destroy
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_roger_android_core_core_destroy
    (JNIEnv *env, jclass cls) {
    if(pool)
        pj_pool_release(pool);
    pool = 0;
    LOGE("destroy ....");
    if ( ring_slot != PJSUA_INVALID_ID && ring_port ) {
        pjsua_conf_remove_port(ring_slot);
        ring_slot = PJSUA_INVALID_ID;
        pjmedia_port_destroy(ring_port);
        ring_port = NULL;
    }
    
    pjsua_destroy();
    CNI::release();
}


static JNINativeMethod gMethods[] = {
    {"init", "(Ljava/lang/String;)I", (void *) Java_org_roger_android_core_core_init},
    {"add_account", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I", (void *) Java_org_roger_android_core_core_add_1account},
    {"acc_get_default", "()I", (void *) Java_org_roger_android_core_core_acc_1get_1default},
    {"make_call", "(ILjava/lang/String;)I", (void *) Java_org_roger_android_core_core_make_1call},
    {"hangup", "()V", (void *) Java_org_roger_android_core_core_hangup},
    {"destroy", "()V", (void *) Java_org_roger_android_core_core_destroy}
};

/* Function is executed on library load */
/*jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    int i;
    const char* kPjsuaPathName = "org/wooyd/android/pjsua/pjsua";

    if (vm->GetEnv((void**) &gEnv, JNI_VERSION_1_4) != JNI_OK) {
        LOGE("failed to get the environment using GetEnv()");
        return -1;
    }
    
    gCls = gEnv->FindClass(kPjsuaPathName);                              
    if (!gCls) {                                             
        LOGE("failed to get pjsua class reference");        
        return -1;                                        
    }

    if(android::AndroidRuntime::registerNativeMethods(
        gEnv, kPjsuaPathName, gMethods, NELEM(gMethods)) != JNI_OK) {
        LOGE("failed to register native methods");
        return -1;
    }

    return JNI_VERSION_1_4;
}*/

#ifdef __cplusplus
}
#endif
