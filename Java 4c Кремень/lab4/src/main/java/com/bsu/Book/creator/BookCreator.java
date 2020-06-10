package com.bsu.Book.creator;

import com.bsu.Book.entity.Book;
import com.bsu.Book.exceptions.ParserException;
import com.bsu.Book.parser.BookParser;
import com.bsu.Book.run.Main;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.ArrayList;

public class BookCreator {
    private static final Logger log = LogManager.getLogger(Book.class.getName());
    private BookParser parser;

    public BookCreator() {
        parser = new BookParser();
    }

    public Book createFromString(String str) throws ParserException{
        ArrayList<Book> bookList = new ArrayList();
        Book book = parser.createFromString(str);
        return book;
    }


    public ArrayList<Book> createFromString(ArrayList<String> stringList) {
        ArrayList<Book> bookList = new ArrayList();
        for (String str : stringList) {
            try {
                bookList.add(createFromString(str));
            }
            catch (Exception ex){
                log.debug("Bad input. Not all required fields are filled");
            }
        }
        return bookList;
    }
}
