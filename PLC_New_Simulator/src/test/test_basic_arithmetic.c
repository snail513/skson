/*
 * test_basic_arithmatic.c
 *
 *  Created on: Feb 6, 2015
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


int setCodeLD_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_3op_in(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_3op_out(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_K_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_2K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_K_2op_div(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD_K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD_K_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD_2K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

int setCodeOp_N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp_N1_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp_N2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputDIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_Val16_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_Val16p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val16_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val16p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_neg_Val16_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_neg_Val16p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_in_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_BCD_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCDp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_in_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCDp_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCDp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCDp_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_BCD_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_BCDp_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCDp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputIn_BCD_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputIn_BCD_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputIn_BCDp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_Val16_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_N2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCDp_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCDp_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_N2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCDp_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

int verifyResultValueWord(int tcase, uint8 dest_reg, uint16 pos, short expected);

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
	int run_step;
	short expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_ADD, setCodeLD_2op, setInputDIn_Val16_off, verifyResultValueWord,
			"ADD off", 1, 5678},
	{1, ML_CODE_ADD, setCodeLD_2op, setInputDIn_Val16_on, verifyResultValueWord,
			"ADD op1 + op2", 1, 6912},
	{2, ML_CODE_ADD, setCodeLD_2op, setInputDIn_Val16_on_overflow, verifyResultValueWord,
			"ADD op1 + op2 overflow", 1, -32767},
	{3, ML_CODE_ADD, setCodeLD_K_1op, setInputSIn_Val16_off, verifyResultValueWord,
			"ADD off with K", 1, 5678},
	{4, ML_CODE_ADD, setCodeLD_K_1op, setInputSIn_Val16_on, verifyResultValueWord,
			"ADD K + op1", 1, 6912},
	{5, ML_CODE_ADD, setCodeOp_N_W, setInputDIn_Val16_N1_off, verifyResultValueWord,
			"ADD off", 1, 5678},
	{6, ML_CODE_ADD, setCodeOp_N_W, setInputDIn_Val16_N1_on, verifyResultValueWord,
			"ADD nop1 + op2", 1, 6912},

	{7, ML_CODE_ADDP, setCodeLD_2op, setInputDIn_Val16_off, verifyResultValueWord,
			"ADDP in off 0 -> 0", 2, 5678},
	{8, ML_CODE_ADDP, setCodeLD_2op, setInputDIn_Val16_on, verifyResultValueWord,
			"ADDP in off 1 -> 1", 2, 5678},
	{9, ML_CODE_ADDP, setCodeLD_2op, setInputDIn_Val16p_on, verifyResultValueWord,
			"ADDP on op1 + op2", 2, 6912},
	{10, ML_CODE_ADDP, setCodeLD_2op, setInputDIn_Val16p_on_overflow, verifyResultValueWord,
			"ADDP on op1 + op2 overflow", 2, -32767},
	{11, ML_CODE_ADDP, setCodeLD_K_1op, setInputSIn_Val16_off, verifyResultValueWord,
			"ADDP off with K", 2, 5678},
	{12, ML_CODE_ADDP, setCodeLD_K_1op, setInputSIn_Val16p_on, verifyResultValueWord,
			"ADDP K + op1", 2, 6912},
	{13, ML_CODE_ADDP, setCodeOp_N_W, setInputDIn_Val16_N1_off, verifyResultValueWord,
			"ADDP off", 2, 5678},
	{14, ML_CODE_ADDP, setCodeOp_N_W, setInputDIn_Val16_N1_on, verifyResultValueWord,
			"ADDP off", 2, 5678},
	{15, ML_CODE_ADDP, setCodeOp_N_W, setInputDIn_Val16p_N1_on, verifyResultValueWord,
			"ADDP nop1 + op2", 2, 6912},

	{16, ML_CODE_SUB, setCodeLD_2op, setInputDIn_Val16_off, verifyResultValueWord,
			"SUB off", 1, 5678},
	{17, ML_CODE_SUB, setCodeLD_2op, setInputDIn_Val16_on, verifyResultValueWord,
			"SUB op2-op1", 1, 4444},
	{18, ML_CODE_SUB, setCodeLD_2op, setInputDIn_neg_Val16_on_overflow, verifyResultValueWord,
			"SUB op2-op1 overflow", 1, 32766},
	{19, ML_CODE_SUB, setCodeLD_K_1op, setInputSIn_Val16_off, verifyResultValueWord,
			"SUB off with K", 1, 5678},
	{20, ML_CODE_SUB, setCodeLD_K_1op, setInputSIn_Val16_on, verifyResultValueWord,
			"SUB op1-K", 1, 4444},
	{21, ML_CODE_SUB, setCodeOp_N_W, setInputDIn_Val16_N1_off, verifyResultValueWord,
			"SUB off", 1, 5678},
	{22, ML_CODE_SUB, setCodeOp_N_W, setInputDIn_Val16_N1_on, verifyResultValueWord,
			"SUB op2-nop1", 1, 4444},

	{23, ML_CODE_SUBP, setCodeLD_2op, setInputDIn_Val16_off, verifyResultValueWord,
			"SUBP 0->0", 2, 5678},
	{24, ML_CODE_SUBP, setCodeLD_2op, setInputDIn_Val16_on, verifyResultValueWord,
			"SUBP 1->1", 2, 5678},
	{25, ML_CODE_SUBP, setCodeLD_2op, setInputDIn_Val16p_on, verifyResultValueWord,
			"SUBP 0->1 op2-op1", 2, 4444},
	{26, ML_CODE_SUBP, setCodeLD_2op, setInputDIn_neg_Val16p_on_overflow, verifyResultValueWord,
			"SUBP 0->1 op2-op1 overflow", 2, 32766},
	{27, ML_CODE_SUBP, setCodeLD_K_1op, setInputSIn_Val16_off, verifyResultValueWord,
			"SUBP off with K", 2, 5678},
	{28, ML_CODE_SUBP, setCodeLD_K_1op, setInputSIn_Val16p_on, verifyResultValueWord,
			"SUBP op1-K", 2, 4444},
	{29, ML_CODE_SUBP, setCodeOp_N_W, setInputDIn_Val16_N1_off, verifyResultValueWord,
			"SUBP 0->0", 2, 5678},
	{30, ML_CODE_SUBP, setCodeOp_N_W, setInputDIn_Val16_N1_on, verifyResultValueWord,
			"SUBP 1->1", 2, 5678},
	{31, ML_CODE_SUBP, setCodeOp_N_W, setInputDIn_Val16p_N1_on, verifyResultValueWord,
			"SUBP op2-nop1", 2, 4444},

	{32, ML_CODE_INC, setCodeLD_1op, setInputSIn_Val16_off, verifyResultValueWord,
			"INC off", 1, 5678},
	{33, ML_CODE_INC, setCodeLD_1op, setInputSIn_Val16_on, verifyResultValueWord,
			"INC on", 1, 5679},
	{34, ML_CODE_INC, setCodeLD_1op, setInputSIn_Val16_on_over, verifyResultValueWord,
			"INC on", 1, -32768},

	{35, ML_CODE_INCP, setCodeLD_1op, setInputSIn_Val16_off, verifyResultValueWord,
			"INCP off 0->0", 2, 5678},
	{36, ML_CODE_INCP, setCodeLD_1op, setInputSIn_Val16_on, verifyResultValueWord,
			"INCP off 1->1", 2, 5678},
	{37, ML_CODE_INCP, setCodeLD_1op, setInputSIn_Val16p_on, verifyResultValueWord,
			"INCP on", 2, 5679},
	{38, ML_CODE_INCP, setCodeLD_1op, setInputSIn_Val16p_on_over, verifyResultValueWord,
			"INCP on", 2, -32768},

	{39, ML_CODE_DEC, setCodeLD_1op, setInputSIn_Val16_off, verifyResultValueWord,
			"DEC off", 1, 5678},
	{40, ML_CODE_DEC, setCodeLD_1op, setInputSIn_Val16_on, verifyResultValueWord,
			"DEC on", 1, 5677},
	{41, ML_CODE_DEC, setCodeLD_1op, setInputSIn_Val16_on_under, verifyResultValueWord,
			"DEC on", 1, 32767},

	{42, ML_CODE_DECP, setCodeLD_1op, setInputSIn_Val16_off, verifyResultValueWord,
			"DECP off 0->0", 2, 5678},
	{43, ML_CODE_DECP, setCodeLD_1op, setInputSIn_Val16_on, verifyResultValueWord,
			"DECP off 1->1", 2, 5678},
	{44, ML_CODE_DECP, setCodeLD_1op, setInputSIn_Val16p_on, verifyResultValueWord,
			"DECP on", 2, 5677},
	{45, ML_CODE_DECP, setCodeLD_1op, setInputSIn_Val16p_on_under, verifyResultValueWord,
			"DECP on", 2, 32767},

	{46, ML_CODE_ADDS, setCodeLD_3op_in, setInput2DIn_Val16_off, verifyResultValueWord,
			"ADDS off", 1, 0},
	{47, ML_CODE_ADDS, setCodeLD_3op_in, setInput2DIn_Val16_on, verifyResultValueWord,
			"ADDS op3 = op1 + op2", 1, 6912},
	{48, ML_CODE_ADDS, setCodeLD_3op_out, setInput1DIn_Val16_off, verifyResultValueWord,
			"ADDS off", 1, 0},
	{49, ML_CODE_ADDS, setCodeLD_3op_out, setInput1DIn_Val16_on, verifyResultValueWord,
			"ADDS op3=op1+op2", 1, 6912},
	{50, ML_CODE_ADDS, setCodeLD_3op_out, setInput1DIn_Val16_on_overflow, verifyResultValueWord,
			"ADDS op3=op1+op2 overflow", 1, -32767},
	{51, ML_CODE_ADDS, setCodeLD_K_2op, setInputSIn_Val16_in_off, verifyResultValueWord,
			"ADDS off with K", 1, 0},
	{52, ML_CODE_ADDS, setCodeLD_K_2op, setInputSIn_Val16_in_on, verifyResultValueWord,
			"ADDS op2=K+op1", 1, 6912},
	{53, ML_CODE_ADDS, setCodeLD_2K_1op, setInputNIn_Val16_off, verifyResultValueWord,
			"ADDS off with K", 1, 0},
	{54, ML_CODE_ADDS, setCodeLD_2K_1op, setInputNIn_Val16_on, verifyResultValueWord,
			"ADDS op1=K+K", 1, 6912},
	{55, ML_CODE_ADDS, setCodeOp_N1_W, setInput2DIn_Val16_N1_off, verifyResultValueWord,
			"ADDS off", 1, 0},
	{56, ML_CODE_ADDS, setCodeOp_N1_W, setInput2DIn_Val16_N1_on, verifyResultValueWord,
			"ADDS op3=nop1+p2", 1, 6912},
	{57, ML_CODE_ADDS, setCodeOp_N2_W, setInput2DIn_Val16_N2_off, verifyResultValueWord,
			"ADDS off", 1, 0},
	{58, ML_CODE_ADDS, setCodeOp_N2_W, setInput2DIn_Val16_N2_on, verifyResultValueWord,
			"ADDS op3=op1+nop2", 1, 6912},

	{59, ML_CODE_ADDPS, setCodeLD_3op_in, setInput2DIn_Val16_off, verifyResultValueWord,
			"ADDPS 0->0", 2, 0},
	{60, ML_CODE_ADDPS, setCodeLD_3op_in, setInput2DIn_Val16_on, verifyResultValueWord,
			"ADDPS 1->1", 2, 0},
	{61, ML_CODE_ADDPS, setCodeLD_3op_in, setInput2DIn_Val16p_on, verifyResultValueWord,
			"ADDPS 0->1 op3=op1+op2", 2, 6912},
	{62, ML_CODE_ADDPS, setCodeLD_3op_out, setInput1DIn_Val16_off, verifyResultValueWord,
			"ADDPS off 0->0", 2, 0},
	{63, ML_CODE_ADDPS, setCodeLD_3op_out, setInput1DIn_Val16_on, verifyResultValueWord,
			"ADDPS off 1->1", 2, 0},
	{64, ML_CODE_ADDPS, setCodeLD_3op_out, setInput1DIn_Val16p_on, verifyResultValueWord,
			"ADDPS op3 = op1 + op2", 2, 6912},
	{65, ML_CODE_ADDPS, setCodeLD_3op_out, setInput1DIn_Val16p_on_overflow, verifyResultValueWord,
			"ADDPS op3 = op1 + op2 overflow", 2, -32767},
	{66, ML_CODE_ADDPS, setCodeLD_K_2op, setInputSIn_Val16_in_off, verifyResultValueWord,
			"ADDPS off 0->0 with K", 2, 0},
	{67, ML_CODE_ADDPS, setCodeLD_K_2op, setInputSIn_Val16_in_on, verifyResultValueWord,
			"ADDPS off 1->1 with K", 2, 0},
	{68, ML_CODE_ADDPS, setCodeLD_K_2op, setInputSIn_Val16p_in_on, verifyResultValueWord,
			"ADDPS op2 = K + op1", 2, 6912},
	{69, ML_CODE_ADDPS, setCodeLD_2K_1op, setInputNIn_Val16_off, verifyResultValueWord,
			"ADDPS off 0->0 with K", 2, 0},
	{70, ML_CODE_ADDPS, setCodeLD_2K_1op, setInputNIn_Val16_on, verifyResultValueWord,
			"ADDPS off 1->1 with K", 2, 0},
	{71, ML_CODE_ADDPS, setCodeLD_2K_1op, setInputNIn_Val16p_on, verifyResultValueWord,
			"ADDPS op1 = K + K", 2, 6912},
	{72, ML_CODE_ADDPS, setCodeOp_N1_W, setInput2DIn_Val16_N1_off, verifyResultValueWord,
			"ADDPS 0->0", 2, 0},
	{73, ML_CODE_ADDPS, setCodeOp_N1_W, setInput2DIn_Val16_N1_on, verifyResultValueWord,
			"ADDPS 1->1", 2, 0},
	{74, ML_CODE_ADDPS, setCodeOp_N1_W, setInput2DIn_Val16p_N1_on, verifyResultValueWord,
			"ADDPS op3=nop1+op2", 2, 6912},
	{75, ML_CODE_ADDPS, setCodeOp_N2_W, setInput2DIn_Val16_N2_off, verifyResultValueWord,
			"ADDPS 0->0", 2, 0},
	{76, ML_CODE_ADDPS, setCodeOp_N2_W, setInput2DIn_Val16_N2_on, verifyResultValueWord,
			"ADDPS 1->1", 2, 0},
	{77, ML_CODE_ADDPS, setCodeOp_N2_W, setInput2DIn_Val16p_N2_on, verifyResultValueWord,
			"ADDPS op3=op1+nop2", 2, 6912},

	{78, ML_CODE_SUBS, setCodeLD_3op_in, setInput2DIn_Val16_off, verifyResultValueWord,
			"SUBS off", 1, 0},
	{79, ML_CODE_SUBS, setCodeLD_3op_in, setInput2DIn_Val16_on, verifyResultValueWord,
			"SUBS op3=op1-op2", 1, -4444},
	{80, ML_CODE_SUBS, setCodeLD_3op_out, setInput1DIn_Val16_off, verifyResultValueWord,
			"SUBS off", 1, 0},
	{81, ML_CODE_SUBS, setCodeLD_3op_out, setInput1DIn_Val16_on, verifyResultValueWord,
			"SUBS op3=op1-op2", 1, -4444},
	{82, ML_CODE_SUBS, setCodeLD_3op_out, setInput1DIn_neg_Val16_on_overflow, verifyResultValueWord,
			"SUBS op3=op1-op2 overflow", 1, -32767},
	{83, ML_CODE_SUBS, setCodeLD_K_2op, setInputSIn_Val16_in_off, verifyResultValueWord,
			"SUBS off with K", 1, 0},
	{84, ML_CODE_SUBS, setCodeLD_K_2op, setInputSIn_Val16_in_on, verifyResultValueWord,
			"SUBS op2=K-op1", 1, -4444},
	{85, ML_CODE_SUBS, setCodeLD_2K_1op, setInputNIn_Val16_off, verifyResultValueWord,
			"SUBS off with K", 1, 0},
	{86, ML_CODE_SUBS, setCodeLD_2K_1op, setInputNIn_Val16_on, verifyResultValueWord,
			"SUBS op1=K-K", 1, 4444},
	{87, ML_CODE_SUBS, setCodeOp_N1_W, setInput2DIn_Val16_N1_off, verifyResultValueWord,
			"SUBS off", 1, 0},
	{88, ML_CODE_SUBS, setCodeOp_N1_W, setInput2DIn_Val16_N1_on, verifyResultValueWord,
			"SUBS op3=op1-op2", 1, -4444},
	{89, ML_CODE_SUBS, setCodeOp_N2_W, setInput2DIn_Val16_N2_off, verifyResultValueWord,
			"SUBS off", 1, 0},
	{90, ML_CODE_SUBS, setCodeOp_N2_W, setInput2DIn_Val16_N2_on, verifyResultValueWord,
			"SUBS op3=op1-op2", 1, -4444},

	{91, ML_CODE_SUBPS, setCodeLD_3op_in, setInput2DIn_Val16_off, verifyResultValueWord,
			"SUBPS off 0->0", 2, 0},
	{92, ML_CODE_SUBPS, setCodeLD_3op_in, setInput2DIn_Val16_on, verifyResultValueWord,
			"SUBPS off 1->1", 2, 0},
	{93, ML_CODE_SUBPS, setCodeLD_3op_in, setInput2DIn_Val16p_on, verifyResultValueWord,
			"SUBPS op3 = op1 - op2", 2, -4444},
	{94, ML_CODE_SUBPS, setCodeLD_3op_out, setInput1DIn_Val16_off, verifyResultValueWord,
			"SUBPS off 0->0", 2, 0},
	{95, ML_CODE_SUBPS, setCodeLD_3op_out, setInput1DIn_Val16_on, verifyResultValueWord,
			"SUBPS off 1->1", 2, 0},
	{96, ML_CODE_SUBPS, setCodeLD_3op_out, setInput1DIn_Val16p_on, verifyResultValueWord,
			"SUBPS op3 = op1 - op2", 2, -4444},
	{97, ML_CODE_SUBPS, setCodeLD_3op_out, setInput1DIn_neg_Val16p_on_overflow, verifyResultValueWord,
			"SUBPS op3 = op1 - op2 overflow", 2, -32767},
	{98, ML_CODE_SUBPS, setCodeLD_K_2op, setInputSIn_Val16_in_off, verifyResultValueWord,
			"SUBPS off 0->0 with K", 2, 0},
	{99, ML_CODE_SUBPS, setCodeLD_K_2op, setInputSIn_Val16_in_on, verifyResultValueWord,
			"SUBPS off 1->1 with K", 2, 0},
	{100, ML_CODE_SUBPS, setCodeLD_K_2op, setInputSIn_Val16p_in_on, verifyResultValueWord,
			"SUBPS op2 = K - op1", 2, -4444},
	{101, ML_CODE_SUBPS, setCodeLD_2K_1op, setInputNIn_Val16_off, verifyResultValueWord,
			"SUBPS off 0->0 with K", 2, 0},
	{102, ML_CODE_SUBPS, setCodeLD_2K_1op, setInputNIn_Val16_on, verifyResultValueWord,
			"SUBPS off 1->1 with K", 2, 0},
	{103, ML_CODE_SUBPS, setCodeLD_2K_1op, setInputNIn_Val16p_on, verifyResultValueWord,
			"SUBPS op1=K-K", 2, 4444},
	{104, ML_CODE_SUBPS, setCodeOp_N1_W, setInput2DIn_Val16_N1_off, verifyResultValueWord,
			"SUBPS off", 2, 0},
	{105, ML_CODE_SUBPS, setCodeOp_N1_W, setInput2DIn_Val16_N1_on, verifyResultValueWord,
			"SUBPS off", 2, 0},
	{106, ML_CODE_SUBPS, setCodeOp_N1_W, setInput2DIn_Val16p_N1_on, verifyResultValueWord,
			"SUBPS op3=op1-op2", 2, -4444},
	{107, ML_CODE_SUBPS, setCodeOp_N2_W, setInput2DIn_Val16_N2_off, verifyResultValueWord,
			"SUBPS off", 2, 0},
	{108, ML_CODE_SUBPS, setCodeOp_N2_W, setInput2DIn_Val16_N2_on, verifyResultValueWord,
			"SUBPS off", 2, 0},
	{109, ML_CODE_SUBPS, setCodeOp_N2_W, setInput2DIn_Val16p_N2_on, verifyResultValueWord,
			"SUBPS op3=op1-op2", 2, -4444},

	{110, ML_CODE_BADD, setCodeLD_2op, setInputDIn_BCD_off, verifyResultValueWord,
			"BCD ADD off", 1, 22136}, //0x5678
	{111, ML_CODE_BADD, setCodeLD_2op, setInputDIn_BCD_on, verifyResultValueWord,
			"BCD ADD op2+op1", 1, 26898}, //0x6912
	{112, ML_CODE_BADD, setCodeLD_2op, setInputDIn_BCD_on_overflow, verifyResultValueWord,
			"BCD ADD op2+op1 overflow OK", 1, 21}, //0x15
	{113, ML_CODE_BADD, setCodeLD_BCD_K_1op, setInputSIn_BCD_off, verifyResultValueWord,
			"BCD ADD off with K", 1, 22136}, //0x5678
	{114, ML_CODE_BADD, setCodeLD_BCD_K_1op, setInputSIn_BCD_on, verifyResultValueWord,
			"BCD ADD op1+K", 1, 26898}, //0x6912
	{115, ML_CODE_BADD, setCodeOp_N_W, setInputDIn_BCD_N_off, verifyResultValueWord,
			"BCD ADD off", 1, 22136}, //0x5678
	{116, ML_CODE_BADD, setCodeOp_N_W, setInputDIn_BCD_N_on, verifyResultValueWord,
			"BCD ADD op2+op1", 1, 26898}, //0x6912

	{117, ML_CODE_BADDP, setCodeLD_2op, setInputDIn_BCD_off, verifyResultValueWord,
			"BCD ADDP off 0->0", 2, 22136}, //0x5678
	{118, ML_CODE_BADDP, setCodeLD_2op, setInputDIn_BCD_on, verifyResultValueWord,
			"BCD ADDP off 1->1", 2, 22136}, //0x5678
	{119, ML_CODE_BADDP, setCodeLD_2op, setInputDIn_BCDp_on, verifyResultValueWord,
			"BCD ADDP op2+op1", 2, 26898}, //0x6912
	{120, ML_CODE_BADDP, setCodeLD_2op, setInputDIn_BCDp_on_overflow, verifyResultValueWord,
			"BCD ADDP op2+op1 overflow OK", 2, 21}, //0x15
	{121, ML_CODE_BADDP, setCodeLD_BCD_K_1op, setInputSIn_BCD_off, verifyResultValueWord,
			"BCD ADDP off with K", 2, 22136}, //0x5678
	{122, ML_CODE_BADDP, setCodeLD_BCD_K_1op, setInputSIn_BCDp_on, verifyResultValueWord,
			"BCD ADDP op1+K", 2, 26898}, //0x6912
	{123, ML_CODE_BADDP, setCodeOp_N_W, setInputDIn_BCD_N_off, verifyResultValueWord,
			"BCD ADDP off 0->0", 2, 22136}, //0x5678
	{124, ML_CODE_BADDP, setCodeOp_N_W, setInputDIn_BCD_N_on, verifyResultValueWord,
			"BCD ADDP off 1->1", 2, 22136}, //0x5678
	{125, ML_CODE_BADDP, setCodeOp_N_W, setInputDIn_BCDp_N_on, verifyResultValueWord,
			"BCD ADDP off 0->1", 2, 26898}, //0x6912

	{126, ML_CODE_BSUB, setCodeLD_2op, setInputDIn_BCD_off, verifyResultValueWord,
			"BCD SUB off", 1, 22136}, //0x5678
	{127, ML_CODE_BSUB, setCodeLD_2op, setInputDIn_BCD_on, verifyResultValueWord,
			"BCD SUB op2-op1", 1, 17476}, //0x4444
	{128, ML_CODE_BSUB, setCodeLD_2op, setInputDIn_neg_BCD_on_overflow, verifyResultValueWord,
			"BCD SUB op2-op1 overflow no error", 1, -26216}, //0x9998
	{129, ML_CODE_BSUB, setCodeLD_BCD_K_1op, setInputSIn_BCD_off, verifyResultValueWord,
			"BCD SUB off with K", 1, 22136},  //0x5678
	{130, ML_CODE_BSUB, setCodeLD_BCD_K_1op, setInputSIn_BCD_on, verifyResultValueWord,
			"BCD SUB op1-K", 1, 17476}, //0x4444
	{131, ML_CODE_BSUB, setCodeOp_N_W, setInputDIn_BCD_N_off, verifyResultValueWord,
			"BCD SUB off", 1, 22136}, //0x5678
	{132, ML_CODE_BSUB, setCodeOp_N_W, setInputDIn_BCD_N_on, verifyResultValueWord,
			"BCD SUB op2-op1", 1, 17476}, //0x4444

	{133, ML_CODE_BSUBP, setCodeLD_2op, setInputDIn_BCD_off, verifyResultValueWord,
			"BCD SUBP off", 2, 22136}, //0x5678
	{134, ML_CODE_BSUBP, setCodeLD_2op, setInputDIn_BCD_on, verifyResultValueWord,
			"BCD SUBP op2-op1", 2, 22136}, //0x5678
	{135, ML_CODE_BSUBP, setCodeLD_2op, setInputDIn_BCDp_on, verifyResultValueWord,
			"BCD SUBP op2-op1", 2, 17476}, //0x4444
	{136, ML_CODE_BSUBP, setCodeLD_2op, setInputDIn_neg_BCDp_on_overflow, verifyResultValueWord,
			"BCD SUBP op2-op1 overflow OK", 2, -26216}, //0x9998
	{137, ML_CODE_BSUBP, setCodeLD_BCD_K_1op, setInputSIn_BCD_off, verifyResultValueWord,
			"BCD SUBP off with K", 2, 22136}, //0x5678
	{138, ML_CODE_BSUBP, setCodeLD_BCD_K_1op, setInputSIn_BCDp_on, verifyResultValueWord,
			"BCD SUBP op1-K", 2, 17476}, //0x4444
	{139, ML_CODE_BSUBP, setCodeOp_N_W, setInputDIn_BCD_N_off, verifyResultValueWord,
			"BCD SUBP off", 2, 22136}, //0x5678
	{140, ML_CODE_BSUBP, setCodeOp_N_W, setInputDIn_BCD_N_on, verifyResultValueWord,
			"BCD SUBP op2-op1", 2, 22136}, //0x5678
	{141, ML_CODE_BSUBP, setCodeOp_N_W, setInputDIn_BCDp_N_on, verifyResultValueWord,
			"BCD SUBP op2-op1", 2, 17476}, //0x4444

	{142, ML_CODE_BADDS, setCodeLD_3op_in, setInputDIn_BCD_in_off, verifyResultValueWord,
			"BCD ADDS off", 1, 0},
	{143, ML_CODE_BADDS, setCodeLD_3op_in, setInputDIn_BCD_in_on, verifyResultValueWord,
			"BCD ADDS op3=op2+op1", 1, 26898}, //0x6912
	{144, ML_CODE_BADDS, setCodeLD_3op_out, setInput1DIn_BCD_off, verifyResultValueWord,
			"BCD ADDS off", 1, 0},
	{145, ML_CODE_BADDS, setCodeLD_3op_out, setInput1DIn_BCD_on, verifyResultValueWord,
			"BCD ADDS op3=op2+op1", 1, 26898}, //0x6912
	{146, ML_CODE_BADDS, setCodeLD_BCD_K_2op, setInputIn_BCD_off, verifyResultValueWord,
			"BCD ADDS off with K", 1, 0},
	{147, ML_CODE_BADDS, setCodeLD_BCD_K_2op, setInputIn_BCD_on, verifyResultValueWord,
			"BCD ADDS op2=op1+K", 1, 26898}, //0x6912
	{148, ML_CODE_BADDS, setCodeLD_BCD_2K_1op, setInputNIn_Val16_off, verifyResultValueWord,
			"BCD ADDS off with 2K", 1, 0},
	{149, ML_CODE_BADDS, setCodeLD_BCD_2K_1op, setInputNIn_Val16_on, verifyResultValueWord,
			"BCD ADDS op1=K+K", 1, 26898}, //0x6912
	{150, ML_CODE_BADDS, setCodeOp_N1_W, setInput1DIn_BCD_N1_off, verifyResultValueWord,
			"BCD ADDS off", 1, 0},
	{151, ML_CODE_BADDS, setCodeOp_N1_W, setInput1DIn_BCD_N1_on, verifyResultValueWord,
			"BCD ADDS op3=op2+op1", 1, 26898}, //0x6912
	{152, ML_CODE_BADDS, setCodeOp_N2_W, setInput1DIn_BCD_N2_off, verifyResultValueWord,
			"BCD ADDS off", 1, 0},
	{153, ML_CODE_BADDS, setCodeOp_N2_W, setInput1DIn_BCD_N2_on, verifyResultValueWord,
			"BCD ADDS op3=op2+op1", 1, 26898}, //0x6912

	{154, ML_CODE_BADDPS, setCodeLD_3op_in, setInputDIn_BCD_in_off, verifyResultValueWord,
			"BCD ADDPS off 0->0", 2, 0},
	{155, ML_CODE_BADDPS, setCodeLD_3op_in, setInputDIn_BCD_in_on, verifyResultValueWord,
			"BCD ADDPS off 1->1", 2, 0},
	{156, ML_CODE_BADDPS, setCodeLD_3op_in, setInputDIn_BCDp_in_on, verifyResultValueWord,
			"BCD ADDPS op3=op2+op1", 2, 26898}, //0x6912
	{157, ML_CODE_BADDPS, setCodeLD_3op_out, setInput1DIn_BCD_off, verifyResultValueWord,
			"BCD ADDPS off 0->0", 2, 0},
	{158, ML_CODE_BADDPS, setCodeLD_3op_out, setInput1DIn_BCD_on, verifyResultValueWord,
			"BCD ADDPS off 1->1", 2, 0},
	{159, ML_CODE_BADDPS, setCodeLD_3op_out, setInput1DIn_BCDp_on, verifyResultValueWord,
			"BCD ADDPS op3=op2+op1", 2, 26898}, //0x6912
	{160, ML_CODE_BADDPS, setCodeLD_BCD_K_2op, setInputIn_BCD_off, verifyResultValueWord,
			"BCD ADDPS off 0->0 with K", 2, 0},
	{161, ML_CODE_BADDPS, setCodeLD_BCD_K_2op, setInputIn_BCD_on, verifyResultValueWord,
			"BCD ADDPS off 1->1 with K", 2, 0},
	{162, ML_CODE_BADDPS, setCodeLD_BCD_K_2op, setInputIn_BCDp_on, verifyResultValueWord,
			"BCD ADDPS op2=K+op1", 2, 26898}, //0x6912
	{163, ML_CODE_BADDPS, setCodeLD_BCD_2K_1op, setInputNIn_Val16_off, verifyResultValueWord,
			"BCD ADDPS off with 2K", 2, 0},
	{164, ML_CODE_BADDPS, setCodeLD_BCD_2K_1op, setInputNIn_Val16_on, verifyResultValueWord,
			"BCD ADDPS op1=K+K", 2, 0},
	{165, ML_CODE_BADDPS, setCodeLD_BCD_2K_1op, setInputNIn_Val16p_on, verifyResultValueWord,
			"BCD ADDPS op1=K+K", 2, 26898}, //0x6912
	{166, ML_CODE_BADDPS, setCodeOp_N1_W, setInput1DIn_BCD_N1_off, verifyResultValueWord,
			"BCD ADDPS 0->0", 2, 0},
	{167, ML_CODE_BADDPS, setCodeOp_N1_W, setInput1DIn_BCD_N1_on, verifyResultValueWord,
			"BCD ADDPS 1->1", 2, 0},
	{168, ML_CODE_BADDPS, setCodeOp_N1_W, setInput1DIn_BCDp_N1_on, verifyResultValueWord,
			"BCD ADDPS op3=op2+op1", 2, 26898}, //0x6912
	{169, ML_CODE_BADDPS, setCodeOp_N2_W, setInput1DIn_BCD_N2_off, verifyResultValueWord,
			"BCD ADDPS 0->0", 2, 0},
	{170, ML_CODE_BADDPS, setCodeOp_N2_W, setInput1DIn_BCD_N2_on, verifyResultValueWord,
			"BCD ADDPS 1->1", 2, 0},
	{171, ML_CODE_BADDPS, setCodeOp_N2_W, setInput1DIn_BCDp_N2_on, verifyResultValueWord,
			"BCD ADDPS op3=op2+op1", 2, 26898}, //0x6912

	{172, ML_CODE_BSUBS, setCodeLD_3op_in, setInputDIn_BCD_in_off, verifyResultValueWord,
			"BCD SUBS off", 1, 0},
	{173, ML_CODE_BSUBS, setCodeLD_3op_in, setInputDIn_BCD_in_on, verifyResultValueWord,
			"BCD SUBS op3=op1-op2", 1, 17476}, //0x4444
	{174, ML_CODE_BSUBS, setCodeLD_3op_out, setInput1DIn_BCD_off, verifyResultValueWord,
			"BCD SUBS off", 1, 0},
	{175, ML_CODE_BSUBS, setCodeLD_3op_out, setInput1DIn_BCD_on, verifyResultValueWord,
			"BCD SUBS op3=op1-op2", 1, 21846}, //0x5556
	{176, ML_CODE_BSUBS, setCodeLD_BCD_K_2op, setInputIn_BCD_off, verifyResultValueWord,
			"BCD SUBS off with K", 1, 0},
	{177, ML_CODE_BSUBS, setCodeLD_BCD_K_2op, setInputIn_BCD_on, verifyResultValueWord,
			"BCD SUBS op2=K-op1", 1, 21846}, //0x5556
	{178, ML_CODE_BSUBS, setCodeLD_BCD_2K_1op, setInputNIn_Val16_off, verifyResultValueWord,
			"BCD SUBS off with 2K", 1, 0},
	{179, ML_CODE_BSUBS, setCodeLD_BCD_2K_1op, setInputNIn_Val16_on, verifyResultValueWord,
			"BCD SUBS op1=K1-K2", 1, 21846}, //0x5556
	{180, ML_CODE_BSUBS, setCodeOp_N1_W, setInput1DIn_BCD_N1_off, verifyResultValueWord,
			"BCD SUBS off", 1, 0},
	{181, ML_CODE_BSUBS, setCodeOp_N1_W, setInput1DIn_BCD_N1_on, verifyResultValueWord,
			"BCD SUBS op3=op1-op2", 1, 17476}, //0x4444
	{182, ML_CODE_BSUBS, setCodeOp_N2_W, setInput1DIn_BCD_N2_off, verifyResultValueWord,
			"BCD SUBS off", 1, 0},
	{183, ML_CODE_BSUBS, setCodeOp_N2_W, setInput1DIn_BCD_N2_on, verifyResultValueWord,
			"BCD SUBS op3=op1-op2", 1, 21846}, //0x5556

	{184, ML_CODE_BSUBPS, setCodeLD_3op_in, setInputDIn_BCD_in_off, verifyResultValueWord,
			"BCD SUBPS off 0->0", 2, 0},
	{185, ML_CODE_BSUBPS, setCodeLD_3op_in, setInputDIn_BCD_in_on, verifyResultValueWord,
			"BCD SUBPS off 1->1", 2, 0},
	{186, ML_CODE_BSUBPS, setCodeLD_3op_in, setInputDIn_BCDp_in_on, verifyResultValueWord,
			"BCD SUBPS op3=op1-op2", 2, 17476}, //0x4444
	{187, ML_CODE_BSUBPS, setCodeLD_3op_out, setInput1DIn_BCD_off, verifyResultValueWord,
			"BCD SUBPS off 0->0", 2, 0},
	{188, ML_CODE_BSUBPS, setCodeLD_3op_out, setInput1DIn_BCD_on, verifyResultValueWord,
			"BCD SUBPS off 1->1", 2, 0},
	{189, ML_CODE_BSUBPS, setCodeLD_3op_out, setInput1DIn_BCDp_on, verifyResultValueWord,
			"BCD SUBPS op3=op1-op2", 2, 21846}, //0x5556
	{190, ML_CODE_BSUBPS, setCodeLD_BCD_K_2op, setInputIn_BCD_off, verifyResultValueWord,
			"BCD SUBPS off 0->0 with K", 2, 0},
	{191, ML_CODE_BSUBPS, setCodeLD_BCD_K_2op, setInputIn_BCD_on, verifyResultValueWord,
			"BCD SUBPS off 1->1 with K", 2, 0},
	{192, ML_CODE_BSUBPS, setCodeLD_BCD_K_2op, setInputIn_BCDp_on, verifyResultValueWord,
			"BCD SUBPS op2=K-op1", 2, 21846}, //0x5556
	{193, ML_CODE_BSUBPS, setCodeLD_BCD_2K_1op, setInputNIn_Val16_off, verifyResultValueWord,
			"BCD SUBPS off 0->0 with 2K", 2, 0},
	{194, ML_CODE_BSUBPS, setCodeLD_BCD_2K_1op, setInputNIn_Val16_on, verifyResultValueWord,
			"BCD SUBPS off 1->1 with 2K", 2, 0},
	{195, ML_CODE_BSUBPS, setCodeLD_BCD_2K_1op, setInputNIn_Val16p_on, verifyResultValueWord,
			"BCD SUBPS op1=K1-K2", 2, 21846}, //0x5556
	{196, ML_CODE_BSUBPS, setCodeOp_N1_W, setInput1DIn_BCD_N1_off, verifyResultValueWord,
			"BCD SUBPS 0->0", 2, 0},
	{197, ML_CODE_BSUBPS, setCodeOp_N1_W, setInput1DIn_BCD_N1_on, verifyResultValueWord,
			"BCD SUBPS 1->1", 2, 0},
	{198, ML_CODE_BSUBPS, setCodeOp_N1_W, setInput1DIn_BCDp_N1_on, verifyResultValueWord,
			"BCD SUBPS op3=op1-op2", 2, 17476}, //0x4444
	{199, ML_CODE_BSUBPS, setCodeOp_N2_W, setInput1DIn_BCD_N2_off, verifyResultValueWord,
			"BCD SUBPS 0->0", 2, 0},
	{200, ML_CODE_BSUBPS, setCodeOp_N2_W, setInput1DIn_BCD_N2_off, verifyResultValueWord,
			"BCD SUBPS 1->1", 2, 0},
	{201, ML_CODE_BSUBPS, setCodeOp_N2_W, setInput1DIn_BCDp_N2_on, verifyResultValueWord,
			"BCD SUBS op3=op1-op2", 2, 21846}, //0x5556

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};


int total_basic_compute_word_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_word_test_number; i++)
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

int setCodeLD_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg < OPERAND_ML_CODE_D ) return 0;
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_3op_in(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 160);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_3op_out(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos);
		addMLOperand(out_reg, 160); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_N1_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperand(out_reg, 160);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_N2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(out_reg, in_pos);
	addMLOperandNibble(4, in_reg, 160); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 1234); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_K_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperand(in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_2K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 5678); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_K_2op_div(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperand(in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD_K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD_K_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234);
		addMLOperand(in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD_2K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234);
		addMLOperand(OPERAND_ML_CODE_K, 0x5678); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_N_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputDIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 5678);

	TestCodeTearDown();
}

void setInputDIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 5678);

	TestCodeTearDown();
}

void setInputDIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_Val16_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos, 5678);

	TestCodeTearDown();
}

void setInputDIn_Val16_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos, 5678);

	TestCodeTearDown();
}

void setInputDIn_Val16p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos, 5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput2DIn_Val16_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 5678);

	TestCodeTearDown();
}

void setInput2DIn_Val16_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 5678);

	TestCodeTearDown();
}

void setInput2DIn_Val16p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput2DIn_Val16_N2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16p_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=5678;

	addDeviceControlInstruction(0, (uint8)out, in_pos, 1234);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput2DIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	addDeviceControlInstruction(0, (uint8)in, 160, 5678);

	TestCodeTearDown();
}

void setInput2DIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	addDeviceControlInstruction(0, (uint8)in, 160, 5678);

	TestCodeTearDown();
}

void setInput2DIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	addDeviceControlInstruction(0, (uint8)in, 160, 5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput1DIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	addDeviceControlInstruction(0, (uint8)out, 160, 5678);

	TestCodeTearDown();
}

void setInput1DIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	addDeviceControlInstruction(0, (uint8)out, 160, 5678);

	TestCodeTearDown();
}

void setInput1DIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);
	addDeviceControlInstruction(0, (uint8)out, 160, 5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);


	TestCodeTearDown();
}

void setInputDIn_Val16_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 2);

	TestCodeTearDown();
}

void setInputDIn_Val16p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 2);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_neg_Val16_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 2);
	addDeviceControlInstruction(0, (uint8)out, out_pos, -32768);

	TestCodeTearDown();
}

void setInputDIn_neg_Val16p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 2);
	addDeviceControlInstruction(0, (uint8)out, out_pos, -32768);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput1DIn_Val16_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);
	addDeviceControlInstruction(0, (uint8)out, 160, 2);

	TestCodeTearDown();
}

void setInput1DIn_Val16p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);
	addDeviceControlInstruction(0, (uint8)out, 160, 2);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput1DIn_neg_Val16_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 2);
	addDeviceControlInstruction(0, (uint8)out, 160, -32767);

	TestCodeTearDown();
}

void setInput1DIn_neg_Val16p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 2);
	addDeviceControlInstruction(0, (uint8)out, 160, -32767);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 5678);

	TestCodeTearDown();
}

void setInputSIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 5678);

	TestCodeTearDown();
}

void setInputSIn_Val16_in_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 5678);

	TestCodeTearDown();
}

void setInputSIn_Val16_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 5678);

	TestCodeTearDown();
}

void setInputSIn_Val16p_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);

	TestCodeTearDown();
}

void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val16_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 32767);

	TestCodeTearDown();
}

void setInputSIn_Val16_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, out_pos, -32768);

	TestCodeTearDown();
}

void setInputSIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)out, out_pos, 5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val16p_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)out, out_pos, 32767);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val16p_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)out, out_pos, -32768);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_BCD_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x1234);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x5678);

	TestCodeTearDown();
}

void setInputDIn_BCD_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x1234);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x5678);

	TestCodeTearDown();
}

void setInputDIn_BCDp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x1234);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_BCD_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x5678);

	TestCodeTearDown();
}

void setInputDIn_BCD_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x5678);

	TestCodeTearDown();
}

void setInputDIn_BCDp_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x1234;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_BCD_in_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)in, 160, 0x1234);

	TestCodeTearDown();
}

void setInputDIn_BCD_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)in, 160, 0x1234);

	TestCodeTearDown();
}

void setInputDIn_BCDp_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)in, 160, 0x1234);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput1DIn_BCD_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x1234);
	addDeviceControlInstruction(0, (uint8)out, 160, 0x5678);

	TestCodeTearDown();
}

void setInput1DIn_BCD_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x1234);
	addDeviceControlInstruction(0, (uint8)out, 160, 0x5678);

	TestCodeTearDown();
}

void setInput1DIn_BCDp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x1234);
	addDeviceControlInstruction(0, (uint8)out, 160, 0x5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}


void setInput1DIn_BCD_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)out, 160, 0x1234);

	TestCodeTearDown();
}

void setInput1DIn_BCD_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, 160, 0x1234);

	TestCodeTearDown();
}

void setInput1DIn_BCDp_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 0x1234);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput1DIn_BCD_N2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 0x1234);

	TestCodeTearDown();
}

void setInput1DIn_BCD_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 0x1234);

	TestCodeTearDown();
}

void setInput1DIn_BCDp_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, in_pos, 0x1234);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}


void setInputDIn_BCD_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x6432);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x3583);

	TestCodeTearDown();
}

void setInputDIn_BCDp_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x6432);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x3583);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_neg_BCD_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 3);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 1);

	TestCodeTearDown();
}

void setInputDIn_neg_BCDp_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 3);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 1);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_BCD_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x5678);

	TestCodeTearDown();
}

void setInputSIn_BCD_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x5678);

	TestCodeTearDown();
}

void setInputSIn_BCDp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)out, out_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputIn_BCD_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);

	TestCodeTearDown();
}

void setInputIn_BCD_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);

	TestCodeTearDown();
}

void setInputIn_BCDp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

int verifyResultValueWord(int tcase, uint8 dest_reg, uint16 pos, short expected)
{
	int rc=0;
	short result;
	char reg[] = {'D', 'W'};

	if(!test_getWord(&result, dest_reg, pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d Reg %c[%d]=%d %d\n", tcase, reg[dest_reg-OPERAND_ML_CODE_D], pos, result, expected);
	CU_ASSERT_EQUAL(result, expected);
	if(result != expected) rc=1;

	return rc;
}


static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12286,8190}}; //16bit

	return pos[inx_pos][reg];
}

static 	FILE *flog;
void test_basic_arithmetic_word(int tno, uint16 dummy)
{
	int i, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos, res_word;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in, i);

					if(in == out && (in_pos == out_pos || in_pos+16 == out_pos) )
					{
						continue;
					}

					rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if(rc2 == 0) continue;

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
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_word, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testBasicArithmeticWordCommand(void)
{
	int i, index=162;
	int start, end;
	char log[] = "err_arith_word.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic word LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=32;index<56;index++)
		test_basic_arithmetic_word(index, 0);
#else
	total_basic_compute_word_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_ADD);
	end = getTestCaseNumberEnd(ML_CODE_BSUBPS); //ML_CODE_BSUBPS

	DBG_LOGPRINT("testBasicArithmeticWordCommand: %d to %d total %d\n", start, end, total_basic_compute_word_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_word(index, 0);
	}
#endif
	fclose(flog);
}

#endif
