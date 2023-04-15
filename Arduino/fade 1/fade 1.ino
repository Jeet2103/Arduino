int i;
void setup() {
  // put your setup code here, to run once:
pinMode(11,OUTPUT);
// pinMode(10,OUTPUT);
// pinMode(9,OUTPUT);
// pinMode(6,OUTPUT);
// pinMode(5,OUTPUT);
// pinMode(3,OUTPUT);
// pinMode(13,OUTPUT);
// pinMode(12,OUTPUT);
// pinMode(8,OUTPUT);
// pinMode(7,OUTPUT);
// pinMode(2,OUTPUT);
// digitalWrite(13,LOW);
// digitalWrite(12,LOW);
// digitalWrite(8,LOW);
// digitalWrite(7,LOW);
// digitalWrite(2,LOW);


}

void loop() {
  // put your main code here, to run repeatedly:
for(i=0;i<=255;i++)
{
  analogWrite(11,i);
  delay(30);
  // analogWrite(10,i);
  // delay(30);
  // analogWrite(9,i);
  // delay(30);
  // analogWrite(6,i);
  // delay(30);
  // analogWrite(5,i);
  // delay(30);
  // analogWrite(3,i);
  // delay(30);
}
delay(1000);
for(i=255;i>=0;i--)
{
  analogWrite(11,i);
  delay(30);
  // analogWrite(10,i);
  // delay(30);
  // analogWrite(9,i);
  // delay(30);
  // analogWrite(6,i);
  // delay(30);
  // analogWrite(5,i);
  // delay(30);
  // analogWrite(3,i);
  // delay(30);
}
delay(1000);
}
