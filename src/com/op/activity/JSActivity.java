/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.op.activity;

import android.app.Activity;
import android.content.res.AssetManager;
import android.os.Bundle;

public class JSActivity extends Activity {

    static {
        System.loadLibrary("v8android");
        System.loadLibrary("glm");
        System.loadLibrary("freetype_gl");
        System.loadLibrary("gl2jni");
    }

    private AssetManager  mgr;

    private JSSurfaceView mView;

    @Override
    protected void onCreate(Bundle icicle) {
        super.onCreate(icicle);

        // prepare tools
        mgr = getAssets();
        initWithAsset(mgr);

        System.out.println("JSActivity.onCreate() 0a");
        jsCreate();
        System.out.println("JSActivity.onCreate() 0b");
//        evalScript("(function() {var a='aabbcc';return a;})()");
//        System.out.println("GL2JNIActivity.onCreate()");

        System.out.println("JSActivity.onCreate() 01");
        mView = new JSSurfaceView(getApplication());
        System.out.println("JSActivity.onCreate() 02");
        setContentView(mView);
        System.out.println("JSActivity.onCreate() 03");
    }

    @Override
    protected void onDestroy() {
        jsDestory();
        super.onDestroy();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mView.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        mView.onResume();
    }

    /**
     * 使用 asset 来初始化上下文
     * 
     * @param assetManager
     */
    public native void initWithAsset(AssetManager assetManager);

    public static native void jsCreate();

    public static native void jsDestory();

    public static native void evalScript(String script);
}