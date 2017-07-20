/*
 * PLCMain.c
 *
 *  Created on: 2015. 6. 11.
 *      Author: skson
 */


#ifndef PLCMAIN_H_
#include "PLCMain.h"

#endif




int main(int argc, char* argv[]){
	//DBG_LOGPRINT("%s\n", PLC_SIMULATOR_VERSION); /*, prints, !!!Hello, World!!!, */
	//DBG_LOGPRINT("%s\n", PLC_SIMULATOR_HISTORY); /*, prints, !!!Hello, World!!!, */
	//DBG_LOGPRINT("argc = %d\n", argc);


#if 0
	PLC_LOG_createDebugBuffer();

	setUserFunctions(testMLCode, testInitProgram, testProgram);
	//setMLFilePathName("/home/skson/out/PLC3/test.ml");
	//setUserFunctions(testFileCode, testInitProgram, testProgram);
	//printfUserMLCode();

	PLC_DEVICE_Init();
	int scanCount = 100;
	//set

	//run
	if(!initExecSuite())
	{
		printf("Initiation Error!\n");
		return FALSE;
	}
	else{
		int i=0;
		double usec=0.f;
		double usecSum=0.f;
		clock_t clocks = clock();
		while(PLC_TaskExecutor_getDevice()->nCurrTimeScan<scanCount || scanCount<0)
		{

			PLC_TaskExecutor_getDevice()->nExecTime++;
			if(FLAG_SYSTEM_HOLD==1)
				continue;
			clock_t clocksPart = clock();
			if(!runExecSuiteOnece())
			{
				printf("Loop funcion Error! [%d]\n", i);
				return FALSE;
			}
			i++;
			usecSum += (double)(clock() - clocksPart);


		}
		usec = (double)(clock() - clocks);
		printf("%s execution time interval = %f(%f/%d) usec\n", __FUNCTION__, usec/i, usec, i);
		printf("%s execution time interval = %f(%f/%d) usecSUM\n", __FUNCTION__, usecSum/i, usecSum, i);
		printExecTimeOfScanTime(scanCount);
	}
	printf("SUCCESS!\n");
	PLC_LOG_Free();
	return EXIT_SUCCESS;
#else
	return t_main(argc, argv);
	//return test_main(argc, argv);
#endif
}
