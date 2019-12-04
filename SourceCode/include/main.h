#define DELAY_HEART_BEATING 500
#define BUTTON_P_PIN 2
#define BUTTON_CW_PIN 3
#define BUTTON_CCW_PIN 18
#define BUTTON_S_PIN 19
#define COVER_CLOSED 10
#define PIN_HEART_BEATING 13

void manual_ISR();
void CW_ISR();
void CCW_ISR();
void spindle_ISR();