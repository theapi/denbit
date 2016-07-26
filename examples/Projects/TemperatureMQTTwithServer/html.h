
const char index_html[] PROGMEM = R"=====(

<html>
<head>
<script>

var connection = new WebSocket('ws://' + location.hostname + ':81/', ['arduino']);
connection.onopen = function () {
    connection.send('Connect ' + new Date());
};
connection.onerror = function (error) {
    console.log('WebSocket Error ', error);
};
connection.onmessage = function (e) {
    console.log('Server: ', e.data);
    document.getElementById('temperature').value = e.data;
};

</script>
</head>
<body>
<input id="temperature" type="text" value="" />
</body>
</html>

)=====";

