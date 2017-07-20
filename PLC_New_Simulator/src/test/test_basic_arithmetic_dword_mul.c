/*
 * test_basic_arithmetic_dword_mul.c
 *
 *  Created on: Aug 17, 2015
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

extern void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

int setCodeOp3_DWDW_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_WDK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_WDN2_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DNW2_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DNDK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DNDN_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DKW_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_2DK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DKDN_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

int setCodeOp3_WDBK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DNDBK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DBKW_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_2DBK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DBKDN_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputOp3_Val32_DWDW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DWDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DWDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DWDK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DWDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DWDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_WDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_WDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_WDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DNW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DNW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DNW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DNDK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DNDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DNDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DNDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DKW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DKW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DKW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DKDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DKDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DKDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputOp3_BCD8_DWDW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DWDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_DWDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DWDK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DWDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_DWDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_WDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_WDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_WDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DNW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DNW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_DNW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DNDK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DNDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_DNDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DNDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_DNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DKW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DKW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_DKW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DKDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DKDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_DKDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);


int verifyResultValueLWord(int tcase, uint8 dest_reg, uint16 pos, long long expected);

static int show_log=1;
typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, long long);
	char str[40];
	//int count;
	int run_step;
	long long expected;

} testFn_st;


static testFn_st testCase[]={
	{0, ML_CODE_DMLT, setCodeOp3_DWDW_QW, setInputOp3_Val32_DWDW_off, verifyResultValueLWord,
			"DMLT off op3=op1*op2", 1, 0},
	{1, ML_CODE_DMLT, setCodeOp3_DWDW_QW, setInputOp3_Val32_DWDW_on, verifyResultValueLWord,
			"DMLT on op3=op1*op2", 1, 70109427840L},
	{2, ML_CODE_DMLT, setCodeOp3_WDK_QW, setInputOp3_Val32_DWDK_off, verifyResultValueLWord,
			"DMLT off op3=op1*DK", 1, 0},
	{3, ML_CODE_DMLT, setCodeOp3_WDK_QW, setInputOp3_Val32_DWDK_on, verifyResultValueLWord,
			"DMLT on op3=op1*DK", 1, 70109427840L},
	{4, ML_CODE_DMLT, setCodeOp3_WDN2_QW, setInputOp3_Val32_WDN_off, verifyResultValueLWord,
			"DMLT off op3=op1*nop2", 1, 0},
	{5, ML_CODE_DMLT, setCodeOp3_WDN2_QW, setInputOp3_Val32_WDN_on, verifyResultValueLWord,
			"DMLT on op3=op1*nop2", 1, 70109427840L},
	{6, ML_CODE_DMLT, setCodeOp3_DNW2_QW, setInputOp3_Val32_DNW_off, verifyResultValueLWord,
			"DMLT off op3=nop1*op2", 1, 0},
	{7, ML_CODE_DMLT, setCodeOp3_DNW2_QW, setInputOp3_Val32_DNW_on, verifyResultValueLWord,
			"DMLT on op3=nop1*op2", 1, 70109427840L},
	{8, ML_CODE_DMLT, setCodeOp3_DNDK_QW, setInputOp3_Val32_DNDK_off, verifyResultValueLWord,
			"DMLT off op3=nop1*K", 1, 0},
	{9, ML_CODE_DMLT, setCodeOp3_DNDK_QW, setInputOp3_Val32_DNDK_on, verifyResultValueLWord,
			"DMLT on op3=nop1*K", 1, 70109427840L},
	{10, ML_CODE_DMLT, setCodeOp3_DNDN_QW, setInputOp3_Val32_DNDN_off, verifyResultValueLWord,
			"DMLT off op3=nop1*nop2", 1, 0},
	{11, ML_CODE_DMLT, setCodeOp3_DNDN_QW, setInputOp3_Val32_DNDN_on, verifyResultValueLWord,
			"DMLT on op3=nop1*nop2", 1, 70109427840L},
	{12, ML_CODE_DMLT, setCodeOp3_DKW_QW, setInputOp3_Val32_DKW_off, verifyResultValueLWord,
			"DMLT off op3=DK*op2", 1, 0},
	{13, ML_CODE_DMLT, setCodeOp3_DKW_QW, setInputOp3_Val32_DKW_on, verifyResultValueLWord,
			"DMLT on op3=DK*op2", 1, 70109427840L},
	{14, ML_CODE_DMLT, setCodeOp3_2DK_QW, setInputNIn_Val16_off, verifyResultValueLWord,
			"DMLT off op3=DK*DK", 1, 0},
	{15, ML_CODE_DMLT, setCodeOp3_2DK_QW, setInputNIn_Val16_on, verifyResultValueLWord,
			"DMLT on op3=DK*DK", 1, 70109427840L},
	{16, ML_CODE_DMLT, setCodeOp3_DKDN_QW, setInputOp3_Val32_DKDN_off, verifyResultValueLWord,
			"DMLT off op3=DK*nop2", 1, 0},
	{17, ML_CODE_DMLT, setCodeOp3_DKDN_QW, setInputOp3_Val32_DKDN_on, verifyResultValueLWord,
			"DMLT on op3=DK*nop2", 1, 70109427840L},

	{18, ML_CODE_DMLTP, setCodeOp3_DWDW_QW, setInputOp3_Val32_DWDW_off, verifyResultValueLWord,
			"DMLTP 0->0 op3=op1*op2", 2, 0},
	{19, ML_CODE_DMLTP, setCodeOp3_DWDW_QW, setInputOp3_Val32p_DWDW_on, verifyResultValueLWord,
			"DMLTP 0->1 op3=op1*op2", 2, 70109427840L},
	{20, ML_CODE_DMLTP, setCodeOp3_WDK_QW, setInputOp3_Val32_DWDK_off, verifyResultValueLWord,
			"DMLTP 0->0 op3=op1*DK", 2, 0},
	{21, ML_CODE_DMLTP, setCodeOp3_WDK_QW, setInputOp3_Val32p_DWDK_on, verifyResultValueLWord,
			"DMLTP 0->1 op3=op1*DK", 2, 70109427840L},
	{22, ML_CODE_DMLTP, setCodeOp3_WDN2_QW, setInputOp3_Val32_WDN_off, verifyResultValueLWord,
			"DMLTP 0->0 op3=op1*nop2", 2, 0},
	{23, ML_CODE_DMLTP, setCodeOp3_WDN2_QW, setInputOp3_Val32p_WDN_on, verifyResultValueLWord,
			"DMLTP 0->1 op3=op1*nop2", 2, 70109427840L},
	{24, ML_CODE_DMLTP, setCodeOp3_DNW2_QW, setInputOp3_Val32_DNW_off, verifyResultValueLWord,
			"DMLTP 0->0 op3=nop1*op2", 2, 0},
	{25, ML_CODE_DMLTP, setCodeOp3_DNW2_QW, setInputOp3_Val32p_DNW_on, verifyResultValueLWord,
			"DMLTP 0->1 op3=nop1*op2", 2, 70109427840L},
	{26, ML_CODE_DMLTP, setCodeOp3_DNDK_QW, setInputOp3_Val32_DNDK_off, verifyResultValueLWord,
			"DMLTP 0->0 op3=nop1*K", 2, 0},
	{27, ML_CODE_DMLTP, setCodeOp3_DNDK_QW, setInputOp3_Val32p_DNDK_on, verifyResultValueLWord,
			"DMLTP 0->1 op3=nop1*K", 2, 70109427840L},
	{28, ML_CODE_DMLTP, setCodeOp3_DNDN_QW, setInputOp3_Val32_DNDN_off, verifyResultValueLWord,
			"DMLTP 0->0 op3=nop1*nop2", 2, 0},
	{29, ML_CODE_DMLTP, setCodeOp3_DNDN_QW, setInputOp3_Val32p_DNDN_on, verifyResultValueLWord,
			"DMLTP 0->1 op3=nop1*nop2", 2, 70109427840L},
	{30, ML_CODE_DMLTP, setCodeOp3_DKW_QW, setInputOp3_Val32_DKW_off, verifyResultValueLWord,
			"DMLTP 0->0 op3=DK*op2", 2, 0},
	{31, ML_CODE_DMLTP, setCodeOp3_DKW_QW, setInputOp3_Val32p_DKW_on, verifyResultValueLWord,
			"DMLTP 0->1 op3=DK*op2", 2, 70109427840L},
	{32, ML_CODE_DMLTP, setCodeOp3_2DK_QW, setInputNIn_Val16_off, verifyResultValueLWord,
			"DMLTP 0->0 op3=DK*DK", 2, 0},
	{33, ML_CODE_DMLTP, setCodeOp3_2DK_QW, setInputNIn_Val16p_on, verifyResultValueLWord,
			"DMLTP 0->1 op3=DK*DK", 2, 70109427840L},
	{34, ML_CODE_DMLTP, setCodeOp3_DKDN_QW, setInputOp3_Val32_DKDN_off, verifyResultValueLWord,
			"DMLTP 0->0 op3=DK*nop2", 2, 0},
	{35, ML_CODE_DMLTP, setCodeOp3_DKDN_QW, setInputOp3_Val32p_DKDN_on, verifyResultValueLWord,
			"DMLTP 0->1 op3=DK*nop2", 2, 70109427840L},

	{36, ML_CODE_DDIV, setCodeOp3_DWDW_QW, setInputOp3_Val32_DWDW_off, verifyResultValueLWord,
			"DDIV off op3=op1/op2", 1, 0},
	{37, ML_CODE_DDIV, setCodeOp3_DWDW_QW, setInputOp3_Val32_DWDW_on, verifyResultValueLWord,
			"DDIV on op3=op1/op2", 1, 318111047745540}, //4, 74066
	{38, ML_CODE_DDIV, setCodeOp3_WDK_QW, setInputOp3_Val32_DWDK_off, verifyResultValueLWord,
			"DDIV off op3=op1/DK", 1, 0},
	{39, ML_CODE_DDIV, setCodeOp3_WDK_QW, setInputOp3_Val32_DWDK_on, verifyResultValueLWord,
			"DDIV on op3=op1/DK", 1, 318111047745540}, //4, 74066
	{40, ML_CODE_DDIV, setCodeOp3_WDN2_QW, setInputOp3_Val32_WDN_off, verifyResultValueLWord,
			"DDIV off op3=op1/nop2", 1, 0},
	{41, ML_CODE_DDIV, setCodeOp3_WDN2_QW, setInputOp3_Val32_WDN_on, verifyResultValueLWord,
			"DDIV on op3=op1/nop2", 1, 318111047745540}, //4, 74066
	{42, ML_CODE_DDIV, setCodeOp3_DNW2_QW, setInputOp3_Val32_DNW_off, verifyResultValueLWord,
			"DDIV off op3=nop1/op2", 1, 0},
	{43, ML_CODE_DDIV, setCodeOp3_DNW2_QW, setInputOp3_Val32_DNW_on, verifyResultValueLWord,
			"DDIV on op3=nop1/op2", 1, 318111047745540}, //4, 74066
	{44, ML_CODE_DDIV, setCodeOp3_DNDK_QW, setInputOp3_Val32_DNDK_off, verifyResultValueLWord,
			"DDIV off op3=nop1/K", 1, 0},
	{45, ML_CODE_DDIV, setCodeOp3_DNDK_QW, setInputOp3_Val32_DNDK_on, verifyResultValueLWord,
			"DDIV on op3=nop1/K", 1, 318111047745540}, //4, 74066
	{46, ML_CODE_DDIV, setCodeOp3_DNDN_QW, setInputOp3_Val32_DNDN_off, verifyResultValueLWord,
			"DDIV off op3=nop1/nop2", 1, 0},
	{47, ML_CODE_DDIV, setCodeOp3_DNDN_QW, setInputOp3_Val32_DNDN_on, verifyResultValueLWord,
			"DDIV on op3=nop1/nop2", 1, 318111047745540}, //4, 74066
	{48, ML_CODE_DDIV, setCodeOp3_DKW_QW, setInputOp3_Val32_DKW_off, verifyResultValueLWord,
			"DDIV off op3=DK/op2", 1, 0},
	{49, ML_CODE_DDIV, setCodeOp3_DKW_QW, setInputOp3_Val32_DKW_on, verifyResultValueLWord,
			"DDIV on op3=DK/op2", 1, 318111047745540}, //4, 74066
	{50, ML_CODE_DDIV, setCodeOp3_2DK_QW, setInputNIn_Val16_off, verifyResultValueLWord,
			"DDIV off op3=DK/DK", 1, 0},
	{51, ML_CODE_DDIV, setCodeOp3_2DK_QW, setInputNIn_Val16_on, verifyResultValueLWord,
			"DDIV on op3=DK/DK", 1, 318111047745540}, //4, 74066
	{52, ML_CODE_DDIV, setCodeOp3_DKDN_QW, setInputOp3_Val32_DKDN_off, verifyResultValueLWord,
			"DDIV off op3=DK/nop2", 1, 0},
	{53, ML_CODE_DDIV, setCodeOp3_DKDN_QW, setInputOp3_Val32_DKDN_on, verifyResultValueLWord,
			"DDIV on op3=DK/nop2", 1, 318111047745540}, //4, 74066

	{54, ML_CODE_DDIVP, setCodeOp3_DWDW_QW, setInputOp3_Val32_DWDW_off, verifyResultValueLWord,
			"DDIVP 0->0 op3=op1/op2", 2, 0},
	{55, ML_CODE_DDIVP, setCodeOp3_DWDW_QW, setInputOp3_Val32p_DWDW_on, verifyResultValueLWord,
			"DDIVP 0->1 op3=op1/op2", 2, 318111047745540}, //4, 74066
	{56, ML_CODE_DDIVP, setCodeOp3_WDK_QW, setInputOp3_Val32_DWDK_off, verifyResultValueLWord,
			"DDIVP 0->0 op3=op1/DK", 2, 0},
	{57, ML_CODE_DDIVP, setCodeOp3_WDK_QW, setInputOp3_Val32p_DWDK_on, verifyResultValueLWord,
			"DDIVP 0->1 op3=op1/DK", 2, 318111047745540}, //4, 74066
	{58, ML_CODE_DDIVP, setCodeOp3_WDN2_QW, setInputOp3_Val32_WDN_off, verifyResultValueLWord,
			"DDIVP 0->0 op3=op1/nop2", 2, 0},
	{59, ML_CODE_DDIVP, setCodeOp3_WDN2_QW, setInputOp3_Val32p_WDN_on, verifyResultValueLWord,
			"DDIVP 0->1 op3=op1/nop2", 2, 318111047745540}, //4, 74066
	{60, ML_CODE_DDIVP, setCodeOp3_DNW2_QW, setInputOp3_Val32_DNW_off, verifyResultValueLWord,
			"DDIVP 0->0 op3=nop1/op2", 2, 0},
	{61, ML_CODE_DDIVP, setCodeOp3_DNW2_QW, setInputOp3_Val32p_DNW_on, verifyResultValueLWord,
			"DDIVP 0->1 op3=nop1/op2", 2, 318111047745540}, //4, 74066
	{62, ML_CODE_DDIVP, setCodeOp3_DNDK_QW, setInputOp3_Val32_DNDK_off, verifyResultValueLWord,
			"DDIVP 0->0 op3=nop1/K", 2, 0},
	{63, ML_CODE_DDIVP, setCodeOp3_DNDK_QW, setInputOp3_Val32p_DNDK_on, verifyResultValueLWord,
			"DDIVP 0->1 op3=nop1/K", 2, 318111047745540}, //4, 74066
	{64, ML_CODE_DDIVP, setCodeOp3_DNDN_QW, setInputOp3_Val32_DNDN_off, verifyResultValueLWord,
			"DDIVP 0->0 op3=nop1/nop2", 2, 0},
	{65, ML_CODE_DDIVP, setCodeOp3_DNDN_QW, setInputOp3_Val32p_DNDN_on, verifyResultValueLWord,
			"DDIVP 0->1 op3=nop1/nop2", 2, 318111047745540}, //4, 74066
	{66, ML_CODE_DDIVP, setCodeOp3_DKW_QW, setInputOp3_Val32_DKW_off, verifyResultValueLWord,
			"DDIVP 0->0 op3=DK/op2", 2, 0},
	{67, ML_CODE_DDIVP, setCodeOp3_DKW_QW, setInputOp3_Val32p_DKW_on, verifyResultValueLWord,
			"DDIVP 0->1 op3=DK/op2", 2, 318111047745540}, //4, 74066
	{68, ML_CODE_DDIVP, setCodeOp3_2DK_QW, setInputNIn_Val16_off, verifyResultValueLWord,
			"DDIVP 0->0 op3=DK/DK", 2, 0},
	{69, ML_CODE_DDIVP, setCodeOp3_2DK_QW, setInputNIn_Val16p_on, verifyResultValueLWord,
			"DDIVP 0->1 op3=DK/DK", 2, 318111047745540}, //4, 74066
	{70, ML_CODE_DDIVP, setCodeOp3_DKDN_QW, setInputOp3_Val32_DKDN_off, verifyResultValueLWord,
			"DDIVP 0->0 op3=DK/nop2", 2, 0},
	{71, ML_CODE_DDIVP, setCodeOp3_DKDN_QW, setInputOp3_Val32p_DKDN_on, verifyResultValueLWord,
			"DDIVP 0->1 op3=DK/nop2", 2, 318111047745540}, //4, 74066

	{72, ML_CODE_DBMLT, setCodeOp3_DWDW_QW, setInputOp3_BCD8_DWDW_off, verifyResultValueLWord,
			"DBMLT off op3=op1*op2", 1, 0},
	{73, ML_CODE_DBMLT, setCodeOp3_DWDW_QW, setInputOp3_BCD8_DWDW_on, verifyResultValueLWord,
			"DBMLT on op3=op1*op2", 1, 0x70109977214741},
	{74, ML_CODE_DBMLT, setCodeOp3_WDBK_QW, setInputOp3_BCD8_DWDK_off, verifyResultValueLWord,
			"DBMLT off op3=op1*DBK", 1, 0},
	{75, ML_CODE_DBMLT, setCodeOp3_WDBK_QW, setInputOp3_BCD8_DWDK_on, verifyResultValueLWord,
			"DBMLT on op3=op1*DBK", 1, 0x70109977214741},
	{76, ML_CODE_DBMLT, setCodeOp3_WDN2_QW, setInputOp3_BCD8_WDN_off, verifyResultValueLWord,
			"DBMLT off op3=op1*nop2", 1, 0},
	{77, ML_CODE_DBMLT, setCodeOp3_WDN2_QW, setInputOp3_BCD8_WDN_on, verifyResultValueLWord,
			"DBMLT on op3=op1*nop2", 1, 0x70109977214741},
	{78, ML_CODE_DBMLT, setCodeOp3_DNW2_QW, setInputOp3_BCD8_DNW_off, verifyResultValueLWord,
			"DBMLT off op3=nop1*op2", 1, 0},
	{79, ML_CODE_DBMLT, setCodeOp3_DNW2_QW, setInputOp3_BCD8_DNW_on, verifyResultValueLWord,
			"DBMLT on op3=nop1*op2", 1, 0x70109977214741},
	{80, ML_CODE_DBMLT, setCodeOp3_DNDBK_QW, setInputOp3_BCD8_DNDK_off, verifyResultValueLWord,
			"DBMLT off op3=nop1*DBK", 1, 0},
	{81, ML_CODE_DBMLT, setCodeOp3_DNDBK_QW, setInputOp3_BCD8_DNDK_on, verifyResultValueLWord,
			"DBMLT on op3=nop1*DBK", 1, 0x70109977214741},
	{82, ML_CODE_DBMLT, setCodeOp3_DNDN_QW, setInputOp3_BCD8_DNDN_off, verifyResultValueLWord,
			"DBMLT off op3=nop1*nop2", 1, 0},
	{83, ML_CODE_DBMLT, setCodeOp3_DNDN_QW, setInputOp3_BCD8_DNDN_on, verifyResultValueLWord,
			"DBMLT on op3=nop1*nop2", 1, 0x70109977214741},
	{84, ML_CODE_DBMLT, setCodeOp3_DBKW_QW, setInputOp3_BCD8_DKW_off, verifyResultValueLWord,
			"DBMLT off op3=DBK*op2", 1, 0},
	{85, ML_CODE_DBMLT, setCodeOp3_DBKW_QW, setInputOp3_BCD8_DKW_on, verifyResultValueLWord,
			"DBMLT on op3=DBK*op2", 1, 0x70109977214741},
	{86, ML_CODE_DBMLT, setCodeOp3_2DBK_QW, setInputNIn_Val16_off, verifyResultValueLWord,
			"DBMLT off op3=DBK*DBK", 1, 0},
	{87, ML_CODE_DBMLT, setCodeOp3_2DBK_QW, setInputNIn_Val16_on, verifyResultValueLWord,
			"DBMLT on op3=DBK*DBK", 1, 0x70109977214741},
	{88, ML_CODE_DBMLT, setCodeOp3_DBKDN_QW, setInputOp3_BCD8_DKDN_off, verifyResultValueLWord,
			"DBMLT off op3=DBK*nop2", 1, 0},
	{89, ML_CODE_DBMLT, setCodeOp3_DBKDN_QW, setInputOp3_BCD8_DKDN_on, verifyResultValueLWord,
			"DBMLT on op3=DBK*nop2", 1, 0x70109977214741},

	{90, ML_CODE_DBMLTP, setCodeOp3_DWDW_QW, setInputOp3_BCD8_DWDW_off, verifyResultValueLWord,
			"DBMLTP 0->0 op3=op1*op2", 2, 0},
	{91, ML_CODE_DBMLTP, setCodeOp3_DWDW_QW, setInputOp3_BCD8p_DWDW_on, verifyResultValueLWord,
			"DBMLTP 0->1 op3=op1*op2", 2, 0x70109977214741},
	{92, ML_CODE_DBMLTP, setCodeOp3_WDBK_QW, setInputOp3_BCD8_DWDK_off, verifyResultValueLWord,
			"DBMLTP 0->0 op3=op1*DBK", 2, 0},
	{93, ML_CODE_DBMLTP, setCodeOp3_WDBK_QW, setInputOp3_BCD8p_DWDK_on, verifyResultValueLWord,
			"DBMLTP 0->1 op3=op1*DBK", 2, 0x70109977214741},
	{94, ML_CODE_DBMLTP, setCodeOp3_WDN2_QW, setInputOp3_BCD8_WDN_off, verifyResultValueLWord,
			"DBMLTP 0->0 op3=op1*nop2", 2, 0},
	{95, ML_CODE_DBMLTP, setCodeOp3_WDN2_QW, setInputOp3_BCD8p_WDN_on, verifyResultValueLWord,
			"DBMLTP 0->1 op3=op1*nop2", 2, 0x70109977214741},
	{96, ML_CODE_DBMLTP, setCodeOp3_DNW2_QW, setInputOp3_BCD8_DNW_off, verifyResultValueLWord,
			"DBMLTP 0->0 op3=nop1*op2", 2, 0},
	{97, ML_CODE_DBMLTP, setCodeOp3_DNW2_QW, setInputOp3_BCD8p_DNW_on, verifyResultValueLWord,
			"DBMLTP 0->1 op3=nop1*op2", 2, 0x70109977214741},
	{98, ML_CODE_DBMLTP, setCodeOp3_DNDBK_QW, setInputOp3_BCD8_DNDK_off, verifyResultValueLWord,
			"DBMLTP 0->0 op3=nop1*DBK", 2, 0},
	{99, ML_CODE_DBMLTP, setCodeOp3_DNDBK_QW, setInputOp3_BCD8p_DNDK_on, verifyResultValueLWord,
			"DBMLTP 0->1 op3=nop1*DBK", 2, 0x70109977214741},
	{100, ML_CODE_DBMLTP, setCodeOp3_DNDN_QW, setInputOp3_BCD8_DNDN_off, verifyResultValueLWord,
			"DBMLTP 0->0 op3=nop1*nop2", 2, 0},
	{101, ML_CODE_DBMLTP, setCodeOp3_DNDN_QW, setInputOp3_BCD8p_DNDN_on, verifyResultValueLWord,
			"DBMLTP 0->1 op3=nop1*nop2", 2, 0x70109977214741},
	{102, ML_CODE_DBMLTP, setCodeOp3_DBKW_QW, setInputOp3_BCD8_DKW_off, verifyResultValueLWord,
			"DBMLTP 0->0 op3=DBK*op2", 2, 0},
	{103, ML_CODE_DBMLTP, setCodeOp3_DBKW_QW, setInputOp3_BCD8p_DKW_on, verifyResultValueLWord,
			"DBMLTP 0->1 op3=DBK*op2", 2, 0x70109977214741},
	{104, ML_CODE_DBMLTP, setCodeOp3_2DBK_QW, setInputNIn_Val16_off, verifyResultValueLWord,
			"DBMLTP 0->0 op3=DBK*DBK", 2, 0},
	{105, ML_CODE_DBMLTP, setCodeOp3_2DBK_QW, setInputNIn_Val16p_on, verifyResultValueLWord,
			"DBMLTP 0->1 op3=DBK*DBK", 2, 0x70109977214741},
	{106, ML_CODE_DBMLTP, setCodeOp3_DBKDN_QW, setInputOp3_BCD8_DKDN_off, verifyResultValueLWord,
			"DBMLTP 0->0 op3=DBK*nop2", 2, 0},
	{107, ML_CODE_DBMLTP, setCodeOp3_DBKDN_QW, setInputOp3_BCD8p_DKDN_on, verifyResultValueLWord,
			"DBMLTP 0->1 op3=DBK*nop2", 2, 0x70109977214741},

	{108, ML_CODE_DBDIV, setCodeOp3_DWDW_QW, setInputOp3_BCD8_DWDW_off, verifyResultValueLWord,
			"DBDIV off op3=op1/op2", 1, 0},
	{109, ML_CODE_DBDIV, setCodeOp3_DWDW_QW, setInputOp3_BCD8_DWDW_on, verifyResultValueLWord,
			"DBDIV on op3=op1/op2", 1, 0x123360800000045}, // 45, 1233608
	{110, ML_CODE_DBDIV, setCodeOp3_WDBK_QW, setInputOp3_BCD8_DWDK_off, verifyResultValueLWord,
			"DBDIV off op3=op1/DBK", 1, 0},
	{111, ML_CODE_DBDIV, setCodeOp3_WDBK_QW, setInputOp3_BCD8_DWDK_on, verifyResultValueLWord,
			"DBDIV on op3=op1/DBK", 1, 0x123360800000045}, // 45, 1233608
	{112, ML_CODE_DBDIV, setCodeOp3_WDN2_QW, setInputOp3_BCD8_WDN_off, verifyResultValueLWord,
			"DBDIV off op3=op1/nop2", 1, 0},
	{113, ML_CODE_DBDIV, setCodeOp3_WDN2_QW, setInputOp3_BCD8_WDN_on, verifyResultValueLWord,
			"DBDIV on op3=op1/nop2", 1, 0x123360800000045}, // 45, 1233608
	{114, ML_CODE_DBDIV, setCodeOp3_DNW2_QW, setInputOp3_BCD8_DNW_off, verifyResultValueLWord,
			"DBDIV off op3=nop1/op2", 1, 0},
	{115, ML_CODE_DBDIV, setCodeOp3_DNW2_QW, setInputOp3_BCD8_DNW_on, verifyResultValueLWord,
			"DBDIV on op3=nop1/op2", 1, 0x123360800000045}, // 45, 1233608
	{116, ML_CODE_DBDIV, setCodeOp3_DNDBK_QW, setInputOp3_BCD8_DNDK_off, verifyResultValueLWord,
			"DBDIV off op3=nop1/DBK", 1, 0},
	{117, ML_CODE_DBDIV, setCodeOp3_DNDBK_QW, setInputOp3_BCD8_DNDK_on, verifyResultValueLWord,
			"DBDIV on op3=nop1/DBK", 1, 0x123360800000045}, // 45, 1233608
	{118, ML_CODE_DBDIV, setCodeOp3_DNDN_QW, setInputOp3_BCD8_DNDN_off, verifyResultValueLWord,
			"DBDIV off op3=nop1/nop2", 1, 0},
	{119, ML_CODE_DBDIV, setCodeOp3_DNDN_QW, setInputOp3_BCD8_DNDN_on, verifyResultValueLWord,
			"DBDIV on op3=nop1/nop2", 1, 0x123360800000045}, // 45, 1233608
	{120, ML_CODE_DBDIV, setCodeOp3_DBKW_QW, setInputOp3_BCD8_DKW_off, verifyResultValueLWord,
			"DBDIV off op3=DBK/op2", 1, 0},
	{121, ML_CODE_DBDIV, setCodeOp3_DBKW_QW, setInputOp3_BCD8_DKW_on, verifyResultValueLWord,
			"DBDIV on op3=DBK/op2", 1, 0x123360800000045}, // 45, 1233608
	{122, ML_CODE_DBDIV, setCodeOp3_2DBK_QW, setInputNIn_Val16_off, verifyResultValueLWord,
			"DBDIV off op3=DBK/DBK", 1, 0},
	{123, ML_CODE_DBDIV, setCodeOp3_2DBK_QW, setInputNIn_Val16_on, verifyResultValueLWord,
			"DBDIV on op3=DBK/DBK", 1, 0x123360800000045}, // 45, 1233608
	{124, ML_CODE_DBDIV, setCodeOp3_DBKDN_QW, setInputOp3_BCD8_DKDN_off, verifyResultValueLWord,
			"DBDIV off op3=DBK/nop2", 1, 0},
	{125, ML_CODE_DBDIV, setCodeOp3_DBKDN_QW, setInputOp3_BCD8_DKDN_on, verifyResultValueLWord,
			"DBDIV on op3=DBK/nop2", 1, 0x123360800000045}, // 45, 1233608

	{126, ML_CODE_DBDIVP, setCodeOp3_DWDW_QW, setInputOp3_BCD8_DWDW_off, verifyResultValueLWord,
			"DBDIVP 0->0 op3=op1/op2", 2, 0},
	{127, ML_CODE_DBDIVP, setCodeOp3_DWDW_QW, setInputOp3_BCD8p_DWDW_on, verifyResultValueLWord,
			"DBDIVP 0->1 op3=op1/op2", 2, 0x123360800000045}, // 45, 1233608
	{128, ML_CODE_DBDIVP, setCodeOp3_WDBK_QW, setInputOp3_BCD8_DWDK_off, verifyResultValueLWord,
			"DBDIVP 0->0 op3=op1/DBK", 2, 0},
	{129, ML_CODE_DBDIVP, setCodeOp3_WDBK_QW, setInputOp3_BCD8p_DWDK_on, verifyResultValueLWord,
			"DBDIVP 0->1 op3=op1/DBK", 2, 0x123360800000045}, // 45, 1233608
	{130, ML_CODE_DBDIVP, setCodeOp3_WDN2_QW, setInputOp3_BCD8_WDN_off, verifyResultValueLWord,
			"DBDIVP 0->0 op3=op1/nop2", 2, 0},
	{131, ML_CODE_DBDIVP, setCodeOp3_WDN2_QW, setInputOp3_BCD8p_WDN_on, verifyResultValueLWord,
			"DBDIVP 0->1 op3=op1/nop2", 2, 0x123360800000045}, // 45, 1233608
	{132, ML_CODE_DBDIVP, setCodeOp3_DNW2_QW, setInputOp3_BCD8_DNW_off, verifyResultValueLWord,
			"DBDIVP 0->0 op3=nop1/op2", 2, 0},
	{133, ML_CODE_DBDIVP, setCodeOp3_DNW2_QW, setInputOp3_BCD8p_DNW_on, verifyResultValueLWord,
			"DBDIVP 0->1 op3=nop1/op2", 2, 0x123360800000045}, // 45, 1233608
	{134, ML_CODE_DBDIVP, setCodeOp3_DNDBK_QW, setInputOp3_BCD8_DNDK_off, verifyResultValueLWord,
			"DBDIVP 0->0 op3=nop1/DBK", 2, 0},
	{135, ML_CODE_DBDIVP, setCodeOp3_DNDBK_QW, setInputOp3_BCD8p_DNDK_on, verifyResultValueLWord,
			"DBDIVP 0->1 op3=nop1/DBK", 2, 0x123360800000045}, // 45, 1233608
	{136, ML_CODE_DBDIVP, setCodeOp3_DNDN_QW, setInputOp3_BCD8_DNDN_off, verifyResultValueLWord,
			"DBDIVP 0->0 op3=nop1/nop2", 2, 0},
	{137, ML_CODE_DBDIVP, setCodeOp3_DNDN_QW, setInputOp3_BCD8p_DNDN_on, verifyResultValueLWord,
			"DBDIVP 0->1 op3=nop1/nop2", 2, 0x123360800000045}, // 45, 1233608
	{138, ML_CODE_DBDIVP, setCodeOp3_DBKW_QW, setInputOp3_BCD8_DKW_off, verifyResultValueLWord,
			"DBDIVP 0->0 op3=DBK/op2", 2, 0},
	{139, ML_CODE_DBDIVP, setCodeOp3_DBKW_QW, setInputOp3_BCD8p_DKW_on, verifyResultValueLWord,
			"DBDIVP 0->1 op3=DBK/op2", 2, 0x123360800000045}, // 45, 1233608
	{140, ML_CODE_DBDIVP, setCodeOp3_2DBK_QW, setInputNIn_Val16_off, verifyResultValueLWord,
			"DBDIVP 0->0 op3=DBK/DBK", 2, 0},
	{141, ML_CODE_DBDIVP, setCodeOp3_2DBK_QW, setInputNIn_Val16p_on, verifyResultValueLWord,
			"DBDIVP 0->1 op3=DBK/DBK", 2, 0x123360800000045}, // 45, 1233608
	{142, ML_CODE_DBDIVP, setCodeOp3_DBKDN_QW, setInputOp3_BCD8_DKDN_off, verifyResultValueLWord,
			"DBDIVP 0->0 op3=DBK/nop2", 2, 0},
	{143, ML_CODE_DBDIVP, setCodeOp3_DBKDN_QW, setInputOp3_BCD8p_DKDN_on, verifyResultValueLWord,
			"DBDIVP 0->1 op3=DBK/nop2", 2, 0x123360800000045}, // 45, 1233608

	{-1, 0xFFFF, NULL, NULL, NULL, " ", 0, 0 }
};

int total_basic_compute_dword_mul_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_dword_mul_test_number; i++)
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

int setCodeOp3_DWDW_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 160);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WDK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in2_val=123456;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WDN2_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(out_reg, in_pos); addMLOperandNibble(8, in_reg, 160);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DNW2_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperand(out_reg, 160);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DNDK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in2_val=123456;
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DNDN_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperandNibble(8, in_reg, 160);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


int setCodeOp3_DKW_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in1_val=567890;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in1_val); addMLOperand(in_reg, in_pos);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_2DK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in1_val=567890, in2_val=123456;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in1_val); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DKDN_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in1_val=567890;

	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in1_val); addMLOperandNibble(8, in_reg, in_pos);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WDBK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in2_val=0x1234567;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DNDBK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in2_val=0x1234567;
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DBKW_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in1_val=0x56789123;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in1_val); addMLOperand(in_reg, in_pos);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_2DBK_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in1_val); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DBKDN_QW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	int in1_val=0x56789123;

	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in1_val); addMLOperandNibble(8, in_reg, in_pos);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputOp3_Val32_DWDW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32_DWDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32p_DWDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32_DWDK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);

	TestCodeTearDown();
}

void setInputOp3_Val32_DWDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);

	TestCodeTearDown();
}

void setInputOp3_Val32p_DWDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);

	TestCodeTearDown();
}

void setInputOp3_Val32_WDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_WDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32p_WDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_DNW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_Val32_DNW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_Val32p_DNW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_Val32_DNDK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_DNDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32p_DNDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_DNDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_DNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32p_DNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_DKW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, in, in_pos, in1_val);

	TestCodeTearDown();
}

void setInputOp3_Val32_DKW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, in, in_pos, in1_val);

	TestCodeTearDown();
}

void setInputOp3_Val32p_DKW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, in, in_pos, in1_val);

	TestCodeTearDown();
}

void setInputOp3_Val32_DKDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_DKDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32p_DKDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWDW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DWDW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWDK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=0x56789123;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=0x56789123;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DWDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=0x56789123;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_WDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_WDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNDK_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNDK_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in1_val=0x56789123, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in1_val>>i)&0x01));
		addDeviceControlInstruction(0, in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DKW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, in, in_pos, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DKW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, in, in_pos, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DKW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in1_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, in, in_pos, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DKDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DKDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DKDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in2_val=0x1234567;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, in, in_pos+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}


int verifyResultValueLWord(int tcase, uint8 dest_reg, uint16 pos, long long expected)
{
	int rc=0;
	long long result;
	char reg[] = {'D', 'W'};

	if(!test_getLong(&result, dest_reg, pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d Reg %c[%d]=%lld %lld\n", tcase, reg[dest_reg-OPERAND_ML_CODE_D], pos, result, expected);
	CU_ASSERT_EQUAL(result, expected);
	if(result != expected) rc=1;

	return rc;
}


static uint16 getPos(int reg, int inx_pos)
{
	//uint16 pos[3][2]={ {0,0}, {6144,4096}, {12285,8189}}; // -2
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8128,8128,8128,8128,1984,8128,0,12284,8188}}; // 4 word

	return pos[inx_pos][reg];
}

static FILE *flog;

void test_basic_arithmetic_dword_mul(int tno, int dummy)
{
	int i=1, rc=0, rc2=0, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	long long res_long;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in, i);

					rc2=testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if(rc2==0) continue;

					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

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
						rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
						if(rc == 1)
						{
							test_getLong(&res_long, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%lld exp=%lld \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_long, testCase[tno].expected);
						}
					}
					//printf("testcase=%d\n", tno);
				}
			}
		}
	}
}



void testBasicArithmeticDWordMulCommand(void)
{
	int i, index=139;
	int start, end;
	char log[] = "err_arith_dwd_mul.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic dword mul div LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=126;index<136;index++)
	test_basic_arithmetic_dword_mul(index, 0);
#else
	total_basic_compute_dword_mul_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DMLT); //ML_CODE_DMLT
	end = getTestCaseNumberEnd(ML_CODE_DBDIVP); //ML_CODE_DBDIVP

	DBG_LOGPRINT("testBasicArithmeticDwordMulCommand: %d to %d total %d\n", start, end, total_basic_compute_dword_mul_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_dword_mul(index, 0);
	}


#endif
	fclose(flog);
}

#endif
