 int trig_mid=A0;
 int echo_mid=A1;
 int left_ir=A3;
 int right_ir=A4;

void setup() {
  pinMode(44,OUTPUT);
  pinMode(45,OUTPUT);
  pinMode(46,OUTPUT);
  pinMode(47,OUTPUT);
  pinMode(48,OUTPUT);
  pinMode(49,OUTPUT);
  pinMode(50,OUTPUT);
  pinMode(51,OUTPUT);
  pinMode(trig_mid,OUTPUT);
  pinMode(echo_mid,INPUT);
  pinMode(left_ir,INPUT);
  pinMode(right_ir,INPUT);
  Serial.begin(9600);
}
void moveRobot(String motion)
{
  if(motion=="LEFT")
  {
  digitalWrite(44,HIGH);
  digitalWrite(45,LOW);
  digitalWrite(46,HIGH);
  digitalWrite(47,LOW);
  digitalWrite(48,HIGH);
  digitalWrite(49,LOW);
  digitalWrite(50,HIGH);
  digitalWrite(51,LOW);
  Serial.println("FORWARD");
}
if(motion=="RIGHT")
  {
  digitalWrite(44,LOW);
  digitalWrite(45,HIGH);
  digitalWrite(46,LOW);
  digitalWrite(47,HIGH);
  digitalWrite(48,LOW);
  digitalWrite(49,HIGH);
  digitalWrite(50,LOW);
  digitalWrite(51,HIGH);
  Serial.println("BACKWARD");
}
if(motion=="FORWARD")
  {
  digitalWrite(44,HIGH);
  digitalWrite(45,LOW);
  digitalWrite(46,HIGH);
  digitalWrite(47,LOW);
  digitalWrite(48,LOW);
  digitalWrite(49,HIGH);
  digitalWrite(50,LOW);
  digitalWrite(51,HIGH);
  Serial.println("LEFT");
}
if(motion=="BACKWARD")
  {
  digitalWrite(44,LOW);
  digitalWrite(45,HIGH);
  digitalWrite(46,LOW);
  digitalWrite(47,HIGH);
  digitalWrite(48,HIGH);
  digitalWrite(49,LOW);
  digitalWrite(50,HIGH);
  digitalWrite(51,LOW);
  Serial.println("RIGHT");
}
if(motion=="STOP")
  {
  digitalWrite(44,LOW);
  digitalWrite(45,LOW);
  digitalWrite(46,LOW);
  digitalWrite(47,LOW);
  digitalWrite(48,LOW);
  digitalWrite(49,LOW);
  digitalWrite(50,LOW);
  digitalWrite(51,LOW);
  Serial.println("STOP");
}
}
int Sonar(int trigpin,int echopin)
{
int distance,duration;
digitalWrite(trigpin,LOW);
delay(2);
digitalWrite(trigpin,HIGH);
delay(10);
digitalWrite(trigpin,LOW);
duration = pulseIn(echopin,HIGH);
distance = (duration*0.034)/2;
Serial.print("Distance : ");
Serial.println(distance);
return(distance);
}


void loop() {
int sonar_mid=Sonar(trig_mid,echo_mid);
if(Sonar(trig_mid,echo_mid)>15)
{
  if((left_ir>400)&&(right_ir>400))
  {
    moveRobot("FORWARD");
  }
  else
  {
    moveRobot("LEFT");  
  }
}
else
{
  moveRobot("STOP");
}
}