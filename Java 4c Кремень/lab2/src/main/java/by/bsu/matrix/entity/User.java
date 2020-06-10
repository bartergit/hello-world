package by.bsu.matrix.entity;

import by.bsu.matrix.exception.DateException;
import by.bsu.matrix.validator.DateValidator;

import java.util.GregorianCalendar;

/**
 * Class {@code User} keeps the data of user
 * Created 07.03.2020
 *
 * @author Pozdnyakov I.V.
 * @version 1.0
 */
public class User {
    private String name;
    private int year;
    private int month;
    private int day;
    private int hourOfDay;
    private int minute;

    /**
     * Constructor of the class
     *
     * @param name      is the name of user
     * @param year      is the year of the date of getting of the task
     * @param month     is the month of the date of getting of the task
     * @param day       is the day of the date of the task
     * @param hourOfDay is the hour Of Day of date of getting of the task
     * @param minute    is the minute of the date of getting of the task
     * @throws DateException this exception arises when the date is incorrect
     */
    public User(String name, int year, int month, int day, int hourOfDay, int minute) throws DateException {
        this.name = name;
        if (DateValidator.isValidDate(year, month, day) && DateValidator.isValidHour(hourOfDay) && DateValidator.isValidMinute(minute)) {
            this.year = year;
            this.month = month;
            this.day = day;
            this.hourOfDay = hourOfDay;
            this.minute = minute;
        } else {
            throw new DateException("Bad date in creating User");
        }
    }

    /**
     * Returns the value of the field name
     *
     * @return field value name
     */
    public String getName() {
        return name;
    }

    /**
     * Returns the time of getting task of student
     *
     * @return the time of getting task in long
     */
    public long timeGettingTask() {
        GregorianCalendar calendarGetTasks = new GregorianCalendar();
        calendarGetTasks.set(year, month, day, hourOfDay, minute);

        return calendarGetTasks.getTimeInMillis();
    }

    /**
     * Returns the time of finish task of student
     *
     * @return the time of finish task in long
     */
    public long timeFinishTask() {
        GregorianCalendar currentCalendar = new GregorianCalendar();
        return currentCalendar.getTimeInMillis();
    }
}
