/*
 * ledRedStateMachine.c
 *
 *  Created on: Mar 16, 2018
 *      Author: Quoc Bao
 */
/******************************************************************************
 *  Include
 *****************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "ledRedStateMachine.h"
#include "driverlib/gpio.h"
#include "switches.h"
#include "led.h"
#include "uartstdio.h"
#include "debug.h"


/******************************************************************************
 *  Define
 *****************************************************************************/
typedef enum {
    S_LEDON=0,
    S_WAITLEDOFF,
    S_LEDOFF,
    S_WAITLEDON
} ledRState_t;

static ledRState_t State = S_LEDOFF;
uint32_t taskredledcounter = TASKLEDREDINIT;
uint32_t taskredledFlag = 0;

#ifdef  DEBUG
static const char *stateName[4]={
    "S_LEDREDON",
    "S_WAITLEDREDOFF",
    "S_LEDREDOFF",
    "S_WAITLEDREDON"
};
#endif


/******************************************************************************
 *  Function performs LED-Red task
 *****************************************************************************/
void ledRedTask(void)
{
    /* Update state */
    switch (State)
    {
        case S_LEDOFF:
            if (switchState(1) == PRESSED)
            {
                State = S_WAITLEDON;
                DBG("State = %s\n",stateName[State]);
            }
            break;
        case S_WAITLEDON:
            if (switchState(1) == RELEASED)
            {
                State = S_LEDON;
                DBG("State = %s\n",stateName[State]);
            }
            break;
        case S_LEDON:
            if (switchState(1) == PRESSED)
            {
                State = S_WAITLEDOFF;
                DBG("State = %s\n",stateName[State]);
            }
            break;
        case S_WAITLEDOFF:
            if (switchState(1) == RELEASED)
            {
                State = S_LEDOFF;
                DBG("State = %s\n",stateName[State]);
            }
            break;
    }

    /* Control Led */
    switch (State)
    {
        case S_LEDOFF:
            ledControl(LEDRED,OFF);
            break;
        case S_WAITLEDOFF:
            ledControl(LEDRED,OFF);
            break;
        case S_LEDON:
            ledControl(LEDRED,ON);
            break;
        case S_WAITLEDON:
            ledControl(LEDRED,ON);
            break;
    }
}
