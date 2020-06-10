package by.bsu.GoogleSpreadsheets.validator;

import java.util.Scanner;

public class Validator {
    public int checkUserChoice(Scanner scanner){
        while(!scanner.hasNextInt()){
            System.out.println("Choice must be an integer");
            System.out.print(">>> ");
            scanner.next();
        }
        return scanner.nextInt();
    }
}