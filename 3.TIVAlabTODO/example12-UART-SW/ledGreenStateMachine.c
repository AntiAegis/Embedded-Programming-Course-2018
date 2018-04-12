/*
 * ledRedStateMachine.c
 *
 *  Created on: Mar 16, 2018
 *      Author: Quoc Bao
 */
/******************************************************************************
 *  Include
 *****************************************************************************/
#include <ledGreenStateMachine.h>


/******************************************************************************
 *  Define
 *****************************************************************************/
typedef enum {
    S_LEDON,
    S_LEDOFF
}ledGState_t;

static ledGState_t State = S_LEDOFF;
uint32_t taskgreenledcounter = TASKLEDGREENINIT;
uint32_t taskgreenledFlag;

#define     BUFF_LEN    64
uint32_t flg_CRLF;
char buffer[BUFF_LEN];
uint32_t pBuffer;

#ifdef  DEBUG
static const  char *stateName[]={
    "S_LEDGREENON",
    "S_LEDGREENOFF"
};
#endif


/******************************************************************************
 *  Function
 *****************************************************************************/
void UARTIntHandler()
{
    char data;
    UARTIntClear(UART0_BASE, UARTIntStatus(UART0_BASE, 1));
    while(UARTCharsAvail(UART0_BASE))
    {
        data = UARTCharGetNonBlocking(UART0_BASE);
        if(data==10)
        {
            IntDisable(INT_UART0);
            flg_CRLF = 1;
            pBuffer++;
        }
        else
        {
            buffer[pBuffer] = data;
            if(++pBuffer == BUFF_LEN)
                pBuffer = 0;
        }
    }
}


/******************************************************************************
 *  Function
 *****************************************************************************/
void processCommand()
{
    buffer[pBuffer] = 0;
    if(strcmp((const char*)buffer, "LED GREEN ON")==0)
    {
        ledControl(LEDGREEN, ON);
        DBG("State = %s\n",stateName[State]);
    }
    else if(strcmp((const char*)buffer, "LED GREEN OFF")==0)
    {
        ledControl(LEDGREEN, OFF);
        DBG("State = %s\n",stateName[State]);
    }
}


/******************************************************************************
 *  Function
 *****************************************************************************/
void clearBuffer()
{
    uint32_t i = 0;
    for(i=0; i<BUFF_LEN; i++)
        buffer[i] = 0;
    pBuffer = 0;
}


/******************************************************************************
 *  Function
 *****************************************************************************/
static void ledGreenStateUpdate()
{
    if(flg_CRLF)
    {
        processCommand();
        clearBuffer();
        flg_CRLF = 0;
        IntEnable(INT_UART0);
    }
}


/******************************************************************************
 *  Function
 *****************************************************************************/
void ledGreenTask(void *myobject)
{
    ledGreenStateUpdate();
}
