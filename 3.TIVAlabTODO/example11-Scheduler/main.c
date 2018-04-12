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
#include "scheduler.h"


/******************************************************************************
 *  Include
 *****************************************************************************/
#ifdef DEBUG
void
InitConsole(void)
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
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);
    switchInit();
    ledInit();
#ifdef  DEBUG
    InitConsole();
#endif
    DBG("\nState machine demonstration\n");
    DBG("\nDebug is ON\n\n");
    SchedulerInit(1000);    //systick is 1 ms
}


/******************************************************************************
 *  Main execution
 *****************************************************************************/
void main()
{
    setupSystem();
    while(1) SchedulerRun();
}
