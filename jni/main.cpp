//
//  Application.cpp
//  v8
//
//  Created by jie on 13-8-4.
//  Copyright (c) 2013年 jie. All rights reserved.
//
#include "global.h"
#include "Java_com_op_activity_JSActivity.h"
#include "Java_com_op_activity_JSRender.h"
#include "Java_com_op_activity_JSSurfaceView.h"
#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include "utils/AssetUtil.h"
#include <v8.h>
//#include "app/Application.h"

//Application* app = NULL;
using namespace v8;

// ==========================
// Life Cycle
// ==========================
JNIEXPORT void JNICALL Java_com_op_activity_JSActivity_initWithAsset
(JNIEnv * env, jobject instance, jobject assetManager) {
	AssetUtil::mgr = AAssetManager_fromJava(env, assetManager);
}

JNIEXPORT void JNICALL Java_com_op_activity_JSActivity_jsCreate
(JNIEnv * env, jclass activityClass) {
//    app = new Application();
//    app->init();
}

JNIEXPORT void JNICALL Java_com_op_activity_JSActivity_jsDestory
(JNIEnv * env, jclass activityClass) {
}

JNIEXPORT void JNICALL Java_com_op_activity_JSActivity_evalScript
(JNIEnv * env, jclass activityClass, jstring script) {
	LOGI("Activity %d", 10);

	Isolate* isolate = v8::Isolate::GetCurrent();
	HandleScope handle_scope(isolate);
	Local<v8::Context> exec_context = Context::New(isolate);
	Context::Scope context_scope(exec_context);

	v8::Handle<v8::String> jscode = String::New(env->GetStringChars(script, NULL));
	Local<Script> comp = Script::Compile(jscode);
	Local<Value> result = comp->Run();
	String::Utf8Value retstr(result);
	LOGI("Activity %s", *retstr);

	LOGI("Activity %d", 20);
}

// ==========================
// View status change
// ==========================
JNIEXPORT void JNICALL Java_com_op_activity_JSSurfaceView_jsPause
  (JNIEnv *, jclass) {
	LOGI("view.pause");
//	app->pause();
}

JNIEXPORT void JNICALL Java_com_op_activity_JSSurfaceView_jsResume
  (JNIEnv *, jclass) {
	LOGI("view.resume");
//	app->resume();
}

// ==========================
// Render
// ==========================
JNIEXPORT void JNICALL Java_com_op_activity_JSRender_onDrawFrame
  (JNIEnv * env, jobject instance, jobject) {
//	LOGI("render.draw");
//    app->onDrawFrame();
}

JNIEXPORT void JNICALL Java_com_op_activity_JSRender_onSurfaceChanged
  (JNIEnv * env, jobject instance, jobject, jint width, jint height) {
	LOGI("render width:%d height:%d", width, height);
//	app->onSurfaceChanged(width, height);
}

JNIEXPORT void JNICALL Java_com_op_activity_JSRender_onSurfaceCreated
  (JNIEnv * env, jobject instance) {
//	app->onSurfaceCreated(800, 480);
}
