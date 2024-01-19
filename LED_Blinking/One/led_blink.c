/*
 * File:   led_blink.c
 * Author: HaRo
 *
 * Created on July 10, 2023, 12:54 PM
 */


#include <xc.h>
#define _XTAL_FREQ 6000000

unsigned char val;

void main() 
{
    TRISC=0xFB;
    while(1)
    {
    PORTC=0x04;
    __delay_ms(1200);
    PORTC=0x00;
    __delay_ms(1200);
    }
}    
