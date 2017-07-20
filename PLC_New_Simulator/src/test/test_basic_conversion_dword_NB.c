/*
 * test_basic_conversion_dword_NB.c
 *
 *  Created on: Aug 27, 2015
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

extern int setCodeOp2_DW1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeOp2_DN1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

extern void setInputSIn_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_10101_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_10101_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_10101_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_99999999_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_99999999_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_10101B_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_10101B_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_10101B_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_99999999B_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_99999999B_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_val32_DN_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN65_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN65B_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN10_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN10_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN10B_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN99_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN99B_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN10_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN10B_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN99_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val32_DN99B_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_conv_float_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_conv_float_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_conv_float_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_float_maxint_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_float_maxint_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_float_half_dn_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_float_half_dn_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_float_half_up_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_float_half_up_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_word_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_word_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_word_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_word_maxint_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_word_maxint_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_val16_N_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val16_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val16_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_normal_101_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_normal_0x101_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_normal_9999_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_normal_0x9999_N_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_normal_101_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_normal_0x101_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_normal_9999_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_normal_0x9999_N_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val16_N_W_max_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_val16_N_W_max_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_gray_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_gray_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_gray_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_gray_DN_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_gray_DN_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_gray_DN_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputSIn_inv_gray_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_inv_gray_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_inv_gray_DW_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_inv_gray_DN_W_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_inv_gray_DN_W_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_inv_gray_DN_W_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected);

int setCodeOp2_DK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_maxDK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_DKB1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_maxDKB1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_maxE1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_minE1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_upE1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_maxintK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_negintK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_N1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_GDK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_IGDK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

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
	{0, ML_CODE_DTOBCD, setCodeOp2_DW1DN2, setInputSIn_10101_off, verifyResultValueNibble8,
			"DTOBCD off", 1, 0},
	{1, ML_CODE_DTOBCD, setCodeOp2_DW1DN2, setInputSIn_10101_on, verifyResultValueNibble8,
			"DTOBCD on 101", 1, 0x10101},
	{2, ML_CODE_DTOBCD, setCodeOp2_DW1DN2, setInputSIn_99999999_on, verifyResultValueNibble8,
			"DTOBCD on 9999", 1, 0x99999999},
	{3, ML_CODE_DTOBCD, setCodeOp2_DK1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"DTOBCD off K10101", 1, 0},
	{4, ML_CODE_DTOBCD, setCodeOp2_DK1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"DTOBCD on K10101", 1, 0x10101},
	{5, ML_CODE_DTOBCD, setCodeOp2_maxDK1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"DTOBCD on K99999999", 1, 0x99999999},
	{6, ML_CODE_DTOBCD, setCodeOp2_DN1DN2, setInputSIn_val32_DN10_W_off, verifyResultValueNibble8,
			"DTOBCD off N10101", 1, 0},
	{7, ML_CODE_DTOBCD, setCodeOp2_DN1DN2, setInputSIn_val32_DN10_W_on, verifyResultValueNibble8,
			"DTOBCD on N10101", 1, 0x10101},
	{8, ML_CODE_DTOBCD, setCodeOp2_DN1DN2, setInputSIn_val32_DN99_W_on, verifyResultValueNibble8,
			"BTOBCD on N99999999", 1, 0x99999999},

	{9, ML_CODE_DTOBCDP, setCodeOp2_DW1DN2, setInputSIn_10101_off, verifyResultValueNibble8,
			"DTOBCDP 0->0 W10101", 2, 0},
	{10, ML_CODE_DTOBCDP, setCodeOp2_DW1DN2, setInputSIn_10101_tr1, verifyResultValueNibble8,
			"DTOBCDP 0->1 W10101", 2, 0x10101},
	{11, ML_CODE_DTOBCDP, setCodeOp2_DW1DN2, setInputSIn_99999999_tr1, verifyResultValueNibble8,
			"DTOBCDP 0->1 W99999999", 2, 0x99999999},
	{12, ML_CODE_DTOBCDP, setCodeOp2_DK1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"DTOBCDP 0->0 K10101", 2, 0},
	{13, ML_CODE_DTOBCDP, setCodeOp2_DK1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"DTOBCDP 0->1 K10101", 2, 0x10101},
	{14, ML_CODE_DTOBCDP, setCodeOp2_maxDK1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"DTOBCDP 0->1 K99999999", 2, 0x99999999},
	{15, ML_CODE_DTOBCDP, setCodeOp2_DN1DN2, setInputSIn_val32_DN_W_off, verifyResultValueNibble8,
			"DTOBCDP 0->0 N10101", 2, 0},
	{16, ML_CODE_DTOBCDP, setCodeOp2_DN1DN2, setInputSIn_val32_DN10_W_tr1, verifyResultValueNibble8,
			"DTOBCDP 0->1 N10101", 2, 0x10101},
	{17, ML_CODE_DTOBCDP, setCodeOp2_DN1DN2, setInputSIn_val32_DN99_W_tr1, verifyResultValueNibble8,
			"DTOBCDP 0->1 N99999999", 2, 0x99999999},

	{18, ML_CODE_BCDTOD, setCodeOp2_DW1DN2, setInputSIn_10101B_off, verifyResultValueNibble8,
			"BCDTOD off B10101", 1, 0},
	{19, ML_CODE_BCDTOD, setCodeOp2_DW1DN2, setInputSIn_10101B_on, verifyResultValueNibble8,
			"BCDTOD on B10101", 1, 10101},
	{20, ML_CODE_BCDTOD, setCodeOp2_DW1DN2, setInputSIn_99999999B_on, verifyResultValueNibble8,
			"BCDTOD on B99999999", 1, 99999999},
	{21, ML_CODE_BCDTOD, setCodeOp2_DKB1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"BCDTOD off KB10101", 1, 0},
	{22, ML_CODE_BCDTOD, setCodeOp2_DKB1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"BCDTOD on KB10101", 1, 10101},
	{23, ML_CODE_BCDTOD, setCodeOp2_maxDKB1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"BCDTOD on KB99999999", 1, 99999999},
	{24, ML_CODE_BCDTOD, setCodeOp2_DN1DN2, setInputSIn_val32_DN_W_off, verifyResultValueNibble8,
			"BCDTOD off NB10101", 1, 0},
	{25, ML_CODE_BCDTOD, setCodeOp2_DN1DN2, setInputSIn_val32_DN10B_W_on, verifyResultValueNibble8,
			"BCDTOD on NB10101", 1, 10101},
	{26, ML_CODE_BCDTOD, setCodeOp2_DN1DN2, setInputSIn_val32_DN99B_W_on, verifyResultValueNibble8,
			"BCDTOD on NB999999999", 1, 99999999},

	{27, ML_CODE_BCDTODP, setCodeOp2_DW1DN2, setInputSIn_10101B_off, verifyResultValueNibble8,
			"BCDTODP 0->0 B10101", 2, 0},
	{28, ML_CODE_BCDTODP, setCodeOp2_DW1DN2, setInputSIn_10101B_tr1, verifyResultValueNibble8,
			"BCDTODP 0->1 B10101", 2, 10101},
	{29, ML_CODE_BCDTODP, setCodeOp2_DW1DN2, setInputSIn_99999999B_tr1, verifyResultValueNibble8,
			"BCDTODP 0->1 B99999999", 2, 99999999},
	{30, ML_CODE_BCDTODP, setCodeOp2_DKB1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"BCDTODP 1->1 BCD10101", 2, 0},
	{31, ML_CODE_BCDTODP, setCodeOp2_DKB1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"BCDTODP 0->1 KB10101", 2, 10101},
	{32, ML_CODE_BCDTODP, setCodeOp2_maxDKB1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"BCDTODP 0->1 KB99999999", 2, 99999999},
	{33, ML_CODE_BCDTODP, setCodeOp2_DN1DN2, setInputSIn_val32_DN_W_off, verifyResultValueNibble8,
			"BCDTODP 0->0 NB10101", 2, 0},
	{34, ML_CODE_BCDTODP, setCodeOp2_DN1DN2, setInputSIn_val32_DN10B_W_tr1, verifyResultValueNibble8,
			"BCDTODP 0->1 NB10101", 2, 10101},
	{35, ML_CODE_BCDTODP, setCodeOp2_DN1DN2, setInputSIn_val32_DN99B_W_tr1, verifyResultValueNibble8,
			"BCDTODP 0->1 NB99999999", 2, 99999999},

	{36, ML_CODE_FTOD, setCodeOp2_DW1DN2, setInputSIn_conv_float_DW_off, verifyResultValueNibble8,
			"FTOD off", 1, 0},
	{37, ML_CODE_FTOD, setCodeOp2_DW1DN2, setInputSIn_conv_float_DW_on, verifyResultValueNibble8,
			"FTOD on 65536.0", 1, 65536},
	{38, ML_CODE_FTOD, setCodeOp2_DW1DN2, setInputSIn_float_maxint_DW_on, verifyResultValueNibble8,
			"FTOD on 9999999.0", 1, 9999999},
	{39, ML_CODE_FTOD, setCodeOp2_DW1DN2, setInputSIn_float_half_dn_on, verifyResultValueNibble8,
			"FTOD on 101.4", 1, 101},
	{40, ML_CODE_FTOD, setCodeOp2_DW1DN2, setInputSIn_float_half_up_on, verifyResultValueNibble8,
			"FTOD on 101.5", 1, 102},
	{41, ML_CODE_FTOD, setCodeOp2_maxE1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"FTOD off", 1, 0},
	{41, ML_CODE_FTOD, setCodeOp2_maxE1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"FTOD on K9999999.0", 1, 9999999},
	{43, ML_CODE_FTOD, setCodeOp2_minE1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"FTOD on K-9999999.0", 1, -9999999},
	{44, ML_CODE_FTOD, setCodeOp2_upE1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"FTOD on K101.5", 1, 102},

	{45, ML_CODE_FTODP, setCodeOp2_DW1DN2, setInputSIn_conv_float_DW_off, verifyResultValueNibble8,
			"FTODP 0->0", 2, 0},
	{46, ML_CODE_FTODP, setCodeOp2_DW1DN2, setInputSIn_conv_float_DW_tr1, verifyResultValueNibble8,
			"FTODP 0->1 65536.0", 2, 65536},
	{47, ML_CODE_FTODP, setCodeOp2_DW1DN2, setInputSIn_float_maxint_DW_tr1, verifyResultValueNibble8,
			"FTODP 0->1 9999999.0", 2, 9999999},
	{48, ML_CODE_FTODP, setCodeOp2_DW1DN2, setInputSIn_float_half_dn_tr1, verifyResultValueNibble8,
			"FTODP 0->1 101.4", 2, 101},
	{49, ML_CODE_FTODP, setCodeOp2_DW1DN2, setInputSIn_float_half_up_tr1, verifyResultValueNibble8,
			"FTODP 0->1 101.5", 2, 102},
	{50, ML_CODE_FTODP, setCodeOp2_maxE1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"FTODP 0->0", 2, 0},
	{51, ML_CODE_FTODP, setCodeOp2_maxE1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"FTODP 0-> 1 K9999999.0", 2, 9999999},
	{52, ML_CODE_FTODP, setCodeOp2_minE1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"FTODP 0->1 K-9999999.0", 2, -9999999},
	{53, ML_CODE_FTODP, setCodeOp2_upE1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"FTODP 0->1 K101.5", 2, 102},

	{54, ML_CODE_BTOD, setCodeOp2_DW1DN2, setInputSIn_word_off, verifyResultValueNibble8,
			"BTOD off", 1, 0},
	{55, ML_CODE_BTOD, setCodeOp2_DW1DN2, setInputSIn_word_on, verifyResultValueNibble8,
			"BTOD on 257", 1, 257},
	{56, ML_CODE_BTOD, setCodeOp2_DW1DN2, setInputSIn_word_maxint_on, verifyResultValueNibble8,
			"BTOD on 32767", 1, 32767},
	{57, ML_CODE_BTOD, setCodeOp2_maxintK1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"BTOD off", 1, 0},
	{58, ML_CODE_BTOD, setCodeOp2_maxintK1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"BTOD on K32767", 1, 32767},
	{59, ML_CODE_BTOD, setCodeOp2_negintK1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"BTOD on K-32768", 1, -32768},
	{60, ML_CODE_BTOD, setCodeOp2_N1DN2, setInputSIn_val16_N_W_off, verifyResultValueNibble8,
			"BTOD off", 1, 0},
	{61, ML_CODE_BTOD, setCodeOp2_N1DN2, setInputSIn_val16_N_W_on, verifyResultValueNibble8,
			"BTOD on  N257", 1, 257},
	{62, ML_CODE_BTOD, setCodeOp2_N1DN2, setInputSIn_val16_N_W_max_on, verifyResultValueNibble8,
			"BTOD on N32767", 1, 32767},

	{63, ML_CODE_BTODP, setCodeOp2_DW1DN2, setInputSIn_word_off, verifyResultValueNibble8,
			"BTODP 0->0", 2, 0},
	{64, ML_CODE_BTODP, setCodeOp2_DW1DN2, setInputSIn_word_tr1, verifyResultValueNibble8,
			"BTODP 0->1 257", 2, 257},
	{65, ML_CODE_BTODP, setCodeOp2_DW1DN2, setInputSIn_word_maxint_tr1, verifyResultValueNibble8,
			"BTODP 0->1 32767", 2, 32767},
	{66, ML_CODE_BTODP, setCodeOp2_maxintK1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"BTODP 0->0", 2, 0},
	{67, ML_CODE_BTODP, setCodeOp2_maxintK1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"BTODP 0->1 K32767", 2, 32767},
	{68, ML_CODE_BTODP, setCodeOp2_negintK1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"BTODP 0->1 K-32768", 2, -32768},
	{69, ML_CODE_BTODP, setCodeOp2_N1DN2, setInputSIn_val16_N_W_off, verifyResultValueNibble8,
			"BTODP 0->0 N257", 2, 0},
	{70, ML_CODE_BTODP, setCodeOp2_N1DN2, setInputSIn_val16_N_W_tr1, verifyResultValueNibble8,
			"BTODP 0->1 N257", 2, 257},
	{71, ML_CODE_BTODP, setCodeOp2_N1DN2, setInputSIn_val16_N_W_max_tr1, verifyResultValueNibble8,
			"BTODP 0->1 N32767", 2, 32767},

	{72, ML_CODE_DTOGRY, setCodeOp2_DW1DN2, setInputSIn_gray_DW_off, verifyResultValueNibble8,
			"DTOGRY off", 1, 0},
	{73, ML_CODE_DTOGRY, setCodeOp2_DW1DN2, setInputSIn_gray_DW_on, verifyResultValueNibble8,
			"DTOGRY on 305419896", 1, 0x1B2E7D44},
	{74, ML_CODE_DTOGRY, setCodeOp2_GDK1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"DTOGRY off", 1, 0},
	{75, ML_CODE_DTOGRY, setCodeOp2_GDK1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"DTOGRY K on", 1, 0x1B2E7D44},
	{76, ML_CODE_DTOGRY, setCodeOp2_DN1DN2, setInputSIn_gray_DN_W_off, verifyResultValueNibble8,
			"DTOGRY off", 1, 0},
	{77, ML_CODE_DTOGRY, setCodeOp2_DN1DN2, setInputSIn_gray_DN_W_on, verifyResultValueNibble8,
			"DTOGRY on", 1, 0x1B2E7D44},

	{78, ML_CODE_DTOGRYP, setCodeOp2_DW1DN2, setInputSIn_gray_DW_off, verifyResultValueNibble8,
			"DTOGRYP 0->0", 2, 0},
	{79, ML_CODE_DTOGRYP, setCodeOp2_DW1DN2, setInputSIn_gray_DW_tr1, verifyResultValueNibble8,
			"DTOGRYP 0->1 305419896", 2, 0x1B2E7D44},
	{80, ML_CODE_DTOGRYP, setCodeOp2_GDK1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"DTOGRYP 0->0 K305419896", 2, 0},
	{81, ML_CODE_DTOGRYP, setCodeOp2_GDK1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"DTOGRYP 0->1 K305419896", 2, 0x1B2E7D44},
	{82, ML_CODE_DTOGRYP, setCodeOp2_DN1DN2, setInputSIn_gray_DN_W_off, verifyResultValueNibble8,
			"DTOGRYP 0->0 N305419896", 2, 0},
	{83, ML_CODE_DTOGRYP, setCodeOp2_DN1DN2, setInputSIn_gray_DN_W_tr1, verifyResultValueNibble8,
			"DTOGRYP 0->1 N305419896", 2, 0x1B2E7D44},

	{84, ML_CODE_GRYTOD, setCodeOp2_DW1DN2, setInputSIn_inv_gray_DW_off, verifyResultValueNibble8,
			"GRYTOD off", 1, 0},
	{85, ML_CODE_GRYTOD, setCodeOp2_DW1DN2, setInputSIn_inv_gray_DW_on, verifyResultValueNibble8,
			"GRYTOD on 0x1B2E7D44", 1, 305419896},
	{86, ML_CODE_GRYTOD, setCodeOp2_IGDK1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"GRYTOD off K0x1B2E7D44", 1, 0},
	{87, ML_CODE_GRYTOD, setCodeOp2_IGDK1_DN2, setInputSIn_none_on, verifyResultValueNibble8,
			"GRYTOD on K0x1B2E7D44", 1, 305419896},
	{88, ML_CODE_GRYTOD, setCodeOp2_DN1DN2, setInputSIn_inv_gray_DN_W_off, verifyResultValueNibble8,
			"GRYTOD off N0x1B2E7D44", 1, 0},
	{89, ML_CODE_GRYTOD, setCodeOp2_DN1DN2, setInputSIn_inv_gray_DN_W_on, verifyResultValueNibble8,
			"GRYTOD on N0x1B2E7D44", 1, 305419896},

	{90, ML_CODE_GRYTODP, setCodeOp2_DW1DN2, setInputSIn_inv_gray_DW_off, verifyResultValueNibble8,
			"GRYTODP 0->0", 2, 0},
	{91, ML_CODE_GRYTODP, setCodeOp2_DW1DN2, setInputSIn_inv_gray_DW_tr1, verifyResultValueNibble8,
			"GRYTODP 0->1 0x1B2E7D44", 2, 305419896},
	{92, ML_CODE_GRYTODP, setCodeOp2_IGDK1_DN2, setInputSIn_none_off, verifyResultValueNibble8,
			"GRYTODP 0->0 K0x1B2E7D44", 2, 0},
	{93, ML_CODE_GRYTODP, setCodeOp2_IGDK1_DN2, setInputSIn_none_tr1, verifyResultValueNibble8,
			"GRYTODP 0->1 K0x1B2E7D44", 2, 305419896},
	{94, ML_CODE_GRYTODP, setCodeOp2_DN1DN2, setInputSIn_inv_gray_DN_W_off, verifyResultValueNibble8,
			"GRYTODP 0->0 N0x1B2E7D44", 2, 0},
	{95, ML_CODE_GRYTODP, setCodeOp2_DN1DN2, setInputSIn_inv_gray_DN_W_tr1, verifyResultValueNibble8,
			"GRYTODP 0->1 N0x1B2E7D44", 2, 305419896},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};

int total_conversion_dword_nb_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_conversion_dword_nb_test_number; i++)
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


int setCodeOp2_DK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in_val=10101;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_DKB1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in_val=0x10101;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxDK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in_val=99999999;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxDKB1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in_val=0x99999999;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxintK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in_val=32767;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_negintK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in_val=-32768;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxE1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	float in_val=9999999.0;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_minE1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	float in_val=-9999999.0;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_upE1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	float in_val=101.5;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_N1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_GDK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in_val=305419896;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_IGDK1_DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in_val=0x1B2E7D44;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}};

	return pos[inx_pos][reg];
}


static FILE *flog;
void test_basic_conversion_dword_nb(int tno, uint16 dummy)
{
	int i=1, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos;
	int res_dword;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in, i);

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
							test_getNibble(&res_dword, out, out_pos, 8);
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


void testConversionDWordNibbleCommand(void)
{
	int i, index=47;
	int start, end;
	char log[] = "err_conv_dword_nb.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("conversion dword nibble LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
	test_basic_conversion_dword_nb(index, 0);

#else
	total_conversion_dword_nb_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DTOBCD); //ML_CODE_DTOBCD
	end = getTestCaseNumberEnd(ML_CODE_GRYTODP); //ML_CODE_GRYTODP

	DBG_LOGPRINT("testConversionDWordNibbleCommand: %d to %d total %d\n", start, end, total_conversion_dword_nb_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_conversion_dword_nb(index, 0);
	}
#endif
	fclose(flog);
}
#endif
