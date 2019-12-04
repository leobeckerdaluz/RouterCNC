#include <Arduino.h>
#include "definitions.h"

String incoming_string;

void convert_string(String serial_read){
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