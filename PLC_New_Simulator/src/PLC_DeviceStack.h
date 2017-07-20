/*
 * PLCDeviceStack.h
 *
 *  Created on: 2014. 11. 5.
 *      Author: skson
 */

#ifndef PLC_DEVICESTACK_H_
#define PLC_DEVICESTACK_H_
#include "PLC_IL_Task.h"
#define STACK_SIZE 256
#define STACK_TRUE 1
#define STACK_FALSE 0xFFFF
typedef struct{
	unsigned char stack[STACK_SIZE];
	unsigned char size;
} PLC_Device_Stack ;

//unsigned char STACK_isFull(PLC_Device_Stack* device_stack);
#define STACK_isFull(device_stack) (((PLC_Device_Stack*)device_stack)->size==STACK_SIZE)

//unsigned char STACK_isEmpty(PLC_Device_Stack* device_stack);
#define STACK_isEmpty(device_stack) (((PLC_Device_Stack*)device_stack)->size==0)

//unsigned char STACK_getSize(PLC_Device_Stack* device_stack);
#define STACK_getSize(device_stack) (((PLC_Device_Stack*)device_stack)->size)

unsigned short STACK_push(PLC_Device_Stack* device_stack, unsigned char in);
unsigned short STACK_overwrite(PLC_Device_Stack* device_stack, unsigned char in);
unsigned short STACK_pull(PLC_Device_Stack* device_stack);
void STACK_clear(PLC_Device_Stack* device_stack);
unsigned short STACK_pick(PLC_Device_Stack* device_stack);

unsigned short STACK_get(PLC_Device_Stack* device_stack, unsigned char index);
unsigned short STACK_set(PLC_Device_Stack* device_stack, unsigned char index, unsigned char value);

#endif /* PLCDEVICESTACK_H_ */
