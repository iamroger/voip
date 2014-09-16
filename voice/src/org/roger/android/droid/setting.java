package org.roger.android.droid;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.SeekBar;
import android.widget.TextView;

public class setting extends Activity {
	TextView carrior, user, passwd;
	CheckBox mute;
	RadioGroup radios;
	SeekBar callvol;
	SeekBar dtmfvol;
	@Override
	public void onResume(){
		super.onResume();
		carrior.setText(droid.callData.getCarrior());
	    user.setText(droid.callData.getUser());
	    passwd.setText(droid.callData.getPasswd());
	    mute.setChecked(droid.callData.getMute());
	    RadioButton rb ;
	    if( droid.callData.getBgimg() == R.drawable.wow1 ) {
	    	rb = (RadioButton)radios.getChildAt(0);
	    	rb.setChecked(true);
	    }else if ( droid.callData.getBgimg() == R.drawable.wow2 ){
	    	rb = (RadioButton)radios.getChildAt(1);
	    	rb.setChecked(true);
	    }else {
	    	rb = (RadioButton)radios.getChildAt(2);
	    	rb.setChecked(true);
	    }
	    dtmfvol.setProgress(droid.callData.getDTMFVolume());
	    callvol.setProgress(droid.callData.getCallVolume());
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
	    dtmfvol = (SeekBar)findViewById(R.id.dtmfvolume);
	    callvol = (SeekBar)findViewById(R.id.callvolume);
    }
	public void register( View v ) {
		droid.callData.setCarrior(carrior.getText().toString());
		droid.callData.setUser(user.getText().toString());
		droid.callData.setPasswd(passwd.getText().toString());
		if( main.co != null )
			main.acc_id = main.co.add_account(droid.callData.getUser(),droid.callData.getCarrior(),droid.callData.getPasswd() );
    }
	public void exit( View v ) {
		if( droid.self != null ) {
			droid.callData.setCarrior(carrior.getText().toString());
			droid.callData.setUser(user.getText().toString());
			droid.callData.setPasswd(passwd.getText().toString());
			droid.callData.setMute(mute.isChecked());
			RadioButton rb = (RadioButton)radios.findViewById(radios.getCheckedRadioButtonId());
		    if( rb.getText().toString().equals("1") ) {
		    	droid.callData.setBgimg(R.drawable.wow1);
		    }else if ( rb.getText().toString().equals("2") ){
		    	droid.callData.setBgimg(R.drawable.wow2);
		    }else {
		    	droid.callData.setBgimg(R.drawable.wow3);
		    }
		    droid.self.getWindow().setBackgroundDrawableResource(droid.callData.getBgimg());
			droid.self.startActivity("main");
		}
    }
}
