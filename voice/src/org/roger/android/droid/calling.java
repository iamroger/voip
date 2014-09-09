package org.roger.android.droid;


import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.media.AudioManager;
import android.media.Ringtone;
import android.media.RingtoneManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.view.WindowManager.LayoutParams;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

public class calling extends Activity {
	
	Ringtone ringtone = null;
	private int currVolume;
	private boolean isInCall = false;
	private String CallName = "";
	private Context ctx;
	
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
	        if( !main.callData.getMute() && !audioManager.isSpeakerphoneOn()) {
	          //audioManager.setSpeakerphoneOn(true);
	          audioManager.setStreamVolume(AudioManager.STREAM_VOICE_CALL,
	                  audioManager.getStreamMaxVolume(AudioManager.STREAM_VOICE_CALL ),
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
		            		CloseSpeaker();
		            		Log.i("debug", "Ringer thread interrupt");
		            	}
		            } finally {
		            	if(ringtone != null && ringtone.isPlaying()) {
		            		ringtone.stop();
		            		ringtone.stop();
		            		CloseSpeaker();
		            		Log.i("debug", "Ringer thread stop");
		            	}
		            }
    			}
    		}
    	}
    	private void go() {
    		synchronized ( lock ) { 
    			lock.notifyAll();
    		}
    	}
    	private void pause() {
    		interrupt();
    	}
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
    @Override
    public void onResume() {
    	super.onRestart();
    	Intent i = getIntent();
		if( i.getStringExtra("route").equals("in") ) 
		     isInCall = true;
		
		CallName = i.getStringExtra("name");
		calling_number.setText(CallName);
 
		if( isInCall ) {
			answerLeftAligned();
			rejectRightAligned();
		}else {
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
	     ctx = this;
	     getWindow().setSoftInputMode(LayoutParams.SOFT_INPUT_STATE_ALWAYS_HIDDEN);
	     
	     ringtone = RingtoneManager.getRingtone(this, RingtoneManager.getDefaultUri(RingtoneManager.TYPE_RINGTONE));
	     ringer.start();
	     ringer.go();
	     
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
	        
    }

}
