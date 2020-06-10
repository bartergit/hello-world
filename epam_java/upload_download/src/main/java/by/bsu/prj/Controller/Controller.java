package by.bsu.prj.Controller;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.Part;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;
import java.util.List;
import java.util.stream.Collectors;

@WebServlet(urlPatterns = {"/upload","/"})
@MultipartConfig
public class Controller extends HttpServlet {
//    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//        response.getWriter().println(request.getParameter("number"));
//    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            Part filePart = request.getPart("fileName");
            InputStream fileInputStream = filePart.getInputStream();
            File fileToSave = new File("C:\\Users\\Lenovo\\IdeaProjects\\web_app_java\\web\\img\\" + filePart.getSubmittedFileName());
            //get real path...
            Files.copy(fileInputStream, fileToSave.toPath(), StandardCopyOption.REPLACE_EXISTING);
            request.setAttribute("res", filePart.getSubmittedFileName() + " was successfully uploaded");
//            response.getOutputStream().println();

//            Desktop d = Desktop.getDesktop();
//            d.browse(new URI("http://google.com"));
        } catch (Exception e) {
            System.out.println(e.getMessage());
            request.setAttribute("res", "Something bad was happened. Pls choose the file.");
        }
        List<File> files =
                Files.walk(Paths.get("C:\\Users\\Lenovo\\IdeaProjects\\web_app_java\\web\\img\\"))
                        .filter(Files::isRegularFile)
                        .map(Path::toFile)
                        .collect(Collectors.toList());
        StringBuilder output = new StringBuilder();
        for (File file:files) {
            output.append("<a href='open?q1=");
            output.append(file.getName());
            output.append("'>");
            output.append(file.getName());
            output.append("</a>");
            output.append("<br />");
        }
        request.setAttribute("list",output.toString());
        System.out.println(output.toString());
        request.getRequestDispatcher("index.jsp").forward(request, response);
    }
}

