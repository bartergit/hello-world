package by.bsu.prj.Controller;

import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;


@WebServlet(urlPatterns = {"*"})
public class ImgDisplay extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println(request.getParameter("q1"));
        File f = new File("C:\\Users\\Lenovo\\IdeaProjects\\web_app_java\\web\\img\\" + request.getParameter("q1"));
        DataInputStream dis = new DataInputStream(new FileInputStream(f));
        byte[] barray = new byte[(int) f.length()];
        dis.readFully(barray);           // now the array contains the image
        ServletOutputStream sos = response.getOutputStream();
        sos.write(barray);                 // send the byte array to client
        sos.close();
    }
}
