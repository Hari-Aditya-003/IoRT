#include "DHT.h"
#define DHTPIN D1    
#define DHTTYPE DHT11 
#define BLYNK_TEMPLATE_ID "TMPLpUzXz_Gu"
#define BLYNK_DEVICE_NAME "LED"
#define BLYNK_AUTH_TOKEN "QwW0G38GLhxFROFH7F0v99H74E4Q-Xk0"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>

DHT dht(DHTPIN, DHTTYPE);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[ ] = "Redmi Note Pro Max 9"; // Enter your Wifi Username
char pass[ ] = "vibusucks";  // Enter your Wifi password

int ledpin1 = D4;
int ledpin2 = D2;
void setup()
{     
  dht.begin();
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
}

void loop()
{
  Blynk.run(); 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
  Blynk.virtualWrite(V0, hic);
  Blynk.virtualWrite(V1, f);
  Blynk.virtualWrite(V2, hif);
}
