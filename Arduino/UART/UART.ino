
#include <SoftwareSerial.h>

SoftwareSerial mySerial(D5, D6); // RX, TX

void setup() {
  pinMode(D0,OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);  // PC - NODEMCU
  mySerial.println("Hello, world?");  //NODE - NODE
}

void loop() { // run over and over
  
  if (mySerial.available()) { // 상대편 시리얼로부터 데이터가 왔는지 여부
   char AA = mySerial.read();
   Serial.print(AA);
   if (AA == 'a'){
        digitalWrite(D0,LOW);
        mySerial.print("COFFEE\n"); }
   if (AA == 'b'){
        digitalWrite(D0, HIGH);
        mySerial.print("MILK\n"); }
    
  }
  if (Serial.available()) {             // 내가 입력한 데이터가 있는지 여부
    char BB = Serial.read();
    Serial.print(BB);
    mySerial.print(BB); }
  }
