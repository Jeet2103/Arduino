void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
pinMode(5,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int value;
value = digitalRead(5);
Serial.print(value);
delay(500);
Serial.println(" ");
if(value==1)
{
  digitalWrite(11,HIGH);
}
else
{
  digitalWrite(11,LOW);
}
}
