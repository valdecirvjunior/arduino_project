/* SevSeg Counter Example
 
 Copyright 2014 Dean Reading
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 
 This example demonstrates a very simple use of the SevSeg library with a 4
 digit display. It displays a counter that counts up, showing deci-seconds.
 */

#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object
int led = 13;
void setup() {
  byte numDigits = 2;   
  byte digitPins[] = {2, 3};
  byte segmentPins[] = {10, 9, 8, 7, 6, 11, 12}; // no H segment
  pinMode(led, OUTPUT); 
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
  static unsigned long timer = millis();
  int counter = 0;
  digitalWrite(led, LOW);
  while(counter <= 5) {  // 60s update
      while (millis() <= timer + 1000) { //delay de 5 s
        sevseg.refreshDisplay(); // Must run repeatedly
        sevseg.setNumber(counter, 0);
        if (counter == 3){
          digitalWrite(led, HIGH);
        }
        else {
          digitalWrite(led, LOW); 
        }      
      }
      timer = millis();
      counter++;
  }
      
  counter = 0;
}

/// END ///



/// END ///
