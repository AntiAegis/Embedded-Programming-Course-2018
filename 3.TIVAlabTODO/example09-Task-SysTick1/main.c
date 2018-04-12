/******************************************************************************
 *  Include
 *****************************************************************************/
#include <stdbool.h>
#include <stdint.h>

#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"

#include "switches.h"
#include "led.h"
#include "debug.h"

#include <ledGreenStateMachine.h>
#include <ledRedStateMachine.h>


/******************************************************************************
 *  Function initializes console
 *****************************************************************************/
#ifdef DEBUG
void InitConsole()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTStdioConfig(0, 115200, 16000000);
}
#endif


/******************************************************************************
 *  Function setups system
 *****************************************************************************/
void setupSystem()
{
    /* Clock and SysTick */
    SysCtlClockSet(
        SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_OSC_MAIN|SYSCTL_XTAL_16MHZ);
    SysTickPeriodSet(SysCtlClockGet()/1000);
    IntMasterEnable();
    SysTickIntEnable();
    SysTickEnable();

    /* Initialize Switch, LED */
    switchInit();
    ledInit();
#ifdef  DEBUG
    InitConsole();
    DBG("\nState machine demonstration\n");
    DBG("\nDebug is ON\n\n");
#endif
}


/******************************************************************************
 *  ISR of SysTick
 *****************************************************************************/
void SysTickIntHandler()
{
    if (ledGTimer>0) ledGTimer--;

    if (taskredledcounter == 0)
    {
        taskredledcounter = TASKLEDREDPERIOD;
        taskredledFlag = 1; //set Flag to signal the main loop to run the task
    }
    else taskredledcounter--;
}


/******************************************************************************
 *  Main execution
 *****************************************************************************/
void main()
{
    setupSystem();
    while(1)
    {
        ledGreenStateMachineUpdate();
        if(taskredledFlag)
        {
            taskredledFlag = 0;
            ledRedTask();
        }
    }
}
