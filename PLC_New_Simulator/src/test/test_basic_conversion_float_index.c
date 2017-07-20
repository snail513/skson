/*
 * test_basic_conversion_float_index.c
 *
 *  Created on: Aug 12, 2015
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

extern int verifyResultValueFloat(int tcase, uint8 dest_reg, uint16 pos, float expected);

int setCodeOp2_WWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_NWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_EWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_nEWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_WZW(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);

void setInputSIn_WWZ_Val16_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WWZ_Val16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WWZ_Val16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WWZ_nVal16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WWZ_nVal16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_NWZ_Val16_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_NWZ_Val16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_NWZ_Val16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_NWZ_nVal16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_NWZ_nVal16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_EWZ_Val16_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_EWZ_Val16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_EWZ_Val16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_WZW_Val16_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WZW_Val16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WZW_Val16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WZW_nVal16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WZW_nVal16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_WZW_Val16_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WZW_Val16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WZW_Val16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WZW_nVal16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_WZW_nVal16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val);

static int verifyResultValueZFloat(int tcase, uint8 dest_reg, uint16 pos, float expected);

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

static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint16, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, float);
	char str[40];
	//int count;
	int z_type; // 0 : out is index, 1: op1 is index
	int run_step;
	float expected;

} testFn_st;


static testFn_st testCase[]={
	{0, ML_CODE_BTOF, setCodeOp2_WWZ, setInputSIn_WWZ_Val16_off, verifyResultValueZFloat,
			"BTOF condition off W", 0, 1, 0.0},
	{1, ML_CODE_BTOF, setCodeOp2_WWZ, setInputSIn_WWZ_Val16_on, verifyResultValueZFloat,
			"BTOF on conv W257", 0, 1, 257.0},
	{2, ML_CODE_BTOF, setCodeOp2_WWZ, setInputSIn_WWZ_nVal16_on, verifyResultValueZFloat,
			"BTOF on conv W-257", 0, 1, -257.0},
	{3, ML_CODE_BTOF, setCodeOp2_NWZ, setInputSIn_NWZ_Val16_off, verifyResultValueZFloat,
			"BTOF off condition off N", 0, 1, 0.0},
	{4, ML_CODE_BTOF, setCodeOp2_NWZ, setInputSIn_NWZ_Val16_on, verifyResultValueZFloat,
			"BTOF on conv N257", 0, 1, 257.0},
	{5, ML_CODE_BTOF, setCodeOp2_NWZ, setInputSIn_NWZ_nVal16_on, verifyResultValueZFloat,
			"BTOF on conv N-257", 0, 1, -257.0},
	{6, ML_CODE_BTOF, setCodeOp2_EWZ, setInputSIn_EWZ_Val16_off, verifyResultValueZFloat,
			"BTOF condition off K", 0, 1, 0.0},
	{7, ML_CODE_BTOF, setCodeOp2_EWZ, setInputSIn_EWZ_Val16_on, verifyResultValueZFloat,
			"BTOF on conv K257", 0, 1, 257.0},
	{8, ML_CODE_BTOF, setCodeOp2_nEWZ, setInputSIn_EWZ_Val16_on, verifyResultValueZFloat,
			"BTOF on conv K-257", 0, 1, -257.0},
	{9, ML_CODE_BTOF, setCodeOp2_WZW, setInputSIn_WZW_Val16_off, verifyResultValueFloat,
			"BTOF condition off WZ", 1, 1, 0.0},
	{10, ML_CODE_BTOF, setCodeOp2_WZW, setInputSIn_WZW_Val16_on, verifyResultValueFloat,
			"BTOF on conv WZ257", 1, 1, 257.0},
	{11, ML_CODE_BTOF, setCodeOp2_WZW, setInputSIn_WZW_nVal16_on, verifyResultValueFloat,
			"BTOF on conv WZ-257", 1, 1, -257.0},

	{12, ML_CODE_BTOFP, setCodeOp2_WWZ, setInputSIn_WWZ_Val16_off, verifyResultValueZFloat,
			"BTOFP 0->0 W257", 0, 2, 0.0},
	{13, ML_CODE_BTOFP, setCodeOp2_WWZ, setInputSIn_WWZ_Val16_on, verifyResultValueZFloat,
			"BTOFP 1->1 conv W257", 0, 2, 0.0},
	{14, ML_CODE_BTOFP, setCodeOp2_WWZ, setInputSIn_WWZ_Val16p_on, verifyResultValueZFloat,
			"BTOFP 0->1 conv W257", 0, 2, 257.0},
	{15, ML_CODE_BTOFP, setCodeOp2_WWZ, setInputSIn_WWZ_nVal16p_on, verifyResultValueZFloat,
			"BTOFP 0->1 conv W-257", 0, 2, -257.0},
	{16, ML_CODE_BTOFP, setCodeOp2_NWZ, setInputSIn_NWZ_Val16_off, verifyResultValueZFloat,
			"BTOFP 0->0 conv N257", 0, 2, 0.0},
	{17, ML_CODE_BTOFP, setCodeOp2_NWZ, setInputSIn_NWZ_Val16_on, verifyResultValueZFloat,
			"BTOFP 1->1 conv N257", 0, 2, 0.0},
	{18, ML_CODE_BTOFP, setCodeOp2_NWZ, setInputSIn_NWZ_Val16p_on, verifyResultValueZFloat,
			"BTOFP 0->1 conv N257", 0, 2, 257.0},
	{19, ML_CODE_BTOFP, setCodeOp2_NWZ, setInputSIn_NWZ_nVal16p_on, verifyResultValueZFloat,
			"BTOFP 0->1 conv N-257", 0, 2, -257.0},
	{20, ML_CODE_BTOFP, setCodeOp2_EWZ, setInputSIn_EWZ_Val16_off, verifyResultValueZFloat,
			"BTOFP 0->0 conv K257", 0, 2, 0.0},
	{21, ML_CODE_BTOFP, setCodeOp2_EWZ, setInputSIn_EWZ_Val16_on, verifyResultValueZFloat,
			"BTOFP 1->1 conv K257", 0, 2, 0.0},
	{22, ML_CODE_BTOFP, setCodeOp2_EWZ, setInputSIn_EWZ_Val16p_on, verifyResultValueZFloat,
			"BTOFP 0->1 conv K-257", 0, 2, 257.0},
	{23, ML_CODE_BTOFP, setCodeOp2_nEWZ, setInputSIn_EWZ_Val16p_on, verifyResultValueZFloat,
			"BTOFP 0->1 conv K-257", 0, 2, -257.0},
	{24, ML_CODE_BTOFP, setCodeOp2_WZW, setInputSIn_WZW_Val16_off, verifyResultValueFloat,
			"BTOFP 0->0 conv WZ257", 1, 2, 0.0},
	{25, ML_CODE_BTOFP, setCodeOp2_WZW, setInputSIn_WZW_Val16_on, verifyResultValueFloat,
			"BTOFP 1->1 conv WZ257", 1, 2, 0.0},
	{26, ML_CODE_BTOFP, setCodeOp2_WZW, setInputSIn_WZW_Val16p_on, verifyResultValueFloat,
			"BTOFP 0->1 conv WZ257", 1, 2, 257.0},
	{27, ML_CODE_BTOFP, setCodeOp2_WZW, setInputSIn_WZW_nVal16p_on, verifyResultValueFloat,
			"BTOFP 0->1 conv WZ-257", 1, 2, -257.0},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0, 0 }
};


int total_conversion_float_idx_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_conversion_float_idx_test_number; i++)
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

int setCodeOp2_WWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


int setCodeOp2_NWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, in_pos); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_EWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 257); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_nEWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, -257); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_WZW(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputSIn_WWZ_Val16_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputSIn_WWZ_Val16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short zVal;
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&zVal, OPERAND_ML_CODE_Z, idx_pos);
	DBG_LOGPRINT("pos=%d val=%d z_index=%d \n", idx_pos, idx_val, zVal);

	TestCodeTearDown();
}

void setInputSIn_WWZ_nVal16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, -257);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputSIn_WWZ_Val16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputSIn_WWZ_nVal16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, -257);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputSIn_NWZ_Val16_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputSIn_NWZ_Val16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputSIn_NWZ_nVal16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	int i;
	short value=-257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputSIn_NWZ_Val16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputSIn_NWZ_nVal16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	int i;
	short value=-257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputSIn_EWZ_Val16_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputSIn_EWZ_Val16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputSIn_EWZ_Val16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputSIn_WZW_Val16_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, 257);
	DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputSIn_WZW_Val16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, 257);

	TestCodeTearDown();
}

void setInputSIn_WZW_nVal16_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, -257);

	TestCodeTearDown();
}

void setInputSIn_WZW_Val16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, 257);

	TestCodeTearDown();
}

void setInputSIn_WZW_nVal16p_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, -257);

	TestCodeTearDown();
}

static short z_index;
static short getIndexVal(void)
{
	return z_index;
}

static void setIndexVal(short zVal)
{
	z_index = zVal;
}

static int verifyResultValueZFloat(int tcase, uint8 dest_reg, uint16 pos, float expected)
{
	int rc=0;
	float result;
	short zVal;
	char reg[] = {'D', 'W'};

	//result = (double)PLC_Register_getFloat(dest_reg, pos);
	zVal = getIndexVal();
	if(!test_getFloat(&result, dest_reg, pos+zVal))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d Index Reg %c[%d+%d]=%f %f\n", tcase, reg[dest_reg-OPERAND_ML_CODE_D], pos, zVal, result, expected);
	CU_ASSERT_EQUAL(result, expected);
	if(result != expected) rc=1;

	return rc;
}


static int isIndexRangeOver(int type, uint16 in, uint16 in_pos, uint16 out, uint16 out_pos, short idx_val)
{
	// X,Y,R,L,F,B,SM,D,W
	uint16 lastIndex[] = {8190,8190,8190,8190,2046,8190,0,12286,8190};

	if(type == 0 ) // out is index
	{
		if( out < OPERAND_ML_CODE_D) return 1;

		if( out_pos+idx_val > lastIndex[out] || out_pos+idx_val < 0 )
			return 1;

		if( in == out && in_pos == out_pos+idx_val )
			return 1;
	}
	else if(type == 1) // op1 is index
	{
		if( in < OPERAND_ML_CODE_D) return 1;

		if( in_pos+idx_val > lastIndex[in] || in_pos+idx_val < 0 )
			return 1;

		if( in == out && in_pos+idx_val == out_pos )
			return 1;
	}
	return 0;
}

static uint16 getInPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}};

	return pos[inx_pos][reg];
}

static uint16 getOutPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; // 2 word

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_conversion_float_index(int tno, uint16 dummy)
{
	int i=0, rc=0, rc2=1, inx, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	float res_float;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getOutPos(out, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getInPos(in, i);
					for(inx=0; inx<15; inx++) // testidx
					{
						if( isIndexRangeOver(testCase[tno].z_type, in, in_pos, out, out_pos, testidx[inx].val) )
						{
							//DBG_LOGPRINT(" SKIP test range over type=%d %s[%d], %s[%d] Z[%d]=%d \n", \
								testCase[tno].z_type, reg[in], in_pos, reg[out], out_pos, testidx[inx].pos, testidx[inx].val);
							continue; // skip test
						}

						rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos, testidx[inx].pos);
						if( rc2 == 0 ) continue;

						testCase[tno].setTestInput_fn(in, in_pos, testidx[inx].pos, testidx[inx].val);

						rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error!\n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName);
						}
						else
						{
							setIndexVal(testidx[inx].val);
							rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
							if(rc == 1)
							{
								if(testCase[tno].z_type==0) // out is index
								{
									test_getFloat(&res_float, out, out_pos+testidx[inx].val);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d+%d]=%f exp=%f\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
										reg[in], in_pos, reg[out], out_pos, testidx[inx].val, res_float, testCase[tno].expected);
								}
								else
								{
									test_getFloat(&res_float, out, out_pos);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d]=%f exp=%f\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
										reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_float, testCase[tno].expected);
								}
							}
						}
					}
				}
			}
		}
	}
}


void testConversionFloatIndexCommand(void)
{
	int i, index=1;
	int start, end;
	char log[] = "err_conv_float_index.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("conversion float index LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
	test_basic_conversion_float_index(index, 0);

#else
	total_conversion_float_idx_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_BTOF); //ML_CODE_BTOF
	end = getTestCaseNumberEnd(ML_CODE_BTOFP); //ML_CODE_BTOFP

	DBG_LOGPRINT("testConversionFloatIndexCommand: %d to %d total %d\n", start, end, total_conversion_float_idx_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_conversion_float_index(index, 0);
	}
#endif
	fclose(flog);
}
#endif
