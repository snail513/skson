/*
 * test_basic_transfer_extra.c
 *
 *  Created on: Aug 19, 2015
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

extern int verifyResultValueWord(int tcase, uint8 dest_reg, uint16 pos, short expected);
extern int verifyResultValueNibble4(int tcase, uint8 dest_reg, uint16 pos, short expected);
extern int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected);
extern int verifyResultValueFloat(int tcase, uint8 dest_reg, uint16 pos, float expected);

typedef struct
{
	uint16	pos;
	short 	val;
} test_pos_st;

static test_pos_st testidx[] = {
	{ 0, 0},
	{ 0, 256},
	{ 0, 1024},
	{ 0, -255},
	{ 0, -1024},
	{ 7, 0},
	{ 7, 256},
	{ 7, 1024},
	{ 7, -255},
	{ 7, -1024},
	{ 15, 0},
	{ 15, 256},
	{ 15, 1024},
	{ 15, -256},
	{ 15, -1024},
};

static FILE *flog;

static int show_log=1;

static int isIdxRangeOver(uint8 in, uint16 in_pos, short idx_val)
{
	uint16 lastIndex[2]={12287, 8191};

	if(in < OPERAND_ML_CODE_D) return 1;

	if(in_pos+idx_val < 0 || in_pos+idx_val > lastIndex[in-OPERAND_ML_CODE_D]) return 1;

	return 0;
}


int setCodeOp2_Ex_W1W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;

	if(in == out && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_N1W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in > OPERAND_ML_CODE_B) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, in_pos); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_Idx1W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(isIdxRangeOver(in, in_pos, idx_val)) return 0;
	if(in == out && in_pos+idx_val == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


int setCodeOp2_Ex_W1N2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandNibble(4, out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_N1N2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in > OPERAND_ML_CODE_B) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	if(in == out && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, in_pos); addMLOperandNibble(4, out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_Idx1N2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;
	if(isIdxRangeOver(in, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperandNibble(4, out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_W1Idx2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(isIdxRangeOver(out, out_pos, idx_val)) return 0;
	if(in == out && in_pos == out_pos+idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_N1Idx2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if(in > OPERAND_ML_CODE_B) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;
	if(isIdxRangeOver(out, out_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, in_pos); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_Idx1Idx2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,	uint16 idx_pos, uint16 idx_val)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(isIdxRangeOver(in, in_pos, idx_val)) return 0;
	if(isIdxRangeOver(out, out_pos, idx_val)) return 0;
	if(in == out && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_N1DW2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in > OPERAND_ML_CODE_B) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in, in_pos); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_DW1N2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandNibble(8, out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_DN1DN2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in > OPERAND_ML_CODE_B) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	if(in == out && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in, in_pos); addMLOperandNibble(8, out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_Idx1DN2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;
	if(isIdxRangeOver(in, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperandNibble(8, out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_Ex_DN1Idx2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if(in > OPERAND_ML_CODE_B) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;
	if(isIdxRangeOver(out, out_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in, in_pos); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp2_None(int on_off)
{
	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	TestCodeTearDown();
}

/**************** SWAP, SWAPP **********************/

int setCodeOp1_SWAP_W(uint16 ml_cmd, uint8 in, uint16 pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp1_SWAP_N(uint16 ml_cmd, uint8 in, uint16 pos)
{
	if( in > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp1_SWAP_Idx(uint16 ml_cmd, uint8 in, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in < OPERAND_ML_CODE_D ) return 0;
	if(isIdxRangeOver(in, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp1_SWAP_W(uint8 in, uint16 in_pos, int on_off)
{
	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x55AA);

	TestCodeTearDown();
}

void setInputOp1_SWAP_N(uint8 in, uint16 in_pos, int on_off)
{
	int i;
	uint16 value=0x55AA;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp1_SWAP_Idx(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, 0x55AA);

	TestCodeTearDown();
}

static uint16 getWordPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0, 6144,4096},
			{8176,8176,8176,8176,2032,8176,0, 12287,8191}};

	return pos[inx_pos][reg];
}


/**************** $MOV, $MOVP **********************/

int setCodeOp2_Ex_K1W2(uint16 ml_cmd, uint8 out, uint16 out_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addConstantStringoperand("ABCDE"); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp2_Str_W1(uint8 in, uint16 in_pos, int on_off)
{
	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");

	TestCodeTearDown();
}

int verifyResultStringEx(int tcase, uint8 dest_reg, uint16 pos, char *expected)
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

static uint16 getWordStrPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0, 6144,4096},
			{8176,8176,8176,8176,2032,8176,0, 12282,8186}};

	return pos[inx_pos][reg];
}

/**************** EMOV, EMOVP **********************/

int setCodeOp2_Ex_E1_W2(uint16 ml_cmd, uint8 out, uint16 out_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 4.23542); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


int setCodeOp2_Ex_E1_Idx2(uint16 ml_cmd, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if(out < OPERAND_ML_CODE_D) return 0;
	if(isIdxRangeOver(out, out_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 4.23542);
		addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp2_EW1_EW2(uint8 in, uint16 in_pos, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 4.23542);

	TestCodeTearDown();
}

void setInputOp2_Idx1_EW2(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 4.23542);

	TestCodeTearDown();
}

void setInputOp2_EW1_Idx2(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 4.23542);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputOp2_E1_Idx2(uint16 idx_pos, uint16 idx_val, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputOp2_Idx1_Idx2(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 4.23542);

	TestCodeTearDown();
}

static uint16 getDWordPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; //32bit

	return pos[inx_pos][reg];
}

/**************** XCH, XCHP **********************/

void setInputOp2_W1W2_all
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint16 out_val, int on_off)
{
	if(on_off == 2)
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

void setInputOp2_N1W2_all
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint16 out_val, int on_off)
{
	int i;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_Idx1W2_all
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint16 out_val,
 uint8 idx_pos, uint16 idx_val, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_W1N2_all
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint16 out_val, int on_off)
{
	int i;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_N1N2_all
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint16 out_val, int on_off)
{
	int i;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Idx1N2_all
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint16 out_val,
 uint16 idx_pos, uint16 idx_val, int on_off)
{
	int i;
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_W1Idx2_all
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint16 out_val,
 uint8 idx_pos, uint16 idx_val, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_N1Idx2_all
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint16 out_val,
 uint8 idx_pos, uint16 idx_val, int on_off)
{
	int i;
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_Idx1Idx2_all
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint16 out_val,
 uint8 idx_pos, uint16 idx_val, int on_off)
{
	int i;
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_DW1DW2_all
(uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int out_val, int on_off)
{
	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_N1DW2_all
(uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int out_val, int on_off)
{
	int i;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_Idx1DW2_all
(uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int out_val,
 uint8 idx_pos, uint16 idx_val, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_DW1N2_all
(uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int out_val, int on_off)
{
	int i;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_DN1DN2_all
(uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int out_val, int on_off)
{
	int i;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Idx1DN2_all
(uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int out_val,
 uint16 idx_pos, uint16 idx_val, int on_off)
{
	int i;
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_DW1Idx2_all
(uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int out_val,
 uint8 idx_pos, uint16 idx_val, int on_off)
{
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_DN1Idx2_all
(uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int out_val,
 uint8 idx_pos, uint16 idx_val, int on_off)
{
	int i;
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_DIdx1DIdx2_all
(uint8 in, uint16 in_pos, int in_val,
 uint8 out, uint16 out_pos, int out_val,
 uint8 idx_pos, uint16 idx_val, int on_off)
{
	int i;
	short z_val;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}


void test_trans_Op1_W(int tno, uint16 ml_code, uint16 on_off, int run_step, short expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getWordPos(in, i);
			ml_rc = setCodeOp1_SWAP_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInputOp1_SWAP_W(in, in_pos, on_off);

			rc = runTestCode(run_step, "transfer SWAP word ");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueWord(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getWord(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_trans_Op1_N(int tno, uint16 ml_code, uint16 on_off, int run_step, short expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;
	long long res_nword;

	for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getWordPos(in, i);
			ml_rc = setCodeOp1_SWAP_N(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInputOp1_SWAP_N(in, in_pos, on_off);

			rc = runTestCode(run_step, "transfer SWAP Nibble ");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueNibble4(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getNibble(&res_word, in, in_pos, 4);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_trans_Op1_Idx(int tno, uint16 ml_code, uint16 on_off, int run_step, short expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getWordPos(in, i);
				ml_rc = setCodeOp1_SWAP_Idx(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInputOp1_SWAP_Idx(in, in_pos, testidx[inx].pos, testidx[inx].val, on_off);

				//DBG_LOGPRINT("PASS in=%d in_pos=%d idx_val=%d\n", in, in_pos, testidx[inx].val);
				rc = runTestCode(run_step, "transfer SWAP index ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueWord(tno, in, in_pos+testidx[inx].val, expected);
					if(rc2 == 1)
					{
						test_getWord(&res_word, in, in_pos+testidx[inx].val);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%d exp=%d\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, testidx[inx].val, res_word, expected);
					}
				}
			}
		}
	}
}

void test_trans_STRMOV_W(int tno, uint16 ml_code, uint16 on_off, int run_step, char *expected)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	char *res_str;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordStrPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordStrPos(in, i);
					ml_rc = setCodeOp2_Ex_W1W2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_Str_W1(in, in_pos, on_off);

					rc = runTestCode(run_step, "transfer $MOV word ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultStringEx(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							res_str = (char *)PLC_Register_getPos(out, out_pos, TYPE_STRING);
							fprintf(flog, "test case %d error cmd=%s %s[%d]=%s exp=%s\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos, res_str, expected);
						}
					}
				}
			}
		}
	}
}

void test_trans_STRMOV_Overlap(int tno, uint16 ml_code, uint16 on_off, int run_step, char *expected)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	char *res_str;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			// set out_pos overlap with in_pos
			out=in;
			in_pos = getWordStrPos(in, i);
			if(in_pos==0)
				out_pos=1;
			else
				out_pos=in_pos-1;

			ml_rc = setCodeOp2_Ex_W1W2(ml_code, in, in_pos, out, out_pos);
			if(ml_rc == 0) continue;

			setInputOp2_Str_W1(in, in_pos, on_off);

			rc = runTestCode(run_step, "transfer $MOV overlap ");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultStringEx(tno, out, out_pos, expected);
				if(rc2 == 1)
				{
					res_str = (char *)PLC_Register_getPos(out, out_pos, TYPE_STRING);
					fprintf(flog, "test case %d error cmd=%s overlap %s[%d]=%s exp=%s\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[out], out_pos, res_str, expected);
				}
			}
		}
	}
}

void test_trans_STRMOV_K(int tno, uint16 ml_code, uint16 on_off, int run_step, char *expected)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	char *res_str;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordStrPos(out, olast);

			PLC_DEVICE_Init();

			ml_rc = setCodeOp2_Ex_K1W2(ml_code, out, out_pos);
			if(ml_rc == 0) continue;

			setInputOp2_None(on_off);

			rc = runTestCode(run_step, "transfer $MOV $->W ");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultStringEx(tno, out, out_pos, expected);
				if(rc2 == 1)
				{
					res_str = (char *)PLC_Register_getPos(out, out_pos, TYPE_STRING);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%s exp=%s\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[out], out_pos, res_str, expected);
				}
			}
		}
	}
}

void test_trans_EMOV_W1W2(int tno, uint16 ml_code, uint16 on_off, int run_step, float expected)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_float;

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getDWordPos(in, i);
					ml_rc = setCodeOp2_Ex_W1W2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_EW1_EW2(in, in_pos, on_off);

					rc = runTestCode(run_step, "transfer EMOV W->W ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueFloat(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							test_getFloat(&res_float, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%f exp=%f \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_float, expected);
						}
					}
				}
			}
		}
	}
}

void test_trans_EMOV_E1W2(int tno, uint16 ml_code, uint16 on_off, int run_step, float expected)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_float;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);

			PLC_DEVICE_Init();

			ml_rc = setCodeOp2_Ex_E1_W2(ml_code, out, out_pos);
			if(ml_rc == 0) continue;

			setInputOp2_None(on_off);

			rc = runTestCode(run_step, "transfer EMOV E->W ");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueFloat(tno, out, out_pos, expected);
				if(rc2 == 1)
				{
					test_getFloat(&res_float, out, out_pos);
					fprintf(flog, "test case %d error cmd=%s E out_%s[%d]=%f exp=%f \n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[out], out_pos, res_float, expected);
				}
			}
		}
	}
}

void test_trans_EMOV_Idx1W2(int tno, uint16 ml_code, uint16 on_off, int run_step, float expected)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_float;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getDWordPos(in, i);
						ml_rc = setCodeOp2_Ex_Idx1W2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						setInputOp2_Idx1_EW2(in, in_pos, testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer EMOV Idx->W ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueFloat(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								test_getFloat(&res_float, out, out_pos);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d]=%f exp=%f \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_float, expected);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_EMOV_W1Idx2(int tno, uint16 ml_code, uint16 on_off, int run_step, float expected)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_float;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(inx=0; inx<15; inx++)
			{
				if(isIdxRangeOver(out, out_pos, testidx[inx].val)) continue;

				for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getDWordPos(in, i);
						ml_rc = setCodeOp2_Ex_W1Idx2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						setInputOp2_EW1_Idx2(in, in_pos, testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer EMOV W->Idx ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueFloat(tno, out, out_pos+testidx[inx].val, expected);
							if(rc2 == 1)
							{
								test_getFloat(&res_float, out, out_pos+testidx[inx].val);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d+%d]=%f exp=%f \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, testidx[inx].val, res_float, expected);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_EMOV_E1Idx2(int tno, uint16 ml_code, uint16 on_off, int run_step, float expected)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_float;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				ml_rc = setCodeOp2_Ex_E1_Idx2(ml_code, out, out_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInputOp2_E1_Idx2(testidx[inx].pos, testidx[inx].val, on_off);

				rc = runTestCode(run_step, "transfer EMOV E->Idx ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueFloat(tno, out, out_pos+testidx[inx].val, expected);
					if(rc2 == 1)
					{
						test_getFloat(&res_float, out, out_pos+testidx[inx].val);
						fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d+%d]=%f exp=%f \n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, reg[out], out_pos, testidx[inx].val, res_float, expected);
					}
				}
			}
		}
	}
}

void test_trans_EMOV_Idx1Idx2(int tno, uint16 ml_code, uint16 on_off, int run_step, float expected)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_float;

	for(olast=0; olast<3; olast++)
	{
		for(inx=0; inx<15; inx++)
		{
			out_pos = getDWordPos(out, olast);

			if(isIdxRangeOver(out, out_pos, testidx[inx].val)) continue;

			for(i=0; i<3; i++)
			{

				PLC_DEVICE_Init();

				in_pos = getDWordPos(in, i);
				ml_rc = setCodeOp2_Ex_Idx1Idx2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				if(isIdxRangeOver(in, in_pos, testidx[inx].val)) continue;

				setInputOp2_Idx1_Idx2(in, in_pos, testidx[inx].pos, testidx[inx].val, on_off);

				rc = runTestCode(run_step, "transfer EMOV Idx->Idx ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueFloat(tno, out, out_pos+testidx[inx].val, expected);
					if(rc2 == 1)
					{
						test_getFloat(&res_float, out, out_pos+testidx[inx].val);
						fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d+%d]=%f exp=%f \n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, testidx[inx].val, reg[out], out_pos, testidx[inx].val, res_float, expected);
					}
				}
			}
		}
	}
}

void test_trans_XCH_W1W2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 uint16 in_val, uint16 out_val, short in_exp, short out_exp)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordPos(in, i);
					ml_rc = setCodeOp2_Ex_W1W2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_W1W2_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					rc = runTestCode(run_step, "transfer XCH W->W ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueWord(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							test_getWord(&res_word, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos, res_word, out_exp);
						}

						rc2=verifyResultValueWord(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							test_getWord(&res_word, in, in_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, res_word, in_exp);
						}
					}
				}
			}
		}
	}
}

void test_trans_XCH_N1W2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 uint16 in_val, uint16 out_val, short in_exp, short out_exp)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordPos(in, i);
					ml_rc = setCodeOp2_Ex_N1W2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_N1W2_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					rc = runTestCode(run_step, "transfer XCH N->W ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueWord(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							test_getWord(&res_out, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos, res_out, out_exp);
						}

						rc2=verifyResultValueNibble4(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							test_getNibble(&res_in, in, in_pos, 4);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, res_in, in_exp);
						}
					}
				}
			}
		}
	}
}

void test_trans_XCH_Idx1W2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 uint16 in_val, uint16 out_val, short in_exp, short out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordPos(in, i);
						ml_rc = setCodeOp2_Ex_Idx1W2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						if(isIdxRangeOver(in, in_pos, testidx[inx].val)) continue;

						setInputOp2_Idx1W2_all(in, in_pos, in_val, out, out_pos, out_val, \
								testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer XCH Idx->W ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWord(tno, out, out_pos, out_exp);
							if(rc2 == 1)
							{
								test_getWord(&res_out, out, out_pos);
								fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos, res_out, out_exp);
							}

							rc2=verifyResultValueWord(tno, in, in_pos+testidx[inx].val, in_exp);
							if(rc2 == 1)
							{
								test_getWord(&res_in, in, in_pos+testidx[inx].val);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, res_in, in_exp);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_XCH_W1N2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 uint16 in_val, uint16 out_val, short in_exp, short out_exp)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordPos(in, i);
					ml_rc = setCodeOp2_Ex_W1N2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_W1N2_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					rc = runTestCode(run_step, "transfer XCH W->N ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueNibble4(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							test_getNibble(&res_out, out, out_pos, 4);
							fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos, res_out, out_exp);
						}

						rc2=verifyResultValueWord(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							test_getWord(&res_in, in, in_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, res_in, in_exp);
						}
					}
				}
			}
		}
	}
}

void test_trans_XCH_N1N2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 uint16 in_val, uint16 out_val, short in_exp, short out_exp)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordPos(in, i);
					ml_rc = setCodeOp2_Ex_N1N2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_N1N2_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					rc = runTestCode(run_step, "transfer XCH N->N ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueNibble4(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							test_getNibble(&res_out, out, out_pos, 4);
							fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos, res_out, out_exp);
						}

						rc2=verifyResultValueNibble4(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							test_getNibble(&res_in, in, in_pos, 4);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, res_in, in_exp);
						}
					}
				}
			}
		}
	}
}

void test_trans_XCH_Idx1N2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 uint16 in_val, uint16 out_val, short in_exp, short out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordPos(in, i);
						ml_rc = setCodeOp2_Ex_Idx1N2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						if(isIdxRangeOver(in, in_pos, testidx[inx].val)) continue;

						setInputOp2_Idx1N2_all(in, in_pos, in_val, out, out_pos, out_val, \
								testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer XCH Idx->W ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueNibble4(tno, out, out_pos, out_exp);
							if(rc2 == 1)
							{
								test_getNibble(&res_out, out, out_pos, 4);
								fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos, res_out, out_exp);
							}

							rc2=verifyResultValueWord(tno, in, in_pos+testidx[inx].val, in_exp);
							if(rc2 == 1)
							{
								test_getWord(&res_in, in, in_pos+testidx[inx].val);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, res_in, in_exp);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_XCH_W1Idx2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 uint16 in_val, uint16 out_val, short in_exp, short out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordPos(in, i);
						ml_rc = setCodeOp2_Ex_W1Idx2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						if(isIdxRangeOver(out, out_pos, testidx[inx].val)) continue;

						setInputOp2_W1Idx2_all(in, in_pos, in_val, out, out_pos, out_val, \
								testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer XCH W->Idx ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWord(tno, out, out_pos+testidx[inx].val, out_exp);
							if(rc2 == 1)
							{
								test_getWord(&res_out, out, out_pos+testidx[inx].val);
								fprintf(flog, "test case %d error cmd=%s out_%s[%d+%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos, testidx[inx].val, res_out, out_exp);
							}

							rc2=verifyResultValueWord(tno, in, in_pos, in_exp);
							if(rc2 == 1)
							{
								test_getWord(&res_in, in, in_pos);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, res_in, in_exp);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_XCH_N1Idx2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 uint16 in_val, uint16 out_val, short in_exp, short out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordPos(in, i);
						ml_rc = setCodeOp2_Ex_N1Idx2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						if(isIdxRangeOver(out, out_pos, testidx[inx].val)) continue;

						setInputOp2_N1Idx2_all(in, in_pos, in_val, out, out_pos, out_val, \
								testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer XCH N->Idx ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWord(tno, out, out_pos+testidx[inx].val, out_exp);
							if(rc2 == 1)
							{
								test_getWord(&res_out, out, out_pos+testidx[inx].val);
								fprintf(flog, "test case %d error cmd=%s out_%s[%d+%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos, testidx[inx].val, res_out, out_exp);
							}

							rc2=verifyResultValueNibble4(tno, in, in_pos, in_exp);
							if(rc2 == 1)
							{
								test_getNibble(&res_in, in, in_pos, 4);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, res_in, in_exp);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_XCH_Idx1Idx2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 uint16 in_val, uint16 out_val, short in_exp, short out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(inx=0; inx<15; inx++)
		{
			out_pos = getWordPos(out, olast);

			if(isIdxRangeOver(out, out_pos, testidx[inx].val)) continue;

			for(i=0; i<3; i++)
			{
				PLC_DEVICE_Init();

				in_pos = getWordPos(in, i);
				ml_rc = setCodeOp2_Ex_Idx1Idx2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				if(isIdxRangeOver(in, in_pos, testidx[inx].val)) continue;

				setInputOp2_Idx1Idx2_all(in, in_pos, in_val, out, out_pos, out_val, \
						testidx[inx].pos, testidx[inx].val, on_off);

				rc = runTestCode(run_step, "transfer XCH Idx->Idx ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueWord(tno, out, out_pos+testidx[inx].val, out_exp);
					if(rc2 == 1)
					{
						test_getWord(&res_out, out, out_pos+testidx[inx].val);
						fprintf(flog, "test case %d error cmd=%s out_%s[%d+%d]=%d exp=%d \n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[out], out_pos, testidx[inx].val, res_out, out_exp);
					}

					rc2=verifyResultValueWord(tno, in, in_pos+testidx[inx].val, in_exp);
					if(rc2 == 1)
					{
						test_getWord(&res_in, in, in_pos+testidx[inx].val);
						fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d]=%d exp=%d \n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, testidx[inx].val, res_in, in_exp);
					}
				}
			}
		}
	}
}

void test_trans_DXCH_DW1DW2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 int in_val, int out_val, int in_exp, int out_exp)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getDWordPos(in, i);
					ml_rc = setCodeOp2_Ex_W1W2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_DW1DW2_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					rc = runTestCode(run_step, "transfer DXCH W->W ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueDWord(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							test_getDWord(&res_word, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos, res_word, out_exp);
						}

						rc2=verifyResultValueDWord(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							test_getDWord(&res_word, in, in_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, res_word, in_exp);
						}
					}
				}
			}
		}
	}
}

void test_trans_DXCH_DN1DW2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 int in_val, int out_val, int in_exp, int out_exp)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getDWordPos(in, i);
					ml_rc = setCodeOp2_Ex_N1DW2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_N1DW2_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					rc = runTestCode(run_step, "transfer DXCH N->W ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueDWord(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							test_getDWord(&res_out, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos, res_out, out_exp);
						}

						rc2=verifyResultValueNibble8(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							test_getNibble(&res_in, in, in_pos, 8);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, res_in, in_exp);
						}
					}
				}
			}
		}
	}
}

void test_trans_DXCH_DIdx1DW2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 int in_val, int out_val, int in_exp, int out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getDWordPos(in, i);
						ml_rc = setCodeOp2_Ex_Idx1W2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						if(isIdxRangeOver(in, in_pos, testidx[inx].val)) continue;

						setInputOp2_Idx1DW2_all(in, in_pos, in_val, out, out_pos, out_val, \
								testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer DXCH Idx->W ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueDWord(tno, out, out_pos, out_exp);
							if(rc2 == 1)
							{
								test_getDWord(&res_out, out, out_pos);
								fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos, res_out, out_exp);
							}

							rc2=verifyResultValueDWord(tno, in, in_pos+testidx[inx].val, in_exp);
							if(rc2 == 1)
							{
								test_getDWord(&res_in, in, in_pos+testidx[inx].val);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, res_in, in_exp);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_DXCH_DW1DN2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 int in_val, int out_val, int in_exp, int out_exp)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getDWordPos(in, i);
					ml_rc = setCodeOp2_Ex_DW1N2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_DW1N2_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					rc = runTestCode(run_step, "transfer DXCH W->N ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueNibble8(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							test_getNibble(&res_out, out, out_pos, 8);
							fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos, res_out, out_exp);
						}

						rc2=verifyResultValueDWord(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							test_getDWord(&res_in, in, in_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, res_in, in_exp);
						}
					}
				}
			}
		}
	}
}

void test_trans_DXCH_DN1DN2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 int in_val, int out_val, int in_exp, int out_exp)
{
	int i, j, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getDWordPos(in, i);
					ml_rc = setCodeOp2_Ex_DN1DN2(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp2_DN1DN2_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					rc = runTestCode(run_step, "transfer DXCH N->N ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueNibble8(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							test_getNibble(&res_out, out, out_pos, 8);
							fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos, res_out, out_exp);
						}

						rc2=verifyResultValueNibble8(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							test_getNibble(&res_in, in, in_pos, 8);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, res_in, in_exp);
						}
					}
				}
			}
		}
	}
}

void test_trans_DXCH_DIdx1DN2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 int in_val, int out_val, int in_exp, int out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getDWordPos(in, i);
						ml_rc = setCodeOp2_Ex_Idx1DN2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						if(isIdxRangeOver(in, in_pos, testidx[inx].val)) continue;

						setInputOp2_Idx1DN2_all(in, in_pos, in_val, out, out_pos, out_val, \
								testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer DXCH Idx->W ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueNibble8(tno, out, out_pos, out_exp);
							if(rc2 == 1)
							{
								test_getNibble(&res_out, out, out_pos, 8);
								fprintf(flog, "test case %d error cmd=%s out_%s[%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos, res_out, out_exp);
							}

							rc2=verifyResultValueDWord(tno, in, in_pos+testidx[inx].val, in_exp);
							if(rc2 == 1)
							{
								test_getDWord(&res_in, in, in_pos+testidx[inx].val);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, res_in, in_exp);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_DXCH_DW1DIdx2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 int in_val, int out_val, int in_exp, int out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getDWordPos(in, i);
						ml_rc = setCodeOp2_Ex_W1Idx2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						if(isIdxRangeOver(out, out_pos, testidx[inx].val)) continue;

						setInputOp2_DW1Idx2_all(in, in_pos, in_val, out, out_pos, out_val, \
								testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer DXCH W->Idx ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueDWord(tno, out, out_pos+testidx[inx].val, out_exp);
							if(rc2 == 1)
							{
								test_getDWord(&res_out, out, out_pos+testidx[inx].val);
								fprintf(flog, "test case %d error cmd=%s out_%s[%d+%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos, testidx[inx].val, res_out, out_exp);
							}

							rc2=verifyResultValueDWord(tno, in, in_pos, in_exp);
							if(rc2 == 1)
							{
								test_getDWord(&res_in, in, in_pos);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, res_in, in_exp);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_DXCH_DN1DIdx2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 int in_val, int out_val, int in_exp, int out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getDWordPos(in, i);
						ml_rc = setCodeOp2_Ex_DN1Idx2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						if(isIdxRangeOver(out, out_pos, testidx[inx].val)) continue;

						setInputOp2_DN1Idx2_all(in, in_pos, in_val, out, out_pos, out_val, \
								testidx[inx].pos, testidx[inx].val, on_off);

						rc = runTestCode(run_step, "transfer DXCH N->Idx ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueDWord(tno, out, out_pos+testidx[inx].val, out_exp);
							if(rc2 == 1)
							{
								test_getDWord(&res_out, out, out_pos+testidx[inx].val);
								fprintf(flog, "test case %d error cmd=%s out_%s[%d+%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos, testidx[inx].val, res_out, out_exp);
							}

							rc2=verifyResultValueNibble8(tno, in, in_pos, in_exp);
							if(rc2 == 1)
							{
								test_getNibble(&res_in, in, in_pos, 8);
								fprintf(flog, "test case %d error cmd=%s in_%s[%d]=%d exp=%d \n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, res_in, in_exp);
							}
						}
					}
				}
			}
		}
	}
}

void test_trans_DXCH_DIdx1DIdx2
(int tno, uint16 ml_code, uint16 on_off, int run_step,
 int in_val, int out_val, int in_exp, int out_exp)
{
	int i, j, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_in, res_out;

	for(olast=0; olast<3; olast++)
	{
		for(inx=0; inx<15; inx++)
		{
			out_pos = getDWordPos(out, olast);

			if(isIdxRangeOver(out, out_pos, testidx[inx].val)) continue;

			for(i=0; i<3; i++)
			{
				PLC_DEVICE_Init();

				in_pos = getDWordPos(in, i);
				ml_rc = setCodeOp2_Ex_Idx1Idx2(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				if(isIdxRangeOver(in, in_pos, testidx[inx].val)) continue;

				setInputOp2_DIdx1DIdx2_all(in, in_pos, in_val, out, out_pos, out_val, \
						testidx[inx].pos, testidx[inx].val, on_off);

				rc = runTestCode(run_step, "transfer DXCH Idx->Idx ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueDWord(tno, out, out_pos+testidx[inx].val, out_exp);
					if(rc2 == 1)
					{
						test_getDWord(&res_out, out, out_pos+testidx[inx].val);
						fprintf(flog, "test case %d error cmd=%s out_%s[%d+%d]=%d exp=%d \n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[out], out_pos, testidx[inx].val, res_out, out_exp);
					}

					rc2=verifyResultValueDWord(tno, in, in_pos+testidx[inx].val, in_exp);
					if(rc2 == 1)
					{
						test_getDWord(&res_in, in, in_pos+testidx[inx].val);
						fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d]=%d exp=%d \n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, testidx[inx].val, res_in, in_exp);
					}
				}
			}
		}
	}
}

void testTransferExtraCommand(void)
{
	char log[] = "err_trans_extra.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("transfer extra LOG file open error !\n");
		exit(1);
	}

#if 1
	test_trans_EMOV_W1W2(23, ML_CODE_EMOV, 1, 1, 4.23542);
#else

	test_trans_Op1_W(0, ML_CODE_SWAP, 0, 1, 0x55AA);
	test_trans_Op1_W(1, ML_CODE_SWAP, 1, 1, 0xAA55);
	test_trans_Op1_N(2, ML_CODE_SWAP, 0, 1, 0x55AA);
	test_trans_Op1_N(3, ML_CODE_SWAP, 1, 1, 0xAA55);
	test_trans_Op1_Idx(4, ML_CODE_SWAP, 0, 1, 0x55AA);
	test_trans_Op1_Idx(5, ML_CODE_SWAP, 1, 1, 0xAA55);

	test_trans_Op1_W(6, ML_CODE_SWAPP, 0, 2, 0x55AA);
	test_trans_Op1_W(7, ML_CODE_SWAPP, 2, 2, 0xAA55);
	test_trans_Op1_N(8, ML_CODE_SWAPP, 0, 2, 0x55AA);
	test_trans_Op1_N(9, ML_CODE_SWAPP, 2, 2, 0xAA55);
	test_trans_Op1_Idx(10, ML_CODE_SWAPP, 0, 2, 0x55AA);
	test_trans_Op1_Idx(11, ML_CODE_SWAPP, 2, 2, 0xAA55);

	test_trans_STRMOV_W(12, ML_CODE_STRMOV, 0, 1, "");
	test_trans_STRMOV_W(13, ML_CODE_STRMOV, 1, 1, "ABCDE");
	test_trans_STRMOV_Overlap(14, ML_CODE_STRMOV, 1, 1, "ABCDE");
	test_trans_STRMOV_K(15, ML_CODE_STRMOV, 0, 1, "");
	test_trans_STRMOV_K(16, ML_CODE_STRMOV, 1, 1, "ABCDE");

	test_trans_STRMOV_W(17, ML_CODE_STRMOVP, 0, 2, "");
	test_trans_STRMOV_W(18, ML_CODE_STRMOVP, 2, 2, "ABCDE");
	test_trans_STRMOV_Overlap(19, ML_CODE_STRMOVP, 2, 2, "ABCDE");
	test_trans_STRMOV_K(20, ML_CODE_STRMOVP, 0, 2, "");
	test_trans_STRMOV_K(21, ML_CODE_STRMOVP, 2, 2, "ABCDE");

	test_trans_EMOV_W1W2(22, ML_CODE_EMOV, 0, 1, 0);
	test_trans_EMOV_W1W2(23, ML_CODE_EMOV, 1, 1, 4.23542);
	test_trans_EMOV_E1W2(24, ML_CODE_EMOV, 0, 1, 0);
	test_trans_EMOV_E1W2(25, ML_CODE_EMOV, 1, 1, 4.23542);
	test_trans_EMOV_Idx1W2(26, ML_CODE_EMOV, 0, 1, 0);
	test_trans_EMOV_Idx1W2(27, ML_CODE_EMOV, 1, 1, 4.23542);
	test_trans_EMOV_W1Idx2(28, ML_CODE_EMOV, 0, 1, 0);
	test_trans_EMOV_W1Idx2(29, ML_CODE_EMOV, 1, 1, 4.23542);
	test_trans_EMOV_E1Idx2(30, ML_CODE_EMOV, 0, 1, 0);
	test_trans_EMOV_E1Idx2(31, ML_CODE_EMOV, 1, 1, 4.23542);
	test_trans_EMOV_E1Idx2(32, ML_CODE_EMOV, 0, 1, 0);
	test_trans_EMOV_Idx1Idx2(33, ML_CODE_EMOV, 1, 1, 4.23542);

	test_trans_EMOV_W1W2(34, ML_CODE_EMOVP, 0, 2, 0);
	test_trans_EMOV_W1W2(35, ML_CODE_EMOVP, 2, 2, 4.23542);
	test_trans_EMOV_E1W2(36, ML_CODE_EMOVP, 0, 2, 0);
	test_trans_EMOV_E1W2(37, ML_CODE_EMOVP, 2, 2, 4.23542);
	test_trans_EMOV_Idx1W2(38, ML_CODE_EMOVP, 0, 2, 0);
	test_trans_EMOV_Idx1W2(39, ML_CODE_EMOVP, 2, 2, 4.23542);
	test_trans_EMOV_W1Idx2(40, ML_CODE_EMOVP, 0, 2, 0);
	test_trans_EMOV_W1Idx2(41, ML_CODE_EMOVP, 2, 2, 4.23542);
	test_trans_EMOV_E1Idx2(42, ML_CODE_EMOVP, 0, 2, 0);
	test_trans_EMOV_E1Idx2(43, ML_CODE_EMOVP, 2, 2, 4.23542);
	test_trans_EMOV_E1Idx2(44, ML_CODE_EMOVP, 0, 2, 0);
	test_trans_EMOV_Idx1Idx2(45, ML_CODE_EMOVP, 2, 2, 4.23542);

	test_trans_XCH_W1W2(46, ML_CODE_XCH, 0, 1, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_W1W2(47, ML_CODE_XCH, 1, 1, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_N1W2(48, ML_CODE_XCH, 0, 1, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_N1W2(49, ML_CODE_XCH, 1, 1, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_Idx1W2(50, ML_CODE_XCH, 0, 1, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_Idx1W2(51, ML_CODE_XCH, 1, 1, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_W1N2(52, ML_CODE_XCH, 0, 1, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_W1N2(53, ML_CODE_XCH, 1, 1, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_N1N2(54, ML_CODE_XCH, 0, 1, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_N1N2(55, ML_CODE_XCH, 1, 1, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_Idx1N2(56, ML_CODE_XCH, 0, 1, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_Idx1N2(57, ML_CODE_XCH, 1, 1, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_W1Idx2(58, ML_CODE_XCH, 0, 1, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_W1Idx2(59, ML_CODE_XCH, 1, 1, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_N1Idx2(60, ML_CODE_XCH, 0, 1, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_N1Idx2(61, ML_CODE_XCH, 1, 1, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_Idx1Idx2(62, ML_CODE_XCH, 0, 1, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_Idx1Idx2(63, ML_CODE_XCH, 1, 1, 0x5555, 0xAAAA, 0xAAAA, 0x5555);

	test_trans_XCH_W1W2(64, ML_CODE_XCHP, 0, 2, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_W1W2(65, ML_CODE_XCHP, 2, 2, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_N1W2(66, ML_CODE_XCHP, 0, 2, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_N1W2(67, ML_CODE_XCHP, 2, 2, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_Idx1W2(68, ML_CODE_XCHP, 0, 2, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_Idx1W2(69, ML_CODE_XCHP, 2, 2, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_W1N2(70, ML_CODE_XCHP, 0, 2, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_W1N2(71, ML_CODE_XCHP, 2, 2, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_N1N2(72, ML_CODE_XCHP, 0, 2, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_N1N2(73, ML_CODE_XCHP, 2, 2, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_Idx1N2(74, ML_CODE_XCHP, 0, 2, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_Idx1N2(75, ML_CODE_XCHP, 2, 2, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_W1Idx2(76, ML_CODE_XCHP, 0, 2, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_W1Idx2(77, ML_CODE_XCHP, 2, 2, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_N1Idx2(78, ML_CODE_XCHP, 0, 2, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_N1Idx2(79, ML_CODE_XCHP, 2, 2, 0x5555, 0xAAAA, 0xAAAA, 0x5555);
	test_trans_XCH_Idx1Idx2(80, ML_CODE_XCHP, 0, 2, 0x5555, 0xAAAA, 0x5555, 0xAAAA);
	test_trans_XCH_Idx1Idx2(81, ML_CODE_XCHP, 2, 2, 0x5555, 0xAAAA, 0xAAAA, 0x5555);

	test_trans_DXCH_DW1DW2(82, ML_CODE_DXCH, 0, 1, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DW1DW2(83, ML_CODE_DXCH, 1, 1, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DN1DW2(84, ML_CODE_DXCH, 0, 1, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DN1DW2(85, ML_CODE_DXCH, 1, 1, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DIdx1DW2(86, ML_CODE_DXCH, 0, 1, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DIdx1DW2(87, ML_CODE_DXCH, 1, 1, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DW1DN2(88, ML_CODE_DXCH, 0, 1, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DW1DN2(89, ML_CODE_DXCH, 1, 1, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DN1DN2(90, ML_CODE_DXCH, 0, 1, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DN1DN2(91, ML_CODE_DXCH, 1, 1, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DIdx1DN2(92, ML_CODE_DXCH, 0, 1, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DIdx1DN2(93, ML_CODE_DXCH, 1, 1, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DW1DIdx2(94, ML_CODE_DXCH, 0, 1, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DW1DIdx2(95, ML_CODE_DXCH, 1, 1, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DN1DIdx2(96, ML_CODE_DXCH, 0, 1, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DN1DIdx2(97, ML_CODE_DXCH, 1, 1, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DIdx1DIdx2(98, ML_CODE_DXCH, 0, 1, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DIdx1DIdx2(99, ML_CODE_DXCH, 1, 1, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);

	test_trans_DXCH_DW1DW2(100, ML_CODE_DXCHP, 0, 2, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DW1DW2(101, ML_CODE_DXCHP, 2, 2, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DN1DW2(102, ML_CODE_DXCHP, 0, 2, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DN1DW2(103, ML_CODE_DXCHP, 2, 2, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DIdx1DW2(104, ML_CODE_DXCHP, 0, 2, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DIdx1DW2(105, ML_CODE_DXCHP, 2, 2, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DW1DN2(106, ML_CODE_DXCHP, 0, 2, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DW1DN2(107, ML_CODE_DXCHP, 2, 2, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DN1DN2(108, ML_CODE_DXCHP, 0, 2, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DN1DN2(109, ML_CODE_DXCHP, 2, 2, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DIdx1DN2(110, ML_CODE_DXCHP, 0, 2, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DIdx1DN2(111, ML_CODE_DXCHP, 2, 2, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DW1DIdx2(112, ML_CODE_DXCHP, 0, 2, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DW1DIdx2(113, ML_CODE_DXCHP, 2, 2, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DN1DIdx2(114, ML_CODE_DXCHP, 0, 2, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DN1DIdx2(115, ML_CODE_DXCHP, 2, 2, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);
	test_trans_DXCH_DIdx1DIdx2(116, ML_CODE_DXCHP, 0, 2, 0x55555555, 0xAAAAAAAA, 0x55555555, 0xAAAAAAAA);
	test_trans_DXCH_DIdx1DIdx2(117, ML_CODE_DXCHP, 2, 2, 0x55555555, 0xAAAAAAAA, 0xAAAAAAAA, 0x55555555);

#endif

	fclose(flog);
}
#endif
