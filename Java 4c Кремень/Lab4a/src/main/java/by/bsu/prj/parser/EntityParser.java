package by.ignot.lab4a.parser;

import by.ignot.lab4a.entity.Continent;
import by.ignot.lab4a.entity.Island;
import by.ignot.lab4a.entity.Ocean;

import java.util.LinkedList;

public class EntityParser {
    public static LinkedList<Island> parseIslands(LinkedList<String> islandStrings){
        LinkedList<Island> islands = new LinkedList<>();

        for(String islandInfo: islandStrings){
            String[] islandFields = islandInfo.split(",");
            try{
                String name = islandFields[0];
                double area = Double.parseDouble(islandFields[1]);
                int highestPoint = Integer.parseInt(islandFields[2]);
                islands.add(new Island(name, area, highestPoint));
            } catch (NumberFormatException e){
                e.printStackTrace();
            }
        }
        return islands;
    }

    public static LinkedList<Continent> parseContinents(LinkedList<String> continentStrings){
        LinkedList<Continent> continents = new LinkedList<>();

        for(String continentInfo: continentStrings){
            String[] continentFields = continentInfo.split(",");
            try{
                String name = continentFields[0];
                double area = Double.parseDouble(continentFields[1]);
                int highestPoint = Integer.parseInt(continentFields[2]);
                continents.add(new Continent(name, area, highestPoint));
            } catch (NumberFormatException e){
                e.printStackTrace();
            }
        }
        return continents;
    }

    public static LinkedList<Ocean> parseOceans(LinkedList<String> oceanStrings){
        LinkedList<Ocean> oceans = new LinkedList<>();

        for(String oceanInfo: oceanStrings){
            String[] oceanFields = oceanInfo.split(",");
            try{
                String name = oceanFields[0];
                double area = Double.parseDouble(oceanFields[1]);
                int avgDepth = Integer.parseInt(oceanFields[2]);
                oceans.add(new Ocean(name, area, avgDepth));
            } catch (NumberFormatException e){
                e.printStackTrace();
            }
        }
        return oceans;
    }
}
