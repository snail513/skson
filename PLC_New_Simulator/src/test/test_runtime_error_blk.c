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


typedef struct {
	uint8 reg;
	uint16 pos;
	short val;
	uint16 bit_pos;
} devWB_st;

typedef struct {
	uint8 reg;
	uint16 pos;
	short val;
} devWD_st;

typedef struct {
	int tno;
	uint16 ml_cmd;
	int on_off;
	int op_cnt;
	int (*setCode)(uint16, int, devWB_st *, devWD_st cnt);
	void (*setInput)(int, devWB_st *, devWD_st cnt, int);
	devWB_st *op;
	devWD_st cnt;
	uint16 expected;

} testCaseBlk_st;

devWB_st wCmpNormalNegCnt[]={
	{OPERAND_ML_CODE_D, 50, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_X, 500, 0, 0},
};

devWB_st wCmpRangeOver_S1[]={
	{OPERAND_ML_CODE_D, 12285, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_X, 500, 0, 0},
};

devWB_st wCmpRangeOver_S2[]={
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 12285, 10, 0},
	{OPERAND_ML_CODE_X, 500, 0, 0},
};

devWB_st wCmpRangeOver_D[]={
	{OPERAND_ML_CODE_D, 50, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_X, 8176, 0, 0},
};

devWB_st wCmpOverlapS1[]={
	{OPERAND_ML_CODE_D, 50, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 51, 0, 8},  // overlap with S1
};

devWB_st wCmpOverlapS2[]={
	{OPERAND_ML_CODE_D, 50, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 201, 0, 8},  // overlap with S2
};

devWB_st wNormalNegCnt[]={
	{OPERAND_ML_CODE_D, 50, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 500, 0, 0},
};

devWB_st wNormalNegCntNB[]={
	{OPERAND_ML_CODE_X, 64, 10, 0},
	{OPERAND_ML_CODE_Y, 192, 10, 0},
	{OPERAND_ML_CODE_D, 500, 0, 0},
};

devWB_st wRangeOver_S1[]={
	{OPERAND_ML_CODE_D, 12285, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 500, 0, 0},
};

devWB_st wRangeOverNB_S1[]={
	{OPERAND_ML_CODE_X, 8176, 10, 0},
	{OPERAND_ML_CODE_Y, 192, 10, 0},
	{OPERAND_ML_CODE_D, 500, 0, 0},
};

devWB_st wRangeOver_S2[]={
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 12285, 10, 0},
	{OPERAND_ML_CODE_D, 500, 0, 0},
};

devWB_st wRangeOverNB_S2[]={
	{OPERAND_ML_CODE_X, 64, 10, 0},
	{OPERAND_ML_CODE_Y, 8176, 10, 0},
	{OPERAND_ML_CODE_D, 500, 0, 0},
};

devWB_st wRangeOver_D[]={
	{OPERAND_ML_CODE_D, 50, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 12285, 0, 0},
};

devWB_st wOverlapS1[]={
	{OPERAND_ML_CODE_D, 50, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 69, 0, 0},  // overlap with S1
};

devWB_st wOverlapS2[]={
	{OPERAND_ML_CODE_D, 50, 10, 0},
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 219, 0, 0},  // overlap with S2
};

devWB_st wOverlap[]={
	{OPERAND_ML_CODE_D, 50, 10, 0},
	{OPERAND_ML_CODE_D, 69, 10, 0},
	{OPERAND_ML_CODE_D, 500, 0, 0},  // overlap with S and D
};

devWB_st wWrongBCD[]={
	{OPERAND_ML_CODE_D, 50, 10000, 0}, // invalid BCD value
	{OPERAND_ML_CODE_D, 200, 10, 0},
	{OPERAND_ML_CODE_D, 500, 0, 0},
};

int setCodeOpBlk_WD(uint16 ml_cmd, int op_cnt, devWB_st op[], devWD_st cnt)
{
	int i;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
	for(i=0; i<op_cnt; i++)
	{
		addMLOperand(op[i].reg, op[i].pos);
	}
		addMLOperand(cnt.reg, cnt.pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOpBlk_WDNB(uint16 ml_cmd, int op_cnt, devWB_st op[], devWD_st cnt)
{
	int i;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
	for(i=0; i<op_cnt; i++)
	{
		addMLOperand(op[i].reg, op[i].pos);
	}
		addMLOperandNibble(4, cnt.reg, cnt.pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOpBlkCMP_WB(uint16 ml_cmd, int op_cnt, devWB_st op[], devWD_st cnt)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
		addMLOperand(op[0].reg, op[0].pos); addMLOperand(op[1].reg, op[1].pos);
		addMLOperandWordBit(op[2].reg, op[2].pos, op[2].bit_pos); addMLOperand(cnt.reg, cnt.pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOpBlkCMP_WBNB(uint16 ml_cmd, int op_cnt, devWB_st op[], devWD_st cnt)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
		addMLOperand(op[0].reg, op[0].pos); addMLOperand(op[1].reg, op[1].pos);
		addMLOperandWordBit(op[2].reg, op[2].pos, op[2].bit_pos); addMLOperandNibble(4, cnt.reg, cnt.pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOpBlk_NB(uint16 ml_cmd, int op_cnt, devWB_st op[], devWD_st cnt)
{
	int i;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
	for(i=0; i<op_cnt; i++)
	{
		addMLOperandNibble(4, op[i].reg, op[i].pos);
	}
		addMLOperand(cnt.reg, cnt.pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputOpBlk_WD(int op_cnt, devWB_st op[], devWD_st cnt, int on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<op_cnt; i++)
	{
		addDeviceControlInstruction(0, op[i].reg, op[i].pos, op[i].val);
		printf("setInputOpBlk_WD : i=%d reg=%d pos=%d val=%d\n", i, op[i].reg, op[i].pos, op[i].val);
	}
	addDeviceControlInstruction(0, cnt.reg, cnt.pos, cnt.val);

	TestCodeTearDown();
}

void setInputOpBlk_NB(int op_cnt, devWB_st op[], devWD_st cnt, int on_off)
{
	int i, j;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<op_cnt; i++)
	{
		for(j=0; j<16; j++)
		{
			addDeviceControlInstruction(0, op[i].reg, op[i].pos+j, ((op[i].val>>j)&0x01));
		}
		printf("setInputOpBlk_WD : i=%d reg=%d pos=%d val=%d\n", i, op[i].reg, op[i].pos, op[i].val);
	}
	addDeviceControlInstruction(0, cnt.reg, cnt.pos, cnt.val);

	TestCodeTearDown();
}

void setInputOpBlk_WDNB(int op_cnt, devWB_st op[], devWD_st cnt, int on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<op_cnt; i++)
	{
		addDeviceControlInstruction(0, op[i].reg, op[i].pos, op[i].val);
		printf("setInputOpBlk_WD : i=%d reg=%d pos=%d val=%d\n", i, op[i].reg, op[i].pos, op[i].val);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, cnt.reg, cnt.pos+i, ((cnt.val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOpBlk_DW(int op_cnt, devWB_st op[], devWD_st cnt, int on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<op_cnt; i++)
	{
		addDeviceControlInstructionToDWord(0, op[i].reg, op[i].pos, (int)op[i].val);
		printf("setInputOpBlk_WD : i=%d reg=%d pos=%d val=%d\n", i, op[i].reg, op[i].pos, op[i].val);
	}
	addDeviceControlInstruction(0, cnt.reg, cnt.pos, cnt.val);

	TestCodeTearDown();
}

void setInputOpBlk_DWD(int op_cnt, devWB_st op[], devWD_st cnt, int on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<op_cnt; i++)
	{
		addDeviceControlInstructionToDWord(0, op[i].reg, op[i].pos, (int)op[i].val);
		printf("setInputOpBlk_WD : i=%d reg=%d pos=%d val=%d\n", i, op[i].reg, op[i].pos, op[i].val);
	}
	addDeviceControlInstruction(0, cnt.reg, cnt.pos, cnt.val);

	TestCodeTearDown();
}

void setInputOpBlk_DWDNB(int op_cnt, devWB_st op[], devWD_st cnt, int on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<op_cnt; i++)
	{
		addDeviceControlInstructionToDWord(0, op[i].reg, op[i].pos, (int)op[i].val);
		printf("setInputOpBlk_WD : i=%d reg=%d pos=%d val=%d\n", i, op[i].reg, op[i].pos, op[i].val);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, cnt.reg, cnt.pos+i, ((cnt.val>>i)&0x01));
	}

	TestCodeTearDown();
}

static testCaseBlk_st tCaseBlk[]={
	{ 0, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wCmpNormalNegCnt, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{ 1, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wCmpRangeOver_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 2, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wCmpRangeOver_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 3, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wCmpRangeOver_D, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 4, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlkCMP_WB, setInputOpBlk_WD,
		(devWB_st *)wCmpOverlapS1, {OPERAND_ML_CODE_D, 160, 50}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 5, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlkCMP_WB, setInputOpBlk_WD,
		(devWB_st *)wCmpOverlapS2, {OPERAND_ML_CODE_D, 160, 50}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 6, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wCmpNormalNegCnt, {OPERAND_ML_CODE_X, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{ 7, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wCmpRangeOver_S1, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 8, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wCmpRangeOver_S2, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 9, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wCmpRangeOver_D, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{10, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlkCMP_WBNB, setInputOpBlk_WDNB,
		(devWB_st *)wCmpOverlapS1, {OPERAND_ML_CODE_X, 160, 50}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{11, ML_CODE_BKCMPEQ, 1, 3, setCodeOpBlkCMP_WBNB, setInputOpBlk_WDNB,
		(devWB_st *)wCmpOverlapS2, {OPERAND_ML_CODE_X, 160, 50}, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{12, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlk_WD, setInputOpBlk_DW,
		(devWB_st *)wCmpNormalNegCnt, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{13, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlk_WD, setInputOpBlk_DW,
		(devWB_st *)wCmpRangeOver_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{14, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlk_WD, setInputOpBlk_DW,
		(devWB_st *)wCmpRangeOver_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{15, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlk_WD, setInputOpBlk_DW,
		(devWB_st *)wCmpRangeOver_D, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{16, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlkCMP_WB, setInputOpBlk_DWD,
		(devWB_st *)wCmpOverlapS1, {OPERAND_ML_CODE_D, 160, 50}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{17, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlkCMP_WB, setInputOpBlk_DWD,
		(devWB_st *)wCmpOverlapS2, {OPERAND_ML_CODE_D, 160, 50}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{18, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_DWDNB,
		(devWB_st *)wCmpNormalNegCnt, {OPERAND_ML_CODE_X, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{19, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_DWDNB,
		(devWB_st *)wCmpRangeOver_S1, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{20, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_DWDNB,
		(devWB_st *)wCmpRangeOver_S2, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{21, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_DWDNB,
		(devWB_st *)wCmpRangeOver_D, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{22, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlkCMP_WBNB, setInputOpBlk_DWDNB,
		(devWB_st *)wCmpOverlapS1, {OPERAND_ML_CODE_X, 160, 50}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{23, ML_CODE_DBKCMPEQ, 1, 3, setCodeOpBlkCMP_WBNB, setInputOpBlk_DWDNB,
		(devWB_st *)wCmpOverlapS2, {OPERAND_ML_CODE_X, 160, 50}, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{24, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{25, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{26, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{27, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_D, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{28, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wOverlapS1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{29, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wOverlapS2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{30, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_X, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{30, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{32, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{33, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_D, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{34, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wOverlapS1, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{35, ML_CODE_BKADD, 1, 3, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wOverlapS2, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{36, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{37, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{38, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{39, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wOverlap, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{40, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wWrongBCD, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_INVALID_BCD},
	{41, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_X, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{42, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{43, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{44, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wOverlap, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{45, ML_CODE_BLKTOBCD, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wWrongBCD, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_INVALID_BCD},

	{46, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{47, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{48, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{49, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wOverlap, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{50, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wWrongBCD, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_INVALID_BCD},
	{51, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_X, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{52, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{53, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{54, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wOverlap, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{55, ML_CODE_BLKTOB, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wWrongBCD, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_INVALID_BCD},

	{56, ML_CODE_BMOV, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{57, ML_CODE_BMOV, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{58, ML_CODE_BMOV, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{59, ML_CODE_BMOV, 1, 2, setCodeOpBlk_NB, setInputOpBlk_NB,
		(devWB_st *)wNormalNegCntNB, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{60, ML_CODE_BMOV, 1, 2, setCodeOpBlk_NB, setInputOpBlk_NB,
		(devWB_st *)wRangeOverNB_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{61, ML_CODE_BMOV, 1, 2, setCodeOpBlk_NB, setInputOpBlk_NB,
		(devWB_st *)wRangeOverNB_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{62, ML_CODE_BMOV, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_X, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{63, ML_CODE_BMOV, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{62, ML_CODE_BMOV, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{63, ML_CODE_FMOV, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{64, ML_CODE_FMOV, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{65, ML_CODE_FMOV, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{66, ML_CODE_FMOV, 1, 2, setCodeOpBlk_NB, setInputOpBlk_NB,
		(devWB_st *)wNormalNegCntNB, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{67, ML_CODE_FMOV, 1, 2, setCodeOpBlk_NB, setInputOpBlk_NB,
		(devWB_st *)wRangeOverNB_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{68, ML_CODE_FMOV, 1, 2, setCodeOpBlk_NB, setInputOpBlk_NB,
		(devWB_st *)wRangeOverNB_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{69, ML_CODE_FMOV, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_X, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{70, ML_CODE_FMOV, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{71, ML_CODE_FMOV, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{72, ML_CODE_BXCH, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_D, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{72, ML_CODE_BXCH, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{73, ML_CODE_BXCH, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{74, ML_CODE_BXCH, 1, 2, setCodeOpBlk_WD, setInputOpBlk_WD,
		(devWB_st *)wOverlap, {OPERAND_ML_CODE_D, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{75, ML_CODE_BXCH, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wNormalNegCnt, {OPERAND_ML_CODE_X, 160, -10}, RUNTIME_ERR_INVALID_COUNT},
	{76, ML_CODE_BXCH, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S1, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{77, ML_CODE_BXCH, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wRangeOver_S2, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{78, ML_CODE_BXCH, 1, 2, setCodeOpBlk_WDNB, setInputOpBlk_WDNB,
		(devWB_st *)wOverlap, {OPERAND_ML_CODE_X, 160, 20}, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{ -1, 0, 0, 0, NULL, NULL, NULL, {0, 0, 0}, 0 }
};

void testBlk_WD(testCaseBlk_st tCase)
{
	int rc1=0, rc2=0;
	short SD_val;

	PLC_DEVICE_Init();

	rc2 = tCase.setCode(tCase.ml_cmd, tCase.op_cnt, tCase.op, tCase.cnt);
	if( rc2 == 0 ) return;

	tCase.setInput(tCase.op_cnt, tCase.op, tCase.cnt, tCase.on_off);

	rc1=runTestCode(tCase.on_off, "runtime error test");
	if(rc1==1)
	{
		rc2=verifyErrorRegister(tCase.expected);
		if(rc2==1)
		{
			test_getWord(&SD_val, OPERAND_ML_CODE_SD, 0);
			printf("tno=%d cmd=%s Error code mismatch %d exp=%d\n", \
					tCase.tno, PLC_OPERATOR_DICTIONARY_findOperator(tCase.ml_cmd)->strName, SD_val, tCase.expected);
		}
	}
	else
	{
		CU_ASSERT_TRUE(rc1);
		printf(" tno=%d cmd=%s Runtime error should occur !! \n",
				tCase.tno, PLC_OPERATOR_DICTIONARY_findOperator(tCase.ml_cmd)->strName);
	}
}

void testRuntimeErrorBlock(void)
{
	int index=78;

#if 1
	testBlk_WD(tCaseBlk[index]);
#else
	for(index=0; index<79; index++)
		testBlk_WD(tCaseBlk[index]);

#endif

}

#endif
