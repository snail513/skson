/*
 * PLC_Log.c
 *
 *  Created on: 2015. 2. 13.
 *      Author: skson
 */
#ifndef PLC_LOG_H_
#include "PLC_Log.h"
#endif
#include "PLC_Definitions.h"
#include <stdlib.h>

static int initialBufSize = 8000;
static char* debugBuffer;
static int debugPos=0;
inline void PLC_LOG_createDebugBuffer(){
	if(debugBuffer==NULL)
		debugBuffer = (char*)malloc(initialBufSize);
	memset(debugBuffer, 0, initialBufSize);
	debugPos=0;
}

inline void PLC_LOG_clearDebugBuffer(){
	if(debugBuffer!=NULL)
		free(debugBuffer);
	debugBuffer = (char*)malloc(initialBufSize);
	memset(debugBuffer, 0, initialBufSize);
	debugPos=0;
}
inline void PLC_LOG_addLog(char* log){
	/*if(strlen(log)+debugPos>initialBufSize)
		debugBuffer = (char*)realloc(debugBuffer, strlen(log)+debugPos+1);
	char* currPos = &debugBuffer[debugPos];
	DBG_LOGSAVE(currPos, log);
	debugPos+=strlen(log);*/
	//printf(log);
	//printf(debugBuffer);
	//PLC_LOG_printSavedLog();
}

inline void PLC_LOG_printSavedLog(){
	DBG_LOGPRINT("%s", debugBuffer);
	//if(debugBuffer!=NULL)
	//	free(debugBuffer);
	//debugBuffer = (char*)malloc(initialBufSize);
	PLC_LOG_clearDebugBuffer();
	//memset(debugBuffer, 0, strlen(debugBuffer));
	//debugPos=0;

}
inline void PLC_LOG_Free(){
	if(debugBuffer!=NULL)
		free(debugBuffer);
	debugPos=0;

}
