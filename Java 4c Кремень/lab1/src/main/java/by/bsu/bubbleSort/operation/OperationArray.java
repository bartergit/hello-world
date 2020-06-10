package by.bsu.bubbleSort.operation;

public class OperationArray {
    public Integer[] bubble_sort(Integer[] numbers) {
        for (int i = 0; i < numbers.length - 1; i++) {
            int counter = 0;
            for (int j = 0; j < numbers.length - i - 1; j++) {
                if (Math.abs(numbers[j]) < Math.abs(numbers[j + 1])) {
                    counter++;
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
            if (counter == 0)
                break;
        }
        return numbers;
    }
}
