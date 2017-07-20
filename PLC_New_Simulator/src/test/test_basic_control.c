/*
 * test_basic_control.c
 *
 *  Created on: Sep 8, 2015
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

extern void TestCodeInit(void);
extern void TestCodeTearDown(void);
extern int runTestCode(int run_step, char *testFuncName);

uint16 Label0=10;


void setCodeCtl_JMP(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, Label0);
	addMLOperator(ML_CODE_LD); addMLOperand(in, in_pos);
	addMLOperator(ML_CODE_INC); addMLOperand(out, out_pos);
	addMLPointLabel(Label0);
	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_DEC); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeCtl_xCJ(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, Label0);
	addMLOperator(ML_CODE_LD); addMLOperand(in, in_pos);
	addMLOperator(ML_CODE_INC); addMLOperand(out, out_pos);
	addMLPointLabel(Label0);
	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_DEC); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeCtl_GOEND(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
	addMLOperator(ML_CODE_LD); addMLOperand(in, in_pos);
	addMLOperator(ML_CODE_INC); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);
}

void setInputCtl_T1(uint8 in, uint16 in_pos, int in_val, uint8 out, uint16 out_pos, int out_val, int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0, 0,0,0},
			{4096,4096,4096,4096,1024,4096, 0,6144,4096},
			{8191,8191,8191,8191,2047,8191, 0,12287,8191}};

	return pos[inx_pos][reg];
}

static FILE *flog;

void test_JMP(int tno, uint16 ml_code, int on_off, int run_step, int in_val, int out_val, short expected)
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D;
	uint16 in_pos=200, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};
	int rc, olast=0;
	//short expected=256;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			PLC_DEVICE_Init();

			out_pos = getPos(out, olast);

			setCodeCtl_JMP(ml_code, in, in_pos, out, out_pos);
			setInputCtl_T1(in, in_pos, in_val, out, out_pos, out_val, on_off);

			rc = runTestCode(run_step, "JMP test");
			if(rc == 1)
			{
				fprintf(flog, "test case %d runtime error cmd=%s out_%c[%d]\n", \
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, reg[out], out_pos);
			}
			else
			{
				rc = verifyResultValueWord(tno, out, out_pos, expected);
				if(rc == 1)
				{
					fprintf(flog, "test case %d error cmd=%s out_%c[%d]\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, reg[out], out_pos);
				}
			}

		}
	}

}

void test_xCJ(int tno, uint16 ml_code, int on_off, int run_step, int in_val, int out_val, short expected)
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D;
	uint16 in_pos=200, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};
	int rc, olast=0;
	//short expected=256;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			PLC_DEVICE_Init();

			out_pos = getPos(out, olast);

			setCodeCtl_xCJ(ml_code, in, in_pos, out, out_pos);
			setInputCtl_T1(in, in_pos, in_val, out, out_pos, out_val, on_off);

			rc = runTestCode(run_step, "xCJ test");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test case %d runtime error cmd=%s out_%c[%d]\n", \
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, reg[out], out_pos);
			}
			else
			{
				rc = verifyResultValueWord(tno, out, out_pos, expected);
				if(rc == 1)
				{
					fprintf(flog, "test case %d error cmd=%s,  out_%c[%d]\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, reg[out], out_pos);
				}
			}

		}
	}

}

void test_GOEND(int tno, uint16 ml_code, int on_off, int run_step, int in_val, int out_val, short expected)
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D;
	uint16 in_pos=200, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};
	int rc, olast=0;
	//short expected=256;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			PLC_DEVICE_Init();

			out_pos = getPos(out, olast);

			setCodeCtl_GOEND(ml_code, in, in_pos, out, out_pos);
			setInputCtl_T1(in, in_pos, in_val, out, out_pos, out_val, on_off);

			rc = runTestCode(run_step, "GOEND test");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test case %d runtime error cmd=%s out_%c[%d]\n", \
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, reg[out], out_pos);
			}
			else
			{
				rc = verifyResultValueWord(tno, out, out_pos, expected);
				if(rc == 1)
				{
					fprintf(flog, "test case %d error cmd=%s out_%c[%d]\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, reg[out], out_pos);
				}
			}

		}
	}

}

void testControlCommand(void)
{
	int i;
	char log[] = "err_ctrl.txt";
	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("control LOG file open error !\n");
		exit(1);
	}

#if 0
	test_GOEND(16, ML_CODE_GOEND, 1, 1, 1, 10, 10);
#else
	test_JMP(0, ML_CODE_JMP, 0, 1, 1, 10, 10);
	test_JMP(1, ML_CODE_JMP, 1, 1, 1, 10, 9);

	test_xCJ(2, ML_CODE_CJ, 0, 1, 0, 10, 10);
	test_xCJ(3, ML_CODE_CJ, 0, 1, 1, 10, 11);
	test_xCJ(4, ML_CODE_CJ, 1, 1, 0, 10, 9);
	test_xCJ(5, ML_CODE_CJ, 1, 1, 1, 10, 9);

	test_xCJ(6, ML_CODE_SCJ, 0, 2, 0, 10, 10);
	test_xCJ(7, ML_CODE_SCJ, 0, 2, 1, 10, 12);
	test_xCJ(8, ML_CODE_SCJ, 1, 2, 0, 10, 8);
	test_xCJ(9, ML_CODE_SCJ, 1, 2, 1, 10, 10);
	test_xCJ(10, ML_CODE_SCJ, 2, 2, 0, 10, 9);
	test_xCJ(11, ML_CODE_SCJ, 2, 2, 1, 10, 10);

	test_GOEND(12, ML_CODE_GOEND, 0, 1, 0, 10, 10);
	test_GOEND(13, ML_CODE_GOEND, 0, 1, 1, 10, 11);
	test_GOEND(14, ML_CODE_GOEND, 1, 1, 0, 10, 10);
	test_GOEND(15, ML_CODE_GOEND, 1, 1, 1, 10, 10);
#endif


	fclose(flog);
}

#endif
