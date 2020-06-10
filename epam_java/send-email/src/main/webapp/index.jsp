<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta charset="utf-8">
    <title>Lab2</title>
</head>

<body>
<form action="send">
    <p>
        <b>Receiver email</b>
        <br>
        <input type="email" name="toEmail" value="xxx@gmail.com">
    </p>
    <p>
        <b>Subject</b>
        <br>
        <input type="text" name="subject" value="Topic">
    </p>
    <p>
        <b>Text</b>
        <br>
        <textarea name="textMessage">Your text...</textarea>
    </p>
    <input type="submit">
</form>
<p><%
    String mes = (String) request.getAttribute("mes");
    if (mes != null) {
        out.println(mes);
    }
%></p>
</body>
</html>

