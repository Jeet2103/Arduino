

#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,16,2);
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();
Serial.begin(9600);
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
    lcd.setCursor(0,0);
    lcd.print("MOVE");
    lcd.setCursor(0,1);
    lcd.print("FORWARD");
    delay(100);
    lcd.clear();
  }
  else if(m=='R')
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
    lcd.setCursor(0,0);
    lcd.print("MOVE");
    lcd.setCursor(0,1);
    lcd.print("RIGHT");
    delay(100);
    lcd.clear();
  }
  else if(m=='L')
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
    lcd.setCursor(0,0);
    lcd.print("MOVE");
    lcd.setCursor(0,1);
    lcd.print("LEFT");
    delay(100);
    lcd.clear();
  }
  else if(m=='RS')
  {
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.println("STOP");
lcd.setCursor(0,0);
lcd.print("Red signal");
lcd.setCursor(0,1);
lcd.print("Stop");
delay(100);
lcd.clear();
  }
   else if(m=='LS')
  {
  motor1.run(RELEASE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  Serial.println("STOP");
  lcd.setCursor(0,0);
  lcd.print("NO LANE");
  lcd.setCursor(0,1);
  lcd.print("Stop");
  delay(100);
  lcd.clear();
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  // lcd.clear();
  move('F');
  delay(2500);
  move('RS');
  delay(2500);
  move('L');
  delay(2500);
  move('R');
  delay(2500);
  move('LS');
  delay(2500);
}
