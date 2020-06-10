package by.bsu.prj.Controller;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;


@WebServlet(name = "Controller", urlPatterns = {""})
public class Controller extends HttpServlet {
    private static final Logger log = LogManager.getLogger(Controller.class.getName());

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String number1 = request.getParameter("num1");
        String number2 = request.getParameter("num2");
        try {
            int num1 = Integer.parseInt(number1);
            int num2 = Integer.parseInt(number2);
            int sum = num1 + num2;
            request.setAttribute("sum", sum);
            log.info("get request; set sum to " + sum);
        } catch (Exception e) {
            log.info("Hello sweetie!");
        }
        request.getRequestDispatcher("index.jsp").forward(request, response);
    }

}

