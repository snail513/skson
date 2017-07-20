/*
 * PLC_TimeScanManager.h
 *
 *  Created on: 2015. 11. 9.
 *      Author: skson
 */

#ifndef PLC_TIMESCANMANAGER_H_
typedef struct timespec timespec_t;


#include "PLC_Definitions.h"
#include "PLC_Register_Log.h"
#define SCANTIME_LOG_SIZE 4096

void PLC_TimeScanManager_outToFile();

void PLC_TimeScanManager_notifyExecStart();

void PLC_TimeScanManager_notifyExecEnd();

void PLC_TimeScanManager_notifyExecEnd_temp(char* symbol);

#endif