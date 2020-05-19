
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#include "DHT.h"
#define DHTPIN D7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

char auth[] = "9124dbbec39d4d849a5b802cf98b48de";
char ssid[] = "Geon hoon의 iPhone";
char pass[] = "mister7260";



void setup()
{
  pinMode(D0,OUTPUT); // 초록 전구 포트 설정
  pinMode(D1,OUTPUT); // 빨간 전구 포트 설정
  
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  }

void loop()
{
  delay(5000);
  float Temp = dht.readTemperature();
  float Hum  = dht.readHumidity();

  Serial.println(" ");
  Serial.println("Industrial Distribution Geonhun");
  Serial.print("Temp = ");
  Serial.print(Temp);
  Serial.print("[C]");
  Serial.print("  Hum = ");
  Serial.print(Hum);
  Serial.println("%");
  
  Blynk.run();
  Blynk.virtualWrite(V0,Temp);
  Blynk.virtualWrite(V1,Hum);

  if(Temp<=26 && Temp>=22 && Hum>=40 && Hum<=70){ //온도가 22~26, 습도가 40%~70%일때 초록불
    digitalWrite(D0,HIGH);
    digitalWrite(D1,LOW);
  }
  else { //온도 또는 습도가 적정하지 않을 때 빨간불
    digitalWrite(D0,LOW);
    digitalWrite(D1,HIGH);
  }
  
}
