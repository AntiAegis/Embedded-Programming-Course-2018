/******************************************************************************
 *  Include
 *****************************************************************************/
#include "cbuff.h"


/******************************************************************************
 *  Functions
 *****************************************************************************/
/*
 *  Description:
 *		Write a data byte into a circular buffer. The writing operation is done
 *		before increasing the write index.
 *
 *  Input:
 *		s_cbuff	: Address of the circular buffer struct.
 *		val 	: Value of the data byte.
 *
 *  Output:
 *		(bool) 	: Success of writing operation.
 */
bool circularWrite(struct t_s_cbuff *s_cbuff, uint8_t val)
{
	if((s_cbuff->write+1)%s_cbuff->len == s_cbuff->read)	// Storage full, wasting 1 slot
		return false;
	else													// Storage available
	{
		s_cbuff->addr[s_cbuff->write] = val;
		if(++(s_cbuff->write) == s_cbuff->len) s_cbuff->write = 0;
		return true;
	}
}
//-----------------------------------------------------------------------------
/*
 *  Description:
 *		Read a data byte from a circular buffer. The reading operation is done
 *		after increasing the read index.
 *
 *  Input:
 *		s_cbuff 	: Address of the circular buffer struct.
 *		addr_val 	: Address of the data byte.
 *
 *  Output:
 *		(bool) 		: Success of reading operation.
 */
bool circularRead(struct t_s_cbuff *s_cbuff, uint8_t *addr_val)
{
	if(s_cbuff->write == s_cbuff->read)	// Data empty
		return false;
	else								// Data available
	{
		*addr_val = s_cbuff->addr[s_cbuff->read];
		if(++(s_cbuff->read) == s_cbuff->len) s_cbuff->read = 0;
		return true;
	}
}
//-----------------------------------------------------------------------------
/*
 *  Description:
 *		Write a data byte into a circular buffer and display the result. 
 *
 *  Input:
 *		s_cbuff : Address of the circular buffer struct.
 *		val 	: Value of the data byte.
 *
 *  Output:
 *		(void)
 */
void performWrite(struct t_s_cbuff *s_cbuff, uint8_t val)
{
	if(circularWrite(s_cbuff, val))
		printf(">> Successful writing.\n");
	else
		printf(">> Fail writing.\n");
}
//-----------------------------------------------------------------------------
/*
 *  Description:
 *		Read a data byte from a circular buffer and display the result.
 *
 *  Input:
 *		s_cbuff 	: Address of the circular buffer struct.
 *		addr_val 	: Address of the data byte.
 *
 *  Output:
 *		(void)
 */
void performRead(struct t_s_cbuff *s_cbuff, uint8_t *addr_val)
{
	if(circularRead(s_cbuff, addr_val))
		printf(">> Read data: [%d]%c\n", *addr_val, *addr_val);
	else
		printf(">> Fail reading.\n");
}

