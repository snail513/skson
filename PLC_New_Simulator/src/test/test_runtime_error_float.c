/*
 * test_runtime_float.c
 *
 *  Created on: Sep 5, 2015
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
	float val;
} devE_st;

typedef struct {
	uint8 reg;
	uint16 pos;
	float val;
	uint16 idx_pos;
	uint16 idx_val;
} devEZ_st;

typedef struct {
	uint8 reg;
	uint16 pos;
	double val;
} devED_st;

typedef struct {
	int tno;
	uint16 ml_cmd;
	int on_off;
	int op_cnt;
	int (*setCode)(uint16, int, devE_st *);
	void (*setInput)(int, devE_st *, int);
	devE_st *op;
	short expected;

} testCaseE_st;

typedef struct {
	int tno;
	uint16 ml_cmd;
	int on_off;
	int op_cnt;
	int (*setCode)(uint16, int, devEZ_st *);
	void (*setInput)(int, devEZ_st *, int);
	devEZ_st *op;
	short expected;

} testCaseEZ_st;

int setCodeOp_E(uint16 ml_cmd, int cnt, devE_st op[]);
int setCodeOp_CMPLDE(uint16 ml_cmd, int cnt, devE_st op[]);
int setCodeOp_CMPE(uint16 ml_cmd, int cnt, devE_st op[]);
int setCodeOp_EZ(uint16 ml_cmd, int cnt, devEZ_st op[]);
void setInputOp_E(int cnt, devE_st op[], int on_off);
void setInputOp_CMPLD_E(int cnt, devE_st op[], int on_off);
void setInputOp_CMP_E(int cnt, devE_st op[], int on_off);
void setInputOp_EZ(int cnt, devEZ_st op[], int on_off);

static devE_st fMax_op[3]={
	{OPERAND_ML_CODE_D,50,FLT_MAX},
	{OPERAND_ML_CODE_D,150,FLT_MAX},
	{OPERAND_ML_CODE_D,200,0},
};

static devE_st fMaxOver_op[3]={
	{OPERAND_ML_CODE_D,50,FLT_MAX*2.0f},
	{OPERAND_ML_CODE_D,150,FLT_MAX},
	{OPERAND_ML_CODE_D,200,0},
};

static devE_st fNegMax_op[3]={
	{OPERAND_ML_CODE_D,50,-FLT_MAX},
	{OPERAND_ML_CODE_D,150,-FLT_MAX},
	{OPERAND_ML_CODE_D,200,0},
};

static devE_st fMin_op[3]={
	{OPERAND_ML_CODE_D,50,FLT_MIN},
	{OPERAND_ML_CODE_D,150,FLT_MIN},
	{OPERAND_ML_CODE_D,200,0},
};

static devE_st fMinUnder_op[3]={
	{OPERAND_ML_CODE_D,50,FLT_MIN/2.0f},
	{OPERAND_ML_CODE_D,150,FLT_MIN},
	{OPERAND_ML_CODE_D,200,0},
};

static devE_st fInf_op[3]={
	{OPERAND_ML_CODE_D,50,INFINITY},
	{OPERAND_ML_CODE_D,150,INFINITY},
	{OPERAND_ML_CODE_D,200,0},
};

static devE_st fNan_op[3]={
	{OPERAND_ML_CODE_D,50,NAN},
	{OPERAND_ML_CODE_D,150,NAN},
	{OPERAND_ML_CODE_D,200,0},
};

static devE_st fNegZero_op[3]={
	{OPERAND_ML_CODE_D,50,-0.0f},
	{OPERAND_ML_CODE_D,150,-0.0f},
	{OPERAND_ML_CODE_D,200,0},
};

static devE_st fWrongRange_op[3]={
	{OPERAND_ML_CODE_D,-1,123.4f},
	{OPERAND_ML_CODE_D,150,-0.0f},
	{OPERAND_ML_CODE_D,200,0},
};

static devE_st fDiv0_op[3]={
	{OPERAND_ML_CODE_D,50,123.4f},
	{OPERAND_ML_CODE_D,150,0.0f},
	{OPERAND_ML_CODE_D,200,0},
};

static devEZ_st fzMax_op[3]={
	{OPERAND_ML_CODE_D,50,FLT_MAX, 5, 10},
	{OPERAND_ML_CODE_D,150,FLT_MAX, 10, 100},
	{OPERAND_ML_CODE_D,200, 15, 300},
};

static devEZ_st fzMaxOver_op[3]={
	{OPERAND_ML_CODE_D,50,FLT_MAX*2.0f, 5, 10},
	{OPERAND_ML_CODE_D,150,FLT_MAX, 10, 100},
	{OPERAND_ML_CODE_D,200,0, 15, 300},
};

static devEZ_st fzNegMax_op[3]={
	{OPERAND_ML_CODE_D,50,-FLT_MAX, 5, 10},
	{OPERAND_ML_CODE_D,150,-FLT_MAX, 10, 100},
	{OPERAND_ML_CODE_D,200,0, 15, 300},
};

static devEZ_st fzMin_op[3]={
	{OPERAND_ML_CODE_D,50,FLT_MIN, 5, 10},
	{OPERAND_ML_CODE_D,150,FLT_MIN, 10, 100},
	{OPERAND_ML_CODE_D,200,0},
};

static devEZ_st fzMinUnder_op[3]={
	{OPERAND_ML_CODE_D,50,FLT_MIN/2.0f, 5, 10},
	{OPERAND_ML_CODE_D,150,FLT_MIN, 10, 100},
	{OPERAND_ML_CODE_D,200,0, 15, 300},
};

static devEZ_st fzInf_op[3]={
	{OPERAND_ML_CODE_D,50,INFINITY, 5, 10},
	{OPERAND_ML_CODE_D,150,INFINITY, 10, 100},
	{OPERAND_ML_CODE_D,200,0, 15, 300},
};

static devEZ_st fzNan_op[3]={
	{OPERAND_ML_CODE_D,50,NAN, 5, 10},
	{OPERAND_ML_CODE_D,150,NAN, 10, 100},
	{OPERAND_ML_CODE_D,200,0, 15, 300},
};

static devEZ_st fzNegZero_op[3]={
	{OPERAND_ML_CODE_D,50,-0.0f, 5, 10},
	{OPERAND_ML_CODE_D,150,-0.0f, 10, 100},
	{OPERAND_ML_CODE_D,200,0, 15, 300},
};

static devEZ_st fzWrongRange_op[3]={
	{OPERAND_ML_CODE_D,-1,123.4f, 5, 10},
	{OPERAND_ML_CODE_D,150,-0.0f, 10, 100},
	{OPERAND_ML_CODE_D,200,0, 15, 300},
};

static devEZ_st fzWrongZRange_op[3]={
	{OPERAND_ML_CODE_D,0,123.4f, 16, 10},
	{OPERAND_ML_CODE_D,150,-0.0f, 10, 100},
	{OPERAND_ML_CODE_D,200,0, 15, 300},
};

static devEZ_st fzWrongZDRange_op[3]={
	{OPERAND_ML_CODE_D,0,123.4f, 5, 12289},
	{OPERAND_ML_CODE_D,150,-0.0f, 10, 100},
	{OPERAND_ML_CODE_D,200,0, 15, 300},
};

static testCaseE_st tCaseE[]={
	{ 0, ML_CODE_ENEG, 1, 1, setCodeOp_E, setInputOp_E,
		(devE_st *)fMaxOver_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{ 1, ML_CODE_ENEG, 1, 1, setCodeOp_E, setInputOp_E,
		(devE_st *)fMinUnder_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{ 2, ML_CODE_ENEG, 1, 1, setCodeOp_E, setInputOp_E,
		(devE_st *)fInf_op, RUNTIME_ERR_INVALID_FLOAT},
	{ 3, ML_CODE_ENEG, 1, 1, setCodeOp_E, setInputOp_E,
		(devE_st *)fNan_op, RUNTIME_ERR_INVALID_FLOAT},
	{ 4, ML_CODE_ENEG, 1, 1, setCodeOp_E, setInputOp_E,
		(devE_st *)fNegZero_op, RUNTIME_ERR_FLOAT_IS_ZERO},
	{ 5, ML_CODE_ENEG, 1, 1, setCodeOp_E, setInputOp_E,
		(devE_st *)fWrongRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{ 6, ML_CODE_EADD, 1, 2, setCodeOp_E, setInputOp_E,
		(devE_st *)fMax_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{ 7, ML_CODE_EADD, 1, 2, setCodeOp_E, setInputOp_E,
		(devE_st *)fNegMax_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{ 8, ML_CODE_EADD, 1, 2, setCodeOp_E, setInputOp_E,
		(devE_st *)fInf_op, RUNTIME_ERR_INVALID_FLOAT},

	{ 9, ML_CODE_LDEEQ, 1, 2, setCodeOp_CMPLDE, setInputOp_CMPLD_E,
		(devE_st *)fMaxOver_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{10, ML_CODE_LDEEQ, 1, 2, setCodeOp_CMPLDE, setInputOp_CMPLD_E,
		(devE_st *)fMinUnder_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{11, ML_CODE_LDEEQ, 1, 2, setCodeOp_CMPLDE, setInputOp_CMPLD_E,
		(devE_st *)fInf_op, RUNTIME_ERR_INVALID_FLOAT},
	{12, ML_CODE_LDEEQ, 1, 2, setCodeOp_CMPLDE, setInputOp_CMPLD_E,
		(devE_st *)fNan_op, RUNTIME_ERR_INVALID_FLOAT},
	{13, ML_CODE_LDEEQ, 1, 2, setCodeOp_CMPLDE, setInputOp_CMPLD_E,
		(devE_st *)fNegZero_op, RUNTIME_ERR_FLOAT_IS_ZERO},

	{14, ML_CODE_ANDEEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fInf_op, RUNTIME_ERR_INVALID_FLOAT},
	{15, ML_CODE_ANDEEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fNan_op, RUNTIME_ERR_INVALID_FLOAT},
	{16, ML_CODE_ANDEEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fNegZero_op, RUNTIME_ERR_FLOAT_IS_ZERO},
	{17, ML_CODE_ANDEEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fMinUnder_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{18, ML_CODE_ANDEEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fMaxOver_op, RUNTIME_ERR_FLOAT_RANGE_OVER},

	{19, ML_CODE_OREEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fInf_op, RUNTIME_ERR_INVALID_FLOAT},
	{20, ML_CODE_OREEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fNan_op, RUNTIME_ERR_INVALID_FLOAT},
	{21, ML_CODE_OREEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fNegZero_op, RUNTIME_ERR_FLOAT_IS_ZERO},
	{22, ML_CODE_OREEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fMinUnder_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{23, ML_CODE_OREEQ, 1, 2, setCodeOp_CMPE, setInputOp_CMPLD_E,
		(devE_st *)fMaxOver_op, RUNTIME_ERR_FLOAT_RANGE_OVER},

	{24, ML_CODE_EMLT, 1, 3, setCodeOp_E, setInputOp_E,
		(devE_st *)fMax_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{25, ML_CODE_EMLT, 1, 3, setCodeOp_E, setInputOp_E,
		(devE_st *)fNegMax_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{26, ML_CODE_EMLT, 1, 3, setCodeOp_E, setInputOp_E,
		(devE_st *)fInf_op, RUNTIME_ERR_INVALID_FLOAT},

	{27, ML_CODE_EDIV, 1, 3, setCodeOp_E, setInputOp_E,
		(devE_st *)fMax_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{28, ML_CODE_EDIV, 1, 3, setCodeOp_E, setInputOp_E,
		(devE_st *)fNegMax_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{29, ML_CODE_EDIV, 1, 3, setCodeOp_E, setInputOp_E,
		(devE_st *)fInf_op, RUNTIME_ERR_INVALID_FLOAT},
	{30, ML_CODE_EDIV, 1, 3, setCodeOp_E, setInputOp_E,
		(devE_st *)fDiv0_op, RUNTIME_ERR_DIVIDE_BY_ZERO},

	{ -1, 0, 0, 0, NULL, NULL, NULL, 0 }
};

static testCaseEZ_st tCaseEZ[]={
	{ 0, ML_CODE_ENEG, 1, 1, setCodeOp_EZ, setInputOp_EZ,
		(devEZ_st *)fzMaxOver_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{ 1, ML_CODE_ENEG, 1, 1, setCodeOp_EZ, setInputOp_EZ,
		(devEZ_st *)fzMinUnder_op, RUNTIME_ERR_FLOAT_RANGE_OVER},
	{ 2, ML_CODE_ENEG, 1, 1, setCodeOp_EZ, setInputOp_EZ,
		(devEZ_st *)fzInf_op, RUNTIME_ERR_INVALID_FLOAT},
	{ 3, ML_CODE_ENEG, 1, 1, setCodeOp_EZ, setInputOp_EZ,
		(devEZ_st *)fzNan_op, RUNTIME_ERR_INVALID_FLOAT},
	{ 4, ML_CODE_ENEG, 1, 1, setCodeOp_EZ, setInputOp_EZ,
		(devEZ_st *)fzNegZero_op, RUNTIME_ERR_FLOAT_IS_ZERO},
	{ 5, ML_CODE_ENEG, 1, 1, setCodeOp_EZ, setInputOp_EZ,
		(devEZ_st *)fzWrongRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{ 6, ML_CODE_ENEG, 1, 1, setCodeOp_EZ, setInputOp_EZ,
		(devEZ_st *)fzWrongZRange_op, RUNTIME_ERR_FLOAT_IS_ZERO},
	{ 7, ML_CODE_ENEG, 1, 1, setCodeOp_EZ, setInputOp_EZ,
		(devEZ_st *)fzWrongZDRange_op, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{ -1, 0, 0, 0, NULL, NULL, NULL, 0 }
};


int isOperandEValid(int cnt, devE_st op[])
{
	if(cnt==2)
	{
		if(op[0].reg==op[1].reg && op[0].pos == op[1].pos) return 0;
	}
	else if(cnt==3)
	{
		if(op[0].reg==op[1].reg && op[0].pos == op[1].pos) return 0;
		if(op[0].reg==op[2].reg && op[0].pos == op[2].pos) return 0;
		if(op[1].reg==op[2].reg && op[1].pos == op[2].pos) return 0;
	}

	return 1;
}

int isOperandEZValid(int cnt, devEZ_st op[])
{
	if(cnt==2)
	{
		if(op[0].reg==op[1].reg && op[0].pos == op[1].pos) return 0;
	}
	else if(cnt==3)
	{
		if(op[0].reg==op[1].reg && op[0].pos == op[1].pos) return 0;
		if(op[0].reg==op[2].reg && op[0].pos == op[2].pos) return 0;
		if(op[1].reg==op[2].reg && op[1].pos == op[2].pos) return 0;
	}

	return 1;
}

int setCodeOp_E(uint16 ml_cmd, int cnt, devE_st op[])
{
	int i;

	if(!isOperandEValid(cnt, op)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
		for(i=0; i<cnt; i++)
		{
			addMLOperand(op[i].reg, op[i].pos);
			printf("setCodeOp_E : i=%d reg=%d pos=%d\n", i, op[i].reg, op[i].pos);
		}
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_CMPLDE(uint16 ml_cmd, int cnt, devE_st op[])
{
	int i;

	if(!isOperandEValid(cnt, op)) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd);
	for(i=0; i<cnt; i++)
	{
		addMLOperand(op[i].reg, op[i].pos);
		printf("setCodeOp_E : i=%d reg=%d pos=%d\n", i, op[i].reg, op[i].pos);
	}
	addMLOperator(ML_CODE_OUT); addMLOperand(OPERAND_ML_CODE_Y, 100);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_CMPE(uint16 ml_cmd, int cnt, devE_st op[])
{
	int i;

	if(!isOperandEValid(cnt, op)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
	for(i=0; i<cnt; i++)
	{
		addMLOperand(op[i].reg, op[i].pos);
		printf("setCodeOp_E : i=%d reg=%d pos=%d\n", i, op[i].reg, op[i].pos);
	}
	addMLOperator(ML_CODE_OUT); addMLOperand(OPERAND_ML_CODE_Y, 100);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_EZ(uint16 ml_cmd, int cnt, devEZ_st op[])
{
	int i;

	if(!isOperandEZValid(cnt, op)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
		for(i=0; i<cnt; i++)
		{
			addMLOperandZIndex(op[i].reg, op[i].pos, op[i].idx_pos);
			printf("setCodeOp_EZ : i=%d reg=%d pos=%d Z[%d]=%d\n", i, op[i].reg, op[i].pos, op[i].idx_pos, op[i].idx_val);
		}
	addMLOperator(ML_CODE_END);

	return 1;
}



void setInputOp_E(int cnt, devE_st op[], int on_off)
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
		addDeviceControlInstructionToFloat(0, op[i].reg, op[i].pos, op[i].val);
		printf("setInputOp_E : i=%d reg=%d pos=%d val=%e\n", i, op[i].reg, op[i].pos, op[i].val);
	}

	TestCodeTearDown();
}

void setInputOp_CMPLD_E(int cnt, devE_st op[], int on_off)
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
		addDeviceControlInstructionToFloat(0, op[i].reg, op[i].pos, op[i].val);
		printf("setInputOp_E : i=%d reg=%d pos=%d val=%e\n", i, op[i].reg, op[i].pos, op[i].val);
	}

	TestCodeTearDown();
}

void setInputOp_CMP_E(int cnt, devE_st op[], int on_off)
{
	int i;

	for(i=0; i<cnt; i++)
	{
		addDeviceControlInstructionToFloat(0, op[i].reg, op[i].pos, op[i].val);
		printf("setInputOp_E : i=%d reg=%d pos=%d val=%e\n", i, op[i].reg, op[i].pos, op[i].val);
	}

	TestCodeTearDown();
}

void setInputOp_EZ(int cnt, devEZ_st op[], int on_off)
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
		addDeviceControlInstructionToFloat(0, op[i].reg, op[i].pos+op[i].idx_val, op[i].val);
		printf("setInputOp_EZ : i=%d reg=%d pos=%d+%d val=%e\n", i, op[i].reg, op[i].pos, op[i].idx_val, op[i].val);
	}

	TestCodeTearDown();
}

void test_float_E(testCaseE_st tCase)
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

void test_float_EZ(testCaseEZ_st tCase)
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

void testRuntimeErrorFloat(void)
{
	int index=30;
	float val;
/*
	val=INFINITY;
	if(isinf(val) ) printf("INF");
	val=NAN;
	if(isnan(val) ) printf(" NAN");
	val=FLT_MAX;
	if(isfinite(val) ) printf(" Normal");
	val=FLT_MIN;
	if(isnormal(val)) printf(" Normal");
	val=FLT_MAX+FLT_MAX;
	if(isinf(val) ) printf(" INF\n");
	printf("FLT_MAX=%e %e %e\n", INFINITY, val, -0.0f);
*/
	printf("run test testRuntimeError2E() tno=%d\n", index);
#if 1
	test_float_E(tCaseE[index]);
	//test_float_EZ(tCaseEZ[index]);
#else
	for(index=0; index<10; index++)
		test_float_E(tCaseE[index]);

	for(index=0; index<10; index++)
		test_float_EZ(tCaseEZ[index]);
#endif
}

#endif
