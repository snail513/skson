/*
 * PLC_InterruptionStack.h
 *
 *  Created on: 2015. 12. 24.
 *      Author: skson
 */

#ifndef PLC_INTERRUPTIONSTACK_H_
#define PLC_INTERRUPTIONSTACK_H_

#include "PLC_Definitions.h"
#include "PLC_PointTable.h"
#define PLC_INTERRUPTION_EVENT_STACK_SIZE 128


typedef struct{
	int nEventStackSize;
	int nEventGIPMapperSize;
	int nCallbackSize;
	EventFlag stackEvent[PLC_INTERRUPTION_EVENT_STACK_SIZE];
	uint32 mapEventGIP[PLC_INTERRUPTION_EVENT_FLAG_COUNT];
	PLC_Point stackCallbackPoint[PLC_INTERRUPTION_EVENT_STACK_SIZE];
} PLC_EventHandler;

PLC_EventHandler* PLC_EventHandler_getInstance();
uint8 PLC_EventHandler_hasEvent();
int PLC_EventHandler_eventCount();
void PLC_EventHandler_init();
uint8 PLC_EventHandler_mapEventFlagToGIP(EventFlag flag, uint32 GIP);
void PLC_EventHandler_unmap();
uint8 PLC_EventHandler_pushEvent(EventFlag flag);
uint8 PLC_EventHandler_pullEvent(EventFlag* dstFlag, uint32* dstGIP);
uint8 PLC_EventHandler_pushCallbackPosition(uint8 taskIdx, uint32 taskPos);
uint8 PLC_EventHandler_callbackPosition(uint8 *taskIdx, uint32 *taskPos);
uint8 PLC_EventHandler_callEvent();
//void part(PLC_Point arr[],int min,int max);
void PLC_EventHandler_enableInterruption();
void PLC_EventHandler_disableInterruption();
uint8 PLC_EventHandler_imask(uint16 maskArray[]);
uint8 PLC_EventHandler_isEnableInterrupt();


void bubbleSort(EventFlag arr[], int size);
#endif /* PLC_INTERRUPTIONSTACK_H_ */
