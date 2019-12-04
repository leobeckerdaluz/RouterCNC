#include <Arduino.h>
#include "definitions.h"

struct interpolacao_motores
{
    uint8_t inc_X;
    uint8_t inc_Y;
};


interpolacao_motores interpolacao(uint8_t X, uint8_t Y){
    interpolacao_motores result_interpolacao;
    result_interpolacao.inc_X = X;
    result_interpolacao.inc_Y = Y;

    if (X==Y){
        
    }
    else if (X > Y){

    }
    else{

    }

    return result_interpolacao;
}