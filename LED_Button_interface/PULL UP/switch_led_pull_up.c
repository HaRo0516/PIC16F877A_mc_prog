/*
 * File:   switch_led_pull_up.c
 * Author: HaRo
 *
 * Created on July 11, 2023, 10:58 AM
 */


#include <xc.h>
#define _XTAL_FREQ 6000000

unsigned char val;
void main() 
{
    
    TRISB=0xF0;//set RB4-RB7 is the Input Pins and other pins are output pin
    TRISD=0x00;//All RD pins are output pin
    PORTB=0xF0;//set RB4-RB7 pin High state
    PORTD=0x00;//All RD pins are low state
    OPTION_REG&=0x7F;
    
    while(1)
    {
    val=PORTB;//assign PORTB as value
    switch(val)
    {
        case 0xE0: PORTD=0x10;//the statement if RB4 switch is ON then RD4 pin is ON
        break;//break the statement
        case 0xD0: PORTD=0x18;//the statement if RB5 switch is ON then RD3 & RD4 pin only ON 
        break;//break the statement
        case 0xB0: PORTD=0x00;//the statement if RB6 switch is ON then All pin is OFF
        break;//break the statement
        case 0x70: PORTD=0x08;//the statement if RB7 switch is ON then RD3 pin is ON 
        break;//break the statement
        case 0xF0: PORTD=0x00;//the statement if All RB switch is OFF then ALL RD pins are OFF 
        break;//break the statement
    }
    
    }
}
    


