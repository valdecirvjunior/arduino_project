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
#include <RBD_LightSensor.h>

SevSeg sevseg; //Instantiate a seven segment controller object
RBD::LightSensor light_sensor(A0);
int led = 13;
int lumin = 0;
void setup() {
  byte numDigits = 2;   
  byte digitPins[] = {2, 3};
  byte segmentPins[] = {10, 9, 8, 7, 6, 11, 12}; // no H segment
  pinMode(led, OUTPUT); 
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
      lumin = light_sensor.getPercentValue();
      if (lumin < 15){
         digitalWrite(led, HIGH);
      } else {
         digitalWrite(led, LOW);
        }
      sevseg.setNumber(lumin, 0);
      sevseg.refreshDisplay();
}



/// END ///
