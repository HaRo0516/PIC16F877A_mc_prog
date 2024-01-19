/*
 * File:   two_led_blinking.c
 * Author: HaRo
 *
 * Created on July 10, 2023, 1:21 PM
 */

#include <xc.h>
#define _XTAL_FREQ 6000000

unsigned char val;

void main() 
{
    TRISC=0xBD;
    while(1)
    {
    PORTC=0x40;
    __delay_ms(3200);
    PORTC=0x00;
    __delay_ms(3200);
    PORTC=0x02;
    __delay_ms(3200);
    PORTC=0x42;
    __delay_ms(3200);
    }
}    
