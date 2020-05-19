int trig = D1;
int echo = D2;


void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(D3,OUTPUT);
}

void loop() {
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  int distance=pulseIn(echo,HIGH)*17/1000;
  Serial.print(distance);
  Serial.println("cm");
  delay(100);

  if (distance<1000){
    digitalWrite(D3,HIGH);
    delay(distance);
    digitalWrite(D3,LOW);
    delay(distance);
    }
  else{
    digitalWrite(D3,LOW);
  }
  }
