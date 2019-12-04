#include <Arduino.h>
#include <string.h>

#define STR_CORRECT 1
#define STEP_TWO 2
#define STEP_THREE 3
#define STEP_FOUR 4
#define STEP_FIVE 5
#define STEP_SIX 6
#define STEP_SEVEN 7

struct values {
    int S_Value, X_Value, Y_Value, Z_Value;
    String F_Value,M3_Value, M4_Value;
};

void findPosition();

String findNext(int id);

void getData();

void getValuesStr();