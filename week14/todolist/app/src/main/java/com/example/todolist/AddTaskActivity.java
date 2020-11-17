package com.example.todolist;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import com.example.todolist.recyclerview.DbHelper;

public class AddTaskActivity extends AppCompatActivity {
    private DbHelper dbHelper;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_task);
    }

    // send respond and close activity
    public void addCar(View view){
        EditText name = findViewById(R.id.task_name);
        Intent intent = new Intent();
        if(!name.getText().toString().isEmpty()){
            intent.putExtra("task_name", name.getText().toString());
            setResult(RESULT_OK, intent);
            finish();
        }
    }
}