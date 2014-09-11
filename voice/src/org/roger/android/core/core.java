
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
    public static native void destroy();
    private static main ctx = null;

    public core( main a ) {
    	ctx = a;
    }
    public void test() {
    	Log.e("Droid", "test" );
    }
    public int receive( String remoteCall ){
    	if( remoteCall.equals("#disconnected#") ) {
    		if( droid.self != null )
				droid.self.startActivity("main");
    	}else if ( remoteCall.equals("#confirmed#") ) {
    		if( droid.self != null )
<<<<<<< HEAD
    			droid.self.startActivity("calling", "route", "confirm" );
=======
    			droid.self.startActivity("calling", "route", "out" );
>>>>>>> 022d8c6704da088cf0bac820993541d2c0eb0edc
    	}else {
    		ctx.incomingCall( remoteCall.substring(5,remoteCall.indexOf('@')) );
    	}
    	return 1;
    	
    }
}
