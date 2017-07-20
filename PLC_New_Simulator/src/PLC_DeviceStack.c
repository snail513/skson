/*
 * PLCDeviceStack.c
 *
 *  Created on: 2014. 11. 5.
 *      Author: skson
 */
#ifndef PLC_DEVICESTACK_H_
#include "PLC_Definitions.h"
#include "PLC_DeviceStack.h"
#endif
/*unsigned char STACK_isFull(PLC_Device_Stack* device_stack){
	return device_stack->size==STACK_SIZE;
}
unsigned char STACK_isEmpty(PLC_Device_Stack* device_stack){
	return device_stack->size==0;
}
unsigned char STACK_getSize(PLC_Device_Stack* device_stack){
	return device_stack->size;
}*/
inline unsigned short STACK_push(PLC_Device_Stack* device_stack,unsigned char in){
	if(STACK_isFull(device_stack))
		return STACK_FALSE;
	device_stack->stack[device_stack->size] = in;
	device_stack->size++;

	return STACK_TRUE;

}
inline unsigned short STACK_overwrite(PLC_Device_Stack* device_stack, unsigned char in){
	if(STACK_isEmpty(device_stack))
		return STACK_FALSE;
	STACK_pull(device_stack);
	return STACK_push(device_stack, in);
}
inline unsigned short STACK_pull(PLC_Device_Stack* device_stack){
	if(STACK_isEmpty(device_stack))
		return STACK_FALSE;
	device_stack->size--;
	unsigned short ret = device_stack->stack[device_stack->size] & 0x0FF;

	return ret;
}
inline unsigned short STACK_pick(PLC_Device_Stack* device_stack){
	return STACK_isEmpty(device_stack)? STACK_FALSE : device_stack->stack[device_stack->size-1] & 0x01;
}
inline unsigned short STACK_get(PLC_Device_Stack* device_stack, unsigned char index){
	return index>=STACK_SIZE? STACK_FALSE : device_stack->stack[index] & 0x01;
}
inline unsigned short STACK_set(PLC_Device_Stack* device_stack, unsigned char index, unsigned char value){
	if(index>=STACK_SIZE)
		return STACK_FALSE;
	device_stack->stack[index] = value;
	//DBG_LOGPRINT("\t[STACK]setting [%d]%d\n", index,device_stack->stack[index]);
	return STACK_TRUE;
}

inline void STACK_clear(PLC_Device_Stack* device_stack){
	memset(device_stack->stack, 0, STACK_SIZE);
	device_stack->size = 0;
}
