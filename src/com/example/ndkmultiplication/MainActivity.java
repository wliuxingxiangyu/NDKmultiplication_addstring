package com.example.ndkmultiplication;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

public class MainActivity extends Activity {
	static {
		System.loadLibrary("NDKmultiplication");
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		// setContentView(R.layout.main);

		String str = JniClient.AddStr("prefix", "suffix");
		
//		int iSum = JniClient.AddInt(5, 2); 
//		String strSum = "5 + 2 = " + iSum;
		
//		int iMulti = JniClient.MultiInt(5, 2);
//		String strSum = "5 * 2 = " + iMulti;

		TextView tv1 = new TextView(this);
		tv1.setText(str);
		setContentView(tv1);
	}
}
