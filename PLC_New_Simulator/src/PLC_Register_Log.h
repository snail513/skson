/*
 * PLC_Register_Log.h
 *
 *  Created on: 2015. 4. 1.
 *      Author: skson
 */

#ifndef PLC_REGISTER_LOG_H_
#define PLC_REGISTER_LOG_H_
#include "PLC_Definitions.h"

#define CHANGED_LOG_SIZE 1024

typedef struct{
	uint8 operandML;
	uint16 operandAddr;
	uint16 operandOldValue;
	uint16 operandNewValue;
	uint32 changedScanCount;
}LogChanged;

typedef struct{
	LogChanged logs[CHANGED_LOG_SIZE];
	uint32 headPos;
	uint32 tailPos;
	uint32 count;
}QueueLog;


void QueueLog_Init();
uint8 QueueLog_AddLog(uint8 operandML, uint16 addr, uint16 oldValue, uint16 newValue, uint32 changedScanCount);
LogChanged* QueueLog_getLog(uint8 operandML, uint16 addr,uint32 changedScanCount);
uint8 ClearFromThisLog(LogChanged* thisLog);
void QueueLog_print();
void QueueLog_save(char* saveFileName);
#endif /* PLC_REGISTER_LOG_H_ */
