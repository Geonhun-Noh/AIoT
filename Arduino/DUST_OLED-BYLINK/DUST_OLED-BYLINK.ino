#include <Wire.h>  // i2c
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     0 // Reset pin # (or -1 if sharing Arduino reset pin)
#include <SoftwareSerial.h>  
SoftwareSerial mySerial(D5,D6); // Arudino Uno port RX, TX  
  
#define START_1 0x42  
#define START_2 0x4d  
#define DATA_LENGTH_H        0  
#define DATA_LENGTH_L        1  
#define PM1_0_ATMOSPHERE_H   8  
#define PM1_0_ATMOSPHERE_L   9  
#define PM2_5_ATMOSPHERE_H   10  
#define PM2_5_ATMOSPHERE_L   11  
#define PM10_ATMOSPHERE_H    12  
#define PM10_ATMOSPHERE_L    13  
#define PM2_5_PARTICLE_H   16  
#define PM2_5_PARTICLE_L   17  
#define VERSION              26  
#define ERROR_CODE           27  
#define CHECKSUM             29  
byte bytCount1 = 0;  
byte bytCount2 = 0;  
unsigned char chrRecv;  
unsigned char chrData[30];  
int PM01;  
int PM25;  
int PM10;  
  
unsigned int GetPM_Data(unsigned char chrSrc[], byte bytHigh, byte bytLow)  
{  
   return (chrSrc[bytHigh] << 8) + chrSrc[bytLow];  
}  
  
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include "DHT.h"
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#include <SoftwareSerial.h>
#include "PMS.h"


#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "9124dbbec39d4d849a5b802cf98b48de";
char ssid[] = "SEOUL_PUBLIC_GONGDEOK";
char pass[] = "";


static const unsigned PROGMEM char Humidity [] = {
0x00, 0x60, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x01, 0x08, 0x00, 0x00,
0x03, 0x04, 0x00, 0x00, 0x02, 0x06, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0x0C, 0x01, 0x00, 0x00,
0x08, 0x01, 0x00, 0x00, 0x18, 0x00, 0x80, 0x00, 0x10, 0x00, 0x80, 0xC0, 0x30, 0x00, 0x41, 0xA0,
0x28, 0x00, 0x43, 0x30, 0x28, 0x00, 0x42, 0x10, 0x28, 0x00, 0x46, 0x08, 0x28, 0x00, 0x44, 0x08,
0x2C, 0x00, 0x4C, 0x04, 0x14, 0x00, 0xC8, 0x14, 0x12, 0x00, 0x88, 0x14, 0x09, 0x81, 0x8C, 0x34,
0x04, 0x03, 0x04, 0xE8, 0x03, 0xFC, 0x46, 0x08, 0x00, 0x00, 0xE3, 0xF0, 0x00, 0x00, 0xB0, 0x00,
0x00, 0x01, 0x10, 0x00, 0x00, 0x03, 0x18, 0x00, 0x00, 0x02, 0x08, 0x00, 0x00, 0x02, 0x88, 0x00,
0x00, 0x02, 0x88, 0x00, 0x00, 0x02, 0xC8, 0x00, 0x00, 0x01, 0x18, 0x00, 0x00, 0x00, 0xF0, 0x00
};

static const unsigned PROGMEM char Temperature [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x34, 0x20, 0x00,
0x00, 0x04, 0x20, 0x00, 0x00, 0x34, 0x20, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x15, 0xA0, 0x00,
0x00, 0x15, 0xA0, 0x00, 0x00, 0x05, 0xA0, 0x00, 0x00, 0x35, 0xA0, 0x00, 0x00, 0x05, 0xA0, 0x00,
0x00, 0x05, 0xA0, 0x00, 0x00, 0x0D, 0xB0, 0x00, 0x00, 0x11, 0x98, 0x00, 0x00, 0x33, 0xC8, 0x00,
0x00, 0x27, 0xEC, 0x00, 0x00, 0x27, 0xE4, 0x00, 0x00, 0x27, 0xEC, 0x00, 0x00, 0x33, 0xE8, 0x00,
0x00, 0x19, 0x98, 0x00, 0x00, 0x0C, 0x70, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    
    for(;;); }
  
  Serial.begin(9600);
  dht.begin();
  mySerial.begin(9600);
  Blynk.begin(auth, ssid, pass);

}

void loop() {
  float Temp = dht.readTemperature();
  float Hum  = dht.readHumidity();
  delay(500);
  Serial.print("Temp = ");
  Serial.print(Temp);
  Serial.print("[C]");
  Serial.print("Hum = ");
  Serial.print(Hum);
  Serial.println("%");

  display.clearDisplay();
  display.drawBitmap(0,0,Temperature,32,32,1);
  display.setTextColor(WHITE);
  display.setTextSize(1.3);
  display.setCursor(40,12);
  display.print("Temp = ");
  display.print(Temp,1);
  display.print("[C]");

  display.drawBitmap(0,32,Humidity,32,32,1);
  display.setCursor(40,44);
  display.print("Hum =");
  display.print(Hum,1);
  display.print("%");
  
  display.display();

  if (mySerial.available())   {  
       for(int i = 0; i < 32; i++)     {  
           chrRecv = mySerial.read();  
           if (chrRecv == START_2 ) {   
              bytCount1 = 2;  
              break;  
            }  
       }   
      if (bytCount1 == 2)  
      {  
         bytCount1 = 0;  
         for(int i = 0; i < 30; i++){  
            chrData[i] = mySerial.read();  
         }   
  
         if ( (unsigned int) chrData[ERROR_CODE] == 0 ) {  
            PM01  = GetPM_Data(chrData, PM1_0_ATMOSPHERE_H, PM1_0_ATMOSPHERE_L);  
            PM25  = GetPM_Data(chrData, PM2_5_ATMOSPHERE_H, PM2_5_ATMOSPHERE_L);  
            PM10  = GetPM_Data(chrData, PM10_ATMOSPHERE_H, PM10_ATMOSPHERE_L);  
            Serial.print("PM1.0=");  
            Serial.print(PM01);  
            Serial.print(",PM2.5=");  
            Serial.print(PM25);  
            Serial.print(",PM10=");  
            Serial.println(PM10);  
            }  
         else{  
            Serial.println("PMS7003  ERROR");  
         }  
      }   
   }  
   else{  
      Serial.println("PMS7003 NOT available");  
   }  
 delay(1000);  

  Blynk.run();
  Blynk.virtualWrite(V4,PM01);
  Blynk.virtualWrite(V5,PM25);
  Blynk.virtualWrite(V6,PM10);
  



}
