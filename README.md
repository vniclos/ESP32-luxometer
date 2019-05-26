# ESP32 BH1750 LUXOMTER 

![alt text](https://github.com/vniclos/ESP32-luxometer/blob/master/images/esp32-bh1750_luxometer.jpg?raw=true "esp32 luxometer" )

### Hardware

- 1 ESP32 DEVKIT V1
- 1 BH1750

### Serial Output 

### Wiring
![alt text](https://github.com/vniclos/ESP32-luxometer/blob/master/images/serial.output.jpg?raw=true "esp32 luxometer" )

Connections:
  - BH1750 -> ESP32 
  - VCC -> 3V3 
  - GND -> GND
  - SCL -> SCL 
  - SDA -> SDA 
  - ADD -> NC

### Software
- Arduino IDE
- Library BH1750.h

### intregration in your projects.
The code are splited in tree files.
### main file 
´´´ c++

#include <Wire.h>
#include <BH1750.h>

#include "_defines.h"   // my defines
#include "_global.h"    // global variables-objects
#include "dev_bh1750.h" // manager sensor

void setup() {
  fnc_dev_bh1750_Setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  fnc_dev_bh1750_Read();
  delay(2000);
}

'''

Contac with me on facebook 
https://www.facebook.com/vicente.niclos
