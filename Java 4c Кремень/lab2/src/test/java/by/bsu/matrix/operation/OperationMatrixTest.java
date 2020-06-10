package by.bsu.matrix.operation;

import by.bsu.matrix.entity.Matrix;
import by.bsu.matrix.exception.MatrixException;
import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;
import static org.testng.Assert.assertNotEquals;

public class OperationMatrixTest {
    @Test
    public void testTranspose() throws MatrixException {
        Matrix expected = new Matrix(5);
        OperationMatrix op = new OperationMatrix();
        op.fillRandom(expected);
        Matrix actual = op.transpose(op.transpose(expected));
        assertEquals(actual, expected);
    }

    @Test
    public void testGetSizeException() throws MatrixException {
        Matrix matrix = new Matrix(4);
        OperationMatrix op = new OperationMatrix();
        op.fillRandom(matrix);
        Matrix empty = new Matrix(4);
        assertNotEquals(matrix,empty);
    }

}