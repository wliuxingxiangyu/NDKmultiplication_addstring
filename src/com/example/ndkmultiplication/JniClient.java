package com.example.ndkmultiplication;

public class JniClient {//java层接口
	static public native String AddStr(String strA, String strB);
	static public native int AddInt(int a, int b);
	static public native int MultiInt(int a, int b);
}
