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

package org.wooyd.android.pjsua;

import java.lang.String;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.util.Log;

public class pjsua {
	public native int init( String proxy, String cls );
    public static native int add_account(String sip_user, String sip_domain, String sip_passwd);
    public static native int acc_get_default();
    public static native int make_call(int acc_id, String uri);
    public static native void hangup();
    public static native void destroy();
    private static Activity ctx = null;

    public pjsua( Activity a ) {
    	ctx = a;
    }
    public void test() {
    	Log.e("VoiDroid", "pjsua" );
    }
    public int receive( String remoteCall ){
    	Intent newIntent = new Intent(Intent.ACTION_CALL, Uri.parse("tel:+4321ww9"));
    	Log.e("VoiDroid", "remoteCall: " + remoteCall.substring(5,remoteCall.indexOf('@')));
    	//Intent newIntent = new Intent();
    	//newIntent.setClassName("com.android.phone", "com.android.phone.InCallScreen");
    	//newIntent.putExtra(Intent.EXTRA_PHONE_NUMBER, number);

    	newIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
    	
    	ctx.startActivity(newIntent);
    	return 1;
    }
}
