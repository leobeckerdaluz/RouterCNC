#include <Arduino.h>
#include "definitions.h"

void heart_beating(){
	static unsigned long long int millis_heart_beating = 0;

	if (millis()-millis_heart_beating >= DELAY_HEART_BEATING){
		millis_heart_beating = millis();
		digitalWrite(PIN_HEART_BEATING, !digitalRead(PIN_HEART_BEATING));
	}
}

void setup() 
{
	// BUTTONS
	pinMode(BUTTON_P_PIN, INPUT);
	pinMode(BUTTON_LEFT_PIN, INPUT);
	pinMode(BUTTON_RIGHT_PIN, INPUT);
	pinMode(BUTTON_S_PIN, INPUT);
	// OUTPUTS
	pinMode(PIN_HEART_BEATING, OUTPUT);
	pinMode(DRIVER_ENABLE_PIN, OUTPUT);
	pinMode(FAN__PWM_OUTPUT_PIN, OUTPUT);
	pinMode(HEAT_PWM_OUTPUT_PIN, OUTPUT);

	#if DEBUG_CONSOLE
	Serial.begin(9600);
	#endif

	// Configura a interrupção nos botões
	attachInterrupt(digitalPinToInterrupt(BUTTON_LEFT_PIN), left_button_short_click_event, RISING);
	attachInterrupt(digitalPinToInterrupt(BUTTON_P_PIN), p_button_short_click_event, RISING);
	attachInterrupt(digitalPinToInterrupt(BUTTON_S_PIN), s_button_short_click_event, RISING);
	attachInterrupt(digitalPinToInterrupt(BUTTON_RIGHT_PIN), right_button_short_click_event, RISING);
}

void loop()
{
	heart_beating();

	// monitor_serial();

	// Atualiza a tela de maneira não forçada
	// update_current_screen(false);
}
