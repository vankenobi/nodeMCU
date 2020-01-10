#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial

char auth[] = "70edd107bcb34973ab2714648d086f6c"; //Blynk üzerinden gönderilen auth kodu girilicek.
char ssid[] = "helloworld"; // SSID girilecek
char pass[] = "**********"; //Buraya password girilecek

int ledk = 16;

WidgetTerminal terminal(V1); // Terminal widgetının v1' e bağlı olduğunu gösteriyoruz.
WidgetLED led(V0); // Led eklentisi V0'a bağlı olduğunu gösteriyoruz .

BLYNK_WRITE(V1) 
{
  String x = param.asStr();    //param.asStr() Blynk'e ait bir koddur terminalden yazılan textin ne olduğunu atayabilmemizi sağlar . 
  Serial.println(x);
  if (String("ac") == param.asStr())
  {
    digitalWrite(ledk, HIGH);
    led.on();
    Blynk.virtualWrite(V1, "ACILDI.\n"); 
  }
  else if (String("kapa") == param.asStr())
  {
    digitalWrite(ledk, LOW);
    led.off();
    Blynk.virtualWrite(V1, "KAPATILDI.\n");
  }
  else if (String("temizle") == param.asStr())
  {
    terminal.clear(); // terminali temizler.
  }
}

void setup()
{
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass);
  pinMode(ledk, OUTPUT);
}

void loop()
{
  Blynk.run();
}
