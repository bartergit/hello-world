package by.bsu.matrix.validator;

import org.testng.annotations.Test;

import static org.testng.Assert.assertFalse;
import static org.testng.Assert.assertTrue;

public class DateValidatorTest {

    @Test
    public void testIsDateValid() {
        assertTrue(DateValidator.isValidDate(2020, 5, 5));
        assertFalse(DateValidator.isValidDate(2005, 78, 2));

    }

    @Test
    public void testIsValidMinute() {
        assertTrue(DateValidator.isValidMinute(45));
        assertFalse(DateValidator.isValidMinute(67));
    }

    @Test
    public void testIsValidHour() {
        assertTrue(DateValidator.isValidHour(5));
        assertFalse(DateValidator.isValidHour(679));
    }
}