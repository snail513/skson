/*
 * PLC_Platform.c
 *
 *  Created on: 2015. 6. 10.
 *      Author: skson
 */
#ifndef PLC_PLATFORM_H_
#include "PLC_Platform.h"
#include "../PLC_Register.h"
#endif

static char* MLFilePathName;

void setMLFilePathName(char* filePathName){
	MLFilePathName = filePathName;
}
void setUserFunctions(void(*userIL)(), uint8 (*userRunTimeInit)(), uint8 (*userRuntime)()){
	setUserLDProgram(userIL);
	setUserLuntimeInitFunction(userRunTimeInit);
	setUserLuntimeFunction(userRuntime);
}
void testFileCode(){
	uint8 taskIdx = 0;
	uint32 crc = 0;
	if(!addMLFile(MLFilePathName, taskIdx, crc))
		printf("File Loading is failed!\n");
}

void testMLCode(void){//-->addMLCode
	/*int i;
	int loopCount=5000;
	for(i=0; i<loopCount; i++)
	{
		addMLOperator(ML_CODE_LD);	addMLOperand(OPERAND_ML_CODE_X, i);
		addMLOperator(ML_CODE_OUT);	addMLOperand(OPERAND_ML_CODE_Y, i);
	}
	addMLOperator(ML_CODE_END);*/
	uint8 taskIdx = 0;
	uint32 crc = 0;
	if(!addMLFile("/home/skson/out/PLC3/test.ml", taskIdx, crc))
			printf("File Loading is failed!\n");
}

uint8 testInitProgram(void){
	//printf("write initiation code!\n");
	return TRUE;//FALSE=>ERROR
}

uint8 testProgram(void){
	//printf("write runtime code!\n");
	return TRUE;//FALSE=>ERROR
}

void printfUserMLCode(void){
	int i;
	for(i=0; i<10; i++)
	{
		printf("%s %s%d\n",
				PLC_OPERATOR_DICTIONARY_findOperator(ML_CODE_LD)->strName,
				opndic[OPERAND_ML_CODE_X].strType,
				i);
		printf("%s %s%d\n",
				PLC_OPERATOR_DICTIONARY_findOperator(ML_CODE_OUT)->strName,
				opndic[OPERAND_ML_CODE_X].strType,
				i);
	}
	printf("%s\n",PLC_OPERATOR_DICTIONARY_findOperator(ML_CODE_END)->strName);
}
uint8 PLC_getSMRegister(uint16 index){
	return PLC_Register_getBit(OPERAND_ML_CODE_SM, index);
}
uint16 PLC_getSDRegister(uint16 index){
	return PLC_Register_getWord(OPERAND_ML_CODE_SD, index);
}
uint8 PLC_setBitRegister(uint8 type, uint16 index, uint8 value){
	return PLC_Register_set(type, index, 0, (uint8*)&value, TYPE_BIT);
}
uint8 PLC_setWordRegister(uint8 type, uint16 index, uint16 value){
	return PLC_Register_set(type, index, 0, (uint8*)&value, TYPE_WORD);
}
uint8 PLC_setSMRegister(uint16 index, uint8 value){
	return PLC_Register_set(OPERAND_ML_CODE_SM, index, 0, (uint8*)&value, TYPE_BIT);
}
uint8 PLC_setSDRegister(uint16 index, uint16 value){
	return PLC_Register_set(OPERAND_ML_CODE_SD, index, 0, (uint8*)&value, TYPE_WORD);
}

uint8 PLC_setLatch(uint8 devMLCode, uint16 latchHeadInWord, uint16 latchSizeInWord)
{
	return PLC_Register_setLatch(devMLCode, latchHeadInWord, latchSizeInWord);
}


