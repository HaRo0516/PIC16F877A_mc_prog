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

void init(void);
void LCD_Command(unsigned char);
void LCD_Data(unsigned char);
void delay(unsigned int);
void LCD_Output(unsigned int);
unsigned char j,k[10],equal,plus;
unsigned int num1,num2,add,delaycount,m,n;

void main() //define the main function
{
    init();          
    num1=523;            
    num2=238;            
    equal='=';           
    plus='+';            
    LCD_Command(0x80);  
    LCD_Output(num1);  
    LCD_Command(0x83);  
    LCD_Data(plus);   
    LCD_Command(0x84);  
    LCD_Output(num2);  
    LCD_Command(0x87);  
    LCD_Data(equal);  
    LCD_Command(0x88);  
    add=num1+num2;       
    LCD_Output(add);    
    while(1);
    
}
void init(void)
{
    TRISC=0x00; //set all the PORTC pins are output pins
    TRISD=0x00; //set all the PORTD pins are output pins 
    __delay_ms(100); //set the time delay
    LCD_Command(0x30); //Function set command BF cannot be checked 
    __delay_ms(100); //set the time delay
    LCD_Command(0x30); //Function set command BF cannot be checked
    __delay_ms(100); //set the time delay
    LCD_Command(0x30); //Function set command BF cannot be checked
    __delay_ms(100); //set the time delay
    LCD_Command(0x38);//Function set command BF can be checked
    __delay_ms(100); //set the time delay
    LCD_Command(0x0c); //Display Shift : Right Shift command
    __delay_ms(100); //set the time delay
    LCD_Command(0x01); //Display Clear command
    __delay_ms(100); //set the time delay
}
void LCD_Output(unsigned int i) 
{
    unsigned char s,j=1; //declare the unsigned char value
    m=i;//store the given value to m
    while(m!=0)//using while loop
    {
    s = (unsigned char) (m-((m/10) * 10));//using formula to separate the value
    k[j]=s;//using the array function
    j++;//increment the j value
    m= m/10;//reduce the m value
    }
    k[j]='\0';//set the null value
    j=j-1;//reduce the j value
    while(j!=0)//using while loop
    {
    n=0x30+k[j];//convert char to integer
    LCD_Data((unsigned char)(n));//print the character value
    j--;//reduce the j value
    }
}
void LCD_Command(unsigned char i) 
{
    PORTC&=~0x08; //RS value should be high RS=0
    PORTD=i;// read the data to PORTD
    PORTC|=0x01; //Enable the port at high EN=1
    PORTC&=~0x01; //Enable the port at low EN=0
    delay(100); //set the time delay
}
void LCD_Data(unsigned char i)
{
    PORTC|=0x08;//RS value should be low RS=1
    PORTD=i;// read the data to PORTD
    PORTC|=0x01;//Enable the port at high
    PORTC&=~0x01;//Enable the port at low EN=1
    delay(100);//set the time delay EN=0
}
void delay(unsigned int delaycount)//I use two type of delay in the code but 1 is enough.
{
    while(--delaycount);//using while loop to reduce the delay count
}