package com.example.users

import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity


abstract class SignInActivity : AppCompatActivity() {
    private var btnCallInputPhoneActivity: Button? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_sign_in)

        btnCallInputPhoneActivity = findViewById<View>(R.id.buttonCallInputPhone) as Button
        btnCallInputPhoneActivity!!.setOnClickListener {
            val intent = Intent(this@SignInActivity, InputPhoneActivity::class.java)
            startActivity(intent)
        }
    }
}