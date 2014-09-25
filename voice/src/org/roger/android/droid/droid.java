package org.roger.android.droid;

import android.app.Activity;
import android.app.ActivityGroup;
import android.app.AlertDialog;
import android.app.LocalActivityManager;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.BitmapFactory.Options;
import android.graphics.Point;
import android.graphics.drawable.BitmapDrawable;
import android.media.AudioManager;
import android.media.Ringtone;
import android.media.RingtoneManager;
import android.media.ToneGenerator;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Looper;
import android.os.Message;
import android.provider.Settings;

import java.util.HashMap;
import java.util.zip.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.File;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

import android.view.KeyEvent;
import android.view.SoundEffectConstants;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager;
import android.view.WindowManager.LayoutParams;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ViewAnimator;

import org.roger.android.core.core;
import org.roger.android.core.data;
import org.roger.android.droid.R;

import android.util.DisplayMetrics;
import android.util.Log;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.AdListener;
       
public class droid extends ActivityGroup {
	public static droid self = null;
	public static data callData ;
	private AdView ads;
	private AdRequest adRequest;
	public class Listener extends AdListener {
		@Override
	    public void onAdLoaded() {
			ads.setVisibility(View.VISIBLE);
	    }
	    @Override
	    public void onAdFailedToLoad(int errorCode) {
	    	new Handler().postDelayed(new Runnable(){    
			    public void run() {
			    	ads.loadAd(adRequest);
			    }    
			}, 60000);
	        String errorReason = "";
	        switch(errorCode) {
	            case AdRequest.ERROR_CODE_INTERNAL_ERROR:
	                errorReason = "Internal error";
	                break;
	            case AdRequest.ERROR_CODE_INVALID_REQUEST:
	                errorReason = "Invalid request";
	                break;
	            case AdRequest.ERROR_CODE_NETWORK_ERROR:
	                errorReason = "Network Error";
	                break;
	            case AdRequest.ERROR_CODE_NO_FILL:
	                errorReason = "No fill";
	                break;
	        }
	    }
	    @Override
	    public void onAdOpened() {
	    }

	    @Override
	    public void onAdClosed() {
	    }
	    @Override
	    public void onAdLeftApplication() {
	    }
	};
	private Listener listener = new Listener();
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        self = this;
        callData = new data(this);
        
        notification.start();
        handler = new Handler(/*notification.getLooper()*/) {
            @Override
            public void handleMessage(Message msg) {
                switch(msg.what) {
                	case START_ACTIVITY:
                		Bundle b = msg.getData();
                		toggleActivity( b.getString("activity"), b.getStringArray("args"));
                    break;
                }
            }
        };
        
        setContentView(R.layout.droid);
        layout = (LinearLayout) findViewById(R.id.activity);
        animator = new ViewAnimator( this );
        
        mActivities.put("main", new Info(main.class)); 
        mActivities.put("calling", new Info(calling.class)); 
        mActivities.put("setting", new Info(setting.class)); 
        mActivities.put("registra", new Info(registra.class)); 
        
        params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.FILL_PARENT,LinearLayout.LayoutParams.FILL_PARENT);
		wparams = new WindowManager.LayoutParams();
		wparams.width = LayoutParams.FILL_PARENT;
		wparams.height = LayoutParams.FILL_PARENT;

		startActivity("main");
        getWindow().setBackgroundDrawableResource(callData.getBgimg());
        
        
        ads = (AdView) findViewById(R.id.adView);

        // Create an ad request. Check logcat output for the hashed device ID to
        // get test ads on a physical device. e.g.
        // "Use AdRequest.Builder.addTestDevice("ABCDEF012345") to get test ads on this device."
        adRequest = new AdRequest.Builder().build();

        // Start loading the ad in the background.
        
        ads.setAdListener(listener);
        ads.setVisibility(View.GONE);
        ads.loadAd(adRequest);
        
    }
    private HandlerThread notification = new HandlerThread("notification");
    
    public final int START_ACTIVITY = 1;
    private Handler handler = null;
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) { 
	    if (keyCode == KeyEvent.KEYCODE_BACK) {
	    	onBackPressed();
	    }
	    return super.onKeyDown(keyCode, event);
    }
    @Override
    public void onBackPressed() {
    	//co.hangup();
    	//co.destroy();
    	moveTaskToBack(true);//finish();
        //System.exit(0);
    }
    /** Called when leaving the activity */
    @Override
    public void onPause() {
        if (ads != null) {
            ads.pause();
        }
        super.onPause();
    }
    /** Called when returning to the activity */
    @Override
    public void onResume() {
        super.onResume();
        if (ads != null) {
            ads.resume();
        }
    }

    @Override
    public void onDestroy() {
    	if (ads != null) {
            ads.destroy();
        }
    	main.co.hangup();
    	main.co.destroy();
        System.exit(0);
        super.onDestroy();
    }
    public void startActivity( String name, String... args ) {
    	LocalActivityManager mgr = getLocalActivityManager();
    	if( name.equals(mgr.getCurrentId()) && name.equals("main") ) {
    		return;
    	}
    	Bundle b = new Bundle();
    	b.putString("activity", name);
    	b.putStringArray("args", args);
    	Message msg = handler.obtainMessage();  
    	msg.what = START_ACTIVITY;
    	msg.setData(b);
    	handler.sendMessage(msg);
    }

    private void toggleActivity( String name, String... args ) {
    	if( args.length % 2 == 1 || name == null)
    		return;
    	
    	LocalActivityManager mgr = getLocalActivityManager();
    	if( name.equals(mgr.getCurrentId()) ){
    		Activity a = mgr.getActivity(name);
    		Intent i = new Intent("ACTIVITY.UPDATE");
    		for( int n = 0; n < args.length ; n += 2 ) {
        		i.putExtra(args[n], args[n+1]);
        	}
    		sendBroadcast(i);
    		return;
    	}
    	
    	
    	for (String key : mActivities.keySet()) {
    		Info r = mActivities.get(key);
    		layout.removeAllViews();
    	}
    	Info a = mActivities.get(name);
    	if( a.cls != null && layout != null ) {
    		Intent i = new Intent(this, a.cls);
    		for( int n = 0; n < args.length ; n += 2 ) {
        		i.putExtra(args[n], args[n+1]);
        	}
    		Activity next = mgr.getActivity(name);
    		if( next != null ) {
    			next.setIntent(i);
    		}
    		View decor = mgr.startActivity(name, i).getDecorView();
    		mgr.getActivity(name).setIntent(i);
    		if (decor != null) {
    			decor.startAnimation( AnimationUtils.loadAnimation(this, R.anim.right_in) );  
    		}
    		
    		layout.addView(decor, wparams);
    	}
    }
    public void tryLoad() {
    	ads.loadAd(adRequest);
    }
    public void tryReg() {
    	LocalActivityManager mgr = getLocalActivityManager();
    	main m = (main)mgr.getActivity("main");
    	m.tryRegiste();
    }
    public boolean isRegistered() {
    	LocalActivityManager mgr = getLocalActivityManager();
    	main m = (main)mgr.getActivity("main");
    	return m.isRegistered();
    }
    class Info {
    	public Class<?> cls;
    	public Info( Class<?> c) {
    		cls = c;
    	}
    };
    ViewAnimator animator;
    HashMap<String, Info > mActivities = new HashMap<String, Info>() ;
    WindowManager.LayoutParams wparams;
    LinearLayout.LayoutParams params;
    LinearLayout layout;
}
