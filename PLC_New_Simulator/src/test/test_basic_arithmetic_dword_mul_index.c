/*
 * test_basic_arithmetic_dword_mul_index.c
 *
 *  Created on: Sep 2, 2015
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
extern int setCodeOp3S_DKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_DKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_DNW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_DWN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZDN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_DNWZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

extern int setCodeOp3S_DBKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_DBKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZDBK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZDBK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp2_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp3_val32_DWW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DW_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DKW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_DKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DNW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DWN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DWN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_DWN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DWZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DWZK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DWZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_DWZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_WZDN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DNWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_WZN_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_WZN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_WZN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DNWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_WZWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32_WZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp3_val32p_WZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);


extern int verifyResultValueLWord(int tcase, uint8 dest_reg, uint16 pos, long long expected);
extern int verifyResultValueNibble16(int tcase, uint8 dest_reg, uint16 pos, long long expected);


int setCodeOp3S_WZW_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDK_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDN_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DNWZ_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZWZ_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

int setCodeOp3S_DBKW_QWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DBKK_QWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDBK_QWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDBK_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

void setInputOp3_BCD8_DWW_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DWW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DW_WQWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DW_WQWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DW_WQWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DBKW_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DBKW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DBKW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNW_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DNW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WDN_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WDN_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_WDN_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWZW_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWZW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DWZW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDBK_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDBK_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_WZDBK_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDN_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDN_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_WZDN_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNWZ_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNWZ_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DNWZ_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDN_QN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDN_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_WZDN_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNWZ_QN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNWZ_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DNWZ_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWZWZ_QN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWZWZ_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DWZWZ_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);


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
	int (*verifyResult_fn)(int, uint8, uint16, long long);
	char str[40];
	//int count;
	int z_type; // 0 : out is index, 1: op1 is index
	int run_step;
	long long expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_DMLT, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_off, verifyResultValueLWord,
			"DMLT off zop3=op1*op2", 0, 1, 0},
	{1, ML_CODE_DMLT, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_on, verifyResultValueLWord,
			"DMLT on zop3=op1*op2", 0, 1, 70109427840},
	{2, ML_CODE_DMLT, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_off, verifyResultValueLWord,
			"DMLT off zop3=op1*op2", 0, 1, 0},
	{3, ML_CODE_DMLT, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_on, verifyResultValueLWord,
			"DMLT on zop3=op1*op2", 0, 1, 70109427840},
	{4, ML_CODE_DMLT, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_off, verifyResultValueLWord,
			"DMLT off zop3=K*op2", 0, 1, 0},
	{5, ML_CODE_DMLT, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_on, verifyResultValueLWord,
			"DMLT on zop3=K*op2", 0, 1, 70109427840},
	{6, ML_CODE_DMLT, setCodeOp3S_DKK_WZ, setInputOp2_none_off, verifyResultValueLWord,
			"DMLT off zop3=K*K", 0, 1, 0},
	{7, ML_CODE_DMLT, setCodeOp3S_DKK_WZ, setInputOp2_none_on, verifyResultValueLWord,
			"DMLT on zop3=K*K", 0, 1, 70109427840},
	{8, ML_CODE_DMLT, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_off, verifyResultValueLWord,
			"DMLT off zop3=nop1*op2", 0, 1, 0},
	{9, ML_CODE_DMLT, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_on, verifyResultValueLWord,
			"DMLT on zop3=nop1*op2", 0, 1, 70109427840},
	{10, ML_CODE_DMLT, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_off, verifyResultValueLWord,
			"DMLT off zop3=op1*nop2", 0, 1, 0},
	{11, ML_CODE_DMLT, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_on, verifyResultValueLWord,
			"DMLT on zop3=op1*nop2", 0, 1, 70109427840},
	{12, ML_CODE_DMLT, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_off, verifyResultValueLWord,
			"DMLT off zop3=zop1*op2", 2, 1, 0},
	{13, ML_CODE_DMLT, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_on, verifyResultValueLWord,
			"DMLT on zop3=zop1*op2", 2, 1, 70109427840},
	{14, ML_CODE_DMLT, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_off, verifyResultValueLWord,
			"DMLT off zop3=zop1*K", 2, 1, 0},
	{15, ML_CODE_DMLT, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_on, verifyResultValueLWord,
			"DMLT on zop3=zop1*K", 2, 1, 70109427840},
	{16, ML_CODE_DMLT, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_off, verifyResultValueLWord,
			"DMLT off zop3=zop1*nop2", 2, 1, 0},
	{17, ML_CODE_DMLT, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_on, verifyResultValueLWord,
			"DMLT on zop3=zop1*nop2", 2, 1, 70109427840},
	{18, ML_CODE_DMLT, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_off, verifyResultValueLWord,
			"DMLT off zop3=nop1*zop2", 2, 1, 0},
	{19, ML_CODE_DMLT, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_on, verifyResultValueLWord,
			"DMLT on zop3=nop1*zop2", 2, 1, 70109427840},
	{20, ML_CODE_DMLT, setCodeOp3S_WZW_QN, setInputOp3_val32_DWZW_WZ_off, verifyResultValueNibble16,
			"DMLT off nop3=zop1*op2", 1, 1, 0},
	{21, ML_CODE_DMLT, setCodeOp3S_WZW_QN, setInputOp3_val32_DWZW_WZ_on, verifyResultValueNibble16,
			"DMLT on nop3=zop1*op2", 1, 1, 70109427840},
	{22, ML_CODE_DMLT, setCodeOp3S_WZDK_QN, setInputOp3_val32_DWZK_WZ_off, verifyResultValueNibble16,
			"DMLT off nop3=zop1*K", 1, 1, 0},
	{23, ML_CODE_DMLT, setCodeOp3S_WZDK_QN, setInputOp3_val32_DWZK_WZ_on, verifyResultValueNibble16,
			"DMLT on nop3=zop1*K", 1, 1, 70109427840},
	{24, ML_CODE_DMLT, setCodeOp3S_WZDN_QN, setInputOp3_val32_WZN_DN_off, verifyResultValueNibble16,
			"DMLT off nop3=zop1*nop2", 1, 1, 0},
	{25, ML_CODE_DMLT, setCodeOp3S_WZDN_QN, setInputOp3_val32_WZN_DN_on, verifyResultValueNibble16,
			"DMLT on nop3=zop1*nop2", 1, 1, 70109427840},
	{26, ML_CODE_DMLT, setCodeOp3S_DNWZ_QN, setInputOp3_val32_DNWZ_DN_off, verifyResultValueNibble16,
			"DMLT off nop3=nop1*zop2", 1, 1, 0},
	{27, ML_CODE_DMLT, setCodeOp3S_DNWZ_QN, setInputOp3_val32_DNWZ_DN_on, verifyResultValueNibble16,
			"DMLT on nop3=nop1*zop2", 1, 1, 70109427840},
	{28, ML_CODE_DMLT, setCodeOp3S_WZWZ_QN, setInputOp3_val32_WZWZ_DN_off, verifyResultValueNibble16,
			"DMLT off nop3=zop1*zop2", 1, 1, 0},
	{29, ML_CODE_DMLT, setCodeOp3S_WZWZ_QN, setInputOp3_val32_WZWZ_DN_on, verifyResultValueNibble16,
			"DMLT on nop3=zop1*zop2", 1, 1, 70109427840},

	{30, ML_CODE_DMLTP, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=op1*op2", 0, 2, 0},
	{31, ML_CODE_DMLTP, setCodeOp3S_WW_WZ, setInputOp3_val32p_DWW_WZ_on, verifyResultValueLWord,
			"DMLTP 0->1 zop3=op1*op2", 0, 2, 70109427840},
	{32, ML_CODE_DMLTP, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=op1*op2", 0, 2, 0},
	{33, ML_CODE_DMLTP, setCodeOp3S_W_WWZ, setInputOp3_val32p_DW_WWZ_on, verifyResultValueLWord,
			"DMLTP 0->1 zop3=op1*op2", 0, 2, 70109427840},
	{34, ML_CODE_DMLTP, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=K*op2", 0, 2, 0},
	{35, ML_CODE_DMLTP, setCodeOp3S_DKW_WZ, setInputOp3_val32p_DKW_WZ_on, verifyResultValueLWord,
			"DMLTP 0->1 zop3=K*op2", 0, 2, 70109427840},
	{36, ML_CODE_DMLTP, setCodeOp3S_DKK_WZ, setInputOp2_none_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=K*K", 0, 2, 0},
	{37, ML_CODE_DMLTP, setCodeOp3S_DKK_WZ, setInputOp2_none_tr1, verifyResultValueLWord,
			"DMLTP 0->1 zop3=K*K", 0, 2, 70109427840},
	{38, ML_CODE_DMLTP, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=nop1*op2", 0, 2, 0},
	{39, ML_CODE_DMLTP, setCodeOp3S_DNW_WZ, setInputOp3_val32p_DNW_WZ_on, verifyResultValueLWord,
			"DMLTP 0->1 zop3=nop1*op2", 0, 2, 70109427840},
	{40, ML_CODE_DMLTP, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=op1*nop2", 0, 2, 0},
	{41, ML_CODE_DMLTP, setCodeOp3S_DWN_WZ, setInputOp3_val32p_DWN_WZ_on, verifyResultValueLWord,
			"DMLTP 0->1 zop3=op1*nop2", 0, 2, 70109427840},
	{42, ML_CODE_DMLTP, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=zop1*op2", 2, 2, 0},
	{43, ML_CODE_DMLTP, setCodeOp3S_WZW_WZ, setInputOp3_val32p_DWZW_WZ_on, verifyResultValueLWord,
			"DMLTP 0->1 zop3=zop1*op2", 2, 2, 70109427840},
	{44, ML_CODE_DMLTP, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=zop1*K", 2, 2, 0},
	{45, ML_CODE_DMLTP, setCodeOp3S_WZDK_WZ, setInputOp3_val32p_DWZK_WZ_on, verifyResultValueLWord,
			"DMLTP 0->1 zop3=zop1*K", 2, 2, 70109427840},
	{46, ML_CODE_DMLTP, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=zop1*nop2", 2, 2, 0},
	{47, ML_CODE_DMLTP, setCodeOp3S_WZDN_WZ, setInputOp3_val32p_WZDN_WZ_on, verifyResultValueLWord,
			"DMLTP 0->1 zop3=zop1*nop2", 2, 2, 70109427840},
	{48, ML_CODE_DMLTP, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_off, verifyResultValueLWord,
			"DMLTP 0->0 zop3=nop1*zop2", 2, 2, 0},
	{49, ML_CODE_DMLTP, setCodeOp3S_DNWZ_WZ, setInputOp3_val32p_DNWZ_WZ_on, verifyResultValueLWord,
			"DMLTP 0->1 zop3=nop1*zop2", 2, 2, 70109427840},
	{50, ML_CODE_DMLTP, setCodeOp3S_WZW_QN, setInputOp3_val32_DWZW_WZ_off, verifyResultValueNibble16,
			"DMLTP 0->0 nop3=zop1*op2", 1, 2, 0},
	{51, ML_CODE_DMLTP, setCodeOp3S_WZW_QN, setInputOp3_val32p_DWZW_WZ_on, verifyResultValueNibble16,
			"DMLTP 0->1 nop3=zop1*op2", 1, 2, 70109427840},
	{52, ML_CODE_DMLTP, setCodeOp3S_WZDK_QN, setInputOp3_val32_DWZK_WZ_off, verifyResultValueNibble16,
			"DMLTP 0->0 nop3=zop1*K", 1, 2, 0},
	{53, ML_CODE_DMLTP, setCodeOp3S_WZDK_QN, setInputOp3_val32p_DWZK_WZ_on, verifyResultValueNibble16,
			"DMLTP 0->1 nop3=zop1*K", 1, 2, 70109427840},
	{54, ML_CODE_DMLTP, setCodeOp3S_WZDN_QN, setInputOp3_val32_WZN_DN_off, verifyResultValueNibble16,
			"DMLTP 0->0 nop3=zop1*nop2", 1, 2, 0},
	{55, ML_CODE_DMLTP, setCodeOp3S_WZDN_QN, setInputOp3_val32p_WZN_DN_on, verifyResultValueNibble16,
			"DMLTP 0->1 nop3=zop1*nop2", 1, 2, 70109427840},
	{56, ML_CODE_DMLTP, setCodeOp3S_DNWZ_QN, setInputOp3_val32_DNWZ_DN_off, verifyResultValueNibble16,
			"DMLTP 0->0 nop3=nop1*zop2", 1, 2, 0},
	{57, ML_CODE_DMLTP, setCodeOp3S_DNWZ_QN, setInputOp3_val32p_DNWZ_DN_on, verifyResultValueNibble16,
			"DMLTP 0->1 nop3=nop1*zop2", 1, 2, 70109427840},
	{58, ML_CODE_DMLTP, setCodeOp3S_WZWZ_QN, setInputOp3_val32_WZWZ_DN_off, verifyResultValueNibble16,
			"DMLTP 0->0 nop3=zop1*zop2", 1, 2, 0},
	{59, ML_CODE_DMLTP, setCodeOp3S_WZWZ_QN, setInputOp3_val32p_WZWZ_DN_on, verifyResultValueNibble16,
			"DMLTP 0->1 nop3=zop1*zop2", 1, 2, 70109427840},

	{60, ML_CODE_DDIV, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_off, verifyResultValueLWord,
			"DDIV off zop3=op1*op2", 0, 1, 0},
	{61, ML_CODE_DDIV, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_on, verifyResultValueLWord,
			"DDIV on zop3=op1*op2", 0, 1, 318111047745540},
	{62, ML_CODE_DDIV, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_off, verifyResultValueLWord,
			"DDIV off zop3=op1*op2", 0, 1, 0},
	{63, ML_CODE_DDIV, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_on, verifyResultValueLWord,
			"DDIV on zop3=op1*op2", 0, 1, 318111047745540},
	{64, ML_CODE_DDIV, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_off, verifyResultValueLWord,
			"DDIV off zop3=K*op2", 0, 1, 0},
	{65, ML_CODE_DDIV, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_on, verifyResultValueLWord,
			"DDIV on zop3=K*op2", 0, 1, 318111047745540},
	{66, ML_CODE_DDIV, setCodeOp3S_DKK_WZ, setInputOp2_none_off, verifyResultValueLWord,
			"DDIV off zop3=K*K", 0, 1, 0},
	{67, ML_CODE_DDIV, setCodeOp3S_DKK_WZ, setInputOp2_none_on, verifyResultValueLWord,
			"DDIV on zop3=K*K", 0, 1, 318111047745540},
	{68, ML_CODE_DDIV, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_off, verifyResultValueLWord,
			"DDIV off zop3=nop1*op2", 0, 1, 0},
	{69, ML_CODE_DDIV, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_on, verifyResultValueLWord,
			"DDIV on zop3=nop1*op2", 0, 1, 318111047745540},
	{70, ML_CODE_DDIV, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_off, verifyResultValueLWord,
			"DDIV off zop3=op1*nop2", 0, 1, 0},
	{71, ML_CODE_DDIV, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_on, verifyResultValueLWord,
			"DDIV on zop3=op1*nop2", 0, 1, 318111047745540},
	{72, ML_CODE_DDIV, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_off, verifyResultValueLWord,
			"DDIV off zop3=zop1*op2", 2, 1, 0},
	{73, ML_CODE_DDIV, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_on, verifyResultValueLWord,
			"DDIV on zop3=zop1*op2", 2, 1, 318111047745540},
	{74, ML_CODE_DDIV, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_off, verifyResultValueLWord,
			"DDIV off zop3=zop1*K", 2, 1, 0},
	{75, ML_CODE_DDIV, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_on, verifyResultValueLWord,
			"DDIV on zop3=zop1*K", 2, 1, 318111047745540},
	{76, ML_CODE_DDIV, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_off, verifyResultValueLWord,
			"DDIV off zop3=zop1*nop2", 2, 1, 0},
	{77, ML_CODE_DDIV, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_on, verifyResultValueLWord,
			"DDIV on zop3=zop1*nop2", 2, 1, 318111047745540},
	{78, ML_CODE_DDIV, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_off, verifyResultValueLWord,
			"DDIV off zop3=nop1*zop2", 2, 1, 0},
	{79, ML_CODE_DDIV, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_on, verifyResultValueLWord,
			"DDIV on zop3=nop1*zop2", 2, 1, 318111047745540},
	{80, ML_CODE_DDIV, setCodeOp3S_WZW_QN, setInputOp3_val32_DWZW_WZ_off, verifyResultValueNibble16,
			"DDIV off nop3=zop1*op2", 1, 1, 0},
	{81, ML_CODE_DDIV, setCodeOp3S_WZW_QN, setInputOp3_val32_DWZW_WZ_on, verifyResultValueNibble16,
			"DDIV on nop3=zop1*op2", 1, 1, 318111047745540},
	{82, ML_CODE_DDIV, setCodeOp3S_WZDK_QN, setInputOp3_val32_DWZK_WZ_off, verifyResultValueNibble16,
			"DDIV off nop3=zop1*K", 1, 1, 0},
	{83, ML_CODE_DDIV, setCodeOp3S_WZDK_QN, setInputOp3_val32_DWZK_WZ_on, verifyResultValueNibble16,
			"DDIV on nop3=zop1*K", 1, 1, 318111047745540},
	{84, ML_CODE_DDIV, setCodeOp3S_WZDN_QN, setInputOp3_val32_WZN_DN_off, verifyResultValueNibble16,
			"DDIV off nop3=zop1*nop2", 1, 1, 0},
	{85, ML_CODE_DDIV, setCodeOp3S_WZDN_QN, setInputOp3_val32_WZN_DN_on, verifyResultValueNibble16,
			"DDIV on nop3=zop1*nop2", 1, 1, 318111047745540},
	{86, ML_CODE_DDIV, setCodeOp3S_DNWZ_QN, setInputOp3_val32_DNWZ_DN_off, verifyResultValueNibble16,
			"DDIV off nop3=nop1*zop2", 1, 1, 0},
	{87, ML_CODE_DDIV, setCodeOp3S_DNWZ_QN, setInputOp3_val32_DNWZ_DN_on, verifyResultValueNibble16,
			"DDIV on nop3=nop1*zop2", 1, 1, 318111047745540},
	{88, ML_CODE_DDIV, setCodeOp3S_WZWZ_QN, setInputOp3_val32_WZWZ_DN_off, verifyResultValueNibble16,
			"DDIV off nop3=zop1*zop2", 1, 1, 0},
	{89, ML_CODE_DDIV, setCodeOp3S_WZWZ_QN, setInputOp3_val32_WZWZ_DN_on, verifyResultValueNibble16,
			"DDIV on nop3=zop1*zop2", 1, 1, 318111047745540},

	{90, ML_CODE_DDIVP, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=op1*op2", 0, 2, 0},
	{91, ML_CODE_DDIVP, setCodeOp3S_WW_WZ, setInputOp3_val32p_DWW_WZ_on, verifyResultValueLWord,
			"DDIVP 0->1 zop3=op1*op2", 0, 2, 318111047745540},
	{92, ML_CODE_DDIVP, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=op1*op2", 0, 2, 0},
	{93, ML_CODE_DDIVP, setCodeOp3S_W_WWZ, setInputOp3_val32p_DW_WWZ_on, verifyResultValueLWord,
			"DDIVP 0->1 zop3=op1*op2", 0, 2, 318111047745540},
	{94, ML_CODE_DDIVP, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=K*op2", 0, 2, 0},
	{95, ML_CODE_DDIVP, setCodeOp3S_DKW_WZ, setInputOp3_val32p_DKW_WZ_on, verifyResultValueLWord,
			"DDIVP 0->1 zop3=K*op2", 0, 2, 318111047745540},
	{96, ML_CODE_DDIVP, setCodeOp3S_DKK_WZ, setInputOp2_none_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=K*K", 0, 2, 0},
	{97, ML_CODE_DDIVP, setCodeOp3S_DKK_WZ, setInputOp2_none_tr1, verifyResultValueLWord,
			"DDIVP 0->1 zop3=K*K", 0, 2, 318111047745540},
	{98, ML_CODE_DDIVP, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=nop1*op2", 0, 2, 0},
	{99, ML_CODE_DDIVP, setCodeOp3S_DNW_WZ, setInputOp3_val32p_DNW_WZ_on, verifyResultValueLWord,
			"DDIVP 0->1 zop3=nop1*op2", 0, 2, 318111047745540},
	{100, ML_CODE_DDIVP, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=op1*nop2", 0, 2, 0},
	{101, ML_CODE_DDIVP, setCodeOp3S_DWN_WZ, setInputOp3_val32p_DWN_WZ_on, verifyResultValueLWord,
			"DDIVP 0->1 zop3=op1*nop2", 0, 2, 318111047745540},
	{102, ML_CODE_DDIVP, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=zop1*op2", 2, 2, 0},
	{103, ML_CODE_DDIVP, setCodeOp3S_WZW_WZ, setInputOp3_val32p_DWZW_WZ_on, verifyResultValueLWord,
			"DDIVP 0->1 zop3=zop1*op2", 2, 2, 318111047745540},
	{104, ML_CODE_DDIVP, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=zop1*K", 2, 2, 0},
	{105, ML_CODE_DDIVP, setCodeOp3S_WZDK_WZ, setInputOp3_val32p_DWZK_WZ_on, verifyResultValueLWord,
			"DDIVP 0->1 zop3=zop1*K", 2, 2, 318111047745540},
	{106, ML_CODE_DDIVP, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=zop1*nop2", 2, 2, 0},
	{107, ML_CODE_DDIVP, setCodeOp3S_WZDN_WZ, setInputOp3_val32p_WZDN_WZ_on, verifyResultValueLWord,
			"DDIVP 0->1 zop3=zop1*nop2", 2, 2, 318111047745540},
	{108, ML_CODE_DDIVP, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_off, verifyResultValueLWord,
			"DDIVP 0->0 zop3=nop1*zop2", 2, 2, 0},
	{109, ML_CODE_DDIVP, setCodeOp3S_DNWZ_WZ, setInputOp3_val32p_DNWZ_WZ_on, verifyResultValueLWord,
			"DDIVP 0->1 zop3=nop1*zop2", 2, 2, 318111047745540},
	{110, ML_CODE_DDIVP, setCodeOp3S_WZW_QN, setInputOp3_val32_DWZW_WZ_off, verifyResultValueNibble16,
			"DDIVP 0->0 nop3=zop1*op2", 1, 2, 0},
	{111, ML_CODE_DDIVP, setCodeOp3S_WZW_QN, setInputOp3_val32p_DWZW_WZ_on, verifyResultValueNibble16,
			"DDIVP 0->1 nop3=zop1*op2", 1, 2, 318111047745540},
	{112, ML_CODE_DDIVP, setCodeOp3S_WZDK_QN, setInputOp3_val32_DWZK_WZ_off, verifyResultValueNibble16,
			"DDIVP 0->0 nop3=zop1*K", 1, 2, 0},
	{113, ML_CODE_DDIVP, setCodeOp3S_WZDK_QN, setInputOp3_val32p_DWZK_WZ_on, verifyResultValueNibble16,
			"DDIVP 0->1 nop3=zop1*K", 1, 2, 318111047745540},
	{114, ML_CODE_DDIVP, setCodeOp3S_WZDN_QN, setInputOp3_val32_WZN_DN_off, verifyResultValueNibble16,
			"DDIVP 0->0 nop3=zop1*nop2", 1, 2, 0},
	{115, ML_CODE_DDIVP, setCodeOp3S_WZDN_QN, setInputOp3_val32p_WZN_DN_on, verifyResultValueNibble16,
			"DDIVP 0->1 nop3=zop1*nop2", 1, 2, 318111047745540},
	{116, ML_CODE_DDIVP, setCodeOp3S_DNWZ_QN, setInputOp3_val32_DNWZ_DN_off, verifyResultValueNibble16,
			"DDIVP 0->0 nop3=nop1*zop2", 1, 2, 0},
	{117, ML_CODE_DDIVP, setCodeOp3S_DNWZ_QN, setInputOp3_val32p_DNWZ_DN_on, verifyResultValueNibble16,
			"DDIVP 0->1 nop3=nop1*zop2", 1, 2, 318111047745540},
	{118, ML_CODE_DDIVP, setCodeOp3S_WZWZ_QN, setInputOp3_val32_WZWZ_DN_off, verifyResultValueNibble16,
			"DDIVP 0->0 nop3=zop1*zop2", 1, 2, 0},
	{119, ML_CODE_DDIVP, setCodeOp3S_WZWZ_QN, setInputOp3_val32p_WZWZ_DN_on, verifyResultValueNibble16,
			"DDIVP 0->1 nop3=zop1*zop2", 1, 2, 318111047745540},

	{120, ML_CODE_DBMLT, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_QWZ_off, verifyResultValueLWord,
			"DBMLT off zop3=op1*op2", 0, 1, 0},
	{121, ML_CODE_DBMLT, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_QWZ_on, verifyResultValueLWord,
			"DBMLT on zop3=op1*op2", 0, 1, 0x70109977214741},
	{122, ML_CODE_DBMLT, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WQWZ_off, verifyResultValueLWord,
			"DBMLT off zop3=op1*op2", 0, 1, 0},
	{123, ML_CODE_DBMLT, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WQWZ_on, verifyResultValueLWord,
			"DBMLT on zop3=op1*op2", 0, 1, 0x70109977214741},
	{124, ML_CODE_DBMLT, setCodeOp3S_DBKW_QWZ, setInputOp3_BCD8_DBKW_QWZ_off, verifyResultValueLWord,
			"DBMLT off zop3=K*op2", 0, 1, 0},
	{125, ML_CODE_DBMLT, setCodeOp3S_DBKW_QWZ, setInputOp3_BCD8_DBKW_QWZ_on, verifyResultValueLWord,
			"DBMLT on zop3=K*op2", 0, 1, 0x70109977214741},
	{126, ML_CODE_DBMLT, setCodeOp3S_DBKK_QWZ, setInputOp2_none_off, verifyResultValueLWord,
			"DBMLT off zop3=K*K", 0, 1, 0},
	{127, ML_CODE_DBMLT, setCodeOp3S_DBKK_QWZ, setInputOp2_none_on, verifyResultValueLWord,
			"DBMLT on zop3=K*K", 0, 1, 0x70109977214741},
	{128, ML_CODE_DBMLT, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_QWZ_off, verifyResultValueLWord,
			"DBMLT off zop3=nop1*op2", 0, 1, 0},
	{129, ML_CODE_DBMLT, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_QWZ_on, verifyResultValueLWord,
			"DBMLT on zop3=nop1*op2", 0, 1, 0x70109977214741},
	{130, ML_CODE_DBMLT, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_QWZ_off, verifyResultValueLWord,
			"DBMLT off zop3=op1*nop2", 0, 1, 0},
	{131, ML_CODE_DBMLT, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_QWZ_on, verifyResultValueLWord,
			"DBMLT on zop3=op1*nop2", 0, 1, 0x70109977214741},
	{132, ML_CODE_DBMLT, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_QWZ_off, verifyResultValueLWord,
			"DBMLT off zop3=zop1*op2", 2, 1, 0},
	{133, ML_CODE_DBMLT, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_QWZ_on, verifyResultValueLWord,
			"DBMLT on zop3=zop1*op2", 2, 1, 0x70109977214741},
	{134, ML_CODE_DBMLT, setCodeOp3S_WZDBK_QWZ, setInputOp3_BCD8_WZDBK_QWZ_off, verifyResultValueLWord,
			"DBMLT off zop3=zop1*K", 2, 1, 0},
	{135, ML_CODE_DBMLT, setCodeOp3S_WZDBK_QWZ, setInputOp3_BCD8_WZDBK_QWZ_on, verifyResultValueLWord,
			"DBMLT on zop3=zop1*K", 2, 1, 0x70109977214741},
	{136, ML_CODE_DBMLT, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_QWZ_off, verifyResultValueLWord,
			"DBMLT off zop3=zop1*nop2", 2, 1, 0},
	{137, ML_CODE_DBMLT, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_QWZ_on, verifyResultValueLWord,
			"DBMLT on zop3=zop1*nop2", 2, 1, 0x70109977214741},
	{138, ML_CODE_DBMLT, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_QWZ_off, verifyResultValueLWord,
			"DBMLT off zop3=nop1*zop2", 2, 1, 0},
	{139, ML_CODE_DBMLT, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_QWZ_on, verifyResultValueLWord,
			"DBMLT on zop3=nop1*zop2", 2, 1, 0x70109977214741},
	{140, ML_CODE_DBMLT, setCodeOp3S_WZW_QN, setInputOp3_BCD8_DWZW_QWZ_off, verifyResultValueNibble16,
			"DBMLT off nop3=zop1*op2", 1, 1, 0},
	{141, ML_CODE_DBMLT, setCodeOp3S_WZW_QN, setInputOp3_BCD8_DWZW_QWZ_on, verifyResultValueNibble16,
			"DBMLT on nop3=zop1*op2", 1, 1, 0x70109977214741},
	{142, ML_CODE_DBMLT, setCodeOp3S_WZDBK_QN, setInputOp3_BCD8_WZDBK_QWZ_off, verifyResultValueNibble16,
			"DBMLT off nop3=zop1*K", 1, 1, 0},
	{143, ML_CODE_DBMLT, setCodeOp3S_WZDBK_QN, setInputOp3_BCD8_WZDBK_QWZ_on, verifyResultValueNibble16,
			"DBMLT on nop3=zop1*K", 1, 1, 0x70109977214741},
	{144, ML_CODE_DBMLT, setCodeOp3S_WZDN_QN, setInputOp3_BCD8_WZDN_QN_off, verifyResultValueNibble16,
			"DBMLT off nop3=zop1*nop2", 1, 1, 0},
	{145, ML_CODE_DBMLT, setCodeOp3S_WZDN_QN, setInputOp3_BCD8_WZDN_QN_on, verifyResultValueNibble16,
			"DBMLT on nop3=zop1*nop2", 1, 1, 0x70109977214741},
	{146, ML_CODE_DBMLT, setCodeOp3S_DNWZ_QN, setInputOp3_BCD8_DNWZ_QN_off, verifyResultValueNibble16,
			"DBMLT off nop3=nop1*zop2", 1, 1, 0},
	{147, ML_CODE_DBMLT, setCodeOp3S_DNWZ_QN, setInputOp3_BCD8_DNWZ_QN_on, verifyResultValueNibble16,
			"DBMLT on nop3=nop1*zop2", 1, 1, 0x70109977214741},
	{148, ML_CODE_DBMLT, setCodeOp3S_WZWZ_QN, setInputOp3_BCD8_DWZWZ_QN_off, verifyResultValueNibble16,
			"DBMLT off nop3=zop1*zop2", 1, 1, 0},
	{149, ML_CODE_DBMLT, setCodeOp3S_WZWZ_QN, setInputOp3_BCD8_DWZWZ_QN_on, verifyResultValueNibble16,
			"DBMLT on nop3=zop1*zop2", 1, 1, 0x70109977214741},

	{150, ML_CODE_DBMLTP, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_QWZ_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=op1*op2", 0, 2, 0},
	{151, ML_CODE_DBMLTP, setCodeOp3S_WW_WZ, setInputOp3_BCD8p_DWW_QWZ_on, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=op1*op2", 0, 2, 0x70109977214741},
	{152, ML_CODE_DBMLTP, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WQWZ_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=op1*op2", 0, 2, 0},
	{153, ML_CODE_DBMLTP, setCodeOp3S_W_WWZ, setInputOp3_BCD8p_DW_WQWZ_on, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=op1*op2", 0, 2, 0x70109977214741},
	{154, ML_CODE_DBMLTP, setCodeOp3S_DBKW_QWZ, setInputOp3_BCD8_DBKW_QWZ_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=K*op2", 0, 2, 0},
	{155, ML_CODE_DBMLTP, setCodeOp3S_DBKW_QWZ, setInputOp3_BCD8p_DBKW_QWZ_on, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=K*op2", 0, 2, 0x70109977214741},
	{156, ML_CODE_DBMLTP, setCodeOp3S_DBKK_QWZ, setInputOp2_none_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=K*K", 0, 2, 0},
	{157, ML_CODE_DBMLTP, setCodeOp3S_DBKK_QWZ, setInputOp2_none_tr1, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=K*K", 0, 2, 0x70109977214741},
	{158, ML_CODE_DBMLTP, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_QWZ_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=nop1*op2", 0, 2, 0},
	{159, ML_CODE_DBMLTP, setCodeOp3S_DNW_WZ, setInputOp3_BCD8p_DNW_QWZ_on, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=nop1*op2", 0, 2, 0x70109977214741},
	{160, ML_CODE_DBMLTP, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_QWZ_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=op1*nop2", 0, 2, 0},
	{161, ML_CODE_DBMLTP, setCodeOp3S_DWN_WZ, setInputOp3_BCD8p_WDN_QWZ_on, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=op1*nop2", 0, 2, 0x70109977214741},
	{162, ML_CODE_DBMLTP, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_QWZ_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=zop1*op2", 2, 2, 0},
	{163, ML_CODE_DBMLTP, setCodeOp3S_WZW_WZ, setInputOp3_BCD8p_DWZW_QWZ_on, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=zop1*op2", 2, 2, 0x70109977214741},
	{164, ML_CODE_DBMLTP, setCodeOp3S_WZDBK_QWZ, setInputOp3_BCD8_WZDBK_QWZ_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=zop1*K", 2, 2, 0},
	{165, ML_CODE_DBMLTP, setCodeOp3S_WZDBK_QWZ, setInputOp3_BCD8p_WZDBK_QWZ_on, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=zop1*K", 2, 2, 0x70109977214741},
	{166, ML_CODE_DBMLTP, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_QWZ_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=zop1*nop2", 2, 2, 0},
	{167, ML_CODE_DBMLTP, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8p_WZDN_QWZ_on, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=zop1*nop2", 2, 2, 0x70109977214741},
	{168, ML_CODE_DBMLTP, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_QWZ_off, verifyResultValueLWord,
			"DBMLTP 0->0 zop3=nop1*zop2", 2, 2, 0},
	{169, ML_CODE_DBMLTP, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8p_DNWZ_QWZ_on, verifyResultValueLWord,
			"DBMLTP 0->1 zop3=nop1*zop2", 2, 2, 0x70109977214741},
	{170, ML_CODE_DBMLTP, setCodeOp3S_WZW_QN, setInputOp3_BCD8_DWZW_QWZ_off, verifyResultValueNibble16,
			"DBMLTP 0->0 nop3=zop1*op2", 1, 2, 0},
	{171, ML_CODE_DBMLTP, setCodeOp3S_WZW_QN, setInputOp3_BCD8p_DWZW_QWZ_on, verifyResultValueNibble16,
			"DBMLTP 0->1 nop3=zop1*op2", 1, 2, 0x70109977214741},
	{172, ML_CODE_DBMLTP, setCodeOp3S_WZDBK_QN, setInputOp3_BCD8_WZDBK_QWZ_off, verifyResultValueNibble16,
			"DBMLTP 0->0 nop3=zop1*K", 1, 2, 0},
	{173, ML_CODE_DBMLTP, setCodeOp3S_WZDBK_QN, setInputOp3_BCD8p_WZDBK_QWZ_on, verifyResultValueNibble16,
			"DBMLTP 0->1 nop3=zop1*K", 1, 2, 0x70109977214741},
	{174, ML_CODE_DBMLTP, setCodeOp3S_WZDN_QN, setInputOp3_BCD8_WZDN_QN_off, verifyResultValueNibble16,
			"DBMLTP 0->0 nop3=zop1*nop2", 1, 2, 0},
	{175, ML_CODE_DBMLTP, setCodeOp3S_WZDN_QN, setInputOp3_BCD8p_WZDN_QN_on, verifyResultValueNibble16,
			"DBMLTP 0->1 nop3=zop1*nop2", 1, 2, 0x70109977214741},
	{176, ML_CODE_DBMLTP, setCodeOp3S_DNWZ_QN, setInputOp3_BCD8_DNWZ_QN_off, verifyResultValueNibble16,
			"DBMLTP 0->0 nop3=nop1*zop2", 1, 2, 0},
	{177, ML_CODE_DBMLTP, setCodeOp3S_DNWZ_QN, setInputOp3_BCD8p_DNWZ_QN_on, verifyResultValueNibble16,
			"DBMLTP 0->1 nop3=nop1*zop2", 1, 2, 0x70109977214741},
	{178, ML_CODE_DBMLTP, setCodeOp3S_WZWZ_QN, setInputOp3_BCD8_DWZWZ_QN_off, verifyResultValueNibble16,
			"DBMLTP 0->0 nop3=zop1*zop2", 1, 2, 0},
	{179, ML_CODE_DBMLTP, setCodeOp3S_WZWZ_QN, setInputOp3_BCD8p_DWZWZ_QN_on, verifyResultValueNibble16,
			"DBMLTP 0->1 nop3=zop1*zop2", 1, 2, 0x70109977214741},

	{180, ML_CODE_DBDIV, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_QWZ_off, verifyResultValueLWord,
			"DBDIV off zop3=op1/op2", 0, 1, 0},
	{181, ML_CODE_DBDIV, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_QWZ_on, verifyResultValueLWord,
			"DBDIV on zop3=op1/op2", 0, 1, 0x123360800000045}, //[]=45, [+1]=0, [+2]=3608, [+3]=123
	{182, ML_CODE_DBDIV, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WQWZ_off, verifyResultValueLWord,
			"DBDIV off zop3=op1/op2", 0, 1, 0},
	{183, ML_CODE_DBDIV, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WQWZ_on, verifyResultValueLWord,
			"DBDIV on zop3=op1/op2", 0, 1, 0x123360800000045},
	{184, ML_CODE_DBDIV, setCodeOp3S_DBKW_QWZ, setInputOp3_BCD8_DBKW_QWZ_off, verifyResultValueLWord,
			"DBDIV off zop3=K/op2", 0, 1, 0},
	{185, ML_CODE_DBDIV, setCodeOp3S_DBKW_QWZ, setInputOp3_BCD8_DBKW_QWZ_on, verifyResultValueLWord,
			"DBDIV on zop3=K/op2", 0, 1, 0x123360800000045},
	{186, ML_CODE_DBDIV, setCodeOp3S_DBKK_QWZ, setInputOp2_none_off, verifyResultValueLWord,
			"DBDIV off zop3=K/K", 0, 1, 0},
	{187, ML_CODE_DBDIV, setCodeOp3S_DBKK_QWZ, setInputOp2_none_on, verifyResultValueLWord,
			"DBDIV on zop3=K/K", 0, 1, 0x123360800000045},
	{188, ML_CODE_DBDIV, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_QWZ_off, verifyResultValueLWord,
			"DBDIV off zop3=nop1/op2", 0, 1, 0},
	{189, ML_CODE_DBDIV, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_QWZ_on, verifyResultValueLWord,
			"DBDIV on zop3=nop1/op2", 0, 1, 0x123360800000045},
	{190, ML_CODE_DBDIV, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_QWZ_off, verifyResultValueLWord,
			"DBDIV off zop3=op1/nop2", 0, 1, 0},
	{191, ML_CODE_DBDIV, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_QWZ_on, verifyResultValueLWord,
			"DBDIV on zop3=op1/nop2", 0, 1, 0x123360800000045},
	{192, ML_CODE_DBDIV, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_QWZ_off, verifyResultValueLWord,
			"DBDIV off zop3=zop1/op2", 2, 1, 0},
	{193, ML_CODE_DBDIV, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_QWZ_on, verifyResultValueLWord,
			"DBDIV on zop3=zop1/op2", 2, 1, 0x123360800000045},
	{194, ML_CODE_DBDIV, setCodeOp3S_WZDBK_QWZ, setInputOp3_BCD8_WZDBK_QWZ_off, verifyResultValueLWord,
			"DBDIV off zop3=zop1/K", 2, 1, 0},
	{195, ML_CODE_DBDIV, setCodeOp3S_WZDBK_QWZ, setInputOp3_BCD8_WZDBK_QWZ_on, verifyResultValueLWord,
			"DBDIV on zop3=zop1/K", 2, 1, 0x123360800000045},
	{196, ML_CODE_DBDIV, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_QWZ_off, verifyResultValueLWord,
			"DBDIV off zop3=zop1/nop2", 2, 1, 0},
	{197, ML_CODE_DBDIV, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_QWZ_on, verifyResultValueLWord,
			"DBDIV on zop3=zop1/nop2", 2, 1, 0x123360800000045},
	{198, ML_CODE_DBDIV, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_QWZ_off, verifyResultValueLWord,
			"DBDIV off zop3=nop1/zop2", 2, 1, 0},
	{199, ML_CODE_DBDIV, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_QWZ_on, verifyResultValueLWord,
			"DBDIV on zop3=nop1/zop2", 2, 1, 0x123360800000045},
	{200, ML_CODE_DBDIV, setCodeOp3S_WZW_QN, setInputOp3_BCD8_DWZW_QWZ_off, verifyResultValueNibble16,
			"DBDIV off nop3=zop1/op2", 1, 1, 0},
	{201, ML_CODE_DBDIV, setCodeOp3S_WZW_QN, setInputOp3_BCD8_DWZW_QWZ_on, verifyResultValueNibble16,
			"DBDIV on nop3=zop1/op2", 1, 1, 0x123360800000045},
	{202, ML_CODE_DBDIV, setCodeOp3S_WZDBK_QN, setInputOp3_BCD8_WZDBK_QWZ_off, verifyResultValueNibble16,
			"DBDIV off nop3=zop1/K", 1, 1, 0},
	{203, ML_CODE_DBDIV, setCodeOp3S_WZDBK_QN, setInputOp3_BCD8_WZDBK_QWZ_on, verifyResultValueNibble16,
			"DBDIV on nop3=zop1/K", 1, 1, 0x123360800000045},
	{204, ML_CODE_DBDIV, setCodeOp3S_WZDN_QN, setInputOp3_BCD8_WZDN_QN_off, verifyResultValueNibble16,
			"DBDIV off nop3=zop1/nop2", 1, 1, 0},
	{205, ML_CODE_DBDIV, setCodeOp3S_WZDN_QN, setInputOp3_BCD8_WZDN_QN_on, verifyResultValueNibble16,
			"DBDIV on nop3=zop1/nop2", 1, 1, 0x123360800000045},
	{206, ML_CODE_DBDIV, setCodeOp3S_DNWZ_QN, setInputOp3_BCD8_DNWZ_QN_off, verifyResultValueNibble16,
			"DBDIV off nop3=nop1/zop2", 1, 1, 0},
	{207, ML_CODE_DBDIV, setCodeOp3S_DNWZ_QN, setInputOp3_BCD8_DNWZ_QN_on, verifyResultValueNibble16,
			"DBDIV on nop3=nop1/zop2", 1, 1, 0x123360800000045},
	{208, ML_CODE_DBDIV, setCodeOp3S_WZWZ_QN, setInputOp3_BCD8_DWZWZ_QN_off, verifyResultValueNibble16,
			"DBDIV off nop3=zop1/zop2", 1, 1, 0},
	{209, ML_CODE_DBDIV, setCodeOp3S_WZWZ_QN, setInputOp3_BCD8_DWZWZ_QN_on, verifyResultValueNibble16,
			"DBDIV on nop3=zop1/zop2", 1, 1, 0x123360800000045},

	{210, ML_CODE_DBDIVP, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_QWZ_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=op1/op2", 0, 2, 0},
	{211, ML_CODE_DBDIVP, setCodeOp3S_WW_WZ, setInputOp3_BCD8p_DWW_QWZ_on, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=op1/op2", 0, 2, 0x123360800000045},
	{212, ML_CODE_DBDIVP, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WQWZ_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=op1/op2", 0, 2, 0},
	{213, ML_CODE_DBDIVP, setCodeOp3S_W_WWZ, setInputOp3_BCD8p_DW_WQWZ_on, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=op1/op2", 0, 2, 0x123360800000045},
	{214, ML_CODE_DBDIVP, setCodeOp3S_DBKW_QWZ, setInputOp3_BCD8_DBKW_QWZ_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=K/op2", 0, 2, 0},
	{215, ML_CODE_DBDIVP, setCodeOp3S_DBKW_QWZ, setInputOp3_BCD8p_DBKW_QWZ_on, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=K/op2", 0, 2, 0x123360800000045},
	{216, ML_CODE_DBDIVP, setCodeOp3S_DBKK_QWZ, setInputOp2_none_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=K/K", 0, 2, 0},
	{217, ML_CODE_DBDIVP, setCodeOp3S_DBKK_QWZ, setInputOp2_none_tr1, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=K/K", 0, 2, 0x123360800000045},
	{218, ML_CODE_DBDIVP, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_QWZ_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=nop1/op2", 0, 2, 0},
	{219, ML_CODE_DBDIVP, setCodeOp3S_DNW_WZ, setInputOp3_BCD8p_DNW_QWZ_on, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=nop1/op2", 0, 2, 0x123360800000045},
	{220, ML_CODE_DBDIVP, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_QWZ_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=op1/nop2", 0, 2, 0},
	{221, ML_CODE_DBDIVP, setCodeOp3S_DWN_WZ, setInputOp3_BCD8p_WDN_QWZ_on, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=op1/nop2", 0, 2, 0x123360800000045},
	{222, ML_CODE_DBDIVP, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_QWZ_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=zop1/op2", 2, 2, 0},
	{223, ML_CODE_DBDIVP, setCodeOp3S_WZW_WZ, setInputOp3_BCD8p_DWZW_QWZ_on, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=zop1/op2", 2, 2, 0x123360800000045},
	{224, ML_CODE_DBDIVP, setCodeOp3S_WZDBK_QWZ, setInputOp3_BCD8_WZDBK_QWZ_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=zop1/K", 2, 2, 0},
	{225, ML_CODE_DBDIVP, setCodeOp3S_WZDBK_QWZ, setInputOp3_BCD8p_WZDBK_QWZ_on, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=zop1/K", 2, 2, 0x123360800000045},
	{226, ML_CODE_DBDIVP, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_QWZ_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=zop1/nop2", 2, 2, 0},
	{227, ML_CODE_DBDIVP, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8p_WZDN_QWZ_on, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=zop1/nop2", 2, 2, 0x123360800000045},
	{228, ML_CODE_DBDIVP, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_QWZ_off, verifyResultValueLWord,
			"DBDIVP 0->0 zop3=nop1/zop2", 2, 2, 0},
	{229, ML_CODE_DBDIVP, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8p_DNWZ_QWZ_on, verifyResultValueLWord,
			"DBDIVP 0->1 zop3=nop1/zop2", 2, 2, 0x123360800000045},
	{230, ML_CODE_DBDIVP, setCodeOp3S_WZW_QN, setInputOp3_BCD8_DWZW_QWZ_off, verifyResultValueNibble16,
			"DBDIVP 0->0 nop3=zop1/op2", 1, 2, 0},
	{231, ML_CODE_DBDIVP, setCodeOp3S_WZW_QN, setInputOp3_BCD8p_DWZW_QWZ_on, verifyResultValueNibble16,
			"DBDIVP 0->1 nop3=zop1/op2", 1, 2, 0x123360800000045},
	{232, ML_CODE_DBDIVP, setCodeOp3S_WZDBK_QN, setInputOp3_BCD8_WZDBK_QWZ_off, verifyResultValueNibble16,
			"DBDIVP 0->0 nop3=zop1/K", 1, 2, 0},
	{233, ML_CODE_DBDIVP, setCodeOp3S_WZDBK_QN, setInputOp3_BCD8p_WZDBK_QWZ_on, verifyResultValueNibble16,
			"DBDIVP 0->1 nop3=zop1/K", 1, 2, 0x123360800000045},
	{234, ML_CODE_DBDIVP, setCodeOp3S_WZDN_QN, setInputOp3_BCD8_WZDN_QN_off, verifyResultValueNibble16,
			"DBDIVP 0->0 nop3=zop1/nop2", 1, 2, 0},
	{235, ML_CODE_DBDIVP, setCodeOp3S_WZDN_QN, setInputOp3_BCD8p_WZDN_QN_on, verifyResultValueNibble16,
			"DBDIVP 0->1 nop3=zop1/nop2", 1, 2, 0x123360800000045},
	{236, ML_CODE_DBDIVP, setCodeOp3S_DNWZ_QN, setInputOp3_BCD8_DNWZ_QN_off, verifyResultValueNibble16,
			"DBDIVP 0->0 nop3=nop1/zop2", 1, 2, 0},
	{237, ML_CODE_DBDIVP, setCodeOp3S_DNWZ_QN, setInputOp3_BCD8p_DNWZ_QN_on, verifyResultValueNibble16,
			"DBDIVP 0->1 nop3=nop1/zop2", 1, 2, 0x123360800000045},
	{238, ML_CODE_DBDIVP, setCodeOp3S_WZWZ_QN, setInputOp3_BCD8_DWZWZ_QN_off, verifyResultValueNibble16,
			"DBDIVP 0->0 nop3=zop1/zop2", 1, 2, 0},
	{239, ML_CODE_DBDIVP, setCodeOp3S_WZWZ_QN, setInputOp3_BCD8p_DWZWZ_QN_on, verifyResultValueNibble16,
			"DBDIVP 0->1 nop3=zop1/zop2", 1, 2, 0x123360800000045},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0, 0 }
};


int total_basic_compute_dword_mul_idx_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_dword_mul_idx_test_number; i++)
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


int setCodeOp3S_WZW_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(in_reg, 160);
		addMLOperandNibble(16, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


int setCodeOp3S_WZDK_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=123456;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandNibble(16, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZDN_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandNibble(8, out_reg, 160);
		addMLOperandNibble(16, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DNWZ_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(in_pos == pos) return 0;
	if(isRangeOver(in_reg, 160, idx_val)) return 0;
	if(isRangeOver(out_reg, in_pos, 0)) return 0;
	if(isRangeOver(out_reg, pos, 0)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, out_reg, in_pos); addMLOperandZIndex(in_reg, 160, idx_pos);
		addMLOperandNibble(16, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZWZ_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(in_reg, 160, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandZIndex(in_reg, 160, idx_pos);
		addMLOperandNibble(16, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DBKW_QWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x56789123;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos + idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperand(in_reg, in_pos);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DBKK_QWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in1_val); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZDBK_QWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x1234567;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZDBK_QN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x1234567;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandNibble(16, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputOp3_BCD8_DWW_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DWW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DW_WQWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DW_WQWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DW_WQWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DBKW_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DBKW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DBKW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNW_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WDN_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_WDN_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_WDN_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWZW_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWZW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DWZW_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDBK_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDBK_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_WZDBK_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x56789123;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDN_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDN_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_WZDN_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNWZ_QWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNWZ_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNWZ_QWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDN_QN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDN_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_WZDN_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNWZ_QN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNWZ_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNWZ_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWZWZ_QN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWZWZ_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DWZWZ_QN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}


static uint16 getPos(int reg, int inx_pos)
{
	//uint16 pos[3][2]={ {0,0}, {6144,4096}, {12285,8189}}; // -2
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8128,8128,8128,8128,1984,8128,0,12284,8188}}; // 4 word

	return pos[inx_pos][reg];
}

static 	FILE *flog;
void test_basic_arithmetic_dword_mul_index(int tno, uint16 dummy)
{
	int i=1, inx=7, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	long long res_long;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_B; out<=OPERAND_ML_CODE_D; out++)
		{
			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_W; in++)
			{
				//if(in==out)
//					continue;
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					for(inx=0; inx<15; inx++) // testidx
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
									test_getNibble(&res_long, out, out_pos, 16);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d Z[%d]=%d\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
										reg[in], in_pos, reg[out], out_pos, res_long, testCase[tno].expected, testidx[inx].pos, testidx[inx].val);
								}
							}
							else // op2 is index or both are index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos+testidx[inx].val, testCase[tno].expected);
								if(rc == 1)
								{
									test_getLong(&res_long, out, out_pos+testidx[inx].val);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d Z[%d]=%d\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
										reg[in], in_pos, reg[out], out_pos, res_long, testCase[tno].expected, testidx[inx].pos, testidx[inx].val);
								}
							}
						}
					}
				}
			}
		}
	}
}

void testBasicArithmeticDWordMulIndexCommand(void)
{
	int i, index=181;
	int testSet[] = {143, 173, 203, 233};
	int testSize = 4;
	int start, end;
	char log[] = "err_arith_dwrd_mul_idx.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic dword mul index LOG file open error !\n");
		exit(1);
	}
#if 1
	//for(index=0;index<testSize;index++)
		//test_basic_arithmetic_dword_mul_index(testSet[index], 0);
	test_basic_arithmetic_dword_mul_index(90, 0);
	//for(i=0; i<230; i++)
	//	printf("testcase %d cmd=%s \n", i, PLC_OPERATOR_DICTIONARY_findOperator(testCase[i].ml_code)->strName);
#else
	total_basic_compute_dword_mul_idx_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DMLT); //ML_CODE_DMLT
	end = getTestCaseNumberEnd(ML_CODE_DBDIVP); //ML_CODE_DBDIVP

	DBG_LOGPRINT("testBasicArithmeticMultiDWordIndexCommand: %d to %d total %d\n", start, end, total_basic_compute_dword_mul_idx_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_dword_mul_index(index, 0);
	}
#endif
	fclose(flog);
}

#endif

