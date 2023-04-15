void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(11,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int a=0,b=0;
a=analogRead(A0);
b=map(a,0,1023,0,255);
Serial.println(b);
  // put your main code here, to run repeatedly:
Serial.println("Enter 0 or 1");
int user=Serial.parseInt();
if(user==0){
analogWrite(A1,HIGH);
analogWrite(A0,LOW);
while(user==0)
{
  analogWrite(11,b);
  user=Serial.parseInt();
}
}
else if(user==1){
  analogWrite(A0,HIGH);
  analogWrite(A1,LOW);
  while(user==1)
{
  analogWrite(11,b);
  user=Serial.parseInt();
}
}



}
