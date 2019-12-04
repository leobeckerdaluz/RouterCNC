#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <Arduino.h>
#include "definitions.h"
#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 100

Stepper stepper_X(STEPS, 8, 9, 10, 11);
Stepper stepper_Y(STEPS, 12, 13, 14, 15);
Stepper stepper_Z(STEPS, 16, 17, 18, 19);

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
    stepper.step(val - previous);

    // remember the previous value of the sensor
    previous = val;
}