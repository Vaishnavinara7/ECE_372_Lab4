#include <avr/io.h>
#include <math.h>

//non-inverting
void initPWMTimer3(){
    //Set Pin number 5 to output
    DDRE |= (1<<DDE3);
    
    //WGM = 0111
    TCCR3A |= (1<<COM3A1)|(1<<WGM31)|(1<<WGM30);
    TCCR3B |= (1<<WGM32)|(1<<CS30);// CS31 and CS32 might need to be set to 0
    TCCR3A &= ~(1<<COM3A0);
        
    //duty cycle to 25%// better to start of 100%
    // OCR3A is frequncy 
    //OCR3A = 255; // not sure
   // OCR4A=1023;
    // duty cycle OCR3B
     //OCR4B=1023;
}

//inverting
void initPWMTimer4(){
    //Set pin numner 6 to output
    DDRH |= (1<<DDH3);
    
    //WGM = 0111
    TCCR4A |= (1<<COM4A1)|(1<<COM4A0)|(1<<WGM41)|(1<<WGM40);
    TCCR4B |= (1<<WGM42)|(1<<CS40);
    //duty cycle to 25% // better to start of 100%
    
    //OCR4A = 1023; // Not sure
    
    // duty cycle OCR3B 
   // OCR4B=1023;
}

void changeDutyCycle(int tenBits){
   //// NEED TO WORK ON ??
    // 0V clockwise
    // 0-2.5 clocwise but decreasing rpm
    // 2.5 no turning
    //2.5 to 5 anticlockwise but increasing rpm, 
    // 5 max rpm
    
    float v = (5.0/1024.0) * tenBits;
 

    if(v > 2.5){
        OCR4A = ((v-2.5)/2.5) * 1023;
        OCR3A = 0;
    }
    else if (fabs(v - 2.5) < 0.0001){      
        OCR3A = 0;
        OCR4A = 0;
    }
    else{
        OCR3A = (1-(v/2.5)) * 1023;
        OCR4A = 0;

    
    
}
