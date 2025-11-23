#include <SoftwareSerial.h>


SoftwareSerial BT(4, 5); // RX, TX

const int ringPin = A1;
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
  int ringVal = analogRead(ringPin);
  int accXPin = A5; 
  int accYPin = A6; 
  int accX = analogRead(accXPin);
  int accY = analogRead(accYPin);


unsigned long lastClearTime = 0;



  Serial.print("Thumb: "); Serial.print(thumbVal);
  Serial.print("  Middle: "); Serial.print(middleVal);
  Serial.print("  Pinky: "); Serial.println(pinkyVal);
  Serial.print("  Ring: "); Serial.println(ringVal);
 
  if (
      thumbVal<410&&
      thumbVal > 400&&
      middleVal <87 &&
      middleVal >40 &&
      ringVal <346 &&
      pinkyVal <136
     ) 
    {
    Serial.println("LUMA");
    BT.println("LUMA");
    delay(500); 
    }
  else if (thumbVal >=405&&
           thumbVal <417)
    {Serial.println("Hello");
    BT.println("Hello");
    delay(500);
    }
    
   else if (thumbVal >=377&&
            thumbVal<400 )
    {Serial.println("Let's Play");
    BT.println("Let's Play");
    delay(2000);;
    }
    else if (thumbVal <340 && middleVal <74 )
    {Serial.println("We are");
    BT.println("We are");
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
