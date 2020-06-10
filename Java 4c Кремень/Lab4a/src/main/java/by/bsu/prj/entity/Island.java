package by.ignot.lab4a.entity;

import java.util.Objects;

public class Island {
    private String name;
    private double area;
    private int highestPoint;

    public Island(){
        this.name = null;
        this.area = 0.0;
        this.highestPoint = 0;
    }

    public Island(String name, double area, int highestPoint){
        this.name = name;
        this.area = area;
        this.highestPoint = highestPoint;
    }

    public String getName() {
        return name;
    }

    public double getArea() {
        return area;
    }

    public int getHighestPoint(){
        return highestPoint;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Island island = (Island) o;
        return Double.compare(island.area, area) == 0 &&
                highestPoint == island.highestPoint &&
                Objects.equals(name, island.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, area, highestPoint);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Island ");
        sb.append(name).append(",");
        sb.append(" with area of ").append(area);
        sb.append(" square kilometres. Highest point is");
        sb.append(highestPoint).append(" metres\n");
        return sb.toString();
    }
}
