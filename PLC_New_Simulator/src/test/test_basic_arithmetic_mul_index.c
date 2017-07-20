/*
 * test_basic_arithmetic_mul_index.c
 *
 *  Created on: Aug 31, 2015
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

extern int setCodeOp3S_WW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_W_WWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_KW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_KK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_NW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_NWZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_BKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_BKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZBK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZBK_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp2_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp3_val16_WW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_W_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_KW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_NW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_NWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZN_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_NWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val16p_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp2_BCD4_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4p_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4p_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4p_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_KWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4p_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_NWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4p_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_WZW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4p_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_WZN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4p_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_WZWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_BCD4p_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp3_BCD4_WW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_W_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_KW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_NW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_NWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZN_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_NWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_BCD4p_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected);
extern int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected);

int setCodeOp3S_WZW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_NWZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZWZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZBK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

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
	int (*verifyResult_fn)(int, uint8, uint16, int);
	char str[40];
	//int count;
	int z_type; // 0 : out is index, 1: op1 is index
	int run_step;
	int expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_MLT, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_off, verifyResultValueDWord,
			"MLT off zop3=op1*op2", 0, 1, 0},
	{1, ML_CODE_MLT, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_on, verifyResultValueDWord,
			"MLT on zop3=op1*op2", 0, 1, 7006652},
	{2, ML_CODE_MLT, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_off, verifyResultValueDWord,
			"MLT off zop3=op1*op2", 0, 1, 0},
	{3, ML_CODE_MLT, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_on, verifyResultValueDWord,
			"MLT on zop3=op1*op2", 0, 1, 7006652},
	{4, ML_CODE_MLT, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_off, verifyResultValueDWord,
			"MLT off zop3=K*op2", 0, 1, 0},
	{5, ML_CODE_MLT, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_on, verifyResultValueDWord,
			"MLT on zop3=K*op2", 0, 1, 7006652},
	{6, ML_CODE_MLT, setCodeOp3S_KK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"MLT off zop3=K*K", 0, 1, 0},
	{7, ML_CODE_MLT, setCodeOp3S_KK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"MLT on zop3=K*K", 0, 1, 7006652},
	{8, ML_CODE_MLT, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_off, verifyResultValueDWord,
			"MLT off zop3=nop1*op2", 0, 1, 0},
	{9, ML_CODE_MLT, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_on, verifyResultValueDWord,
			"MLT on zop3=nop1*op2", 0, 1, 7006652},
	{10, ML_CODE_MLT, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_off, verifyResultValueDWord,
			"MLT off zop3=op1*nop2", 0, 1, 0},
	{11, ML_CODE_MLT, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_on, verifyResultValueDWord,
			"MLT on zop3=op1*nop2", 0, 1, 7006652},
	{12, ML_CODE_MLT, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_off, verifyResultValueDWord,
			"MLT off zop3=zop1*op2", 2, 1, 0},
	{13, ML_CODE_MLT, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_on, verifyResultValueDWord,
			"MLT on zop3=zop1*op2", 2, 1, 7006652},
	{14, ML_CODE_MLT, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_off, verifyResultValueDWord,
			"MLT off zop3=zop1*K", 2, 1, 0},
	{15, ML_CODE_MLT, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_on, verifyResultValueDWord,
			"MLT on zop3=zop1*K", 2, 1, 7006652},
	{16, ML_CODE_MLT, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_off, verifyResultValueDWord,
			"MLT off zop3=zop1*nop2", 2, 1, 0},
	{17, ML_CODE_MLT, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_on, verifyResultValueDWord,
			"MLT on zop3=zop1*nop2", 2, 1, 7006652},
	{18, ML_CODE_MLT, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_off, verifyResultValueDWord,
			"MLT off zop3=nop1*zop2", 2, 1, 0},
	{19, ML_CODE_MLT, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_on, verifyResultValueDWord,
			"MLT on zop3=nop1*zop2", 2, 1, 7006652},
	{20, ML_CODE_MLT, setCodeOp3S_WZW_DN, setInputOp3_val16_WZW_WZ_off, verifyResultValueNibble8,
			"MLT off nop3=zop1*op2", 1, 1, 0},
	{21, ML_CODE_MLT, setCodeOp3S_WZW_DN, setInputOp3_val16_WZW_WZ_on, verifyResultValueNibble8,
			"MLT on nop3=zop1*op2", 1, 1, 7006652},
	{22, ML_CODE_MLT, setCodeOp3S_WZK_DN, setInputOp3_val16_WZK_WZ_off, verifyResultValueNibble8,
			"MLT off nop3=zop1*K", 1, 1, 0},
	{23, ML_CODE_MLT, setCodeOp3S_WZK_DN, setInputOp3_val16_WZK_WZ_on, verifyResultValueNibble8,
			"MLT on nop3=zop1*K", 1, 1, 7006652},
	{24, ML_CODE_MLT, setCodeOp3S_WZN_DN, setInputOp3_val16_WZN_N_off, verifyResultValueNibble8,
			"MLT off nop3=zop1*nop2", 1, 1, 0},
	{25, ML_CODE_MLT, setCodeOp3S_WZN_DN, setInputOp3_val16_WZN_N_on, verifyResultValueNibble8,
			"MLT on nop3=zop1*nop2", 1, 1, 7006652},
	{26, ML_CODE_MLT, setCodeOp3S_NWZ_DN, setInputOp3_val16_NWZ_N_off, verifyResultValueNibble8,
			"MLT off nop3=nop1*zop2", 1, 1, 0},
	{27, ML_CODE_MLT, setCodeOp3S_NWZ_DN, setInputOp3_val16_NWZ_N_on, verifyResultValueNibble8,
			"MLT on nop3=nop1*zop2", 1, 1, 7006652},
	{28, ML_CODE_MLT, setCodeOp3S_WZWZ_DN, setInputOp3_val16_WZWZ_N_off, verifyResultValueNibble8,
			"MLT off nop3=zop1*zop2", 1, 1, 0},
	{29, ML_CODE_MLT, setCodeOp3S_WZWZ_DN, setInputOp3_val16_WZWZ_N_on, verifyResultValueNibble8,
			"MLT on nop3=zop1*zop2", 1, 1, 7006652},

	{30, ML_CODE_MLTP, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=op1*op2", 0, 2, 0},
	{31, ML_CODE_MLTP, setCodeOp3S_WW_WZ, setInputOp3_val16p_WW_WZ_on, verifyResultValueDWord,
			"MLTP 0->1 zop3=op1*op2", 0, 2, 7006652},
	{32, ML_CODE_MLTP, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=op1*op2", 0, 2, 0},
	{33, ML_CODE_MLTP, setCodeOp3S_W_WWZ, setInputOp3_val16p_W_WWZ_on, verifyResultValueDWord,
			"MLTP 0->1 zop3=op1*op2", 0, 2, 7006652},
	{34, ML_CODE_MLTP, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=K*op2", 0, 2, 0},
	{35, ML_CODE_MLTP, setCodeOp3S_KW_WZ, setInputOp3_val16p_KW_WZ_on, verifyResultValueDWord,
			"MLTP 0->1 zop3=K*op2", 0, 2, 7006652},
	{36, ML_CODE_MLTP, setCodeOp3S_KK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=K*K", 0, 2, 0},
	{37, ML_CODE_MLTP, setCodeOp3S_KK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"MLTP 0->1 zop3=K*K", 0, 2, 7006652},
	{38, ML_CODE_MLTP, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=nop1*op2", 0, 2, 0},
	{39, ML_CODE_MLTP, setCodeOp3S_NW_WZ, setInputOp3_val16p_NW_WZ_on, verifyResultValueDWord,
			"MLTP 0->1 zop3=nop1*op2", 0, 2, 7006652},
	{40, ML_CODE_MLTP, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=op1*nop2", 0, 2, 0},
	{41, ML_CODE_MLTP, setCodeOp3S_WN_WZ, setInputOp3_val16p_WN_WZ_on, verifyResultValueDWord,
			"MLTP 0->1 zop3=op1*nop2", 0, 2, 7006652},
	{42, ML_CODE_MLTP, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=zop1*op2", 2, 2, 0},
	{43, ML_CODE_MLTP, setCodeOp3S_WZW_WZ, setInputOp3_val16p_WZW_WZ_on, verifyResultValueDWord,
			"MLTP 0->1 zop3=zop1*op2", 2, 2, 7006652},
	{44, ML_CODE_MLTP, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=zop1*K", 2, 2, 0},
	{45, ML_CODE_MLTP, setCodeOp3S_WZK_WZ, setInputOp3_val16p_WZK_WZ_on, verifyResultValueDWord,
			"MLTP 0->1 zop3=zop1*K", 2, 2, 7006652},
	{46, ML_CODE_MLTP, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=zop1*nop2", 2, 2, 0},
	{47, ML_CODE_MLTP, setCodeOp3S_WZN_WZ, setInputOp3_val16p_WZN_WZ_on, verifyResultValueDWord,
			"MLTP 0->1 zop3=zop1*nop2", 2, 2, 7006652},
	{48, ML_CODE_MLTP, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_off, verifyResultValueDWord,
			"MLTP 0->0 zop3=nop1*zop2", 2, 2, 0},
	{49, ML_CODE_MLTP, setCodeOp3S_NWZ_WZ, setInputOp3_val16p_NWZ_WZ_on, verifyResultValueDWord,
			"MLTP 0->1 zop3=nop1*zop2", 2, 2, 7006652},
	{50, ML_CODE_MLTP, setCodeOp3S_WZW_DN, setInputOp3_val16_WZW_WZ_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=zop1*op2", 1, 2, 0},
	{51, ML_CODE_MLTP, setCodeOp3S_WZW_DN, setInputOp3_val16p_WZW_WZ_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=zop1*op2", 1, 2, 7006652},
	{52, ML_CODE_MLTP, setCodeOp3S_WZK_DN, setInputOp3_val16_WZK_WZ_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=zop1*K", 1, 2, 0},
	{53, ML_CODE_MLTP, setCodeOp3S_WZK_DN, setInputOp3_val16p_WZK_WZ_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=zop1*K", 1, 2, 7006652},
	{54, ML_CODE_MLTP, setCodeOp3S_WZN_DN, setInputOp3_val16_WZN_N_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=zop1*nop2", 1, 2, 0},
	{55, ML_CODE_MLTP, setCodeOp3S_WZN_DN, setInputOp3_val16p_WZN_N_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=zop1*nop2", 1, 2, 7006652},
	{56, ML_CODE_MLTP, setCodeOp3S_NWZ_DN, setInputOp3_val16_NWZ_N_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=nop1*zop2", 1, 2, 0},
	{57, ML_CODE_MLTP, setCodeOp3S_NWZ_DN, setInputOp3_val16p_NWZ_N_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=nop1*zop2", 1, 2, 7006652},
	{58, ML_CODE_MLTP, setCodeOp3S_WZWZ_DN, setInputOp3_val16_WZWZ_N_off, verifyResultValueNibble8,
			"MLTP 0->0 nop3=zop1*zop2", 1, 2, 0},
	{59, ML_CODE_MLTP, setCodeOp3S_WZWZ_DN, setInputOp3_val16p_WZWZ_N_on, verifyResultValueNibble8,
			"MLTP 0->1 nop3=zop1*zop2", 1, 2, 7006652},

	{60, ML_CODE_DIV, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_off, verifyResultValueDWord,
			"DIV off zop3=op1/op2", 0, 1, 0},
	{61, ML_CODE_DIV, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_on, verifyResultValueDWord,
			"DIV on zop3=op1/op2", 0, 1, 48627716}, //D[+1]=742, D[]=4
	{62, ML_CODE_DIV, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_off, verifyResultValueDWord,
			"DIV off zop3=op1/op2", 0, 1, 0},
	{63, ML_CODE_DIV, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_on, verifyResultValueDWord,
			"DIV on zop3=op1/op2", 0, 1, 48627716},
	{64, ML_CODE_DIV, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_off, verifyResultValueDWord,
			"DIV off zop3=K/op2", 0, 1, 0},
	{65, ML_CODE_DIV, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_on, verifyResultValueDWord,
			"DIV on zop3=K/op2", 0, 1, 48627716},
	{66, ML_CODE_DIV, setCodeOp3S_KK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DIV off zop3=K/K", 0, 1, 0},
	{67, ML_CODE_DIV, setCodeOp3S_KK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"DIV on zop3=K/K", 0, 1, 48627716},
	{68, ML_CODE_DIV, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_off, verifyResultValueDWord,
			"DIV off zop3=nop1/op2", 0, 1, 0},
	{69, ML_CODE_DIV, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_on, verifyResultValueDWord,
			"DIV on zop3=nop1/op2", 0, 1, 48627716},
	{70, ML_CODE_DIV, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_off, verifyResultValueDWord,
			"DIV off zop3=op1/nop2", 0, 1, 0},
	{71, ML_CODE_DIV, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_on, verifyResultValueDWord,
			"DIV on zop3=op1/nop2", 0, 1, 48627716},
	{72, ML_CODE_DIV, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_off, verifyResultValueDWord,
			"DIV off zop3=zop1/op2", 2, 1, 0},
	{73, ML_CODE_DIV, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_on, verifyResultValueDWord,
			"DIV on zop3=zop1/op2", 2, 1, 48627716},
	{74, ML_CODE_DIV, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_off, verifyResultValueDWord,
			"DIV off zop3=zop1/K", 2, 1, 0},
	{75, ML_CODE_DIV, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_on, verifyResultValueDWord,
			"DIV on zop3=zop1/K", 2, 1, 48627716},
	{76, ML_CODE_DIV, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_off, verifyResultValueDWord,
			"DIV off zop3=zop1/nop2", 2, 1, 0},
	{77, ML_CODE_DIV, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_on, verifyResultValueDWord,
			"DIV on zop3=zop1/nop2", 2, 1, 48627716},
	{78, ML_CODE_DIV, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_off, verifyResultValueDWord,
			"DIV off zop3=nop1/zop2", 2, 1, 0},
	{79, ML_CODE_DIV, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_on, verifyResultValueDWord,
			"DIV on zop3=nop1/zop2", 2, 1, 48627716},
	{80, ML_CODE_DIV, setCodeOp3S_WZW_DN, setInputOp3_val16_WZW_WZ_off, verifyResultValueNibble8,
			"DIV off nop3=zop1/op2", 1, 1, 0},
	{81, ML_CODE_DIV, setCodeOp3S_WZW_DN, setInputOp3_val16_WZW_WZ_on, verifyResultValueNibble8,
			"DIV on nop3=zop1/op2", 1, 1, 48627716},
	{82, ML_CODE_DIV, setCodeOp3S_WZK_DN, setInputOp3_val16_WZK_WZ_off, verifyResultValueNibble8,
			"DIV off nop3=zop1/K", 1, 1, 0},
	{83, ML_CODE_DIV, setCodeOp3S_WZK_DN, setInputOp3_val16_WZK_WZ_on, verifyResultValueNibble8,
			"DIV on nop3=zop1/K", 1, 1, 48627716},
	{84, ML_CODE_DIV, setCodeOp3S_WZN_DN, setInputOp3_val16_WZN_N_off, verifyResultValueNibble8,
			"DIV off nop3=zop1/nop2", 1, 1, 0},
	{85, ML_CODE_DIV, setCodeOp3S_WZN_DN, setInputOp3_val16_WZN_N_on, verifyResultValueNibble8,
			"DIV on nop3=zop1/nop2", 1, 1, 48627716},
	{86, ML_CODE_DIV, setCodeOp3S_NWZ_DN, setInputOp3_val16_NWZ_N_off, verifyResultValueNibble8,
			"DIV off nop3=nop1/zop2", 1, 1, 0},
	{87, ML_CODE_DIV, setCodeOp3S_NWZ_DN, setInputOp3_val16_NWZ_N_on, verifyResultValueNibble8,
			"DIV on nop3=nop1/zop2", 1, 1, 48627716},
	{88, ML_CODE_DIV, setCodeOp3S_WZWZ_DN, setInputOp3_val16_WZWZ_N_off, verifyResultValueNibble8,
			"DIV off nop3=zop1/zop2", 1, 1, 0},
	{89, ML_CODE_DIV, setCodeOp3S_WZWZ_DN, setInputOp3_val16_WZWZ_N_on, verifyResultValueNibble8,
			"DIV on nop3=zop1/zop2", 1, 1, 48627716},

	{90, ML_CODE_DIVP, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=op1/op2", 0, 2, 0},
	{91, ML_CODE_DIVP, setCodeOp3S_WW_WZ, setInputOp3_val16p_WW_WZ_on, verifyResultValueDWord,
			"DIVP 0->1 zop3=op1/op2", 0, 2, 48627716},
	{92, ML_CODE_DIVP, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=op1/op2", 0, 2, 0},
	{93, ML_CODE_DIVP, setCodeOp3S_W_WWZ, setInputOp3_val16p_W_WWZ_on, verifyResultValueDWord,
			"DIVP 0->1 zop3=op1/op2", 0, 2, 48627716},
	{94, ML_CODE_DIVP, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=K/op2", 0, 2, 0},
	{95, ML_CODE_DIVP, setCodeOp3S_KW_WZ, setInputOp3_val16p_KW_WZ_on, verifyResultValueDWord,
			"DIVP 0->1 zop3=K/op2", 0, 2, 48627716},
	{96, ML_CODE_DIVP, setCodeOp3S_KK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=K/K", 0, 2, 0},
	{97, ML_CODE_DIVP, setCodeOp3S_KK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"DIVP 0->1 zop3=K/K", 0, 2, 48627716},
	{98, ML_CODE_DIVP, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=nop1/op2", 0, 2, 0},
	{99, ML_CODE_DIVP, setCodeOp3S_NW_WZ, setInputOp3_val16p_NW_WZ_on, verifyResultValueDWord,
			"DIVP 0->1 zop3=nop1/op2", 0, 2, 48627716},
	{100, ML_CODE_DIVP, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=op1/nop2", 0, 2, 0},
	{101, ML_CODE_DIVP, setCodeOp3S_WN_WZ, setInputOp3_val16p_WN_WZ_on, verifyResultValueDWord,
			"DIVP 0->1 zop3=op1/nop2", 0, 2, 48627716},
	{102, ML_CODE_DIVP, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=zop1/op2", 2, 2, 0},
	{103, ML_CODE_DIVP, setCodeOp3S_WZW_WZ, setInputOp3_val16p_WZW_WZ_on, verifyResultValueDWord,
			"DIVP 0->1 zop3=zop1/op2", 2, 2, 48627716},
	{104, ML_CODE_DIVP, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=zop1/K", 2, 2, 0},
	{105, ML_CODE_DIVP, setCodeOp3S_WZK_WZ, setInputOp3_val16p_WZK_WZ_on, verifyResultValueDWord,
			"DIVP 0->1 zop3=zop1/K", 2, 2, 48627716},
	{106, ML_CODE_DIVP, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=zop1/nop2", 2, 2, 0},
	{107, ML_CODE_DIVP, setCodeOp3S_WZN_WZ, setInputOp3_val16p_WZN_WZ_on, verifyResultValueDWord,
			"DIVP 0->1 zop3=zop1/nop2", 2, 2, 48627716},
	{108, ML_CODE_DIVP, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_off, verifyResultValueDWord,
			"DIVP 0->0 zop3=nop1/zop2", 2, 2, 0},
	{109, ML_CODE_DIVP, setCodeOp3S_NWZ_WZ, setInputOp3_val16p_NWZ_WZ_on, verifyResultValueDWord,
			"DIVP 0->1 zop3=nop1/zop2", 2, 2, 48627716},
	{110, ML_CODE_DIVP, setCodeOp3S_WZW_DN, setInputOp3_val16_WZW_WZ_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=zop1/op2", 1, 2, 0},
	{111, ML_CODE_DIVP, setCodeOp3S_WZW_DN, setInputOp3_val16p_WZW_WZ_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=zop1/op2", 1, 2, 48627716},
	{112, ML_CODE_DIVP, setCodeOp3S_WZK_DN, setInputOp3_val16_WZK_WZ_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=zop1/K", 1, 2, 0},
	{113, ML_CODE_DIVP, setCodeOp3S_WZK_DN, setInputOp3_val16p_WZK_WZ_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=zop1/K", 1, 2, 48627716},
	{114, ML_CODE_DIVP, setCodeOp3S_WZN_DN, setInputOp3_val16_WZN_N_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=zop1/nop2", 1, 2, 0},
	{115, ML_CODE_DIVP, setCodeOp3S_WZN_DN, setInputOp3_val16p_WZN_N_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=zop1/nop2", 1, 2, 48627716},
	{116, ML_CODE_DIVP, setCodeOp3S_NWZ_DN, setInputOp3_val16_NWZ_N_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=nop1/zop2", 1, 2, 0},
	{117, ML_CODE_DIVP, setCodeOp3S_NWZ_DN, setInputOp3_val16p_NWZ_N_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=nop1/zop2", 1, 2, 48627716},
	{118, ML_CODE_DIVP, setCodeOp3S_WZWZ_DN, setInputOp3_val16_WZWZ_N_off, verifyResultValueNibble8,
			"DIVP 0->0 nop3=zop1/zop2", 1, 2, 0},
	{119, ML_CODE_DIVP, setCodeOp3S_WZWZ_DN, setInputOp3_val16p_WZWZ_N_on, verifyResultValueNibble8,
			"DIVP 0->1 nop3=zop1/zop2", 1, 2, 48627716},

	{120, ML_CODE_BMLT, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_off, verifyResultValueDWord,
			"BMLT off zop3=op1*op2", 0, 1, 0},
	{121, ML_CODE_BMLT, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_on, verifyResultValueDWord,
			"BMLT on zop3=op1*op2", 0, 1, 0x7006652},
	{122, ML_CODE_BMLT, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_off, verifyResultValueDWord,
			"BMLT off zop3=op1*op2", 0, 1, 0},
	{123, ML_CODE_BMLT, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_on, verifyResultValueDWord,
			"BMLT on zop3=op1*op2", 0, 1, 0x7006652},
	{124, ML_CODE_BMLT, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_off, verifyResultValueDWord,
			"BMLT off zop3=K*op2", 0, 1, 0},
	{125, ML_CODE_BMLT, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_on, verifyResultValueDWord,
			"BMLT on zop3=K*op2", 0, 1, 0x7006652},
	{126, ML_CODE_BMLT, setCodeOp3S_BKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"BMLT off zop3=K*K", 0, 1, 0},
	{127, ML_CODE_BMLT, setCodeOp3S_BKK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"BMLT on zop3=K*K", 0, 1, 0x7006652},
	{128, ML_CODE_BMLT, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_off, verifyResultValueDWord,
			"BMLT off zop3=nop1*op2", 0, 1, 0},
	{129, ML_CODE_BMLT, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_on, verifyResultValueDWord,
			"BMLT on zop3=nop1*op2", 0, 1, 0x7006652},
	{130, ML_CODE_BMLT, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_off, verifyResultValueDWord,
			"BMLT off zop3=op1*nop2", 0, 1, 0},
	{131, ML_CODE_BMLT, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_on, verifyResultValueDWord,
			"BMLT on zop3=op1*nop2", 0, 1, 0x7006652},
	{132, ML_CODE_BMLT, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueDWord,
			"BMLT off zop3=zop1*op2", 2, 1, 0},
	{133, ML_CODE_BMLT, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_on, verifyResultValueDWord,
			"BMLT on zop3=zop1*op2", 2, 1, 0x7006652},
	{134, ML_CODE_BMLT, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueDWord,
			"BMLT off zop3=zop1*K", 2, 1, 0},
	{135, ML_CODE_BMLT, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_on, verifyResultValueDWord,
			"BMLT on zop3=zop1*K", 2, 1, 0x7006652},
	{136, ML_CODE_BMLT, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_off, verifyResultValueDWord,
			"BMLT off zop3=zop1*nop2", 2, 1, 0},
	{137, ML_CODE_BMLT, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_on, verifyResultValueDWord,
			"BMLT on zop3=zop1*nop2", 2, 1, 0x7006652},
	{138, ML_CODE_BMLT, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_off, verifyResultValueDWord,
			"BMLT off zop3=nop1*zop2", 2, 1, 0},
	{139, ML_CODE_BMLT, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_on, verifyResultValueDWord,
			"BMLT on zop3=nop1*zop2", 2, 1, 0x7006652},
	{140, ML_CODE_BMLT, setCodeOp3S_WZW_DN, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueNibble8,
			"BMLT off nop3=zop1*op2", 1, 1, 0},
	{141, ML_CODE_BMLT, setCodeOp3S_WZW_DN, setInputOp3_BCD4_WZW_WZ_on, verifyResultValueNibble8,
			"BMLT on nop3=zop1*op2", 1, 1, 0x7006652},
	{142, ML_CODE_BMLT, setCodeOp3S_WZBK_DN, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueNibble8,
			"BMLT off nop3=zop1*K", 1, 1, 0},
	{143, ML_CODE_BMLT, setCodeOp3S_WZBK_DN, setInputOp3_BCD4_WZK_WZ_on, verifyResultValueNibble8,
			"BMLT on nop3=zop1*K", 1, 1, 0x7006652},
	{144, ML_CODE_BMLT, setCodeOp3S_WZN_DN, setInputOp3_BCD4_WZN_N_off, verifyResultValueNibble8,
			"BMLT off nop3=zop1*nop2", 1, 1, 0},
	{145, ML_CODE_BMLT, setCodeOp3S_WZN_DN, setInputOp3_BCD4_WZN_N_on, verifyResultValueNibble8,
			"BMLT on nop3=zop1*nop2", 1, 1, 0x7006652},
	{146, ML_CODE_BMLT, setCodeOp3S_NWZ_DN, setInputOp3_BCD4_NWZ_N_off, verifyResultValueNibble8,
			"BMLT off nop3=nop1*zop2", 1, 1, 0},
	{147, ML_CODE_BMLT, setCodeOp3S_NWZ_DN, setInputOp3_BCD4_NWZ_N_on, verifyResultValueNibble8,
			"BMLT on nop3=nop1*zop2", 1, 1, 0x7006652},
	{148, ML_CODE_BMLT, setCodeOp3S_WZWZ_DN, setInputOp3_BCD4_WZWZ_N_off, verifyResultValueNibble8,
			"BMLT off nop3=zop1*zop2", 1, 1, 0},
	{149, ML_CODE_BMLT, setCodeOp3S_WZWZ_DN, setInputOp3_BCD4_WZWZ_N_on, verifyResultValueNibble8,
			"BMLT on nop3=zop1*zop2", 1, 1, 0x7006652},

	{150, ML_CODE_BMLTP, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=op1*op2", 0, 2, 0},
	{151, ML_CODE_BMLTP, setCodeOp3S_WW_WZ, setInputOp3_BCD4p_WW_WZ_on, verifyResultValueDWord,
			"BMLTP 0->1 zop3=op1*op2", 0, 2, 0x7006652},
	{152, ML_CODE_BMLTP, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=op1*op2", 0, 2, 0},
	{153, ML_CODE_BMLTP, setCodeOp3S_W_WWZ, setInputOp3_BCD4p_W_WWZ_on, verifyResultValueDWord,
			"BMLTP 0->1 zop3=op1*op2", 0, 2, 0x7006652},
	{154, ML_CODE_BMLTP, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=K*op2", 0, 2, 0},
	{155, ML_CODE_BMLTP, setCodeOp3S_BKW_WZ, setInputOp3_BCD4p_KW_WZ_on, verifyResultValueDWord,
			"BMLTP 0->1 zop3=K*op2", 0, 2, 0x7006652},
	{156, ML_CODE_BMLTP, setCodeOp3S_BKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=K*K", 0, 2, 0},
	{157, ML_CODE_BMLTP, setCodeOp3S_BKK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"BMLTP 0->1 zop3=K*K", 0, 2, 0x7006652},
	{158, ML_CODE_BMLTP, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=nop1*op2", 0, 2, 0},
	{159, ML_CODE_BMLTP, setCodeOp3S_NW_WZ, setInputOp3_BCD4p_NW_WZ_on, verifyResultValueDWord,
			"BMLTP 0->1 zop3=nop1*op2", 0, 2, 0x7006652},
	{160, ML_CODE_BMLTP, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=op1*nop2", 0, 2, 0},
	{161, ML_CODE_BMLTP, setCodeOp3S_WN_WZ, setInputOp3_BCD4p_WN_WZ_on, verifyResultValueDWord,
			"BMLTP 0->1 zop3=op1*nop2", 0, 2, 0x7006652},
	{162, ML_CODE_BMLTP, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=zop1*op2", 2, 2, 0},
	{163, ML_CODE_BMLTP, setCodeOp3S_WZW_WZ, setInputOp3_BCD4p_WZW_WZ_on, verifyResultValueDWord,
			"BMLTP 0->1 zop3=zop1*op2", 2, 2, 0x7006652},
	{164, ML_CODE_BMLTP, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=zop1*K", 2, 2, 0},
	{165, ML_CODE_BMLTP, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4p_WZK_WZ_on, verifyResultValueDWord,
			"BMLTP 0->1 zop3=zop1*K", 2, 2, 0x7006652},
	{166, ML_CODE_BMLTP, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=zop1*nop2", 2, 2, 0},
	{167, ML_CODE_BMLTP, setCodeOp3S_WZN_WZ, setInputOp3_BCD4p_WZN_WZ_on, verifyResultValueDWord,
			"BMLTP 0->1 zop3=zop1*nop2", 2, 2, 0x7006652},
	{168, ML_CODE_BMLTP, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_off, verifyResultValueDWord,
			"BMLTP 0->0 zop3=nop1*zop2", 2, 2, 0},
	{169, ML_CODE_BMLTP, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4p_NWZ_WZ_on, verifyResultValueDWord,
			"BMLTP 0->1 zop3=nop1*zop2", 2, 2, 0x7006652},
	{170, ML_CODE_BMLTP, setCodeOp3S_WZW_DN, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=zop1*op2", 1, 2, 0},
	{171, ML_CODE_BMLTP, setCodeOp3S_WZW_DN, setInputOp3_BCD4p_WZW_WZ_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=zop1*op2", 1, 2, 0x7006652},
	{172, ML_CODE_BMLTP, setCodeOp3S_WZBK_DN, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=zop1*K", 1, 2, 0},
	{173, ML_CODE_BMLTP, setCodeOp3S_WZBK_DN, setInputOp3_BCD4p_WZK_WZ_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=zop1*K", 1, 2, 0x7006652},
	{174, ML_CODE_BMLTP, setCodeOp3S_WZN_DN, setInputOp3_BCD4_WZN_N_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=zop1*nop2", 1, 2, 0},
	{175, ML_CODE_BMLTP, setCodeOp3S_WZN_DN, setInputOp3_BCD4p_WZN_N_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=zop1*nop2", 1, 2, 0x7006652},
	{176, ML_CODE_BMLTP, setCodeOp3S_NWZ_DN, setInputOp3_BCD4_NWZ_N_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=nop1*zop2", 1, 2, 0},
	{177, ML_CODE_BMLTP, setCodeOp3S_NWZ_DN, setInputOp3_BCD4p_NWZ_N_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=nop1*zop2", 1, 2, 0x7006652},
	{178, ML_CODE_BMLTP, setCodeOp3S_WZWZ_DN, setInputOp3_BCD4_WZWZ_N_off, verifyResultValueNibble8,
			"BMLTP 0->0 nop3=zop1*zop2", 1, 2, 0},
	{179, ML_CODE_BMLTP, setCodeOp3S_WZWZ_DN, setInputOp3_BCD4p_WZWZ_N_on, verifyResultValueNibble8,
			"BMLTP 0->1 nop3=zop1*zop2", 1, 2, 0x7006652},

	{180, ML_CODE_BDIV, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_off, verifyResultValueDWord,
			"BDIV off zop3=op1/op2", 0, 1, 0},
	{181, ML_CODE_BDIV, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_on, verifyResultValueDWord,
			"BDIV on zop3=op1/op2", 0, 1, 0x7420004}, //0x7420004, []=0x4, [+1]=0x742
	{182, ML_CODE_BDIV, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_off, verifyResultValueDWord,
			"BDIV off zop3=op1/op2", 0, 1, 0},
	{183, ML_CODE_BDIV, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_on, verifyResultValueDWord,
			"BDIV on zop3=op1/op2", 0, 1, 0x7420004},
	{184, ML_CODE_BDIV, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_off, verifyResultValueDWord,
			"BDIV off zop3=K/op2", 0, 1, 0},
	{185, ML_CODE_BDIV, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_on, verifyResultValueDWord,
			"BDIV on zop3=K/op2", 0, 1, 0x7420004},
	{186, ML_CODE_BDIV, setCodeOp3S_BKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"BDIV off zop3=K/K", 0, 1, 0},
	{187, ML_CODE_BDIV, setCodeOp3S_BKK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"BDIV on zop3=K/K", 0, 1, 0x7420004},
	{188, ML_CODE_BDIV, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_off, verifyResultValueDWord,
			"BDIV off zop3=nop1/op2", 0, 1, 0},
	{189, ML_CODE_BDIV, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_on, verifyResultValueDWord,
			"BDIV on zop3=nop1/op2", 0, 1, 0x7420004},
	{190, ML_CODE_BDIV, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_off, verifyResultValueDWord,
			"BDIV off zop3=op1/nop2", 0, 1, 0},
	{191, ML_CODE_BDIV, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_on, verifyResultValueDWord,
			"BDIV on zop3=op1/nop2", 0, 1, 0x7420004},
	{192, ML_CODE_BDIV, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueDWord,
			"BDIV off zop3=zop1/op2", 2, 1, 0},
	{193, ML_CODE_BDIV, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_on, verifyResultValueDWord,
			"BDIV on zop3=zop1/op2", 2, 1, 0x7420004},
	{194, ML_CODE_BDIV, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueDWord,
			"BDIV off zop3=zop1/K", 2, 1, 0},
	{195, ML_CODE_BDIV, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_on, verifyResultValueDWord,
			"BDIV on zop3=zop1/K", 2, 1, 0x7420004},
	{196, ML_CODE_BDIV, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_off, verifyResultValueDWord,
			"BDIV off zop3=zop1/nop2", 2, 1, 0},
	{197, ML_CODE_BDIV, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_on, verifyResultValueDWord,
			"BDIV on zop3=zop1/nop2", 2, 1, 0x7420004},
	{198, ML_CODE_BDIV, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_off, verifyResultValueDWord,
			"BDIV off zop3=nop1/zop2", 2, 1, 0},
	{199, ML_CODE_BDIV, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_on, verifyResultValueDWord,
			"BDIV on zop3=nop1/zop2", 2, 1, 0x7420004},
	{200, ML_CODE_BDIV, setCodeOp3S_WZW_DN, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueNibble8,
			"BDIV off nop3=zop1/op2", 1, 1, 0},
	{201, ML_CODE_BDIV, setCodeOp3S_WZW_DN, setInputOp3_BCD4_WZW_WZ_on, verifyResultValueNibble8,
			"BDIV on nop3=zop1/op2", 1, 1, 0x7420004},
	{202, ML_CODE_BDIV, setCodeOp3S_WZBK_DN, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueNibble8,
			"BDIV off nop3=zop1/K", 1, 1, 0},
	{203, ML_CODE_BDIV, setCodeOp3S_WZBK_DN, setInputOp3_BCD4_WZK_WZ_on, verifyResultValueNibble8,
			"BDIV on nop3=zop1/K", 1, 1, 0x7420004},
	{204, ML_CODE_BDIV, setCodeOp3S_WZN_DN, setInputOp3_BCD4_WZN_N_off, verifyResultValueNibble8,
			"BDIV off nop3=zop1/nop2", 1, 1, 0},
	{205, ML_CODE_BDIV, setCodeOp3S_WZN_DN, setInputOp3_BCD4_WZN_N_on, verifyResultValueNibble8,
			"BDIV on nop3=zop1/nop2", 1, 1, 0x7420004},
	{206, ML_CODE_BDIV, setCodeOp3S_NWZ_DN, setInputOp3_BCD4_NWZ_N_off, verifyResultValueNibble8,
			"BDIV off nop3=nop1/zop2", 1, 1, 0},
	{207, ML_CODE_BDIV, setCodeOp3S_NWZ_DN, setInputOp3_BCD4_NWZ_N_on, verifyResultValueNibble8,
			"BDIV on nop3=nop1/zop2", 1, 1, 0x7420004},
	{208, ML_CODE_BDIV, setCodeOp3S_WZWZ_DN, setInputOp3_BCD4_WZWZ_N_off, verifyResultValueNibble8,
			"BDIV off nop3=zop1/zop2", 1, 1, 0},
	{209, ML_CODE_BDIV, setCodeOp3S_WZWZ_DN, setInputOp3_BCD4_WZWZ_N_on, verifyResultValueNibble8,
			"BDIV on nop3=zop1*zop2", 1, 1, 0x7420004},

	{210, ML_CODE_BDIVP, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=op1/op2", 0, 2, 0},
	{211, ML_CODE_BDIVP, setCodeOp3S_WW_WZ, setInputOp3_BCD4p_WW_WZ_on, verifyResultValueDWord,
			"BDIVP 0->1 zop3=op1/op2", 0, 2, 0x7420004},
	{212, ML_CODE_BDIVP, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=op1/op2", 0, 2, 0},
	{213, ML_CODE_BDIVP, setCodeOp3S_W_WWZ, setInputOp3_BCD4p_W_WWZ_on, verifyResultValueDWord,
			"BDIVP 0->1 zop3=op1/op2", 0, 2, 0x7420004},
	{214, ML_CODE_BDIVP, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=K/op2", 0, 2, 0},
	{215, ML_CODE_BDIVP, setCodeOp3S_BKW_WZ, setInputOp3_BCD4p_KW_WZ_on, verifyResultValueDWord,
			"BDIVP 0->1 zop3=K/op2", 0, 2, 0x7420004},
	{216, ML_CODE_BDIVP, setCodeOp3S_BKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=K/K", 0, 2, 0},
	{217, ML_CODE_BDIVP, setCodeOp3S_BKK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"BDIVP 0->1 zop3=K/K", 0, 2, 0x7420004},
	{218, ML_CODE_BDIVP, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=nop1/op2", 0, 2, 0},
	{219, ML_CODE_BDIVP, setCodeOp3S_NW_WZ, setInputOp3_BCD4p_NW_WZ_on, verifyResultValueDWord,
			"BDIVP 0->1 zop3=nop1/op2", 0, 2, 0x7420004},
	{220, ML_CODE_BDIVP, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=op1/nop2", 0, 2, 0},
	{221, ML_CODE_BDIVP, setCodeOp3S_WN_WZ, setInputOp3_BCD4p_WN_WZ_on, verifyResultValueDWord,
			"BDIVP 0->1 zop3=op1/nop2", 0, 2, 0x7420004},
	{222, ML_CODE_BDIVP, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=zop1/op2", 2, 2, 0},
	{223, ML_CODE_BDIVP, setCodeOp3S_WZW_WZ, setInputOp3_BCD4p_WZW_WZ_on, verifyResultValueDWord,
			"BDIVP 0->1 zop3=zop1/op2", 2, 2, 0x7420004},
	{224, ML_CODE_BDIVP, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=zop1/K", 2, 2, 0},
	{225, ML_CODE_BDIVP, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4p_WZK_WZ_on, verifyResultValueDWord,
			"BDIVP 0->1 zop3=zop1/K", 2, 2, 0x7420004},
	{226, ML_CODE_BDIVP, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=zop1/nop2", 2, 2, 0},
	{227, ML_CODE_BDIVP, setCodeOp3S_WZN_WZ, setInputOp3_BCD4p_WZN_WZ_on, verifyResultValueDWord,
			"BDIVP 0->1 zop3=zop1/nop2", 2, 2, 0x7420004},
	{228, ML_CODE_BDIVP, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_off, verifyResultValueDWord,
			"BDIVP 0->0 zop3=nop1/zop2", 2, 2, 0},
	{229, ML_CODE_BDIVP, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4p_NWZ_WZ_on, verifyResultValueDWord,
			"BDIVP 0->1 zop3=nop1/zop2", 2, 2, 0x7420004},
	{230, ML_CODE_BDIVP, setCodeOp3S_WZW_DN, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueNibble8,
			"BDIVP 0->0 nop3=zop1/op2", 1, 2, 0},
	{231, ML_CODE_BDIVP, setCodeOp3S_WZW_DN, setInputOp3_BCD4p_WZW_WZ_on, verifyResultValueNibble8,
			"BDIVP 0->1 nop3=zop1/op2", 1, 2, 0x7420004},
	{232, ML_CODE_BDIVP, setCodeOp3S_WZBK_DN, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueNibble8,
			"BDIVP 0->0 nop3=zop1/K", 1, 2, 0},
	{233, ML_CODE_BDIVP, setCodeOp3S_WZBK_DN, setInputOp3_BCD4p_WZK_WZ_on, verifyResultValueNibble8,
			"BDIVP 0->1 nop3=zop1/K", 1, 2, 0x7420004},
	{234, ML_CODE_BDIVP, setCodeOp3S_WZN_DN, setInputOp3_BCD4_WZN_N_off, verifyResultValueNibble8,
			"BDIVP 0->0 nop3=zop1/nop2", 1, 2, 0},
	{235, ML_CODE_BDIVP, setCodeOp3S_WZN_DN, setInputOp3_BCD4p_WZN_N_on, verifyResultValueNibble8,
			"BDIVP 0->1 nop3=zop1/nop2", 1, 2, 0x7420004},
	{236, ML_CODE_BDIVP, setCodeOp3S_NWZ_DN, setInputOp3_BCD4_NWZ_N_off, verifyResultValueNibble8,
			"BDIVP 0->0 nop3=nop1/zop2", 1, 2, 0},
	{237, ML_CODE_BDIVP, setCodeOp3S_NWZ_DN, setInputOp3_BCD4p_NWZ_N_on, verifyResultValueNibble8,
			"BDIVP 0->1 nop3=nop1/zop2", 1, 2, 0x7420004},
	{238, ML_CODE_BDIVP, setCodeOp3S_WZWZ_DN, setInputOp3_BCD4_WZWZ_N_off, verifyResultValueNibble8,
			"BDIVP 0->0 nop3=zop1/zop2", 1, 2, 0},
	{239, ML_CODE_BDIVP, setCodeOp3S_WZWZ_DN, setInputOp3_BCD4p_WZWZ_N_on, verifyResultValueNibble8,
			"BDIVP 0->1 nop3=zop1/zop2", 1, 2, 0x7420004},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0, 0 }
};


int total_basic_compute_word_mul_idx_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_word_mul_idx_test_number; i++)
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


int setCodeOp3S_WZW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(in_reg, 160);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandNibble(4, out_reg, 160);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_NWZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, 160, idx_val)) return 0;
	if(isRangeOver(out_reg, in_pos, 0)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, out_reg, in_pos); addMLOperandZIndex(in_reg, 160, idx_pos);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZWZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(in_reg, 160, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandZIndex(in_reg, 160, idx_pos);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZBK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_X, 0x1234);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12287,8191}}; //16bit

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_arithmetic_mul_index(int tno, uint16 dummy)
{
	int i=1, inx=7, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos, res_word;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

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

						rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos, \
								testidx[inx].pos, testidx[inx].val);
						if(rc2 == 0) continue;

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
							if(testCase[tno].z_type==1) //op1 is index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
								if(rc == 1)
								{
									test_getNibble(&res_word, out, out_pos, 8);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d Z[%d]=%d\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
										reg[in], in_pos, reg[out], out_pos, res_word, testCase[tno].expected, testidx[inx].pos, testidx[inx].val);
								}
							}
							else // op2 is index or both are index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos+testidx[inx].val, testCase[tno].expected);
								if(rc == 1)
								{
									test_getDWord(&res_word, out, out_pos+testidx[inx].val);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d Z[%d]=%d\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
										reg[in], in_pos, reg[out], out_pos, res_word, testCase[tno].expected, testidx[inx].pos, testidx[inx].val);
								}
							}
						}
					}
				}
			}
		}
	}
}

void testBasicArithmeticMulIndexCommand(void)
{
	int i, index=185;
	int start, end;
	char log[] = "err_arith_word_mul_idx.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic word mul index LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=32;index<56;index++)
	test_basic_arithmetic_mul_index(index, 0);
	//for(i=0; i<230; i++)
	//	printf("testcase %d cmd=%s \n", i, PLC_OPERATOR_DICTIONARY_findOperator(testCase[i].ml_code)->strName);
#else
	total_basic_compute_word_mul_idx_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_MLT); //ML_CODE_MLT
	end = getTestCaseNumberEnd(ML_CODE_BDIVP); //ML_CODE_BDIVP

	DBG_LOGPRINT("testBasicArithmeticMulIndexCommand: %d to %d total %d\n", start, end, total_basic_compute_word_mul_idx_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_mul_index(index, 0);
	}
#endif
	fclose(flog);
}

#endif
