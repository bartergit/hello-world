package by.bsu.bubbleSort.operation;

import by.bsu.bubbleSort.creator.IntegerArrayCreator;
import org.testng.annotations.Test;

import java.util.Arrays;
import java.util.Collections;

import static org.testng.Assert.assertEquals;

@Test
public class OperationArrayTest {
    @Test(invocationCount = 10)
    public void test(){
        IntegerArrayCreator arrayCreator = new IntegerArrayCreator();
        OperationArray op = new OperationArray();
        int n = (int)(Math.random()* 10);
        Integer[] actual = arrayCreator.createRandom(n);
        Arrays.sort(actual, Collections.reverseOrder());
        System.out.println(Arrays.toString(actual));

        Integer[] expected = new Integer[n];
        System.arraycopy(actual,0,expected,0, n);
        op.bubble_sort(expected);
        System.out.println(Arrays.toString(expected));

        assertEquals(actual,expected);
    }
}
