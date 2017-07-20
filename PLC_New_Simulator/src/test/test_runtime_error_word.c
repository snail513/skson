/*
 * test_runtime_error_2word.c
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
} devWD_st;

typedef struct {
	uint8 reg;
	uint16 pos;
	short val;
	uint16 idx_pos;
	uint16 idx_val;
} devWDZ_st;

typedef struct {
	int tno;
	uint16 ml_cmd;
	int on_off;
	int op_cnt;
	int (*setCode)(uint16, int, devWD_st *);
	void (*setInput)(int, devWD_st *, int);
	devWD_st *op;
	short expected;

} testCaseWD_st;

typedef struct {
	int tno;
	uint16 ml_cmd;
	int on_off;
	int op_cnt;
	int (*setCode)(uint16, int, devWDZ_st *);
	void (*setInput)(int, devWDZ_st *, int);
	devWDZ_st *op;
	short expected;

} testCaseWDZ_st;

int setCodeOp_WD(uint16 ml_cmd, int cnt, devWD_st op[])
{
	int i;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
		for(i=0; i<cnt; i++)
		{
			addMLOperand(op[i].reg, op[i].pos);
			printf("setCodeOp_WD : i=%d reg=%d pos=%d\n", i, op[i].reg, op[i].pos);
		}
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_WDNB(uint16 ml_cmd, int cnt, devWD_st op[])
{
	int i;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
		for(i=0; i<cnt; i++)
		{
			addMLOperandNibble(4, op[i].reg, op[i].pos);
			printf("setCodeOp_WDNB : i=%d reg=%d pos=%d\n", i, op[i].reg, op[i].pos);
		}
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_WDZ(uint16 ml_cmd, int cnt, devWDZ_st op[])
{
	int i;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
	for(i=0; i<cnt; i++)
	{
		addMLOperandZIndex(op[i].reg, op[i].pos, op[i].idx_pos);
		printf("setCodeOp_WDZ : i=%d reg=%d pos=%d Z[%d]=%d\n", i, op[i].reg, op[i].pos, op[i].idx_pos, op[i].idx_val);
	}
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp_WD(int cnt, devWD_st op[], int on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<cnt; i++)
	{
		addDeviceControlInstruction(0, op[i].reg, op[i].pos, op[i].val);
		printf("setInputOp_WD : i=%d reg=%d pos=%d val=%d\n", i, op[i].reg, op[i].pos, op[i].val);
	}

	TestCodeTearDown();
}

void setInputOp_WDNB(int cnt, devWD_st op[], int on_off)
{
	int i, j;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<cnt; i++)
	{
		for(j=0; j<16; j++)
		{
			addDeviceControlInstruction(0, op[i].reg, op[i].pos+j, ((op[i].val>>j)&0x01));
		}
		printf("setInputOp_WDNB : i=%d reg=%d pos=%d val=%d\n", i, op[i].reg, op[i].pos, op[i].val);
	}

	TestCodeTearDown();
}

void setInputOp_WDZ(int cnt, devWDZ_st op[], int on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<cnt; i++)
	{
		PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, op[i].idx_pos, op[i].idx_val);
		addDeviceControlInstruction(0, op[i].reg, op[i].pos, op[i].val+op[i].idx_val);
		printf("setInputOp_WDZ : i=%d reg=%d pos=%d+%d val=%d\n", i, op[i].reg, op[i].pos, op[i].idx_val, op[i].val);
	}

	TestCodeTearDown();
}

void test_word(testCaseWD_st tCase)
{
	int rc1=0, rc2=0;

	PLC_DEVICE_Init();

	rc2 = tCase.setCode(tCase.ml_cmd, tCase.op_cnt, tCase.op);
	if( rc2 == 0 ) return;

	tCase.setInput(tCase.op_cnt, tCase.op, tCase.on_off);

	rc1=runTestCode(tCase.on_off, "runtime error test");
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

void test_wordz(testCaseWDZ_st tCase)
{
	int rc1=0, rc2=0;

	PLC_DEVICE_Init();

	rc2 = tCase.setCode(tCase.ml_cmd, tCase.op_cnt, tCase.op);
	if( rc2 == 0 ) return;

	tCase.setInput(tCase.op_cnt, tCase.op, tCase.on_off);

	rc1=runTestCode(tCase.on_off, "runtime error test");
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

static devWD_st wDiv0_op[]=
{
	{OPERAND_ML_CODE_D,500,1024},
	{OPERAND_ML_CODE_D,1000,0},
	{OPERAND_ML_CODE_D,1500,0},
};

static devWD_st wWrongRangeNB_op[]=
{
	{OPERAND_ML_CODE_X,8192,1024},
	{OPERAND_ML_CODE_X,1024,100},
	{OPERAND_ML_CODE_X,2048,0},
};

static devWD_st wDiv0nb_op[]=
{
	{OPERAND_ML_CODE_X,480,1024},
	{OPERAND_ML_CODE_X,1024,0},
	{OPERAND_ML_CODE_X,2048,0},
};

static devWD_st wWrongBCD_op1[]=
{
	{OPERAND_ML_CODE_D,500,0x999A},
	{OPERAND_ML_CODE_D,1000,0x256},
	{OPERAND_ML_CODE_D,1500,0},
};

static devWD_st wWrongBCDnb_op1[]=
{
	{OPERAND_ML_CODE_X,480,0x999A},
	{OPERAND_ML_CODE_X,1024,0x256},
	{OPERAND_ML_CODE_X,2048,0},
};

static devWD_st wWrongBCD_op2[]=
{
	{OPERAND_ML_CODE_D,500,0x5000},
	{OPERAND_ML_CODE_D,1000,0x999A},
	{OPERAND_ML_CODE_D,1500,0},
};

static devWD_st wWrongBCDSum_op[]=
{
	{OPERAND_ML_CODE_D,500,0x5000},
	{OPERAND_ML_CODE_D,1000,0x5000},
	{OPERAND_ML_CODE_D,1500,0},
};

static devWD_st wWrongBCDSumnb_op[]=
{
	{OPERAND_ML_CODE_X,480,0x5000},
	{OPERAND_ML_CODE_X,1024,0x5000},
	{OPERAND_ML_CODE_X,2048,0},
};

static devWD_st wWrongB2BCD_op1[]=
{
	{OPERAND_ML_CODE_D,500,10000},
	{OPERAND_ML_CODE_D,1000,0},
	{OPERAND_ML_CODE_D,1500,0},
};

static devWD_st wWrongB2BCDnb_op1[]=
{
	{OPERAND_ML_CODE_X,480,10000},
	{OPERAND_ML_CODE_X,1024,0},
	{OPERAND_ML_CODE_X,2048,0},
};

static devWD_st wWrongBCD2B_op1[]=
{
	{OPERAND_ML_CODE_D,500,0x999A},
	{OPERAND_ML_CODE_D,1000,0},
	{OPERAND_ML_CODE_D,1500,0},
};

static devWD_st wWrongBCD2Bnb_op1[]=
{
	{OPERAND_ML_CODE_X,480,0x999A},
	{OPERAND_ML_CODE_X,1024,0},
	{OPERAND_ML_CODE_X,2048,0},
};

static devWD_st wWrongGray_op1[]=
{
	{OPERAND_ML_CODE_D,500,-100},
	{OPERAND_ML_CODE_D,1000,0},
	{OPERAND_ML_CODE_D,1500,0},
};

static devWD_st wWrongGraynb_op1[]=
{
	{OPERAND_ML_CODE_X,480,-100},
	{OPERAND_ML_CODE_X,1024,0},
	{OPERAND_ML_CODE_X,2048,0},
};

static testCaseWD_st tCaseWD[]={
	{ 0, ML_CODE_DIV, 1, 3, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wDiv0_op, RUNTIME_ERR_DIVIDE_BY_ZERO},
	{ 1, ML_CODE_DIV, 1, 3, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongRangeNB_op, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 2, ML_CODE_DIV, 1, 3, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wDiv0_op, RUNTIME_ERR_DIVIDE_BY_ZERO},

	{ 3, ML_CODE_DIVP, 2, 3, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wDiv0_op, RUNTIME_ERR_DIVIDE_BY_ZERO},
	{ 4, ML_CODE_DIVP, 2, 3, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongRangeNB_op, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 5, ML_CODE_DIVP, 2, 3, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wDiv0nb_op, RUNTIME_ERR_DIVIDE_BY_ZERO},

	{ 6, ML_CODE_BADD, 1, 2, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongBCD_op1, RUNTIME_ERR_INVALID_BCD},
	{ 7, ML_CODE_BADD, 1, 2, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongBCD_op2, RUNTIME_ERR_INVALID_BCD},
	{ 8, ML_CODE_BADD, 1, 2, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongBCDSum_op, RUNTIME_ERR_INVALID_BCD},
	{ 9, ML_CODE_BADD, 1, 2, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongBCDnb_op1, RUNTIME_ERR_INVALID_BCD},
	{10, ML_CODE_BADD, 1, 2, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongBCDSumnb_op, RUNTIME_ERR_INVALID_BCD},

	{11, ML_CODE_BADDS, 1, 3, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongBCD_op1, RUNTIME_ERR_INVALID_BCD},
	{12, ML_CODE_BADDS, 1, 3, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongBCD_op2, RUNTIME_ERR_INVALID_BCD},
	{13, ML_CODE_BADDS, 1, 3, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongBCDSum_op, RUNTIME_ERR_INVALID_BCD},
	{14, ML_CODE_BADDS, 1, 3, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongBCDnb_op1, RUNTIME_ERR_INVALID_BCD},
	{15, ML_CODE_BADDS, 1, 3, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongBCDSumnb_op, RUNTIME_ERR_INVALID_BCD},

	{16, ML_CODE_BMLT, 1, 3, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongBCD_op1, RUNTIME_ERR_INVALID_BCD},
	{17, ML_CODE_BMLT, 1, 3, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongBCD_op2, RUNTIME_ERR_INVALID_BCD},
	{18, ML_CODE_BMLT, 1, 3, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongBCDnb_op1, RUNTIME_ERR_INVALID_BCD},

	{19, ML_CODE_BTOBCD, 1, 2, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongB2BCD_op1, RUNTIME_ERR_INVALID_BCD},
	{20, ML_CODE_BTOBCD, 1, 2, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongB2BCDnb_op1, RUNTIME_ERR_INVALID_BCD},

	{21, ML_CODE_BCDTOB, 1, 2, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongBCD2B_op1, RUNTIME_ERR_INVALID_BCD},
	{22, ML_CODE_BCDTOB, 1, 2, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongBCD2Bnb_op1, RUNTIME_ERR_INVALID_BCD},

	{23, ML_CODE_BTOGRY, 1, 2, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongGray_op1, RUNTIME_ERR_INVALID_GRAY_CODE},
	{24, ML_CODE_BTOGRY, 1, 2, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongGraynb_op1, RUNTIME_ERR_INVALID_GRAY_CODE},

	{25, ML_CODE_GRYTOB, 1, 2, setCodeOp_WD, setInputOp_WD,
		(devWD_st *)wWrongGray_op1, RUNTIME_ERR_INVALID_GRAY_CODE},
	{26, ML_CODE_GRYTOB, 1, 2, setCodeOp_WDNB, setInputOp_WDNB,
		(devWD_st *)wWrongGraynb_op1, RUNTIME_ERR_INVALID_GRAY_CODE},

		/*
	{15, ML_CODE_BADDP, 2, 2, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0,0x9999999A},
		{OPERAND_ML_CODE_D,10,0x123456}, RUNTIME_ERR_INVALID_BCD},
	{16, ML_CODE_BADDP, 2, 2, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0, 0x12345678},
		{OPERAND_ML_CODE_D,100,0x9999999A}, RUNTIME_ERR_INVALID_BCD},
	{17, ML_CODE_BADDP, 2, 2, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0, 0x50000000},
		{OPERAND_ML_CODE_D,200,0x50000000}, RUNTIME_ERR_INVALID_BCD},

	{18, ML_CODE_BSUB, 1, 1, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0,0x9999999A},
		{OPERAND_ML_CODE_D,10,0x123456}, RUNTIME_ERR_INVALID_BCD},
	{19, ML_CODE_BSUB, 1, 1, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0, 0x12345678},
		{OPERAND_ML_CODE_D,100,0x9999999A}, RUNTIME_ERR_INVALID_BCD},
	{20, ML_CODE_BSUB, 1, 1, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0, 0x50000000},
		{OPERAND_ML_CODE_D,200,0x50000000}, RUNTIME_ERR_INVALID_BCD},

	{21, ML_CODE_BSUBP, 2, 2, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0,0x9999999A},
		{OPERAND_ML_CODE_D,10,0x123456}, RUNTIME_ERR_INVALID_BCD},
	{22, ML_CODE_BSUBP, 2, 2, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0, 0x12345678},
		{OPERAND_ML_CODE_D,100,0x9999999A}, RUNTIME_ERR_INVALID_BCD},
	{23, ML_CODE_BSUBP, 2, 2, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0, 0x50000000},
		{OPERAND_ML_CODE_D,200,0x50000000}, RUNTIME_ERR_INVALID_BCD},


	{12, ML_CODE_DBADD, 1, 1, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0,0x9999999A},
		{OPERAND_ML_CODE_D,10,0x123456}, RUNTIME_ERR_INVALID_BCD},
	{13, ML_CODE_BADD, 1, 1, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0, 0x12345678},
		{OPERAND_ML_CODE_D,100,0x9999999A}, RUNTIME_ERR_INVALID_BCD},
	{14, ML_CODE_BADD, 1, 1, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0, 0x50000000},
		{OPERAND_ML_CODE_D,200,0x50000000}, RUNTIME_ERR_INVALID_BCD},

	{24, ML_CODE_DTOB, 1, 1, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0,32768},
		{OPERAND_ML_CODE_D,10,0}, RUNTIME_ERR_INTEGER_RANGE_OVER},

	{26, ML_CODE_DTOGRY, 1, 1, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0,-100},
		{OPERAND_ML_CODE_D,200,0}, RUNTIME_ERR_INVALID_GRAY_CODE},

	{28, ML_CODE_GRYTOD, 1, 1, setCodeOp2_WD, setInputOp2_DW, {OPERAND_ML_CODE_D,0,-100},
		{OPERAND_ML_CODE_D,200,0}, RUNTIME_ERR_INVALID_GRAY_CODE},
*/
	{ -1, 0, 0, 0, NULL, NULL, NULL, 0 }
};


static devWDZ_st wzDiv0_op[]=
{
	{OPERAND_ML_CODE_D,500,1024, 5, 100},
	{OPERAND_ML_CODE_D,1000,0, 10, 200},
	{OPERAND_ML_CODE_D,1500,0, 15, 300},
};

static devWDZ_st wzWrongZRange_op[]=
{
	{OPERAND_ML_CODE_D,500,1024, 16, 100},
	{OPERAND_ML_CODE_D,1000,0, 10, 200},
	{OPERAND_ML_CODE_D,1500,0, 15, 300},
};

static devWDZ_st wzWrongBCD_op1[]=
{
	{OPERAND_ML_CODE_D,500,0x999A, 5, 100},
	{OPERAND_ML_CODE_D,1000,0x256, 10, 200},
	{OPERAND_ML_CODE_D,1500,0, 15, 300},
};

static devWDZ_st wzWrongBCD_op2[]=
{
	{OPERAND_ML_CODE_D,500,0x5000, 5, 100},
	{OPERAND_ML_CODE_D,1000,0x999A, 10, 200},
	{OPERAND_ML_CODE_D,1500,0, 15, 300},
};

static devWDZ_st wzWrongBCDSum_op[]=
{
	{OPERAND_ML_CODE_D,500,0x5000, 5, 100},
	{OPERAND_ML_CODE_D,1000,0x5000, 10, 200},
	{OPERAND_ML_CODE_D,1500,0, 15, 300},
};

static devWDZ_st wzWrongB2BCD_op1[]=
{
	{OPERAND_ML_CODE_D,500,10000, 5, 100},
	{OPERAND_ML_CODE_D,1000,0, 10, 200},
	{OPERAND_ML_CODE_D,1500,0, 15, 300},
};

static devWDZ_st wzWrongBCD2B_op1[]=
{
	{OPERAND_ML_CODE_D,500,0x999A, 5, 100},
	{OPERAND_ML_CODE_D,1000,0, 10, 200},
	{OPERAND_ML_CODE_D,1500,0, 15, 300},
};

static devWDZ_st wzWrongGray_op1[]=
{
	{OPERAND_ML_CODE_D,500,-100, 5, 100},
	{OPERAND_ML_CODE_D,1000,0, 10, 200},
	{OPERAND_ML_CODE_D,1500,0, 15, 300},
};


static testCaseWDZ_st tCaseWDZ[]={
	{ 0, ML_CODE_DIV, 1, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzDiv0_op, RUNTIME_ERR_DIVIDE_BY_ZERO},
	{ 1, ML_CODE_DIV, 1, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongZRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{ 2, ML_CODE_DIVP, 2, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzDiv0_op, RUNTIME_ERR_DIVIDE_BY_ZERO},
	{ 3, ML_CODE_DIVP, 2, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongZRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{ 4, ML_CODE_BADD, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongBCD_op1, RUNTIME_ERR_INVALID_BCD},
	{ 5, ML_CODE_BADD, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongBCD_op2, RUNTIME_ERR_INVALID_BCD},
	{ 6, ML_CODE_BADD, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongBCDSum_op, RUNTIME_ERR_INVALID_BCD},
	{ 7, ML_CODE_BADD, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongZRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{8, ML_CODE_BADDS, 1, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongBCD_op1, RUNTIME_ERR_INVALID_BCD},
	{9, ML_CODE_BADDS, 1, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongBCD_op2, RUNTIME_ERR_INVALID_BCD},
	{10, ML_CODE_BADDS, 1, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongBCDSum_op, RUNTIME_ERR_INVALID_BCD},
	{11, ML_CODE_BADDS, 1, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongZRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{12, ML_CODE_BMLT, 1, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongBCD_op1, RUNTIME_ERR_INVALID_BCD},
	{13, ML_CODE_BMLT, 1, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongBCD_op2, RUNTIME_ERR_INVALID_BCD},
	{14, ML_CODE_BMLT, 1, 3, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongZRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{16, ML_CODE_BTOBCD, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongB2BCD_op1, RUNTIME_ERR_INVALID_BCD},
	{17, ML_CODE_BTOBCD, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongZRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{18, ML_CODE_BCDTOB, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongBCD2B_op1, RUNTIME_ERR_INVALID_BCD},
	{19, ML_CODE_BCDTOB, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongZRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{20, ML_CODE_BTOGRY, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongGray_op1, RUNTIME_ERR_INVALID_GRAY_CODE},
	{21, ML_CODE_BTOGRY, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongZRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{22, ML_CODE_GRYTOB, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongGray_op1, RUNTIME_ERR_INVALID_GRAY_CODE},
	{23, ML_CODE_GRYTOB, 1, 2, setCodeOp_WDZ, setInputOp_WDZ,
		(devWDZ_st *)wzWrongZRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{ -1, 0, 0, 0, NULL, NULL, NULL, 0 }
};

void testRuntimeErrorWD(void)
{
	int index=20;

	printf("run test testRuntimeErrorWD() tno=%d\n", index);

#if 1
	//test_word(tCaseWD[index]);
	test_wordz(tCaseWDZ[index]);
#else
	for(index=0; index<10; index++)
		test_word(tCaseWD[index]);

	printf("run test testRuntimeErrorWD index() tno=%d\n\n", index);
	for(index=0; index<23; index++)
		test_wordz(tCaseWDZ[index]);
#endif
}

#endif
