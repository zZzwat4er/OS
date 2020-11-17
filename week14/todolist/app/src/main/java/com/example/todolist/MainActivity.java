package com.example.todolist;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import com.example.todolist.recyclerview.Adapter;
import com.example.todolist.recyclerview.DbHelper;


/*
this code is basically one of my projects that I have made piteously. So I had the same issue to
deal with so I just rewrite it here
ALERT: the way DBHelper was realised do not consider that there are 2 identical task so it deletes
all task with same name
*/

public class MainActivity extends AppCompatActivity {

    public static final Integer ADD_TASK_ACTIVITY_CODE = 0;
    private RecyclerView recyclerView;// list of items

    DbHelper dbHelper;// interface to communicate with database

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        dbHelper = new DbHelper(this);// DB init
        //Setting up RV
        recyclerView = (RecyclerView) findViewById(R.id.carList);
        recyclerView.setHasFixedSize(false);
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        recyclerView.setAdapter(new Adapter(this, dbHelper.getList(), this));


    }

    // start Activity with task addition
    public void addTask(View view){
        Intent intent = new Intent(this, AddTaskActivity.class);
        startActivityForResult(intent, ADD_TASK_ACTIVITY_CODE);
    }
    // update activity if something has changed
    public void update(){
        recyclerView.getAdapter().notifyDataSetChanged();
        recreate();
    }

    // work on respond
    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == ADD_TASK_ACTIVITY_CODE){
            if(resultCode == RESULT_OK){
                if(data != null) {
                    dbHelper.insert(data.getStringExtra("task_name"));
                    recyclerView.getAdapter().notifyDataSetChanged();
                    recreate();
                }
            }
        }
    }
}
