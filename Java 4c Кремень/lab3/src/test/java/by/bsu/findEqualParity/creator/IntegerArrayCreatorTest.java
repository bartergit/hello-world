package by.bsu.findEqualParity.creator;

import org.testng.annotations.Test;

import static org.testng.Assert.assertEquals;

@Test
public class IntegerArrayCreatorTest {
    @Test
    public void testCreateFromString(){
        String[] array = new String[]{"5","9","-18"};
        IntegerArrayCreator creator = new IntegerArrayCreator();
        Integer[] actual = creator.createFromString(array);
        assertEquals(actual,new Integer[]{5,9,-18});
        array = new String[]{};
        actual = creator.createFromString(array);
        assertEquals(actual,new Integer[]{});
    }
    @Test
    public void testCreateFromEmptyString(){
        String[] array = new String[]{};
        IntegerArrayCreator creator = new IntegerArrayCreator();
        Integer[] actual = creator.createFromString(array);
        assertEquals(actual,new Integer[]{});
    }
    @Test
    public void testCreateRandom(){
        IntegerArrayCreator creator = new IntegerArrayCreator();
        Integer[] array = creator.createRandom(5);
        for (int i = 0; i < 5; i++){
            array[i] = 0;
        }
        assertEquals(array.length,5);
    }

}