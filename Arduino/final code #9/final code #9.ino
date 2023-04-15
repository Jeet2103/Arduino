/*ARDUINO CODE FOR INTELLICAR.*/

// predefining TCS3200 RGB colour Sensor pins
#define S0 4 
#define S1 3
#define S2 6
#define S3 5
#define sensorOut 7

//Including libraries required for running I2C based 16x2 LCD module
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {

  //Initializing the LCD module
  lcd.init();
  lcd.backlight();

  //Initializing output pins to send signal to the motor drivers
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(50, OUTPUT);
  pinMode(51, OUTPUT);

  //Initializing trig and echo pin for HC-SR04 Ultrasonic module
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);

  //Initializing input pins from KY-032 infrared modules
  pinMode(8, INPUT);
  pinMode(9, INPUT);

  //Initializing output and input pins for Colour Sensor Module
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting RGB colour sensor frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  //initializing the serial monitor with 9600 baud rate
  Serial.begin(9600);
}


/*void moveRobot is a motor driver function that accepts a string parameter
 and then sends a particular sequence of signals to the two L293d motor
 driver module input pins to execute a desired motion*/

void moveRobot(String motion) {
  //seq of signals for moving robot left
  if (motion == "LEFT") {
    digitalWrite(44, HIGH);
    digitalWrite(45, LOW);
    digitalWrite(46, HIGH);
    digitalWrite(47, LOW);
    digitalWrite(48, HIGH);
    digitalWrite(49, LOW);
    digitalWrite(50, HIGH);
    digitalWrite(51, LOW);
    Serial.println("LEFT");
  }
  //seq of signals for moving robot right
  if (motion == "RIGHT") {
    digitalWrite(44, LOW);
    digitalWrite(45, HIGH);
    digitalWrite(46, LOW);
    digitalWrite(47, HIGH);
    digitalWrite(48, LOW);
    digitalWrite(49, HIGH);
    digitalWrite(50, LOW);
    digitalWrite(51, HIGH);
    Serial.println("RIGHT");
  }
  //seq of signals for moving robot forward
  if (motion == "FORWARD") {
    digitalWrite(44, HIGH);
    digitalWrite(45, LOW);
    digitalWrite(46, HIGH);
    digitalWrite(47, LOW);
    digitalWrite(48, LOW);
    digitalWrite(49, HIGH);
    digitalWrite(50, LOW);
    digitalWrite(51, HIGH);
    Serial.println("FORWARD");
  }
  //seq of signals for stopping robot
  if (motion == "STOP") {
    digitalWrite(44, LOW);
    digitalWrite(45, LOW);
    digitalWrite(46, LOW);
    digitalWrite(47, LOW);
    digitalWrite(48, LOW);
    digitalWrite(49, LOW);
    digitalWrite(50, LOW);
    digitalWrite(51, LOW);
    Serial.println("STOP");
  }
}


/*int Sonar function detects the distance between itself
and an obstacle in front of it and returns the distance in cm
when called in the void loop function */
int Sonar(int trigpin, int echopin) {
  int distance, duration;
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration * 0.034) / 2;
  return (distance);
}


/*int signal function operates the colour sensor by reading the 
values from red and green filtered photodiodes. If this function
detects a red light, it returns 0 and on detecting a green light 
it returns 1. */
int signal() {

  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  // Reading the output frequency
  int Rfrequency = pulseIn(sensorOut, LOW);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  // Reading the output frequency
  int Gfrequency = pulseIn(sensorOut, LOW);

  if ((Rfrequency < Gfrequency) && Rfrequency < 20)  //light is red
    return 0;
  else  //light is green
    return 1;
}


void loop() {
  int left_ir;
  int right_ir;
  int sonar_mid = Sonar(11, 12);
  if (!(signal())) //This if statement checks if the signal is red
   {
    Serial.println("RED SIGNAL!");
    moveRobot("STOP"); //Robot stops upon encountering a red signal
    lcd.setCursor(0, 0);
    lcd.print("RED SIGNAL!");
    lcd.setCursor(0, 1);
    lcd.print("CAR HAS STOPPED"); //LCD displays the given text
    delay(200);
    lcd.clear();
    } 
  else
    {

    if (Sonar(11, 12) > 15) //if the signal is not red, then the robot checks for obstacles in front of it
      {
      left_ir = digitalRead(9);//reading the value from left ir sensor
      right_ir = digitalRead(8);//reading the value from right ir sensor
      Serial.print(left_ir);
      Serial.print(" ");
      Serial.print(right_ir);
      Serial.println(" ");

if ((left_ir == 1) && (right_ir == 1)) /*if the signal is not red and there's no  obstacles, the robot starts moving forward*/
       {
        lcd.clear();
        moveRobot("FORWARD"); //robot moving forward
        lcd.setCursor(3, 0);
        lcd.print("CAR IS MOVING");
        delay(100);
      } else if (left_ir == 0) //if left ir sensor detects white border
          moveRobot("RIGHT"); //robot moves right
       else if (right_ir == 0) //if right ir sensor detects white border
          moveRobot("LEFT"); //robot moves left
      
    } 
    else //when there is an obstacle within 15 centimetres of the robot
    {
      lcd.setCursor(0, 0);
      lcd.print("OBSTACLE AHEAD");
      lcd.setCursor(0, 1);
      lcd.print("Car is Honking"); 
      moveRobot("STOP"); //the robot stops
      tone(13, 10); //and plays a repetitive honking sound in the buzzer
      delay(500);
      noTone(13);
      delay(500);
    }
  }
}

