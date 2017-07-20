/*
 * test_runtime_error.c
 *
 *  Created on: Sep 4, 2015
 *      Author: hrjung
 */


#ifdef USE_CUNIT_TEST_DEF

#ifndef PLC_LISTOFTESTSUITE_H_
#include "../PLC_ListOfTestSuite.h"
#endif

#include <stdio.h>
#include <stdlib.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../testPlatform/PLC_Platform.h"

#define RUNTIME_ERR_INVALID_BCD			ERROR_CODE_INVALID_VALUE
#define RUNTIME_ERR_INTEGER_RANGE_OVER	ERROR_CODE_INVALID_VALUE
#define RUNTIME_ERR_FLOAT_RANGE_OVER	ERROR_CODE_OUT_OF_VALUE_RANGE
#define RUNTIME_ERR_INVALID_STRING		4141 //no null terminated string
#define RUNTIME_ERR_INVALID_GRAY_CODE	ERROR_CODE_INVALID_VALUE //negative value is not allowed
#define RUNTIME_ERR_INVALID_FLOAT		4140 // nan, -0, infinite value..

#define RUNTIME_ERR_DEVICE_RANGE_OVER	ERROR_CODE_OUT_OF_DEVICE_RANGE
#define RUNTIME_ERR_TOO_LONG_STRING		ERROR_CODE_INVALID_VALUE
#define RUNTIME_ERR_INVALID_COUNT		ERROR_CODE_INVALID_VALUE // negative count
#define RUNTIME_ERR_OVERLAP_RANGE		ERROR_CODE_OUT_OF_DEVICE_RANGE // overlap src and dest for block command
#define RUNTIME_ERR_DIVIDE_BY_ZERO		4102
#define RUNTIME_ERR_FLOAT_IS_ZERO		ERROR_CODE_INVALID_VALUE // ??


extern void TestCodeInit(void);
extern void TestCodeTearDown(void);
extern int runTestCode(int run_step, char *testFuncName);

typedef struct {
	uint8 reg;
	uint16 pos;
	uint16 bpos;
	uint8 val;
} dev_st;


typedef struct {
	int tno;
	uint16 ml_cmd;
	int on_off;
	int run_step;
	int (*setCode)(uint16, dev_st);
	void (*setInput)(dev_st, int);
	dev_st out;
	short expected;

} testCase_st;


int setCodeOp1_Bit(uint16 ml_cmd, dev_st out)
{
	if(out.reg > OPERAND_ML_CODE_B) return 0;
	if(out.reg == OPERAND_ML_CODE_X && out.pos == 100) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);	addMLOperand(out.reg, out.pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp1_WBit(uint16 ml_cmd, dev_st out)
{
	if(out.reg < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandWordBit(out.reg, out.pos, out.bpos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp1_OUT_C(uint16 ml_cmd, dev_st out)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(out.reg, out.pos); addMLOperand(OPERAND_ML_CODE_K, -10);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp1_Bit(dev_st out, int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, (uint8)out.reg, out.pos, out.val);

	TestCodeTearDown();
}

void setInputOp1_None(dev_st out, int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	TestCodeTearDown();
}

int verifyErrorRegister(uint16 expected)
{
	int rc=0;
	uint8 SM_bit=0;
	uint16 SD_val=0;

	test_getBit(&SM_bit, OPERAND_ML_CODE_SM, 0);
	test_getWord(&SD_val, OPERAND_ML_CODE_SD, 0);
	//SM_bit = PLC_getSMRegister(0);
	//SD_val = PLC_getSDRegister(0);

	CU_ASSERT_EQUAL(SM_bit, 1);
	CU_ASSERT_EQUAL(SD_val, expected);

	DBG_LOGPRINT("SM=%d SD=%d exp=%d\n", SM_bit, SD_val, expected);
	if(SM_bit==1 && SD_val==expected) rc=1;

	return rc;
}

void test_Op1_Bit(testCase_st tCase)
{
	int rc1=0, rc2=0;

	PLC_DEVICE_Init();

	rc2 = tCase.setCode(tCase.ml_cmd, tCase.out);
	if( rc2 == 0 ) return; // test input error

	tCase.setInput(tCase.out, tCase.on_off);

	rc1=runTestCode(tCase.run_step, "runtime error test");
	if(rc1==1)
	{
		rc2=verifyErrorRegister(tCase.expected);
		if(rc2==1)
		{
			printf("tno=%d cmd=%s exp=%d\n", \
				tCase.tno, PLC_OPERATOR_DICTIONARY_findOperator(tCase.ml_cmd)->strName, tCase.expected);
		}
	}
	else
	{
		CU_ASSERT_TRUE(rc1);
		printf(" tno=%d cmd=%s Runtime error should occur !! \n",
			tCase.tno, PLC_OPERATOR_DICTIONARY_findOperator(tCase.ml_cmd)->strName);
	}
}

uint16 lastpos[] = {8192,8192,8192,8192,2048,8192,0,12288,8192};

static testCase_st tCase[]={
	{ 0, ML_CODE_SFT, 1, 1, setCodeOp1_Bit, setInputOp1_Bit,
		{OPERAND_ML_CODE_X,0,0,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 1, ML_CODE_SFT, 1, 1, setCodeOp1_Bit, setInputOp1_Bit,
		{OPERAND_ML_CODE_X,8192,0,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 2, ML_CODE_SFT, 1, 1, setCodeOp1_WBit, setInputOp1_Bit,
		{OPERAND_ML_CODE_D,0,0,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 3, ML_CODE_SFT, 1, 1, setCodeOp1_WBit, setInputOp1_Bit,
		{OPERAND_ML_CODE_D,0,16,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 4, ML_CODE_SFT, 1, 1, setCodeOp1_WBit, setInputOp1_Bit,
		{OPERAND_ML_CODE_D,12288,1,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{ 5, ML_CODE_SFTP, 2, 2, setCodeOp1_Bit, setInputOp1_Bit,
		{OPERAND_ML_CODE_X,0,0,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 6, ML_CODE_SFTP, 2, 2, setCodeOp1_Bit, setInputOp1_Bit,
		{OPERAND_ML_CODE_X,8192,0,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 7, ML_CODE_SFTP, 2, 2, setCodeOp1_WBit, setInputOp1_Bit,
		{OPERAND_ML_CODE_D,0,0,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 8, ML_CODE_SFTP, 2, 2, setCodeOp1_WBit, setInputOp1_Bit,
		{OPERAND_ML_CODE_D,0,16,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 9, ML_CODE_SFTP, 2, 2, setCodeOp1_WBit, setInputOp1_Bit,
		{OPERAND_ML_CODE_D,12288,1,0}, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{10, ML_CODE_OUT, 1, 1, setCodeOp1_OUT_C, setInputOp1_None,
		{OPERAND_ML_CODE_C,10,0,0}, RUNTIME_ERR_INVALID_COUNT},

	{ -1, 0, 0, 0, NULL, NULL, {0,0,0}, 0 }
};

void testRuntimeErrorSequence(void)
{
	int index=8;

	printf("run test testRuntimeErrorSequence() tno=%d\n", index);
#if 1
	test_Op1_Bit(tCase[index]);
#else
	for(index=0; index<10; index++)
		test_Op1_Bit(tCase[index]);
#endif
}


#endif
