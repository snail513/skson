/*
 * test_basic_compare_word_index.c
 *
 *  Created on: Jul 9, 2015
 *      Author: hrjung
 */


#ifdef USE_CUNIT_TEST_DEF

#ifndef PLC_LISTOFTESTSUITE_H_
#include "../PLC_ListOfTestSuite.h"
#endif
#include "../testPlatform/PLC_Platform.h"

#include <stdio.h>
#include <stdlib.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

extern void TestCodeInit(void);
extern void TestCodeTearDown(void);
extern int runTestCode(int run_step, char *testFuncName);

extern int verifyResultNormal(int tcase, uint8 dest_reg, uint16 pos, uint8 expected);

int setCodeOp_Idx_WWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp_Idx_NWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp_Idx_KWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp_Idx_WZW(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp_Idx_WZN(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp_Idx_WZK(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

int setCodeOp2_Idx_WWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_Idx_NWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_Idx_KWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_Idx_WZW(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_Idx_WZN(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_Idx_WZK(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);


void setInputIdx_WWZ_bigVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_sameVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_lessVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_bigVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_sameVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_lessVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_bigVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_sameVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_lessVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_bigVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_sameVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_lessVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_bigVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_sameVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_lessVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_bigVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_sameVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_lessVal16(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_WWZ_bigVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_bigVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_sameVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_sameVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_lessVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_lessVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_bigVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_bigVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_sameVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_sameVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_lessVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_lessVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_bigVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_bigVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_sameVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_sameVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_lessVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_lessVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_bigVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_bigVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_sameVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_sameVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_lessVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_lessVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_bigVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_bigVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_sameVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_sameVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_lessVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_lessVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_bigVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_bigVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_sameVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_sameVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_lessVal16_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_lessVal16_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

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
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16, uint8, uint16, uint16, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16, uint16, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, uint8);
	char str[40];
	int z_type; // 0 : op2 is index, 1: op1 is index
	int run_step;
	int expected;
} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_LDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigVal16, verifyResultNormal,
			"LDEQ_OUT op1 > op2z", 0, 1, 0},
	{1, ML_CODE_LDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal16, verifyResultNormal,
			"LDEQ_OUT op1 == op2z", 0, 1, 1},
	{2, ML_CODE_LDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessVal16, verifyResultNormal,
			"LDEQ_OUT op1 < op2z", 0, 1, 0},
	{3, ML_CODE_LDEQ, setCodeOp_Idx_NWZ, setInputIdx_NWZ_bigVal16, verifyResultNormal,
			"LDEQ_OUT nop1 > op2z", 0, 1, 0},
	{4, ML_CODE_LDEQ, setCodeOp_Idx_NWZ, setInputIdx_NWZ_sameVal16, verifyResultNormal,
			"LDEQ_OUT nop1 == op2z", 0, 1, 1},
	{5, ML_CODE_LDEQ, setCodeOp_Idx_NWZ, setInputIdx_NWZ_lessVal16, verifyResultNormal,
			"LDEQ_OUT nop1 < op2z", 0, 1, 0},
	{6, ML_CODE_LDEQ, setCodeOp_Idx_KWZ, setInputIdx_KWZ_bigVal16, verifyResultNormal,
			"LDEQ_OUT K > op2z", 0, 1, 0},
	{7, ML_CODE_LDEQ, setCodeOp_Idx_KWZ, setInputIdx_KWZ_sameVal16, verifyResultNormal,
			"LDEQ_OUT K == op2z", 0, 1, 1},
	{8, ML_CODE_LDEQ, setCodeOp_Idx_KWZ, setInputIdx_KWZ_lessVal16, verifyResultNormal,
			"LDEQ_OUT K < op2z", 0, 1, 0},
	{9, ML_CODE_LDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_bigVal16, verifyResultNormal,
			"LDEQ_OUT op1z > op2", 1, 1, 0},
	{10, ML_CODE_LDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal16, verifyResultNormal,
			"LDEQ_OUT op1z == op2", 1, 1, 1},
	{11, ML_CODE_LDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_lessVal16, verifyResultNormal,
			"LDEQ_OUT op1z < op2", 1, 1, 0},
	{12, ML_CODE_LDEQ, setCodeOp_Idx_WZN, setInputIdx_WZN_bigVal16, verifyResultNormal,
			"LDEQ_OUT op1z > nop2", 1, 1, 0},
	{13, ML_CODE_LDEQ, setCodeOp_Idx_WZN, setInputIdx_WZN_sameVal16, verifyResultNormal,
			"LDEQ_OUT op1z == nop2", 1, 1, 1},
	{14, ML_CODE_LDEQ, setCodeOp_Idx_WZN, setInputIdx_WZN_lessVal16, verifyResultNormal,
			"LDEQ_OUT op1z < nop2", 1, 1, 0},
	{15, ML_CODE_LDEQ, setCodeOp_Idx_WZK, setInputIdx_WZK_bigVal16, verifyResultNormal,
			"LDEQ_OUT op1z > K", 1, 1, 0},
	{16, ML_CODE_LDEQ, setCodeOp_Idx_WZK, setInputIdx_WZK_sameVal16, verifyResultNormal,
			"LDEQ_OUT op1z == K", 1, 1, 1},
	{17, ML_CODE_LDEQ, setCodeOp_Idx_WZK, setInputIdx_WZK_lessVal16, verifyResultNormal,
			"LDEQ_OUT op1z < K", 1, 1, 0},

	{18, ML_CODE_LDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigVal16, verifyResultNormal,
			"LDNE_OUT op1 > op2z", 0, 1, 1},
	{19, ML_CODE_LDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal16, verifyResultNormal,
			"LDNE_OUT op1 == op2z", 0, 1, 0},
	{20, ML_CODE_LDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessVal16, verifyResultNormal,
			"LDNE_OUT op1 < op2z", 0, 1, 1},
	{21, ML_CODE_LDNE, setCodeOp_Idx_NWZ, setInputIdx_NWZ_bigVal16, verifyResultNormal,
			"LDNE_OUT nop1 > op2z", 0, 1, 1},
	{22, ML_CODE_LDNE, setCodeOp_Idx_NWZ, setInputIdx_NWZ_sameVal16, verifyResultNormal,
			"LDNE_OUT nop1 == op2z", 0, 1, 0},
	{23, ML_CODE_LDNE, setCodeOp_Idx_NWZ, setInputIdx_NWZ_lessVal16, verifyResultNormal,
			"LDNE_OUT nop1 < op2z", 0, 1, 1},
	{24, ML_CODE_LDNE, setCodeOp_Idx_KWZ, setInputIdx_KWZ_bigVal16, verifyResultNormal,
			"LDNE_OUT K > op2z", 0, 1, 1},
	{25, ML_CODE_LDNE, setCodeOp_Idx_KWZ, setInputIdx_KWZ_sameVal16, verifyResultNormal,
			"LDNE_OUT K == op2z", 0, 1, 0},
	{26, ML_CODE_LDNE, setCodeOp_Idx_KWZ, setInputIdx_KWZ_lessVal16, verifyResultNormal,
			"LDNE_OUT K < op2z", 0, 1, 1},
	{27, ML_CODE_LDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_bigVal16, verifyResultNormal,
			"LDNE_OUT op1z > op2", 1, 1, 1},
	{28, ML_CODE_LDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal16, verifyResultNormal,
			"LDNE_OUT op1z == op2", 1, 1, 0},
	{29, ML_CODE_LDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_lessVal16, verifyResultNormal,
			"LDNE_OUT op1z < op2", 1, 1, 1},
	{30, ML_CODE_LDNE, setCodeOp_Idx_WZN, setInputIdx_WZN_bigVal16, verifyResultNormal,
			"LDNE_OUT op1z > nop2", 1, 1, 1},
	{31, ML_CODE_LDNE, setCodeOp_Idx_WZN, setInputIdx_WZN_sameVal16, verifyResultNormal,
			"LDNE_OUT op1z == nop2", 1, 1, 0},
	{32, ML_CODE_LDNE, setCodeOp_Idx_WZN, setInputIdx_WZN_lessVal16, verifyResultNormal,
			"LDNE_OUT op1z < nop2", 1, 1, 1},
	{33, ML_CODE_LDNE, setCodeOp_Idx_WZK, setInputIdx_WZK_bigVal16, verifyResultNormal,
			"LDNE_OUT op1z > K", 1, 1, 1},
	{34, ML_CODE_LDNE, setCodeOp_Idx_WZK, setInputIdx_WZK_sameVal16, verifyResultNormal,
			"LDNE_OUT op1z == K", 1, 1, 0},
	{35, ML_CODE_LDNE, setCodeOp_Idx_WZK, setInputIdx_WZK_lessVal16, verifyResultNormal,
			"LDNE_OUT op1z < K", 1, 1, 1},

	{36, ML_CODE_LDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigVal16, verifyResultNormal,
			"LDGT_OUT op1 > op2z", 0, 1, 1},
	{37, ML_CODE_LDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal16, verifyResultNormal,
			"LDGT_OUT op1 == op2z", 0, 1, 0},
	{38, ML_CODE_LDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessVal16, verifyResultNormal,
			"LDGT_OUT op1 < op2z", 0, 1, 0},
	{39, ML_CODE_LDGT, setCodeOp_Idx_NWZ, setInputIdx_NWZ_bigVal16, verifyResultNormal,
			"LDGT_OUT nop1 > op2z", 0, 1, 1},
	{40, ML_CODE_LDGT, setCodeOp_Idx_NWZ, setInputIdx_NWZ_sameVal16, verifyResultNormal,
			"LDGT_OUT nop1 == op2z", 0, 1, 0},
	{41, ML_CODE_LDGT, setCodeOp_Idx_NWZ, setInputIdx_NWZ_lessVal16, verifyResultNormal,
			"LDGT_OUT nop1 < op2z", 0, 1, 0},
	{42, ML_CODE_LDGT, setCodeOp_Idx_KWZ, setInputIdx_KWZ_bigVal16, verifyResultNormal,
			"LDGT_OUT K > op2z", 0, 1, 1},
	{43, ML_CODE_LDGT, setCodeOp_Idx_KWZ, setInputIdx_KWZ_sameVal16, verifyResultNormal,
			"LDGT_OUT K == op2z", 0, 1, 0},
	{44, ML_CODE_LDGT, setCodeOp_Idx_KWZ, setInputIdx_KWZ_lessVal16, verifyResultNormal,
			"LDGT_OUT K < op2z", 0, 1, 0},
	{45, ML_CODE_LDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_bigVal16, verifyResultNormal,
			"LDGT_OUT op1z > op2", 1, 1, 1},
	{46, ML_CODE_LDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal16, verifyResultNormal,
			"LDGT_OUT op1z == op2", 1, 1, 0},
	{47, ML_CODE_LDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_lessVal16, verifyResultNormal,
			"LDGT_OUT op1z < op2", 1, 1, 0},
	{48, ML_CODE_LDGT, setCodeOp_Idx_WZN, setInputIdx_WZN_bigVal16, verifyResultNormal,
			"LDGT_OUT op1z > nop2", 1, 1, 1},
	{49, ML_CODE_LDGT, setCodeOp_Idx_WZN, setInputIdx_WZN_sameVal16, verifyResultNormal,
			"LDGT_OUT op1z == nop2", 1, 1, 0},
	{50, ML_CODE_LDGT, setCodeOp_Idx_WZN, setInputIdx_WZN_lessVal16, verifyResultNormal,
			"LDGT_OUT op1z < nop2", 1, 1, 0},
	{51, ML_CODE_LDGT, setCodeOp_Idx_WZK, setInputIdx_WZK_bigVal16, verifyResultNormal,
			"LDGT_OUT op1z > K", 1, 1, 1},
	{52, ML_CODE_LDGT, setCodeOp_Idx_WZK, setInputIdx_WZK_sameVal16, verifyResultNormal,
			"LDGT_OUT op1z == K", 1, 1, 0},
	{53, ML_CODE_LDGT, setCodeOp_Idx_WZK, setInputIdx_WZK_lessVal16, verifyResultNormal,
			"LDGT_OUT op1z < K", 1, 1, 0},

	{54, ML_CODE_LDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigVal16, verifyResultNormal,
			"LDGE_OUT op1 > op2z", 0, 1, 1},
	{55, ML_CODE_LDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal16, verifyResultNormal,
			"LDGE_OUT op1 == op2z", 0, 1, 1},
	{56, ML_CODE_LDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessVal16, verifyResultNormal,
			"LDGE_OUT op1 < op2z", 0, 1, 0},
	{57, ML_CODE_LDGE, setCodeOp_Idx_NWZ, setInputIdx_NWZ_bigVal16, verifyResultNormal,
			"LDGE_OUT nop1 > op2z", 0, 1, 1},
	{58, ML_CODE_LDGE, setCodeOp_Idx_NWZ, setInputIdx_NWZ_sameVal16, verifyResultNormal,
			"LDGE_OUT nop1 == op2z", 0, 1, 1},
	{59, ML_CODE_LDGE, setCodeOp_Idx_NWZ, setInputIdx_NWZ_lessVal16, verifyResultNormal,
			"LDGE_OUT nop1 < op2z", 0, 1, 0},
	{60, ML_CODE_LDGE, setCodeOp_Idx_KWZ, setInputIdx_NWZ_bigVal16, verifyResultNormal,
			"LDGE_OUT K > op2z", 0, 1, 1},
	{61, ML_CODE_LDGE, setCodeOp_Idx_KWZ, setInputIdx_KWZ_sameVal16, verifyResultNormal,
			"LDGE_OUT K == op2z", 0, 1, 1},
	{62, ML_CODE_LDGE, setCodeOp_Idx_KWZ, setInputIdx_KWZ_lessVal16, verifyResultNormal,
			"LDGE_OUT K < op2z", 0, 1, 0},
	{63, ML_CODE_LDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_bigVal16, verifyResultNormal,
			"LDGE_OUT op1z > op2", 1, 1, 1},
	{64, ML_CODE_LDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal16, verifyResultNormal,
			"LDGE_OUT op1z == op2", 1, 1, 1},
	{65, ML_CODE_LDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_lessVal16, verifyResultNormal,
			"LDGE_OUT op1z < op2", 1, 1, 0},
	{66, ML_CODE_LDGE, setCodeOp_Idx_WZN, setInputIdx_WZN_bigVal16, verifyResultNormal,
			"LDGE_OUT op1z > nop2", 1, 1, 1},
	{67, ML_CODE_LDGE, setCodeOp_Idx_WZN, setInputIdx_WZN_sameVal16, verifyResultNormal,
			"LDGE_OUT op1z == nop2", 1, 1, 1},
	{68, ML_CODE_LDGE, setCodeOp_Idx_WZN, setInputIdx_WZN_lessVal16, verifyResultNormal,
			"LDGE_OUT op1z < nop2", 1, 1, 0},
	{69, ML_CODE_LDGE, setCodeOp_Idx_WZK, setInputIdx_WZK_bigVal16, verifyResultNormal,
			"LDGE_OUT op1z > K", 1, 1, 1},
	{70, ML_CODE_LDGE, setCodeOp_Idx_WZK, setInputIdx_WZK_sameVal16, verifyResultNormal,
			"LDGE_OUT op1z == K", 1, 1, 1},
	{71, ML_CODE_LDGE, setCodeOp_Idx_WZK, setInputIdx_WZK_lessVal16, verifyResultNormal,
			"LDGE_OUT op1z < K", 1, 1, 0},

	{72, ML_CODE_LDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigVal16, verifyResultNormal,
			"LDLT_OUT op1 > op2z", 0, 1, 0},
	{73, ML_CODE_LDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal16, verifyResultNormal,
			"LDLT_OUT op1 == op2z", 0, 1, 0},
	{74, ML_CODE_LDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessVal16, verifyResultNormal,
			"LDLT_OUT op1 < op2z", 0, 1, 1},
	{75, ML_CODE_LDLT, setCodeOp_Idx_NWZ, setInputIdx_NWZ_bigVal16, verifyResultNormal,
			"LDLT_OUT nop1 > op2z", 0, 1, 0},
	{76, ML_CODE_LDLT, setCodeOp_Idx_NWZ, setInputIdx_NWZ_sameVal16, verifyResultNormal,
			"LDLT_OUT nop1 == op2z", 0, 1, 0},
	{77, ML_CODE_LDLT, setCodeOp_Idx_NWZ, setInputIdx_NWZ_lessVal16, verifyResultNormal,
			"LDLT_OUT nop1 < op2z", 0, 1, 1},
	{78, ML_CODE_LDLT, setCodeOp_Idx_KWZ, setInputIdx_NWZ_bigVal16, verifyResultNormal,
			"LDLT_OUT K > op2z", 0, 1, 0},
	{79, ML_CODE_LDLT, setCodeOp_Idx_KWZ, setInputIdx_KWZ_sameVal16, verifyResultNormal,
			"LDLT_OUT K == op2z", 0, 1, 0},
	{80, ML_CODE_LDLT, setCodeOp_Idx_KWZ, setInputIdx_KWZ_lessVal16, verifyResultNormal,
			"LDLT_OUT K < op2z", 0, 1, 1},
	{81, ML_CODE_LDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_bigVal16, verifyResultNormal,
			"LDLT_OUT op1z > op2", 1, 1, 0},
	{82, ML_CODE_LDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal16, verifyResultNormal,
			"LDLT_OUT op1z == op2", 1, 1, 0},
	{83, ML_CODE_LDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_lessVal16, verifyResultNormal,
			"LDLT_OUT op1z < op2", 1, 1, 1},
	{84, ML_CODE_LDLT, setCodeOp_Idx_WZN, setInputIdx_WZN_bigVal16, verifyResultNormal,
			"LDLT_OUT op1z > nop2", 1, 1, 0},
	{85, ML_CODE_LDLT, setCodeOp_Idx_WZN, setInputIdx_WZN_sameVal16, verifyResultNormal,
			"LDLT_OUT op1z == nop2", 1, 1, 0},
	{86, ML_CODE_LDLT, setCodeOp_Idx_WZN, setInputIdx_WZN_lessVal16, verifyResultNormal,
			"LDLT_OUT op1z < nop2", 1, 1, 1},
	{87, ML_CODE_LDLT, setCodeOp_Idx_WZK, setInputIdx_WZK_bigVal16, verifyResultNormal,
			"LDLT_OUT op1z > K", 1, 1, 0},
	{88, ML_CODE_LDLT, setCodeOp_Idx_WZK, setInputIdx_WZK_sameVal16, verifyResultNormal,
			"LDLT_OUT op1z == K", 1, 1, 0},
	{89, ML_CODE_LDLT, setCodeOp_Idx_WZK, setInputIdx_WZK_lessVal16, verifyResultNormal,
			"LDLT_OUT op1z < K", 1, 1, 1},

	{90, ML_CODE_LDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigVal16, verifyResultNormal,
			"LDLE_OUT op1 > op2z", 0, 1, 0},
	{91, ML_CODE_LDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal16, verifyResultNormal,
			"LDLE_OUT op1 == op2z", 0, 1, 1},
	{92, ML_CODE_LDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessVal16, verifyResultNormal,
			"LDLE_OUT op1 < op2z", 0, 1, 1},
	{93, ML_CODE_LDLE, setCodeOp_Idx_NWZ, setInputIdx_NWZ_bigVal16, verifyResultNormal,
			"LDLE_OUT nop1 > op2z", 0, 1, 0},
	{94, ML_CODE_LDLE, setCodeOp_Idx_NWZ, setInputIdx_NWZ_sameVal16, verifyResultNormal,
			"LDLE_OUT nop1 == op2z", 0, 1, 1},
	{95, ML_CODE_LDLE, setCodeOp_Idx_NWZ, setInputIdx_NWZ_lessVal16, verifyResultNormal,
			"LDLE_OUT nop1 < op2z", 0, 1, 1},
	{96, ML_CODE_LDLE, setCodeOp_Idx_KWZ, setInputIdx_KWZ_bigVal16, verifyResultNormal,
			"LDLE_OUT K > op2z", 0, 1, 0},
	{97, ML_CODE_LDLE, setCodeOp_Idx_KWZ, setInputIdx_KWZ_sameVal16, verifyResultNormal,
			"LDLE_OUT K == op2z", 0, 1, 1},
	{98, ML_CODE_LDLE, setCodeOp_Idx_KWZ, setInputIdx_KWZ_lessVal16, verifyResultNormal,
			"LDLE_OUT K < op2z", 0, 1, 1},
	{99, ML_CODE_LDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_bigVal16, verifyResultNormal,
			"LDLE_OUT op1z > op2", 1, 1, 0},
	{100, ML_CODE_LDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal16, verifyResultNormal,
			"LDLE_OUT op1z == op2", 1, 1, 1},
	{101, ML_CODE_LDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_lessVal16, verifyResultNormal,
			"LDLE_OUT op1z < op2", 1, 1, 1},
	{102, ML_CODE_LDLE, setCodeOp_Idx_WZN, setInputIdx_WZN_bigVal16, verifyResultNormal,
			"LDLE_OUT op1z > nop2", 1, 1, 0},
	{103, ML_CODE_LDLE, setCodeOp_Idx_WZN, setInputIdx_WZN_sameVal16, verifyResultNormal,
			"LDLE_OUT op1z == nop2", 1, 1, 1},
	{104, ML_CODE_LDLE, setCodeOp_Idx_WZN, setInputIdx_WZN_lessVal16, verifyResultNormal,
			"LDLE_OUT op1z < nop2", 1, 1, 1},
	{105, ML_CODE_LDLE, setCodeOp_Idx_WZK, setInputIdx_WZK_bigVal16, verifyResultNormal,
			"LDLE_OUT op1z > K", 1, 1, 0},
	{106, ML_CODE_LDLE, setCodeOp_Idx_WZK, setInputIdx_WZK_sameVal16, verifyResultNormal,
			"LDLE_OUT op1z == K", 1, 1, 1},
	{107, ML_CODE_LDLE, setCodeOp_Idx_WZK, setInputIdx_WZK_lessVal16, verifyResultNormal,
			"LDLE_OUT op1z < K", 1, 1, 1},

	{108, ML_CODE_ANDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1 > op2z", 0, 1, 0},
	{109, ML_CODE_ANDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1 == op2z", 0, 1, 0},
	{110, ML_CODE_ANDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1 < op2z", 0, 1, 0},
	{111, ML_CODE_ANDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1 > op2z", 0, 1, 0},
	{112, ML_CODE_ANDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1 == op2z", 0, 1, 1},
	{113, ML_CODE_ANDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1 < op2z", 0, 1, 0},
	{114, ML_CODE_ANDEQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ANDEQ_OUT nop1 > op2z", 0, 1, 0},
	{115, ML_CODE_ANDEQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ANDEQ_OUT nop1 == op2z", 0, 1, 0},
	{116, ML_CODE_ANDEQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ANDEQ_OUT nop1 < op2z", 0, 1, 0},
	{117, ML_CODE_ANDEQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ANDEQ_OUT nop1 > op2z", 0, 1, 0},
	{118, ML_CODE_ANDEQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ANDEQ_OUT nop1 == op2z", 0, 1, 1},
	{119, ML_CODE_ANDEQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ANDEQ_OUT nop1 < op2z", 0, 1, 0},
	{120, ML_CODE_ANDEQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ANDEQ_OUT K > op2z", 0, 1, 0},
	{121, ML_CODE_ANDEQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ANDEQ_OUT K == op2z", 0, 1, 0},
	{122, ML_CODE_ANDEQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ANDEQ_OUT K < op2z", 0, 1, 0},
	{123, ML_CODE_ANDEQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ANDEQ_OUT K > op2z", 0, 1, 0},
	{124, ML_CODE_ANDEQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ANDEQ_OUT K == op2z", 0, 1, 1},
	{125, ML_CODE_ANDEQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ANDEQ_OUT K < op2z", 0, 1, 0},
	{126, ML_CODE_ANDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1z > op2", 1, 1, 0},
	{127, ML_CODE_ANDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1z == op2", 1, 1, 0},
	{128, ML_CODE_ANDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1z < op2", 1, 1, 0},
	{129, ML_CODE_ANDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1z > op2", 1, 1, 0},
	{130, ML_CODE_ANDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1z == op2", 1, 1, 1},
	{131, ML_CODE_ANDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1z < op2", 1, 1, 0},
	{132, ML_CODE_ANDEQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1z > nop2", 1, 1, 0},
	{133, ML_CODE_ANDEQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1z == nop2", 1, 1, 0},
	{134, ML_CODE_ANDEQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1z < nop2", 1, 1, 0},
	{135, ML_CODE_ANDEQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1z > nop2", 1, 1, 0},
	{136, ML_CODE_ANDEQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1z == nop2", 1, 1, 1},
	{137, ML_CODE_ANDEQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1z < nop2", 1, 1, 0},
	{138, ML_CODE_ANDEQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1z > K", 1, 1, 0},
	{139, ML_CODE_ANDEQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1z == K", 1, 1, 0},
	{140, ML_CODE_ANDEQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ANDEQ_OUT op1z < K", 1, 1, 0},
	{141, ML_CODE_ANDEQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1z > K", 1, 1, 0},
	{142, ML_CODE_ANDEQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1z == K", 1, 1, 1},
	{143, ML_CODE_ANDEQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ANDEQ_OUT op1z < K", 1, 1, 0},

	{144, ML_CODE_ANDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ANDNE_OUT op1 > op2z", 0, 1, 0},
	{145, ML_CODE_ANDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ANDNE_OUT op1 == op2z", 0, 1, 0},
	{146, ML_CODE_ANDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ANDNE_OUT op1 < op2z", 0, 1, 0},
	{147, ML_CODE_ANDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ANDNE_OUT op1 > op2z", 0, 1, 1},
	{148, ML_CODE_ANDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ANDNE_OUT op1 == op2z", 0, 1, 0},
	{149, ML_CODE_ANDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ANDNE_OUT op1 < op2z", 0, 1, 1},
	{150, ML_CODE_ANDNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ANDNE_OUT nop1 > op2z", 0, 1, 0},
	{151, ML_CODE_ANDNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ANDNE_OUT nop1 == op2z", 0, 1, 0},
	{152, ML_CODE_ANDNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ANDNE_OUT nop1 < op2z", 0, 1, 0},
	{153, ML_CODE_ANDNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ANDNE_OUT nop1 > op2z", 0, 1, 1},
	{154, ML_CODE_ANDNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ANDNE_OUT nop1 == op2z", 0, 1, 0},
	{155, ML_CODE_ANDNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ANDNE_OUT nop1 < op2z", 0, 1, 1},
	{156, ML_CODE_ANDNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ANDNE_OUT K > op2z", 0, 1, 0},
	{157, ML_CODE_ANDNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ANDNE_OUT K == op2z", 0, 1, 0},
	{158, ML_CODE_ANDNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ANDNE_OUT K < op2z", 0, 1, 0},
	{159, ML_CODE_ANDNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ANDNE_OUT K > op2z", 0, 1, 1},
	{160, ML_CODE_ANDNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ANDNE_OUT K == op2z", 0, 1, 0},
	{161, ML_CODE_ANDNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ANDNE_OUT K < op2z", 0, 1, 1},
	{162, ML_CODE_ANDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ANDNE_OUT op1z > op2", 1, 1, 0},
	{163, ML_CODE_ANDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ANDNE_OUT op1z == op2", 1, 1, 0},
	{164, ML_CODE_ANDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ANDNE_OUT op1z < op2", 1, 1, 0},
	{165, ML_CODE_ANDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ANDNE_OUT op1z > op2", 1, 1, 1},
	{166, ML_CODE_ANDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ANDNE_OUT op1z == op2", 1, 1, 0},
	{167, ML_CODE_ANDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ANDNE_OUT op1z < op2", 1, 1, 1},
	{168, ML_CODE_ANDNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ANDNE_OUT op1z > nop2", 1, 1, 0},
	{169, ML_CODE_ANDNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ANDNE_OUT op1z == nop2", 1, 1, 0},
	{170, ML_CODE_ANDNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ANDNE_OUT op1z < nop2", 1, 1, 0},
	{171, ML_CODE_ANDNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ANDNE_OUT op1z > nop2", 1, 1, 1},
	{172, ML_CODE_ANDNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ANDNE_OUT op1z == nop2", 1, 1, 0},
	{173, ML_CODE_ANDNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ANDNE_OUT op1z < nop2", 1, 1, 1},
	{174, ML_CODE_ANDNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ANDNE_OUT op1z > K", 1, 1, 0},
	{175, ML_CODE_ANDNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ANDNE_OUT op1z == K", 1, 1, 0},
	{176, ML_CODE_ANDNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ANDNE_OUT op1z < K", 1, 1, 0},
	{177, ML_CODE_ANDNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ANDNE_OUT op1z > K", 1, 1, 1},
	{178, ML_CODE_ANDNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ANDNE_OUT op1z == K", 1, 1, 0},
	{179, ML_CODE_ANDNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ANDNE_OUT op1z < K", 1, 1, 1},

	{180, ML_CODE_ANDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ANDGT_OUT op1 > op2z", 0, 1, 0},
	{181, ML_CODE_ANDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ANDGT_OUT op1 == op2z", 0, 1, 0},
	{182, ML_CODE_ANDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ANDGT_OUT op1 < op2z", 0, 1, 0},
	{183, ML_CODE_ANDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ANDGT_OUT op1 > op2z", 0, 1, 1},
	{184, ML_CODE_ANDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ANDGT_OUT op1 == op2z", 0, 1, 0},
	{185, ML_CODE_ANDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ANDGT_OUT op1 < op2z", 0, 1, 0},
	{186, ML_CODE_ANDGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ANDGT_OUT nop1 > op2z", 0, 1, 0},
	{187, ML_CODE_ANDGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ANDGT_OUT nop1 == op2z", 0, 1, 0},
	{188, ML_CODE_ANDGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ANDGT_OUT nop1 < op2z", 0, 1, 0},
	{189, ML_CODE_ANDGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ANDGT_OUT nop1 > op2z", 0, 1, 1},
	{190, ML_CODE_ANDGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ANDGT_OUT nop1 == op2z", 0, 1, 0},
	{191, ML_CODE_ANDGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ANDGT_OUT nop1 < op2z", 0, 1, 0},
	{192, ML_CODE_ANDGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ANDGT_OUT K > op2z", 0, 1, 0},
	{193, ML_CODE_ANDGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ANDGT_OUT K == op2z", 0, 1, 0},
	{194, ML_CODE_ANDGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ANDGT_OUT K < op2z", 0, 1, 0},
	{195, ML_CODE_ANDGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ANDGT_OUT K > op2z", 0, 1, 1},
	{196, ML_CODE_ANDGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ANDGT_OUT K == op2z", 0, 1, 0},
	{197, ML_CODE_ANDGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ANDGT_OUT K < op2z", 0, 1, 0},
	{198, ML_CODE_ANDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ANDGT_OUT op1z > op2", 1, 1, 0},
	{199, ML_CODE_ANDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ANDGT_OUT op1z == op2", 1, 1, 0},
	{200, ML_CODE_ANDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ANDGT_OUT op1z < op2", 1, 1, 0},
	{201, ML_CODE_ANDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ANDGT_OUT op1z > op2", 1, 1, 1},
	{202, ML_CODE_ANDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ANDGT_OUT op1z == op2", 1, 1, 0},
	{203, ML_CODE_ANDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ANDGT_OUT op1z < op2", 1, 1, 0},
	{204, ML_CODE_ANDGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ANDGT_OUT op1z > nop2", 1, 1, 0},
	{205, ML_CODE_ANDGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ANDGT_OUT op1z == nop2", 1, 1, 0},
	{206, ML_CODE_ANDGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ANDGT_OUT op1z < nop2", 1, 1, 0},
	{207, ML_CODE_ANDGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ANDGT_OUT op1z > nop2", 1, 1, 1},
	{208, ML_CODE_ANDGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ANDGT_OUT op1z == nop2", 1, 1, 0},
	{209, ML_CODE_ANDGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ANDGT_OUT op1z < nop2", 1, 1, 0},
	{210, ML_CODE_ANDGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ANDGT_OUT op1z > K", 1, 1, 0},
	{211, ML_CODE_ANDGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ANDGT_OUT op1z == K", 1, 1, 0},
	{212, ML_CODE_ANDGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ANDGT_OUT op1z < K", 1, 1, 0},
	{213, ML_CODE_ANDGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ANDGT_OUT op1z > K", 1, 1, 1},
	{214, ML_CODE_ANDGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ANDGT_OUT op1z == K", 1, 1, 0},
	{215, ML_CODE_ANDGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ANDGT_OUT op1z < K", 1, 1, 0},

	{216, ML_CODE_ANDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ANDGE_OUT op1 > op2z", 0, 1, 0},
	{217, ML_CODE_ANDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ANDGE_OUT op1 == op2z", 0, 1, 0},
	{218, ML_CODE_ANDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ANDGE_OUT op1 < op2z", 0, 1, 0},
	{219, ML_CODE_ANDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ANDGE_OUT op1 > op2z", 0, 1, 1},
	{220, ML_CODE_ANDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ANDGE_OUT op1 == op2z", 0, 1, 1},
	{221, ML_CODE_ANDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ANDGE_OUT op1 < op2z", 0, 1, 0},
	{222, ML_CODE_ANDGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ANDGE_OUT nop1 > op2z", 0, 1, 0},
	{223, ML_CODE_ANDGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ANDGE_OUT nop1 == op2z", 0, 1, 0},
	{224, ML_CODE_ANDGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ANDGE_OUT nop1 < op2z", 0, 1, 0},
	{225, ML_CODE_ANDGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ANDGE_OUT nop1 > op2z", 0, 1, 1},
	{226, ML_CODE_ANDGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ANDGE_OUT nop1 == op2z", 0, 1, 1},
	{227, ML_CODE_ANDGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ANDGE_OUT nop1 < op2z", 0, 1, 0},
	{228, ML_CODE_ANDGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ANDGE_OUT K > op2z", 0, 1, 0},
	{229, ML_CODE_ANDGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ANDGE_OUT K == op2z", 0, 1, 0},
	{230, ML_CODE_ANDGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ANDGE_OUT K < op2z", 0, 1, 0},
	{231, ML_CODE_ANDGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ANDGE_OUT K > op2z", 0, 1, 1},
	{232, ML_CODE_ANDGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ANDGE_OUT K == op2z", 0, 1, 1},
	{233, ML_CODE_ANDGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ANDGE_OUT K < op2z", 0, 1, 0},
	{234, ML_CODE_ANDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ANDGE_OUT op1z > op2", 1, 1, 0},
	{235, ML_CODE_ANDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ANDGE_OUT op1z == op2", 1, 1, 0},
	{236, ML_CODE_ANDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ANDGE_OUT op1z < op2", 1, 1, 0},
	{237, ML_CODE_ANDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ANDGE_OUT op1z > op2", 1, 1, 1},
	{238, ML_CODE_ANDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ANDGE_OUT op1z == op2", 1, 1, 1},
	{239, ML_CODE_ANDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ANDGE_OUT op1z < op2", 1, 1, 0},
	{240, ML_CODE_ANDGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ANDGE_OUT op1z > nop2", 1, 1, 0},
	{241, ML_CODE_ANDGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ANDGE_OUT op1z == nop2", 1, 1, 0},
	{242, ML_CODE_ANDGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ANDGE_OUT op1z < nop2", 1, 1, 0},
	{243, ML_CODE_ANDGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ANDGE_OUT op1z > nop2", 1, 1, 1},
	{244, ML_CODE_ANDGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ANDGE_OUT op1z == nop2", 1, 1, 1},
	{245, ML_CODE_ANDGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ANDGE_OUT op1z < nop2", 1, 1, 0},
	{246, ML_CODE_ANDGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ANDGE_OUT op1z > K", 1, 1, 0},
	{247, ML_CODE_ANDGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ANDGE_OUT op1z == K", 1, 1, 0},
	{248, ML_CODE_ANDGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ANDGE_OUT op1z < K", 1, 1, 0},
	{249, ML_CODE_ANDGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ANDGE_OUT op1z > K", 1, 1, 1},
	{250, ML_CODE_ANDGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ANDGE_OUT op1z == K", 1, 1, 1},
	{251, ML_CODE_ANDGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ANDGE_OUT op1z < K", 1, 1, 0},

	{252, ML_CODE_ANDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ANDLT_OUT op1 > op2z", 0, 1, 0},
	{253, ML_CODE_ANDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ANDLT_OUT op1 == op2z", 0, 1, 0},
	{254, ML_CODE_ANDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ANDLT_OUT op1 < op2z", 0, 1, 0},
	{255, ML_CODE_ANDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ANDLT_OUT op1 > op2z", 0, 1, 0},
	{256, ML_CODE_ANDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ANDLT_OUT op1 == op2z", 0, 1, 0},
	{257, ML_CODE_ANDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ANDLT_OUT op1 < op2z", 0, 1, 1},
	{258, ML_CODE_ANDLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ANDLT_OUT nop1 > op2z", 0, 1, 0},
	{259, ML_CODE_ANDLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ANDLT_OUT nop1 == op2z", 0, 1, 0},
	{260, ML_CODE_ANDLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ANDLT_OUT nop1 < op2z", 0, 1, 0},
	{261, ML_CODE_ANDLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ANDLT_OUT nop1 > op2z", 0, 1, 0},
	{262, ML_CODE_ANDLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ANDLT_OUT nop1 == op2z", 0, 1, 0},
	{263, ML_CODE_ANDLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ANDLT_OUT nop1 < op2z", 0, 1, 1},
	{264, ML_CODE_ANDLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ANDLT_OUT K > op2z", 0, 1, 0},
	{265, ML_CODE_ANDLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ANDLT_OUT K == op2z", 0, 1, 0},
	{266, ML_CODE_ANDLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ANDLT_OUT K < op2z", 0, 1, 0},
	{267, ML_CODE_ANDLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ANDLT_OUT K > op2z", 0, 1, 0},
	{268, ML_CODE_ANDLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ANDLT_OUT K == op2z", 0, 1, 0},
	{269, ML_CODE_ANDLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ANDLT_OUT K < op2z", 0, 1, 1},
	{270, ML_CODE_ANDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ANDLT_OUT op1z > op2", 1, 1, 0},
	{271, ML_CODE_ANDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ANDLT_OUT op1z == op2", 1, 1, 0},
	{272, ML_CODE_ANDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ANDLT_OUT op1z < op2", 1, 1, 0},
	{273, ML_CODE_ANDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ANDLT_OUT op1z > op2", 1, 1, 0},
	{274, ML_CODE_ANDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ANDLT_OUT op1z == op2", 1, 1, 0},
	{275, ML_CODE_ANDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ANDLT_OUT op1z < op2", 1, 1, 1},
	{276, ML_CODE_ANDLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ANDLT_OUT op1z > nop2", 1, 1, 0},
	{277, ML_CODE_ANDLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ANDLT_OUT op1z == nop2", 1, 1, 0},
	{278, ML_CODE_ANDLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ANDLT_OUT op1z < nop2", 1, 1, 0},
	{279, ML_CODE_ANDLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ANDLT_OUT op1z > nop2", 1, 1, 0},
	{280, ML_CODE_ANDLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ANDLT_OUT op1z == nop2", 1, 1, 0},
	{281, ML_CODE_ANDLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ANDLT_OUT op1z < nop2", 1, 1, 1},
	{282, ML_CODE_ANDLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ANDLT_OUT op1z > K", 1, 1, 0},
	{283, ML_CODE_ANDLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ANDLT_OUT op1z == K", 1, 1, 0},
	{284, ML_CODE_ANDLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ANDLT_OUT op1z < K", 1, 1, 0},
	{285, ML_CODE_ANDLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ANDLT_OUT op1z > K", 1, 1, 0},
	{286, ML_CODE_ANDLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ANDLT_OUT op1z == K", 1, 1, 0},
	{287, ML_CODE_ANDLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ANDLT_OUT op1z < K", 1, 1, 1},

	{288, ML_CODE_ANDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ANDLE_OUT op1 > op2z", 0, 1, 0},
	{289, ML_CODE_ANDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ANDLE_OUT op1 == op2z", 0, 1, 0},
	{290, ML_CODE_ANDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ANDLE_OUT op1 < op2z", 0, 1, 0},
	{291, ML_CODE_ANDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ANDLE_OUT op1 > op2z", 0, 1, 0},
	{292, ML_CODE_ANDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ANDLE_OUT op1 == op2z", 0, 1, 1},
	{293, ML_CODE_ANDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ANDLE_OUT op1 < op2z", 0, 1, 1},
	{294, ML_CODE_ANDLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ANDLE_OUT nop1 > op2z", 0, 1, 0},
	{295, ML_CODE_ANDLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ANDLE_OUT nop1 == op2z", 0, 1, 0},
	{296, ML_CODE_ANDLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ANDLE_OUT nop1 < op2z", 0, 1, 0},
	{297, ML_CODE_ANDLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ANDLE_OUT nop1 > op2z", 0, 1, 0},
	{298, ML_CODE_ANDLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ANDLE_OUT nop1 == op2z", 0, 1, 1},
	{299, ML_CODE_ANDLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ANDLE_OUT nop1 < op2z", 0, 1, 1},
	{300, ML_CODE_ANDLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ANDLE_OUT K > op2z", 0, 1, 0},
	{301, ML_CODE_ANDLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ANDLE_OUT K == op2z", 0, 1, 0},
	{302, ML_CODE_ANDLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ANDLE_OUT K < op2z", 0, 1, 0},
	{303, ML_CODE_ANDLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ANDLE_OUT K > op2z", 0, 1, 0},
	{304, ML_CODE_ANDLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ANDLE_OUT K == op2z", 0, 1, 1},
	{305, ML_CODE_ANDLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ANDLE_OUT K < op2z", 0, 1, 1},
	{306, ML_CODE_ANDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ANDLE_OUT op1z > op2", 1, 1, 0},
	{307, ML_CODE_ANDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ANDLE_OUT op1z == op2", 1, 1, 0},
	{308, ML_CODE_ANDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ANDLE_OUT op1z < op2", 1, 1, 0},
	{309, ML_CODE_ANDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ANDLE_OUT op1z > op2", 1, 1, 0},
	{310, ML_CODE_ANDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ANDLE_OUT op1z == op2", 1, 1, 1},
	{311, ML_CODE_ANDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ANDLE_OUT op1z < op2", 1, 1, 1},
	{312, ML_CODE_ANDLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ANDLE_OUT op1z > nop2", 1, 1, 0},
	{313, ML_CODE_ANDLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ANDLE_OUT op1z == nop2", 1, 1, 0},
	{314, ML_CODE_ANDLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ANDLE_OUT op1z < nop2", 1, 1, 0},
	{315, ML_CODE_ANDLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ANDLE_OUT op1z > nop2", 1, 1, 0},
	{316, ML_CODE_ANDLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ANDLE_OUT op1z == nop2", 1, 1, 1},
	{317, ML_CODE_ANDLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ANDLE_OUT op1z < nop2", 1, 1, 1},
	{318, ML_CODE_ANDLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ANDLE_OUT op1z > K", 1, 1, 0},
	{319, ML_CODE_ANDLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ANDLE_OUT op1z == K", 1, 1, 0},
	{320, ML_CODE_ANDLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ANDLE_OUT op1z < K", 1, 1, 0},
	{321, ML_CODE_ANDLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ANDLE_OUT op1z > K", 1, 1, 0},
	{322, ML_CODE_ANDLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ANDLE_OUT op1z == K", 1, 1, 1},
	{323, ML_CODE_ANDLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ANDLE_OUT op1z < K", 1, 1, 1},

	{324, ML_CODE_OREQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"OREQ_OUT op1 > op2z", 0, 1, 0},
	{325, ML_CODE_OREQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"OREQ_OUT op1 == op2z", 0, 1, 1},
	{326, ML_CODE_OREQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"OREQ_OUT op1 < op2z", 0, 1, 0},
	{327, ML_CODE_OREQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"OREQ_OUT op1 > op2z", 0, 1, 1},
	{328, ML_CODE_OREQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"OREQ_OUT op1 == op2z", 0, 1, 1},
	{329, ML_CODE_OREQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"OREQ_OUT op1 < op2z", 0, 1, 1},
	{330, ML_CODE_OREQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"OREQ_OUT nop1 > op2z", 0, 1, 0},
	{331, ML_CODE_OREQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"OREQ_OUT nop1 == op2z", 0, 1, 1},
	{332, ML_CODE_OREQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"OREQ_OUT nop1 < op2z", 0, 1, 0},
	{333, ML_CODE_OREQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"OREQ_OUT nop1 > op2z", 0, 1, 1},
	{334, ML_CODE_OREQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"OREQ_OUT nop1 == op2z", 0, 1, 1},
	{335, ML_CODE_OREQ, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"OREQ_OUT nop1 < op2z", 0, 1, 1},
	{336, ML_CODE_OREQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"OREQ_OUT K > op2z", 0, 1, 0},
	{337, ML_CODE_OREQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"OREQ_OUT K == op2z", 0, 1, 1},
	{338, ML_CODE_OREQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"OREQ_OUT K < op2z", 0, 1, 0},
	{339, ML_CODE_OREQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"OREQ_OUT K > op2z", 0, 1, 1},
	{340, ML_CODE_OREQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"OREQ_OUT K == op2z", 0, 1, 1},
	{341, ML_CODE_OREQ, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"OREQ_OUT K < op2z", 0, 1, 1},
	{342, ML_CODE_OREQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"OREQ_OUT op1z > op2", 1, 1, 0},
	{343, ML_CODE_OREQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"OREQ_OUT op1z == op2", 1, 1, 1},
	{344, ML_CODE_OREQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"OREQ_OUT op1z < op2", 1, 1, 0},
	{345, ML_CODE_OREQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"OREQ_OUT op1z > op2", 1, 1, 1},
	{346, ML_CODE_OREQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"OREQ_OUT op1z == op2", 1, 1, 1},
	{347, ML_CODE_OREQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"OREQ_OUT op1z < op2", 1, 1, 1},
	{348, ML_CODE_OREQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"OREQ_OUT op1z > nop2", 1, 1, 0},
	{349, ML_CODE_OREQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"OREQ_OUT op1z == nop2", 1, 1, 1},
	{350, ML_CODE_OREQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"OREQ_OUT op1z < nop2", 1, 1, 0},
	{351, ML_CODE_OREQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"OREQ_OUT op1z > nop2", 1, 1, 1},
	{352, ML_CODE_OREQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"OREQ_OUT op1z == nop2", 1, 1, 1},
	{353, ML_CODE_OREQ, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"OREQ_OUT op1z < nop2", 1, 1, 1},
	{354, ML_CODE_OREQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"OREQ_OUT op1z > K", 1, 1, 0},
	{355, ML_CODE_OREQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"OREQ_OUT op1z == K", 1, 1, 1},
	{356, ML_CODE_OREQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"OREQ_OUT op1z < K", 1, 1, 0},
	{357, ML_CODE_OREQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"OREQ_OUT op1z > K", 1, 1, 1},
	{358, ML_CODE_OREQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"OREQ_OUT op1z == K", 1, 1, 1},
	{359, ML_CODE_OREQ, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"OREQ_OUT op1z < K", 1, 1, 1},

	{360, ML_CODE_ORNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ORNE_OUT op1 > op2z", 0, 1, 1},
	{361, ML_CODE_ORNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ORNE_OUT op1 == op2z", 0, 1, 0},
	{362, ML_CODE_ORNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ORNE_OUT op1 < op2z", 0, 1, 1},
	{363, ML_CODE_ORNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ORNE_OUT op1 > op2z", 0, 1, 1},
	{364, ML_CODE_ORNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ORNE_OUT op1 == op2z", 0, 1, 1},
	{365, ML_CODE_ORNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ORNE_OUT op1 < op2z", 0, 1, 1},
	{366, ML_CODE_ORNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ORNE_OUT nop1 > op2z", 0, 1, 1},
	{367, ML_CODE_ORNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ORNE_OUT nop1 == op2z", 0, 1, 0},
	{368, ML_CODE_ORNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ORNE_OUT nop1 < op2z", 0, 1, 1},
	{369, ML_CODE_ORNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ORNE_OUT nop1 > op2z", 0, 1, 1},
	{370, ML_CODE_ORNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ORNE_OUT nop1 == op2z", 0, 1, 1},
	{371, ML_CODE_ORNE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ORNE_OUT nop1 < op2z", 0, 1, 1},
	{372, ML_CODE_ORNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ORNE_OUT K > op2z", 0, 1, 1},
	{373, ML_CODE_ORNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ORNE_OUT K == op2z", 0, 1, 0},
	{374, ML_CODE_ORNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ORNE_OUT K < op2z", 0, 1, 1},
	{375, ML_CODE_ORNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ORNE_OUT K > op2z", 0, 1, 1},
	{376, ML_CODE_ORNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ORNE_OUT K == op2z", 0, 1, 1},
	{377, ML_CODE_ORNE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ORNE_OUT K < op2z", 0, 1, 1},
	{378, ML_CODE_ORNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ORNE_OUT op1z > op2", 1, 1, 1},
	{379, ML_CODE_ORNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ORNE_OUT op1z == op2", 1, 1, 0},
	{380, ML_CODE_ORNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ORNE_OUT op1z < op2", 1, 1, 1},
	{381, ML_CODE_ORNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ORNE_OUT op1z > op2", 1, 1, 1},
	{382, ML_CODE_ORNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ORNE_OUT op1z == op2", 1, 1, 1},
	{383, ML_CODE_ORNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ORNE_OUT op1z < op2", 1, 1, 1},
	{384, ML_CODE_ORNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ORNE_OUT op1z > nop2", 1, 1, 1},
	{385, ML_CODE_ORNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ORNE_OUT op1z == nop2", 1, 1, 0},
	{386, ML_CODE_ORNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ORNE_OUT op1z < nop2", 1, 1, 1},
	{387, ML_CODE_ORNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ORNE_OUT op1z > nop2", 1, 1, 1},
	{388, ML_CODE_ORNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ORNE_OUT op1z == nop2", 1, 1, 1},
	{389, ML_CODE_ORNE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ORNE_OUT op1z < nop2", 1, 1, 1},
	{390, ML_CODE_ORNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ORNE_OUT op1z > K", 1, 1, 1},
	{391, ML_CODE_ORNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ORNE_OUT op1z == K", 1, 1, 0},
	{392, ML_CODE_ORNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ORNE_OUT op1z < K", 1, 1, 1},
	{393, ML_CODE_ORNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ORNE_OUT op1z > K", 1, 1, 1},
	{394, ML_CODE_ORNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ORNE_OUT op1z == K", 1, 1, 1},
	{395, ML_CODE_ORNE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ORNE_OUT op1z < K", 1, 1, 1},

	{396, ML_CODE_ORGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ORGT_OUT op1 > op2z", 0, 1, 1},
	{397, ML_CODE_ORGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ORGT_OUT op1 == op2z", 0, 1, 0},
	{398, ML_CODE_ORGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ORGT_OUT op1 < op2z", 0, 1, 0},
	{399, ML_CODE_ORGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ORGT_OUT op1 > op2z", 0, 1, 1},
	{400, ML_CODE_ORGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ORGT_OUT op1 == op2z", 0, 1, 1},
	{401, ML_CODE_ORGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ORGT_OUT op1 < op2z", 0, 1, 1},
	{402, ML_CODE_ORGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ORGT_OUT nop1 > op2z", 0, 1, 1},
	{403, ML_CODE_ORGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ORGT_OUT nop1 == op2z", 0, 1, 0},
	{404, ML_CODE_ORGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ORGT_OUT nop1 < op2z", 0, 1, 0},
	{405, ML_CODE_ORGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ORGT_OUT nop1 > op2z", 0, 1, 1},
	{406, ML_CODE_ORGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ORGT_OUT nop1 == op2z", 0, 1, 1},
	{407, ML_CODE_ORGT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ORGT_OUT nop1 < op2z", 0, 1, 1},
	{408, ML_CODE_ORGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ORGT_OUT K > op2z", 0, 1, 1},
	{409, ML_CODE_ORGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ORGT_OUT K == op2z", 0, 1, 0},
	{410, ML_CODE_ORGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ORGT_OUT K < op2z", 0, 1, 0},
	{411, ML_CODE_ORGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ORGT_OUT K > op2z", 0, 1, 1},
	{412, ML_CODE_ORGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ORGT_OUT K == op2z", 0, 1, 1},
	{413, ML_CODE_ORGT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ORGT_OUT K < op2z", 0, 1, 1},
	{414, ML_CODE_ORGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ORGT_OUT op1z > op2", 1, 1, 1},
	{415, ML_CODE_ORGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ORGT_OUT op1z == op2", 1, 1, 0},
	{416, ML_CODE_ORGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ORGT_OUT op1z < op2", 1, 1, 0},
	{417, ML_CODE_ORGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ORGT_OUT op1z > op2", 1, 1, 1},
	{418, ML_CODE_ORGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ORGT_OUT op1z == op2", 1, 1, 1},
	{419, ML_CODE_ORGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ORGT_OUT op1z < op2", 1, 1, 1},
	{420, ML_CODE_ORGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ORGT_OUT op1z > nop2", 1, 1, 1},
	{421, ML_CODE_ORGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ORGT_OUT op1z == nop2", 1, 1, 0},
	{422, ML_CODE_ORGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ORGT_OUT op1z < nop2", 1, 1, 0},
	{423, ML_CODE_ORGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ORGT_OUT op1z > nop2", 1, 1, 1},
	{424, ML_CODE_ORGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ORGT_OUT op1z == nop2", 1, 1, 1},
	{425, ML_CODE_ORGT, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ORGT_OUT op1z < nop2", 1, 1, 1},
	{426, ML_CODE_ORGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ORGT_OUT op1z > K", 1, 1, 1},
	{427, ML_CODE_ORGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ORGT_OUT op1z == K", 1, 1, 0},
	{428, ML_CODE_ORGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ORGT_OUT op1z < K", 1, 1, 0},
	{429, ML_CODE_ORGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ORGT_OUT op1z > K", 1, 1, 1},
	{430, ML_CODE_ORGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ORGT_OUT op1z == K", 1, 1, 1},
	{431, ML_CODE_ORGT, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ORGT_OUT op1z < K", 1, 1, 1},

	{432, ML_CODE_ORGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ORGE_OUT op1 > op2z", 0, 1, 1},
	{433, ML_CODE_ORGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ORGE_OUT op1 == op2z", 0, 1, 1},
	{434, ML_CODE_ORGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ORGE_OUT op1 < op2z", 0, 1, 0},
	{435, ML_CODE_ORGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ORGE_OUT op1 > op2z", 0, 1, 1},
	{436, ML_CODE_ORGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ORGE_OUT op1 == op2z", 0, 1, 1},
	{437, ML_CODE_ORGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ORGE_OUT op1 < op2z", 0, 1, 1},
	{438, ML_CODE_ORGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ORGE_OUT nop1 > op2z", 0, 1, 1},
	{439, ML_CODE_ORGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ORGE_OUT nop1 == op2z", 0, 1, 1},
	{440, ML_CODE_ORGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ORGE_OUT nop1 < op2z", 0, 1, 0},
	{441, ML_CODE_ORGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ORGE_OUT nop1 > op2z", 0, 1, 1},
	{442, ML_CODE_ORGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ORGE_OUT nop1 == op2z", 0, 1, 1},
	{443, ML_CODE_ORGE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ORGE_OUT nop1 < op2z", 0, 1, 1},
	{444, ML_CODE_ORGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ORGE_OUT K > op2z", 0, 1, 1},
	{445, ML_CODE_ORGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ORGE_OUT K == op2z", 0, 1, 1},
	{446, ML_CODE_ORGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ORGE_OUT K < op2z", 0, 1, 0},
	{447, ML_CODE_ORGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ORGE_OUT K > op2z", 0, 1, 1},
	{448, ML_CODE_ORGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ORGE_OUT K == op2z", 0, 1, 1},
	{449, ML_CODE_ORGE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ORGE_OUT K < op2z", 0, 1, 1},
	{450, ML_CODE_ORGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ORGE_OUT op1z > op2", 1, 1, 1},
	{451, ML_CODE_ORGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ORGE_OUT op1z == op2", 1, 1, 1},
	{452, ML_CODE_ORGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ORGE_OUT op1z < op2", 1, 1, 0},
	{453, ML_CODE_ORGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ORGE_OUT op1z > op2", 1, 1, 1},
	{454, ML_CODE_ORGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ORGE_OUT op1z == op2", 1, 1, 1},
	{455, ML_CODE_ORGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ORGE_OUT op1z < op2", 1, 1, 1},
	{456, ML_CODE_ORGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ORGE_OUT op1z > nop2", 1, 1, 1},
	{457, ML_CODE_ORGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ORGE_OUT op1z == nop2", 1, 1, 1},
	{458, ML_CODE_ORGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ORGE_OUT op1z < nop2", 1, 1, 0},
	{459, ML_CODE_ORGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ORGE_OUT op1z > nop2", 1, 1, 1},
	{460, ML_CODE_ORGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ORGE_OUT op1z == nop2", 1, 1, 1},
	{461, ML_CODE_ORGE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ORGE_OUT op1z < nop2", 1, 1, 1},
	{462, ML_CODE_ORGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ORGE_OUT op1z > K", 1, 1, 1},
	{463, ML_CODE_ORGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ORGE_OUT op1z == K", 1, 1, 1},
	{464, ML_CODE_ORGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ORGE_OUT op1z < K", 1, 1, 0},
	{465, ML_CODE_ORGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ORGE_OUT op1z > K", 1, 1, 1},
	{466, ML_CODE_ORGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ORGE_OUT op1z == K", 1, 1, 1},
	{467, ML_CODE_ORGE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ORGE_OUT op1z < K", 1, 1, 1},

	{468, ML_CODE_ORLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ORLT_OUT op1 > op2z", 0, 1, 0},
	{469, ML_CODE_ORLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ORLT_OUT op1 == op2z", 0, 1, 0},
	{470, ML_CODE_ORLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ORLT_OUT op1 < op2z", 0, 1, 1},
	{471, ML_CODE_ORLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ORLT_OUT op1 > op2z", 0, 1, 1},
	{472, ML_CODE_ORLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ORLT_OUT op1 == op2z", 0, 1, 1},
	{473, ML_CODE_ORLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ORLT_OUT op1 < op2z", 0, 1, 1},
	{474, ML_CODE_ORLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ORLT_OUT nop1 > op2z", 0, 1, 0},
	{475, ML_CODE_ORLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ORLT_OUT nop1 == op2z", 0, 1, 0},
	{476, ML_CODE_ORLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ORLT_OUT nop1 < op2z", 0, 1, 1},
	{477, ML_CODE_ORLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ORLT_OUT nop1 > op2z", 0, 1, 1},
	{478, ML_CODE_ORLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ORLT_OUT nop1 == op2z", 0, 1, 1},
	{479, ML_CODE_ORLT, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ORLT_OUT nop1 < op2z", 0, 1, 1},
	{480, ML_CODE_ORLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ORLT_OUT K > op2z", 0, 1, 0},
	{481, ML_CODE_ORLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ORLT_OUT K == op2z", 0, 1, 0},
	{482, ML_CODE_ORLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ORLT_OUT K < op2z", 0, 1, 1},
	{483, ML_CODE_ORLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ORLT_OUT K > op2z", 0, 1, 1},
	{484, ML_CODE_ORLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ORLT_OUT K == op2z", 0, 1, 1},
	{485, ML_CODE_ORLT, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ORLT_OUT K < op2z", 0, 1, 1},
	{486, ML_CODE_ORLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ORLT_OUT op1z > op2", 1, 1, 0},
	{487, ML_CODE_ORLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ORLT_OUT op1z == op2", 1, 1, 0},
	{488, ML_CODE_ORLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ORLT_OUT op1z < op2", 1, 1, 1},
	{489, ML_CODE_ORLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ORLT_OUT op1z > op2", 1, 1, 1},
	{490, ML_CODE_ORLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ORLT_OUT op1z == op2", 1, 1, 1},
	{491, ML_CODE_ORLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ORLT_OUT op1z < op2", 1, 1, 1},
	{492, ML_CODE_ORLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ORLT_OUT op1z > nop2", 1, 1, 0},
	{493, ML_CODE_ORLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ORLT_OUT op1z == nop2", 1, 1, 0},
	{494, ML_CODE_ORLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ORLT_OUT op1z < nop2", 1, 1, 1},
	{495, ML_CODE_ORLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ORLT_OUT op1z > nop2", 1, 1, 1},
	{496, ML_CODE_ORLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ORLT_OUT op1z == nop2", 1, 1, 1},
	{497, ML_CODE_ORLT, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ORLT_OUT op1z < nop2", 1, 1, 1},
	{498, ML_CODE_ORLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ORLT_OUT op1z > K", 1, 1, 0},
	{499, ML_CODE_ORLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ORLT_OUT op1z == K", 1, 1, 0},
	{500, ML_CODE_ORLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ORLT_OUT op1z < K", 1, 1, 1},
	{501, ML_CODE_ORLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ORLT_OUT op1z > K", 1, 1, 1},
	{502, ML_CODE_ORLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ORLT_OUT op1z == K", 1, 1, 1},
	{503, ML_CODE_ORLT, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ORLT_OUT op1z < K", 1, 1, 1},

	{504, ML_CODE_ORLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_off, verifyResultNormal,
			"ORLE_OUT op1 > op2z", 0, 1, 0},
	{505, ML_CODE_ORLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_off, verifyResultNormal,
			"ORLE_OUT op1 == op2z", 0, 1, 1},
	{506, ML_CODE_ORLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_off, verifyResultNormal,
			"ORLE_OUT op1 < op2z", 0, 1, 1},
	{507, ML_CODE_ORLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigVal16_on, verifyResultNormal,
			"ORLE_OUT op1 > op2z", 0, 1, 1},
	{508, ML_CODE_ORLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal16_on, verifyResultNormal,
			"ORLE_OUT op1 == op2z", 0, 1, 1},
	{509, ML_CODE_ORLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessVal16_on, verifyResultNormal,
			"ORLE_OUT op1 < op2z", 0, 1, 1},
	{510, ML_CODE_ORLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_off, verifyResultNormal,
			"ORLE_OUT nop1 > op2z", 0, 1, 0},
	{511, ML_CODE_ORLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_off, verifyResultNormal,
			"ORLE_OUT nop1 == op2z", 0, 1, 1},
	{512, ML_CODE_ORLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_off, verifyResultNormal,
			"ORLE_OUT nop1 < op2z", 0, 1, 1},
	{513, ML_CODE_ORLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_bigVal16_on, verifyResultNormal,
			"ORLE_OUT nop1 > op2z", 0, 1, 1},
	{514, ML_CODE_ORLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_sameVal16_on, verifyResultNormal,
			"ORLE_OUT nop1 == op2z", 0, 1, 1},
	{515, ML_CODE_ORLE, setCodeOp2_Idx_NWZ, setInputIdx_NWZ_lessVal16_on, verifyResultNormal,
			"ORLE_OUT nop1 < op2z", 0, 1, 1},
	{516, ML_CODE_ORLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_off, verifyResultNormal,
			"ORLE_OUT K > op2z", 0, 1, 0},
	{517, ML_CODE_ORLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_off, verifyResultNormal,
			"ORLE_OUT K == op2z", 0, 1, 1},
	{518, ML_CODE_ORLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_off, verifyResultNormal,
			"ORLE_OUT K < op2z", 0, 1, 1},
	{519, ML_CODE_ORLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_bigVal16_on, verifyResultNormal,
			"ORLE_OUT K > op2z", 0, 1, 1},
	{520, ML_CODE_ORLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_sameVal16_on, verifyResultNormal,
			"ORLE_OUT K == op2z", 0, 1, 1},
	{521, ML_CODE_ORLE, setCodeOp2_Idx_KWZ, setInputIdx_KWZ_lessVal16_on, verifyResultNormal,
			"ORLE_OUT K < op2z", 0, 1, 1},
	{522, ML_CODE_ORLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_off, verifyResultNormal,
			"ORLE_OUT op1z > op2", 1, 1, 0},
	{523, ML_CODE_ORLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_off, verifyResultNormal,
			"ORLE_OUT op1z == op2", 1, 1, 1},
	{524, ML_CODE_ORLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_off, verifyResultNormal,
			"ORLE_OUT op1z < op2", 1, 1, 1},
	{525, ML_CODE_ORLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigVal16_on, verifyResultNormal,
			"ORLE_OUT op1z > op2", 1, 1, 1},
	{526, ML_CODE_ORLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal16_on, verifyResultNormal,
			"ORLE_OUT op1z == op2", 1, 1, 1},
	{527, ML_CODE_ORLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessVal16_on, verifyResultNormal,
			"ORLE_OUT op1z < op2", 1, 1, 1},
	{528, ML_CODE_ORLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_off, verifyResultNormal,
			"ORLE_OUT op1z > nop2", 1, 1, 0},
	{529, ML_CODE_ORLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_off, verifyResultNormal,
			"ORLE_OUT op1z == nop2", 1, 1, 1},
	{530, ML_CODE_ORLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_off, verifyResultNormal,
			"ORLE_OUT op1z < nop2", 1, 1, 1},
	{531, ML_CODE_ORLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_bigVal16_on, verifyResultNormal,
			"ORLE_OUT op1z > nop2", 1, 1, 1},
	{532, ML_CODE_ORLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_sameVal16_on, verifyResultNormal,
			"ORLE_OUT op1z == nop2", 1, 1, 1},
	{533, ML_CODE_ORLE, setCodeOp2_Idx_WZN, setInputIdx_WZN_lessVal16_on, verifyResultNormal,
			"ORLE_OUT op1z < nop2", 1, 1, 1},
	{534, ML_CODE_ORLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_off, verifyResultNormal,
			"ORLE_OUT op1z > K", 1, 1, 0},
	{535, ML_CODE_ORLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_off, verifyResultNormal,
			"ORLE_OUT op1z == K", 1, 1, 1},
	{536, ML_CODE_ORLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_off, verifyResultNormal,
			"ORLE_OUT op1z < K", 1, 1, 1},
	{537, ML_CODE_ORLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_bigVal16_on, verifyResultNormal,
			"ORLE_OUT op1z > K", 1, 1, 1},
	{538, ML_CODE_ORLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_sameVal16_on, verifyResultNormal,
			"ORLE_OUT op1z == K", 1, 1, 1},
	{539, ML_CODE_ORLE, setCodeOp2_Idx_WZK, setInputIdx_WZK_lessVal16_on, verifyResultNormal,
			"ORLE_OUT op1z < K", 1, 1, 1},

	{-1, 0xFFFF, NULL, NULL, NULL, NULL, 0, 0 }
};

int total_basic_comp_word_index_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_comp_word_index_test_number; i++)
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

// op1 : word register
// op2 : word + index register
// out : bit register
int setCodeOp_Idx_WWZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;
	if(in1 == in2 && in1_pos == in2_pos+idx_val) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : bit nibble register
// op2 : word + index register
// out : bit register
int setCodeOp_Idx_NWZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_B || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;
	if(in1 == out && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(4, in1, in1_pos); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : K constant
// op2 : word + index register
// out : bit register
int setCodeOp_Idx_KWZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_X || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 256); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word + index register
// op2 : word register
// out : bit register
int setCodeOp_Idx_WZW
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;
	if(in1 == in2 && in1_pos+idx_val == in2_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperand(in2, in2_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word + index register
// op2 : bit nibble register
// out : bit register
int setCodeOp_Idx_WZN
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_B ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;
	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperandNibble(4, in2, in2_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word + index register
// op2 : K constant
// out : bit register
int setCodeOp_Idx_WZK
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_X ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_K, 256);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word register
// op2 : word + index register
// out : bit register
int setCodeOp2_Idx_WWZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;
	if(in1 == in2 && in1_pos == in2_pos+idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


// op1 : bit nibble register
// op2 : word + index register
// out : bit register
int setCodeOp2_Idx_NWZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_B || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;
	if(in1 == out && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in1, in1_pos); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : K constant
// op2 : word + index register
// out : bit register
int setCodeOp2_Idx_KWZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_X || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 256); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word + index register
// op2 : word register
// out : bit register
int setCodeOp2_Idx_WZW
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;
	if(in1 == in2 && in1_pos+idx_val == in2_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperand(in2, in2_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word + index register
// op2 : bit nibble register
// out : bit register
int setCodeOp2_Idx_WZN
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_B ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;
	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperandNibble(4, in2, in2_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word + index register
// op2 : K constant
// out : bit register
int setCodeOp2_Idx_WZK
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_X ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_K, 256);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputIdx_WWZ_bigVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos, 257);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_sameVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos, 257);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_lessVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos, 256);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_bigVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_sameVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_lessVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=256;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_bigVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 255);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_sameVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 256);
	DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_lessVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_bigVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_sameVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_lessVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 256);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_bigVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=256;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_sameVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_lessVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 256);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_bigVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_sameVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_lessVal16
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 255);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}


void setInputIdx_WWZ_bigVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos, 257);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_bigVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos, 257);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}


void setInputIdx_WWZ_sameVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos, 257);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_sameVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos, 257);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_lessVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos, 256);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_lessVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos, 256);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_bigVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_bigVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_sameVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_sameVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_lessVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=256;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_lessVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=256;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_bigVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 255);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_bigVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 255);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_sameVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 256);
	DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_sameVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 256);
	DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_lessVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_lessVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}


void setInputIdx_WZW_bigVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos, 256);
	DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_bigVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos, 256);
	DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_sameVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_sameVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_lessVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 256);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_lessVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 256);
	addDeviceControlInstruction(0, (uint8)in2, in2_pos, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_bigVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=256;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_bigVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=256;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_sameVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_sameVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}
void setInputIdx_WZN_lessVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 256);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_lessVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	short value=257;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 256);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_bigVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_bigVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 257);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_sameVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_sameVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 256);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_lessVal16_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 255);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_lessVal16_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in1, in1_pos+z_val, 255);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}
/*
static int isIndexRangeOver(int type, uint16 in1_reg, uint16 in1_pos, uint16 in2_reg, uint16 in2_pos, short idx_val)
{
	// X,Y,R,L,F,B,SM,D,W
	uint16 lastIndex[] = {8191,8191,8191,8191,2047,8191,0,12287,8191};

	if(type == 0 ) // op2 is index
	{
		if( in2_reg < OPERAND_ML_CODE_D) return 1;

		if( in2_pos+idx_val > lastIndex[in2_reg] || in2_pos+idx_val < 0 )
			return 1;
	}
	else if(type == 1) // op1 is index
	{
		if( in1_reg < OPERAND_ML_CODE_D) return 1;

		if( in1_pos+idx_val > lastIndex[in1_reg] || in1_pos+idx_val < 0 )
			return 1;
	}
	return 0;
}
*/
static uint16 getInPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12287,8191}};

	return pos[inx_pos][reg];
}

static uint16 getOutPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096},
			{8191,8191,8191,8191,2047,8191}};

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_compare_word_index(int tno, uint16 dummy)
{
	int rc=0, vc=0, ml_rc=1, i=0, j=1, inx=0, olast=0;
	short zVal, Dreg_val1, Dreg_val2;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_Y;
	uint16 in1_pos=0, in2_pos=0, out_pos=0;
	uint8 res_bit;
	//uint16 idx_pos[]={0,7,15};
	//uint32 in1_val=257, in2_val=257, out_val=0;
	//short expected=1;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
	//for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		//if(out==OPERAND_ML_CODE_F) continue;

		out_pos = getOutPos(out, olast);
		for(in1=OPERAND_ML_CODE_X; in1<=OPERAND_ML_CODE_W; in1++)
		{
			for(i=0; i<3; i++) // index pos of in1
			{
				in1_pos = getInPos(in1, i);
				for(in2=OPERAND_ML_CODE_X; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(j=0; j<3; j++) //index pos of in2
					{
						in2_pos = getInPos(in2, j);
						for(inx=0; inx<15; inx++) // testidx
						{
							PLC_DEVICE_Init();

							ml_rc = testCase[tno].setTestCode_fn(testCase[tno].ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, \
									testidx[inx].pos, testidx[inx].val);
							if(ml_rc==0)
							{
								//DBG_LOGPRINT(" SKIP test invalid operand op1=%s[%d] op2=%s[%d]\n", reg[in1], in1_pos, reg[in2], in2_pos);
								continue;
							}

							//DBG_LOGPRINT("test proceed ! %s[%d] = %s[%d] %s[%d] Z[%d]=%d\n", \
								reg[out], out_pos, reg[in1], in1_pos, reg[in2], in2_pos, testidx[inx].pos, testidx[inx].val);

							testCase[tno].setTestInput_fn(in1,in1_pos,in2,in2_pos, testidx[inx].pos,testidx[inx].val);

							test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
							rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								if(testCase[tno].z_type == 0)
								{
									if(in1 > OPERAND_ML_CODE_B)
										test_getWord(&Dreg_val1, in1, in1_pos);
									else
										test_getNibble(&Dreg_val1, in1, in1_pos, 4);
									test_getWord(&Dreg_val2, in2, in2_pos+zVal);
									fprintf(flog,"test_no[%d] run time error Z[%d]=%d, %s[%d]=%d %s[%d+%d]=%d\n",
										tno, testidx[inx].pos, zVal, reg[in1], in1_pos, Dreg_val1, reg[in2], in2_pos, zVal, Dreg_val2);
								}
								else if(testCase[tno].z_type == 1)
								{

									test_getWord(&Dreg_val1, in1, in1_pos+zVal);
									if(in1 > OPERAND_ML_CODE_B)
										test_getWord(&Dreg_val2, in2, in2_pos);
									else
										test_getNibble(&Dreg_val2, in2, in2_pos, 4);
									fprintf(flog, "test_no[%d] run time error Z[%d]=%d, %s[%d+%d]=%d %s[%d]=%d\n", \
										tno, testidx[inx].pos, zVal, reg[in1], in1_pos, zVal, Dreg_val1, reg[in2], in2_pos, Dreg_val2);
								}
							}
							else
							{
								vc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
								if( vc == 1)
								{
									if(testCase[tno].z_type == 0)
									{
										if(in1 > OPERAND_ML_CODE_B)
											test_getWord(&Dreg_val1, in1, in1_pos);
										else
											test_getNibble(&Dreg_val1, in1, in1_pos, 4);
										test_getWord(&Dreg_val2, in2, in2_pos+zVal);
										fprintf(flog, "test_no[%d] error index Z[%d]=%d, %s[%d]=%d %s[%d+%d]=%d\n",
											tno, testidx[inx].pos, zVal, reg[in1], in1_pos, Dreg_val1, reg[in2], in2_pos, zVal, Dreg_val2);
									}
									else if(testCase[tno].z_type == 1)
									{
										test_getWord(&Dreg_val1, in1, in1_pos+zVal);
										if(in1 > OPERAND_ML_CODE_B)
											test_getWord(&Dreg_val2, in2, in2_pos);
										else
											test_getNibble(&Dreg_val2, in2, in2_pos, 4);
										fprintf(flog, "test_no[%d] error index Z[%d]=%d, %s[%d+%d]=%d %s[%d]=%d\n", \
											tno, testidx[inx].pos, zVal, reg[in1], in1_pos, zVal, Dreg_val1, reg[in2], in2_pos, Dreg_val2);
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
}

void testBasicCompareWordIndexCommand(void)
{
	int i, index=0;
	int start, end;
	char log[] = "err_comp_word_index.txt";

#if 0
	test_basic_compare_word_index(index, 0);
#else
	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare word index LOG file open error !\n");
		exit(1);
	}
	total_basic_comp_word_index_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LDEQ);
	end = getTestCaseNumberEnd(ML_CODE_ORLE); //ML_CODE_ORLE

	DBG_LOGPRINT("testBasicCompareWordIndexCommand: %d to %d total %d\n", start, end, total_basic_comp_word_index_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_compare_word_index(index, 0);
	}

	fclose(flog);
#endif
}

#endif
