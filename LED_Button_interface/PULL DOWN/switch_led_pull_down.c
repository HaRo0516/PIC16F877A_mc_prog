/*
 * File:   switch_led_pull_down.c
 * Author: HaRo
 *
 * Created on July 11, 2023, 10:58 AM
 */


#include <xc.h>
#define _XTAL_FREQ 6000000

unsigned char val;
void main() 
{
    
    TRISC=0x0F;//set RC1-RC3 is the Input Pins and other pins are output pin
    TRISD=0x00;//All RD pins are output pin
    PORTC=0x0F;//All RC0-RC3 pins are high state other pins are low state 
    PORTD=0x00;//All RD pins are low state
    
    while(1)
    {
    val=PORTC;//assign PORTC as value
    switch(val)//Using switch condition
    {
        case 0x01: PORTD=0x20;//the statement if RC0 switch is ON then RD3=0 & RD5=1 0010 0000
        break;//break the statement
        case 0x02: PORTD=0x08;//the statement if RC1 switch is ON then RD3=1 & RD5=0 0000 1000
        break;//break the statement
        case 0x04: PORTD=0x28;//the statement if RC2 switch is ON then RD3=1 & RD5=1 0010 1000
        break;//break the statement
        case 0x08: PORTD=0x00;//the statement if RC3 switch is ON then RD3=0 & RD5=0 0000 0000
        break;//break the statement
        default: PORTD=0x00;//If all Switch is off LED is OFF. 0000 0000 
    }
    
    }
}
    


