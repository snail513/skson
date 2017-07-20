/*
 * test_basic_transfer_word_index.c
 *
 *  Created on: Aug 28, 2015
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

extern int setCodeOp2_WZ_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_W_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_N_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp2_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern void setInputSIn_257_W_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputSIn_257_W_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputSIn_257_W_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputSIn_maxint_W_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputSIn_maxint_W_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern void setInputSIn_257_N_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputSIn_257_N_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputSIn_257_N_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputSIn_maxint_N_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputSIn_maxint_N_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_257_WZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_257_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_257_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_maxint_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_maxint_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);


extern int verifyResultValueWord(int tcase, uint8 dest_reg, uint16 pos, short expected);
extern int verifyResultValueNibble4(int tcase, uint8 dest_reg, uint16 pos, short expected);

int setCodeOp2_K257_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_maxK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_2N_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_K0x5555_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

void setInputOp2_val16_WZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_maxWZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_maxWZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_Val16_2N_5555_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_Val16_2N_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_Val16_2N_5555_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_5555_W_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_5555_W_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_5555_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_5555_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

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

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16, uint16, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16, uint16, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, short);
	char str[30];
	//int count;
	int z_type; // 0 : op2 is index, 1: op1 is index
	int run_step;
	short expected;

} testFn_st;


static testFn_st testCase[]={
	{0, ML_CODE_MOV, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_off, verifyResultValueWord,
			"MOV off 257", 0, 1, 0},
	{1, ML_CODE_MOV, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_on, verifyResultValueWord,
			"MOV on 257", 0, 1, 257},
	{2, ML_CODE_MOV, setCodeOp2_W_WZ, setInputSIn_maxint_W_WZ_on, verifyResultValueWord,
			"MOV on 32767", 0, 1, 32767},
	{3, ML_CODE_MOV, setCodeOp2_K257_WZ, setInputOp2_none_off, verifyResultValueWord,
			"MOV off K257", 0, 1, 0},
	{4, ML_CODE_MOV, setCodeOp2_K257_WZ, setInputOp2_none_on, verifyResultValueWord,
			"MOV on K257", 0, 1, 257},
	{5, ML_CODE_MOV, setCodeOp2_maxK_WZ, setInputOp2_none_on, verifyResultValueWord,
			"MOV on K32767", 0, 1, 32767},
	{6, ML_CODE_MOV, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_off, verifyResultValueWord,
			"MOV off N257", 0, 1, 0},
	{7, ML_CODE_MOV, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_on, verifyResultValueWord,
			"MOV on N257", 0, 1, 257},
	{8, ML_CODE_MOV, setCodeOp2_N_WZ, setInputSIn_maxint_N_WZ_on, verifyResultValueWord,
			"MOV on N32767", 0, 1, 32767},
	{9, ML_CODE_MOV, setCodeOp2_2N_WZ, setInputOp2_Val16_2N_5555_off, verifyResultValueWord,
			"MOV off N0x55", 0, 1, 0},
	{10, ML_CODE_MOV, setCodeOp2_2N_WZ, setInputOp2_Val16_2N_5555_on, verifyResultValueWord,
			"MOV on N0x55", 0, 1, 85}, //0x55
	{11, ML_CODE_MOV, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_off, verifyResultValueWord,
			"MOV off WZ257", 1, 1, 0},
	{12, ML_CODE_MOV, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_on, verifyResultValueWord,
			"MOV on WZ257", 1, 1, 257},
	{13, ML_CODE_MOV, setCodeOp2_WZ_N, setInputOp2_257_WZ_W_off, verifyResultValueNibble4,
			"MOV off WZ257", 3, 1, 0},
	{14, ML_CODE_MOV, setCodeOp2_WZ_N, setInputOp2_257_WZ_W_on, verifyResultValueNibble4,
			"MOV on WZ257", 3, 1, 257},
	{15, ML_CODE_MOV, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_off, verifyResultValueWord,
			"MOV off WZ257", 2, 1, 0},
	{16, ML_CODE_MOV, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_on, verifyResultValueWord,
			"MOV on WZ257", 2, 1, 257},

	{17, ML_CODE_MOVP, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_off, verifyResultValueWord,
			"MOV 0->0 257", 0, 2, 0},
	{18, ML_CODE_MOVP, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_tr1, verifyResultValueWord,
			"MOVP 0->1 257", 0, 2, 257},
	{19, ML_CODE_MOVP, setCodeOp2_W_WZ, setInputSIn_maxint_W_WZ_tr1, verifyResultValueWord,
			"MOVP 0->1 32767", 0, 2, 32767},
	{20, ML_CODE_MOVP, setCodeOp2_K257_WZ, setInputOp2_none_off, verifyResultValueWord,
			"MOVP 0->0 K257", 0, 2, 0},
	{21, ML_CODE_MOVP, setCodeOp2_K257_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"MOVP 0->1 K257", 0, 2, 257},
	{22, ML_CODE_MOVP, setCodeOp2_maxK_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"MOVP 0->1 K32767", 0, 2, 32767},
	{23, ML_CODE_MOVP, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_off, verifyResultValueWord,
			"MOVP 0->0 N257", 0, 2, 0},
	{24, ML_CODE_MOVP, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_tr1, verifyResultValueWord,
			"MOVP 0->1 N257", 0, 2, 257},
	{25, ML_CODE_MOVP, setCodeOp2_N_WZ, setInputSIn_maxint_N_WZ_tr1, verifyResultValueWord,
			"MOVP 0->1 N32767", 0, 2, 32767},
	{26, ML_CODE_MOVP, setCodeOp2_2N_WZ, setInputOp2_Val16_2N_5555_off, verifyResultValueWord,
			"MOVP 0->0 N0x55", 0, 2, 0},
	{27, ML_CODE_MOVP, setCodeOp2_2N_WZ, setInputOp2_Val16_2N_5555_tr1, verifyResultValueWord,
			"MOVP 0->1 N0x55", 0, 2, 85}, //0x55
	{28, ML_CODE_MOVP, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_off, verifyResultValueWord,
			"MOVP 0->0 WZ257", 1, 2, 0},
	{29, ML_CODE_MOVP, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_tr1, verifyResultValueWord,
			"MOVP 0->1 WZ257", 1, 2, 257},
	{30, ML_CODE_MOVP, setCodeOp2_WZ_N, setInputOp2_257_WZ_W_off, verifyResultValueNibble4,
			"MOVP 0->0 WZ257", 3, 2, 0},
	{31, ML_CODE_MOVP, setCodeOp2_WZ_N, setInputOp2_257_WZ_W_tr1, verifyResultValueNibble4,
			"MOVP 0->1 WZ257", 3, 2, 257},
	{32, ML_CODE_MOVP, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_off, verifyResultValueWord,
			"MOVP 0->0 WZ257", 2, 2, 0},
	{33, ML_CODE_MOVP, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_tr1, verifyResultValueWord,
			"MOVP 0->1 WZ257", 2, 2, 257},

	{34, ML_CODE_CML, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_off, verifyResultValueWord,
		"CML off 257", 0, 1, 0},
	{35, ML_CODE_CML, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_on, verifyResultValueWord,
		"CML on 0x101", 0, 1, -258}, //0xFEFE
	{36, ML_CODE_CML, setCodeOp2_W_WZ, setInputSIn_5555_W_WZ_on, verifyResultValueWord,
		"CML on 0x5555", 0, 1, -21846}, //0xAAAA
	{37, ML_CODE_CML, setCodeOp2_K257_WZ, setInputOp2_none_off, verifyResultValueWord,
		"CML off K0x101", 0, 1, 0},
	{38, ML_CODE_CML, setCodeOp2_K257_WZ, setInputOp2_none_on, verifyResultValueWord,
		"CML on K0x101", 0, 1, -258}, //0xFEFE
	{39, ML_CODE_CML, setCodeOp2_K0x5555_WZ, setInputOp2_none_on, verifyResultValueWord,
		"CML on K0x5555", 0, 1, -21846}, //0xAAAA
	{40, ML_CODE_CML, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_off, verifyResultValueWord,
		"CML off N0x101", 0, 1, 0},
	{41, ML_CODE_CML, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_on, verifyResultValueWord,
		"CML on N0x101", 0, 1, -258}, //0xFEFE
	{42, ML_CODE_CML, setCodeOp2_N_WZ, setInputOp2_Val16_2N_5555_on, verifyResultValueWord,
		"CML on N0x5555", 0, 1, -21846}, //0xAAAA
	{43, ML_CODE_CML, setCodeOp2_2N_WZ, setInputOp2_Val16_2N_5555_off, verifyResultValueWord,
		"CML off N2 0x55", 0, 1, 0},
	{44, ML_CODE_CML, setCodeOp2_2N_WZ, setInputOp2_Val16_2N_5555_on, verifyResultValueWord,
		"CML on N2 0x55", 0, 1, -86}, //0xFFAA
	{45, ML_CODE_CML, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_off, verifyResultValueWord,
		"CML off WZ0x101", 1, 1, 0},
	{46, ML_CODE_CML, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_on, verifyResultValueWord,
		"CML on WZ0x101", 1, 1, -258}, //0xFEFE
	{47, ML_CODE_CML, setCodeOp2_WZ_W, setInputOp2_5555_WZ_W_on, verifyResultValueWord,
		"CML on WZ0x5555", 1, 1, -21846}, //0xAAAA
	{48, ML_CODE_CML, setCodeOp2_WZ_N, setInputOp2_257_WZ_W_off, verifyResultValueNibble4,
		"CML off WZ0x101", 3, 1, 0},
	{49, ML_CODE_CML, setCodeOp2_WZ_N, setInputOp2_257_WZ_W_on, verifyResultValueNibble4,
		"CML on WZ0x101", 3, 1, -258}, //0xFEFE
	{50, ML_CODE_CML, setCodeOp2_WZ_N, setInputOp2_5555_WZ_W_on, verifyResultValueNibble4,
		"CML on WZ0x5555", 3, 1, -21846}, //0xAAAA
	{51, ML_CODE_CML, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_off, verifyResultValueWord,
		"CML off WZ0x101", 2, 1, 0},
	{52, ML_CODE_CML, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_on, verifyResultValueWord,
		"CML on WZ0x101", 2, 1, -258}, //0xFEFE
	{53, ML_CODE_CML, setCodeOp2_WZ_WZ, setInputOp2_5555_WZ_W_on, verifyResultValueWord,
		"CML on WZ0x5555", 2, 1, -21846}, //0xAAAA

	{54, ML_CODE_CMLP, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_off, verifyResultValueWord,
		"CMLP 0->0 257", 0, 2, 0},
	{55, ML_CODE_CMLP, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_tr1, verifyResultValueWord,
		"CMLP 0->1 0x101", 0, 2, -258}, //0xFEFE
	{56, ML_CODE_CMLP, setCodeOp2_W_WZ, setInputSIn_5555_W_WZ_tr1, verifyResultValueWord,
		"CMLP 0->1 0x5555", 0, 2, -21846}, //0xAAAA
	{57, ML_CODE_CMLP, setCodeOp2_K257_WZ, setInputOp2_none_off, verifyResultValueWord,
		"CMLP 0->0 K0x101", 0, 2, 0},
	{58, ML_CODE_CMLP, setCodeOp2_K257_WZ, setInputOp2_none_tr1, verifyResultValueWord,
		"CMLP 0->1 K0x101", 0, 2, -258}, //0xFEFE
	{59, ML_CODE_CMLP, setCodeOp2_K0x5555_WZ, setInputOp2_none_tr1, verifyResultValueWord,
		"CMLP 0->1 K0x5555", 0, 2, -21846}, //0xAAAA
	{60, ML_CODE_CMLP, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_off, verifyResultValueWord,
		"CMLP 0->0 N0x101", 0, 2, 0},
	{61, ML_CODE_CMLP, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_tr1, verifyResultValueWord,
		"CMLP 0->1 N0x101", 0, 2, -258}, //0xFEFE
	{62, ML_CODE_CMLP, setCodeOp2_N_WZ, setInputOp2_Val16_2N_5555_tr1, verifyResultValueWord,
		"CMLP 0->1 N0x5555", 0, 2, -21846}, //0xAAAA
	{63, ML_CODE_CMLP, setCodeOp2_2N_WZ, setInputOp2_Val16_2N_5555_off, verifyResultValueWord,
		"CMLP 0->0 N2 0x55", 0, 2, 0},
	{64, ML_CODE_CMLP, setCodeOp2_2N_WZ, setInputOp2_Val16_2N_5555_tr1, verifyResultValueWord,
		"CMLP 0->1 N2 0x55", 0, 2, -86}, //0xFFAA
	{65, ML_CODE_CMLP, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_off, verifyResultValueWord,
		"CMLP 0->0 WZ0x101", 1, 2, 0},
	{66, ML_CODE_CMLP, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_tr1, verifyResultValueWord,
		"CMLP 0->1 WZ0x101", 1, 2, -258}, //0xFEFE
	{67, ML_CODE_CMLP, setCodeOp2_WZ_W, setInputOp2_5555_WZ_W_tr1, verifyResultValueWord,
		"CMLP 0->1 WZ0x5555", 1, 2, -21846}, //0xAAAA
	{68, ML_CODE_CMLP, setCodeOp2_WZ_N, setInputOp2_257_WZ_W_off, verifyResultValueNibble4,
		"CMLP 0->0 WZ0x101", 3, 2, 0},
	{69, ML_CODE_CMLP, setCodeOp2_WZ_N, setInputOp2_257_WZ_W_tr1, verifyResultValueNibble4,
		"CMLP 0->1 WZ0x101", 3, 2, -258}, //0xFEFE
	{70, ML_CODE_CMLP, setCodeOp2_WZ_N, setInputOp2_5555_WZ_W_tr1, verifyResultValueNibble4,
		"CMLP 0->1 WZ0x5555", 3, 2, -21846}, //0xAAAA
	{71, ML_CODE_CMLP, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_off, verifyResultValueWord,
		"CMLP 0->0 WZ0x101", 2, 2, 0},
	{72, ML_CODE_CMLP, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_tr1, verifyResultValueWord,
		"CMLP 0->1 WZ0x101", 2, 2, -258}, //0xFEFE
	{73, ML_CODE_CMLP, setCodeOp2_WZ_WZ, setInputOp2_5555_WZ_W_tr1, verifyResultValueWord,
		"CMLP 0->1 WZ0x5555", 2, 2, -21846}, //0xAAAA

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};



int total_transfer_wd_idx_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_transfer_wd_idx_test_number; i++)
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

static int isRangeOver(uint8 reg, uint16 pos, uint16 idx_val)
{
	uint16 lastpos[]={8191,8191,8191,8191,2047,8191,0, 12287, 8191};

	if(pos+idx_val < 0 || pos+idx_val > lastpos[reg]) return 1;

	return 0;
}


int setCodeOp2_K257_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	short in_val=257;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	short in_val=32767;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_2N_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(2, in_reg, in_pos); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_K0x5555_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	short in_val=0x5555;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp2_val16_WZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_maxWZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_maxWZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_Val16_2N_5555_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x5555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val16_2N_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x5555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val16_2N_5555_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x5555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_5555_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x5555;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_5555_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x5555;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12287,8191}}; // for Dword input

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_transfer_word_idx(int tno, uint16 dummy)
{
	int i=1, inx=7, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	short res_word;

	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_B; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_W; in++)
			{
				if(in==out)
					continue;
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					//for(inx=0; inx<15; inx++) // testidx
					{
						PLC_DEVICE_Init();

						in_pos = getPos(in, i);

						rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos, testidx[inx].pos, testidx[inx].val);
						if( rc2 == 0 ) continue;

						testCase[tno].setTestInput_fn(in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);

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
							if(testCase[tno].z_type==1 || testCase[tno].z_type==3) //op1 is index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
								if(rc == 1)
								{
									if(testCase[tno].z_type==1)
									{
										test_getWord(&res_word, out, out_pos);
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d]=%d exp=%d\n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_word, testCase[tno].expected);
									}
									else
									{
										test_getNibble(&res_word, out, out_pos, 4);
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_N_%s[%d]=%d exp=%d\n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_word, testCase[tno].expected);
									}
								}
							}
							else // op2 is index or both are index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos+testidx[inx].val, testCase[tno].expected);
								if(rc == 1)
								{
									test_getWord(&res_word, out, out_pos+testidx[inx].val);
									if(testCase[tno].z_type==0)
									{
										fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d+%d]=%d exp=%d \n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, reg[out], out_pos, testidx[inx].val, res_word, testCase[tno].expected);
									}
									else
									{
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d+%d]=%d exp=%d \n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, testidx[inx].val, res_word, testCase[tno].expected);
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

void testTransferWordIndexCommand(void)
{
	int i, index=62;
	int start, end;
	char log[] = "err_trans_word_idx.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("transfer word index LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
	test_basic_transfer_word_idx(index, 0);

#else
	total_transfer_wd_idx_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_MOV);
	end = getTestCaseNumberEnd(ML_CODE_CMLP); //ML_CODE_CMLP

	DBG_LOGPRINT("testTransferWordIndexCommand: %d to %d total %d\n", start, end, total_transfer_wd_idx_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_transfer_word_idx(index, 0);
	}
#endif
	fclose(flog);
}
#endif
