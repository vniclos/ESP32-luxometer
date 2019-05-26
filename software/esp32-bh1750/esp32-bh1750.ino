// other good example on
//https://diyprojects.io/bh1750-gy-302-measure-lighting-quality-home-arduino-esp8266-esp32/#.XOlT1JP7SUk

#include <Wire.h>
#include <BH1750.h>

#include "_defines.h"   // my defines
#include "_global.h"    // global variables-objects
#include "dev_bh1750.h" // manager sensor

void setup() {
  // Show firmware 
  Serial.begin(115200);
  Serial.println("=====================================");
  Serial.print(FILENAME);
  Serial.print(" compiled: ");
  Serial.print(__DATE__);
  Serial.print(" ");
  Serial.println(__TIME__);
  Serial.println("=====================================");
  
  fnc_dev_bh1750_Setup();

}

void loop() {
  // put your main code here, to run repeatedly:
  fnc_dev_bh1750_Read();
  delay(2000);
}
