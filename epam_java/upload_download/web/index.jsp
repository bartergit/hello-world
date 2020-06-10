<html>
<head>
    <title>Index</title>
</head>
<body>
<form action="upload" method="POST" enctype="multipart/form-data">
    <p>
        Select File to Upload:
        <input type="file" name="fileName">
    </p>
    <input type="submit" value="Upload">
</form>
<form action="open" method="Get">
    <input type="submit" name="q1" value="Open">
</form>
<b>
    ${res}
</b>
<p>
${list}
</p>
</body>
</html>