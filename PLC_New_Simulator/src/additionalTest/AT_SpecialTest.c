/*
 * AT_SpecialTest.c
 *
 *  Created on: 2016. 5. 13.
 *      Author: skson
 */

#ifndef AT_SPECIALTEST_H_
#include "AT_SpecialTest.h"
#include "CUnit/CUnit.h"

extern uint16 AT_getOperandAddr(uint8 type, uint8 pos, uint8 arraySize);
extern uint8 AT_assertWordResult(uint8 type, uint16 addr, uint16* exp, int expSize, uint8 isEQ);

#define BREAK_COUNT 7


static uint16 repeatCount[] = {5, 10, 100};
static uint16 breakCount[] = {1, 10, 107};

uint8 AT_testSpecialUnit(SpecicalTestInput input)
{

	PLC_DEVICE_Init();
	TestCodeInit();
	int time;
	if(!input.inputFunction(input.inputCount, input.inputType, input.inputAddr, input.inValue))
	{
		int t =1, f = 0;
		CU_ASSERT_EQUAL(t, f);
		return FALSE;
	}

	if(!input.MLFunction(input.inputCount, input.inputType, input.inputAddr, input.inValue))
	{
		int t =1, f = 0;
		CU_ASSERT_EQUAL(t, f);
		return FALSE;
	}
	TestCodeTearDownByTaskIdx(0);
	time = input.isPulse?2:1;
	if(!runAdditionalTestCode(time, input.testName))
	{
		int t =1, f = 0;
		CU_ASSERT_EQUAL(t, f);
		return FALSE;
	}


	if(!AT_assertWordResult(
			input.inputType[input.expectedIdx],
			input.inputAddr[input.expectedIdx],
			input.expected,
			input.inValLength[input.expectedIdx],
			input.isOn))
	{
		int t =1, f = 0;
		CU_ASSERT_EQUAL(t, f);
		return FALSE;
	}
	return TRUE;
}

uint8 AT_forNext_setInput(int opCount, uint8* operand, uint16* operandAddr, uint16** operandValue)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 1, 1);
	addDeviceControlInstruction(0, operand[0], operandAddr[0], *operandValue[0]);
	addDeviceControlInstruction(0, operand[1], operandAddr[1], *operandValue[1]);
	return TRUE;
}

uint8 AT_forNextBreak_setInput(int opCount, uint8* operand, uint16* operandAddr, uint16** operandValue)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 1, 1);
	addDeviceControlInstruction(0, operand[0], operandAddr[0], *operandValue[0]);
	addDeviceControlInstruction(0, operand[1], operandAddr[1], *operandValue[1]);
	addDeviceControlInstruction(0, operand[2], operandAddr[2], *operandValue[2]);
	addDeviceControlInstruction(0, operand[3], operandAddr[3], *operandValue[3]);
	return TRUE;
}

uint8 AT_forNext_setML(int opCount, uint8* operand, uint16* operandAddr, uint16** operandValue)
{
	addMLOperator(ML_CODE_FOR);addMLOperand(operand[0], operandAddr[0]);
	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 1);
	addMLOperator(ML_CODE_INC);addMLOperand(operand[1], operandAddr[1]);
	addMLOperator(ML_CODE_NEXT);
	addMLOperator(ML_CODE_END);
	return TRUE;
}

uint8 AT_forNextBreak_setML(int opCount, uint8* operand, uint16* operandAddr, uint16** operandValue)
{
	addMLOperator(ML_CODE_FOR);addMLOperand(operand[0], operandAddr[0]);
	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 1);
	addMLOperator(ML_CODE_INC);addMLOperand(operand[1], operandAddr[1]);
	addMLOperator(ML_CODE_LDEQ);addMLOperand(operand[1], operandAddr[1]);addMLOperand(OPERAND_ML_CODE_K, *operandValue[2]);
	addMLOperator(ML_CODE_BREAK);addMLOperand(operand[3], operandAddr[3]);addMLOperand(OPERAND_ML_CODE_K, 0);
	addMLOperator(ML_CODE_NEXT);
	addMLOperator(ML_CODE_END);
	return TRUE;
}
//TODO : complete this method!
uint8 AT_forNext()
{
	SpecicalTestInput input ;
	input.MLFunction = AT_forNext_setML;
	input.inputFunction = AT_forNext_setInput;
	input.testName = "For-Next test";
	input.inputCount = 2;
	input.expectedIdx = 1;

	input.inValLength[0] = 1;
	input.inValLength[1] = 1;

	input.isPulse = 0;
	input.isOn = 1;

	uint16 wordDev[] = {OPERAND_ML_CODE_D, OPERAND_ML_CODE_W};
	int i, j, idx;
	for(j = 0; j< 2; j++)
	{
		uint16 srcVal;
		uint16 dstVal = 0;

		input.inputType[0] = OPERAND_ML_CODE_D;
		input.inputType[1] = OPERAND_ML_CODE_W;

		input.inputAddr[0] = 100;
		input.inputAddr[1] = 200;

		input.inValue[0] = &srcVal;
		input.inValue[1] = &dstVal;

		input.expected = &srcVal;

		for(idx = 0 ; idx<2; idx++)
		{
			input.inputType[j] = wordDev[idx];
			for(i = 0 ; i < 3; i++)
			{
				int repeatCountTry;
				input.inputAddr[j] = AT_getOperandAddr(wordDev[idx], i, 1);
				for( repeatCountTry=0; repeatCountTry<3; repeatCountTry++ )
				{
					srcVal = repeatCount[repeatCountTry];
					AT_testSpecialUnit(input);
				}
			}
		}
	}
	return TRUE;
}


uint8 AT_forNextBreak()
{
	SpecicalTestInput input ;
	input.MLFunction = AT_forNextBreak_setML;
	input.inputFunction = AT_forNextBreak_setInput;
	input.testName = "For-Next-Break test";
	input.inputCount = 4;
	input.expectedIdx = 3;

	input.inValLength[0] = 1;
	input.inValLength[1] = 1;
	input.inValLength[2] = 1;
	input.inValLength[3] = 1;
	input.isPulse = 0;
	input.isOn = 1;

	uint16 wordDev[] = {OPERAND_ML_CODE_D, OPERAND_ML_CODE_W};
	int i, j, idx;
	for(j = 0; j< 2; j++)
	{

		uint16 srcVal;
		uint16 dstVal = 0;

		input.inputType[0] = OPERAND_ML_CODE_D;
		input.inputType[1] = OPERAND_ML_CODE_W;
		input.inputType[2] = OPERAND_ML_CODE_D;
		input.inputType[3] = OPERAND_ML_CODE_W;

		input.inputAddr[0] = 100;
		input.inputAddr[1] = 200;
		input.inputAddr[2] = 300;
		input.inputAddr[3] = 400;

		input.inValue[0] = &srcVal;
		input.inValue[1] = &dstVal;
		input.inValue[2] = &dstVal;
		input.inValue[3] = &dstVal;
		uint16 expected = 0;
		input.expected = &expected;

		for(idx = 0 ; idx<2; idx++)
		{
			input.inputType[j] = wordDev[idx];
			for(i = 0 ; i < 3; i++)
			{

				int repeatCountTry;
				int breakCountTry;
				for( repeatCountTry=0; repeatCountTry<3; repeatCountTry++ )
				{
					for( breakCountTry=0; breakCountTry<3; breakCountTry++ )
					{
						input.inputAddr[j] = AT_getOperandAddr(wordDev[idx], i, 1);
						srcVal = repeatCount[repeatCountTry];
						input.inValue[2] = &breakCount[breakCountTry];


						if(repeatCount[repeatCountTry]+1>breakCount[breakCountTry])
						{
							expected = repeatCount[repeatCountTry] + 1 - breakCount[breakCountTry];
							//input.isOn = 1;
						}
						else
						{
							expected = 0;
						}
						//DBG_LOGPRINT("repeat  = %d, break = %d, expected : %d\n", repeatCount[repeatCountTry], breakCount[breakCountTry], expected);

						//expected = (repeatCount[repeatCountTry]+1-breakCount>0?(:0);
						AT_testSpecialUnit(input);
					}
				}

			}
		}
	}
	return TRUE;
}
#endif

