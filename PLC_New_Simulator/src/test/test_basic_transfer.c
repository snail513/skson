/*
 * test_basic_transfer.c
 *
 *  Created on: Feb 23, 2015
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

extern int setCodeLD_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeOp_N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

extern void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern int verifyResultValueWord(int tcase, uint8 dest_reg, uint16 pos, short expected);

int setCodeOp2_K1W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
int setCodeOp2_maxK1W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
int setCodeOp2_K101W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
int setCodeOp2_K5555W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
int setCodeOp_2N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputSIn_sval16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sval16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sval16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_maxval16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_maxval16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputOp2_Val16_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val16_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val16p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val16_maxN1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val16p_maxN1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_Val16_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val16_N1_5555_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val16_N1_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val16p_N1_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);


static FILE *flog;
static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, short);
	char str[40];
	//int count;
	int run_step;
	int expected;
} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_MOV, setCodeLD_2op, setInputSIn_sval16_off, verifyResultValueWord,
		"MOV off ", 1, 0},
	{1, ML_CODE_MOV, setCodeLD_2op, setInputSIn_sval16_on, verifyResultValueWord,
		"MOV on 257", 1, 257},
	{2, ML_CODE_MOV, setCodeLD_2op, setInputSIn_maxval16_on, verifyResultValueWord,
		"MOV on 32767", 1, 32767},
	{3, ML_CODE_MOV, setCodeOp2_K1W2, setInputNIn_Val16_off, verifyResultValueWord,
		"MOV off K257", 1, 0},
	{4, ML_CODE_MOV, setCodeOp2_K1W2, setInputNIn_Val16_on, verifyResultValueWord,
		"MOV on K257", 1, 257},
	{5, ML_CODE_MOV, setCodeOp2_maxK1W2, setInputNIn_Val16_on, verifyResultValueWord,
		"MOV on K32767", 1, 32767},
	{6, ML_CODE_MOV, setCodeOp_N_W, setInputOp2_Val16_N1_off, verifyResultValueWord,
		"MOV off N257", 1, 0},
	{7, ML_CODE_MOV, setCodeOp_N_W, setInputOp2_Val16_N1_on, verifyResultValueWord,
		"MOV on N257", 1, 257},
	{8, ML_CODE_MOV, setCodeOp_N_W, setInputOp2_Val16_maxN1_on, verifyResultValueWord,
		"MOV on N32767", 1, 32767},
	{9, ML_CODE_MOV, setCodeOp_2N_W, setInputOp2_Val16_N1_5555_off, verifyResultValueWord,
		"MOV off N0x55", 1, 0},
	{10, ML_CODE_MOV, setCodeOp_2N_W, setInputOp2_Val16_N1_5555_on, verifyResultValueWord,
		"MOV on N0x55", 1, 85}, //0x55

	{11, ML_CODE_MOVP, setCodeLD_2op, setInputSIn_sval16_off, verifyResultValueWord,
		"MOVP 0->0 257", 2, 0},
	{12, ML_CODE_MOVP, setCodeLD_2op, setInputSIn_sval16_on, verifyResultValueWord,
		"MOVP 1->1 257", 2, 0},
	{13, ML_CODE_MOVP, setCodeLD_2op, setInputSIn_sval16p_on, verifyResultValueWord,
		"MOVP 0->1 257", 2, 257},
	{14, ML_CODE_MOVP, setCodeLD_2op, setInputSIn_maxval16p_on, verifyResultValueWord,
		"MOVP 0->1 32767", 2, 32767},
	{15, ML_CODE_MOVP, setCodeOp2_K1W2, setInputNIn_Val16_off, verifyResultValueWord,
		"MOVP 0->0 K257", 2, 0},
	{16, ML_CODE_MOVP, setCodeOp2_K1W2, setInputNIn_Val16_on, verifyResultValueWord,
		"MOVP 1->1 K257", 2, 0},
	{17, ML_CODE_MOVP, setCodeOp2_K1W2, setInputNIn_Val16p_on, verifyResultValueWord,
		"MOVP 0->1 K257", 2, 257},
	{18, ML_CODE_MOVP, setCodeOp2_maxK1W2, setInputNIn_Val16p_on, verifyResultValueWord,
		"MOVP 0->1 K32767", 2, 32767},
	{19, ML_CODE_MOVP, setCodeOp_N_W, setInputOp2_Val16_N1_off, verifyResultValueWord,
		"MOVP 0->0 N257", 2, 0},
	{20, ML_CODE_MOVP, setCodeOp_N_W, setInputOp2_Val16_N1_on, verifyResultValueWord,
		"MOVP 1->1 N257", 2, 0},
	{21, ML_CODE_MOVP, setCodeOp_N_W, setInputOp2_Val16p_N1_on, verifyResultValueWord,
		"MOVP 0->1 N257", 2, 257},
	{22, ML_CODE_MOVP, setCodeOp_N_W, setInputOp2_Val16p_maxN1_on, verifyResultValueWord,
		"MOVP 0->1 N32767", 2, 32767},
	{23, ML_CODE_MOVP, setCodeOp_2N_W, setInputOp2_Val16_N1_5555_off, verifyResultValueWord,
		"MOVP 0->0 N0x55", 1, 0},
	{24, ML_CODE_MOVP, setCodeOp_2N_W, setInputOp2_Val16p_N1_5555_on, verifyResultValueWord,
		"MOVP 0->1 N0x55", 2, 85}, //0x55

	{25, ML_CODE_CML, setCodeLD_2op, setInputSIn_sval16_off, verifyResultValueWord,
		"CML off invert 257", 1, 0},
	{26, ML_CODE_CML, setCodeLD_2op, setInputSIn_sval16_on, verifyResultValueWord,
		"CML on invert 0x101", 1, -258}, //0xFEFE
	{27, ML_CODE_CML, setCodeLD_2op, setInputSIn_Val16_5555_on, verifyResultValueWord,
		"CML on invert 0x5555", 1, -21846}, //0xAAAA
	{28, ML_CODE_CML, setCodeOp2_K101W2, setInputNIn_Val16_off, verifyResultValueWord,
		"CML off invert K257", 1, 0},
	{29, ML_CODE_CML, setCodeOp2_K101W2, setInputNIn_Val16_on, verifyResultValueWord,
		"CML on invert K257", 1, -258}, //0xFEFE
	{30, ML_CODE_CML, setCodeOp2_K5555W2, setInputNIn_Val16_on, verifyResultValueWord,
		"CML on invert K0x5555", 1, -21846}, //0xAAAA
	{31, ML_CODE_CML, setCodeOp_N_W, setInputOp2_Val16_N1_off, verifyResultValueWord,
		"CML off invert N257", 1, 0},
	{32, ML_CODE_CML, setCodeOp_N_W, setInputOp2_Val16_N1_on, verifyResultValueWord,
		"CML on invert N257", 1, -258}, //0xFEFE
	{33, ML_CODE_CML, setCodeOp_N_W, setInputOp2_Val16_N1_5555_on, verifyResultValueWord,
		"CML on invert N0x5555", 1, -21846}, //0xAAAA
	{34, ML_CODE_CML, setCodeOp_2N_W, setInputOp2_Val16_N1_5555_off, verifyResultValueWord,
		"CML off invert N2 0x55", 1, 0},
	{35, ML_CODE_CML, setCodeOp_2N_W, setInputOp2_Val16_N1_5555_on, verifyResultValueWord,
		"CML on invert N2 0x55", 1, -86}, //0xFFAA

	{36, ML_CODE_CMLP, setCodeLD_2op, setInputSIn_sval16_off, verifyResultValueWord,
		"CMLP 0->0 invert 257", 2, 0},
	{37, ML_CODE_CMLP, setCodeLD_2op, setInputSIn_sval16_on, verifyResultValueWord,
		"CMLP 1->1 invert 0x101", 2, 0}, //0xFEFE
	{38, ML_CODE_CMLP, setCodeLD_2op, setInputSIn_sval16p_on, verifyResultValueWord,
		"CMLP 0->1 invert 0x101", 2, -258}, //0xFEFE
	{39, ML_CODE_CMLP, setCodeLD_2op, setInputSIn_Val16p_5555_on, verifyResultValueWord,
		"CMLP 0->1 invert 0x5555", 2, -21846}, //0xAAAA
	{40, ML_CODE_CMLP, setCodeOp2_K101W2, setInputNIn_Val16_off, verifyResultValueWord,
		"CMLP 0->0 invert K2570", 2, 0},
	{41, ML_CODE_CMLP, setCodeOp2_K101W2, setInputNIn_Val16_on, verifyResultValueWord,
		"CMLP 1->1 invert K257", 2, 0}, //0xFEFE
	{42, ML_CODE_CMLP, setCodeOp2_K101W2, setInputNIn_Val16p_on, verifyResultValueWord,
		"CMLP 0->1 invert K257", 2, -258}, //0xFEFE
	{43, ML_CODE_CMLP, setCodeOp2_K5555W2, setInputNIn_Val16p_on, verifyResultValueWord,
		"CMLP 0->1 invert K0x5555", 2, -21846}, //0xAAAA
	{44, ML_CODE_CMLP, setCodeOp_N_W, setInputOp2_Val16_N1_off, verifyResultValueWord,
		"CMLP 0->0 invert N257", 2, 0},
	{45, ML_CODE_CMLP, setCodeOp_N_W, setInputOp2_Val16_N1_on, verifyResultValueWord,
		"CMLP 1->1 invert N257", 2, 0}, //0xFEFE
	{46, ML_CODE_CMLP, setCodeOp_N_W, setInputOp2_Val16p_N1_on, verifyResultValueWord,
		"CMLP 0->1 invert N257", 2, -258}, //0xFEFE
	{47, ML_CODE_CMLP, setCodeOp_N_W, setInputOp2_Val16p_N1_5555_on, verifyResultValueWord,
		"CMLP 0->1 invert N0x5555", 2, -21846}, //0xAAAA
	{48, ML_CODE_CMLP, setCodeOp_2N_W, setInputOp2_Val16_N1_5555_off, verifyResultValueWord,
		"CMLP 0->0 invert N2 0x55", 2, 0}, //0xFEFE
	{49, ML_CODE_CMLP, setCodeOp_2N_W, setInputOp2_Val16p_N1_5555_on, verifyResultValueWord,
		"CMLP 0->1 invert N2 0x55", 2, -86}, //0xFFAA

	{-1, 0xFFFF, NULL, NULL, NULL, NULL, 0, 0 }
};


int total_transfer_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_transfer_test_number; i++)
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


int setCodeOp2_K1W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 257); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxK1W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 32767); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_K101W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x101); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_K5555W2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x5555); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_2N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(2, in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputSIn_sval16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_sval16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_sval16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_maxval16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);

	TestCodeTearDown();
}

void setInputSIn_maxval16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);

	TestCodeTearDown();
}

void setInputOp2_Val16_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val16_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val16_maxN1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val16p_maxN1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val16p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputSIn_Val16_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5555);

	TestCodeTearDown();
}

void setInputSIn_Val16p_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5555);

	TestCodeTearDown();
}

void setInputOp2_Val16_N1_5555_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x5555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val16_N1_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x5555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val16p_N1_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x5555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}



static uint16 getInRegPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0, 6144,4096},
			{8176,8176,8176,8176,2032,8176,0, 12287,8191}};

	return pos[inx_pos][reg];
}

static uint16 getOutPos(int reg, int inx_pos)
{
	uint16 pos[3][2]={ {0,0}, {6144,4096}, {12287,8191}};

	return pos[inx_pos][reg];
}

void test_basic_transfer_word(int tno, uint16 dummy)
{
	int i=1, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	short res_word;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getOutPos(out-OPERAND_ML_CODE_D, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getInRegPos(in, i);

					rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if( rc2 == 0 ) continue;

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
							test_getWord(&res_word, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
								reg[in], in_pos, reg[out], out_pos, res_word, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testTransferWordCommand(void)
{
	int i, index=24;
	int start, end;
	char log[] = "err_trans_wd.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("transfer word LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
		test_basic_transfer_word(index, 0);

#else
	total_transfer_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_MOV);
	end = getTestCaseNumberEnd(ML_CODE_CMLP); //ML_CODE_CMLP

	DBG_LOGPRINT("testBasicTransferWordCommand: %d to %d total %d\n", start, end, total_transfer_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_transfer_word(index, 0);
	}
#endif
	fclose(flog);
}

#endif //USE_CUNIT_TEST_DEF
