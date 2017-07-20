/*
 * test_basic_arithmatic_dword.c
 *
 *  Created 0->1: Apr 9, 2015
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

extern int setCodeLD_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeLD_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeLD_3op_in(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeLD_3op_out(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

extern void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

int setCodeOp_N8DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp_N8(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_N8WDW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_WN8DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD32_K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_K1WDW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_K1N8DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_WK2DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_N8K2DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD32_2K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

int setCodeLD_BCD8_K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_BCD8_K1WDW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_BCD8_K1N8DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_BCD8_WK2DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_BCD8_N8K2DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD32_BCD8_2K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInput2Op_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2Op_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2Op_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val32_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_neg_Val32_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val32_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val32_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val32p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32p_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputOp3_Val32_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_N2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_N1K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_N1K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_N1K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32p_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32p_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_K1W2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_K1W2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32p_K1W2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_W1K2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32_W1K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val32p_W1K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInput2DIn_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val32_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val32p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_neg_Val32_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_neg_Val32p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_BCD8_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8_on_underflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8p_on_underflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_BCD8_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD8_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD8p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_N8BCD8_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_N8BCD8_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_N8BCD8p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputOP3_BCD8_WW_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOP3_BCD8_WW_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOP3_BCD8p_WW_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOP3_BCD8_WW_DW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOP3_BCD8p_WW_DW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOP3_BCD8_WW_DW_on_underflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOP3_BCD8p_WW_DW_on_underflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOP3_BCD8_W_WDW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOP3_BCD8_W_WDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOP3_BCD8p_W_WDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_N8BCD8DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_N8BCD8DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_N8BCD8DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8N8DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8N8DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8N8DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_K1N8DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_K1N8DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_K1N8DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_K1BCD8DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_K1BCD8DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_K1BCD8DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8K2DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8K2DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD8K2DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_N8K2DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_N8K2DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_N8K2DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected);

static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, int);
	char str[40];
	//int count;
	int run_step;
	int expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_DADD, setCodeLD_2op, setInput2Op_Val32_off, verifyResultValueDWord,
			"DADD off op1+op2", 1, 123456},
	{1, ML_CODE_DADD, setCodeLD_2op, setInput2Op_Val32_on, verifyResultValueDWord,
			"DADD on op1+op2", 1, 691346},
	{2, ML_CODE_DADD, setCodeLD_2op, setInputDIn_Val32_on_overflow, verifyResultValueDWord,
			"DADD on op1+op2 overflow", 1, -2147483647},
	{3, ML_CODE_DADD, setCodeOp_N8DW, setInputDIn_Val32_N1_off, verifyResultValueDWord,
			"DADD off nop1+op2", 1, 123456},
	{4, ML_CODE_DADD, setCodeOp_N8DW, setInputDIn_Val32_N1_on, verifyResultValueDWord,
			"DADD on nop1+op2", 1, 691346},
	{5, ML_CODE_DADD, setCodeLD32_K_1op, setInputSIn_Val32_off, verifyResultValueDWord,
			"DADD off with K", 1, 123456},
	{6, ML_CODE_DADD, setCodeLD32_K_1op, setInputSIn_Val32_on, verifyResultValueDWord,
			"DADD on K+op1", 1, 691346},

	{7, ML_CODE_DADDP, setCodeLD_2op, setInput2Op_Val32_off, verifyResultValueDWord,
			"DADDP 0->0 op1+op2", 2, 123456},
	{8, ML_CODE_DADDP, setCodeLD_2op, setInput2Op_Val32_on, verifyResultValueDWord,
			"DADDP 1->1 op1+op2", 2, 123456},
	{9, ML_CODE_DADDP, setCodeLD_2op, setInput2Op_Val32p_on, verifyResultValueDWord,
			"DADDP 0->1 op1+op2", 2, 691346},
	{10, ML_CODE_DADDP, setCodeOp_N8DW, setInputDIn_Val32_N1_off, verifyResultValueDWord,
			"DADDP 0->0 nop1+op2", 2, 123456},
	{11, ML_CODE_DADDP, setCodeOp_N8DW, setInputDIn_Val32_N1_on, verifyResultValueDWord,
			"DADDP 1->1 nop1+op2", 2, 123456},
	{12, ML_CODE_DADDP, setCodeOp_N8DW, setInputDIn_Val32p_N1_on, verifyResultValueDWord,
			"DADDP 0->1 nop1+op2", 2, 691346},
	{13, ML_CODE_DADDP, setCodeLD32_K_1op, setInputSIn_Val32_off, verifyResultValueDWord,
			"DADDP 0->0 K+op1", 2, 123456},
	{14, ML_CODE_DADDP, setCodeLD32_K_1op, setInputSIn_Val32_on, verifyResultValueDWord,
			"DADDP 1->1 K+op1", 2, 123456},
	{15, ML_CODE_DADDP, setCodeLD32_K_1op, setInputSIn_Val32p_on, verifyResultValueDWord,
			"DADDP 0->1 K+op1", 2, 691346},

	{16, ML_CODE_DSUB, setCodeLD_2op, setInput2Op_Val32_off, verifyResultValueDWord,
			"DSUB off op1-op2", 1, 123456},
	{17, ML_CODE_DSUB, setCodeLD_2op, setInput2Op_Val32_on, verifyResultValueDWord,
			"DSUB on op1-op2", 1, -444434},
	{18, ML_CODE_DSUB, setCodeLD_2op, setInputDIn_neg_Val32_on_overflow, verifyResultValueDWord,
			"DSUB on op1-op2 overflow", 1, 2147483646},
	{19, ML_CODE_DSUB, setCodeOp_N8DW, setInputDIn_Val32_N1_off, verifyResultValueDWord,
			"DSUB off nop1-op2", 1, 123456},
	{20, ML_CODE_DSUB, setCodeOp_N8DW, setInputDIn_Val32_N1_on, verifyResultValueDWord,
			"DSUB on nop1-op2", 1, -444434},
	{21, ML_CODE_DSUB, setCodeLD32_K_1op, setInputSIn_Val32_off, verifyResultValueDWord,
			"DSUB off K-op1", 1, 123456},
	{22, ML_CODE_DSUB, setCodeLD32_K_1op, setInputSIn_Val32_on, verifyResultValueDWord,
			"DSUB on K-op1", 1, -444434},

	{23, ML_CODE_DSUBP, setCodeLD_2op, setInput2Op_Val32_off, verifyResultValueDWord,
			"DSUBP 0->0 op2-op1", 2, 123456},
	{24, ML_CODE_DSUBP, setCodeLD_2op, setInput2Op_Val32_on, verifyResultValueDWord,
			"DSUBP 1->1 op2-op1", 2, 123456},
	{25, ML_CODE_DSUBP, setCodeLD_2op, setInput2Op_Val32p_on, verifyResultValueDWord,
			"DSUBP 0->1 op2-op1", 2, -444434},
	{26, ML_CODE_DSUBP, setCodeOp_N8DW, setInputDIn_Val32_N1_off, verifyResultValueDWord,
			"DSUBP 0->0 op2-nop1", 2, 123456},
	{27, ML_CODE_DSUBP, setCodeOp_N8DW, setInputDIn_Val32_N1_on, verifyResultValueDWord,
			"DSUBP 1->1 op2-nop1", 2,  123456},
	{28, ML_CODE_DSUBP, setCodeOp_N8DW, setInputDIn_Val32p_N1_on, verifyResultValueDWord,
			"DSUBP 0->1 op2-nop1", 2, -444434},
	{29, ML_CODE_DSUBP, setCodeLD32_K_1op, setInputSIn_Val32_off, verifyResultValueDWord,
			"DSUBP 0->0 op2-K", 2, 123456},
	{30, ML_CODE_DSUBP, setCodeLD32_K_1op, setInputSIn_Val32_on, verifyResultValueDWord,
			"DSUBP 1->1 op2-K", 2, 123456},
	{31, ML_CODE_DSUBP, setCodeLD32_K_1op, setInputSIn_Val32p_on, verifyResultValueDWord,
			"DSUBP 0->1 op2-K", 2, -444434},

	{32, ML_CODE_DINC, setCodeLD_1op, setInputSIn_Val32_off, verifyResultValueDWord,
			"DINC off", 1, 123456},
	{33, ML_CODE_DINC, setCodeLD_1op, setInputSIn_Val32_on, verifyResultValueDWord,
			"DINC on", 1, 123457},
	{34, ML_CODE_DINC, setCodeLD_1op, setInputSIn_Val32_on_over, verifyResultValueDWord,
			"DINC on overflow", 1, -2147483648},

	{35, ML_CODE_DINCP, setCodeLD_1op, setInputSIn_Val32_off, verifyResultValueDWord,
			"DINCP 0->0", 2, 123456},
	{36, ML_CODE_DINCP, setCodeLD_1op, setInputSIn_Val32_on, verifyResultValueDWord,
			"DINCP 1->1", 2, 123456},
	{37, ML_CODE_DINCP, setCodeLD_1op, setInputSIn_Val32p_on, verifyResultValueDWord,
			"DINCP 0->1", 2, 123457},
	{38, ML_CODE_DINCP, setCodeLD_1op, setInputSIn_Val32p_on_over, verifyResultValueDWord,
			"DINCP 0->1 overflow", 2, -2147483648},

	{39, ML_CODE_DDEC, setCodeLD_1op, setInputSIn_Val32_off, verifyResultValueDWord,
			"DDEC off", 1, 123456},
	{40, ML_CODE_DDEC, setCodeLD_1op, setInputSIn_Val32_on, verifyResultValueDWord,
			"DDEC on", 1, 123455},
	{41, ML_CODE_DDEC, setCodeLD_1op, setInputSIn_Val32_on_under, verifyResultValueDWord,
			"DDEC on overflow", 1, 2147483647},

	{42, ML_CODE_DDECP, setCodeLD_1op, setInputSIn_Val32_off, verifyResultValueDWord,
			"DDECP 0->0", 2, 123456},
	{43, ML_CODE_DDECP, setCodeLD_1op, setInputSIn_Val32_on, verifyResultValueDWord,
			"DDECP 1->1", 2, 123456},
	{44, ML_CODE_DDECP, setCodeLD_1op, setInputSIn_Val32p_on, verifyResultValueDWord,
			"DDECP 0->1", 2, 123455},
	{45, ML_CODE_DDECP, setCodeLD_1op, setInputSIn_Val32p_on_under, verifyResultValueDWord,
			"DDECP 0->1 overflow", 2, 2147483647},

	{46, ML_CODE_DADDS, setCodeLD_3op_in, setInput2DIn_Val32_off, verifyResultValueDWord,
			"DADDS off op3=op1+op2", 1, 0},
	{47, ML_CODE_DADDS, setCodeLD_3op_in, setInput2DIn_Val32_on, verifyResultValueDWord,
			"DADDS on op3=op1+op2", 1, 691346},
	{48, ML_CODE_DADDS, setCodeLD_3op_out, setInput1DIn_Val32_off, verifyResultValueDWord,
			"DADDS off op3=op1+op2", 1, 0},
	{49, ML_CODE_DADDS, setCodeLD_3op_out, setInput1DIn_Val32_on, verifyResultValueDWord,
			"DADDS on op3=op1+op2", 1, 691346},
	{50, ML_CODE_DADDS, setCodeLD_3op_out, setInput1DIn_Val32_on_overflow, verifyResultValueDWord,
			"DADDS on op3=op1+op2 overflow", 1, -2147483647},
	{51, ML_CODE_DADDS, setCodeOp3_N8WDW, setInputOp3_Val32_N1_off, verifyResultValueDWord,
			"DADDS off op3=nop1+op2", 1, 0},
	{52, ML_CODE_DADDS, setCodeOp3_N8WDW, setInputOp3_Val32_N1_on, verifyResultValueDWord,
			"DADDS on op3=nop1+op2", 1, 691346},
	{53, ML_CODE_DADDS, setCodeOp3_WN8DW, setInputOp3_Val32_N2_off, verifyResultValueDWord,
			"DADDS off op3=op1+nop2", 1, 0},
	{54, ML_CODE_DADDS, setCodeOp3_WN8DW, setInputOp3_Val32_N2_on, verifyResultValueDWord,
			"DADDS on op3=op1+nop2", 1, 691346},
	{55, ML_CODE_DADDS, setCodeOp3_K1WDW, setInputSIn_Val32_K1W2_off, verifyResultValueDWord,
			"DADDS off op3=K+op2", 1, 0},
	{56, ML_CODE_DADDS, setCodeOp3_K1WDW, setInputSIn_Val32_K1W2_on, verifyResultValueDWord,
			"DADDS on op3=K+op2", 1, 691346},
	{57, ML_CODE_DADDS, setCodeOp3_K1N8DW, setInputOp3_Val32_KN2_off, verifyResultValueDWord,
			"DADDS off op3=K+nop2", 1, 0},
	{58, ML_CODE_DADDS, setCodeOp3_K1N8DW, setInputOp3_Val32_KN2_on, verifyResultValueDWord,
			"DADDS on op3=K+nop2", 1, 691346},
	{59, ML_CODE_DADDS, setCodeOp3_WK2DW, setInputSIn_Val32_W1K2_off, verifyResultValueDWord,
			"DADDS off op3=op1+K", 1, 0},
	{60, ML_CODE_DADDS, setCodeOp3_WK2DW, setInputSIn_Val32_W1K2_on, verifyResultValueDWord,
			"DADDS on op3=op1+K", 1, 691346},
	{61, ML_CODE_DADDS, setCodeOp3_N8K2DW, setInputOp3_Val32_N1K_off, verifyResultValueDWord,
			"DADDS off op3=nop1+K", 1, 0},
	{62, ML_CODE_DADDS, setCodeOp3_N8K2DW, setInputOp3_Val32_N1K_on, verifyResultValueDWord,
			"DADDS on op3=nop1+K", 1, 691346},
	{63, ML_CODE_DADDS, setCodeLD32_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"DADDS off op1=K+K", 1, 0},
	{64, ML_CODE_DADDS, setCodeLD32_2K_1op, setInputNIn_Val16_on, verifyResultValueDWord,
			"DADDS on op1=K+K", 1, 691346},

	{65, ML_CODE_DADDPS, setCodeLD_3op_in, setInput2DIn_Val32_off, verifyResultValueDWord,
			"DADDPS 0->0 op3=op1+op2", 2, 0},
	{66, ML_CODE_DADDPS, setCodeLD_3op_in, setInput2DIn_Val32p_on, verifyResultValueDWord,
			"DADDPS 0->1 op3=op1+op2", 2, 691346},
	{67, ML_CODE_DADDPS, setCodeLD_3op_out, setInput1DIn_Val32_off, verifyResultValueDWord,
			"DADDPS 0->0 op3=op1+op2", 2, 0},
	{68, ML_CODE_DADDPS, setCodeLD_3op_out, setInput1DIn_Val32p_on, verifyResultValueDWord,
			"DADDPS 0->1 op3=op1+op2", 2, 691346},
	{69, ML_CODE_DADDPS, setCodeLD_3op_out, setInput1DIn_Val32p_on_overflow, verifyResultValueDWord,
			"DADDPS 0->1 op3=op1+op2 overflow", 2, -2147483647},
	{70, ML_CODE_DADDPS, setCodeOp3_N8WDW, setInputOp3_Val32_N1_off, verifyResultValueDWord,
			"DADDPS 0->0 op3=nop1+op2", 2, 0},
	{71, ML_CODE_DADDPS, setCodeOp3_N8WDW, setInputOp3_Val32p_N1_on, verifyResultValueDWord,
			"DADDPS 0->1 op3=nop1+op2", 2, 691346},
	{72, ML_CODE_DADDPS, setCodeOp3_WN8DW, setInputOp3_Val32_N2_off, verifyResultValueDWord,
			"DADDPS 0->0 op3=op1+nop2", 2, 0},
	{73, ML_CODE_DADDPS, setCodeOp3_WN8DW, setInputOp3_Val32p_N2_on, verifyResultValueDWord,
			"DADDPS 0->1 op3=op1+nop2", 2, 691346},
	{74, ML_CODE_DADDPS, setCodeOp3_K1WDW, setInputSIn_Val32_K1W2_off, verifyResultValueDWord,
			"DADDPS 0->0 op3=K+op2", 2, 0},
	{75, ML_CODE_DADDPS, setCodeOp3_K1WDW, setInputSIn_Val32p_K1W2_on, verifyResultValueDWord,
			"DADDPS 0->1 op3=K+op2", 2, 691346},
	{76, ML_CODE_DADDPS, setCodeOp3_K1N8DW, setInputOp3_Val32_KN2_off, verifyResultValueDWord,
			"DADDPS 0->0 op3=K+nop2", 2, 0},
	{77, ML_CODE_DADDPS, setCodeOp3_K1N8DW, setInputOp3_Val32p_KN2_on, verifyResultValueDWord,
			"DADDPS 0->1 op3=K+nop2", 2, 691346},
	{78, ML_CODE_DADDPS, setCodeOp3_WK2DW, setInputSIn_Val32_W1K2_off, verifyResultValueDWord,
			"DADDPS 0->0 op3=op1+K", 2, 0},
	{79, ML_CODE_DADDPS, setCodeOp3_WK2DW, setInputSIn_Val32p_W1K2_on, verifyResultValueDWord,
			"DADDPS 0->1 op3=op1+K", 2, 691346},
	{80, ML_CODE_DADDPS, setCodeOp3_N8K2DW, setInputOp3_Val32_N1K_off, verifyResultValueDWord,
			"DADDPS 0->0 op3=nop1+K", 2, 0},
	{81, ML_CODE_DADDPS, setCodeOp3_N8K2DW, setInputOp3_Val32p_N1K_on, verifyResultValueDWord,
			"DADDPS 0->1 op3=nop1+K", 2, 691346},
	{82, ML_CODE_DADDPS, setCodeLD32_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"DADDPS 0->0 op1=K+K", 2, 0},
	{83, ML_CODE_DADDS, setCodeLD32_2K_1op, setInputNIn_Val16p_on, verifyResultValueDWord,
			"DADDPS 0->1 op1=K+K", 2, 691346},

	{84, ML_CODE_DSUBS, setCodeLD_3op_in, setInput2DIn_Val32_off, verifyResultValueDWord,
			"DSUBS off op3=op1+op2", 1, 0},
	{85, ML_CODE_DSUBS, setCodeLD_3op_in, setInput2DIn_Val32_on, verifyResultValueDWord,
			"DSUBS on op3=op1-op2", 1, 444434},
	{86, ML_CODE_DSUBS, setCodeLD_3op_out, setInput1DIn_Val32_off, verifyResultValueDWord,
			"DSUBS off op3=op1-op2", 1, 0},
	{87, ML_CODE_DSUBS, setCodeLD_3op_out, setInput1DIn_Val32_on, verifyResultValueDWord,
			"DSUBS on op3=op1-op2", 1, 444434},
	{88, ML_CODE_DSUBS, setCodeLD_3op_out, setInput1DIn_neg_Val32_on_overflow, verifyResultValueDWord,
			"DSUBS on op3=op1-op2 overflow", 1, 2147483646},
	{89, ML_CODE_DSUBS, setCodeOp3_N8WDW, setInputOp3_Val32_N1_off, verifyResultValueDWord,
			"DSUBS off op3=nop1-op2", 1, 0},
	{90, ML_CODE_DSUBS, setCodeOp3_N8WDW, setInputOp3_Val32_N1_on, verifyResultValueDWord,
			"DSUBS on op3=nop1-op2", 1, 444434},
	{91, ML_CODE_DSUBS, setCodeOp3_WN8DW, setInputOp3_Val32_N2_off, verifyResultValueDWord,
			"DSUBS off op3=op1-nop2", 1, 0},
	{92, ML_CODE_DSUBS, setCodeOp3_WN8DW, setInputOp3_Val32_N2_on, verifyResultValueDWord,
			"DSUBS on op3=op1-nop2", 1, 444434},
	{93, ML_CODE_DSUBS, setCodeOp3_K1WDW, setInputSIn_Val32_K1W2_off, verifyResultValueDWord,
			"DSUBS off op3=K-op2", 1, 0},
	{94, ML_CODE_DSUBS, setCodeOp3_K1WDW, setInputSIn_Val32_K1W2_on, verifyResultValueDWord,
			"DSUBS on op3=K-op2", 1, 444434},
	{95, ML_CODE_DSUBS, setCodeOp3_K1N8DW, setInputOp3_Val32_KN2_off, verifyResultValueDWord,
			"DSUBS off op3=K-nop2", 1, 0},
	{96, ML_CODE_DSUBS, setCodeOp3_K1N8DW, setInputOp3_Val32_KN2_on, verifyResultValueDWord,
			"DSUBS on op3=K-nop2", 1, 444434},
	{97, ML_CODE_DSUBS, setCodeOp3_WK2DW, setInputSIn_Val32_W1K2_off, verifyResultValueDWord,
			"DSUBS off op3=op1-K", 1, 0},
	{98, ML_CODE_DSUBS, setCodeOp3_WK2DW, setInputSIn_Val32_W1K2_on, verifyResultValueDWord,
			"DSUBS on op3=op1-K", 1, 444434},
	{99, ML_CODE_DSUBS, setCodeOp3_N8K2DW, setInputOp3_Val32_N1K_off, verifyResultValueDWord,
			"DSUBS off op3=nop1-K", 1, 0},
	{100, ML_CODE_DSUBS, setCodeOp3_N8K2DW, setInputOp3_Val32_N1K_on, verifyResultValueDWord,
			"DSUBS on op3=nop1-K", 1, 444434},
	{101, ML_CODE_DSUBS, setCodeLD32_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"DSUBS off op1=K-K", 1, 0},
	{102, ML_CODE_DSUBS, setCodeLD32_2K_1op, setInputNIn_Val16_on, verifyResultValueDWord,
			"DSUBS on op1=K-K", 1, 444434},

	{103, ML_CODE_DSUBPS, setCodeLD_3op_in, setInput2DIn_Val32_off, verifyResultValueDWord,
			"DSUBPS 0->0 op3=op1-op2", 2, 0},
	{104, ML_CODE_DSUBPS, setCodeLD_3op_in, setInput2DIn_Val32p_on, verifyResultValueDWord,
			"DSUBPS 0->1 op3=op1-op2", 2, 444434},
	{105, ML_CODE_DSUBPS, setCodeLD_3op_out, setInput1DIn_Val32_off, verifyResultValueDWord,
			"DSUBPS 0->0 op3=op1-op2", 2, 0},
	{106, ML_CODE_DSUBPS, setCodeLD_3op_out, setInput1DIn_Val32p_on, verifyResultValueDWord,
			"DSUBPS 0->1 op3=op1-op2", 2, 444434},
	{107, ML_CODE_DSUBPS, setCodeLD_3op_out, setInput1DIn_neg_Val32p_on_overflow, verifyResultValueDWord,
			"DSUBPS 0->1 op3=op1-op2 overflow", 2, 2147483646},
	{108, ML_CODE_DSUBPS, setCodeOp3_N8WDW, setInputOp3_Val32_N1_off, verifyResultValueDWord,
			"DSUBPS 0->0 op3=nop1-op2", 2, 0},
	{109, ML_CODE_DSUBPS, setCodeOp3_N8WDW, setInputOp3_Val32p_N1_on, verifyResultValueDWord,
			"DSUBPS 0->1 op3=nop1-op2", 2, 444434},
	{110, ML_CODE_DSUBPS, setCodeOp3_WN8DW, setInputOp3_Val32_N2_off, verifyResultValueDWord,
			"DSUBPS 0->0 op3=op1-nop2", 2, 0},
	{111, ML_CODE_DSUBPS, setCodeOp3_WN8DW, setInputOp3_Val32p_N2_on, verifyResultValueDWord,
			"DSUBPS 0->1 op3=op1-nop2", 2, 444434},
	{112, ML_CODE_DSUBPS, setCodeOp3_K1WDW, setInputSIn_Val32_K1W2_off, verifyResultValueDWord,
			"DSUBPS 0->0 op3=K-op2", 2, 0},
	{113, ML_CODE_DSUBPS, setCodeOp3_K1WDW, setInputSIn_Val32p_K1W2_on, verifyResultValueDWord,
			"DSUBPS 0->1 op3=K-op2", 2, 444434},
	{114, ML_CODE_DSUBPS, setCodeOp3_K1N8DW, setInputOp3_Val32_KN2_off, verifyResultValueDWord,
			"DSUBPS 0->0 op3=K-nop2", 2, 0},
	{115, ML_CODE_DSUBPS, setCodeOp3_K1N8DW, setInputOp3_Val32p_KN2_on, verifyResultValueDWord,
			"DSUBPS 0->1 op3=K-nop2", 2, 444434},
	{116, ML_CODE_DSUBPS, setCodeOp3_WK2DW, setInputSIn_Val32_W1K2_off, verifyResultValueDWord,
			"DSUBPS 0->0 op3=op1-K", 2, 0},
	{117, ML_CODE_DSUBPS, setCodeOp3_WK2DW, setInputSIn_Val32p_W1K2_on, verifyResultValueDWord,
			"DSUBPS 0->1 op3=op1-K", 2, 444434},
	{118, ML_CODE_DSUBPS, setCodeOp3_N8K2DW, setInputOp3_Val32_N1K_off, verifyResultValueDWord,
			"DSUBPS 0->0 op3=nop1-K", 2, 0},
	{119, ML_CODE_DSUBPS, setCodeOp3_N8K2DW, setInputOp3_Val32p_N1K_on, verifyResultValueDWord,
			"DSUBPS 0->1 op3=nop1-K", 2, 444434},
	{120, ML_CODE_DSUBPS, setCodeLD32_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"DSUBPS 0->0 op1=K-K", 2, 0},
	{121, ML_CODE_DSUBPS, setCodeLD32_2K_1op, setInputNIn_Val16p_on, verifyResultValueDWord,
			"DSUBPS 0->1 op1=K-K", 2, 444434},

	{122, ML_CODE_DBADD, setCodeLD_2op, setInputDIn_BCD8_off, verifyResultValueDWord,
			"BCD DADD off op2+op1", 1, 159846504}, //0x9871068
	{123, ML_CODE_DBADD, setCodeLD_2op, setInputDIn_BCD8_on, verifyResultValueDWord,
			"BCD DADD on op2+op1", 1, 270091556}, //0x10194524
	{124, ML_CODE_DBADD, setCodeLD_2op, setInputDIn_BCD8_on_overflow, verifyResultValueDWord,
			"BCD DADD on op2+op1 overflow", 1, 6636321}, //0x654321
	{125, ML_CODE_DBADD, setCodeOp_N8DW, setInputDIn_N8BCD8_off, verifyResultValueDWord,
			"BCD DADD off op2+op1", 1, 159846504}, //0x9871068
	{126, ML_CODE_DBADD, setCodeOp_N8DW, setInputDIn_N8BCD8_on, verifyResultValueDWord,
			"BCD DADD on op2+op1", 1, 270091556}, //0x10194524
	{127, ML_CODE_DBADD, setCodeLD_BCD8_K_1op, setInputSIn_BCD8_off, verifyResultValueDWord,
			"BCD DADD off K+op2", 1, 159846504}, //0x9871068
	{128, ML_CODE_DBADD, setCodeLD_BCD8_K_1op, setInputSIn_BCD8_on, verifyResultValueDWord,
			"BCD DADD on K+op2", 1, 270091556}, //0x10194524

	{129, ML_CODE_DBADDP, setCodeLD_2op, setInputDIn_BCD8_off, verifyResultValueDWord,
			"BCD DADDP 0->0 op2=op1+op2", 2, 159846504}, //0x9871068
	{130, ML_CODE_DBADDP, setCodeLD_2op, setInputDIn_BCD8_on, verifyResultValueDWord,
			"BCD DADDP 1->1 op2=op1+op2", 2, 159846504}, //0x9871068
	{131, ML_CODE_DBADDP, setCodeLD_2op, setInputDIn_BCD8p_on, verifyResultValueDWord,
			"BCD DADDP 0->1 op2=op1+op2", 2, 270091556}, //0x10194524
	{132, ML_CODE_DBADDP, setCodeLD_2op, setInputDIn_BCD8p_on_overflow, verifyResultValueDWord,
			"BCD DADDP 0->1 op2+op1 overflow", 2, 6636321}, //0x654321
	{133, ML_CODE_DBADDP, setCodeOp_N8DW, setInputDIn_N8BCD8_off, verifyResultValueDWord,
			"BCD DADD 0->0 op2+op1", 2, 159846504}, //0x9871068
	{134, ML_CODE_DBADDP, setCodeOp_N8DW, setInputDIn_N8BCD8_on, verifyResultValueDWord,
			"BCD DADD 1->1 op2+op1", 2, 159846504}, //0x9871068
	{135, ML_CODE_DBADDP, setCodeOp_N8DW, setInputDIn_N8BCD8p_on, verifyResultValueDWord,
			"BCD DADD 0->1 op2+op1", 2, 270091556}, //0x10194524
	{136, ML_CODE_DBADDP, setCodeLD_BCD8_K_1op, setInputSIn_BCD8_off, verifyResultValueDWord,
			"BCD DADDP 0->0 op2=K+op2", 2, 159846504}, //0x9871068
	{137, ML_CODE_DBADDP, setCodeLD_BCD8_K_1op, setInputSIn_BCD8_on, verifyResultValueDWord,
			"BCD DADDP 1->1 op2=K+op2", 2, 159846504}, //0x9871068
	{138, ML_CODE_DBADDP, setCodeLD_BCD8_K_1op, setInputSIn_BCD8p_on, verifyResultValueDWord,
			"BCD DADDP 0->1 op2=K+op2", 2, 270091556}, //0x10194524

	{139, ML_CODE_DBSUB, setCodeLD_2op, setInputDIn_BCD8_off, verifyResultValueDWord,
			"BCD DSUB off op2=op2-op1", 1, 159846504}, //0x9871068
	{140, ML_CODE_DBSUB, setCodeLD_2op, setInputDIn_BCD8_on, verifyResultValueDWord,
			"BCD DSUB on op2=op2-op1", 1, 156530194}, //0x9547612
	{141, ML_CODE_DBSUB, setCodeLD_2op, setInputDIn_BCD8_on_underflow, verifyResultValueDWord,
			"BCD DSUB on op2-op1 underflow", 1, 2576980377}, //0x99999999
	{142, ML_CODE_DBSUB, setCodeOp_N8DW, setInputDIn_N8BCD8_off, verifyResultValueDWord,
			"BCD DSUB off op2=op2-nop1", 1, 159846504}, //0x9871068
	{143, ML_CODE_DBSUB, setCodeOp_N8DW, setInputDIn_N8BCD8_on, verifyResultValueDWord,
			"BCD DSUB on op2=op2-nop1", 1, 156530194}, //0x9547612
	{144, ML_CODE_DBSUB, setCodeLD_BCD8_K_1op, setInputSIn_BCD8_off, verifyResultValueDWord,
			"BCD DSUB off op2=op2-K", 1, 159846504}, //0x9871068
	{145, ML_CODE_DBSUB, setCodeLD_BCD8_K_1op, setInputSIn_BCD8_on, verifyResultValueDWord,
			"BCD DSUB on op2=op2-K", 1, 156530194}, //0x9547612

	{146, ML_CODE_DBSUBP, setCodeLD_2op, setInputDIn_BCD8_off, verifyResultValueDWord,
			"BCD DSUBP 0->0 op2=op2-op1", 2, 159846504}, //0x9871068
	{147, ML_CODE_DBSUBP, setCodeLD_2op, setInputDIn_BCD8_on, verifyResultValueDWord,
			"BCD DSUBP 1->1 op2=op2-op1", 2, 159846504}, //0x9871068
	{148, ML_CODE_DBSUBP, setCodeLD_2op, setInputDIn_BCD8p_on, verifyResultValueDWord,
			"BCD DSUBP 0->1 op2=op2-op1", 2, 156530194}, //0x9547612
	{149, ML_CODE_DBSUBP, setCodeLD_2op, setInputDIn_BCD8p_on_underflow, verifyResultValueDWord,
			"BCD DSUBP 0->1 op2+op1 undflow", 2, 2576980377}, //0x99999999
	{150, ML_CODE_DBSUBP, setCodeOp_N8DW, setInputDIn_N8BCD8_off, verifyResultValueDWord,
			"BCD DSUBP 0->0 op2=op2-op1", 2, 159846504}, //0x9871068
	{151, ML_CODE_DBSUBP, setCodeOp_N8DW, setInputDIn_N8BCD8_on, verifyResultValueDWord,
			"BCD DSUBP 1->1 op2=op2-op1", 2, 159846504}, //0x9871068
	{152, ML_CODE_DBSUBP, setCodeOp_N8DW, setInputDIn_N8BCD8p_on, verifyResultValueDWord,
			"BCD DSUBP 0->1 op2=op2-op1", 2, 156530194}, //0x9547612
	{153, ML_CODE_DBSUBP, setCodeLD_BCD8_K_1op, setInputSIn_BCD8_off, verifyResultValueDWord,
			"BCD DSUBP 0->0 op2=op2-K", 2, 159846504}, //0x9871068
	{154, ML_CODE_DBSUBP, setCodeLD_BCD8_K_1op, setInputSIn_BCD8_on, verifyResultValueDWord,
			"BCD DSUBP 0->0 op2=op2-K", 2, 159846504}, //0x9871068
	{155, ML_CODE_DBSUBP, setCodeLD_BCD8_K_1op, setInputSIn_BCD8p_on, verifyResultValueDWord,
			"BCD DSUBP 0->1 op2=op2-K", 2, 156530194}, //0x9547612

	{156, ML_CODE_DBADDS, setCodeLD_3op_in, setInputOP3_BCD8_WW_DW_off, verifyResultValueDWord,
			"BCD DADDS off op3=op2+op1", 1, 0},
	{157, ML_CODE_DBADDS, setCodeLD_3op_in, setInputOP3_BCD8_WW_DW_on, verifyResultValueDWord,
			"BCD DADDS on op3=op2+op1", 1, 270091556}, //0x10194524
	{158, ML_CODE_DBADDS, setCodeLD_3op_in, setInputOP3_BCD8_WW_DW_on_overflow, verifyResultValueDWord,
			"BCD DADDS on op3=op2+op1 overflow", 1, 6636321}, //0x654321
	{159, ML_CODE_DBADDS, setCodeLD_3op_out, setInputOP3_BCD8_W_WDW_off, verifyResultValueDWord,
			"BCD DADDS off op3=op2+op1", 1, 0},
	{160, ML_CODE_DBADDS, setCodeLD_3op_out, setInputOP3_BCD8_W_WDW_on, verifyResultValueDWord,
			"BCD DADDS on op3=op2+op1", 1, 270091556}, //0x10194524
	{161, ML_CODE_DBADDS, setCodeOp3_N8WDW, setInputDIn_N8BCD8DW_off, verifyResultValueDWord,
			"BCD DADDS off op3=nop1+op2", 1, 0},
	{162, ML_CODE_DBADDS, setCodeOp3_N8WDW, setInputDIn_N8BCD8DW_on, verifyResultValueDWord,
			"BCD DADDS on op3=nop1+op2", 1, 270091556}, //0x10194524
	{163, ML_CODE_DBADDS, setCodeOp3_WN8DW, setInputDIn_BCD8N8DW_off, verifyResultValueDWord,
			"BCD DADDS off op3=op1+nop2", 1, 0},
	{164, ML_CODE_DBADDS, setCodeOp3_WN8DW, setInputDIn_BCD8N8DW_on, verifyResultValueDWord,
			"BCD DADDS on op3=op1+nop2", 1, 270091556}, //0x10194524
	{165, ML_CODE_DBADDS, setCodeOp3_BCD8_K1WDW, setInputDIn_K1BCD8DW_off, verifyResultValueDWord,
			"BCD DADDS off op3=K+op2", 1, 0},
	{166, ML_CODE_DBADDS, setCodeOp3_BCD8_K1WDW, setInputDIn_K1BCD8DW_on, verifyResultValueDWord,
			"BCD DADDS on op3=K+op2", 1, 270091556}, //0x10194524
	{167, ML_CODE_DBADDS, setCodeOp3_BCD8_K1N8DW, setInputDIn_K1N8DW_off, verifyResultValueDWord,
			"BCD DADDS off op3=K+nop2", 1, 0},
	{168, ML_CODE_DBADDS, setCodeOp3_BCD8_K1N8DW, setInputDIn_K1N8DW_on, verifyResultValueDWord,
			"BCD DADDS on op3=K+nop2", 1, 270091556}, //0x10194524
	{169, ML_CODE_DBADDS, setCodeOp3_BCD8_WK2DW, setInputDIn_BCD8K2DW_off, verifyResultValueDWord,
			"BCD DADDS off op3=K+op2", 1, 0},
	{170, ML_CODE_DBADDS, setCodeOp3_BCD8_WK2DW, setInputDIn_BCD8K2DW_on, verifyResultValueDWord,
			"BCD DADDS on op3=K+op2", 1, 270091556}, //0x10194524
	{171, ML_CODE_DBADDS, setCodeOp3_BCD8_N8K2DW, setInputDIn_N8K2DW_off, verifyResultValueDWord,
			"BCD DADDS off op3=K+nop2", 1, 0},
	{172, ML_CODE_DBADDS, setCodeOp3_BCD8_N8K2DW, setInputDIn_N8K2DW_on, verifyResultValueDWord,
			"BCD DADDS on op3=K+nop2", 1, 270091556}, //0x10194524
	{173, ML_CODE_DBADDS, setCodeLD32_BCD8_2K, setInputNIn_Val16_off, verifyResultValueDWord,
			"BCD DADDS off op3=K+nop2", 1, 0},
	{174, ML_CODE_DBADDS, setCodeLD32_BCD8_2K, setInputNIn_Val16_on, verifyResultValueDWord,
			"BCD DADDS on op3=K+nop2", 1, 270091556}, //0x10194524

	{175, ML_CODE_DBADDPS, setCodeLD_3op_in, setInputOP3_BCD8_WW_DW_off, verifyResultValueDWord,
			"BCD DBADDPS 0->0 op3=op2+op1", 2, 0},
	{176, ML_CODE_DBADDPS, setCodeLD_3op_in, setInputOP3_BCD8p_WW_DW_on, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=op2+op1", 2, 270091556}, //0x10194524
	{177, ML_CODE_DBADDPS, setCodeLD_3op_in, setInputOP3_BCD8p_WW_DW_on_overflow, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=op2+op1 over", 2, 6636321}, //0x654321
	{178, ML_CODE_DBADDPS, setCodeLD_3op_out, setInputOP3_BCD8_W_WDW_off, verifyResultValueDWord,
			"BCD DBADDPS 0->0 op3=op2+op1", 2, 0},
	{179, ML_CODE_DBADDPS, setCodeLD_3op_out, setInputOP3_BCD8p_W_WDW_on, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=op2+op1", 2, 270091556}, //0x10194524
	{180, ML_CODE_DBADDPS, setCodeOp3_N8WDW, setInputDIn_N8BCD8DW_off, verifyResultValueDWord,
			"BCD DBADDPS 0->0 op3=nop1+op2", 2, 0},
	{181, ML_CODE_DBADDPS, setCodeOp3_N8WDW, setInputDIn_N8BCD8DWp_on, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=nop1+op2", 2, 270091556}, //0x10194524
	{182, ML_CODE_DBADDPS, setCodeOp3_WN8DW, setInputDIn_BCD8N8DW_off, verifyResultValueDWord,
			"BCD DBADDPS 0->0 op3=op1+nop2", 2, 0},
	{183, ML_CODE_DBADDPS, setCodeOp3_WN8DW, setInputDIn_BCD8N8DWp_on, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=op1+nop2", 2, 270091556}, //0x10194524
	{184, ML_CODE_DBADDPS, setCodeOp3_BCD8_K1WDW, setInputDIn_K1BCD8DW_off, verifyResultValueDWord,
			"BCD DBADDPS 0->0 op3=K+op2", 2, 0},
	{185, ML_CODE_DBADDPS, setCodeOp3_BCD8_K1WDW, setInputDIn_K1BCD8DWp_on, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=K+op2", 2, 270091556}, //0x10194524
	{186, ML_CODE_DBADDPS, setCodeOp3_BCD8_K1N8DW, setInputDIn_K1N8DW_off, verifyResultValueDWord,
			"BCD DBADDPS 0->0 op3=K+nop2", 2, 0},
	{187, ML_CODE_DBADDPS, setCodeOp3_BCD8_K1N8DW, setInputDIn_K1N8DWp_on, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=K+nop2", 2, 270091556}, //0x10194524
	{188, ML_CODE_DBADDPS, setCodeOp3_BCD8_WK2DW, setInputDIn_BCD8K2DW_off, verifyResultValueDWord,
			"BCD DBADDPS 0->0 op3=K+op2", 2, 0},
	{189, ML_CODE_DBADDPS, setCodeOp3_BCD8_WK2DW, setInputDIn_BCD8K2DWp_on, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=K+op2", 2, 270091556}, //0x10194524
	{190, ML_CODE_DBADDPS, setCodeOp3_BCD8_N8K2DW, setInputDIn_N8K2DW_off, verifyResultValueDWord,
			"BCD DBADDPS 0->0 op3=K+nop2", 2, 0},
	{191, ML_CODE_DBADDPS, setCodeOp3_BCD8_N8K2DW, setInputDIn_N8K2DWp_on, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=K+nop2", 2, 270091556}, //0x10194524
	{192, ML_CODE_DBADDPS, setCodeLD32_BCD8_2K, setInputNIn_Val16_off, verifyResultValueDWord,
			"BCD DBADDPS 0->0 op3=K+nop2", 2, 0},
	{193, ML_CODE_DBADDPS, setCodeLD32_BCD8_2K, setInputNIn_Val16p_on, verifyResultValueDWord,
			"BCD DBADDPS 0->1 op3=K+nop2", 2, 270091556}, //0x10194524

	{194, ML_CODE_DBSUBS, setCodeLD_3op_in, setInputOP3_BCD8_WW_DW_off, verifyResultValueDWord,
			"BCD DBSUBS off op3=op1-op2", 1, 0},
	{195, ML_CODE_DBSUBS, setCodeLD_3op_in, setInputOP3_BCD8_WW_DW_on, verifyResultValueDWord,
			"BCD DBSUBS on op3=op1-op2", 1, 156530194}, //0x9547612
	{196, ML_CODE_DBSUBS, setCodeLD_3op_in, setInputOP3_BCD8_WW_DW_on_underflow, verifyResultValueDWord,
			"BCD DBSUBS on op3=op1-op2 under", 1, 0x99999999}, //0x99999999
	{197, ML_CODE_DBSUBS, setCodeLD_3op_out, setInputOP3_BCD8_W_WDW_off, verifyResultValueDWord,
			"BCD DBSUBS off op3=op1-op2", 1, 0},
	{198, ML_CODE_DBSUBS, setCodeLD_3op_out, setInputOP3_BCD8_W_WDW_on, verifyResultValueDWord,
			"BCD DBSUBS on op3=op1-op2", 1, 156530194}, //0x9547612
	{199, ML_CODE_DBSUBS, setCodeOp3_N8WDW, setInputDIn_N8BCD8DW_off, verifyResultValueDWord,
			"BCD DBSUBS off op3=nop1-op2", 1, 0},
	{200, ML_CODE_DBSUBS, setCodeOp3_N8WDW, setInputDIn_N8BCD8DW_on, verifyResultValueDWord,
			"BCD DBSUBS on op3=nop1-op2", 1, 156530194}, //0x9547612
	{201, ML_CODE_DBSUBS, setCodeOp3_WN8DW, setInputDIn_BCD8N8DW_off, verifyResultValueDWord,
			"BCD DBSUBS off op3=op1-nop2", 1, 0},
	{202, ML_CODE_DBSUBS, setCodeOp3_WN8DW, setInputDIn_BCD8N8DW_on, verifyResultValueDWord,
			"BCD DBSUBS on op3=op1-nop2", 1, 156530194}, //0x9547612
	{203, ML_CODE_DBSUBS, setCodeOp3_BCD8_K1WDW, setInputDIn_K1BCD8DW_off, verifyResultValueDWord,
			"BCD DBSUBS off op3=K-op2", 1, 0},
	{204, ML_CODE_DBSUBS, setCodeOp3_BCD8_K1WDW, setInputDIn_K1BCD8DW_on, verifyResultValueDWord,
			"BCD DBSUBS on op3=K-op2", 1, 156530194}, //0x9547612
	{205, ML_CODE_DBSUBS, setCodeOp3_BCD8_K1N8DW, setInputDIn_K1N8DW_off, verifyResultValueDWord,
			"BCD DBSUBS off op3=K-nop2", 1, 0},
	{206, ML_CODE_DBSUBS, setCodeOp3_BCD8_K1N8DW, setInputDIn_K1N8DW_on, verifyResultValueDWord,
			"BCD DBSUBS on op3=K-nop2", 1, 156530194}, //0x9547612
	{207, ML_CODE_DBSUBS, setCodeOp3_BCD8_WK2DW, setInputDIn_BCD8K2DW_off, verifyResultValueDWord,
			"BCD DBSUBS off op3=K-op2", 1, 0},
	{208, ML_CODE_DBSUBS, setCodeOp3_BCD8_WK2DW, setInputDIn_BCD8K2DW_on, verifyResultValueDWord,
			"BCD DBSUBS on op3=K-op2", 1, 156530194}, //0x9547612
	{209, ML_CODE_DBSUBS, setCodeOp3_BCD8_N8K2DW, setInputDIn_N8K2DW_off, verifyResultValueDWord,
			"BCD DBSUBS off op3=K-nop2", 1, 0},
	{210, ML_CODE_DBSUBS, setCodeOp3_BCD8_N8K2DW, setInputDIn_N8K2DW_on, verifyResultValueDWord,
			"BCD DBSUBS on op3=K-nop2", 1, 156530194}, //0x9547612
	{211, ML_CODE_DBSUBS, setCodeLD32_BCD8_2K, setInputNIn_Val16_off, verifyResultValueDWord,
			"BCD DBSUBS off op3=K-nop2", 1, 0},
	{212, ML_CODE_DBSUBS, setCodeLD32_BCD8_2K, setInputNIn_Val16_on, verifyResultValueDWord,
			"BCD DBSUBS on op3=K-nop2", 1, 156530194}, //0x9547612

	{213, ML_CODE_DBSUBPS, setCodeLD_3op_in, setInputOP3_BCD8_WW_DW_off, verifyResultValueDWord,
			"BCD DBSUBPS 0->0 op3=op1-op2", 2, 0},
	{214, ML_CODE_DBSUBPS, setCodeLD_3op_in, setInputOP3_BCD8p_WW_DW_on, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=op1-op2", 2, 156530194}, //0x9547612
	{215, ML_CODE_DBSUBPS, setCodeLD_3op_in, setInputOP3_BCD8p_WW_DW_on_underflow, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=op1-op2 over", 2, 0x99999999}, //0x99999999
	{216, ML_CODE_DBSUBPS, setCodeLD_3op_out, setInputOP3_BCD8_W_WDW_off, verifyResultValueDWord,
			"BCD DBSUBPS 0->0 op3=op1-op2", 2, 0},
	{217, ML_CODE_DBSUBPS, setCodeLD_3op_out, setInputOP3_BCD8p_W_WDW_on, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=op1-op2", 2, 156530194}, //0x9547612
	{218, ML_CODE_DBSUBPS, setCodeOp3_N8WDW, setInputDIn_N8BCD8DW_off, verifyResultValueDWord,
			"BCD DBSUBPS 0->0 op3=nop1-op2", 2, 0},
	{219, ML_CODE_DBSUBPS, setCodeOp3_N8WDW, setInputDIn_N8BCD8DWp_on, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=nop1-op2", 2, 156530194}, //0x9547612
	{220, ML_CODE_DBSUBPS, setCodeOp3_WN8DW, setInputDIn_BCD8N8DW_off, verifyResultValueDWord,
			"BCD DBSUBPS 0->0 op3=op1-nop2", 2, 0},
	{221, ML_CODE_DBSUBPS, setCodeOp3_WN8DW, setInputDIn_BCD8N8DWp_on, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=op1-nop2", 2, 156530194}, //0x9547612
	{222, ML_CODE_DBSUBPS, setCodeOp3_BCD8_K1WDW, setInputDIn_K1BCD8DW_off, verifyResultValueDWord,
			"BCD DBSUBPS 0->0 op3=K-op2", 2, 0},
	{223, ML_CODE_DBSUBPS, setCodeOp3_BCD8_K1WDW, setInputDIn_K1BCD8DWp_on, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=K-op2", 2, 156530194}, //0x9547612
	{224, ML_CODE_DBSUBPS, setCodeOp3_BCD8_K1N8DW, setInputDIn_K1N8DW_off, verifyResultValueDWord,
			"BCD DBSUBPS 0->0 op3=K-nop2", 2, 0},
	{225, ML_CODE_DBSUBPS, setCodeOp3_BCD8_K1N8DW, setInputDIn_K1N8DWp_on, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=K-nop2", 2, 156530194}, //0x9547612
	{226, ML_CODE_DBSUBPS, setCodeOp3_BCD8_WK2DW, setInputDIn_BCD8K2DW_off, verifyResultValueDWord,
			"BCD DBSUBPS 0->0 op3=K-op2", 2, 0},
	{227, ML_CODE_DBSUBPS, setCodeOp3_BCD8_WK2DW, setInputDIn_BCD8K2DWp_on, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=K-op2", 2, 156530194}, //0x9547612
	{228, ML_CODE_DBSUBPS, setCodeOp3_BCD8_N8K2DW, setInputDIn_N8K2DW_off, verifyResultValueDWord,
			"BCD DBSUBPS 0->0 op3=K-nop2", 2, 0},
	{229, ML_CODE_DBSUBPS, setCodeOp3_BCD8_N8K2DW, setInputDIn_N8K2DWp_on, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=K-nop2", 2, 156530194}, //0x9547612
	{230, ML_CODE_DBSUBPS, setCodeLD32_BCD8_2K, setInputNIn_Val16_off, verifyResultValueDWord,
			"BCD DBSUBPS 0->0 op3=K-nop2", 2, 0},
	{231, ML_CODE_DBSUBPS, setCodeLD32_BCD8_2K, setInputNIn_Val16p_on, verifyResultValueDWord,
			"BCD DBSUBPS 0->1 op3=K-nop2", 2, 156530194}, //0x9547612

	{-1, 0xFFFF, NULL, NULL, NULL, " ", 0, 0 }
};


int total_basic_compute_dword_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_dword_test_number; i++)
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

int setCodeOp_N8DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_N8(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_N8WDW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperand(out_reg, 160);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WN8DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(out_reg, in_pos); addMLOperandNibble(8, in_reg, 160);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD32_K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 567890); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_K1WDW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if(in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 567890);
		addMLOperand(in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_K1N8DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 567890);
		addMLOperandNibble(8, in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WK2DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if(in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos);
		addMLOperand(OPERAND_ML_CODE_DK, 123456); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_N8K2DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos);
		addMLOperand(OPERAND_ML_CODE_DK, 123456); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD32_2K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 567890); addMLOperand(OPERAND_ML_CODE_DK, 123456);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD8_K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x323456); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_BCD8_K1WDW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if(in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x323456);
		addMLOperand(in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_BCD8_K1N8DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x323456);
		addMLOperandNibble(8, in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_BCD8_WK2DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if(in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos);
		addMLOperand(OPERAND_ML_CODE_DK, 0x9871068); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_BCD8_N8K2DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if(in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos);
		addMLOperand(OPERAND_ML_CODE_DK, 0x9871068); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD32_BCD8_2K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x323456);
		addMLOperand(OPERAND_ML_CODE_DK, 0x9871068); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput2Op_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 123456);

	TestCodeTearDown();
}

void setInput2Op_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 123456);

	TestCodeTearDown();
}

void setInput2Op_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 123456);

	TestCodeTearDown();
}

void setInputDIn_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 123456);

	TestCodeTearDown();
}

void setInputDIn_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 123456);

	TestCodeTearDown();
}

void setInputDIn_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 123456);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_Val32_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 123456);

	TestCodeTearDown();
}

void setInputDIn_Val32_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 123456);

	TestCodeTearDown();
}

void setInputDIn_Val32p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32_N2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, 567890);

	TestCodeTearDown();
}

void setInputOp3_Val32_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, 567890);

	TestCodeTearDown();
}

void setInputOp3_Val32p_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, 567890);

	TestCodeTearDown();
}

void setInputOp3_Val32_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32p_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_N1K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_N1K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32p_N1K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 123456);

	TestCodeTearDown();
}

void setInputSIn_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 123456);

	TestCodeTearDown();
}

void setInputDIn_Val32_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 2147483647);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 2);

	TestCodeTearDown();
}

void setInputDIn_neg_Val32_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 2 );
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, -2147483648);

	TestCodeTearDown();
}

void setInputSIn_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 123456);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val32_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 2147483647);

	TestCodeTearDown();
}

void setInputSIn_Val32_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, -2147483648);

	TestCodeTearDown();
}

void setInputSIn_Val32p_on_over(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 2147483647);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val32p_on_under(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, -2147483648);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput2DIn_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 123456);

	TestCodeTearDown();
}

void setInput2DIn_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 123456);

	TestCodeTearDown();
}

void setInput2DIn_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 123456);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);


	TestCodeTearDown();
}

void setInput1DIn_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 123456);

	TestCodeTearDown();
}

void setInput1DIn_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 123456);

	TestCodeTearDown();
}

void setInput1DIn_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 123456);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);


	TestCodeTearDown();
}

void setInput1DIn_Val32_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 2147483647);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 2);

	TestCodeTearDown();
}

void setInput1DIn_Val32p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 2147483647);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 2);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput1DIn_neg_Val32_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, -2147483648);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 2);

	TestCodeTearDown();
}

void setInput1DIn_neg_Val32p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, -2147483648L);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 2);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val32_K1W2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 123456);

	TestCodeTearDown();
}

void setInputSIn_Val32_K1W2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 123456);

	TestCodeTearDown();
}

void setInputSIn_Val32p_K1W2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 123456);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_Val32_W1K2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);

	TestCodeTearDown();
}

void setInputSIn_Val32_W1K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);

	TestCodeTearDown();
}

void setInputSIn_Val32p_W1K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);

	TestCodeTearDown();
}

void setInputDIn_BCD8_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_BCD8_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_BCD8p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x9871068);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_BCD8_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99000000);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x1654321);

	TestCodeTearDown();
}

void setInputDIn_BCD8p_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99000000);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x1654321);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_BCD8_on_underflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x12345679);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x12345678);

	TestCodeTearDown();
}

void setInputDIn_BCD8p_on_underflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x12345679);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x12345678);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}


void setInputSIn_BCD8_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputSIn_BCD8_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputSIn_BCD8p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x9871068);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputDIn_N8BCD8_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_N8BCD8_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_N8BCD8p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputOP3_BCD8_WW_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x9871068);

	TestCodeTearDown();
}

void setInputOP3_BCD8_WW_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x9871068);

	TestCodeTearDown();
}

void setInputOP3_BCD8p_WW_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x9871068);

	TestCodeTearDown();
}

void setInputOP3_BCD8_WW_DW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99000000);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x1654321);

	TestCodeTearDown();
}

void setInputOP3_BCD8p_WW_DW_on_overflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99000000);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x1654321);

	TestCodeTearDown();
}

void setInputOP3_BCD8_WW_DW_on_underflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x12345678);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x12345679);

	TestCodeTearDown();
}

void setInputOP3_BCD8p_WW_DW_on_underflow(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x12345678);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x12345679);

	TestCodeTearDown();
}

void setInputOP3_BCD8_W_WDW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 0x9871068);

	TestCodeTearDown();
}

void setInputOP3_BCD8_W_WDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 0x9871068);

	TestCodeTearDown();
}

void setInputOP3_BCD8p_W_WDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_N8BCD8DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_N8BCD8DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_N8BCD8DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, 0x9871068);

	TestCodeTearDown();
}


void setInputDIn_BCD8N8DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, 0x323456);

	TestCodeTearDown();
}

void setInputDIn_BCD8N8DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, 0x323456);

	TestCodeTearDown();
}

void setInputDIn_BCD8N8DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, 0x323456);

	TestCodeTearDown();
}

void setInputDIn_K1BCD8DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_K1BCD8DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_K1BCD8DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x9871068);

	TestCodeTearDown();
}

void setInputDIn_K1N8DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}


	TestCodeTearDown();
}

void setInputDIn_K1N8DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_K1N8DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCD8K2DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);

	TestCodeTearDown();
}

void setInputDIn_BCD8K2DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);

	TestCodeTearDown();
}

void setInputDIn_BCD8K2DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);

	TestCodeTearDown();
}

void setInputDIn_N8K2DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N8K2DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N8K2DWp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected)
{
	int rc=0;
	int result;
	char reg[] = {'D', 'W'};

	if(!test_getDWord(&result, dest_reg, pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d Reg %c[%d]=%d %d\n", tcase, reg[dest_reg-OPERAND_ML_CODE_D], pos, result, expected);
	CU_ASSERT_EQUAL(result, expected);
	if(result != expected) rc=1;

	return rc;
}


static uint16 getPos(int reg, int inx_pos)
{
	//uint16 pos[3][2]={ {0,0}, {6144,4096}, {12285,8189}}; // -2
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}};
	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_arithmetic_dword(int tno, uint16 dummy)
{
	int i, ml_rc, rc=0, olast=0, res_dword;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
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

					if(in == out && (in_pos == out_pos || in_pos-2 == out_pos) )
					{
						continue;
					}

					ml_rc= testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if(ml_rc==0) continue;

					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

					rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error!\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName);
					}
					else
					{
						rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
						if(rc == 1)
						{
							test_getDWord(&res_dword, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_dword, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testBasicArithmeticDWordCommand(void)
{
	int i, index=33;
	int start, end;
	char log[] = "err_arith_dword.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic dword LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0;index<5;index++)
		test_basic_arithmetic_dword(index, 0);
#else
	total_basic_compute_dword_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DADD);
	end = getTestCaseNumberEnd(ML_CODE_DBSUBP); //ML_CODE_DBSUBP

	DBG_LOGPRINT("testBasicArithmeticDWordCommand: %d to %d total %d\n", start, end, total_basic_compute_dword_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_dword(index, 0);
	}
#endif
	fclose(flog);
}

#endif
