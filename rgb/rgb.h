#ifndef RGB_H
#define RGB_H

#include <Arduino.h>

struct RGB {
  byte red;
  byte green;
  byte blue;
};

RGB HSV(int angle);

#endif