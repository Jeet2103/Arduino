char val;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  val = Serial.read();
  Serial.println(val);
  
  if (val == "A") {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    
    Serial.println("FORWARD");
  }
  else if (val == "B") {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    
    Serial.println("BACKWARD");
  }
  else if (val == "D") {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    
    Serial.println("LEFT");
  }
  else if (val == 'C') {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    
    Serial.println("RIGHT");
  }
  else if (val=='T') {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    
    Serial.println("STOP");
  }
}
}

