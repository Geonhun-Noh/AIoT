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

  int Time = map(distance,0,400,0,4000);
  digitalWrite(D3,HIGH);
  delay(Time);
  digitalWrite(D3,LOW);
  delay(Time);
  
  }
