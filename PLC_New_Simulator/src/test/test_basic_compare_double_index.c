/*
 * test_basic_compare_double_index.c
 *
 *  Created on: Aug 10, 2015
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

extern int setCodeOp_Idx_WWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp_Idx_WZW(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_Idx_WWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_Idx_WZW(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

int setCodeOp_Idx_DEWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp_Idx_WZDE(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

int setCodeOp2_Idx_DEWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_Idx_WZDE(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_WWZ_bigValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_sameValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_lessValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_DEWZ_bigValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_DEWZ_sameValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_DEWZ_lessValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_WZW_bigValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_sameValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_lessValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_WZDE_bigValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZDE_sameValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZDE_lessValDouble(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_WWZ_bigValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_sameValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_lessValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_bigValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_sameValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_lessValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_DEWZ_bigValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_DEWZ_sameValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_DEWZ_lessValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_DEWZ_bigValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_DEWZ_sameValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_DEWZ_lessValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_WZW_bigValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_sameValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_lessValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_bigValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_sameValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_lessValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_WZDE_bigValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZDE_sameValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZDE_lessValDouble_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZDE_bigValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZDE_sameValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZDE_lessValDouble_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

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
	{0, ML_CODE_LDEDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigValDouble, verifyResultNormal,
			"LDEDEQ op1 > index op2", 0, 1, 0},
	{1, ML_CODE_LDEDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameValDouble, verifyResultNormal,
			"LDEDEQ op1 == index op2", 0, 1, 1},
	{2, ML_CODE_LDEDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessValDouble, verifyResultNormal,
			"LDEDEQ op1 < index op2", 0, 1, 0},
	{3, ML_CODE_LDEDEQ, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDEQ DE > index op2", 0, 1, 0},
	{4, ML_CODE_LDEDEQ, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble, verifyResultNormal,
			"LDEDEQ DE == index op2", 0, 1, 1},
	{5, ML_CODE_LDEDEQ, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble, verifyResultNormal,
			"LDEDEQ DE < index op2", 0, 1, 0},
	{6, ML_CODE_LDEDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_bigValDouble, verifyResultNormal,
			"LDEDEQ op1 > index op2", 1, 1, 0},
	{7, ML_CODE_LDEDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_sameValDouble, verifyResultNormal,
			"LDEDEQ op1 == index op2", 1, 1, 1},
	{8, ML_CODE_LDEDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_lessValDouble, verifyResultNormal,
			"LDEDEQ op1 < index op2", 1, 1, 0},
	{9, ML_CODE_LDEDEQ, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDEQ DE > index op2", 1, 1, 0},
	{10, ML_CODE_LDEDEQ, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDEQ DE == index op2", 1, 1, 1},
	{11, ML_CODE_LDEDEQ, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDEQ DE < index op2", 1, 1, 0},

	{12, ML_CODE_LDEDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigValDouble, verifyResultNormal,
			"LDEDNE op1 > index op2", 0, 1, 1},
	{13, ML_CODE_LDEDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameValDouble, verifyResultNormal,
			"LDEDNE op1 == index op2", 0, 1, 0},
	{14, ML_CODE_LDEDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessValDouble, verifyResultNormal,
			"LDEDEQ op1 < index op2", 0, 1, 1},
	{15, ML_CODE_LDEDNE, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDNE DE > index op2", 0, 1, 1},
	{16, ML_CODE_LDEDNE, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble, verifyResultNormal,
			"LDEDNE DE == index op2", 0, 1, 0},
	{17, ML_CODE_LDEDNE, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble, verifyResultNormal,
			"LDEDNE DE < index op2", 0, 1, 1},
	{18, ML_CODE_LDEDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_bigValDouble, verifyResultNormal,
			"LDEDNE op1 > index op2", 1, 1, 1},
	{19, ML_CODE_LDEDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_sameValDouble, verifyResultNormal,
			"LDEDNE op1 == index op2", 1, 1, 0},
	{20, ML_CODE_LDEDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_lessValDouble, verifyResultNormal,
			"LDEDNE op1 < index op2", 1, 1, 1},
	{21, ML_CODE_LDEDNE, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDNE DE > index op2", 1, 1, 1},
	{22, ML_CODE_LDEDNE, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDNE DE == index op2", 1, 1, 0},
	{23, ML_CODE_LDEDNE, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDNE DE < index op2", 1, 1, 1},

	{24, ML_CODE_LDEDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigValDouble, verifyResultNormal,
			"LDEDGT op1 > index op2", 0, 1, 1},
	{25, ML_CODE_LDEDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameValDouble, verifyResultNormal,
			"LDEDGT op1 == index op2", 0, 1, 0},
	{26, ML_CODE_LDEDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessValDouble, verifyResultNormal,
			"LDEDEQ op1 < index op2", 0, 1, 0},
	{27, ML_CODE_LDEDGT, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDGT DE > index op2", 0, 1, 1},
	{28, ML_CODE_LDEDGT, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble, verifyResultNormal,
			"LDEDGT DE == index op2", 0, 1, 0},
	{29, ML_CODE_LDEDGT, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble, verifyResultNormal,
			"LDEDGT DE < index op2", 0, 1, 0},
	{30, ML_CODE_LDEDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_bigValDouble, verifyResultNormal,
			"LDEDGT op1 > index op2", 1, 1, 1},
	{31, ML_CODE_LDEDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_sameValDouble, verifyResultNormal,
			"LDEDGT op1 == index op2", 1, 1, 0},
	{32, ML_CODE_LDEDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_lessValDouble, verifyResultNormal,
			"LDEDGT op1 < index op2", 1, 1, 0},
	{33, ML_CODE_LDEDGT, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDGT DE > index op2", 1, 1, 1},
	{34, ML_CODE_LDEDGT, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDGT DE == index op2", 1, 1, 0},
	{35, ML_CODE_LDEDGT, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDGT DE < index op2", 1, 1, 0},

	{36, ML_CODE_LDEDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigValDouble, verifyResultNormal,
			"LDEDGE op1 > index op2", 0, 1, 1},
	{37, ML_CODE_LDEDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameValDouble, verifyResultNormal,
			"LDEDGE op1 == index op2", 0, 1, 1},
	{38, ML_CODE_LDEDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessValDouble, verifyResultNormal,
			"LDEDEQ op1 < index op2", 0, 1, 0},
	{39, ML_CODE_LDEDGE, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDGE DE > index op2", 0, 1, 1},
	{40, ML_CODE_LDEDGE, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble, verifyResultNormal,
			"LDEDGE DE == index op2", 0, 1, 1},
	{41, ML_CODE_LDEDGE, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble, verifyResultNormal,
			"LDEDGE DE < index op2", 0, 1, 0},
	{42, ML_CODE_LDEDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_bigValDouble, verifyResultNormal,
			"LDEDGE op1 > index op2", 1, 1, 1},
	{43, ML_CODE_LDEDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_sameValDouble, verifyResultNormal,
			"LDEDGE op1 == index op2", 1, 1, 1},
	{44, ML_CODE_LDEDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_lessValDouble, verifyResultNormal,
			"LDEDGE op1 < index op2", 1, 1, 0},
	{45, ML_CODE_LDEDGE, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDGE DE > index op2", 1, 1, 1},
	{46, ML_CODE_LDEDGE, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDGE DE == index op2", 1, 1, 1},
	{47, ML_CODE_LDEDGE, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDGE DE < index op2", 1, 1, 0},

	{48, ML_CODE_LDEDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigValDouble, verifyResultNormal,
			"LDEDLT op1 > index op2", 0, 1, 0},
	{49, ML_CODE_LDEDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameValDouble, verifyResultNormal,
			"LDEDLT op1 == index op2", 0, 1, 0},
	{50, ML_CODE_LDEDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessValDouble, verifyResultNormal,
			"LDEDEQ op1 < index op2", 0, 1, 1},
	{51, ML_CODE_LDEDLT, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDLT DE > index op2", 0, 1, 0},
	{52, ML_CODE_LDEDLT, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble, verifyResultNormal,
			"LDEDLT DE == index op2", 0, 1, 0},
	{53, ML_CODE_LDEDLT, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble, verifyResultNormal,
			"LDEDLT DE < index op2", 0, 1, 1},
	{54, ML_CODE_LDEDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_bigValDouble, verifyResultNormal,
			"LDEDLT op1 > index op2", 1, 1, 0},
	{55, ML_CODE_LDEDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_sameValDouble, verifyResultNormal,
			"LDEDLT op1 == index op2", 1, 1, 0},
	{56, ML_CODE_LDEDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_lessValDouble, verifyResultNormal,
			"LDEDLT op1 < index op2", 1, 1, 1},
	{57, ML_CODE_LDEDLT, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDLT DE > index op2", 1, 1, 0},
	{58, ML_CODE_LDEDLT, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDLT DE == index op2", 1, 1, 0},
	{59, ML_CODE_LDEDLT, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDLT DE < index op2", 1, 1, 1},

	{60, ML_CODE_LDEDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_bigValDouble, verifyResultNormal,
			"LDEDLE op1 > index op2", 0, 1, 0},
	{61, ML_CODE_LDEDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameValDouble, verifyResultNormal,
			"LDEDLE op1 == index op2", 0, 1, 1},
	{62, ML_CODE_LDEDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lessValDouble, verifyResultNormal,
			"LDEDEQ op1 < index op2", 0, 1, 1},
	{63, ML_CODE_LDEDLE, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDLE DE > index op2", 0, 1, 0},
	{64, ML_CODE_LDEDLE, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble, verifyResultNormal,
			"LDEDLE DE == index op2", 0, 1, 1},
	{65, ML_CODE_LDEDLE, setCodeOp_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble, verifyResultNormal,
			"LDEDLE DE < index op2", 0, 1, 1},
	{66, ML_CODE_LDEDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_bigValDouble, verifyResultNormal,
			"LDEDLE op1 > index op2", 1, 1, 0},
	{67, ML_CODE_LDEDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_sameValDouble, verifyResultNormal,
			"LDEDLE op1 == index op2", 1, 1, 1},
	{68, ML_CODE_LDEDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_lessValDouble, verifyResultNormal,
			"LDEDLE op1 < index op2", 1, 1, 1},
	{69, ML_CODE_LDEDLE, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDLE DE > index op2", 1, 1, 0},
	{70, ML_CODE_LDEDLE, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDLE DE == index op2", 1, 1, 1},
	{71, ML_CODE_LDEDLE, setCodeOp_Idx_WZDE, setInputIdx_DEWZ_bigValDouble, verifyResultNormal,
			"LDEDLE DE < index op2", 1, 1, 1},

	{72, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDEQ off S > DZ", 0, 1, 0},
	{73, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDEQ off S = DZ", 0, 1, 0},
	{74, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDEQ off S < DZ", 0, 1, 0},
	{75, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDEQ on S > DZ", 0, 1, 0},
	{76, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDEQ on S = DZ", 0, 1, 1},
	{77, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDEQ on S < DZ", 0, 1, 0},
	{78, ML_CODE_ANDEDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDEQ off F > DZ", 0, 1, 0},
	{79, ML_CODE_ANDEDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDEQ off F = DZ", 0, 1, 0},
	{80, ML_CODE_ANDEDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDEQ off F < DZ", 0, 1, 0},
	{81, ML_CODE_ANDEDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDEQ on F > DZ", 0, 1, 0},
	{82, ML_CODE_ANDEDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDEQ on F = DZ", 0, 1, 1},
	{83, ML_CODE_ANDEDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDEQ on F < DZ", 0, 1, 0},
	{84, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"ANDEDEQ off SZ > D", 1, 1, 0},
	{85, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"ANDEDEQ off SZ = D", 1, 1, 0},
	{86, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"ANDEDEQ off SZ < D", 1, 1, 0},
	{87, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"ANDEDEQ on SZ > D", 1, 1, 0},
	{88, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"ANDEDEQ on SZ = D", 1, 1, 1},
	{89, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"ANDEDEQ on SZ < D", 1, 1, 0},
	{90, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"ANDEDEQ off SZ > F", 1, 1, 0},
	{91, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"ANDEDEQ off SZ = F", 1, 1, 0},
	{92, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"ANDEDEQ off SZ < F", 1, 1, 0},
	{93, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"ANDEDEQ on SZ > F", 1, 1, 0},
	{94, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"ANDEDEQ on SZ = F", 1, 1, 1},
	{95, ML_CODE_ANDEDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"ANDEDEQ on SZ < F", 1, 1, 0},

	{96, ML_CODE_ANDEDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDNE off S > DZ", 0, 1, 0},
	{97, ML_CODE_ANDEDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDNE off S = DZ", 0, 1, 0},
	{98, ML_CODE_ANDEDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDNE off S < DZ", 0, 1, 0},
	{99, ML_CODE_ANDEDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDNE on S > DZ", 0, 1, 1},
	{100, ML_CODE_ANDEDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDNE on S = DZ", 0, 1, 0},
	{101, ML_CODE_ANDEDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDNE on S < DZ", 0, 1, 1},
	{102, ML_CODE_ANDEDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDNE off F > DZ", 0, 1, 0},
	{103, ML_CODE_ANDEDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDNE off F = DZ", 0, 1, 0},
	{104, ML_CODE_ANDEDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDNE off F < DZ", 0, 1, 0},
	{105, ML_CODE_ANDEDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDNE on F > DZ", 0, 1, 1},
	{106, ML_CODE_ANDEDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDNE on F = DZ", 0, 1, 0},
	{107, ML_CODE_ANDEDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDNE on F < DZ", 0, 1, 1},
	{108, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"ANDEDNE off SZ > D", 1, 1, 0},
	{109, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"ANDEDNE off SZ = D", 1, 1, 0},
	{110, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"ANDEDNE off SZ < D", 1, 1, 0},
	{111, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"ANDEDNE on SZ > D", 1, 1, 1},
	{112, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"ANDEDNE on SZ = D", 1, 1, 0},
	{113, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"ANDEDNE on SZ < D", 1, 1, 1},
	{114, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"ANDEDNE off SZ > F", 1, 1, 0},
	{115, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"ANDEDNE off SZ = F", 1, 1, 0},
	{116, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"ANDEDNE off SZ < F", 1, 1, 0},
	{117, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"ANDEDNE on SZ > F", 1, 1, 1},
	{118, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"ANDEDNE on SZ = F", 1, 1, 0},
	{119, ML_CODE_ANDEDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"ANDEDNE on SZ < F", 1, 1, 1},

	{120, ML_CODE_ANDEDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDGT off S > DZ", 0, 1, 0},
	{121, ML_CODE_ANDEDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDGT off S = DZ", 0, 1, 0},
	{122, ML_CODE_ANDEDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDGT off S < DZ", 0, 1, 0},
	{123, ML_CODE_ANDEDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDGT on S > DZ", 0, 1, 1},
	{124, ML_CODE_ANDEDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDGT on S = DZ", 0, 1, 0},
	{125, ML_CODE_ANDEDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDGT on S < DZ", 0, 1, 0},
	{126, ML_CODE_ANDEDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDGT off F > DZ", 0, 1, 0},
	{127, ML_CODE_ANDEDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDGT off F = DZ", 0, 1, 0},
	{128, ML_CODE_ANDEDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDGT off F < DZ", 0, 1, 0},
	{129, ML_CODE_ANDEDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDGT on F > DZ", 0, 1, 1},
	{130, ML_CODE_ANDEDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDGT on F = DZ", 0, 1, 0},
	{131, ML_CODE_ANDEDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDGT on F < DZ", 0, 1, 0},
	{132, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"ANDEDGT off SZ > D", 1, 1, 0},
	{133, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"ANDEDGT off SZ = D", 1, 1, 0},
	{134, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"ANDEDGT off SZ < D", 1, 1, 0},
	{135, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"ANDEDGT on SZ > D", 1, 1, 1},
	{136, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"ANDEDGT on SZ = D", 1, 1, 0},
	{137, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"ANDEDGT on SZ < D", 1, 1, 0},
	{138, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"ANDEDGT off SZ > F", 1, 1, 0},
	{139, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"ANDEDGT off SZ = F", 1, 1, 0},
	{140, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"ANDEDGT off SZ < F", 1, 1, 0},
	{141, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"ANDEDGT on SZ > F", 1, 1, 1},
	{142, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"ANDEDGT on SZ = F", 1, 1, 0},
	{143, ML_CODE_ANDEDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"ANDEDGT on SZ < F", 1, 1, 0},

	{144, ML_CODE_ANDEDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDGE off S > DZ", 0, 1, 0},
	{145, ML_CODE_ANDEDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDGE off S = DZ", 0, 1, 0},
	{146, ML_CODE_ANDEDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDGE off S < DZ", 0, 1, 0},
	{147, ML_CODE_ANDEDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDGE on S > DZ", 0, 1, 1},
	{148, ML_CODE_ANDEDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDGE on S = DZ", 0, 1, 1},
	{149, ML_CODE_ANDEDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDGE on S < DZ", 0, 1, 0},
	{150, ML_CODE_ANDEDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDGE off F > DZ", 0, 1, 0},
	{151, ML_CODE_ANDEDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDGE off F = DZ", 0, 1, 0},
	{152, ML_CODE_ANDEDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDGE off F < DZ", 0, 1, 0},
	{153, ML_CODE_ANDEDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDGE on F > DZ", 0, 1, 1},
	{154, ML_CODE_ANDEDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDGE on F = DZ", 0, 1, 1},
	{155, ML_CODE_ANDEDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDGE on F < DZ", 0, 1, 0},
	{156, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"ANDEDGE off SZ > D", 1, 1, 0},
	{157, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"ANDEDGE off SZ = D", 1, 1, 0},
	{158, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"ANDEDGE off SZ < D", 1, 1, 0},
	{159, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"ANDEDGE on SZ > D", 1, 1, 1},
	{160, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"ANDEDGE on SZ = D", 1, 1, 1},
	{161, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"ANDEDGE on SZ < D", 1, 1, 0},
	{162, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"ANDEDGE off SZ > F", 1, 1, 0},
	{163, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"ANDEDGE off SZ = F", 1, 1, 0},
	{164, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"ANDEDGE off SZ < F", 1, 1, 0},
	{165, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"ANDEDGE on SZ > F", 1, 1, 1},
	{166, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"ANDEDGE on SZ = F", 1, 1, 1},
	{167, ML_CODE_ANDEDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"ANDEDGE on SZ < F", 1, 1, 0},

	{168, ML_CODE_ANDEDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDLT off S > DZ", 0, 1, 0},
	{169, ML_CODE_ANDEDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDLT off S = DZ", 0, 1, 0},
	{170, ML_CODE_ANDEDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDLT off S < DZ", 0, 1, 0},
	{171, ML_CODE_ANDEDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDLT on S > DZ", 0, 1, 0},
	{172, ML_CODE_ANDEDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDLT on S = DZ", 0, 1, 0},
	{173, ML_CODE_ANDEDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDLT on S < DZ", 0, 1, 1},
	{174, ML_CODE_ANDEDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDLT off F > DZ", 0, 1, 0},
	{175, ML_CODE_ANDEDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDLT off F = DZ", 0, 1, 0},
	{176, ML_CODE_ANDEDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDLT off F < DZ", 0, 1, 0},
	{177, ML_CODE_ANDEDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDLT on F > DZ", 0, 1, 0},
	{178, ML_CODE_ANDEDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDLT on F = DZ", 0, 1, 0},
	{179, ML_CODE_ANDEDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDLT on F < DZ", 0, 1, 1},
	{180, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"ANDEDLT off SZ > D", 1, 1, 0},
	{181, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"ANDEDLT off SZ = D", 1, 1, 0},
	{182, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"ANDEDLT off SZ < D", 1, 1, 0},
	{183, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"ANDEDLT on SZ > D", 1, 1, 0},
	{184, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"ANDEDLT on SZ = D", 1, 1, 0},
	{185, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"ANDEDLT on SZ < D", 1, 1, 1},
	{186, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"ANDEDLT off SZ > F", 1, 1, 0},
	{187, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"ANDEDLT off SZ = F", 1, 1, 0},
	{188, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"ANDEDLT off SZ < F", 1, 1, 0},
	{189, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"ANDEDLT on SZ > F", 1, 1, 0},
	{190, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"ANDEDLT on SZ = F", 1, 1, 0},
	{191, ML_CODE_ANDEDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"ANDEDLT on SZ < F", 1, 1, 1},

	{192, ML_CODE_ANDEDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDLE off S > DZ", 0, 1, 0},
	{193, ML_CODE_ANDEDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDLE off S = DZ", 0, 1, 0},
	{194, ML_CODE_ANDEDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDLE off S < DZ", 0, 1, 0},
	{195, ML_CODE_ANDEDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDLE on S > DZ", 0, 1, 0},
	{196, ML_CODE_ANDEDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDLE on S = DZ", 0, 1, 1},
	{197, ML_CODE_ANDEDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDLE on S < DZ", 0, 1, 1},
	{198, ML_CODE_ANDEDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"ANDEDLE off F > DZ", 0, 1, 0},
	{199, ML_CODE_ANDEDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"ANDEDLE off F = DZ", 0, 1, 0},
	{200, ML_CODE_ANDEDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"ANDEDLE off F < DZ", 0, 1, 0},
	{201, ML_CODE_ANDEDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"ANDEDLE on F > DZ", 0, 1, 0},
	{202, ML_CODE_ANDEDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"ANDEDLE on F = DZ", 0, 1, 1},
	{203, ML_CODE_ANDEDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"ANDEDLE on F < DZ", 0, 1, 1},
	{204, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"ANDEDLE off SZ > D", 1, 1, 0},
	{205, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"ANDEDLE off SZ = D", 1, 1, 0},
	{206, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"ANDEDLE off SZ < D", 1, 1, 0},
	{207, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"ANDEDLE on SZ > D", 1, 1, 0},
	{208, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"ANDEDLE on SZ = D", 1, 1, 1},
	{209, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"ANDEDLE on SZ < D", 1, 1, 1},
	{210, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"ANDEDLE off SZ > F", 1, 1, 0},
	{211, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"ANDEDLE off SZ = F", 1, 1, 0},
	{212, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"ANDEDLE off SZ < F", 1, 1, 0},
	{213, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"ANDEDLE on SZ > F", 1, 1, 0},
	{214, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"ANDEDLE on SZ = F", 1, 1, 1},
	{215, ML_CODE_ANDEDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"ANDEDLE on SZ < F", 1, 1, 1},

	{216, ML_CODE_OREDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"OREDEQ off S > DZ", 0, 1, 0},
	{217, ML_CODE_OREDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"OREDEQ off S = DZ", 0, 1, 1},
	{218, ML_CODE_OREDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"OREDEQ off S < DZ", 0, 1, 0},
	{219, ML_CODE_OREDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"OREDEQ on S > DZ", 0, 1, 1},
	{220, ML_CODE_OREDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"OREDEQ on S = DZ", 0, 1, 1},
	{221, ML_CODE_OREDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"OREDEQ on S < DZ", 0, 1, 1},
	{222, ML_CODE_OREDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"OREDEQ off F > DZ", 0, 1, 0},
	{223, ML_CODE_OREDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"OREDEQ off F = DZ", 0, 1, 1},
	{224, ML_CODE_OREDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"OREDEQ off F < DZ", 0, 1, 0},
	{225, ML_CODE_OREDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"OREDEQ on F > DZ", 0, 1, 1},
	{226, ML_CODE_OREDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"OREDEQ on F = DZ", 0, 1, 1},
	{227, ML_CODE_OREDEQ, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"OREDEQ on F < DZ", 0, 1, 1},
	{228, ML_CODE_OREDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"OREDEQ off SZ > D", 1, 1, 0},
	{229, ML_CODE_OREDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"OREDEQ off SZ = D", 1, 1, 1},
	{230, ML_CODE_OREDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"OREDEQ off SZ < D", 1, 1, 0},
	{231, ML_CODE_OREDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"OREDEQ on SZ > D", 1, 1, 1},
	{232, ML_CODE_OREDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"OREDEQ on SZ = D", 1, 1, 1},
	{233, ML_CODE_OREDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"OREDEQ on SZ < D", 1, 1, 1},
	{234, ML_CODE_OREDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"OREDEQ off SZ > F", 1, 1, 0},
	{235, ML_CODE_OREDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"OREDEQ off SZ = F", 1, 1, 1},
	{236, ML_CODE_OREDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"OREDEQ off SZ < F", 1, 1, 0},
	{237, ML_CODE_OREDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"OREDEQ on SZ > F", 1, 1, 1},
	{238, ML_CODE_OREDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"OREDEQ on SZ = F", 1, 1, 1},
	{239, ML_CODE_OREDEQ, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"OREDEQ on SZ < F", 1, 1, 1},

	{240, ML_CODE_OREDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"OREDNE off S > DZ", 0, 1, 1},
	{241, ML_CODE_OREDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"OREDNE off S = DZ", 0, 1, 0},
	{242, ML_CODE_OREDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"OREDNE off S < DZ", 0, 1, 1},
	{243, ML_CODE_OREDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"OREDNE on S > DZ", 0, 1, 1},
	{244, ML_CODE_OREDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"OREDNE on S = DZ", 0, 1, 1},
	{245, ML_CODE_OREDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"OREDNE on S < DZ", 0, 1, 1},
	{246, ML_CODE_OREDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"OREDNE off F > DZ", 0, 1, 1},
	{247, ML_CODE_OREDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"OREDNE off F = DZ", 0, 1, 0},
	{248, ML_CODE_OREDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"OREDNE off F < DZ", 0, 1, 1},
	{249, ML_CODE_OREDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"OREDNE on F > DZ", 0, 1, 1},
	{250, ML_CODE_OREDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"OREDNE on F = DZ", 0, 1, 1},
	{251, ML_CODE_OREDNE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"OREDNE on F < DZ", 0, 1, 1},
	{252, ML_CODE_OREDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"OREDNE off SZ > D", 1, 1, 1},
	{253, ML_CODE_OREDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"OREDNE off SZ = D", 1, 1, 0},
	{254, ML_CODE_OREDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"OREDNE off SZ < D", 1, 1, 1},
	{255, ML_CODE_OREDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"OREDNE on SZ > D", 1, 1, 1},
	{256, ML_CODE_OREDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"OREDNE on SZ = D", 1, 1, 1},
	{257, ML_CODE_OREDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"OREDNE on SZ < D", 1, 1, 1},
	{258, ML_CODE_OREDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"OREDNE off SZ > F", 1, 1, 1},
	{259, ML_CODE_OREDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"OREDNE off SZ = F", 1, 1, 0},
	{260, ML_CODE_OREDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"OREDNE off SZ < F", 1, 1, 1},
	{261, ML_CODE_OREDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"OREDNE on SZ > F", 1, 1, 1},
	{262, ML_CODE_OREDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"OREDNE on SZ = F", 1, 1, 1},
	{263, ML_CODE_OREDNE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"OREDNE on SZ < F", 1, 1, 1},

	{264, ML_CODE_OREDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"OREDGT off S > DZ", 0, 1, 1},
	{265, ML_CODE_OREDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"OREDGT off S = DZ", 0, 1, 0},
	{266, ML_CODE_OREDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"OREDGT off S < DZ", 0, 1, 0},
	{267, ML_CODE_OREDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"OREDGT on S > DZ", 0, 1, 1},
	{268, ML_CODE_OREDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"OREDGT on S = DZ", 0, 1, 1},
	{269, ML_CODE_OREDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"OREDGT on S < DZ", 0, 1, 1},
	{270, ML_CODE_OREDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"OREDGT off F > DZ", 0, 1, 1},
	{271, ML_CODE_OREDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"OREDGT off F = DZ", 0, 1, 0},
	{272, ML_CODE_OREDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"OREDGT off F < DZ", 0, 1, 0},
	{273, ML_CODE_OREDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"OREDGT on F > DZ", 0, 1, 1},
	{274, ML_CODE_OREDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"OREDGT on F = DZ", 0, 1, 1},
	{275, ML_CODE_OREDGT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"OREDGT on F < DZ", 0, 1, 1},
	{276, ML_CODE_OREDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"OREDGT off SZ > D", 1, 1, 1},
	{277, ML_CODE_OREDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"OREDGT off SZ = D", 1, 1, 0},
	{278, ML_CODE_OREDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"OREDGT off SZ < D", 1, 1, 0},
	{279, ML_CODE_OREDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"OREDGT on SZ > D", 1, 1, 1},
	{280, ML_CODE_OREDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"OREDGT on SZ = D", 1, 1, 1},
	{281, ML_CODE_OREDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"OREDGT on SZ < D", 1, 1, 1},
	{282, ML_CODE_OREDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"OREDGT off SZ > F", 1, 1, 1},
	{283, ML_CODE_OREDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"OREDGT off SZ = F", 1, 1, 0},
	{284, ML_CODE_OREDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"OREDGT off SZ < F", 1, 1, 0},
	{285, ML_CODE_OREDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"OREDGT on SZ > F", 1, 1, 1},
	{286, ML_CODE_OREDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"OREDGT on SZ = F", 1, 1, 1},
	{287, ML_CODE_OREDGT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"OREDGT on SZ < F", 1, 1, 1},

	{288, ML_CODE_OREDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"OREDGE off S > DZ", 0, 1, 1},
	{289, ML_CODE_OREDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"OREDGE off S = DZ", 0, 1, 1},
	{290, ML_CODE_OREDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"OREDGE off S < DZ", 0, 1, 0},
	{291, ML_CODE_OREDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"OREDGE on S > DZ", 0, 1, 1},
	{292, ML_CODE_OREDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"OREDGE on S = DZ", 0, 1, 1},
	{293, ML_CODE_OREDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"OREDGE on S < DZ", 0, 1, 1},
	{294, ML_CODE_OREDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"OREDGE off F > DZ", 0, 1, 1},
	{295, ML_CODE_OREDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"OREDGE off F = DZ", 0, 1, 1},
	{296, ML_CODE_OREDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"OREDGE off F < DZ", 0, 1, 0},
	{297, ML_CODE_OREDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"OREDGE on F > DZ", 0, 1, 1},
	{298, ML_CODE_OREDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"OREDGE on F = DZ", 0, 1, 1},
	{299, ML_CODE_OREDGE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"OREDGE on F < DZ", 0, 1, 1},
	{300, ML_CODE_OREDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"OREDGE off SZ > D", 1, 1, 1},
	{301, ML_CODE_OREDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"OREDGE off SZ = D", 1, 1, 1},
	{302, ML_CODE_OREDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"OREDGE off SZ < D", 1, 1, 0},
	{303, ML_CODE_OREDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"OREDGE on SZ > D", 1, 1, 1},
	{304, ML_CODE_OREDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"OREDGE on SZ = D", 1, 1, 1},
	{305, ML_CODE_OREDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"OREDGE on SZ < D", 1, 1, 1},
	{306, ML_CODE_OREDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"OREDGE off SZ > F", 1, 1, 1},
	{307, ML_CODE_OREDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"OREDGE off SZ = F", 1, 1, 1},
	{308, ML_CODE_OREDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"OREDGE off SZ< F", 1, 1, 0},
	{309, ML_CODE_OREDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"OREDGE on SZ > F", 1, 1, 1},
	{310, ML_CODE_OREDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"OREDGE on SZ = F", 1, 1, 1},
	{311, ML_CODE_OREDGE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"OREDGE on SZ < F", 1, 1, 1},

	{312, ML_CODE_OREDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"ORELT off S > DZ", 0, 1, 0},
	{313, ML_CODE_OREDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"ORELT off S = DZ", 0, 1, 0},
	{314, ML_CODE_OREDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"ORELT off S < DZ", 0, 1, 1},
	{315, ML_CODE_OREDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"ORELT on S > DZ", 0, 1, 1},
	{316, ML_CODE_OREDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"ORELT on S = DZ", 0, 1, 1},
	{317, ML_CODE_OREDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"ORELT on S < DZ", 0, 1, 1},
	{318, ML_CODE_OREDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"ORELT off F > DZ", 0, 1, 0},
	{319, ML_CODE_OREDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"ORELT off F = DZ", 0, 1, 0},
	{320, ML_CODE_OREDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"ORELT off F < DZ", 0, 1, 1},
	{321, ML_CODE_OREDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"ORELT on F > DZ", 0, 1, 1},
	{322, ML_CODE_OREDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"ORELT on F = DZ", 0, 1, 1},
	{323, ML_CODE_OREDLT, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"ORELT on F < DZ", 0, 1, 1},
	{324, ML_CODE_OREDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"ORELT off S > DZ", 1, 1, 0},
	{325, ML_CODE_OREDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"ORELT off S = DZ", 1, 1, 0},
	{326, ML_CODE_OREDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"ORELT off S < DZ", 1, 1, 1},
	{327, ML_CODE_OREDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"ORELT on S > DZ", 1, 1, 1},
	{328, ML_CODE_OREDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"ORELT on S = DZ", 1, 1, 1},
	{329, ML_CODE_OREDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"ORELT on S < DZ", 1, 1, 1},
	{330, ML_CODE_OREDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"ORELT off F > DZ", 1, 1, 0},
	{331, ML_CODE_OREDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"ORELT off F = DZ", 1, 1, 0},
	{332, ML_CODE_OREDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"ORELT off F < DZ", 1, 1, 1},
	{333, ML_CODE_OREDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"ORELT on F > DZ", 1, 1, 1},
	{334, ML_CODE_OREDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"ORELT on F = DZ", 1, 1, 1},
	{335, ML_CODE_OREDLT, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"ORELT on F < DZ", 1, 1, 1},

	{336, ML_CODE_OREDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_off, verifyResultNormal,
			"ORELE off S > DZ", 0, 1, 0},
	{337, ML_CODE_OREDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_off, verifyResultNormal,
			"ORELE off S = DZ", 0, 1, 1},
	{338, ML_CODE_OREDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_off, verifyResultNormal,
			"ORELE off S < DZ", 0, 1, 1},
	{339, ML_CODE_OREDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_bigValDouble_on, verifyResultNormal,
			"ORELE on S > DZ", 0, 1, 1},
	{340, ML_CODE_OREDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameValDouble_on, verifyResultNormal,
			"ORELE on S = DZ", 0, 1, 1},
	{341, ML_CODE_OREDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lessValDouble_on, verifyResultNormal,
			"ORELE on S < DZ", 0, 1, 1},
	{342, ML_CODE_OREDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_off, verifyResultNormal,
			"ORELE off F > DZ", 0, 1, 0},
	{343, ML_CODE_OREDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_off, verifyResultNormal,
			"ORELE off F = DZ", 0, 1, 0},
	{344, ML_CODE_OREDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_off, verifyResultNormal,
			"ORELE off F < DZ", 0, 1, 1},
	{345, ML_CODE_OREDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_bigValDouble_on, verifyResultNormal,
			"ORELE on F > DZ", 0, 1, 1},
	{346, ML_CODE_OREDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_sameValDouble_on, verifyResultNormal,
			"ORELE on F = DZ", 0, 1, 1},
	{347, ML_CODE_OREDLE, setCodeOp2_Idx_DEWZ, setInputIdx_DEWZ_lessValDouble_on, verifyResultNormal,
			"ORELE on F < DZ", 0, 1, 1},
	{348, ML_CODE_OREDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_off, verifyResultNormal,
			"ORELE off S > DZ", 1, 1, 0},
	{349, ML_CODE_OREDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_off, verifyResultNormal,
			"ORELE off S = DZ", 1, 1, 1},
	{350, ML_CODE_OREDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_off, verifyResultNormal,
			"ORELE off S < DZ", 1, 1, 1},
	{351, ML_CODE_OREDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_bigValDouble_on, verifyResultNormal,
			"ORELE on S > DZ", 1, 1, 1},
	{352, ML_CODE_OREDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameValDouble_on, verifyResultNormal,
			"ORELE on S = DZ", 1, 1, 1},
	{353, ML_CODE_OREDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lessValDouble_on, verifyResultNormal,
			"ORELE on S < DZ", 1, 1, 1},
	{354, ML_CODE_OREDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_off, verifyResultNormal,
			"ORELE off F > DZ", 1, 1, 0},
	{355, ML_CODE_OREDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_off, verifyResultNormal,
			"ORELE off F = DZ", 1, 1, 0},
	{356, ML_CODE_OREDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_off, verifyResultNormal,
			"ORELE off F < DZ", 1, 1, 1},
	{357, ML_CODE_OREDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_bigValDouble_on, verifyResultNormal,
			"ORELE on F > DZ", 1, 1, 1},
	{358, ML_CODE_OREDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_sameValDouble_on, verifyResultNormal,
			"ORELE on F = DZ", 1, 1, 1},
	{359, ML_CODE_OREDLE, setCodeOp2_Idx_WZDE, setInputIdx_WZDE_lessValDouble_on, verifyResultNormal,
			"ORELE on F < DZ", 1, 1, 1},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0, 0 }
};

int total_basic_comp_double_idx_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_comp_double_idx_test_number; i++)
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


// op1 : word + index register
// op2 : DE constant
// out : bit register
int setCodeOp_Idx_DEWZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_X || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;
	if(in2 == out && in2_pos+idx_val == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandDouble(OPERAND_ML_CODE_DE, 1.23f); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word + index register
// op2 : DE constant
// out : bit register
int setCodeOp_Idx_WZDE
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_X ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;
	if(in1 == out && in1_pos+idx_val == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperandDouble(OPERAND_ML_CODE_DE, 1.23f);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : K constant
// op2 : word + index register
// out : bit register
int setCodeOp2_Idx_DEWZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_X || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;
	if(in2 == out && in2_pos+idx_val == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandDouble(OPERAND_ML_CODE_DE, 1.23f); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : K constant
// op2 : word + index register
// out : bit register
int setCodeOp2_Idx_WZDE
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_X ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;
	if(in1 == out && in1_pos+idx_val == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperandDouble(OPERAND_ML_CODE_DE, 1.23f);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}



void setInputIdx_WWZ_bigValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos, 1.23);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_sameValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos, 1.23);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_lessValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos, 1.22);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_DEWZ_bigValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_DEWZ_sameValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_DEWZ_lessValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.24);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_bigValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.23);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_sameValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.23);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_lessValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.22);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZDE_bigValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.24);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZDE_sameValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZDE_lessValDouble
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_bigValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos, 1.23);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_sameValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos, 1.23);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_lessValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos, 1.22);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_bigValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos, 1.23);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_sameValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos, 1.23);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_lessValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos, 1.22);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_DEWZ_bigValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_DEWZ_sameValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_DEWZ_lessValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.24);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_DEWZ_bigValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_DEWZ_sameValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_DEWZ_lessValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos+z_val, 1.24);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_bigValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.23);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_sameValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.23);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_lessValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.22);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_bigValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.23);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_sameValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.23);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_lessValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.22);
	addDeviceControlInstructionToDouble(0, (uint8)in2, in2_pos, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZDE_bigValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.24);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZDE_sameValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}


void setInputIdx_WZDE_lessValDouble_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZDE_bigValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.24);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZDE_sameValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.23);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}


void setInputIdx_WZDE_lessValDouble_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in1, in1_pos+z_val, 1.22);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}
/*
static int isIndexRangeOver(int type, uint16 in1_reg, uint16 in1_pos, uint16 in2_reg, uint16 in2_pos, short idx_val)
{
	// X,Y,R,L,F,B,SM,D,W
	uint16 lastIndex[] = {8188,8188,8188,8188,2044,8188,0,12284,8188};

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
			{8176,8176,8176,8176,2032,8176,0,12284,8188}}; // 4 word required

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
void test_basic_compare_double_index(int tno, uint16 dummy)
{
	int i=0, j, ml_rc, rc=0, inx, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=0, out=OPERAND_ML_CODE_L;
	short zVal;
	double Dreg_val1, Dreg_val2;
	uint16 in1_pos, in2_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
	//for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		if(out==OPERAND_ML_CODE_F) continue;

		out_pos = getOutPos(out, olast);
		for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
		{
			for(i=0; i<3; i++) // index pos of in1
			{
				in1_pos = getInPos(in1, i);
				for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(j=0; j<3; j++) //index pos of in2
					{
						in2_pos = getInPos(in2, j);
						for(inx=0; inx<15; inx++) // testidx
						{
/*
							if( isIndexRangeOver(testCase[tno].z_type, in1, in1_pos, in2, in2_pos, testidx[inx].val) )
							{
								//DBG_LOGPRINT(" SKIP test range error %s[%d] Z[%d]=%d \n", reg[in2], in2_pos, testidx[inx].pos, testidx[inx].val);
								continue; // skip test
							}

							if( in1 == in2 && in1_pos == in2_pos )
							{
								//DBG_LOGPRINT(" SKIP test same op1, op2 %s[%d] \n", reg[in2], in2_pos);
								continue; // skip test
							}
*/
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
								fprintf(flog, "test_no[%d] run time error Z[%d]=%d, %s[%d]=%f %s[%d+%d]=%f\n", \
									tno, testidx[inx].pos, zVal, reg[in1], in1_pos, Dreg_val1, reg[in2], in2_pos, zVal, Dreg_val2);
							}
							else
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
								if(rc == 1)
								{
									if(testCase[tno].z_type == 0)
									{
										test_getDouble(&Dreg_val1, in1, in1_pos);
										test_getDouble(&Dreg_val2, in2, in2_pos+zVal);
									}
									else if(testCase[tno].z_type == 1)
									{
										test_getDouble(&Dreg_val1, in1, in1_pos+zVal);
										test_getDouble(&Dreg_val2, in2, in2_pos);
									}

									fprintf(flog, "test_no[%d] error Z[%d]=%d, %s[%d]=%f %s[%d+%d]=%f\n", \
										tno, testidx[inx].pos, zVal, reg[in1], in1_pos, Dreg_val1, reg[in2], in2_pos, zVal, Dreg_val2);
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

void testBasicCompareDoubleIndexCommand(void)
{
	int index=349;
	int start, end;
	char log[] = "err_comp_double_index.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare double index LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=186;index<192;index++)
		test_basic_compare_double_index(index, 0);
#else
	total_basic_comp_double_idx_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LDEDEQ);
	end = getTestCaseNumberEnd(ML_CODE_OREDLE); //ML_CODE_OREDLE

	DBG_LOGPRINT("testBasicCompareDoubleIndexCommand: %d to %d total %d\n", start, end, total_basic_comp_double_idx_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_compare_double_index(index, 0);
	}
#endif
	fclose(flog);
}
#endif
