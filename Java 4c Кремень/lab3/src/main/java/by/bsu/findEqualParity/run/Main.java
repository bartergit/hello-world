package by.bsu.findEqualParity.run;

import by.bsu.findEqualParity.creator.IntegerArrayCreator;
import by.bsu.findEqualParity.filter.Filter;
import by.bsu.findEqualParity.operation.OperationArray;
import by.bsu.findEqualParity.reader.ConsoleReader;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        System.out.println("Input array:");
        String[] strings;
        ConsoleReader reader = new ConsoleReader();
        strings = reader.readStringArray();
        Filter filter = new Filter();
        String[] strNumbers = filter.filterInt(strings);
        IntegerArrayCreator creator = new IntegerArrayCreator();
        Integer[] numbers = creator.createFromString(strNumbers);
        if (numbers.length > 0) {
            System.out.println("Parsed numbers:");
            System.out.println(Arrays.toString(numbers));
            OperationArray manipulator = new OperationArray();
            System.out.println();
            System.out.println("the quantity of numbers with an equal number of even and odd digits: ");
            System.out.println(manipulator.findEqualParity(numbers));
        } else {
            System.out.println("Array is empty");
        }
    }
}
