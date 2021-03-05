#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

//SSID and Password to ESP Access Point
const char* ssid = "ESPWebServer";

ESP8266WebServer server(80); //Server on port 80

String str = "";
void handleRoot() {
  while(!Serial.available());
  String newStr = Serial.readStringUntil('\n');
  if (newStr.length() != 0) {
      str = newStr;
  }
  
  server.send(200, "text/plain", str);
}


void setup(void){
  Serial.begin(115200);
  delay(10);
  WiFi.mode(WIFI_AP);           //Only Access point
  WiFi.softAP(ssid);  //Start HOTspot

  IPAddress myIP = WiFi.softAPIP(); //Get IP address
  Serial.print("HotSpt IP:");
  Serial.println(myIP);
 
  server.on("/", handleRoot);      //Which routine to handle at root location

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();          //Handle client requests
}