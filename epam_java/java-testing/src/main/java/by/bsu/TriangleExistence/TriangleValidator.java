package by.bsu.TriangleExistence;

public class TriangleValidator {
    public static boolean checkIsExist(double a, double b, double c) throws Exception {
        if (a > Double.MAX_VALUE / 2 || b > Double.MAX_VALUE / 2 || c == Double.MAX_VALUE / 2) {
            throw new Exception("Side are too big");
        }
        return (a + b > c && a + c > b && b + c > a);
    }
}
