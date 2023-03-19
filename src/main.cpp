#include <Arduino.h>
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

void setup() {
  // put your setup code here, to run once:
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);//
  pinMode(19,OUTPUT);//
  pinMode(23,OUTPUT);//
  pinMode(33,OUTPUT);
  pinMode(26,OUTPUT);//
  pinMode(27,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(32,OUTPUT);

  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(12,OUTPUT);//
  pinMode(13,OUTPUT);//
  pinMode(14,OUTPUT);//
  pinMode(15,OUTPUT);
  pinMode(21,OUTPUT);//
  pinMode(22,OUTPUT);



  digitalWrite(16,HIGH);
  digitalWrite(17,HIGH);
  digitalWrite(18,HIGH);
  digitalWrite(19,HIGH);
  digitalWrite(23,HIGH);
  digitalWrite(33,HIGH);
  digitalWrite(26,HIGH);
  digitalWrite(27,HIGH);
  digitalWrite(25,HIGH);
  digitalWrite(32,HIGH);
/*
  digitalWrite(4,HIGH); // D
  digitalWrite(5,HIGH); // A
  digitalWrite(12,HIGH); // E
  digitalWrite(13,HIGH); // DP
  digitalWrite(14,HIGH); // F
  digitalWrite(15,HIGH); // G
  digitalWrite(21,LOW); // C 
  digitalWrite(22,HIGH); // B */

  byte numDigits = 10;
  byte digitPins[] = {32,25,27,26,33,23,19,18,17,16};
  byte segmentPins[] = {5,22,21,4,12,14,15,13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(10);
                  
}

void loop() {

 //local vars
  static byte decPlace = 0;
  
  sevseg.setNumber(123890,decPlace);
  sevseg.refreshDisplay(); // Must run repeatedly; don't use blocking code (ex: delay()) in the loop() function or this won't work right
}