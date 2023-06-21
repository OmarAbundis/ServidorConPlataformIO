// Siempre debe de empezar con la biblioteca de Arduino.h

#include <Arduino.h>

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
// Replace with your network credentials
const char* ssid = "*****";
const char* password = "*****";
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>ESP Web Server</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="icon" href="data:,">
<style>
html {
font-family: Arial;
text-align: center;
}
body {
max-width: 400px;
margin:0px auto;
}
</style>
</head>
<body>
<h1> Hola Mundo! </h1>
<p> Felicidades! <br>Este es tu primer servidor WEB en un ESP32DEVKIT.</p>
</body>
</html>
)rawliteral";

void initWiFi() {
WiFi.mode(WIFI_STA);
WiFi.begin(ssid, password);
Serial.print("Connecting to WiFi ..");
while (WiFi.status() != WL_CONNECTED) {
Serial.print('.');
delay(1000);
}
Serial.println(WiFi.localIP());
}

void setup() {
// Serial port for debugging purposes
Serial.begin(9600);
initWiFi();
server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
request->send(200, "text/html", index_html);
});
// Start server
server.begin();
}
void loop() {
// put your main code here, to run repeatedly:
}
