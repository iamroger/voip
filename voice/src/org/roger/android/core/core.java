
package org.roger.android.core;

import java.lang.String;

import org.roger.android.droid.droid;
import org.roger.android.droid.main;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.util.Log;

public class core {
	public native int init( String pxy, String cls );
    public static native int add_account(String user, String carrior, String passwd);
    public static native int acc_get_default();
    public static native int make_call(int acc_id, String uri);
    public static native void hangup();
    public static native void answer();
    public static native void sendim( String to, String msg );
    public static native void destroy();
    private static main ctx = null;

    public core( main a ) {
    	ctx = a;
    }
    public void test() {
    	Log.e("Droid", "test" );
    }
    public int receive( String remoteCall ){
    	Log.e("debug-------------------------------",remoteCall);
    	if( remoteCall.equals("#disconnected#") || remoteCall.equals("#offline#") ) {
    		if( droid.self != null )
				droid.self.startActivity("main");
    	}else if ( remoteCall.equals("#confirmed#") ) {
    		if( droid.self != null )
    			droid.self.startActivity("calling", "route", "confirm" );
    	}else if( remoteCall.indexOf("#message#") == 0 ) {
    		ctx.setIMSG(remoteCall);
    	}else {
    		ctx.incomingCall( remoteCall.substring(5,remoteCall.indexOf('@')) );
    	}
    	return 1;
    	
    }
}
