#include "Servo.h"
#include "Stepper.h"
#include "ColorSensor.h"

// Stepper Motor
#define STEPPER_STEPS_PER_REVOLUTION 200
#define STEPPER_A_PIN 2
#define STEPPER_B_PIN 3
#define STEPPER_X_PIN 4
#define STEPPER_Y_PIN 5

// Servo Motor
#define SERVO_CONTROL_PIN_A 9
#define SERVO_CONTROL_PIN_B 10
#define SERVO_TACHO_PIN A4

// Color Sensor
#define COLORSENSOR_R_PIN 7
#define COLORSENSOR_G_PIN 6
#define COLORSENSOR_B_PIN 8
#define COLORSENSOR_SENSE_PIN A5
#define COLORSENSOR_MEASSUREDELAY 200

// Stepper Motor
Stepper Stepper_motor(STEPPER_STEPS_PER_REVOLUTION, STEPPER_A_PIN, STEPPER_B_PIN, STEPPER_X_PIN, STEPPER_Y_PIN);

Servo Servo_motor(SERVO_CONTROL_PIN_A, SERVO_CONTROL_PIN_B, SERVO_TACHO_PIN);

ColorSensor Color_sensor(COLORSENSOR_R_PIN, COLORSENSOR_G_PIN, COLORSENSOR_B_PIN, COLORSENSOR_SENSE_PIN, COLORSENSOR_MEASSUREDELAY);

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
}

void loop() {

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
  
}
