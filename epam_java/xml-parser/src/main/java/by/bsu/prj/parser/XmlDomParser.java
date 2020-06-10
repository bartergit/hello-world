package by.bsu.prj.parser;

import by.bsu.prj.controller.Controller;
import by.bsu.prj.entity.Flower;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class XmlDomParser {
    private static final Logger log = LogManager.getLogger(Controller.class.getName());
    public List<Flower> parseFlower(String pathname) throws ParserConfigurationException, IOException, SAXException {
        List<Flower> flowerList = new ArrayList<>();
        File inputFile = new File(pathname);
        DocumentBuilderFactory dbFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = dBuilder.parse(inputFile);
        doc.getDocumentElement().normalize();
        String root = doc.getDocumentElement().getNodeName();
        NodeList nodeList = doc.getElementsByTagName("plant");
        for (int i = 0; i < nodeList.getLength(); i++) {
            try {
                Node node = nodeList.item(i);
                //                System.out.println("\nCurrent Element :" + node.getNodeName());
                if (node.getNodeType() == Node.ELEMENT_NODE) {
                    Element element = (Element) node;
                    String name = element.getElementsByTagName("name").item(0).getTextContent();
                    int id = Integer.parseInt(element.getAttribute("id"));
                    String soil = element.getElementsByTagName("soil").item(0).getTextContent();
                    String origin = element.getElementsByTagName("origin").item(0).getTextContent();
                    NodeList growingTipsNodeList = element.getElementsByTagName("growing-tips").item(0).getChildNodes();
                    String multiplying = element.getElementsByTagName("multiplying").item(0).getTextContent();
                    List<String> growingTips = new ArrayList<>();
                    for (int j = 0; j < growingTipsNodeList.getLength(); j++) {
                        Node tip = growingTipsNodeList.item(j);
                        if (tip.getNodeType() == Node.ELEMENT_NODE) {
                            growingTips.add(tip.getTextContent());
                        }
                    }
                    NodeList visualParametersNodeList = element.getElementsByTagName("visual-parameters").item(0).getChildNodes();
                    List<String> visualParameters = new ArrayList<>();
                    for (int j = 0; j < visualParametersNodeList.getLength(); j++) {
                        Node tip = visualParametersNodeList.item(j);
                        if (tip.getNodeType() == Node.ELEMENT_NODE) {
                            visualParameters.add(tip.getTextContent());
                        }
                    }
                    flowerList.add(new Flower(id, name, soil, origin, visualParameters, growingTips, multiplying));
                }
            } catch (Exception ex) {
                log.debug(ex.getMessage());
            }
        }
        return flowerList;
    }

    public static void main(String[] args) {
        XmlDomParser xmlDomParser = new XmlDomParser();
        try {
            List<Flower> flowerList = xmlDomParser.parseFlower("src/main/resources/input.xml");
            for (Flower flower : flowerList) {
                System.out.println(flower.generateTableHtml());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
