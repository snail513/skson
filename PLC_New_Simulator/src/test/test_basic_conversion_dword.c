/*
 * test_basic_conversion_dword.c
 *
 *  Created on: Jul 6, 2015
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


extern int setCodeVal_W_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
extern int setCodeVal_DN_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
extern int setCodeVal_F_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
extern int setCodeVal_N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

extern void setInputSIn_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_val16_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val16_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val16_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_float_half_dn_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_float_half_dn_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_float_half_up_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_float_half_up_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected);

int setCodeVal_K_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_nK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_K10101(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_K99999999(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_K10101B(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_K99999999B(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_E_DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_nE_DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_E_up_DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_GDK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_IGDK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

void setInputSIn_val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_10101_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_10101_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_99999999_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_99999999_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_10101B_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_10101B_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_99999999B_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_99999999B_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_val32_DN_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN65_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN65B_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN10_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN10B_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN99_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN99B_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN10_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN10B_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN99_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val32_DN99B_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_conv_float_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_conv_float_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_conv_float_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_float_maxint_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_float_maxint_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_word_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_word_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_word_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_word_maxint_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_word_maxint_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_val16_N_W_max_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_val16_N_W_max_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_gray_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_DN_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_DN_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_gray_DN_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_inv_gray_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_DN_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_DN_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_inv_gray_DN_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

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
	{0, ML_CODE_DTOBCD, setCodeVal_W_W, setInputSIn_val32_off, verifyResultValueDWord,
			"DTOBCD condition off", 1, 0},
	{1, ML_CODE_DTOBCD, setCodeVal_W_W, setInputSIn_10101_on, verifyResultValueDWord,
			"DTOBCD on conv 101", 1, 0x10101},
	{2, ML_CODE_DTOBCD, setCodeVal_W_W, setInputSIn_99999999_on, verifyResultValueDWord,
			"DTOBCD on conv 9999", 1, 0x99999999},
	{3, ML_CODE_DTOBCD, setCodeVal_K10101, setInputSIn_none_off, verifyResultValueDWord,
			"DTOBCD off K 101", 1, 0},
	{4, ML_CODE_DTOBCD, setCodeVal_K10101, setInputSIn_none_on, verifyResultValueDWord,
			"DTOBCD on conv K 101", 1, 0x10101},
	{5, ML_CODE_DTOBCD, setCodeVal_K99999999, setInputSIn_none_on, verifyResultValueDWord,
			"DTOBCD on conv K 9999", 1, 0x99999999},
	{6, ML_CODE_DTOBCD, setCodeVal_DN_W, setInputSIn_val32_DN_W_off, verifyResultValueDWord,
			"DTOBCD nib condition off", 1, 0},
	{7, ML_CODE_DTOBCD, setCodeVal_DN_W, setInputSIn_val32_DN10_W_on, verifyResultValueDWord,
			"DTOBCD on conv 101", 1, 0x10101},
	{8, ML_CODE_DTOBCD, setCodeVal_DN_W, setInputSIn_val32_DN99_W_on, verifyResultValueDWord,
			"BTOBCD on conv 9999", 1, 0x99999999},

	{9, ML_CODE_DTOBCDP, setCodeVal_W_W, setInputSIn_val32_off, verifyResultValueDWord,
			"DTOBCDP condition off", 2, 0},
	{10, ML_CODE_DTOBCDP, setCodeVal_W_W, setInputSIn_10101_on, verifyResultValueDWord,
			"DTOBCDP on conv 101", 2, 0},
	{11, ML_CODE_DTOBCDP, setCodeVal_W_W, setInputSIn_10101_tr1, verifyResultValueDWord,
			"DTOBCDP on conv 101", 2, 0x10101},
	{12, ML_CODE_DTOBCDP, setCodeVal_W_W, setInputSIn_99999999_tr1, verifyResultValueDWord,
			"DTOBCDP on conv 9999", 2, 0x99999999},
	{13, ML_CODE_DTOBCDP, setCodeVal_K10101, setInputSIn_none_off, verifyResultValueDWord,
			"DTOBCDP 0->0 K 101", 2, 0},
	{14, ML_CODE_DTOBCDP, setCodeVal_K10101, setInputSIn_none_on, verifyResultValueDWord,
			"DTOBCDP 1->1 K 101", 2, 0},
	{15, ML_CODE_DTOBCDP, setCodeVal_K10101, setInputSIn_none_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 conv K 101", 2, 0x10101},
	{16, ML_CODE_DTOBCDP, setCodeVal_K99999999, setInputSIn_none_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 conv K 9999", 2, 0x99999999},
	{17, ML_CODE_DTOBCDP, setCodeVal_DN_W, setInputSIn_val32_DN_W_off, verifyResultValueDWord,
			"DTOBCDP nb condition 0->0", 2, 0},
	{18, ML_CODE_DTOBCDP, setCodeVal_DN_W, setInputSIn_val32_DN65_W_on, verifyResultValueDWord,
			"DTOBCDP nb condition 1->1", 2, 0},
	{19, ML_CODE_DTOBCDP, setCodeVal_DN_W, setInputSIn_val32_DN10_W_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 conv 101", 2, 0x10101},
	{20, ML_CODE_DTOBCDP, setCodeVal_DN_W, setInputSIn_val32_DN99_W_tr1, verifyResultValueDWord,
			"DTOBCDP 0->1 conv 9999", 2, 0x99999999},

	{21, ML_CODE_BCDTOD, setCodeVal_W_W, setInputSIn_val32_off, verifyResultValueDWord,
			"BCDTOD condition off", 1, 0},
	{22, ML_CODE_BCDTOD, setCodeVal_W_W, setInputSIn_10101B_on, verifyResultValueDWord,
			"BCDTOD on K BCD101", 1, 10101},
	{23, ML_CODE_BCDTOD, setCodeVal_W_W, setInputSIn_99999999B_on, verifyResultValueDWord,
			"BCDTOD on K BCD9999", 1, 99999999},
	{24, ML_CODE_BCDTOD, setCodeVal_K10101B, setInputSIn_none_off, verifyResultValueDWord,
			"BCDTOD off K BCD101", 1, 0},
	{25, ML_CODE_BCDTOD, setCodeVal_K10101B, setInputSIn_none_on, verifyResultValueDWord,
			"BCDTOD on conv K BCD101", 1, 10101},
	{26, ML_CODE_BCDTOD, setCodeVal_K99999999B, setInputSIn_none_on, verifyResultValueDWord,
			"BCDTOD on conv K BCD9999", 1, 99999999},
	{27, ML_CODE_BCDTOD, setCodeVal_DN_W, setInputSIn_val32_DN_W_off, verifyResultValueDWord,
			"BCDTOD nb condition off", 1, 0},
	{28, ML_CODE_BCDTOD, setCodeVal_DN_W, setInputSIn_val32_DN10B_W_on, verifyResultValueDWord,
			"BCDTOD on conv 101", 1, 10101},
	{29, ML_CODE_BCDTOD, setCodeVal_DN_W, setInputSIn_val32_DN99B_W_on, verifyResultValueDWord,
			"BCDTOD on conv 9999", 1, 99999999},

	{30, ML_CODE_BCDTODP, setCodeVal_W_W, setInputSIn_val32_off, verifyResultValueDWord,
			"BCDTODP condition 0->0", 2, 0},
	{31, ML_CODE_BCDTODP, setCodeVal_W_W, setInputSIn_10101B_on, verifyResultValueDWord,
			"BCDTODP 1->1 conv B10101", 2, 0},
	{32, ML_CODE_BCDTODP, setCodeVal_W_W, setInputSIn_10101B_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 conv B10101", 2, 10101},
	{33, ML_CODE_BCDTODP, setCodeVal_W_W, setInputSIn_99999999B_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 conv B99999999", 2, 99999999},
	{34, ML_CODE_BCDTODP, setCodeVal_K10101B, setInputSIn_none_off, verifyResultValueDWord,
			"BCDTODP 1->1 K BCD101", 2, 0},
	{35, ML_CODE_BCDTODP, setCodeVal_K10101B, setInputSIn_none_on, verifyResultValueDWord,
			"BCDTODP 1->1 conv BCD10101", 2, 0},
	{36, ML_CODE_BCDTODP, setCodeVal_K10101B, setInputSIn_none_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 conv B10101", 2, 10101},
	{37, ML_CODE_BCDTODP, setCodeVal_K99999999B, setInputSIn_none_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 conv B99999999", 2, 99999999},
	{38, ML_CODE_BCDTODP, setCodeVal_DN_W, setInputSIn_val32_DN_W_off, verifyResultValueDWord,
			"BCDTODP nb condition 0->0", 2, 0},
	{39, ML_CODE_BCDTODP, setCodeVal_DN_W, setInputSIn_val32_DN65_W_on, verifyResultValueDWord,
			"BCDTODP nb condition 1->1", 2, 0},
	{40, ML_CODE_BCDTODP, setCodeVal_DN_W, setInputSIn_val32_DN10B_W_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 conv nb 101", 2, 10101},
	{41, ML_CODE_BCDTODP, setCodeVal_DN_W, setInputSIn_val32_DN99B_W_tr1, verifyResultValueDWord,
			"BCDTODP 0->1 conv nb B99999999", 2, 99999999},

	{42, ML_CODE_FTOD, setCodeVal_F_W, setInputSIn_conv_float_DW_off, verifyResultValueDWord,
			"FTOD condition off", 1, 0},
	{43, ML_CODE_FTOD, setCodeVal_F_W, setInputSIn_conv_float_DW_on, verifyResultValueDWord,
			"FTOD on conv 65536.0", 1, 65536},
	{44, ML_CODE_FTOD, setCodeVal_F_W, setInputSIn_float_maxint_DW_on, verifyResultValueDWord,
			"FTOD on conv 9999999.0", 1, 9999999},
	{45, ML_CODE_FTOD, setCodeVal_F_W, setInputSIn_float_half_dn_on, verifyResultValueDWord,
			"FTOD on conv 101.4", 1, 101},
	{46, ML_CODE_FTOD, setCodeVal_F_W, setInputSIn_float_half_up_on, verifyResultValueDWord,
			"FTOD on conv 101.5", 1, 102},
	{47, ML_CODE_FTOD, setCodeVal_E_DW, setInputSIn_none_off, verifyResultValueDWord,
			"FTOD condition off", 1, 0},
	{48, ML_CODE_FTOD, setCodeVal_E_DW, setInputSIn_none_on, verifyResultValueDWord,
			"FTOD on conv 9999999.0", 1, 9999999},
	{49, ML_CODE_FTOD, setCodeVal_nE_DW, setInputSIn_none_on, verifyResultValueDWord,
			"FTOD on conv -9999999.0", 1, -9999999},
	{50, ML_CODE_FTOD, setCodeVal_E_up_DW, setInputSIn_none_on, verifyResultValueDWord,
			"FTOD on conv 101.5", 1, 102},

	{51, ML_CODE_FTODP, setCodeVal_F_W, setInputSIn_conv_float_DW_off, verifyResultValueDWord,
			"FTODP condition 0->0", 2, 0},
	{52, ML_CODE_FTODP, setCodeVal_F_W, setInputSIn_conv_float_DW_on, verifyResultValueDWord,
			"FTODP 1->1 conv 257.0", 2, 0},
	{53, ML_CODE_FTODP, setCodeVal_F_W, setInputSIn_conv_float_DW_tr1, verifyResultValueDWord,
			"FTODP 0->1 conv 257.0", 2, 65536},
	{54, ML_CODE_FTODP, setCodeVal_F_W, setInputSIn_float_maxint_DW_tr1, verifyResultValueDWord,
			"FTODP 0->1 conv 9999999.0", 2, 9999999},
	{55, ML_CODE_FTODP, setCodeVal_F_W, setInputSIn_float_half_dn_tr1, verifyResultValueDWord,
			"FTODP on conv 101.4", 2, 101},
	{56, ML_CODE_FTODP, setCodeVal_F_W, setInputSIn_float_half_up_tr1, verifyResultValueDWord,
			"FTODP on conv 101.5", 2, 102},
	{57, ML_CODE_FTODP, setCodeVal_E_DW, setInputSIn_none_off, verifyResultValueDWord,
			"FTODP condition 0->0", 2, 0},
	{58, ML_CODE_FTODP, setCodeVal_E_DW, setInputSIn_none_on, verifyResultValueDWord,
			"FTODP conv 1->1", 2, 0},
	{59, ML_CODE_FTODP, setCodeVal_E_DW, setInputSIn_none_tr1, verifyResultValueDWord,
			"FTODP conv 0-> 1 9999999.0", 2, 9999999},
	{60, ML_CODE_FTODP, setCodeVal_nE_DW, setInputSIn_none_tr1, verifyResultValueDWord,
			"FTODP 0->1 conv -9999999.0", 2, -9999999},
	{61, ML_CODE_FTODP, setCodeVal_E_up_DW, setInputSIn_none_tr1, verifyResultValueDWord,
			"FTODP 0->1 conv 101.5", 2, 102},

	{62, ML_CODE_BTOD, setCodeVal_W_W, setInputSIn_word_off, verifyResultValueDWord,
			"BTOD condition off", 1, 0},
	{63, ML_CODE_BTOD, setCodeVal_W_W, setInputSIn_word_on, verifyResultValueDWord,
			"BTOD on conv 257", 1, 257},
	{64, ML_CODE_BTOD, setCodeVal_W_W, setInputSIn_word_maxint_on, verifyResultValueDWord,
			"BTOD on conv 32767", 1, 32767},
	{65, ML_CODE_BTOD, setCodeVal_K_W, setInputSIn_none_off, verifyResultValueDWord,
			"BTOD condition off", 1, 0},
	{66, ML_CODE_BTOD, setCodeVal_K_W, setInputSIn_none_on, verifyResultValueDWord,
			"BTOD on conv 32767.0", 1, 32767},
	{67, ML_CODE_BTOD, setCodeVal_nK_W, setInputSIn_none_on, verifyResultValueDWord,
			"BTOD on conv -32768.0", 1, -32768},
	{68, ML_CODE_BTOD, setCodeVal_N_W, setInputSIn_val16_N_W_off, verifyResultValueDWord,
			"BTOD condition off", 1, 0},
	{69, ML_CODE_BTOD, setCodeVal_N_W, setInputSIn_val16_N_W_on, verifyResultValueDWord,
			"BTOD on conv nb 257", 1, 257},
	{70, ML_CODE_BTOD, setCodeVal_N_W, setInputSIn_val16_N_W_max_on, verifyResultValueDWord,
			"BTOD on conv nb 32767", 1, 32767},

	{71, ML_CODE_BTODP, setCodeVal_W_W, setInputSIn_word_off, verifyResultValueDWord,
			"BTODP condition 0->0", 2, 0},
	{72, ML_CODE_BTODP, setCodeVal_W_W, setInputSIn_word_on, verifyResultValueDWord,
			"BTODP 1->1 conv 257", 2, 0},
	{73, ML_CODE_BTODP, setCodeVal_W_W, setInputSIn_word_tr1, verifyResultValueDWord,
			"BTODP 0->1 conv 257", 2, 257},
	{74, ML_CODE_BTODP, setCodeVal_W_W, setInputSIn_word_maxint_tr1, verifyResultValueDWord,
			"BTODP 0->1 conv 32767", 2, 32767},
	{75, ML_CODE_BTODP, setCodeVal_K_W, setInputSIn_none_off, verifyResultValueDWord,
			"BTODP condition 0->0", 2, 0},
	{76, ML_CODE_BTODP, setCodeVal_K_W, setInputSIn_none_on, verifyResultValueDWord,
			"BTODP 1->1 conv 32767.0", 2, 0},
	{77, ML_CODE_BTODP, setCodeVal_K_W, setInputSIn_none_tr1, verifyResultValueDWord,
			"BTODP 0->1 conv 32767.0", 2, 32767},
	{78, ML_CODE_BTODP, setCodeVal_nK_W, setInputSIn_none_tr1, verifyResultValueDWord,
			"BTODP 0->1 conv -32768.0", 2, -32768},
	{79, ML_CODE_BTODP, setCodeVal_N_W, setInputSIn_val16_N_W_off, verifyResultValueDWord,
			"BTODP condition 0->0", 2, 0},
	{80, ML_CODE_BTODP, setCodeVal_N_W, setInputSIn_val16_N_W_on, verifyResultValueDWord,
			"BTODP 1->1 conv nb 257", 2, 0},
	{81, ML_CODE_BTODP, setCodeVal_N_W, setInputSIn_val16_N_W_tr1, verifyResultValueDWord,
			"BTODP 0->1 conv nb 257", 2, 257},
	{82, ML_CODE_BTODP, setCodeVal_N_W, setInputSIn_val16_N_W_max_tr1, verifyResultValueDWord,
			"BTODP 0->1 conv nb 32767", 2, 32767},

	{83, ML_CODE_DTOGRY, setCodeVal_W_W, setInputSIn_gray_DW_off, verifyResultValueDWord,
			"DTOGRY condition off", 1, 0},
	{84, ML_CODE_DTOGRY, setCodeVal_W_W, setInputSIn_gray_DW_on, verifyResultValueDWord,
			"DTOGRY on conv 305419896", 1, 0x1B2E7D44},
	{85, ML_CODE_DTOGRY, setCodeVal_GDK_W, setInputSIn_none_off, verifyResultValueDWord,
			"DTOGRY conv K off", 1, 0},
	{86, ML_CODE_DTOGRY, setCodeVal_GDK_W, setInputSIn_none_on, verifyResultValueDWord,
			"DTOGRY condition K on", 1, 0x1B2E7D44},
	{87, ML_CODE_DTOGRY, setCodeVal_DN_W, setInputSIn_gray_DN_W_off, verifyResultValueDWord,
			"DTOGRY conv nb off", 1, 0},
	{88, ML_CODE_DTOGRY, setCodeVal_DN_W, setInputSIn_gray_DN_W_on, verifyResultValueDWord,
			"DTOGRY conv nb on", 1, 0x1B2E7D44},

	{89, ML_CODE_DTOGRYP, setCodeVal_W_W, setInputSIn_gray_DW_off, verifyResultValueDWord,
			"DTOGRYP condition 0->0", 2, 0},
	{90, ML_CODE_DTOGRYP, setCodeVal_W_W, setInputSIn_gray_DW_on, verifyResultValueDWord,
			"DTOGRYP 1->1 conv 305419896", 2, 0},
	{91, ML_CODE_DTOGRYP, setCodeVal_W_W, setInputSIn_gray_DW_tr1, verifyResultValueDWord,
			"DTOGRYP 0->1 conv 305419896", 2, 0x1B2E7D44},
	{92, ML_CODE_DTOGRYP, setCodeVal_GDK_W, setInputSIn_none_off, verifyResultValueDWord,
			"DTOGRYP conv K 0->0", 2, 0},
	{93, ML_CODE_DTOGRYP, setCodeVal_GDK_W, setInputSIn_none_tr1, verifyResultValueDWord,
			"DTOGRYP condition K 0->1", 2, 0x1B2E7D44},
	{94, ML_CODE_DTOGRYP, setCodeVal_DN_W, setInputSIn_gray_DN_W_off, verifyResultValueDWord,
			"DTOGRYP conv nb 0->0", 2, 0},
	{95, ML_CODE_DTOGRYP, setCodeVal_DN_W, setInputSIn_gray_DN_W_on, verifyResultValueDWord,
			"DTOGRYP conv nb 1->1 ", 2, 0},
	{96, ML_CODE_DTOGRYP, setCodeVal_DN_W, setInputSIn_gray_DN_W_tr1, verifyResultValueDWord,
			"DTOGRYP conv nb 0->1 305419896", 2, 0x1B2E7D44},

	{97, ML_CODE_GRYTOD, setCodeVal_W_W, setInputSIn_inv_gray_DW_off, verifyResultValueDWord,
			"GRYTOD condition off", 1, 0},
	{98, ML_CODE_GRYTOD, setCodeVal_W_W, setInputSIn_inv_gray_DW_on, verifyResultValueDWord,
			"GRYTOD on conv 0x1B2E7D44", 1, 305419896},
	{99, ML_CODE_GRYTOD, setCodeVal_IGDK_W, setInputSIn_none_off, verifyResultValueDWord,
			"GRYTOD conv K off", 1, 0},
	{100, ML_CODE_GRYTOD, setCodeVal_IGDK_W, setInputSIn_none_on, verifyResultValueDWord,
			"GRYTOD condition K on", 1, 305419896},
	{101, ML_CODE_GRYTOD, setCodeVal_DN_W, setInputSIn_inv_gray_DN_W_off, verifyResultValueDWord,
			"GRYTOD conv nb off", 1, 0},
	{102, ML_CODE_GRYTOD, setCodeVal_DN_W, setInputSIn_inv_gray_DN_W_on, verifyResultValueDWord,
			"GRYTOD conv nb on 0x1B2E7D44", 1, 305419896},

	{103, ML_CODE_GRYTODP, setCodeVal_W_W, setInputSIn_inv_gray_DW_off, verifyResultValueDWord,
			"GRYTODP condition 0->0", 2, 0},
	{104, ML_CODE_GRYTODP, setCodeVal_W_W, setInputSIn_inv_gray_DW_on, verifyResultValueDWord,
			"GRYTODP 1->1 conv 0x1B2E7D44", 2, 0},
	{105, ML_CODE_GRYTODP, setCodeVal_W_W, setInputSIn_inv_gray_DW_tr1, verifyResultValueDWord,
			"GRYTODP 0->1 conv 0x1B2E7D44", 2, 305419896},
	{106, ML_CODE_GRYTODP, setCodeVal_IGDK_W, setInputSIn_none_off, verifyResultValueDWord,
			"GRYTODP conv K 0->0", 2, 0},
	{107, ML_CODE_GRYTODP, setCodeVal_IGDK_W, setInputSIn_none_tr1, verifyResultValueDWord,
			"GRYTODP condition K 0->1", 2, 305419896},
	{108, ML_CODE_GRYTODP, setCodeVal_DN_W, setInputSIn_inv_gray_DN_W_off, verifyResultValueDWord,
			"GRYTODP conv nb 0->0", 2, 0},
	{109, ML_CODE_GRYTODP, setCodeVal_DN_W, setInputSIn_inv_gray_DN_W_on, verifyResultValueDWord,
			"GRYTODP conv nb 1->1 0x1B2E7D44", 2, 0},
	{110, ML_CODE_GRYTODP, setCodeVal_DN_W, setInputSIn_inv_gray_DN_W_tr1, verifyResultValueDWord,
			"GRYTODP conv nb 0->1 0x1B2E7D44", 2, 305419896},

	{-1, 0xFFFF, NULL, NULL, NULL, NULL, 0, 0 }
};


int total_conversion_dword_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_conversion_dword_test_number; i++)
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

int setCodeVal_E_DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 9999999.0); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_nE_DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, -9999999.0); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_E_up_DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 101.5); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 32767); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_nK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, -32768); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K10101(uint16 ml_cmd, uint8 in_reg, uint16 val, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 10101); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K99999999(uint16 ml_cmd, uint8 in_reg, uint16 val, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 99999999); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K10101B(uint16 ml_cmd, uint8 in_reg, uint16 val, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x10101); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_K99999999B(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x99999999); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_GDK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 305419896); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_IGDK_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x1B2E7D44); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputSIn_val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 65536);

	TestCodeTearDown();
}

void setInputSIn_val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 65536);

	TestCodeTearDown();
}

void setInputSIn_10101_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 10101);

	TestCodeTearDown();
}

void setInputSIn_10101_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 10101);

	TestCodeTearDown();
}

void setInputSIn_10101_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 10101);

	TestCodeTearDown();
}

void setInputSIn_99999999_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 99999999);

	TestCodeTearDown();
}

void setInputSIn_99999999_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 99999999);

	TestCodeTearDown();
}

void setInputSIn_10101B_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x10101);

	TestCodeTearDown();
}

void setInputSIn_10101B_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x10101);

	TestCodeTearDown();
}

void setInputSIn_10101B_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x10101);

	TestCodeTearDown();
}

void setInputSIn_99999999B_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99999999);

	TestCodeTearDown();
}

void setInputSIn_99999999B_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99999999);

	TestCodeTearDown();
}

void setInputSIn_val32_DN_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=65536;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN65_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=65536;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN65B_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=65536;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN10_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN10_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN10B_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN99_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN99B_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN10_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN10B_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x10101;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN99_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val32_DN99B_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x99999999;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputSIn_conv_float_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	float in_val = 65536.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_conv_float_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	float in_val = 65536.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}


void setInputSIn_conv_float_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	float in_val = 65536.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_maxint_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	float in_val = 9999999.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_float_maxint_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	float in_val = 9999999.0;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_word_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_word_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_word_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_word_maxint_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);

	TestCodeTearDown();
}

void setInputSIn_word_maxint_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 32767);

	TestCodeTearDown();
}


void setInputSIn_val16_N_W_max_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_val16_N_W_max_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=32767;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_gray_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 305419896);

	TestCodeTearDown();
}

void setInputSIn_gray_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 305419896);

	TestCodeTearDown();
}


void setInputSIn_gray_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 305419896);

	TestCodeTearDown();
}

void setInputSIn_gray_DN_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	uint32 value=305419896;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_gray_DN_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	uint32 value=305419896;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_gray_DN_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	uint32 value=305419896;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_inv_gray_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x1B2E7D44);

	TestCodeTearDown();
}

void setInputSIn_inv_gray_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x1B2E7D44);

	TestCodeTearDown();
}


void setInputSIn_inv_gray_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x1B2E7D44);

	TestCodeTearDown();
}


void setInputSIn_inv_gray_DN_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	uint32 value=0x1B2E7D44;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_inv_gray_DN_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	uint32 value=0x1B2E7D44;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_inv_gray_DN_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	uint32 value=0x1B2E7D44;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}


// bit reg: nibble,
// word reg : normal
static uint16 getInRegPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}};

	return pos[inx_pos][reg];
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][2]={ {0,0}, {6144,4096}, {12286,8190}}; // -2

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_conversion_dword(int tno, uint16 dummy)
{
	int i=1, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	int res_dword;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getInRegPos(in, i);
					out_pos = getInRegPos(out, olast);

					rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if( rc2 == 0 ) continue;

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
							test_getDWord(&res_dword, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d\n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_dword, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}


void testConversionDWordCommand(void)
{
	int i, index=2;
	int start, end;
	char log[] = "err_conv_dword.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("conversion dword LOG file open error !\n");
		exit(1);
	}
#if 0
	for(index=2; index<10; index++)
		test_basic_conversion_dword(index, 0);

#else
	total_conversion_dword_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DTOBCD); //ML_CODE_DTOBCD
	end = getTestCaseNumberEnd(ML_CODE_GRYTODP); //ML_CODE_GRYTODP

	DBG_LOGPRINT("testConversionDWordCommand: %d to %d total %d\n", start, end, total_conversion_dword_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_conversion_dword(index, 0);
	}
#endif
	fclose(flog);
}
#endif
