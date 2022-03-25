////////////////////////////////////////////////////////////////////////////////////////////////
//  Author: James Robinson
//
//  Allows the user to select a major key using the pot
//  Assigns the corresponding octave to the buttons
//  Plays a note while the button is pressed
///////////////////////////////////////////////////////////////////////////////////////////////

int button1Pin = A5;
int button2Pin = A4;
int button3Pin = A3;
int button4Pin = A2;
int button5Pin = A1;
int button6Pin = 3;
int button7Pin = 4;
int button8Pin = 5;
int buzzerPin = 2;
int potPin = A0;
int led1 = 7;
int led2 = 6;
int led3 = 12;
int led4 = 11;
int led5 = 10;
int led6 = 9;
int led7 = 8;
int led8 = 13;
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


///////////////////////////////////////////////Fills the current key array with notes from the selected key//////////////////////////////////////
void selectKey(){
 if(analogRead(potPin)<=146){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfF[i]; 
  }
 }
 else if(analogRead(potPin)>146 && analogRead(potPin)<=292){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfG[i];
   }
  }
 else if(analogRead(potPin)>292 && analogRead(potPin)<=438){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfA[i];
   }
  }
 else if(analogRead(potPin)>438 && analogRead(potPin)<=585){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfB[i];
   }
  }
 else if(analogRead(potPin)>585 && analogRead(potPin)<=731){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfC[i];
   }
  }
 else if(analogRead(potPin)>731 && analogRead(potPin)<=877){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfD[i];
   }
  }
 else if(analogRead(potPin)>877){
  for(int i=0;i<8;i++){
    currentKey[i] = keyOfE[i];
   }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////Displays the key currently selected///////////////////////////////////////////////////////////////
void displayKey(){
 if(analogRead(potPin)<=146){ //F
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(led7,LOW);
  digitalWrite(led8,LOW);
 }
 else if(analogRead(potPin)>146 && analogRead(potPin)<=292){ //G
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(led7,LOW);
  digitalWrite(led8,LOW);
  }
 else if(analogRead(potPin)>292 && analogRead(potPin)<=438){ //A
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(led7,HIGH);
  digitalWrite(led8,LOW);
  }
 else if(analogRead(potPin)>438 && analogRead(potPin)<=585){ //B
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,LOW);
  digitalWrite(led7,LOW);
  digitalWrite(led8,LOW);
  }  
 else if(analogRead(potPin)>585 && analogRead(potPin)<=731){ //C
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(led7,LOW);
  digitalWrite(led8,LOW);
  }
 else if(analogRead(potPin)>731 && analogRead(potPin)<=877){ //D
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,LOW);
  digitalWrite(led7,HIGH);
  digitalWrite(led8,LOW);
  }
 else if(analogRead(potPin)>877){ //E
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
  digitalWrite(led7,LOW);
  digitalWrite(led8,LOW);
  }
}
///////////////////////////////////////////////Plays a note from the current key while the corresponding button is pushed////////////////////////
void playNote(){
  while(digitalRead(button1Pin)==1){
  tone(buzzerPin, currentKey[0]);
  }
  while(digitalRead(button2Pin)==1){
    tone(buzzerPin, currentKey[1]);
  }
  while(digitalRead(button3Pin)==1){
    tone(buzzerPin, currentKey[2]);
  }
  while(digitalRead(button4Pin)==1){
    tone(buzzerPin,currentKey[3]);
  }
  while(digitalRead(button5Pin)==1){
    tone(buzzerPin,currentKey[4]);
  }
  while(digitalRead(button6Pin)==1){
    tone(buzzerPin,currentKey[5]);
  }
  while(digitalRead(button7Pin)==1){
    tone(buzzerPin,currentKey[6]);
  }
  while(digitalRead(button8Pin)==1){
    tone(buzzerPin,currentKey[7]);
  }
  noTone(buzzerPin);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(button1Pin,INPUT);
pinMode(button2Pin,INPUT);
pinMode(button3Pin,INPUT);
pinMode(button4Pin,INPUT);
pinMode(button5Pin,INPUT);
pinMode(button6Pin,INPUT);
pinMode(button7Pin,INPUT);
pinMode(button8Pin,INPUT);
pinMode(buzzerPin,OUTPUT);
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);
pinMode(led8,OUTPUT);
pinMode(potPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
selectKey();
displayKey();
playNote();

}
