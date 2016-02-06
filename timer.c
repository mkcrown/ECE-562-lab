/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    T1CONbits.TCKPS = 3;//initial prescalar to 256
    T1CONbits.TCS = 0;//setting the oscillator
    TMR1 = 0;//clear timer 1
    PR1 = 39062;//initial 1 second PR1 
    IFS0bits.T1IF = 0;//put flag down
    IPC1bits.T1IP = 3;
    IPC1bits.T1IS = 3;
    IEC0bits.T1IE = 1;//enable interrupt 
    T1CONbits.TON = 1;//turn the timer on
}

initTimer2(){
    //TODO: Initialize Timer 2.
    TMR2 = 0;//clear timer 2
    T2CONbits.TCKPS = 0;//initial prescalar to 1
    T2CONbits.TCS = 0;//setting the oscillator
    
    IFS0bits.T2IF = 0;//put flag down
    
    
    
}

