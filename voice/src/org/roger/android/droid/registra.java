package org.roger.android.droid;

import android.app.Activity;
import android.content.SharedPreferences;
import android.net.ConnectivityManager;
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
		
		if( droid.callData.getUser() != null )
			loginname.setText(droid.callData.getUser());
		if( droid.callData.getPasswd() != null )
			password.setText(droid.callData.getPasswd());
    }
	@Override
	public void onResume() {
		super.onResume();
		alarm.setVisibility(View.INVISIBLE);
	}
	public void submit( View v ) {
		droid.callData.setUser(loginname.getText().toString());
		droid.callData.setPasswd(password.getText().toString());
		
		ConnectivityManager connManager = (ConnectivityManager) getSystemService(CONNECTIVITY_SERVICE);
		if (connManager.getActiveNetworkInfo() != null && connManager.getActiveNetworkInfo().isAvailable() ) {
			droid.self.tryReg();
			new Handler().postDelayed(new Runnable(){    
			    public void run() {
			    	if( droid.self != null ){
			    		if( droid.self.isRegistered() ) {
			    			droid.callData.setOnline(true);
			    			droid.self.startActivity("main");
			    		}else {
			    			alarm.setText(R.string.name_conflict_err);
			    			alarm.setVisibility(View.VISIBLE);
			    		}
			    	}
			    }    
			}, 2000);
		}else {
			alarm.setText(R.string.network_err);
			alarm.setVisibility(View.VISIBLE);
		}
	}
}
