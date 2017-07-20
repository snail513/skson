/*
 * test_basic_conversion_dword_index.c
 *
 *  Created on: Aug 28, 2015
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


extern int setCodeOp2_W_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_K101_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_K9999_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_N_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_DN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp2_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected);
extern int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected);


int setCodeOp2_DK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_maxDK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_DBK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_maxDBK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_maxEK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_minEK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_upEK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_maxintK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_minintK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_GDK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_IGDK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_10101_DW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_10101_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_10101_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_99999999_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_99999999_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DN10_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DN10_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DN10_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DN99_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DN99_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_WZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_B10101_DW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_B10101_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_B10101_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_B99999999_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_B99999999_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DBN10_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DBN10_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DBN10_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DBN99_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_DBN99_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BWZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BWZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BWZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_float_DW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_maxfloat_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_maxfloat_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_dn_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_dn_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_up_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_up_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_DZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_DZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_DZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_dn_DZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_dn_DZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_up_DZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_float_up_DZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_257_W_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_257_W_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_257_W_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_maxint_W_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_maxint_W_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_257_N_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_257_N_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_257_N_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_maxint_N_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_maxint_N_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_257_WZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_257_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_257_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_maxint_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_maxint_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_GDW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_GDW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_GDW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_GDN1_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_GDN1_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_GDN1_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_GWZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_GWZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_GWZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_IGDW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_IGDW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_IGDW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_IGDN1_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_IGDN1_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_IGDN1_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_IGWZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_IGWZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_IGWZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

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

//z_type=0 : op2 is index
//z_type=1 : op1 is index op2 is W
//z_type=2 : op1, op2 is index
//z_type=3 : op1 is index op2 is nibble
typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16, uint16, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16, uint16, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, int);
	char str[30];
	//int count;
	int z_type; // 0 : op2 is index, 1: op1 is index
	int run_step;
	int expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_DTOBCD, setCodeOp2_W_WZ, setInputSIn_10101_DW_WZ_off, verifyResultValueDWord,
			"DTOBCD off", 0, 1, 0},
	{1, ML_CODE_DTOBCD, setCodeOp2_W_WZ, setInputSIn_10101_DW_WZ_on, verifyResultValueDWord,
			"DTOBCD on 10101", 0, 1, 0x10101},
	{2, ML_CODE_DTOBCD, setCodeOp2_W_WZ, setInputSIn_99999999_DW_WZ_on, verifyResultValueDWord,
			"DTOBCD on 99999999", 0, 1, 0x99999999},
	{3, ML_CODE_DTOBCD, setCodeOp2_DK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"DTOBCD off K10101", 0, 1, 0},
	{4, ML_CODE_DTOBCD, setCodeOp2_DK1_WZ2, setInputOp2_none_on, verifyResultValueDWord,
			"DTOBCD on K10101", 0, 1, 0x10101},
	{5, ML_CODE_DTOBCD, setCodeOp2_maxDK1_WZ2, setInputOp2_none_on, verifyResultValueDWord,
			"DTOBCD on K99999999", 0, 1, 0x99999999},
	{6, ML_CODE_DTOBCD, setCodeOp2_DN_WZ, setInputSIn_DN10_WZ_off, verifyResultValueDWord,
			"DTOBCD off N10101", 0, 1, 0},
	{7, ML_CODE_DTOBCD, setCodeOp2_DN_WZ, setInputSIn_DN10_WZ_on, verifyResultValueDWord,
			"DTOBCD on N10101", 0, 1, 0x10101},
	{8, ML_CODE_DTOBCD, setCodeOp2_DN_WZ, setInputSIn_DN99_WZ_on, verifyResultValueDWord,
			"BTOBCD on N99999999", 0, 1, 0x99999999},
	{9, ML_CODE_DTOBCD, setCodeOp2_WZ_W, setInputOp2_WZ_W_off, verifyResultValueDWord,
			"DTOBCD off DWZ10101", 1, 1, 0},
	{10, ML_CODE_DTOBCD, setCodeOp2_WZ_W, setInputOp2_WZ_W_on, verifyResultValueDWord,
			"DTOBCD on DWZ10101", 1, 1, 0x10101},
	{11, ML_CODE_DTOBCD, setCodeOp2_WZ_DN, setInputOp2_WZ_W_off, verifyResultValueNibble8,
			"DTOBCD off DWZ10101", 3, 1, 0},
	{12, ML_CODE_DTOBCD, setCodeOp2_WZ_DN, setInputOp2_WZ_W_on, verifyResultValueNibble8,
			"DTOBCD on DWZ10101", 3, 1, 0x10101},
	{13, ML_CODE_DTOBCD, setCodeOp2_WZ_WZ, setInputOp2_WZ_W_off, verifyResultValueDWord,
			"DTOBCD off DWZ10101", 2, 1, 0},
	{14, ML_CODE_DTOBCD, setCodeOp2_WZ_WZ, setInputOp2_WZ_W_on, verifyResultValueDWord,
			"DTOBCD on DWZ10101", 2, 1, 0x10101},

	{15, ML_CODE_DTOBCDP, setCodeOp2_W_WZ, setInputSIn_10101_DW_WZ_off, verifyResultValueDWord,
			"DTOBCDP 0->0", 0, 2, 0},
	{16, ML_CODE_DTOBCDP, setCodeOp2_W_WZ, setInputSIn_10101_DW_WZ_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 10101", 0, 2, 0x10101},
	{17, ML_CODE_DTOBCDP, setCodeOp2_W_WZ, setInputSIn_99999999_DW_WZ_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 99999999", 0, 2, 0x99999999},
	{18, ML_CODE_DTOBCDP, setCodeOp2_DK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"DTOBCDP 0->0 K10101", 0, 2, 0},
	{19, ML_CODE_DTOBCDP, setCodeOp2_DK1_WZ2, setInputOp2_none_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 K10101", 0, 2, 0x10101},
	{20, ML_CODE_DTOBCDP, setCodeOp2_maxDK1_WZ2, setInputOp2_none_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 K99999999", 0, 2, 0x99999999},
	{21, ML_CODE_DTOBCDP, setCodeOp2_DN_WZ, setInputSIn_DN10_WZ_off, verifyResultValueDWord,
			"DTOBCDP 0->0 N10101", 0, 2, 0},
	{22, ML_CODE_DTOBCDP, setCodeOp2_DN_WZ, setInputSIn_DN10_WZ_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 N10101", 0, 2, 0x10101},
	{23, ML_CODE_DTOBCDP, setCodeOp2_DN_WZ, setInputSIn_DN99_WZ_tr1, verifyResultValueDWord,
			"BTOBCD 0->1 N99999999", 0, 2, 0x99999999},
	{24, ML_CODE_DTOBCDP, setCodeOp2_WZ_W, setInputOp2_WZ_W_off, verifyResultValueDWord,
			"DTOBCDP 0->0 DWZ10101", 1, 2, 0},
	{25, ML_CODE_DTOBCDP, setCodeOp2_WZ_W, setInputOp2_WZ_W_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 DWZ10101", 1, 2, 0x10101},
	{26, ML_CODE_DTOBCDP, setCodeOp2_WZ_DN, setInputOp2_WZ_W_off, verifyResultValueNibble8,
			"DTOBCDP 0->0 DWZ10101", 3, 2, 0},
	{27, ML_CODE_DTOBCDP, setCodeOp2_WZ_DN, setInputOp2_WZ_W_tr1, verifyResultValueNibble8,
			"DTOBCDP 0->1 DWZ10101", 3, 2, 0x10101},
	{28, ML_CODE_DTOBCDP, setCodeOp2_WZ_WZ, setInputOp2_WZ_W_off, verifyResultValueDWord,
			"DTOBCDP 0->0 DWZ10101", 2, 2, 0},
	{29, ML_CODE_DTOBCDP, setCodeOp2_WZ_WZ, setInputOp2_WZ_W_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 DWZ10101", 2, 2, 0x10101},

	{30, ML_CODE_BCDTOD, setCodeOp2_W_WZ, setInputSIn_B10101_DW_WZ_off, verifyResultValueDWord,
			"BCDTOD off", 0, 1, 0},
	{31, ML_CODE_BCDTOD, setCodeOp2_W_WZ, setInputSIn_B10101_DW_WZ_on, verifyResultValueDWord,
			"BCDTOD on 0x10101", 0, 1, 10101},
	{32, ML_CODE_BCDTOD, setCodeOp2_W_WZ, setInputSIn_B99999999_DW_WZ_on, verifyResultValueDWord,
			"BCDTOD on 0x99999999", 0, 1, 99999999},
	{33, ML_CODE_BCDTOD, setCodeOp2_DBK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"BCDTOD off K0x10101", 0, 1, 0},
	{34, ML_CODE_BCDTOD, setCodeOp2_DBK1_WZ2, setInputOp2_none_on, verifyResultValueDWord,
			"BCDTOD on K0x10101", 0, 1, 10101},
	{35, ML_CODE_BCDTOD, setCodeOp2_maxDBK1_WZ2, setInputOp2_none_on, verifyResultValueDWord,
			"BCDTOD on K0x99999999", 0, 1, 99999999},
	{36, ML_CODE_BCDTOD, setCodeOp2_DN_WZ, setInputSIn_DBN10_WZ_off, verifyResultValueDWord,
			"BCDTOD off N0x10101", 0, 1, 0},
	{37, ML_CODE_BCDTOD, setCodeOp2_DN_WZ, setInputSIn_DBN10_WZ_on, verifyResultValueDWord,
			"BCDTOD on N0x10101", 0, 1, 10101},
	{38, ML_CODE_BCDTOD, setCodeOp2_DN_WZ, setInputSIn_DBN99_WZ_on, verifyResultValueDWord,
			"BTOBCD on N0x99999999", 0, 1, 99999999},
	{39, ML_CODE_BCDTOD, setCodeOp2_WZ_W, setInputOp2_BWZ_W_off, verifyResultValueDWord,
			"BCDTOD off DWZ0x10101", 1, 1, 0},
	{40, ML_CODE_BCDTOD, setCodeOp2_WZ_W, setInputOp2_BWZ_W_on, verifyResultValueDWord,
			"BCDTOD on DWZ0x10101", 1, 1, 10101},
	{41, ML_CODE_BCDTOD, setCodeOp2_WZ_DN, setInputOp2_BWZ_W_off, verifyResultValueNibble8,
			"BCDTOD off DWZ0x10101", 3, 1, 0},
	{42, ML_CODE_BCDTOD, setCodeOp2_WZ_DN, setInputOp2_BWZ_W_on, verifyResultValueNibble8,
			"BCDTOD on DWZ0x10101", 3, 1, 10101},
	{43, ML_CODE_BCDTOD, setCodeOp2_WZ_WZ, setInputOp2_BWZ_W_off, verifyResultValueDWord,
			"BCDTOD off DWZ0x10101", 2, 1, 0},
	{44, ML_CODE_BCDTOD, setCodeOp2_WZ_WZ, setInputOp2_BWZ_W_on, verifyResultValueDWord,
			"BCDTOD on DWZ0x10101", 2, 1, 10101},

	{45, ML_CODE_BCDTODP, setCodeOp2_W_WZ, setInputSIn_B10101_DW_WZ_off, verifyResultValueDWord,
			"BCDTODP 0->0", 0, 2, 0},
	{46, ML_CODE_BCDTODP, setCodeOp2_W_WZ, setInputSIn_B10101_DW_WZ_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 0x10101", 0, 2, 10101},
	{47, ML_CODE_BCDTODP, setCodeOp2_W_WZ, setInputSIn_B99999999_DW_WZ_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 0x99999999", 0, 2, 99999999},
	{48, ML_CODE_BCDTODP, setCodeOp2_DBK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"BCDTODP 0->0 K0x10101", 0, 2, 0},
	{49, ML_CODE_BCDTODP, setCodeOp2_DBK1_WZ2, setInputOp2_none_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 K0x10101", 0, 2, 10101},
	{50, ML_CODE_BCDTODP, setCodeOp2_maxDBK1_WZ2, setInputOp2_none_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 K0x99999999", 0, 2, 99999999},
	{51, ML_CODE_BCDTODP, setCodeOp2_DN_WZ, setInputSIn_DBN10_WZ_off, verifyResultValueDWord,
			"BCDTODP 0->0 N0x10101", 0, 2, 0},
	{52, ML_CODE_BCDTODP, setCodeOp2_DN_WZ, setInputSIn_DBN10_WZ_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 N0x10101", 0, 2, 10101},
	{53, ML_CODE_BCDTODP, setCodeOp2_DN_WZ, setInputSIn_DBN99_WZ_tr1, verifyResultValueDWord,
			"BTOBCD 0->1 N0x99999999", 0, 2, 99999999},
	{54, ML_CODE_BCDTODP, setCodeOp2_WZ_W, setInputOp2_BWZ_W_off, verifyResultValueDWord,
			"BCDTODP 0->0 DWZ0x10101", 1, 2, 0},
	{55, ML_CODE_BCDTODP, setCodeOp2_WZ_W, setInputOp2_BWZ_W_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 DWZ0x10101", 1, 2, 10101},
	{56, ML_CODE_BCDTODP, setCodeOp2_WZ_DN, setInputOp2_BWZ_W_off, verifyResultValueNibble8,
			"BCDTODP 0->0 DWZ0x10101", 3, 2, 0},
	{57, ML_CODE_BCDTODP, setCodeOp2_WZ_DN, setInputOp2_BWZ_W_tr1, verifyResultValueNibble8,
			"BCDTODP 0->1 DWZ0x10101", 3, 2, 10101},
	{58, ML_CODE_BCDTODP, setCodeOp2_WZ_WZ, setInputOp2_BWZ_W_off, verifyResultValueDWord,
			"BCDTODP 0->0 DWZ0x10101", 2, 2, 0},
	{59, ML_CODE_BCDTODP, setCodeOp2_WZ_WZ, setInputOp2_BWZ_W_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 DWZ0x10101", 2, 2, 10101},

	{60, ML_CODE_FTOD, setCodeOp2_W_WZ, setInputSIn_float_DW_WZ_off, verifyResultValueDWord,
			"FTOD off", 0, 1, 0},
	{61, ML_CODE_FTOD, setCodeOp2_W_WZ, setInputSIn_float_DW_WZ_on, verifyResultValueDWord,
			"FTOD on 65536.0", 0, 1, 65536},
	{62, ML_CODE_FTOD, setCodeOp2_W_WZ, setInputSIn_maxfloat_DW_WZ_on, verifyResultValueDWord,
			"FTOD on 9999999.0", 0, 1, 9999999},
	{63, ML_CODE_FTOD, setCodeOp2_W_WZ, setInputSIn_float_dn_DW_WZ_on, verifyResultValueDWord,
			"FTOD on 101.4", 0, 1, 101},
	{64, ML_CODE_FTOD, setCodeOp2_W_WZ, setInputSIn_float_up_DW_WZ_on, verifyResultValueDWord,
			"FTOD on 101.5", 0, 1, 102},
	{65, ML_CODE_FTOD, setCodeOp2_maxEK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"FTOD off", 0, 1, 0},
	{66, ML_CODE_FTOD, setCodeOp2_maxEK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"FTOD on K9999999.0", 0, 1, 9999999},
	{67, ML_CODE_FTOD, setCodeOp2_minEK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"FTOD on K-9999999.0", 0, 1, -9999999},
	{68, ML_CODE_FTOD, setCodeOp2_upEK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"FTOD on K101.5", 0, 1, 102},
	{69, ML_CODE_FTOD, setCodeOp2_WZ_W, setInputSIn_float_DZ_W_off, verifyResultValueDWord,
			"FTOD off", 1, 1, 0},
	{70, ML_CODE_FTOD, setCodeOp2_WZ_W, setInputSIn_float_DZ_W_on, verifyResultValueDWord,
			"FTOD on WZ65536.0", 1, 1, 65536},
	{71, ML_CODE_FTOD, setCodeOp2_WZ_W, setInputSIn_float_dn_DZ_W_on, verifyResultValueDWord,
			"FTOD on WZ101.4", 1, 1, 101},
	{72, ML_CODE_FTOD, setCodeOp2_WZ_W, setInputSIn_float_up_DZ_W_on, verifyResultValueDWord,
			"FTOD on WZ101.5", 1, 1, 102},
	{73, ML_CODE_FTOD, setCodeOp2_WZ_DN, setInputSIn_float_DZ_W_off, verifyResultValueNibble8,
			"FTOD off", 3, 1, 0},
	{74, ML_CODE_FTOD, setCodeOp2_WZ_DN, setInputSIn_float_DZ_W_on, verifyResultValueNibble8,
			"FTOD on WZ65536.0", 3, 1, 65536},
	{75, ML_CODE_FTOD, setCodeOp2_WZ_DN, setInputSIn_float_dn_DZ_W_on, verifyResultValueNibble8,
			"FTOD on WZ101.4", 3, 1, 101},
	{76, ML_CODE_FTOD, setCodeOp2_WZ_DN, setInputSIn_float_up_DZ_W_on, verifyResultValueNibble8,
			"FTOD on WZ101.5", 3, 1, 102},
	{77, ML_CODE_FTOD, setCodeOp2_WZ_WZ, setInputSIn_float_DZ_W_off, verifyResultValueDWord,
			"FTOD off", 2, 1, 0},
	{78, ML_CODE_FTOD, setCodeOp2_WZ_WZ, setInputSIn_float_DZ_W_on, verifyResultValueDWord,
			"FTOD on WZ65536.0", 2, 1, 65536},
	{79, ML_CODE_FTOD, setCodeOp2_WZ_WZ, setInputSIn_float_dn_DZ_W_on, verifyResultValueDWord,
			"FTOD on WZ101.4", 2, 1, 101},
	{80, ML_CODE_FTOD, setCodeOp2_WZ_WZ, setInputSIn_float_up_DZ_W_on, verifyResultValueDWord,
			"FTOD on WZ101.5", 2, 1, 102},

	{81, ML_CODE_FTODP, setCodeOp2_W_WZ, setInputSIn_float_DW_WZ_off, verifyResultValueDWord,
			"FTODP 0->0", 0, 2, 0},
	{82, ML_CODE_FTODP, setCodeOp2_W_WZ, setInputSIn_float_DW_WZ_tr1, verifyResultValueDWord,
			"FTODP 0->1 65536.0", 0, 2, 65536},
	{83, ML_CODE_FTODP, setCodeOp2_W_WZ, setInputSIn_maxfloat_DW_WZ_tr1, verifyResultValueDWord,
			"FTODP 0->1 9999999.0", 0, 2, 9999999},
	{84, ML_CODE_FTODP, setCodeOp2_W_WZ, setInputSIn_float_dn_DW_WZ_tr1, verifyResultValueDWord,
			"FTODP 0->1 101.4", 0, 2, 101},
	{85, ML_CODE_FTODP, setCodeOp2_W_WZ, setInputSIn_float_up_DW_WZ_tr1, verifyResultValueDWord,
			"FTODP 0->1 101.5", 0, 2, 102},
	{86, ML_CODE_FTODP, setCodeOp2_maxEK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"FTODP 0->0", 0, 2, 0},
	{87, ML_CODE_FTODP, setCodeOp2_maxEK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"FTODP 0->1 K9999999.0", 0, 2, 9999999},
	{88, ML_CODE_FTODP, setCodeOp2_minEK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"FTODP 0->1 K-9999999.0", 0, 2, -9999999},
	{89, ML_CODE_FTODP, setCodeOp2_upEK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"FTODP 0->1 K101.5", 0, 2, 102},
	{90, ML_CODE_FTODP, setCodeOp2_WZ_W, setInputSIn_float_DZ_W_off, verifyResultValueDWord,
			"FTODP 0->0", 1, 2, 0},
	{91, ML_CODE_FTODP, setCodeOp2_WZ_W, setInputSIn_float_DZ_W_tr1, verifyResultValueDWord,
			"FTODP 0->1 WZ65536.0", 1, 2, 65536},
	{92, ML_CODE_FTODP, setCodeOp2_WZ_W, setInputSIn_float_dn_DZ_W_tr1, verifyResultValueDWord,
			"FTODP 0->1 WZ101.4", 1, 2, 101},
	{93, ML_CODE_FTODP, setCodeOp2_WZ_W, setInputSIn_float_up_DZ_W_tr1, verifyResultValueDWord,
			"FTODP 0->1 WZ101.5", 1, 2, 102},
	{94, ML_CODE_FTODP, setCodeOp2_WZ_DN, setInputSIn_float_DZ_W_off, verifyResultValueNibble8,
			"FTODP 0->0", 3, 2, 0},
	{95, ML_CODE_FTODP, setCodeOp2_WZ_DN, setInputSIn_float_DZ_W_tr1, verifyResultValueNibble8,
			"FTODP 0->1 WZ65536.0", 3, 2, 65536},
	{96, ML_CODE_FTODP, setCodeOp2_WZ_DN, setInputSIn_float_dn_DZ_W_tr1, verifyResultValueNibble8,
			"FTODP 0->1 WZ101.4", 3, 2, 101},
	{97, ML_CODE_FTODP, setCodeOp2_WZ_DN, setInputSIn_float_up_DZ_W_tr1, verifyResultValueNibble8,
			"FTODP 0->1 WZ101.5", 3, 2, 102},
	{98, ML_CODE_FTODP, setCodeOp2_WZ_WZ, setInputSIn_float_DZ_W_off, verifyResultValueDWord,
			"FTODP 0->0", 2, 2, 0},
	{99, ML_CODE_FTODP, setCodeOp2_WZ_WZ, setInputSIn_float_DZ_W_tr1, verifyResultValueDWord,
			"FTODP 0->1 WZ65536.0", 2, 2, 65536},
	{100, ML_CODE_FTODP, setCodeOp2_WZ_WZ, setInputSIn_float_dn_DZ_W_tr1, verifyResultValueDWord,
			"FTODP 0->1 WZ101.4", 2, 2, 101},
	{101, ML_CODE_FTODP, setCodeOp2_WZ_WZ, setInputSIn_float_up_DZ_W_tr1, verifyResultValueDWord,
			"FTODP 0->1 WZ101.5", 2, 2, 102},

	{102, ML_CODE_BTOD, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_off, verifyResultValueDWord,
			"BTOD off", 0, 1, 0},
	{103, ML_CODE_BTOD, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_on, verifyResultValueDWord,
			"BTOD on 257", 0, 1, 257},
	{104, ML_CODE_BTOD, setCodeOp2_W_WZ, setInputSIn_maxint_W_WZ_on, verifyResultValueDWord,
			"BTOD on 32767", 0, 1, 32767},
	{105, ML_CODE_BTOD, setCodeOp2_maxintK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"BTOD off", 0, 1, 0},
	{106, ML_CODE_BTOD, setCodeOp2_maxintK1_WZ2, setInputOp2_none_on, verifyResultValueDWord,
			"BTOD on K32767.0", 0, 1, 32767},
	{107, ML_CODE_BTOD, setCodeOp2_minintK1_WZ2, setInputOp2_none_on, verifyResultValueDWord,
			"BTOD on K-32768.0", 0, 1, -32768},
	{108, ML_CODE_BTOD, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_off, verifyResultValueDWord,
			"BTOD off", 0, 1, 0},
	{109, ML_CODE_BTOD, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_on, verifyResultValueDWord,
			"BTOD on N257", 0, 1, 257},
	{110, ML_CODE_BTOD, setCodeOp2_N_WZ, setInputSIn_maxint_N_WZ_on, verifyResultValueDWord,
			"BTOD on N32767", 0, 1, 32767},
	{111, ML_CODE_BTOD, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_off, verifyResultValueDWord,
			"BTOD off", 1, 1, 0},
	{112, ML_CODE_BTOD, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_on, verifyResultValueDWord,
			"BTOD on WZ257", 1, 1, 257},
	{113, ML_CODE_BTOD, setCodeOp2_WZ_W, setInputOp2_maxint_WZ_W_on, verifyResultValueDWord,
			"BTOD on WZ32767", 1, 1, 32767},
	{114, ML_CODE_BTOD, setCodeOp2_WZ_DN, setInputOp2_257_WZ_W_off, verifyResultValueNibble8,
			"BTOD off", 3, 1, 0},
	{115, ML_CODE_BTOD, setCodeOp2_WZ_DN, setInputOp2_257_WZ_W_on, verifyResultValueNibble8,
			"BTOD on WZ257", 3, 1, 257},
	{116, ML_CODE_BTOD, setCodeOp2_WZ_DN, setInputOp2_maxint_WZ_W_on, verifyResultValueNibble8,
			"BTOD on WZ32767", 3, 1, 32767},
	{117, ML_CODE_BTOD, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_off, verifyResultValueDWord,
			"BTOD off", 2, 1, 0},
	{118, ML_CODE_BTOD, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_on, verifyResultValueDWord,
			"BTOD on WZ257", 2, 1, 257},
	{119, ML_CODE_BTOD, setCodeOp2_WZ_WZ, setInputOp2_maxint_WZ_W_on, verifyResultValueDWord,
			"BTOD on WZN32767", 2, 1, 32767},

	{120, ML_CODE_BTODP, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_off, verifyResultValueDWord,
			"BTODP 0->0", 0, 2, 0},
	{121, ML_CODE_BTODP, setCodeOp2_W_WZ, setInputSIn_257_W_WZ_tr1, verifyResultValueDWord,
			"BTODP 0->1 257", 0, 2, 257},
	{122, ML_CODE_BTODP, setCodeOp2_W_WZ, setInputSIn_maxint_W_WZ_tr1, verifyResultValueDWord,
			"BTODP 0->1 32767", 0, 2, 32767},
	{123, ML_CODE_BTODP, setCodeOp2_maxintK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"BTODP 0->0", 0, 2, 0},
	{124, ML_CODE_BTODP, setCodeOp2_maxintK1_WZ2, setInputOp2_none_tr1, verifyResultValueDWord,
			"BTODP 0->1 K32767.0", 0, 2, 32767},
	{125, ML_CODE_BTODP, setCodeOp2_minintK1_WZ2, setInputOp2_none_tr1, verifyResultValueDWord,
			"BTODP 0->1 K-32768.0", 0, 2, -32768},
	{126, ML_CODE_BTODP, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_off, verifyResultValueDWord,
			"BTODP 0->0", 0, 2, 0},
	{127, ML_CODE_BTODP, setCodeOp2_N_WZ, setInputSIn_257_N_WZ_tr1, verifyResultValueDWord,
			"BTODP 0->1 N257", 0, 2, 257},
	{128, ML_CODE_BTODP, setCodeOp2_N_WZ, setInputSIn_maxint_N_WZ_tr1, verifyResultValueDWord,
			"BTODP 0->1 N32767", 0, 2, 32767},
	{129, ML_CODE_BTODP, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_off, verifyResultValueDWord,
			"BTODP 0->0", 1, 2, 0},
	{130, ML_CODE_BTODP, setCodeOp2_WZ_W, setInputOp2_257_WZ_W_tr1, verifyResultValueDWord,
			"BTODP 0->1 WZ257", 1, 2, 257},
	{131, ML_CODE_BTODP, setCodeOp2_WZ_W, setInputOp2_maxint_WZ_W_tr1, verifyResultValueDWord,
			"BTODP 0->1 WZ32767", 1, 2, 32767},
	{132, ML_CODE_BTODP, setCodeOp2_WZ_DN, setInputOp2_257_WZ_W_off, verifyResultValueNibble8,
			"BTODP 0->0", 3, 2, 0},
	{133, ML_CODE_BTODP, setCodeOp2_WZ_DN, setInputOp2_257_WZ_W_tr1, verifyResultValueNibble8,
			"BTODP 0->1 WZ257", 3, 2, 257},
	{134, ML_CODE_BTODP, setCodeOp2_WZ_DN, setInputOp2_maxint_WZ_W_tr1, verifyResultValueNibble8,
			"BTODP 0->1 WZ32767", 3, 2, 32767},
	{135, ML_CODE_BTODP, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_off, verifyResultValueDWord,
			"BTODP 0->0", 2, 2, 0},
	{136, ML_CODE_BTODP, setCodeOp2_WZ_WZ, setInputOp2_257_WZ_W_tr1, verifyResultValueDWord,
			"BTODP 0->1 WZ257", 2, 2, 257},
	{137, ML_CODE_BTODP, setCodeOp2_WZ_WZ, setInputOp2_maxint_WZ_W_tr1, verifyResultValueDWord,
			"BTODP 0->1 WZN32767", 2, 2, 32767},

	{138, ML_CODE_DTOGRY, setCodeOp2_W_WZ, setInputSIn_GDW_WZ_off, verifyResultValueDWord,
			"DTOGRY off 305419896", 0, 1, 0},
	{139, ML_CODE_DTOGRY, setCodeOp2_W_WZ, setInputSIn_GDW_WZ_on, verifyResultValueDWord,
			"DTOGRY on 305419896", 0, 1, 0x1B2E7D44},
	{140, ML_CODE_DTOGRY, setCodeOp2_GDK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"DTOGRY off K305419896", 0, 1, 0},
	{141, ML_CODE_DTOGRY, setCodeOp2_GDK1_WZ2, setInputOp2_none_on, verifyResultValueDWord,
			"DTOGRY on K305419896", 0, 1, 0x1B2E7D44},
	{142, ML_CODE_DTOGRY, setCodeOp2_DN_WZ, setInputSIn_GDN1_WZ_off, verifyResultValueDWord,
			"DTOGRY off N305419896", 0, 1, 0},
	{143, ML_CODE_DTOGRY, setCodeOp2_DN_WZ, setInputSIn_GDN1_WZ_on, verifyResultValueDWord,
			"DTOGRY on N305419896", 0, 1, 0x1B2E7D44},
	{144, ML_CODE_DTOGRY, setCodeOp2_WZ_W, setInputOp2_GWZ_W_off, verifyResultValueDWord,
			"DTOGRY off WZ305419896", 1, 1, 0},
	{145, ML_CODE_DTOGRY, setCodeOp2_WZ_W, setInputOp2_GWZ_W_on, verifyResultValueDWord,
			"DTOGRY on WZ305419896", 1, 1, 0x1B2E7D44},
	{146, ML_CODE_DTOGRY, setCodeOp2_WZ_DN, setInputOp2_GWZ_W_off, verifyResultValueNibble8,
			"DTOGRY off WZ305419896", 3, 1, 0},
	{147, ML_CODE_DTOGRY, setCodeOp2_WZ_DN, setInputOp2_GWZ_W_on, verifyResultValueNibble8,
			"DTOGRY on WZ305419896", 3, 1, 0x1B2E7D44},
	{148, ML_CODE_DTOGRY, setCodeOp2_WZ_WZ, setInputOp2_GWZ_W_off, verifyResultValueDWord,
			"DTOGRY off WZ305419896", 2, 1, 0},
	{149, ML_CODE_DTOGRY, setCodeOp2_WZ_WZ, setInputOp2_GWZ_W_on, verifyResultValueDWord,
			"DTOGRY on WZ305419896", 2, 1, 0x1B2E7D44},

	{150, ML_CODE_DTOGRYP, setCodeOp2_W_WZ, setInputSIn_GDW_WZ_off, verifyResultValueDWord,
			"DTOGRYP 0->0 305419896", 0, 2, 0},
	{151, ML_CODE_DTOGRYP, setCodeOp2_W_WZ, setInputSIn_GDW_WZ_tr1, verifyResultValueDWord,
			"DTOGRYP 0->1 305419896", 0, 2, 0x1B2E7D44},
	{152, ML_CODE_DTOGRYP, setCodeOp2_GDK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"DTOGRYP 0->0 K305419896", 0, 2, 0},
	{153, ML_CODE_DTOGRYP, setCodeOp2_GDK1_WZ2, setInputOp2_none_tr1, verifyResultValueDWord,
			"DTOGRYP 0->1 K305419896", 0, 2, 0x1B2E7D44},
	{154, ML_CODE_DTOGRYP, setCodeOp2_DN_WZ, setInputSIn_GDN1_WZ_off, verifyResultValueDWord,
			"DTOGRYP 0->0 N305419896", 0, 2, 0},
	{155, ML_CODE_DTOGRYP, setCodeOp2_DN_WZ, setInputSIn_GDN1_WZ_tr1, verifyResultValueDWord,
			"DTOGRYP 0->1 N305419896", 0, 2, 0x1B2E7D44},
	{156, ML_CODE_DTOGRYP, setCodeOp2_WZ_W, setInputOp2_GWZ_W_off, verifyResultValueDWord,
			"DTOGRYP 0->0 WZ305419896", 1, 2, 0},
	{157, ML_CODE_DTOGRYP, setCodeOp2_WZ_W, setInputOp2_GWZ_W_tr1, verifyResultValueDWord,
			"DTOGRYP 0->1 WZ305419896", 1, 2, 0x1B2E7D44},
	{158, ML_CODE_DTOGRYP, setCodeOp2_WZ_DN, setInputOp2_GWZ_W_off, verifyResultValueNibble8,
			"DTOGRYP 0->0 WZ305419896", 3, 2, 0},
	{159, ML_CODE_DTOGRYP, setCodeOp2_WZ_DN, setInputOp2_GWZ_W_tr1, verifyResultValueNibble8,
			"DTOGRYP 0->1 WZ305419896", 3, 2, 0x1B2E7D44},
	{160, ML_CODE_DTOGRYP, setCodeOp2_WZ_WZ, setInputOp2_GWZ_W_off, verifyResultValueDWord,
			"DTOGRYP 0->0 WZ305419896", 2, 2, 0},
	{161, ML_CODE_DTOGRYP, setCodeOp2_WZ_WZ, setInputOp2_GWZ_W_tr1, verifyResultValueDWord,
			"DTOGRYP 0->1 WZ305419896", 2, 2, 0x1B2E7D44},

	{162, ML_CODE_GRYTOD, setCodeOp2_W_WZ, setInputSIn_IGDW_WZ_off, verifyResultValueDWord,
			"GRYTOD off 0x1B2E7D44", 0, 1, 0},
	{163, ML_CODE_GRYTOD, setCodeOp2_W_WZ, setInputSIn_IGDW_WZ_on, verifyResultValueDWord,
			"GRYTOD on 0x1B2E7D44", 0, 1, 305419896},
	{164, ML_CODE_GRYTOD, setCodeOp2_IGDK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"GRYTOD off K0x1B2E7D44", 0, 1, 0},
	{165, ML_CODE_GRYTOD, setCodeOp2_IGDK1_WZ2, setInputOp2_none_on, verifyResultValueDWord,
			"GRYTOD on K0x1B2E7D44", 0, 1, 305419896},
	{166, ML_CODE_GRYTOD, setCodeOp2_DN_WZ, setInputSIn_IGDN1_WZ_off, verifyResultValueDWord,
			"GRYTOD off N0x1B2E7D44", 0, 1, 0},
	{167, ML_CODE_GRYTOD, setCodeOp2_DN_WZ, setInputSIn_IGDN1_WZ_on, verifyResultValueDWord,
			"GRYTOD on N0x1B2E7D44", 0, 1, 305419896},
	{168, ML_CODE_GRYTOD, setCodeOp2_WZ_W, setInputOp2_IGWZ_W_off, verifyResultValueDWord,
			"GRYTOD off WZ0x1B2E7D44", 1, 1, 0},
	{169, ML_CODE_GRYTOD, setCodeOp2_WZ_W, setInputOp2_IGWZ_W_on, verifyResultValueDWord,
			"GRYTOD on WZ0x1B2E7D44", 1, 1, 305419896},
	{170, ML_CODE_GRYTOD, setCodeOp2_WZ_DN, setInputOp2_IGWZ_W_off, verifyResultValueNibble8,
			"GRYTOD off WZ0x1B2E7D44", 3, 1, 0},
	{171, ML_CODE_GRYTOD, setCodeOp2_WZ_DN, setInputOp2_IGWZ_W_on, verifyResultValueNibble8,
			"GRYTOD on WZ0x1B2E7D44", 3, 1, 305419896},
	{172, ML_CODE_GRYTOD, setCodeOp2_WZ_WZ, setInputOp2_IGWZ_W_off, verifyResultValueDWord,
			"GRYTOD off WZ0x1B2E7D44", 2, 1, 0},
	{173, ML_CODE_GRYTOD, setCodeOp2_WZ_WZ, setInputOp2_IGWZ_W_on, verifyResultValueDWord,
			"GRYTOD on WZ0x1B2E7D44", 2, 1, 305419896},

	{174, ML_CODE_GRYTODP, setCodeOp2_W_WZ, setInputSIn_IGDW_WZ_off, verifyResultValueDWord,
			"GRYTODP 0->0 305419896", 0, 2, 0},
	{175, ML_CODE_GRYTODP, setCodeOp2_W_WZ, setInputSIn_IGDW_WZ_tr1, verifyResultValueDWord,
			"GRYTODP 0->1 305419896", 0, 2, 305419896},
	{176, ML_CODE_GRYTODP, setCodeOp2_IGDK1_WZ2, setInputOp2_none_off, verifyResultValueDWord,
			"GRYTODP 0->0 K305419896", 0, 2, 0},
	{177, ML_CODE_GRYTODP, setCodeOp2_IGDK1_WZ2, setInputOp2_none_tr1, verifyResultValueDWord,
			"GRYTODP 0->1 K305419896", 0, 2, 305419896},
	{178, ML_CODE_GRYTODP, setCodeOp2_DN_WZ, setInputSIn_IGDN1_WZ_off, verifyResultValueDWord,
			"GRYTODP 0->0 N305419896", 0, 2, 0},
	{179, ML_CODE_GRYTODP, setCodeOp2_DN_WZ, setInputSIn_IGDN1_WZ_tr1, verifyResultValueDWord,
			"GRYTODP 0->1 N305419896", 0, 2, 305419896},
	{180, ML_CODE_GRYTODP, setCodeOp2_WZ_W, setInputOp2_IGWZ_W_off, verifyResultValueDWord,
			"GRYTODP 0->0 WZ305419896", 1, 2, 0},
	{181, ML_CODE_GRYTODP, setCodeOp2_WZ_W, setInputOp2_IGWZ_W_tr1, verifyResultValueDWord,
			"GRYTODP 0->1 WZ305419896", 1, 2, 305419896},
	{182, ML_CODE_GRYTODP, setCodeOp2_WZ_DN, setInputOp2_IGWZ_W_off, verifyResultValueNibble8,
			"GRYTODP 0->0 WZ305419896", 3, 2, 0},
	{183, ML_CODE_GRYTODP, setCodeOp2_WZ_DN, setInputOp2_IGWZ_W_tr1, verifyResultValueNibble8,
			"GRYTODP 0->1 WZ305419896", 3, 2, 305419896},
	{184, ML_CODE_GRYTODP, setCodeOp2_WZ_WZ, setInputOp2_IGWZ_W_off, verifyResultValueDWord,
			"GRYTODP 0->0 WZ305419896", 2, 2, 0},
	{185, ML_CODE_GRYTODP, setCodeOp2_WZ_WZ, setInputOp2_IGWZ_W_tr1, verifyResultValueDWord,
			"GRYTODP 0->1 WZ305419896", 2, 2, 305419896},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};


int total_conversion_test_dwd_idx_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_conversion_test_dwd_idx_number; i++)
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

int setCodeOp2_DK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=10101;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxDK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=99999999;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_DBK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x10101;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxDBK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x99999999;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_WZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxEK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=9999999.0;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_minEK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=-9999999.0;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_upEK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val=101.5;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxintK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=32767;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_minintK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=-32768;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_GDK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=305419896;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_IGDK1_WZ2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1B2E7D44;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputSIn_10101_DW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_10101_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_10101_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_99999999_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_99999999_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_DN10_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_DN10_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_DN10_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_DN99_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_DN99_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_WZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=10101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=10101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=10101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_B10101_DW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_B10101_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_B10101_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_B99999999_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_B99999999_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_DBN10_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_DBN10_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_DBN10_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_DBN99_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_DBN99_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BWZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x10101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_BWZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x10101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_BWZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x10101;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_DW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 65536.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 65536.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 65536.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_maxfloat_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 9999999.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_maxfloat_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 9999999.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_dn_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 101.4;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_dn_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 101.4;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_up_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 101.5;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_up_DW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 101.5;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_DZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 65536.0;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_DZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 65536.0;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_DZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 65536.0;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_dn_DZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 101.4;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_dn_DZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 101.4;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_up_DZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 101.5;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_up_DZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	float in_val = 101.5;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_257_W_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_257_W_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_257_W_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_5555_W_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x5555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_5555_W_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x5555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_maxint_W_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_maxint_W_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_257_N_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_257_N_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_257_N_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}



void setInputSIn_maxint_N_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_maxint_N_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_257_WZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_257_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_257_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=257;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_maxint_WZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_maxint_WZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=32767;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_GDW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=305419896;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_GDW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=305419896;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_GDW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=305419896;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_GDN1_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=305419896;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_GDN1_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=305419896;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_GDN1_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=305419896;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_GWZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=305419896;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_GWZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=305419896;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_GWZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=305419896;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputSIn_IGDW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1B2E7D44;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_IGDW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1B2E7D44;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_IGDW_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1B2E7D44;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_IGDN1_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1B2E7D44;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_IGDN1_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1B2E7D44;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_IGDN1_WZ_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1B2E7D44;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_IGWZ_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1B2E7D44;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_IGWZ_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1B2E7D44;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_IGWZ_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1B2E7D44;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

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
void test_basic_conversion_dword_idx(int tno, uint16 dummy)
{
	int i=1, inx=7, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	int res_word;
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
										test_getDWord(&res_word, out, out_pos);
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d]=%d exp=%d\n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_word, testCase[tno].expected);
									}
									else
									{
										test_getNibble(&res_word, out, out_pos, 8);
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_N_%s[%d]=%d exp=%d\n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_word, testCase[tno].expected);
									}
								}
							}
							else // op2 is index or both are index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos+testidx[inx].val, testCase[tno].expected);
								if(rc == 1)
								{
									test_getDWord(&res_word, out, out_pos+testidx[inx].val);
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

void testConversionDWordIndexCommand(void)
{
	int i, index=62;
	int start, end;
	char log[] = "err_conv_dword_idx.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("conversion dword index LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
	test_basic_conversion_dword_idx(index, 0);

#else
	total_conversion_test_dwd_idx_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DTOBCD); //ML_CODE_DTOBCD
	end = getTestCaseNumberEnd(ML_CODE_GRYTODP); //ML_CODE_GRYTODP

	DBG_LOGPRINT("testConversionDWordIndexCommand: %d to %d total %d\n", start, end, total_conversion_test_dwd_idx_number);
	for(index=start; index<=end; index++)
	{
		test_basic_conversion_dword_idx(index, 0);
	}
#endif
	fclose(flog);
}
#endif
