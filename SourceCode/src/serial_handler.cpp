#include <Arduino.h>
#include "definitions.h"

#include <readString.h>

String incoming_string;
// $X=10Y=5#
// $S=1000M3Z=10F=Rapido#
int k;

struct values valuesData;

void monitor_serial(){
    findPosition();

    getData();
    
    Serial.println("Teste de struct");
    Serial.println(valuesData.Z_Value - 10);

    return;
}