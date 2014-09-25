package org.roger.android.droid;

import android.app.Activity;
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

       
public class main extends Activity implements OnClickListener
{
	static Activity mCxt;
	public static core co = null;
	
    ImageView callstatus;
    
    public static int acc_id = -1;
    
    private Handler mHandler= new Handler(){      
    	public void handleMessage(Message msg) {
    		if( msg.what == INCALL ) {
				if( droid.self != null )
					droid.self.startActivity("calling", "route", "in", "name", msg.getData().getString("name"));
    		}else if ( msg.what == TRYREG ) {
    			acc_id = co.add_account(droid.callData.getUser(),droid.callData.getCarrior(),droid.callData.getPasswd() );
    		}
    	}
    };

    public void loadNativeLibrary() {
        try {
        	PackageInfo  apk = this.getPackageManager().getPackageInfo(this.getPackageName(), 0);
        	String path = apk.applicationInfo.publicSourceDir;
            ZipFile zip = new ZipFile(path);
            ZipEntry zipen = zip.getEntry("assets/roger_jni.so");
            InputStream is = zip.getInputStream(zipen);
            OutputStream os = new FileOutputStream(apk.applicationInfo.dataDir+"/roger_jni.so");
            byte[] buf = new byte[8092];
            int n;
            while ((n = is.read(buf)) > 0) os.write(buf, 0, n);
            os.flush();
            os.close();
            is.close();
            System.load("/data/data/org.roger.android.droid/roger_jni.so");
        } catch (Exception ex) {
            Log.e("droid", "failed to copy native library: " + ex);
        }
    }
    public void droid() {
    	Log.e("droid", "droid" );
    }
    public  String test() {
    	Log.e("droid", "droid" );
    	return null;
    }
    private final static int INCALL = 1;
    private final static int TRYREG = 2;
    public void incomingCall(String name ) {
    	if( name.equals(droid.callData.get("user"))  )
    		return;
    	
        Bundle b = new Bundle();
        b.putString("name", name);
        Message m = new Message();
        m.what = INCALL;
        m.setData( b );
    	mHandler.sendMessage( m );      	
    }
    
    @Override
    public void onResume() {
    	super.onResume();
    	
    	synchronized (mToneGeneratorLock) {
            if (mToneGenerator == null) {
                try {
                    mToneGenerator = new ToneGenerator(AudioManager.STREAM_MUSIC, 80);
                } catch (RuntimeException e) {
                    Log.w("debug", "Exception caught while creating local tone generator: " + e);
                    mToneGenerator = null;
                }
            }
        }
    	
    	if( co.acc_get_default() == 1 ) 
    		callstatus.setImageResource(R.drawable.on);
    	else
    		callstatus.setImageResource(R.drawable.off);
    	//View decorView = getWindow().getDecorView();
    	//decorView.setSystemUiVisibility( View.SYSTEM_UI_FLAG_HIDE_NAVIGATION /*lvl 19 | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY*/ );
    	Intent i = getIntent();
    	if( i.getStringExtra("hangup") != null && i.getStringExtra("hangup").equals("hangup") )
    		co.hangup();
    }
    public void tryRegiste() {
    	Message msg = mHandler.obtainMessage();
    	msg.what = TRYREG;
    	mHandler.sendMessage(msg);
    }
    public boolean isRegistered() {
    	return co.acc_get_default() == 1;
    }
    public void exit( View v ) {
    	//co.hangup();
    	//co.destroy();
    	//moveTaskToBack(true);//finish();
        //System.exit(0);
    	droid.self.onBackPressed();
    }
    public void register( View v ) {
    	if( co.acc_get_default() == 1 ) 
    		callstatus.setImageResource(R.drawable.on);
    	else
    		callstatus.setImageResource(R.drawable.off);
    	if( droid.self != null )
    		droid.self.tryLoad();
    }

    @Override
    public void onPause() {
    	super.onPause();
    	synchronized (mToneGeneratorLock) {
            if (mToneGenerator == null) {
                Log.i("debug", "stopTone: mToneGenerator == null");
                return;
            }
            mToneGenerator.stopTone();
        }
    }
    private ToneGenerator mToneGenerator;
     /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.mainf);
        
        mCxt = this;
        co =  new core(this); 
        //View decorView = getWindow().getDecorView();
        //int uiOptions = View.SYSTEM_UI_FLAG_HIDE_NAVIGATION;
                  /*| View.SYSTEM_UI_FLAG_FULLSCREEN;*/
        //decorView.setSystemUiVisibility(uiOptions);
        /*Bitmap bm = BitmapFactory.decodeResource(getApplicationContext().getResources(), R.drawable.wow); 
        try {
			this.getApplication().setWallpaper(bm);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
        synchronized (mToneGeneratorLock) {
        	if (mToneGenerator == null) {
	        	try {
		        	mToneGenerator = new ToneGenerator(AudioManager.STREAM_MUSIC, 80);
		        	setVolumeControlStream(AudioManager.STREAM_MUSIC);
		        	AudioManager audioManager = ((AudioManager) getSystemService(Context.AUDIO_SERVICE));
		        	audioManager.setSpeakerphoneOn(true);
		        	audioManager.setStreamVolume(AudioManager.STREAM_MUSIC,
			                  droid.callData.getDTMFVolume(),
			                  AudioManager.STREAM_MUSIC);
	        	} catch (Exception e) {
		        	e.printStackTrace();
		        	mToneGenerator = null;
	        	}
        	}
    	}
        
        Point size = new Point();
        getWindowManager().getDefaultDisplay().getSize(size);
        DisplayMetrics metrics = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(metrics);
        //Log.i("debug",decorView.getHeight()+" w:"+size.x+",h:"+size.y+", "+metrics.toString()+":"+metrics.widthPixels+","+metrics.heightPixels );
        
        /*Options options = new BitmapFactory.Options();
        options.inScaled = false;
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.wow, options);

        getWindow().setBackgroundDrawable(new BitmapDrawable(bitmap));

        getWindow().setBackgroundDrawableResource(R.drawable.wow);*/
        
        getWindow().setSoftInputMode(LayoutParams.SOFT_INPUT_STATE_ALWAYS_HIDDEN);
               
        
       // co = ((MyApp)getApplication()).co;
        loadNativeLibrary();
        
        
        int status = co.init("","org/roger/android/core/core/receive"); 
        
        
        acc_id = co.add_account(droid.callData.getUser(),droid.callData.getCarrior(),droid.callData.getPasswd() );
		if(acc_id < 0) {
			Log.i("debug","failed to login!");
			return;
		} else {
			Log.i("debug","success to login!");
		}
		ImageView callButton = (ImageView) findViewById(R.id.call_button);
		Button dial_0 = (Button) findViewById(R.id.dial_0);
		Button dial_1 = (Button) findViewById(R.id.dial_1);
		Button dial_2 = (Button) findViewById(R.id.dial_2);
		Button dial_3 = (Button) findViewById(R.id.dial_3);
		Button dial_4 = (Button) findViewById(R.id.dial_4);
		Button dial_5 = (Button) findViewById(R.id.dial_5);
		Button dial_6 = (Button) findViewById(R.id.dial_6);
		Button dial_7 = (Button) findViewById(R.id.dial_7);
		Button dial_8 = (Button) findViewById(R.id.dial_8);
		Button dial_9 = (Button) findViewById(R.id.dial_9);
		Button dial_s = (Button) findViewById(R.id.dial_star);
		Button dial_a = (Button) findViewById(R.id.dial_sharp);
		ImageView back = (ImageView) findViewById(R.id.backspace);
		callstatus = (ImageView) findViewById(R.id.status);
		callButton.setOnClickListener(this);
		dial_0.setOnClickListener(this);
		dial_1.setOnClickListener(this);
		dial_2.setOnClickListener(this);
		dial_3.setOnClickListener(this);
		dial_4.setOnClickListener(this);
		dial_5.setOnClickListener(this);
		dial_6.setOnClickListener(this);
		dial_7.setOnClickListener(this);
		dial_8.setOnClickListener(this);
		dial_9.setOnClickListener(this);
		dial_s.setOnClickListener(this);
		dial_a.setOnClickListener(this);
		back.setOnClickListener(this);
		
		if( droid.self != null && droid.callData.getOnline() == false )
			droid.self.startActivity("registra");
    }
    private Object mToneGeneratorLock = new Object();
    void playTone(int tone) {
    	if (!( Settings.System.getInt(getContentResolver(), Settings.System.DTMF_TONE_WHEN_DIALING, 1) == 1) ) {
    		return;
    	}

    	int ringerMode = ((AudioManager) getSystemService(Context.AUDIO_SERVICE)).getRingerMode();
    	if ((ringerMode == AudioManager.RINGER_MODE_SILENT) || (ringerMode == AudioManager.RINGER_MODE_VIBRATE)) {
    		return;
    	}
    	AudioManager audioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);

    	synchronized (mToneGeneratorLock) {
	    	if (mToneGenerator == null) {
	    		return;
	    	}
	    	mToneGenerator.startTone(tone, 150);
    	}
	}
    public boolean onKeyDown(int keyCode, KeyEvent event)
    {

        if (keyCode == KeyEvent.KEYCODE_BACK)
        {
            moveTaskToBack(true);
            return true; // return
        }

        return false;
    }
	@Override
	public void onClick(View arg0) {
		// TODO Auto-generated method stub
		EditText et = (EditText)findViewById(R.id.dial_num); 
		if( !droid.callData.getMute() ){
			Settings.System.putInt(getContentResolver(), Settings.System.SOUND_EFFECTS_ENABLED, 1);
			arg0.setSoundEffectsEnabled(true);
			//arg0.playSoundEffect(SoundEffectConstants.CLICK);
			AudioManager audioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
			audioManager.playSoundEffect(AudioManager.FX_KEY_CLICK);
		}else {
			arg0.setSoundEffectsEnabled(false);
			Settings.System.getInt(getContentResolver(), Settings.System.SOUND_EFFECTS_ENABLED, 0);
		}
		switch( arg0.getId() ) {
		case R.id.call_button:
			if( et.getText().toString().equals("*#*#123#*#*") ) {
				if( droid.self != null )
					droid.self.startActivity("setting");
				break;
			}
			else if( et.getText().toString().equals("*1") ) {
				droid.callData.setBgimg(R.drawable.wow1);
				droid.self.getWindow().setBackgroundDrawableResource(droid.callData.getBgimg());
				break;
			}
			else if( et.getText().toString().equals("*2") ) {
				droid.callData.setBgimg(R.drawable.wow2);
				droid.self.getWindow().setBackgroundDrawableResource(droid.callData.getBgimg());
				break;
			}
			else if( et.getText().toString().equals("*3") ) {
				droid.callData.setBgimg(R.drawable.wow3);
				droid.self.getWindow().setBackgroundDrawableResource(droid.callData.getBgimg());
				break;
			}
			int status = co.make_call( acc_id, et.getText().toString() +"@"+ droid.callData.getCarrior() );
            if(status != 0) {
                Log.i("debug","Call to " + et.getText().toString() + "failed");
            }
            {
				if( droid.self != null )
					droid.self.startActivity("calling", "route", "out", "name", et.getText().toString() );
            }
			break;
		case R.id.dial_0:
			playTone(ToneGenerator.TONE_DTMF_0);
			et.append("0");
			break;
		case R.id.dial_1:
			playTone(ToneGenerator.TONE_DTMF_1);
			et.append("1");
			break;
		case R.id.dial_2:
			playTone(ToneGenerator.TONE_DTMF_2);
			et.append("2");
			break;
		case R.id.dial_3:
			playTone(ToneGenerator.TONE_DTMF_3);
			et.append("3");
			break;
		case R.id.dial_4:
			playTone(ToneGenerator.TONE_DTMF_4);
			et.append("4");
			break;
		case R.id.dial_5:
			playTone(ToneGenerator.TONE_DTMF_5);
			et.append("5");
			break;
		case R.id.dial_6:
			playTone(ToneGenerator.TONE_DTMF_6);
			et.append("6");
			break;
		case R.id.dial_7:
			playTone(ToneGenerator.TONE_DTMF_7);
			et.append("7");
			break;
		case R.id.dial_8:
			playTone(ToneGenerator.TONE_DTMF_8);
			et.append("8");
			break;
		case R.id.dial_9:
			playTone(ToneGenerator.TONE_DTMF_9);
			et.append("9");
			break;
		case R.id.dial_sharp:
			playTone(ToneGenerator.TONE_DTMF_P);
			et.append("#");
			break;
		case R.id.dial_star:
			playTone(ToneGenerator.TONE_DTMF_S);
			et.append("*");
			break;
		case R.id.backspace:
			String str = et.getText().toString();
			if( str.length() > 0 )
				et.setText(str.substring(0, str.length()-1));
			break;
		
			
		}
		
	}
}
