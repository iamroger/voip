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
import android.widget.ViewAnimator;

import org.roger.android.core.core;
import org.roger.android.core.data;
import org.roger.android.droid.R;

import android.util.DisplayMetrics;
import android.util.Log;

       
public class droid extends ActivityGroup {
	static public droid self = null;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        self = this;
        setContentView(R.layout.droid);
        layout = (LinearLayout) findViewById(R.id.activity);
        animator = new ViewAnimator( this );
        
        mActivities.put("main", new Info(main.class)); 
        mActivities.put("calling", new Info(calling.class)); 
        mActivities.put("setting", new Info(setting.class)); 
        
        params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.FILL_PARENT,LinearLayout.LayoutParams.FILL_PARENT);
		wparams = new WindowManager.LayoutParams();
		wparams.width = LayoutParams.FILL_PARENT;
		wparams.height = LayoutParams.FILL_PARENT;

        startActivity("main");
        getWindow().setBackgroundDrawableResource(main.callData.getBgimg());
    }
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
    @Override
    public void onDestroy() {
    	main.co.hangup();
    	main.co.destroy();
        System.exit(0);
    }

    public void startActivity( String name, String... args ) {
    	if( args.length % 2 == 1 )
    		return;
    	
    	LocalActivityManager mgr = getLocalActivityManager();
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
