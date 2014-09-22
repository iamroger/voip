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
import android.view.animation.Animation;
import android.view.animation.Animation.AnimationListener;
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
		            	ringtone.play();
		    			while (ringtone.isPlaying()) {
		    				Thread.sleep(100);
		    			}
		            } catch (InterruptedException ex) {
		            	if(ringtone != null && ringtone.isPlaying()) {
			    			ringtone.stop();
			    			ringtone.stop();
		    			}
	            		CloseSpeaker();
	            		Log.i("debug", "Ringer thread interrupt");
		            } finally {
		            	if(ringtone != null && ringtone.isPlaying()) {
			    			ringtone.stop();
			    			ringtone.stop();
		    			}
	            		CloseSpeaker();
	            		Log.i("debug", "Ringer thread stop");
		            }
    			}
    		}
    	}
    	public final static int STOPED = 1;
    	public final static int PLAYING = 2;
    	private int state = STOPED;

    	private void play() {
    		synchronized ( lock ) { 
    			if( state == STOPED ) {
    				lock.notifyAll();
    				state = PLAYING ;
    			}
    		}
    	}
    	private void pause() {
    		if( state == PLAYING ) {
				interrupt();
    			state = STOPED ;
    		}
    	}
    	private void init() {
    		synchronized ( lock ) {
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

    	Ringtone ringtone = null;
    }
    RingerThread ringer = new RingerThread();
    class ToneThread extends Thread {
    	private Object lock = new Object();
    	private boolean stop = true;
    	void play() {
        	if (!( Settings.System.getInt(getContentResolver(), Settings.System.DTMF_TONE_WHEN_DIALING, 1) == 1) ) {
        		return;
        	}

        	int ringerMode = ((AudioManager) getSystemService(Context.AUDIO_SERVICE)).getRingerMode();
        	if ((ringerMode == AudioManager.RINGER_MODE_SILENT) || (ringerMode == AudioManager.RINGER_MODE_VIBRATE)) {
        		return;
        	}
        	AudioManager audioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);

        	if( stop == true ) {
        		synchronized ( lock ) { 
   	    			stop = false;
   	    			lock.notifyAll();
   	    		}
        	}
    	}
    	void pause() {
    		if( stop == false ) {
				interrupt();
				stop = true;
    		}
    	}
    	private ToneGenerator mToneGenerator = null; 
    	public void run() {
			while( true ) {
				// {
					try {
						synchronized ( lock ) {
							lock.wait();
						}
				
						while( !stop && mToneGenerator != null ) {
	    					mToneGenerator.startTone(ToneGenerator.TONE_CDMA_NETWORK_USA_RINGBACK, 800);
	    					Log.i("debug", "tone thread play");
							Thread.sleep(2200);
						}
						
					} catch (InterruptedException e1) {
						// TODO Auto-generated catch block
						Log.i("debug", "tone thread interrupt");
						e1.printStackTrace();
					} finally {
						Log.i("debug", "tone thread stop");
						mToneGenerator.stopTone();
					}
				//}
			}
		}
    	private void init() {
    		if (mToneGenerator == null) {
                try {
                    mToneGenerator = new ToneGenerator(AudioManager.STREAM_MUSIC, 80);
                    setVolumeControlStream(AudioManager.STREAM_MUSIC);
		        	AudioManager audioManager = ((AudioManager) getSystemService(Context.AUDIO_SERVICE));
		        	//audioManager.setSpeakerphoneOn(true);
		        	audioManager.setStreamVolume(AudioManager.STREAM_MUSIC, droid.callData.getDTMFVolume(),AudioManager.STREAM_MUSIC);
		        	
                } catch (RuntimeException e) {
                    Log.w("debug", "Exception caught while creating local tone generator: " + e);
                    mToneGenerator = null;
                }
            }
    	}
    };
    ToneThread tone = new ToneThread();
    private final static int CONFIRMED = 3;
    private Handler mHandler= new Handler(){      
    	public void handleMessage(Message msg) {
    		if( msg.what == CONFIRMED ) {
    			calling_answer.setVisibility(View.INVISIBLE);    			
       	 		//calling_reject.startAnimation( animation );
    			RelativeLayout.LayoutParams layoutParams2 = (RelativeLayout.LayoutParams)calling_reject.getLayoutParams();
    			layoutParams2.addRule(RelativeLayout.CENTER_HORIZONTAL, RelativeLayout.TRUE);
    			calling_reject.setLayoutParams(layoutParams2);
    		}
    	}
    };
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
    public void answerLeftAligned(){
    	calling_answer.setVisibility(View.VISIBLE);
		RelativeLayout.LayoutParams layoutParams1 = (RelativeLayout.LayoutParams)calling_answer.getLayoutParams();
		layoutParams1.addRule(RelativeLayout.ALIGN_PARENT_LEFT, RelativeLayout.TRUE);
		calling_answer.setLayoutParams(layoutParams1);
    }
    public void rejectRightAligned(){
    	RelativeLayout.LayoutParams layoutParams2 = (RelativeLayout.LayoutParams)calling_reject.getLayoutParams();
		layoutParams2.addRule(RelativeLayout.ALIGN_PARENT_RIGHT, RelativeLayout.TRUE);
		calling_reject.setLayoutParams(layoutParams2);
    }
    public void rejectCenterAligned(){
    	RelativeLayout.LayoutParams layoutParams2 = (RelativeLayout.LayoutParams)calling_reject.getLayoutParams();
		layoutParams2.addRule(RelativeLayout.CENTER_HORIZONTAL, RelativeLayout.TRUE);
		calling_reject.setLayoutParams(layoutParams2);
    }

    public BroadcastReceiver reciver = new BroadcastReceiver(){
		@Override
		public void onReceive(Context context, Intent intent) {
			if( intent.getAction().equals("ACTIVITY.UPDATE") ) {
				if( intent.getStringExtra("route") != null && intent.getStringExtra("route").equals("confirm") ) {
		    		Message msg = mHandler.obtainMessage();
		    		msg.what = CONFIRMED;
		    		mHandler.sendMessage(msg);
		    	}
			}
		}    	
    };
    @Override
    public void onPause() {
    	super.onPause();
    	ringer.init();
    	tone.init();
    }
    @Override
    public void onStart() {
    	super.onPause();
    	IntentFilter filter = new IntentFilter("ACTIVITY.UPDATE");
    	registerReceiver(reciver,filter);
    }
    @Override
    public void onResume() {
    	super.onResume();
    	Intent i = getIntent();
    	if( i.getStringExtra("route").equals("confirm") ) {
    		tone.pause();
    		calling_answer.setVisibility(View.INVISIBLE);
			rejectCenterAligned();
    		Log.i("debug", "calling confirm");
    		return;
    	}
		if( i.getStringExtra("route").equals("in") ) 
		     isInCall = true;
		else if ( i.getStringExtra("route").equals("out") )
			isInCall = false;
		
		CallName = i.getStringExtra("name");
		if( CallName != null && CallName.length() != 0 )
			calling_number.setText(CallName);
 
		if( isInCall ) {
			ringer.play();
			answerLeftAligned();
			rejectRightAligned();
		}else {
			tone.play();
			calling_answer.setVisibility(View.INVISIBLE);
			rejectCenterAligned();
		}
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
		            	tone.pause();
		            	//main.co.hangup();
		            	if( droid.self != null )
							droid.self.startActivity("main","hangup","hangup");
		             }
		     });
		     calling_answer.setOnClickListener(new Button.OnClickListener() {
	             public void onClick(View v) {
					ringer.pause();
					main.co.answer();
					Message msg = mHandler.obtainMessage();
					msg.what = CONFIRMED;
					mHandler.sendMessage(msg);
	             }
		     });
		     ringer.init();
		     ringer.start();
		     tone.init();
		     tone.start();
	     } 
    }

}
