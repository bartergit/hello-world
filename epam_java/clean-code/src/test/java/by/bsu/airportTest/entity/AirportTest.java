package by.bsu.airportTest.entity;

import by.bsu.airportTest.entity.plane.ExperimentalPlane;
import by.bsu.airportTest.entity.plane.MilitaryPlane;
import by.bsu.airportTest.entity.plane.PassengerPlane;
import by.bsu.airportTest.entity.plane.Plane;
import by.bsu.airportTest.model.ClassificationLevel;
import by.bsu.airportTest.model.ExperimentalType;
import by.bsu.airportTest.model.MilitaryType;
import org.testng.Assert;
import org.testng.annotations.BeforeTest;
import org.testng.annotations.DataProvider;
import org.testng.annotations.Test;

import java.util.Arrays;
import java.util.List;

public class AirportTest {

    private Airport airport;
    private List<Plane> planes;

    @BeforeTest
    public void createData() {
        planes = Arrays.asList(
                new PassengerPlane("Boeing-737", 900, 12000, 60500, 164),
                new PassengerPlane("Boeing-737-800", 940, 12300, 63870, 192),
                new PassengerPlane("Boeing-747", 980, 16100, 70500, 242),
                new PassengerPlane("Airbus A320", 930, 11800, 65500, 188),
                new PassengerPlane("Airbus A330", 990, 14800, 80500, 222),
                new PassengerPlane("Embraer 190", 870, 8100, 30800, 64),
                new PassengerPlane("Sukhoi Superjet 100", 870, 11500, 50500, 140),
                new PassengerPlane("Bombardier CS300", 920, 11000, 60700, 196),
                new MilitaryPlane("B-1B Lancer", 1050, 21000, 80000, MilitaryType.BOMBER),
                new MilitaryPlane("B-2 Spirit", 1030, 22000, 70000, MilitaryType.BOMBER),
                new MilitaryPlane("B-52 Stratofortress", 1000, 20000, 80000, MilitaryType.BOMBER),
                new MilitaryPlane("F-15", 1500, 12000, 10000, MilitaryType.FIGHTER),
                new MilitaryPlane("F-22", 1550, 13000, 11000, MilitaryType.FIGHTER),
                new MilitaryPlane("C-130 Hercules", 650, 5000, 110000, MilitaryType.TRANSPORT),
                new ExperimentalPlane("Bell X-14", 277, 482, 500, ExperimentalType.HIGH_ALTITUDE, ClassificationLevel.SECRET),
                new ExperimentalPlane("Ryan X-13 Vertijet", 560, 307, 500, ExperimentalType.VTOL, ClassificationLevel.TOP_SECRET)
        );
        airport = new Airport(planes);
    }

    @Test
    public void testGetTransportMilitaryPlanes() {
        Assert.assertEquals(airport.getMilitaryPlanes().get(5).getType(),MilitaryType.TRANSPORT);
    }

    @Test
    public void testGetPassengerPlaneWithMaxCapacity() {
        PassengerPlane expectedPlaneWithMaxPassengersCapacity = airport.getPassengerPlanes().get(2);
        Assert.assertEquals(expectedPlaneWithMaxPassengersCapacity, airport.getPassengerPlaneWithMaxPassengersCapacity());
    }

    @Test
    public void thirdPlaneMaxLoadCapacityIsHigherThanFirst() {
        List<? extends Plane> planesSortedByMaxLoadCapacity = airport.sortByMaxLoadCapacity().getPlanes();
        Assert.assertTrue(planesSortedByMaxLoadCapacity.get(2).getMaxLoadCapacity() > planesSortedByMaxLoadCapacity.get(0).getMaxLoadCapacity());
    }

    @Test
    public void testHasAtLeastOneBomberInMilitaryPlanes() {
        Assert.assertEquals(airport.getMilitaryPlanes().get(0).getType(),MilitaryType.BOMBER);
    }

    @DataProvider
    public Object[] experimentalPlane() {
        return new Plane[]{
                planes.get(14),
                planes.get(15)
        };
    }

    @Test(dataProvider = "experimentalPlane")
    public void testExperimentalPlanesHasClassificationLevelHigherThanUnclassified(ExperimentalPlane experimentalPlane) {
        Assert.assertNotEquals(experimentalPlane.getClassificationLevel(), ClassificationLevel.UNCLASSIFIED);
    }
}
