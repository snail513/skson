/*
 * PLC_OperandDictionary.c
 *
 *  Created on: 2014. 10. 27.
 *      Author: skson
 */


#ifndef PLC_OPERANDDICTIONARY_H_
#include "PLC_OperandDictionary.h"
#endif
#include "PLC_Log.h"
static uint16 nOperandListCount=OPERAND_ML_CODE_MAX;

inline PLC_Operand* PLC_OPERAND_DICTIONARY_findOperand(uint8 typeCode){
	return (nOperandListCount>typeCode)? (PLC_Operand*)&opndic[typeCode] : NULL;
}

inline PLC_Operand* PLC_OPERAND_DICTIONARY_findOperandByName(char* name){
	uint16 index;
	for(index=0;index<nOperandListCount;index++){
		if(strcmp(name, opndic[index].strType)==0){
			return (PLC_Operand*)&opndic[index];
		}
	}
	return NULL;
}

inline int OPND_DICT_getRegSize()
{
	int i=0;
	int memorySize = 0;
	for(i=0; i<OPERAND_ML_CODE_MAX;i++)
	{
		memorySize += OPND_DICT_getOperandRegByteSize(i);
	}
	return memorySize;
}

inline int OPND_DICT_getOperandRegHeadOffset_old(uint8 typeCode)
{
	int i=0;
	int memorySize = 0;
	for(i=0; i<typeCode;i++)
	{
		memorySize += OPND_DICT_getOperandRegByteSize(i);
	}
	memorySize += OPND_DICT_getRegSize();
	//DBG_LOGPRINT("[%s_old]head offset : %d\n", opndic[i].strType, memorySize);
	return memorySize;
}

inline int OPND_DICT_getOperandRegHeadOffset(uint8 typeCode)
{
	int i=0;
	int memorySize = 0;
	for(i=0; i<typeCode;i++)
	{
		memorySize += OPND_DICT_getOperandRegByteSize(i);
	}
	//DBG_LOGPRINT("[%s]head offset : %d\n", opndic[i].strType, memorySize);
	return memorySize;
}

inline uint16 OPND_DICT_getOperandRegByteSize(uint8 typeCode){
	return opndic[typeCode].nAddressCount * opndic[typeCode].nBitSize / 8;
}

inline uint16 OPND_DICT_getOperandListCount(){
	return nOperandListCount;
}

inline void OPND_DICT_printAll(){
	char buf[300];
	int i;
	for(i=0;i<OPERAND_ML_CODE_MAX;i++)
	{
		DBG_LOGSCAN(buf, "[%s] AddrCount : %d, const : %d, size: %d, code : %d\n",
				opndic[i].strType,
				opndic[i].nAddressCount,
				opndic[i].bIsConstant,
				opndic[i].nBitSize,
				opndic[i].nMLCode
			);PLC_LOG_addLog(buf);
	}
}

uint8 OPND_DICT_ByteSize(uint8 OPERAND[])
{
	uint8 OPERAND_ML_CODE = OPERAND[0];

	switch(OPERAND_ML_CODE)
	{
		case OPERAND_ML_CODE_X:
		case OPERAND_ML_CODE_Y:
		case OPERAND_ML_CODE_R:
		case OPERAND_ML_CODE_L:
		case OPERAND_ML_CODE_F :
		case OPERAND_ML_CODE_B :
		case OPERAND_ML_CODE_SM :
		case OPERAND_ML_CODE_SB :
		case OPERAND_ML_CODE_D :
		case OPERAND_ML_CODE_W :
		case OPERAND_ML_CODE_SW :
		case OPERAND_ML_CODE_SD :
		case OPERAND_ML_CODE_T :
		case OPERAND_ML_CODE_C :
		case OPERAND_ML_CODE_K :
		case OPERAND_ML_CODE_H :
		case OPERAND_ML_CODE_Zin :// 1 + sizeof(short)
		case OPERAND_ML_CODE_FUNC_OP :
			return 3;

		case OPERAND_ML_CODE_E : // 1 + sizeof(float)
		case OPERAND_ML_CODE_DK :// 1 + sizeof(int)
			return 5;

		case OPERAND_ML_CODE_DE :// 1 + sizeof(double)
			return 9;

		case OPERAND_ML_CODE_STR :// 1 + sizeof(string) + 1
		{
			char* string = (char*)&OPERAND[1];
			return 1+strlen(string);
		}
		case OPERAND_ML_CODE_N :// 1 + sizeof(short) + 1 + sizeof(short)
		case OPERAND_ML_CODE_WB :
		case OPERAND_ML_CODE_J :
		case OPERAND_ML_CODE_Z :
		case OPERAND_ML_CODE_U :
			return 6;

		default :
			return 0;
	}
}
