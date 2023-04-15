#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

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
  pinMode(S0, OUTPUT);  
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT); 
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW); 
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
  Serial.println("RIGHT");
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
int signal()
{
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  int Rfrequency = pulseIn(sensorOut, LOW);
  //Rfrequency = map(frequency,70,300,1000,0);

 

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  int Gfrequency = pulseIn(sensorOut, LOW);
  //Gfrequency = map(frequency,70,300,1000,0);
  if((Rfrequency<Gfrequency)&&Rfrequency<20) //light is red
    return 0;
  else //if(Rfrequency>Gfrequency)  //light is green
    return 1; 
}


void loop() {
  int left_ir;
  int right_ir;
  int sonar_mid=Sonar(A0,A1);
  Serial.print(sonar_mid);
  Serial.print(" ");
  if(!(signal()))
  {
    Serial.println("0");
    moveRobot("STOP");
  }
  else
  {
    Serial.println("1");
  if(Sonar(A0,A1)>15)
  {
    left_ir=analogRead(A2);
    right_ir=analogRead(A3);
    Serial.print(left_ir);
    Serial.print(" ");
    Serial.println(" ");
      if((left_ir<300)&&(right_ir<300))
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
   tone(14,10);
   delay(500);
   noTone(14);
   delay(500);
  }
  }
}
