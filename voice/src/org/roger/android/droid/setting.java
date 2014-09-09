package org.roger.android.droid;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

public class setting extends Activity {
	TextView carrior, user, passwd;
	CheckBox mute;
	RadioGroup radios;
	@Override
	public void onResume(){
		super.onResume();
		carrior.setText(main.callData.getCarrior());
	    user.setText(main.callData.getUser());
	    passwd.setText(main.callData.getPasswd());
	    mute.setChecked(main.callData.getMute());
	    RadioButton rb ;
	    if( main.callData.getBgimg() == R.drawable.wow1 ) {
	    	rb = (RadioButton)radios.getChildAt(0);
	    	rb.setChecked(true);
	    }else if ( main.callData.getBgimg() == R.drawable.wow2 ){
	    	rb = (RadioButton)radios.getChildAt(1);
	    	rb.setChecked(true);
	    }else {
	    	rb = (RadioButton)radios.getChildAt(2);
	    	rb.setChecked(true);
	    }
	    	
	}
	@Override
	public void onCreate(Bundle savedInstanceState)
    {
		super.onCreate(savedInstanceState);
	    setContentView(R.layout.setting);
	    carrior = (TextView)findViewById(R.id.carrior);
	    user = (TextView)findViewById(R.id.user);
	    passwd = (TextView)findViewById(R.id.passwd);
	    mute = (CheckBox)findViewById(R.id.mute); 
	    radios = (RadioGroup)findViewById(R.id.bg_img);
    }
	public void exit( View v ) {
		if( droid.self != null ) {
			main.callData.setCarrior(carrior.getText().toString());
			main.callData.setUser(user.getText().toString());
			main.callData.setPasswd(passwd.getText().toString());
			main.callData.setMute(mute.isChecked());
			RadioButton rb = (RadioButton)radios.findViewById(radios.getCheckedRadioButtonId());
		    if( rb.getText().toString().equals("1") ) {
		    	main.callData.setBgimg(R.drawable.wow1);
		    }else if ( rb.getText().toString().equals("2") ){
		    	main.callData.setBgimg(R.drawable.wow2);
		    }else {
		    	main.callData.setBgimg(R.drawable.wow3);
		    }
		    droid.self.getWindow().setBackgroundDrawableResource(main.callData.getBgimg());
			droid.self.startActivity("main");
		}
    }
}
