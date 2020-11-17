package com.example.todolist.recyclerview;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import androidx.annotation.Nullable;
import java.util.ArrayList;

public class DbHelper extends SQLiteOpenHelper {

    // communication with DB

    private static final String DB_NAME = "List";
    private static final int DB_VER = 1;
    private static final String DB_TABLE = "ToDo";
    public static final String DB_COLUMN1 = "Info";

    public DbHelper(@Nullable Context context) {
        super(context, DB_NAME, null, DB_VER);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String query = String.format("CREATE TABLE %s (ID INTEGER PRIMARY KEY AUTOINCREMENT, %s TEXT NOT NULL);",
                DB_TABLE, DB_COLUMN1);
        db.execSQL(query);

    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        String query = String.format("DELETE TABLE IF EXISTS %s", DB_TABLE);
        db.execSQL(query);
        onCreate(db);
    }

    public void insert(String info){
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues value = new ContentValues();
        value.put(DB_COLUMN1, info);
        db.insertWithOnConflict(DB_TABLE, null, value, SQLiteDatabase.CONFLICT_REPLACE);
        db.close();
    }

    public void delete(String info){
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(DB_TABLE, DB_COLUMN1 + " = ?", new String[]{info});
        db.close();
    }

    public ArrayList<String> getList(){
        ArrayList<String> task = new ArrayList<>();
        SQLiteDatabase db = this.getReadableDatabase();
        Cursor cursor = db.query(DB_TABLE, new String[]{DB_COLUMN1},null,null,null,null,null);
        while(cursor.moveToNext()){
            int nameIndex = cursor.getColumnIndex(DB_COLUMN1);
            String carName = cursor.getString(nameIndex);
            task.add(carName);
        }
        cursor.close();
        db.close();
        return task;
    }
}
