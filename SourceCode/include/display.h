#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

#define DISPLAY_ADDRESS 0x27

enum {
    INICIAL=0,
    ERRO,
    REFERENCIAMENTO,
    POSICAO,
    MANUAL,
    FIM_DE_CURSO,

    NUMBER_OF_SCREENS
};

enum{
    X=0,
    Y,
    Z,
    S
};

enum{
    CW=0,
    CCW
};

void display_init();
void display_update_screen();
void welcome_display();

extern LiquidCrystal_I2C lcd;
extern uint8_t page;

extern uint8_t axis_x;
extern uint8_t axis_y;
extern uint8_t axis_z;
extern uint8_t spindle;
extern uint8_t axis;
extern uint8_t sentido;

extern byte special_LCD_char_UPF1[8];
extern byte special_LCD_char_UPF2[8];
extern byte super_special_LCD_char_UPF1[8];
extern byte super_special_LCD_char_UPF2[8];
extern byte special_LCD_char_S[8];
extern byte special_LCD_char_Y[8];
extern byte special_LCD_char_Z[8];
extern byte special_LCD_char_X[8];


const char lcd_string_UNIVERSIDADE[]           = "Universidade";
const char lcd_string_DE_PASSO_FUNDO[]         = " de Passo Fundo ";
const char lcd_string_INICIAL_LINHA1[]         = "   CNC Router   ";
const char lcd_string_INICIAL_LINHA2[]         = "Home Ret? <S>   ";
const char lcd_string_ERRO_LINHA1[]            = "Erro: Please    ";
const char lcd_string_ERRO_LINHA2[]            = "Close the Cover!";
const char lcd_string_REFERENCIAMENTO_LINHA1[] = "Machine Home    ";
const char lcd_string_REFERENCIAMENTO_LINHA2[] = "in progress...  ";
const char lcd_string_POSICAO_LINHA1[]         = "S:    0   Z:   0";
const char lcd_string_POSICAO_LINHA2[]         = "X:    0   Y:   0";
const char lcd_string_FIM_DE_CURSO_LINHA1[]    = "  Over  Travel  ";
const char lcd_string_FIM_DE_CURSO_LINHA2[]    = "    Axis: ";
