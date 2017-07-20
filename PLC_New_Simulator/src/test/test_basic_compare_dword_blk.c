/*
 * test_basic_compare_dword_blk.c
 *
 *  Created on: Aug 18, 2015
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

#define BLK_COMP_CNT 	5

extern void TestCodeInit(void);
extern void TestCodeTearDown(void);
extern int runTestCode(int run_step, char *testFuncName);

extern int setCodeOp4_W1W2BR3W4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos);
extern int setCodeOp4_W1W2BR3K4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos);
extern int setCodeOp4_W1W2BR3N4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint8 c_reg, uint16 c_pos);
extern int setCodeOp4_W1W2BR3Idx4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos);
extern int setCodeOp4_W1W2WB3W4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 bit_pos);
extern int setCodeOp4_W1W2WB3K4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 bit_pos);
extern int setCodeOp4_W1W2WB3N4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 bit_pos, uint8 c_reg, uint16 c_pos);
extern int setCodeOp4_W1W2WB3Idx4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 bit_pos, uint16 idx_pos);

extern int verifyResultValueBitBlk(int tcase, uint8 dest_reg, uint16 pos, uint8 expected[]);
extern int verifyResultValueWordBitBlk(int tcase, uint8 dest_reg, uint16 pos, uint16 bit_pos, uint8 expected[]);

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

int blk_op1_dval[BLK_COMP_CNT] = {16843009, 16843010, 16843009, 16843009, 16843010};
int blk_op2_dval[BLK_COMP_CNT] = {16777473, 16843008, 16843009, 16843010, 16908545};

uint8 dblk_off[BLK_COMP_CNT] = {0, 0, 0, 0, 0};
uint8 dblk_eq[BLK_COMP_CNT] = {0, 0, 1, 0, 0};
uint8 dblk_ne[BLK_COMP_CNT] = {1, 1, 0, 1, 1};
uint8 dblk_gt[BLK_COMP_CNT] = {1, 1, 0, 0, 0};
uint8 dblk_ge[BLK_COMP_CNT] = {1, 1, 1, 0, 0};
uint8 dblk_lt[BLK_COMP_CNT] = {0, 0, 0, 1, 1};
uint8 dblk_le[BLK_COMP_CNT] = {0, 0, 1, 1, 1};

static FILE *flog;

void setInput_BK_DW1DW2BR3W4
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos, uint16 on_off
)
{
	int i;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+i*2, blk_op1_dval[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_COMP_CNT);


	TestCodeTearDown();
}

void setInput_BK_DW1DW2BR3K4
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos, uint16 on_off
)
{
	int i;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+i*2, blk_op1_dval[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}

	TestCodeTearDown();
}

void setInput_BK_DW1DW2BR3N4
(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 c_reg, uint16 c_pos, uint16 on_off
)
{
	int i, value=BLK_COMP_CNT;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+i*2, blk_op1_dval[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput_BK_DW1DW2BR3Idx4
(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val, uint16 on_off
)
{
	int i;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+i*2, blk_op1_dval[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, 5);

	TestCodeTearDown();
}

void setInput_BK_DW1DW2WB3W4
(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint16 on_off
)
{
	int i;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+i*2, blk_op1_dval[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 5);

	TestCodeTearDown();
}

void setInput_BK_DW1DW2WB3K4(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 on_off)
{
	int i;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+i*2, blk_op1_dval[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}

	TestCodeTearDown();
}

void setInput_BK_DW1DW2WB3N4
(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 c_reg, uint16 c_pos, uint16 on_off
)
{
	int i, value=BLK_COMP_CNT;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+i*2, blk_op1_dval[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput_BK_DW1DW2WB3Idx4
(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val, uint16 on_off
)
{
	int i;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+i*2, blk_op1_dval[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, 5);

	TestCodeTearDown();
}

int setCodeOp4_DK1DW2BR3W4
(uint16 ml_cmd, uint8 in, uint16 in_pos,
 uint8 out, uint16 out_pos
)
{
	if(in < OPERAND_ML_CODE_D) return 0;

	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperand(in, in_pos);
		addMLOperand(out, out_pos); addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_DK1DW2BR3W4(uint8 in2, uint16 in2_pos, uint16 on_off)
{
	int i;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_COMP_CNT);


	TestCodeTearDown();
}

int setCodeOp4_DK1DW2BR3K4
(uint16 ml_cmd, uint8 in, uint16 in_pos,
 uint8 out, uint16 out_pos
)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperand(in, in_pos);
		addMLOperand(out, out_pos); addMLOperand(OPERAND_ML_CODE_K, 5);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_DK1DW2BR3K4(uint8 in2, uint16 in2_pos, uint16 on_off)
{
	int i;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+i*2, blk_op2_dval[i]);
	}

	TestCodeTearDown();
}

int setCodeOp4_DK1DW2BR3N4
(uint16 ml_cmd, uint8 in, uint16 in_pos,
 uint8 out, uint16 out_pos, uint8 c_reg, uint16 c_pos
)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperand(in, in_pos);
		addMLOperand(out, out_pos); addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_DK1DW2BR3N4
( uint8 in, uint16 in_pos,
  uint8 c_reg, uint16 c_pos, uint16 on_off
)
{
	int i, value=BLK_COMP_CNT;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+i*2, blk_op2_dval[i]);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

int setCodeOp4_DK1DW2BR3Idx4
(uint16 ml_cmd, uint8 in, uint16 in_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos
)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperand(in, in_pos);
		addMLOperand(out, out_pos); addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_DK1DW2BR3Idx4
(uint8 in, uint16 in_pos,
 uint16 idx_pos, uint16 idx_val, uint16 on_off
)
{
	int i;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+i*2, blk_op2_dval[i]);
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, 5);

	TestCodeTearDown();
}

int setCodeOp4_DK1DW2WB3W4
(uint16 ml_cmd, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 bit_pos
)
{
	if(in2 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperand(in2, in2_pos);
		addMLOperandWordBit(out, out_pos, bit_pos); addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_DK1DW2WB3W4(uint8 in, uint16 in_pos, uint16 on_off)
{
	int i;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+i*2, blk_op2_dval[i]);
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 5);

	TestCodeTearDown();
}

int setCodeOp4_DK1DW2WB3K4
(uint16 ml_cmd, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 bit_pos
)
{
	if(in2 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperand(in2, in2_pos);
		addMLOperandWordBit(out, out_pos, bit_pos); addMLOperand(OPERAND_ML_CODE_K, 5);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_DK1DW2WB3K4(uint8 in, uint16 in_pos, uint16 on_off)
{
	int i;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+i*2, blk_op2_dval[i]);
	}

	TestCodeTearDown();
}

int setCodeOp4_DK1DW2WB3N4
(uint16 ml_cmd, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 bit_pos, uint8 c_reg, uint16 c_pos
)
{
	if(in2 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperand(in2, in2_pos);
		addMLOperandWordBit(out, out_pos, bit_pos); addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_DK1DW2WB3N4
(uint8 in, uint16 in_pos,
 uint8 c_reg, uint16 c_pos, uint16 on_off
)
{
	int i, value=BLK_COMP_CNT;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+i*2, blk_op2_dval[i]);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

int setCodeOp4_DK1DW2WB3Idx4
(uint16 ml_cmd, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 bit_pos,
 uint16 idx_pos
)
{
	if(in2 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperand(in2, in2_pos);
		addMLOperandWordBit(out, out_pos, bit_pos); addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_DK1DW2WB3Idx4
(uint8 in, uint16 in_pos,
 uint16 idx_pos, uint16 idx_val, uint16 on_off
)
{
	int i;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);
	for(i=0; i<BLK_COMP_CNT; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+i*2, blk_op2_dval[i]);
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, 5);

	TestCodeTearDown();
}




static uint16 getBitPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0, 6144,4096},
			{8186,8186,8186,8186,2042,8186,0, 12287,8191}};// 5bit, 1 word

	return pos[inx_pos][reg];
}

static uint16 getWordPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12277,8181}}; //5 block*2word

	return pos[inx_pos][reg];
}


void test_blk_comp_DW1DW2BR3W4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos=50, out_pos, c_pos=160;
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getBitPos(out, olast);
			printf("%d o_pos=%d \n", __LINE__, out_pos);
			for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in1_pos = getWordPos(in1, i);
						ml_rc = setCodeOp4_W1W2BR3W4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos);
						if(ml_rc == 0) continue;

						setInput_BK_DW1DW2BR3W4(in1, in1_pos, in2, in2_pos, on_off);

						printf("in1(%d:%d) in2(%d:%d) out(%d:%d)\n", in1, in1_pos, in2, in2_pos, out, out_pos);
						rc = runTestCode(1, "block compare DW1DW2BR3W4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBitBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d]=", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos);
								for(k=0; k<BLK_COMP_CNT; k++)
								{
									test_getBit(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected[k]);
								}
								fprintf(flog, "\n");
							}
						}
					}
				}
			}
		}
	}
}


void test_blk_comp_DW1DW2BR3K4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos=50, out_pos, c_pos=160;
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in1_pos = getWordPos(in1, i);
						ml_rc = setCodeOp4_W1W2BR3K4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos);
						if(ml_rc == 0) continue;

						setInput_BK_DW1DW2BR3K4(in1, in1_pos, in2, in2_pos, on_off);
						printf("in1(%d:%d) in2(%d:%d) out(%d:%d)\n", in1, in1_pos, in2, in2_pos, out, out_pos);
						rc = runTestCode(1, "block compare DW1DW2BR3K4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBitBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] K5 : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos);
								for(k=0; k<BLK_COMP_CNT; k++)
								{
									test_getBit(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected[k]);
								}
								fprintf(flog, "\n");
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DW1DW2BR3N4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_X;
	uint16 in1_pos, in2_pos=50, out_pos, c_pos=160;
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
					{
						for(i=0; i<3; i++)
						{
							PLC_DEVICE_Init();

							in1_pos = getWordPos(in1, i);
							ml_rc = setCodeOp4_W1W2BR3N4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, c_reg, c_pos);
							if(ml_rc == 0) continue;

							setInput_BK_DW1DW2BR3N4(in1, in1_pos, in2, in2_pos, c_reg, c_pos, on_off);

							rc = runTestCode(1, "block compare DW1DW2BR3N4 ");
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								fprintf(flog, "test_no[%d]: %s runtime error! \n",
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
							}
							else
							{
								rc2=verifyResultValueBitBlk(tno, out, out_pos, expected);
								if(rc2 == 1)
								{
									fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] N_%s[%d] =", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
										reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, reg[c_reg], c_pos);
									for(k=0; k<BLK_COMP_CNT; k++)
									{
										test_getBit(&result[k], out, out_pos+k);
										fprintf(flog, "(%d:%d), ", result[k], expected[k]);
									}
									fprintf(flog, "\n");
								}
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DW1DW2BR3Idx4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_X;
	uint16 in1_pos, in2_pos=50, out_pos, c_pos=160;
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(i=0; i<3; i++)
					{
						for(inx=0; inx<15; inx++) // for index register
						{
							PLC_DEVICE_Init();

							in1_pos = getWordPos(in1, i);
							ml_rc = setCodeOp4_W1W2BR3Idx4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, testidx[inx].pos);
							if(ml_rc == 0) continue;

							// max D(12288-5)
							if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12283 ) continue;

							setInput_BK_DW1DW2BR3Idx4(in1, in1_pos, in2, in2_pos, testidx[inx].pos, testidx[inx].val, on_off);

							rc = runTestCode(1, "block compare DW1DW2BR3Idx4 ");
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								fprintf(flog, "test_no[%d]: %s runtime error! \n",
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
							}
							else
							{
								rc2=verifyResultValueBitBlk(tno, out, out_pos, expected);
								if(rc2 == 1)
								{
									fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] D[%d+500] =", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
										reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, testidx[inx].val);
									for(k=0; k<BLK_COMP_CNT; k++)
									{
										test_getBit(&result[k], out, out_pos+k);
										fprintf(flog, "(%d:%d), ", result[k], expected[k]);
									}
									fprintf(flog, "\n");
								}
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DW1DW2WB3W4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in1_pos, in2_pos=50, out_pos, c_pos=160, bit_pos[3]={0,7,11};
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(i=0; i<3; i++)
					{
						for(j=0; j<3; j++) // bit position for word bit
						{
							PLC_DEVICE_Init();

							in1_pos = getWordPos(in1, i);
							ml_rc = setCodeOp4_W1W2WB3W4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, bit_pos[j]);
							if(ml_rc == 0) continue;

							setInput_BK_DW1DW2WB3W4(in1, in1_pos, in2, in2_pos, on_off);

							//DBG_LOGPRINT("in1=%d i=%d, pos=%d\n", in1, i, in1_pos);
							rc = runTestCode(1, "block compare DW1DW2WB3W4 ");
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								fprintf(flog, "test_no[%d]: %s runtime error! \n",
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
							}
							else
							{
								rc2=verifyResultValueWordBitBlk(tno, out, out_pos, bit_pos[j], expected);
								if(rc2 == 1)
								{
									fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d].%d D[160] =", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
										reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, bit_pos[j]);
									for(k=0; k<BLK_COMP_CNT; k++)
									{
										test_getWordBit(&result[k], out, out_pos, bit_pos[j]+k );
										fprintf(flog, "(%d:%d), ", result[k], expected[k]);
									}
									fprintf(flog, "\n");
								}
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DW1DW2WB3K4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in1_pos, in2_pos=50, out_pos, c_pos=160, bit_pos[3]={0,7,11};
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(i=0; i<3; i++)
					{
						for(j=0; j<3; j++) // bit position for word bit
						{
							PLC_DEVICE_Init();

							in1_pos = getWordPos(in1, i);
							ml_rc = setCodeOp4_W1W2WB3K4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, bit_pos[j]);
							if(ml_rc == 0) continue;

							setInput_BK_DW1DW2WB3K4(in1, in1_pos, in2, in2_pos, on_off);

							//DBG_LOGPRINT("in1=%d i=%d, pos=%d\n", in1, i, in1_pos);
							rc = runTestCode(1, "block compare DW1DW2WB3K4 ");
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								fprintf(flog, "test_no[%d]: %s runtime error! \n",
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
							}
							else
							{
								rc2=verifyResultValueWordBitBlk(tno, out, out_pos, bit_pos[j], expected);
								if(rc2 == 1)
								{
									fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d].%d D[160] =", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
										reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, bit_pos[j]);
									for(k=0; k<BLK_COMP_CNT; k++)
									{
										test_getWordBit(&result[k], out, out_pos, bit_pos[j]+k );
										fprintf(flog, "(%d:%d), ", result[k], expected[k]);
									}
									fprintf(flog, "\n");
								}
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DW1DW2WB3N4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in1_pos, in2_pos=50, out_pos, c_pos=160, bit_pos[3]={0,7,11};
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
					{
						for(i=0; i<3; i++)
						{
							for(j=0; j<3; j++) // bit position for word bit
							{
								PLC_DEVICE_Init();

								in1_pos = getWordPos(in1, i);
								ml_rc = setCodeOp4_W1W2WB3N4(ml_code, in1, in1_pos, in2, in2_pos, \
										out, out_pos, bit_pos[j], c_reg, c_pos);
								if(ml_rc == 0) continue;

								setInput_BK_DW1DW2WB3N4(in1, in1_pos, in2, in2_pos, c_reg, c_pos, on_off);

								//DBG_LOGPRINT("in1=%d i=%d, pos=%d\n", in1, i, in1_pos);
								rc = runTestCode(1, "block compare DW1DW2WB3N4 ");
								if(rc == 1)
								{
									CU_ASSERT_FALSE(rc); // run time failure
									fprintf(flog, "test_no[%d]: %s runtime error! \n",
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
								}
								else
								{
									rc2=verifyResultValueWordBitBlk(tno, out, out_pos, bit_pos[j], expected);
									if(rc2 == 1)
									{
										fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d].%d N_%s[%d] =", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
											reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, bit_pos[j], reg[c_reg], c_pos);
										for(k=0; k<BLK_COMP_CNT; k++)
										{
											test_getWordBit(&result[k], out, out_pos, bit_pos[j]+k );
											fprintf(flog, "(%d:%d), ", result[k], expected[k]);
										}
										fprintf(flog, "\n");
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DW1DW2WB3Idx4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in1_pos, in2_pos=50, out_pos, c_pos=160, bit_pos[3]={0,7,11};
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(i=0; i<3; i++)
					{
						for(j=0; j<3; j++) // bit position for word bit
						{
						for(inx=0; inx<15; inx++) // for index register
						{
							PLC_DEVICE_Init();

							in1_pos = getWordPos(in1, i);
							ml_rc = setCodeOp4_W1W2WB3Idx4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, bit_pos[j], testidx[inx].pos);
							if(ml_rc == 0) continue;

							// max D(12288-5)
							if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12283 ) continue;

							setInput_BK_DW1DW2WB3Idx4(in1, in1_pos, in2, in2_pos, testidx[inx].pos, testidx[inx].val, on_off);

							rc = runTestCode(1, "block compare DW1DW2WB3Idx4 ");
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								fprintf(flog, "test_no[%d]: %s runtime error! \n",
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
							}
							else
							{
								rc2=verifyResultValueWordBitBlk(tno, out, out_pos, bit_pos[j], expected);
								if(rc2 == 1)
								{
									fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d].%d D[%d+500] =", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
										reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, bit_pos[j], testidx[inx].val);
									for(k=0; k<BLK_COMP_CNT; k++)
									{
										test_getBit(&result[k], out, out_pos+k);
										fprintf(flog, "(%d:%d), ", result[k], expected[k]);
									}
									fprintf(flog, "\n");
								}
							}
						}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DK1DW2BR3W4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordPos(in, i);
					ml_rc = setCodeOp4_DK1DW2BR3W4(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInput_BK_DK1DW2BR3W4(in, in_pos, on_off);

					rc = runTestCode(1, "block compare DK1DW2BR3W4 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBitBlk(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s K1234 %s[%d] %s[%d]=", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_COMP_CNT; k++)
							{
								test_getBit(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], expected[k]);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DK1DW2BR3K4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordPos(in, i);
					ml_rc = setCodeOp4_DK1DW2BR3K4(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInput_BK_DK1DW2BR3K4(in, in_pos, on_off);

					rc = runTestCode(1, "block compare DK1DW2BR3K4 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBitBlk(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s K1234 %s[%d] %s[%d]=", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_COMP_CNT; k++)
							{
								test_getBit(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], expected[k]);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DK1DW2BR3N4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordPos(in, i);
						ml_rc = setCodeOp4_DK1DW2BR3N4(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInput_BK_DK1DW2BR3N4(in, in_pos, c_reg, c_pos, on_off);

						rc = runTestCode(1, "block compare DK1DW2BR3N4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBitBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s K1234 %s[%d] %s[%d] N_%s[%d] =", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, reg[c_reg], c_pos);
								for(k=0; k<BLK_COMP_CNT; k++)
								{
									test_getBit(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected[k]);
								}
								fprintf(flog, "\n");
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DK1DW2BR3Idx4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						for(inx=0; inx<15; inx++) // for index register
						{
							PLC_DEVICE_Init();

							in_pos = getWordPos(in, i);
							ml_rc = setCodeOp4_DK1DW2BR3Idx4(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
							if(ml_rc == 0) continue;

							// max D(12288-5)
							if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12283 ) continue;

							setInput_BK_DK1DW2BR3Idx4(in, in_pos, testidx[inx].pos, testidx[inx].val, on_off);

							rc = runTestCode(1, "block compare DK1DW2BR3Idx4 ");
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								fprintf(flog, "test_no[%d]: %s runtime error! \n",
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
							}
							else
							{
								rc2=verifyResultValueBitBlk(tno, out, out_pos, expected);
								if(rc2 == 1)
								{
									fprintf(flog, "test case %d error cmd=%s K1234 %s[%d] %s[%d] D[500+%d] =", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
										reg[in], in_pos, reg[out], out_pos, testidx[inx].val);
									for(k=0; k<BLK_COMP_CNT; k++)
									{
										test_getBit(&result[k], out, out_pos+k);
										fprintf(flog, "(%d:%d), ", result[k], expected[k]);
									}
									fprintf(flog, "\n");
								}
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DK1DW2WB3W4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160, bit_pos[3]={0,7,11};
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(j=0; j<3; j++) // bit position for word bit
					{
						PLC_DEVICE_Init();

						in_pos = getWordPos(in, i);
						ml_rc = setCodeOp4_DK1DW2WB3W4(ml_code, in, in_pos, out, out_pos, bit_pos[j]);
						if(ml_rc == 0) continue;

						setInput_BK_DK1DW2WB3W4(in, in_pos, on_off);

						//DBG_LOGPRINT("in1=%d i=%d, pos=%d\n", in1, i, in1_pos);
						rc = runTestCode(1, "block compare DK1DW2WB3W4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWordBitBlk(tno, out, out_pos, bit_pos[j], expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s K1234 %s[%d] %s[%d].%d D[160] :", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, bit_pos[j]);
								for(k=0; k<BLK_COMP_CNT; k++)
								{
									test_getWordBit(&result[k], out, out_pos, bit_pos[j]+k );
									fprintf(flog, "(%d:%d), ", result[k], expected[k]);
								}
								fprintf(flog, "\n");
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DK1DW2WB3K4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160, bit_pos[3]={0,7,11};
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(j=0; j<3; j++) // bit position for word bit
					{
						PLC_DEVICE_Init();

						in_pos = getWordPos(in, i);
						ml_rc = setCodeOp4_DK1DW2WB3K4(ml_code, in, in_pos, out, out_pos, bit_pos[j]);
						if(ml_rc == 0) continue;

						setInput_BK_DK1DW2WB3K4(in, in_pos, on_off);

						//DBG_LOGPRINT("in1=%d i=%d, pos=%d\n", in1, i, in1_pos);
						rc = runTestCode(1, "block compare DK1DW2WB3K4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWordBitBlk(tno, out, out_pos, bit_pos[j], expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s K1234 %s[%d] %s[%d].%d K5 :", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, bit_pos[j]);
								for(k=0; k<BLK_COMP_CNT; k++)
								{
									test_getWordBit(&result[k], out, out_pos, bit_pos[j]+k );
									fprintf(flog, "(%d:%d), ", result[k], expected[k]);
								}
								fprintf(flog, "\n");
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DK1DW2WB3N4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160, bit_pos[3]={0,7,11};
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						for(j=0; j<3; j++) // bit position for word bit
						{
							PLC_DEVICE_Init();

							in_pos = getWordPos(in, i);
							ml_rc = setCodeOp4_DK1DW2WB3N4(ml_code, in, in_pos, out, out_pos, bit_pos[j], c_reg, c_pos);
							if(ml_rc == 0) continue;

							setInput_BK_DK1DW2WB3N4(in, in_pos, c_reg, c_pos, on_off);

							//DBG_LOGPRINT("in1=%d i=%d, pos=%d\n", in1, i, in1_pos);
							rc = runTestCode(1, "block compare DK1DW2WB3N4 ");
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								fprintf(flog, "test_no[%d]: %s runtime error! \n",
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
							}
							else
							{
								rc2=verifyResultValueWordBitBlk(tno, out, out_pos, bit_pos[j], expected);
								if(rc2 == 1)
								{
									fprintf(flog, "test case %d error cmd=%s K1234 %s[%d] %s[%d].%d N_%s[%d] :", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
										reg[in], in_pos, reg[out], out_pos, bit_pos[j], reg[c_reg], c_pos);
									for(k=0; k<BLK_COMP_CNT; k++)
									{
										test_getWordBit(&result[k], out, out_pos, bit_pos[j]+k );
										fprintf(flog, "(%d:%d), ", result[k], expected[k]);
									}
									fprintf(flog, "\n");
								}
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_comp_DK1DW2WB3Idx4(int tno, uint16 ml_code, uint16 on_off, uint8 *expected)
{
	int i, j, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160, bit_pos[3]={0,7,11};
	uint8 result[BLK_COMP_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getBitPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						for(j=0; j<3; j++) // bit position for word bit
						{
							for(inx=0; inx<15; inx++) // for index register
							{
								PLC_DEVICE_Init();

								in_pos = getWordPos(in, i);
								ml_rc = setCodeOp4_DK1DW2WB3Idx4(ml_code, in, in_pos, out, out_pos, bit_pos[j], testidx[inx].pos);
								if(ml_rc == 0) continue;

								// max D(12288-5)
								if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12283 ) continue;

								setInput_BK_DK1DW2WB3Idx4(in, in_pos, testidx[inx].pos, testidx[inx].val, on_off);

								//DBG_LOGPRINT("in1=%d i=%d, pos=%d\n", in1, i, in1_pos);
								rc = runTestCode(1, "block compare DK1DW2WB3Idx4 ");
								if(rc == 1)
								{
									CU_ASSERT_FALSE(rc); // run time failure
									fprintf(flog, "test_no[%d]: %s runtime error! \n",
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
								}
								else
								{
									rc2=verifyResultValueWordBitBlk(tno, out, out_pos, bit_pos[j], expected);
									if(rc2 == 1)
									{
										fprintf(flog, "test case %d error cmd=%s K1234 %s[%d] %s[%d].%d D[500+%d] :", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
											reg[in], in_pos, reg[out], out_pos, bit_pos[j], reg[c_reg], c_pos);
										for(k=0; k<BLK_COMP_CNT; k++)
										{
											test_getWordBit(&result[k], out, out_pos, bit_pos[j]+k );
											fprintf(flog, "(%d:%d), ", result[k], expected[k]);
										}
										fprintf(flog, "\n");
									}
								}
							}
						}
					}
				}
			}
		}
	}
}



void testBasicCompareDWordBlockCommand(void)
{
	char log[] = "err_comp_dwrd_blk.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare dword block LOG file open error !\n");
		exit(1);
	}

#if 0
	test_blk_comp_DW1DW2BR3K4(3, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
#else
	test_blk_comp_DW1DW2BR3W4(0, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3W4(1, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DW1DW2BR3K4(2, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3K4(3, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DW1DW2BR3N4(4, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3N4(5, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DW1DW2BR3Idx4(6, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3Idx4(7, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DW1DW2WB3W4(8, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3W4(9, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DW1DW2WB3K4(10, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3K4(11, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DW1DW2WB3N4(12, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3N4(13, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DW1DW2WB3Idx4(14, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3Idx4(15, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);

	test_blk_comp_DK1DW2BR3W4(16, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3W4(17, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DK1DW2BR3K4(18, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3K4(19, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DK1DW2BR3N4(20, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3N4(21, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DK1DW2BR3Idx4(22, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3Idx4(23, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DK1DW2WB3W4(24, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3W4(25, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DK1DW2WB3K4(26, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3K4(27, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DK1DW2WB3N4(28, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3N4(29, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);
	test_blk_comp_DK1DW2WB3Idx4(30, ML_CODE_DBKCMPEQ, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3Idx4(31, ML_CODE_DBKCMPEQ, 1, (uint8 *)dblk_eq);

	test_blk_comp_DW1DW2BR3W4(32, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3W4(33, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DW1DW2BR3K4(34, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3K4(35, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DW1DW2BR3N4(36, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3N4(37, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DW1DW2BR3Idx4(38, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3Idx4(39, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DW1DW2WB3W4(40, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3W4(41, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DW1DW2WB3K4(42, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3K4(43, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DW1DW2WB3N4(44, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3N4(45, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DW1DW2WB3Idx4(46, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3Idx4(47, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);

	test_blk_comp_DK1DW2BR3W4(48, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3W4(49, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DK1DW2BR3K4(50, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3K4(51, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DK1DW2BR3N4(52, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3N4(53, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DK1DW2BR3Idx4(54, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3Idx4(55, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DK1DW2WB3W4(56, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3W4(57, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DK1DW2WB3K4(58, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3K4(59, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DK1DW2WB3N4(60, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3N4(61, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);
	test_blk_comp_DK1DW2WB3Idx4(62, ML_CODE_DBKCMPNE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3Idx4(63, ML_CODE_DBKCMPNE, 1, (uint8 *)dblk_ne);

	test_blk_comp_DW1DW2BR3W4(64, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3W4(65, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DW1DW2BR3K4(66, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3K4(67, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DW1DW2BR3N4(68, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3N4(69, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DW1DW2BR3Idx4(70, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3Idx4(71, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DW1DW2WB3W4(72, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3W4(73, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DW1DW2WB3K4(74, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3K4(75, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DW1DW2WB3N4(76, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3N4(77, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DW1DW2WB3Idx4(78, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3Idx4(79, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);

	test_blk_comp_DK1DW2BR3W4(80, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3W4(81, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DK1DW2BR3K4(82, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3K4(83, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DK1DW2BR3N4(84, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3N4(85, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DK1DW2BR3Idx4(86, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3Idx4(87, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DK1DW2WB3W4(88, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3W4(89, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DK1DW2WB3K4(90, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3K4(91, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DK1DW2WB3N4(92, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3N4(93, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);
	test_blk_comp_DK1DW2WB3Idx4(94, ML_CODE_DBKCMPGT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3Idx4(95, ML_CODE_DBKCMPGT, 1, (uint8 *)dblk_gt);

	test_blk_comp_DW1DW2BR3W4(96, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3W4(97, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DW1DW2BR3K4(98, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3K4(99, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DW1DW2BR3N4(100, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3N4(101, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DW1DW2BR3Idx4(102, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3Idx4(103, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DW1DW2WB3W4(104, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3W4(105, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DW1DW2WB3K4(106, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3K4(107, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DW1DW2WB3N4(108, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3N4(109, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DW1DW2WB3Idx4(110, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3Idx4(111, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);

	test_blk_comp_DK1DW2BR3W4(112, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3W4(113, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DK1DW2BR3K4(114, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3K4(115, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DK1DW2BR3N4(116, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3N4(117, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DK1DW2BR3Idx4(118, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3Idx4(119, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DK1DW2WB3W4(120, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3W4(121, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DK1DW2WB3K4(122, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3K4(123, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DK1DW2WB3N4(124, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3N4(125, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);
	test_blk_comp_DK1DW2WB3Idx4(126, ML_CODE_DBKCMPGE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3Idx4(127, ML_CODE_DBKCMPGE, 1, (uint8 *)dblk_ge);

	test_blk_comp_DW1DW2BR3W4(128, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3W4(129, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DW1DW2BR3K4(130, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3K4(131, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DW1DW2BR3N4(132, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3N4(133, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DW1DW2BR3Idx4(134, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3Idx4(135, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DW1DW2WB3W4(136, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3W4(137, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DW1DW2WB3K4(138, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3K4(139, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DW1DW2WB3N4(140, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3N4(141, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DW1DW2WB3Idx4(142, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3Idx4(143, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);

	test_blk_comp_DK1DW2BR3W4(144, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3W4(145, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DK1DW2BR3K4(146, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3K4(147, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DK1DW2BR3N4(148, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3N4(149, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DK1DW2BR3Idx4(150, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3Idx4(151, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DK1DW2WB3W4(152, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3W4(153, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DK1DW2WB3K4(154, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3K4(155, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DK1DW2WB3N4(156, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3N4(157, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);
	test_blk_comp_DK1DW2WB3Idx4(158, ML_CODE_DBKCMPLT, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3Idx4(159, ML_CODE_DBKCMPLT, 1, (uint8 *)dblk_lt);

	test_blk_comp_DW1DW2BR3W4(160, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3W4(161, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DW1DW2BR3K4(162, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3K4(163, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DW1DW2BR3N4(164, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3N4(165, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DW1DW2BR3Idx4(166, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2BR3Idx4(167, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DW1DW2WB3W4(168, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3W4(169, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DW1DW2WB3K4(170, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3K4(171, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DW1DW2WB3N4(172, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3N4(173, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DW1DW2WB3Idx4(174, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DW1DW2WB3Idx4(175, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);

	test_blk_comp_DK1DW2BR3W4(176, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3W4(177, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DK1DW2BR3K4(178, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3K4(179, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DK1DW2BR3N4(180, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3N4(181, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DK1DW2BR3Idx4(182, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2BR3Idx4(183, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DK1DW2WB3W4(184, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3W4(185, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DK1DW2WB3K4(186, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3K4(187, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DK1DW2WB3N4(188, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3N4(189, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
	test_blk_comp_DK1DW2WB3Idx4(190, ML_CODE_DBKCMPLE, 0, (uint8 *)dblk_off);
	test_blk_comp_DK1DW2WB3Idx4(191, ML_CODE_DBKCMPLE, 1, (uint8 *)dblk_le);
#endif

	fclose(flog);
}
#endif
