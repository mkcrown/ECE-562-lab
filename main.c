/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

#define PRESS 0
#define RELEASE 1


//TODO: Define states of the state machine

typedef enum stateTypeEnum {
    led1, led2, led3, wait1, wait2, wait3//, debouncePress, debounceRelease, debounceRelease2
} stateType;

//TODO: Use volatile variables that change within interrupts
volatile stateType state;
volatile int count = 0;
//turnOnLED(3);

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.

    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
 
    initTimer1();
    //This function is necessary to use interrupts. 
    state = led3;

    while (1) {

        //TODO: Implement a state machine to create the desired functionality
        switch (state) {
            case wait1:
                turnOnLED(1);
                if(PORTDbits.RD6 == RELEASE && count == 1){
                    state = led3;
                }
                else if(PORTDbits.RD6 == RELEASE && count == 0){
                    state = led2;
                }
                break;
                
            case wait2:
                turnOnLED(2);
                if(PORTDbits.RD6 == RELEASE && count == 1){
                    state = led1;
                }
                else if(PORTDbits.RD6 == RELEASE && count == 0){
                    state = led3;
                }
                break;
                
            case wait3:
                turnOnLED(3);
                if(PORTDbits.RD6 == RELEASE && count == 1){
                    state = led2;
                }
                else if(PORTDbits.RD6 == RELEASE && count == 0){
                    state = led1;
                }
                break;
                
            case led3:
                count = 0;
                TMR1 = 0;
                
                turnOnLED(3);
                if (PORTDbits.RD6 == PRESS){
                    state = wait3;
                }

                break;

            
            case led1:
                count = 0;
                TMR1 = 0;
                
                turnOnLED(1);
                if (PORTDbits.RD6 == PRESS){
                    state = wait1;
                }
                break;


            case led2:
                count = 0;
                TMR1 = 0;
                
                turnOnLED(2);
                if (PORTDbits.RD6 == PRESS){
                    state = wait2;
                }
                break;

           
        }

    }

    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL3SRS)_T1Interrupt() {
    IFS0bits.T1IF = 0;
    count = 1;
}