package by.ignot.lab4a.entity;

import java.util.LinkedList;
import java.util.Objects;

public class Planet {
    private String name;
    private LinkedList<Island> islands = new LinkedList<Island>();
    private LinkedList<Ocean> oceans = new LinkedList<Ocean>();
    private LinkedList<Continent> continents = new LinkedList<Continent>();

    public Planet(){
        this.name = null;
        this.islands = null;
        this.oceans = null;
        this.continents = null;
    }

    public Planet(String name, LinkedList<Island> islands, LinkedList<Ocean> oceans, LinkedList<Continent> continents){
        this.name = name;
        this.islands = islands;
        this.oceans = oceans;
        this.continents = continents;
    }

    public String getName() {
        return name;
    }

    public LinkedList<String> getIslandsNames(){
        LinkedList<String> islandsNames = new LinkedList<String>();
        for (int i = 0; i < islands.size(); i++){
            islandsNames.add(islands.get(i).getName());
        }
        return islandsNames;
    }

    public LinkedList<String> getOceansNames(){
        LinkedList<String> oceansNames = new LinkedList<String>();
        for (int i = 0; i < oceans.size(); i++){
            oceansNames.add(oceans.get(i).getName());
        }
        return oceansNames;
    }


    public LinkedList<String> getContinentsNames(){
        LinkedList<String> continentsNames = new LinkedList<String>();
        for (int i = 0; i < continents.size(); i++){
            continentsNames.add(continents.get(i).getName());
        }
        return continentsNames;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Planet planet = (Planet) o;
        return Objects.equals(name, planet.name) &&
                Objects.equals(islands, planet.islands) &&
                Objects.equals(oceans, planet.oceans) &&
                Objects.equals(continents, planet.continents);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, islands, oceans, continents);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("Planet ");
        sb.append(name).append('\n');
        sb.append("Islands: ").append(getIslandsNames()).append('\n');
        sb.append("Oceans: ").append(getOceansNames()).append('\n');
        sb.append("Continents: ").append(getContinentsNames()).append('\n');
        return sb.toString();
    }
}
