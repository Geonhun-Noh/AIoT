
#include <SoftwareSerial.h>

SoftwareSerial mySerial(D5, D6); // RX, TX


#include <Wire.h>  // i2c
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     0 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "DHT.h"
#define DHTPIN D7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);  // PC - NODEMCU
  mySerial.println("Hello, world?");  //NODE - NODE

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    
    for(;;); }
  
  Serial.begin(9600);
  dht.begin();
}

void loop() { // run over and over
  pinMode(D0,OUTPUT);
  float Temp = dht.readTemperature();
  float Hum  = dht.readHumidity();
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  
  if (mySerial.available()) { // 상대편 시리얼로부터 데이터가 왔는지 여부
   char AA = mySerial.read();
   Serial.print(AA);
   if (AA == 't'){mySerial.print(Temp); 
                  mySerial.println('C');}
   if (AA == 'h'){mySerial.print(Hum);
                  mySerial.println('%');}
   if (AA == 'a'){digitalWrite(D0,LOW);
                  mySerial.println("Turn On");}
   if (AA == 'b'){digitalWrite(D0,HIGH);
                  mySerial.println("Turn Off");}
    
   }
  if (Serial.available()) {             // 내가 입력한 데이터가 있는지 여부
    char BB = Serial.read();
    Serial.print(BB);
    mySerial.print(BB); }
  }
