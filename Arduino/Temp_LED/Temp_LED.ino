#include "DHT.h"
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(D0,OUTPUT); // 초록 전구
  pinMode(D1,OUTPUT); // 빨간 전구
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  delay(1000);
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
}
/*
  if(26<=Temp<=28 && 40<=Hum<=50){ //온도가 26~28, 습도가 40%~50%일때 초록불
    digitalWrite(D0,HIGH);
    digitalWrite(D1,LOW);
  }
  else { //온도 또는 습도가 적정하지 않을 때 빨간불
    digitalWrite(D0,LOW);
    digitalWrite(D1,HIGH);
  }
}
*/
