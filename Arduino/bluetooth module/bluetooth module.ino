char val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
  val = Serial.read();
  Serial.println(val);
  if (val == "D") {
    digitalWrite(44, HIGH);
    digitalWrite(45, LOW);
    digitalWrite(46, HIGH);
    digitalWrite(47, LOW);
    
    Serial.println("LEFT");
  }
  if (val == "C") {
    digitalWrite(44, LOW);
    digitalWrite(45, HIGH);
    digitalWrite(46, LOW);
    digitalWrite(47, HIGH);
    
    Serial.println("RIGHT");
  }
  if (val == "A") {
    digitalWrite(44, HIGH);
    digitalWrite(45, LOW);
    digitalWrite(46, HIGH);
    digitalWrite(47, LOW);
    
    Serial.println("FORWARD");
  }
  if (val == 'B') {
    digitalWrite(44, LOW);
    digitalWrite(45, HIGH);
    digitalWrite(46, LOW);
    digitalWrite(47, HIGH);
    
    Serial.println("BACKWARD");
  }
  if (val=='T') {
    digitalWrite(44, LOW);
    digitalWrite(45, LOW);
    digitalWrite(46, LOW);
    digitalWrite(47, LOW);
    
    Serial.println("STOP");
  }
}
}

