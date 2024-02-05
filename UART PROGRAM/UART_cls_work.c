/*
 * File:   UART_cls_work.c
 * Author: HaRo
 *
 * Created on September 2, 2023, 9:00 PM
 */


#include <xc.h>
#define _XTAL_FREQ 6000000
void init();//declare the initial function
int swith_info;//declare the variable

void main()//define the main function
{
    init();//call the initial function
    while(1)//using while loop as super loop
    {
        swith_info=PORTB;//set the transmit bit
        switch(swith_info)//using switch condition
        {
            case 0xE0: TXREG='A';//set the case when switch1 is on transmit A
            __delay_ms(1000);//set the delay 
            break;
            case 0xD0: TXREG='B';//set the case when switch2 is on transmit B
            __delay_ms(1000);//set the delay 
            break;
            case 0xB0: TXREG='C';//set the case when switch2 is on transmit C
            __delay_ms(1000);//set the delay 
            break;
            case 0x70: TXREG='D';//set the case when switch2 is on transmit D
            __delay_ms(1000);//set the delay 
            break;
        }
        
    }
    
}
void init()//define the setup function
{
    TRISB=0xF0;//set the RD7-RD4 is input and remind output pins
    PORTB=0x00;//set all PORTD pins are low
    OPTION_REG&=0x7F;//st the optional register to on the pull-up
    TRISC=0xC0;//set the PORTC RC7,RC6 as input pins
    RCSTA=0x90;//set the value 1001 0000 in RCSTA register
    TXSTA=0x20;//set the value 0010 0000 in TXSTA register
    SPBRG=0x09;//set the value 0000 1001 in SPBRRG register
}