package by.bsu.findEqualParity.filter;


import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;

@Test
public class FilterTest {
    @Test
    public void testFilterInt(){
        String[] array = new String[]{"1","5,1", "0", "add", "5.1", "67", "-97"};
        Filter f = new Filter();
        String[] actual = f.filterInt(array);
        assertEquals(actual,new String[]{"1","0","67","-97"});
    }
}