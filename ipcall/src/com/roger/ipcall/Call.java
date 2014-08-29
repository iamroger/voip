package com.roger.ipcall;

import com.roger.ipcall.Message.MSG_ID;

import android.content.Context;
import android.content.Intent;
import android.telephony.TelephonyManager;

public class Call extends CallDelegator {
	private Context ctx = null;
	public Call( Context c ) {
		ctx = c;
	}
	public void makeCall( String uri ) {
		Message msg = new Message( MSG_ID.CMD_MAKE_CALL );
		msg.put("uri", "sip:"+uri);
		Command( msg.serialize() );
	}
	
	public void answer() {
		Message msg = new Message( MSG_ID.CMD_ANSWER );
		Command( msg.serialize() );
	}
	public void reject() {
		Message msg = new Message( MSG_ID.CMD_REJECT );
		Command( msg.serialize() );		
	}
	public void unrister() {
		Message msg = new Message( MSG_ID.CMD_UNREGISTE );
		Command( msg.serialize() );		
	}
	private String ip = "192.168.56.101";
	public void register( Context ctx ) {
		
		Message msg = new Message( MSG_ID.CMD_REGISTE );
		msg.put("ip", ip);
		msg.put("user", ((TelephonyManager) ctx.getSystemService(Context.TELEPHONY_SERVICE)).getDeviceId().toString().substring(1,4) );
		msg.put("passwd", "1234");
		Command( msg.serialize() );
		
	}
	
	@Override
	public int HandleMessage( Message msg ) {
		// TODO Auto-generated method stub
		switch( msg.id) {
		case MSG_INCOMING_CALL: {
				Intent i = new Intent("android.intent.action.INCOMINGCALL");
				i.putExtra("name", msg.get("name").toStr());
				i.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
		    	ctx.startActivity(i);
			}
			return 1;
		}
		return 0;
	}
	
}