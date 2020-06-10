package com.bsu.Book.manipulator;

import com.bsu.Book.entity.Book;

import java.util.ArrayList;
import java.util.stream.Collectors;

public class StreamApi {
    public ArrayList<Book> findByAuthor(String author, ArrayList<Book> bookList) {
        return bookList.stream().filter((b) -> b.getAuthor().equals(author)).collect(Collectors.toCollection(ArrayList::new));
    }

    public void printByAuthor(String author, ArrayList<Book> bookList) {
        System.out.println("\nSorted by author " + author);
        for (Book book : findByAuthor(author, bookList)) {
            System.out.println(book.toString());
        }
    }


    public ArrayList<Book> findByPublisher(String publisher, ArrayList<Book> bookList) {
        return bookList.stream().filter((b) -> b.getPublisher().equals(publisher)).collect(Collectors.toCollection(ArrayList::new));
    }

    public void printByPublisher(String publisher, ArrayList<Book> bookList) {
        System.out.println("\nSorted by publisher " + publisher);
        for (Book book : findByPublisher(publisher, bookList)) {
            System.out.println(book.toString());
        }
    }


    public ArrayList<Book> findLaterThen(int year, ArrayList<Book> bookList) {
        return bookList.stream().filter((b) -> b.getYear() > year).collect(Collectors.toCollection(ArrayList::new));
    }

    public void printLaterThen(int year, ArrayList<Book> bookList) {
        System.out.println("\nBooks came out later then " + year);
        for (Book book : findLaterThen(year, bookList)) {
            System.out.println(book.toString());
        }
    }
}
