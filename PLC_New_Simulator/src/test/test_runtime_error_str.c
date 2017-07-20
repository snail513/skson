/*
 * test_runtime_error_str.c
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
} devStr_st;

typedef struct {
	int tno;
	uint16 ml_cmd;
	int on_off;
	int op_cnt;
	int (*setCode)(uint16, int, devStr_st *);
	void (*setInput)(int, devStr_st *, int);
	devStr_st *op;
	uint16 expected;

} testCaseStr_st;

int setCodeSTR_LDCMP(uint16 ml_cmd, int op_cnt, devStr_st op[])
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(op[0].reg, op[0].pos); addMLOperand(op[1].reg, op[1].pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(OPERAND_ML_CODE_Y, 100);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeSTR_CMP(uint16 ml_cmd, int op_cnt, devStr_st op[])
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(op[0].reg, op[0].pos); addMLOperand(op[1].reg, op[1].pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(OPERAND_ML_CODE_Y, 100);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeSTR_Op(uint16 ml_cmd, int op_cnt, devStr_st op[])
{
	int i;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd);
	for(i=0; i<op_cnt; i++)
	{
		addMLOperand(op[i].reg, op[i].pos);
	}
	addMLOperator(ML_CODE_END);

	return 1;
}


void setStrFull2End(uint8 reg, uint16 pos)
{
	int i;

	for(i=pos; i<12288; i++)
	{
		addDeviceControlInstruction(0, reg, i, 0x4141); //"AA"
	}
}

void setStrLengthOver(uint8 reg, uint16 pos)
{
	int i;

	for(i=0; i<8192; i++)
	{
		addDeviceControlInstruction(0, reg, pos+i, 0x4141); //"AA"
	}
}

void setInputOpStr_LDCMP_NoNull(int op_cnt, devStr_st op[], int on_off)
{
	if(op[0].val==1)
	{
		setStrFull2End(op[0].reg, op[0].pos);
		addDeviceControlInstructionToString(0, op[1].reg, op[1].pos, "AAAAA");
	}
	else
	{
		addDeviceControlInstructionToString(0, op[0].reg, op[0].pos, "AAAAA");
		setStrFull2End(op[1].reg, op[1].pos);
	}

	TestCodeTearDown();
}

void setInputOpStr_LDCMP_LenOver(int op_cnt, devStr_st op[], int on_off)
{
	if(op[0].val==1)
	{
		setStrLengthOver(op[0].reg, op[0].pos);
		addDeviceControlInstructionToString(0, op[1].reg, op[1].pos, "AAAAA");
	}
	else
	{
		addDeviceControlInstructionToString(0, op[0].reg, op[0].pos, "AAAAA");
		setStrLengthOver(op[1].reg, op[1].pos);
	}

	TestCodeTearDown();
}

void setInputOpStr_NoNull(int op_cnt, devStr_st op[], int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	if(op[0].val==1)
	{
		setStrFull2End(op[0].reg, op[0].pos);
		addDeviceControlInstructionToString(0, op[1].reg, op[1].pos, "AAAAA");
	}
	else
	{
		addDeviceControlInstructionToString(0, op[0].reg, op[0].pos, "AAAAA");
		setStrFull2End(op[1].reg, op[1].pos);
	}

	TestCodeTearDown();
}

void setInputOpStr_LenOver(int op_cnt, devStr_st op[], int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	if(op[0].val==1)
	{
		setStrLengthOver(op[0].reg, op[0].pos);
		addDeviceControlInstructionToString(0, op[1].reg, op[1].pos, "AAAAA");
	}
	else
	{
		addDeviceControlInstructionToString(0, op[0].reg, op[0].pos, "AAAAA");
		setStrLengthOver(op[1].reg, op[1].pos);
	}

	TestCodeTearDown();
}

void setInputOpStr_DevOver(int op_cnt, devStr_st op[], int on_off)
{
	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstructionToString(0, op[0].reg, op[0].pos, "AAAAA");
	addDeviceControlInstructionToString(0, op[1].reg, op[1].pos, "AAAAA");

	TestCodeTearDown();
}

devStr_st sNoNullOp1[]={
	{OPERAND_ML_CODE_D, 12000, 1},
	{OPERAND_ML_CODE_D, 200, 0},
	{OPERAND_ML_CODE_D, 0, 0},
};

devStr_st sNoNullOp2[]={
	{OPERAND_ML_CODE_D, 100, 0},
	{OPERAND_ML_CODE_D, 12000, 1},
	{OPERAND_ML_CODE_D, 0, 0},
};

devStr_st sLenOverOp1[]={
	{OPERAND_ML_CODE_D, 100, 1},
	{OPERAND_ML_CODE_D, 200, 0},
	{OPERAND_ML_CODE_D, 0, 0},
};

devStr_st sLenOverOp2[]={
	{OPERAND_ML_CODE_D, 100, 0},
	{OPERAND_ML_CODE_D, 200, 1},
	{OPERAND_ML_CODE_D, 0, 0},
};

devStr_st sDevOverOp2[]={
	{OPERAND_ML_CODE_D, 100, 0},
	{OPERAND_ML_CODE_D, 12284, 0}, //op2 = op1+op2 over DevRange
	{OPERAND_ML_CODE_D, 0, 0},
};

devStr_st sDevOverOp3[]={
	{OPERAND_ML_CODE_D, 100, 0},
	{OPERAND_ML_CODE_D, 200, 0},
	{OPERAND_ML_CODE_D, 12280, 0}, //op3 = op1+op2 over DevRange
};

devStr_st sOverlap[]={
	{OPERAND_ML_CODE_D, 100, 0},
	{OPERAND_ML_CODE_D, 103, 0}, //op1, op2 overlap
	{OPERAND_ML_CODE_D, 0, 0},
};

devStr_st sOverlapS1[]={
	{OPERAND_ML_CODE_D, 100, 0},
	{OPERAND_ML_CODE_D, 200, 0},
	{OPERAND_ML_CODE_D, 103, 0}, //op3, op1 overlap
};

devStr_st sOverlapS2[]={
	{OPERAND_ML_CODE_D, 100, 0},
	{OPERAND_ML_CODE_D, 200, 0},
	{OPERAND_ML_CODE_D, 203, 0}, //op3, op2 overlap
};

static testCaseStr_st tCaseStr[]={
	{0, ML_CODE_LDSTREQ, 1, 2, setCodeSTR_LDCMP, setInputOpStr_LDCMP_NoNull,
		(devStr_st *)sNoNullOp1, RUNTIME_ERR_INVALID_STRING},
	{1, ML_CODE_LDSTREQ, 1, 2, setCodeSTR_LDCMP, setInputOpStr_LDCMP_NoNull,
		(devStr_st *)sNoNullOp2, RUNTIME_ERR_INVALID_STRING},
	{2, ML_CODE_LDSTREQ, 1, 2, setCodeSTR_LDCMP, setInputOpStr_LDCMP_LenOver,
		(devStr_st *)sLenOverOp1, RUNTIME_ERR_TOO_LONG_STRING},
	{3, ML_CODE_LDSTREQ, 1, 2, setCodeSTR_LDCMP, setInputOpStr_LDCMP_LenOver,
		(devStr_st *)sLenOverOp2, RUNTIME_ERR_TOO_LONG_STRING},

	{4, ML_CODE_ANDSTREQ, 1, 2, setCodeSTR_CMP, setInputOpStr_NoNull,
		(devStr_st *)sNoNullOp1, RUNTIME_ERR_INVALID_STRING},
	{5, ML_CODE_ANDSTREQ, 1, 2, setCodeSTR_CMP, setInputOpStr_NoNull,
		(devStr_st *)sNoNullOp2, RUNTIME_ERR_INVALID_STRING},
	{6, ML_CODE_ANDSTREQ, 1, 2, setCodeSTR_CMP, setInputOpStr_LenOver,
		(devStr_st *)sLenOverOp1, RUNTIME_ERR_TOO_LONG_STRING},
	{7, ML_CODE_ANDSTREQ, 1, 2, setCodeSTR_CMP, setInputOpStr_LenOver,
		(devStr_st *)sLenOverOp2, RUNTIME_ERR_TOO_LONG_STRING},

	{8, ML_CODE_STRADD, 1, 2, setCodeSTR_Op, setInputOpStr_NoNull,
		(devStr_st *)sNoNullOp1, RUNTIME_ERR_INVALID_STRING},
	{9, ML_CODE_STRADD, 1, 2, setCodeSTR_Op, setInputOpStr_NoNull,
		(devStr_st *)sNoNullOp2, RUNTIME_ERR_INVALID_STRING},
	{10, ML_CODE_STRADD, 1, 2, setCodeSTR_Op, setInputOpStr_LenOver,
		(devStr_st *)sLenOverOp1, RUNTIME_ERR_TOO_LONG_STRING},
	{11, ML_CODE_STRADD, 1, 2, setCodeSTR_Op, setInputOpStr_LenOver,
		(devStr_st *)sLenOverOp2, RUNTIME_ERR_TOO_LONG_STRING},
	{12, ML_CODE_STRADD, 1, 2, setCodeSTR_Op, setInputOpStr_DevOver,
		(devStr_st *)sDevOverOp2, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{13, ML_CODE_STRADD, 1, 2, setCodeSTR_Op, setInputOpStr_DevOver,
		(devStr_st *)sOverlap, RUNTIME_ERR_OVERLAP_RANGE},

	{14, ML_CODE_STRADDS, 1, 3, setCodeSTR_Op, setInputOpStr_NoNull,
		(devStr_st *)sNoNullOp1, RUNTIME_ERR_INVALID_STRING},
	{15, ML_CODE_STRADDS, 1, 3, setCodeSTR_Op, setInputOpStr_NoNull,
		(devStr_st *)sNoNullOp2, RUNTIME_ERR_INVALID_STRING},
	{16, ML_CODE_STRADDS, 1, 3, setCodeSTR_Op, setInputOpStr_LenOver,
		(devStr_st *)sLenOverOp1, RUNTIME_ERR_TOO_LONG_STRING},
	{17, ML_CODE_STRADDS, 1, 3, setCodeSTR_Op, setInputOpStr_LenOver,
		(devStr_st *)sLenOverOp2, RUNTIME_ERR_TOO_LONG_STRING},
	{18, ML_CODE_STRADDS, 1, 3, setCodeSTR_Op, setInputOpStr_DevOver,
		(devStr_st *)sDevOverOp3, RUNTIME_ERR_DEVICE_RANGE_OVER},
	{19, ML_CODE_STRADDS, 1, 3, setCodeSTR_Op, setInputOpStr_DevOver,
		(devStr_st *)sOverlapS1, RUNTIME_ERR_OVERLAP_RANGE},
	{20, ML_CODE_STRADDS, 1, 3, setCodeSTR_Op, setInputOpStr_DevOver,
		(devStr_st *)sOverlapS2, RUNTIME_ERR_OVERLAP_RANGE},

	{21, ML_CODE_STRMOV, 1, 2, setCodeSTR_Op, setInputOpStr_NoNull,
		(devStr_st *)sNoNullOp1, RUNTIME_ERR_INVALID_STRING},
	{22, ML_CODE_STRMOV, 1, 2, setCodeSTR_Op, setInputOpStr_LenOver,
		(devStr_st *)sLenOverOp1, RUNTIME_ERR_TOO_LONG_STRING},
	{23, ML_CODE_STRMOV, 1, 2, setCodeSTR_Op, setInputOpStr_DevOver,
		(devStr_st *)sDevOverOp2, RUNTIME_ERR_DEVICE_RANGE_OVER},

	{ -1, 0, 0, 0, NULL, NULL, NULL, 0 }
};

void testStr_WD(testCaseStr_st tCase)
{
	int rc1=0, rc2=0;
	uint16 SD_val;

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

void testRuntimeErrorString(void)
{
	int index=0;

	testStr_WD(tCaseStr[index]);

}

#endif
