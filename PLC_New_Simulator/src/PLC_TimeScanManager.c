/*
 * PLC_TimeScanManager.c
 *
 *  Created on: 2015. 11. 9.
 *      Author: skson
 */
#ifndef PLC_TIMESCANMANAGER_H_
#include "PLC_TimeScanManager.h"
#include "PLC_OperatorDictionary.h"
#include <unistd.h>
#include <time.h>
#endif

#define SCANTIME_MANAGER TRUE
#define MAX_BUFFUR_SIZE 500
#define CUTOFF_BUFFUR_SIZE 400
static char* SCANLOG_FILENAME[] = {
		"./scanfile[00].txt",
		"./scanfile[01].txt",
		"./scanfile[02].txt",
		"./scanfile[03].txt",
		"./scanfile[04].txt",
		"./scanfile[05].txt",
		"./scanfile[06].txt",
		"./scanfile[07].txt",
		"./scanfile[08].txt",
		"./scanfile[09].txt",
		"./scanfile[10].txt",
		"./scanfile[11].txt",
		"./scanfile[12].txt",
		"./scanfile[13].txt",
		"./scanfile[14].txt",
		"./scanfile[15].txt",
		"./scanfile[16].txt",
		"./scanfile[17].txt",
		"./scanfile[18].txt",
		"./scanfile[19].txt",
		"./scanfile[20].txt",
};
static int currLogFileIdx = 0;
static int currLogLineIdx = 0;
static char buf[MAX_BUFFUR_SIZE];


typedef enum{
	Starting,
	Running,
	Ending,
	Waiting
}ScanState;


static timespec_t nstart, nstop;

void PLC_TimeScanManager_outToFile(){
	FILE* file = fopen(SCANLOG_FILENAME,"a+");
	if(!file)
	{
		DBG_LOGPRINT("[PLC_TimeScanManager_outToFile] Cannot open time-log file !\n");
		return ;
	}
	//printf(file);
	fprintf(file, buf);
	memset(buf, 0, MAX_BUFFUR_SIZE);
	fclose(file);
	DBG_LOGPRINT("[PLC_TimeScanManager_outToFile] Added to file !\n");
}

void PLC_TimeScanManager_notifyExecStart(){
#if SCANTIME_MANAGER
	clock_gettime(CLOCK_REALTIME, &nstart);
#endif
}

void PLC_TimeScanManager_notifyExecEnd(){
#if SCANTIME_MANAGER
	clock_gettime(CLOCK_REALTIME, &nstop);
	long long sec = nstop.tv_sec- nstart.tv_sec;
	long long nsec = nstop.tv_nsec- nstart.tv_nsec;
	FILE* file;
	char* bufFileName = SCANLOG_FILENAME[currLogFileIdx];
	//sprintf(bufFileName, "%s[%d].txt", SCANLOG_FILENAME, currLogFileIdx);

	//sprintf(buf, "[%s]\t%lu\n", symbol, nsec);
	sprintf(buf, "%llu\n", nsec + sec*1000000000);
	if(currLogLineIdx==0)
		file = fopen(bufFileName,"w+");
	else
		file = fopen(bufFileName,"a+");

	if(!file)
	{
		DBG_LOGPRINT("[PLC_TimeScanManager_outToFile] Cannot open time-log file !\n");
		return ;
	}

	fprintf(file, buf);
	if(currLogFileIdx < 20)
	{
		if(currLogLineIdx < 20000)
		{
			currLogLineIdx++;
			//DBG_LOGPRINT("File idx = %d, Line idx = %d\n",currLogFileIdx, currLogLineIdx);
		}
		else
		{
			currLogFileIdx++;
			currLogLineIdx=0;
			//DBG_LOGPRINT("File idx = %d, Line idx = %d\n",currLogFileIdx, currLogLineIdx);
		}
	}
	else
	{
		currLogFileIdx=0;
		currLogLineIdx=0;
	}

	fclose(file);
#endif
}

void PLC_TimeScanManager_notifyExecEnd_temp(char* symbol){
#if SCANTIME_MANAGER
	clock_gettime(CLOCK_REALTIME, &nstop);
	uint32 nsec = nstop.tv_nsec- nstart.tv_nsec;
	FILE* file;
	char* bufFileName = SCANLOG_FILENAME[currLogFileIdx];
	//sprintf(bufFileName, "%s[%d].txt", SCANLOG_FILENAME, currLogFileIdx);

	//sprintf(buf, "[%s]\t%lu\n", symbol, nsec);
	sprintf(buf, "%lu\n", nsec);
	if(currLogLineIdx==0)
		file = fopen(bufFileName,"w+");
	else
		file = fopen(bufFileName,"a+");

	if(!file)
	{
		DBG_LOGPRINT("[PLC_TimeScanManager_outToFile] Cannot open time-log file !\n");
		return ;
	}

	fprintf(file, buf);
	if(currLogFileIdx < 20)
	{
		if(currLogLineIdx < 20000)
		{
			currLogLineIdx++;
			//DBG_LOGPRINT("File idx = %d, Line idx = %d\n",currLogFileIdx, currLogLineIdx);
		}
		else
		{
			currLogFileIdx++;
			currLogLineIdx=0;
			//DBG_LOGPRINT("File idx = %d, Line idx = %d\n",currLogFileIdx, currLogLineIdx);
		}
	}
	else
	{
		currLogFileIdx=0;
		currLogLineIdx=0;
	}

	fclose(file);
	//memset(buf, 0, MAX_BUFFUR_SIZE);
#endif
}