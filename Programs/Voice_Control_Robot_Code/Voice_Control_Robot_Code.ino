

#include <ESP8266WiFi.h>
#include <WiFiClient.h>

WiFiClient client;
WiFiServer server(80);
const char* ssid = "NANI'S HOTSPOT";
const char* password = "nani1111";
String  command =""; // Command received from Android device

// Set Motor Control Pins
int rightMotor2 = D0;    // D7 - right Motor -
int rightMotor1 = D1;    // D8 - right Motor +
int leftMotor2 = D2;    // D3 - left Motor - 
int leftMotor1 = D3;    // D4 - left Motor +


void setup()
{
  Serial.begin(9600);


  pinMode(leftMotor1, OUTPUT); 
  pinMode(leftMotor2, OUTPUT);  
  pinMode(rightMotor1, OUTPUT);  
  pinMode(rightMotor2, OUTPUT);  

  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,LOW);
      
  connectWiFi();
  server.begin();
}

void loop()
{
    client = server.available();
    if (!client) return; 
    command = checkClient ();

         if (command == "forward" || command == "frente" || command == "a frente")  forwardMotor();
    else if (command == "reverse" || command == "reverso"|| command == "voltar") reverseMotor();
    else if (command == "left"    || command == "esquerda") leftMotor();    
    else if (command == "right"   || command == "direita") rightMotor();     
    else if (command == "stop"    || command == "pare" || command == "parar" || command == "parando")     stopMotor();     
     
    sendBackEcho(command); // send command echo back to android device
    command = "";   
} 

/* command motor forward */
void forwardMotor(void)   
{
    
  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
}

/* command motor backward */
void reverseMotor(void)   
{

  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,HIGH);
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,HIGH);
}

/* command motor turn left */
void leftMotor(void)   
{


  digitalWrite(leftMotor1,HIGH);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,HIGH);
}

/* command motor turn right */
void rightMotor(void)   
{

  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,HIGH);
  digitalWrite(rightMotor1,HIGH);
  digitalWrite(rightMotor2,LOW);
}

/* command motor stop */
void stopMotor(void)   
{

  digitalWrite(leftMotor1,LOW);
  digitalWrite(leftMotor2,LOW);
  digitalWrite(rightMotor1,LOW);
  digitalWrite(rightMotor2,LOW);
}

/* connecting WiFi */
void connectWiFi()
{
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("NodeMCU Local IP is : ");
  Serial.print((WiFi.localIP()));
}

/* check command received from Android Device */
String checkClient (void)
{
  while(!client.available()) delay(1); 
  String request = client.readStringUntil('\r');
  request.remove(0, 5);
  request.remove(request.length()-9,9);
  return request;
}

/* send command echo back to android device */
void sendBackEcho(String echo)
{
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println(echo);
  client.println("</html>");
  client.stop();
  delay(1);
}
