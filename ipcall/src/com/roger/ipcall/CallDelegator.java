package com.roger.ipcall;

public class CallDelegator extends DelegatorInterface {
	
	public native int Command( String msg );

	@Override
	public int HandleMessage( Message msg ) {
		// TODO Auto-generated method stub
		
		return 0;
	}
}