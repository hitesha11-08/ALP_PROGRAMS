#include <reg51.h>

sbit RS = P2^0;
sbit EN = P2^1;

#define LCD P1

void delay(unsigned int ms) {
    unsigned int i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<1275;j++);
}

void enable() {
    EN = 1;
    delay(1);
    EN = 0;
}

void send4bit(unsigned char value) {   // ? fixed (no 'data' keyword)
    LCD = value;                       
    enable();
}

void lcd_cmd(unsigned char cmd) {
    RS = 0;
    send4bit(cmd & 0xF0);             // high nibble
    send4bit((cmd << 4) & 0xF0);      // low nibble
    delay(2);
}

void lcd_data(unsigned char dat) {
    RS = 1;
    send4bit(dat & 0xF0);
    send4bit((dat << 4) & 0xF0);
    delay(2);
}

void lcd_init() {
    delay(50);

    send4bit(0x30);
    delay(5);
    send4bit(0x30);
    delay(5);
    send4bit(0x30);
    delay(5);
    send4bit(0x20);   // 4-bit mode

    lcd_cmd(0x28); // 4-bit, 2 line
    lcd_cmd(0x0C); // display ON
    lcd_cmd(0x06); // cursor increment
    lcd_cmd(0x01); // clear display
    delay(5);
}

void main() {
    lcd_init();

    lcd_cmd(0x80);   // first line

    lcd_data('H');
    lcd_data('E');
    lcd_data('L');
    lcd_data('L');
    lcd_data('O');

    while(1);
}
