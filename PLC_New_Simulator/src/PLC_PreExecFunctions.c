/*
 * PLC_PreExecFunctions.c
 *
 *  Created on: 2014. 11. 5.
 *      Author: skson
 */

#ifndef PLC_PREEXECFUNCTIONS_H_
#include "PLC_PreExecFunctions.h"
#endif
#include "PLC_Device.h"
#include "PLC_OperatorDictionary.h"
#include "PLC_RealDevice.h"
#include "PLC_Log.h"
#include <time.h>
//static char buf[200];


static char currBitValue = 0;
uint8* functionOperands[5]= {NULL, NULL, NULL, NULL, NULL};
//static char lastBitValue = 0;
extern uint8 PLC_TaskExecutor_isMCOn();
inline uint32 getCurrBitValue(uint32 pos){
	TaskList_setTaskCMDValue(pos, currBitValue);
	//if(!PLC_TaskExecutor_isMCOn())
	//	DBG_LOGPRINT("MC cut off the control area!\n");
	return currBitValue & PLC_TaskExecutor_isMCOn();
}
inline uint32 preProcess_pick(uint32 pos){
	return TaskList_getTaskCMDValue(pos);
}
inline uint32 preProcess_pull(uint32 pos){
	return TaskList_setTaskCMDValue(pos, currBitValue);
}
inline uint32 preProcess_load(uint8 inst[], uint32 pos, PLC_Operator* opt, uint8 opdIdx){

	uint16 optMLCode = opt->nMLCode;
	uint8* operandHead = inProcess_getIndexedOperand(inst, pos, opdIdx);
	uint8 opndType = operandHead[0];//inst[OPERATOR_LENGTH+pos+OPERAND_LENGTH*opdIdx];

	if(isValid(optMLCode, opdIdx, opndType)==FALSE)
	{
		DBG_LOGPRINT("[ERROR] Not valid load value : [%s : %s%d]", opt->strName, opndic[opndType].strType, opdIdx);
		return PLC_DEVICE_FALSE_32;
	}
	return PLC_DEVICE_getDeviceValue(operandHead);
}
inline uint32 preProcess_loadPast(uint8 inst[], uint32 pos, PLC_Operator* opt, uint8 opdIdx){
	uint16 optMLCode = opt->nMLCode;
	uint8* operandHead = inProcess_getIndexedOperand(inst, pos, opdIdx);
	uint8 opndType = operandHead[0];//inst[OPERATOR_LENGTH+pos+OPERAND_LENGTH*opdIdx];

	if(isValid(optMLCode, opdIdx, opndType)==FALSE)
		return PLC_DEVICE_FALSE_32;

	return PLC_DEVICE_getPastDeviceValue(operandHead);
}
inline uint32 preProcess_loadPulse(){
	return dev.nCurrPulseStackPosision>=STACK_SIZE? PLC_DEVICE_FALSE_32: STACK_get(&(dev.device_pulse_stack), dev.nCurrPulseStackPosision);
	//return TaskList_getTaskCMDValue(pos);
}
inline uint32 preProcess_loadDelta(){
	if(dev.nCurrPulseStackPosision>=STACK_SIZE)
		return PLC_DEVICE_FALSE_32;
	return STACK_get(&(dev.device_delta_stack), dev.nCurrDeltaStackPosision);

}
inline uint32 preProcess_loadFront(uint8 inst[], uint32 pos, PLC_Operator* opt, uint8 offset){
	long long ret = 0;
	uint8 bitSize= 0;
	long long push = 0;
	uint8 opndType = inst[OPERATOR_LENGTH+pos];
	uint8* opnd = inProcess_getIndexedOperand(inst, pos, 0);
	if(!test_getValue(&ret, &bitSize, opnd, -1))
	{
		return PLC_DEVICE_FALSE_32;
	}
	if(opndType==OPERAND_ML_CODE_WB || opndType==OPERAND_ML_CODE_N )
	{
		PLC_DEVICE_setDeviceValue(opnd, push, -1);
		PLC_DEVICE_setDeviceValue(opnd, ret, 0);
		uint16 exp;
		test_getWord(&exp,opnd[3], *(uint16*)&opnd[4]);
	}
	else
	{
		PLC_DEVICE_setDeviceValue(opnd, push, -1);
		PLC_DEVICE_setDeviceValue(opnd, ret, 0);
	}

	return TRUE;
}


inline uint32 preProcess_checkMC(){
	return STACK_getSize(&(dev.device_mc_stack))==0?TRUE:STACK_pick(&(dev.device_mc_stack));//No MC control is effected.
}
inline uint32 preProcess_loadWord(uint8 inst[], uint32 pos, PLC_Operator* opt, uint8 opdIdx){
	uint16 optMLCode = opt->nMLCode;
	uint8* getOperand = inProcess_getIndexedOperand(inst, pos, opdIdx);

	if(getOperand==NULL)
	{
		DBG_LOGPRINT("\t[ERROR] getting operand is failed!\n");
		return PLC_DEVICE_FALSE_32;
	}

	uint8 opndType = getOperand[0];
	if(!isValid(optMLCode, opdIdx, opndType) && opndType!=OPERAND_ML_CODE_K)
	//if(isValid(optMLCode, opdIdx, opndType)==FALSE)
	{
		//
		DBG_LOGPRINT("\t[ERROR] Invalid operand type for operator %s!\n", opndic[opndType].strType);
		return PLC_DEVICE_FALSE_32;
	}
	//
	return PLC_DEVICE_getDeviceWordValue(getOperand);
}
inline uint8 preProcess_loadLastCMDValue(uint32 pos){
	currBitValue = TaskList_getTaskCMDValue(pos);
	return currBitValue;
}
inline uint8 preProcess_saveLastCMDValue(uint32 pos){
	TaskList_setTaskCMDValue(pos, currBitValue);
	return currBitValue;
}
inline int inProcess_getIndexPosition(uint8* opndType, uint8 inst[], uint32* pos, uint8 opdIdx)
{
	int currPos = OPERATOR_LENGTH+(*pos);
	int i;
	*opndType = inst[currPos];
	for(i=0;i<opdIdx;i++)
	{

		//printf("%s %d\n",__FUNCTION__, __LINE__);
		*opndType = inst[currPos];
		//DBG_LOGSCAN(buf, "%d\n",opndType);PLC_LOG_addLog(buf);
		PLC_Operand* opd = PLC_OPERAND_DICTIONARY_findOperand(*opndType);
		//DBG_LOGSCAN(buf, "%s\n",opd->strType);PLC_LOG_addLog(buf);
		//printf("OPD Type %s(ML = %d)\n", opd->strType,*opndType);PLC_LOG_addLog(buf);
		if(opd->nMLCode==OPERAND_ML_CODE_STR)
			currPos += strlen((char*)&inst[currPos+1]);
		if(opd->nMLCode==OPERAND_ML_CODE_DE)
			currPos += (1+sizeof(double));
		else if(opd->nMLCode==OPERAND_ML_CODE_DK)
			currPos += (1+sizeof(float));
		else if(opd->nMLCode==OPERAND_ML_CODE_E)
			currPos += (1+sizeof(int));
		else if(opd->nMLCode==OPERAND_ML_CODE_K)
			currPos += (1+sizeof(short));
		else if(opd->nMLCode==OPERAND_ML_CODE_N)
			currPos += 2*(1+sizeof(short));
		else if(opd->nMLCode==OPERAND_ML_CODE_Z)
			currPos += 2*(1+sizeof(short));
		else
			currPos += 3;
	}
	return currPos;
}

inline uint32 preProcess_loadDoubleWord(uint8 inst[], uint32 pos, PLC_Operator* opt, uint8 opdIdx){
	uint16 optMLCode = opt->nMLCode;

	uint8 opndType;
	uint8* currOperand;
	currOperand = inProcess_getIndexedOperand(inst, pos, opdIdx);
	opndType = currOperand[0];
	uint8 valid =isValid(optMLCode, opdIdx, opndType);
	if(!valid){
		DBG_LOGPRINT( "[opt %s(index = %d)->%s] not valid\n", PLC_OPERATOR_DICTIONARY_findOperator(optMLCode)->strName, opdIdx, opndic[opndType].strType);
		return PLC_DEVICE_FALSE_32;
	}
	uint32 ret;
	if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&ret, currOperand, 0))
		return PLC_DEVICE_FALSE_32;
	return ret;
}
inline float preProcess_loadFloat(uint8 inst[], uint32* pos, PLC_Operator* opt, uint8 opdIdx){
		//uint8 operandCount = PLC_OPERATOR_DICTIONARY_getOperandCount(optMLCode);

	uint8 opndType;
	int currPos;
	currPos = inProcess_getIndexPosition(&opndType, inst,pos,opdIdx);
	return PLC_DEVICE_getDeviceFloatValue(&inst[currPos]);
}
inline double preProcess_loadDouble(uint8 inst[], uint32* pos, PLC_Operator* opt, uint8 opdIdx){


	uint8 opndType;
	int currPos;
	currPos = inProcess_getIndexPosition(&opndType, inst,pos,opdIdx);
	return PLC_DEVICE_getDeviceDoubleValue(&inst[currPos]);


}

inline uint8* preProcess_loadString(uint8 inst[], uint32 pos, PLC_Operator* opt, uint8 opdIdx){
	uint16 optMLCode = opt->nMLCode;
		//uint8 operandCount = PLC_OPERATOR_DICTIONARY_getOperandCount(optMLCode);

	uint32 currPos = OPERATOR_LENGTH + pos;
	int i;

	uint8 opndType = inst[currPos];
	//uint16* val = (uint16*)&inst[currPos+1];

	for(i=0;i<opdIdx;i++)
	{
		//printf("currType = %s\n", opndic[opndType].strType);
		if(opndType == OPERAND_ML_CODE_STR)
		{
			//printf("%s %d\n", __FUNCTION__, __LINE__);
			//printf("%s %d\n", __FUNCTION__, __LINE__);
			currPos += 1+getOperandStrLength(inst, &currPos);
			//printf("o : %d, strlen = %d \n", o++, (uint16)strlen(&inst[currPos+1]));
		}
		else if(opndType == OPERAND_ML_CODE_DK || opndType == OPERAND_ML_CODE_E )
		{
			//printf("%s %d\n", __FUNCTION__, __LINE__);
			currPos += 5;
		}
		else if(opndType == OPERAND_ML_CODE_DE)
		{
			//printf("%s %d\n", __FUNCTION__, __LINE__);
			currPos += 9;
		}
		else if(opndType == OPERAND_ML_CODE_N)
		{
			//printf("%s %d\n", __FUNCTION__, __LINE__);
			//opndSize = inst[currPos+1];
			opndType = inst[currPos+2];
			//val = (uint16*)&inst[currPos+3];
			currPos += 6;
		}
		else if(opndType == OPERAND_ML_CODE_Z)
		{
			opndType = inst[currPos+2];
			currPos += 6;
		}
		else
		{
			//printf("%s %d\n", __FUNCTION__, __LINE__);
			currPos += 3;
		}
		opndType = inst[currPos];
	}

	if(opndType == OPERAND_ML_CODE_N)
	{
		currPos+=3;//Device value position
	}
	//fix bug 2015. 05.19
	if(isValid(optMLCode, opdIdx, opndType)==FALSE){

		DBG_LOGPRINT("\t[device] invalid : %s - %s - opdIdx : %d, pos - %d!\n",
				PLC_OPERATOR_DICTIONARY_findOperator(optMLCode)->strName,
				opndic[opndType].strType,
				opdIdx, currPos);
		return NULL;
	}
	uint8* ret = (uint8*)PLC_DEVICE_getDeviceString(&inst[currPos]);
	if(ret==NULL){
		return NULL;
	}
	if(strlen((char*)ret)>PLC_STRING_MAX_LENGTH)
	{
		handleExecError(ERROR_CODE_OUT_OF_DEVICE_RANGE);
		return NULL;
	}
	return ret;
}

inline uint32 preProcess_compareString(uint8 inst[], uint32 *pos, PLC_Operator* opt){
	/*int i;
	for(i=0;i<50;i++)
	{
		printf("%02d ", inst[i]);
		if(i%16==15)
			printf("\n");
		else if(i%8==7)
			printf("\t");

	}
	printf("\n");*/
	int ret;
	uint16* getFirstString = (uint16*)preProcess_loadString(inst, *pos, opt, 0);

	uint16* getSecondString = (uint16*)preProcess_loadString(inst, *pos, opt, 1);

	/*DBG_LOGSCAN(buf, "\t[%s] Compare %s with %s.\n"
			,__FUNCTION__
			, (char*)getFirstString
			, (char*)getSecondString);PLC_LOG_addLog(buf);
*/
	if(getFirstString==NULL|| getSecondString ==NULL)
	{
		return FALSE;
	}

	ret = strcmp((char*)getFirstString,(char*)getSecondString);
	if(ret==0)
		return COMPARE_RESULT_EQUAL;
	else if(ret>0)
		return COMPARE_RESULT_FIRST_IS_BIG;
	else
		return COMPARE_RESULT_FIRST_IS_SMALL;

}

inline uint32 preProcess_compareWordBlock(
		uint8 inst[],
		uint32 *pos,
		PLC_Operator* opt,
		uint32 (*comparingFunction)(void*, void*),
		int isPulseOn)
{
	uint32 offset;
	uint32 getLastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	uint8* firstOperand = inProcess_getIndexedOperand(inst, *pos, 0);
	uint8* secondOperand = inProcess_getIndexedOperand(inst, *pos, 1);
	uint8* thirdDst = inProcess_getIndexedOperand(inst, *pos, 2);
	uint8 isSingleToMultiple = opndic[firstOperand[0]].bIsConstant;
	uint8* forthSize = inProcess_getIndexedOperand(inst, *pos, 3);
	long long size = 0;
	uint8 size_size;
	if(!test_getValue(&size, &size_size, forthSize, 0))
		return FALSE;

	if(size == PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("[Error %s] Error while loading size\n", __FUNCTION__);
		return FALSE;
	}

	if(((isPulseOn==FALSE) && getCurrValue) ||
			(isPulseOn && inProcess_detectRaisingEdge(getCurrValue,getLastValue&0x01)))
	{
		for(offset=0;offset<size;offset++){
			long long val1=0;
			long long val2=0;
			uint8 size1=0;
			uint8 size2=0;

			if(!test_getValue(&val1, &size1, firstOperand, offset*(!isSingleToMultiple)))
				return FALSE;
			if(!test_getValue(&val2, &size2, secondOperand, offset))
				return FALSE;

			uint32 setVal = comparingFunction((void*)&val1, (void*)&val2);

			if(PLC_DEVICE_setDeviceValue(thirdDst, setVal, offset)==PLC_DEVICE_FALSE_32)
			{
				DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
				return PLC_DEVICE_FALSE_32;
			}
		}
	}

	return TRUE;
}

inline uint32 preProcess_compareDoubleWordBlock(uint8 inst[], uint32 *pos, PLC_Operator* opt, uint32 (*comparingFunction)(void*, void*), int isPulseOn)
{

	uint32 offset;
	uint32 getLastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	uint8* firstOperand = inProcess_getIndexedOperand(inst, *pos, 0);
	uint8* secondOperand = inProcess_getIndexedOperand(inst, *pos, 1);
	uint8* thirdDst = inProcess_getIndexedOperand(inst, *pos, 2);
	uint8 isSingleToMultiple = opndic[firstOperand[0]].bIsConstant;
	uint8* forthSize = inProcess_getIndexedOperand(inst, *pos, 3);
	long long size = 0;
	uint8 size_size;
	if(!test_getValue(&size, &size_size, forthSize, 0))
		return FALSE;

	if(size == PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("[Error %s] Error while loading size\n", __FUNCTION__);
		return FALSE;
	}

	if(((isPulseOn==FALSE) && getCurrValue) ||
			(isPulseOn && inProcess_detectRaisingEdge(getCurrValue,getLastValue&0x01)))
	{
		for(offset=0;offset<size;offset++){
			long long val1=0;
			long long val2=0;
			uint8 size1=0;
			uint8 size2=0;

			if(!test_getDValue((int*)&val1, &size1, firstOperand, 2*offset*(!isSingleToMultiple)))
				return FALSE;
			if(!test_getDValue((int*)&val2, &size2, secondOperand, 2*offset))
				return FALSE;
			/*DBG_LOGPRINT("DBK %X | %X\n",
					val1, val2);*/
			uint32 setVal = comparingFunction((void*)&val1, (void*)&val2);

			if(PLC_DEVICE_setDeviceValue(thirdDst, setVal, offset)==PLC_DEVICE_FALSE_32)
			{
				DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
				return PLC_DEVICE_FALSE_32;
			}
		}
	}

	return TRUE;
}
inline uint32 preProcess_calculateFloat(
		uint8 inst[], uint32 *pos, PLC_Operator* opt,
		uint8 (*calculatingFunction)(uint8*, uint8*, uint8*, uint8),
		int isPulseOn, int hasNewDst, uint8 byteSize){

	uint8* getFirstWord;
	uint8* getSecondWord;
	uint8*	tarWord;
	uint8 destOpndType;
	long long destOpndVal;
	uint16 optMLCode = opt->nMLCode;
	uint8 destinationOperandIndex;

	int j;
	int currPos;


	if(!hasNewDst)
	{
		getFirstWord  = preProcess_loadString(inst, *pos, opt, 1);
		getSecondWord = preProcess_loadString(inst, *pos, opt, 0);
		tarWord = getFirstWord;
		destinationOperandIndex = 1;
		//printf("!hasNewDst\n");
	}else{
		getFirstWord  = preProcess_loadString(inst, *pos, opt, 0);
		getSecondWord = preProcess_loadString(inst, *pos, opt, 1);
		tarWord= preProcess_loadString(inst, *pos, opt, 2);
		destinationOperandIndex = 2;
		//printf("hasNewDst\n");
	}

	/*if(byteSize==4)
		printf("first[%d | %X] :%02X %02X, second[%d | %X] : %02X %02X\n",
				*(float*)getFirstWord, *(float*)getFirstWord,
				getFirstWord[0], getFirstWord[1],
				*(float*)getSecondWord, *(float*)getSecondWord,
				getSecondWord[0], getSecondWord[1]);
	else if(byteSize==8)
		printf("first[%d | %X] :%02X %02X %02X %02X, second[%d | %X] : %02X %02X %02X %02X\n",
				*(double*)getFirstWord, *(double*)getFirstWord,
				getFirstWord[0], getFirstWord[1], getFirstWord[2], getFirstWord[3],
				*(double*)getSecondWord, *(double*)getSecondWord,
				getSecondWord[0], getSecondWord[1], getSecondWord[2], getSecondWord[3]);*/
	currPos = OPERATOR_LENGTH+*pos;
	uint8 opndType = inst[currPos];
	for(j=0;j<destinationOperandIndex;j++)
	{
		//printf("[currPos] : %d\n", currPos);
		currPos += OPND_DICT_ByteSize(&inst[currPos]);
		/*if(opndType == OPERAND_ML_CODE_STR)
		{
			//printf("%s %d\n", __FUNCTION__, __LINE__);
			//printf("[opndType] : %d, STR\n", opndType);
			currPos += 1+getOperandStrLength(inst, &currPos);
			//printf("o : %d, strlen = %d \n", o++, (uint16)strlen(&inst[currPos+1]));
		}
		else if(opndType == OPERAND_ML_CODE_DE)
		{
			//printf("[opndType] : %d, DK\n", opndType);
			currPos += 8;
		}
		else if(opndType == OPERAND_ML_CODE_DK || opndType == OPERAND_ML_CODE_E)
		{
			//printf("[opndType] : %d, DK\n", opndType);
			currPos += 5;
		}
		else if(opndType == OPERAND_ML_CODE_N || opndType == OPERAND_ML_CODE_Z){
			currPos += 6;
		}
		else
		{
			//printf("[opndType] : %d, else\n", opndType);
			currPos += 3;
		}*/
		//opndType = inst[currPos];
		//printf("[opndType%d] : %d\n", currPos, inst[currPos]);
	}
	destOpndType =opndType;
	destOpndVal = *(short*)&inst[currPos+1];
	if(destOpndType == OPERAND_ML_CODE_Z)
	{
		destOpndType = inst[currPos+3];
		destOpndVal += *(short*)&inst[currPos+4];
	}
	//printf("third type = %s, third value = %f\n", opndic[destOpndType].strType, *(float*)destOpndVal);
	//uint16* valpoint = (uint16*)&inst[currPos+1];
	//destOpndVal = inst[currPos+1]*256+ inst[currPos+2];

	uint32 getLastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	//printf("[%s]%d\n", __FUNCTION__, __LINE__);
	if(getFirstWord==NULL|| getSecondWord ==NULL)
	{
		//printf("[%s]%d\n", __FUNCTION__, __LINE__);
		//printf("[ERROR] while loading first Operand or second operand.\n");
		return PLC_DEVICE_FALSE_32;
	}
	if(((isPulseOn==FALSE) && ((getCurrValue&0x01)==1))||
			((isPulseOn==TRUE) && inProcess_detectRaisingEdge(getCurrValue, getLastValue)))
	{

		if(isValid(optMLCode, destinationOperandIndex, destOpndType)==FALSE){
			/*DBG_LOGSCAN(buf,
					"\t[%s] error while checking operand& operator [%s%d]%d\n",
					opt->strName,
					opndic[destOpndType].strType,
					destOpndVal,
					PLC_DEVICE_getDeviceValue( &inst[OPERATOR_LENGTH+*pos]));
			PLC_LOG_addLog(buf);*/
			DBG_LOGPRINT("[ERROR] invalid dst register - %s %d, [%s%d]\n", __FUNCTION__, __LINE__, opndic[destOpndType].strType, (int)destOpndVal);
			return PLC_DEVICE_FALSE_32;
		}

		if(calculatingFunction(tarWord, getFirstWord,getSecondWord, byteSize)==FALSE)
		{
			DBG_LOGPRINT("[ERROR] calculation failed - %s %d\n", __FUNCTION__, __LINE__);
			//printf("[%s]%d\n", __FUNCTION__, __LINE__);
			return PLC_DEVICE_FALSE_32;
		}

		/*else if(byteSize==4)
		{
			printf("\t[%s] int calculation. input1 : %d(X:%X,F:%F), input2 : %d(X:%X,F:%F), "
					"\n\t\toutput value = [%s%d]%d(X:%X,F:%F)\n",
					opt->strName,
					*(int*)getFirstWord,*(int*)getFirstWord,*(float*)getFirstWord,
					*(int*)getSecondWord,*(int*)getSecondWord,*(float*)getSecondWord,
					opndic[destOpndType].strType,
					destOpndVal,
					*((int*)tarWord), *((int*)tarWord), *((int*)tarWord));
		}
		else if(byteSize==8)
		{
			printf("\t[%s]  llong calculation. input1 : %d(X:%X,DF:%F), input2 : %d(X:%X,DF:%F), output value = [%s%d]%d\n",
					opt->strName,
					*(long long*)getFirstWord,*(long long*)getFirstWord,*(double*)getFirstWord,
					*(long long*)getSecondWord,*(long long*)getSecondWord,*(double*)getSecondWord,
					opndic[destOpndType].strType,
					destOpndVal,
					*((long long*)tarWord));
		}*/
	}

	return TRUE;
}
inline uint32 preProcess_calculate(
		uint8 inst[], uint32 *pos,
		PLC_Operator* opt, void* calculatingFunction,
		/*uint8 (*calculatingFunction)(uint8*, uint8*, uint8*, uint8),*/
		int isPulseOn, int hasNewDst, uint8 byteSize)
{
	uint32 getPastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	//printf("%s %d!\n", __FUNCTION__, __LINE__);
	if(getCurrValue ==PLC_DEVICE_FALSE_32)
	{
		printf("Curr sequence bit value has been lost!\n");
		return FALSE;
	}
	if(isPulseOn){
		if(!inProcess_detectRaisingEdge(getCurrValue, getPastValue))
		{
			//printf("Raising edge off\n");
			return TRUE;
		}
	}else
		if((getCurrValue&0x01)==0)
		{
			//printf("%s %d!\n", __FUNCTION__, __LINE__);
			return TRUE;
		}
	//printf("%s %d!\n", __FUNCTION__, __LINE__);
	uint8* firstOperand;
	uint8* secondOperand;
	uint8* thirdOperand;
	//printf("%s %d!\n", __FUNCTION__, __LINE__);
	int (*function)(uint8*, uint8*, uint8*, uint8);
	if(hasNewDst)
	{
		firstOperand = inProcess_getIndexedOperand(inst, *pos, 0);
		secondOperand = inProcess_getIndexedOperand(inst, *pos, 1);
		thirdOperand = inProcess_getIndexedOperand(inst, *pos, 2);
	}
	else
	{
		firstOperand = inProcess_getIndexedOperand(inst, *pos, 1);
		secondOperand = inProcess_getIndexedOperand(inst, *pos, 0);
		thirdOperand = inProcess_getIndexedOperand(inst, *pos, 1);
	}

	//printf("load calculation Position: %d, %d\n", firstOperand, secondOperand);
	function= calculatingFunction;



	if(byteSize == 2)
	{

		long long firstValue;
		long long secondValue;

		uint8 bitSize;

		if(!test_getValue((long long*)&firstValue, &bitSize, firstOperand, 0))
		{
			printf("\t[Error] while getting first value \n");
			return FALSE;
		}

		if(!test_getValue((long long*)&secondValue, &bitSize, secondOperand, 0))
		{
			printf("\t[Error] while getting second value \n");
			return FALSE;
		}

		if((void*)function == (void*)inProcess_divBCD || (void*)function == (void*)inProcess_divInt
			||(void*)function == (void*)inProcess_mltBCD || (void*)function == (void*)inProcess_mltInt)
		{

			int thirdValue;
			if(!function((uint8*) &thirdValue, (uint8*)&firstValue, (uint8*)&secondValue, byteSize))
			{
				printf("\t[Error] while calculating third value \n");
				return FALSE;
			}
			//printf("getVal : %d(0x%X), %d(0x%X), %d(0x%X)\n", firstValue, firstValue, secondValue, secondValue, thirdValue, thirdValue);
			//printf("third operand : %02X %02X %02X %02X %02X %02X\n", thirdOperand[0],thirdOperand[1],thirdOperand[2],thirdOperand[3],thirdOperand[4], thirdOperand[5]);
			return PLC_DEVICE_setDeviceValueBySize(thirdOperand, (long long)thirdValue, 8*(sizeof(thirdValue)));
		}
		else{
			short thirdValue;
			if(!function((uint8*) &thirdValue, (uint8*)&firstValue, (uint8*)&secondValue, byteSize))
			{
				printf("\t[Error] while calculating third value \n");
				return FALSE;
			}
			//printf("getVal : %d(0x%X), %d(0x%X), %d(0x%X)\n", firstValue, firstValue, secondValue, secondValue, thirdValue, thirdValue);
			//printf("third operand : %02X %02X %02X %02X %02X %02X\n", thirdOperand[0],thirdOperand[1],thirdOperand[2],thirdOperand[3],thirdOperand[4], thirdOperand[5]);
			return PLC_DEVICE_setDeviceValueBySize(thirdOperand, thirdValue, 8*(sizeof(thirdValue)));
		}
	}else if(byteSize == 4)
	{

		int firstValue;
		int secondValue;

		uint8 bitSize;

		if(!test_getDValue((int*)&firstValue, &bitSize, firstOperand, 0))
		{
			printf("\t[Error] while getting first value \n");
			return FALSE;
		}

		if(!test_getDValue((int*)&secondValue, &bitSize, secondOperand, 0))
		{
			printf("\t[Error] while getting second value \n");
			return FALSE;
		}
		//printf("getValue : %d %d\n", firstValue, secondValue);
		//printf("%s %d\n", __FUNCTION__, __LINE__);
		if((void*)function == (void*)inProcess_divBCD || (void*)function == (void*)inProcess_divInt
			||(void*)function == (void*)inProcess_mltBCD || (void*)function == (void*)inProcess_mltInt)
		{
			long long thirdValue;
			if(!function((uint8*) &thirdValue, (uint8*)&firstValue, (uint8*)&secondValue, byteSize))
			{
				printf("\t[Error] while calculating third value \n");
				return FALSE;
			}
			//printf("getVal : %d, %d, %d\n", firstValue, secondValue, thirdValue);
			return PLC_DEVICE_setDeviceValueBySize(thirdOperand, thirdValue, 8*(sizeof(thirdValue)));
		}
		else{
			int thirdValue=0;
			if(!function((uint8*) &thirdValue, (uint8*)&firstValue, (uint8*)&secondValue, byteSize))
			{
				printf("\t[Error] while calculating third value \n");
				return FALSE;
			}
			//printf("getVal : %d(0x%X), %d(0x%X), %d(0x%X)\n", firstValue, firstValue, secondValue, secondValue, thirdValue, thirdValue);
			return PLC_DEVICE_setDeviceValueBySize(thirdOperand, thirdValue, 8*(sizeof(thirdValue)));

		}
	}
	//printf("\t[ERROR] target size is wrong: %d!", byteSize);
	return TRUE;

}


inline uint32 preProcess_calculateFloatBlock(uint8 inst[], uint32 *pos, PLC_Operator* opt, uint32 (*calculatingFunction)(double, double), int isPulseOn, int hasNewDst){
	return FALSE;
}

inline uint8 inProcess_getOperandType(uint8 inst[], uint32* pos, int index){
	uint8* operandPos = inProcess_getIndexedOperand(inst, *pos, index);
	return operandPos[0];
}
inline uint8* inProcess_getOperandValue(uint8 inst[], uint32* pos, int index){
	uint8* operandPos = inProcess_getIndexedOperand(inst, *pos, index);
	return &operandPos[1];
}


inline uint8 inProcess_logicSequence(uint8 inst[], uint32* pos, PLC_Operator* opt, uint8 logicFlag, uint8 pulseFlag, uint8 invertFlag)
{
	(*pos) += OPERATOR_LENGTH;
	uint8* operand = inProcess_getNextIndexedOperand(inst, pos);
	uint32 getValue = PLC_DEVICE_getDeviceValue(operand);
	if(operand ==NULL)
				return FALSE;
	//uint32 getValue = preProcess_load(inst, *pos, opt, 0);
	if(getValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(pulseFlag==FUNCTION_PULSETYPE_RAISING)
		getValue = inProcess_detectRaisingEdge(getValue, PLC_DEVICE_getPastDeviceValue(operand));
	else if(pulseFlag==FUNCTION_PULSETYPE_FALLING)
		getValue = inProcess_detectFallingEdge(getValue, PLC_DEVICE_getPastDeviceValue(operand));

	if(invertFlag == FUNCTION_OUTTYPE_INVERT)
		getValue = !getValue;

	if(logicFlag == FUNCTION_TYPE_AND)
		currBitValue = getCurrBitValue(*pos) & getValue;
	else
		currBitValue = getCurrBitValue(*pos) | getValue;
	if(!PLC_DEVICE_overWirteBlockResult(currBitValue))
		return FALSE;

	return PLC_DEVICE_increaseStep(TRUE);//finalProcess_progressPosition(inst, pos, opt);
}

inline uint32 inProcess_inv(uint32 in){
	return !in;
}
inline uint32 inProcess_detectRaisingEdge(uint32 current, uint32 past){
	//DBG_LOGPRINT("in(%d|%d)\n", current, past);
	if((current==TRUE) & (past==FALSE))
		return 1;
	//if((current==TRUE) & (past==2))
	//	return 1;
	return 0;
}
inline uint32 inProcess_detectFallingEdge(uint32 current, uint32 past){
	//DBG_LOGSCAN(buf, "in(%d) & 0x03 = %d", in, in & 0x03);PLC_DEVICE_addLog(buf);
	if((current==FALSE) & (past==TRUE))
		return 1;
	return 0;
}
inline uint32 inProcess_and(uint32 in, uint32 pos){
	uint32 value = getCurrBitValue(pos);//preProcess_pick(pos);//STACK_pick(&(dev.device_stack));
	//DBG_LOGSCAN(buf, "\t[in & current = rst] %02X and %02X = %02X\n", in, value,in & value );
	//PLC_LOG_addLog(buf);
	return (in & value);
}
inline uint32 inProcess_or(uint32 in, uint32 pos){
	//uint32 value = STACK_pick(&(dev.device_stack));
	uint32 value = getCurrBitValue(pos);//preProcess_pick(pos);
	//DBG_LOGSCAN(buf, "\t[in & current = rst] %02X or %02X = %02X\n", in, value,in | value );
	//PLC_LOG_addLog(buf);
	return (in | value);
}
inline uint32 inProcess_savePulse(uint32 in){
	return STACK_set(&(dev.device_pulse_stack), dev.nCurrPulseStackPosision++, in);
}
inline uint32 inProcess_saveDelta(uint32 in){
	return STACK_set(&(dev.device_delta_stack), dev.nCurrDeltaStackPosision++, in);
}
inline uint32 inProcess_pushMC(uint32 in){
	return STACK_push(&(dev.device_mc_stack), in)==STACK_TRUE;
}
inline uint32 inProcess_pullMC(){

	return STACK_pull(&(dev.device_mc_stack));
}

inline uint32 inProcess_swapByte(uint16* value){
	if(value == NULL)
		return PLC_DEVICE_FALSE_32;
	//DBG_LOGSCAN(buf, "\t[SWAP] in : %04X\n", *value);	PLC_LOG_addLog(buf);
	uint8* valueSwap;
	uint8 tmp;
	valueSwap = (uint8*)value;
	tmp = valueSwap[0];
	valueSwap[0] = valueSwap[1];
	valueSwap[1] = tmp;
	//DBG_LOGSCAN(buf, "\t[SWAP] out : %04X\n", *value);	PLC_LOG_addLog(buf);
	return TRUE;
}
inline uint8 inProcess_isPulse(uint8 value){
	return (((value>>1)&0x03)==1);
}

inline uint8 inProcess_calculateBK(uint8 inst[], uint32 pos, void* calculatingFunction)
{
	uint8 rstSize;
	uint8 *s1Opnd = inProcess_getIndexedOperand(inst, pos, 0);
	uint8 *s2Opnd = inProcess_getIndexedOperand(inst, pos, 1);
	uint8 *dOpnd = inProcess_getIndexedOperand(inst, pos, 2);
	uint8 *nOpnd = inProcess_getIndexedOperand(inst, pos, 3);
	uint8 (*function)(uint8*, uint8*, uint8*, uint8) = calculatingFunction;
	int idx;
	uint16 nVal ;//= PLC_DEVICE_getDeviceValue(nOpnd);
	if(!test_getValue((long long*)&nVal, &rstSize, nOpnd, 0))
		return FALSE;
	if(nVal ==PLC_DEVICE_FALSE_32)
		return FALSE;
	//DBG_LOGPRINT("nVal %d\n", nVal);
	for(idx=0;idx<nVal;idx++)
	{
		long long src1=0, src2=0, dst=0;
		if(!test_getValue(&src1, &rstSize, s1Opnd, idx))
		{
			DBG_LOGPRINT("[Error] while %s\n", __func__);
			return FALSE;
		}
		if(!test_getValue(&src2, &rstSize, s2Opnd, idx))
		{
			DBG_LOGPRINT("[Error] while %s\n", __func__);
			return FALSE;
		}
		if(!function((uint8*)&dst, (uint8*)&src1, (uint8*)&src2, 2))
		{
			DBG_LOGPRINT("[Error] while %s\n", __func__);
			return FALSE;
		}

		//DBG_LOGPRINT("[idx%d]%d+%d => %d\n", idx, src1, src2, dst);

		if(!PLC_DEVICE_setDeviceValue(dOpnd, dst, idx))
		{
			DBG_LOGPRINT("[Error] while %s\n", __func__);
			return FALSE;
		}
	}
	return TRUE;

}

inline uint32 inProcess_compareValue(uint8 inst[], uint32* pos, PLC_Operator* opt,
		uint32(*compareFunction)(void* inFirst, void* inSecond),
		 uint8 byteSize, uint8 functionType)
{
	uint32 ret;

	long long firstValue=0;
	long long secondValue=0;

	uint32 getCurrValue;

	if(byteSize==2)
	{
		//PLC_LOG_addLog("\t[COMPARE]Loading WORD\n");
		firstValue = preProcess_loadWord(inst, *pos, opt, 0);
		if(firstValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[%s] Error while picking first value.[pos = %d]\n", opt->strName, *pos);
			return FALSE;
		}
		//PLC_LOG_addLog("\t[COMPARE]Loading DWORD\n");
		secondValue = preProcess_loadWord(inst, *pos, opt, 1);

		if(secondValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[%s] Error while picking second value.[pos = %d]\n", opt->strName, *pos);
			return FALSE;
		}

	}
	else if(byteSize==4)
	{
		//DBG_LOGPRINT("\t[COMPARE]Loading DWORD\n");
		firstValue = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		if(firstValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[%s] Error while picking first value.[pos = %d]\n", opt->strName, *pos);
			return FALSE;
		}
		//PLC_LOG_addLog("\t[COMPARE]Loading DWORD\n");
		secondValue = preProcess_loadDoubleWord(inst, *pos, opt, 1);

		if(secondValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[%s] Error while picking second value.[pos = %d]\n", opt->strName, *pos);
			return FALSE;
		}
		//DBG_LOGPRINT("\t[COMPARE]Loading DWORD\n");
	}
	else
	{
		DBG_LOGPRINT("\t[%s] Error byteSize = %d\n", opt->strName, byteSize);
		return FALSE;
	}

	//DBG_LOGPRINT("%lld | %lld , getCurrVal =  %d\n", firstValue, secondValue, getCurrValue);
	if(functionType==FUNCTION_TYPE_LD)
	{

		if(compareFunction((void*)&firstValue, (void*)&secondValue)==TRUE)
			ret = 1;
		else
			ret = 0;

		return postProcess_pushNewBranchedValue(inst, pos, opt, ret);
	}

	getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
	{
		//DBG_LOGSCAN(buf,"\t[%s] Error while picking current value.[pos = %d]\n", opt->strName, *pos);PLC_LOG_addLog(buf);
		return FALSE;
	}

	if(functionType==FUNCTION_TYPE_AND){


		if(compareFunction((void*)&firstValue, (void*)&secondValue)==TRUE)
			ret = getCurrValue&0x01;
		else
			ret = getCurrValue&0x00;

		return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
	}
	else if(functionType==FUNCTION_TYPE_OR){

		if(compareFunction((void*)&firstValue, (void*)&secondValue)==TRUE)
			ret = getCurrValue|0x01;
		else
			ret = getCurrValue|0x00;

		return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);

	}
	return FALSE;
}
inline uint32 inProcess_compareFloatValue(uint8 inst[], uint32* pos, PLC_Operator* opt,
		uint32(*compareFunction)(double inFirst, double inSecond),
		uint8 byteSize, uint8 functionType)
{
	uint32 ret;
	double getFirstOperand;
	double getSecondOperand;
	uint32 getCurrValue;
	//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
	//uint32 (*preProcess_loadFunction)(uint8, uint32*, PLC_Operator*, uint8);

	if(byteSize==4)
	{
		//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
		getFirstOperand = preProcess_loadFloat(inst, pos, opt, 0);
		//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
		getSecondOperand = preProcess_loadFloat(inst, pos, opt, 1);
		//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
		//DBG_LOGSCAN(buf, "\t[COMPARE]Loading float: %f, %f\n", getFirstOperand, getSecondOperand);PLC_LOG_addLog(buf);
		float inf = 1.0f/0;
		float sinf = -1.0f/0;
		//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
		if(getFirstOperand==-0.f ||getSecondOperand==-0.f|| getFirstOperand==inf ||getSecondOperand==sinf)
		{
			//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
			handleExecError(ERROR_CODE_OUT_OF_VALUE_RANGE);
			return FALSE;
		}
		//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
		//DBG_LOGPRINT("\t[COMPARE]Loading float: %f, %f\n", getFirstOperand, getSecondOperand);
	}
	else if(byteSize==8)
	{
		//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
		getFirstOperand = preProcess_loadDouble(inst, pos, opt, 0);
		getSecondOperand = preProcess_loadDouble(inst, pos, opt, 1);
		//DBG_LOGSCAN(buf, "\t[COMPARE]Loading double: %f, %f\n", getFirstOperand, getSecondOperand);PLC_LOG_addLog(buf);
		//DBG_LOGPRINT("\t[COMPARE]Loading double: %f, %f\n", getFirstOperand, getSecondOperand);
		double inf = 1.0/0;
		double sinf = -1.0/0;
		if(getFirstOperand==-0.f ||getSecondOperand==-0.f|| getFirstOperand==inf ||getSecondOperand==sinf)
		{
			//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
			handleExecError(ERROR_CODE_OUT_OF_VALUE_RANGE);
			return FALSE;
		}
	}
	else
	{
		//printf("line %d, function %s\n", __LINE__, __FUNCTION__);
		return FALSE;
	}

	if(functionType==FUNCTION_TYPE_LD)
	{

		if(compareFunction(getFirstOperand, getSecondOperand)==TRUE)
			ret = 1;
		else
			ret = 0;

		return postProcess_pushNewBranchedValue(inst, pos, opt, ret);
	}

	getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
	{
		//DBG_LOGSCAN(buf,"\t[%s] Error while picking current value.[pos = %d]\n", opt->strName, *pos);PLC_LOG_addLog(buf);
		return FALSE;
	}

	if(functionType==FUNCTION_TYPE_AND){


		if(compareFunction(getFirstOperand, getSecondOperand)==TRUE)
			ret = getCurrValue&0x01;
		else
			ret = getCurrValue&0x00;

		return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
	}
	else if(functionType==FUNCTION_TYPE_OR){

		if(compareFunction(getFirstOperand, getSecondOperand)==TRUE)
			ret = getCurrValue|0x01;
		else
			ret = getCurrValue|0x00;

		return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);

	}
	return FALSE;
}

inline uint8 inProcess_addInt(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	switch(byteSize){
		case 2:
		{
			short* srcVal1;
			short* srcVal2;
			short* tarVal;

			srcVal1 = (short*)src1;
			srcVal2 = (short*)src2;
			tarVal = (short*)tar;

			*tarVal = (*srcVal1) + (*srcVal2);
			//DBG_LOGSCAN(buf, "\t[CAL(%d)] %d(%X) = %d(%X) + %d(%X)\n", byteSize, *tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);	PLC_LOG_addLog(buf);
			//printf("\t[CAL(%d)] %d(%X) = %d(%X) + %d(%X)\n", byteSize, *tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);
			return TRUE;
		}
		case 4:
		{
			int* srcVal1;
			int* srcVal2;
			int* tarVal;

			srcVal1 = (int*)src1;
			srcVal2 = (int*)src2;
			tarVal = (int*)tar;
			//printf("\t[CAL(%d)] %d(%X) + %d(%X) = ", byteSize, *srcVal1, *srcVal1, *srcVal2, *srcVal2);
			*tarVal = *srcVal1 + *srcVal2;
			//printf("%d(%X)\n", *tarVal,*tarVal);
			//DBG_LOGSCAN(buf, "\t[CAL(%d)] %d(%X) = %d(%X) + %d(%X)\n", byteSize, *tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);PLC_LOG_addLog(buf);
			//printf("\t[CAL(%d)] %d(%X) = %d(%X) + %d(%X)\n", byteSize, *tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);
			return TRUE;
		}
		default:
		{
			return FALSE;
		}
	}
}
inline uint8 inProcess_subInt(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	switch(byteSize){
		case 2:
		{
			short* srcVal1;
			short* srcVal2;
			short* tarVal;

			srcVal1 = (short*)src1;
			srcVal2 = (short*)src2;
			//printf("\t[CAL(%d)] %d(%X) - %d(%X) = ", byteSize, *srcVal1, *srcVal2, *srcVal2, *srcVal2);
			tarVal = (short*)tar;
			//short srcV = *srcVal1;
			*tarVal = *srcVal1 - *srcVal2;
			//printf("%d(%X)\n", *tarVal,*tarVal);
			//DBG_LOGSCAN(buf, "\t[CAL(%d)] %d(%X) = %d(%X) - %d(%X)\n", byteSize, *tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);PLC_LOG_addLog(buf);

			return TRUE;
		}
		case 4:
		{
			int* srcVal1;
			int* srcVal2;
			int* tarVal;

			srcVal1 = (int*)src1;
			srcVal2 = (int*)src2;
			tarVal = (int*)tar;

			*tarVal = *srcVal1 - *srcVal2;
			//DBG_LOGSCAN(buf, "\t[CAL(%d)] %d(%X) = %d(%X) - %d(%X)\n", byteSize, *tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);PLC_LOG_addLog(buf);
			return TRUE;
		}
		default:
		{
			return FALSE;
		}
	}
}
inline uint8 inProcess_mltInt(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	switch(byteSize){
		case 2:
		{
			short* srcVal1;
			short* srcVal2;
			int* tarVal;

			srcVal1 = (short*)src1;
			srcVal2 = (short*)src2;
			tarVal = (int*)tar;
			//printf("srcVal1 %d, srcVal2 %d\n", *srcVal1,*srcVal2);
			*tarVal = (*srcVal1) * (*srcVal2);
			//printf("\t[CAL(%ld)] %d(%X) = %d(%X) * %d(%X)\n", sizeof(*tarVal), *tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);
			return TRUE;
		}
		case 4:
		{
			int* srcVal1;
			int* srcVal2;
			long long srclong1;
			long long srclong2;
			long long* tarVal;

			srcVal1 = (int*)src1;
			srcVal2 = (int*)src2;
			srclong1 =  *srcVal1 & 0x0FFFFFFFF;
			srclong2 =  *srcVal2 & 0x0FFFFFFFF;
			tarVal = (long long*)tar;
			//printf("\nsrc1 %d src2 %d tar %d", *srcVal1, *srcVal2, *tarVal);
			*tarVal = srclong1 * srclong2;
			//printf("%lld(%llX)\n", *tarVal,*tarVal);
			//DBG_LOGSCAN(buf, "\t[CAL(%ld)] %ld(%lX) = %ld(%lX) * %ld(%lX)\n", sizeof(*tarVal), *tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);	PLC_LOG_addLog(buf);
			//printf("src1 %d src2 %d tar %lld exec rst %lld\n", *srcVal1, *srcVal2, *tarVal, (*srcVal1)*(*srcVal2));
			return TRUE;
		}
		default:
		{
			return FALSE;
		}
	}
}
inline uint8 inProcess_divInt(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	switch(byteSize){
		case 2:
		{
			short* srcVal1;
			short* srcVal2;
			short* tarVal1 = (short*)&tar[0];
			short* tarVal2 = (short*)&tar[byteSize];

			srcVal1 = (short*)src1;
			srcVal2 = (short*)src2;
			//tarVal = (short*)tar;

			if((*srcVal2) ==0 )
			{
				handleExecError(ERROR_CODE_INVALID_VALUE);
				printf("\t[DIV] unable to div by 0!\n");
				return FALSE;
			}
			*tarVal1 = (*srcVal1) / (*srcVal2);
			*tarVal2 = (*srcVal1) % (*srcVal2);
			//memcpy(&tar[0], &tarVal[0], byteSize);
			//memcpy(&tar[byteSize], &tarVal[1], byteSize);
			//DBG_LOGSCAN(buf, "\t[CAL] %d(%X) = %d(%X) / %d(%X)\n",*tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);PLC_LOG_addLog(buf);

			//printf("\t[CAL] %d(%x) / %d(%x) = %d(%X) / %d(%X)\n",tarVal[0], tarVal[0], tarVal[1], tarVal[1], *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);
			return TRUE;
		}
		case 4:
		{
			int* srcVal1;
			int* srcVal2;
			int* tarVal1 = (int*)&tar[0];
			int* tarVal2 = (int*)&tar[byteSize];

			srcVal1 = (int*)src1;
			srcVal2 = (int*)src2;
			//tarVal = (int*)tar;

			if((*srcVal2) ==0 )
			{
				handleExecError(ERROR_CODE_INVALID_VALUE);
				printf("\t[DIV] unable to div by 0!\n");
				return FALSE;
			}
			*tarVal1 = (*srcVal1) / (*srcVal2);
			*tarVal2 = (*srcVal1) % (*srcVal2);
			//memcpy(&tar[0], &tarVal[0], byteSize);
			//memcpy(&tar[byteSize], &tarVal[1], byteSize);
			//DBG_LOGSCAN(buf, "\t[CAL] %d(%X) = %d(%X) / %d(%X)\n",*tarVal ,*tarVal , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);PLC_LOG_addLog(buf);
			//DBG_LOGPRINT("\t[CAL] %d(%X)|%d(%X) = %d(%X) / %d(%X)\n",*tarVal1,*tarVal1 ,*tarVal2 ,*tarVal2 , *srcVal1 ,*srcVal1 , *srcVal2, *srcVal2);
			return TRUE;
		}
		default:
		{
			return FALSE;
		}
	}
}

inline uint8 inProcess_addBCD(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	if(byteSize ==4)
	{
		uint32 srcBin1;
		uint32 srcBin2;
		//printf("src1 : 0x%X, src2 : 0x%X\n", *(int*)src1, *(int*)src2);
		uint32 dstBin = 0;
		if(!inprocess_convertBCDToBin(&srcBin1, src1, byteSize))
		{
			//printf("src1 converting [BCD->Bin] failed!\n");
			return FALSE;
		}
		if(!inprocess_convertBCDToBin(&srcBin2, src2, byteSize))
		{
			//printf("src2 converting [BCD->Bin] failed!\n");
			return FALSE;
		}
		if(!inProcess_addInt((uint8*)&dstBin, (uint8*)&srcBin1, (uint8*)&srcBin2, byteSize))
		{
			//printf("add int failed!\n");
			return FALSE;
		}
		if(!inprocess_convertBinToBCD(tar, &dstBin, byteSize))
		{
			//printf("dst converting [BCD<-Bin] failed!\n");
			return FALSE;
		}
	}else if(byteSize ==2)
	{
		uint16 srcBin1;
		uint16 srcBin2;
		//printf("src1 : 0x%X, src2 : 0x%X\n", *(short*)src1, *(short*)src2);
		uint16 dstBin = 0;
		if(!inprocess_convertBCDToBin(&srcBin1, src1, byteSize))
		{
			//printf("src1 converting [BCD->Bin] failed!\n");
			return FALSE;
		}
		if(!inprocess_convertBCDToBin(&srcBin2, src2, byteSize))
		{
			//printf("src2 converting [BCD->Bin] failed!\n");
			return FALSE;
		}
		if(!inProcess_addInt((uint8*)&dstBin, (uint8*)&srcBin1, (uint8*)&srcBin2, byteSize))
		{
			//printf("add int failed!\n");
			return FALSE;
		}
		if(!inprocess_convertBinToBCD(tar, &dstBin, byteSize))
		{
			//printf("dst converting [BCD<-Bin] failed!\n");
			return FALSE;
		}

	}
	return TRUE;
}
inline uint8 inProcess_subBCD(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	uint32 srcBin1;
	uint32 srcBin2;
	uint32 dstBin = 0;

	if(!inprocess_convertBCDToBin(&srcBin1, src1, byteSize))
		return FALSE;
	if(!inprocess_convertBCDToBin(&srcBin2, src2, byteSize))
		return FALSE;

	if(srcBin1<srcBin2)
	{
		if(byteSize==2)
			srcBin1+=10000;
		else if(byteSize==4)
			srcBin1+=100000000;
	}
	//printf("BCD SUB %d - %d\n", srcBin1, srcBin2);
	if(!inProcess_subInt((uint8*)&dstBin, (uint8*)&srcBin1, (uint8*)&srcBin2, byteSize))
		return FALSE;
	if(!inprocess_convertBinToBCD(tar, &dstBin, byteSize))
		return FALSE;
	return TRUE;
}
inline uint8 inProcess_mltBCD(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	uint32 srcBin1=0;
	uint32 srcBin2=0;
	long long dstBin = 0;
	unsigned long long dstBCDLong;
	//uint8 dstBCD[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	if(!inprocess_convertBCDToBin(&srcBin1, src1, byteSize))
		return FALSE;
	if(!inprocess_convertBCDToBin(&srcBin2, src2, byteSize))
		return FALSE;
	//printf("[byteSize = %d]bin1 : %ld * bin2 : %ld = ", byteSize, srcBin1, srcBin2);
	if(!inProcess_mltInt((uint8*)&dstBin, (uint8*)&srcBin1, (uint8*)&srcBin2, byteSize))
		return FALSE;
	//printf("dstBin : %lld \n", dstBin);
	if(!inprocess_convertBinToBCD(&dstBCDLong, &dstBin, 2*byteSize))
		return FALSE;
	//printf("tar1 (size = %d): %llX \n", 2*byteSize, dstBCDLong);
	memcpy(tar, &dstBCDLong, 2*byteSize);
	//printf("tar2 (size = %d): %llX \n", 2*byteSize, dstBCDLong);
	return TRUE;
}
inline uint8 inProcess_divBCD(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	uint32 srcBin1=0;
	uint32 srcBin2=0;
	long long dstBin = 0;
	//unsigned long long dstBCDLong;
	uint32 binRet[2], BCDRet[2];

	//uint8 dstBCD[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	if(!inprocess_convertBCDToBin(&srcBin1, src1, byteSize))
		return FALSE;
	if(!inprocess_convertBCDToBin(&srcBin2, src2, byteSize))
		return FALSE;

	if(!inProcess_divInt((uint8*)&dstBin, (uint8*)&srcBin1, (uint8*)&srcBin2, byteSize))
		return FALSE;
	printf("[byteSize = %d]bin1 : %d / bin2 : %d = 0x%08llX\n", byteSize, srcBin1, srcBin2, dstBin);
	if( byteSize ==2 )
	{
		binRet[0] = dstBin & 0x0FFFF;
		binRet[1] = (dstBin>>16) & 0x0FFFF;
	}
	else if( byteSize == 4 ){
		binRet[0] = dstBin & 0x0FFFFFFFF;
		binRet[1] = (dstBin>>32) & 0x0FFFFFFFF;
	}
	printf("binRet d= %d %d [%04X%04X]\n", binRet[0], binRet[1], binRet[1],  binRet[0]);
	if(!inprocess_convertBinToBCD(&BCDRet[0], &binRet[0], byteSize))
		return FALSE;
	if(!inprocess_convertBinToBCD(&BCDRet[1], &binRet[1], byteSize))
		return FALSE;
	printf("BCDRet X= %X %X\n", BCDRet[0], BCDRet[1]);

	memcpy(&tar[0], &BCDRet[0], byteSize);
	memcpy(&tar[byteSize], &BCDRet[1], byteSize);

	//printf("tar (size = %d): %X %X\n", 2*byteSize, BCDRet[0], BCDRet[1]);
	return TRUE;
}

inline uint8 inProcess_addFloat(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	switch(byteSize){
		case 2:
		case 4:
		{
			float *srcVal1;
			float *srcVal2;
			float *tarVal;

			srcVal1 =  (float*)src1;
			srcVal2 =  (float*)src2;
			//printf(buf, "\t[CAL] %.f + %.f",*srcVal1 , *srcVal2);
			tarVal = (float*)tar;
			*tarVal = (*srcVal1) + (*srcVal2);
			//printf(buf, "%.f\n", *tarVal);
			//DBG_LOGPRINT("\t[CAL] %.f = %.f + %.f\n",*tarVal , *srcVal1 , *srcVal2);
			//PLC_LOG_addLog(buf);
			return TRUE;
		}
		case 8:
		{

			double* srcVal1;
			double* srcVal2;
			double* tarVal;

			srcVal1 = (double*)src1;
			srcVal2 = (double*)src2;
			//printf(buf, "\t[CAL] %.f + %.f",*srcVal1 , *srcVal2);
			tarVal = (double*)tar;
			*tarVal = (*srcVal1) + (*srcVal2);
			//DBG_LOGSCAN(buf, "\t[CAL] %.f = %.f + %.f\n",*tarVal , *srcVal1 , *srcVal2);	PLC_LOG_addLog(buf);
			return TRUE;
		}
		default:
		{
			return FALSE;
		}
	}
}
inline uint8 inProcess_subFloat(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	switch(byteSize){
		case 2:
		case 4:
		{
			float* srcVal1;
			float* srcVal2;
			float* tarVal;

			srcVal1 = (float*)src1;
			srcVal2 = (float*)src2;
			tarVal = (float*)tar;

			*tarVal = *srcVal1 - *srcVal2;
			//DBG_LOGSCAN(buf, "\t[CAL] %.f = %.f - %.f\n",*tarVal , *srcVal1 , *srcVal2);PLC_LOG_addLog(buf);
			return TRUE;
		}
		case 8:
		{
			double* srcVal1;
			double* srcVal2;
			double* tarVal;

			srcVal1 = (double*)src1;
			srcVal2 = (double*)src2;
			tarVal = (double*)tar;

			*tarVal = *srcVal1 - *srcVal2;
			//DBG_LOGSCAN(buf, "\t[CAL] %.f = %.f - %.f\n",*tarVal , *srcVal1 , *srcVal2);PLC_LOG_addLog(buf);
			return TRUE;
		}
		default:
		{
			return FALSE;
		}
	}
}
inline uint8 inProcess_mltFloat(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	switch(byteSize){
		case 2:
		case 4:
		{
			float* srcVal1;
			float* srcVal2;
			float* tarVal;

			srcVal1 = (float*)src1;
			srcVal2 = (float*)src2;
			tarVal = (float*)tar;

			*tarVal = (*srcVal1) * (*srcVal2);
			//DBG_LOGSCAN(buf, "\t[CAL] %.f = %.f * %.f\n",*tarVal , *srcVal1 , *srcVal2);PLC_LOG_addLog(buf);
			return TRUE;
		}case 8:
		{
			double* srcVal1;
			double* srcVal2;
			double* tarVal;

			srcVal1 = (double*)src1;
			srcVal2 = (double*)src2;
			tarVal = (double*)tar;

			*tarVal = (*srcVal1) * (*srcVal2);
			//DBG_LOGSCAN(buf, "\t[CAL] %.f = %.f * %.f\n",*tarVal , *srcVal1 , *srcVal2);PLC_LOG_addLog(buf);
			return TRUE;
		}
		default:
		{
			return FALSE;
		}
	}
}
inline uint8 inProcess_divFloat(uint8* tar, uint8* src1, uint8* src2, uint8 byteSize){
	switch(byteSize){
		case 2:
		case 4:
		{
			float* srcVal1;
			float* srcVal2;
			float* tarVal;

			srcVal1 = (float*)src1;
			srcVal2 = (float*)src2;
			tarVal = (float*)tar;
			if((*srcVal2) ==0.f )
			{
				handleExecError(ERROR_CODE_INVALID_VALUE);
				return FALSE;
			}

			*tarVal = (*srcVal1) / (*srcVal2);
			//DBG_LOGPRINT("\t[CAL] %.f = %.f / %.f\n",*tarVal , *srcVal1 , *srcVal2);
			return TRUE;
		}
		case 8:
		{
			double* srcVal1;
			double* srcVal2;
			double* tarVal;

			srcVal1 = (double*)src1;
			srcVal2 = (double*)src2;
			tarVal = (double*)tar;
			if((*srcVal2) ==0.f)
			{
				handleExecError(ERROR_CODE_INVALID_VALUE);
				return FALSE;
			}

			*tarVal = (*srcVal1) / (*srcVal2);
			//DBG_LOGSCAN(buf, "\t[CAL] %.f = %.f / %.f\n",*tarVal , *srcVal1 , *srcVal2);PLC_LOG_addLog(buf);
			return TRUE;
		}
		default:
		{
			return FALSE;
		}
	}
}
inline uint8 inprocess_convertBinToBCD(void* dstBCD, void* srcBin, uint8 byteSize){
	if(byteSize==2)
	{
		uint16* dst = dstBCD;
		uint16* src = srcBin;

		*dst = (*src)%10 + (((*src)/10)%10<<4) + (((*src)/100)%10<<8) + (((*src)/1000)%10<<12);
		if(*dst>0x9999)
		{
			(*dst)-=0x10000;
		}
		//DBG_LOGSCAN(buf, "\t[B>BCD out(%d)] dstBCD = [X]%X, srcBin= [D]%d\n", byteSize, *dst, *src);PLC_LOG_addLog(buf);
	}
	else if(byteSize==4)
	{
		uint32* dst = (uint32*)dstBCD;
		uint32* src =  (uint32*)srcBin;

		*dst = (*src)%10 + (((*src)/10)%10<<4) + (((*src)/100)%10<<8) + (((*src)/1000)%10<<12)
				+  (((*src)/10000)%10<<16) + (((*src)/100000)%10<<20) + (((*src)/1000000)%10<<24) + (((*src)/10000000)%10<<28);
		if((*dst)>0x99999999 )
				{
					(*dst)-=0x100000000;
				}
		//DBG_LOGPRINT("\t[DBCD out(%d)] dstBCD = [X]%X, srcBin= [D]%d\n", byteSize, *dst, *src);
		//DBG_LOGSCAN(buf, "\t[B>BCD out(%d)] dstBCD = [X]%X, srcBin= [D]%d\n", byteSize, *dst, *src);	PLC_LOG_addLog(buf);
	}
	else if(byteSize==8)
	{
		long long* dst = (long long*)dstBCD;
		long long* src =  (long long*)srcBin;
		long long dstVal=0;
		//printf("%src = %lld\n", *src);
		if(*dst>0x9999999999999999 )
		{
			//printf( "dst value = %d is out of range!\n", *dst);
			//handleExecError(ERROR_CODE_INVALID_VALUE);
			(*dst)-=(long long)0x10000000000000000;
		}
		//printf("srcBin %lld\n", *src);
		//DBG_LOGPRINT("srcX %X \n", (((*src)/100000000)%10<<32) );
		dstVal = 		(*src)%10 + (((*src)/10)%10<<4) + (((*src)/100)%10<<8) + (((*src)/1000)%10<<12)
				+  (((*src)/10000)%10<<16) + (((*src)/100000)%10<<20) + (((*src)/1000000)%10<<24) + (((*src)/10000000)%10<<28)
				+  (((*src)/100000000)%10<<32) + (((*src)/1000000000)%10<<36) + (((*src)/10000000000)%10<<40) + (((*src)/100000000000)%10<<44)
				+  (((*src)/1000000000000)%10<<48) + (((*src)/10000000000000)%10<<52) + (((*src)/100000000000000)%10<<56) + (((*src)/1000000000000000)%10<<60);
		//printf("dstVal %llX, size of type unsigned long int : %d\n", dstVal, sizeof(unsigned long int));
		*dst = dstVal;
		//printf("dst %llX, size of type unsigned long int : %d\n", *dst, sizeof(unsigned long int));
		//DBG_LOGSCAN(buf, "\t[B>BCD out(%d)] dstBCD = [X]%lX, srcBin= [D]%d\n", byteSize, dst[0]+0x100000000*dst[1], *src);		PLC_LOG_addLog(buf);
	}
	return TRUE;

}
inline void inprocess_convertBinToFloat(void* dstFloat, void* srcBin, uint8 byteSize){
	if(byteSize==2)
	{
		float* dst = (float*)dstFloat;
		short* src = srcBin;
		*dst = *src;
		//DBG_LOGSCAN(buf, "\t[B>F out] dstFloat = [F]%F, srcBin= [X]%X\n", *dst, *src);		PLC_LOG_addLog(buf);
	}
	else if(byteSize==4)
	{
		float* dst = (float*)dstFloat;
		int* src =  (int*)srcBin;
		*dst = *src;
		//DBG_LOGSCAN(buf, "\t[B>F out] dstFloat = [F]%F, srcBin= [X]%X\n", *dst, *src);	PLC_LOG_addLog(buf);
	}
	return;

}
inline void inprocess_convertFloatToBin(void* dstBin, void* srcFloat, uint8 byteSize){
	if(byteSize==2)
	{
		short* dst = (short*)dstBin;
		float* src = (float*)srcFloat;
		//DBG_LOGPRINT("\t] Load dst [F]%F[X]%X, src= [f]%f\n", (float)*dst, (int)*dst, (float)*src);
		*dst = *src;//+0.5;

		if(0.5f <= (*src-*dst))
		{
			*dst = *dst+1;
		}
		//DBG_LOGPRINT("\t[F>B out] dstFloat = [F]%F[X]%X, srcBin= [f]%f\n", (float)*dst, (int)*dst, (float)*src);
	}
	else if(byteSize==4)
	{
		int* dst = (int*)dstBin;
		float* src =  (float*)srcFloat;
		*dst = (int)*src;//+0.5;
		//DBG_LOGPRINT("\t[F > B Load] dst(%d), src(%d)\n", *dst, *src);
		if(0.5f <= *src-*dst)
		{

			*dst = *dst+1;
			//DBG_LOGPRINT("\t[F>B out] dstFloat = [F]%F[X]%X, srcBin= [X]%X\n", (float)*dst, (int)*dst, (short)*src);
		}

	}
	return;
}
inline void inprocess_convertBinToDouble(void* dstDouble, void* srcBin, uint8 byteSize){

	if(byteSize==2)
	{
		double* dst = (double*)dstDouble;
		short* src = srcBin;
		*dst = *src;
		if(0.5f <= *src-*dst)
			*dst = *dst+1;
		//DBG_LOGSCAN(buf, "\t[B>F out] dstdouble = [F]%F, srcBin= [X]%X\n", *dst, *src);		PLC_LOG_addLog(buf);
	}
	else if(byteSize==4)
	{
		double* dst = (double*)dstDouble;
		int* src =  (int*)srcBin;
		*dst = *src;
		if(0.5f <= *src-*dst)
			*dst = *dst+1;
		//DBG_LOGSCAN(buf, "\t[B>F out] dstdouble = [F]%F, srcBin= [X]%X\n", *dst, *src);		PLC_LOG_addLog(buf);
	}
	return;

}
inline void inprocess_convertDoubleToBin(void* dstBin, void* srcDouble, uint8 byteSize){
	if(byteSize==2)
	{
		short* dst = (short*)dstBin;
		double* src = (double*)srcDouble;
		*dst = *src;
		//DBG_LOGSCAN(buf, "\t[F>B out] dstdouble = [F]%F, srcBin= [X]%X\n", (float)*dst, (short)*src);		PLC_LOG_addLog(buf);
	}
	else if(byteSize==4)
	{
		int* dst = (int*)dstBin;
		double* src =  (double*)srcDouble;
		*dst = *src;
		//DBG_LOGSCAN(buf, "\t[F>B out] dstdouble = [F]%F, srcBin= [X]%X\n", (float)*dst, (short)*src);		PLC_LOG_addLog(buf);
	}
	return;
}

inline uint8 inprocess_convertBCDToBin(void* dstBin, void* srcBCD, uint8 byteSize){
	/*uint8* dstprint = dstBin;
	uint8* srcprint = srcBCD;
	printf("start : dst %02X %02X %02X %02X  || src %02X %02X %02X %02X\n",
				dstprint[0], dstprint[1], dstprint[2], dstprint[3],
				srcprint[0], srcprint[1], srcprint[2], srcprint[3]
				);*/
	if(byteSize==2)
	{
		short* dst = (short*)dstBin;
		short* src = (short*)srcBCD;
		uint16 testSRC = *(uint16*)srcBCD;
		//DBG_LOGPRINT("src to conversion : 0x%04X\n", testSRC);
		int i;
		for(i=0;i<4;i++)
		{
			if((testSRC&0x0F)>9)
			{
				DBG_LOGPRINT("0x%04X is not a BCD form :%d[%d]!\n", testSRC,(testSRC>>(i*4))&0x0F, i);
				handleExecError(ERROR_CODE_INVALID_VALUE);
				return FALSE;
			}
			testSRC = testSRC>>4;
		}

		*dst = ((*src>>0)&0x0F)+((*src>>4)&0x0F)*10+((*src>>8)&0x0F)*100+((*src>>12)&0x0F)*1000;
		//DBG_LOGSCAN(buf, "\t[BCD>Bin out] dstBin = [D]%d, srcBCD = [X]%X\n", *dst, *src);		PLC_LOG_addLog(buf);
		//printf("\t[BCD>Bin out[2]] dstBin = [D]%d <== srcBCD = [X]%X\n", *dst, *src);
	}
	else if(byteSize==4)
	{
		int* dst = (int*)dstBin;
		uint32* src =  (uint32*)srcBCD;
		int testSRC = *src;
		//printf("0x%08X 0x%08X 0x%08X\n",*dst, *src, testSRC);
		int i;
		for(i=0;i<8;i++)
		{
			//if(((testSRC>>(i*4))&0x0F)>9)
			if((testSRC&0x0F)>9)
			{
				DBG_LOGPRINT("0x%08X is not a BCD form :%d[%d]!\n", testSRC,(testSRC>>(i*4))&0x0F, i);
				handleExecError(ERROR_CODE_INVALID_VALUE);
				return FALSE;
			}
			testSRC = testSRC>>4;
		}
		*dst = ((*src>>0)&0x0F) + ((*src>>4)&0x0F)*10 + ((*src>>8)&0x0F)*100 + ((*src>>12)&0x0F)*1000
				+  ((*src>>16)&0x0F)*10000 + ((*src>>20)&0x0F)*100000 + ((*src>>24)&0x0F)*1000000 + ((*src>>28)&0x0F)*10000000;
		//DBG_LOGSCAN(buf, "\t[BCD>Bin out] dstBin = [D]%d, srcBCD = [X]%X\n", *dst, *src);		PLC_LOG_addLog(buf);
		//printf("\t[BCD>Bin out[4]] dstBin = [D]%d, srcBCD = [X]%X\n", *dst, *src);
	}
	/*printf("end : dst %02X %02X %02X %02X  || src %02X %02X %02X %02X\n",
			dstprint[0], dstprint[1], dstprint[2], dstprint[3],
			srcprint[0], srcprint[1], srcprint[2], srcprint[3]
			);*/
	return TRUE;
}

inline uint32 inProcess_logicAnd(uint32 src1, uint32 src2){return src1 & src2;}
inline uint32 inProcess_logicOr(uint32 src1, uint32 src2){return src1 | src2;}
inline uint32 inProcess_logicXor(uint32 src1, uint32 src2){return src1 ^ src2;}
inline uint32 inProcess_logicXnr(uint32 src1, uint32 src2){return !(src1 ^ src2);}

inline uint32 binaryToGray(uint32 num)
{
        return (num >> 1) ^ num;
}
inline uint32 grayToBinary(uint32 num)
{
    unsigned long long mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;
    }
    return num;
}

inline void  inprocess_convertGrayToBin(void* dstBin, void* srcGray, uint8 byteSize){
	if(byteSize==2)
	{
		uint16* dst = (uint16*)dstBin;
		uint16* src = (uint16*)srcGray;
		*dst = grayToBinary(*src);
		//DBG_LOGSCAN(buf, "\t[Gray>Bin out] dstBin = [X]%X, srcBCD = [X]%X\n", *dst, *src);		PLC_LOG_addLog(buf);
	}
	else if(byteSize==4)
	{
		uint32* dst = (uint32*)dstBin;
		uint32* src =  (uint32*)srcGray;
		*dst = grayToBinary(*src);
		//DBG_LOGSCAN(buf, "\t[Gray>Bin out] dstBin = [X]%X, srcBCD = [X]%X\n", *dst, *src);		PLC_LOG_addLog(buf);
	}

	return;
}

inline void  inprocess_convertBinToGray(void* dstGray, void* srcBin, uint8 byteSize){
	if(byteSize==2)
	{
		uint16* dst = dstGray;
		uint16* src = srcBin;
		*dst = binaryToGray(*src);
		//DBG_LOGSCAN(buf, "\t[B>Gray out] dstBCD = [X]%X, srcBin= [X]%d\n", *dst, *src);		PLC_LOG_addLog(buf);
	}
	else if(byteSize==4)
	{
		uint32* dst = (uint32*)dstGray;
		uint32* src =  (uint32*)srcBin;
		*dst = binaryToGray(*src);
		//DBG_LOGSCAN(buf, "\t[B>Gray out] dstBCD = [X]%X, srcBin= [X]%d\n", *dst, *src);		PLC_LOG_addLog(buf);
	}
	return;

}

inline void inProcess_rewindPulseDeltaStack(){

	dev.nCurrPulseStackPosision=0;
	dev.nCurrDeltaStackPosision=0;
	dev.device_block_stack.size = 0;
}
inline uint32 inProcess_isEqual(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	short* in1 = (short*) inFirst;
	short* in2 = (short*) inSecond;
	uint32 ret = (*in1==*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//DBG_LOGPRINT("\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);
	return ret;

}
inline uint32 inProcess_isNotEqual(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	short* in1 = (short*) inFirst;
	short* in2 = (short*) inSecond;
	uint32 ret = (*in1!=*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//printf("\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);
	return ret;
}
inline uint32 inProcess_isGreaterThan(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	short* in1 = (short*) inFirst;
	short* in2 = (short*) inSecond;
	uint32 ret = (*in1>*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//DBG_LOGPRINT("\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);
	return ret;
}
inline uint32 inProcess_isLesserThan(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	short* in1 = (short*) inFirst;
	short* in2 = (short*) inSecond;
	uint32 ret = (*in1<*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//printf("\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);
	return ret;
}
inline uint32 inProcess_isGreaterOrEqual(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	short* in1 = (short*) inFirst;
	short* in2 = (short*) inSecond;
	uint32 ret = (*in1>=*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//printf("\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);
	return ret;
}
inline uint32 inProcess_isLesserOrEqual(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	short* in1 = (short*) inFirst;
	short* in2 = (short*) inSecond;
	uint32 ret = (*in1<=*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//printf("\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);
	return ret;
}
///////////////////
inline uint32 inProcess_isDWordEqual(void* inFirst, void* inSecond){

	int* in1 = (int*) inFirst;
	int* in2 = (int*) inSecond;
	uint32 ret = (*in1==*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//DBG_LOGPRINT("\t[%s] ret = %d[%d:%d]\n",__FUNCTION__, ret, *in1, *in2);
	return ret;

}
inline uint32 inProcess_isDWordNotEqual(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	int* in1 = (int*) inFirst;
	int* in2 = (int*) inSecond;
	uint32 ret = (*in1!=*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//DBG_LOGPRINT("\t[%s] ret = %d[%d:%d]\n",__FUNCTION__, ret, *in1, *in2);
	return ret;

}
inline uint32 inProcess_isDWordGreaterThan(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	int* in1 = (int*) inFirst;
	int* in2 = (int*) inSecond;
	uint32 ret = (*in1>*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//DBG_LOGPRINT("\t[%s] ret = %d[%d:%d]\n",__FUNCTION__, ret, *in1, *in2);
	return ret;

}
inline uint32 inProcess_isDWordLesserThan(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	int* in1 = (int*) inFirst;
	int* in2 = (int*) inSecond;
	uint32 ret = (*in1<*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//DBG_LOGPRINT("\t[%s] ret = %d[%d:%d]\n",__FUNCTION__, ret, *in1, *in2);
	return ret;

}
inline uint32 inProcess_isDWordGreaterOrEqual(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	int* in1 = (int*) inFirst;
	int* in2 = (int*) inSecond;
	uint32 ret = (*in1>=*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//DBG_LOGPRINT("\t[%s] ret = %d[%d:%d]\n",__FUNCTION__, ret, *in1, *in2);
	return ret;

}
inline uint32 inProcess_isDWordLesserOrEqual(void* inFirst, void* inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	int* in1 = (int*) inFirst;
	int* in2 = (int*) inSecond;
	uint32 ret = (*in1<=*in2)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare] ret = %d[%d:%d]\n", ret, *in1, *in2);	PLC_LOG_addLog(buf);
	//DBG_LOGPRINT("\t[%s] ret = %d[%d:%d]\n",__FUNCTION__, ret, *in1, *in2);
	return ret;
}
///////////////////
inline uint32 inProcess_isDoubleEqual(double inFirst, double inSecond){

	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	uint32 ret = (inFirst==inSecond)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare1] ret = %d[%f = %X : %f = %X]\n", ret, * (double*) inFirst, * (double*) inFirst, *(double*) inSecond, *(double*) inSecond);PLC_LOG_addLog(buf);
	//DBG_LOGSCAN(buf, "\t[compare2] ret = %d[%f : %f]\n", ret, inFirst, inSecond);PLC_LOG_addLog(buf);
	//DBG_LOGPRINT("\t[compare2] ret = %d[%f : %f]\n", ret, inFirst, inSecond);
	return ret;

}
inline uint32 inProcess_isDoubleNotEqual(double inFirst, double inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	uint32 ret = (inFirst!=inSecond)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare1] ret = %d[%f = %X : %f = %X]\n", ret, * (double*) inFirst, * (double*) inFirst, *(double*) inSecond, *(double*) inSecond);PLC_LOG_addLog(buf);
	//DBG_LOGSCAN(buf, "\t[compare2] ret = %d[%f : %f]\n", ret, inFirst, inSecond);PLC_LOG_addLog(buf);
	return ret;
}
inline uint32 inProcess_isDoubleGreaterThan(double inFirst, double inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	uint32 ret = (inFirst>inSecond)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare2] ret = %d[%f : %f]\n", ret, inFirst, inSecond);PLC_LOG_addLog(buf);
	return ret;
}
inline uint32 inProcess_isDoubleLesserThan(double inFirst, double inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	uint32 ret = (inFirst<inSecond)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare2] ret = %d[%f : %f]\n", ret, inFirst, inSecond);PLC_LOG_addLog(buf);
	return ret;

	//return PLC_DEVICE_FALSE_32;
}
inline uint32 inProcess_isDoubleGreaterOrEqual(double inFirst, double inSecond){
	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	uint32 ret = (inFirst>=inSecond)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare2] ret = %d[%f : %f]\n", ret, inFirst, inSecond);PLC_LOG_addLog(buf);
	return ret;
}
inline uint32 inProcess_isDoubleLesserOrEqual(double inFirst, double inSecond){

	//DBG_LOGPRINT("\t[%s]start\n", __FUNCTION__);
	uint32 ret = (inFirst<=inSecond)? TRUE:FALSE;
	//DBG_LOGSCAN(buf, "\t[compare2] ret = %d[%f : %f]\n", ret, inFirst, inSecond);PLC_LOG_addLog(buf);
	return ret;
}

inline uint8 inProcess_transperBlock(uint8 inst[], uint32 pos, uint8 wordSize, uint8 F_OR_B){
	uint8* dstOpnd = inProcess_getIndexedOperand(inst, pos, 1);
	uint8* srcOpnd = inProcess_getIndexedOperand(inst, pos, 0);
	uint8* thirdOpnd = inProcess_getIndexedOperand(inst, pos, 2);

	uint16 srcLength = PLC_DEVICE_getDeviceWordValue(thirdOpnd);
	if(srcLength ==0xFFFF)
	{
		DBG_LOGPRINT("[Error inProcess_transperBlock] invalid 3rd operand is loaded!\n");
		return FALSE;
	}

		//in

	if(srcOpnd==NULL || dstOpnd == NULL)
	{
		DBG_LOGPRINT("[Error inProcess_transperBlock]Null operand is loaded!\n");
		return FALSE;
	}
	if(!PLC_DEVICE_copyDeviceBLK_new(dstOpnd,srcOpnd,srcLength, wordSize, F_OR_B))
	{
		DBG_LOGPRINT("[Error inProcess_transperBlock] PLC_DEVICE_copyDeviceBLK_new returns Error!\n");
		return FALSE;
	}
	return TRUE;
}
///////////////////

inline uint8 inProcess_addString(uint8* target, uint8* source1, uint8* source2){
	uint16 src1Length = 0;
	uint16 src2Length = 0;
	uint16 MAX_STR_LENGTH = 16383;
	src1Length = strlen((char*)source1);
	src2Length = strlen((char*)source2);
	//DBG_LOGSCAN(buf, "\t[SET STR] src1Length : %d, src2Length : %d\n", src1Length,src2Length);
	if(src1Length+src2Length>MAX_STR_LENGTH)
	{
		//DBG_LOGSCAN(buf, "\t[ERROR] src1Length+src2Length>MAX_STR_LENGTH:%d + %d = %d\n", src1Length,src2Length,MAX_STR_LENGTH);		PLC_LOG_addLog(buf);
		return FALSE;
	}
	if( target + src1Length+src2Length> source1 && target< source1)
	{
		//DBG_LOGSCAN(buf, "\t[ERROR] target + src1Length+src2Length> source1 && target< source1\n");		PLC_LOG_addLog(buf);
		return FALSE;
	}
	if( target + src1Length+src2Length> source2 && target< source2)
	{
		//DBG_LOGSCAN(buf, "\t[ERROR] target + src1Length+src2Length> source2 && target< source2\n");		PLC_LOG_addLog(buf);
		return FALSE;
	}
	strcpy((char*)target, (char*)source1);
	strcat((char*)target, (char*)source2);
	//DBG_LOGSCAN(buf, "\t[SET STR] TAR:%s\n", target);	PLC_LOG_addLog(buf);
	return TRUE;

}
inline uint8* inProcess_getIndexedOperand(uint8 inst[], uint32 pos, uint8 opndIdx){

	uint32 currPos = pos+OPERATOR_LENGTH;
	int idx;
	for(idx = 0; idx<opndIdx; idx++)
	{
		currPos += OPND_DICT_ByteSize(&inst[currPos]);
	}
	return &inst[currPos];
}

inline uint8* inProcess_getNextIndexedOperand(uint8 inst[], uint32 *pos){

	uint8* ret = &inst[*pos];
	(*pos) += OPND_DICT_ByteSize(&inst[(*pos)]);
	if(ret[0] == OPERAND_ML_CODE_FUNC_OP)
	{
		uint16* idx = (uint16*)&ret[1];
		if(*idx>4)
			return NULL;
		ret = inProcess_getsubstitutedOperand(*idx);
	}
	return ret;
}

inline uint32 inProcess_outTC(uint8 isTimer, uint16 addr, uint16 setValue, uint8 timerMode, uint8 isPulse, uint32* pos){
	//printf("%s : %d, pos : %d\n", __FUNCTION__,__LINE__, *pos);
	uint16 fastValue = preProcess_pick(*pos);
	//printf("%s : %d\n", __FUNCTION__,__LINE__);
	uint16 currValue = getCurrBitValue(*pos);
	//printf("%s : %d\n", __FUNCTION__,__LINE__);
	//printf("%s %d\n",__FUNCTION__, __LINE__);
	if(isPulse && !inProcess_detectRaisingEdge(currValue, fastValue))
	{
		return TRUE;
	}
	//printf("%s %d\n",__FUNCTION__, __LINE__);
	//printf("%s : %d\n", __FUNCTION__,__LINE__);
	if(!currValue)
		return TRUE;
	//printf("%s %d\n",__FUNCTION__, __LINE__);
	//printf("%s : %d\n", __FUNCTION__,__LINE__);
	if(isTimer)
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		if(addr>=OPERAND_SIZE_T)
		{
			//printf("%s : %d\n", __FUNCTION__,__LINE__);
			return PLC_DEVICE_FALSE_32;
		}
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		PLC_Register_setTimer(addr, timerMode, setValue);
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
	}
	else
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		if(addr>=OPERAND_SIZE_C)
		{
			return PLC_DEVICE_FALSE_32;
		}
		PLC_Register_setCount(addr, setValue);
	}
	//printf("%s : %d\n", __FUNCTION__,__LINE__);
	return TRUE;
}

inline void inProcess_outC(uint16 trigger, uint16 countIdx, uint16 setValue){
	//DBG_LOGPRINT("OUT_C input = %d(trigger) %d(countIdx) %d(setValue)\n", trigger, countIdx, setValue);
	if(trigger)
	{
//#define COUNT_LOG
		//if(PLC_Register_getCount(countIdx, VALUE_TYPE_ISON)==TRUE)
		//{
#ifdef COUNT_LOG
			DBG_LOGPRINT("OUT_C is on!\n");
#endif
			if(PLC_Register_getCount(countIdx, VALUE_TYPE_RET)!=TRUE)
			{
#ifdef COUNT_LOG
				DBG_LOGPRINT("OUT_C is not true!\n");
#endif
				if(PLC_Register_getCount(countIdx, VALUE_TYPE_CURR)<setValue)
				{
#ifdef COUNT_LOG
					DBG_LOGPRINT("OUT_C is not reached yet!([C%d]%d : %d)\n",countIdx, PLC_Register_getCount(countIdx, VALUE_TYPE_CURR),setValue);
#endif
					/*DBG_LOGSCAN(buf, "\t[%s] : increase C%d : %d->%d\n", __FUNCTION__, countIdx,
							PLC_Register_getCount(countIdx, VALUE_TYPE_CURR), PLC_Register_getCount(countIdx, VALUE_TYPE_CURR)+1);PLC_LOG_addLog(buf);
							*/
					if(!PLC_Register_increaseCount(countIdx, setValue))
					{
						DBG_LOGPRINT("OUT_C increasing failed!\n");
					}
				}
				else
				{
#ifdef COUNT_LOG
					DBG_LOGPRINT("OUT_C is reached !([C%d]%d : %d)\n",countIdx, PLC_Register_getCount(countIdx, VALUE_TYPE_CURR),setValue);
#endif
					/*DBG_LOGSCAN(buf, "\t[%s] : Set C%d true .\n", __FUNCTION__, countIdx);PLC_LOG_addLog(buf);*/
					PLC_Register_setCValue(countIdx, VALUE_TYPE_RET, TRUE);
					PLC_Register_setCValue(countIdx, VALUE_TYPE_CURR, 0);
				}
			}
			else
			{
				//DBG_LOGSCAN(buf, "\t[%s] : Keeping C%d value as true .\n", __FUNCTION__, countIdx);PLC_LOG_addLog(buf);
			}
			//return postProcess_nop(inst, pos, opt);
		//}
		/*else{
			DBG_LOGPRINT("OUT_C is turnning on!\n");

			PLC_Register_setCValue(countIdx, VALUE_TYPE_ISON, TRUE);
			PLC_Register_setCValue(countIdx, VALUE_TYPE_SET, setValue);
			PLC_Register_setCValue(countIdx, VALUE_TYPE_CURR, 0);
		}*/
		//PLC_Register_setTValue(addr1, VALUE_TYPE_CURR, currTime);
		//TODO::PLC_Register_runTimer

	}
	/*else
	{
		DBG_LOGPRINT("\t[OUT_C] reset! curr = 0\n");
		PLC_Register_setCValue(countIdx, VALUE_TYPE_ISON, FALSE);
		PLC_Register_setCValue(countIdx, VALUE_TYPE_SET, 0);
		PLC_Register_setCValue(countIdx, VALUE_TYPE_CURR, 0);
		PLC_Register_setCValue(countIdx, VALUE_TYPE_RET, FALSE);
	}*/
}

inline void inProcess_outT(uint16 trigger, uint16 timerIdx, long long setValue, uint8 setMode){
	//printf("%s %d\n",__FUNCTION__, __LINE__);
	//printf("setVal = %d, old setVal = %d\n",PLC_Register_getTimer(timerIdx, VALUE_TYPE_SET),PLC_Register_getTimer(timerIdx, VALUE_TYPE_SET_OLD));


	//DBG_LOGPRINT("curr time : %s : tmr(%d)\n", timeToString(t), timer);
	if(trigger)
	{
		struct timespec mytime;
		long long currTimeUnit;

		//clock_t curr;
		//DBG_LOGPRINT("clock : %lldus = %lldms = %llds\n", curr, curr/1000, curr/1000000);

		//curr = clock();
		clock_gettime(CLOCK_MONOTONIC, &mytime);
		if(setMode ==TIMER_MODE_HIGH || setMode ==TIMER_MODE_HIGH_STORE)
		{
			currTimeUnit = (long long)(mytime.tv_sec*1000 + mytime.tv_nsec/1000000); // 1ms
			//currTimeUnit = (long long)curr/10;
		}
		else
		{
			//currTimeUnit = (long long)curr/10;
			currTimeUnit = (long long)(mytime.tv_sec*10 + mytime.tv_nsec/100000000); //100 ms
		}

		//printf("gettimeofday setMode=%d sec=%ld cur=%lld \n", setMode, (unsigned long)mytime.tv_sec, currTimeUnit);
		if(!PLC_Register_getTimer(timerIdx, VALUE_TYPE_ISON))
		{/*is Off*/
			PLC_Register_setTValue(timerIdx, VALUE_TYPE_ISON, TRUE);
			PLC_Register_setTValue(timerIdx, VALUE_TYPE_SET, setValue);
			PLC_Register_setTValue(timerIdx, VALUE_TYPE_CURR, 0);
			//DBG_LOGPRINT("[T%d]Turn on timer (setValue = %lld)\n", timerIdx, setValue);

		}
		//DBG_LOGPRINT("Timer is on? : [T%d] %d\n", timerIdx, PLC_Register_getTimer(timerIdx, VALUE_TYPE_RET));
		if(PLC_Register_getTimer(timerIdx, VALUE_TYPE_RET)!=TRUE)/*T-ON and Not reached to final value*/
		{
			long long pastTimeUnit= PLC_Register_getTimer(timerIdx, VALUE_TYPE_CURR);
			//long long tarValue =  PLC_Register_getTimer(timerIdx, VALUE_TYPE_SET);
			//printf("Curr time state : %lld = %lld - %lld, tar = %lld\n", currTimeUnit- pastTimeUnit, currTimeUnit, pastTimeUnit, tarValue);

			if(pastTimeUnit ==0 || currTimeUnit - pastTimeUnit < PLC_Register_getTimer(timerIdx, VALUE_TYPE_SET))/*On Going*/
			{
				if(pastTimeUnit ==0)
				{
					PLC_Register_setTValue(timerIdx, VALUE_TYPE_CURR, currTimeUnit);
					//DBG_LOGPRINT("timer is now staring : [T%d]%lld\n", timerIdx, setValue);
				}
				//DBG_LOGSCAN(buf, "\t[%s] : increase T%d : %d->%d\n", __FUNCTION__, timerIdx,PLC_Register_getTimer(timerIdx, VALUE_TYPE_CURR), PLC_Register_getTimer(timerIdx, VALUE_TYPE_CURR)+1);PLC_LOG_addLog(buf);
				//PLC_Register_setTValue(timerIdx, VALUE_TYPE_SET, PLC_Register_getTimer(timerIdx, VALUE_TYPE_SET) - (currTimeUnit - pastTimeUnit));
				//DBG_LOGPRINT("timer is on going : [T%d]%lld\n", timerIdx, PLC_Register_getTimer(timerIdx, VALUE_TYPE_SET) + pastTimeUnit+currTimeUnit );
			}
			else/*Time reached*/
			{
				PLC_Register_setTValue(timerIdx, VALUE_TYPE_RET, TRUE);
				PLC_Register_setTValue(timerIdx, VALUE_TYPE_CURR, 0);
				PLC_Register_setTValue(timerIdx, VALUE_TYPE_REMAINED, 0);
				//DBG_LOGPRINT("set timer : [T%d] %lld-%lld<=%lld\n", timerIdx, currTimeUnit, pastTimeUnit, PLC_Register_getTimer(timerIdx, VALUE_TYPE_SET));
			}
		}
		else/*Already On*/
		{
			//DBG_LOGPRINT("\t[%s] : Keeping T%d value as true .\n", __FUNCTION__, timerIdx);
		}
			//return postProcess_nop(inst, pos, opt);

		//PLC_Register_setTValue(addr1, VALUE_TYPE_CURR, currTime);

	}
	else if(setMode == TIMER_MODE_HIGH ||setMode == TIMER_MODE_NORMAL)
	{
		//DBG_LOGSCAN(buf, "\t[%s] : Turn T%d off.\n", __FUNCTION__, timerIdx);PLC_LOG_addLog(buf);
		PLC_Register_setTValue(timerIdx, VALUE_TYPE_ISON, FALSE);
		PLC_Register_setTValue(timerIdx, VALUE_TYPE_SET, 0);
		PLC_Register_setTValue(timerIdx, VALUE_TYPE_CURR, 0);
		PLC_Register_setTValue(timerIdx, VALUE_TYPE_RET, FALSE);
	}
	else{
		//DBG_LOGSCAN(buf, "\t[%s] : T%d is holding its value.\n", __FUNCTION__, timerIdx);PLC_LOG_addLog(buf);
	}
}



uint32 postProcess_changeCurrentBranchValue(uint8 inst[], uint32* pos, PLC_Operator* opt, uint32 rstVal){

	currBitValue = rstVal;
	PLC_DEVICE_overWirteBlockResult(rstVal);
	finalProcess_progressPosition(inst, pos, opt);
	return TRUE;
}
inline uint32 postProcess_pushNewBranchedValue(uint8 inst[], uint32* pos, PLC_Operator* opt, uint32 rstVal){


	currBitValue = rstVal;
	if(!TaskList_setTaskCMDValue(*pos, rstVal))
	{
		DBG_LOGPRINT("\t[ERROR %s:%s] TaskList_setTaskCMDValue %d at position = %d\n",__FUNCTION__, opt->strName, rstVal, *pos);
		return FALSE;
	}

	//TIME_SET_START;


	PLC_DEVICE_saveBlockResult((uint8)rstVal);

	finalProcess_progressPosition(inst, pos, opt);

	return TRUE;
}

inline uint32 postProcess_out(uint8 inst[], uint32* pos, PLC_Operator* opt, uint32 rstVal){

	//uint8* operand = inProcess_getIndexedOperand(inst, *pos, 0);
	(*pos)+=OPERATOR_LENGTH;
	uint8* operand = inProcess_getNextIndexedOperand(inst, pos);
	if(operand ==NULL)
		return FALSE;
	if(!operand)
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	//DBG_LOGPRINT("\t[OUT] set value : [%s%d] <== %d\n", opt->strName, );
	if(!PLC_DEVICE_setDeviceValue(operand, rstVal, 0))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	currBitValue = rstVal;

	//return finalProcess_progressPosition(inst, pos, opt);
	return PLC_DEVICE_increaseStep(TRUE);
}

inline uint32 postProcess_outBySize(uint8 inst[], uint32* pos, PLC_Operator* opt, uint32 rstVal, uint8 size){

	uint16 optMLCode = opt->nMLCode;
	uint8 opndType = inst[OPERATOR_LENGTH+*pos];
	uint16* valpoint = (uint16*)&inst[OPERATOR_LENGTH+*pos+1];
	uint16 opndVal = *valpoint;
	//uint16 opndVal = inst[OPERATOR_LENGTH+*pos+1]*256+(inst[OPERATOR_LENGTH+*pos+2]);
	if(!isValid(optMLCode, 0, opndType))
	{
		/*DBG_LOGSCAN(buf,
				"\t[%s] error while checking operand& operator [%s%d]%d\n",
				opt->strName,
				opndic[opndType].strType,
				opndVal,
				PLC_DEVICE_getDeviceValue(&inst[OPERATOR_LENGTH+*pos]));
		PLC_LOG_addLog(buf);*/
		return FALSE;
	}

	if(PLC_DEVICE_setDeviceValueBySize(&inst[OPERATOR_LENGTH+*pos], (long long)rstVal, size)==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[%s] error while PLC_DEVICE_setDeviceValueBySize\n", opt->strName);
		return FALSE;
	}
	return finalProcess_progressPosition(inst, pos, opt);
}

inline uint32 finalProcess_progressPosition(uint8 inst[],uint32* pos, PLC_Operator* opt){
	(*pos) += OPERATOR_LENGTH;
	int i;
	for(i=0;i<opt->nOperandPosCount;i++)
	{
		(*pos) += OPND_DICT_ByteSize(&inst[*pos]);
	}
	return PLC_DEVICE_increaseStep(TRUE);
}
inline uint32 inProcess_saveToDev(uint8 inst[], uint32* pos, PLC_Operator* opt, uint32 rstVal, uint8 opndIdx, uint8 byteSize){
	uint16 optMLCode = opt->nMLCode;
	//printf("saveToDev input rst = %08X, byteSize = %d\n", rstVal, byteSize);
	uint8* operand = inProcess_getIndexedOperand(inst, *pos, opndIdx);
	//printf("[%d %d %d] idx = %d, rst = %08X, byteSize = %d\n", operand[0], operand[1], operand[2], opndIdx, rstVal, byteSize);
	/*printf("[%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d]\n",
			inst[0], inst[1], inst[2],
			inst[3], inst[4], inst[5],
			inst[6], inst[7], inst[8],
			inst[9], inst[10], inst[11],
			inst[12], inst[13], inst[14]);*/
	uint8 opndType = inProcess_getIndexedOperand(inst, *pos, opndIdx)[0];
	//int pos = inProcess_getIndexedOperand()(inst, *pos, opndIdx);

	if(!isValid(optMLCode, opndIdx, opndType))
	{
		DBG_LOGPRINT("\t[%s]invalid value :[%d] \n",__FUNCTION__, opndType);
		return PLC_DEVICE_FALSE_32;
	}

	//printf("[%s%02X%02X] %d\n", opndic[operand[0]].strType, operand[1], operand[2], rstVal);
	return PLC_DEVICE_setDeviceValueBySize(operand, (long long)rstVal, 8*byteSize);
}
inline uint8 inProcess_from(uint8 inst[], uint32 pos, PLC_Operator* opt, uint8 unitByteSize)
{
	uint32 firstDevAddr, secondRegAddr, forthCount;
	firstDevAddr = preProcess_load(inst, pos, opt, 0);
	if(firstDevAddr == PLC_DEVICE_FALSE_32)
		return FALSE;
	secondRegAddr = preProcess_load(inst, pos, opt, 1);
	if(secondRegAddr == PLC_DEVICE_FALSE_32)
		return FALSE;
	uint8* thirdDst = preProcess_loadString(inst, pos, opt, 2);
	if(thirdDst==NULL)
		return FALSE;
	forthCount = unitByteSize*preProcess_load(inst, pos, opt, 3);
	if(forthCount == PLC_DEVICE_FALSE_32)
		return FALSE;
	if(!PLC_RealDevice_getFromIntelligenceModule(thirdDst, firstDevAddr, secondRegAddr, forthCount))
		return FALSE;
	return TRUE;
}
inline uint8 inProcess_to(uint8 inst[], uint32 pos, PLC_Operator* opt, uint8 unitByteSize)
{
	uint32 firstDevAddr, secondRegAddr, forthCount;
	firstDevAddr = preProcess_load(inst, pos, opt, 0);
	if(firstDevAddr == PLC_DEVICE_FALSE_32)
		return FALSE;
	secondRegAddr = preProcess_load(inst, pos, opt, 1);
	if(secondRegAddr == PLC_DEVICE_FALSE_32)
		return FALSE;
	uint8* thirdSrc = preProcess_loadString(inst, pos, opt, 2);
	if(thirdSrc==NULL)
		return FALSE;
	forthCount = unitByteSize*preProcess_load(inst, pos, opt, 3);
	if(forthCount == PLC_DEVICE_FALSE_32)
		return FALSE;
	if(!PLC_RealDevice_setToIntelligenceModule(thirdSrc, firstDevAddr, secondRegAddr, forthCount))
		return FALSE;
	return TRUE;

}
uint32 inProcess_load(uint8 inst[], uint32 *pos, PLC_Operator* opt, int pulseType, uint8 isInv)
{
	uint32 currPosition = *pos;
	(*pos) += OPERATOR_LENGTH;
	uint8* operand1 = inProcess_getNextIndexedOperand(inst, pos);
	//uint8* operand1 = inProcess_getIndexedOperand(inst, *pos, 0);
	if(operand1 ==NULL)
			return FALSE;
	uint32 getValue =  PLC_DEVICE_getDeviceValue(operand1);
	//logic
	if(getValue == PLC_DEVICE_FALSE_32 )
		return FALSE;
	if(pulseType == 1)
	{
		getValue = inProcess_detectRaisingEdge(getValue, PLC_DEVICE_getPastDeviceValue(operand1));
	}
	else if(pulseType ==-1)
	{
		getValue = inProcess_detectFallingEdge(getValue, PLC_DEVICE_getPastDeviceValue(operand1));
	}
	if(isInv)
		getValue = !getValue;//inProcess_inv(getValue);

	//save
	currBitValue = getValue;
	if(!TaskList_setTaskCMDValue(currPosition, getValue))
	{
		DBG_LOGPRINT("\t[ERROR %s:%s] TaskList_setTaskCMDValue %d at position = %d\n",__FUNCTION__, opt->strName, getValue, *pos);
		return FALSE;
	}

	//TIME_SET_START;
	//return
	if(!PLC_DEVICE_saveBlockResult((uint8)getValue))
		return FALSE;
	return PLC_DEVICE_increaseStep(TRUE);
	//return finalProcess_progressPosition(inst, pos, opt);
}

uint8 inProcess_wordLogics(uint8 inst[], uint32 *pos, int pulseType, void* logicFunction, uint8 hasDst, uint8 isDWord)
{
	uint8 isRun = FALSE;
	uint32 rst = 0;
	uint32(*logic)(uint32, uint32) = logicFunction;
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = opnd2;
	if(hasDst)
		opnd3 = inProcess_getNextIndexedOperand(inst, pos);

	if(opnd1 ==NULL || opnd2 == NULL || opnd3 ==NULL)
		return FALSE;
	uint16 src1, src2;
	if(pulseType)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}
	if(isRun)
	{
		if(!isDWord)
		{
			src1 = PLC_DEVICE_getDeviceWordValue(opnd1);
			src2 = PLC_DEVICE_getDeviceWordValue(opnd2);
			if(src1 == PLC_DEVICE_FALSE_32 || src2 == PLC_DEVICE_FALSE_32 )
				return FALSE;
			rst = logic(src1, src2);
			DBG_LOGPRINT("%08X logic %08X = %08X\n", src1, src2, rst);
			PLC_DEVICE_setDeviceValue(opnd3, rst, 0);
		}
		else
		{
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&src1, opnd1, 0))
				return FALSE;
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&src2, opnd2, 0))
				return FALSE;
			rst = logic(src1, src2);
			DBG_LOGPRINT("%08X logic %08X = %08X\n", src1, src2, rst);
			PLC_DEVICE_setDeviceDoubleWordValue(opnd3, rst);
		}
	}
	return PLC_DEVICE_increaseStep(TRUE);
}

uint8 inProcess_blockLogics(uint8 inst[], uint32 *pos, int pulseType, void* logicFunction)
{
	uint8 isRun = FALSE;
	uint32 rst = 0;
	uint32(*logic)(uint32, uint32) = logicFunction;
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd4 = inProcess_getNextIndexedOperand(inst, pos);
	if(opnd1 ==NULL || opnd2 ==NULL || opnd3 ==NULL || opnd4 ==NULL )
		return FALSE;
	uint16 cnt, dst, src1, src2;
	if(pulseType)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}
	if(isRun)
	{
		int idx;
		cnt = PLC_DEVICE_getDeviceWordValue(opnd4);
		if(cnt == PLC_DEVICE_FALSE_32)
			return FALSE;
		for(idx = 0; idx < cnt; idx++)
		{
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&src1, opnd1, idx))
				return FALSE;
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&src2, opnd2, idx))
				return FALSE;
			rst = logic(src1, src2);
			DBG_LOGPRINT("[%d] %08X logic %08X = %08X\n", idx, src1, src2, rst);
			PLC_DEVICE_setDeviceValue(opnd3, rst, idx);
		}
	}
	return PLC_DEVICE_increaseStep(TRUE);

}

uint8 inProcess_rotate(uint8 inst[], uint32 *pos, int pulseType, uint8 isRight, uint8 hasCarry, uint8 isDWord)
{
	uint8 isRun = FALSE;
	uint32 rst = 0;
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	if(opnd1 ==NULL || opnd2 == NULL)
		return FALSE;
	uint32 step, src;
	long long value = 0;
	if(pulseType)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}
	if(isRun)
	{
		if(!isDWord)
		{
			step = PLC_DEVICE_getDeviceWordValue(opnd2);
			src = PLC_DEVICE_getDeviceWordValue(opnd1);
			if(step == PLC_DEVICE_FALSE_32 || src == PLC_DEVICE_FALSE_32 )
				return FALSE;
			if(hasCarry)
				value = src + src * 0x00010000;

			if(isRight)
			{
				value = value>>step;
			}else
			{
				value = value<<step;
			}

			rst = value;
			PLC_DEVICE_setDeviceValue(opnd1, rst, 0);
		}
		else
		{
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&step, opnd2, 0))
				return FALSE;
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&src, opnd1, 0))
				return FALSE;

			value = src * 0x0000000100000000 + src ;

			if(isRight)
			{
				value = value>>step;
			}
			else
			{
				value = value<<step;
			}
			rst = value;
			PLC_DEVICE_setDeviceDoubleWordValue(opnd1, rst);
		}

	}
	return PLC_DEVICE_increaseStep(TRUE);
}

uint8 inProcess_call(uint8 inst[], uint32 *pos, uint8 isPulse)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd4 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd5 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd6 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun = FALSE;
	if(opnd1 ==NULL || opnd2 ==NULL || opnd3 ==NULL || opnd4 ==NULL )
			return FALSE;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		uint8* prevOperands[4] = {functionOperands[0], functionOperands[1], functionOperands[2], functionOperands[3]};
		uint16 label = PLC_DEVICE_getDeviceValue(opnd1);
		uint8 taskIdx;
		uint32 taskPos;
		//memcpy(prevOperands, functionOperands, 4*sizeof(void*));
		inProcess_substitudeOperand(opnd2, opnd3, opnd4, opnd5, opnd6);
		if(!PLC_PointTable_getPointByLabel(&taskIdx, &taskPos, label))
			return FALSE;
		//DBG_LOGPRINT("[CALL] goto task %d pos %d\n", taskIdx, taskPos);
		if(PLC_TaskExecutor_execOneScanTime(taskIdx, taskPos, PLC_TaskExecutor_getCurrPriority())!=ML_CODE_RET)
			return FALSE;
		functionOperands[0] = prevOperands[0];
		functionOperands[1] = prevOperands[1];
		functionOperands[2] = prevOperands[2];
		functionOperands[3] = prevOperands[3];
		functionOperands[4] = prevOperands[4];
	}
	return PLC_DEVICE_increaseStep(TRUE);
}

void inProcess_substitudeOperand(uint8* opnd2,uint8* opnd3, uint8* opnd4, uint8* opnd5, uint8* opnd6 )
{
	functionOperands[0] = opnd2;
	functionOperands[1] = opnd3;
	functionOperands[2] = opnd4;
	functionOperands[3] = opnd5;
	functionOperands[4] = opnd6;
}
uint8* inProcess_getsubstitutedOperand(uint16 idx)
{
	/*
	uint8* operand = functionOperands[idx];
	uint16* addr = (uint16*)&operand[1];
	DBG_LOGPRINT("<--[%s%d]\n", opndic[operand[0]].strType, *addr);
	*/
	return functionOperands[idx];
}
void initBlockStack()
{
	dev.forStack.count = 0;
	memset( dev.forStack.blocks, 0, sizeof(BlockFor)*BLOCK_FOR_SIZE );
}
uint8 inProcess_visitFor(uint8 inst[], uint32 *pos)
{
	uint32 currPos = *pos;
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint32 cnt = PLC_DEVICE_getDeviceWordValue(opnd1);
	if(cnt == PLC_FALSE_32)
		return FALSE;
	if(cnt<=0)
		cnt = 1;
	if(dev.forStack.count >= BLOCK_FOR_SIZE)
	{
		DBG_LOGPRINT("[ERROR] Overflowed for stack!\n");
		return FALSE;
	}

	if( dev.forStack.count == 0 ||
			dev.forStack.blocks[dev.forStack.count-1].pos != currPos )
	{
		dev.forStack.blocks[dev.forStack.count].countFor = cnt;
		dev.forStack.blocks[dev.forStack.count].pos = currPos;
		dev.forStack.count++;
		//DBG_LOGPRINT("<--[for stack++]\n");
	}

	return PLC_DEVICE_increaseStep(TRUE);
}
uint8 inProcess_visitNext(uint8 inst[], uint32 *pos)
{
	(*pos)+= OPERATOR_LENGTH;
	if(dev.forStack.count == 0)
	{
		DBG_LOGPRINT("[ERROR] Underflowed for stack!\n");
		return FALSE;
	}
	dev.forStack.blocks[dev.forStack.count-1].countFor--;
	if(dev.forStack.blocks[dev.forStack.count-1].countFor>0)
	{
		//;
		(*pos) = dev.forStack.blocks[dev.forStack.count-1].pos;
		//DBG_LOGPRINT("[goto for = %d)]\n", forStack.blocks[forStack.count-1].countFor);
	}
	else
	{
		//DBG_LOGPRINT("[out next]\n");
		dev.forStack.count--;
	}

	return PLC_DEVICE_increaseStep(TRUE);
}
uint8 inProcess_visitBreak(uint8 inst[], uint32 *pos, uint8 isPulse)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	if(dev.forStack.count==0)
	{
		return FALSE;
	}
	uint8 isRun = FALSE;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}
	//DBG_LOGPRINT("BREAK passing! : %d\n", forStack.blocks[forStack.count-1].countFor);
	if(isRun)
	{
		//DBG_LOGPRINT("BREAK launched!\n");
		uint32 remainedCount = dev.forStack.blocks[dev.forStack.count-1].countFor;
		//DBG_LOGPRINT("BREAK launched! : [%s%d]<--%d\n", opndic[opnd1[0]].strType,*(uint16*)&opnd1[1],remainedCount);
		if(!PLC_DEVICE_setDeviceValue(opnd1, remainedCount, 0))
			return FALSE;
		dev.forStack.count--;
		while(TRUE)
		{
			uint16 currCMD = inProcess_goNextCMD(inst,pos);
			//DBG_LOGPRINT("CMD : %d\n", currCMD);
			if(currCMD >= OPERATOR_LIST_SIZE)
			{
				DBG_LOGPRINT("CMD : invalid - %d\n", currCMD);
				return FALSE;
			}
			if(currCMD == ML_CODE_NEXT)
			{
				//DBG_LOGPRINT("Break success! forStack.count = %d, remained : %d\n",forStack.count, remainedCount);
				break;
			}
		}
	}

	return PLC_DEVICE_increaseStep(TRUE);
}

uint16 inProcess_goNextCMD(uint8 inst[], uint32 *pos)
{
	//DBG_LOGPRINT("%s :: %d\n", __func__, __LINE__);
	uint16* cmd = (uint16*)&inst[*pos];
	//DBG_LOGPRINT("%s :: %d\n", __func__, __LINE__);
	PLC_Operator* opt = PLC_OPERATOR_DICTIONARY_findOperator(*cmd);
	if(opt==NULL)
		return 0xFFFF;
	//DBG_LOGPRINT("%s :: %d\n", __func__, __LINE__);
	uint8 cnt = opt->nOperandPosCount;
	int idx;
	(*pos)+=OPERATOR_LENGTH;
	for( idx = 0; idx < cnt ; idx++ )
	{
		inProcess_getNextIndexedOperand(inst, pos);
	}
	//DBG_LOGPRINT("%s :: %d\n", __func__, __LINE__);
	return *cmd;
}

uint16 inProcess_searchAndCount(uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDWord)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd4 = inProcess_getNextIndexedOperand(inst, pos);

	uint8 isRun = FALSE;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);

	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		uint16 cnt = PLC_DEVICE_getDeviceWordValue(opnd4);
		int idx;
		uint16 countEQ = 0;
		uint16 firstMatchedIdx= 0;
		if(!isDWord)
		{
			uint32 value = PLC_DEVICE_getDeviceWordValue(opnd1);
			if(value == PLC_FALSE_32)
			{
				DBG_LOGPRINT("[ERROR] failed to get value!\n");
				return FALSE;
			}
			for( idx = 0 ; idx < cnt ; idx++ )
			{
				uint32 compare;
				if(!PLC_DEVICE_getOffsetDeviceWordValue(& compare, opnd2, idx))
				{
					DBG_LOGPRINT("[SRCH] ERROR : opnd2 [%s%d+%d]\n", opndic[opnd2[0]].strType,
							*(uint16*)&opnd2[1], idx);
					return FALSE;
				}
				if(value == compare)
				{
					//DBG_LOGPRINT("[SRCH] MATCHED: %d=%d!\n", value, compare);
					if(countEQ==0)
						firstMatchedIdx = idx;
					countEQ++;

				}
				else
				{
					/*DBG_LOGPRINT("[SRCH] UNMATCHED: [%s%d]%d!=%d[%s%d]!\n",
							opndic[opnd1[0]].strType, *(uint16*)&opnd1[1],
							value, compare,
							opndic[opnd2[0]].strType, idx+*(uint16*)&opnd2[1]
							);*/
				}
			}
			//DBG_LOGPRINT("[SRCH] place : [%s%d]%d, cnt : %d!\n", opndic[opnd3[0]].strType, *(uint16*)&opnd3[1],firstMatchedIdx, countEQ);
			if(!PLC_DEVICE_setDeviceValue(opnd3, firstMatchedIdx, 0))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
			if(!PLC_DEVICE_setDeviceValue(opnd3, countEQ, 1))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
		}
		else
		{
			uint32 value;
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&value, opnd1, 0))
			{
				DBG_LOGPRINT("[SRCH] ERROR : opnd1\n");
				return FALSE;
			}
			for( idx = 0 ; idx < cnt ; idx++ )
			{
				uint32 compare;
				if(PLC_DEVICE_getOffsetDeviceDoubleWordValue(&compare, opnd2, idx*2))
				{
					DBG_LOGPRINT("[SRCH] ERROR : opnd2\n");
					return FALSE;
				}
				if(value == compare)
				{
					//DBG_LOGPRINT("[SRCH] MATCHED: %d=%d!\n", value, compare);
					if(countEQ==0)
						firstMatchedIdx = idx;
					countEQ++;
				}
				else
				{
					/*DBG_LOGPRINT("[SRCH] UNMATCHED: [%s%d]%d!=%d[%s%d]!\n",
							opndic[opnd1[0]].strType, *(uint16*)&opnd1[1],
							value, compare,
							opndic[opnd2[0]].strType, idx+*(uint16*)&opnd2[1]
							);*/
				}
			}
			//DBG_LOGPRINT("[SRCH] place : %d, cnt : %d!\n", firstMatchedIdx, countEQ);
			if(!PLC_DEVICE_setDeviceValue(opnd3, firstMatchedIdx, 0))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
			if(!PLC_DEVICE_setDeviceValue(opnd3, countEQ+1, 1))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
		}
	}
	return PLC_DEVICE_increaseStep(TRUE);
}

uint16 inProcess_searchMaxMinCount(uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDWord, uint8 isMax)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	//uint8* opnd4 = inProcess_getNextIndexedOperand(inst, pos);

	uint8 isRun = FALSE;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		uint16 cnt = PLC_DEVICE_getDeviceWordValue(opnd3);
		int idx;
		uint16 countOfValues = 0;
		uint16 firstMatchedIdx= 0;


		if(!isDWord)
		{
			//uint32 value = PLC_DEVICE_getOffsetDeviceWordValue(opnd1, idx);
			short currValue;
			short compare= 0;

			if(isMax)
				currValue = 0;
			else
				currValue = 0x7FFF;

			for( idx = 0 ; idx < cnt ; idx++ )
			{

				if(!PLC_DEVICE_getOffsetDeviceWordValue((uint16*)&compare, opnd1, idx))
					return FALSE;
				//DBG_LOGPRINT("[MAX/MIN] comp %d, curr %d!\n", compare, currValue);
				if(isMax)
				{
					if(currValue<compare)
					{
						currValue = compare;
						countOfValues = 1;
						firstMatchedIdx = idx;
					}
					else if(currValue==compare)
					{
						countOfValues++;
					}
				}
				else
				{
					if(currValue>compare)
					{
						currValue = compare;
						countOfValues = 1;
						firstMatchedIdx = idx;
					}
					else if(currValue==compare)
					{
						countOfValues++;
					}
				}
			}
			//DBG_LOGPRINT("[MAX/MIN] value : %d, place : %d, cnt : %d!\n", currValue, firstMatchedIdx, countOfValues);
			if(!PLC_DEVICE_setDeviceValue(opnd2, currValue, 0))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
			if(!PLC_DEVICE_setDeviceValue(opnd2, firstMatchedIdx, 1))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
			if(!PLC_DEVICE_setDeviceValue(opnd2, countOfValues, 2))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
		}
		else
		{
			int currValue;
			int compare= 0;

			if(isMax)
				currValue = 0;
			else
				currValue = 0xF0000000;

			//uint32 value = PLC_DEVICE_getOffsetDeviceWordValue(opnd1, idx);
			for( idx = 0 ; idx < cnt ; idx++ )
			{
				if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue((uint32*)&compare, opnd1, idx*2))
					return FALSE;
				//DBG_LOGPRINT("[MAX/MIN] comp %d, curr %d!\n", compare, currValue);
				if(isMax)
				{
					if(currValue<compare)
					{
						currValue = compare;
						countOfValues = 1;
						firstMatchedIdx = idx;
					}
					else if(currValue==compare)
					{
						countOfValues++;
					}
				}
				else
				{
					if(currValue>compare)
					{
						currValue = compare;
						countOfValues = 1;
						firstMatchedIdx = idx;
					}
					else if(currValue==compare)
					{
						countOfValues++;
					}
				}
			}
			//DBG_LOGPRINT("[D-MAX/MIN] value : %d, place : %d, cnt : %d!\n", currValue, firstMatchedIdx, countOfValues);
			if(!PLC_DEVICE_setDeviceDoubleWordValue(opnd2, currValue))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
			if(!PLC_DEVICE_setDeviceValue(opnd2, firstMatchedIdx, 2))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
			if(!PLC_DEVICE_setDeviceValue(opnd2, countOfValues, 3))
			{
				DBG_LOGPRINT("[ERROR] failed to set value!\n");
				return FALSE;
			}
		}
	}
	return PLC_DEVICE_increaseStep(TRUE);
}


uint16 inProcess_sumBit(uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDWord)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);

	uint8 isRun = FALSE;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		int idx;
		uint16 cnt = 0;
		if(!isDWord)
		{
			uint32 val = PLC_DEVICE_getDeviceWordValue(opnd1);
			if(val == PLC_FALSE_32)
			{
				DBG_LOGPRINT("[ERROR] failed to get value!\n");
				return FALSE;
			}
			for(idx = 0; idx< 16; idx++)
			{
				cnt += (val>>idx)&0x01;
			}
		}
		else
		{
			uint32 val;
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&val, opnd1, 0))
				return FALSE;
			for(idx = 0; idx < 32; idx++)
			{
				cnt += (val>>idx)&0x01;
			}
		}
		if(!PLC_DEVICE_setDeviceValue(opnd2, cnt, 0))
		{
			DBG_LOGPRINT("[ERROR] failed to set value!\n");
			return FALSE;
		}
		//DBG_LOGPRINT("cnt = %d!\n", cnt);
	}
	return PLC_DEVICE_increaseStep(TRUE);
}

uint16 inProcess_sort(uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDWord)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd4 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd5 = inProcess_getNextIndexedOperand(inst, pos);

	uint8 isRun = FALSE;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{

		uint16 cnt;
		uint16 isIncrease;
		if(!PLC_DEVICE_getOffsetDeviceWordValue(&cnt, opnd2, 0))
			return FALSE;
		if(!PLC_DEVICE_getOffsetDeviceWordValue(&isIncrease, opnd3, 0))
			return FALSE;
		if(!isDWord)
		{
			if(!PLC_DEVICE_isDeviceAddrRange(opnd1, cnt))
				return FALSE;

			uint16* listHead = PLC_DEVICE_getDeviceString(opnd1);

			if(!sort(listHead, cnt, 2, isIncrease))
				return FALSE;
			/*int i;
			printf("\n");
			for(i = 0; i< cnt; i++)
				printf("[%s%d]%d ", opndic[OPERAND_ML_CODE_D].strType, i, PLC_Register_getWord(OPERAND_ML_CODE_D, i));
			printf("\n");*/
		}
		else
		{
			if(!PLC_DEVICE_isDeviceAddrRange(opnd1, cnt*2))
				return FALSE;

			uint32* listHead = (uint32*)PLC_DEVICE_getDeviceString(opnd1);
			if(!sort(listHead, cnt, 4, isIncrease))
				return FALSE;
			/*int i;
			printf("\n");
			for(i = 0; i< cnt; i++)
			{
				printf("[%s%d]%d ", opndic[OPERAND_ML_CODE_D].strType, i*2, PLC_Register_getDWord(OPERAND_ML_CODE_D, i*2));
			}
			printf("\n");*/
		}
	}
	return PLC_DEVICE_increaseStep(TRUE);
}
unsigned char sort(void* arr, int dataSize, int byteSize, uint8 isIncrease)
{
	if(dataSize==1)
		return 1;
	int i;
	int lengthA = dataSize/2;
	int lengthB = dataSize - dataSize/2;
	//printf("lengthA %d, lengthB %d,  byteSize %d\n", lengthA, lengthB, byteSize);
	if(byteSize == 2)
	{

		short* arrShort = (short*)arr;
		short* arrA = arrShort;
		short* arrB = &arrShort[lengthA];
		if(!sort(arrA, lengthA, byteSize, isIncrease))
			return FALSE;
		if(!sort(arrB, lengthB, byteSize, isIncrease))
			return FALSE;
		if(!merge(arrA, arrB, lengthA, lengthB, byteSize, isIncrease))
			return FALSE;
		return TRUE;
	}
	else if(byteSize == 4)
	{
		int* arrShort = (int*)arr;
		int* arrA = arrShort;
		int* arrB = &arrShort[lengthA];

		if(!sort(arrA, lengthA, byteSize, isIncrease))
			return FALSE;
		if(!sort(arrB, lengthB, byteSize, isIncrease))
			return FALSE;

		if(!merge(arrA, arrB, lengthA, lengthB, byteSize, isIncrease))
			return 0;
		return TRUE;
	}

	return FALSE;
}

unsigned char merge(void* arrA, void* arrB, int lengthA, int lengthB, int byteSize, uint8 isDecrease)
{
	//printf("sorting input lengthA : %d, lengthB : %d\n", lengthA, lengthB);

	if(byteSize == 2)
	{
		short* arrShortA = (short*)arrA;
		short* arrShortB = (short*)arrB;
		int idxA=0, idxB=0, i=0;
		short* arrSorted = (short*)malloc(sizeof(short)*(lengthA+lengthB));
		//DBG_LOGPRINT("increase case::%d\n", isIncrease);
			//printf("A %d B %d i %d\n", idxA, idxB, i);
		if((isDecrease&0x01)==0)
		{
			for(i = 0 ; i < lengthA+lengthB ; i++ )
			{

				if( (idxA < lengthA) && (arrShortA[idxA]<arrShortB[idxB] || idxB == lengthB))
				{
					arrSorted[i] = arrShortA[idxA];
					idxA++;
				}
				else if( (idxB < lengthB) && (arrShortA[idxA]>=arrShortB[idxB] || idxA == lengthA))
				{
					arrSorted[i] = arrShortB[idxB];
					idxB++;
				}
			}
		}
		else //if((isIncrease&0x01)!=0)
		{
			for(i = 0 ; i < lengthA+lengthB ; i++ )
			{
				//DBG_LOGPRINT("decrease case::");
				if( (idxA < lengthA) && (arrShortA[idxA]>arrShortB[idxB] || idxB == lengthB))
				{
					arrSorted[i] = arrShortA[idxA];
					idxA++;
				}
				else if( (idxB < lengthB) && (arrShortA[idxA]<=arrShortB[idxB] || idxA == lengthA))
				{
					arrSorted[i] = arrShortB[idxB];
					idxB++;
				}
			}
		}
		memcpy(arrA, arrSorted, sizeof(short)*lengthA);
		memcpy(arrB, &arrSorted[lengthA], sizeof(short)*lengthB);
		free(arrSorted);
		return TRUE;
	}
	else if(byteSize == 4)
	{
		int* arrShortA = (int*)arrA;
		int* arrShortB = (int*)arrB;
		int idxA=0, idxB=0, i=0;
		int* arrSorted = (int*)malloc(sizeof(int)*(lengthA+lengthB));
		for(i = 0 ; i < lengthA+lengthB ; i++ )
		{
			if(isDecrease)
			{
				if( (idxA < lengthA) && (arrShortA[idxA]<arrShortB[idxB] || idxB == lengthB))
				{
					arrSorted[i] = arrShortA[idxA];
					idxA++;
				}
				else if( (idxB < lengthB) && (arrShortA[idxA]>=arrShortB[idxB] || idxA == lengthA))
				{
					arrSorted[i] = arrShortB[idxB];
					idxB++;
				}
			}
			else
			{
				if( (idxA < lengthA) && (arrShortA[idxA]>arrShortB[idxB] || idxB == lengthB))
				{
					arrSorted[i] = arrShortA[idxA];
					idxA++;
				}
				else if( (idxB < lengthB) && (arrShortA[idxA]<=arrShortB[idxB] || idxA == lengthA))
				{
					arrSorted[i] = arrShortB[idxB];
					idxB++;
				}
			}
		}
		memcpy(arrA, arrSorted, sizeof(int)*lengthA);
		memcpy(arrB, &arrSorted[lengthA], sizeof(int)*lengthB);
		free(arrSorted);
		return TRUE;
	}
	return FALSE;

}

uint8 inProcess_BINToASCII(uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDecimal, uint8 isDWord, uint8 isBCDSrc)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	char* tar;
	uint8 isRun = FALSE;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}
	tar = (char*)PLC_DEVICE_getDeviceString(opnd2);

	if(tar==NULL)
		return PLC_DEVICE_increaseStep(FALSE);
	if(isRun)
	{
		if(!isDWord)
		{
			short value;

			if(!PLC_DEVICE_getOffsetDeviceWordValue((uint16*)&value, opnd1, 0))
			{
				DBG_LOGPRINT("[Error] invalid operand1!\n");
				return FALSE;
			}


			if(isBCDSrc)
			{
				int dst;
				if(!inprocess_convertBCDToBin(&dst, &value, 2))
				{
					DBG_LOGPRINT("[Error] conversion failed!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
				value = dst;
			}

			if(isDecimal)
			{
				if(!PLC_DEVICE_isDeviceAddrRange(opnd2, 4))
				{
					DBG_LOGPRINT("[Error] device range of opnd2!\n");
					return FALSE;
				}

				inProcess_intToArr(tar, value, 5);
				//DBG_LOGPRINT("tar %s <== val %d\n", tar, value);
			}
			else
			{
				if(!PLC_DEVICE_isDeviceAddrRange(opnd2, 3))
				{
					DBG_LOGPRINT("[Error] device range of opnd2!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}

				inProcess_intToArrHex(tar, value, 3);
				//DBG_LOGPRINT("tar %s <== val %X\n", tar, value);
			}
		}
		else
		{
			int value;

			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue((uint32*)&value, opnd1, 0))
				return PLC_DEVICE_increaseStep(FALSE);

			if(isBCDSrc)
			{
				int dst;
				if(!inprocess_convertBCDToBin(&dst, &value, 2))
				{
					DBG_LOGPRINT("[Error] conversion failed!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
				value = dst;
			}

			if(isDecimal)
			{
				if(!PLC_DEVICE_isDeviceAddrRange(opnd2, 6))
				{
					DBG_LOGPRINT("[Error] device range of opnd2!\n");
					return FALSE;
				}

				inProcess_intToArr(tar, value, 10);
				//DBG_LOGPRINT("tar %s <== val %d\n", tar, value);
			}
			else
			{
				if(!PLC_DEVICE_isDeviceAddrRange(opnd2, 5))
				{
					DBG_LOGPRINT("[Error] device range of opnd2!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}

				inProcess_intToArrHex(tar, value, 7);
				//DBG_LOGPRINT("tar %s <== val %d\n", tar, value);
			}
		}
	}
	return PLC_DEVICE_increaseStep(TRUE);
}
//todo:: complete method!
uint8 inProcess_ASCIIToBIN(uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDecimal, uint8 isDWord, uint8 isBCDdst)
{

	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);


	uint8 isRun = FALSE;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		char* src;
		int value= 0;
		src = (uint16*)PLC_DEVICE_getDeviceString(opnd1);

		if(src==NULL)
			return PLC_DEVICE_increaseStep(FALSE);

		if(!isDWord)
		{

			if(isDecimal)
			{
				if(!PLC_DEVICE_isDeviceAddrRange(opnd2, 0))
				{
					DBG_LOGPRINT("operand2 length error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
				if(!inProcess_arrToInt(&value, src, 6))
				{
					DBG_LOGPRINT("parsing error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
			}
			else
			{
				if(!PLC_DEVICE_isDeviceAddrRange(opnd2, 0))
				{
					DBG_LOGPRINT("operand2 length error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
				if(!inProcess_hexArrToInt(&value, src, 4))
				{
					DBG_LOGPRINT("parsing error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
			}

			if(isBCDdst)
			{
				short bcdVal = 0;
				if(!inprocess_convertBinToBCD(&bcdVal, &value, 2))
				{
					DBG_LOGPRINT("parsing error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
				value = bcdVal;
			}
			if(!PLC_DEVICE_setDeviceValue(opnd2, value, 0))
			{
				DBG_LOGPRINT("set error!\n");
				return PLC_DEVICE_increaseStep(FALSE);
			}

		}
		else
		{
			if(isDecimal)
			{
				if(!PLC_DEVICE_isDeviceAddrRange(opnd2, 1))
				{
					DBG_LOGPRINT("operand2 length error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
				if(!inProcess_arrToInt(&value, src, 11))
				{
					DBG_LOGPRINT("parsing error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
			}
			else
			{
				if(!PLC_DEVICE_isDeviceAddrRange(opnd2, 1))
				{
					DBG_LOGPRINT("operand2 length error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
				if(!inProcess_hexArrToInt(&value, src, 8))
				{
					DBG_LOGPRINT("parsing error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
			}
			if(isBCDdst)
			{
				int bcdVal = 0;
				if(!inprocess_convertBinToBCD(&bcdVal, &value, 4))
				{
					DBG_LOGPRINT("parsing error!\n");
					return PLC_DEVICE_increaseStep(FALSE);
				}
				value = bcdVal;
			}
			if(!PLC_DEVICE_setDeviceDoubleWordValue(opnd2, value))
			{
				DBG_LOGPRINT("set error!\n");
				return PLC_DEVICE_increaseStep(FALSE);
			}

		}
		//DBG_LOGPRINT("set value : %X<==%s\n", value, src);
	}
	return PLC_DEVICE_increaseStep(TRUE);

}

unsigned char inProcess_intToArr( char* dst, int src, int onePos)
{
	int j;
	if(src<0)
	{
		dst[0] = '-';
		src = -src;
	}
	else
		dst[0] = ' ';


	for(j = onePos; j>0; j--)
	{
		if(src==0)
		{
			dst[j] = ' ';
		}
		else
		{
			dst[j] = src%10+'0';
			src/=10;
		}
	}
	if(onePos%2 ==1)
	{
		dst[onePos+2] = 0;
	}
	dst[onePos+1] = 0;

	return 1;
}


unsigned char inProcess_intToArrHex( char* dst, uint16 src, int onePos)
{
	int j;
	for(j = onePos; j>=0; j--)
	{
		if(src==0)
		{
			dst[j] = ' ';
		}
		else
		{

			int curr = src %16;
			//DBG_LOGPRINT("curr : %d\n");
			if(curr<10)
			{
				dst[j] = src%16+'0';
			}
			else
			{
				dst[j] = src%16 -10 + 'A';
			}
			src/=16;
		}
	}
	if(onePos%2 ==1)
	{
		dst[onePos+2] = 0;
	}
	dst[onePos+1] = 0;

	return 1;
}


unsigned char inProcess_arrToInt( int* dst, char* src, int strMaxlength)
{
	*dst = 0;
	char isUnderZero;
	int i=0;
	if(src[i]=='-')
	{
		isUnderZero = 1;
	}
	else if(src[i]==' ')
	{
		isUnderZero = 0;
	}
	else
	{
		printf("sign error!\n");
		return 0;
	}
	i++;
	while(i < strMaxlength && src[i]!=0 )
	{
		(*dst)*=10;
		if(src[i]<='9' && src[i]>='0')
		{
			*dst+=src[i]-'0';
		}
		else if(src[i]==0 || src[i]=='\n')
		{
			break;
		}
		else if(src[i]==' ')
		{

		}
		else
		{
			printf("value error i = %d[%c]!\n", i, src[i]);
			return 0;
		}
		i++;
	}
	if(isUnderZero)
		*dst = -(*dst);
	return 1;
}
unsigned char inProcess_hexArrToInt( int* dst, char* src, int strMaxlength)
{
	*dst = 0;
	int i=0;
	while(i < strMaxlength && src[i]!=0 )
	{
		(*dst)*=16;
		if(src[i]<='9' && src[i]>='0')
		{
			*dst+=src[i]-'0';
		}
		else if(src[i]<='F' && src[i]>='A')
		{
			*dst+=10 + src[i]-'A';
		}
		else if(src[i]==0 || src[i]=='\n')
		{
			break;
		}
		else if(src[i]==' ')
		{

		}
		else
		{
			printf("value error i = %d[%c]!\n", i, src[i]);
			return 0;
		}
		i++;
	}
	return 1;

}
unsigned char inProcess_intIntToStr( uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDWord)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		char* charPos;
		char strVal1[50], strVal2[50];
		int length=0;
		float fvalue = 0;
		int integer = 0, point = 0;
		int modular=1, divider=1;
		int i;
		if(!PLC_DEVICE_getOffsetDeviceWordValue((uint16*)&integer, opnd1, 0))
		{
			DBG_LOGPRINT("ERROR while get operand1.1\n");
			return PLC_DEVICE_increaseStep(FALSE);
		}
		if(!PLC_DEVICE_getOffsetDeviceWordValue((uint16*)&point, opnd1, 1))
		{
			DBG_LOGPRINT("ERROR while get operand1.1\n");
			return PLC_DEVICE_increaseStep(FALSE);
		}
		//sprintf(strVal1, "%%%d.%df", integer, point);
		//printf("%%%d.%df", integer, point);

		if(!isDWord)
		{
			short value2=0;
			if(!PLC_DEVICE_getOffsetDeviceWordValue((uint16*)&value2, opnd2, 0))
			{
				DBG_LOGPRINT("ERROR while get operand2\n");
				return PLC_DEVICE_increaseStep(FALSE);
			}

			if(integer > 8 || integer<2)
			{
				DBG_LOGPRINT("ERROR while get integer = %d\n", integer);
				return PLC_DEVICE_increaseStep(FALSE);
			}
			if(point >5 || point <0)
			{
				DBG_LOGPRINT("ERROR while get point = %d\n", point);
				return PLC_DEVICE_increaseStep(FALSE);
			}
			fvalue +=value2;
		}
		else
		{
			int value2=0;
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue((uint32*)&value2, opnd2, 0))
			{
				DBG_LOGPRINT("ERROR while get operand2\n");
				return PLC_DEVICE_increaseStep(FALSE);
			}

			if(integer > 12 || integer<2)
			{
				DBG_LOGPRINT("ERROR while get integer = %d\n", integer);
				return PLC_DEVICE_increaseStep(FALSE);
			}
			if(point >10 || point <0)
			{
				DBG_LOGPRINT("ERROR while get point = %d\n", point);
				return PLC_DEVICE_increaseStep(FALSE);
			}
			fvalue +=value2;
		}

		for(i=0; i<integer ; i++)
		{
			modular*=10;
		}
		for(i=0; i<point ; i++)
		{
			divider*=10;
		}


		fvalue -= ((int)fvalue / modular) * modular;
		fvalue /= divider;
		//DBG_LOGPRINT("BTOSTR %d-%d => %f\n", integer, point, fvalue);
		sprintf(strVal2, "%%%d.%df", integer, point);

		sprintf(strVal1, strVal2, fvalue);

		length = strlen(strVal1);

		//DBG_LOGPRINT("strVal1 = %s(len = %d), strVal2 = %s\n", strVal1, length, strVal2);
		if(!PLC_DEVICE_isDeviceAddrRange(opnd3, length+1))
		{
			DBG_LOGPRINT("ERROR while set operand3 range\n");
			return PLC_DEVICE_increaseStep(TRUE);
		}

		charPos = (char*)PLC_DEVICE_getDeviceString(opnd3);
		strcpy(charPos, strVal1);
		//DBG_LOGPRINT("BTOSTR %d-%d => %f\n", integer, point, fvalue);
	}
	return PLC_DEVICE_increaseStep(TRUE);

}
unsigned char inProcess_strToIntInt( uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDWord)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		int intValue = 0;
		uint8 isBelowZero = FALSE;
		uint8 isSmallerThenOne = FALSE;
		int strLength, floatLength=0;

		char* charPos = (char*)PLC_DEVICE_getDeviceString(opnd1);
		if(charPos==NULL)
			return PLC_DEVICE_increaseStep(FALSE);
		//DBG_LOGPRINT("STRTOB [%s]\n", charPos);
		strLength = strlen(charPos);

		if(*charPos == '-')
			isBelowZero = TRUE;
		charPos++;
		while(*charPos==' ')
			charPos++;
		while(*charPos>='0' && *charPos<='9')
		{
			intValue *=10;
			intValue += *charPos-'0';
			charPos++;
			if(isSmallerThenOne)
				floatLength++;
			if(*charPos =='.' && !isSmallerThenOne)
			{
				charPos++;
				isSmallerThenOne=TRUE;
			}
		}

		if(isSmallerThenOne)
			strLength--;
		if(isBelowZero)
			intValue = -intValue;
		//DBG_LOGPRINT("BTOSTR strLength %d floatLength %d => intValue %d\n", strLength, floatLength, intValue);
		if(!PLC_DEVICE_setDeviceValue(opnd2, strLength, 0))
		{
			DBG_LOGPRINT("setValue 2.1 failed!\n");
			return PLC_DEVICE_increaseStep(FALSE);
		}
		if(!PLC_DEVICE_setDeviceValue(opnd2, floatLength, 1))
		{
			DBG_LOGPRINT("setValue 2.1 failed!\n");
			return PLC_DEVICE_increaseStep(FALSE);
		}
		if(!PLC_DEVICE_setDeviceValue(opnd3, intValue, 0))
		{
			DBG_LOGPRINT("setValue 3 failed!\n");
			return PLC_DEVICE_increaseStep(FALSE);
		}
	}

	return PLC_DEVICE_increaseStep(TRUE);
}

unsigned char inProcess_intToASCIIArr( uint8 inst[], uint32 *pos, uint8 isPulse)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		uint16 cnt = 0;
		int i;
		if(!PLC_DEVICE_getOffsetDeviceWordValue(&cnt, opnd3, 0))
			return PLC_DEVICE_increaseStep(FALSE);
		if(!PLC_DEVICE_isDeviceAddrRange(opnd1, cnt))
			return PLC_DEVICE_increaseStep(FALSE);
		if(!PLC_DEVICE_isDeviceAddrRange(opnd2, cnt*2))
			return PLC_DEVICE_increaseStep(FALSE);
		char* tar =  (char*)PLC_DEVICE_getDeviceString(opnd2);

		//DBG_LOGPRINT("[cnt %d] From src [%s%d]0x", cnt, opndic[opnd1[0]].strType, *(uint16*)&opnd1[1]);
		for(i=0;i<cnt;i++)
		{

			if(tar==NULL)
				return PLC_DEVICE_increaseStep(FALSE);
			uint16 value = PLC_DEVICE_getOffsetDeviceValue(opnd1, i);
			sprintf(&tar[i*4], "%04X", value);

			//DBG_LOGPRINT("%04X ", value);

		}
		for( i=0 ; i<strlen(tar)-1 ; i++ )
		{
			if(tar[i]=='0')
				tar[i] = ' ';
			else
				break;
		}
		//DBG_LOGPRINT("TO TAR [%s%d]%s\n", opndic[opnd2[0]].strType, *(uint16*)&opnd2[1], tar);
		//
	}
	return PLC_DEVICE_increaseStep(TRUE);
}
unsigned char inProcess_ASCIIArrToInt( uint8 inst[], uint32 *pos, uint8 isPulse)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		uint16 cnt = 0;
		int i, j;
		if(!PLC_DEVICE_getOffsetDeviceWordValue(&cnt, opnd3, 0))
		{
			DBG_LOGPRINT("getValue 3 failed!\n");
			return PLC_DEVICE_increaseStep(FALSE);
		}
		if(!PLC_DEVICE_isDeviceAddrRange(opnd1, cnt*2))
		{
			DBG_LOGPRINT("getValue 1 failed [%s%d + %d]!\n",
					opndic[opnd1[0]].strType,
					*(uint16*)&opnd1[1],
					cnt*2);
			return PLC_DEVICE_increaseStep(FALSE);
		}
		if(!PLC_DEVICE_isDeviceAddrRange(opnd2, cnt))
		{
			DBG_LOGPRINT("getValue 2 failed!\n");
			return PLC_DEVICE_increaseStep(FALSE);
		}
		char* tar =  (char*)PLC_DEVICE_getDeviceString(opnd1);
		for(i=0;i<cnt;i++)
		{

			//DBG_LOGPRINT("FROM TAR [%d]%s\n", i, tar);
			uint16 value = 0;
			uint16 currplace = 1;
			for(j=0; j<4; j++)
			{
				uint16 currVal = 0;
				if(tar[j]<='9'&& tar[j]>='0')
				{
					currVal = tar[j]-'0';
				}
				else if(tar[j]<='F' && tar[j]>='A' )
				{
					currVal = tar[j]-'A'+10;

				}
				else if(tar[j] != ' ')
				{
					DBG_LOGPRINT("[ERROR] curr tar[%d] uint8[%d] char[%c], str = %s\n", j, tar[j], tar[j], &tar[j]);
					return PLC_DEVICE_increaseStep(FALSE);
				}
				//DBG_LOGPRINT("currVal[%d] %X\n", j, currVal);
				value += currplace* currVal;


				currplace*=16;
			}
			//DBG_LOGPRINT("TO TAR [%d]%04X\n", i, value);
			tar += 4;
			PLC_DEVICE_setDeviceValue(opnd2, value, i);
		}
	}
	return PLC_DEVICE_increaseStep(TRUE);
}

unsigned char inProcess_limit( uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDWord)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd4 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		if(!isDWord)
		{
			short upperLimit;
			short lowerLimit;
			short src;
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&upperLimit, opnd2, 0))
			{
				DBG_LOGPRINT("[Error %s] operand1\n");
				return PLC_DEVICE_increaseStep(FALSE);
			}
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&lowerLimit, opnd1, 0))
			{
				DBG_LOGPRINT("[Error %s] operand2\n");
				return PLC_DEVICE_increaseStep(FALSE);
			}
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&src, opnd3, 0))
			{
				DBG_LOGPRINT("[Error %s] operand3\n");
				return PLC_DEVICE_increaseStep(FALSE);
			}
			if(upperLimit < lowerLimit)
			{
				DBG_LOGPRINT("[Error %s] operand4\n");
				return PLC_DEVICE_increaseStep(FALSE);
			}
			if(src<lowerLimit)
			{
				if(!PLC_DEVICE_setDeviceValue(opnd4, lowerLimit, 0))
					DBG_LOGPRINT("[Error %s] set operand4\n");
			}
			else if(src>upperLimit)
			{
				if(!PLC_DEVICE_setDeviceValue(opnd4, upperLimit, 0))
					DBG_LOGPRINT("[Error %s] set operand4\n");
			}
			else
			{
				if(!PLC_DEVICE_setDeviceValue(opnd4, src, 0))
					DBG_LOGPRINT("[Error %s] set operand4\n");
			}

		}
		else
		{
			int upperLimit;
			int lowerLimit;
			int src;
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&upperLimit, opnd2, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&lowerLimit, opnd1, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&src, opnd3, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(upperLimit < lowerLimit)
				return PLC_DEVICE_increaseStep(FALSE);
			if(src<lowerLimit)
				PLC_DEVICE_setDeviceDoubleWordValue(opnd4, lowerLimit);
			else if(src>upperLimit)
				PLC_DEVICE_setDeviceDoubleWordValue(opnd4, upperLimit);
			else
				PLC_DEVICE_setDeviceDoubleWordValue(opnd4, src);
		}

	}

	return PLC_DEVICE_increaseStep(TRUE);
}
unsigned char inProcess_band( uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDWord)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd4 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		if(!isDWord)
		{
			short upperBand;
			short lowerBand;
			short src;
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&upperBand, opnd2, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&lowerBand, opnd1, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&src, opnd3, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(upperBand < lowerBand)
				return PLC_DEVICE_increaseStep(FALSE);
			if(src<lowerBand)
				PLC_DEVICE_setDeviceValue(opnd4, src - lowerBand, 0);
			else if(src>upperBand)
				PLC_DEVICE_setDeviceValue(opnd4, src - upperBand, 0);
			else
				PLC_DEVICE_setDeviceValue(opnd4, 0, 0);

		}
		else
		{
			int upperBand;
			int lowerBand;
			int src;
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&upperBand, opnd2, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&lowerBand, opnd1, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&src, opnd3, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(upperBand < lowerBand)
				return PLC_DEVICE_increaseStep(FALSE);
			if(src<lowerBand)
				PLC_DEVICE_setDeviceDoubleWordValue(opnd4, src-lowerBand);
			else if(src>upperBand)
				PLC_DEVICE_setDeviceDoubleWordValue(opnd4, src-upperBand);
			else
				PLC_DEVICE_setDeviceDoubleWordValue(opnd4, 0);
		}

	}
	return PLC_DEVICE_increaseStep(TRUE);
}

unsigned char inProcess_zone( uint8 inst[], uint32 *pos, uint8 isPulse, uint8 isDWord)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd3 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd4 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		if(!isDWord)
		{
			short upperBand;
			short lowerBand;
			short src;
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&upperBand, opnd2, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&lowerBand, opnd1, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceWordValue(&src, opnd3, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(upperBand < lowerBand)
				return PLC_DEVICE_increaseStep(FALSE);
			if(src<0)
			{
				PLC_DEVICE_setDeviceValue(opnd4, src + lowerBand, 0);
			}
			else if(src>0)
			{
				//DBG_LOGPRINT("[band]%d+%d\n", src, upperBand);
				PLC_DEVICE_setDeviceValue(opnd4, src + upperBand, 0);
			}
			else
				PLC_DEVICE_setDeviceValue(opnd4, 0, 0);

		}
		else
		{
			int upperBand;
			int lowerBand;
			int src;
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&upperBand, opnd2, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&lowerBand, opnd1, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&src, opnd3, 0))
				return PLC_DEVICE_increaseStep(FALSE);
			if(upperBand < lowerBand)
				return PLC_DEVICE_increaseStep(FALSE);
			if(src<0)
				PLC_DEVICE_setDeviceDoubleWordValue(opnd4, src +lowerBand);
			else if(src>0)
				PLC_DEVICE_setDeviceDoubleWordValue(opnd4, src+ upperBand);
			else
				PLC_DEVICE_setDeviceDoubleWordValue(opnd4, 0);
		}

	}
	return PLC_DEVICE_increaseStep(TRUE);
}
unsigned char inProcess_daterd( uint8 inst[], uint32 *pos, uint8 isPulse)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		int i;
		for(i=0;i<7;i++)
		{
			uint16 value = PLC_Register_getWord(OPERAND_ML_CODE_SD, PLC_SD_REG_DATE_TIME+i);
			if(!PLC_DEVICE_setDeviceValue(opnd1, value, i))
				return PLC_DEVICE_increaseStep(FALSE);
		}
	}
	return PLC_DEVICE_increaseStep(TRUE);
}
unsigned char inProcess_datewr( uint8 inst[], uint32 *pos, uint8 isPulse)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		int i;
		uint16 value;
		for(i=0;i<7;i++)
		{

			if(!PLC_DEVICE_getOffsetDeviceWordValue(&value, opnd1, i))
				return PLC_DEVICE_increaseStep(FALSE);
			if(!PLC_Register_set(OPERAND_ML_CODE_SD, PLC_SD_REG_DATE_TIME+i,0, &value, TYPE_WORD))
				return PLC_DEVICE_increaseStep(FALSE);
		}

	}
	return PLC_DEVICE_increaseStep(TRUE);
}
unsigned char inProcess_toSecond( uint8 inst[], uint32 *pos, uint8 isPulse)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		uint16 hour, min, sec;
		uint32 second;
		if(!PLC_DEVICE_getOffsetDeviceWordValue(&hour, opnd1, 0))
			return PLC_DEVICE_increaseStep(FALSE);
		if(!PLC_DEVICE_getOffsetDeviceWordValue(&min, opnd1, 1))
			return PLC_DEVICE_increaseStep(FALSE);
		if(!PLC_DEVICE_getOffsetDeviceWordValue(&sec, opnd1, 2))
			return PLC_DEVICE_increaseStep(FALSE);

		second = 3600*hour + 60*min+ sec;

		if(!PLC_DEVICE_setDeviceDoubleWordValue(opnd2, second))
			return PLC_DEVICE_increaseStep(FALSE);
		//DBG_LOGPRINT("%d:%d:%d => %d\n", hour, min, sec, second);
	}
	return PLC_DEVICE_increaseStep(TRUE);
}
unsigned char inProcess_toHour( uint8 inst[], uint32 *pos, uint8 isPulse)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		uint16 hour, min, sec;
		uint32 second;
		if(!PLC_DEVICE_getOffsetDeviceDoubleWordValue(&second, opnd1, 0))
			return PLC_DEVICE_increaseStep(FALSE);
		hour = second / 3600;
		min = (second / 60) %60;
		sec = second % 60;
		//second = 3600*hour + 60*min+ sec;
		if(!PLC_DEVICE_setDeviceValue(opnd2, hour, 0))
			return PLC_DEVICE_increaseStep(FALSE);
		if(!PLC_DEVICE_setDeviceValue(opnd2, min, 1))
			return PLC_DEVICE_increaseStep(FALSE);
		if(!PLC_DEVICE_setDeviceValue(opnd2, sec, 2))
			return PLC_DEVICE_increaseStep(FALSE);
		//DBG_LOGPRINT("%d:%d:%d <= %d\n", hour, min, sec, second);
	}
	return PLC_DEVICE_increaseStep(TRUE);
}

unsigned char inProcess_rotationBitInTargetWord( uint8 inst[], uint32 *pos, uint8 isWord, uint8 isCarryIncluded, uint8 isPulse, uint8 isRightDirection)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint8 isRun;
	if(isPulse)
	{
		uint8 past = preProcess_pick(*pos);
		uint8 curr = getCurrBitValue(*pos);
		isRun = inProcess_detectRaisingEdge(curr, past);
	}
	else
	{
		isRun = getCurrBitValue(*pos);
	}

	if(isRun)
	{
		uint16 rotationLength = PLC_DEVICE_getDeviceWordValue(opnd2);
		int modSize=0;
		unsigned long long src;
		unsigned long long dst=0;
		uint16 dst1, dst2;
		uint16 carry = 0;
		uint8 precarry=0;
		if(isWord)
		{
			modSize = 16;
			src = PLC_DEVICE_getDeviceWordValue(opnd1);
			rotationLength %= modSize;
		}
		else
		{
			modSize = 32;
			src = PLC_DEVICE_getDeviceDoubleWordValue(opnd1);
			rotationLength %= modSize;
		}
		if(isRightDirection)
		{
			if(!isCarryIncluded)
			{
					carry = (src>>(rotationLength-1))&0x01;
					dst1 = src>>rotationLength;
					dst2 = src<<(modSize-rotationLength);
					dst =  dst1 + dst2;
				//DBG_LOGPRINT("[Rotation>>%d] src : %d, dst : %d, carry : %d\n", rotationLength, src, dst, carry);
			}
			else
			{
				precarry = PLC_Register_getBit(OPERAND_ML_CODE_SM, PLC_SM_REG_CARRY_FLAG);
				//DBG_LOGPRINT("[SM700] precarry = %d\n", precarry);
				carry = (src>>(rotationLength-1))&0x01;
				dst1 = src>>rotationLength;
				dst2 = src<<(modSize+1-rotationLength);
				dst = dst1 + dst2 + (precarry<<(modSize-rotationLength));
			}
		}
		else
		{
			if(!isCarryIncluded)
			{
					carry = (src<<(rotationLength-1))&0x01;
					dst1 = src<<rotationLength;
					dst2 = src>>(modSize-rotationLength);
					dst =  dst1 + dst2;
				//DBG_LOGPRINT("[Rotation>>%d] src : %d, dst : %d, carry : %d\n", rotationLength, src, dst, carry);
			}
			else
			{
				precarry = PLC_Register_getBit(OPERAND_ML_CODE_SM, PLC_SM_REG_CARRY_FLAG);
				//DBG_LOGPRINT("[SM700] precarry = %d\n", precarry);
				carry = (src<<(rotationLength-1))&0x01;
				dst1 = src<<rotationLength;
				dst2 = src>>(modSize+1-rotationLength);
				dst = dst1 + dst2 + (precarry<<(rotationLength-1));
			}
		}
		//DBG_LOGPRINT("[RotationC >>%d] src : %04X, precarry : %d, dst : %04X [ dst1 | dst2] = [ %04X | %04X ], carry : %d\n", rotationLength, src, precarry, dst, dst1, dst2, carry);

		if(isWord)
			PLC_DEVICE_setDeviceValue(opnd1, dst, 0);
		else
			PLC_DEVICE_setDeviceDoubleWordValue(opnd1, dst);

		PLC_Register_set(OPERAND_ML_CODE_SM, PLC_SM_REG_CARRY_FLAG, 0, &carry, TYPE_BIT);
	}
	return PLC_DEVICE_increaseStep(TRUE);
}