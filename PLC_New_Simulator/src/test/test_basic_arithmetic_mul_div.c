/*
 * test_basic_arithmatic_mul_div.c
 *
 *  Created on: May 22, 2015
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

extern int setCodeLD_3op_in(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeLD_3op_out(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeLD_K_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeLD_2K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeLD_K_2op_div(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

extern int setCodeOp_N1_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeOp_N2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

extern void setInput2DIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInput2DIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInput2DIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInput1DIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInput1DIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInput1DIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_Val16_in_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_Val16_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_Val16p_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected);

int setCodeOp_WN2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp_N1K_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp_KN2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_WK2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

//int setCodeLD_BCD_mlt_K_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD_mlt_2K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD_mlt_K1BCD4_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD_mlt_K1N2_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD_mlt_BCD4K2_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD_mlt_N1K2_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD4K2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_BCD_N1K2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInput2DIn_Val16div_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16div_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16divp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val16div_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val16div_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_Val16divp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInput2DIn_Val16div_N1W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16div_N1W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16divp_N1W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16div_WN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16div_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16divp_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInput2DIn_Val16_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_N2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInput2DIn_Val16_N1K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_N1K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_N1K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_WK2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_WK2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_WK2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_BCD_mlt_in_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD_mlt_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCDp_mlt_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_mlt_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCD_mlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput1DIn_BCDp_mlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputIn_BCD_mlt_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputIn_BCD_mlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputIn_BCDp_mlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInput2DIn_Val16_N1BCD4_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_N1BCD4_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_N1BCD4_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_BCD4N2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_BCD4N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_BCD4N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_BCD_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_BCD_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_BCD_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_BCD4K2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_BCD4K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_BCD4K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_BCD_N1K2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_BCD_N1K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_BCD_N1K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

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
	{0, ML_CODE_MLT, setCodeLD_3op_in, setInput2DIn_Val16_off, verifyResultValueDWord,
			"Multiply off op3=op1*op2", 1, 0},
	{1, ML_CODE_MLT, setCodeLD_3op_in, setInput2DIn_Val16_on, verifyResultValueDWord,
			"Multiply on op3=op1*op2", 1, 7006652},
	{2, ML_CODE_MLT, setCodeLD_3op_out, setInput1DIn_Val16_off, verifyResultValueDWord,
			"Multiply off op3=op1*op2", 1, 0},
	{3, ML_CODE_MLT, setCodeLD_3op_out, setInput1DIn_Val16_on, verifyResultValueDWord,
			"Multiply on op3=op1*op2", 1, 7006652},
	{4, ML_CODE_MLT, setCodeOp_N1_W, setInput2DIn_Val16_N1_off, verifyResultValueDWord,
			"Multiply off op3=nop1*op2", 1, 0},
	{5, ML_CODE_MLT, setCodeOp_N1_W, setInput2DIn_Val16_N1_on, verifyResultValueDWord,
			"Multiply on op3=nop1*op2", 1, 7006652},
	{6, ML_CODE_MLT, setCodeOp_WN2_W, setInput2DIn_Val16_N2_off, verifyResultValueDWord,
			"Multiply off op3=op1*nop2", 1, 0},
	{7, ML_CODE_MLT, setCodeOp_WN2_W, setInput2DIn_Val16_N2_on, verifyResultValueDWord,
			"Multiply on op3=op1*nop2", 1, 7006652},
	{8, ML_CODE_MLT, setCodeLD_K_2op, setInputSIn_Val16_in_off, verifyResultValueDWord,
			"Multiply off op2=K*op1", 1, 0},
	{9, ML_CODE_MLT, setCodeLD_K_2op, setInputSIn_Val16_in_on, verifyResultValueDWord,
			"Multiply on op2=K*op1", 1, 7006652},
	{10, ML_CODE_MLT, setCodeOp_KN2_W, setInput2DIn_Val16_KN2_off, verifyResultValueDWord,
			"Multiply off op2=K*nop1", 1, 0},
	{11, ML_CODE_MLT, setCodeOp_KN2_W, setInput2DIn_Val16_KN2_on, verifyResultValueDWord,
			"Multiply on op2=K*nop1", 1, 7006652},
	{12, ML_CODE_MLT, setCodeLD_WK2_W, setInputSIn_Val16_WK2_off, verifyResultValueDWord,
			"Multiply off op2=op1*K", 1, 0},
	{13, ML_CODE_MLT, setCodeLD_WK2_W, setInputSIn_Val16_WK2_on, verifyResultValueDWord,
			"Multiply on op2=op1*K", 1, 7006652},
	{14, ML_CODE_MLT, setCodeOp_N1K_W, setInput2DIn_Val16_N1K_off, verifyResultValueDWord,
			"Multiply off op2=nop1*K", 1, 0},
	{15, ML_CODE_MLT, setCodeOp_N1K_W, setInput2DIn_Val16_N1K_on, verifyResultValueDWord,
			"Multiply on op2=nop1*K", 1, 7006652},
	{16, ML_CODE_MLT, setCodeLD_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"Multiply off op1=K*K", 1, 0},
	{17, ML_CODE_MLT, setCodeLD_2K_1op, setInputNIn_Val16_on, verifyResultValueDWord,
			"Multiply on op1=K*K", 1, 7006652},

	{18, ML_CODE_MLTP, setCodeLD_3op_in, setInput2DIn_Val16_off, verifyResultValueDWord,
			"MultiplyP 0->0 op3=op1*op2", 2, 0},
	{19, ML_CODE_MLTP, setCodeLD_3op_in, setInput2DIn_Val16p_on, verifyResultValueDWord,
			"MultiplyP 0->1 op3=op1*op2", 2, 7006652},
	{20, ML_CODE_MLTP, setCodeLD_3op_out, setInput1DIn_Val16_off, verifyResultValueDWord,
			"MultiplyP 0->0 op3=op1*op2", 2, 0},
	{21, ML_CODE_MLTP, setCodeLD_3op_out, setInput1DIn_Val16p_on, verifyResultValueDWord,
			"MultiplyP 0->1 op3=op1*op2", 2, 7006652},
	{22, ML_CODE_MLTP, setCodeOp_N1_W, setInput2DIn_Val16_N1_off, verifyResultValueDWord,
			"MultiplyP 0->0 op3=nop1*op2", 2, 0},
	{23, ML_CODE_MLTP, setCodeOp_N1_W, setInput2DIn_Val16p_N1_on, verifyResultValueDWord,
			"MultiplyP 0->1 op3=nop1*op2", 2, 7006652},
	{24, ML_CODE_MLTP, setCodeOp_WN2_W, setInput2DIn_Val16_N2_off, verifyResultValueDWord,
			"MultiplyP 0->0 op3=op1*nop2", 2, 0},
	{25, ML_CODE_MLTP, setCodeOp_WN2_W, setInput2DIn_Val16p_N2_on, verifyResultValueDWord,
			"MultiplyP 0->1 op3=op1*nop2", 2, 7006652},
	{26, ML_CODE_MLTP, setCodeLD_K_2op, setInputSIn_Val16_in_off, verifyResultValueDWord,
			"MultiplyP off op2=K*op1", 2, 0},
	{27, ML_CODE_MLTP, setCodeLD_K_2op, setInputSIn_Val16p_in_on, verifyResultValueDWord,
			"MultiplyP 0->1 op2=K*op1", 2, 7006652},
	{28, ML_CODE_MLTP, setCodeOp_KN2_W, setInput2DIn_Val16_KN2_off, verifyResultValueDWord,
			"MultiplyP off op2=K*nop1", 2, 0},
	{29, ML_CODE_MLTP, setCodeOp_KN2_W, setInput2DIn_Val16p_KN2_on, verifyResultValueDWord,
			"MultiplyP 0->1 op2=K*nop1", 2, 7006652},
	{30, ML_CODE_MLTP, setCodeLD_WK2_W, setInputSIn_Val16_WK2_off, verifyResultValueDWord,
			"MultiplyP off op2=op1*K", 2, 0},
	{31, ML_CODE_MLTP, setCodeLD_WK2_W, setInputSIn_Val16p_WK2_on, verifyResultValueDWord,
			"MultiplyP 0->1 op2=op1*K", 2, 7006652},
	{32, ML_CODE_MLTP, setCodeOp_N1K_W, setInput2DIn_Val16_N1K_off, verifyResultValueDWord,
			"MultiplyP off op2=nop1*K", 2, 0},
	{33, ML_CODE_MLTP, setCodeOp_N1K_W, setInput2DIn_Val16p_N1K_on, verifyResultValueDWord,
			"MultiplyP 0->1 op2=nop1*K", 2, 7006652},
	{34, ML_CODE_MLTP, setCodeLD_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"MultiplyP 0->0 op1=K*K", 2, 0},
	{35, ML_CODE_MLTP, setCodeLD_2K_1op, setInputNIn_Val16p_on, verifyResultValueDWord,
			"MultiplyP 0->1 op1=K*K", 2, 7006652},

	{36, ML_CODE_DIV, setCodeLD_3op_in, setInput2DIn_Val16div_off, verifyResultValueDWord,
			"Division off op3=op1/op2", 1, 0},
	{37, ML_CODE_DIV, setCodeLD_3op_in, setInput2DIn_Val16div_on, verifyResultValueDWord,
			"Division on op3=op1/op2", 1, 48627716}, // D[+1]=742, D[]=4
	{38, ML_CODE_DIV, setCodeLD_3op_out, setInput1DIn_Val16div_off, verifyResultValueDWord,
			"Division off op3=op1/op2", 1, 0},
	{39, ML_CODE_DIV, setCodeLD_3op_out, setInput1DIn_Val16div_on, verifyResultValueDWord,
			"Division on op3=op1/op2", 1, 48627716},
	{40, ML_CODE_DIV, setCodeOp_N1_W, setInput2DIn_Val16div_N1W_off, verifyResultValueDWord,
			"Division off op3=nop1/op2", 1, 0},
	{41, ML_CODE_DIV, setCodeOp_N1_W, setInput2DIn_Val16div_N1W_on, verifyResultValueDWord,
			"Division on op3=nop1/op2", 1, 48627716}, // D[+1]=742, D[]=4
	{42, ML_CODE_DIV, setCodeOp_WN2_W, setInput2DIn_Val16div_WN2_off, verifyResultValueDWord,
			"Division off op3=op1/nop2", 1, 0},
	{43, ML_CODE_DIV, setCodeOp_WN2_W, setInput2DIn_Val16div_WN2_on, verifyResultValueDWord,
			"Division on op3=op1/nop2", 1, 48627716}, // D[+1]=742, D[]=4
	{44, ML_CODE_DIV, setCodeLD_K_2op, setInputSIn_Val16_in_off, verifyResultValueDWord,
			"Division off op2=K/op1", 1, 0},
	{45, ML_CODE_DIV, setCodeLD_K_2op, setInputSIn_Val16_in_on, verifyResultValueDWord,
			"Division on op2=K/op1", 1, 80871424}, //D[+1]=1234, D[]=0
	{46, ML_CODE_DIV, setCodeOp_KN2_W, setInput2DIn_Val16_KN2_off, verifyResultValueDWord,
			"Division off op2=K/nop1", 1, 0},
	{47, ML_CODE_DIV, setCodeOp_KN2_W, setInput2DIn_Val16_KN2_on, verifyResultValueDWord,
			"Division on op2=K/nop1", 1, 80871424}, //D[+1]=1234, D[]=0
	{48, ML_CODE_DIV, setCodeLD_WK2_W, setInputSIn_Val16_WK2_off, verifyResultValueDWord,
			"Division off op2=op1/K", 1, 0},
	{49, ML_CODE_DIV, setCodeLD_WK2_W, setInputSIn_Val16_WK2_on, verifyResultValueDWord,
			"Division on op2=op1/K", 1, 80871424}, //D[+1]=1234, D[]=0
	{50, ML_CODE_DIV, setCodeOp_N1K_W, setInput2DIn_Val16_N1K_off, verifyResultValueDWord,
			"Division off op2=nop1/K", 1, 0},
	{51, ML_CODE_DIV, setCodeOp_N1K_W, setInput2DIn_Val16_N1K_on, verifyResultValueDWord,
			"Division on op2=nop1/K", 1, 80871424}, //D[+1]=1234, D[]=0
	{52, ML_CODE_DIV, setCodeLD_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"Division off op1=K/K", 1, 0},
	{53, ML_CODE_DIV, setCodeLD_2K_1op, setInputNIn_Val16_on, verifyResultValueDWord,
			"Division on op1=K/K", 1, 48627716}, // D[+1]=742, D[]=4

	{54, ML_CODE_DIVP, setCodeLD_3op_in, setInput2DIn_Val16div_off, verifyResultValueDWord,
			"DivisionP 0->0 op3=op1/op2", 2, 0},
	{55, ML_CODE_DIVP, setCodeLD_3op_in, setInput2DIn_Val16divp_on, verifyResultValueDWord,
			"DivisionP 0->1 op3=op1/op2", 2, 48627716}, // D[+1]=742, D[]=4
	{56, ML_CODE_DIVP, setCodeLD_3op_out, setInput1DIn_Val16div_off, verifyResultValueDWord,
			"DivisionP 0->0 op3=op1/op2", 2, 0},
	{57, ML_CODE_DIVP, setCodeLD_3op_out, setInput1DIn_Val16divp_on, verifyResultValueDWord,
			"DivisionP 0->1 op3=op1/op2", 2, 48627716},
	{58, ML_CODE_DIVP, setCodeOp_N1_W, setInput2DIn_Val16div_N1W_off, verifyResultValueDWord,
			"DivisionP 0->0 op3=nop1/op2", 2, 0},
	{59, ML_CODE_DIVP, setCodeOp_N1_W, setInput2DIn_Val16divp_N1W_on, verifyResultValueDWord,
			"DivisionP 0->1 op3=nop1/op2", 2, 48627716}, // D[+1]=742, D[]=4
	{60, ML_CODE_DIVP, setCodeOp_WN2_W, setInput2DIn_Val16div_WN2_off, verifyResultValueDWord,
			"DivisionP 0->0 op3=op1/nop2", 2, 0},
	{61, ML_CODE_DIVP, setCodeOp_WN2_W, setInput2DIn_Val16divp_WN2_on, verifyResultValueDWord,
			"DivisionP 0->1 op3=op1/nop2", 2, 48627716}, // D[+1]=742, D[]=4
	{62, ML_CODE_DIVP, setCodeLD_K_2op, setInputSIn_Val16_in_off, verifyResultValueDWord,
			"DivisionP 0->0 op2=K/op1", 2, 0},
	{63, ML_CODE_DIVP, setCodeLD_K_2op, setInputSIn_Val16p_in_on, verifyResultValueDWord,
			"DivisionP 0->1 op2=K/op1", 2, 80871424}, //D[+1]=1234, D[]=0
	{64, ML_CODE_DIVP, setCodeOp_KN2_W, setInput2DIn_Val16_KN2_off, verifyResultValueDWord,
			"DivisionP 0->0 op2=K/nop1", 2, 0},
	{65, ML_CODE_DIVP, setCodeOp_KN2_W, setInput2DIn_Val16p_KN2_on, verifyResultValueDWord,
			"DivisionP 0->1 op2=K/nop1", 2, 80871424}, //D[+1]=1234, D[]=0
	{66, ML_CODE_DIVP, setCodeLD_WK2_W, setInputSIn_Val16_WK2_off, verifyResultValueDWord,
			"DivisionP 0->0 op2=op1/K", 2, 0},
	{67, ML_CODE_DIVP, setCodeLD_WK2_W, setInputSIn_Val16p_WK2_on, verifyResultValueDWord,
			"DivisionP 0->1 op2=op1/K", 2, 80871424}, //D[+1]=1234, D[]=0
	{68, ML_CODE_DIVP, setCodeOp_N1K_W, setInput2DIn_Val16_N1K_off, verifyResultValueDWord,
			"DivisionP 0->0 op2=nop1/K", 2, 0},
	{69, ML_CODE_DIVP, setCodeOp_N1K_W, setInput2DIn_Val16p_N1K_on, verifyResultValueDWord,
			"DivisionP 0->1 op2=nop1/K", 2, 80871424}, //D[+1]=1234, D[]=0
	{70, ML_CODE_DIVP, setCodeLD_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"DivisionP 0->0 op1=K/K", 2, 0},
	{71, ML_CODE_DIVP, setCodeLD_2K_1op, setInputNIn_Val16p_on, verifyResultValueDWord,
			"DivisionP 0->1 op1=K/K", 2, 48627716}, // D[+1]=742, D[]=4

	{72, ML_CODE_BMLT, setCodeLD_3op_in, setInputDIn_BCD_mlt_in_off, verifyResultValueDWord,
			"BCD* off op3=op1*op2", 1, 0},
	{73, ML_CODE_BMLT, setCodeLD_3op_in, setInputDIn_BCD_mlt_in_on, verifyResultValueDWord,
			"BCD* on op3=op1*op2", 1, 77019432}, //0x4973928
	{74, ML_CODE_BMLT, setCodeLD_3op_out, setInput1DIn_BCD_mlt_off, verifyResultValueDWord,
			"BCD* off op3=op1*op2", 1, 0},
	{75, ML_CODE_BMLT, setCodeLD_3op_out, setInput1DIn_BCD_mlt_on, verifyResultValueDWord,
			"BCD* on op3=op1*op2", 1, 77019432}, //0x4973928
	{76, ML_CODE_BMLT, setCodeOp_N1_W, setInput2DIn_Val16_N1BCD4_off, verifyResultValueDWord,
			"BCD* off op3=nop1*op2", 1, 0},
	{77, ML_CODE_BMLT, setCodeOp_N1_W, setInput2DIn_Val16_N1BCD4_on, verifyResultValueDWord,
			"BCD* on op3=nop1*op2", 1, 77019432}, //0x4973928
	{78, ML_CODE_BMLT, setCodeOp_WN2_W, setInput2DIn_Val16_BCD4N2_off, verifyResultValueDWord,
			"BCD* off op3=op1*nop2", 1, 0},
	{79, ML_CODE_BMLT, setCodeOp_WN2_W, setInput2DIn_Val16_BCD4N2_on, verifyResultValueDWord,
			"BCD* on op3=op1*nop2", 1, 77019432}, //0x4973928
	{80, ML_CODE_BMLT, setCodeLD_BCD_mlt_K1BCD4_2op, setInputIn_BCD_mlt_off, verifyResultValueDWord,
			"BCD* off op2=K*op1", 1, 0},
	{81, ML_CODE_BMLT, setCodeLD_BCD_mlt_K1BCD4_2op, setInputIn_BCD_mlt_on, verifyResultValueDWord,
			"BCD* on op2=K*op1", 1, 77019432}, //0x4973928
	{82, ML_CODE_BMLT, setCodeLD_BCD_mlt_K1N2_2op, setInput2DIn_Val16_BCD_KN2_off, verifyResultValueDWord,
			"BCD* off op2=K*nop1", 1, 0},
	{83, ML_CODE_BMLT, setCodeLD_BCD_mlt_K1N2_2op, setInput2DIn_Val16_BCD_KN2_on, verifyResultValueDWord,
			"BCD* on op2=K*nop1", 1, 77019432}, //0x4973928
	{84, ML_CODE_BMLT, setCodeLD_BCD4K2_W, setInputSIn_Val16_BCD4K2_off, verifyResultValueDWord,
			"BCD* off op2=op1*K", 1, 0},
	{85, ML_CODE_BMLT, setCodeLD_BCD4K2_W, setInputSIn_Val16_BCD4K2_on, verifyResultValueDWord,
			"BCD* on op2=op1*K", 1, 77019432}, //0x4973928
	{86, ML_CODE_BMLT, setCodeLD_BCD_N1K2_W, setInput2DIn_Val16_BCD_N1K2_off, verifyResultValueDWord,
			"BCD* off op2=nop1*K", 1, 0},
	{87, ML_CODE_BMLT, setCodeLD_BCD_N1K2_W, setInput2DIn_Val16_BCD_N1K2_on, verifyResultValueDWord,
			"BCD* on op2=nop1*K", 1, 77019432}, //0x4973928
	{88, ML_CODE_BMLT, setCodeLD_BCD_mlt_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"BCD* off op1=K*K", 1, 0},
	{89, ML_CODE_BMLT, setCodeLD_BCD_mlt_2K_1op, setInputNIn_Val16_on, verifyResultValueDWord,
			"BCD* on op1=K*K", 1, 77019432}, //0x4973928

	{90, ML_CODE_BMLTP, setCodeLD_3op_in, setInputDIn_BCD_mlt_in_off, verifyResultValueDWord,
			"BCD*P 0->0 op3=op1*op2", 2, 0},
	{91, ML_CODE_BMLTP, setCodeLD_3op_in, setInputDIn_BCDp_mlt_in_on, verifyResultValueDWord,
			"BCD*P 0->1 op3=op1*op2", 2, 77019432}, //0x4973928
	{92, ML_CODE_BMLTP, setCodeLD_3op_out, setInput1DIn_BCD_mlt_off, verifyResultValueDWord,
			"BCD*P 0->0 op3=op1*op2", 2, 0},
	{93, ML_CODE_BMLTP, setCodeLD_3op_out, setInput1DIn_BCDp_mlt_on, verifyResultValueDWord,
			"BCD*P 0->1 op3=op1*op2", 2, 77019432}, //0x4973928
	{94, ML_CODE_BMLTP, setCodeOp_N1_W, setInput2DIn_Val16_N1BCD4_off, verifyResultValueDWord,
			"BCD*P 0->0 op3=nop1*op2", 2, 0},
	{95, ML_CODE_BMLTP, setCodeOp_N1_W, setInput2DIn_Val16p_N1BCD4_on, verifyResultValueDWord,
			"BCD*P 0->1 op3=nop1*op2", 2, 77019432}, //0x4973928
	{96, ML_CODE_BMLTP, setCodeOp_WN2_W, setInput2DIn_Val16_BCD4N2_off, verifyResultValueDWord,
			"BCD*P 0->0 op3=op1*nop2", 2, 0},
	{97, ML_CODE_BMLTP, setCodeOp_WN2_W, setInput2DIn_Val16p_BCD4N2_on, verifyResultValueDWord,
			"BCD*P 0->1 op3=op1*nop2", 2, 77019432}, //0x4973928
	{98, ML_CODE_BMLTP, setCodeLD_BCD_mlt_K1BCD4_2op, setInputIn_BCD_mlt_off, verifyResultValueDWord,
			"BCD*P 0->0 op2=K*op1", 1, 0},
	{99, ML_CODE_BMLTP, setCodeLD_BCD_mlt_K1BCD4_2op, setInputIn_BCDp_mlt_on, verifyResultValueDWord,
			"BCD*P 0->1 op2=K*op1", 2, 77019432}, //0x4973928
	{100, ML_CODE_BMLTP, setCodeLD_BCD_mlt_K1N2_2op, setInput2DIn_Val16_BCD_KN2_off, verifyResultValueDWord,
			"BCD*P 0->0 op2=K*nop1", 2, 0},
	{101, ML_CODE_BMLTP, setCodeLD_BCD_mlt_K1N2_2op, setInput2DIn_Val16p_BCD_KN2_on, verifyResultValueDWord,
			"BCD*P 0->1 op2=K*nop1", 2, 77019432}, //0x4973928
	{102, ML_CODE_BMLTP, setCodeLD_BCD4K2_W, setInputSIn_Val16_BCD4K2_off, verifyResultValueDWord,
			"BCD*P 0->0 op2=op1*K", 2, 0},
	{103, ML_CODE_BMLTP, setCodeLD_BCD4K2_W, setInputSIn_Val16p_BCD4K2_on, verifyResultValueDWord,
			"BCD*P 0->1 op2=op1*K", 2, 77019432}, //0x4973928
	{104, ML_CODE_BMLTP, setCodeLD_BCD_N1K2_W, setInput2DIn_Val16_BCD_N1K2_off, verifyResultValueDWord,
			"BCD*P 0->0 op2=nop1*K", 2, 0},
	{105, ML_CODE_BMLTP, setCodeLD_BCD_N1K2_W, setInput2DIn_Val16p_BCD_N1K2_on, verifyResultValueDWord,
			"BCD*P 0->1 op2=nop1*K", 2, 77019432}, //0x4973928
	{106, ML_CODE_BMLTP, setCodeLD_BCD_mlt_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"BCD*P 0->0 op1=K*K", 2, 0},
	{107, ML_CODE_BMLTP, setCodeLD_BCD_mlt_2K_1op, setInputNIn_Val16p_on, verifyResultValueDWord,
			"BCD*P 0->1 op1=K*K", 2, 77019432}, //0x4973928

	{108, ML_CODE_BDIV, setCodeLD_3op_in, setInputDIn_BCD_mlt_in_off, verifyResultValueDWord,
			"BCD/ off op3=op1/op2", 1, 0},
	{109, ML_CODE_BDIV, setCodeLD_3op_in, setInputDIn_BCD_mlt_in_on, verifyResultValueDWord,
			"BCD/ on op3=op1/op2", 1, 69337094}, //D[+1]=0x422 D[]=0x6
	{110, ML_CODE_BDIV, setCodeLD_3op_out, setInput1DIn_BCD_mlt_off, verifyResultValueDWord,
			"BCD/ off op3=op1/op2", 1, 0},
	{111, ML_CODE_BDIV, setCodeLD_3op_out, setInput1DIn_BCD_mlt_on, verifyResultValueDWord,
			"BCD/ on op3=op1/op2", 1, 69337094}, //D[+1]=0x422 D[]=0x6
	{112, ML_CODE_BDIV, setCodeOp_N1_W, setInput2DIn_Val16_N1BCD4_off, verifyResultValueDWord,
			"BCD/ off op3=nop1/op2", 1, 0},
	{113, ML_CODE_BDIV, setCodeOp_N1_W, setInput2DIn_Val16_N1BCD4_on, verifyResultValueDWord,
			"BCD/ on op3=nop1/op2", 1, 69337094}, //D[+1]=0x422 D[]=0x6
	{114, ML_CODE_BDIV, setCodeOp_WN2_W, setInput2DIn_Val16_BCD4N2_off, verifyResultValueDWord,
			"BCD/ off op3=op1/nop2", 1, 0},
	{115, ML_CODE_BDIV, setCodeOp_WN2_W, setInput2DIn_Val16_BCD4N2_on, verifyResultValueDWord,
			"BCD/ on op3=op1/nop2", 1, 69337094}, //D[+1]=0x422 D[]=0x6
	{116, ML_CODE_BDIV, setCodeLD_BCD_mlt_K1BCD4_2op, setInputIn_BCD_mlt_off, verifyResultValueDWord,
			"BCD/ off op2=K/op1", 1, 0},
	{117, ML_CODE_BDIV, setCodeLD_BCD_mlt_K1BCD4_2op, setInputIn_BCD_mlt_on, verifyResultValueDWord,
			"BCD/ on op2=K/op1", 1, 69337094}, //D[+1]=0x422 D[]=0x6
	{118, ML_CODE_BDIV, setCodeLD_BCD_mlt_K1N2_2op, setInput2DIn_Val16_BCD_KN2_off, verifyResultValueDWord,
			"BCD/ off op2=K/nop1", 1, 0},
	{119, ML_CODE_BDIV, setCodeLD_BCD_mlt_K1N2_2op, setInput2DIn_Val16_BCD_KN2_on, verifyResultValueDWord,
			"BCD/ on op2=K/nop1", 1, 69337094}, //D[+1]=0x422 D[]=0x6
	{120, ML_CODE_BDIV, setCodeLD_BCD4K2_W, setInputSIn_Val16_BCD4K2_off, verifyResultValueDWord,
			"BCD/ off op2=op1/K", 1, 0},
	{121, ML_CODE_BDIV, setCodeLD_BCD4K2_W, setInputSIn_Val16_BCD4K2_on, verifyResultValueDWord,
			"BCD/ on op2=op1/K", 1, 69337094}, //D[+1]=0x422 D[]=0x6
	{122, ML_CODE_BDIV, setCodeLD_BCD_N1K2_W, setInput2DIn_Val16_BCD_N1K2_off, verifyResultValueDWord,
			"BCD/ off op2=nop1/K", 1, 0},
	{123, ML_CODE_BDIV, setCodeLD_BCD_N1K2_W, setInput2DIn_Val16_BCD_N1K2_on, verifyResultValueDWord,
			"BCD/ on op2=nop1/K", 1, 69337094}, //D[+1]=0x422 D[]=0x6
	{124, ML_CODE_BDIV, setCodeLD_BCD_mlt_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"BCD/ off op1=K/K", 1, 0},
	{125, ML_CODE_BDIV, setCodeLD_BCD_mlt_2K_1op, setInputNIn_Val16_on, verifyResultValueDWord,
			"BCD/ on op1=K/K", 1, 69337094}, //D[+1]=0x422 D[]=0x6

	{126, ML_CODE_BDIVP, setCodeLD_3op_in, setInputDIn_BCD_mlt_in_off, verifyResultValueDWord,
			"BCD/P off op3=op1/op2", 2, 0},
	{127, ML_CODE_BDIVP, setCodeLD_3op_in, setInputDIn_BCDp_mlt_in_on, verifyResultValueDWord,
			"BCD/P on op3=op1/op2", 2, 69337094}, //D[+1]=0x422 D[]=0x6
	{128, ML_CODE_BDIVP, setCodeLD_3op_out, setInput1DIn_BCD_mlt_off, verifyResultValueDWord,
			"BCD/P off op3=op1/op2", 2, 0},
	{129, ML_CODE_BDIVP, setCodeLD_3op_out, setInput1DIn_BCDp_mlt_on, verifyResultValueDWord,
			"BCD/P on op3=op1/op2", 2, 69337094}, //D[+1]=0x422 D[]=0x6
	{130, ML_CODE_BDIVP, setCodeOp_N1_W, setInput2DIn_Val16_N1BCD4_off, verifyResultValueDWord,
			"BCD/P off op3=nop1/op2", 2, 0},
	{131, ML_CODE_BDIVP, setCodeOp_N1_W, setInput2DIn_Val16p_N1BCD4_on, verifyResultValueDWord,
			"BCD/P on op3=nop1/op2", 2, 69337094}, //D[+1]=0x422 D[]=0x6
	{132, ML_CODE_BDIVP, setCodeOp_WN2_W, setInput2DIn_Val16_BCD4N2_off, verifyResultValueDWord,
			"BCD/P off op3=op1/nop2", 2, 0},
	{133, ML_CODE_BDIVP, setCodeOp_WN2_W, setInput2DIn_Val16p_BCD4N2_on, verifyResultValueDWord,
			"BCD/P on op3=op1/nop2", 2, 69337094}, //D[+1]=0x422 D[]=0x6
	{134, ML_CODE_BDIVP, setCodeLD_BCD_mlt_K1BCD4_2op, setInputIn_BCD_mlt_off, verifyResultValueDWord,
			"BCD/P off op2=K/op1", 2, 0},
	{135, ML_CODE_BDIVP, setCodeLD_BCD_mlt_K1BCD4_2op, setInputIn_BCDp_mlt_on, verifyResultValueDWord,
			"BCD/P on op2=K/op1", 2, 69337094}, //D[+1]=0x422 D[]=0x6
	{136, ML_CODE_BDIVP, setCodeLD_BCD_mlt_K1N2_2op, setInput2DIn_Val16_BCD_KN2_off, verifyResultValueDWord,
			"BCD/P off op2=K/nop1", 2, 0},
	{137, ML_CODE_BDIVP, setCodeLD_BCD_mlt_K1N2_2op, setInput2DIn_Val16p_BCD_KN2_on, verifyResultValueDWord,
			"BCD/P on op2=K/nop1", 2, 69337094}, //D[+1]=0x422 D[]=0x6
	{138, ML_CODE_BDIVP, setCodeLD_BCD4K2_W, setInputSIn_Val16_BCD4K2_off, verifyResultValueDWord,
			"BCD/P off op2=op1/K", 2, 0},
	{139, ML_CODE_BDIVP, setCodeLD_BCD4K2_W, setInputSIn_Val16p_BCD4K2_on, verifyResultValueDWord,
			"BCD/P on op2=op1/K", 2, 69337094}, //D[+1]=0x422 D[]=0x6
	{140, ML_CODE_BDIVP, setCodeLD_BCD_N1K2_W, setInput2DIn_Val16_BCD_N1K2_off, verifyResultValueDWord,
			"BCD/P off op2=nop1/K", 2, 0},
	{141, ML_CODE_BDIVP, setCodeLD_BCD_N1K2_W, setInput2DIn_Val16p_BCD_N1K2_on, verifyResultValueDWord,
			"BCD/P on op2=nop1/K", 2, 69337094}, //D[+1]=0x422 D[]=0x6
	{142, ML_CODE_BDIVP, setCodeLD_BCD_mlt_2K_1op, setInputNIn_Val16_off, verifyResultValueDWord,
			"BCD/P off op1=K/K", 2, 0},
	{143, ML_CODE_BDIVP, setCodeLD_BCD_mlt_2K_1op, setInputNIn_Val16p_on, verifyResultValueDWord,
			"BCD/P on op1=K/K", 2, 69337094}, //D[+1]=0x422 D[]=0x6

	{-1, 0xFFFF, NULL, NULL, NULL, " ", 0, 0 }
};


int total_basic_compute_word_mul_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_word_mul_test_number; i++)
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

int setCodeOp_WN2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
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

int setCodeOp_KN2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 1234); addMLOperandNibble(4, in_reg, in_pos);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_N1K_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_K, 5678);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_WK2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos);  addMLOperand(OPERAND_ML_CODE_K, 5678);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD4K2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos);  addMLOperand(OPERAND_ML_CODE_K, 0x876);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD_N1K2_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos);  addMLOperand(OPERAND_ML_CODE_K, 0x876);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD_mlt_K1BCD4_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x5678);
		addMLOperand(in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD_mlt_K1N2_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x5678);
		addMLOperandNibble(4, in_reg, in_pos); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD_mlt_BCD4K2_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_K, 0x5678);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_BCD_mlt_2K_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x5678);
		addMLOperand(OPERAND_ML_CODE_K, 0x876); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput2DIn_Val16div_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 5678);
	addDeviceControlInstruction(0, (uint8)in, 160, 1234);

	TestCodeTearDown();
}

void setInput2DIn_Val16div_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 5678);
	addDeviceControlInstruction(0, (uint8)in, 160, 1234);

	TestCodeTearDown();
}

void setInput2DIn_Val16divp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 5678);
	addDeviceControlInstruction(0, (uint8)in, 160, 1234);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);


	TestCodeTearDown();
}

void setInput1DIn_Val16div_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 5678);
	addDeviceControlInstruction(0, (uint8)out, 160, 1234);

	TestCodeTearDown();
}

void setInput1DIn_Val16div_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 5678);
	addDeviceControlInstruction(0, (uint8)out, 160, 1234);

	TestCodeTearDown();
}

void setInput1DIn_Val16divp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 5678);
	addDeviceControlInstruction(0, (uint8)out, 160, 1234);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput2DIn_Val16div_N1W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 1234);

	TestCodeTearDown();
}

void setInput2DIn_Val16div_N1W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 1234);

	TestCodeTearDown();
}

void setInput2DIn_Val16divp_N1W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 1234);

	TestCodeTearDown();
}

void setInput2DIn_Val16div_WN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 5678);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16div_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 5678);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16divp_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 5678);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16_WK2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);

	TestCodeTearDown();
}

void setInputSIn_Val16_WK2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);

	TestCodeTearDown();
}

void setInputSIn_Val16p_WK2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);

	TestCodeTearDown();
}

void setInput2DIn_Val16_N1K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_N1K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16p_N1K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16p_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCD_mlt_in_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)in, 160, 0x876);

	TestCodeTearDown();
}

void setInputDIn_BCD_mlt_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)in, 160, 0x876);

	TestCodeTearDown();
}

void setInputDIn_BCDp_mlt_in_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)in, 160, 0x876);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput1DIn_BCD_mlt_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)out, 160, 0x876);

	TestCodeTearDown();
}

void setInput1DIn_BCD_mlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)out, 160, 0x876);

	TestCodeTearDown();
}

void setInput1DIn_BCDp_mlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);
	addDeviceControlInstruction(0, (uint8)out, 160, 0x876);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputIn_BCD_mlt_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x876);

	TestCodeTearDown();
}

void setInputIn_BCD_mlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x876);

	TestCodeTearDown();
}

void setInputIn_BCDp_mlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x876);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInput2DIn_Val16_N1BCD4_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 0x876);

	TestCodeTearDown();
}

void setInput2DIn_Val16_N1BCD4_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 0x876);

	TestCodeTearDown();
}

void setInput2DIn_Val16p_N1BCD4_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, 0x876);

	TestCodeTearDown();
}

void setInput2DIn_Val16_BCD4N2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 0x5678);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_BCD4N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 0x5678);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16p_BCD4N2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)out, in_pos, 0x5678);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_BCD_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_BCD_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16p_BCD_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_BCD_N1K2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_BCD_N1K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16p_BCD_N1K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, value=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16_BCD4K2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);

	TestCodeTearDown();
}

void setInputSIn_Val16_BCD4K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);

	TestCodeTearDown();
}

void setInputSIn_Val16p_BCD4K2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x5678);

	TestCodeTearDown();
}

static uint16 getPos(int reg, int inx_pos)
{
	//uint16 pos[3][2]={ {0,0}, {6144,4096}, {12287,8191}};
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12286,8190}}; //16bit

	return pos[inx_pos][reg];
}


static FILE *flog;
void test_basic_arithmetic_multi(int tno, uint16 dummy)
{
	int i, rc=0, rc2=1, olast=0, res_dword;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
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

					rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if(rc2 == 0)
					{
						//DBG_LOGPRINT("SKIP by ML code in=%d in_pos=%d out=%d out_pos=%d\n", \
							in, in_pos, out, out_pos);
						continue;
					}

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

void testBasicArithmeticMulCommand(void)
{
	int i, index=15;
	int start, end;
	char log[] = "err_arith_mul_div.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic mul_div LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=48;index<54;index++)
		test_basic_arithmetic_multi(index, 0);
#else
	total_basic_compute_word_mul_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_MLT); //ML_CODE_MLT
	end = getTestCaseNumberEnd(ML_CODE_BDIVP); //ML_CODE_BDIVP

	DBG_LOGPRINT("testBasicArithmeticMulCommand: %d to %d total %d\n", start, end, total_basic_compute_word_mul_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_multi(index, 0);
	}
#endif
	fclose(flog);
}
#endif
