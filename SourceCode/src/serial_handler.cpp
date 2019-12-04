#include <Arduino.h>
#include "definitions.h"
#include <readString.h>

// $X=10Y=5#
// $S=1000M3Z=10F=Rapido#

struct values valuesData;

void monitor_serial(){
    uint8_t serial_available = findPosition();

    if (serial_available){
        getData();

        Serial.println("Teste de struct");
        Serial.println(valuesData.Z_Value - 10);
    }

    return;
}