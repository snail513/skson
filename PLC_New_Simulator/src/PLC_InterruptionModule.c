/*
 * PLC_InterruptionModule.c
 *
 *  Created on: 2015. 2. 13.
 *      Author: skson
 */

#ifndef PLC_INTERRUPTIONMODULE_H_
#include "PLC_InterruptionModule.h"
#endif
#include "PLC_PointTable.h"
#include "PLC_IL_Task.h"

static InterruptionModule module;

InterruptionModule* PLC_InterruptionModule_getInstance(){
	return &module;
}

void PLC_InterruptionModule_init(){
	module.bIsInterruptable = 0;
	module.nCurrInterruptionPointCount= 0;
	//module.nCurrInterruptionEventCount= 0;
	memset(module.bIsInterruptablePointer,1, INTERRUPTION_SIZE);
}

void PLC_InterruptionModule_resetInterruptionPointers(){

	memset(&module.bIsInterruptablePointer[32], 0, 16);
}

uint8 PLC_InterruptionModule_setGlobalInterruption(uint8 setValue)
{
	if(setValue>1)
		return FALSE;
	module.bIsInterruptable = setValue;
	return TRUE;
}

uint8 PLC_InterruptionModule_setInterruption(uint8 pointer, uint8 setValue){
	if(pointer>=INTERRUPTION_SIZE || setValue>1)
		return FALSE;
	module.bIsInterruptablePointer[pointer]=setValue;
	return TRUE;
}
