#include "mainPack_CFun.h"
//#include <unistd.h>
#include <stdio.h>

JNIEXPORT jboolean JNICALL Java_mainPack_CFun_isCFun
(JNIEnv *env, jclass cls)
{
    return JNI_TRUE;
}

JNIEXPORT jint JNICALL Java_mainPack_CFun_sum_1written_1in_1c
(JNIEnv *env, jclass cls, jdouble a, jdouble b, jdouble c)
{
    jint t = a + b + c;
    return t;
}
