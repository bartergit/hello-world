package by.ignot.lab4a.entity;

import java.util.Objects;

public class Ocean {
    private String name;
    private double area;
    private int avgDepth;

    public Ocean(){
        this.name = null;
        this.area = 0.0;
        this.avgDepth = 0;
    }

    public Ocean(String name, double area, int avgDepth){
        this.name = name;
        this.area = area;
        this.avgDepth = avgDepth;
    }

    public String getName() {
        return name;
    }

    public double getArea() {
        return area;
    }

    public int getAvgDepth() {
        return avgDepth;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Ocean ocean = (Ocean) o;
        return Double.compare(ocean.area, area) == 0 &&
                avgDepth == ocean.avgDepth &&
                Objects.equals(name, ocean.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, area, avgDepth);
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Ocean ");
        sb.append(name).append(" with area of ");
        sb.append(area).append(" mln. square kilometres. Average depth is ");
        sb.append(avgDepth).append(" metres\n");
        return sb.toString();
    }
}
