#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
char auth[] = "70edd107bcb34973ab2714648d086f6c"; //Blynk üzerinden gönderilen auth kodu girilicek.
char ssid[] = "helloworld"; // SSID girilecek
char pass[] = "*********"; //Buraya password girilecek
WidgetTerminal terminal(V1); // Terminal widgetının v1' e bağlı olduğunu gösteriyoruz.
LiquidCrystal lcd(0,5,14,12,13,15); //(rs,e,d4,d5,d6,d7)
BLYNK_WRITE(V1) 
{
  String x = param.asStr();    //param.asStr() Blynk'e ait bir koddur terminalden yazılan textin ne olduğunu atayabilmemizi sağlar . 
  lcd.print(x);
}
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2); //(sütun,satır)
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

}
