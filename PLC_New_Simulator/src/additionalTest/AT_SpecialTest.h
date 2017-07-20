/*
 * AT_SpecialTest.h
 *
 *  Created on: 2016. 5. 13.
 *      Author: skson
 */

#ifndef AT_SPECIALTEST_H_
#define AT_SPECIALTEST_H_
#include "../PLC_ListOfTestSuite.h"

typedef struct{
	char* testName;
	uint8(* inputFunction)(int , uint8* , uint16* , uint16**);
	uint8(* MLFunction)(int , uint8* , uint16* , uint16** );
	int inputCount;
	int expectedIdx;
	uint8 inputType[5];
	uint16 inputAddr[5];
	uint16* inValue[5];
	int inValLength[5];
	uint16* expected;
	uint8 isPulse;
	uint8 isOn;
}SpecicalTestInput;

void printTestInput(SpecicalTestInput input);

uint8 AT_forNext_setInput(int opCount, uint8* operand, uint16* operandAddr, uint16** operandValue);
uint8 AT_forNext_setML(int opCount, uint8* operand, uint16* operandAddr, uint16** operandValue);
uint8 AT_forNext();

uint8 AT_forNextBreak_setInput(int opCount, uint8* operand, uint16* operandAddr, uint16** operandValue);
uint8 AT_forNextBreak_setML(int opCount, uint8* operand, uint16* operandAddr, uint16** operandValue);
uint8 AT_forNextBreak();

uint8 AT_testSpecialUnit(SpecicalTestInput input);

#endif /* AT_SPECIALTEST_H_ */
