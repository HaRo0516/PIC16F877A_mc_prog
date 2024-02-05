/*
 * File:   UART_master_task.c
 * Author: HaRo
 *
 * Created on September 3, 2023, 10:35 PM
 */
#include <xc.h>
#define _XTAL_FREQ 6000000
void setup();//initialize the initial
int input,data;//declare the integer

void main()//define the main function
{
    setup();//call the setup 
    while(1)//using the while loop super loop
    {
        input=PORTB;//set the transmit data
        switch(input)//using switch condition
        {
            case 0xE0: TXREG='A';//set the case when switch1 is on transmit A
            __delay_ms(1000);//set the delay 
            break;
            case 0xD0: TXREG='B';//set the case when switch2 is on transmit B
            __delay_ms(1000);//set the delay 
            break;
            case 0xB0: TXREG='C';//set the case when switch3 is on transmit C
            __delay_ms(1000);//set the delay
            break;
            case 0x70: TXREG='D';//set the case when switch 4 is on transmit D
            __delay_ms(1000);//set the delay
            break;
        }
        if(PIR1&0x20)//using if condition to check all bits are received 
        {
            data=RCREG;//store the received data 
            switch(data)// using switch condition
            {
                case'a':PORTD=0x01;//set the case 'a' when blink RD0
                break;
                case'b':PORTD=0x02;//set the case 'b' when blink RD1
                break;
                case'c':PORTD=0x00;//set the case 'c' when blink RD0 & RD1 is off
                break; 
                case'd':PORTD=0x03;//set the case 'd' when blink RD0 & RD1 is ON
            }    
        }
    }
}
void setup()//define the setup function
{
    TRISD=0xFC;//set the RD7-RD2 is input and remind output pins
    PORTD=0x00;//set all PORTD pins are low
    TRISB=0xF0;//set the RB7-RB4 is input pins
    PORTB=0x00;//set the all PORTD pins are low
    OPTION_REG&=0x7F;//st the optional register to on the pull-up
    TRISC=0xC0;//set the PORTC RC7,RC6 as input pins 
    RCSTA=0x90;//set the value 1001 0000 in RCSTA register
    TXSTA=0x20;//set the value 0010 0000 in TXSTA register
    SPBRG=0x09;//set the value 0000 1001 in SPBRRG register
}