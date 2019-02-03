#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
char auth[] = "70edd107bcb34973ab2714648d086f6c";
char ssid[] = "helloworld";
char pass[] = "KIBEmJ6i";
int ledk = 16;
WidgetTerminal terminal(V1);
WidgetLED led(V0);
BLYNK_WRITE(V1)
{
  String x = param.asStr();
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
    terminal.clear();
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
