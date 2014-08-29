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
#ifndef __CALL_H__
#define __CALL_H__

#include <jni.h>
#include <pjsua-lib/pjsua.h>
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)

#undef  LOG_TAG
#define LOG_TAG       "call"

class Action {
	public:
		void exec( );
};

class Registe : public Action {
	
};

class MakeCall : public Action {
	
};

class Answer : public Action {
	
};

class Reject : public Action {
	
};

class UnRegiste : public Action {
	
};


class Context {
	public:
		enum MSG_ID {
			CMD_REGISTE,
			CMD_MAKE_CALL,
			CMD_ANSWER,
			CMD_REJECT,
			CMD_UNREGISTE,
			MSG_INCOMING_CALL,
		}
		static void acquire();
		
		static Context* singleton();
		
		void delegate( jobject obj );
		
		void Context( JavaVM* vm );
		
		void ~Context();
		
		void answer();
		
		void reject();
		
		void init();
		
		void login();
		
		void logout();
		
		void makeCall( char* uri );
		
		int receive( char* cmd );
		
		int send( MSG_ID id, char* data );
	protected:
		static Context* instance;
		JavaVM* jvm;
		jobject delegator;
		struct Dispatcher {
			Dispatcher(int i,Action* a):id(i),act(a){}
			int id,
			Action* act;
		};
		Dispatcher dispather[6];
		
		void dispatch();
};

#endif

