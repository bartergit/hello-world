package com.bsu.Book.parser;

import com.bsu.Book.exceptions.ParserException;

import java.lang.reflect.Field;
import java.util.Dictionary;
import java.util.Hashtable;

public abstract class Parser<Entity> {
    public Dictionary parseToDict(Class className, String str) throws ParserException {
//        Book b = new Book("1","2","3",13,24.5, Binding.HARD);
//        ArrayList<String> fields = new ArrayList();
        Dictionary dict = new Hashtable();
        for (Field field : className.getDeclaredFields()) {
            String fieldStr = field.getName();
            int index = str.indexOf(fieldStr);
            int endIndex = str.indexOf(",", index);
            if (endIndex == -1){
                endIndex = str.length();
            }
            if (index != -1)
                dict.put(fieldStr, str.substring(index + fieldStr.length() + 1, endIndex));
        }
        return dict;
    }

    public abstract Entity createFromString(String str) throws ParserException;
}
