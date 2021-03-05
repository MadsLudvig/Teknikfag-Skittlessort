#include "Servo.h"

Servo::Servo(byte control_pin_a, byte control_pin_b, byte tacho_pin) {
  this->control_pin_a = control_pin_a;
  this->control_pin_b = control_pin_b;
  this->tacho_pin = tacho_pin;
  init();
}

void Servo::init() {
  pinMode(control_pin_a, OUTPUT);
  pinMode(control_pin_b, OUTPUT);
  pinMode(tacho_pin, INPUT);
  hall_sensings = 0;

}

int Servo::get_tacho_pin() {
  return tacho_pin;
}

void Servo::hall_sense() {
  Serial.println("hall_Sense");
  if (hall_sensings == hall_sensings_goal) {
    stop();
  }
  
  if (direction == 0) {
    hall_sensings += 1;
  } else {
    hall_sensings -= 1;
  }
    
  if (hall_sensings == 8) {
    hall_sensings = 0;
  }

  if (hall_sensings == -1) {
    hall_sensings = 7;
  }
}

void Servo::get_direction() {

  cw_value = hall_sensings;
  ccw_value = hall_sensings;

  while(true) {
    if(ccw_value == -1) {
      ccw_value = 7;     
    }
    if (cw_value == 8) {
      cw_value = 0;
    }

    if (cw_value == hall_sensings_goal) {
      direction = 0;
      break;
    }

    if (ccw_value == hall_sensings_goal) {
      direction = 1;
      break;
    }

    cw_value += 1;
    ccw_value -= 1;
  }

}

void Servo::move(int speed, int position) {

  hall_sensings_goal = position;

  get_direction();
                         
  if (direction == 1){
    analogWrite(control_pin_a, speed);
    analogWrite(control_pin_b, 0);
    while(control_pin_a) {}; 
  } else {
    analogWrite(control_pin_a, 0);
    analogWrite(control_pin_b, speed);
    while(control_pin_b) {}; 
  }
}

void Servo::stop() {
  digitalWrite(0, control_pin_a);
  digitalWrite(0, control_pin_b);
}
