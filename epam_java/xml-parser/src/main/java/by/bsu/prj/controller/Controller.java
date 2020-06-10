package by.bsu.prj.controller;

import by.bsu.prj.entity.Flower;
import by.bsu.prj.parser.XmlDomParser;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;


@WebServlet(name = "Controller", urlPatterns = {""})
public class Controller extends HttpServlet {
    private static final Logger log = LogManager.getLogger(Controller.class.getName());

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        StringBuilder tableBuilder = new StringBuilder();
        tableBuilder.append(Flower.generateHeaderHtml());
        try {
            List<Flower> flowerList = (new XmlDomParser()).parseFlower("C:/input.xml");
            for (Flower flower : flowerList) {
                tableBuilder.append(flower.generateTableHtml());
            }
        }
        catch (Exception ex){
            log.error(ex.getMessage());
        }
        request.setAttribute("table", tableBuilder.toString());
        request.getRequestDispatcher("index.jsp").forward(request,response);
    }

}

