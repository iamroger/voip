package com.roger.ipcall;

public abstract class DelegatorInterface {
	
	abstract int HandleMessage( Message msg  );
	
	public int Receive( String msg  ) {
		return HandleMessage( new Message( msg ) );
	}
}