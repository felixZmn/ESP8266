#include "rgb.h"

const byte HSVlights[61] = { 0, 4, 8, 13, 17, 21, 25, 30, 34, 38, 42, 47, 51, 55, 59, 64, 68, 72, 76,
                             81, 85, 89, 93, 98, 102, 106, 110, 115, 119, 123, 127, 132, 136, 140, 144,
                             149, 153, 157, 161, 166, 170, 174, 178, 183, 187, 191, 195, 200, 204, 208,
                             212, 217, 221, 225, 229, 234, 238, 242, 246, 251, 255 };
/**
 * Hue, Saturation, Value is an cylindrical representation of the RGB color model. 
 * Only hue is considered, saturation and value are ignored
 * @param int angle the position of the color 
 * @returns an rgb color tripple
 */
RGB HSV(int angle) {
  struct RGB rgb;

  if (angle < 60) {
    rgb.red = 255;
    rgb.green = HSVlights[angle];
    rgb.blue = 0;
  } else if (angle < 120) {
    rgb.red = HSVlights[120 - angle];
    rgb.green = 255;
    rgb.blue = 0;
  } else if (angle < 180) {
    rgb.red = 0;
    rgb.green = 255;
    rgb.blue = HSVlights[angle - 120];
  } else if (angle < 240) {
    rgb.red = 0;
    rgb.green = HSVlights[240 - angle];
    rgb.blue = 255;
  } else if (angle < 300) {
    rgb.red = HSVlights[angle - 240];
    rgb.green = 0;
    rgb.blue = 255;
  } else {
    rgb.red = 255;
    rgb.green = 0;
    rgb.blue = HSVlights[360 - angle];
  }

  return rgb;
}
