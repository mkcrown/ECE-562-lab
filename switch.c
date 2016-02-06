/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include <xc.h>

void initSwitch1(){
    //TODO: Initialize switch 1
    TRISDbits.TRISD6 = 1;//set switch to input.
        
    CNCONDbits.ON = 1;//ENABLE INTERRUPT
    CNENDbits.CNIED6 = 1;//enable interrupt
    IEC1bits.CNDIE = 1;//enable allover interrupt   
    IFS1bits.CNDIF = 0;//put flag down    
    CNPUDbits.CNPUD6 = 1;//ENABLE PULL UP RESISTOR
}