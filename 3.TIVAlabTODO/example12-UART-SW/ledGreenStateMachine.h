/*
 * ledRedStateMachine.h
 *
 *  Created on: Mar 16, 2018
 *      Author: Quoc Bao
 */

#ifndef LEDGREENSTATEMACHINE_H_
#define LEDGREENSTATEMACHINE_H_

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/interrupt.h"
#include "switches.h"
#include "led.h"
#include "uartstdio.h"
#include "debug.h"

#define     TASKLEDGREENPERIOD    1      //period is 50 ms
#define     TASKLEDGREENINIT      1    //start after 1 ms
extern      uint32_t            taskgreenledcounter;
extern      uint32_t            taskgreenledFlag;

void UARTIntHandler();
void ledGreenTask(void *myobject);

#endif /* LEDGREENSTATEMACHINE_H_ */
