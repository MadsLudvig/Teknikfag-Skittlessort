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
}

void ColorSensor::meassure() {
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
