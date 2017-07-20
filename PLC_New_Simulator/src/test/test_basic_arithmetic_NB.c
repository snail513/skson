/*
 * test_basic_arithmatic_NB.c
 *
 *  Created on: Jul 8, 2015
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

extern int setCodeVal_W_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
extern int setCodeVal_N_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
extern int setCodeVal_K1234_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

extern void setInput2DIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInput2DIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInput2DIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_Val16_in_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_Val16_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_Val16p_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputDIn_BCD_in_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputDIn_BCD_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputDIn_BCDp_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern int verifyResultValueNibble4(int tcase, uint8 dest_reg, uint16 pos, short expected);


int setCodeOp_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp_WWN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeOp_NWN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeOp_WNN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeOp_K1234_NN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeOp_K1234_KN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeOp_K0x1234_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeOp_K0x1234_NN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeOp_K0x1234_KN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

void setInputDIn_Val16_WN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16p_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_NN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_NN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16p_NN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_Val16_KN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_KN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16p_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_Val16_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16p_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_NW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_NW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_Val16_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_Val16p_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_Val16_NW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_Val16p_NW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_N_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_N_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_N_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_N_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInput2DIn_Val16_NW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_NW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_NW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_WN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_BCD_WN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCDp_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_NN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_NN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCDp_NN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_KN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCDp_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCDp_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_BCD_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_BCDp_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_NW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_NW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCDp_NW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD_WN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCDp_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_KN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCDp_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, short);
	char str[50];
	//int count;
	int type; // 0: 2op, 1: 3op
	int run_step;
	short expected;

} testFn_st;


static testFn_st testCase[]={
	{0, ML_CODE_ADD, setCodeVal_W_N, setInputDIn_Val16_WN_off, verifyResultValueNibble4,
			"ADD off op1+op2", 0, 1, 5678},
	{1, ML_CODE_ADD, setCodeVal_W_N, setInputDIn_Val16_WN_on, verifyResultValueNibble4,
			"ADD on op1+op2", 0, 1, 6912},
	{2, ML_CODE_ADD, setCodeVal_W_N, setInputDIn_Val16_WN_on_overflow, verifyResultValueNibble4,
			"ADD on op1+op2 overflow", 0, 1, -32767},
	{3, ML_CODE_ADD, setCodeVal_N_N, setInputDIn_Val16_NN_off, verifyResultValueNibble4,
			"ADD off op1+op2", 0, 1, 5678},
	{4, ML_CODE_ADD, setCodeVal_N_N, setInputDIn_Val16_NN_on, verifyResultValueNibble4,
			"ADD on op1+op2", 0, 1, 6912},
	{5, ML_CODE_ADD, setCodeVal_K1234_N, setInputSIn_Val16_KN_off, verifyResultValueNibble4,
			"ADD off K+op1", 0, 1, 5678},
	{6, ML_CODE_ADD, setCodeVal_K1234_N, setInputSIn_Val16_KN_on, verifyResultValueNibble4,
			"ADD on K+op1", 0, 1, 6912},

	{7, ML_CODE_ADDP, setCodeVal_W_N, setInputDIn_Val16_WN_off, verifyResultValueNibble4,
			"ADDP off", 0, 2, 5678},
	{8, ML_CODE_ADDP, setCodeVal_W_N, setInputDIn_Val16_WN_on, verifyResultValueNibble4,
			"ADDP off", 0, 2, 5678},
	{9, ML_CODE_ADDP, setCodeVal_W_N, setInputDIn_Val16p_WN_on, verifyResultValueNibble4,
			"ADDP op1 + op2", 0, 2, 6912},
	{10, ML_CODE_ADDP, setCodeVal_W_N, setInputDIn_Val16p_WN_on_overflow, verifyResultValueNibble4,
			"ADDP op1 + op2 overflow", 0, 2, -32767},
	{11, ML_CODE_ADDP, setCodeVal_N_N, setInputDIn_Val16_NN_off, verifyResultValueNibble4,
			"ADDP off", 0, 2, 5678},
	{12, ML_CODE_ADDP, setCodeVal_N_N, setInputDIn_Val16_NN_on, verifyResultValueNibble4,
			"ADDP off", 0, 2, 5678},
	{13, ML_CODE_ADDP, setCodeVal_N_N, setInputDIn_Val16p_NN_on, verifyResultValueNibble4,
			"ADDP op1 + op2", 0, 2, 6912},
	{14, ML_CODE_ADDP, setCodeVal_K1234_N, setInputSIn_Val16_KN_off, verifyResultValueNibble4,
			"ADDP off with K", 0, 2, 5678},
	{15, ML_CODE_ADDP, setCodeVal_K1234_N, setInputSIn_Val16p_KN_on, verifyResultValueNibble4,
			"ADDP K + op1", 0, 2, 6912},

	{16, ML_CODE_SUB, setCodeVal_W_N, setInputDIn_Val16_WN_off, verifyResultValueNibble4,
			"SUB off", 0, 1, 5678},
	{17, ML_CODE_SUB, setCodeVal_W_N, setInputDIn_Val16_WN_on, verifyResultValueNibble4,
			"SUB op2 - op1", 0, 1, 4444},
	{18, ML_CODE_SUB, setCodeVal_W_N, setInputDIn_neg_Val16_WN_on_overflow, verifyResultValueNibble4,
			"SUB op2 - op1 overflow", 0, 1, 32766},
	{19, ML_CODE_SUB, setCodeVal_N_N, setInputDIn_Val16_NN_off, verifyResultValueNibble4,
			"SUB off", 0, 1, 5678},
	{20, ML_CODE_SUB, setCodeVal_N_N, setInputDIn_Val16_NN_on, verifyResultValueNibble4,
			"SUB op2 - nop1", 0, 1, 4444},
	{21, ML_CODE_SUB, setCodeVal_K1234_N, setInputSIn_Val16_KN_off, verifyResultValueNibble4,
			"SUB off with K", 0, 1, 5678},
	{22, ML_CODE_SUB, setCodeVal_K1234_N, setInputSIn_Val16_KN_on, verifyResultValueNibble4,
			"SUB op1 - K", 0, 1, 4444},

	{23, ML_CODE_SUBP, setCodeVal_W_N, setInputDIn_Val16_WN_off, verifyResultValueNibble4,
			"SUBP off", 0, 2, 5678},
	{24, ML_CODE_SUBP, setCodeVal_W_N, setInputDIn_Val16_WN_on, verifyResultValueNibble4,
			"SUBP off", 0, 2, 5678},
	{25, ML_CODE_SUBP, setCodeVal_W_N, setInputDIn_Val16p_WN_on, verifyResultValueNibble4,
			"SUBP op2 - op1", 0, 2, 4444},
	{26, ML_CODE_SUBP, setCodeVal_W_N, setInputDIn_neg_Val16p_WN_on_overflow, verifyResultValueNibble4,
			"SUBP op2 - op1 overflow", 0, 2, 32766},
	{27, ML_CODE_SUBP, setCodeVal_N_N, setInputDIn_Val16_NN_off, verifyResultValueNibble4,
			"SUBP off", 0, 2, 5678},
	{28, ML_CODE_SUBP, setCodeVal_N_N, setInputDIn_Val16_NN_on, verifyResultValueNibble4,
			"SUBP off", 0, 2, 5678},
	{29, ML_CODE_SUBP, setCodeVal_N_N, setInputDIn_Val16p_NN_on, verifyResultValueNibble4,
			"SUBP op2 - nop1", 0, 2, 4444},
	{30, ML_CODE_SUBP, setCodeVal_K1234_N, setInputSIn_Val16_KN_off, verifyResultValueNibble4,
			"SUBP off with K", 0, 2, 5678},
	{31, ML_CODE_SUBP, setCodeVal_K1234_N, setInputSIn_Val16p_KN_on, verifyResultValueNibble4,
			"SUBP op1 - K", 0, 2, 4444},

	{32, ML_CODE_INC, setCodeOp_N, setInputSIn_Val16_KN_off, verifyResultValueNibble4,
			"INC off", 0, 1, 5678},
	{33, ML_CODE_INC, setCodeOp_N, setInputSIn_Val16_KN_on, verifyResultValueNibble4,
			"INC on", 0, 1, 5679},
	{34, ML_CODE_INC, setCodeOp_N, setInputSIn_Val16_N_on_over, verifyResultValueNibble4,
			"INC on", 0, 1, -32768},

	{35, ML_CODE_INCP, setCodeOp_N, setInputSIn_Val16_KN_off, verifyResultValueNibble4,
			"INCP off 0->0", 0, 2, 5678},
	{36, ML_CODE_INCP, setCodeOp_N, setInputSIn_Val16_KN_on, verifyResultValueNibble4,
			"INCP off 1->1", 0, 2, 5678},
	{37, ML_CODE_INCP, setCodeOp_N, setInputSIn_Val16p_KN_on, verifyResultValueNibble4,
			"INCP on", 0, 2, 5679},
	{38, ML_CODE_INCP, setCodeOp_N, setInputSIn_Val16p_N_on_over, verifyResultValueNibble4,
			"INCP on", 0, 2, -32768},

	{39, ML_CODE_DEC, setCodeOp_N, setInputSIn_Val16_KN_off, verifyResultValueNibble4,
			"DEC off", 0, 1, 5678},
	{40, ML_CODE_DEC, setCodeOp_N, setInputSIn_Val16_KN_on, verifyResultValueNibble4,
			"DEC on", 0, 1, 5677},
	{41, ML_CODE_DEC, setCodeOp_N, setInputSIn_Val16_N_on_under, verifyResultValueNibble4,
			"DEC on", 0, 1, 32767},

	{42, ML_CODE_DECP, setCodeOp_N, setInputSIn_Val16_KN_off, verifyResultValueNibble4,
			"DECP off 0->0", 0, 2, 5678},
	{43, ML_CODE_DECP, setCodeOp_N, setInputSIn_Val16_KN_on, verifyResultValueNibble4,
			"DECP off 1->1", 0, 2, 5678},
	{44, ML_CODE_DECP, setCodeOp_N, setInputSIn_Val16p_KN_on, verifyResultValueNibble4,
			"DECP on", 0, 2, 5677},
	{45, ML_CODE_DECP, setCodeOp_N, setInputSIn_Val16p_N_on_under, verifyResultValueNibble4,
			"DECP on", 0, 2, 32767},

	{46, ML_CODE_ADDS, setCodeOp_WWN, setInput2DIn_Val16_off, verifyResultValueNibble4,
			"ADDS off nop3=op1+op2", 1, 1, 0},
	{47, ML_CODE_ADDS, setCodeOp_WWN, setInput2DIn_Val16_on, verifyResultValueNibble4,
			"ADDS on nop3=op1+op2", 1, 1, 6912},
	{48, ML_CODE_ADDS, setCodeOp_NWN, setInput2DIn_Val16_NW_off, verifyResultValueNibble4,
			"ADDS off nop3=nop1+op2", 1, 1, 0},
	{49, ML_CODE_ADDS, setCodeOp_NWN, setInput2DIn_Val16_NW_on, verifyResultValueNibble4,
			"ADDS on nop3=nop1+op2", 1, 1, 6912},
	{50, ML_CODE_ADDS, setCodeOp_NWN, setInput2DIn_Val16_NW_on_overflow, verifyResultValueNibble4,
			"ADDS on nop3=nop1+op2 overflow", 1, 1, -32767},
	{51, ML_CODE_ADDS, setCodeOp_WNN, setInput2DIn_Val16_WN_off, verifyResultValueNibble4,
			"ADDS off nop3=op1+nop2", 1, 1, 0},
	{52, ML_CODE_ADDS, setCodeOp_WNN, setInput2DIn_Val16_WN_on, verifyResultValueNibble4,
			"ADDS nop3=op1+nop2", 1, 1, 6912},
	{53, ML_CODE_ADDS, setCodeOp_K1234_NN, setInputDIn_Val16_KN_off, verifyResultValueNibble4,
			"ADDS off nop2=K+nop1", 1, 1, 0},
	{54, ML_CODE_ADDS, setCodeOp_K1234_NN, setInputDIn_Val16_KN_on, verifyResultValueNibble4,
			"ADDS nop2=K+nop1", 1, 1, 6912},
	{55, ML_CODE_ADDS, setCodeOp_K1234_KN, setInputNIn_Val16_off, verifyResultValueNibble4,
			"ADDS off nop1=K+K", 1, 1, 0},
	{56, ML_CODE_ADDS, setCodeOp_K1234_KN, setInputNIn_Val16_on, verifyResultValueNibble4,
			"ADDS nop1=K+K", 1, 1, 6912},

	{57, ML_CODE_ADDPS, setCodeOp_WWN, setInput2DIn_Val16_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop3=op1+nop2", 1, 2, 0},
	{58, ML_CODE_ADDPS, setCodeOp_WWN, setInput2DIn_Val16_on, verifyResultValueNibble4,
			"ADDPS 1->1 nop3=op1+nop2", 1, 2, 0},
	{59, ML_CODE_ADDPS, setCodeOp_WWN, setInput2DIn_Val16p_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop3=op1+nop2", 1, 2, 6912},
	{60, ML_CODE_ADDPS, setCodeOp_NWN, setInput2DIn_Val16_NW_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop3=nop1+op2", 1, 2, 0},
	{61, ML_CODE_ADDPS, setCodeOp_NWN, setInput2DIn_Val16_NW_on, verifyResultValueNibble4,
			"ADDPS 1->1 nop3=nop1+op2", 1, 2, 0},
	{62, ML_CODE_ADDPS, setCodeOp_NWN, setInput2DIn_Val16p_NW_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop3=nop1+op2", 1, 2, 6912},
	{63, ML_CODE_ADDPS, setCodeOp_NWN, setInput2DIn_Val16p_NW_on_overflow, verifyResultValueNibble4,
			"ADDPS 0->1 nop3=nop1+op2 overflow", 1, 2, -32767},
	{64, ML_CODE_ADDPS, setCodeOp_WNN, setInput2DIn_Val16_WN_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop3=op1+nop2", 1, 2, 0},
	{65, ML_CODE_ADDPS, setCodeOp_WNN, setInput2DIn_Val16_WN_on, verifyResultValueNibble4,
			"ADDPS 1->1 nop3=op1+nop2", 1, 2, 0},
	{66, ML_CODE_ADDPS, setCodeOp_WNN, setInput2DIn_Val16p_WN_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop3=op1+nop2", 1, 2, 6912},
	{67, ML_CODE_ADDPS, setCodeOp_K1234_NN, setInputDIn_Val16_KN_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop2=K+nop1", 1, 2, 0},
	{68, ML_CODE_ADDPS, setCodeOp_K1234_NN, setInputDIn_Val16_KN_on, verifyResultValueNibble4,
			"ADDPS 1->1 nop2=K+nop1", 1, 2, 0},
	{69, ML_CODE_ADDPS, setCodeOp_K1234_NN, setInputDIn_Val16p_KN_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop2=K+nop1", 1, 2, 6912},
	{70, ML_CODE_ADDPS, setCodeOp_K1234_KN, setInputNIn_Val16_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop1=K+K", 1, 2, 0},
	{71, ML_CODE_ADDPS, setCodeOp_K1234_KN, setInputNIn_Val16_on, verifyResultValueNibble4,
			"ADDPS 1->1 nop1=K+K", 1, 2, 0},
	{72, ML_CODE_ADDPS, setCodeOp_K1234_KN, setInputNIn_Val16p_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop1=K+K", 1, 2, 6912},

	{73, ML_CODE_SUBS, setCodeOp_WWN, setInput2DIn_Val16_off, verifyResultValueNibble4,
			"SUBS off nop3=op1-nop2", 1, 1, 0},
	{74, ML_CODE_SUBS, setCodeOp_WWN, setInput2DIn_Val16_on, verifyResultValueNibble4,
			"SUBS on nop3=op1-nop2", 1, 1, -4444},
	{75, ML_CODE_SUBS, setCodeOp_NWN, setInput2DIn_Val16_NW_off, verifyResultValueNibble4,
			"SUBS off nop3=nop1-op2", 1, 1, 0},
	{76, ML_CODE_SUBS, setCodeOp_NWN, setInput2DIn_Val16_NW_on, verifyResultValueNibble4,
			"SUBS on nop3=nop1-op2", 1, 1, -4444},
	{77, ML_CODE_SUBS, setCodeOp_NWN, setInputDIn_neg_Val16_NW_on_overflow, verifyResultValueNibble4,
			"SUBS on nop3=nop1-op2 overflow", 1, 1, -32767},
	{78, ML_CODE_SUBS, setCodeOp_WNN, setInput2DIn_Val16_WN_off, verifyResultValueNibble4,
			"SUBS off nop3=op1-nop2", 1, 1, 0},
	{79, ML_CODE_SUBS, setCodeOp_WNN, setInput2DIn_Val16_WN_on, verifyResultValueNibble4,
			"SUBS on nop3=op1-nop2", 1, 1, -4444},
	{80, ML_CODE_SUBS, setCodeOp_K1234_NN, setInputDIn_Val16_KN_off, verifyResultValueNibble4,
			"SUBS off nop2=K-op1", 1, 1, 0},
	{81, ML_CODE_SUBS, setCodeOp_K1234_NN, setInputDIn_Val16_KN_on, verifyResultValueNibble4,
			"SUBS on nop2=K-op1", 1, 1, -4444},
	{82, ML_CODE_SUBS, setCodeOp_K1234_KN, setInputNIn_Val16_off, verifyResultValueNibble4,
			"SUBS off nop1=K-K", 1, 1, 0},
	{83, ML_CODE_SUBS, setCodeOp_K1234_KN, setInputNIn_Val16_on, verifyResultValueNibble4,
			"SUBS on nop1=K-K", 1, 1, 4444},

	{84, ML_CODE_SUBPS, setCodeOp_WWN, setInput2DIn_Val16_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop3=op1-nop2", 1, 2, 0},
	{85, ML_CODE_SUBPS, setCodeOp_WWN, setInput2DIn_Val16_on, verifyResultValueNibble4,
			"SUBPS 1->1 nop3=op1-nop2", 1, 2, 0},
	{86, ML_CODE_SUBPS, setCodeOp_WWN, setInput2DIn_Val16p_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop3=op1-nop2", 1, 2, -4444},
	{87, ML_CODE_SUBPS, setCodeOp_NWN, setInput2DIn_Val16_NW_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop3=nop1-op2", 1, 2, 0},
	{88, ML_CODE_SUBPS, setCodeOp_NWN, setInput2DIn_Val16_NW_on, verifyResultValueNibble4,
			"SUBPS 1->1 nop3=nop1-op2", 1, 2, 0},
	{89, ML_CODE_SUBPS, setCodeOp_NWN, setInput2DIn_Val16p_NW_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop3=nop1-op2", 1, 2, -4444},
	{90, ML_CODE_SUBPS, setCodeOp_NWN, setInputDIn_neg_Val16p_NW_on_overflow, verifyResultValueNibble4,
			"SUBPS 0->1 nop3=nop1-op2 overflow", 1, 2, -32767},
	{91, ML_CODE_SUBPS, setCodeOp_WNN, setInput2DIn_Val16_WN_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop3=op1-nop2", 1, 2, 0},
	{92, ML_CODE_SUBPS, setCodeOp_WNN, setInput2DIn_Val16_WN_on, verifyResultValueNibble4,
			"SUBPS 1->1 nop3=op1-nop2", 1, 2, 0},
	{93, ML_CODE_SUBPS, setCodeOp_WNN, setInput2DIn_Val16p_WN_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop3=op1-nop2", 1, 2, -4444},
	{94, ML_CODE_SUBPS, setCodeOp_K1234_NN, setInputDIn_Val16_KN_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop2=K-nop1", 1, 2, 0},
	{95, ML_CODE_SUBPS, setCodeOp_K1234_NN, setInputDIn_Val16_KN_on, verifyResultValueNibble4,
			"SUBPS 1->1 nop2=K-nop1", 1, 2, 0},
	{96, ML_CODE_SUBPS, setCodeOp_K1234_NN, setInputDIn_Val16p_KN_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop2=K-nop1", 1, 2, -4444},
	{97, ML_CODE_SUBPS, setCodeOp_K1234_KN, setInputNIn_Val16_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop1=K-K", 1, 2, 0},
	{98, ML_CODE_SUBPS, setCodeOp_K1234_KN, setInputNIn_Val16_on, verifyResultValueNibble4,
			"SUBPS 1->1 nop1=K-K", 1, 2, 0},
	{99, ML_CODE_SUBPS, setCodeOp_K1234_KN, setInputNIn_Val16p_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop1=K-K", 1, 2, 4444},

	{100, ML_CODE_BADD, setCodeVal_W_N, setInputDIn_BCD_WN_off, verifyResultValueNibble4,
			"BCD ADD off nop2+op1", 0, 1, 22136}, //0x5678
	{101, ML_CODE_BADD, setCodeVal_W_N, setInputDIn_BCD_WN_on, verifyResultValueNibble4,
			"BCD ADD on nop2+op1", 0, 1, 26898}, //0x6912
	{102, ML_CODE_BADD, setCodeVal_W_N, setInputDIn_BCD_WN_on_overflow, verifyResultValueNibble4,
			"BCD ADD on nop2+op1 overflow OK", 0, 1, 21}, //0x15
	{103, ML_CODE_BADD, setCodeVal_N_N, setInputDIn_BCD_NN_off, verifyResultValueNibble4,
			"BCD ADD off nop2+nop1", 0, 1, 22136}, //0x5678
	{104, ML_CODE_BADD, setCodeVal_N_N, setInputDIn_BCD_NN_on, verifyResultValueNibble4,
			"BCD ADD on nop2+nop1", 0, 1, 26898}, //0x6912
	{105, ML_CODE_BADD, setCodeOp_K0x1234_N, setInputDIn_BCD_KN_off, verifyResultValueNibble4,
			"BCD ADD off nop1+K", 0, 1, 22136}, //0x5678
	{106, ML_CODE_BADD, setCodeOp_K0x1234_N, setInputDIn_BCD_KN_on, verifyResultValueNibble4,
			"BCD ADD on nop1+K", 0, 1, 26898}, //0x6912

	{107, ML_CODE_BADDP, setCodeVal_W_N, setInputDIn_BCD_WN_off, verifyResultValueNibble4,
			"BCD ADDP 0->0 nop2+op1", 0, 2, 22136}, //0x5678
	{108, ML_CODE_BADDP, setCodeVal_W_N, setInputDIn_BCD_WN_on, verifyResultValueNibble4,
			"BCD ADDP 1->1 nop2+op1", 0, 2, 22136}, //0x5678
	{109, ML_CODE_BADDP, setCodeVal_W_N, setInputDIn_BCDp_WN_on, verifyResultValueNibble4,
			"BCD ADDP 0->1 nop2+op1", 0, 2, 26898}, //0x6912
	{110, ML_CODE_BADDP, setCodeVal_W_N, setInputDIn_BCDp_WN_on_overflow, verifyResultValueNibble4,
			"BCD ADDP nop2+op1 overflow OK", 0, 2, 21}, //0x15
	{111, ML_CODE_BADDP, setCodeVal_N_N, setInputDIn_BCD_NN_off, verifyResultValueNibble4,
			"BCD ADDP 0->0 nop2+nop1", 0, 2, 22136}, //0x5678
	{112, ML_CODE_BADDP, setCodeVal_N_N, setInputDIn_BCD_NN_on, verifyResultValueNibble4,
			"BCD ADDP 1->0 nop2+nop1", 0, 2, 22136}, //0x5678
	{113, ML_CODE_BADDP, setCodeVal_N_N, setInputDIn_BCDp_NN_on, verifyResultValueNibble4,
			"BCD ADDP 0->1 nop2+nop1", 0, 2, 26898}, //0x6912
	{114, ML_CODE_BADDP, setCodeOp_K0x1234_N, setInputDIn_BCD_KN_off, verifyResultValueNibble4,
			"BCD ADDP 0->0 op1+K", 0, 2, 22136}, //0x5678
	{115, ML_CODE_BADDP, setCodeOp_K0x1234_N, setInputDIn_BCDp_KN_on, verifyResultValueNibble4,
			"BCD ADDP 0->1 op1+K", 0, 2, 26898}, //0x6912

	{116, ML_CODE_BSUB, setCodeVal_W_N, setInputDIn_BCD_WN_off, verifyResultValueNibble4,
			"BCD SUB off nop2-op1", 0, 1, 22136}, //0x5678
	{117, ML_CODE_BSUB, setCodeVal_W_N, setInputDIn_BCD_WN_on, verifyResultValueNibble4,
			"BCD SUB on nop2-op1", 0, 1, 17476}, //0x4444
	{118, ML_CODE_BSUB, setCodeVal_W_N, setInputDIn_neg_BCD_WN_on_overflow, verifyResultValueNibble4,
			"BCD SUB on nop2-op1 overflow ", 0, 1, -26216}, //0x9998
	{119, ML_CODE_BSUB, setCodeVal_N_N, setInputDIn_BCD_NN_off, verifyResultValueNibble4,
			"BCD SUB off nop2-nop1", 0, 1, 22136}, //0x5678
	{120, ML_CODE_BSUB, setCodeVal_N_N, setInputDIn_BCD_NN_on, verifyResultValueNibble4,
			"BCD SUB on nop2-nop1", 0, 1, 17476}, //0x4444
	{121, ML_CODE_BSUB, setCodeOp_K0x1234_N, setInputDIn_BCD_KN_off, verifyResultValueNibble4,
			"BCD SUB off nop1-K", 0, 1, 22136}, //0x5678
	{122, ML_CODE_BSUB, setCodeOp_K0x1234_N, setInputDIn_BCD_KN_on, verifyResultValueNibble4,
			"BCD SUB on nop1-K", 0, 1, 17476}, //0x4444

	{123, ML_CODE_BSUBP, setCodeVal_W_N, setInputDIn_BCD_WN_off, verifyResultValueNibble4,
			"BCD SUBP 0->0 nop2-op1", 0, 2, 22136}, //0x5678
	{124, ML_CODE_BSUBP, setCodeVal_W_N, setInputDIn_BCD_WN_on, verifyResultValueNibble4,
			"BCD SUBP 1->1 nop2-op1", 0, 2, 22136}, //0x5678
	{125, ML_CODE_BSUBP, setCodeVal_W_N, setInputDIn_BCDp_WN_on, verifyResultValueNibble4,
			"BCD SUBP 0->1 nop2-op1", 0, 2, 17476}, //0x4444
	{126, ML_CODE_BSUBP, setCodeVal_W_N, setInputDIn_neg_BCDp_WN_on_overflow, verifyResultValueNibble4,
			"BCD SUBP 0->1 nop2-op1 overflow ", 0, 2, -26216}, //0x9998
	{127, ML_CODE_BSUBP, setCodeVal_N_N, setInputDIn_BCD_NN_off, verifyResultValueNibble4,
			"BCD SUBP 0->0 nop2-nop1", 0, 2, 22136}, //0x5678
	{128, ML_CODE_BSUBP, setCodeVal_N_N, setInputDIn_BCD_NN_on, verifyResultValueNibble4,
			"BCD SUBP 1->1 nop2-nop1", 0, 2, 22136}, //0x5678
	{129, ML_CODE_BSUBP, setCodeVal_N_N, setInputDIn_BCDp_NN_on, verifyResultValueNibble4,
			"BCD SUBP 0->1 nop2-nop1", 0, 2, 17476}, //0x4444
	{130, ML_CODE_BSUBP, setCodeOp_K0x1234_N, setInputDIn_BCD_KN_off, verifyResultValueNibble4,
			"BCD SUBP 0->0 nop1-K", 0, 2, 22136}, //0x5678
	{131, ML_CODE_BSUBP, setCodeOp_K0x1234_N, setInputDIn_BCDp_KN_on, verifyResultValueNibble4,
			"BCD SUBP 0->1 nop1-K", 0, 2, 17476}, //0x4444

	{132, ML_CODE_BADDS, setCodeOp_WWN, setInputDIn_BCD_in_off, verifyResultValueNibble4,
			"BCD ADDS off nop3=op2+op1", 1, 1, 0},
	{133, ML_CODE_BADDS, setCodeOp_WWN, setInputDIn_BCD_in_on, verifyResultValueNibble4,
			"BCD ADDS on nop3=op2+op1", 1, 1, 26898}, //0x6912
	{134, ML_CODE_BADDS, setCodeOp_NWN, setInput1DIn_BCD_NW_off, verifyResultValueNibble4,
			"BCD ADDS off nop3=op2+nop1", 1, 1, 0},
	{135, ML_CODE_BADDS, setCodeOp_NWN, setInput1DIn_BCD_NW_on, verifyResultValueNibble4,
			"BCD ADDS on nop3=op2+nop1", 1, 1, 26898}, //0x6912
	{136, ML_CODE_BADDS, setCodeOp_WNN, setInput2DIn_BCD_WN_off, verifyResultValueNibble4,
			"BCD ADDS off nop3=nop2+op1", 1, 1, 0},
	{137, ML_CODE_BADDS, setCodeOp_WNN, setInput2DIn_BCD_WN_on, verifyResultValueNibble4,
			"BCD ADDS on nop3=nop2+op1", 1, 1, 26898}, //0x6912
	{138, ML_CODE_BADDS, setCodeOp_K0x1234_NN, setInput1DIn_BCD_KN_off, verifyResultValueNibble4,
			"BCD ADDS off nop2=op1+K", 1, 1, 0},
	{139, ML_CODE_BADDS, setCodeOp_K0x1234_NN, setInput1DIn_BCD_KN_on, verifyResultValueNibble4,
			"BCD ADDS on nop2=op1+K", 1, 1, 26898}, //0x6912
	{140, ML_CODE_BADDS, setCodeOp_K0x1234_KN, setInputNIn_Val16_off, verifyResultValueNibble4,
			"BCD ADDS off nop1=K+K", 1, 1, 0},
	{141, ML_CODE_BADDS, setCodeOp_K0x1234_KN, setInputNIn_Val16_on, verifyResultValueNibble4,
			"BCD ADDS on nop1=K+K", 1, 1, 26898}, //0x6912

	{142, ML_CODE_BADDPS, setCodeOp_WWN, setInputDIn_BCD_in_off, verifyResultValueNibble4,
			"BCD ADDPS off", 1, 2, 0},
	{143, ML_CODE_BADDPS, setCodeOp_WWN, setInputDIn_BCD_in_on, verifyResultValueNibble4,
			"BCD ADDPS off", 1, 2, 0},
	{144, ML_CODE_BADDPS, setCodeOp_WWN, setInputDIn_BCDp_in_on, verifyResultValueNibble4,
			"BCD ADDPS op3=op2+op1", 1, 2, 26898}, //0x6912
	{145, ML_CODE_BADDPS, setCodeOp_NWN, setInput1DIn_BCD_NW_off, verifyResultValueNibble4,
			"BCD ADDPS off", 1, 2, 0},
	{146, ML_CODE_BADDPS, setCodeOp_NWN, setInput1DIn_BCD_NW_on, verifyResultValueNibble4,
			"BCD ADDPS off", 1, 2, 0},
	{147, ML_CODE_BADDPS, setCodeOp_NWN, setInput1DIn_BCDp_NW_on, verifyResultValueNibble4,
			"BCD ADDPS op3=op2+op1", 1, 2, 26898}, //0x6912
	{148, ML_CODE_BADDPS, setCodeOp_WNN, setInput2DIn_BCD_WN_off, verifyResultValueNibble4,
			"BCD ADDPS off", 1, 2, 0},
	{149, ML_CODE_BADDPS, setCodeOp_WNN, setInput2DIn_BCD_WN_on, verifyResultValueNibble4,
			"BCD ADDPS off", 1, 2, 0},
	{150, ML_CODE_BADDPS, setCodeOp_WNN, setInput2DIn_BCDp_WN_on, verifyResultValueNibble4,
			"BCD ADDPS op3=op2+op1", 1, 2, 26898}, //0x6912
	{151, ML_CODE_BADDPS, setCodeOp_K0x1234_NN, setInput1DIn_BCD_KN_off, verifyResultValueNibble4,
			"BCD ADDPS off with K", 1, 2, 0},
	{152, ML_CODE_BADDPS, setCodeOp_K0x1234_NN, setInput1DIn_BCD_KN_on, verifyResultValueNibble4,
			"BCD ADDPS off with K", 1, 2, 0},
	{153, ML_CODE_BADDPS, setCodeOp_K0x1234_NN, setInput1DIn_BCDp_KN_on, verifyResultValueNibble4,
			"BCD ADDPS op2=op1+K", 1, 2, 26898}, //0x6912
	{154, ML_CODE_BADDPS, setCodeOp_K0x1234_KN, setInputNIn_Val16_off, verifyResultValueNibble4,
			"BCD ADDPS off with 2K", 1, 2, 0},
	{155, ML_CODE_BADDPS, setCodeOp_K0x1234_KN, setInputNIn_Val16_on, verifyResultValueNibble4,
			"BCD ADDPS off with 2K", 1, 2, 0},
	{156, ML_CODE_BADDPS, setCodeOp_K0x1234_KN, setInputNIn_Val16p_on, verifyResultValueNibble4,
			"BCD ADDPS op1=K+K", 1, 2, 26898}, //0x6912

	{157, ML_CODE_BSUBS, setCodeOp_WWN, setInputDIn_BCD_in_off, verifyResultValueNibble4,
			"BCD SUBS off", 1, 1, 0},
	{158, ML_CODE_BSUBS, setCodeOp_WWN, setInputDIn_BCD_in_on, verifyResultValueNibble4,
			"BCD SUBS op3=op1-op2", 1, 1, 17476}, //0x4444
	{159, ML_CODE_BSUBS, setCodeOp_NWN, setInput1DIn_BCD_NW_off, verifyResultValueNibble4,
			"BCD SUBS off", 1, 1, 0},
	{160, ML_CODE_BSUBS, setCodeOp_NWN, setInput1DIn_BCD_NW_on, verifyResultValueNibble4,
			"BCD SUBS op3=op1-op2", 1, 1, 21846}, //0x5556
	{161, ML_CODE_BSUBS, setCodeOp_WNN, setInput2DIn_BCD_WN_off, verifyResultValueNibble4,
			"BCD SUBS off", 1, 1, 0},
	{162, ML_CODE_BSUBS, setCodeOp_WNN, setInput2DIn_BCD_WN_on, verifyResultValueNibble4,
			"BCD SUBS op3=op1-op2", 1, 1, 21846}, //0x5556
	{163, ML_CODE_BSUBS, setCodeOp_K0x1234_NN, setInput1DIn_BCD_KN_off, verifyResultValueNibble4,
			"BCD SUBS off with K", 1, 1, 0},
	{164, ML_CODE_BSUBS, setCodeOp_K0x1234_NN, setInput1DIn_BCD_KN_on, verifyResultValueNibble4,
			"BCD SUBS op2=K-op1", 1, 1, 21846}, //0x5556
	{165, ML_CODE_BSUBS, setCodeOp_K0x1234_KN, setInputNIn_Val16_off, verifyResultValueNibble4,
			"BCD SUBS off with 2K", 1, 1, 0},
	{166, ML_CODE_BSUBS, setCodeOp_K0x1234_KN, setInputNIn_Val16_on, verifyResultValueNibble4,
			"BCD SUBS op1=K1-K2", 1, 1, 21846}, //0x5556

	{167, ML_CODE_BSUBPS, setCodeOp_WWN, setInputDIn_BCD_in_off, verifyResultValueNibble4,
			"BCD SUBPS off", 1, 2, 0},
	{168, ML_CODE_BSUBPS, setCodeOp_WWN, setInputDIn_BCD_in_on, verifyResultValueNibble4,
			"BCD SUBPS off", 1, 2, 0},
	{169, ML_CODE_BSUBPS, setCodeOp_WWN, setInputDIn_BCDp_in_on, verifyResultValueNibble4,
			"BCD SUBPS op3=op1-op2", 1, 2, 17476}, //0x4444
	{170, ML_CODE_BSUBPS, setCodeOp_NWN, setInput1DIn_BCD_NW_off, verifyResultValueNibble4,
			"BCD SUBPS off", 1, 2, 0},
	{171, ML_CODE_BSUBPS, setCodeOp_NWN, setInput1DIn_BCD_NW_on, verifyResultValueNibble4,
			"BCD SUBPS off", 1, 2, 0},
	{172, ML_CODE_BSUBPS, setCodeOp_NWN, setInput1DIn_BCDp_NW_on, verifyResultValueNibble4,
			"BCD SUBPS op3=op1-op2", 1, 2, 21846}, //0x5556
	{173, ML_CODE_BSUBPS, setCodeOp_WNN, setInput2DIn_BCD_WN_off, verifyResultValueNibble4,
			"BCD SUBPS off", 1, 2, 0},
	{174, ML_CODE_BSUBPS, setCodeOp_WNN, setInput2DIn_BCD_WN_on, verifyResultValueNibble4,
			"BCD SUBPS off", 1, 2, 0},
	{175, ML_CODE_BSUBPS, setCodeOp_WNN, setInput2DIn_BCDp_WN_on, verifyResultValueNibble4,
			"BCD SUBPS op3=op1-op2", 1, 2, 21846}, //0x5556
	{176, ML_CODE_BSUBPS, setCodeOp_K0x1234_NN, setInput1DIn_BCD_KN_off, verifyResultValueNibble4,
			"BCD SUBPS off with K", 1, 2, 0},
	{177, ML_CODE_BSUBPS, setCodeOp_K0x1234_NN, setInput1DIn_BCD_KN_on, verifyResultValueNibble4,
			"BCD SUBPS off with K", 1, 2, 0},
	{178, ML_CODE_BSUBPS, setCodeOp_K0x1234_NN, setInput1DIn_BCDp_KN_on, verifyResultValueNibble4,
			"BCD SUBPS op2=K-op1", 1, 2, 21846}, //0x5556
	{179, ML_CODE_BSUBPS, setCodeOp_K0x1234_KN, setInputNIn_Val16_off, verifyResultValueNibble4,
			"BCD SUBPS off with 2K", 1, 2, 0},
	{180, ML_CODE_BSUBPS, setCodeOp_K0x1234_KN, setInputNIn_Val16_on, verifyResultValueNibble4,
			"BCD SUBPS off with 2K", 1, 2, 0},
	{181, ML_CODE_BSUBPS, setCodeOp_K0x1234_KN, setInputNIn_Val16p_on, verifyResultValueNibble4,
			"BCD SUBPS op1=K1-K2", 1, 2, 21846}, //0x5556

	{-1, 0xFFFF, NULL, NULL, NULL, " ", 0, 0 }
};


int total_basic_compute_word_nb_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_word_nb_test_number; i++)
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

int setCodeOp_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_WWN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 160);
		addMLOperandNibble(4, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_NWN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_D, 160);
		addMLOperandNibble(4, out_reg, out_pos);
	//printf("Nibble out : 4, %d, %d\n", out_reg, out_pos);

	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_WNN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_D, in_pos); addMLOperandNibble(4, in_reg, 160);
		addMLOperandNibble(4, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_K0x1234_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_K1234_NN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 1234); addMLOperandNibble(4, in_reg, in_pos);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_K1234_KN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 5678); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


int setCodeOp_K0x1234_NN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperandNibble(4, in_reg, in_pos);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_K0x1234_KN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperand(OPERAND_ML_CODE_K, 0x5678);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}



void setInputDIn_Val16_WN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16p_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_Val16_NN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=1234;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16_NN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=1234;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16p_NN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=1234;
	short value2=5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val16_KN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16p_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16_KN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16p_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputDIn_Val16_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=2;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16p_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=2;

	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput2DIn_Val16_NW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 2);

	TestCodeTearDown();
}

void setInput2DIn_Val16p_NW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=32767;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 2);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_neg_Val16_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=-32768;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 2);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_neg_Val16p_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=-32768;

	addDeviceControlInstruction(0, (uint8)in, in_pos, 2);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_neg_Val16_NW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=2;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, -32767);

	TestCodeTearDown();
}

void setInputDIn_neg_Val16p_NW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=2;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, -32767);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val16_N_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16p_N_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16_N_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=-32768;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16p_N_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=-32768;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_NW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 5678);

	TestCodeTearDown();
}

void setInput2DIn_Val16_NW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 5678);

	TestCodeTearDown();
}

void setInput2DIn_Val16p_NW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=1234;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput2DIn_Val16_WN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, 1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, 1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16p_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, 1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_BCD_WN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCD_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCDp_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_BCD_NN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=0x1234;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCD_NN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=0x1234;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCDp_NN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=0x1234;
	short value2=0x5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_BCD_KN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCD_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCDp_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_BCD_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x3583;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x6432);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCDp_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x3583;

	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x6432);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_neg_BCD_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=1;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 3);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_neg_BCDp_WN_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=1;

	addDeviceControlInstruction(0, (uint8)in, in_pos, 3);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput1DIn_BCD_NW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=0x1234;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 0x5678);

	TestCodeTearDown();
}

void setInput1DIn_BCD_NW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=0x1234;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 0x5678);

	TestCodeTearDown();
}

void setInput1DIn_BCDp_NW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value1=0x1234;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value1>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, 0x5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}


void setInput2DIn_BCD_WN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, 0x1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_BCD_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, 0x1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_BCDp_WN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, 0x1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}


void setInput1DIn_BCD_KN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput1DIn_BCD_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput1DIn_BCDp_KN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value2=0x5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value2>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}


static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12286,8190}}; //16bit

	return pos[inx_pos][reg];
}


static FILE *flog;
void test_basic_arithmetic_word_nb(int tno, uint16 dummy)
{
	int i=0, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos;
	short res_word;
	long long res_nword;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getPos(out, olast);

			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in, i);
					//printf("1: in=%d in_pos=%d out_pos=%d  out=%d olast=%d\n", in, in_pos, out_pos, out, olast);
					if(in == out && in_pos == out_pos )
					{
						continue;
					}

					rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if(rc2 == 0) continue;
					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

					//printf("2: in=%d in_pos=%d out_pos=%d  out=%d olast=%d\n", in, in_pos, out_pos, out, olast);
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
							test_getNibble(&res_word, out, out_pos, 4);

							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, (short)res_word, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testBasicArithmeticWordNibbleCommand(void)
{
	int i, index=135;
	int start, end;
	char log[] = "err_arith_word_nb.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic word nibble LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=36;index<45;index++)
		test_basic_arithmetic_word_nb(index, 0);
#else
	total_basic_compute_word_nb_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_ADD);
	end = getTestCaseNumberEnd(ML_CODE_BSUBPS); //ML_CODE_BSUBPS

	DBG_LOGPRINT("testBasicArithmeticWordCommand: %d to %d total %d\n", start, end, total_basic_compute_word_nb_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_word_nb(index, 0); // out register position 0
	}
#endif
	fclose(flog);
}

#endif
