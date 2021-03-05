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
  attachInterrupt(digitalPinToInterrupt(A5), hall_sense, CHANGE);

  // Stepper Motor
  Stepper_motor.setSpeed(120);

  // initialize the serial port
  Serial.begin(9600);

  // Initialize Serial port for esp8266
  esp8266.begin(115200);
}

void loop() {
  /*
  delay(1000);

  Stepper_motor.step(STEPPER_STEPS_PER_REVOLUTION/4);

  delay(1000);
  
  Color_sensor.meassure();
  Serial.println(Color_sensor.get_r_value());
  Serial.println(Color_sensor.get_g_value());
  Serial.println(Color_sensor.get_b_value());
  Serial.println("");
  
  delay(1000);

  Servo_motor.move(2)
  */

  Serial.println(Color_sensor.get_color());
  
  esp8266.println("Hell YEAH niigger");
  delay(2000);
}
