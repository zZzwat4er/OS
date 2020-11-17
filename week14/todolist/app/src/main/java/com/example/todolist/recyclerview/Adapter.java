package com.example.todolist.recyclerview;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;
import com.example.todolist.MainActivity;
import com.example.todolist.R;
import java.util.ArrayList;

public class Adapter extends RecyclerView.Adapter<Adapter.ViewHolder> {

    // Data Adapter for RecyclerView

    private static Context currentActivity;
    private ArrayList<String> infos;
    private static MainActivity mAct;

    public Adapter(Context currentActivity, ArrayList<String> infos, MainActivity act){
        this.currentActivity = currentActivity;
        this.infos = infos;
        mAct = act;
    }

    public static class ViewHolder extends RecyclerView.ViewHolder{

        //Class of ViewHolder

        private TextView infoTextView;
        private Button deleteButton;
        private String info;
        public ViewHolder(@NonNull ConstraintLayout itemView) {
            super(itemView);// row.xml
            infoTextView = (TextView) itemView.getChildAt(0);
            deleteButton = (Button) itemView.getChildAt(1);
            // set onClick
            // delete item from DB and trigger activity update(MainActivity.update())
            deleteButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    DbHelper db = new DbHelper(currentActivity);
                    db.delete(infoTextView.getText().toString());
                    mAct.update();
                }
            });
        }
    }

    @NonNull
    @Override
    public Adapter.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        ConstraintLayout view = (ConstraintLayout) LayoutInflater.from(parent.getContext())
                .inflate(R.layout.row, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        holder.info = infos.get(position);
        holder.infoTextView.setText(infos.get(position));
    }

    @Override
    public int getItemCount() { return infos.size(); }

}
