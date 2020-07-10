#include <Arduino.h>
#include "definitions.h"
#include <readString.h>

// $X=10Y=5#
// $S=1000M3Z=10F=Rapido#

struct values valuesData;
interpolacao_motores results_interpolacao;

void monitor_serial(){
    uint8_t serial_available = findPosition();

    // Se available, chegou e processou algum comando
    if (serial_available){
        getData();

        Serial.println("Teste de struct");
        Serial.println(valuesData.Z_Value - 10);
    }

    if ((valuesData.X_Value == 0) || (valuesData.Y_Value == 0)){
        if (valuesData.X_Value != 0){
            set_X_motor(valuesData.X_Value);
        }
        else if (valuesData.Y_Value != 0){
            set_Y_motor(valuesData.Y_Value);
        }
    }
    else{
        results_interpolacao = interpolacao(valuesData.X_Value, valuesData.Y_Value, 1, 1);
    }

    return;
}