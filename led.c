/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"

void initLEDs(){
    //TODO: Initialize LEDs
    TRISDbits.TRISD0 = 0;//initialize all led off
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    

}

void turnOnLED(int led){
    
    //TODO: You may choose to write this function
    // as a matter of convenience
    
    if(led == 1)
    {
        LATDbits.LATD0 = 1;//turn on led 1
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 0; 
    }
    
    else if(led==2)
    {
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 1;
        LATDbits.LATD2 = 0;
    }
    
    else if (led==3)
    {
        LATDbits.LATD0 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD2 = 1;
    }
    
}