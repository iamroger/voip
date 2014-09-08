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

import android.view.SoundEffectConstants;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.WindowManager.LayoutParams;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

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
        layout_main = (LinearLayout) findViewById(R.id.main);
        layout_calling = (LinearLayout) findViewById(R.id.calling);
        layout_setting = (LinearLayout) findViewById(R.id.setting);
        
        mActivities.put("main", new Info(main.class,layout_main)); 
        mActivities.put("calling", new Info(calling.class,layout_calling)); 
        mActivities.put("setting", new Info(setting.class,layout_setting)); 

        getWindow().setBackgroundDrawableResource(R.drawable.wow);
        startActivity("main");
    }

    public void startActivity( String name, String... args ) {
    	if( args.length % 2 == 1 )
    		return;
    	
    	LocalActivityManager mgr = getLocalActivityManager();
    	for (String key : mActivities.keySet()) {
    		Info r = mActivities.get(key);
    		r.layout.removeAllViews();
    		r.layout.setVisibility(View.INVISIBLE);
    	}
    	Info a = mActivities.get(name);
    	if( a.cls != null && a.layout != null ) {
    		Intent i = new Intent(this, a.cls);
    		for( int n = 0; n < args.length ; n += 2 ) {
        		i.putExtra(args[n], args[n+1]);
        	}
    		a.layout.setVisibility(View.VISIBLE);
    		a.layout.addView(mgr.startActivity(name, i).getDecorView());
    	}
    }
    class Info {
    	public Class<?> cls;
    	public LinearLayout layout;
    	public Info( Class<?> c, LinearLayout l) {
    		cls = c;
    		layout = l;
    	}
    };
    HashMap<String, Info > mActivities = new HashMap<String, Info>() ;
    LinearLayout layout_main;
    LinearLayout layout_calling;
    LinearLayout layout_setting;
}
