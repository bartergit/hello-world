package by.bsu.prj.controller;

import by.bsu.prj.data.Constant;
import by.bsu.prj.mailManipulation.MailFormer;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


@WebServlet(name = "SendMail", urlPatterns = {"/send"})
public class SendMail extends HttpServlet {
    private static final Logger log = LogManager.getLogger(SendMail.class.getName());

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            MailFormer mf = new MailFormer(Constant.USERNAME, Constant.PASSWORD);
            String toEmail = request.getParameter("toEmail");
            String subject = request.getParameter("subject");
            String textMessage = request.getParameter("textMessage");
//            System.out.println(textMessage);
            mf.send(toEmail, subject, textMessage);
            request.setAttribute("mes", "OK");
        } catch (Exception ex) {
            log.error(ex);
            String mes = "Check input data is correct";
            request.setAttribute("mes", mes);
        }
        request.getRequestDispatcher("index.jsp").forward(request, response);
    }
}

