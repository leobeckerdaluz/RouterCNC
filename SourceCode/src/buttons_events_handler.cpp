#include <Arduino.h>

extern uint8_t page;

bool editing = false;
bool programming_mode = false;
uint8_t screens_iterator = 1; // Inicia na posição da primeira tela de edição

unsigned long time_p, atual_p;
bool button_p_state;

// ----------------------------------------------------
/* P */
void manual_ISR(){
    delay(100);
    // if(digitalRead(BUTTON_P_PIN)){
	// 	atual_p = millis();
	// 	while(digitalRead(BUTTON_P_PIN) == HIGH);
	// 	time_p = millis();
	// 	if(time_p - atual_p >= 100)	button_p_state = true;
	// }

    if(page <= 6){
        page++;
        if (page == 2)
            page = 3;
    }   
    else
        page=0;        
}
// ----------------------------------------------------

// ----------------------------------------------------
/* LEFT */
void CW_ISR(){
    // if(initializing){
    //     controller_type = PROPORTIONAL_CONTROLLER;
    //     welcome_controller();
    // }
    // else{
    //     if (programming_mode){
    //         if(editing){
    //             // Atualiza o valor
    //             update_value(UPDATE_VALUE_TO_DOWN);
    //         }
    //         else{
    //             // Navega para a tela da esquerda
    //             #if DEBUG_CONSOLE
    //             Serial.println("Navegando para a tela da esquerda!");
    //             #endif
                
    //             // Decrementa a página atual                
    //             screens_iterator--;
    //             switch (controller_type){
    //                 case HYSTERESIS_CONTROLLER:
    //                     if (screens_iterator < 1)
    //                         screens_iterator = NUMBER_OF_HYST_SCREENS - 1;
    //                     current_page = programming_hyst_screens[screens_iterator];
    //                 break;
    //                 case PROPORTIONAL_CONTROLLER:
    //                     if (screens_iterator < 1)
    //                         screens_iterator = NUMBER_OF_PROP_SCREENS - 1;
    //                     current_page = programming_prop_screens[screens_iterator];
    //                 break;
    //             }

    //             lcd_scroll(RIGHT_SCROLL);
    //             update_current_screen(true);
    //         }
    //     }
    // }
}
// ----------------------------------------------------

// ----------------------------------------------------
/* RIGHT */
void CCW_ISR(){
    // if(initializing){
    //     controller_type = HYSTERESIS_CONTROLLER;
    //     welcome_controller();
    // }
    // else{
    //     if(programming_mode){
    //         if(editing){
    //             // Atualiza o valor
    //             update_value(UPDATE_VALUE_TO_UP);
    //         }
    //         else{
    //             // Navega para a tela da direita
    //             #if DEBUG_CONSOLE
    //             Serial.println("Navegando para a tela da direita!");
    //             #endif

    //             // Incrementa a página atual   
    //             screens_iterator++; 
    //             switch (controller_type){
    //                 case HYSTERESIS_CONTROLLER:
    //                     if (screens_iterator >= NUMBER_OF_HYST_SCREENS)
    //                         screens_iterator = 1;
    //                     current_page = programming_hyst_screens[screens_iterator];
    //                 break;
    //                 case PROPORTIONAL_CONTROLLER:
    //                     if (screens_iterator >= NUMBER_OF_PROP_SCREENS)
    //                         screens_iterator = 1;
    //                     current_page = programming_prop_screens[screens_iterator];
    //                 break;
    //             }

    //             lcd_scroll(LEFT_SCROLL);
    //             update_current_screen(true);
    //         }
    //     }
    // }
}
// ----------------------------------------------------

// ----------------------------------------------------
/* s */
void spindle_ISR(){
    // if(programming_mode){
    //     if(editing){
    //         #if DEBUG_CONSOLE
    //         Serial.println("Salvando as alterações!");
    //         #endif
    //         editing = false;
    //         update_current_screen(true);
    //     }
    //     else{
    //         #if DEBUG_CONSOLE
    //         Serial.println("Alterando os campos!");
    //         #endif
    //         editing = true;
    //         update_current_screen(true);
    //     }
    // }
}
// ----------------------------------------------------