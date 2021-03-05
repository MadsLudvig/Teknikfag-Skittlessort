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
    int yellow_r;
    int yellow_g;
    int yellow_b;
    int green_r;
    int green_g;
    int green_b;
    int purple_r;
    int purple_g;
    int purple_b;
    int orange_r;
    int orange_g;
    int orange_b;
    int red_r;
    int red_g;
    int red_b;
    int grey1_r;
    int grey1_g;
    int grey1_b;
    int grey2_r;
    int grey2_g;
    int grey2_b;
    
  public:
    ColorSensor(byte r_pin, byte g_pin, byte b_pin, byte sense_pin, int meassure_delay);
    void init();
    int get_r_value();
    int get_g_value();
    int get_b_value();
    String get_color();
    
};

#endif
