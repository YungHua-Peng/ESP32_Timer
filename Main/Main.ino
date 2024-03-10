//==========================================================================//
// Copyright 2024 - 2024 YungHua-Peng                                       //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//         http://www.apache.org/licenses/LICENSE-2.0                       //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
//==========================================================================//

#include "ConstantDefinition.h"

hw_timer_t *Timer0 = NULL;
hw_timer_t *Timer1 = NULL;
hw_timer_t *Timer2 = NULL;
hw_timer_t *Timer3 = NULL;

void IRAM_ATTR Timer0_ISR();
void IRAM_ATTR Timer1_ISR();
void IRAM_ATTR Timer2_ISR();
void IRAM_ATTR Timer3_ISR();

int a = 0;
int b = 0;
int c = 0;
int d = 0;

void setup() {
  // Set the serial baud rate
  Serial.begin(Baud_Rate);

  //
  // Timer setting
  // The clock in ESP32 is 80 MHz
  // The second parameter of timerBegin is prescaler (Accepted from range [65535:2])
  // Prescaler = 80 = Count every 1 micro second
  // The second parameter of timerAlarmWrite is Divider
  //
  Timer0 =  timerBegin(0, 80, true);
            timerAttachInterrupt(Timer0, &Timer0_ISR, true);
            timerAlarmWrite(Timer0, 1000000, true);   // Triggered per second
            timerAlarmEnable(Timer0);

  Timer1 =  timerBegin(1, 8000, true);
            timerAttachInterrupt(Timer1, Timer1_ISR, true);
            timerAlarmWrite(Timer1, 20000, true);    // Triggered per 2 seconds
            timerAlarmEnable(Timer1);

  Timer2 =  timerBegin(2, 65535, true);
            timerAttachInterrupt(Timer2, Timer2_ISR, true);
            timerAlarmWrite(Timer2, 1220, true);     // Triggered per second
            timerAlarmEnable(Timer2);

  Timer3 =  timerBegin(3, 65535, true);
            timerAttachInterrupt(Timer3, Timer3_ISR, true);
            timerAlarmWrite(Timer3, 2440, true);    // Triggered per 2 seconds
            timerAlarmEnable(Timer3);
}

void loop() {
  Serial.print("A = ");
  Serial.println(a);
  Serial.print("B = ");
  Serial.println(b);
  Serial.print("C = ");
  Serial.println(c);
  Serial.print("D = ");
  Serial.println(d);
  Serial.println("========");
  delay(500);
}

void IRAM_ATTR Timer0_ISR() {
  a = a + 1;
}

void IRAM_ATTR Timer1_ISR() {
  b = b + 1;
}

void IRAM_ATTR Timer2_ISR() {
  c = c + 1;
}

void IRAM_ATTR Timer3_ISR() {
  d = d + 1;
}