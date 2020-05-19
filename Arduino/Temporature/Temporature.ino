void setup() {
Serial.begin(9600);

}

void loop() {
  int Adc = analogRead(A0);
  float MV = (Adc/1024)*3000; 
  float Temp = MV;
  Serial.print("Temp = ");
  Serial.print(Temp,1);
  Serial.println("[c]");
  delay(500);
}
