#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>

class Servo {
  
  private:
    byte control_pin_a;
    byte control_pin_b;
    byte tacho_pin;
    int hall_sensings;
    int hall_sensings_goal;
    int direction;
    int cw_value;
    int ccw_value;
    void get_direction();
    
  public:
    Servo(byte control_pin_a, byte control_pin_b, byte tacho_pin);
    int get_tacho_pin();
    void hall_sense();
    void init();
    void move(int speed, int position);
    void stop();
    
};

#endif
