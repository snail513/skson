/*
 * test_basic_compare_dword_nibble.c
 *
 *  Created on: Jun 24, 2015
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

int setCodeLD32x_N_W(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeLD32x_W_N(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeLD32x_N_N(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeLD32x_N_K(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeLD32x_N_nK(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeAND_OR_32x_N_W(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeAND_OR_32x_W_N(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeAND_OR_32x_N_N(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);
int setCodeAND_OR_32x_N_K(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos);

void setInputDIn_N_W_hbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_hlessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_lbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_llessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_sameVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputDIn_W_N_hbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_hlessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_lbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_llessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_sameVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputDIn_N_N_hbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_hlessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_lbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_llessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_sameVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputSIn_N_K_hbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_lbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_hlessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_llessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_sameVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputDIn_N_W_hbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_hlessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_lbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_llessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_sameVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_hbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_hlessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_lbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_llessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_W_sameVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputDIn_W_N_hbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_hlessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_lbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_llessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_sameVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_hbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_hlessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_lbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_llessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_W_N_sameVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputDIn_N_N_hbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_hlessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_lbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_llessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_sameVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_hbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_hlessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_lbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_llessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputDIn_N_N_sameVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

void setInputSIn_N_K_hbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_hlessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_lbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_llessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_sameVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_hbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_hlessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_lbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_llessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);
void setInputSIn_N_K_sameVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos);

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, uint8);
	char str[30];
	int run_step;
	int expected;

} testFn_st;



static testFn_st testCase[]={
	{0, ML_CODE_LDDEQ, setCodeLD32x_N_W, setInputDIn_N_W_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT high nop1 > op2", 1, 0 },
	{1, ML_CODE_LDDEQ, setCodeLD32x_N_W, setInputDIn_N_W_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT low nop1 > op2", 1, 0 },
	{2, ML_CODE_LDDEQ, setCodeLD32x_N_W, setInputDIn_N_W_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT high nop1 < op2", 1, 0 },
	{3, ML_CODE_LDDEQ, setCodeLD32x_N_W, setInputDIn_N_W_llessVal32, verifyResultNormal,
			"LDDEQ_OUT low nop1 < op2", 1, 0 },
	{4, ML_CODE_LDDEQ, setCodeLD32x_N_W, setInputDIn_N_W_sameVal32, verifyResultNormal,
			"LDDEQ_OUT nop1 == op2", 1, 1},
	{5, ML_CODE_LDDEQ, setCodeLD32x_W_N, setInputDIn_W_N_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT high nop1 > op2", 1, 0 },
	{6, ML_CODE_LDDEQ, setCodeLD32x_W_N, setInputDIn_W_N_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT low nop1 > op2", 1, 0 },
	{7, ML_CODE_LDDEQ, setCodeLD32x_W_N, setInputDIn_W_N_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT high nop1 < op2", 1, 0 },
	{8, ML_CODE_LDDEQ, setCodeLD32x_W_N, setInputDIn_W_N_llessVal32, verifyResultNormal,
			"LDDEQ_OUT low nop1 < op2", 1, 0 },
	{9, ML_CODE_LDDEQ, setCodeLD32x_W_N, setInputDIn_W_N_sameVal32, verifyResultNormal,
			"LDDEQ_OUT nop1 == op2", 1, 1},
	{10, ML_CODE_LDDEQ, setCodeLD32x_N_N, setInputDIn_N_N_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT high nop1 > nop2", 1, 0},
	{11, ML_CODE_LDDEQ, setCodeLD32x_N_N, setInputDIn_N_N_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT low nop1 > nop2", 1, 0},
	{12, ML_CODE_LDDEQ, setCodeLD32x_N_N, setInputDIn_N_N_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT high nop1 < nop2", 1, 0},
	{13, ML_CODE_LDDEQ, setCodeLD32x_N_N, setInputDIn_N_N_llessVal32, verifyResultNormal,
			"LDDEQ_OUT low nop1 < nop2", 1, 0},
	{14, ML_CODE_LDDEQ, setCodeLD32x_N_N, setInputDIn_N_N_sameVal32, verifyResultNormal,
			"LDDEQ_OUT nop1 == nop2", 1, 1},
	{15, ML_CODE_LDDEQ, setCodeLD32x_N_K, setInputSIn_N_K_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT high nop1 > K", 1, 0},
	{16, ML_CODE_LDDEQ, setCodeLD32x_N_K, setInputSIn_N_K_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT low nop1 > K", 1, 0},
	{17, ML_CODE_LDDEQ, setCodeLD32x_N_K, setInputSIn_N_K_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT high nop1 < K", 1, 0},
	{18, ML_CODE_LDDEQ, setCodeLD32x_N_K, setInputSIn_N_K_llessVal32, verifyResultNormal,
			"LDDEQ_OUT low nop1 < K", 1, 0},
	{19, ML_CODE_LDDEQ, setCodeLD32x_N_K, setInputSIn_N_K_sameVal32, verifyResultNormal,
			"LDDEQ_OUT nop1 == K", 1, 1},

	{20, ML_CODE_LDDNE, setCodeLD32x_N_W, setInputDIn_N_W_hbigVal32, verifyResultNormal,
			"LDDNE_OUT high nop1 > op2", 1, 1 },
	{21, ML_CODE_LDDNE, setCodeLD32x_N_W, setInputDIn_N_W_lbigVal32, verifyResultNormal,
			"LDDNE_OUT low nop1 > op2", 1, 1 },
	{22, ML_CODE_LDDNE, setCodeLD32x_N_W, setInputDIn_N_W_hlessVal32, verifyResultNormal,
			"LDDNE_OUT high nop1 < op2", 1, 1 },
	{23, ML_CODE_LDDNE, setCodeLD32x_N_W, setInputDIn_N_W_llessVal32, verifyResultNormal,
			"LDDNE_OUT low nop1 < op2", 1, 1 },
	{24, ML_CODE_LDDNE, setCodeLD32x_N_W, setInputDIn_N_W_sameVal32, verifyResultNormal,
			"LDDNE_OUT nop1 == op2", 1, 0},
	{25, ML_CODE_LDDNE, setCodeLD32x_W_N, setInputDIn_W_N_hbigVal32, verifyResultNormal,
			"LDDNE_OUT high nop1 > op2", 1, 1 },
	{26, ML_CODE_LDDNE, setCodeLD32x_W_N, setInputDIn_W_N_lbigVal32, verifyResultNormal,
			"LDDNE_OUT low nop1 > op2", 1, 1 },
	{27, ML_CODE_LDDNE, setCodeLD32x_W_N, setInputDIn_W_N_hlessVal32, verifyResultNormal,
			"LDDNE_OUT high nop1 < op2", 1, 1 },
	{28, ML_CODE_LDDNE, setCodeLD32x_W_N, setInputDIn_W_N_llessVal32, verifyResultNormal,
			"LDDNE_OUT low nop1 < op2", 1, 1 },
	{29, ML_CODE_LDDNE, setCodeLD32x_W_N, setInputDIn_W_N_sameVal32, verifyResultNormal,
			"LDDNE_OUT nibble_op1 == op2", 1, 0},
	{30, ML_CODE_LDDNE, setCodeLD32x_N_N, setInputDIn_N_N_hbigVal32, verifyResultNormal,
			"LDDNE_OUT high nop1 > nop2", 1, 1},
	{31, ML_CODE_LDDNE, setCodeLD32x_N_N, setInputDIn_N_N_lbigVal32, verifyResultNormal,
			"LDDNE_OUT low nop1 > nop2", 1, 1},
	{32, ML_CODE_LDDNE, setCodeLD32x_N_N, setInputDIn_N_N_hlessVal32, verifyResultNormal,
			"LDDNE_OUT high nop1 < nop2", 1, 1},
	{33, ML_CODE_LDDNE, setCodeLD32x_N_N, setInputDIn_N_N_llessVal32, verifyResultNormal,
			"LDDNE_OUT low nop1 < nop2", 1, 1},
	{34, ML_CODE_LDDNE, setCodeLD32x_N_N, setInputDIn_N_N_sameVal32, verifyResultNormal,
			"LDDNE_OUT nop1 == nop2", 1, 0},
	{35, ML_CODE_LDDNE, setCodeLD32x_N_K, setInputSIn_N_K_hbigVal32, verifyResultNormal,
			"LDDNE_OUT high nop1 > K", 1, 1},
	{36, ML_CODE_LDDNE, setCodeLD32x_N_K, setInputSIn_N_K_lbigVal32, verifyResultNormal,
			"LDDNE_OUT low nop1 > K", 1, 1},
	{37, ML_CODE_LDDNE, setCodeLD32x_N_K, setInputSIn_N_K_hlessVal32, verifyResultNormal,
			"LDDNE_OUT high nop1 < K", 1, 1},
	{38, ML_CODE_LDDNE, setCodeLD32x_N_K, setInputSIn_N_K_llessVal32, verifyResultNormal,
			"LDDNE_OUT low nop1 < K", 1, 1},
	{39, ML_CODE_LDDNE, setCodeLD32x_N_K, setInputSIn_N_K_sameVal32, verifyResultNormal,
			"LDDNE_OUT nop1 == K", 1, 0},

	{40, ML_CODE_LDDGT, setCodeLD32x_N_W, setInputDIn_N_W_hbigVal32, verifyResultNormal,
			"LDDGT_OUT high nop1 > op2", 1, 1 },
	{41, ML_CODE_LDDGT, setCodeLD32x_N_W, setInputDIn_N_W_lbigVal32, verifyResultNormal,
			"LDDGT_OUT low nop1 > op2", 1, 1 },
	{42, ML_CODE_LDDGT, setCodeLD32x_N_W, setInputDIn_N_W_hlessVal32, verifyResultNormal,
			"LDDGT_OUT high nop1 < op2", 1, 0 },
	{43, ML_CODE_LDDGT, setCodeLD32x_N_W, setInputDIn_N_W_llessVal32, verifyResultNormal,
			"LDDGT_OUT low nop1 < op2", 1, 0 },
	{44, ML_CODE_LDDGT, setCodeLD32x_N_W, setInputDIn_N_W_sameVal32, verifyResultNormal,
			"LDDGT_OUT nop1 == op2", 1, 0},
	{45, ML_CODE_LDDGT, setCodeLD32x_W_N, setInputDIn_W_N_hbigVal32, verifyResultNormal,
			"LDDGT_OUT high nop1 > op2", 1, 1 },
	{46, ML_CODE_LDDGT, setCodeLD32x_W_N, setInputDIn_W_N_lbigVal32, verifyResultNormal,
			"LDDGT_OUT low nop1 > op2", 1, 1 },
	{47, ML_CODE_LDDGT, setCodeLD32x_W_N, setInputDIn_W_N_hlessVal32, verifyResultNormal,
			"LDDGT_OUT high nop1 < op2", 1, 0 },
	{48, ML_CODE_LDDGT, setCodeLD32x_W_N, setInputDIn_W_N_llessVal32, verifyResultNormal,
			"LDDGT_OUT low nop1 < op2", 1, 0 },
	{49, ML_CODE_LDDGT, setCodeLD32x_W_N, setInputDIn_W_N_sameVal32, verifyResultNormal,
			"LDDGT_OUT nibble_op1 == op2", 1, 0},
	{50, ML_CODE_LDDGT, setCodeLD32x_N_N, setInputDIn_N_N_hbigVal32, verifyResultNormal,
			"LDDGT_OUT high nop1 > nop2", 1, 1},
	{51, ML_CODE_LDDGT, setCodeLD32x_N_N, setInputDIn_N_N_lbigVal32, verifyResultNormal,
			"LDDGT_OUT low nop1 > nop2", 1, 1},
	{52, ML_CODE_LDDGT, setCodeLD32x_N_N, setInputDIn_N_N_hlessVal32, verifyResultNormal,
			"LDDGT_OUT high nop1 < nop2", 1, 0},
	{53, ML_CODE_LDDGT, setCodeLD32x_N_N, setInputDIn_N_N_llessVal32, verifyResultNormal,
			"LDDGT_OUT low nop1 < nop2", 1, 0},
	{54, ML_CODE_LDDGT, setCodeLD32x_N_N, setInputDIn_N_N_sameVal32, verifyResultNormal,
			"LDDGT_OUT nop1 == nop2", 1, 0},
	{55, ML_CODE_LDDGT, setCodeLD32x_N_K, setInputSIn_N_K_hbigVal32, verifyResultNormal,
			"LDDGT_OUT high nop1 > K", 1, 1},
	{56, ML_CODE_LDDGT, setCodeLD32x_N_K, setInputSIn_N_K_lbigVal32, verifyResultNormal,
			"LDDGT_OUT low nop1 > K", 1, 1},
	{57, ML_CODE_LDDGT, setCodeLD32x_N_K, setInputSIn_N_K_hlessVal32, verifyResultNormal,
			"LDDGT_OUT high nop1 < K", 1, 0},
	{58, ML_CODE_LDDGT, setCodeLD32x_N_K, setInputSIn_N_K_llessVal32, verifyResultNormal,
			"LDDGT_OUT low nop1 < K", 1, 0},
	{59, ML_CODE_LDDGT, setCodeLD32x_N_K, setInputSIn_N_K_sameVal32, verifyResultNormal,
			"LDDGT_OUT nop1 == K", 1, 0},

	{60, ML_CODE_LDDGE, setCodeLD32x_N_W, setInputDIn_N_W_hbigVal32, verifyResultNormal,
			"LDDGE_OUT high nop1 > op2", 1, 1 },
	{61, ML_CODE_LDDGE, setCodeLD32x_N_W, setInputDIn_N_W_lbigVal32, verifyResultNormal,
			"LDDGE_OUT low nop1 > op2", 1, 1 },
	{62, ML_CODE_LDDGE, setCodeLD32x_N_W, setInputDIn_N_W_hlessVal32, verifyResultNormal,
			"LDDGE_OUT high nop1 < op2", 1, 0 },
	{63, ML_CODE_LDDGE, setCodeLD32x_N_W, setInputDIn_N_W_llessVal32, verifyResultNormal,
			"LDDGE_OUT low nop1 < op2", 1, 0 },
	{64, ML_CODE_LDDGE, setCodeLD32x_N_W, setInputDIn_N_W_sameVal32, verifyResultNormal,
			"LDDGE_OUT nop1 == op2", 1, 1},
	{65, ML_CODE_LDDGE, setCodeLD32x_W_N, setInputDIn_W_N_hbigVal32, verifyResultNormal,
			"LDDGE_OUT high nop1 > op2", 1, 1 },
	{66, ML_CODE_LDDGE, setCodeLD32x_W_N, setInputDIn_W_N_lbigVal32, verifyResultNormal,
			"LDDGE_OUT low nop1 > op2", 1, 1 },
	{67, ML_CODE_LDDGE, setCodeLD32x_W_N, setInputDIn_W_N_hlessVal32, verifyResultNormal,
			"LDDGE_OUT high nop1 < op2", 1, 0 },
	{68, ML_CODE_LDDGE, setCodeLD32x_W_N, setInputDIn_W_N_llessVal32, verifyResultNormal,
			"LDDGE_OUT low nop1 < op2", 1, 0 },
	{69, ML_CODE_LDDGE, setCodeLD32x_W_N, setInputDIn_W_N_sameVal32, verifyResultNormal,
			"LDDGE_OUT nibble_op1 == op2", 1, 1},
	{70, ML_CODE_LDDGE, setCodeLD32x_N_N, setInputDIn_N_N_hbigVal32, verifyResultNormal,
			"LDDGE_OUT high nop1 > nop2", 1, 1},
	{71, ML_CODE_LDDGE, setCodeLD32x_N_N, setInputDIn_N_N_lbigVal32, verifyResultNormal,
			"LDDGE_OUT low nop1 > nop2", 1, 1},
	{72, ML_CODE_LDDGE, setCodeLD32x_N_N, setInputDIn_N_N_hlessVal32, verifyResultNormal,
			"LDDGE_OUT high nop1 < nop2", 1, 0},
	{73, ML_CODE_LDDGE, setCodeLD32x_N_N, setInputDIn_N_N_llessVal32, verifyResultNormal,
			"LDDGE_OUT low nop1 < nop2", 1, 0},
	{74, ML_CODE_LDDGE, setCodeLD32x_N_N, setInputDIn_N_N_sameVal32, verifyResultNormal,
			"LDDGE_OUT nop1 == nop2", 1, 1},
	{75, ML_CODE_LDDGE, setCodeLD32x_N_K, setInputSIn_N_K_hbigVal32, verifyResultNormal,
			"LDDGE_OUT high nop1 > K", 1, 1},
	{76, ML_CODE_LDDGE, setCodeLD32x_N_K, setInputSIn_N_K_lbigVal32, verifyResultNormal,
			"LDDGE_OUT low nop1 > K", 1, 1},
	{77, ML_CODE_LDDGE, setCodeLD32x_N_K, setInputSIn_N_K_hlessVal32, verifyResultNormal,
			"LDDGE_OUT high nop1 < K", 1, 0},
	{78, ML_CODE_LDDGE, setCodeLD32x_N_K, setInputSIn_N_K_llessVal32, verifyResultNormal,
			"LDDGE_OUT low nop1 < K", 1, 0},
	{79, ML_CODE_LDDGE, setCodeLD32x_N_K, setInputSIn_N_K_sameVal32, verifyResultNormal,
			"LDDGE_OUT nop1 == K", 1, 1},

	{80, ML_CODE_LDDLT, setCodeLD32x_N_W, setInputDIn_N_W_hbigVal32, verifyResultNormal,
			"LDDLT_OUT high nop1 > op2", 1, 0 },
	{81, ML_CODE_LDDLT, setCodeLD32x_N_W, setInputDIn_N_W_lbigVal32, verifyResultNormal,
			"LDDLT_OUT low nop1 > op2", 1, 0 },
	{82, ML_CODE_LDDLT, setCodeLD32x_N_W, setInputDIn_N_W_hlessVal32, verifyResultNormal,
			"LDDLT_OUT high nop1 < op2", 1, 1 },
	{83, ML_CODE_LDDLT, setCodeLD32x_N_W, setInputDIn_N_W_llessVal32, verifyResultNormal,
			"LDDLT_OUT low nop1 < op2", 1, 1 },
	{84, ML_CODE_LDDLT, setCodeLD32x_N_W, setInputDIn_N_W_sameVal32, verifyResultNormal,
			"LDDLT_OUT nop1 == op2", 1, 0},
	{85, ML_CODE_LDDLT, setCodeLD32x_W_N, setInputDIn_W_N_hbigVal32, verifyResultNormal,
			"LDDLT_OUT high nop1 > op2", 1, 0 },
	{86, ML_CODE_LDDLT, setCodeLD32x_W_N, setInputDIn_W_N_lbigVal32, verifyResultNormal,
			"LDDLT_OUT low nop1 > op2", 1, 0 },
	{87, ML_CODE_LDDLT, setCodeLD32x_W_N, setInputDIn_W_N_hlessVal32, verifyResultNormal,
			"LDDLT_OUT high nop1 < op2", 1, 1 },
	{88, ML_CODE_LDDLT, setCodeLD32x_W_N, setInputDIn_W_N_llessVal32, verifyResultNormal,
			"LDDLT_OUT low nop1 < op2", 1, 1 },
	{89, ML_CODE_LDDLT, setCodeLD32x_W_N, setInputDIn_W_N_sameVal32, verifyResultNormal,
			"LDDLT_OUT nibble_op1 == op2", 1, 0},
	{90, ML_CODE_LDDLT, setCodeLD32x_N_N, setInputDIn_N_N_hbigVal32, verifyResultNormal,
			"LDDLT_OUT high nop1 > nop2", 1, 0},
	{91, ML_CODE_LDDLT, setCodeLD32x_N_N, setInputDIn_N_N_lbigVal32, verifyResultNormal,
			"LDDLT_OUT low nop1 > nop2", 1, 0},
	{92, ML_CODE_LDDLT, setCodeLD32x_N_N, setInputDIn_N_N_hlessVal32, verifyResultNormal,
			"LDDLT_OUT high nop1 < nop2", 1, 1},
	{93, ML_CODE_LDDLT, setCodeLD32x_N_N, setInputDIn_N_N_llessVal32, verifyResultNormal,
			"LDDLT_OUT low nop1 < nop2", 1, 1},
	{94, ML_CODE_LDDLT, setCodeLD32x_N_N, setInputDIn_N_N_sameVal32, verifyResultNormal,
			"LDDLT_OUT nop1 == nop2", 1, 0},
	{95, ML_CODE_LDDLT, setCodeLD32x_N_K, setInputSIn_N_K_hbigVal32, verifyResultNormal,
			"LDDLT_OUT high nop1 > K", 1, 0},
	{96, ML_CODE_LDDLT, setCodeLD32x_N_K, setInputSIn_N_K_lbigVal32, verifyResultNormal,
			"LDDLT_OUT low nop1 > K", 1, 0},
	{97, ML_CODE_LDDLT, setCodeLD32x_N_K, setInputSIn_N_K_hlessVal32, verifyResultNormal,
			"LDDLT_OUT high nop1 < K", 1, 1},
	{98, ML_CODE_LDDLT, setCodeLD32x_N_K, setInputSIn_N_K_llessVal32, verifyResultNormal,
			"LDDLT_OUT low nop1 < K", 1, 1},
	{99, ML_CODE_LDDLT, setCodeLD32x_N_K, setInputSIn_N_K_sameVal32, verifyResultNormal,
			"LDDLT_OUT nop1 == K", 1, 0},

	{100, ML_CODE_LDDLE, setCodeLD32x_N_W, setInputDIn_N_W_hbigVal32, verifyResultNormal,
			"LDDLE_OUT high nop1 > op2", 1, 0 },
	{101, ML_CODE_LDDLE, setCodeLD32x_N_W, setInputDIn_N_W_lbigVal32, verifyResultNormal,
			"LDDLE_OUT low nop1 > op2", 1, 0 },
	{102, ML_CODE_LDDLE, setCodeLD32x_N_W, setInputDIn_N_W_hlessVal32, verifyResultNormal,
			"LDDLE_OUT high nop1 < op2", 1, 1 },
	{103, ML_CODE_LDDLE, setCodeLD32x_N_W, setInputDIn_N_W_llessVal32, verifyResultNormal,
			"LDDLE_OUT low nop1 < op2", 1, 1 },
	{104, ML_CODE_LDDLE, setCodeLD32x_N_W, setInputDIn_N_W_sameVal32, verifyResultNormal,
			"LDDLE_OUT nop1 == op2", 1, 1},
	{105, ML_CODE_LDDLE, setCodeLD32x_W_N, setInputDIn_W_N_hbigVal32, verifyResultNormal,
			"LDDLE_OUT high nop1 > op2", 1, 0 },
	{106, ML_CODE_LDDLE, setCodeLD32x_W_N, setInputDIn_W_N_lbigVal32, verifyResultNormal,
			"LDDLE_OUT low nop1 > op2", 1, 0 },
	{107, ML_CODE_LDDLE, setCodeLD32x_W_N, setInputDIn_W_N_hlessVal32, verifyResultNormal,
			"LDDLE_OUT high nop1 < op2", 1, 1 },
	{108, ML_CODE_LDDLE, setCodeLD32x_W_N, setInputDIn_W_N_llessVal32, verifyResultNormal,
			"LDDLE_OUT low nop1 < op2", 1, 1 },
	{109, ML_CODE_LDDLE, setCodeLD32x_W_N, setInputDIn_W_N_sameVal32, verifyResultNormal,
			"LDDLE_OUT nibble_op1 == op2", 1, 1},
	{110, ML_CODE_LDDLE, setCodeLD32x_N_N, setInputDIn_N_N_hbigVal32, verifyResultNormal,
			"LDDLE_OUT high nop1 > nop2", 1, 0},
	{111, ML_CODE_LDDLE, setCodeLD32x_N_N, setInputDIn_N_N_lbigVal32, verifyResultNormal,
			"LDDLE_OUT low nop1 > nop2", 1, 0},
	{112, ML_CODE_LDDLE, setCodeLD32x_N_N, setInputDIn_N_N_hlessVal32, verifyResultNormal,
			"LDDLE_OUT high nop1 < nop2", 1, 1},
	{113, ML_CODE_LDDLE, setCodeLD32x_N_N, setInputDIn_N_N_llessVal32, verifyResultNormal,
			"LDDLE_OUT low nop1 < nop2", 1, 1},
	{114, ML_CODE_LDDLE, setCodeLD32x_N_N, setInputDIn_N_N_sameVal32, verifyResultNormal,
			"LDDLE_OUT nop1 == nop2", 1, 1},
	{115, ML_CODE_LDDLE, setCodeLD32x_N_K, setInputSIn_N_K_hbigVal32, verifyResultNormal,
			"LDDLE_OUT high nop1 > K", 1, 0},
	{116, ML_CODE_LDDLE, setCodeLD32x_N_K, setInputSIn_N_K_lbigVal32, verifyResultNormal,
			"LDDLE_OUT low nop1 > K", 1, 0},
	{117, ML_CODE_LDDLE, setCodeLD32x_N_K, setInputSIn_N_K_hlessVal32, verifyResultNormal,
			"LDDLE_OUT high nop1 < K", 1, 1},
	{118, ML_CODE_LDDLE, setCodeLD32x_N_K, setInputSIn_N_K_llessVal32, verifyResultNormal,
			"LDDLE_OUT low nop1 < K", 1, 1},
	{119, ML_CODE_LDDLE, setCodeLD32x_N_K, setInputSIn_N_K_sameVal32, verifyResultNormal,
			"LDDLE_OUT nop1 == K", 1, 1},

	{120, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off nop1 > op2", 1, 0 },
	{121, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off nop1 < op2", 1, 0 },
	{122, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off nop1 == op2", 1, 0 },
	{123, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high nop1 > op2", 1, 0 },
	{124, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low nop1 > op2", 1, 0 },
	{125, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high nop1 < op2", 1, 0 },
	{126, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low nop1 < op2", 1, 0 },
	{127, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT nop1 == op2", 1, 1},
	{128, ML_CODE_ANDDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1 > nop2", 1, 0 },
	{129, ML_CODE_ANDDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1 < nop2", 1, 0 },
	{130, ML_CODE_ANDDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1 == nop2", 1, 0 },
	{131, ML_CODE_ANDDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high op1 > nop2", 1, 0 },
	{132, ML_CODE_ANDDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low op1 > nop2", 1, 0 },
	{133, ML_CODE_ANDDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high op1 < nop2", 1, 0 },
	{134, ML_CODE_ANDDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low op1 < nop2", 1, 0 },
	{135, ML_CODE_ANDDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT op1 == nop2", 1, 1},
	{136, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off nop1 > nop2", 1, 0 },
	{137, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off nop1 < op2", 1, 0 },
	{138, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off nop1 == nop2", 1, 0 },
	{139, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high nop1 > nop2", 1, 0 },
	{140, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low nop1 > nop2", 1, 0 },
	{141, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high nop1 < nop2", 1, 0 },
	{142, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low nop1 < nop2", 1, 0 },
	{143, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT nop1 == nop2", 1, 1},
	{144, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT high nop1 > K", 1, 0},
	{145, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT high nop1 < K", 1, 0},
	{146, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT nop1 == K", 1, 0},
	{147, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high nop1 > K", 1, 0},
	{148, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low nop1 > K", 1, 0},
	{149, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high nop1 < K", 1, 0},
	{150, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low nop1 < K", 1, 0},
	{151, ML_CODE_ANDDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT nop1 == K", 1, 1},

	{152, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off nop1 > op2", 1, 0 },
	{153, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off nop1 < op2", 1, 0 },
	{154, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off nop1 == op2", 1, 0 },
	{155, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT high nop1 > op2", 1, 1 },
	{156, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT low nop1 > op2", 1, 1 },
	{157, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT high nop1 < op2", 1, 1 },
	{158, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT low nop1 < op2", 1, 1 },
	{159, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT nop1 == op2", 1, 0},
	{160, ML_CODE_ANDDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1 > nop2", 1, 0 },
	{161, ML_CODE_ANDDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1 < nop2", 1, 0 },
	{162, ML_CODE_ANDDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1 == nop2", 1, 0 },
	{163, ML_CODE_ANDDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT high op1 > nop2", 1, 1 },
	{164, ML_CODE_ANDDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT low op1 > nop2", 1, 1 },
	{165, ML_CODE_ANDDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT high op1 < nop2", 1, 1 },
	{166, ML_CODE_ANDDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT low op1 < nop2", 1, 1 },
	{167, ML_CODE_ANDDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT op1 == nop2", 1, 0},
	{168, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off nop1 > nop2", 1, 0 },
	{169, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off nop1 < nop2", 1, 0 },
	{170, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off nop1 == nop2", 1, 0 },
	{171, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT high nop1 > nop2", 1, 1 },
	{172, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT low nop1 > nop2", 1, 1 },
	{173, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT high nop1 < nop2", 1, 1 },
	{174, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT low nop1 < nop2", 1, 1 },
	{175, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT nop1 == nop2", 1, 0},
	{176, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT high nop1 > K", 1, 0},
	{177, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT high nop1 < K", 1, 0},
	{178, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT nop1 == K", 1, 0},
	{179, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT high nop1 > K", 1, 1},
	{180, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT low nop1 > K", 1, 1},
	{181, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT high nop1 < K", 1, 1},
	{182, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT low nop1 < K", 1, 1},
	{183, ML_CODE_ANDDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT nop1 == K", 1, 0},

	{184, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off nop1 > op2", 1, 0 },
	{185, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off nop1 < op2", 1, 0 },
	{186, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off nop1 == op2", 1, 0 },
	{187, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT high nop1 > op2", 1, 1 },
	{188, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT low nop1 > op2", 1, 1 },
	{189, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT high nop1 < op2", 1, 0 },
	{190, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT low nop1 < op2", 1, 0 },
	{191, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT nop1 == op2", 1, 0},
	{192, ML_CODE_ANDDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1 > nop2", 1, 0 },
	{193, ML_CODE_ANDDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1 < nop2", 1, 0 },
	{194, ML_CODE_ANDDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1 == nop2", 1, 0 },
	{195, ML_CODE_ANDDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT high op1 > nop2", 1, 1 },
	{196, ML_CODE_ANDDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT low op1 > nop2", 1, 1 },
	{197, ML_CODE_ANDDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT high op1 < nop2", 1, 0 },
	{198, ML_CODE_ANDDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT low op1 < nop2", 1, 0 },
	{199, ML_CODE_ANDDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT op1 == nop2", 1, 0},
	{200, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off nop1 > nop2", 1, 0 },
	{201, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off nop1 < nop2", 1, 0 },
	{202, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off nop1 == nop2", 1, 0 },
	{203, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT high nop1 > nop2", 1, 1 },
	{204, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT low nop1 > nop2", 1, 1 },
	{205, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT high nop1 < nop2", 1, 0 },
	{206, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT low nop1 < nop2", 1, 0 },
	{207, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT nop1 == nop2", 1, 0},
	{208, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT high nop1 > K", 1, 0},
	{209, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT high nop1 < K", 1, 0},
	{210, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT nop1 == K", 1, 0},
	{211, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT high nop1 > K", 1, 1},
	{212, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT low nop1 > K", 1, 1},
	{213, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT high nop1 < K", 1, 0},
	{214, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT low nop1 < K", 1, 0},
	{215, ML_CODE_ANDDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT nop1 == K", 1, 0},

	{216, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off nop1 > op2", 1, 0 },
	{217, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off nop1 < op2", 1, 0 },
	{218, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off nop1 == op2", 1, 0 },
	{219, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT high nop1 > op2", 1, 1 },
	{220, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT low nop1 > op2", 1, 1 },
	{221, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT high nop1 < op2", 1, 0 },
	{222, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT low nop1 < op2", 1, 0 },
	{223, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT nop1 == op2", 1, 1},
	{224, ML_CODE_ANDDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1 > nop2", 1, 0 },
	{225, ML_CODE_ANDDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1 < nop2", 1, 0 },
	{226, ML_CODE_ANDDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1 == nop2", 1, 0 },
	{227, ML_CODE_ANDDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT high op1 > nop2", 1, 1 },
	{228, ML_CODE_ANDDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT low op1 > nop2", 1, 1 },
	{229, ML_CODE_ANDDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT high op1 < nop2", 1, 0 },
	{230, ML_CODE_ANDDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT low op1 < nop2", 1, 0 },
	{231, ML_CODE_ANDDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT op1 == nop2", 1, 1},
	{232, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off nop1 > nop2", 1, 0 },
	{233, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off nop1 < nop2", 1, 0 },
	{234, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off nop1 == nop2", 1, 0 },
	{235, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT high nop1 > nop2", 1, 1 },
	{236, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT low nop1 > nop2", 1, 1 },
	{237, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT high nop1 < nop2", 1, 0 },
	{238, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT low nop1 < nop2", 1, 0 },
	{239, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT nop1 == nop2", 1, 1},
	{240, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT high nop1 > K", 1, 0},
	{241, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT high nop1 < K", 1, 0},
	{242, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT nop1 == K", 1, 0},
	{243, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT high nop1 > K", 1, 1},
	{244, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT low nop1 > K", 1, 1},
	{245, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT high nop1 < K", 1, 0},
	{246, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT low nop1 < K", 1, 0},
	{247, ML_CODE_ANDDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT nop1 == K", 1, 1},

	{248, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off nop1 > op2", 1, 0 },
	{249, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off nop1 < op2", 1, 0 },
	{250, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off nop1 == op2", 1, 0 },
	{251, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT high nop1 > op2", 1, 0 },
	{252, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT low nop1 > op2", 1, 0 },
	{253, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT high nop1 < op2", 1, 1 },
	{254, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT low nop1 < op2", 1, 1 },
	{255, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT nop1 == op2", 1, 0},
	{256, ML_CODE_ANDDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1 > nop2", 1, 0 },
	{257, ML_CODE_ANDDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1 < nop2", 1, 0 },
	{258, ML_CODE_ANDDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1 == nop2", 1, 0 },
	{259, ML_CODE_ANDDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT high op1 > nop2", 1, 0 },
	{260, ML_CODE_ANDDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT low op1 > nop2", 1, 0 },
	{261, ML_CODE_ANDDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT high op1 < nop2", 1, 1 },
	{262, ML_CODE_ANDDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT low op1 < nop2", 1, 1 },
	{263, ML_CODE_ANDDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT op1 == nop2", 1, 0},
	{264, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off nop1 > nop2", 1, 0 },
	{265, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off nop1 < nop2", 1, 0 },
	{266, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off nop1 == nop2", 1, 0 },
	{267, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT high nop1 > nop2", 1, 0 },
	{268, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT low nop1 > nop2", 1, 0 },
	{269, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT high nop1 < nop2", 1, 1 },
	{270, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT low nop1 < nop2", 1, 1 },
	{271, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT nop1 == nop2", 1, 0},
	{272, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT high nop1 > K", 1, 0},
	{273, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT high nop1 < K", 1, 0},
	{274, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT nop1 == K", 1, 0},
	{275, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT high nop1 > K", 1, 0},
	{276, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT low nop1 > K", 1, 0},
	{277, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT high nop1 < K", 1, 1},
	{278, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT low nop1 < K", 1, 1},
	{279, ML_CODE_ANDDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT nop1 == K", 1, 0},

	{280, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off nop1 > op2", 1, 0 },
	{281, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off nop1 < op2", 1, 0 },
	{282, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off nop1 == op2", 1, 0 },
	{283, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT high nop1 > op2", 1, 0 },
	{284, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT low nop1 > op2", 1, 0 },
	{285, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT high nop1 < op2", 1, 1 },
	{286, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT low nop1 < op2", 1, 1 },
	{287, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT nop1 == op2", 1, 1},
	{288, ML_CODE_ANDDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1 > nop2", 1, 0 },
	{289, ML_CODE_ANDDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1 < nop2", 1, 0 },
	{290, ML_CODE_ANDDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1 == nop2", 1, 0 },
	{291, ML_CODE_ANDDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT high op1 > nop2", 1, 0 },
	{292, ML_CODE_ANDDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT low op1 > nop2", 1, 0 },
	{293, ML_CODE_ANDDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT high op1 < nop2", 1, 1 },
	{294, ML_CODE_ANDDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT low op1 < nop2", 1, 1 },
	{295, ML_CODE_ANDDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT op1 == nop2", 1, 1},
	{296, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off nop1 > nop2", 1, 0 },
	{297, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off nop1 < nop2", 1, 0 },
	{298, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off nop1 == nop2", 1, 0 },
	{299, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT high nop1 > nop2", 1, 0 },
	{300, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT low nop1 > nop2", 1, 0 },
	{301, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT high nop1 < nop2", 1, 1 },
	{302, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT low nop1 < nop2", 1, 1 },
	{303, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT nop1 == nop2", 1, 1},
	{304, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT high nop1 > K", 1, 0},
	{305, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT high nop1 < K", 1, 0},
	{306, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT nop1 == K", 1, 0},
	{307, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT high nop1 > K", 1, 0},
	{308, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT low nop1 > K", 1, 0},
	{309, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT high nop1 < K", 1, 1},
	{310, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT low nop1 < K", 1, 1},
	{311, ML_CODE_ANDDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT nop1 == K", 1, 1},

	{312, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 > op2", 1, 0 },
	{313, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 < op2", 1, 0 },
	{314, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT low nop1 > op2", 1, 0 },
	{315, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT high nop1 < op2", 1, 0 },
	{316, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 == op2", 1, 1 },
	{317, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT high nop1 > op2", 1, 1 },
	{318, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT high nop1 < op2", 1, 1 },
	{319, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT nop1 == op2", 1, 1},
	{320, ML_CODE_ORDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 > nop2", 1, 0 },
	{321, ML_CODE_ORDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 < nop2", 1, 0 },
	{322, ML_CODE_ORDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT low op1 > nop2", 1, 0 },
	{323, ML_CODE_ORDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT high op1 < nop2", 1, 0 },
	{324, ML_CODE_ORDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 == nop2", 1, 1 },
	{325, ML_CODE_ORDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT high op1 > nop2", 1, 1 },
	{326, ML_CODE_ORDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT high op1 < nop2", 1, 1 },
	{327, ML_CODE_ORDEQ, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT op1 == nop2", 1, 1},
	{328, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 > nop2", 1, 0 },
	{329, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 < nop2", 1, 0 },
	{330, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT low nop1 > nop2", 1, 0 },
	{331, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT high nop1 < nop2", 1, 0 },
	{332, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 == nop2", 1, 1 },
	{333, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT high nop1 > nop2", 1, 1 },
	{334, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT high nop1 < nop2", 1, 1 },
	{335, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT nop1 == nop2", 1, 1},
	{336, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT high nop1 > K", 1, 0},
	{337, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT high nop1 < K", 1, 0},
	{338, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT low nop1 > K", 1, 0},
	{339, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT low nop1 < K", 1, 0},
	{340, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT nop1 == K", 1, 1},
	{341, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT high nop1 > K", 1, 1},
	{342, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT high nop1 < K", 1, 1},
	{343, ML_CODE_ORDEQ, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT nop1 == K", 1, 1},

	{344, ML_CODE_ORDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 > op2", 1, 1 },
	{345, ML_CODE_ORDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 < op2", 1, 1 },
	{346, ML_CODE_ORDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT low nop1 > op2", 1, 1 },
	{347, ML_CODE_ORDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT high nop1 < op2", 1, 1 },
	{348, ML_CODE_ORDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 == op2", 1, 0 },
	{349, ML_CODE_ORDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT high nop1 > op2", 1, 1 },
	{350, ML_CODE_ORDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT high nop1 < op2", 1, 1 },
	{351, ML_CODE_ORDNE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT nop1 == op2", 1, 1},
	{352, ML_CODE_ORDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 > nop2", 1, 1 },
	{353, ML_CODE_ORDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 < nop2", 1, 1 },
	{354, ML_CODE_ORDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT low op1 > nop2", 1, 1 },
	{355, ML_CODE_ORDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT high op1 < nop2", 1, 1 },
	{356, ML_CODE_ORDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 == nop2", 1, 0 },
	{357, ML_CODE_ORDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT high op1 > nop2", 1, 1 },
	{358, ML_CODE_ORDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT high op1 < nop2", 1, 1 },
	{359, ML_CODE_ORDNE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT op1 == nop2", 1, 1},
	{360, ML_CODE_ORDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 > nop2", 1, 1 },
	{361, ML_CODE_ORDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 < nop2", 1, 1 },
	{362, ML_CODE_ORDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT low nop1 > nop2", 1, 1 },
	{363, ML_CODE_ORDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT high nop1 < nop2", 1, 1 },
	{364, ML_CODE_ORDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 == nop2", 1, 0 },
	{365, ML_CODE_ORDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT high nop1 > nop2", 1, 1 },
	{366, ML_CODE_ORDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT high nop1 < nop2", 1, 1 },
	{367, ML_CODE_ORDNE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT nop1 == nop2", 1, 1},
	{368, ML_CODE_ORDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT high nop1 > K", 1, 1},
	{369, ML_CODE_ORDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT high nop1 < K", 1, 1},
	{370, ML_CODE_ORDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT low nop1 > K", 1, 1},
	{371, ML_CODE_ORDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT low nop1 < K", 1, 1},
	{372, ML_CODE_ORDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT op1 == K", 1, 0},
	{373, ML_CODE_ORDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT high nop1 > K", 1, 1},
	{374, ML_CODE_ORDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT high nop1 < K", 1, 1},
	{375, ML_CODE_ORDNE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT nop1 == K", 1, 1},

	{376, ML_CODE_ORDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 > op2", 1, 1 },
	{377, ML_CODE_ORDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 < op2", 1, 0 },
	{378, ML_CODE_ORDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT low nop1 > op2", 1, 1 },
	{379, ML_CODE_ORDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT high nop1 < op2", 1, 0 },
	{380, ML_CODE_ORDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 == op2", 1, 0 },
	{381, ML_CODE_ORDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT high nop1 > op2", 1, 1 },
	{382, ML_CODE_ORDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT high nop1 < op2", 1, 1 },
	{383, ML_CODE_ORDGT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT nop1 == op2", 1, 1},
	{384, ML_CODE_ORDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 > nop2", 1, 1 },
	{385, ML_CODE_ORDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 < nop2", 1, 0 },
	{386, ML_CODE_ORDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT low op1 > nop2", 1, 1 },
	{387, ML_CODE_ORDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT high op1 < nop2", 1, 0 },
	{388, ML_CODE_ORDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 == nop2", 1, 0 },
	{389, ML_CODE_ORDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT high op1 > nop2", 1, 1 },
	{390, ML_CODE_ORDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT high op1 < nop2", 1, 1 },
	{391, ML_CODE_ORDGT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT op1 == nop2", 1, 1},
	{392, ML_CODE_ORDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 > nop2", 1, 1 },
	{393, ML_CODE_ORDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 < nop2", 1, 0 },
	{394, ML_CODE_ORDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT low nop1 > nop2", 1, 1 },
	{395, ML_CODE_ORDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT high nop1 < nop2", 1, 0 },
	{396, ML_CODE_ORDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 == nop2", 1, 0 },
	{397, ML_CODE_ORDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT high nop1 > nop2", 1, 1 },
	{398, ML_CODE_ORDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT high nop1 < nop2", 1, 1 },
	{399, ML_CODE_ORDGT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT nop1 == nop2", 1, 1},
	{400, ML_CODE_ORDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT high nop1 > K", 1, 1},
	{401, ML_CODE_ORDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT high nop1 < K", 1, 0},
	{402, ML_CODE_ORDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT low nop1 > K", 1, 1},
	{403, ML_CODE_ORDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT low nop1 < K", 1, 0},
	{404, ML_CODE_ORDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT nop1 == K", 1, 0},
	{405, ML_CODE_ORDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT high nop1 > K", 1, 1},
	{406, ML_CODE_ORDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT high nop1 < K", 1, 1},
	{407, ML_CODE_ORDGT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT nop1 == K", 1, 1},

	{408, ML_CODE_ORDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 > op2", 1, 1 },
	{409, ML_CODE_ORDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 < op2", 1, 0 },
	{410, ML_CODE_ORDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT low nop1 > op2", 1, 1 },
	{411, ML_CODE_ORDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT high nop1 < op2", 1, 0 },
	{412, ML_CODE_ORDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 == op2", 1, 1 },
	{413, ML_CODE_ORDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT high nop1 > op2", 1, 1 },
	{414, ML_CODE_ORDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT high nop1 < op2", 1, 1 },
	{415, ML_CODE_ORDGE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT nop1 == op2", 1, 1},
	{416, ML_CODE_ORDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 > nop2", 1, 1 },
	{417, ML_CODE_ORDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 < nop2", 1, 0 },
	{418, ML_CODE_ORDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT low op1 > nop2", 1, 1 },
	{419, ML_CODE_ORDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT high op1 < nop2", 1, 0 },
	{420, ML_CODE_ORDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 == nop2", 1, 1 },
	{421, ML_CODE_ORDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT high op1 > nop2", 1, 1 },
	{422, ML_CODE_ORDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT high op1 < nop2", 1, 1 },
	{423, ML_CODE_ORDGE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT op1 == nop2", 1, 1},
	{424, ML_CODE_ORDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 > nop2", 1, 1 },
	{425, ML_CODE_ORDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 < nop2", 1, 0 },
	{426, ML_CODE_ORDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT low nop1 > nop2", 1, 1 },
	{427, ML_CODE_ORDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT high nop1 < nop2", 1, 0 },
	{428, ML_CODE_ORDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 == nop2", 1, 1 },
	{429, ML_CODE_ORDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT high nop1 > nop2", 1, 1 },
	{430, ML_CODE_ORDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT high nop1 < nop2", 1, 1 },
	{431, ML_CODE_ORDGE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT nop1 == nop2", 1, 1},
	{432, ML_CODE_ORDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT high nop1 > K", 1, 1},
	{433, ML_CODE_ORDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT high nop1 < K", 1, 0},
	{434, ML_CODE_ORDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT low nop1 > K", 1, 1},
	{435, ML_CODE_ORDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT low nop1 < K", 1, 0},
	{436, ML_CODE_ORDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT nop1 == K", 1, 1},
	{437, ML_CODE_ORDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT high nop1 > K", 1, 1},
	{438, ML_CODE_ORDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT high nop1 < K", 1, 1},
	{439, ML_CODE_ORDGE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT nop1 == K", 1, 1},

	{440, ML_CODE_ORDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 > op2", 1, 0 },
	{441, ML_CODE_ORDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 < op2", 1, 1 },
	{442, ML_CODE_ORDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT low nop1 > op2", 1, 0 },
	{443, ML_CODE_ORDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT high nop1 < op2", 1, 1 },
	{444, ML_CODE_ORDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 == op2", 1, 0 },
	{445, ML_CODE_ORDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT high nop1 > op2", 1, 1 },
	{446, ML_CODE_ORDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT high nop1 < op2", 1, 1 },
	{447, ML_CODE_ORDLT, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT nop1 == op2", 1, 1},
	{448, ML_CODE_ORDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 > nop2", 1, 0 },
	{449, ML_CODE_ORDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 < nop2", 1, 1 },
	{450, ML_CODE_ORDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT low op1 > nop2", 1, 0 },
	{451, ML_CODE_ORDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT high op1 < nop2", 1, 1 },
	{452, ML_CODE_ORDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 == nop2", 1, 0 },
	{453, ML_CODE_ORDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT high op1 > nop2", 1, 1 },
	{454, ML_CODE_ORDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT high op1 < nop2", 1, 1 },
	{455, ML_CODE_ORDLT, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT op1 == nop2", 1, 1},
	{456, ML_CODE_ORDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 > nop2", 1, 0 },
	{457, ML_CODE_ORDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 < nop2", 1, 1 },
	{458, ML_CODE_ORDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT low nop1 > nop2", 1, 0 },
	{459, ML_CODE_ORDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT high nop1 < nop2", 1, 1 },
	{460, ML_CODE_ORDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 == nop2", 1, 0 },
	{461, ML_CODE_ORDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT high nop1 > nop2", 1, 1 },
	{462, ML_CODE_ORDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT high nop1 < nop2", 1, 1 },
	{463, ML_CODE_ORDLT, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT nop1 == nop2", 1, 1},
	{464, ML_CODE_ORDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT high nop1 > K", 1, 0},
	{465, ML_CODE_ORDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT high nop1 < K", 1, 1},
	{466, ML_CODE_ORDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT low nop1 > K", 1, 0},
	{467, ML_CODE_ORDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT low nop1 < K", 1, 1},
	{468, ML_CODE_ORDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT nop1 == K", 1, 0},
	{469, ML_CODE_ORDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT high nop1 > K", 1, 1},
	{470, ML_CODE_ORDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT high nop1 < K", 1, 1},
	{471, ML_CODE_ORDLT, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT nop1 == K", 1, 1},

	{472, ML_CODE_ORDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 > op2", 1, 0 },
	{473, ML_CODE_ORDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 < op2", 1, 1 },
	{474, ML_CODE_ORDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT low nop1 > op2", 1, 0 },
	{475, ML_CODE_ORDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT high nop1 < op2", 1, 1 },
	{476, ML_CODE_ORDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 == op2", 1, 1 },
	{477, ML_CODE_ORDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT high nop1 > op2", 1, 1 },
	{478, ML_CODE_ORDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT high nop1 < op2", 1, 1 },
	{479, ML_CODE_ORDLE, setCodeAND_OR_32x_N_W, setInputDIn_N_W_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT nop1 == op2", 1, 1},
	{480, ML_CODE_ORDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 > nop2", 1, 0 },
	{481, ML_CODE_ORDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 < nop2", 1, 1 },
	{482, ML_CODE_ORDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT low op1 > nop2", 1, 0 },
	{483, ML_CODE_ORDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT high op1 < nop2", 1, 1 },
	{484, ML_CODE_ORDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 == nop2", 1, 1 },
	{485, ML_CODE_ORDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT high op1 > nop2", 1, 1 },
	{486, ML_CODE_ORDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT high op1 < nop2", 1, 1 },
	{487, ML_CODE_ORDLE, setCodeAND_OR_32x_W_N, setInputDIn_W_N_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT op1 == nop2", 1, 1},
	{488, ML_CODE_ORDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 > nop2", 1, 0 },
	{489, ML_CODE_ORDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 < nop2", 1, 1 },
	{490, ML_CODE_ORDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT low nop1 > nop2", 1, 0 },
	{491, ML_CODE_ORDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT high nop1 < nop2", 1, 1 },
	{492, ML_CODE_ORDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 == nop2", 1, 1 },
	{493, ML_CODE_ORDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT high nop1 > nop2", 1, 1 },
	{494, ML_CODE_ORDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT high nop1 < nop2", 1, 1 },
	{495, ML_CODE_ORDLE, setCodeAND_OR_32x_N_N, setInputDIn_N_N_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT nop1 == nop2", 1, 1},
	{496, ML_CODE_ORDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT high nop1 > K", 1, 0},
	{497, ML_CODE_ORDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT high nop1 < K", 1, 1},
	{498, ML_CODE_ORDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT low nop1 > K", 1, 0},
	{499, ML_CODE_ORDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT low nop1 < K", 1, 1},
	{500, ML_CODE_ORDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT nop1 == K", 1, 1},
	{501, ML_CODE_ORDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT high nop1 > K", 1, 1},
	{502, ML_CODE_ORDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT high nop1 < K", 1, 1},
	{503, ML_CODE_ORDLE, setCodeAND_OR_32x_N_K, setInputSIn_N_K_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT nop1 == K", 1, 1},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};

int total_basic_comp_dword_nb_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_comp_dword_nb_test_number; i++)
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


//compare with 2x 16bit registers
int setCodeLD32x_N_W(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B) return 0;
	if(in2_reg < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(8, in1_reg, in_pos); addMLOperand(in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD32x_W_N(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg < OPERAND_ML_CODE_D) return 0;
	if(in2_reg > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in1_reg, in_pos); addMLOperandNibble(8, in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD32x_N_N(uint16 ml_cmd, uint8 in1_reg, uint16 in_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B) return 0;
	if(in2_reg > OPERAND_ML_CODE_B) return 0;
	if(in1_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(8, in1_reg, in_pos); addMLOperandNibble(8, in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

//compare with 32bit constant
int setCodeLD32x_N_K(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B) return 0;
	if(in2_reg < OPERAND_ML_CODE_D) return 0;
	if(in1_reg == out_reg && in1_pos == out_pos) return 0;


	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(8, in1_reg, in1_pos); addMLOperand(OPERAND_ML_CODE_DK, 16843009L); //0x101 0101
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

//compare with 32bit negative constant
int setCodeLD32x_N_nK(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B) return 0;
	if(in2_reg < OPERAND_ML_CODE_D) return 0;
	if(in1_reg == out_reg && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(8, in1_reg, in1_pos); addMLOperand(OPERAND_ML_CODE_DK, -2130640639L);//0x81010101
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

//compare with 2x 16bit registers
int setCodeAND_OR_32x_N_W(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B) return 0;
	if(in2_reg < OPERAND_ML_CODE_D) return 0;
	if(in1_reg == out_reg && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in1_reg, in1_pos); addMLOperand(in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeAND_OR_32x_W_N(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg < OPERAND_ML_CODE_D) return 0;
	if(in2_reg > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1_reg, in1_pos); addMLOperandNibble(8, in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeAND_OR_32x_N_N(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B) return 0;
	if(in2_reg > OPERAND_ML_CODE_B) return 0;
	if(in1_reg == out_reg && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in1_reg, in1_pos); addMLOperandNibble(8, in2_reg, 160);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeAND_OR_32x_N_K(uint16 ml_cmd, uint8 in1_reg, uint16 in1_pos, uint8 in2_reg, uint8 out_reg, uint16 out_pos)
{
	if(in1_reg > OPERAND_ML_CODE_B) return 0;
	if(in2_reg < OPERAND_ML_CODE_D) return 0;
	if(in1_reg == out_reg && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in1_reg, in1_pos); addMLOperand(OPERAND_ML_CODE_DK, 16843009L);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


// high word is different, low word is same
void setInputDIn_N_W_hbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 00101
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16777473); //0x100 0101

	TestCodeTearDown();
}

// low word is different, high word is same
void setInputDIn_N_W_lbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));//
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843008); //0x101 0100

	TestCodeTearDown();
}

void setInputDIn_N_W_hlessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16777473; // 0x100 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843009); //0x101 00101

	TestCodeTearDown();
}

void setInputDIn_N_W_llessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843008; // 0x101 0100

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01) );
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843009);//0x101 0101

	TestCodeTearDown();
}

void setInputDIn_N_W_sameVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01) );
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843009);

	TestCodeTearDown();
}

void setInputDIn_W_N_hbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16777473; // 0x100 0101

	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843009); //0x101 0101
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 00101
	}

	TestCodeTearDown();
}

// low word is different, high word is same
void setInputDIn_W_N_lbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843008; // 0x101 0100

	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843009); //0x101 0101
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 00100
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_hlessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16777473); //0x101 00101
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 00100
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_llessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843008);//0x101 0100
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01) );
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_sameVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01) );
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_hbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16843009; // 0x101 0101
	int value2=16777473; // 0x100 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01)); //0x101 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01)); //0x101 00101
	}

	TestCodeTearDown();
}

// low word is different, high word is same
void setInputDIn_N_N_lbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16843009; // 0x101 0101
	int value2=16843008; // 0x101 0100

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01)); //0x101 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01)); //0x101 00100
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_hlessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16777473; // 0x100 0101
	int value2=16843009; // 0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01)); //0x100 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01)); //0x101 00100
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_llessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16843008; // 0x0101 0100
	int value2=16843009; // 0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01)); //0x100 0100
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01) );
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_sameVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x100 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01) );
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_hbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16908545; // 0x102 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_lbigVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843010; // 0x101 0102

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_hlessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16777473; // 0x100 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_llessVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843008; // 0x101 0100

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_sameVal32(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}

void setInputDIn_N_W_hbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x100 0101
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16777473); //0x100 0101

	TestCodeTearDown();
}

void setInputDIn_N_W_hlessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16777473; // 0x100 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x100 0101
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843009); //0x101 00101

	TestCodeTearDown();
}

void setInputDIn_N_W_lbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));//0x101 0101
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843008); //0x101 0100

	TestCodeTearDown();
}

void setInputDIn_N_W_llessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0100
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843009);//0x101 0101

	TestCodeTearDown();
}

void setInputDIn_N_W_sameVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0101
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843009);

	TestCodeTearDown();
}

void setInputDIn_N_W_hbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x100 0101
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16777473); //0x100 0101

	TestCodeTearDown();
}

// low word is different, high word is same
void setInputDIn_N_W_lbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01));//0x101 0101
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843008); //0x101 0100

	TestCodeTearDown();
}

void setInputDIn_N_W_hlessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16777473; // 0x100 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x100 0101
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843009); //0x101 00101

	TestCodeTearDown();
}

void setInputDIn_N_W_llessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0100
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843009);//0x101 0101

	TestCodeTearDown();
}


void setInputDIn_N_W_sameVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0101
	}
	addDeviceControlInstructionToDWord(0, (uint8)in2, 160, 16843009);

	TestCodeTearDown();
}

void setInputDIn_W_N_hbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16777473; // 0x100 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843009); //0x100 0101
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x100 0101
	}

	TestCodeTearDown();
}

// low word is different, high word is same
void setInputDIn_W_N_lbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843009);//0x101 0101
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 0100
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_hlessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16777473); //0x100 0101
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 00101
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_llessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843008); //0x101 0100
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));//0x101 0101
	}

	TestCodeTearDown();
}


void setInputDIn_W_N_sameVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_hbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16777473; // 0x100 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843009); //0x100 0101
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x100 0101
	}

	TestCodeTearDown();
}

// low word is different, high word is same
void setInputDIn_W_N_lbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843009);//0x101 0101
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 0100
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_hlessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16777473); //0x100 0101
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 00101
	}

	TestCodeTearDown();
}

void setInputDIn_W_N_llessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843008); //0x101 0100
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01));//0x101 0101
	}

	TestCodeTearDown();
}


void setInputDIn_W_N_sameVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in_pos, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_hbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16843009; // 0x101 0101
	int value2=16777473; // 0x100 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01)); //0x100 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01)); //0x100 0101
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_hlessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16777473; // 0x100 0101
	int value2=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01)); //0x100 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01)); //0x101 00101
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_lbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16843009; // 0x101 0101
	int value2=16843008; // 0x101 0100

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01));//0x101 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01));//0x101 0100
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_llessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16843008; //  0x101 0100
	int value2=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01)); //0x101 0100
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_sameVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}


void setInputDIn_N_N_hbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16843009; // 0x101 0101
	int value2=16777473; // 0x100 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01)); //0x100 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01)); //0x100 0101
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_hlessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16777473; // 0x100 0101
	int value2=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01)); //0x100 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01)); //0x101 00101
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_lbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16843009; // 0x101 0101
	int value2=16843008; // 0x101 0100

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_llessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i;
	int value1=16843008; // 0x101 0100
	int value2=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value1>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value2>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputDIn_N_N_sameVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0101
		addDeviceControlInstruction(0, (uint8)in2, 160+i, ((value>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}


void setInputSIn_N_K_hbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16908545; // 0x102 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x102 0101
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_hlessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16777473; // 0x100 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_lbigVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843010; // 0x101 0102

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0102
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_llessVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0100
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_sameVal32_off(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_hbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16908545; // 0x102 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x102 0101
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_hlessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16777473; // 0x100 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_lbigVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843010; // 0x101 0102

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0102
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_llessVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0100
	}

	TestCodeTearDown();
}

void setInputSIn_N_K_sameVal32_on(uint8 in1, uint16 in_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	int i, value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in_pos+i, ((value>>i)&0x01)); //0x101 0101
	}

	TestCodeTearDown();
}


static uint16 getInRegPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; //32bit

	return pos[inx_pos][reg];
}

static uint16 getOutPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096},
			{8191,8191,8191,8191,2047,8191}};

	return pos[inx_pos][reg];
}

static 	FILE *flog;
//normal test case
void test_compare_dword_nb(int tno, uint16 dummy)
{
	int i, rc=0, rc2=1, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos;
	uint8 res_bit;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			if(out==OPERAND_ML_CODE_F) continue;

			out_pos = getInRegPos(out, olast);
			for(in1=OPERAND_ML_CODE_X; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(in2=OPERAND_ML_CODE_X; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getInRegPos(in1, i);

						rc2=testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in1, in_pos, (uint8)in2, (uint8)out, out_pos);
						if(rc2 == 0) continue;

						testCase[tno].setTestInput_fn(in1, in_pos, in2, out, out_pos);

						rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s command error! in1_%s[%d], in2_%s[160], out_%s[%d] exp=%d\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in1], in_pos, reg[in2], reg[out], out_pos, testCase[tno].expected);
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

void testBasicCompareDWordNibbleCommand(void)
{
	int index=500;
	int start, end;
	char log[] = "err_comp_dword_nb.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare dword nibble LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0;index<5;index++)
		test_compare_dword_nb(index, 0);

#else
	total_basic_comp_dword_nb_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LDDEQ); //ML_CODE_LDDEQ
	end = getTestCaseNumberEnd(ML_CODE_ORDLE); //ML_CODE_ORDLE

	DBG_LOGPRINT("testBasicCompareDWordNibbleCommand: %d to %d total %d\n", start, end, total_basic_comp_dword_nb_test_number);
	for(index=start; index<=end; index++)
	{
		test_compare_dword_nb(index, 0);
	}
#endif
	fclose(flog);
}

#endif
