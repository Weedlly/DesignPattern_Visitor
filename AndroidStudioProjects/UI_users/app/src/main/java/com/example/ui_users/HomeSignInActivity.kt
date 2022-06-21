package com.example.ui_users

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button

class HomeSignInActivity : AppCompatActivity() {
    private var btnCallInputPhoneActivity: Button? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_home_sign_in)

        btnCallInputPhoneActivity = findViewById<View>(R.id.buttonCallInputPhone) as Button
        btnCallInputPhoneActivity!!.setOnClickListener {
            val intent = Intent(this@HomeSignInActivity, PhoneNumberActivity::class.java)
            startActivity(intent)
        }
    }
}