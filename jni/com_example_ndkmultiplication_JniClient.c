#include "com_example_ndkmultiplication_JniClient.h"
#include <stdlib.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * 工具方法
 * 作用: 把java中的string 转化成一个c语言中的char数组
 * 接受的参数 envjni环境的指针
 * jstr 代表的是要被转化的java的string 字符串
 * 返回值 : 一个c语言中的char数组的首地址 (char 字符串)
 */

char* Jstring2CStr(JNIEnv* env, jstring jstr) {
	char* rtn = NULL;
	jclass clsstring = (*env)->FindClass(env, "java/lang/String");
	jstring strencode = (*env)->NewStringUTF(env, "GB2312");
	jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes",
			"(Ljava/lang/String;)[B");
// String.getByte("GB2312");
	jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid,
			strencode);
	jsize alen = (*env)->GetArrayLength(env, barr);
	jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char*) malloc(alen + 1); //"\0"
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}

	(*env)->ReleaseByteArrayElements(env, barr, ba, 0); //

	return rtn;
}

/*
 * Class: com_example_ndkmultiplication_JniClient
 * Method: AddStr
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_ndkmultiplication_JniClient_AddStr(
		JNIEnv *env, jclass arg, jstring jstringA, jstring jstringB) {
	//把java中的string 转化成 c语言里面的char数组

	char* cstrA = Jstring2CStr(env, jstringA);
	char* cstrB = Jstring2CStr(env, jstringB);
	strcat(cstrA, cstrB); //拼接两个字符串
	return (*env)->NewStringUTF(env, cstrA);
}
/*
 * Class: com_example_ndkmultiplication_JniClient
 * Method: AddInt
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_com_example_ndkmultiplication_JniClient_AddInt(
		JNIEnv *env, jclass arg, jint a, jint b) {
	return a + b;
}

JNIEXPORT jint JNICALL Java_com_example_ndkmultiplication_JniClient_MultiInt(
		JNIEnv *env, jclass arg, jint a, jint b) {
	return a * b;
}

#ifdef __cplusplus
}
#endif
