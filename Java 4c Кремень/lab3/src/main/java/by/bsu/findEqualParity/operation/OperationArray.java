package by.bsu.findEqualParity.operation;

public class OperationArray {
    public int findEqualParity(Integer[] numbers) {  //finds the quantity of numbers
        // with an equal number of even and odd digits
        int counter = 0;
        for (int number : numbers) {
            int digitNumber = 0;
            number = Math.abs(number);
            while (number > 0) {
                int digit = number - (number / 10)*10;
//                System.out.println(digit);
                if (digit % 2 == 0)
                    digitNumber++;
                else
                    digitNumber--;
                number /= 10;
            }
            if (digitNumber == 0)
                counter++;
        }
        return counter;
    }
}

