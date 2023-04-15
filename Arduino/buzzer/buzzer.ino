void setup() {
  // put your setup code here, to run once:
pinMode(12,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
// tone(12,450);
// delay(100);
// noTone(12);
// delay(100);
// tone(12,450);
// delay(500);
// noTone(12);
// delay(500);
for(int i=1;i<50;i++)
{

  tone(12,450);
  delay(i);
  noTone(12);
  delay(i);
}
for(int i=50;i>1;i--)
{

  tone(12,450);
  delay(i);
  noTone(12);
  delay(i);
}
}
