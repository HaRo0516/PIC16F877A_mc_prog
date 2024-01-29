
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 6000000

void Initial(void); //declare the initial function 
void LCD_command(unsigned char); //declare the LCD_Command function
void LCD_data(unsigned char); //declare the LCD_data function
unsigned char x,y,i; //declare the variable
unsigned char my_name[16]={"HARIHARASUDHAN"}; //declare array as name

void main() 
{
Initial(); //call the Initial function 
//Print name in forward direction in 1st ROw
LCD_command(0x81);//Set the Position of printing name
for(x=0;x<15;x++) //Using the for loop
{
   LCD_data(my_name[x]); //call the LCD_data function
}
//print the name in Reverse direction using Left shift 2ed ROW
LCD_command(0x04); //Display Shift : Left Shift command
LCD_command(0xCE); //call the LCD_Command function
for(y=0;y<15;y++)  //Using the for loop
{
   LCD_data(my_name[y]); //call the LCD_data function
}
   while(1); //Using the while loop
}
void Initial(void) 
{
    TRISC=0x00; //set the port_C as Output port
    TRISD=0x00; //set the port_D as Output port
     __delay_ms(100); //set the time delay
    LCD_command(0x30); //Function set command BF cannot be checked 
    __delay_ms(100); //set the time delay
    LCD_command(0x30); //Function set command BF cannot be checked
    __delay_ms(100); //set the time delay
    LCD_command(0x30); //Function set command BF cannot be checked
    __delay_ms(100); //set the time delay
    LCD_command(0x38);//Function set command BF can be checked
    __delay_ms(100); //set the time delay
   LCD_command(0x06); //Display Shift : Right Shift command
    __delay_ms(100);   //set the Time delay
    LCD_command(0x0c); //Display ON Cursor OFF command
    __delay_ms(100);   //Set the time delay
    LCD_command(0x01); //Display Clear command
    __delay_ms(100); //set the time delay
}
void LCD_data(unsigned char i)
{
    RC3=1;// RS  high
    PORTD = i; // data to PORTD
    RC0=1; //Enable high
    RC0=0; //Enable low
    __delay_ms(100);//Set the delay
}
void LCD_command(unsigned char i) 
{ 
    RC3=0; //RS LOW
    PORTD= i; //command to PORTD
    RC0=1; // Enable high
    RC0=0;// Enable low
    __delay_ms(100);//set the delay    
}