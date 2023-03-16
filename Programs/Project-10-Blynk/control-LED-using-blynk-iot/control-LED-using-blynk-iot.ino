//Arc Labs Anvesh Reddy
//Control LED Using Blynk 2.0/Blynk IOT

#define BLYNK_TEMPLATE_ID "TMPL-N0Z6Yro"
#define BLYNK_DEVICE_NAME "Esp8266 Node MCU"
#define BLYNK_AUTH_TOKEN "5PtpG0Gwq3g1g_BlnKFpbKiQLw3atl3F"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>
 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[ ] = "sss"; // Enter your Wifi Username
char pass[ ] = "act12345";  // Enter your Wifi password

int ledpin = D4;
void setup()
{     
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(ledpin,OUTPUT);
}

void loop()
{
  Blynk.run(); 
}
