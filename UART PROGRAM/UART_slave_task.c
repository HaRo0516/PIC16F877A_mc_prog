/*
 * File:   UART_slave_task.c
 * Author: HaRo
 *
 * Created on September 3, 2023, 10:38 PM
 */
#include <xc.h>
#define _XTAL_FREQ 6000000

void setup(void);//declare the setup function
int data,re_data;//declare the integer
void lcd_possition(unsigned char);//declare the lcd_possition 
void lcd_value(unsigned char);//declare the lcd_value
void element();//declare the element function
unsigned char i,val,a[10]={"REC SGNL:"},b[10]={"SND SGNL:"};//declare the unsigned char
void main()//define the main function
{
    setup();//call the setup function
    element();//call the element function
    while(1)//use the while loop as super loop
    {
        if(PIR1&0x20)//using if condition to check all bits are received
        {
           data=RCREG;//store the received variable in data
        switch(data)//using switch condition
        {
            case 'A'://set the CASE
            lcd_possition(0x8B);//set the LCD possition
            lcd_value(data);//print the value in LCD
            __delay_ms(1000);//using some delay
            break;
            case 'B'://set the CASE
            lcd_possition(0x8B);//set the LCD possition
            lcd_value(data);//print the value in LCD
            __delay_ms(1000);//using some delay
            break;
            case 'C': //set the CASE
            lcd_possition(0x8B);//set the LCD possition
            lcd_value(data);//print the value in LCD
            __delay_ms(1000);//using some delay
            break;
            case 'D': //set the CASE
            lcd_possition(0x8B);//set the LCD possition
            lcd_value(data);//print the value in LCD
            __delay_ms(1000);//using some delay
            break;
        }
        }
        switch (data)//Using another switch condition to send the data
        {
            case 'A': //set the case
            lcd_possition(0xCB);//set the LCD possition
            re_data='a';//set the transmitted data
            lcd_value(re_data);//print the received data
            TXREG='a';//transmit the value using TXREG register
            __delay_ms(1000);//set the delay
            break;
            case 'B': //set the case
            lcd_possition(0xCB);//set the LCD possition
            re_data='b';//set the transmitted data
            lcd_value(re_data); //print the received data
            TXREG='b';//transmit the value using TXREG register
            __delay_ms(1000);//set the delay
            break;
            case 'C': //set the case
            lcd_possition(0xCB);//set the LCD possition
            re_data='c';//set the transmitted data
            lcd_value(re_data);//print the received data
            TXREG='c';//transmit the value using TXREG register
            __delay_ms(1000);//set the delay
            break;
            case 'D': //set the case
            lcd_possition(0xCB);//set the LCD possition
            re_data='d';//set the transmitted data
            lcd_value(re_data);//print the received data
            TXREG='d';//transmit the value using TXREG register
            __delay_ms(1000);//set the delay
            break;
        }
    }
    
}
void setup()//define the setup function
{
    TRISC=0xC0;//set the RC7,RC6 bits are input other bits are output in PORTD
    TRISD=0x00;//set the All PORTD pins are set to 0
    RCSTA=0x90;//set the value 1001 0000 in RCSTA register
    TXSTA=0x20;//set the value 0010 0000 in TXSTA register
    SPBRG=0x09;//set the value 0000 1001 in SPBRRG register
    lcd_possition(0x00);//set the initial function of led_preview
    __delay_ms(50);//set the delay function
    lcd_possition(0x00);//set the initial function of led_preview
    __delay_ms(50);//set the delay function
    lcd_possition(0x00);//set the initial function of led_preview
    __delay_ms(50);//set the delay function
    lcd_possition(0x38);//Function set command BF can be checked
    __delay_ms(50);//set the delay function
    lcd_possition(0x06);//set the shift command : RIGHT Shift
    __delay_ms(50);//set the delay function
    lcd_possition(0x0C);//set the cursor off and display on
    __delay_ms(50);//set the delay function
    lcd_possition(0x01);//set the clear display command
    __delay_ms(50);//set the delay function 
}
void element()//define the element function
{
    int i,j;//declare the local variable as i,j
    lcd_possition(0x80);//set the possition of the LCD
    for(i=0;i<10;i++)//using for loop when print the string
    {   
        lcd_value(a[i]);//send the value to the LCD
    }
    lcd_possition(0xC0);//set the possition of LCD
    for(j=0;j<10;j++)//using for loop when print the string
    {
        lcd_value(b[j]);//send the value to the LCD
    }
}
void lcd_possition(unsigned char i)//Define the LCD possition
{
    PORTC&=~0x08;//set the RS value as 0
    PORTD=i;//send the data to PORTD register
    PORTC|=0x01;//set the enable pin as 1
    PORTC&=~0x01;//set the enable pin as 0
    __delay_ms(10);//set the time delay
}
void lcd_value(unsigned char i)//define the LCD value
{
    PORTC|=0x08;//set the RS value as 0
    PORTD=i;//send the data to PORTD register
    PORTC|=0x01;// set the enable pin as 1
    PORTC&=~0x01;//set the enable pin as 0
    __delay_ms(10);//set the time delay
}