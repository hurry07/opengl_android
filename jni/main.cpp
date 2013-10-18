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
#include "app/Application.h"

Application* app = NULL;

// ==========================
// Life Cycle
// ==========================
JNIEXPORT void JNICALL Java_com_op_activity_JSActivity_initWithAsset
(JNIEnv * env, jobject instance, jobject assetManager) {
    AssetUtil::mgr = AAssetManager_fromJava(env, assetManager);

    long size = 0;
    FILE* file = 0;

	file = AssetUtil::android_fopen("images/upgrade/paper_01.png", "r");
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
	fclose(file);
	LOGE("initAsset %ld", size);

	file = AssetUtil::android_fopen("images/upgrade/paper_01.png", "r");
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);
	fclose(file);
	LOGE("initAsset %ld", size);
}

JNIEXPORT void JNICALL Java_com_op_activity_JSActivity_jsCreate
(JNIEnv * env, jclass activityClass) {
    app = new Application();
}

JNIEXPORT void JNICALL Java_com_op_activity_JSActivity_jsDestory
(JNIEnv * env, jclass activityClass) {
    app->destroy();
}

JNIEXPORT void JNICALL Java_com_op_activity_JSActivity_evalScript
(JNIEnv * env, jclass activityClass, jstring script) {
//	LOGI("Activity %d", 10);
//
//	Isolate* isolate = v8::Isolate::GetCurrent();
//	HandleScope handle_scope(isolate);
//	Local<v8::Context> exec_context = Context::New(isolate);
//	Context::Scope context_scope(exec_context);
//
//	v8::Handle<v8::String> jscode = String::New(env->GetStringChars(script, NULL));
//	Local<Script> comp = Script::Compile(jscode);
//	Local<Value> result = comp->Run();
//	String::Utf8Value retstr(result);
//	LOGI("Activity %s", *retstr);
	LOGI("Activity %d", 20);
}

// ==========================
// View status change
// ==========================
JNIEXPORT void JNICALL Java_com_op_activity_JSSurfaceView_jsPause
  (JNIEnv *, jclass) {
	LOGI("view.pause");
	app->pause();
}

JNIEXPORT void JNICALL Java_com_op_activity_JSSurfaceView_jsResume
  (JNIEnv *, jclass) {
	LOGI("view.resume");
	app->resume();
}

// ==========================
// Render
// ==========================
JNIEXPORT void JNICALL Java_com_op_activity_JSRender_onSurfaceCreated
  (JNIEnv * env, jobject instance) {
    app->init();
	app->onSurfaceCreated(800, 480);
}

JNIEXPORT void JNICALL Java_com_op_activity_JSRender_onDrawFrame
  (JNIEnv * env, jobject instance, jobject) {
	app->onDrawFrame();
}

JNIEXPORT void JNICALL Java_com_op_activity_JSRender_onSurfaceChanged
  (JNIEnv * env, jobject instance, jobject, jint width, jint height) {
	LOGI("render width:%d height:%d", width, height);
	app->onSurfaceChanged(width, height);
}
