#include <Arduino.h>
#include <string.h>

#include <readString.h>


// $X=10Y=5#
// $S=1000M3Z=10F=Rapido#
int k;

struct values valuesData;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
 findPosition();

 getData();

Serial.println("Teste de struct");
Serial.println(valuesData.Z_Value - 10);

}

