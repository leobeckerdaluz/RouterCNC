#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <Arduino.h>
#include "definitions.h"
#include <Stepper.h>
#include <display.h>


#define X_AXIS_STEPPER_DRIVER_1     12
#define X_AXIS_STEPPER_DRIVER_2     11
#define Y_AXIS_STEPPER_DRIVER_1     10
#define Y_AXIS_STEPPER_DRIVER_2     9
#define Z_AXIS_STEPPER_DRIVER_1     8
#define Z_AXIS_STEPPER_DRIVER_2     7
#define SPIPNDLE_DRIVER             6


// change this to the number of steps on your motor
#define STEPS 100

Stepper stepper_X(STEPS, X_AXIS_STEPPER_DRIVER_1, X_AXIS_STEPPER_DRIVER_2);
Stepper stepper_Y(STEPS, Y_AXIS_STEPPER_DRIVER_1, Y_AXIS_STEPPER_DRIVER_2);
Stepper stepper_Z(STEPS, Z_AXIS_STEPPER_DRIVER_1, Z_AXIS_STEPPER_DRIVER_2);

// the previous reading from the analog input
int previous = 0;


typedef struct
{
    uint8_t inc_X;
    uint8_t inc_Y;
    uint8_t Y_maior;
} interpolacao_motores;


void setup_motors() {
    // set the speed of the motor to 30 RPMs
    stepper_X.setSpeed(30);
    stepper_Y.setSpeed(30);
    stepper_Z.setSpeed(30);
}

interpolacao_motores interpolacao(uint8_t X, uint8_t Y, uint8_t min_inc_X, uint8_t min_inc_Y){
    interpolacao_motores result_interpolacao;

    uint8_t y_eh_maior = 0;

    if (Y == X){
        y_eh_maior = -1;

        printf("X e Y são iguais, logo retornando 0 \n");
        result_interpolacao.inc_X = 0;
        result_interpolacao.inc_Y = 0;
        result_interpolacao.Y_maior = -1;
        return result_interpolacao;
    }
    else if (Y > X){
        y_eh_maior = 1;

        uint8_t quociente = (Y - min_inc_Y) / (X - min_inc_X);
        uint8_t resto = (Y - min_inc_Y) % (X - min_inc_X);

        printf("Y é maior! Logo, Y(%d)/X(%d) deu quociente %d e resto %d \n", Y, X, quociente, resto);
        result_interpolacao.inc_X = resto;
        result_interpolacao.inc_Y = quociente;
        result_interpolacao.Y_maior = 1;
        return result_interpolacao;
    }
    else{
        uint8_t quociente = (X - min_inc_X) / (Y - min_inc_Y);
        uint8_t resto = (X - min_inc_X) % (Y - min_inc_Y);

        printf("X é maior! Logo, X(%d)/Y(%d) deu quociente %d e resto %d \n", X, Y, quociente, resto);
        result_interpolacao.inc_X = quociente;
        result_interpolacao.inc_Y = resto;
        result_interpolacao.Y_maior = 0;
        return result_interpolacao;
    }
}

void run_motor(){
    // get the sensor value
    int val = 200;//analogRead(0);

    // move a number of steps equal to the change in the
    // sensor reading
    // stepperX.step(val - previous);

    // remember the previous value of the sensor
    previous = val;
}

#define LENTO   30
#define MEDIO   60
#define RAPIDO  100

uint8_t duty;

void set_X_motor(uint8_t value){


}
void set_Y_motor(uint8_t value){
    
}
void set_Z_motor(uint8_t value){
    
}
void set_all_motors_speed(String state){
    if(state == "Lento")
    {
        stepper_X.setSpeed(LENTO);
        stepper_Y.setSpeed(LENTO);
        stepper_Z.setSpeed(LENTO);
    }else if(state=="Medio"){
        stepper_X.setSpeed(MEDIO);
        stepper_Y.setSpeed(MEDIO);
        stepper_Z.setSpeed(MEDIO);
    }else if(state=="Rapido"){
        stepper_X.setSpeed(RAPIDO);
        stepper_Y.setSpeed(RAPIDO);
        stepper_Z.setSpeed(RAPIDO);
    }
}
void set_spindle_state(uint8_t on_off){
    if(!on_off)
    {
        analogWrite(SPIPNDLE_DRIVER_1, 0);
        analogWrite(SPIPNDLE_DRIVER_2,0);

    }else{
        if(sentido==CW)
        {
            analogWrite(SPIPNDLE_DRIVER_1, duty);
        }else{
            analogWrite(SPIPNDLE_DRIVER_2, duty);
        }
    }
        
    
    
}
void set_spindle_speed(uint8_t value){
    
    duty = map(value,200,2000, 0,255);


    // analogWrite();
}
void set_spindle_rotation_side(uint8_t right_left){
    
}
