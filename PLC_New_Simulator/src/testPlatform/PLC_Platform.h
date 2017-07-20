/*
 * PLC_Platform.h
 *
 *  Created on: 2015. 6. 10.
 *      Author: skson
 */

#ifndef PLC_PLATFORM_H_
#define PLC_PLATFORM_H_
#include "../PLC_ListOfTestSuite.h"

void setMLFilePathName(char* filePathName);
void setUserFunctions(void(*userIL)(), uint8 (*userRunTimeInit)(), uint8 (*userRuntime)());
void testFileCode();
void testMLCode(void);
uint8 testInitProgram(void);
uint8 testProgram(void);
void printfUserMLCode(void);

#define PLC_getBitRegister(uint8, uint16) PLC_Register_getBit(uint8, uint16)
#define PLC_getWordRegister(uint8, uint16) PLC_Register_getWord(uint8, uint16)
uint8 PLC_getSMRegister(uint16);
uint16 PLC_getSDRegister(uint16);

uint8 PLC_setBitRegister(uint8 type, uint16 index, uint8 value);
uint8 PLC_setWordRegister(uint8 type, uint16 index, uint16 value);
uint8 PLC_setSMRegister(uint16 index, uint8 value);
uint8 PLC_setSDRegister(uint16 index, uint16 value);
uint8 PLC_setLatch(uint8 devMLCode, uint16 latchHeadInWord, uint16 latchSizeInWord);

#endif /* PLC_PLATFORM_H_ */
