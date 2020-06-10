<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <meta charset="utf-8">
        <title>Lab2</title>
    </head>

    <body>
    <form>
        <input type="number" name="num1">
        <input type="number" name="num2">
        <input type="submit">
    </form>
    <p><%
        try{
            int sum = (int)request.getAttribute("sum");
            out.println("Your sum is " + Integer.valueOf(sum));
        }
        catch (Exception e){
            out.println("Your sum is...");
        }
    %></p>
    </body>
</html>
