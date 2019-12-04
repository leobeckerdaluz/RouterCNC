#include "display.h"

LiquidCrystal_I2C lcd(DISPLAY_ADDRESS,2,1,0,4,5,6,7,3, POSITIVE);

unsigned long time_display;
unsigned long atual_display;

uint8_t last_page = page;

byte special_LCD_char_Y[8] = {
	0b10001,
	0b10001,
	0b10001,
	0b01010,
	0b00100,
	0b00100,
	0b00100,
	0b11111
};

byte special_LCD_char_Z[8] = {
	0b11111,
	0b00001,
	0b00010,
	0b00100,
	0b01000,
	0b10000,
	0b11111,
	0b11111
};

byte special_LCD_char_X[8] = {
	0b10001,
	0b10001,
	0b01010,
	0b00100,
	0b01010,
	0b10001,
	0b10001,
	0b11111
};

byte special_LCD_char_S[8] = {
	0b01111,
	0b10000,
	0b10000,
	0b01110,
	0b00001,
	0b00001,
	0b11110,
	0b11111
};

byte special_LCD_char_UPF1[8] = {
    0b00000,
    0b00001,
    0b00011,
    0b00111,
    0b00000,
    0b00111,
    0b00011,
    0b00001
};

byte special_LCD_char_UPF2[8] = {
    0b00000,
    0b10000,
    0b11000,
    0b11100,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};

void display_init()
{
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setBacklight(HIGH);

    lcd.createChar(4, special_LCD_char_UPF1);
	lcd.createChar(5, special_LCD_char_UPF2);
    lcd.createChar(6, special_LCD_char_X);
    lcd.createChar(7, special_LCD_char_Y);
    lcd.createChar(8, special_LCD_char_Z);
    lcd.createChar(9, special_LCD_char_S);
} 

void welcome_display(){
	lcd.clear();
    lcd.setCursor(0, 0);
	lcd.write(4);
	lcd.write(5);
	lcd.setCursor(3, 0);
	lcd.print(lcd_string_UNIVERSIDADE);
	lcd.setCursor(0, 1);
	lcd.print(lcd_string_DE_PASSO_FUNDO);
	delay(1000);

	lcd.clear();

	lcd.setCursor(0, 0);
	lcd.print(lcd_string_INICIAL_LINHA1);
	lcd.setCursor(0, 1);
	lcd.print(lcd_string_INICIAL_LINHA2);
	delay(1000);
}

static void display_inicial()
{
    lcd.setCursor(0, 0);
	lcd.print(lcd_string_INICIAL_LINHA1);
	lcd.setCursor(0, 1);
	lcd.print(lcd_string_INICIAL_LINHA2);
}

static void display_erro()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(lcd_string_ERRO_LINHA1);
    lcd.setCursor(0,1);
    lcd.print(lcd_string_ERRO_LINHA2);
}

static void display_referenciamento()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(lcd_string_REFERENCIAMENTO_LINHA1);
    lcd.setCursor(0,1);
    lcd.print(lcd_string_REFERENCIAMENTO_LINHA2);
}

static void display_posicao()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(lcd_string_POSICAO_LINHA1);
    lcd.setCursor(0,1);
    lcd.print(lcd_string_POSICAO_LINHA2);

    /* Atualiza valores no display */
    if(axis_x > 99)      lcd.setCursor(4, 1);
    else if(axis_x >  9) lcd.setCursor(5, 1);
    else                 lcd.setCursor(6, 1);
    lcd.print(axis_x, 10);
    
    if(axis_y > 99)      lcd.setCursor(13, 1);
    else if(axis_y >  9) lcd.setCursor(14, 1);
    else                 lcd.setCursor(15, 1);
    lcd.print(axis_y, 10);    

    if(axis_z > 99)      lcd.setCursor(13, 0);
    else if(axis_z >  9) lcd.setCursor(14, 0);
    else                 lcd.setCursor(15, 0);
    lcd.print(axis_z, 10);    

    if(spindle > 99)      lcd.setCursor(4, 0);
    else if(spindle >  9) lcd.setCursor(5, 0);
    else                  lcd.setCursor(6, 0);
    lcd.print(spindle, 10);
}

static void display_manual()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(lcd_string_POSICAO_LINHA1);
    lcd.setCursor(0, 1);
    lcd.print(lcd_string_POSICAO_LINHA2);

    switch (axis)
    {
    case X:
        lcd.setCursor(0, 1);
        lcd.write(6);
        if(axis_x > 99)      lcd.setCursor(4, 1);
        else if(axis_x >  9) lcd.setCursor(5, 1);
        else                 lcd.setCursor(6, 1);
        lcd.print(axis_x, 10);
        
        break;

    case Y:
        lcd.setCursor(10, 1);
        lcd.write(7);
        if(axis_y > 99)      lcd.setCursor(13, 1);
        else if(axis_y >  9) lcd.setCursor(14, 1);
        else                 lcd.setCursor(15, 1);
        lcd.print(axis_y, 10);
        break;
    
    case Z:
        lcd.setCursor(10, 0);
        lcd.write(8);
        if(axis_z > 99)      lcd.setCursor(13, 0);
        else if(axis_z >  9) lcd.setCursor(14, 0);
        else                 lcd.setCursor(15, 0);
        lcd.print(axis_z, 10);
        break;
    
    case S:
        lcd.setCursor(0, 0);
        lcd.write(9);
        if(spindle > 99)      lcd.setCursor(4, 0);
        else if(spindle >  9) lcd.setCursor(5, 0);
        else                  lcd.setCursor(6, 0);
        lcd.print(spindle, 10);
        break;

    default:
        break;
    }
}

static void display_fim()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(lcd_string_FIM_DE_CURSO_LINHA1);
    lcd.setCursor(0, 1);
    lcd.print(lcd_string_FIM_DE_CURSO_LINHA2);
    lcd.setCursor(10, 1);

    switch (axis)
    {
    case X:
        lcd.write("X");
        break;
    
    case Y:
        lcd.write("Y");
        break;
    
    case Z:
        lcd.write("Z");
        break;
    
    default:
        break;
    }

    lcd.setCursor(11, 1);
    if(sentido == CW) lcd.write("+");
    else              lcd.write("-");
}

void display_update_screen()
{
    switch (page)
    {
        case INICIAL:
            atual_display = millis();
            if(atual_display - time_display >= 200){
                if(page != last_page)   
                    display_inicial();
                else    last_page = page;
                time_display = millis();
            }

        break;

        case ERRO:
            atual_display = millis();
            if(atual_display - time_display >= 200){
                if(last_page != page) 
                    display_erro();
                else last_page = page;
                time_display = millis();
            }

        break;

        case REFERENCIAMENTO:
            atual_display = millis();
            if(atual_display - time_display >= 200){
                if(last_page != page)
                    display_referenciamento();
                else    last_page = page;
                time_display = millis();
            }

        break;

        case POSICAO:
            atual_display = millis();
            if(atual_display - time_display >= 200){
                if(last_page != page)
                    display_posicao();
                else    last_page = page;
                time_display = millis();
            }
           
        break;

        case MANUAL:
            atual_display = millis();
            if(atual_display - time_display >= 200){
                if(last_page != page)
                    display_manual();
                else    last_page = page;
                time_display = millis();
            }
            
        break;

        case FIM_DE_CURSO:
            atual_display = millis();
            if(atual_display - time_display >= 200){
                if(last_page != page)
                    display_fim();
                else    last_page = page;
                time_display = millis();
            }
    
        break;

        default:
        break;
    }
}