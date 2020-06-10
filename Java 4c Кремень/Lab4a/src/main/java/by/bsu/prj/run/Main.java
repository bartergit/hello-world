package java.bsu.prj.run;
public class Main {
    public static void main (String[] args){
        LinkedList<String> islandStrings;
        LinkedList<String> oceanStrings;
        LinkedList<String> continentStrings;
        try{
            islandStrings = CsvReader.readCsv("src/main/resources/islands.csv");
            oceanStrings = CsvReader.readCsv("src/main/resources/oceans.csv");
            continentStrings = CsvReader.readCsv("src/main/resources/continents.csv");

            LinkedList<Island> islands = EntityParser.parseIslands(islandStrings);
            LinkedList<Ocean> oceans = EntityParser.parseOceans(oceanStrings);
            LinkedList<Continent> continents = EntityParser.parseContinents(continentStrings);

            Planet halfEarth = new Planet("Half-Earth", islands, oceans, continents);
            Planet halfEarth2 = new Planet("Half-Earth", islands, oceans, continents);
            System.out.print(halfEarth);
            System.out.println("Amount of continents: " + halfEarth.getContinentsNames().size());
            System.out.print(halfEarth2);
            System.out.print("Comparing to half-earthes: " + halfEarth.equals(halfEarth2));

        } catch (FileReadException e){
            e.printStackTrace();
        } catch (NumberFormatException e){
            e.printStackTrace();
        }
    }
}

// Создать объект класса Планета, используя классы Материк,Океан,Остров.
// Методы: вывести на консоль название материка, планеты, количество материков