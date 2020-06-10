package by.bsu.TriangleExistence;


import org.testng.annotations.DataProvider;
import org.testng.annotations.Ignore;
import org.testng.annotations.Test;
import static org.testng.Assert.*;


public class TriangleValidatorTest {
    @DataProvider
    public Object[][] sidesAreZero() {
        return new Object[][]{
                {0, 0, 0},
                {1, 0, 0},
                {5, 0, 9},
                {0, 8, 3},
                {6, 16, 0}
        };
    }

    @Test(dataProvider = "sidesAreZero")
    public void checkIsExistZeroes(double a, double b, double c) throws Exception {
        assertEquals(TriangleValidator.checkIsExist(a, b, c), false);
    }

    @DataProvider
    public Object[][] positiveSides() {
        return new Object[][]{
                {5, 6.4, 9},
                {7, 8, 4},
                {6, 16, 11}
        };
    }
    @Test(dataProvider = "positiveSides")
    public void testCheckTrianglePossiblePositiveSides(double a, double b, double c) throws Exception {
        assertTrue(TriangleValidator.checkIsExist(a, b, c));
    }

    @DataProvider
    public Object[][] nonCorrectSides() {
        return new Object[][]{
                {5, 34, 5},
                {100, 1, 101},
        };
    }
    @Test(dataProvider = "nonCorrectSides")
    public void testCheckTrianglePossibleNonCorrectSidesSides(double a, double b, double c) throws Exception {
        assertFalse(TriangleValidator.checkIsExist(a, b, c));
    }

    @DataProvider
    public Object[][] smallData() {
        return new Object[][]{
                {Float.MIN_VALUE * 3, Float.MIN_VALUE * 4, Float.MIN_VALUE * 5},
                {0.000003, 0.000004, 0.000005}
        };
    }
    @Test(dataProvider = "smallData")
    public void testCheckTriangleSmallData(double a, double b, double c) throws Exception {
        assertTrue(TriangleValidator.checkIsExist(a, b, c));
    }


    @DataProvider
    public Object[][] mediumData() {
        return new Object[][]{
                {Float.MAX_VALUE, Float.MAX_VALUE - 15, Float.MAX_VALUE - 1},
                {Double.MAX_VALUE/2, Double.MAX_VALUE / 3, Double.MAX_VALUE/3}
        };
    }
    @Test(dataProvider = "mediumData")
    public void testCheckTriangleMediumData(double a, double b, double c) throws Exception {
        assertTrue(TriangleValidator.checkIsExist(a, b, c));
    }

    @DataProvider
    public Object[][] bigData() {
        return new Object[][]{
                {Double.MAX_VALUE, Double.MAX_VALUE - 15, Double.MAX_VALUE - 1},
                {Double.MAX_VALUE + 100, Double.MAX_VALUE / 2, Double.MAX_VALUE + 18}
        };
    }
    @Test(dataProvider = "bigData",
            expectedExceptions = Exception.class)
    public void testCheckTriangleBigData(double a, double b, double c) throws Exception {
        TriangleValidator.checkIsExist(a, b, c);
    }

    @DataProvider
    public Object[][] NanData() {
        return new Object[][]{
                {Double.NaN * 3,Double.NaN * 3, Double.NaN * 5 },
                {Float.NaN, 0, 1},
                {Float.NaN, 3, 5},
                {Double.NaN, Float.NaN, 5},
        };
    }
    @Test(dataProvider = "NanData")
    public void testCheckTriangleNanData(double a, double b, double c) throws Exception {
        assertFalse(TriangleValidator.checkIsExist(a, b, c));
    }
}