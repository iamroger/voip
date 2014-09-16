package org.roger.android.droid;


import android.app.Activity;
import android.app.AlertDialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.media.AudioManager;
import android.media.Ringtone;
import android.media.RingtoneManager;
import android.media.ToneGenerator;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.provider.Settings;
import android.util.Log;
import android.view.View;
import android.view.WindowManager.LayoutParams;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

public class calling extends Activity {
	
	
	private int currVolume;
	private boolean isInCall = false;
	private String CallName = "";
	private Context ctx = null;
	
	public void OpenSpeaker() {

        try{
	        AudioManager audioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
	        audioManager.setRouting(AudioManager.MODE_NORMAL, 
	        		AudioManager.ROUTE_SPEAKER, 
	        		AudioManager.ROUTE_ALL); 
	        audioManager.setRouting(AudioManager.MODE_RINGTONE, 
	        		AudioManager.ROUTE_SPEAKER, 
	        		AudioManager.ROUTE_ALL); 
	        audioManager.setRouting(AudioManager.MODE_IN_CALL, 
	        		AudioManager.ROUTE_EARPIECE, 
	        		AudioManager.ROUTE_ALL); 
	        audioManager.setMode(AudioManager.MODE_NORMAL);
	        currVolume = audioManager.getStreamVolume(AudioManager.STREAM_VOICE_CALL);
	        if( !droid.callData.getMute() && !audioManager.isSpeakerphoneOn()) {
	          audioManager.setSpeakerphoneOn(true);
	          audioManager.setStreamVolume(AudioManager.STREAM_VOICE_CALL,
	                  droid.callData.getCallVolume(),
	                  AudioManager.STREAM_VOICE_CALL);
	        }
        } catch (Exception e) {
           e.printStackTrace();
        }
    }
    
    public void CloseSpeaker() {
        
        try {
            AudioManager audioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
            if(audioManager != null) {
                if(audioManager.isSpeakerphoneOn()) {
                  audioManager.setSpeakerphoneOn(false);
                  audioManager.setStreamVolume(AudioManager.STREAM_VOICE_CALL,currVolume,
                          AudioManager.STREAM_VOICE_CALL);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    class RingerThread extends Thread {
    	private Object lock = new Object();
    	public void run() {
    		while (true) {
    			synchronized ( lock ) { 
		            try {
		            	lock.wait();
		            	OpenSpeaker();
		            	Log.i("debug", "Ringer thread play");
		    			aloud();
		            } catch (InterruptedException ex) {
	            		quiet();
	            		CloseSpeaker();
	            		Log.i("debug", "Ringer thread interrupt");
		            } finally {
	            		quiet();
	            		CloseSpeaker();
	            		Log.i("debug", "Ringer thread stop");
		            }
    			}
    		}
    	}
    	public final static int TONE = 1;
    	public final static int RINGTONE = 2;
    	private int type = RINGTONE;
    	private void aloud() throws InterruptedException {
    		if( type == TONE ) {
    			playTone(ToneGenerator.TONE_SUP_DIAL);
    			Thread.sleep(100);
    		}
    		else if( type == RINGTONE ) {
    			ringtone.play();
    			while (ringtone.isPlaying()) {
    				Thread.sleep(100);
    			}
    		}
    	}
    	private void quiet() {
    		if( type == TONE ){
    			playTone(ToneGenerator.TONE_SUP_DIAL);
    		}else if( type == RINGTONE ) {
    			if(ringtone != null && ringtone.isPlaying()) {
	    			ringtone.stop();
	    			ringtone.stop();
    			}
    		}
    	}
    	private void play( int t ) {
    		synchronized ( lock ) { 
    			type = t;
    			lock.notifyAll();
    		}
    	}
    	private void pause() {
    		interrupt();
    	}
    	private void init() {
    		synchronized (lock) {
                if (mToneGenerator == null) {
                    try {
                        mToneGenerator = new ToneGenerator(AudioManager.STREAM_MUSIC, 80);
                    } catch (RuntimeException e) {
                        Log.w("debug", "Exception caught while creating local tone generator: " + e);
                        mToneGenerator = null;
                    }
                }
                if (ringtone == null) {
                    try {
                    	ringtone = RingtoneManager.getRingtone(ctx, RingtoneManager.getDefaultUri(RingtoneManager.TYPE_RINGTONE));
                    } catch (RuntimeException e) {
                        Log.w("debug", "Exception caught while creating local tone generator: " + e);
                        ringtone = null;
                    }
                }
            }
    		
    	}
    	void playTone(int tone) {
        	if (!( Settings.System.getInt(getContentResolver(), Settings.System.DTMF_TONE_WHEN_DIALING, 1) == 1) ) {
        		return;
        	}

        	int ringerMode = ((AudioManager) getSystemService(Context.AUDIO_SERVICE)).getRingerMode();
        	if ((ringerMode == AudioManager.RINGER_MODE_SILENT) || (ringerMode == AudioManager.RINGER_MODE_VIBRATE)) {
        		return;
        	}
        	AudioManager audioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);

        	synchronized (lock) {
    	    	if (mToneGenerator == null) {
    	    		return;
    	    	}
    	    	mToneGenerator.startTone(tone, 150);
        	}
    	}
    	private ToneGenerator mToneGenerator = null; 
    	Ringtone ringtone = null;
    }
    RingerThread ringer = new RingerThread();
    /*
    private Handler mHandler= new Handler(){      
    	public void handleMessage(Message msg) {
    		ringer.rego();
    		
    		
    		new  AlertDialog.Builder(mCxt)   
        	.setTitle(ringtone.getTitle(mCxt) )  
        	.setMessage(msg.getData().getString("name") )  
        	.setPositiveButton("½ÓÌý" ,  new AlertDialog.OnClickListener() {
    			@Override
    			public void onClick(DialogInterface arg0, int arg1) {
    				// TODO Auto-generated method stub
    				ringer.pause();
    				co.answer();
                    statusField.setText("call...");
                    
                    new  AlertDialog.Builder(mCxt)   
                	.setTitle(ringtone.getTitle(mCxt) )  
                	.setMessage("½ÓÌýÖÐ......" )  
                	.setNegativeButton("¹Ò¶Ï" ,  new AlertDialog.OnClickListener() {
                		@Override
            			public void onClick(DialogInterface arg0, int arg1) {
            				// TODO Auto-generated method stub
            				ringer.pause();
            				co.hangup();
                            statusField.setText("Hung up");
            			}
                    })  
                	.show();
    			}
            } )  
        	.setNegativeButton("¹Ò¶Ï" , 
        		new AlertDialog.OnClickListener() {
    			@Override
    			public void onClick(DialogInterface arg0, int arg1) {
    				// TODO Auto-generated method stub
    				ringer.pause();
    				co.hangup();
                    statusField.setText("Hung up");
    			}
            })  
        	.show();
    	}
    };*/
    public final void answerLeftAligned(){
    	calling_answer.setVisibility(View.VISIBLE);
		RelativeLayout.LayoutParams layoutParams1 = (RelativeLayout.LayoutParams)calling_answer.getLayoutParams();
		layoutParams1.addRule(RelativeLayout.ALIGN_PARENT_LEFT, RelativeLayout.TRUE);
		calling_answer.setLayoutParams(layoutParams1);
    }
    public final void rejectRightAligned(){
    	RelativeLayout.LayoutParams layoutParams2 = (RelativeLayout.LayoutParams)calling_reject.getLayoutParams();
		layoutParams2.addRule(RelativeLayout.ALIGN_PARENT_RIGHT, RelativeLayout.TRUE);
		calling_reject.setLayoutParams(layoutParams2);
    }
    public final void rejectCenterAligned(){
    	RelativeLayout.LayoutParams layoutParams2 = (RelativeLayout.LayoutParams)calling_reject.getLayoutParams();
		layoutParams2.addRule(RelativeLayout.CENTER_HORIZONTAL, RelativeLayout.TRUE);
		calling_reject.setLayoutParams(layoutParams2);
    }

    public BroadcastReceiver reciver = new BroadcastReceiver(){
		@Override
		public void onReceive(Context context, Intent intent) {
			if( intent.getAction().equals("ACTIVITY.UPDATE") ) {
				if( intent.getStringExtra("route").equals("confirm") ) {
		    		calling_answer.setVisibility(View.INVISIBLE);
		       	 	calling_reject.startAnimation( AnimationUtils.loadAnimation(ctx, R.anim.right_in_center) );
		    	}
			}
		}    	
    };
    @Override
    public void onPause() {
    	super.onPause();
    	ringer.init();
    }
    @Override
    public void onStart() {
    	super.onPause();
    	IntentFilter filter = new IntentFilter("ACTIVITY.UPDATE");
    	registerReceiver(reciver,filter);
    }
    
    TextView calling_number;
    ImageView calling_answer;
    ImageView calling_reject;
	@Override
    public void onCreate(Bundle savedInstanceState)
    {
		 super.onCreate(savedInstanceState);
	     setContentView(R.layout.calling);
	     if( ctx == null ) {
	    	 ctx = this;
		     getWindow().setSoftInputMode(LayoutParams.SOFT_INPUT_STATE_ALWAYS_HIDDEN);
		     
		     calling_answer = (ImageView)findViewById(R.id.calling_answer);
		     calling_number = (TextView)findViewById(R.id.calling_number);
		     calling_reject = (ImageView)findViewById(R.id.calling_reject);
	
		     calling_reject.setOnClickListener(new Button.OnClickListener() {
		             public void onClick(View v) {
		            	ringer.pause();
		            	main.co.hangup();
		            	if( droid.self != null )
							droid.self.startActivity("main");
		             }
		     });
		     calling_answer.setOnClickListener(new Button.OnClickListener() {
	             public void onClick(View v) {
	            	 ringer.pause();
	            	 main.co.answer();
	            	 calling_answer.setVisibility(View.INVISIBLE);
	            	 calling_reject.startAnimation( AnimationUtils.loadAnimation(ctx, R.anim.right_in_center) );
	             }
		     });
		     ringer.init();
		     ringer.start();
	     }
	     
    	Intent i = getIntent();
    	if( i.getStringExtra("route").equals("confirm") ) {
    		ringer.pause();
    		calling_answer.setVisibility(View.INVISIBLE);
			rejectCenterAligned();
    		Log.i("debug", "calling confirm");
    		return;
    	}
		if( i.getStringExtra("route").equals("in") ) 
		     isInCall = true;
		
		CallName = i.getStringExtra("name");
		if( CallName != null && CallName.length() != 0 )
			calling_number.setText(CallName);
 
		if( isInCall ) {
			ringer.play(ringer.RINGTONE);
			answerLeftAligned();
			rejectRightAligned();
		}else {
			ringer.play(ringer.TONE);
			calling_answer.setVisibility(View.INVISIBLE);
			rejectCenterAligned();
		}
   
    }

}
