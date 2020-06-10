package by.bsu.bubbleSort.creator;

public class IntegerArrayCreator {
    public Integer[] createFromString(String[] values) {
        Integer[] result = new Integer[values.length];
        for (int i = 0; i < values.length; i++) {
            result[i] = Integer.parseInt(values[i]);
        }
        return result;
    }
    public Integer[] createRandom(int n){
        Integer[] result = new Integer[n];
        for (int i = 0; i < n; i++) {
            result[i] = (int)(Math.random() * 50);
        }
        return result;
    }
}
