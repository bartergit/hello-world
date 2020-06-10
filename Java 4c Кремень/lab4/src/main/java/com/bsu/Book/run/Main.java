package com.bsu.Book.run;

import com.bsu.Book.creator.BookCreator;
import com.bsu.Book.entity.Book;
import com.bsu.Book.manipulator.DefaultManipulator;
import com.bsu.Book.manipulator.StreamApi;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    private static final Logger log = LogManager.getLogger(Main.class.getName());
    public static void main(String[] args) {
        log.info("Working just fine!");
        BookCreator creator = new BookCreator();
        ArrayList<String> stringList = new ArrayList<>(Arrays.asList("name=Name,id=14,year=1999,author=Поздняков,publisher=Белиздат",
                "id=13,name=Name2,publisher=Черниздат,author=Поздняков,year=1789,",
                "name=Я крокодил 1, id=15, year=2000, binding=HARD, price=3.45, pageAmount=28, author=Иванов, publisher=Белиздат",
                "name=Крокожу, id=11, year=2000, author=Иванов",
                "name=Я крокодил 1, id=15, year=2000, binding=HARD, price=56, pageAmount=a, author=Иванов, publisher=Белиздат"));
        ArrayList<Book> bookList =  creator.createFromString(stringList);
        System.out.println(bookList.toString());
        DefaultManipulator manip1 = new DefaultManipulator();
        manip1.printByAuthor("Поздняков",bookList);
        manip1.printByPublisher("Белиздат",bookList);
        manip1.printLaterThen(1800,bookList);
        StreamApi manip2 = new StreamApi();
        System.out.println("\nSame with StreamApi");
        manip2.printByAuthor("Поздняков",bookList);
        manip2.printByPublisher("Белиздат",bookList);
        manip2.printLaterThen(1800,bookList);
    }
}
