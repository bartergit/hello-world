package by.bsu.bubbleSort.run;

import by.bsu.bubbleSort.creator.IntegerArrayCreator;
import by.bsu.bubbleSort.filter.Filter;
import by.bsu.bubbleSort.operation.OperationArray;
import by.bsu.bubbleSort.reader.ConsoleReader;

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
            System.out.println("Sorted array:");
            System.out.println(Arrays.toString(manipulator.bubble_sort(numbers)));
        } else {
            System.out.println("Array is empty");
        }
    }
}
