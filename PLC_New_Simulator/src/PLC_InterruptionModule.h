/*
 * PLC_InterruptionModule.h
 *
 *  Created on: 2015. 2. 13.
 *      Author: skson
 */

#ifndef PLC_INTERRUPTIONMODULE_H_
#define PLC_INTERRUPTIONMODULE_H_

#include "PLC_Definitions.h"
#define INTERRUPTION_SIZE 128

/*interruption system variables*/
#define INTERRUPTION_TYPE_MAX_COUNT 5


typedef struct{
	unsigned char bIsInterruptablePointer[INTERRUPTION_SIZE];
	unsigned char bIsInterruptable;
	//InterruptionUnit stackInterruptionUnit[INTERRUPTION_SIZE];
	//InterruptionFlag iFlag[INTERRUPTION_SIZE];
	unsigned short nCurrInterruptionPointCount;
} InterruptionModule;


InterruptionModule* PLC_InterruptionModule_getInstance();

//uint32 PLC_InterruptionModule_getInterruptionPoint();
void PLC_InterruptionModule_init();
void PLC_InterruptionModule_resetInterruptionPointers();
uint8 PLC_InterruptionModule_setGlobalInterruption(uint8 setValue);
uint8 PLC_InterruptionModule_setInterruption(uint8 pointer, uint8 setValue);


#endif /* PLC_INTERRUPTIONMODULE_H_ */
