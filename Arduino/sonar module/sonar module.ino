int ledpin = 12 , trigpin=A1,echopin=A3,distance,duration;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigpin,OUTPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigpin,LOW);
delay(2);
digitalWrite(trigpin,HIGH);
delay(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH);
distance = (duration*0.034)/2;
Serial.print("Distance : ");
Serial.println(distance);
delay(200);
if(distance <=50)
{
  digitalWrite(ledpin,HIGH);
Serial.println("LED ON.");
}
else
{
digitalWrite(ledpin,LOW);
Serial.print("OFF");
}
}
