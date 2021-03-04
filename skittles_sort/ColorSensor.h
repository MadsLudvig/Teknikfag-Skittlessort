#ifndef COLORSENSOR_H
#define COLORSENSOR_H

#include <Arduino.h>

class ColorSensor {
  
  private:
    byte r_pin;
    byte g_pin;
    byte b_pin;
    byte sense_pin;
    int r_value;
    int g_value;
    int b_value;
    int meassure_delay;
    
  public:
    ColorSensor(byte r_pin, byte g_pin, byte b_pin, byte sense_pin, int meassure_delay);
    void init();
    void meassure();
    int get_r_value();
    int get_g_value();
    int get_b_value();
    
};

#endif
