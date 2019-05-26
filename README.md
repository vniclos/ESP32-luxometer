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
##### main file 
Are very simple,  for good maintinence and easy intregration in other project, Only need includes and one line in setup and other in loop

* _defines.h has constants for configuration

* _global.h has declaration of global variables and objects (I use g_ as prefij)

*_dev_bh1740.has manager and function for use sensor, (I use  fnc_dev_bh1750_ as prefij)

* BH1750.h you can download from https://github.com/claws/BH1750 or inside libraries folder of this project

* Wire.h is a standar I2C librari
``` c++

#include <Wire.h>
#include <BH1750.h>
#include "_defines.h"   // my defines
#include "_global.h"    // global variables-objects
#include "dev_bh1750.h" // manager sensor
void setup() {

  // Show firmware name date time compilation on start
  
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
  fnc_dev_bh1750_Read();
  delay(2000);
}

```

##### defines.h

Config pins for use SDA and SLC, in ESP32 21 and 22 are the pins in ESP-32 dev kit v2 modulo, but is posible you need change it.
LEN_ is the prefig that i use for easy change lengt of char[] and be careful whit sizes

``` c++

#define PIN_SDA 21
#define PIN_SLC 22
#define LEN_LUXVALUEMSG 4
#define LEN_LUXLEVELMSG 32


// I use this macro for get only firmware filename for debug proposits and get it when i use OTA, it  is not necesary for this project
#define FILENAME ({ \
    const char* filename_start = __FILE__; \
    const char* filename = filename_start; \
    while(*filename != '\0') \
      filename++; \
    while((filename != filename_start) && (*(filename - 1) != '\\')) \
      filename--; \
    filename; })
``` 
Contac with me on facebook 
https://www.facebook.com/vicente.niclos
