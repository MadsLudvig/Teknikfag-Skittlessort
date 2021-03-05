#include "ColorSensor.h"

ColorSensor::ColorSensor(byte r_pin, byte g_pin, byte b_pin, byte sense_pin, int meassure_delay) {
  this->r_pin = r_pin;
  this->g_pin = g_pin;
  this->b_pin = b_pin;
  this->sense_pin = sense_pin;
  this->meassure_delay = meassure_delay;
  init();
};

void ColorSensor::init() {
  pinMode(sense_pin, INPUT);
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  yellow_r = 191;
  yellow_g = 365;
  yellow_b = 187;
  green_r = 154;
  green_g = 330;
  green_b = 177;
  purple_r = 152;
  purple_g = 286;
  purple_b = 173;
  orange_r = 172;
  orange_g = 296;
  orange_b = 175;
  red_r = 161;
  red_g = 285;
  red_b = 171;
  grey1_r = 162;
  grey1_g = 325;
  grey1_b = 191;
  grey2_r = 152;
  grey2_g = 293;
  grey2_b = 177;
}

int ColorSensor::get_r_value() {
  return (r_value);
}
int ColorSensor::get_g_value() {
  return (g_value);
}
int ColorSensor::get_b_value() {
  return (b_value);
}

String ColorSensor::get_color() {
  digitalWrite(r_pin, HIGH);
  digitalWrite(g_pin, LOW);
  digitalWrite(b_pin, LOW);
  delay(meassure_delay);
  r_value = analogRead(sense_pin);

  digitalWrite(r_pin, LOW);
  digitalWrite(g_pin, HIGH);
  digitalWrite(b_pin, LOW);
  delay(meassure_delay);
  g_value = analogRead(sense_pin);

  digitalWrite(r_pin, LOW);
  digitalWrite(g_pin, LOW);
  digitalWrite(b_pin, HIGH);
  delay(meassure_delay);
  b_value = analogRead(sense_pin);
  digitalWrite(b_pin, LOW);

  int yellow_distance = sqrt((yellow_r-r_value)^2 + (yellow_g-g_value)^2 + (yellow_b-b_value)^2);
  int green_distance = sqrt((green_r-r_value)^2 + (green_g-g_value)^2 + (green_b-b_value)^2);
  int purple_distance = sqrt((purple_r-r_value)^2 + (purple_g-g_value)^2 + (purple_b-b_value)^2);
  int orange_distance = sqrt((orange_r-r_value)^2 + (orange_g-g_value)^2 + (orange_b-b_value)^2);
  int red_distance = sqrt((red_r-r_value)^2 + (red_g-g_value)^2 + (red_b-b_value)^2);
  int grey1_distance = sqrt((grey1_r-r_value)^2 + (grey1_g-g_value)^2 + (grey1_b-b_value)^2);
  int grey2_distance = sqrt((grey2_r-r_value)^2 + (grey2_g-g_value)^2 + (grey2_b-b_value)^2);

  int minimum_value = min(yellow_distance, min(green_distance, min(purple_distance, min(orange_distance, min(red_distance, min(grey1_distance, grey2_distance) ) ) ) ) );

  if(yellow_distance==minimum_value) {
    return "Yellow";
  } 
  else if (green_distance==minimum_value) {
    return "Green";
  }
  else if (purple_distance==minimum_value) {
    return "Purple";
  }
  else if (orange_distance==minimum_value) {
    return "Orange";
  }
  else if (red_distance==minimum_value) {
    return "Red";
  }
  else if (grey1_distance==minimum_value) {
    return "Grey";
  }
  else if (grey2_distance==minimum_value) {
    return "Grey";
  }
}
