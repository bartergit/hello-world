package by.bsu.findEqualParity.filter;

public class Filter {
    public static final String REGEX = "[-+]?\\d+";

    public String[] filterInt(String[] numbers) {
        int counter = 0;
        for (String numberString : numbers) {
            if (numberString.matches(REGEX)) {
                counter++;
            }
        }
        String[] correctStr = new String[counter];
        int index = 0;
        for (String numberString : numbers) {
            if (numberString.matches(REGEX)) {
                correctStr[index] = numberString;
                index++;
            }
        }
        return correctStr;
    }
}
