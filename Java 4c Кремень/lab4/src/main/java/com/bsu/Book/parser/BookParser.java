package com.bsu.Book.parser;

import com.bsu.Book.entity.Binding;
import com.bsu.Book.entity.Book;
import com.bsu.Book.exceptions.ParserException;
import com.bsu.Book.run.Main;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.Dictionary;

public class BookParser extends Parser<Book> {
    private static final Logger log = LogManager.getLogger(Parser.class.getName());
    public Book createFromString(String str) throws ParserException {
        Dictionary dict = parseToDict(Book.class, str);
        Book book = new Book();
        try {
            book.setId(Integer.parseInt(dict.get("id").toString()));
            book.setName(dict.get("name").toString());
            book.setYear(Integer.parseInt(dict.get("year").toString()));
            book.setAuthor(dict.get("author").toString());
            book.setPublisher(dict.get("publisher").toString());
        }
        catch (Exception ex){
            throw new ParserException();
        }
        try{
            book.setPageAmount(Integer.parseInt(dict.get("pageAmount").toString()));
        }
        catch (Exception ex){
            log.debug("page amount is not recognized, data discarded");
        }
        try{
            book.setBinding(Binding.valueOf(dict.get("binding").toString()));
        }
        catch (Exception ex){
            log.debug("binding is not recognized, data discarded");
        }
        try{
            book.setPrice(Float.parseFloat(dict.get("price").toString()));
        }
        catch (Exception ex){
            log.debug("price is not recognized, data discarded");
        }
        return book;
    }
}
