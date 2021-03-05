#include "Servo.h"
#include "Stepper.h"
#include "ColorSensor.h"
#include <SoftwareSerial.h>

// Stepper Motor
#define STEPPER_STEPS_PER_REVOLUTION 200
#define STEPPER_A_PIN 4
#define STEPPER_B_PIN 5
#define STEPPER_X_PIN 6
#define STEPPER_Y_PIN 7

// Servo Motor
#define SERVO_CONTROL_PIN_A 11
#define SERVO_CONTROL_PIN_B 12
#define SERVO_TACHO_PIN A4

// Color Sensor
#define COLORSENSOR_R_PIN 9
#define COLORSENSOR_G_PIN 10
#define COLORSENSOR_B_PIN 8
#define COLORSENSOR_SENSE_PIN A5
#define COLORSENSOR_MEASSUREDELAY 200

// Wifi Module
#define WIFIMODULE_RX_PIN 3
#define WIFIMODULE_TX_PIN 2

// Stepper Motor
Stepper Stepper_motor(STEPPER_STEPS_PER_REVOLUTION, STEPPER_A_PIN, STEPPER_B_PIN, STEPPER_X_PIN, STEPPER_Y_PIN);

Servo Servo_motor(SERVO_CONTROL_PIN_A, SERVO_CONTROL_PIN_B, SERVO_TACHO_PIN);

ColorSensor Color_sensor(COLORSENSOR_R_PIN, COLORSENSOR_G_PIN, COLORSENSOR_B_PIN, COLORSENSOR_SENSE_PIN, COLORSENSOR_MEASSUREDELAY);

SoftwareSerial esp8266(WIFIMODULE_RX_PIN, WIFIMODULE_TX_PIN);

void hall_sense() {
  Servo_motor.hall_sense();
}

void setup() {

  // Servo Motor
  attachInterrupt(digitalPinToInterrupt(SERVO_TACHO_PIN), hall_sense, CHANGE);

  // Stepper Motor
  Stepper_motor.setSpeed(120);

  // initialize the serial port
  Serial.begin(9600);

  // Initialize Serial port for esp8266
  esp8266.begin(115200);
}

void loop() {
  delay(1000);

  Stepper_motor.step(STEPPER_STEPS_PER_REVOLUTION/4);
  
  String color = Color_sensor.get_color()

  if(color == "Yellow") {
    Servo_motor.move(255, 1)
  }
  if(color == "Green") {
    Servo_motor.move(255, 2)
  }
  if(color == "Purple") {
    Servo_motor.move(255, 3)
  }
  if(color == "Orange") {
    Servo_motor.move(255, 4)
  }
  if(color == "Red") {
    Servo_motor.move(255, 5)
  }

  Stepper_motor.step(STEPPER_STEPS_PER_REVOLUTION/4);
  
  esp8266.println(color);
  delay(1000);
}
