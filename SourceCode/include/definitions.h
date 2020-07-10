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


typedef struct
{
    uint8_t inc_X;
    uint8_t inc_Y;
    uint8_t Y_maior;
} interpolacao_motores;

void set_X_motor(uint8_t value);
void set_Y_motor(uint8_t value);
void set_Z_motor(uint8_t value);
void set_all_motors_speed(uint8_t state);
void set_spindle_state(uint8_t on_off);
void set_spindle_speed(uint8_t value);
void set_spindle_rotation_side(uint8_t right_left);

interpolacao_motores interpolacao(uint8_t X, uint8_t Y, uint8_t min_inc_X, uint8_t min_inc_Y);