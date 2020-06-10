<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <meta charset="utf-8">
        <title>Lab2</title>
    </head>

    <body>
    <table border="3"><%
        try{
            String table = (String) request.getAttribute("table");
            out.println(table);
        }
        catch (Exception e){
            out.println("Your sum is...");
        }
    %></table>
    </body>
</html>
