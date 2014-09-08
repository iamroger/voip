package org.roger.android.droid;

import android.app.Activity;
import android.os.Bundle;
import android.widget.CheckBox;
import android.widget.TextView;

public class setting extends Activity {
	TextView carrior, user, passwd;
	CheckBox mute;
	public void onCreate(Bundle savedInstanceState)
    {
		 super.onCreate(savedInstanceState);
	     setContentView(R.layout.setting);
	     carrior = (TextView)findViewById(R.id.carrior);
	     user = (TextView)findViewById(R.id.user);
	     passwd = (TextView)findViewById(R.id.passwd);
	     mute = (CheckBox)findViewById(R.id.mute);
	     
	     carrior.setText(main.callData.getCarrior());
	     user.setText(main.callData.getUser());
	     passwd.setText(main.callData.getPasswd());
	     mute.setChecked(main.callData.getMute());
	     
    }
}
