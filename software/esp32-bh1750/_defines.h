#ifndef _DEFINES_h
#define _DEFINES_h
/*
  --------------------|--------|--------|-
  DEVICE              | BH1750 | ESP32  |
  --------------------|--------|--------|-
  I2C SDA             | SDA    | 21     |
  I2C SLC             | SLC    | 22     |
  GND                 | GND    | GND    |
  VCCC                | VCC    | 3.3V   |
  ADD notconnected or | ADD    |        |
  --------------------|--------|--------|-
*/
#define PIN_SDA 21
#define PIN_SLC 22
#define LEN_LUXVALUEMSG 4
#define LEN_LUXLEVELMSG 32

// macro for get only firmware filename
#define FILENAME ({ \
    const char* filename_start = __FILE__; \
    const char* filename = filename_start; \
    while(*filename != '\0') \
      filename++; \
    while((filename != filename_start) && (*(filename - 1) != '\\')) \
      filename--; \
    filename; })

#endif
