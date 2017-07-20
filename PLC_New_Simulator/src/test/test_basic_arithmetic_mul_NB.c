/*
 * test_basic_arithmetic_mul_NB.c
 *
 *  Created on: Aug 26, 2015
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


extern void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected);

int setCodeOp3_WW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_NW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_WN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_KW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_KN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_WK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_NK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_KK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_NN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_BKW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_BKN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);;
int setCodeOp3_WBK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_NBK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_BKK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInput2DIn_Val16_WW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_WW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_WW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_NW2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_NW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_NW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_WN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_Val16p_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_WK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_WK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_WK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_KW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_KW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_KW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_NK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_NK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_NK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_Val16p_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_NN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16_NN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_Val16p_NN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInput2DIn_BCD4_WW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD4_WW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD4p_WW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD4_NW2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD4_NW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD4p_NW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD4_WN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD4_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD4p_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4_KW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4_KW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4p_KW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4p_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4_WK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4_WK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4p_WK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4_NK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4_NK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD4p_NK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD4_NN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD4_NN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_BCD4p_NN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

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
	{0, ML_CODE_MLT, setCodeOp3_WW_DN, setInput2DIn_Val16_WW_off, verifyResultValueNibble8,
			"Multiply off nop3=op1*op2", 1, 0},
	{1, ML_CODE_MLT, setCodeOp3_WW_DN, setInput2DIn_Val16_WW_on, verifyResultValueNibble8,
			"Multiply on nop3=op1*op2", 1, 7006652},
	{2, ML_CODE_MLT, setCodeOp3_NW_DN, setInput2DIn_Val16_NW2_off, verifyResultValueNibble8,
			"Multiply off nop3=nop1*op2", 1, 0},
	{3, ML_CODE_MLT, setCodeOp3_NW_DN, setInput2DIn_Val16_NW2_on, verifyResultValueNibble8,
			"Multiply on nop3=nop1*op2", 1, 7006652},
	{4, ML_CODE_MLT, setCodeOp3_WN_DN, setInput2DIn_Val16_WN2_off, verifyResultValueNibble8,
			"Multiply off nop3=nop1*op2", 1, 0},
	{5, ML_CODE_MLT, setCodeOp3_WN_DN, setInput2DIn_Val16_WN2_on, verifyResultValueNibble8,
			"Multiply on nop3=nop1*op2", 1, 7006652},
	{6, ML_CODE_MLT, setCodeOp3_KW_DN, setInputSIn_Val16_KW_off, verifyResultValueNibble8,
			"Multiply off nop3=op1*op2", 1, 0},
	{7, ML_CODE_MLT, setCodeOp3_KW_DN, setInputSIn_Val16_KW_on, verifyResultValueNibble8,
			"Multiply on nop3=op1*op2", 1, 7006652},
	{8, ML_CODE_MLT, setCodeOp3_KN_DN, setInputSIn_Val16_KN2_off, verifyResultValueNibble8,
			"Multiply off nop3=nop1*op2", 1, 0},
	{9, ML_CODE_MLT, setCodeOp3_KN_DN, setInputSIn_Val16_KN2_on, verifyResultValueNibble8,
			"Multiply on nop3=nop1*op2", 1, 7006652},
	{10, ML_CODE_MLT, setCodeOp3_WK_DN, setInputSIn_Val16_WK_off, verifyResultValueNibble8,
			"Multiply off nop3=nop1*op2", 1, 0},
	{11, ML_CODE_MLT, setCodeOp3_WK_DN, setInputSIn_Val16_WK_on, verifyResultValueNibble8,
			"Multiply on nop3=nop1*op2", 1, 7006652},
	{12, ML_CODE_MLT, setCodeOp3_NK_DN, setInputSIn_Val16_NK_off, verifyResultValueNibble8,
			"Multiply off nop3=nop1*op2", 1, 0},
	{13, ML_CODE_MLT, setCodeOp3_NK_DN, setInputSIn_Val16_NK_on, verifyResultValueNibble8,
			"Multiply on nop3=nop1*op2", 1, 7006652},
	{14, ML_CODE_MLT, setCodeOp3_KK_DN, setInputNIn_Val16_off, verifyResultValueNibble8,
			"Multiply off nop3=nop1*op2", 1, 0},
	{15, ML_CODE_MLT, setCodeOp3_KK_DN, setInputNIn_Val16_on, verifyResultValueNibble8,
			"Multiply on nop3=nop1*op2", 1, 7006652},
	{16, ML_CODE_MLT, setCodeOp3_NN_DN, setInputDIn_Val16_NN2_off, verifyResultValueNibble8,
			"Multiply off nop3=nop1*op2", 1, 0},
	{17, ML_CODE_MLT, setCodeOp3_NN_DN, setInputDIn_Val16_NN2_on, verifyResultValueNibble8,
			"Multiply on nop3=nop1*op2", 1, 7006652},

	{18, ML_CODE_MLTP, setCodeOp3_WW_DN, setInput2DIn_Val16_WW_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=op1*op2", 2, 0},
	{19, ML_CODE_MLTP, setCodeOp3_WW_DN, setInput2DIn_Val16p_WW_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=op1*op2", 2, 7006652},
	{20, ML_CODE_MLTP, setCodeOp3_NW_DN, setInput2DIn_Val16_NW2_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=nop1*op2", 2, 0},
	{21, ML_CODE_MLTP, setCodeOp3_NW_DN, setInput2DIn_Val16p_NW2_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=nop1*op2", 2, 7006652},
	{22, ML_CODE_MLTP, setCodeOp3_WN_DN, setInput2DIn_Val16_WN2_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=nop1*op2", 2, 0},
	{23, ML_CODE_MLTP, setCodeOp3_WN_DN, setInput2DIn_Val16p_WN2_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=nop1*op2", 2, 7006652},
	{24, ML_CODE_MLTP, setCodeOp3_KW_DN, setInputSIn_Val16_KW_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=op1*op2", 2, 0},
	{25, ML_CODE_MLTP, setCodeOp3_KW_DN, setInputSIn_Val16p_KW_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=op1*op2", 2, 7006652},
	{26, ML_CODE_MLTP, setCodeOp3_KN_DN, setInputSIn_Val16_KN2_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=nop1*op2", 2, 0},
	{27, ML_CODE_MLTP, setCodeOp3_KN_DN, setInputSIn_Val16p_KN2_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=nop1*op2", 2, 7006652},
	{28, ML_CODE_MLTP, setCodeOp3_WK_DN, setInputSIn_Val16_WK_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=nop1*op2", 2, 0},
	{29, ML_CODE_MLTP, setCodeOp3_WK_DN, setInputSIn_Val16p_WK_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=nop1*op2", 2, 7006652},
	{30, ML_CODE_MLTP, setCodeOp3_NK_DN, setInputSIn_Val16_NK_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=nop1*op2", 2, 0},
	{31, ML_CODE_MLTP, setCodeOp3_NK_DN, setInputSIn_Val16p_NK_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=nop1*op2", 2, 7006652},
	{32, ML_CODE_MLTP, setCodeOp3_KK_DN, setInputNIn_Val16_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=nop1*op2", 2, 0},
	{33, ML_CODE_MLTP, setCodeOp3_KK_DN, setInputNIn_Val16p_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=nop1*op2", 2, 7006652},
	{34, ML_CODE_MLTP, setCodeOp3_NN_DN, setInputDIn_Val16_NN2_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=nop1*op2", 2, 0},
	{35, ML_CODE_MLTP, setCodeOp3_NN_DN, setInputDIn_Val16p_NN2_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=nop1*op2", 2, 7006652},

	{36, ML_CODE_DIV, setCodeOp3_WW_DN, setInput2DIn_Val16_WW_off, verifyResultValueNibble8,
			"DIV off nop3=op1/op2", 1, 0},
	{37, ML_CODE_DIV, setCodeOp3_WW_DN, setInput2DIn_Val16_WW_on, verifyResultValueNibble8,
			"DIV on nop3=op1/op2", 1, 48627716},
	{38, ML_CODE_DIV, setCodeOp3_NW_DN, setInput2DIn_Val16_NW2_off, verifyResultValueNibble8,
			"DIV off nop3=nop1/op2", 1, 0},
	{39, ML_CODE_DIV, setCodeOp3_NW_DN, setInput2DIn_Val16_NW2_on, verifyResultValueNibble8,
			"DIV on nop3=nop1/op2", 1, 48627716},
	{40, ML_CODE_DIV, setCodeOp3_WN_DN, setInput2DIn_Val16_WN2_off, verifyResultValueNibble8,
			"DIV off nop3=nop1/op2", 1, 0},
	{41, ML_CODE_DIV, setCodeOp3_WN_DN, setInput2DIn_Val16_WN2_on, verifyResultValueNibble8,
			"DIV on nop3=nop1/op2", 1, 48627716},
	{42, ML_CODE_DIV, setCodeOp3_KW_DN, setInputSIn_Val16_KW_off, verifyResultValueNibble8,
			"DIV off nop3=op1/op2", 1, 0},
	{43, ML_CODE_DIV, setCodeOp3_KW_DN, setInputSIn_Val16_KW_on, verifyResultValueNibble8,
			"DIV on nop3=op1/op2", 1, 48627716},
	{44, ML_CODE_DIV, setCodeOp3_KN_DN, setInputSIn_Val16_KN2_off, verifyResultValueNibble8,
			"DIV off nop3=nop1/op2", 1, 0},
	{45, ML_CODE_DIV, setCodeOp3_KN_DN, setInputSIn_Val16_KN2_on, verifyResultValueNibble8,
			"DIV on nop3=nop1/op2", 1, 48627716},
	{46, ML_CODE_DIV, setCodeOp3_WK_DN, setInputSIn_Val16_WK_off, verifyResultValueNibble8,
			"DIV off nop3=nop1/op2", 1, 0},
	{47, ML_CODE_DIV, setCodeOp3_WK_DN, setInputSIn_Val16_WK_on, verifyResultValueNibble8,
			"DIV on nop3=nop1/op2", 1, 48627716},
	{48, ML_CODE_DIV, setCodeOp3_NK_DN, setInputSIn_Val16_NK_off, verifyResultValueNibble8,
			"DIV off nop3=nop1/op2", 1, 0},
	{49, ML_CODE_DIV, setCodeOp3_NK_DN, setInputSIn_Val16_NK_on, verifyResultValueNibble8,
			"DIV on nop3=nop1/op2", 1, 48627716},
	{50, ML_CODE_DIV, setCodeOp3_KK_DN, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DIV off nop3=nop1/op2", 1, 0},
	{51, ML_CODE_DIV, setCodeOp3_KK_DN, setInputNIn_Val16_on, verifyResultValueNibble8,
			"DIV on nop3=nop1/op2", 1, 48627716},
	{52, ML_CODE_DIV, setCodeOp3_NN_DN, setInputDIn_Val16_NN2_off, verifyResultValueNibble8,
			"DIV off nop3=nop1/op2", 1, 0},
	{53, ML_CODE_DIV, setCodeOp3_NN_DN, setInputDIn_Val16_NN2_on, verifyResultValueNibble8,
			"DIV on nop3=nop1/op2", 1, 48627716},

	{54, ML_CODE_DIVP, setCodeOp3_WW_DN, setInput2DIn_Val16_WW_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=op1/op2", 2, 0},
	{55, ML_CODE_DIVP, setCodeOp3_WW_DN, setInput2DIn_Val16p_WW_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=op1/op2", 2, 48627716},
	{56, ML_CODE_DIVP, setCodeOp3_NW_DN, setInput2DIn_Val16_NW2_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=nop1/op2", 2, 0},
	{57, ML_CODE_DIVP, setCodeOp3_NW_DN, setInput2DIn_Val16p_NW2_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=nop1/op2", 2, 48627716},
	{58, ML_CODE_DIVP, setCodeOp3_WN_DN, setInput2DIn_Val16_WN2_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=nop1/op2", 2, 0},
	{59, ML_CODE_DIVP, setCodeOp3_WN_DN, setInput2DIn_Val16p_WN2_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=nop1/op2", 2, 48627716},
	{60, ML_CODE_DIVP, setCodeOp3_KW_DN, setInputSIn_Val16_KW_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=op1/op2", 2, 0},
	{61, ML_CODE_DIVP, setCodeOp3_KW_DN, setInputSIn_Val16p_KW_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=op1/op2", 2, 48627716},
	{62, ML_CODE_DIVP, setCodeOp3_KN_DN, setInputSIn_Val16_KN2_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=nop1/op2", 2, 0},
	{63, ML_CODE_DIVP, setCodeOp3_KN_DN, setInputSIn_Val16p_KN2_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=nop1/op2", 2, 48627716},
	{64, ML_CODE_DIVP, setCodeOp3_WK_DN, setInputSIn_Val16_WK_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=nop1/op2", 2, 0},
	{65, ML_CODE_DIVP, setCodeOp3_WK_DN, setInputSIn_Val16p_WK_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=nop1/op2", 2, 48627716},
	{66, ML_CODE_DIVP, setCodeOp3_NK_DN, setInputSIn_Val16_NK_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=nop1/op2", 2, 0},
	{67, ML_CODE_DIVP, setCodeOp3_NK_DN, setInputSIn_Val16p_NK_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=nop1/op2", 2, 48627716},
	{68, ML_CODE_DIVP, setCodeOp3_KK_DN, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=nop1/op2", 2, 0},
	{69, ML_CODE_DIVP, setCodeOp3_KK_DN, setInputNIn_Val16p_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=nop1/op2", 2, 48627716},
	{70, ML_CODE_DIVP, setCodeOp3_NN_DN, setInputDIn_Val16_NN2_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=nop1/op2", 2, 0},
	{71, ML_CODE_DIVP, setCodeOp3_NN_DN, setInputDIn_Val16p_NN2_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=nop1/op2", 2, 48627716},

	{72, ML_CODE_BMLT, setCodeOp3_WW_DN, setInput2DIn_BCD4_WW_off, verifyResultValueNibble8,
			"BCDMLT off nop3=op1*op2", 1, 0},
	{73, ML_CODE_BMLT, setCodeOp3_WW_DN, setInput2DIn_BCD4_WW_on, verifyResultValueNibble8,
			"BCDMLT on nop3=op1*op2", 1, 77019432}, //0x497 3928
	{74, ML_CODE_BMLT, setCodeOp3_NW_DN, setInput2DIn_BCD4_NW2_off, verifyResultValueNibble8,
			"BCDMLT off nop3=nop1*op2", 1, 0},
	{75, ML_CODE_BMLT, setCodeOp3_NW_DN, setInput2DIn_BCD4_NW2_on, verifyResultValueNibble8,
			"BCDMLT on nop3=nop1*op2", 1, 77019432},
	{76, ML_CODE_BMLT, setCodeOp3_WN_DN, setInput2DIn_BCD4_WN2_off, verifyResultValueNibble8,
			"BCDMLT off nop3=nop1*op2", 1, 0},
	{77, ML_CODE_BMLT, setCodeOp3_WN_DN, setInput2DIn_BCD4_WN2_on, verifyResultValueNibble8,
			"BCDMLT on nop3=nop1*op2", 1, 77019432},
	{78, ML_CODE_BMLT, setCodeOp3_BKW_DN, setInputSIn_BCD4_KW_off, verifyResultValueNibble8,
			"BCDMLT off nop3=op1*op2", 1, 0},
	{79, ML_CODE_BMLT, setCodeOp3_BKW_DN, setInputSIn_BCD4_KW_on, verifyResultValueNibble8,
			"BCDMLT on nop3=op1*op2", 1, 77019432},
	{80, ML_CODE_BMLT, setCodeOp3_BKN_DN, setInputSIn_BCD4_KN2_off, verifyResultValueNibble8,
			"BCDMLT off nop3=nop1*op2", 1, 0},
	{81, ML_CODE_BMLT, setCodeOp3_BKN_DN, setInputSIn_BCD4_KN2_on, verifyResultValueNibble8,
			"BCDMLT on nop3=nop1*op2", 1, 77019432},
	{82, ML_CODE_BMLT, setCodeOp3_WBK_DN, setInputSIn_BCD4_WK_off, verifyResultValueNibble8,
			"BCDMLT off nop3=nop1*op2", 1, 0},
	{83, ML_CODE_BMLT, setCodeOp3_WBK_DN, setInputSIn_BCD4_WK_on, verifyResultValueNibble8,
			"BCDMLT on nop3=nop1*op2", 1, 77019432},
	{84, ML_CODE_BMLT, setCodeOp3_NBK_DN, setInputSIn_BCD4_NK_off, verifyResultValueNibble8,
			"BCDMLT off nop3=nop1*op2", 1, 0},
	{85, ML_CODE_BMLT, setCodeOp3_NBK_DN, setInputSIn_BCD4_NK_on, verifyResultValueNibble8,
			"BCDMLT on nop3=nop1*op2", 1, 77019432},
	{86, ML_CODE_BMLT, setCodeOp3_BKK_DN, setInputNIn_Val16_off, verifyResultValueNibble8,
			"BCDMLT off nop3=nop1*op2", 1, 0},
	{87, ML_CODE_BMLT, setCodeOp3_BKK_DN, setInputNIn_Val16_on, verifyResultValueNibble8,
			"BCDMLT on nop3=nop1*op2", 1, 77019432},
	{88, ML_CODE_BMLT, setCodeOp3_NN_DN, setInputDIn_BCD4_NN2_off, verifyResultValueNibble8,
			"BCDMLT off nop3=nop1*op2", 1, 0},
	{89, ML_CODE_BMLT, setCodeOp3_NN_DN, setInputDIn_BCD4_NN2_on, verifyResultValueNibble8,
			"BCDMLT on nop3=nop1*op2", 1, 77019432},

	{90, ML_CODE_BMLTP, setCodeOp3_WW_DN, setInput2DIn_BCD4_WW_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=op1*op2", 2, 0},
	{91, ML_CODE_BMLTP, setCodeOp3_WW_DN, setInput2DIn_BCD4p_WW_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=op1*op2", 2, 77019432}, //0x497 3928
	{92, ML_CODE_BMLTP, setCodeOp3_NW_DN, setInput2DIn_BCD4_NW2_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=nop1*op2", 2, 0},
	{93, ML_CODE_BMLTP, setCodeOp3_NW_DN, setInput2DIn_BCD4p_NW2_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=nop1*op2", 2, 77019432},
	{94, ML_CODE_BMLTP, setCodeOp3_WN_DN, setInput2DIn_BCD4_WN2_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=nop1*op2", 2, 0},
	{95, ML_CODE_BMLTP, setCodeOp3_WN_DN, setInput2DIn_BCD4p_WN2_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=nop1*op2", 2, 77019432},
	{96, ML_CODE_BMLTP, setCodeOp3_BKW_DN, setInputSIn_BCD4_KW_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=op1*op2", 2, 0},
	{97, ML_CODE_BMLTP, setCodeOp3_BKW_DN, setInputSIn_BCD4p_KW_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=op1*op2", 2, 77019432},
	{98, ML_CODE_BMLTP, setCodeOp3_BKN_DN, setInputSIn_BCD4_KN2_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=nop1*op2", 2, 0},
	{99, ML_CODE_BMLTP, setCodeOp3_BKN_DN, setInputSIn_BCD4p_KN2_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=nop1*op2", 2, 77019432},
	{100, ML_CODE_BMLTP, setCodeOp3_WBK_DN, setInputSIn_BCD4_WK_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=nop1*op2", 2, 0},
	{101, ML_CODE_BMLTP, setCodeOp3_WBK_DN, setInputSIn_BCD4p_WK_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=nop1*op2", 2, 77019432},
	{102, ML_CODE_BMLTP, setCodeOp3_NBK_DN, setInputSIn_BCD4_NK_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=nop1*op2", 2, 0},
	{103, ML_CODE_BMLTP, setCodeOp3_NBK_DN, setInputSIn_BCD4p_NK_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=nop1*op2", 2, 77019432},
	{104, ML_CODE_BMLTP, setCodeOp3_BKK_DN, setInputNIn_Val16_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=nop1*op2", 2, 0},
	{105, ML_CODE_BMLTP, setCodeOp3_BKK_DN, setInputNIn_Val16p_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=nop1*op2", 2, 77019432},
	{106, ML_CODE_BMLTP, setCodeOp3_NN_DN, setInputDIn_BCD4_NN2_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=nop1*op2", 2, 0},
	{107, ML_CODE_BMLTP, setCodeOp3_NN_DN, setInputDIn_BCD4p_NN2_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=nop1*op2", 2, 77019432},

	{108, ML_CODE_BDIV, setCodeOp3_WW_DN, setInput2DIn_BCD4_WW_off, verifyResultValueNibble8,
			"BCDDIV off nop3=op1/op2", 1, 0},
	{109, ML_CODE_BDIV, setCodeOp3_WW_DN, setInput2DIn_BCD4_WW_on, verifyResultValueNibble8,
			"BCDDIV on nop3=op1/op2", 1, 69337094}, //0x422 0006
	{110, ML_CODE_BDIV, setCodeOp3_NW_DN, setInput2DIn_BCD4_NW2_off, verifyResultValueNibble8,
			"BCDDIV off nop3=nop1/op2", 1, 0},
	{111, ML_CODE_BDIV, setCodeOp3_NW_DN, setInput2DIn_BCD4_NW2_on, verifyResultValueNibble8,
			"BCDDIV on nop3=nop1/op2", 1, 69337094},
	{112, ML_CODE_BDIV, setCodeOp3_WN_DN, setInput2DIn_BCD4_WN2_off, verifyResultValueNibble8,
			"BCDDIV off nop3=nop1/op2", 1, 0},
	{113, ML_CODE_BDIV, setCodeOp3_WN_DN, setInput2DIn_BCD4_WN2_on, verifyResultValueNibble8,
			"BCDDIV on nop3=nop1/op2", 1, 69337094},
	{114, ML_CODE_BDIV, setCodeOp3_BKW_DN, setInputSIn_BCD4_KW_off, verifyResultValueNibble8,
			"BCDDIV off nop3=op1/op2", 1, 0},
	{115, ML_CODE_BDIV, setCodeOp3_BKW_DN, setInputSIn_BCD4_KW_on, verifyResultValueNibble8,
			"BCDDIV on nop3=op1/op2", 1, 69337094},
	{116, ML_CODE_BDIV, setCodeOp3_BKN_DN, setInputSIn_BCD4_KN2_off, verifyResultValueNibble8,
			"BCDDIV off nop3=nop1/op2", 1, 0},
	{117, ML_CODE_BDIV, setCodeOp3_BKN_DN, setInputSIn_BCD4_KN2_on, verifyResultValueNibble8,
			"BCDDIV on nop3=nop1/op2", 1, 69337094},
	{118, ML_CODE_BDIV, setCodeOp3_WBK_DN, setInputSIn_BCD4_WK_off, verifyResultValueNibble8,
			"BCDDIV off nop3=nop1/op2", 1, 0},
	{119, ML_CODE_BDIV, setCodeOp3_WBK_DN, setInputSIn_BCD4_WK_on, verifyResultValueNibble8,
			"BCDDIV on nop3=nop1/op2", 1, 69337094},
	{120, ML_CODE_BDIV, setCodeOp3_NBK_DN, setInputSIn_BCD4_NK_off, verifyResultValueNibble8,
			"BCDDIV off nop3=nop1/op2", 1, 0},
	{121, ML_CODE_BDIV, setCodeOp3_NBK_DN, setInputSIn_BCD4_NK_on, verifyResultValueNibble8,
			"BCDDIV on nop3=nop1/op2", 1, 69337094},
	{122, ML_CODE_BDIV, setCodeOp3_BKK_DN, setInputNIn_Val16_off, verifyResultValueNibble8,
			"BCDDIV off nop3=nop1/op2", 1, 0},
	{123, ML_CODE_BDIV, setCodeOp3_BKK_DN, setInputNIn_Val16_on, verifyResultValueNibble8,
			"BCDDIV on nop3=nop1/op2", 1, 69337094},
	{124, ML_CODE_BDIV, setCodeOp3_NN_DN, setInputDIn_BCD4_NN2_off, verifyResultValueNibble8,
			"BCDDIV off nop3=nop1/op2", 1, 0},
	{125, ML_CODE_BDIV, setCodeOp3_NN_DN, setInputDIn_BCD4_NN2_on, verifyResultValueNibble8,
			"BCDDIV on nop3=nop1/op2", 1, 69337094},

	{126, ML_CODE_BDIVP, setCodeOp3_WW_DN, setInput2DIn_BCD4_WW_off, verifyResultValueNibble8,
			"BDIVP off nop3=op1/op2", 2, 0},
	{127, ML_CODE_BDIVP, setCodeOp3_WW_DN, setInput2DIn_BCD4p_WW_on, verifyResultValueNibble8,
			"BDIVP on nop3=op1/op2", 2, 69337094}, //0x422 0006
	{128, ML_CODE_BDIVP, setCodeOp3_NW_DN, setInput2DIn_BCD4_NW2_off, verifyResultValueNibble8,
			"BDIVP off nop3=nop1/op2", 2, 0},
	{129, ML_CODE_BDIVP, setCodeOp3_NW_DN, setInput2DIn_BCD4p_NW2_on, verifyResultValueNibble8,
			"BDIVP on nop3=nop1/op2", 2, 69337094},
	{130, ML_CODE_BDIVP, setCodeOp3_WN_DN, setInput2DIn_BCD4_WN2_off, verifyResultValueNibble8,
			"BDIVP off nop3=nop1/op2", 2, 0},
	{131, ML_CODE_BDIVP, setCodeOp3_WN_DN, setInput2DIn_BCD4p_WN2_on, verifyResultValueNibble8,
			"BDIVP on nop3=nop1/op2", 2, 69337094},
	{132, ML_CODE_BDIVP, setCodeOp3_BKW_DN, setInputSIn_BCD4_KW_off, verifyResultValueNibble8,
			"BDIVP off nop3=op1/op2", 2, 0},
	{133, ML_CODE_BDIVP, setCodeOp3_BKW_DN, setInputSIn_BCD4p_KW_on, verifyResultValueNibble8,
			"BDIVP on nop3=op1/op2", 2, 69337094},
	{134, ML_CODE_BDIVP, setCodeOp3_BKN_DN, setInputSIn_BCD4_KN2_off, verifyResultValueNibble8,
			"BDIVP off nop3=nop1/op2", 2, 0},
	{135, ML_CODE_BDIVP, setCodeOp3_BKN_DN, setInputSIn_BCD4p_KN2_on, verifyResultValueNibble8,
			"BDIVP on nop3=nop1/op2", 2, 69337094},
	{136, ML_CODE_BDIVP, setCodeOp3_WBK_DN, setInputSIn_BCD4_WK_off, verifyResultValueNibble8,
			"BDIVP off nop3=nop1/op2", 2, 0},
	{137, ML_CODE_BDIVP, setCodeOp3_WBK_DN, setInputSIn_BCD4p_WK_on, verifyResultValueNibble8,
			"BDIVP on nop3=nop1/op2", 2, 69337094},
	{138, ML_CODE_BDIVP, setCodeOp3_NBK_DN, setInputSIn_BCD4_NK_off, verifyResultValueNibble8,
			"BDIVP off nop3=nop1/op2", 2, 0},
	{139, ML_CODE_BDIVP, setCodeOp3_NBK_DN, setInputSIn_BCD4p_NK_on, verifyResultValueNibble8,
			"BDIVP on nop3=nop1/op2", 2, 69337094},
	{140, ML_CODE_BDIVP, setCodeOp3_BKK_DN, setInputNIn_Val16_off, verifyResultValueNibble8,
			"BDIVP off nop3=nop1/op2", 2, 0},
	{141, ML_CODE_BDIVP, setCodeOp3_BKK_DN, setInputNIn_Val16p_on, verifyResultValueNibble8,
			"BDIVP on nop3=nop1/op2", 2, 69337094},
	{142, ML_CODE_BDIVP, setCodeOp3_NN_DN, setInputDIn_BCD4_NN2_off, verifyResultValueNibble8,
			"BDIVP off nop3=nop1/op2", 2, 0},
	{143, ML_CODE_BDIVP, setCodeOp3_NN_DN, setInputDIn_BCD4p_NN2_on, verifyResultValueNibble8,
			"BDIVP on nop3=nop1/op2", 2, 69337094},

	{-1, 0xFFFF, NULL, NULL, NULL, " ", 0, 0 }
};



int total_basic_compute_word_mul_nb_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_word_mul_nb_test_number; i++)
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


int setCodeOp3_WW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 160);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_NW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_D, 160);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_D, in_pos); addMLOperandNibble(4, in_reg, 160);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_KW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 5678); addMLOperand(in_reg, in_pos);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_KN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 5678); addMLOperandNibble(4, in_reg, in_pos);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_NN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperandNibble(4, in_reg, 160);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_NK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_KK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 5678); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_BKW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x5678); addMLOperand(in_reg, in_pos);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_BKN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x5678); addMLOperandNibble(4, in_reg, in_pos);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WBK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_K, 0x876);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_NBK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_K, 0x876);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


int setCodeOp3_BKK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x5678); addMLOperand(OPERAND_ML_CODE_K, 0x876);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput2DIn_Val16_WW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_Val16_WW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_Val16p_WW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_Val16_NW2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_Val16_NW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_Val16p_NW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_Val16_WN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_Val16p_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16_WK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_Val16_WK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_Val16p_WK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_Val16_KW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_Val16_KW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_Val16p_KW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_Val16_NK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16_NK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16p_NK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_Val16p_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16_NN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16_NN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_Val16p_NN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInput2DIn_BCD4_WW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_BCD4_WW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_BCD4p_WW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_BCD4_NW2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_BCD4_NW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_BCD4p_NW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, in2_val);

	TestCodeTearDown();
}

void setInput2DIn_BCD4_WN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_BCD4_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_BCD4p_WN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_BCD4_KW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_BCD4_KW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_BCD4p_KW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_BCD4_KN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_BCD4_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_BCD4p_KN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_BCD4_WK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_BCD4_WK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_BCD4p_WK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_BCD4_NK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_BCD4_NK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_BCD4p_NK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x5678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCD4_NN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCD4_NN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_BCD4p_NN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x5678, in2_val=0x876;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12287,8191}}; // word, nibble8
	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_arithmetic_multi_nb(int tno, uint16 dummy)
{
	int i, rc=0, rc2=1, olast=0, res_dword;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos;
	long long res_ndword;
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
							test_getNibble(&res_dword, out, out_pos, 8);
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

void testBasicArithmeticMulNibbleCommand(void)
{
	int i, index=125;
	int start, end;
	char log[] = "err_arith_mul_nb.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic mul_div LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=36;index<45;index++)
	test_basic_arithmetic_multi_nb(index, 0);
#else
	total_basic_compute_word_mul_nb_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_MLT);
	end = getTestCaseNumberEnd(ML_CODE_BDIVP); //ML_CODE_BDIVP

	DBG_LOGPRINT("testBasicArithmeticMulNibbleCommand: %d to %d total %d\n", start, end, total_basic_compute_word_mul_nb_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_multi_nb(index, 0);
	}
#endif
	fclose(flog);
}
#endif
