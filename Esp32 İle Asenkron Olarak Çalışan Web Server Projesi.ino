#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>


const char* ssid = "Ag Adi";
const char* password = "Ag Parolasi";

const int led = 2;

const char index_html[] PROGMEM = R"rawliteral(<!DOCTYPE Html>

<head>
    <meta charset="utf-8">
    <title> Web Sayfasi </title>
    <style>
        body {
            margin: 0;
            text-align: center;
        }
        
        button {
            width: 200px;
            height: 100px;
            border-radius: 3px;
        }
    </style>
</head>

<body>
    <h2>Esp32 İle Asenkron Web Server</h2>
    <br>
    <button style="background-color: #77d772;" id="ac" onclick="myfunction('ac')"><b>Aç</b></button>
    <button style="background-color: red;" id="kapat" onclick="myfunction('kapat')"><b>Kapat</b></button>
    <h4>Led Durum:
        <h4 id="leddurum">Led Kapalı</h4>
    </h4>
    <script>
        function myfunction(value) {
            var xhr = new XMLHttpRequest();
            if (value == 'ac') {
                document.getElementById("leddurum").innerHTML = "Led Açık";
                xhr.open("GET", "/ac", true);
                xhr.send();
            } else {
                document.getElementById("leddurum").innerHTML = "Led Kapalı";
                xhr.open("GET", "/kapat", true);
                xhr.send();
            }
        }
    </script>
</body>

</Html>)rawliteral";



void notFound(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Sayfa Bulunamdadi");
}

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Wifi agina Baglanmadi!");
    return;
  }
  Serial.println();
  Serial.print("ESP IP Address: http://");
  Serial.println(WiFi.localIP());
  
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html);
  });

  
  server.on("/ac", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(output, HIGH);
    request->send(200, "text/plain", "ac sinyali gonderildi.");
  });

  
  server.on("/kapat", HTTP_GET, [] (AsyncWebServerRequest *request) {
    digitalWrite(output, LOW);
    request->send(200, "text/plain", "kapat sinyali gönderildi.");
  });
  
  server.onNotFound(notFound);
  server.begin();
}

void loop() {
 
}
