void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int a = digitalRead(2);
Serial.print(a);
Serial.println(" ");
delay(1000);
}
