#ifndef GLOBALS_H
#define GLOBALS_H

/*
===============
I/O pins setup
===============
*/

//ALLOWED PINS FOR PWM (analogWrite):
//5, 6, 9, 10

#define PIN_FLOW_SENSOR_INPUT 2 
#define PIN_WATER_PUMP 6
#define PIN_SETPOINT_ADJ_INPUT A0
#define PIN_SETPOINT_ADJ_BUTTON 9

/*
===============
Constants
===============
*/
#define MAX_TIMER_INTERRUPTS 8 // 99.84 ms interrupts ~ 100 ms interrupts




/*
===============
PID-related
===============
*/

#define KP 3.0
#define KI 1.5
#define KD 0.5

#define MOTOR_MAX 100
#define MOTOR_MIN 0

#define SETPOINT_MAX 20
#define SETPOINT_MIN 5

#endif



/*
===============
Prototypes
===============
*/
extern void Timer2Setup(void);
extern unsigned int getSetPointValue(void);



/*
===============
Global vars
===============
*/
extern volatile unsigned long pulseCount;
extern volatile unsigned long avgCount;
extern volatile unsigned int interruptCounts; //Accumulator used to reduce timer interrupt rate

extern volatile unsigned int ledStatus;

extern volatile unsigned int pidSetPoint;
extern volatile unsigned int pidOutput;
