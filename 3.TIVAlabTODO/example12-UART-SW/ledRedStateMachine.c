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
    S_LEDON,
    S_LEDOFF
}ledRState_t;

static ledRState_t State = S_LEDOFF;
uint32_t            taskredledcounter = TASKLEDREDINIT;
uint32_t            taskredledFlag = 0;

#ifdef  DEBUG
static const  char *stateName[]={
    "S_LEDREDON",
    "S_LEDREDOFF"
};
#endif


/******************************************************************************
 *  Function
 *****************************************************************************/
static void ledRedStateMachineUpdate()
{
    switch (State)
    {
        case S_LEDOFF:
            if (switchState(1) == PRESSED)
                {
                    State = S_LEDON;
                    DBG("State = %s\n",stateName[State]);
                }
            break;
        case S_LEDON:
            if (switchState(1) == RELEASED)
                {
                    State = S_LEDOFF;
                    DBG("State = %s\n",stateName[State]);
                }
            break;
    }

    switch (State)
    {
    case S_LEDOFF:
        ledControl(LEDRED,OFF);
        break;
    case S_LEDON:
        ledControl(LEDRED,ON);
    }
}


/******************************************************************************
 *  Function
 *****************************************************************************/
void ledRedTask(void *myobject)
{
    ledRedStateMachineUpdate();
}
