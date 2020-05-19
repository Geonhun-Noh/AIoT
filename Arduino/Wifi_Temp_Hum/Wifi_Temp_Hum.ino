#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "SEOUL_PUBLIC_GONGDEOK"
#define STAPSK  ""
#endif

#include "DHT.h"
#define DHTPIN D7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = STASSID;
const char* password = STAPSK;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80); // 서버를 만들기 위함

void setup() {
  Serial.begin(115200); //디버깅을 위함
  dht.begin();
    
  // prepare LED
  pinMode(D0, OUTPUT);
  digitalWrite(D0, 0);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to "));
  Serial.println(ssid);

  WiFi.mode(WIFI_STA); //AP:자신이 IP를 나눠주는 것, ST:다른 AP에 붙는 것 공덕한테 IP를 받아온다는 의미
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) { // 와이파이가 연결될동안 점을 찍음
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  // Start the server         
  server.begin();
  Serial.println(F("Server started"));

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // Check if a client has connected
  WiFiClient client = server.available(); //클라이언트가 서버한테 붙을 수 있는지를 의미
  if (!client) {
    return;
  }
  Serial.println(F("new client"));

  client.setTimeout(5000); // default is 1000

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);

  // Match the request
  int val;
  if (req.indexOf(F("/0")) != -1) { //-1이 아니다 -> 참이다 라는 이야기
    val = 1;
  } else if (req.indexOf(F("/1")) != -1) {
    val = 0;
  } else {
    Serial.println(F("invalid request"));
    val = digitalRead(D0); //현재 상태를 체크하기 위함
  }

  // Set LED according to the request
  digitalWrite(D0, val);

  // read/ignore the rest of the request
  // do not client.flush(): it is for output only, see below
  while (client.available()) {
    // byte by byte is not very efficient
    client.read();
  }

  // Send the response to the client
  // it is OK for multiple small client.print/write,
  // because nagle algorithm will group them into one single packet
  client.print(F("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ")); //HTTP의 형식임 앞에 문장이 있어야 보낼 수 있음
  client.print(F("Temp = "));
  client.print(t);
  client.print((val) ? F("LOW") : F("HIGH")); //1이면 하이 0이면 로우
  client.print(F("<br><br>Click <a href='http://")); //하이퍼링크같은 개념
  client.print(WiFi.localIP());
  client.print(F("/1'>here</a> to switch LED GPIO on, or <a href='http://"));
  client.print(WiFi.localIP());
  client.print(F("/0'>here</a> to switch LED GPIO off.</html>"));

  // The client will actually be *flushed* then disconnected
  // when the function returns and 'client' object is destroyed (out-of-scope)
  // flush = ensure written data are received by the other side
  Serial.println(F("Disconnecting from client"));
}
