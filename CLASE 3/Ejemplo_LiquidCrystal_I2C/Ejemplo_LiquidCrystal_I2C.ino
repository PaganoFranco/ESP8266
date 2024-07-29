#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27    //Dirección I2C del dispositivo
#define LCD_COLUMNS 16      //Número de Columnas Display
#define LCD_ROWS    2       //Número de Filas Display

LiquidCrystal_I2C miDisplay(I2C_ADDR, LCD_COLUMNS, LCD_ROWS); //Inicia Objeto

void setup() {
    delay(400);
    miDisplay.begin(LCD_COLUMNS, LCD_ROWS); //Configura Display
    miDisplay.init(); //Inicia Display
    miDisplay.clear(); //Limpia Pantalla
    miDisplay.backlight(); //Enciende la luz de fondo (backlight)
    miDisplay.setCursor(0, 0);
    miDisplay.print("   Display OK   ");
    delay(3000);
}

void loop() {
    miDisplay.setCursor(0, 0);
    miDisplay.print("     FILA 1    ");
    delay(1500);
    miDisplay.clear();
    miDisplay.setCursor(0, 1);
    miDisplay.print("     FILA 2    ");
    delay(1500);
    miDisplay.clear();
}
