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

void loop() {
  // Read sensor values
  int thumbVal = analogRead(thumbPin);
  int middleVal = analogRead(middlePin);
  int pinkyVal = analogRead(pinkyPin);
  int accXPin = A5; 
  int accYPin = A6; 
  int accX = analogRead(accXPin);
  int accY = analogRead(accYPin);


unsigned long lastClearTime = 0;



  Serial.print("Thumb: "); Serial.print(thumbVal);
  Serial.print("  Middle: "); Serial.print(middleVal);
  Serial.print("  Pinky: "); Serial.println(pinkyVal);

 
  if (thumbVal <400 &&
      middleVal <=185 &&
      pinkyVal <299 ) {
    Serial.println("Saanvi");
    BT.println("Saanvi");
    delay(500); 
  }
  else if (thumbVal >=405)
    {Serial.println("Hello");
    BT.println("Hello");
    delay(500);
    }
   else if (thumbVal >=377 )
    {Serial.println("Play");
    BT.println("play");
    delay(500);
    }
    else if (thumbVal <360 && middleVal <790 )
    {Serial.println("I");
    BT.println("I am");
    delay(500);
    }

  else if (accX < 400 && accY < 400) {
    if (millis() - lastClearTime > 450) {
      BT.println(" ");
      Serial.println("[SCREEN CLEARED]");
    }
  }
delay(500);
}
