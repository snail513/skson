/*
 * test_basic_conversion_word_index.c
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

extern int verifyResultValueWord(int tcase, uint8 dest_reg, uint16 pos, short expected);
extern int verifyResultValueNibble4(int tcase, uint8 dest_reg, uint16 pos, short expected);

int setCodeOp2_W_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_K101_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_K9999_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_N_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_WZ_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_WZ_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_WZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_BK101_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_BK9999_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_maxE_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_minE_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_upE_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_maxDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_minDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_DN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_K1234_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_K0x06BB_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

void setInputOp2_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_maxN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_maxN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp2_BCD4_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_maxN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_maxN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp2_float_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_float_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_floatp_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_float_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_floatp_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_float_dn_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_floatp_dn_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_float_up_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_floatp_up_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_float_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_float_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_floatp_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_float_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_floatp_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_float_dn_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_floatp_dn_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_float_up_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_floatp_up_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp2_val32_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_maxDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_maxDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_maxDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_maxDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_maxDWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_maxDWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp2_val16_BGW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_BGW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_BGW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_BGN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_BGN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_BGN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_BGWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_BGWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_BGWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_GBW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_GBW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_GBW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_GBN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_GBN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_GBN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_GBWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_GBWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_GBWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

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
	int (*verifyResult_fn)(int, uint8, uint16, short);
	char str[30];
	//int count;
	int z_type; // 0 : op2 is index, 1: op1 is index
	int run_step;
	int expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_BTOBCD, setCodeOp2_W_WZ, setInputOp2_val16_W_off, verifyResultValueWord,
			"BTOBCD off 101", 0, 1, 0},
	{1, ML_CODE_BTOBCD, setCodeOp2_W_WZ, setInputOp2_val16_W_on, verifyResultValueWord,
			"BTOBCD on 101", 0, 1, 0x101},
	{2, ML_CODE_BTOBCD, setCodeOp2_W_WZ, setInputOp2_val16_maxW_on, verifyResultValueWord,
			"BTOBCD on 9999", 0, 1, 0x9999},
	{3, ML_CODE_BTOBCD, setCodeOp2_K101_WZ, setInputOp2_none_off, verifyResultValueWord,
			"BTOBCD off K101", 0, 1, 0},
	{4, ML_CODE_BTOBCD, setCodeOp2_K101_WZ, setInputOp2_none_on, verifyResultValueWord,
			"BTOBCD on K101", 0, 1, 0x101},
	{5, ML_CODE_BTOBCD, setCodeOp2_K9999_WZ, setInputOp2_none_on, verifyResultValueWord,
			"BTOBCD on K9999", 0, 1, 0x9999},
	{6, ML_CODE_BTOBCD, setCodeOp2_N_WZ, setInputOp2_val16_N_off, verifyResultValueWord,
			"BTOBCD off N101", 0, 1, 0},
	{7, ML_CODE_BTOBCD, setCodeOp2_N_WZ, setInputOp2_val16_N_on, verifyResultValueWord,
			"BTOBCD on N101", 0, 1, 0x101},
	{8, ML_CODE_BTOBCD, setCodeOp2_N_WZ, setInputOp2_val16_maxN_on, verifyResultValueWord,
			"BTOBCD on N9999", 0, 1, 0x9999},
	{9, ML_CODE_BTOBCD, setCodeOp2_WZ_W, setInputOp2_val16_WZ_off, verifyResultValueWord,
			"BTOBCD off WZ101", 1, 1, 0},
	{10, ML_CODE_BTOBCD, setCodeOp2_WZ_W, setInputOp2_val16_WZ_on, verifyResultValueWord,
			"BTOBCD on WZ101", 1, 1, 0x101},
	{11, ML_CODE_BTOBCD, setCodeOp2_WZ_W, setInputOp2_val16_maxWZ_on, verifyResultValueWord,
			"BTOBCD on WZ9999", 1, 1, 0x9999},
	{12, ML_CODE_BTOBCD, setCodeOp2_WZ_N, setInputOp2_val16_WZ_off, verifyResultValueNibble4,
			"BTOBCD off WZ101", 3, 1, 0},
	{13, ML_CODE_BTOBCD, setCodeOp2_WZ_N, setInputOp2_val16_WZ_on, verifyResultValueNibble4,
			"BTOBCD on WZ101", 3, 1, 0x101},
	{14, ML_CODE_BTOBCD, setCodeOp2_WZ_N, setInputOp2_val16_maxWZ_on, verifyResultValueNibble4,
			"BTOBCD on WZ9999", 3, 1, 0x9999},
	{15, ML_CODE_BTOBCD, setCodeOp2_WZ_WZ, setInputOp2_val16_WZ_off, verifyResultValueWord,
			"BTOBCD off WZ101", 2, 1, 0},
	{16, ML_CODE_BTOBCD, setCodeOp2_WZ_WZ, setInputOp2_val16_WZ_on, verifyResultValueWord,
			"BTOBCD on WZ101", 2, 1, 0x101},
	{17, ML_CODE_BTOBCD, setCodeOp2_WZ_WZ, setInputOp2_val16_maxWZ_on, verifyResultValueWord,
			"BTOBCD on WZ9999", 2, 1, 0x9999},

	{18, ML_CODE_BTOBCDP, setCodeOp2_W_WZ, setInputOp2_val16_W_off, verifyResultValueWord,
			"BTOBCDP 0->0 101", 0, 2, 0},
	{19, ML_CODE_BTOBCDP, setCodeOp2_W_WZ, setInputOp2_val16p_W_on, verifyResultValueWord,
			"BTOBCDP 0->1 101", 0, 2, 0x101},
	{20, ML_CODE_BTOBCDP, setCodeOp2_W_WZ, setInputOp2_val16p_maxW_on, verifyResultValueWord,
			"BTOBCDP 0->1 9999", 0, 2, 0x9999},
	{21, ML_CODE_BTOBCDP, setCodeOp2_K101_WZ, setInputOp2_none_on, verifyResultValueWord,
			"BTOBCDP 0->0 K101", 0, 2, 0},
	{22, ML_CODE_BTOBCDP, setCodeOp2_K101_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"BTOBCDP 0->1 K101", 0, 2, 0x101},
	{23, ML_CODE_BTOBCDP, setCodeOp2_K9999_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"BTOBCDP 0->1 K9999", 0, 2, 0x9999},
	{24, ML_CODE_BTOBCDP, setCodeOp2_N_WZ, setInputOp2_val16_N_off, verifyResultValueWord,
			"BTOBCDP 0->0 N101", 0, 2, 0},
	{25, ML_CODE_BTOBCDP, setCodeOp2_N_WZ, setInputOp2_val16p_N_on, verifyResultValueWord,
			"BTOBCDP 0->1 N101", 0, 2, 0x101},
	{26, ML_CODE_BTOBCDP, setCodeOp2_N_WZ, setInputOp2_val16p_maxN_on, verifyResultValueWord,
			"BTOBCDP 0->1 N9999", 0, 2, 0x9999},
	{27, ML_CODE_BTOBCDP, setCodeOp2_WZ_W, setInputOp2_val16_WZ_off, verifyResultValueWord,
			"BTOBCDP 0->0 WZ101", 1, 2, 0},
	{28, ML_CODE_BTOBCDP, setCodeOp2_WZ_W, setInputOp2_val16p_WZ_on, verifyResultValueWord,
			"BTOBCDP 0->1 WZ101", 1, 2, 0x101},
	{29, ML_CODE_BTOBCDP, setCodeOp2_WZ_W, setInputOp2_val16p_maxWZ_on, verifyResultValueWord,
			"BTOBCDP 0->1 WZ9999", 1, 2, 0x9999},
	{30, ML_CODE_BTOBCDP, setCodeOp2_WZ_N, setInputOp2_val16_WZ_off, verifyResultValueNibble4,
			"BTOBCDP 0->0 WZ101", 3, 2, 0},
	{31, ML_CODE_BTOBCDP, setCodeOp2_WZ_N, setInputOp2_val16p_WZ_on, verifyResultValueNibble4,
			"BTOBCDP 0->1 WZ101", 3, 2, 0x101},
	{32, ML_CODE_BTOBCDP, setCodeOp2_WZ_N, setInputOp2_val16p_maxWZ_on, verifyResultValueNibble4,
			"BTOBCDP 0->1 WZ9999", 3, 2, 0x9999},
	{33, ML_CODE_BTOBCDP, setCodeOp2_WZ_WZ, setInputOp2_val16_WZ_off, verifyResultValueWord,
			"BTOBCDP 0->0 WZ101", 2, 2, 0},
	{34, ML_CODE_BTOBCDP, setCodeOp2_WZ_WZ, setInputOp2_val16p_WZ_on, verifyResultValueWord,
			"BTOBCDP 0->1 WZ101", 2, 2, 0x101},
	{35, ML_CODE_BTOBCDP, setCodeOp2_WZ_WZ, setInputOp2_val16p_maxWZ_on, verifyResultValueWord,
			"BTOBCDP 0->1 WZ9999", 2, 2, 0x9999},

	{36, ML_CODE_BCDTOB, setCodeOp2_W_WZ, setInputOp2_BCD4_W_off, verifyResultValueWord,
			"BCDTOB off 0x101", 0, 1, 0},
	{37, ML_CODE_BCDTOB, setCodeOp2_W_WZ, setInputOp2_BCD4_W_on, verifyResultValueWord,
			"BCDTOB on 0x101", 0, 1, 101},
	{38, ML_CODE_BCDTOB, setCodeOp2_W_WZ, setInputOp2_BCD4_maxW_on, verifyResultValueWord,
			"BCDTOB on 0x9999", 0, 1, 9999},
	{39, ML_CODE_BCDTOB, setCodeOp2_BK101_WZ, setInputOp2_none_off, verifyResultValueWord,
			"BCDTOB off K0x101", 0, 1, 0},
	{40, ML_CODE_BCDTOB, setCodeOp2_BK101_WZ, setInputOp2_none_on, verifyResultValueWord,
			"BCDTOB on K0x101", 0, 1, 101},
	{41, ML_CODE_BCDTOB, setCodeOp2_BK9999_WZ, setInputOp2_none_on, verifyResultValueWord,
			"BCDTOB on K0x9999", 0, 1, 9999},
	{42, ML_CODE_BCDTOB, setCodeOp2_N_WZ, setInputOp2_BCD4_N_off, verifyResultValueWord,
			"BCDTOB off N0x101", 0, 1, 0},
	{43, ML_CODE_BCDTOB, setCodeOp2_N_WZ, setInputOp2_BCD4_N_on, verifyResultValueWord,
			"BCDTOB on N0x101", 0, 1, 101},
	{44, ML_CODE_BCDTOB, setCodeOp2_N_WZ, setInputOp2_BCD4_maxN_on, verifyResultValueWord,
			"BCDTOB on N0x9999", 0, 1, 9999},
	{45, ML_CODE_BCDTOB, setCodeOp2_WZ_W, setInputOp2_BCD4_WZ_off, verifyResultValueWord,
			"BCDTOB off WZ0x101", 1, 1, 0},
	{46, ML_CODE_BCDTOB, setCodeOp2_WZ_W, setInputOp2_BCD4_WZ_on, verifyResultValueWord,
			"BCDTOB on WZ0x101", 1, 1, 101},
	{47, ML_CODE_BCDTOB, setCodeOp2_WZ_W, setInputOp2_BCD4_maxWZ_on, verifyResultValueWord,
			"BCDTOB on WZ0x9999", 1, 1, 9999},
	{48, ML_CODE_BCDTOB, setCodeOp2_WZ_N, setInputOp2_BCD4_WZ_off, verifyResultValueNibble4,
			"BCDTOB off WZ0x101", 3, 1, 0},
	{49, ML_CODE_BCDTOB, setCodeOp2_WZ_N, setInputOp2_BCD4_WZ_on, verifyResultValueNibble4,
			"BCDTOB on WZ0x101", 3, 1, 101},
	{50, ML_CODE_BCDTOB, setCodeOp2_WZ_N, setInputOp2_BCD4_maxWZ_on, verifyResultValueNibble4,
			"BCDTOB on WZ0x9999", 3, 1, 9999},
	{51, ML_CODE_BCDTOB, setCodeOp2_WZ_WZ, setInputOp2_BCD4_WZ_off, verifyResultValueWord,
			"BCDTOB off WZ0x101", 2, 1, 0},
	{52, ML_CODE_BCDTOB, setCodeOp2_WZ_WZ, setInputOp2_BCD4_WZ_on, verifyResultValueWord,
			"BCDTOB on WZ0x101", 2, 1, 101},
	{53, ML_CODE_BCDTOB, setCodeOp2_WZ_WZ, setInputOp2_BCD4_maxWZ_on, verifyResultValueWord,
			"BCDTOB on WZ0x9999", 2, 1, 9999},

	{54, ML_CODE_BCDTOBP, setCodeOp2_W_WZ, setInputOp2_BCD4_W_off, verifyResultValueWord,
			"BCDTOBP 0->0 0x101", 0, 2, 0},
	{55, ML_CODE_BCDTOBP, setCodeOp2_W_WZ, setInputOp2_BCD4p_W_on, verifyResultValueWord,
			"BCDTOBP 0->1 0x101", 0, 2, 101},
	{56, ML_CODE_BCDTOBP, setCodeOp2_W_WZ, setInputOp2_BCD4p_maxW_on, verifyResultValueWord,
			"BCDTOBP 0->1 0x9999", 0, 2, 9999},
	{57, ML_CODE_BCDTOBP, setCodeOp2_BK101_WZ, setInputOp2_none_off, verifyResultValueWord,
			"BCDTOBP 0->0 K0x101", 0, 2, 0},
	{58, ML_CODE_BCDTOBP, setCodeOp2_BK101_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"BCDTOBP 0->1 K0x101", 0, 2, 101},
	{59, ML_CODE_BCDTOBP, setCodeOp2_BK9999_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"BCDTOBP 0->1 K0x9999", 0, 2, 9999},
	{60, ML_CODE_BCDTOBP, setCodeOp2_N_WZ, setInputOp2_BCD4_N_off, verifyResultValueWord,
			"BCDTOBP 0->0 N0x101", 0, 2, 0},
	{61, ML_CODE_BCDTOBP, setCodeOp2_N_WZ, setInputOp2_BCD4p_N_on, verifyResultValueWord,
			"BCDTOBP 0->1 N0x101", 0, 2, 101},
	{62, ML_CODE_BCDTOBP, setCodeOp2_N_WZ, setInputOp2_BCD4p_maxN_on, verifyResultValueWord,
			"BCDTOBP 0->1 N0x9999", 0, 2, 9999},
	{63, ML_CODE_BCDTOBP, setCodeOp2_WZ_W, setInputOp2_BCD4_WZ_off, verifyResultValueWord,
			"BCDTOBP 0->0 WZ0x101", 1, 2, 0},
	{64, ML_CODE_BCDTOBP, setCodeOp2_WZ_W, setInputOp2_BCD4p_WZ_on, verifyResultValueWord,
			"BCDTOBP 0->1 WZ0x101", 1, 2, 101},
	{65, ML_CODE_BCDTOBP, setCodeOp2_WZ_W, setInputOp2_BCD4p_maxWZ_on, verifyResultValueWord,
			"BCDTOBP 0->1 WZ0x9999", 1, 2, 9999},
	{66, ML_CODE_BCDTOBP, setCodeOp2_WZ_N, setInputOp2_BCD4_WZ_off, verifyResultValueNibble4,
			"BCDTOBP 0->0 WZ0x101", 3, 2, 0},
	{67, ML_CODE_BCDTOBP, setCodeOp2_WZ_N, setInputOp2_BCD4p_WZ_on, verifyResultValueNibble4,
			"BCDTOBP 0->1 WZ0x101", 3, 2, 101},
	{68, ML_CODE_BCDTOBP, setCodeOp2_WZ_N, setInputOp2_BCD4p_maxWZ_on, verifyResultValueNibble4,
			"BCDTOBP 0->1 WZ0x9999", 3, 2, 9999},
	{69, ML_CODE_BCDTOBP, setCodeOp2_WZ_WZ, setInputOp2_BCD4_WZ_off, verifyResultValueWord,
			"BCDTOBP 0->0 WZ0x101", 2, 2, 0},
	{70, ML_CODE_BCDTOBP, setCodeOp2_WZ_WZ, setInputOp2_BCD4p_WZ_on, verifyResultValueWord,
			"BCDTOBP 0->1 WZ0x101", 2, 2, 101},
	{71, ML_CODE_BCDTOBP, setCodeOp2_WZ_WZ, setInputOp2_BCD4p_maxWZ_on, verifyResultValueWord,
			"BCDTOBP 0->1 WZ0x9999", 2, 2, 9999},

	{72, ML_CODE_FTOB, setCodeOp2_W_WZ, setInputOp2_float_W_off, verifyResultValueWord,
			"FTOB off 257.0", 0, 1, 0},
	{73, ML_CODE_FTOB, setCodeOp2_W_WZ, setInputOp2_float_W_on, verifyResultValueWord,
			"FTOB on 257.0", 0, 1, 257},
	{74, ML_CODE_FTOB, setCodeOp2_W_WZ, setInputOp2_float_maxW_on, verifyResultValueWord,
			"FTOB on 32767.0", 0, 1, 32767},
	{75, ML_CODE_FTOB, setCodeOp2_W_WZ, setInputOp2_float_dn_W_on, verifyResultValueWord,
			"FTOB on 101.4", 0, 1, 101},
	{76, ML_CODE_FTOB, setCodeOp2_W_WZ, setInputOp2_float_up_W_on, verifyResultValueWord,
			"FTOB on 101.5", 0, 1, 102},
	{77, ML_CODE_FTOB, setCodeOp2_maxE_WZ, setInputOp2_none_off, verifyResultValueWord,
			"FTOB off K32767.0", 0, 1, 0},
	{78, ML_CODE_FTOB, setCodeOp2_maxE_WZ, setInputOp2_none_on, verifyResultValueWord,
			"FTOB on K32767.0", 0, 1, 32767},
	{79, ML_CODE_FTOB, setCodeOp2_minE_WZ, setInputOp2_none_on, verifyResultValueWord,
			"FTOB on K-32768.0", 0, 1, -32768},
	{80, ML_CODE_FTOB, setCodeOp2_upE_WZ, setInputOp2_none_on, verifyResultValueWord,
			"FTOB on K101.5", 0, 1, 102},
	{81, ML_CODE_FTOB, setCodeOp2_WZ_W, setInputOp2_float_WZ_off, verifyResultValueWord,
			"FTOB off WZ257.0", 1, 1, 0},
	{82, ML_CODE_FTOB, setCodeOp2_WZ_W, setInputOp2_float_WZ_on, verifyResultValueWord,
			"FTOB on WZ257.0", 1, 1, 257},
	{83, ML_CODE_FTOB, setCodeOp2_WZ_W, setInputOp2_float_maxWZ_on, verifyResultValueWord,
			"FTOB on WZ32767.0", 1, 1, 32767},
	{84, ML_CODE_FTOB, setCodeOp2_WZ_W, setInputOp2_float_dn_WZ_on, verifyResultValueWord,
			"FTOB on WZ101.4", 1, 1, 101},
	{85, ML_CODE_FTOB, setCodeOp2_WZ_W, setInputOp2_float_up_WZ_on, verifyResultValueWord,
			"FTOB on WZ101.5", 1, 1, 102},
	{86, ML_CODE_FTOB, setCodeOp2_WZ_N, setInputOp2_float_WZ_off, verifyResultValueNibble4,
			"FTOB off WZ257.0", 3, 1, 0},
	{87, ML_CODE_FTOB, setCodeOp2_WZ_N, setInputOp2_float_WZ_on, verifyResultValueNibble4,
			"FTOB on WZ257.0", 3, 1, 257},
	{88, ML_CODE_FTOB, setCodeOp2_WZ_N, setInputOp2_float_maxWZ_on, verifyResultValueNibble4,
			"FTOB on WZ32767.0", 3, 1, 32767},
	{89, ML_CODE_FTOB, setCodeOp2_WZ_N, setInputOp2_float_dn_WZ_on, verifyResultValueNibble4,
			"FTOB on WZ101.4", 3, 1, 101},
	{90, ML_CODE_FTOB, setCodeOp2_WZ_N, setInputOp2_float_up_WZ_on, verifyResultValueNibble4,
			"FTOB on WZ101.5", 3, 1, 102},
	{91, ML_CODE_FTOB, setCodeOp2_WZ_WZ, setInputOp2_float_WZ_off, verifyResultValueWord,
			"FTOB off WZ257.0", 2, 1, 0},
	{92, ML_CODE_FTOB, setCodeOp2_WZ_WZ, setInputOp2_float_WZ_on, verifyResultValueWord,
			"FTOB on WZ257.0", 2, 1, 257},
	{93, ML_CODE_FTOB, setCodeOp2_WZ_WZ, setInputOp2_float_maxWZ_on, verifyResultValueWord,
			"FTOB on WZ32767.0", 2, 1, 32767},
	{94, ML_CODE_FTOB, setCodeOp2_WZ_WZ, setInputOp2_float_dn_WZ_on, verifyResultValueWord,
			"FTOB on WZ101.4", 2, 1, 101},
	{95, ML_CODE_FTOB, setCodeOp2_WZ_WZ, setInputOp2_float_up_WZ_on, verifyResultValueWord,
			"FTOB on WZ101.5", 2, 1, 102},

	{96, ML_CODE_FTOBP, setCodeOp2_W_WZ, setInputOp2_float_W_off, verifyResultValueWord,
			"FTOBP 0->0 257.0", 0, 2, 0},
	{97, ML_CODE_FTOBP, setCodeOp2_W_WZ, setInputOp2_floatp_W_on, verifyResultValueWord,
			"FTOBP 0->1 257.0", 0, 2, 257},
	{98, ML_CODE_FTOBP, setCodeOp2_W_WZ, setInputOp2_floatp_maxW_on, verifyResultValueWord,
			"FTOBP 0->1 32767.0", 0, 2, 32767},
	{99, ML_CODE_FTOBP, setCodeOp2_W_WZ, setInputOp2_floatp_dn_W_on, verifyResultValueWord,
			"FTOBP 0->1 101.4", 0, 2, 101},
	{100, ML_CODE_FTOBP, setCodeOp2_W_WZ, setInputOp2_floatp_up_W_on, verifyResultValueWord,
			"FTOBP 0->1 101.5", 0, 2, 102},
	{101, ML_CODE_FTOBP, setCodeOp2_maxE_WZ, setInputOp2_none_off, verifyResultValueWord,
			"FTOBP 0->0 K32767.0", 0, 2, 0},
	{102, ML_CODE_FTOBP, setCodeOp2_maxE_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"FTOBP 0->1 K32767.0", 0, 2, 32767},
	{103, ML_CODE_FTOBP, setCodeOp2_minE_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"FTOBP 0->1 K-32768.0", 0, 2, -32768},
	{104, ML_CODE_FTOBP, setCodeOp2_upE_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"FTOBP 0->1 K101.5", 0, 2, 102},
	{105, ML_CODE_FTOBP, setCodeOp2_WZ_W, setInputOp2_float_WZ_off, verifyResultValueWord,
			"FTOBP 0->0 WZ257.0", 1, 2, 0},
	{106, ML_CODE_FTOBP, setCodeOp2_WZ_W, setInputOp2_floatp_WZ_on, verifyResultValueWord,
			"FTOBP 0->1 WZ257.0", 1, 2, 257},
	{107, ML_CODE_FTOBP, setCodeOp2_WZ_W, setInputOp2_floatp_maxWZ_on, verifyResultValueWord,
			"FTOBP 0->1 WZ32767.0", 1, 2, 32767},
	{108, ML_CODE_FTOBP, setCodeOp2_WZ_W, setInputOp2_floatp_dn_WZ_on, verifyResultValueWord,
			"FTOBP 0->1 WZ101.4", 1, 2, 101},
	{109, ML_CODE_FTOBP, setCodeOp2_WZ_W, setInputOp2_floatp_up_WZ_on, verifyResultValueWord,
			"FTOBP 0->1 WZ101.5", 1, 2, 102},
	{110, ML_CODE_FTOBP, setCodeOp2_WZ_N, setInputOp2_float_WZ_off, verifyResultValueNibble4,
			"FTOBP 0->0 WZ257.0", 3, 2, 0},
	{111, ML_CODE_FTOBP, setCodeOp2_WZ_N, setInputOp2_floatp_WZ_on, verifyResultValueNibble4,
			"FTOBP 0->1 WZ257.0", 3, 2, 257},
	{112, ML_CODE_FTOBP, setCodeOp2_WZ_N, setInputOp2_floatp_maxWZ_on, verifyResultValueNibble4,
			"FTOBP 0->1 WZ32767.0", 3, 2, 32767},
	{113, ML_CODE_FTOBP, setCodeOp2_WZ_N, setInputOp2_floatp_dn_WZ_on, verifyResultValueNibble4,
			"FTOBP 0->1 WZ101.4", 3, 2, 101},
	{114, ML_CODE_FTOBP, setCodeOp2_WZ_N, setInputOp2_floatp_up_WZ_on, verifyResultValueNibble4,
			"FTOBP 0->1 WZ101.5", 3, 2, 102},
	{115, ML_CODE_FTOBP, setCodeOp2_WZ_WZ, setInputOp2_float_WZ_off, verifyResultValueWord,
			"FTOBP 0->0 WZ257.0", 2, 2, 0},
	{116, ML_CODE_FTOBP, setCodeOp2_WZ_WZ, setInputOp2_floatp_WZ_on, verifyResultValueWord,
			"FTOBP 0->1 WZ257.0", 2, 2, 257},
	{117, ML_CODE_FTOBP, setCodeOp2_WZ_WZ, setInputOp2_floatp_maxWZ_on, verifyResultValueWord,
			"FTOBP 0->1 WZ32767.0", 2, 2, 32767},
	{118, ML_CODE_FTOBP, setCodeOp2_WZ_WZ, setInputOp2_floatp_dn_WZ_on, verifyResultValueWord,
			"FTOBP 0->1 WZ101.4", 2, 2, 101},
	{119, ML_CODE_FTOBP, setCodeOp2_WZ_WZ, setInputOp2_floatp_up_WZ_on, verifyResultValueWord,
			"FTOBP 0->1 WZ101.5", 2, 2, 102},

	{120, ML_CODE_DTOB, setCodeOp2_W_WZ, setInputOp2_val32_DW_off, verifyResultValueWord,
			"DTOB off 257", 0, 1, 0},
	{121, ML_CODE_DTOB, setCodeOp2_W_WZ, setInputOp2_val32_DW_on, verifyResultValueWord,
			"DTOB on 257", 0, 1, 257},
	{122, ML_CODE_DTOB, setCodeOp2_W_WZ, setInputOp2_val32_maxDW_on, verifyResultValueWord,
			"DTOB on 32767", 0, 1, 32767},
	{123, ML_CODE_DTOB, setCodeOp2_maxDK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"DTOB off DK32767", 0, 1, 0},
	{124, ML_CODE_DTOB, setCodeOp2_maxDK_WZ, setInputOp2_none_on, verifyResultValueWord,
			"DTOB on DK32767", 0, 1, 32767},
	{125, ML_CODE_DTOB, setCodeOp2_minDK_WZ, setInputOp2_none_on, verifyResultValueWord,
			"DTOB on DK-32768", 0, 1, -32768},
	{126, ML_CODE_DTOB, setCodeOp2_DN_WZ, setInputOp2_val32_DN_off, verifyResultValueWord,
			"DTOB off DN257", 0, 1, 0},
	{127, ML_CODE_DTOB, setCodeOp2_DN_WZ, setInputOp2_val32_DN_on, verifyResultValueWord,
			"DTOB on DN257", 0, 1, 257},
	{128, ML_CODE_DTOB, setCodeOp2_DN_WZ, setInputOp2_val32_maxDN_on, verifyResultValueWord,
			"DTOB on DN32767", 0, 1, 32767},
	{129, ML_CODE_DTOB, setCodeOp2_WZ_W, setInputOp2_val32_DWZ_off, verifyResultValueWord,
			"DTOB off DWZ257", 1, 1, 0},
	{130, ML_CODE_DTOB, setCodeOp2_WZ_W, setInputOp2_val32_DWZ_on, verifyResultValueWord,
			"DTOB on DWZ257", 1, 1, 257},
	{131, ML_CODE_DTOB, setCodeOp2_WZ_W, setInputOp2_val32_maxDWZ_on, verifyResultValueWord,
			"DTOB on DWZ32767", 1, 1, 32767},
	{132, ML_CODE_DTOB, setCodeOp2_WZ_N, setInputOp2_val32_DWZ_off, verifyResultValueNibble4,
			"DTOB off DWZ257", 3, 1, 0},
	{133, ML_CODE_DTOB, setCodeOp2_WZ_N, setInputOp2_val32_DWZ_on, verifyResultValueNibble4,
			"DTOB on DWZ257", 3, 1, 257},
	{134, ML_CODE_DTOB, setCodeOp2_WZ_N, setInputOp2_val32_maxDWZ_on, verifyResultValueNibble4,
			"DTOB on DWZ32767", 3, 1, 32767},
	{135, ML_CODE_DTOB, setCodeOp2_WZ_WZ, setInputOp2_val32_DWZ_off, verifyResultValueWord,
			"DTOB off DWZ257", 2, 1, 0},
	{136, ML_CODE_DTOB, setCodeOp2_WZ_WZ, setInputOp2_val32_DWZ_on, verifyResultValueWord,
			"DTOB on DWZ257", 2, 1, 257},
	{137, ML_CODE_DTOB, setCodeOp2_WZ_WZ, setInputOp2_val32_maxDWZ_on, verifyResultValueWord,
			"DTOB on DWZ32767", 2, 1, 32767},

	{138, ML_CODE_DTOBP, setCodeOp2_W_WZ, setInputOp2_val32_DW_off, verifyResultValueWord,
			"DTOBP 0->0 257", 0, 2, 0},
	{139, ML_CODE_DTOBP, setCodeOp2_W_WZ, setInputOp2_val32p_DW_on, verifyResultValueWord,
			"DTOBP 0->1 257", 0, 2, 257},
	{140, ML_CODE_DTOBP, setCodeOp2_W_WZ, setInputOp2_val32p_maxDW_on, verifyResultValueWord,
			"DTOBP 0->1 32767", 0, 2, 32767},
	{141, ML_CODE_DTOBP, setCodeOp2_maxDK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"DTOBP 0->0 DK32767", 0, 2, 0},
	{142, ML_CODE_DTOBP, setCodeOp2_maxDK_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"DTOBP 0->1 DK32767", 0, 2, 32767},
	{143, ML_CODE_DTOBP, setCodeOp2_minDK_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"DTOBP 0->1 DK-32768", 0, 2, -32768},
	{144, ML_CODE_DTOBP, setCodeOp2_DN_WZ, setInputOp2_val32_DN_off, verifyResultValueWord,
			"DTOBP 0->0 DN257", 0, 2, 0},
	{145, ML_CODE_DTOBP, setCodeOp2_DN_WZ, setInputOp2_val32p_DN_on, verifyResultValueWord,
			"DTOBP 0->1 DN257", 0, 2, 257},
	{146, ML_CODE_DTOBP, setCodeOp2_DN_WZ, setInputOp2_val32p_maxDN_on, verifyResultValueWord,
			"DTOBP 0->1 DN32767", 0, 2, 32767},
	{147, ML_CODE_DTOBP, setCodeOp2_WZ_W, setInputOp2_val32_DWZ_off, verifyResultValueWord,
			"DTOBP 0->0 DWZ257", 1, 2, 0},
	{148, ML_CODE_DTOBP, setCodeOp2_WZ_W, setInputOp2_val32p_DWZ_on, verifyResultValueWord,
			"DTOBP 0->1 DWZ257", 1, 2, 257},
	{149, ML_CODE_DTOBP, setCodeOp2_WZ_W, setInputOp2_val32p_maxDWZ_on, verifyResultValueWord,
			"DTOBP 0->1 DWZ32767", 1, 2, 32767},
	{150, ML_CODE_DTOBP, setCodeOp2_WZ_N, setInputOp2_val32_DWZ_off, verifyResultValueNibble4,
			"DTOBP 0->0 DWZ257", 3, 2, 0},
	{151, ML_CODE_DTOBP, setCodeOp2_WZ_N, setInputOp2_val32p_DWZ_on, verifyResultValueNibble4,
			"DTOBP 0->1 DWZ257", 3, 2, 257},
	{152, ML_CODE_DTOBP, setCodeOp2_WZ_N, setInputOp2_val32p_maxDWZ_on, verifyResultValueNibble4,
			"DTOBP 0->1 DWZ32767", 3, 2, 32767},
	{153, ML_CODE_DTOBP, setCodeOp2_WZ_WZ, setInputOp2_val32_DWZ_off, verifyResultValueWord,
			"DTOBP 0->0 DWZ257", 2, 2, 0},
	{154, ML_CODE_DTOBP, setCodeOp2_WZ_WZ, setInputOp2_val32p_DWZ_on, verifyResultValueWord,
			"DTOBP 0->1 DWZ257", 2, 2, 257},
	{155, ML_CODE_DTOBP, setCodeOp2_WZ_WZ, setInputOp2_val32p_maxDWZ_on, verifyResultValueWord,
			"DTOBP 0->1 DWZ32767", 2, 2, 32767},

	{156, ML_CODE_BTOGRY, setCodeOp2_W_WZ, setInputOp2_val16_BGW_off, verifyResultValueWord,
			"BTOGRY off 1234", 0, 1, 0},
	{157, ML_CODE_BTOGRY, setCodeOp2_W_WZ, setInputOp2_val16_BGW_on, verifyResultValueWord,
			"BTOGRY on 1234", 0, 1, 0x06BB},
	{158, ML_CODE_BTOGRY, setCodeOp2_K1234_WZ, setInputOp2_none_off, verifyResultValueWord,
			"BTOGRY off K1234", 0, 1, 0},
	{159, ML_CODE_BTOGRY, setCodeOp2_K1234_WZ, setInputOp2_none_on, verifyResultValueWord,
			"BTOGRY on K1234", 0, 1, 0x06BB},
	{160, ML_CODE_BTOGRY, setCodeOp2_N_WZ, setInputOp2_val16_BGN_off, verifyResultValueWord,
			"BTOGRY off N1234", 0, 1, 0},
	{161, ML_CODE_BTOGRY, setCodeOp2_N_WZ, setInputOp2_val16_BGN_on, verifyResultValueWord,
			"BTOGRY on N1234", 0, 1, 0x06BB},
	{162, ML_CODE_BTOGRY, setCodeOp2_WZ_W, setInputOp2_val16_BGWZ_off, verifyResultValueWord,
			"BTOGRY off WZ1234", 1, 1, 0},
	{163, ML_CODE_BTOGRY, setCodeOp2_WZ_W, setInputOp2_val16_BGWZ_on, verifyResultValueWord,
			"BTOGRY on WZ1234", 1, 1, 0x06BB},
	{164, ML_CODE_BTOGRY, setCodeOp2_WZ_N, setInputOp2_val16_BGWZ_off, verifyResultValueNibble4,
			"BTOGRY off WZ1234", 3, 1, 0},
	{165, ML_CODE_BTOGRY, setCodeOp2_WZ_N, setInputOp2_val16_BGWZ_on, verifyResultValueNibble4,
			"BTOGRY on WZ1234", 3, 1, 0x06BB},
	{166, ML_CODE_BTOGRY, setCodeOp2_WZ_WZ, setInputOp2_val16_BGWZ_off, verifyResultValueWord,
			"BTOGRY off WZ1234", 2, 1, 0},
	{167, ML_CODE_BTOGRY, setCodeOp2_WZ_WZ, setInputOp2_val16_BGWZ_on, verifyResultValueWord,
			"BTOGRY on WZ1234", 2, 1, 0x06BB},

	{168, ML_CODE_BTOGRYP, setCodeOp2_W_WZ, setInputOp2_val16_BGW_off, verifyResultValueWord,
			"BTOGRYP 0->0 1234", 0, 2, 0},
	{169, ML_CODE_BTOGRYP, setCodeOp2_W_WZ, setInputOp2_val16p_BGW_on, verifyResultValueWord,
			"BTOGRYP 0->1 1234", 0, 2, 0x06BB},
	{170, ML_CODE_BTOGRYP, setCodeOp2_K1234_WZ, setInputOp2_none_off, verifyResultValueWord,
			"BTOGRYP 0->0 K1234", 0, 2, 0},
	{171, ML_CODE_BTOGRYP, setCodeOp2_K1234_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"BTOGRYP 0->1 K1234", 0, 2, 0x06BB},
	{172, ML_CODE_BTOGRYP, setCodeOp2_N_WZ, setInputOp2_val16_BGN_off, verifyResultValueWord,
			"BTOGRYP 0->0 N1234", 0, 2, 0},
	{173, ML_CODE_BTOGRYP, setCodeOp2_N_WZ, setInputOp2_val16p_BGN_on, verifyResultValueWord,
			"BTOGRYP 0->1 N1234", 0, 2, 0x06BB},
	{174, ML_CODE_BTOGRYP, setCodeOp2_WZ_W, setInputOp2_val16_BGWZ_off, verifyResultValueWord,
			"BTOGRYP 0->0 WZ1234", 1, 2, 0},
	{175, ML_CODE_BTOGRYP, setCodeOp2_WZ_W, setInputOp2_val16p_BGWZ_on, verifyResultValueWord,
			"BTOGRYP 0->1 WZ1234", 1, 2, 0x06BB},
	{176, ML_CODE_BTOGRYP, setCodeOp2_WZ_N, setInputOp2_val16_BGWZ_off, verifyResultValueNibble4,
			"BTOGRYP 0->0 WZ1234", 3, 2, 0},
	{177, ML_CODE_BTOGRYP, setCodeOp2_WZ_N, setInputOp2_val16p_BGWZ_on, verifyResultValueNibble4,
			"BTOGRYP 0->1 WZ1234", 3, 2, 0x06BB},
	{178, ML_CODE_BTOGRYP, setCodeOp2_WZ_WZ, setInputOp2_val16_BGWZ_off, verifyResultValueWord,
			"BTOGRYP 0->0 WZ1234", 2, 2, 0},
	{179, ML_CODE_BTOGRYP, setCodeOp2_WZ_WZ, setInputOp2_val16p_BGWZ_on, verifyResultValueWord,
			"BTOGRYP 0->1 WZ1234", 2, 2, 0x06BB},

	{180, ML_CODE_GRYTOB, setCodeOp2_W_WZ, setInputOp2_val16_GBW_off, verifyResultValueWord,
			"GRYTOB off 0x06BB", 0, 1, 0},
	{181, ML_CODE_GRYTOB, setCodeOp2_W_WZ, setInputOp2_val16_GBW_on, verifyResultValueWord,
			"GRYTOB on 0x06BB", 0, 1, 1234},
	{182, ML_CODE_GRYTOB, setCodeOp2_K0x06BB_WZ, setInputOp2_none_off, verifyResultValueWord,
			"GRYTOB off K0x06BB", 0, 1, 0},
	{183, ML_CODE_GRYTOB, setCodeOp2_K0x06BB_WZ, setInputOp2_none_on, verifyResultValueWord,
			"GRYTOB on K0x06BB", 0, 1, 1234},
	{184, ML_CODE_GRYTOB, setCodeOp2_N_WZ, setInputOp2_val16_GBN_off, verifyResultValueWord,
			"GRYTOB off N0x06BB", 0, 1, 0},
	{185, ML_CODE_GRYTOB, setCodeOp2_N_WZ, setInputOp2_val16_GBN_on, verifyResultValueWord,
			"GRYTOB on N0x06BB", 0, 1, 1234},
	{186, ML_CODE_GRYTOB, setCodeOp2_WZ_W, setInputOp2_val16_GBWZ_off, verifyResultValueWord,
			"GRYTOB off WZ0x06BB", 1, 1, 0},
	{187, ML_CODE_GRYTOB, setCodeOp2_WZ_W, setInputOp2_val16_GBWZ_on, verifyResultValueWord,
			"GRYTOB on WZ0x06BB", 1, 1, 1234},
	{188, ML_CODE_GRYTOB, setCodeOp2_WZ_N, setInputOp2_val16_GBWZ_off, verifyResultValueNibble4,
			"GRYTOB off WZ0x06BB", 3, 1, 0},
	{189, ML_CODE_GRYTOB, setCodeOp2_WZ_N, setInputOp2_val16_GBWZ_on, verifyResultValueNibble4,
			"GRYTOB on WZ0x06BB", 3, 1, 1234},
	{190, ML_CODE_GRYTOB, setCodeOp2_WZ_WZ, setInputOp2_val16_GBWZ_off, verifyResultValueWord,
			"GRYTOB off WZ0x06BB", 2, 1, 0},
	{191, ML_CODE_GRYTOB, setCodeOp2_WZ_WZ, setInputOp2_val16_GBWZ_on, verifyResultValueWord,
			"GRYTOB on WZ0x06BB", 2, 1, 1234},

	{192, ML_CODE_GRYTOBP, setCodeOp2_W_WZ, setInputOp2_val16_GBW_off, verifyResultValueWord,
			"GRYTOBP off 0x06BB", 0, 2, 0},
	{193, ML_CODE_GRYTOBP, setCodeOp2_W_WZ, setInputOp2_val16p_GBW_on, verifyResultValueWord,
			"GRYTOBP on 0x06BB", 0, 2, 1234},
	{194, ML_CODE_GRYTOBP, setCodeOp2_K0x06BB_WZ, setInputOp2_none_off, verifyResultValueWord,
			"GRYTOBP off K0x06BB", 0, 2, 0},
	{195, ML_CODE_GRYTOBP, setCodeOp2_K0x06BB_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"GRYTOBP on K0x06BB", 0, 2, 1234},
	{196, ML_CODE_GRYTOBP, setCodeOp2_N_WZ, setInputOp2_val16_GBN_off, verifyResultValueWord,
			"GRYTOBP off N0x06BB", 0, 2, 0},
	{197, ML_CODE_GRYTOBP, setCodeOp2_N_WZ, setInputOp2_val16p_GBN_on, verifyResultValueWord,
			"GRYTOBP on N0x06BB", 0, 2, 1234},
	{198, ML_CODE_GRYTOBP, setCodeOp2_WZ_W, setInputOp2_val16_GBWZ_off, verifyResultValueWord,
			"GRYTOBP off WZ0x06BB", 1, 2, 0},
	{199, ML_CODE_GRYTOBP, setCodeOp2_WZ_W, setInputOp2_val16p_GBWZ_on, verifyResultValueWord,
			"GRYTOBP on WZ0x06BB", 1, 2, 1234},
	{200, ML_CODE_GRYTOBP, setCodeOp2_WZ_N, setInputOp2_val16_GBWZ_off, verifyResultValueNibble4,
			"GRYTOBP off WZ0x06BB", 3, 2, 0},
	{201, ML_CODE_GRYTOBP, setCodeOp2_WZ_N, setInputOp2_val16p_GBWZ_on, verifyResultValueNibble4,
			"GRYTOBP on WZ0x06BB", 3, 2, 1234},
	{202, ML_CODE_GRYTOBP, setCodeOp2_WZ_WZ, setInputOp2_val16_GBWZ_off, verifyResultValueWord,
			"GRYTOBP off WZ0x06BB", 2, 2, 0},
	{203, ML_CODE_GRYTOBP, setCodeOp2_WZ_WZ, setInputOp2_val16p_GBWZ_on, verifyResultValueWord,
			"GRYTOBP on WZ0x06BB", 2, 2, 1234},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};


int total_conversion_test_idx_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_conversion_test_idx_number; i++)
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

int setCodeOp2_W_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos + idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_K101_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 101); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_BK101_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x101); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_K9999_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 9999); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_BK9999_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x9999); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_K1234_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 1234); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_K0x06BB_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x06BB); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_N_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_WZ_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos+idx_val == pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_WZ_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_WZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	if(in_reg == out_reg && in_pos == pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxE_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 32767.0); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_minE_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, -32768.0); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_upE_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 101.5); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 32767); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_minDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, -32768); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_DN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp2_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputOp2_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputOp2_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);

	TestCodeTearDown();
}

void setInputOp2_val16_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16p_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16_maxN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16p_maxN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=9999;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=9999;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	uint16 in_val=0x101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	uint16 in_val=0x101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	uint16 in_val=0x101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	uint16 in_val=0x9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	uint16 in_val=0x9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD4_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD4p_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD4_maxN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD4p_maxN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD4_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x9999;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x9999;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=257.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=257.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_floatp_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=257.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=32767.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_floatp_maxW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=32767.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_dn_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=101.4;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_floatp_dn_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=101.4;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_up_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=101.5;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_floatp_up_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=101.5;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=257.0;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=257.0;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_floatp_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=257.0;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=32767.0;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_floatp_maxWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=32767.0;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_dn_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=101.4;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_floatp_dn_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=101.4;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_float_up_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=101.5;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_floatp_up_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=101.5;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32_maxDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_maxDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val32_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val32p_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val32_maxDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val32p_maxDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val32_DWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_DWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32_maxDWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_maxDWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_BGW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_BGW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_BGW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_BGN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16_BGN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16p_BGN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16_BGWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_BGWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_BGWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_GBW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x06BB;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_GBW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x06BB;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_GBW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x06BB;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_GBN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x06BB;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16_GBN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x06BB;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16p_GBN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x06BB;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16_GBWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x06BB;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16_GBWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x06BB;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_GBWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x06BB;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; // for Dword input

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_conversion_word_idx(int tno, uint16 dummy)
{
	int i=1, inx=7, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	short res_word;
	long long res_nword;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_B; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				if(in==out)
					continue;
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					//for(inx=0; inx<15; inx++) // testidx
					{
						PLC_DEVICE_Init();

						in_pos = getPos(in, i);

						rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos, testidx[inx].pos, testidx[inx].val);
						if( rc2 == 0 ) continue;

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
							if(testCase[tno].z_type==1 || testCase[tno].z_type==3) //op1 is index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
								if(rc == 1)
								{
									if(testCase[tno].z_type==1)
									{
										test_getWord(&res_word, out, out_pos);
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d]=%d exp=%d\n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_word, testCase[tno].expected);
									}
									else
									{
										test_getNibble(&res_nword, out, out_pos, 4);
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_N_%s[%d]=%d exp=%d\n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_nword, testCase[tno].expected);
									}
								}
							}
							else // op2 is index or both are index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos+testidx[inx].val, testCase[tno].expected);
								if(rc == 1)
								{
									test_getWord(&res_word, out, out_pos+testidx[inx].val);
									if(testCase[tno].z_type==0)
									{
										fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d+%d]=%d exp=%d \n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, reg[out], out_pos, testidx[inx].val, res_word, testCase[tno].expected);
									}
									else
									{
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d+%d]=%d exp=%d \n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, testidx[inx].val, res_word, testCase[tno].expected);
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

void testConversionWordIndexCommand(void)
{
	int i, index=129;
	int start, end;
	char log[] = "err_conv_word_idx.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("conversion word index LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
	test_basic_conversion_word_idx(index, 0);

#else
	total_conversion_test_idx_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_BTOBCD); //ML_CODE_BTOBCD
	end = getTestCaseNumberEnd(ML_CODE_GRYTOBP); //ML_CODE_GRYTOBP

	DBG_LOGPRINT("testConversionWordIndexCommand: %d to %d total %d\n", start, end, total_conversion_test_idx_number);
	for(index=start; index<=end; index++)
	{
		test_basic_conversion_word_idx(index, 0);
	}
#endif
	fclose(flog);
}
#endif
