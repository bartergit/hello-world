package by.bsu.prj.entity;

import java.lang.reflect.*;
import java.util.Arrays;
import java.util.List;

public class Flower{
    private int id;
    private String name;
    private String soil;
    private String origin;
    private String multiplying;
    private List<String> visualParameters;
    private List<String> growingTips;

    public Flower(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public Flower(int id, String name, String soil, String origin, List<String> visualParameters, List<String> growingTips, String multiplying) {
        this.id = id;
        this.name = name;
        this.soil = soil;
        this.origin = origin;
        this.multiplying = multiplying;
        this.visualParameters = visualParameters;
        this.growingTips = growingTips;
    }

    public String generateTableHtml() throws IllegalAccessException {
        StringBuilder sb = new StringBuilder();
        Field[] fields = this.getClass().getDeclaredFields();
        sb.append("<tr>");
        for (Field field: fields) {
            sb.append("<td>");
            try {
                List<String> list = (List<String>) field.get(this);
                sb.append("<ul>");
                for (String item: list) {
                    sb.append("<li>").append(item).append("</li>");
                }
                sb.append("</ul>");
            }
            catch (Exception ex){
                sb.append(field.get(this));
            }
            sb.append("</td>");
        }
        sb.append("</tr>");
        return sb.toString();
    }

        public static String generateHeaderHtml(){
        StringBuilder sb = new StringBuilder();
        Field[] fields = Flower.class.getDeclaredFields();
        sb.append("<tr>");
        for (Field field: fields) {
            sb.append("<th>").append(field.getName()).append("</th>");
        }
        sb.append("</tr>");
        return sb.toString();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSoil() {
        return soil;
    }

    public void setSoil(String soil) {
        this.soil = soil;
    }

    public String getOrigin() {
        return origin;
    }

    public void setOrigin(String origin) {
        this.origin = origin;
    }

    public List<String> getVisualParameters() {
        return visualParameters;
    }

    public void setVisualParameters(List<String> visualParameters) {
        this.visualParameters = visualParameters;
    }

    public List<String> getGrowingTips() {
        return growingTips;
    }

    public void setGrowingTips(List<String> growingTips) {
        this.growingTips = growingTips;
    }

    public String getMultiplying() {
        return multiplying;
    }

    public void setMultiplying(String multiplying) {
        this.multiplying = multiplying;
    }
}
