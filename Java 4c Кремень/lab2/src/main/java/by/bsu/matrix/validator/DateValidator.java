package by.bsu.matrix.validator;

import java.text.ParseException;
import java.text.SimpleDateFormat;

/**
 * Class {@code DateValidator} validates the date
 * Created 07.03.2020.
 *
 * @author Pozdnyakov I.V.
 * @version 1.0
 */
public class DateValidator {
    /**
     * Constructor of the class
     *
     * @param year  the year of the date of getting of the task
     * @param month the month of the date of getting of the task
     * @param day   the day of the date of getting of the task
     * @return {@code true} if the date is valid
     * and {@code false} if the date isn't valid.
     */
    public static boolean isValidDate(int year, int month, int day) {

        String dateStr = day + "/" + month + "/" + year;
        SimpleDateFormat sdf = new SimpleDateFormat();
        sdf.applyPattern("dd/MM/yyyy");
        sdf.setLenient(false);
        try {
            sdf.parse(dateStr);
        } catch (ParseException exc) {
            System.out.println(exc.getMessage());
            return false;
        }
        return true;
    }

    /**
     * Validation ot the minutes
     *
     * @param min minute of getting of the task
     * @return {@code true} if minute is valid
     * and {@code false} if minute isn't valid.
     */
    public static boolean isValidMinute(int min) {
        return (min > 0 && min <= 60);
    }

    /**
     * Validation ot the hours
     *
     * @param hour hour of getting of task
     * @return {@code true} if hour is valid
     * and {@code false} if hour isn't valid.
     */
    public static boolean isValidHour(int hour) {
        return (hour >= 0 && hour <= 23);
    }
}
