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

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_com_roger_ipcall_CallDelegator (JNIEnv *env, jclass cls, jstring p ) {
	jboolean iscopy = 0;
	char* cmd = (char*) env->GetStringUTFChars( p, &iscopy );
	Context* ctx = Context::singleton();
	if( ctx ) {
		if( ctx->isDelegated() )
			ctx->delegate((jobject)cls);
		return ctx->receive( cmd );
	}
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	Context::acquire( vm );
    
	return JNI_VERSION_1_4;
}

#ifdef __cplusplus
}
#endif 
