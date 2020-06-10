package by.ignot.lab4a.reader;

import by.ignot.lab4a.exception.FileReadException;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

public class CsvReader {
    public static LinkedList<String> readCsv(String path) throws FileReadException {
        if (path == null){
            throw new FileReadException("Path can't be null");
        }
        File file = new File(path);
        LinkedList<String> strings = new LinkedList<>();
        try(Scanner scanner = new Scanner(file)){
            while(scanner.hasNextLine()){
                strings.add(scanner.nextLine());
            }
            return strings;
        }
        catch (FileNotFoundException e){
            throw new FileReadException("No such file at path: " + path, e);
        }
    }
}
