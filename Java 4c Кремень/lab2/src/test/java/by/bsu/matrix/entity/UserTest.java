package by.bsu.matrix.entity;

import by.bsu.matrix.exception.DateException;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import java.util.GregorianCalendar;

import static org.testng.Assert.*;

public class UserTest {

    User user;
    GregorianCalendar calendarGetTasks;

    @BeforeMethod
    public void setUp() throws DateException {
        user = new User("Ivan", 2020, 2, 25, 12, 53);
        calendarGetTasks = new GregorianCalendar();
        calendarGetTasks.set(2020, 2, 25, 12, 53);
    }

    @Test
    public void testGetName() {
        String actual = user.getName();
        String expected = "Ivan";
        assertEquals(actual, expected);
    }

    @Test
    public void testTimeGettingTask() {
        long actual = calendarGetTasks.getTimeInMillis();
        long expected = 8;
        assertNotEquals(actual, expected);
    }

}