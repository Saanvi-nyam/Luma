#include <SoftwareSerial.h>

SoftwareSerial BT(4, 5); // RX, TX

const int thumbPin = A5;
const int middlePin = A2;
const int pinkyPin = A0;

int thumbBend = 500;  
int middleBend = 500; 
int pinkyBend = 500;  

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Sign Language to Text Converter Started");
}

