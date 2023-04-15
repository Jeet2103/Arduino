int i,ledpin=11 ;
void setup() {
  // put your setup code here, to run once:
pinMode(ledpin,OUTPUT);
pinMode(10,OUTPUT);
pinMode(12,OUTPUT);
digitalWrite(12,LOW);
pinMode(9,OUTPUT);
pinMode(8,OUTPUT);
digitalWrite(8,LOW);
pinMode(6,OUTPUT);
pinMode(4,OUTPUT);
digitalWrite(4,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
for(i=0;i<=255;i+=5)
{
analogWrite(ledpin,i);
delay(15);
analogWrite(10,i);
delay(5);
analogWrite(9,i);
delay(5);
analogWrite(6,i);
delay(5);
}
// delay(1000);
for(i=255;i>=0;i--)
{
analogWrite(ledpin,i);
delay(5);
analogWrite(10,i);
delay(5);
analogWrite(9,i);
delay(5);
analogWrite(6,i);
delay(5);
}
delay(1000);
}
