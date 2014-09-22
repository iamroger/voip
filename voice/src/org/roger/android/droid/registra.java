package org.roger.android.droid;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.TextView;

public class registra extends Activity {
	TextView loginname, password, alarm;
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.registra);
		loginname = (TextView)findViewById(R.id.loginname);
		password = (TextView)findViewById(R.id.pawssword);
		alarm = (TextView)findViewById(R.id.alarm);
    }
	
	public void submit( View v ) {
		droid.callData.setUser(loginname.getText().toString());
		droid.callData.setPasswd(password.getText().toString());
		droid.self.tryReg();
		new Handler().postDelayed(new Runnable(){    
		    public void run() {
		    	if( droid.self != null ){
		    		if( droid.self.isRegistered() ) {
		    			droid.callData.setOnline(true);
		    			droid.self.startActivity("main");
		    		}else {
		    			alarm.setText("username conflict");
		    			alarm.setVisibility(View.VISIBLE);
		    		}
		    	}
		    }    
		}, 2000);  
	}
}
