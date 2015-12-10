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
#include <dht11.h>
dht11 DHT11;
#define DHT11PIN 4
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
  int chk = DHT11.read(DHT11PIN); 
  int temp = DHT11.temperature;
  int humidity = DHT11.humidity;
  int counter = 0;
  while(counter <= 6) {  // 60s update
      digitalWrite(led, LOW);
      sevseg.setNumber(temp, 0);
      while (millis() <= timer + 2000) { //delay de 5 s
        sevseg.refreshDisplay(); // Must run repeatedly
      }
      timer = millis();

      sevseg.setNumber(humidity, 0);
      while (millis() <= timer + 2000) { //delay of 5 s
        digitalWrite(led, HIGH); // indeicate the Humidity reading
        sevseg.refreshDisplay(); // Must run repeatedly
        digitalWrite(led, LOW); // to lower a little the led bright
      }
      timer = millis();
      counter++;
  }
  counter = 0;
}

/// END ///
