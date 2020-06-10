package by.bsu.findEqualParity.reader;

import java.util.Scanner;

public class ConsoleReader {
    public static final String REGEX_DELIMITER = "\\s+";

    public String[] readStringArray() {
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        line = line.trim();
        return line.split(REGEX_DELIMITER);
    }
}
