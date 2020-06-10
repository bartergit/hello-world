package by.bsu.matrix.entity;

import by.bsu.matrix.exception.MatrixException;


/**
 * Class {@code Matirx} this class describes quadratic matrix n x n.
 * <p>
 * Created 07.03.2020.
 *
 * @author Pozdnyakov I.V.
 * @version 1.0
 */

public class Matrix {

    private double[][] matrix;


    /**
     * Constructor of the class
     *
     * @param verticalSize is the vertical size of of matrix
     * @param horizontalSize is the horizontal size of of matrix
     * @throws MatrixException this exception arises when the matrix is incorrect
     */

    public Matrix(int verticalSize, int horizontalSize) throws MatrixException {
        if (verticalSize < 1 || horizontalSize < 1) {
            throw new MatrixException();
        }
        matrix = new double[verticalSize][horizontalSize];
    }


    /**
     * Constructor of the class
     *
     * @param n is the size of of square matrix
     * @throws MatrixException this exception arises when the matrix is incorrect
     */

    public Matrix(int n) throws MatrixException {
        if (n < 1) {
            throw new MatrixException();
        }
        matrix = new double[n][n];
    }

    /**
     * returns matrix vertical size
     *
     * @return matrix length in integer
     */

    public int getVerticalSize() {
        return matrix.length;
    }


    /**
     * returns matrix vertical size
     *
     * @return matrix length in integer
     */

    public int getHorizontalSize() {
        return matrix[0].length;
    }


    /**
     * returns matrix[i][j] element
     *
     * @param i - vertical index
     * @param j - horizontal index
     * @return returns matrix[i][j] element
     * @throws MatrixException this exception arises when the matrix is incorrect
     */

    public double getElement(int i, int j) throws MatrixException {
        if (checkRange(i, j)) {
            return matrix[i][j];
        }
        throw new MatrixException();
    }

    /**
     * set matrix[i][j] element
     *
     * @param i     - vertical index
     * @param j     - horizontal index
     * @param value - setting value
     * @throws MatrixException this exception arises when the matrix is incorrect
     */

    public void setElement(int i, int j, double value) throws MatrixException {
        if (checkRange(i, j)) {
            matrix[i][j] = value;
        } else {
            throw new MatrixException();
        }
    }

    /**
     * overriding default toString function to output
     *
     * @return beautiful matrix view of double array
     */

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder("\nMatrix : " + this.getVerticalSize() + " x " + this.getHorizontalSize() + "\n");
        for (double[] row : matrix) {
            for (double value : row) {
                s.append(String.format("%6.2f", value));
            }
            s.append("\n");
        }
        return s.toString();
    }

    /**
     * compare 2 object by values
     *
     * @param obj compared object
     * @return boolean is equal or not
     */
    @Override
    public boolean equals(Object obj) {
        if (obj == this)
            return true;
        if (!(obj instanceof Matrix))
            return false;
        Matrix another = (Matrix) (obj);
        if (another.getHorizontalSize()!= this.getHorizontalSize() || another.getVerticalSize()!= this.getVerticalSize())
            return false;
        try {
            for (int i = 0; i < another.getVerticalSize(); i++) {
                for (int j = 0; j < another.getHorizontalSize(); j++) {
                    if (another.getElement(i, j) != this.getElement(i, j))
                        return false;
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return true;
    }

    /**
     * check if [i][j] is in range and correct
     *
     * @param i vertical index
     * @param j horizontal index
     * @return boolean if in range
     */

    public boolean checkRange(int i, int j) {
        return i >= 0 && i < this.getVerticalSize() && j >= 0 && j < this.getHorizontalSize();
    }
}