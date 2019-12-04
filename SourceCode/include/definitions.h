#include <stdbool.h>

// ----------------------------------
//             GERAL
// ----------------------------------
#define DELAY_HEART_BEATING 500
#define WELCOME_INTRODUCTION true
#define DEBUG_CONSOLE false
#define TIME_BANDWIDHT 1.0/100

// ----------------------------------
//              PINS
// ----------------------------------
#define BUTTON_P_PIN 9
#define BUTTON_LEFT_PIN 8
#define BUTTON_RIGHT_PIN 7
#define BUTTON_S_PIN 6
#define LM35_PIN A0
#define ANALOG_SETPOINT_PIN A1
#define ENCODER_PIN 2
#define PIN_HEART_BEATING 13
#define HYSTERESIS_CONTROLLER_STATUS_PIN 4
#define DRIVER_ENABLE_PIN 12
#define FAN__PWM_OUTPUT_PIN 10
#define HEAT_PWM_OUTPUT_PIN 11

// ----------------------------------
//            SERIAL
// ----------------------------------
void monitor_serial();