#include <Arduino.h>
#include "definitions.h"
#include "main.h"
#include "display.h"

// temporizador heartbeat
unsigned long atual_hb;
unsigned long time_hb;

// temporizador cover closed
unsigned long time_cc;
unsigned long atual_cc;

unsigned long timer, atual;

bool cover_closed_state = false, timer_end = false, referencia = false;

uint8_t axis_x = 100, axis_y = 99, axis_z = 9, spindle;
uint8_t axis, page, sentido = CW;

void heart_beating(){
	atual_hb = millis();
	if (atual_hb - time_hb >= DELAY_HEART_BEATING){
		digitalWrite(PIN_HEART_BEATING, !digitalRead(PIN_HEART_BEATING));
		time_hb = atual_hb;
	}
}

void cover_closed(){
	if(digitalRead(COVER_CLOSED)){
		cover_closed_state = true;
		page = 1;
		// atual_cc = millis();
		// while(digitalRead(COVER_CLOSED) == HIGH);
		// time_cc = millis();
		// if(time_cc - atual_cc >= 100)	
		
		cover_closed_state = true;
		page = 3;
	}
}

void button_init(void)
{
	pinMode(BUTTON_P_PIN,   INPUT);
	pinMode(BUTTON_S_PIN,   INPUT);
	pinMode(BUTTON_CCW_PIN, INPUT);
	pinMode(BUTTON_CW_PIN,  INPUT);

	attachInterrupt(digitalPinToInterrupt(BUTTON_P_PIN),   manual_ISR, RISING);
	attachInterrupt(digitalPinToInterrupt(BUTTON_S_PIN),   CW_ISR, RISING);
	attachInterrupt(digitalPinToInterrupt(BUTTON_CCW_PIN), CCW_ISR, RISING);
	attachInterrupt(digitalPinToInterrupt(BUTTON_CW_PIN),  spindle_ISR, RISING);
}

void setup() 
{
	display_init();	
	button_init();
	
	// OUTPUTS
	pinMode(COVER_CLOSED, INPUT);
	pinMode(PIN_HEART_BEATING, OUTPUT);

	Serial.begin(9600);

	welcome_display();
	// motors_go_home();
}

void loop()
{
	cover_closed();
	heart_beating();
	// monitor_serial();
	display_update_screen();
}