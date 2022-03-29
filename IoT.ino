#include <ESP32.h> 
#include <WiFiClient.h> 
#include <PubSubClient.h> 
 
int sensorPin1 = 1;
 
 
unsigned long flow1count = 0;
unsigned long flow2count = 0;
 
#define countof(a) (sizeof(a) / sizeof(a[0]))

 
const char* ssid     = "TEST";
const char* password = "TEST";
 
 
IPAddress server(192, 168, 4, 100);
 
PubSubClient client(server);
String webString = "Flux | Water Flow Sensor with ESP8266";   
 


void callback(const MQTT::Publish& pub) 
  if(pub.payload_string().equals("flow1"))
  
    webString = "Flow 2: " + String(flow1count/450.0) + " L"; 
    client.publish("outTopic",webString);
   else if(pub.payload_string().equals("flow2"))
  
    webString = "Flow 2: " + String(flow2count/450.0) + " L";
    client.publish("outTopic",webString);               
 
       else
 
Serial.print("Flux SERVER");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
    
