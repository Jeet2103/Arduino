int ledpin =12 ,ldrpin = A0,ldr_read ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  pinMode(ldrpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ldr_read = analogRead(ldrpin);
  Serial.println(ldr_read);
  //  delay(1000);
  if(ldr_read == 0)
  {
    digitalWrite(ledpin,HIGH);
    Serial.println("LED ON");
  }
  else 
  {
    digitalWrite(ledpin,LOW);
    Serial.println("..................");
  }
}
