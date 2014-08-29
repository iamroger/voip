package com.roger.ipcall;

public class Message {
	enum MSG_ID {
		CMD_REGISTE,
		CMD_MAKE_CALL,
		CMD_ANSWER,
		CMD_REJECT,
		CMD_UNREGISTE,
		MSG_INCOMING_CALL,
	}
	public MSG_ID id;
	public Message( MSG_ID id ) {
		
	}
	public Message( String data ) {
		
	}
	public class Data {
		public Data() {
			
		}
		public String toStr() {
			return null;
		}
		public int toInt() {
			return 0;
		}
	}
	public Data get( String key ) {
		return null;
	}
	public void put( String key, String val ) {
		
	}
	public String serialize() {
		return null;
	}
}