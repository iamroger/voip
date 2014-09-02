/* 
 * Copyright (C) 2009 Jurij Smakov <jurij@wooyd.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

package org.wooyd.android.voidroid;

import android.app.Activity;
import android.os.Bundle;
import java.util.zip.*;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.File;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import org.wooyd.android.pjsua.pjsua;
import android.util.Log;
       
public class VoiDroid extends Activity
{
    String callStateText;
    pjsua pj;
    EditText addressField, sipUsername, sipDomain, sipPassword, proxyField;
    TextView statusField;
    Button callButton, hangupButton;
    int acc_id = -1;

    public void loadNativeLibrary() {
        try {
            ZipFile zip = new ZipFile("/data/app/org.wooyd.android.voidroid.apk");
            ZipEntry zipen = zip.getEntry("assets/libpjsua_simple_jni.so");
            InputStream is = zip.getInputStream(zipen);
            OutputStream os = new FileOutputStream("/data/data/org.wooyd.android.voidroid/libpjsua_simple_jni.so");
            byte[] buf = new byte[8092];
            int n;
            while ((n = is.read(buf)) > 0) os.write(buf, 0, n);
            os.flush();
            os.close();
            is.close();
            System.load("/data/data/org.wooyd.android.voidroid/libpjsua_simple_jni.so");
        } catch (Exception ex) {
            Log.e("VoiDroid", "failed to copy native library: " + ex);
        }
    }

     /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        addressField = (EditText) findViewById(R.id.address);
        sipUsername = (EditText) findViewById(R.id.username);
        sipDomain = (EditText) findViewById(R.id.domain);
        sipPassword = (EditText) findViewById(R.id.password);
        proxyField = (EditText) findViewById(R.id.proxy);
        statusField = (TextView) findViewById(R.id.status);

        loadNativeLibrary();
        pj = new pjsua();

        callButton = (Button) findViewById(R.id.call_button);
        callButton.setOnClickListener(new Button.OnClickListener() {
            public void onClick(View v) {
                String proxy = proxyField.getText().toString();
                if(proxy.length() != 0) {
                    if(!proxy.startsWith("sip:")) proxy = "sip:" + proxy;
                    if(!proxy.endsWith(";lr")) proxy += ";lr";
                }
                int status = pj.init(proxy);
                String address = addressField.getText().toString();
                if(acc_id < 0) {
                    acc_id = pj.add_account(sipUsername.getText().toString(),
                                            sipDomain.getText().toString(),
                                            sipPassword.getText().toString());
                    if(acc_id < 0) {
                        /* Tried to register, but an error has occured */
                        statusField.setText("Failed to register SIP account");
                        return;
                    } else {
                        statusField.setText("Registered SIP account");
                    }
                }
                statusField.setText("Call to " + address + " in progress");
                status = pj.make_call(acc_id, address);
                if(status != 0) {
                    statusField.setText("Call to " + address + "failed");
                }
            }
        });

        hangupButton = (Button) findViewById(R.id.hangup_button);
        hangupButton.setOnClickListener(new Button.OnClickListener() {
             public void onClick(View v) {
                pj.hangup();
                statusField.setText("Hung up");
                pj.destroy();
             }
        });    
    }
}
