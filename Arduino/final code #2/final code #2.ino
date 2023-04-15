 

void setup() {
  pinMode(44,OUTPUT);
  pinMode(45,OUTPUT);
  pinMode(46,OUTPUT);
  pinMode(47,OUTPUT);
  pinMode(48,OUTPUT);
  pinMode(49,OUTPUT);
  pinMode(50,OUTPUT);
  pinMode(51,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
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
  Serial.println("LEFT");
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
  Serial.println("FORWARD");
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
return(distance);
}


void loop() {
  int left_ir;
  int right_ir;
  int sonar_mid=Sonar(A0,A1);
  Serial.print(sonar_mid);
  Serial.print(" ");
  if(Sonar(A0,A1)>15)
  {
    left_ir=analogRead(A2);
    right_ir=analogRead(A3);
    Serial.print(left_ir);
    Serial.print(" ");
    Serial.print(right_ir);
    Serial.println(" ");
      if((left_ir<250)&&(right_ir<250))
      {
        moveRobot("FORWARD");
      }
      else if(left_ir>600)
      {
        moveRobot("RIGHT");  
      }
      else if(right_ir>600)
      {
        moveRobot("LEFT");  
      }
  }
  else
  {
   moveRobot("STOP");
   tone(7,10);
   delay(500);
   noTone(7);
   delay(500);
  }
  }
