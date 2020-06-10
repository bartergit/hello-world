package com.bsu.Book.manipulator;

// a) список книг заданного автора;
//
//  b) список книг, выпущенных заданным издательством;
//
//  c) список книг, выпущенных после заданного года.

import com.bsu.Book.entity.Book;

import java.util.ArrayList;

public class DefaultManipulator {
    public ArrayList<Book> findByAuthor(String author, ArrayList<Book> bookList){
        ArrayList<Book> listByAuthor = new ArrayList<>();
        for (Book book:bookList) {
            if (book.getAuthor().equals(author))
                listByAuthor.add(book);
        }
        return listByAuthor;
    }

    public void printByAuthor(String author, ArrayList<Book> bookList){
        System.out.println("\nSorted by author "+ author);
        for (Book book:findByAuthor(author,bookList)) {
            System.out.println(book.toString());
        }
    }

    public ArrayList<Book> findLaterThen(int year, ArrayList<Book> bookList){
        ArrayList<Book> listByYear = new ArrayList<>();
        for (Book book:bookList) {
            if (book.getYear() > year)
                listByYear.add(book);
        }
        return listByYear;
    }

    public void printLaterThen(int year, ArrayList<Book> bookList){
        System.out.println("\nBooks came out later then "+ year);
        for (Book book:findLaterThen(year,bookList)) {
            System.out.println(book.toString());
        }
    }

    public ArrayList<Book> findByPublisher(String publisher, ArrayList<Book> bookList){
        ArrayList<Book> listByPublisher = new ArrayList<>();
        for (Book book:bookList) {
            if (book.getPublisher().equals(publisher))
                listByPublisher.add(book);
        }
        return listByPublisher;
    }

    public void printByPublisher(String publisher, ArrayList<Book> bookList){
        System.out.println("\nSorted by publisher "+ publisher);
        for (Book book:findByAuthor(publisher,bookList)) {
            System.out.println(book.toString());
        }
    }
}
