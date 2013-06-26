#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
//int gettimeofday(struct timeval * tv, struct timezone *tz);

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Runtime.h"
#include "V8Util.h"

using namespace titanium;
using namespace v8;

extern "C" {
extern void example_initialize(v8::Handle<v8::Object> global_obj);
	
/*
int counter;

double timeDiff(timespec start, timespec end)
{
	return 1e3 * (end.tv_sec - start.tv_sec) + 1e-6 * (end.tv_nsec - start.tv_nsec);
}

int sprintfdoubles(char * buffer, int sampleSize, double * inputs)
{
	buffer[0] = '[';
	char * output = buffer + 1;
	for(int j=0; j<sampleSize; j++){
		output += sprintf(output," %f,",inputs[j]);
	}
	output[-1] = ' ';
	output[0] = ']';
	output[1] = 0;
	return output + 1 - buffer;
}

char * measureFunction( void (workFunct)(), char * name, int loopCount, int sampleSize)
{
	double cpuResults[sampleSize];
	double clockResults[sampleSize];
	double cpuSum = 0.0;
	double clockSum = 0.0;

	for(int j=0; j<sampleSize; j++){
		timespec threadStart, threadEnd, clockStart, clockEnd;
		clock_gettime(CLOCK_THREAD_CPUTIME_ID, &threadStart);
		clock_gettime(CLOCK_MONOTONIC, &clockStart);
		for(int i=0; i<loopCount; i++){
			workFunct();
		}
		clock_gettime(CLOCK_THREAD_CPUTIME_ID, &threadEnd);
		clock_gettime(CLOCK_MONOTONIC, &clockEnd);
		cpuSum += cpuResults[j]=timeDiff(threadStart,threadEnd);
		clockSum += clockResults[j]=timeDiff(clockStart,clockEnd);
	}
	char * buffer = (char *) malloc(sizeof(char)*4096);
	char * output = buffer + sprintf(buffer,"CPU results for %s (Avg %f): ",name, cpuSum/sampleSize);
	output += sprintfdoubles(output,sampleSize,cpuResults);
	output += sprintf(output," --------------- Time results for %s (Avg %f): ",name, clockSum/sampleSize);
	output += sprintfdoubles(output,sampleSize,clockResults);
	return buffer;
}

void doNothing(){
	counter ++;
}
*/
/*
jobject javaObject;
v8::Persistent<v8::Value> v8Object;
JNIEnv *localEnv;

void java2js(){
	v8::Handle<v8::Value> result = TypeConverter::javaObjectToJsValue(localEnv,javaObject);
}

void js2java(){
	v8::Local<v8::Value> result = v8::Local<v8::Value>(*TypeConverter::javaObjectToJsValue(localEnv,javaObject));
	jobject result2 = TypeConverter::jsValueToJavaObject(localEnv,result);
	localEnv->DeleteLocalRef(result2);
}


jobject quickTest(JNIEnv *env, void (workFunct)(), char * name)
{
	int loopCount = 10000;
	int sampleSize = 20;
	char * message = measureFunction(workFunct, name, loopCount, sampleSize);
	v8::Local<v8::String> jsMessage = String::New(message);
	jstring result = TypeConverter::jsStringToJavaString(env,jsMessage);
	free(message);
	return result;	
} 
*/
JNIEXPORT void JNICALL Java_co_lanica_calcswig_CalcswigModule_initializeSwig(JNIEnv* j_env, jclass j_class)
{
	example_initialize(titanium::V8Runtime::globalContext->Global());
}
/*
JNIEXPORT jobject JNICALL Java_ti_jnimark_JnimarkModule_nativeTest(JNIEnv *env, jobject jEmitter)
{
	ENTER_V8(V8Runtime::globalContext);
	JNIScope jniScope(env);
	return quickTest(env, doNothing, "Do nothing WONK");
}

JNIEXPORT jobject JNICALL Java_ti_jnimark_JnimarkModule_nativeTestToJS(JNIEnv *env, jobject jEmitter, jobject testSubject)
{
	ENTER_V8(V8Runtime::globalContext);
	JNIScope jniScope(env);

	localEnv = env;
	javaObject = testSubject;

	return quickTest(env, java2js, "Converting from Java to JS");
}

JNIEXPORT jobject JNICALL Java_ti_jnimark_JnimarkModule_nativeTestToJava(JNIEnv *env, jobject jEmitter, jobject testSubject)
{
	ENTER_V8(V8Runtime::globalContext);
	JNIScope jniScope(env);

	localEnv = env;
	javaObject = testSubject;
//	v8Object = v8::Persistent<v8::Value>(TypeConverter::javaObjectToJsValue(localEnv,testSubject));
//	v8Object = &v8Objects;
	return quickTest(env, js2java, "Converting from JS to Java");
//	v8Object.Dispose();
}
*/

}

