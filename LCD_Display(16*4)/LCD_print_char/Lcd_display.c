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

void Init();  
void LCD_command(unsigned char); 
void LCD_data(unsigned char); 
unsigned char x,i; 
unsigned char array[11]={"HELLO WORLD"}; 
void main() 
{
Init();
LCD_command(0x83);//Using this command to set the printing position
for(x=0;x<11;x++) //Using the for the loop for printing the all elements in array
{
   LCD_data(array[x]); // Call the LCD_data function to print the array elements
}
    while(1);  // Using the While loop continuously print the words
}
void Init()       
{
    TRISC=0x00;        //set the port c as the Output port
    TRISD=0x00;        //set the port D as the Output port
    //__delay_ms(100);   //Set the Time delay
    LCD_command(0x38); //Function set command BF cannot be checked
    __delay_ms(100);   //Set the Time delay
    LCD_command(0x38); //Function set command BF cannot be checked
    __delay_ms(100);   //Set the Time delay
    LCD_command(0x38); //Function set command BF cannot be checked
    __delay_ms(100);   //Set the Time delay
    LCD_command(0x38); //Function set command BF can be checked
    __delay_ms(100);   //set the Time delay
    LCD_command(0x06); //Display Shift : Right Shift command
    __delay_ms(100);   //set the Time delay
    LCD_command(0x0c); //Display ON Cursor OFF command
    __delay_ms(100);   //Set the time delay
    LCD_command(0x01); //Display Clear command
    __delay_ms(100);   //set the Time delay
}

void LCD_data(unsigned char i)//define the LCD_data function
{
    RC3=1;// RS  high
    PORTD=i; // data to PORTD
    RC0=1; //Enable high
    RC0=0; //Enable low
    __delay_ms(100);//Set the delay
}
void LCD_command(unsigned char i) //define the LCD_command function
{
    RC3=0; //RS LOW
    PORTD=i; //command to PORTD
    RC0=1; // Enable high
    RC0=0;// Enable low
    __delay_ms(100);//set the delay    
}