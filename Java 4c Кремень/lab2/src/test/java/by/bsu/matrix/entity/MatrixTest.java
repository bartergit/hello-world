package by.bsu.matrix.entity;

import by.bsu.matrix.exception.MatrixException;
import org.testng.annotations.Test;

import static org.testng.Assert.*;

public class MatrixTest {

    @Test
    public void testGetSize() throws MatrixException {
        Matrix matrix = new Matrix(5);
        int actual = matrix.getVerticalSize();
        int expected = 5;
        assertEquals(actual, expected);
    }

    @Test(expectedExceptions = MatrixException.class)
    public void testGetSizeException() throws MatrixException {
        Matrix matrix = new Matrix(0);
    }

    @Test
    public void testGetElement() throws MatrixException {
        Matrix matrix = new Matrix(2);
        matrix.setElement(0, 0, 1.5);
        double actual = matrix.getElement(0, 0);
        double expected = 1.5;
        assertEquals(actual, expected, 0.001);
    }

    @Test(expectedExceptions = MatrixException.class)
    public void testGetElementException() throws MatrixException {
        Matrix matrix = new Matrix(5);
        matrix.getElement(6, 4);
    }
}