/*
 * File:   UART_cls_work_1.c
 * Author: HaRo
 *
 * Created on September 2, 2023, 9:00 PM
 */


#include <xc.h>
void init();//declare the initial function
int rec_info;//declare the variable

void main()//define the main function
{
    init();//call the initial function
    while(1)//using while loop as super loop
    {
        if(PIR1&0x20)//using if condition to check all bits are received
        {
            rec_info=RCREG;//store the received variable in data
        switch(rec_info)//using switch condition
        {
            case 'A': PORTD=0x01;//set the CASE A when blink RD0 LED
            break;
            case 'B': PORTD=0x02;//set the CASE B when blink RD1 LED
            break;
            case 'C': PORTD=0x04;//set the CASE C when blink RD2 LED
            break;
            case 'D': PORTD=0x08;//set the CASE D when blink RD3 LED
            break;
        }
        }
    }
    
}
void init()
{
    TRISD=0x00;//set the all PORTD pins are output pins 
    PORTD=0x00;//set the all PORTD pins are high
    TRISC=0xc0;//set the RC7 & RC6 pins are input others output
    RCSTA=0x90;//set RCSTA register to 1001 0000
    TXSTA=0x20;//set TXSTA register to 0010 0000
    SPBRG=0x09;//set SPBRG register to 0000 1001
}