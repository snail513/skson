/*
 * test_runtime_error_blk.c
 *
 *  Created on: Sep 7, 2015
 *      Author: hrjung
 */


#ifdef USE_CUNIT_TEST_DEF

#ifndef PLC_LISTOFTESTSUITE_H_
#include "../PLC_ListOfTestSuite.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

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

extern int verifyErrorRegister(uint16 expected);



/*************  FTOB, FTOD, DTOB ***************/

int setCodeOp2_F2BWD(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);	addMLOperand(in, in_pos); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_F2BNB(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);	addMLOperand(in, in_pos); addMLOperandNibble(4, out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_F2BWZ(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);	addMLOperandZIndex(in, in_pos, idx_pos); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_F2DNB(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);	addMLOperand(in, in_pos); addMLOperandNibble(8, out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_D2BNB(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);	addMLOperandNibble(8, in, in_pos); addMLOperandNibble(4, out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp_F2B(uint8 in, uint16 in_pos, float in_val, uint8 out, uint16 out_pos, int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstructionToFloat(0, in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp_F2BWZ
(uint8 in, uint16 in_pos, float in_val, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val, int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, in, in_pos+idx_val, in_val);

	TestCodeTearDown();
}

void setInputOp_D2B(uint8 in, uint16 in_pos, int in_val, uint8 out, uint16 out_pos, int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstructionToDWord(0, in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp_D2BNB(uint8 in, uint16 in_pos, int in_val, uint8 out, uint16 out_pos, int on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<32; i++)
		addDeviceControlInstructionToDWord(0, in, in_pos+i, ((in_val>>i)&0x01));

	TestCodeTearDown();
}


void setInputOp_D2BWZ
(uint8 in, uint16 in_pos, int in_val, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val, int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, in, in_pos+idx_val, in_val);

	TestCodeTearDown();
}

void test_F2BWord(int tno, uint16 ml_cmd, int on_off, uint8 in, uint16 in_pos, float in_val, uint8 out, uint16 out_pos, int expected)
{
	int rc1=0, rc2=0;
	int run_time=1;

	PLC_DEVICE_Init();

	rc2 = setCodeOp2_F2BWD(ml_cmd, in, in_pos, out, out_pos);
	if( rc2 == 0 ) return;

	setInputOp_F2B(on_off, in, in_pos, in_val, out, out_pos);

	rc1=runTestCode(run_time, "runtime error test");
	if(rc1==1)
	{
		rc2=verifyErrorRegister(expected);
		if(rc2==1)
		{
			printf("tno=%d cmd=%s exp=%d\n", \
				tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName, expected);
		}
	}
	else
	{
		CU_ASSERT_TRUE(rc1);
		printf(" tno=%d cmd=%s Runtime error should occur !! \n",
			tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName);
	}
}

void test_F2B_NB(int tno, uint16 ml_cmd, int on_off, uint8 in, uint16 in_pos, float in_val, uint8 out, uint16 out_pos, int expected)
{
	int rc1=0, rc2=0;
	int run_time=1;

	PLC_DEVICE_Init();

	rc2 = setCodeOp2_F2BNB(ml_cmd, in, in_pos, out, out_pos);
	if( rc2 == 0 ) return;

	setInputOp_F2B(on_off, in, in_pos, in_val, out, out_pos);

	rc1=runTestCode(run_time, "runtime error test");
	if(rc1==1)
	{
		rc2=verifyErrorRegister(expected);
		if(rc2==1)
		{
			printf("tno=%d cmd=%s exp=%d\n", \
				tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName, expected);
		}
	}
	else
	{
		CU_ASSERT_TRUE(rc1);
		printf(" tno=%d cmd=%s Runtime error should occur !! \n",
			tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName);
	}
}

void test_F2B_WZ
(int tno, uint16 ml_cmd, int on_off, uint8 in, uint16 in_pos, float in_val,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val, int expected)
{
	int rc1=0, rc2=0;
	int run_time=1;

	PLC_DEVICE_Init();

	rc2 = setCodeOp2_F2BWZ(ml_cmd, in, in_pos, out, out_pos, idx_pos);
	if( rc2 == 0 ) return;

	setInputOp_F2BWZ(on_off, in, in_pos, in_val, out, out_pos, idx_pos, idx_val);

	rc1=runTestCode(run_time, "runtime error test");
	if(rc1==1)
	{
		rc2=verifyErrorRegister(expected);
		if(rc2==1)
		{
			printf("tno=%d cmd=%s exp=%d\n", \
				tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName, expected);
		}
	}
	else
	{
		CU_ASSERT_TRUE(rc1);
		printf(" tno=%d cmd=%s Runtime error should occur !! \n",
			tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName);
	}
}

void test_F2D_NB(int tno, uint16 ml_cmd, int on_off, uint8 in, uint16 in_pos, float in_val, uint8 out, uint16 out_pos, int expected)
{
	int rc1=0, rc2=0;
	int run_time=1;

	PLC_DEVICE_Init();

	rc2 = setCodeOp2_F2DNB(ml_cmd, in, in_pos, out, out_pos);
	if( rc2 == 0 ) return;

	setInputOp_F2B(on_off, in, in_pos, in_val, out, out_pos);

	rc1=runTestCode(run_time, "runtime error test");
	if(rc1==1)
	{
		rc2=verifyErrorRegister(expected);
		if(rc2==1)
		{
			printf("tno=%d cmd=%s exp=%d\n", \
				tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName, expected);
		}
	}
	else
	{
		CU_ASSERT_TRUE(rc1);
		printf(" tno=%d cmd=%s Runtime error should occur !! \n",
			tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName);
	}
}

void test_D2B_WD
(int tno, uint16 ml_cmd, int on_off, uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int expected)
{
	int rc1=0, rc2=0;
	int run_time=1;

	PLC_DEVICE_Init();

	rc2 = setCodeOp2_F2BWD(ml_cmd, in, in_pos, out, out_pos);
	if( rc2 == 0 ) return;

	setInputOp_D2B(on_off, in, in_pos, in_val, out, out_pos);

	rc1=runTestCode(run_time, "runtime error test");
	if(rc1==1)
	{
		rc2=verifyErrorRegister(expected);
		if(rc2==1)
		{
			printf("tno=%d cmd=%s exp=%d\n", \
				tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName, expected);
		}
	}
	else
	{
		CU_ASSERT_TRUE(rc1);
		printf(" tno=%d cmd=%s Runtime error should occur !! \n",
			tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName);
	}
}

void test_D2B_NB
(int tno, uint16 ml_cmd, int on_off, uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int expected)
{
	int rc1=0, rc2=0;
	int run_time=1;

	PLC_DEVICE_Init();

	rc2 = setCodeOp2_D2BNB(ml_cmd, in, in_pos, out, out_pos);
	if( rc2 == 0 ) return;

	setInputOp_D2BNB(on_off, in, in_pos, in_val, out, out_pos);

	rc1=runTestCode(run_time, "runtime error test");
	if(rc1==1)
	{
		rc2=verifyErrorRegister(expected);
		if(rc2==1)
		{
			printf("tno=%d cmd=%s exp=%d\n", \
				tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName, expected);
		}
	}
	else
	{
		CU_ASSERT_TRUE(rc1);
		printf(" tno=%d cmd=%s Runtime error should occur !! \n",
			tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName);
	}
}

void test_D2B_WZ
(int tno, uint16 ml_cmd, int on_off, uint8 in, uint16 in_pos, float in_val,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val, int expected)
{
	int rc1=0, rc2=0;
	int run_time=1;

	PLC_DEVICE_Init();

	rc2 = setCodeOp2_F2BWZ(ml_cmd, in, in_pos, out, out_pos, idx_pos);
	if( rc2 == 0 ) return;

	setInputOp_D2BWZ(on_off, in, in_pos, in_val, out, out_pos, idx_pos, idx_val);

	rc1=runTestCode(run_time, "runtime error test");
	if(rc1==1)
	{
		rc2=verifyErrorRegister(expected);
		if(rc2==1)
		{
			printf("tno=%d cmd=%s exp=%d\n", \
				tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName, expected);
		}
	}
	else
	{
		CU_ASSERT_TRUE(rc1);
		printf(" tno=%d cmd=%s Runtime error should occur !! \n",
			tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_cmd)->strName);
	}
}

void testRuntimeErrorExtra(void)
{
#if 0
	test_F2B_WZ(15, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, 500.0f, \
		OPERAND_ML_CODE_D, 500, 16, 100, RUNTIME_ERR_DEVICE_RANGE_OVER);
#else
	test_F2BWord(0, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, 32768.0f, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2BWord(1, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, -32769.0f, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2BWord(2, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, INFINITY, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2BWord(3, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, NAN, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2BWord(4, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, FLT_MIN/2.0f, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_NB(5, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, 32768.0f, \
		OPERAND_ML_CODE_X, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2B_NB(6, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, -32769.0f, \
		OPERAND_ML_CODE_X, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2B_NB(7, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, INFINITY, \
		OPERAND_ML_CODE_X, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_NB(8, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, NAN, \
		OPERAND_ML_CODE_X, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_NB(9, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, FLT_MIN/2.0f, \
		OPERAND_ML_CODE_X, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_WZ(10, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, 32768.0f, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2B_WZ(11, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, -32769.0f, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2B_WZ(12, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, INFINITY, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_WZ(13, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, NAN, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_WZ(14, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, FLT_MIN/2.0f, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_WZ(15, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, 500.0f, \
		OPERAND_ML_CODE_D, 500, 16, 100, RUNTIME_ERR_DEVICE_RANGE_OVER);
	test_F2B_WZ(16, ML_CODE_FTOB, 1, OPERAND_ML_CODE_D, 100, 500.0f, \
		OPERAND_ML_CODE_D, 500, 5, 12000, RUNTIME_ERR_DEVICE_RANGE_OVER);

	test_F2BWord(17, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, 2147490000.0f, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2BWord(18, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, -2147490000.0f, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2BWord(19, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, INFINITY, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2BWord(20, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, NAN, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2BWord(21, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, FLT_MIN/2.0f, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2D_NB(22, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, 2147490000.0f, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2D_NB(23, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, -2147490000.0f, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2D_NB(24, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, INFINITY, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2D_NB(25, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, NAN, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2D_NB(26, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, FLT_MIN/2.0f, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_WZ(27, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, 2147490000.0f, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2B_WZ(28, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, -2147490000.0f, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_F2B_WZ(29, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, INFINITY, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_WZ(30, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, NAN, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_WZ(31, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, FLT_MIN/2.0f, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INVALID_FLOAT);
	test_F2B_WZ(32, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, 500.0f, \
		OPERAND_ML_CODE_D, 500, 16, 100, RUNTIME_ERR_DEVICE_RANGE_OVER);
	test_F2B_WZ(33, ML_CODE_FTOD, 1, OPERAND_ML_CODE_D, 100, 500.0f, \
		OPERAND_ML_CODE_D, 500, 5, 12000, RUNTIME_ERR_DEVICE_RANGE_OVER);

	test_D2B_WD(34, ML_CODE_DTOB, 1, OPERAND_ML_CODE_D, 100, 32768, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_D2B_WD(35, ML_CODE_DTOB, 1, OPERAND_ML_CODE_D, 100, -32769, \
		OPERAND_ML_CODE_D, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_D2B_NB(36, ML_CODE_DTOB, 1, OPERAND_ML_CODE_X, 100, 32768, \
		OPERAND_ML_CODE_X, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_D2B_NB(37, ML_CODE_DTOB, 1, OPERAND_ML_CODE_X, 100, -32769, \
		OPERAND_ML_CODE_X, 500, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_D2B_WZ(38, ML_CODE_DTOB, 1, OPERAND_ML_CODE_D, 100, 32768, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_D2B_WZ(39, ML_CODE_DTOB, 1, OPERAND_ML_CODE_D, 100, -32769, \
		OPERAND_ML_CODE_D, 500, 5, 100, RUNTIME_ERR_INTEGER_RANGE_OVER);
	test_D2B_WZ(40, ML_CODE_DTOB, 1, OPERAND_ML_CODE_D, 100, 500, \
		OPERAND_ML_CODE_D, 500, 16, 100, RUNTIME_ERR_DEVICE_RANGE_OVER);
	test_D2B_WZ(41, ML_CODE_DTOB, 1, OPERAND_ML_CODE_D, 100, 500, \
		OPERAND_ML_CODE_D, 500, 5, 12000, RUNTIME_ERR_DEVICE_RANGE_OVER);

#endif

}

#endif
