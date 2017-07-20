/*
 * test_basic_arithmatic_extra.c
 *
 *  Created on: Apr 23, 2015
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

extern void setInputSIn_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

int setCodeStringAdd(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeStringAdd_K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeStrAdd3_2In(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeStrAddOp3_2Out(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeStrAdd3_K2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeStrAdd3_K1(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeStrAdd3_2K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputDIn_Str_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Str_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Strp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Str_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Str_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Strp_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_Str_2In_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Str_2In_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Strp_2In_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Str_2Out_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Str_2Out_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Strp_2Out_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Str_K2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Str_K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Strp_K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Str_K1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Str_K1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Strp_K1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

int verifyResultStringAdd(int tcase, uint8 dest_reg, uint16 pos, char *expected);

static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, char *);
	char str[40];
	//int count;
	int run_step;
	char *expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_STRADD, setCodeStringAdd, setInputDIn_Str_off, verifyResultStringAdd,
			"STRADD off op1+op2", 1, "ABCDE"},
	{1, ML_CODE_STRADD, setCodeStringAdd, setInputDIn_Str_on, verifyResultStringAdd,
			"STRADD on op1+op2", 1, "ABCDE123456"},
	{2, ML_CODE_STRADD, setCodeStringAdd_K, setInputSIn_Str_K_off, verifyResultStringAdd,
			"STRADD off K+op2", 1, "ABCDE"},
	{3, ML_CODE_STRADD, setCodeStringAdd_K, setInputSIn_Str_K_on, verifyResultStringAdd,
			"STRADD on K+op2", 1, "ABCDE123456"},

	{4, ML_CODE_STRADDP, setCodeStringAdd, setInputDIn_Str_off, verifyResultStringAdd,
			"STRADDP 0->0 op1+op2", 2, "ABCDE"},
	{5, ML_CODE_STRADDP, setCodeStringAdd, setInputDIn_Str_on, verifyResultStringAdd,
			"STRADDP 1->1 op1+op2", 2, "ABCDE"},
	{6, ML_CODE_STRADDP, setCodeStringAdd, setInputDIn_Strp_on, verifyResultStringAdd,
			"STRADDP 0->1 op1+op2", 2, "ABCDE123456"},
	{7, ML_CODE_STRADDP, setCodeStringAdd_K, setInputSIn_Str_K_off, verifyResultStringAdd,
			"STRADDP 0->0 K+op2", 2, "ABCDE"},
	{8, ML_CODE_STRADDP, setCodeStringAdd_K, setInputSIn_Str_K_on, verifyResultStringAdd,
			"STRADDP 1->1 K+op2", 2, "ABCDE"},
	{9, ML_CODE_STRADDP, setCodeStringAdd_K, setInputSIn_Strp_K_on, verifyResultStringAdd,
			"STRADDP 0->1 K+op2", 2, "ABCDE123456"},

	{10, ML_CODE_STRADDS, setCodeStrAdd3_2In, setInputDIn_Str_2In_off, verifyResultStringAdd,
			"STRADDS off op3=op1+op2", 1, ""},
	{11, ML_CODE_STRADDS, setCodeStrAdd3_2In, setInputDIn_Str_2In_on, verifyResultStringAdd,
			"STRADDS on op3=op1+op2", 1, "123456ABCDE"},
	{12, ML_CODE_STRADDS, setCodeStrAddOp3_2Out, setInputDIn_Str_2Out_off, verifyResultStringAdd,
			"STRADDS off op3=op1+op2", 1, ""},
	{13, ML_CODE_STRADDS, setCodeStrAddOp3_2Out, setInputDIn_Str_2Out_on, verifyResultStringAdd,
			"STRADDS on op3=op1+op2", 1, "123456ABCDE"},
	{14, ML_CODE_STRADDS, setCodeStrAdd3_K2, setInputSIn_Str_K2_off, verifyResultStringAdd,
			"STRADDS off op3=op1+op2", 1, ""},
	{15, ML_CODE_STRADDS, setCodeStrAdd3_K2, setInputSIn_Str_K2_on, verifyResultStringAdd,
			"STRADDS on op3=op1+op2", 1, "ABCDE123456"},
	{16, ML_CODE_STRADDS, setCodeStrAdd3_K1, setInputSIn_Str_K1_off, verifyResultStringAdd,
			"STRADDS off op3=op1+op2", 1, ""},
	{17, ML_CODE_STRADDS, setCodeStrAdd3_K1, setInputSIn_Str_K1_on, verifyResultStringAdd,
			"STRADDS on op3=op1+op2", 1, "ABCDE123456"},
	{18, ML_CODE_STRADDS, setCodeStrAdd3_2K, setInputSIn_none_off, verifyResultStringAdd,
			"STRADDS off op3=op1+op2", 1, ""},
	{19, ML_CODE_STRADDS, setCodeStrAdd3_2K, setInputSIn_none_on, verifyResultStringAdd,
			"STRADDS on op3=op1+op2", 1, "ABCDE123456"},

	{20, ML_CODE_STRADDPS, setCodeStrAdd3_2In, setInputDIn_Str_2In_off, verifyResultStringAdd,
			"STRADDPS 0->0 op3=op1+op2", 2, ""},
	{21, ML_CODE_STRADDPS, setCodeStrAdd3_2In, setInputDIn_Strp_2In_on, verifyResultStringAdd,
			"STRADDPS 0->1 op3=op1+op2", 2, "123456ABCDE"},
	{22, ML_CODE_STRADDPS, setCodeStrAddOp3_2Out, setInputDIn_Str_2Out_off, verifyResultStringAdd,
			"STRADDPS 0->0 op3=op1+op2", 2, ""},
	{23, ML_CODE_STRADDPS, setCodeStrAddOp3_2Out, setInputDIn_Strp_2Out_on, verifyResultStringAdd,
			"STRADDPS 0->1 op3=op1+op2", 2, "123456ABCDE"},
	{24, ML_CODE_STRADDPS, setCodeStrAdd3_K2, setInputSIn_Str_K2_off, verifyResultStringAdd,
			"STRADDPS 0->0 op3=op1+op2", 2, ""},
	{25, ML_CODE_STRADDPS, setCodeStrAdd3_K2, setInputSIn_Strp_K2_on, verifyResultStringAdd,
			"STRADDPS 0->1 op3=op1+op2", 2, "ABCDE123456"},
	{26, ML_CODE_STRADDPS, setCodeStrAdd3_K1, setInputSIn_Str_K1_off, verifyResultStringAdd,
			"STRADDPS 0->0 op3=op1+op2", 2, ""},
	{27, ML_CODE_STRADDPS, setCodeStrAdd3_K1, setInputSIn_Strp_K1_on, verifyResultStringAdd,
			"STRADDPS 0->1 op3=op1+op2", 2, "ABCDE123456"},
	{28, ML_CODE_STRADDPS, setCodeStrAdd3_2K, setInputSIn_none_off, verifyResultStringAdd,
			"STRADDPS 0->0 op3=op1+op2", 2, ""},
	{29, ML_CODE_STRADDPS, setCodeStrAdd3_2K, setInputSIn_none_tr1, verifyResultStringAdd,
			"STRADDPS 0->1 op3=op1+op2", 2, "ABCDE123456"},

	{-1, 0xFFFF, NULL, NULL, NULL, " ", 0, 0 },
};

int total_basic_arithmetic_str_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_arithmetic_str_test_number; i++)
	{
		if(testCase[i].ml_code == ml_code )
			return i;
	}
	DBG_LOGPRINT("[FATAL error %d command not found\n", ml_code);
	return -1;
}

static int getTestCaseNumberEnd(uint16 ml_code)
{
	int i, start=0, count=0;

	start = getTestCaseNumber(ml_code);
	if(start == -1 )
	{
		DBG_LOGPRINT("[FATAL] error %d command not found\n", ml_code);
		return -1;
	}

	i=start;
	while(testCase[i++].ml_code == ml_code )
	{
		count++;
	}

	//DBG_LOGPRINT("getTestCaseNumberEnd: end %d\n", start+count-1);
	return start+count-1;
}

int setCodeStringAdd(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeStringAdd_K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addConstantStringoperand("123456"); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeStrAdd3_2In(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 50);
	     addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeStrAddOp3_2Out(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(out_reg, 50);
	     addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeStrAdd3_K2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addConstantStringoperand("123456");
	     addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeStrAdd3_K1(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addConstantStringoperand("ABCDE"); addMLOperand(in_reg, in_pos);
	     addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeStrAdd3_2K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addConstantStringoperand("ABCDE"); addConstantStringoperand("123456");
	     addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputDIn_Str_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");
	addDeviceControlInstructionToString(0, (uint8)out, out_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_Str_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");
	addDeviceControlInstructionToString(0, (uint8)out, out_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_Strp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");
	addDeviceControlInstructionToString(0, (uint8)out, out_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_Str_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToString(0, (uint8)out, out_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_Str_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)out, out_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_Strp_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)out, out_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_Str_2In_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_Str_2In_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_Strp_2In_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_Str_2Out_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");
	addDeviceControlInstructionToString(0, (uint8)out, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_Str_2Out_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");
	addDeviceControlInstructionToString(0, (uint8)out, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_Strp_2Out_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");
	addDeviceControlInstructionToString(0, (uint8)out, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_Str_K2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_Str_K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_Strp_K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_Str_K1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");

	TestCodeTearDown();
}

void setInputSIn_Str_K1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");

	TestCodeTearDown();
}

void setInputSIn_Strp_K1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "123456");

	TestCodeTearDown();
}

int verifyResultStringAdd(int tcase, uint8 dest_reg, uint16 pos, char *expected)
{
	int rc=0;
	char *result;
	char reg[] = {'D', 'W'};

	//result = PLC_Register_getString(dest_reg, pos);
	result = (char *)PLC_Register_getPos(dest_reg, pos, TYPE_STRING);
	if( show_log ) DBG_LOGPRINT("test=%d Reg %c[%d]=%s %s\n", tcase, reg[dest_reg-OPERAND_ML_CODE_D], pos, result, expected);
	CU_ASSERT_STRING_EQUAL(result, expected);
	if(strcmp(result, expected)) rc=1;

	return rc;
}

static uint16 getPosStr(int reg, int inx_pos)
{
	uint16 pos[3][2]={ {0,0}, {6144,4096}, {12275,8179}}; // -12

	return pos[inx_pos][reg];
}

static FILE *flog;

void test_basic_arithmetic_str(int tno, int dummy)
{
	int i, ml_rc, rc=0, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	char *res_str;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getPosStr(out-OPERAND_ML_CODE_D, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPosStr(in-OPERAND_ML_CODE_D, i);

					/*
					if(in == out && in_pos == out_pos)
					{
						continue;
					}*/

					ml_rc = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if(ml_rc==0) continue;
					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

					rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! in_%s[%d] out_%s[%d]\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
							reg[in], in_pos, reg[out], out_pos);
					}
					else
					{
						rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
						if(rc == 1)
						{
							res_str = (char *)PLC_Register_getPos(out, out_pos, TYPE_STRING);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%s exp=%s \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_str, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testBasicArithmeticStringCommand(void)
{
	int i, index=10;
	int start, end;
	char log[] = "err_arith_str.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic string LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0;index<5;index++)
	test_basic_arithmetic_str(index, 0);
#else
	total_basic_arithmetic_str_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_STRADD);
	end = getTestCaseNumberEnd(ML_CODE_STRADDPS); //ML_CODE_STRADDPS

	DBG_LOGPRINT("testBasicArithmeticStringCommand: %d to %d total %d\n", start, end, total_basic_arithmetic_str_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_str(index, 0);
	}
#endif
	fclose(flog);
}

#endif
