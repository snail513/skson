/*
 * test_basic_compare_word_nibble.c
 *
 *  Created on: Jun 23, 2015
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

extern int verifyResultNormal(int tcase, uint8 dest_reg, uint16 pos, uint8 expected);


int setCodeLD16_N_W_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeLD16_W_N_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeLD16_N_N_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeLD16_N_K_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeLD16_N_nK_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeAND_OR_N_W(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeAND_OR_W_N(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeAND_OR_N_N(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeAND_OR_K_N(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);

void setInputDIn_N_W_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_nK_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_nK_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_nK_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputSIn_N_K_off_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_off_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_off_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_on_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_on_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_on_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputDIn_N_W_off_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_off_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_off_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_on_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_on_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_on_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputDIn_W_N_off_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_off_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_off_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_on_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_on_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_on_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputDIn_N_N_off_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_off_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_off_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_on_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_on_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_on_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint8, uint16);
	int (*verifyResult_fn)(uint, uint8, uint16, uint8);
	char str[30];
	int run_step;
	int expected;
} testFn_st;

static testFn_st testCase[]={

	{0, ML_CODE_LDEQ, setCodeLD16_N_W_OUT, setInputDIn_N_W_bigVal16, verifyResultNormal,
			"LDEQ_OUT nop1 > op2", 1, 0},
	{1, ML_CODE_LDEQ, setCodeLD16_N_W_OUT, setInputDIn_N_W_sameVal16, verifyResultNormal,
			"LDEQ_OUT nop1 == op2", 1, 1},
	{2, ML_CODE_LDEQ, setCodeLD16_N_W_OUT, setInputDIn_N_W_lessVal16, verifyResultNormal,
			"LDEQ_OUT nop1 < op2", 1, 0},
	{3, ML_CODE_LDEQ, setCodeLD16_N_K_OUT, setInputSIn_N_K_bigVal16, verifyResultNormal,
			"LDEQ_OUT nop1 > K", 1, 0},
	{4, ML_CODE_LDEQ, setCodeLD16_N_K_OUT, setInputSIn_N_K_sameVal16, verifyResultNormal,
			"LDEQ_OUT nop1 == K", 1, 1},
	{5, ML_CODE_LDEQ, setCodeLD16_N_K_OUT, setInputSIn_N_K_lessVal16, verifyResultNormal,
			"LDEQ_OUT nop1 < K", 1, 0},
	{6, ML_CODE_LDEQ, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_bigVal16, verifyResultNormal,
			"LDEQ_OUT nop1 > nK", 1, 0},
	{7, ML_CODE_LDEQ, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_sameVal16, verifyResultNormal,
			"LDEQ_OUT nop1 == nK", 1, 1},
	{8, ML_CODE_LDEQ, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_lessVal16, verifyResultNormal,
			"LDEQ_OUT nop1 < nK", 1, 0},
	{9, ML_CODE_LDEQ, setCodeLD16_W_N_OUT, setInputDIn_W_N_bigVal16, verifyResultNormal,
			"LDEQ_OUT op1 > nop2", 1, 0},
	{10, ML_CODE_LDEQ, setCodeLD16_W_N_OUT, setInputDIn_W_N_sameVal16, verifyResultNormal,
			"LDEQ_OUT op1 == nop2", 1, 1},
	{11, ML_CODE_LDEQ, setCodeLD16_W_N_OUT, setInputDIn_W_N_lessVal16, verifyResultNormal,
			"LDEQ_OUT op1 < nop2", 1, 0},
	{12, ML_CODE_LDEQ, setCodeLD16_N_N_OUT, setInputDIn_N_N_bigVal16, verifyResultNormal,
			"LDEQ_OUT nop1 > nop2", 1, 0},
	{13, ML_CODE_LDEQ, setCodeLD16_N_N_OUT, setInputDIn_N_N_sameVal16, verifyResultNormal,
			"LDEQ_OUT nop1 == nop2", 1, 1},
	{14, ML_CODE_LDEQ, setCodeLD16_N_N_OUT, setInputDIn_N_N_lessVal16, verifyResultNormal,
			"LDEQ_OUT nop1 < nop2", 1, 0},

	{15, ML_CODE_LDNE, setCodeLD16_N_W_OUT, setInputDIn_N_W_bigVal16, verifyResultNormal,
			"LDNE_OUT nop1 > op2", 1, 1},
	{16, ML_CODE_LDNE, setCodeLD16_N_W_OUT, setInputDIn_N_W_sameVal16, verifyResultNormal,
			"LDNE_OUT nop1 == op2", 1, 0},
	{17, ML_CODE_LDNE, setCodeLD16_N_W_OUT, setInputDIn_N_W_lessVal16, verifyResultNormal,
			"LDNE_OUT nop1 < op2", 1, 1},
	{18, ML_CODE_LDNE, setCodeLD16_N_K_OUT, setInputSIn_N_K_bigVal16, verifyResultNormal,
			"LDNE_OUT nop1 > K", 1, 1},
	{19, ML_CODE_LDNE, setCodeLD16_N_K_OUT, setInputSIn_N_K_sameVal16, verifyResultNormal,
			"LDNE_OUT nop1 == K", 1, 0},
	{20, ML_CODE_LDNE, setCodeLD16_N_K_OUT, setInputSIn_N_K_lessVal16, verifyResultNormal,
			"LDNE_OUT nop1 < K", 1, 1},
	{21, ML_CODE_LDNE, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_bigVal16, verifyResultNormal,
			"LDNE_OUT nop1 > nK", 1, 1},
	{22, ML_CODE_LDNE, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_sameVal16, verifyResultNormal,
			"LDNE_OUT nop1 == nK", 1, 0},
	{23, ML_CODE_LDNE, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_lessVal16, verifyResultNormal,
			"LDNE_OUT nop1 < nK", 1, 1},
	{24, ML_CODE_LDNE, setCodeLD16_W_N_OUT, setInputDIn_W_N_bigVal16, verifyResultNormal,
			"LDNE_OUT op1 > nop2", 1, 1},
	{25, ML_CODE_LDNE, setCodeLD16_W_N_OUT, setInputDIn_W_N_sameVal16, verifyResultNormal,
			"LDNE_OUT op1 == nop2", 1, 0},
	{26, ML_CODE_LDNE, setCodeLD16_W_N_OUT, setInputDIn_W_N_lessVal16, verifyResultNormal,
			"LDNE_OUT op1 < nop2", 1, 1},
	{27, ML_CODE_LDNE, setCodeLD16_N_N_OUT, setInputDIn_N_N_bigVal16, verifyResultNormal,
			"LDNE_OUT nop1 > nop2", 1, 1},
	{28, ML_CODE_LDNE, setCodeLD16_N_N_OUT, setInputDIn_N_N_sameVal16, verifyResultNormal,
			"LDNE_OUT nop1 == nop2", 1, 0},
	{29, ML_CODE_LDNE, setCodeLD16_N_N_OUT, setInputDIn_N_N_lessVal16, verifyResultNormal,
			"LDNE_OUT nop1 < nop2", 1, 1},

	{30, ML_CODE_LDGT, setCodeLD16_N_W_OUT, setInputDIn_N_W_bigVal16, verifyResultNormal,
			"LDGT_OUT nop1 > op2", 1, 1},
	{31, ML_CODE_LDGT, setCodeLD16_N_W_OUT, setInputDIn_N_W_sameVal16, verifyResultNormal,
			"LDGT_OUT nop1 == op2", 1, 0},
	{32, ML_CODE_LDGT, setCodeLD16_N_W_OUT, setInputDIn_N_W_lessVal16, verifyResultNormal,
			"LDGT_OUT nop1 < op2", 1, 0},
	{33, ML_CODE_LDGT, setCodeLD16_N_K_OUT, setInputSIn_N_K_bigVal16, verifyResultNormal,
			"LDGT_OUT nop1 > K", 1, 1},
	{34, ML_CODE_LDGT, setCodeLD16_N_K_OUT, setInputSIn_N_K_sameVal16, verifyResultNormal,
			"LDGT_OUT nop1 == K", 1, 0},
	{35, ML_CODE_LDGT, setCodeLD16_N_K_OUT, setInputSIn_N_K_lessVal16, verifyResultNormal,
			"LDGT_OUT nop1 < K", 1, 0},
	{36, ML_CODE_LDGT, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_bigVal16, verifyResultNormal,
			"LDGT_OUT nop1 > nK", 1, 1},
	{37, ML_CODE_LDGT, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_sameVal16, verifyResultNormal,
			"LDGT_OUT nop1 == nK", 1, 0},
	{38, ML_CODE_LDGT, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_lessVal16, verifyResultNormal,
			"LDGT_OUT nop1 < nK", 1, 0},
	{39, ML_CODE_LDGT, setCodeLD16_W_N_OUT, setInputDIn_W_N_bigVal16, verifyResultNormal,
			"LDGT_OUT op1 > nop2", 1, 1},
	{40, ML_CODE_LDGT, setCodeLD16_W_N_OUT, setInputDIn_W_N_sameVal16, verifyResultNormal,
			"LDGT_OUT op1 == nop2", 1, 0},
	{41, ML_CODE_LDGT, setCodeLD16_W_N_OUT, setInputDIn_W_N_lessVal16, verifyResultNormal,
			"LDGT_OUT op1 < nop2", 1, 0},
	{42, ML_CODE_LDGT, setCodeLD16_N_N_OUT, setInputDIn_N_N_bigVal16, verifyResultNormal,
			"LDGT_OUT nop1 > nop2", 1, 1},
	{43, ML_CODE_LDGT, setCodeLD16_N_N_OUT, setInputDIn_N_N_sameVal16, verifyResultNormal,
			"LDGT_OUT nop1 == nop2", 1, 0},
	{44, ML_CODE_LDGT, setCodeLD16_N_N_OUT, setInputDIn_N_N_lessVal16, verifyResultNormal,
			"LDGT_OUT nop1 < nop2", 1, 0},

	{45, ML_CODE_LDGE, setCodeLD16_N_W_OUT, setInputDIn_N_W_bigVal16, verifyResultNormal,
			"LDGE_OUT nop1 > op2", 1, 1},
	{46, ML_CODE_LDGE, setCodeLD16_N_W_OUT, setInputDIn_N_W_sameVal16, verifyResultNormal,
			"LDGE_OUT nop1 == op2", 1, 1},
	{47, ML_CODE_LDGE, setCodeLD16_N_W_OUT, setInputDIn_N_W_lessVal16, verifyResultNormal,
			"LDGE_OUT nop1 < op2", 1, 0},
	{48, ML_CODE_LDGE, setCodeLD16_N_K_OUT, setInputSIn_N_K_bigVal16, verifyResultNormal,
			"LDGE_OUT nop1 > K", 1, 1},
	{49, ML_CODE_LDGE, setCodeLD16_N_K_OUT, setInputSIn_N_K_sameVal16, verifyResultNormal,
			"LDGE_OUT nop1 == K", 1, 1},
	{50, ML_CODE_LDGE, setCodeLD16_N_K_OUT, setInputSIn_N_K_lessVal16, verifyResultNormal,
			"LDGE_OUT nop1 < K", 1, 0},
	{51, ML_CODE_LDGE, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_bigVal16, verifyResultNormal,
			"LDGE_OUT nop1 > nK", 1, 1},
	{52, ML_CODE_LDGE, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_sameVal16, verifyResultNormal,
			"LDGE_OUT nop1 == nK", 1, 1},
	{53, ML_CODE_LDGE, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_lessVal16, verifyResultNormal,
			"LDGE_OUT nop1 < nK", 1, 0},
	{54, ML_CODE_LDGE, setCodeLD16_W_N_OUT, setInputDIn_W_N_bigVal16, verifyResultNormal,
			"LDGE_OUT op1 > nop2", 1, 1},
	{55, ML_CODE_LDGE, setCodeLD16_W_N_OUT, setInputDIn_W_N_sameVal16, verifyResultNormal,
			"LDGE_OUT op1 == nop2", 1, 1},
	{56, ML_CODE_LDGE, setCodeLD16_W_N_OUT, setInputDIn_W_N_lessVal16, verifyResultNormal,
			"LDGE_OUT op1 < nop2", 1, 0},
	{57, ML_CODE_LDLT, setCodeLD16_N_N_OUT, setInputDIn_N_N_bigVal16, verifyResultNormal,
			"LDLT_OUT nop1 > nop2", 1, 0},
	{58, ML_CODE_LDLT, setCodeLD16_N_N_OUT, setInputDIn_N_N_sameVal16, verifyResultNormal,
			"LDLT_OUT nop1 == nop2", 1, 0},
	{59, ML_CODE_LDLT, setCodeLD16_N_N_OUT, setInputDIn_N_N_lessVal16, verifyResultNormal,
			"LDLT_OUT nop1 < nop2", 1, 1},

	{60, ML_CODE_LDLT, setCodeLD16_N_W_OUT, setInputDIn_N_W_bigVal16, verifyResultNormal,
			"LDLT_OUT nop1 > op2", 1, 0},
	{61, ML_CODE_LDLT, setCodeLD16_N_W_OUT, setInputDIn_N_W_sameVal16, verifyResultNormal,
			"LDLT_OUT nop1 == op2", 1, 0},
	{62, ML_CODE_LDLT, setCodeLD16_N_W_OUT, setInputDIn_N_W_lessVal16, verifyResultNormal,
			"LDLT_OUT nop1 < op2", 1, 1},
	{63, ML_CODE_LDLT, setCodeLD16_N_K_OUT, setInputSIn_N_K_bigVal16, verifyResultNormal,
			"LDLT_OUT nop1 > K", 1, 0},
	{64, ML_CODE_LDLT, setCodeLD16_N_K_OUT, setInputSIn_N_K_sameVal16, verifyResultNormal,
			"LDLT_OUT nop1 == K", 1, 0},
	{65, ML_CODE_LDLT, setCodeLD16_N_K_OUT, setInputSIn_N_K_lessVal16, verifyResultNormal,
			"LDLT_OUT nop1 < K", 1, 1},
	{66, ML_CODE_LDLT, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_bigVal16, verifyResultNormal,
			"LDLT_OUT nop1 > nK", 1, 0},
	{67, ML_CODE_LDLT, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_sameVal16, verifyResultNormal,
			"LDLT_OUT nop1 == nK", 1, 0},
	{68, ML_CODE_LDLT, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_lessVal16, verifyResultNormal,
			"LDLT_OUT nop1 < nK", 1, 1},
	{69, ML_CODE_LDLT, setCodeLD16_W_N_OUT, setInputDIn_W_N_bigVal16, verifyResultNormal,
			"LDLT_OUT op1 > nop2", 1, 0},
	{70, ML_CODE_LDLT, setCodeLD16_W_N_OUT, setInputDIn_W_N_sameVal16, verifyResultNormal,
			"LDLT_OUT op1 == nop2", 1, 0},
	{71, ML_CODE_LDLT, setCodeLD16_W_N_OUT, setInputDIn_W_N_lessVal16, verifyResultNormal,
			"LDLT_OUT op1 < nop2", 1, 1},
	{72, ML_CODE_LDLT, setCodeLD16_N_N_OUT, setInputDIn_N_N_bigVal16, verifyResultNormal,
			"LDLT_OUT nop1 > nop2", 1, 0},
	{73, ML_CODE_LDLT, setCodeLD16_N_N_OUT, setInputDIn_N_N_sameVal16, verifyResultNormal,
			"LDLT_OUT nop1 == nop2", 1, 0},
	{74, ML_CODE_LDLT, setCodeLD16_N_N_OUT, setInputDIn_N_N_lessVal16, verifyResultNormal,
			"LDLT_OUT nop1 < nop2", 1, 1},

	{75, ML_CODE_LDLE, setCodeLD16_N_W_OUT, setInputDIn_N_W_bigVal16, verifyResultNormal,
			"LDLE_OUT nop1 > op2", 1, 0},
	{76, ML_CODE_LDLE, setCodeLD16_N_W_OUT, setInputDIn_N_W_sameVal16, verifyResultNormal,
			"LDLE_OUT nop1 == op2", 1, 1},
	{77, ML_CODE_LDLE, setCodeLD16_N_W_OUT, setInputDIn_N_W_lessVal16, verifyResultNormal,
			"LDLE_OUT nop1 < op2", 1, 1},
	{78, ML_CODE_LDLE, setCodeLD16_N_K_OUT, setInputSIn_N_K_bigVal16, verifyResultNormal,
			"LDLE_OUT nop1 > K", 1, 0},
	{79, ML_CODE_LDLE, setCodeLD16_N_K_OUT, setInputSIn_N_K_sameVal16, verifyResultNormal,
			"LDLE_OUT nop1 == K", 1, 1},
	{80, ML_CODE_LDLE, setCodeLD16_N_K_OUT, setInputSIn_N_K_lessVal16, verifyResultNormal,
			"LDLE_OUT nop1 < K", 1, 1},
	{81, ML_CODE_LDLE, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_bigVal16, verifyResultNormal,
			"LDLE_OUT nop1 > nK", 1, 0},
	{82, ML_CODE_LDLE, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_sameVal16, verifyResultNormal,
			"LDLE_OUT nop1 < nK", 1, 1},
	{83, ML_CODE_LDLE, setCodeLD16_N_nK_OUT, setInputSIn_N_nK_lessVal16, verifyResultNormal,
			"LDLE_OUT nop1 < nK", 1, 1},
	{84, ML_CODE_LDLE, setCodeLD16_W_N_OUT, setInputDIn_W_N_bigVal16, verifyResultNormal,
			"LDLE_OUT nop1 > nop2", 1, 0},
	{85, ML_CODE_LDLE, setCodeLD16_W_N_OUT, setInputDIn_W_N_sameVal16, verifyResultNormal,
			"LDLE_OUT op1 == nop2", 1, 1},
	{86, ML_CODE_LDLE, setCodeLD16_W_N_OUT, setInputDIn_W_N_lessVal16, verifyResultNormal,
			"LDLE_OUT op1 < nop2", 1, 1},
	{87, ML_CODE_LDLE, setCodeLD16_N_N_OUT, setInputDIn_N_N_bigVal16, verifyResultNormal,
			"LDLE_OUT nop1 > nop2", 1, 0},
	{88, ML_CODE_LDLE, setCodeLD16_N_N_OUT, setInputDIn_N_N_sameVal16, verifyResultNormal,
			"LDLE_OUT nop1 == nop2", 1, 1},
	{89, ML_CODE_LDLE, setCodeLD16_N_N_OUT, setInputDIn_N_N_lessVal16, verifyResultNormal,
			"LDLE_OUT nop1 < nop2", 1, 1},

	{90, ML_CODE_ANDEQ, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ANDEQ_OUT off nb_S > D", 1, 0},
	{91, ML_CODE_ANDEQ, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ANDEQ_OUT off nb_S = D", 1, 0},
	{92, ML_CODE_ANDEQ, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ANDEQ_OUT off nb_S < D", 1, 0},
	{93, ML_CODE_ANDEQ, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ANDEQ_OUT on nb_S > D", 1, 0},
	{94, ML_CODE_ANDEQ, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ANDEQ_OUT on nb_S = D", 1, 1},
	{95, ML_CODE_ANDEQ, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ANDEQ_OUT on nb_S < D", 1, 0},
	{96, ML_CODE_ANDEQ, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ANDEQ_OUT off K > nb_D", 1, 0},
	{97, ML_CODE_ANDEQ, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ANDEQ_OUT off K = nb_D", 1, 0},
	{98, ML_CODE_ANDEQ, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ANDEQ_OUT off K < nb_D", 1, 0},
	{99, ML_CODE_ANDEQ, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ANDEQ_OUT on K > nb_D", 1, 0},
	{100, ML_CODE_ANDEQ, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ANDEQ_OUT on K = nb_D", 1, 1},
	{101, ML_CODE_ANDEQ, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ANDEQ_OUT on K < nb_D", 1, 0},
	{102, ML_CODE_ANDEQ, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ANDEQ_OUT off S > nb_D", 1, 0},
	{103, ML_CODE_ANDEQ, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ANDEQ_OUT off S = nb_D", 1, 0},
	{104, ML_CODE_ANDEQ, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ANDEQ_OUT off S < nb_D", 1, 0},
	{105, ML_CODE_ANDEQ, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ANDEQ_OUT on S > nb_D", 1, 0},
	{106, ML_CODE_ANDEQ, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ANDEQ_OUT on S = nb_D", 1, 1},
	{107, ML_CODE_ANDEQ, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ANDEQ_OUT on S < nb_D", 1, 0},
	{108, ML_CODE_ANDEQ, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ANDEQ_OUT off nb_S > nb_D", 1, 0},
	{109, ML_CODE_ANDEQ, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ANDEQ_OUT off nb_S = nb_D", 1, 0},
	{110, ML_CODE_ANDEQ, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ANDEQ_OUT off nb_S < nb_D", 1, 0},
	{111, ML_CODE_ANDEQ, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ANDEQ_OUT on nb_S > nb_D", 1, 0},
	{112, ML_CODE_ANDEQ, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ANDEQ_OUT on nb_S = nb_D", 1, 1},
	{113, ML_CODE_ANDEQ, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ANDEQ_OUT on nb_S < nb_D", 1, 0},

	{114, ML_CODE_ANDNE, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ANDNE_OUT off nb_S > D", 1, 0},
	{115, ML_CODE_ANDNE, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ANDNE_OUT off nb_S = D", 1, 0},
	{116, ML_CODE_ANDNE, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ANDNE_OUT off nb_S < D", 1, 0},
	{117, ML_CODE_ANDNE, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ANDNE_OUT on nb_S > D", 1, 1},
	{118, ML_CODE_ANDNE, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ANDNE_OUT on nb_S = D", 1, 0},
	{119, ML_CODE_ANDNE, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ANDNE_OUT on nb_S < D", 1, 1},
	{120, ML_CODE_ANDNE, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ANDNE_OUT off K > nb_D", 1, 0},
	{121, ML_CODE_ANDNE, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ANDNE_OUT off K = nb_D", 1, 0},
	{122, ML_CODE_ANDNE, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ANDNE_OUT off K < nb_D", 1, 0},
	{123, ML_CODE_ANDNE, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ANDNE_OUT on K > nb_D", 1, 1},
	{124, ML_CODE_ANDNE, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ANDNE_OUT on K = nb_D", 1, 0},
	{125, ML_CODE_ANDNE, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ANDNE_OUT on K < nb_D", 1, 1},
	{126, ML_CODE_ANDNE, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ANDNE_OUT off S > nb_D", 1, 0},
	{127, ML_CODE_ANDNE, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ANDNE_OUT off S = nb_D", 1, 0},
	{128, ML_CODE_ANDNE, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ANDNE_OUT off S < nb_D", 1, 0},
	{129, ML_CODE_ANDNE, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ANDNE_OUT on S > nb_D", 1, 1},
	{130, ML_CODE_ANDNE, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ANDNE_OUT on S = nb_D", 1, 0},
	{131, ML_CODE_ANDNE, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ANDNE_OUT on S < nb_D", 1, 1},
	{132, ML_CODE_ANDNE, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ANDNE_OUT off nb_S > nb_D", 1, 0},
	{133, ML_CODE_ANDNE, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ANDNE_OUT off nb_S = nb_D", 1, 0},
	{134, ML_CODE_ANDNE, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ANDNE_OUT off nb_S < nb_D", 1, 0},
	{135, ML_CODE_ANDNE, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ANDNE_OUT on nb_S > nb_D", 1, 1},
	{136, ML_CODE_ANDNE, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ANDNE_OUT on nb_S = nb_D", 1, 0},
	{137, ML_CODE_ANDNE, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ANDNE_OUT on nb_S < nb_D", 1, 1},

	{138, ML_CODE_ANDGT, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ANDGT_OUT off nb_S > D", 1, 0},
	{139, ML_CODE_ANDGT, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ANDGT_OUT off nb_S = D", 1, 0},
	{140, ML_CODE_ANDGT, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ANDGT_OUT off nb_S < D", 1, 0},
	{141, ML_CODE_ANDGT, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ANDGT_OUT on nb_S > D", 1, 1},
	{142, ML_CODE_ANDGT, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ANDGT_OUT on nb_S = D", 1, 0},
	{143, ML_CODE_ANDGT, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ANDGT_OUT on nb_S < D", 1, 0},
	{144, ML_CODE_ANDGT, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ANDGT_OUT off K > nb_D", 1, 0},
	{145, ML_CODE_ANDGT, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ANDGT_OUT off K = nb_D", 1, 0},
	{146, ML_CODE_ANDGT, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ANDGT_OUT off K < nb_D", 1, 0},
	{147, ML_CODE_ANDGT, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ANDGT_OUT on K > nb_D", 1, 1},
	{148, ML_CODE_ANDGT, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ANDGT_OUT on K = nb_D", 1, 0},
	{149, ML_CODE_ANDGT, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ANDGT_OUT on K < nb_D", 1, 0},
	{150, ML_CODE_ANDGT, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ANDGT_OUT off S > nb_D", 1, 0},
	{151, ML_CODE_ANDGT, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ANDGT_OUT off S = nb_D", 1, 0},
	{152, ML_CODE_ANDGT, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ANDGT_OUT off S < nb_D", 1, 0},
	{153, ML_CODE_ANDGT, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ANDGT_OUT on S > nb_D", 1, 1},
	{154, ML_CODE_ANDGT, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ANDGT_OUT on S = nb_D", 1, 0},
	{155, ML_CODE_ANDGT, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ANDGT_OUT on S < nb_D", 1, 0},
	{156, ML_CODE_ANDGT, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ANDGT_OUT off nb_S > nb_D", 1, 0},
	{157, ML_CODE_ANDGT, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ANDGT_OUT off nb_S = nb_D", 1, 0},
	{158, ML_CODE_ANDGT, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ANDGT_OUT off nb_S < nb_D", 1, 0},
	{159, ML_CODE_ANDGT, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ANDGT_OUT on nb_S > nb_D", 1, 1},
	{160, ML_CODE_ANDGT, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ANDGT_OUT on nb_S = nb_D", 1, 0},
	{161, ML_CODE_ANDGT, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ANDGT_OUT on nb_S < nb_D", 1, 0},

	{162, ML_CODE_ANDGE, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ANDGE_OUT off nb_S > D", 1, 0},
	{163, ML_CODE_ANDGE, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ANDGE_OUT off nb_S = D", 1, 0},
	{164, ML_CODE_ANDGE, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ANDGE_OUT off nb_S < D", 1, 0},
	{165, ML_CODE_ANDGE, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ANDGE_OUT on nb_S > D", 1, 1},
	{166, ML_CODE_ANDGE, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ANDGE_OUT on nb_S = D", 1, 1},
	{167, ML_CODE_ANDGE, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ANDGE_OUT on nb_S < D", 1, 0},
	{168, ML_CODE_ANDGE, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ANDGE_OUT off K > nb_D", 1, 0},
	{169, ML_CODE_ANDGE, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ANDGE_OUT off K = nb_D", 1, 0},
	{170, ML_CODE_ANDGE, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ANDGE_OUT off K < nb_D", 1, 0},
	{171, ML_CODE_ANDGE, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ANDGE_OUT on K > nb_D", 1, 1},
	{172, ML_CODE_ANDGE, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ANDGE_OUT on K = nb_D", 1, 1},
	{173, ML_CODE_ANDGE, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ANDGE_OUT on K < nb_D", 1, 0},
	{174, ML_CODE_ANDGE, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ANDGE_OUT off S > nb_D", 1, 0},
	{175, ML_CODE_ANDGE, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ANDGE_OUT off S = nb_D", 1, 0},
	{176, ML_CODE_ANDGE, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ANDGE_OUT off S < nb_D", 1, 0},
	{177, ML_CODE_ANDGE, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ANDGE_OUT on S > nb_D", 1, 1},
	{178, ML_CODE_ANDGE, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ANDGE_OUT on S = nb_D", 1, 1},
	{179, ML_CODE_ANDGE, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ANDGE_OUT on S < nb_D", 1, 0},
	{180, ML_CODE_ANDGE, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ANDGE_OUT off nb_S > nb_D", 1, 0},
	{181, ML_CODE_ANDGE, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ANDGE_OUT off nb_S = nb_D", 1, 0},
	{182, ML_CODE_ANDGE, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ANDGE_OUT off nb_S < nb_D", 1, 0},
	{183, ML_CODE_ANDGE, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ANDGE_OUT on nb_S > nb_D", 1, 1},
	{184, ML_CODE_ANDGE, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ANDGE_OUT on nb_S = nb_D", 1, 1},
	{185, ML_CODE_ANDGE, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ANDGE_OUT on nb_S < nb_D", 1, 0},

	{186, ML_CODE_ANDLT, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ANDLT_OUT off nb_S > D", 1, 0},
	{187, ML_CODE_ANDLT, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ANDLT_OUT off nb_S = D", 1, 0},
	{188, ML_CODE_ANDLT, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ANDLT_OUT off nb_S < D", 1, 0},
	{189, ML_CODE_ANDLT, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ANDLT_OUT on nb_S > D", 1, 0},
	{190, ML_CODE_ANDLT, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ANDLT_OUT on nb_S = D", 1, 0},
	{191, ML_CODE_ANDLT, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ANDLT_OUT on nb_S < D", 1, 1},
	{192, ML_CODE_ANDLT, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ANDLT_OUT off K > nb_D", 1, 0},
	{193, ML_CODE_ANDLT, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ANDLT_OUT off K = nb_D", 1, 0},
	{194, ML_CODE_ANDLT, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ANDLT_OUT off K < nb_D", 1, 0},
	{195, ML_CODE_ANDLT, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ANDLT_OUT on K > nb_D", 1, 0},
	{196, ML_CODE_ANDLT, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ANDLT_OUT on K = nb_D", 1, 0},
	{197, ML_CODE_ANDLT, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ANDLT_OUT on K < nb_D", 1, 1},
	{198, ML_CODE_ANDLT, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ANDLT_OUT off S > nb_D", 1, 0},
	{199, ML_CODE_ANDLT, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ANDLT_OUT off S = nb_D", 1, 0},
	{200, ML_CODE_ANDLT, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ANDLT_OUT off S < nb_D", 1, 0},
	{201, ML_CODE_ANDLT, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ANDLT_OUT on S > nb_D", 1, 0},
	{202, ML_CODE_ANDLT, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ANDLT_OUT on S = nb_D", 1, 0},
	{203, ML_CODE_ANDLT, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ANDLT_OUT on S < nb_D", 1, 1},
	{204, ML_CODE_ANDLT, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ANDLT_OUT off nb_S > nb_D", 1, 0},
	{205, ML_CODE_ANDLT, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ANDLT_OUT off nb_S = nb_D", 1, 0},
	{206, ML_CODE_ANDLT, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ANDLT_OUT off nb_S < nb_D", 1, 0},
	{207, ML_CODE_ANDLT, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ANDLT_OUT on nb_S > nb_D", 1, 0},
	{208, ML_CODE_ANDLT, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ANDLT_OUT on nb_S = nb_D", 1, 0},
	{209, ML_CODE_ANDLT, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ANDLT_OUT on nb_S < nb_D", 1, 1},

	{210, ML_CODE_ANDLE, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ANDLE_OUT off nb_S > D", 1, 0},
	{211, ML_CODE_ANDLE, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ANDLE_OUT off nb_S = D", 1, 0},
	{212, ML_CODE_ANDLE, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ANDLE_OUT off nb_S < D", 1, 0},
	{213, ML_CODE_ANDLE, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ANDLE_OUT on nb_S > D", 1, 0},
	{214, ML_CODE_ANDLE, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ANDLE_OUT on nb_S = D", 1, 1},
	{215, ML_CODE_ANDLE, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ANDLE_OUT on nb_S < D", 1, 1},
	{216, ML_CODE_ANDLE, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ANDLE_OUT off K > nb_D", 1, 0},
	{217, ML_CODE_ANDLE, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ANDLE_OUT off K = nb_D", 1, 0},
	{218, ML_CODE_ANDLE, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ANDLE_OUT off K < nb_D", 1, 0},
	{219, ML_CODE_ANDLE, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ANDLE_OUT on K > nb_D", 1, 0},
	{220, ML_CODE_ANDLE, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ANDLE_OUT on K = nb_D", 1, 1},
	{221, ML_CODE_ANDLE, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ANDLE_OUT on K < nb_D", 1, 1},
	{222, ML_CODE_ANDLE, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ANDLE_OUT off S > nb_D", 1, 0},
	{223, ML_CODE_ANDLE, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ANDLE_OUT off S = nb_D", 1, 0},
	{224, ML_CODE_ANDLE, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ANDLE_OUT off S < nb_D", 1, 0},
	{225, ML_CODE_ANDLE, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ANDLE_OUT on S > nb_D", 1, 0},
	{226, ML_CODE_ANDLE, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ANDLE_OUT on S = nb_D", 1, 1},
	{227, ML_CODE_ANDLE, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ANDLE_OUT on S < nb_D", 1, 1},
	{228, ML_CODE_ANDLE, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ANDLE_OUT off nb_S > nb_D", 1, 0},
	{229, ML_CODE_ANDLE, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ANDLE_OUT off nb_S = nb_D", 1, 0},
	{230, ML_CODE_ANDLE, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ANDLE_OUT off nb_S < nb_D", 1, 0},
	{231, ML_CODE_ANDLE, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ANDLE_OUT on nb_S > nb_D", 1, 0},
	{232, ML_CODE_ANDLE, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ANDLE_OUT on nb_S = nb_D", 1, 1},
	{233, ML_CODE_ANDLE, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ANDLE_OUT on nb_S < nb_D", 1, 1},

	{234, ML_CODE_OREQ, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"OREQ_OUT off nb_S > D", 1, 0},
	{235, ML_CODE_OREQ, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"OREQ_OUT off nb_S = D", 1, 1},
	{236, ML_CODE_OREQ, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"OREQ_OUT off nb_S < D", 1, 0},
	{237, ML_CODE_OREQ, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"OREQ_OUT on nb_S > D", 1, 1},
	{238, ML_CODE_OREQ, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"OREQ_OUT on nb_S = D", 1, 1},
	{239, ML_CODE_OREQ, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"OREQ_OUT on nb_S < D", 1, 1},
	{240, ML_CODE_OREQ, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"OREQ_OUT off K > nb_D", 1, 0},
	{241, ML_CODE_OREQ, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"OREQ_OUT off K = nb_D", 1, 1},
	{242, ML_CODE_OREQ, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"OREQ_OUT off K < nb_D", 1, 0},
	{243, ML_CODE_OREQ, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"OREQ_OUT on K > nb_D", 1, 1},
	{244, ML_CODE_OREQ, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"OREQ_OUT on K = nb_D", 1, 1},
	{245, ML_CODE_OREQ, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"OREQ_OUT on K < nb_D", 1, 1},
	{246, ML_CODE_OREQ, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"OREQ_OUT off S > nb_D", 1, 0},
	{247, ML_CODE_OREQ, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"OREQ_OUT off S = nb_D", 1, 1},
	{248, ML_CODE_OREQ, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"OREQ_OUT off S < nb_D", 1, 0},
	{249, ML_CODE_OREQ, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"OREQ_OUT on S > nb_D", 1, 1},
	{250, ML_CODE_OREQ, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"OREQ_OUT on S = nb_D", 1, 1},
	{251, ML_CODE_OREQ, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"OREQ_OUT on S < nb_D", 1, 1},
	{252, ML_CODE_OREQ, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"OREQ_OUT off nb_S > nb_D", 1, 0},
	{253, ML_CODE_OREQ, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"OREQ_OUT off nb_S = nb_D", 1, 1},
	{254, ML_CODE_OREQ, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"OREQ_OUT off nb_S < nb_D", 1, 0},
	{255, ML_CODE_OREQ, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"OREQ_OUT on nb_S > nb_D", 1, 1},
	{256, ML_CODE_OREQ, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"OREQ_OUT on nb_S = nb_D", 1, 1},
	{257, ML_CODE_OREQ, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"OREQ_OUT on nb_S < nb_D", 1, 1},

	{258, ML_CODE_ORNE, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ORNE_OUT off nb_S > D", 1, 1},
	{259, ML_CODE_ORNE, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ORNE_OUT off nb_S = D", 1, 0},
	{260, ML_CODE_ORNE, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ORNE_OUT off nb_S < D", 1, 1},
	{261, ML_CODE_ORNE, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ORNE_OUT on nb_S > D", 1, 1},
	{262, ML_CODE_ORNE, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ORNE_OUT on nb_S = D", 1, 1},
	{263, ML_CODE_ORNE, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ORNE_OUT on nb_S < D", 1, 1},
	{264, ML_CODE_ORNE, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ORNE_OUT off K > nb_D", 1, 1},
	{265, ML_CODE_ORNE, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ORNE_OUT off K = nb_D", 1, 0},
	{266, ML_CODE_ORNE, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ORNE_OUT off K < nb_D", 1, 1},
	{267, ML_CODE_ORNE, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ORNE_OUT on K > nb_D", 1, 1},
	{268, ML_CODE_ORNE, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ORNE_OUT on K = nb_D", 1, 1},
	{269, ML_CODE_ORNE, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ORNE_OUT on K < nb_D", 1, 1},
	{270, ML_CODE_ORNE, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ORNE_OUT off S > nb_D", 1, 1},
	{271, ML_CODE_ORNE, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ORNE_OUT off S = nb_D", 1, 0},
	{272, ML_CODE_ORNE, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ORNE_OUT off S < nb_D", 1, 1},
	{273, ML_CODE_ORNE, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ORNE_OUT on S > nb_D", 1, 1},
	{274, ML_CODE_ORNE, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ORNE_OUT on S = nb_D", 1, 1},
	{275, ML_CODE_ORNE, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ORNE_OUT on S < nb_D", 1, 1},
	{276, ML_CODE_ORNE, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ORNE_OUT off nb_S > nb_D", 1, 1},
	{277, ML_CODE_ORNE, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ORNE_OUT off nb_S = nb_D", 1, 0},
	{278, ML_CODE_ORNE, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ORNE_OUT off nb_S < nb_D", 1, 1},
	{279, ML_CODE_ORNE, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ORNE_OUT on nb_S > nb_D", 1, 1},
	{280, ML_CODE_ORNE, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ORNE_OUT on nb_S = nb_D", 1, 1},
	{281, ML_CODE_ORNE, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ORNE_OUT on nb_S < nb_D", 1, 1},

	{282, ML_CODE_ORGT, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ORGT_OUT off nb_S > D", 1, 1},
	{283, ML_CODE_ORGT, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ORGT_OUT off nb_S = D", 1, 0},
	{284, ML_CODE_ORGT, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ORGT_OUT off nb_S < D", 1, 0},
	{285, ML_CODE_ORGT, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ORGT_OUT on nb_S > D", 1, 1},
	{286, ML_CODE_ORGT, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ORGT_OUT on nb_S = D", 1, 1},
	{287, ML_CODE_ORGT, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ORGT_OUT on nb_S < D", 1, 1},
	{288, ML_CODE_ORGT, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ORGT_OUT off K > nb_D", 1, 1},
	{289, ML_CODE_ORGT, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ORGT_OUT off K = nb_D", 1, 0},
	{290, ML_CODE_ORGT, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ORGT_OUT off K < nb_D", 1, 0},
	{291, ML_CODE_ORGT, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ORGT_OUT on K > nb_D", 1, 1},
	{292, ML_CODE_ORGT, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ORGT_OUT on K = nb_D", 1, 1},
	{293, ML_CODE_ORGT, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ORGT_OUT on K < nb_D", 1, 1},
	{294, ML_CODE_ORGT, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ORGT_OUT off S > nb_D", 1, 1},
	{295, ML_CODE_ORGT, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ORGT_OUT off S = nb_D", 1, 0},
	{296, ML_CODE_ORGT, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ORGT_OUT off S < nb_D", 1, 0},
	{297, ML_CODE_ORGT, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ORGT_OUT on S > nb_D", 1, 1},
	{298, ML_CODE_ORGT, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ORGT_OUT on S = nb_D", 1, 1},
	{299, ML_CODE_ORGT, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ORGT_OUT on S < nb_D", 1, 1},
	{300, ML_CODE_ORGT, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ORGT_OUT off nb_S > nb_D", 1, 1},
	{301, ML_CODE_ORGT, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ORGT_OUT off nb_S = nb_D", 1, 0},
	{302, ML_CODE_ORGT, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ORGT_OUT off nb_S < nb_D", 1, 0},
	{303, ML_CODE_ORGT, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ORGT_OUT on nb_S > nb_D", 1, 1},
	{304, ML_CODE_ORGT, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ORGT_OUT on nb_S = nb_D", 1, 1},
	{305, ML_CODE_ORGT, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ORGT_OUT on nb_S < nb_D", 1, 1},

	{306, ML_CODE_ORGE, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ORGE_OUT off nb_S > D", 1, 1},
	{307, ML_CODE_ORGE, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ORGE_OUT off nb_S = D", 1, 1},
	{308, ML_CODE_ORGE, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ORGE_OUT off nb_S < D", 1, 0},
	{309, ML_CODE_ORGE, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ORGE_OUT on nb_S > D", 1, 1},
	{310, ML_CODE_ORGE, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ORGE_OUT on nb_S = D", 1, 1},
	{311, ML_CODE_ORGE, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ORGE_OUT on nb_S < D", 1, 1},
	{312, ML_CODE_ORGE, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ORGE_OUT off K > nb_D", 1, 1},
	{313, ML_CODE_ORGE, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ORGE_OUT off K = nb_D", 1, 1},
	{314, ML_CODE_ORGE, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ORGE_OUT off K < nb_D", 1, 0},
	{315, ML_CODE_ORGE, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ORGE_OUT on K > nb_D", 1, 1},
	{316, ML_CODE_ORGE, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ORGE_OUT on K = nb_D", 1, 1},
	{317, ML_CODE_ORGE, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ORGE_OUT on K < nb_D", 1, 1},
	{318, ML_CODE_ORGE, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ORGE_OUT off S > nb_D", 1, 1},
	{319, ML_CODE_ORGE, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ORGE_OUT off S = nb_D", 1, 1},
	{320, ML_CODE_ORGE, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ORGE_OUT off S < nb_D", 1, 0},
	{321, ML_CODE_ORGE, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ORGE_OUT on S > nb_D", 1, 1},
	{322, ML_CODE_ORGE, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ORGE_OUT on S = nb_D", 1, 1},
	{323, ML_CODE_ORGE, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ORGE_OUT on S < nb_D", 1, 1},
	{324, ML_CODE_ORGE, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ORGE_OUT off nb_S > nb_D", 1, 1},
	{325, ML_CODE_ORGE, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ORGE_OUT off nb_S = nb_D", 1, 1},
	{326, ML_CODE_ORGE, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ORGE_OUT off nb_S < nb_D", 1, 0},
	{327, ML_CODE_ORGE, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ORGE_OUT on nb_S > nb_D", 1, 1},
	{328, ML_CODE_ORGE, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ORGE_OUT on nb_S = nb_D", 1, 1},
	{329, ML_CODE_ORGE, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ORGE_OUT on nb_S < nb_D", 1, 1},

	{330, ML_CODE_ORLT, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ORLT_OUT off nb_S > D", 1, 0},
	{331, ML_CODE_ORLT, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ORLT_OUT off nb_S = D", 1, 0},
	{332, ML_CODE_ORLT, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ORLT_OUT off nb_S < D", 1, 1},
	{333, ML_CODE_ORLT, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ORLT_OUT on nb_S > D", 1, 1},
	{334, ML_CODE_ORLT, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ORLT_OUT on nb_S = D", 1, 1},
	{335, ML_CODE_ORLT, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ORLT_OUT on nb_S < D", 1, 1},
	{336, ML_CODE_ORLT, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ORLT_OUT off K > nb_D", 1, 0},
	{337, ML_CODE_ORLT, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ORLT_OUT off K = nb_D", 1, 0},
	{338, ML_CODE_ORLT, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ORLT_OUT off K < nb_D", 1, 1},
	{339, ML_CODE_ORLT, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ORLT_OUT on K > nb_D", 1, 1},
	{340, ML_CODE_ORLT, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ORLT_OUT on K = nb_D", 1, 1},
	{341, ML_CODE_ORLT, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ORLT_OUT on K < nb_D", 1, 1},
	{342, ML_CODE_ORLT, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ORLT_OUT off S > nb_D", 1, 0},
	{343, ML_CODE_ORLT, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ORLT_OUT off S = nb_D", 1, 0},
	{344, ML_CODE_ORLT, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ORLT_OUT off S < nb_D", 1, 1},
	{345, ML_CODE_ORLT, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ORLT_OUT on S > nb_D", 1, 1},
	{346, ML_CODE_ORLT, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ORLT_OUT on S = nb_D", 1, 1},
	{347, ML_CODE_ORLT, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ORLT_OUT on S < nb_D", 1, 1},
	{348, ML_CODE_ORLT, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ORLT_OUT off nb_S > nb_D", 1, 0},
	{349, ML_CODE_ORLT, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ORLT_OUT off nb_S = nb_D", 1, 0},
	{350, ML_CODE_ORLT, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ORLT_OUT off nb_S < nb_D", 1, 1},
	{351, ML_CODE_ORLT, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ORLT_OUT on nb_S > nb_D", 1, 1},
	{352, ML_CODE_ORLT, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ORLT_OUT on nb_S = nb_D", 1, 1},
	{353, ML_CODE_ORLT, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ORLT_OUT on nb_S < nb_D", 1, 1},

	{354, ML_CODE_ORLE, setCodeAND_OR_N_W, setInputDIn_N_W_off_bigVal16, verifyResultNormal,
			"ORLE_OUT off nb_S > D", 1, 0},
	{355, ML_CODE_ORLE, setCodeAND_OR_N_W, setInputDIn_N_W_off_sameVal16, verifyResultNormal,
			"ORLE_OUT off nb_S = D", 1, 1},
	{356, ML_CODE_ORLE, setCodeAND_OR_N_W, setInputDIn_N_W_off_lessVal16, verifyResultNormal,
			"ORLE_OUT off nb_S < D", 1, 1},
	{357, ML_CODE_ORLE, setCodeAND_OR_N_W, setInputDIn_N_W_on_bigVal16, verifyResultNormal,
			"ORLE_OUT on nb_S > D", 1, 1},
	{358, ML_CODE_ORLE, setCodeAND_OR_N_W, setInputDIn_N_W_on_sameVal16, verifyResultNormal,
			"ORLE_OUT on nb_S = D", 1, 1},
	{359, ML_CODE_ORLE, setCodeAND_OR_N_W, setInputDIn_N_W_on_lessVal16, verifyResultNormal,
			"ORLE_OUT on nb_S < D", 1, 1},
	{360, ML_CODE_ORLE, setCodeAND_OR_K_N, setInputSIn_N_K_off_bigVal16, verifyResultNormal,
			"ORLE_OUT off K > nb_D", 1, 0},
	{361, ML_CODE_ORLE, setCodeAND_OR_K_N, setInputSIn_N_K_off_sameVal16, verifyResultNormal,
			"ORLE_OUT off K = nb_D", 1, 1},
	{362, ML_CODE_ORLE, setCodeAND_OR_K_N, setInputSIn_N_K_off_lessVal16, verifyResultNormal,
			"ORLE_OUT off K < nb_D", 1, 1},
	{363, ML_CODE_ORLE, setCodeAND_OR_K_N, setInputSIn_N_K_on_bigVal16, verifyResultNormal,
			"ORLE_OUT on K > nb_D", 1, 1},
	{364, ML_CODE_ORLE, setCodeAND_OR_K_N, setInputSIn_N_K_on_sameVal16, verifyResultNormal,
			"ORLE_OUT on K = nb_D", 1, 1},
	{365, ML_CODE_ORLE, setCodeAND_OR_K_N, setInputSIn_N_K_on_lessVal16, verifyResultNormal,
			"ORLE_OUT on K < nb_D", 1, 1},
	{366, ML_CODE_ORLE, setCodeAND_OR_W_N, setInputDIn_W_N_off_bigVal16, verifyResultNormal,
			"ORLE_OUT off S > nb_D", 1, 0},
	{367, ML_CODE_ORLE, setCodeAND_OR_W_N, setInputDIn_W_N_off_sameVal16, verifyResultNormal,
			"ORLE_OUT off S = nb_D", 1, 1},
	{368, ML_CODE_ORLE, setCodeAND_OR_W_N, setInputDIn_W_N_off_lessVal16, verifyResultNormal,
			"ORLE_OUT off S < nb_D", 1, 1},
	{369, ML_CODE_ORLE, setCodeAND_OR_W_N, setInputDIn_W_N_on_bigVal16, verifyResultNormal,
			"ORLE_OUT on S > nb_D", 1, 1},
	{370, ML_CODE_ORLE, setCodeAND_OR_W_N, setInputDIn_W_N_on_sameVal16, verifyResultNormal,
			"ORLE_OUT on S = nb_D", 1, 1},
	{371, ML_CODE_ORLE, setCodeAND_OR_W_N, setInputDIn_W_N_on_lessVal16, verifyResultNormal,
			"ORLE_OUT on S < nb_D", 1, 1},
	{372, ML_CODE_ORLE, setCodeAND_OR_N_N, setInputDIn_N_N_off_bigVal16, verifyResultNormal,
			"ORLE_OUT off nb_S > nb_D", 1, 0},
	{373, ML_CODE_ORLE, setCodeAND_OR_N_N, setInputDIn_N_N_off_sameVal16, verifyResultNormal,
			"ORLE_OUT off nb_S = nb_D", 1, 1},
	{374, ML_CODE_ORLE, setCodeAND_OR_N_N, setInputDIn_N_N_off_lessVal16, verifyResultNormal,
			"ORLE_OUT off nb_S < nb_D", 1, 1},
	{375, ML_CODE_ORLE, setCodeAND_OR_N_N, setInputDIn_N_N_on_bigVal16, verifyResultNormal,
			"ORLE_OUT on nb_S > nb_D", 1, 1},
	{376, ML_CODE_ORLE, setCodeAND_OR_N_N, setInputDIn_N_N_on_sameVal16, verifyResultNormal,
			"ORLE_OUT on nb_S = nb_D", 1, 1},
	{377, ML_CODE_ORLE, setCodeAND_OR_N_N, setInputDIn_N_N_on_lessVal16, verifyResultNormal,
			"ORLE_OUT on nb_S < nb_D", 1, 1},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};

int total_basic_comp_word_nibble_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_comp_word_nibble_test_number; i++)
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


//compare with 16bit registers
int setCodeLD16_N_W_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B || in2_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(4, in1_reg, in1_pos); addMLOperand(in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


int setCodeLD16_W_N_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg < OPERAND_ML_CODE_D || in2_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in1_reg, in1_pos); addMLOperandNibble(4, in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD16_N_N_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B || in2_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(4, in1_reg, in1_pos); addMLOperandNibble(4, in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

//compare with 16bit constant
int setCodeLD16_N_K_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B || in2_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(4, in1_reg, in1_pos); addMLOperand(OPERAND_ML_CODE_K, 257);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

//compare with 16bit negative constant
int setCodeLD16_N_nK_OUT(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B || in2_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(4, in1_reg, in1_pos); addMLOperand(OPERAND_ML_CODE_K, -257);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeAND_OR_N_W(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B || in2_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in1_reg, in1_pos); addMLOperand(in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeAND_OR_K_N(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B || in2_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 256); addMLOperandNibble(4, in1_reg, in1_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeAND_OR_N_N(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B || in2_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in1_reg, in1_pos); addMLOperandNibble(4, in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeAND_OR_W_N(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg < OPERAND_ML_CODE_D || in2_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1_reg, in1_pos); addMLOperandNibble(4, in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputDIn_N_W_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in2, 160, 256);

	TestCodeTearDown();
}

void setInputDIn_N_W_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in2, 160, 257);

	TestCodeTearDown();
}

void setInputDIn_N_W_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=256;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in2, 160, 257);

	TestCodeTearDown();
}


void setInputDIn_W_N_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=256;

	addDeviceControlInstruction(0, (uint8)in1, in_pos, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, (uint8)in1, in_pos, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, (uint8)in1, in_pos, 256);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value1=257;
	short value2=256;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value1=256;
	short value2=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputSIn_N_K_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=258;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=256;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_nK_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=-256;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_nK_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=-257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_nK_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=-258;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_off_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=255;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_off_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=256;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_off_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputDIn_N_N_off_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value1=257;
	short value2=256;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_off_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_on_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value1=257;
	short value2=256;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_on_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_on_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value1=256;
	short value2=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_off_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value1=256;
	short value2=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputSIn_N_K_on_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=255;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_on_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=256;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_on_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_W_off_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in2, 160, 256);

	TestCodeTearDown();
}

void setInputDIn_N_W_off_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in2, 160, 257);

	TestCodeTearDown();
}

void setInputDIn_N_W_off_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=256;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in2, 160, 257);

	TestCodeTearDown();
}


void setInputDIn_N_W_on_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;


	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in2, 160, 256);

	TestCodeTearDown();
}

void setInputDIn_N_W_on_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in2, 160, 257);

	TestCodeTearDown();
}

void setInputDIn_N_W_on_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=256;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in2, 160, 257);

	TestCodeTearDown();
}

void setInputDIn_W_N_off_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=256;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in_pos, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_off_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in_pos, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_off_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in_pos, 256);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_on_bigVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=256;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in_pos, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_on_sameVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in_pos, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_on_lessVal16(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in_pos, 256);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}


static uint16 getInRegPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12287,8191}};

	return pos[inx_pos][reg];
}

static uint16 getOutBitRegPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096},
			{8191,8191,8191,8191,2047,8191}};

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_compare_word_nibble(int tno, uint16 dummy)
{
	int i, rc=0, rc2=1, olast=0;
	uint8 in1=0, in2, out=0;
	uint16 in_pos, out_pos;
	uint8 res_bit;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			if(out==OPERAND_ML_CODE_F) continue;

			out_pos = getOutBitRegPos(out, olast);
			for( in1=OPERAND_ML_CODE_X; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_X; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getInRegPos(in1, i);

						if( in1 == out && (in_pos == out_pos || in_pos+16 == out_pos))
						{
							continue;
						}

						rc2=testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in1, in_pos, (uint8)in2, (uint8)out, out_pos);
						if(rc2 == 0) continue;

						testCase[tno].setTestInput_fn(in1, in_pos, in2, out, out_pos);

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
								test_getBit(&res_bit, out, out_pos);
								fprintf(flog, "test_no[%d]: %s command error! in1_%s[%d], in2_%s[160], out_%s[%d]=%d exp=%d\n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
									reg[in1], in_pos, reg[in2], reg[out], out_pos, res_bit, testCase[tno].expected);
							}
						}
					}
				}
			}
		}
	}
}

void testBasicCompareWordNibbleCommand(void)
{
	int index=1;
	int start, end;
	char log[] = "err_comp_word_nibble.txt";

#if 0
	//for(index=0; index<10; index++)
		test_compare_word_nibble(index, 0);
#else
	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare word nibble LOG file open error !\n");
		exit(1);
	}

	total_basic_comp_word_nibble_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LDEQ);
	end = getTestCaseNumberEnd(ML_CODE_ORLE);

	DBG_LOGPRINT("testBasicCompareWordNibbleCommand: %d to %d total %d\n", start, end, total_basic_comp_word_nibble_test_number);
	for(index=start; index<=end; index++)
	{
		test_compare_word_nibble(index, 0);
	}

	fclose(flog);
#endif
}

#endif
