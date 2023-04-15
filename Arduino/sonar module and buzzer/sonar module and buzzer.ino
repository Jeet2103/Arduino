int buzzer = 12 , trigpin=A1,echopin=A3,distance,duration;
void setup() {
  // put your setup code here, to run once:
  pinMode(trigpin,OUTPUT);
  pinMode(buzzer,OUTPUT);
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
  digitalWrite(buzzer,HIGH);

Serial.println("buzzer ON.");
}
else
{
digitalWrite(buzzer,LOW);
Serial.print("OFF");
}
}
