/*
 * PLC_Log.h
 *
 *  Created on: 2015. 2. 13.
 *      Author: skson
 */

#ifndef PLC_LOG_H_
#define PLC_LOG_H_

void PLC_LOG_createDebugBuffer();
void PLC_LOG_freeLog();
void PLC_LOG_clearDebugBuffer();
void PLC_LOG_addLog(char* log);
void PLC_LOG_printSavedLog();
void PLC_LOG_Free();
#endif /* PLC_LOG_H_ */
