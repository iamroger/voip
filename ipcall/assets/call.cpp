/*
 * Copyright (C) 2014 roger <imiracle@live.cn>
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
#ifndef __CALL_CPP__
#define __CALL_CPP__

#include <call.h>

Context* Context::instance = null;

static void Context::acquire( JavaVM* vm ) {
	if ( singleton == NULL )
		singleton = new Context( vm );
}

void Context::release() {
	if( singleton ) {
		delete singleton;
		singleton = NULL;
	}
}

void Context::delegate( jobject obj ) {
	delegator = obj;
}

int Context::receive( char* cmd ) {
	

}

int Context::send( MSG_ID id, char* data ) {

	JNIEnv* delegator_env = NULL;
	int ret = -1;

	if( jvm && delegator && jvm->AttachCurrentThread( &delegator_env, NULL ) == JNI_OK && delegator_env ) {
	    jclass cls = delegator_env->GetObjectClass(delegator);
	    if( cls ) {
	    	jmethodID method = delegator_env->GetMethodID( jc, "Receive", "(Ljava/lang/String;)I");
	    	if( method ) {
	    		jstring str = delegator_env->NewStringUTF( str );
	    		ret = thread_env->CallIntMethod( delegator, method, str );
	    	}
	    }
	    jvm->DetachCurrentThread();
	}
	LOGI("send %d", ret);
	return ret;
}

void Context::Context( JavaVM* vm ) {
	singleton = this;
	jvm = vm;
	Dispatcher d[6] = {
			Dispatcher(CMD_REGISTE,new Registe()),
			Dispatcher(CMD_MAKE_CALL,new MakeCall()),
			Dispatcher(CMD_ANSWER,new Answer()),
			Dispatcher(CMD_REJECT,new Reject()),
			Dispatcher(CMD_UNREGISTE,new UnRegiste()) };
	memcpy( dispatcher, d, sizeof(d[0])*6 );
}

void Context::~Context() {

}

#endif
