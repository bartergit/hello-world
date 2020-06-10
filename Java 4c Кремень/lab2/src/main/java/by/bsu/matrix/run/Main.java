package by.bsu.matrix.run;

import by.bsu.matrix.entity.Matrix;
import by.bsu.matrix.entity.User;
import by.bsu.matrix.exception.DateException;
import by.bsu.matrix.exception.MatrixException;
import by.bsu.matrix.operation.OperationMatrix;

import java.text.SimpleDateFormat;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            System.out.println("Enter the size of the matrix:");
            Scanner scanner = new Scanner(System.in);
            while (!scanner.hasNextInt()){
                System.out.println("Bad input. Int expected");
                scanner.next();
            }
            int size = scanner.nextInt();
            Matrix matrix = new Matrix(size);
            OperationMatrix operationMatrix = new OperationMatrix();
            matrix = operationMatrix.fillRandom(matrix);
            System.out.println(matrix.toString());

            System.out.println("Transposed matrix:");
            System.out.println(operationMatrix.transpose(matrix));

            User user = new User("Pozdnyakov", 2020, 1, 28, 19, 14);
            System.out.println("Author: " + user.getName());
            System.out.print("The time of getting task: ");
            long getTaskTime = user.timeGettingTask();
            String taskStringDate = new SimpleDateFormat("d MMMMM yyyy HH:mm").format(getTaskTime);
            System.out.println(taskStringDate);

            System.out.print("The time of end of task: ");
            long currTime = user.timeFinishTask();
            String currStingTime = new SimpleDateFormat("d MMMMM yyyy HH:mm").format(currTime);
            System.out.println(currStingTime);
        } catch (DateException | MatrixException exc) {
            System.out.println(exc.getMessage());
        }
    }
}
