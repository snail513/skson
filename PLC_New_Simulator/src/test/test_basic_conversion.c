/*
 * test_basic_conversion.c
 *
 *  Created on: Feb 23, 2015
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

int setCodeVal_W_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_K101(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_K9999(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_K101B(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_K9999B(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

int setCodeVal_F_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_E_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_nE_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_E_up_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

int setCodeVal_DK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_nDK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_DN_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

int setCodeVal_K1234_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_K06BB_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

void setInputSIn_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_101_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_101_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_0x101_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_0x101_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_9999_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_9999_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_0x9999_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_0x9999_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_val16_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val16_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val16_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_101_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_0x101_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_9999_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_0x9999_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_101_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_0x101_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_9999_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_normal_0x9999_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_conv_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_conv_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_conv_float_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_float_maxint_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_float_maxint_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_float_half_dn_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_float_half_dn_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_float_half_up_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_float_half_up_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_dword_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_dword_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_dword_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_dword_maxint_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_dword_maxint_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_val32_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_N_W_max_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_N_W_max_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_gray_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_inv_gray_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, short);
	char str[30];
	//int count;
	int run_step;
	int expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_BTOBCD, setCodeVal_W_W, setInputSIn_val16_off, verifyResultValueWord,
			"BTOBCD condition off", 1, 0},
	{1, ML_CODE_BTOBCD, setCodeVal_W_W, setInputSIn_normal_101_on, verifyResultValueWord,
			"BTOBCD on conv 101", 1, 0x101},
	{2, ML_CODE_BTOBCD, setCodeVal_W_W, setInputSIn_normal_9999_on, verifyResultValueWord,
			"BTOBCD on conv 9999", 1, 0x9999},
	{3, ML_CODE_BTOBCD, setCodeVal_K101, setInputSIn_none_off, verifyResultValueWord,
			"BTOBCD off K 101", 1, 0},
	{4, ML_CODE_BTOBCD, setCodeVal_K101, setInputSIn_none_on, verifyResultValueWord,
			"BTOBCD on conv K 101", 1, 0x101},
	{5, ML_CODE_BTOBCD, setCodeVal_K9999, setInputSIn_none_on, verifyResultValueWord,
			"BTOBCD on conv K 9999", 1, 0x9999},
	{6, ML_CODE_BTOBCD, setCodeVal_N_W, setInputSIn_val16_N_W_off, verifyResultValueWord,
			"BTOBCD nibble condition off", 1, 0},
	{7, ML_CODE_BTOBCD, setCodeVal_N_W, setInputSIn_normal_101_N_W_on, verifyResultValueWord,
			"BTOBCD on conv 101", 1, 0x101},
	{8, ML_CODE_BTOBCD, setCodeVal_N_W, setInputSIn_normal_9999_N_W_on, verifyResultValueWord,
			"BTOBCD on conv 9999", 1, 0x9999},

	{9, ML_CODE_BTOBCDP, setCodeVal_W_W, setInputSIn_val16_off, verifyResultValueWord,
			"BTOBCDP condition off", 2, 0},
	{10, ML_CODE_BTOBCDP, setCodeVal_W_W, setInputSIn_normal_101_on, verifyResultValueWord,
			"BTOBCDP on conv 101", 2, 0},
	{11, ML_CODE_BTOBCDP, setCodeVal_W_W, setInputSIn_normal_101_tr1, verifyResultValueWord,
			"BTOBCDP on conv 101", 2, 0x101},
	{12, ML_CODE_BTOBCDP, setCodeVal_W_W, setInputSIn_normal_9999_tr1, verifyResultValueWord,
			"BTOBCDP on conv 9999", 2, 0x9999},
	{13, ML_CODE_BTOBCDP, setCodeVal_K101, setInputSIn_none_off, verifyResultValueWord,
			"BTOBCDP 0->0 K 101", 2, 0},
	{14, ML_CODE_BTOBCDP, setCodeVal_K101, setInputSIn_none_on, verifyResultValueWord,
			"BTOBCDP 1->1 K 101", 2, 0},
	{15, ML_CODE_BTOBCDP, setCodeVal_K101, setInputSIn_none_tr1, verifyResultValueWord,
			"BTOBCDP 0->1 conv K 101", 2, 0x101},
	{16, ML_CODE_BTOBCDP, setCodeVal_K9999, setInputSIn_none_tr1, verifyResultValueWord,
			"BTOBCDP 0->1 conv K 9999", 2, 0x9999},
	{17, ML_CODE_BTOBCDP, setCodeVal_N_W, setInputSIn_val16_N_W_off, verifyResultValueWord,
			"BTOBCDP nb condition 0->0", 2, 0},
	{18, ML_CODE_BTOBCDP, setCodeVal_N_W, setInputSIn_val16_N_W_on, verifyResultValueWord,
			"BTOBCDP nb condition 1->1", 2, 0},
	{19, ML_CODE_BTOBCDP, setCodeVal_N_W, setInputSIn_normal_101_N_W_tr1, verifyResultValueWord,
			"BTOBCDP 0->1 conv 101", 2, 0x101},
	{20, ML_CODE_BTOBCDP, setCodeVal_N_W, setInputSIn_normal_9999_N_W_tr1, verifyResultValueWord,
			"BTOBCDP 0->1 conv 9999", 2, 0x9999},

	{21, ML_CODE_BCDTOB, setCodeVal_W_W, setInputSIn_val16_off, verifyResultValueWord,
			"BCDTOB condition off", 1, 0},
	{22, ML_CODE_BCDTOB, setCodeVal_W_W, setInputSIn_normal_0x101_on, verifyResultValueWord,
			"BCDTOB on K BCD101", 1, 101},
	{23, ML_CODE_BCDTOB, setCodeVal_W_W, setInputSIn_normal_0x9999_on, verifyResultValueWord,
			"BCDTOB on K BCD9999", 1, 9999},
	{24, ML_CODE_BCDTOB, setCodeVal_K101B, setInputSIn_none_off, verifyResultValueWord,
			"BCDTOB off K BCD101", 1, 0},
	{25, ML_CODE_BCDTOB, setCodeVal_K101B, setInputSIn_none_on, verifyResultValueWord,
			"BCDTOB on conv K BCD101", 1, 101},
	{26, ML_CODE_BCDTOB, setCodeVal_K9999B, setInputSIn_none_on, verifyResultValueWord,
			"BCDTOB on conv K BCD9999", 1, 9999},
	{27, ML_CODE_BCDTOB, setCodeVal_N_W, setInputSIn_val16_N_W_off, verifyResultValueWord,
			"BCDTOB nb condition off", 1, 0},
	{28, ML_CODE_BCDTOB, setCodeVal_N_W, setInputSIn_normal_0x101_N_W_on, verifyResultValueWord,
			"BCDTOB on conv 101", 1, 101},
	{29, ML_CODE_BCDTOB, setCodeVal_N_W, setInputSIn_normal_0x9999_N_W_on, verifyResultValueWord,
			"BCDTOB on conv 9999", 1, 9999},

	{30, ML_CODE_BCDTOBP, setCodeVal_W_W, setInputSIn_val16_off, verifyResultValueWord,
			"BCDTOBP condition 0->0", 2, 0},
	{31, ML_CODE_BCDTOBP, setCodeVal_W_W, setInputSIn_normal_0x101_on, verifyResultValueWord,
			"BCDTOBP 1->1 conv BCD101", 2, 0},
	{32, ML_CODE_BCDTOBP, setCodeVal_W_W, setInputSIn_normal_0x101_tr1, verifyResultValueWord,
			"BCDTOBP 0->1 conv BCD101", 2, 101},
	{33, ML_CODE_BCDTOBP, setCodeVal_W_W, setInputSIn_normal_0x9999_tr1, verifyResultValueWord,
			"BCDTOBP 0->1 conv BCD9999", 2, 9999},
	{34, ML_CODE_BCDTOBP, setCodeVal_K101B, setInputSIn_none_off, verifyResultValueWord,
			"BCDTOBP 1->1 K BCD101", 2, 0},
	{35, ML_CODE_BCDTOBP, setCodeVal_K101B, setInputSIn_none_on, verifyResultValueWord,
			"BCDTOBP 1->1 conv K BCD101", 2, 0},
	{36, ML_CODE_BCDTOBP, setCodeVal_K101B, setInputSIn_none_tr1, verifyResultValueWord,
			"BCDTOBP 0->1 conv K BCD101", 2, 101},
	{37, ML_CODE_BCDTOBP, setCodeVal_K9999B, setInputSIn_none_tr1, verifyResultValueWord,
			"BCDTOBP 0->1 conv K BCD9999", 2, 9999},
	{38, ML_CODE_BCDTOBP, setCodeVal_N_W, setInputSIn_val16_N_W_off, verifyResultValueWord,
			"BCDTOBP nb condition 0->0", 2, 0},
	{39, ML_CODE_BCDTOBP, setCodeVal_N_W, setInputSIn_val16_N_W_on, verifyResultValueWord,
			"BCDTOBP nb condition 1->1", 2, 0},
	{40, ML_CODE_BCDTOBP, setCodeVal_N_W, setInputSIn_normal_0x101_N_W_tr1, verifyResultValueWord,
			"BCDTOBP 0->1 conv nb 101", 2, 101},
	{41, ML_CODE_BCDTOBP, setCodeVal_N_W, setInputSIn_normal_0x9999_N_W_tr1, verifyResultValueWord,
			"BCDTOBP 0->1 conv nb 9999", 2, 9999},

	{42, ML_CODE_FTOB, setCodeVal_F_W, setInputSIn_conv_float_off, verifyResultValueWord,
			"FTOB condition off", 1, 0},
	{43, ML_CODE_FTOB, setCodeVal_F_W, setInputSIn_conv_float_on, verifyResultValueWord,
			"FTOB on conv 257.0", 1, 257},
	{44, ML_CODE_FTOB, setCodeVal_F_W, setInputSIn_float_maxint_on, verifyResultValueWord,
			"FTOB on conv 32767.0", 1, 32767},
	{45, ML_CODE_FTOB, setCodeVal_F_W, setInputSIn_float_half_dn_on, verifyResultValueWord,
			"FTOB on conv 101.4", 1, 101},
	{46, ML_CODE_FTOB, setCodeVal_F_W, setInputSIn_float_half_up_on, verifyResultValueWord,
			"FTOB on conv 101.5", 1, 102},
	{47, ML_CODE_FTOB, setCodeVal_E_W, setInputSIn_none_off, verifyResultValueWord,
			"FTOB condition off", 1, 0},
	{48, ML_CODE_FTOB, setCodeVal_E_W, setInputSIn_none_on, verifyResultValueWord,
			"FTOB on conv 32767.0", 1, 32767},
	{49, ML_CODE_FTOB, setCodeVal_nE_W, setInputSIn_none_on, verifyResultValueWord,
			"FTOB on conv -32768.0", 1, -32768},
	{50, ML_CODE_FTOB, setCodeVal_E_up_W, setInputSIn_none_on, verifyResultValueWord,
			"FTOB on conv 101.5", 1, 102},

	{51, ML_CODE_FTOBP, setCodeVal_F_W, setInputSIn_conv_float_off, verifyResultValueWord,
			"FTOBP condition 0->0", 2, 0},
	{52, ML_CODE_FTOBP, setCodeVal_F_W, setInputSIn_conv_float_on, verifyResultValueWord,
			"FTOBP 1->1 conv 257.0", 2, 0},
	{53, ML_CODE_FTOBP, setCodeVal_F_W, setInputSIn_conv_float_tr1, verifyResultValueWord,
			"FTOBP 0->1 conv 257.0", 2, 257},
	{54, ML_CODE_FTOBP, setCodeVal_F_W, setInputSIn_float_maxint_tr1, verifyResultValueWord,
			"FTOBP 0->1 conv 32767.0", 2, 32767},
	{55, ML_CODE_FTOBP, setCodeVal_F_W, setInputSIn_float_half_dn_tr1, verifyResultValueWord,
			"FTOBP on conv 101.4", 2, 101},
	{56, ML_CODE_FTOBP, setCodeVal_F_W, setInputSIn_float_half_up_tr1, verifyResultValueWord,
			"FTOBP on conv 101.5", 2, 102},
	{57, ML_CODE_FTOBP, setCodeVal_E_W, setInputSIn_none_off, verifyResultValueWord,
			"FTOBP condition 0->0", 2, 0},
	{58, ML_CODE_FTOBP, setCodeVal_E_W, setInputSIn_none_on, verifyResultValueWord,
			"FTOBP conv 1->1", 2, 0},
	{59, ML_CODE_FTOBP, setCodeVal_E_W, setInputSIn_none_tr1, verifyResultValueWord,
			"FTOBP conv 0-> 1 32767.0", 2, 32767},
	{60, ML_CODE_FTOBP, setCodeVal_nE_W, setInputSIn_none_tr1, verifyResultValueWord,
			"FTOBP 0->1 conv -32768.0", 2, -32768},
	{61, ML_CODE_FTOBP, setCodeVal_E_up_W, setInputSIn_none_tr1, verifyResultValueWord,
			"FTOBP 0->1 conv 101.5", 2, 102},

	{62, ML_CODE_DTOB, setCodeVal_W_W, setInputSIn_dword_off, verifyResultValueWord,
			"DTOB condition off", 1, 0},
	{63, ML_CODE_DTOB, setCodeVal_W_W, setInputSIn_dword_on, verifyResultValueWord,
			"DTOB on conv 257", 1, 257},
	{64, ML_CODE_DTOB, setCodeVal_W_W, setInputSIn_dword_maxint_on, verifyResultValueWord,
			"DTOB on conv 32767", 1, 32767},
	{65, ML_CODE_DTOB, setCodeVal_DK_W, setInputSIn_none_off, verifyResultValueWord,
			"DTOB condition off", 1, 0},
	{66, ML_CODE_DTOB, setCodeVal_DK_W, setInputSIn_none_on, verifyResultValueWord,
			"DTOB on conv 32767.0", 1, 32767},
	{67, ML_CODE_DTOB, setCodeVal_nDK_W, setInputSIn_none_on, verifyResultValueWord,
			"DTOB on conv -32768.0", 1, -32768},
	{68, ML_CODE_DTOB, setCodeVal_DN_W, setInputSIn_val32_N_W_off, verifyResultValueWord,
			"DTOB condition off", 1, 0},
	{69, ML_CODE_DTOB, setCodeVal_DN_W, setInputSIn_val32_N_W_on, verifyResultValueWord,
			"DTOB on conv nb 257", 1, 257},
	{70, ML_CODE_DTOB, setCodeVal_DN_W, setInputSIn_val32_N_W_max_on, verifyResultValueWord,
			"DTOB on conv nb 32767", 1, 32767},

	{71, ML_CODE_DTOBP, setCodeVal_W_W, setInputSIn_dword_off, verifyResultValueWord,
			"DTOBP condition 0->0", 2, 0},
	{72, ML_CODE_DTOBP, setCodeVal_W_W, setInputSIn_dword_on, verifyResultValueWord,
			"DTOBP 1->1 conv 257", 2, 0},
	{73, ML_CODE_DTOBP, setCodeVal_W_W, setInputSIn_dword_tr1, verifyResultValueWord,
			"DTOBP 0->1 conv 257", 2, 257},
	{74, ML_CODE_DTOBP, setCodeVal_W_W, setInputSIn_dword_maxint_tr1, verifyResultValueWord,
			"DTOBP 0->1 conv 32767", 2, 32767},
	{75, ML_CODE_DTOBP, setCodeVal_DK_W, setInputSIn_none_off, verifyResultValueWord,
			"DTOBP condition 0->0", 2, 0},
	{76, ML_CODE_DTOBP, setCodeVal_DK_W, setInputSIn_none_on, verifyResultValueWord,
			"DTOBP 1->1 conv 32767.0", 2, 0},
	{77, ML_CODE_DTOBP, setCodeVal_DK_W, setInputSIn_none_tr1, verifyResultValueWord,
			"DTOBP 0->1 conv 32767.0", 2, 32767},
	{78, ML_CODE_DTOBP, setCodeVal_nDK_W, setInputSIn_none_tr1, verifyResultValueWord,
			"DTOBP 0->1 conv -32768.0", 2, -32768},
	{79, ML_CODE_DTOBP, setCodeVal_DN_W, setInputSIn_val32_N_W_off, verifyResultValueWord,
			"DTOBP condition 0->0", 2, 0},
	{80, ML_CODE_DTOBP, setCodeVal_DN_W, setInputSIn_val32_N_W_on, verifyResultValueWord,
			"DTOBP 1->1 conv nb 257", 2, 0},
	{81, ML_CODE_DTOBP, setCodeVal_DN_W, setInputSIn_val32_N_W_tr1, verifyResultValueWord,
			"DTOBP 0->1 conv nb 257", 2, 257},
	{82, ML_CODE_DTOBP, setCodeVal_DN_W, setInputSIn_val32_N_W_max_tr1, verifyResultValueWord,
			"DTOBP 0->1 conv nb 32767", 2, 32767},

	{83, ML_CODE_BTOGRY, setCodeVal_W_W, setInputSIn_gray_off, verifyResultValueWord,
			"BTOGRY condition off", 1, 0},
	{84, ML_CODE_BTOGRY, setCodeVal_W_W, setInputSIn_gray_on, verifyResultValueWord,
			"BTOGRY on conv 1234", 1, 0x06BB},
	{85, ML_CODE_BTOGRY, setCodeVal_K1234_W, setInputSIn_none_off, verifyResultValueWord,
			"BTOGRY conv K off", 1, 0},
	{86, ML_CODE_BTOGRY, setCodeVal_K1234_W, setInputSIn_none_on, verifyResultValueWord,
			"BTOGRY condition K on", 1, 0x06BB},
	{87, ML_CODE_BTOGRY, setCodeVal_N_W, setInputSIn_gray_N_W_off, verifyResultValueWord,
			"BTOGRY conv nb off", 1, 0},
	{88, ML_CODE_BTOGRY, setCodeVal_N_W, setInputSIn_gray_N_W_on, verifyResultValueWord,
			"BTOGRY conv nb on", 1, 0x06BB},

	{89, ML_CODE_BTOGRYP, setCodeVal_W_W, setInputSIn_gray_off, verifyResultValueWord,
			"BTOGRYP condition 0->0", 2, 0},
	{90, ML_CODE_BTOGRYP, setCodeVal_W_W, setInputSIn_gray_on, verifyResultValueWord,
			"BTOGRYP 1->1 conv 1234", 2, 0},
	{91, ML_CODE_BTOGRYP, setCodeVal_W_W, setInputSIn_gray_tr1, verifyResultValueWord,
			"BTOGRYP 0->1 conv 1234", 2, 0x06BB},
	{92, ML_CODE_BTOGRYP, setCodeVal_K1234_W, setInputSIn_none_off, verifyResultValueWord,
			"BTOGRYP conv K 0->0", 2, 0},
	{93, ML_CODE_BTOGRYP, setCodeVal_K1234_W, setInputSIn_none_tr1, verifyResultValueWord,
			"BTOGRYP condition K 0->1", 2, 0x06BB},
	{94, ML_CODE_BTOGRYP, setCodeVal_N_W, setInputSIn_gray_N_W_off, verifyResultValueWord,
			"BTOGRYP conv nb 0->0", 2, 0},
	{95, ML_CODE_BTOGRYP, setCodeVal_N_W, setInputSIn_gray_N_W_on, verifyResultValueWord,
			"BTOGRYP conv nb 1->1 ", 2, 0},
	{96, ML_CODE_BTOGRYP, setCodeVal_N_W, setInputSIn_gray_N_W_tr1, verifyResultValueWord,
			"BTOGRYP conv nb 0->1 ", 2, 0x06BB},

	{97, ML_CODE_GRYTOB, setCodeVal_W_W, setInputSIn_inv_gray_off, verifyResultValueWord,
			"GRYTOB condition off", 1, 0},
	{98, ML_CODE_GRYTOB, setCodeVal_W_W, setInputSIn_inv_gray_on, verifyResultValueWord,
			"GRYTOB on conv 0x06BB", 1, 1234},
	{99, ML_CODE_GRYTOB, setCodeVal_K06BB_W, setInputSIn_none_off, verifyResultValueWord,
			"GRYTOB conv K off", 1, 0},
	{100, ML_CODE_GRYTOB, setCodeVal_K06BB_W, setInputSIn_none_on, verifyResultValueWord,
			"GRYTOB condition K on", 1, 1234},
	{101, ML_CODE_GRYTOB, setCodeVal_N_W, setInputSIn_inv_gray_N_W_off, verifyResultValueWord,
			"GRYTOB conv nb off", 1, 0},
	{102, ML_CODE_GRYTOB, setCodeVal_N_W, setInputSIn_inv_gray_N_W_on, verifyResultValueWord,
			"GRYTOB conv nb on 0x06BB", 1, 1234},

	{103, ML_CODE_GRYTOBP, setCodeVal_W_W, setInputSIn_inv_gray_off, verifyResultValueWord,
			"GRYTOBP condition 0->0", 2, 0},
	{104, ML_CODE_GRYTOBP, setCodeVal_W_W, setInputSIn_inv_gray_on, verifyResultValueWord,
			"GRYTOBP 1->1 conv 0x06BB", 2, 0},
	{105, ML_CODE_GRYTOBP, setCodeVal_W_W, setInputSIn_inv_gray_tr1, verifyResultValueWord,
			"GRYTOBP 0->1 conv 0x06BB", 2, 1234},
	{106, ML_CODE_GRYTOBP, setCodeVal_K06BB_W, setInputSIn_none_off, verifyResultValueWord,
			"GRYTOBP conv K 0->0", 2, 0},
	{107, ML_CODE_GRYTOBP, setCodeVal_K06BB_W, setInputSIn_none_tr1, verifyResultValueWord,
			"GRYTOBP condition K 0->1", 2, 1234},
	{108, ML_CODE_GRYTOBP, setCodeVal_N_W, setInputSIn_inv_gray_N_W_off, verifyResultValueWord,
			"GRYTOBP conv nb 0->0", 2, 0},
	{109, ML_CODE_GRYTOBP, setCodeVal_N_W, setInputSIn_inv_gray_N_W_on, verifyResultValueWord,
			"GRYTOBP conv nb 1->1 0x06BB", 2, 0},
	{110, ML_CODE_GRYTOBP, setCodeVal_N_W, setInputSIn_inv_gray_N_W_tr1, verifyResultValueWord,
			"GRYTOBP conv nb 0->1 0x06BB", 2, 1234},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};


int total_conversion_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_conversion_test_number; i++)
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

int setCodeVal_W_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K101(uint16 ml_cmd, uint8 in_reg, uint16 val, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 101); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K9999(uint16 ml_cmd, uint8 in_reg, uint16 val, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 9999); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K101B(uint16 ml_cmd, uint8 in_reg, uint16 val, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x101); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K9999B(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x9999); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_F_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(in_reg, in_pos); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_E_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 32767.0); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_nE_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, -32768.0); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_E_up_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 101.5); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_DK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 32767); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_nDK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, -32768); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_DN_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K1234_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 1234); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K06BB_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x06BB); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputSIn_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);

	TestCodeTearDown();
}

void setInputSIn_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_normal_101_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 101);

	TestCodeTearDown();
}

void setInputSIn_normal_101_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 101);

	TestCodeTearDown();
}

void setInputSIn_normal_101_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 101);

	TestCodeTearDown();
}

void setInputSIn_normal_0x101_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x101);

	TestCodeTearDown();
}

void setInputSIn_normal_0x101_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x101);

	TestCodeTearDown();
}

void setInputSIn_normal_9999_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 9999);

	TestCodeTearDown();
}

void setInputSIn_normal_9999_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 9999);

	TestCodeTearDown();
}

void setInputSIn_normal_0x9999_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x9999);

	TestCodeTearDown();
}

void setInputSIn_normal_0x9999_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x9999);

	TestCodeTearDown();
}

void setInputSIn_val16_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val16_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val16_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_normal_101_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_normal_101_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputSIn_normal_0x101_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_normal_0x101_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_normal_9999_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_normal_9999_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_normal_0x9999_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_normal_0x9999_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x9999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputSIn_conv_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 257.0);

	TestCodeTearDown();
}

void setInputSIn_conv_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 257.0);

	TestCodeTearDown();
}


void setInputSIn_conv_float_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 257.0);

	TestCodeTearDown();
}


void setInputSIn_float_maxint_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 32767.0);

	TestCodeTearDown();
}

void setInputSIn_float_maxint_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 32767.0);

	TestCodeTearDown();
}

void setInputSIn_float_half_dn_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 101.4);

	TestCodeTearDown();
}

void setInputSIn_float_half_dn_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 101.4);

	TestCodeTearDown();
}

void setInputSIn_float_half_up_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 101.5);

	TestCodeTearDown();
}

void setInputSIn_float_half_up_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 101.5);

	TestCodeTearDown();
}

void setInputSIn_dword_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_dword_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_dword_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_dword_maxint_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 32767);

	TestCodeTearDown();
}

void setInputSIn_dword_maxint_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 32767);

	TestCodeTearDown();
}

void setInputSIn_val32_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=257;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputSIn_val32_N_W_max_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_N_W_max_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_gray_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);

	TestCodeTearDown();
}

void setInputSIn_gray_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);

	TestCodeTearDown();
}


void setInputSIn_gray_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1234);

	TestCodeTearDown();
}

void setInputSIn_inv_gray_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x06BB);

	TestCodeTearDown();
}

void setInputSIn_inv_gray_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x06BB);

	TestCodeTearDown();
}


void setInputSIn_inv_gray_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0x06BB);

	TestCodeTearDown();
}

void setInputSIn_gray_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_gray_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_gray_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_inv_gray_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x06BB;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_inv_gray_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x06BB;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_inv_gray_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x06BB;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

// bit reg: nibble,
// word reg : normal
static uint16 getInRegPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; // for Dword input

	return pos[inx_pos][reg];
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][2]={ {0,0}, {6144,4096}, {12286,8190}};

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_conversion_word(int tno, uint16 dummy)
{
	int i, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	short res_word;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				if(in==out)
					continue;
				out_pos = getInRegPos(out, olast);
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getInRegPos(in, i);

					//printf("%d\n", __LINE__);
					rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if( rc2 == 0 ) continue;

					//printf("%d\n", __LINE__);
					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

					//printf("%d\n", __LINE__);
					rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
					//printf("%d\n", __LINE__);
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! in_%s[%d] out_%s[%d]\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
							reg[in], in_pos, reg[out], out_pos);
					}
					else
					{
						rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
						if(rc == 1)
						{
							test_getWord(&res_word, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
								reg[in], in_pos, reg[out], out_pos, res_word, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testConversionWordCommand(void)
{
	int i, index=42;
	int start, end;
	char log[] = "err_conv_word.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("conversion word LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=48; index<111; index++)
		test_basic_conversion_word(index, 0);

#else
	total_conversion_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_BTOBCD);
	end = getTestCaseNumberEnd(ML_CODE_GRYTOBP); //

	DBG_LOGPRINT("testConversionWordCommand: %d to %d total %d\n", start, end, total_conversion_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_conversion_word(index, 0);
	}
#endif
	fclose(flog);
}
#endif
