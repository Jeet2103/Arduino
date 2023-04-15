#define S0 4
#define S1 3
#define S2 6
#define S3 5
#define sensorOut 7

int Rfrequency = 0,Gfrequency=0,Bfrequency=0,frequency=0;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13,HIGH);
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

void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  Rfrequency = pulseIn(sensorOut, LOW);
  //Rfrequency = map(frequency,70,300,1000,0);

 

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  Gfrequency = pulseIn(sensorOut, LOW);
  //Gfrequency = map(frequency,70,300,1000,0);

  

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  Bfrequency = map(frequency,70,250,1000,0);

  Serial.print("RED ");
  Serial.print(Rfrequency);
  Serial.print("    GREEN ");
  Serial.print(Gfrequency);
  Serial.println();
  delay(200);

 
}