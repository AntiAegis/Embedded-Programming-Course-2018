/******************************************************************************
 *  Include
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


/******************************************************************************
 *  Definitions
 *****************************************************************************/
/* Circular buffer struct */
struct t_s_cbuff
{
    uint8_t write;	// Write before increment
    uint8_t read;	// Read before increment
    uint8_t len;	// Len of circular buffer
    uint8_t *addr;	// Storage location
};

/* Declare a circular struct */
#define def_cbuff(name,len) 	uint8_t arr_##name[len];   		\
                            	struct t_s_cbuff s_cbuff_##name = {0, 0, len, arr_##name};


/******************************************************************************
 *  Functions
 *****************************************************************************/
bool circularWrite(struct t_s_cbuff *s_cbuff, uint8_t val);
bool circularRead(struct t_s_cbuff *s_cbuff, uint8_t *addr_val);
void performWrite(struct t_s_cbuff *s_cbuff, uint8_t val);
void performRead(struct t_s_cbuff *s_cbuff, uint8_t *addr_val);

