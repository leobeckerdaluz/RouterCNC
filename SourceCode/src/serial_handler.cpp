#include <Arduino.h>
#include "definitions.h"

#include <readString.h>

String incoming_string;
// $X=10Y=5#
// $S=1000M3Z=10F=Rapido#
int k;

struct values valuesData;


void convert_string(String serial_read){
    findPosition();

    getData();

    Serial.println("Teste de struct");
    Serial.println(valuesData.Z_Value - 10);

    return;
}

void monitor_serial(){
    // enviar resposta apenas quando receber dados:
    if (Serial.available() > 0) {
        // Lê o dado recebido
        incoming_string = Serial.read();

        // Processa a string
        convert_string(incoming_string);

        // Atua com base nos parâmetros recebidos
        
    }
}