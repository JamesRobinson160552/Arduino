int playButtonPin = A4;
int pauseButtonPin = A3;
int resetButtonPin = A2;
int potPin = A0;
int potVal;
int ledSegA = 2;
int ledSegB = 3;
int ledSegC = 4;
int ledSegD = 5;
int ledSegE = 6;
int ledSegF = 7;
int ledSegG = 8;
int ledSegDP = 9;
int buzzerPin = 11;
int f4 = 349.23;
int g4 = 392;
int gSharp4 = 415.3;
int a4 = 440;
int aSharp4 = 466.16;
int b4 = 493.88;
int c5 = 523.25;
int cSharp5 = 554.37;
int d5 = 587.33;
int dSharp5 = 622.25;
int e5 = 659.25;
int f5 = 698.46;
int fSharp5 = 739.99;
int g5 = 783.99;
int gSharp5 = 830.61;
int a5 = 880;
int aSharp5 = 932.33;
int b5 = 987.77;
int c6 = 1046.5;
int cSharp6 = 1108.73;
int d6 = 1174.66;
int dSharp6 = 1244.51;
int e6 = 1318.51;
int currentKey[8];
int keyOfF[] = {f4,g4,a4,aSharp4,c5,d5,e5,f5}; 
int keyOfG[] = {g4,a4,b4,c5,d5,e5,fSharp5,g5};
int keyOfA[] = {a4,b4,cSharp5,d5,e5,fSharp5,gSharp5,a5};
int keyOfB[] = {b4,cSharp5,dSharp5,e5,fSharp5,gSharp5,aSharp5,b5};
int keyOfC[] = {c5,d5,e5,f5,g5,a5,b5,c6};
int keyOfD[] = {d5,e5,fSharp5,g5,a5,b5,cSharp6,d6};
int keyOfE[] = {e5,fSharp5,gSharp5,a5,b5,cSharp6,dSharp6,e6}; 
int melody[7];
int noteTimes[7];
int possibleTimes[] = {300,600,1200,2400};

///////////////////////////////////////////////Fills the current key array with notes from the selected key//////////////////////////////////////
void selectKey(){
 if(analogRead(potPin)<=97){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfA[i]; 
  }
 }
 else if(analogRead(potPin)>97 && analogRead(potPin)<=194){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfB[i];
   }
  }
 else if(analogRead(potPin)>194 && analogRead(potPin)<=292){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfC[i];
   }
  }
 else if(analogRead(potPin)>292 && analogRead(potPin)<=389){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfD[i];
   }
  }
 else if(analogRead(potPin)>389 && analogRead(potPin)<=496){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfE[i];
   }
  }
 else if(analogRead(potPin)>496 && analogRead(potPin)<=584){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfF[i];
   }
  }
 else if(analogRead(potPin)>584){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfG[i];
   }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////Shows the current key on the 7 segment led display/////////////////////////////////////////////////////////////
void displayKey(){
  potVal = analogRead(potPin);
  if(potVal<=97){ //A
    digitalWrite(ledSegA,HIGH);
    digitalWrite(ledSegB,HIGH);
    digitalWrite(ledSegC,HIGH);
    digitalWrite(ledSegD,LOW);
    digitalWrite(ledSegE,HIGH);
    digitalWrite(ledSegF,HIGH);
    digitalWrite(ledSegG,HIGH);
    digitalWrite(ledSegDP,LOW);
  }
  else if(potVal>97 && potVal<=194){ //B
    digitalWrite(ledSegA,LOW);
    digitalWrite(ledSegB,LOW);
    digitalWrite(ledSegC,HIGH);
    digitalWrite(ledSegD,HIGH);
    digitalWrite(ledSegE,HIGH);
    digitalWrite(ledSegF,HIGH);
    digitalWrite(ledSegG,HIGH);
    digitalWrite(ledSegDP,LOW);
  }
  else if(potVal>194 && potVal <=292){ //C
    digitalWrite(ledSegA,HIGH);
    digitalWrite(ledSegB,LOW);
    digitalWrite(ledSegC,LOW);
    digitalWrite(ledSegD,HIGH);
    digitalWrite(ledSegE,HIGH);
    digitalWrite(ledSegF,HIGH);
    digitalWrite(ledSegG,LOW);
    digitalWrite(ledSegDP,LOW);
  }
  else if(potVal>292 && potVal<=389){ //D
    digitalWrite(ledSegA,LOW);
    digitalWrite(ledSegB,HIGH);
    digitalWrite(ledSegC,HIGH);
    digitalWrite(ledSegD,HIGH);
    digitalWrite(ledSegE,HIGH);
    digitalWrite(ledSegF,LOW);
    digitalWrite(ledSegG,HIGH);
    digitalWrite(ledSegDP,LOW);
  }
  else if(potVal>389 && potVal<=496){ //E
    digitalWrite(ledSegA,HIGH);
    digitalWrite(ledSegB,LOW);
    digitalWrite(ledSegC,LOW);
    digitalWrite(ledSegD,HIGH);
    digitalWrite(ledSegE,HIGH);
    digitalWrite(ledSegF,HIGH);
    digitalWrite(ledSegG,HIGH);
    digitalWrite(ledSegDP,LOW);
  }
  else if(potVal>496 && potVal <=584){ //F
    digitalWrite(ledSegA,HIGH);
    digitalWrite(ledSegB,LOW);
    digitalWrite(ledSegC,LOW);
    digitalWrite(ledSegD,LOW);
    digitalWrite(ledSegE,HIGH);
    digitalWrite(ledSegF,HIGH);
    digitalWrite(ledSegG,HIGH);
    digitalWrite(ledSegDP,LOW);
  }
  else if(potVal>584){ //G
    digitalWrite(ledSegA,HIGH);
    digitalWrite(ledSegB,LOW);
    digitalWrite(ledSegC,HIGH);
    digitalWrite(ledSegD,HIGH);
    digitalWrite(ledSegE,HIGH);
    digitalWrite(ledSegF,HIGH);
    digitalWrite(ledSegG,HIGH);
    digitalWrite(ledSegDP,LOW);
  }
  
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////fills an array with notes of the current key///////////////////////////////////////////////
void getMelody(){
  for(int i=0; i<8; i++){
    melody[i] = currentKey[(random(0,7))];
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////Randomly determines the duration of each note/////////////////////////////////////////////////////
void getBeats(){
  for(int i=0; i<8; i++){
    noteTimes[i] = possibleTimes[(random(0,3))];
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////plays each note n in the melody array for time t in the times array//////////////////////////////
void playMelody(){
  for(int i=0; i<8; i++){
    tone(buzzerPin, melody[i]);
    delay(noteTimes[i]);
    noTone(buzzerPin);
  }
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(playButtonPin,INPUT);
pinMode(pauseButtonPin,INPUT);
pinMode(resetButtonPin,INPUT);
pinMode(potPin,INPUT);
pinMode(ledSegA,OUTPUT);
pinMode(ledSegB,OUTPUT);
pinMode(ledSegC,OUTPUT);
pinMode(ledSegD,OUTPUT);
pinMode(ledSegE,OUTPUT);
pinMode(ledSegF,OUTPUT);
pinMode(ledSegG,OUTPUT);
pinMode(ledSegDP,OUTPUT);
pinMode(buzzerPin,OUTPUT);
randomSeed(analogRead(12));
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(playButtonPin)==1){
    selectKey();
    displayKey();
    }
  getMelody();
  getBeats();
  playMelody();
}
