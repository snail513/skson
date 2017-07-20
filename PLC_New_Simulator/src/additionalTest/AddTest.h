/*
 * AddTest.h
 *
 *  Created on: 2016. 5. 4.
 *      Author: skson
 */

#ifndef ADDTEST_H_
#define ADDTEST_H_
#include "../PLC_ListOfTestSuite.h"


typedef enum{
	IOTypeSRC,
	IOTypeDST,
	IOTypeCNT,
	IOTypeConst,
}IOType;

typedef enum{
	VTypeWordDev,
	VTypeBitDev,
	VTypeK,
	VTypeDK,
	VTypeStr,
	VTypeE,
	VTypeDE,
}VType;

typedef enum{
	TVarTest,
	TVarConst
}TVarType;

#define TRRIGER_DEVICE OPERAND_ML_CODE_X
#define TRRIGER_ADDRESS 100

uint8* AT_getOperand(VType v);
int AT_getOperandSize(VType v, TVarType tv);
void AT_setNibbleInclude(uint8 isNInclude);
void AT_setWordBitInclude(uint8 isWBInclude);
void ATest_setCarryOff();
void ATest_setCarryOn();
uint8* AT_getBitOperand();
uint8 AT_getDefaultOperand(IOType* ioType, VType* vType, uint8* operandType, uint16* operandAddr, int operandcount, uint16** initValue);
uint16 AT_getOperandAddr(uint8 type, uint8 pos, uint8 arraySize);
uint8* AT_getWordOperand();
//uint16 AT_getOperandAddr(uint8 type, uint8 pos, uint8 isBit ,uint8 arraySize);
uint8 AT_setMLCode(uint16 operatorML, uint8* operand, uint16* addr);
uint8 AT_setGeneralMLCode(uint16 operatorML, uint8** operand);
uint8 AT_setInputSwitch(uint8 isOn, uint8 isPulse);
uint8 AT_setInputSrcWord(uint8 type, uint16 addr, uint16* src, int addrSize);
uint8 AT_assertWordResult(uint8 type, uint16 addr, uint16* exp, int expSize, uint8 isEQ);
uint8 AT_assertBitResult(uint8 type, uint16 addr, uint16* exp, int expSize);

uint8 AT_testGeneralUnitTest(
		uint16 cmd, uint8 runAsOn, uint8 runAsPls,
		TVarType* tvarType, VType* vType, IOType* ioType,
		char* testName,
		uint16** initialValue, uint16* initialValueSize, uint16* expected, uint16 expectedSize,
		void(*inputFunction)(void)
		);
#endif /* ADDTEST_H_ */
