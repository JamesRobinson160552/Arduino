///////////////////////////////////////////////////////////////////////
//  Author: James Robinson
//
//  Lights an led to indicate if soil has a proper moisture level
//////////////////////////////////////////////////////////////////////

//#define MOISTURE_VALUE (

int sensorPin = A0;
int redLedPin = 2;
int greenLedPin = 3;
int blueLedPin = 4;


//TODO: GET MORE PRECISE VALUES
int moistureVal;
int tooDry = 500;
int tooWet = 400;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  moistureVal = analogRead(sensorPin);
  Serial.println(moistureVal); //Sanity check
  
  if (moistureVal > tooDry) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(blueLedPin, LOW);
  } 
  
  else if (moistureVal < tooWet) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
    digitalWrite(blueLedPin, HIGH);
  }

  else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(blueLedPin, LOW);
  }
  
  delay(250);
}
