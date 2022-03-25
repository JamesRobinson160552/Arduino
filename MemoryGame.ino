/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Author: James Robinson
//
//  Displays a pattern on 4 leds and requires the user to press the 
//  corresponding buttons in order to continue
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int leftLedPin = 9;
int upLedPin = 13;
int rightLedPin = 11;
int downLedPin = 7;
int successLed = 2;
int failLed = 4;
int leftButtonPin = A1;
int upButtonPin = A2;
int rightButtonPin = A3;
int downButtonPin = A4;
long pattern[10];
long userInput[10];
int pause = 350;
int buzzerPin = 6;

//Fills an array with random numbers between 1 and 4///////////////////////////////////////////////////////////
void fillPattern(long pattern[]){
  for(int i = 0; i <10; i++)
  {
    long myLong = random(1,5);
    pattern[i] = myLong;
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//lights up leds in accordance with the pattern array/////////////////////////////////////////////////////////
void displayPattern(int level){
    for(int i=0; i<level; i++)
  {
    if(pattern[i]==1)
    {
      digitalWrite(leftLedPin,HIGH);
      tone(buzzerPin,939);
      delay(pause);
      digitalWrite(leftLedPin,LOW);
      noTone(buzzerPin);
      delay(pause);
    }
    else if(pattern[i]==2)
    {
      digitalWrite(upLedPin,HIGH);
      tone(buzzerPin,1408);
      delay(pause);
      digitalWrite(upLedPin,LOW);
      noTone(buzzerPin);
      delay(pause);
    }
    else if(pattern[i]==3)
    {
      digitalWrite(rightLedPin,HIGH);
      tone(buzzerPin,1117);
      delay(pause);
      digitalWrite(rightLedPin,LOW);
      noTone(buzzerPin);
      delay(pause);
    }
    else if(pattern[i]==4)
    {
      digitalWrite(downLedPin,HIGH);
      tone(buzzerPin,704);
      delay(pause);
      digitalWrite(downLedPin,LOW);
      noTone(buzzerPin);
      delay(pause);
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Gets the user's answer based on the order of buttons pushed/////////////////////////////////////////////////
void getUserAnswer(int level){
  for(int j=0; j<level; j++){
    while(userInput[j]==0){
      if(digitalRead(leftButtonPin)==1){
        userInput[j] = 1;
        while(digitalRead(leftButtonPin)==1){
          tone(buzzerPin,939);
        }
        delay(300);
      }
      else if(digitalRead(upButtonPin)==1){
        userInput[j] = 2;
        while(digitalRead(upButtonPin)==1){
          tone(buzzerPin,1408);
        }
        delay(300);
      }
      else if(digitalRead(rightButtonPin)==1){
        userInput[j] = 3;
        while(digitalRead(rightButtonPin)==1){
          tone(buzzerPin,1117);
        }
        delay(300);
      }
      else if(digitalRead(downButtonPin)==1){
        userInput[j] = 4;
        while(digitalRead(downButtonPin)==1){
          tone(buzzerPin,704);
        }
        delay(300);
      }
      noTone(buzzerPin);
    }
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Compares the user pattern to the correct pattern//////////////////////////////////////////////////////////
boolean compareArrays(int level){
  boolean match = true;
    for(int k=0; k<level; k++){
      Serial.print("User Input: ");
      Serial.println(userInput[k]);
      Serial.print("Desired Pattern: ");
      Serial.println(pattern[k]);
      if(userInput[k] != pattern[k]){
      match = false;   
    }
  }
  Serial.print("Result: match = ");
  if(match){
   Serial.println("TRUE"); 
  }
  else{
    Serial.println("FALSE");
  }
  return match;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  
  pinMode(leftLedPin,OUTPUT);
  pinMode(upLedPin,OUTPUT);
  pinMode(rightLedPin,OUTPUT);
  pinMode(downLedPin,OUTPUT);
  pinMode(successLed,OUTPUT);
  pinMode(failLed,OUTPUT);
  pinMode(leftButtonPin,INPUT);
  pinMode(upButtonPin,INPUT);
  pinMode(rightButtonPin,INPUT);
  pinMode(downButtonPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));

//Buffer//////////////////////////////////////////
  for(int x=0;x<5;x++){
    digitalWrite(successLed,HIGH);
    delay(300);
    digitalWrite(successLed,LOW);
    delay(300);
  }

  for(int y=0; y<5; y++){
    digitalWrite(failLed,HIGH);
    delay(300);
    digitalWrite(failLed,LOW);
    delay(300);
  }
/////////////////////////////////////////////////

  fillPattern(pattern);
  for(int level = 1; level<11; level++)
  {
    displayPattern(level);
    getUserAnswer(level);
    if(!compareArrays(level)){
      digitalWrite(failLed,HIGH);
      break;
    }
    digitalWrite(successLed,HIGH);
    delay(400);
    digitalWrite(successLed,LOW);
    for(int i=0; i<10; i++){ //Reset input array
      userInput[i] = 0;
    }
    delay(pause);
  }
  delay(500);
}

void loop(){}
