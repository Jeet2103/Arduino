#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
}
void move(char m)
{
  if(m=='F')
  {
    motor1.setSpeed(255);
    motor1.run(FORWARD);
    motor2.setSpeed(255);
    motor2.run(FORWARD);
    motor3.setSpeed(255);
    motor3.run(FORWARD);
    motor4.setSpeed(255);
    motor4.run(FORWARD);
    Serial.println("FORWARD");
  }
  if(m=='B')
  {
    motor1.setSpeed(255);
    motor1.run(BACKWARD);
    motor2.setSpeed(255);
    motor2.run(BACKWARD);
    motor3.setSpeed(255);
    motor3.run(BACKWARD);
    motor4.setSpeed(255);
    motor4.run(BACKWARD);
    Serial.println("BACKWARD");
  }
  if(m=='R')
  {
    motor1.setSpeed(255);
    motor1.run(BACKWARD);
    motor2.setSpeed(255);
    motor2.run(BACKWARD);
    motor3.setSpeed(255);
    motor3.run(FORWARD);
    motor4.setSpeed(255);
    motor4.run(FORWARD);
    Serial.println("RIGHT");
  }
  if(m=='L')
  {
    motor1.setSpeed(255);
    motor1.run(FORWARD);
    motor2.setSpeed(255);
    motor2.run(FORWARD);
    motor3.setSpeed(255);
    motor3.run(BACKWARD);
    motor4.setSpeed(255);
    motor4.run(BACKWARD);
    Serial.println("LEFT");
  }
  if(m=='S')
  {
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.println("STOP");
  }

}

void loop() {
  char d='S';
while(Serial.available())
{
  d=Serial.read();
  if(d=='F')
  move('F');
  if(d=='B')
  move('B');
  if(d=='L')
  move('L');
  if(d=='R')
  move('R');
  if(d=='S')
  move('S');
}

  
}

