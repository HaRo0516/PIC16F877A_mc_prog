/*
 * File:   switch_tech.c
 * Author: HaRo
 *
 * Created on July 11, 2023, 8:26 AM
 */


#include <xc.h>
#define _XTAL_FREQ 6000000

unsigned char val;
void main() 
{
    
    TRISB=0xF0;//set RB4-RB8 is the Input Pins and other pins are output pin
    TRISC=0x00;//All RC pins are output pin
    PORTB=0x00;//all RB pins low state 
    PORTC=0x00;//All RC pins are low state
    
    while(1)//Using While loop
    {
         val=PORTB;//assign portB as val
    switch(val)//Using switch condition
    {
        case 0xE0: PORTC=0x0C;//the statement if RB4 switch is ON then RC3 and RC4 pins is on 
        break;//break the statement
        case 0xD0: PORTC=0x08;//the statement if RB5 switch is ON then RC3 pin only on 
        break;//break the statement
        case 0xB0: PORTC=0x04;//the statement if RB6 switch is ON then RC3 and RC4 pins is on 
        break;//break the statement
        case 0x70: PORTC=0x00;//the statement if RB7 switch is ON then RC3 and RC4 pins is on 
        break;//break the statement
        case 0xF0: PORTC=0x00;//the statement if All RB switch is OFF then ALL RC pins are OFF  
        break;//break the statement
    }
    
    }
}
    

