char val;
void setup() {
  // put your setup code here, to run once:
pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);  
pinMode(A2,OUTPUT);
pinMode(A3,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  val = Serial.read();
 Serial.println(val);

  if (val == 'D') {
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
    
    Serial.println("LEFT");
  }
  else if (val == 'C') {
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    
    Serial.println("RIGHT");
  }
  else if (val == 'A') {
    digitalWrite(A0, HIGH);
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, LOW);
    
    Serial.println("FORWARD");
  }
  else if (val == 'B') {
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(A3, HIGH);
    
    Serial.println("BACKWARD");
  }
  else if(val =='T') {
    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    
    Serial.println("STOP");
  }
}
}