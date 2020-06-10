package by.bsu.findEqualParity.operation;

import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;

@Test
public class OperationArrayTest {
    @Test
    public void testFindEqualParityZero() {
        OperationArray op = new OperationArray();
        Integer[] array = new Integer[]{1, 5, 8, 19};
        int actual = op.findEqualParity(array);
        int expected = 0;
        assertEquals(actual, expected);

    }
    @Test
    public void testFindEqualParityOne() {
        OperationArray op = new OperationArray();
        Integer[] array = new Integer[]{29};
        int actual = op.findEqualParity(array);
        int expected = 1;
        assertEquals(actual, expected);
    }
    @Test
    public void testFindEqualParityMany() {
        OperationArray op = new OperationArray();
        Integer[] array = new Integer[]{29, 32, 555666, 5556667, 5456, 312867};
        int actual = op.findEqualParity(array);
        int expected = 5;
        assertEquals(actual, expected);
    }
}
