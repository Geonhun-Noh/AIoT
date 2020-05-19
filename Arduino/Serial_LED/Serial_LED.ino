void setup() {
  pinMode(D1, OUTPUT);
  Serial.begin(9600);
  pinMode(D2, OUTPUT);
  pinMode(D4, OUTPUT);

}

void loop() {
  char command;
  
  if (Serial.available()>0){ // PC에서 사용가능 여부를 확인 -> PC쪽에서 데이터가 왔는지
    command = Serial.read();
    if( command =='a'){
      digitalWrite(D1, HIGH);
      digitalWrite(D2, LOW);
      digitalWrite(D4, LOW);
      Serial.println("a");}
    
    if( command =='b'){
      digitalWrite(D2,HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D4, LOW);
      Serial.println("b");}

    if( command =='c'){
      digitalWrite(D4, HIGH);
      digitalWrite(D1, LOW);
      digitalWrite(D2, LOW);
      Serial.println("c");}

    if( command =='d'){
      digitalWrite(D1, HIGH);
      digitalWrite(D2, HIGH);
      digitalWrite(D4, LOW);
      Serial.println("d");}
    
    if( command =='e'){
      digitalWrite(D1, LOW);
      digitalWrite(D2, HIGH);
      digitalWrite(D4, HIGH);

    if( command =='f'){
      digitalWrite(D1, HIGH);
      digitalWrite(D2, LOW);
      digitalWrite(D4, HIGH);

    if( command =='g'){
      digitalWrite(D1, HIGH);
      digitalWrite(D2, HIGH);
      digitalWrite(D4, HIGH);
      Serial.println("d");}
      Serial.println("d");}
      Serial.println("d");}   
     }
}
