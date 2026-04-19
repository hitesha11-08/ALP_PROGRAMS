#include <reg52.h>

#define LCD P2

sbit RS = P3^0;
sbit RW = P3^1;
sbit EN = P3^2;

void delay_ms() {
    unsigned int i, j;
    for(i = 0; i < 500; i++){
        for(j = 0; j < 123; j++){
   }
		}
}

void lcd_cmd(unsigned char cmd) {
    
    RS = 0;
    RW = 0;
  LCD = cmd;  
	   EN = 1;
    delay_ms();
    EN = 0;
}

void lcd_data(unsigned char dat) {
    
    RS = 1;
    RW = 0;
  LCD = dat;  
	EN = 1;
    delay_ms();
    EN = 0;
}

void lcd_init() {
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
	  lcd_cmd(0x06);
    lcd_cmd(0x01);
	  lcd_cmd(0x80);
}

void lcd_string(char *str) {
    while(*str) {
        lcd_data(*str++);
    }
}

void main() {
	  lcd_init();
    lcd_string("HELLO");
    while(1);
}