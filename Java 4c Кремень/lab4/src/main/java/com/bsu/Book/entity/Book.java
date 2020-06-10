package com.bsu.Book.entity;
//Название, Автор(ы), Издательство, Год издания, Количество страниц, Цена, Переплет

public class Book {

    private int id;
    private String name;
    private String author;
    private String publisher;
    private int pageAmount;

    @Override
    public String toString() {
        return "Book{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", author='" + author + '\'' +
                ", publisher='" + publisher + '\'' +
                ", pageAmount=" + pageAmount +
                ", price=" + price +
                ", binding=" + binding +
                ", year=" + year +
                '}';
    }

    private double price;
    private Binding binding;
    private int year;

    public Book() {
    }

    public Book(int id, String name, String author, int year, String publishingHouse, int pageAmount, double price, Binding binding) {
        this.id = id;
        this.name = name;
        this.author = author;
        this.year = year;
        this.publisher = publishingHouse;
        this.pageAmount = pageAmount;
        this.price = price;
        this.binding = binding;
    }

    //SET
    public void setName(String name) {
        this.name = name;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public void setPageAmount(int pageAmount) {
        this.pageAmount = pageAmount;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setBinding(Binding binding) {
        this.binding = binding;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setYear(int year) {
        this.year = year;
    }

    //GET

    public int getYear() {
        return year;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getAuthor() {
        return author;
    }

    public String getPublisher() {
        return publisher;
    }

    public int getPageAmount() {
        return pageAmount;
    }

    public double getPrice() {
        return price;
    }

    public Binding getBinding() {
        return binding;
    }

}
