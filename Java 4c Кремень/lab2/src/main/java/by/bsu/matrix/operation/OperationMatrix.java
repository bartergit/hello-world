package by.bsu.matrix.operation;

import by.bsu.matrix.entity.Matrix;
import by.bsu.matrix.exception.MatrixException;

/**
 * Class {@code OperationMatrix} this class performs various operations, like transpose and filling existing matrices.
 * <p>
 * Created 07.03.2020.
 *
 * @author Pozdnyakov I.V.
 * @version 1.0
 */
public class OperationMatrix {
    /**
     * Finds the transposed to given matrix.
     *
     * @param originalMatrix is matrix of float numbers
     * @return transposed matrix
     */
    public Matrix transpose(Matrix originalMatrix) throws MatrixException {
        double temp = 0;
        Matrix matrix = new Matrix(originalMatrix.getVerticalSize());
        for (int i = 0; i < matrix.getVerticalSize(); i++) {
            for (int j = i; j < matrix.getVerticalSize(); j++) {
                matrix.setElement(i, j, originalMatrix.getElement(j, i));
                matrix.setElement(j, i, originalMatrix.getElement(i, j));
            }
        }
        return matrix;
    }

    /**
     * Finds the maximum modulus value in the array.
     *
     * @param matrix is matrix of float numbers
     * @return matrix, filled with random float numbers from 10 to 40
     */

    public Matrix fillRandom(Matrix matrix) throws MatrixException {
        for (int i = 0; i < matrix.getVerticalSize(); i++) {
            for (int j = 0; j < matrix.getHorizontalSize(); j++) {
                double value = (Math.random() * 30 + 10);
                matrix.setElement(i, j, value);
            }
        }
        return matrix;
    }
}
