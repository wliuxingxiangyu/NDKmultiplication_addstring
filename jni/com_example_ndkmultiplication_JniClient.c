#include "com_example_ndkmultiplication_JniClient.h"
#include <stdlib.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * ���߷���
 * ����: ��java�е�string ת����һ��c�����е�char����
 * ���ܵĲ��� envjni������ָ��
 * jstr �������Ҫ��ת����java��string �ַ���
 * ����ֵ : һ��c�����е�char������׵�ַ (char �ַ���)
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
	//��java�е�string ת���� c���������char����

	char* cstrA = Jstring2CStr(env, jstringA);
	char* cstrB = Jstring2CStr(env, jstringB);
	strcat(cstrA, cstrB); //ƴ�������ַ���
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
