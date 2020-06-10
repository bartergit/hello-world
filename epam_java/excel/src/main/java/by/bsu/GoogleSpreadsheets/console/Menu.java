package by.bsu.GoogleSpreadsheets.console;

import by.bsu.GoogleSpreadsheets.controller.SheetManipulator;
import by.bsu.GoogleSpreadsheets.validator.Validator;

import java.io.IOException;
import java.security.GeneralSecurityException;
import java.util.List;
import java.util.Scanner;

public class Menu {
    private Scanner scanner;
    private Validator validator;
    private boolean menuIsRunning = true;
    private SheetManipulator sheetManipulator;

    public Menu(){
        scanner = new Scanner(System.in);
        validator = new Validator();
        sheetManipulator = new SheetManipulator("tokens","/credentials.json");
        sheetManipulator.setSpreadsheetId("1NikstCejlPwT-iM3jCJIaeNeCZZVcVTLiY6U1ux0ISg");
    }

    public void run(){
        while (menuIsRunning){
            showMenu();
            int choice = validator.checkUserChoice(scanner);
            switch (choice){
                case 1:
                    showStudents();
                    break;
                case 2:
                    addNewStudent();
                    break;
                case 0:
                    exit();
                    break;
                default:
                    System.out.println("There is no such choice as " + choice);
            }
        }
    }

    public void showMenu(){
        StringBuilder s = new StringBuilder();

        s.append("Choose the action").append("\n")
                .append("1.Show table").append("\n")
                .append("2.Add new line").append("\n")
                .append("0.Exit program").append("\n")
                .append(">>> ");

        System.out.print(s.toString());
    }

    public void showStudents(){
        try {
            System.out.println("-----------------");
            System.out.println(sheetManipulator.showTable());
            System.out.println("-----------------");
        } catch (IOException | GeneralSecurityException e){
            System.out.println(e.toString());
        }
    }

    public void addNewStudent() {
        try {
            System.out.println("Enter student name");
            System.out.print(">>>");
            String name = scanner.next();
            System.out.println("Enter student surname");
            System.out.print(">>>");
            String surname = scanner.next();
            System.out.println("Enter student third name");
            System.out.print(">>>");
            String thirdName = scanner.next();
            System.out.println("Enter student age");
            System.out.print(">>>");
            int age = scanner.nextInt();
            sheetManipulator.addLine(name, surname, thirdName, age);
        } catch (Exception ex){
            System.out.println(ex.toString());
        }
    }

    public void exit(){
        System.out.println("Stopping application...");
        menuIsRunning = false;
    }

}