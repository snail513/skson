/*
 * PLC_ListOfTestSuite.h
 *
 *  Created on: 2014. 11. 17.
 *      Author: skson
 */

#ifndef PLC_LISTOFTESTSUITE_H_
#define PLC_LISTOFTESTSUITE_H_
#include "PLC_OperatorDictionary.h"
#include "PLC_Device.h"
#define BIT_RST 1
#define WORD_RST 2
#define DWORD_RST 3
#define LONG_RST 5
#define FLOAT_RST 6
#define DOUBLE_RST 7
#define BLOCK_RST 4

#ifdef USE_CUNIT_DEF
uint8 getSimpleTest();
PLC_DEVICE_ControlInstruction* PLC_ListOfTestSuite_getControlInput();
uint16 PLC_ListOfTestSuite_getControlSize();



void addMLPointLabel(uint16 label);
void addMLOperator(uint16 operator_ml);
void addMLOperand(uint8 devType, uint32 devAddr);
uint8 addMLFile(char* MLFilePathName, uint8 taskIdx, uint32 crc);
uint8 reloadMLfile(char* MLFilePathName, uint8 taskIdx, uint32 crc, LaunchingCondition condition);
void addMLOperandFloat(uint8 devType, float fvalue);
void addMLOperandDouble(uint8 devType, double dvalue);
void addMLOperandNibble(uint16 nibbleAddr, uint8 devType, uint16 devAddr);
void addMLOperandWordBit(uint8 devType, uint16 devAddr, uint16 bitValue);
void addMLOperandZIndex(uint8 operandType, uint16 devAddr, uint16 zIdx);
void addConstantStringoperand(char* strValue);

//TODO :: float, double, DWord


void addDeviceControlInstruction(uint32 time, uint8 operandType, uint16 operandAddr, uint32 value);
void addDeviceControlInstructionToDWord(uint32 time, uint8 operandType, uint16 operandAddr, uint32 dwordValue);
void addDeviceControlInstructionToFloat(uint32 time, uint8 operandType, uint16 operandAddr, float fValue);
void addDeviceControlInstructionToDouble(uint32 time, uint8 operandType, uint16 operandAddr, double fValue);
void addDeviceControlInstructionToString(uint32 time, uint8 operandType, uint16 operandAddr, char* strValue);
void writeDeviceControlInputFile(char* filePathName);
void addDeviceControlInputFile(char* filePathName);

//Todo :: DWord, String, Nibble, Bit, WordBit
void addDeviceControlNibble(uint32 time, uint8 operandType, uint16 operandAddr, uint8  nibbleCount, uint8 nibbleValue);
void addDeviceControlBit(uint32 time, uint8 operandType, uint16 operandAddr, uint8 bitValue);
void addDeviceControlWordBit(uint32 time, uint8 operandType, uint16 bitAddr, uint16 bitValue);


void setUserLDProgram(void(*userProgram)(void));
void* getUserLDProgram();
void setUserLuntimeInitFunction(uint8(*userProgram)(void));
void* getUserLuntimeInitFunction();
void setUserLuntimeFunction(uint8(*userProgram)(void));
void* getUserLuntimeFunction();
void setTestCase(uint16 mlCode, void (*setUserProgram)(void));

void TestCodeInit();
void TestCodeTearDown();
void TestCodeTearDownByTaskIdx(uint8 taskIdx);
int runTestCode(int run_step, char* nameTest);
int runAdditionalTestCode(int run_step, char* nameTest);
int init_suite_EXEC_SUITE();
int clean_suite_EXEC_SUITE();
void test_suite_EXEC_SUITE();
uint32 run_suite_EXEC_SUITE();
uint8 initExecSuite();
uint8 runExecSuiteOnece();


void setTimerLD();

void setTimerInput();

void setUserInput();
void setUserIL(uint8 taskIdx);
void setTestILInput(uint8 taskIdx);

void timerTest(void);

#endif /* CROSS_COMPILER */

#endif /* PLC_LISTOFTESTSUITE_H_ */


