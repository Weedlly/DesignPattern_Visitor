package com.example.ui_users

import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity


class PhoneNumberActivity : AppCompatActivity() {
    var editPhone: EditText? = null
    var btnPhone: Button? = null
    //var phoneNumber: Long = 0
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_phone_number)
        editPhone = findViewById<EditText>(R.id.editTextPhoneNumber)
        btnPhone = findViewById<Button>(R.id.buttonCall)
        var str = ""

        this@PhoneNumberActivity.btnPhone!!.setOnClickListener(View.OnClickListener {
            str = this@PhoneNumberActivity.editPhone!!.getText().toString()
            val msg = Toast.makeText(this@PhoneNumberActivity, str, Toast.LENGTH_LONG)
            msg.show()
        })

    }

}