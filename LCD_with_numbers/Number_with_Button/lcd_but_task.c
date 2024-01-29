// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 6000000


void Lcd_instruction(unsigned char);//declare the LCD position function to store the possition
void Lcd_preview(unsigned char);//declare the LCD preview function to preview the value
void initial(void);//declare the initial function to provide initial steps
void condition(void);//declare the condition function to provide switch condition
void Lcd_exchange(unsigned int);//declare the LCD exchange function
unsigned char array[20]={"BATT VOLT:     "};
unsigned char sts_low[15]={"BATT LOW"};
unsigned char sts_normal[15]={"BATT NORMAL"};
unsigned char sts_high[12]={"BATT HIGH"};
unsigned char x,m,n,value;
unsigned int d4,d3,d2,d1,j,i,sts[15];

void main()
{
initial();//call the initial function
while(1)//use the while loop
condition();//call the condition statement
}
void initial()//define the initial function
{
    TRISB=0XF0;//set all the lower PORTB pins are output pins and higher pins are input pins
    TRISC=0X00;//set all the PORTC pins are output pins
    TRISD=0X00;//set all the PORTD pins are output pins
    PORTB=0XF0;//set the all PORTB pins are low
    OPTION_REG&=0x7F;//Use optional register to the PORTB in Pull Up mode 
    __delay_ms(100); //set the time delay
    Lcd_instruction(0x30); //Function set command BF cannot be checked 
    __delay_ms(100); //set the time delay
    Lcd_instruction(0x30); //Function set command BF cannot be checked
    __delay_ms(100); //set the time delay
    Lcd_instruction(0x30); //Function set command BF cannot be checked
    __delay_ms(100); //set the time delay
    Lcd_instruction(0x38);//Function set command BF can be checked
    __delay_ms(100); //set the time delay
    Lcd_instruction(0x0c); //Display Shift : Right Shift command
    __delay_ms(100); //set the time delay
    Lcd_instruction(0x01); //Display Clear command
    __delay_ms(100); //set the time delay
    j=150;
    
}
void condition()//define the condition function
{
    value=PORTB&0xF0;//set the value is PORTB
    switch(value)//using switch condition
    {
        case 0xE0://set the case 0xE0 when switch s1 is on
        Lcd_instruction(0x80);//set the position
        for(x=0;x<10;x++)//Using for loop
        {
            Lcd_preview(array[x]);//preview the array value
        }
        Lcd_instruction(0x8B); //set the position
        Lcd_exchange(j);//call the exchange function
        break;
        
        case 0xD0://set the case 0xE0 when switch s2 is on
        j++;
        if(j>225)//Using if condition
        {
            j=225;
        }
        Lcd_instruction(0x88);//set the position
        Lcd_exchange(j);//call the exchange function
        
        break;
        
        case 0xB0://set the case 0xE0 when switch s3 is on
        j--;
        Lcd_instruction(0x88);//set the position
        if(j<150)//Using if condition
        {
            j=150;
        }
        Lcd_exchange(j);//call the exchange function
        break;
        
        case 0x70://set the case 0xE0 when switch s4 is on
        j=155;
        Lcd_instruction(0x88);//set the position
        Lcd_exchange(j);//call the exchange function
        break;
}
}
void Lcd_exchange(unsigned int i)
{
d4=(unsigned char)(i/100);  
d3=(unsigned char)((i-(d4*100))/10);
d2=(unsigned char)(i-(d4*100)-(d3*10));
//d1=(unsigned char)(i-(d4*1000)-(d3*100)-(d2*10));
Lcd_instruction(0x8B);//set the position
Lcd_preview((unsigned char)(0x30+d4));//preview the value
Lcd_instruction(0x8C);//set the position
Lcd_preview((unsigned char)(0x30+d3));//preview the value
Lcd_instruction(0x8D);//set the position
Lcd_preview((unsigned char)('.'));//preview the value of character
Lcd_instruction(0x8E);//set the position
Lcd_preview((unsigned char)(0x30+d2));//preview the value

Lcd_instruction(0xc3); //set the position
if (j >= 150 && j < 175) //Using if condition
{
for(x=0;x<13;x++)//using for loop
{
    Lcd_preview(sts_low[x]);//preview the value
}
}
else if (j >= 175 && j < 205)//Using else if condition
{   
for(x=0;x<13;x++)//using for loop
{
    Lcd_preview(sts_normal[x]);//preview the value
}
}
else if (j >= 205 && j < 225)//Using else if condition
{
for(x=0;x<13;x++)//using for loop
{
    Lcd_preview(sts_high[x]);//preview the value
}
}
}

  
void Lcd_instruction(unsigned char i)//declare the LCD position function
{
    PORTC&=~0x08;//RS value should be LOW RS=0
    PORTD=i;// Send the Instruction to PORTD datapins
    PORTC|=0x01;//Enable the port at high EN=1
    PORTC&=~0x01;//Enable the port at low EN=0
    __delay_ms(20);//set the time delay
}

void Lcd_preview(unsigned char i)
{
    PORTC|=0x08;//RS value become 1
    PORTD=i;//send the preview value to PORTD 
    PORTC|=0x01;//Enable the port at high EN=1
    PORTC&=~0x01;//Enable the port at low EN=0
    __delay_ms(20);//set the time delay
}
