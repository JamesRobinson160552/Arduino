int brightButton = A0;
int dimButton = A5;
int brightRead;
int dimRead;
int ledPin = 5;
int ledBright = 0;
int dimButtonOld = 0;
int brightButtonOld = 0;
int pause = 100;
int ledChange = 50;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);
pinMode(brightButton,INPUT);
pinMode(dimButton,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
brightRead = digitalRead(brightButton);
dimRead = digitalRead(dimButton);
Serial.println(ledBright);

if (brightButtonOld == 0 && brightRead == 1 && ledBright < 250){
  ledBright = ledBright + ledChange;
}
if(dimButtonOld == 0 and dimRead == 1 and ledBright > 0){
  ledBright = ledBright - ledChange;
}

while(brightRead == 0 && ledBright < 250){
    ledBright = ledBright + 5;
    analogWrite(ledPin,ledBright);
    Serial.println(ledBright);
    delay(100);
  brightRead = digitalRead(brightButton);
}

while(dimRead == 0 && ledBright > 0){
    ledBright = ledBright - 5;
    Serial.println(ledBright);
    analogWrite(ledPin,ledBright);
    delay(100);
    dimRead = digitalRead(dimButton);
  }

brightButtonOld = digitalRead(brightButton);
dimButtonOld = digitalRead(dimButton);
Serial.println(ledBright);
analogWrite(ledPin, ledBright);
delay(pause);

}
