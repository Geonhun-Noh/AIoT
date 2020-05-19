void setup() {

// 아날로그는 pin번호 지정 안해줘도 된다.
Serial.begin(9600);
}

void loop() {
  int Adc = analogRead(A0);
  Serial.print("ADC = ");
  Serial.println(Adc);
  analogWrite(D4,Adc);
 
}
