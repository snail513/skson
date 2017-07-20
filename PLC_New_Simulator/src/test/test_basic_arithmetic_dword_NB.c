/*
 * test_basic_arithmatic_dword_NB.c
 *
 *  Created on: Jul 8, 2015
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

extern void setInput2DIn_Val32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInput2DIn_Val32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInput2DIn_Val32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_Val32_K1W2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_Val32_K1W2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_Val32p_K1W2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected);

int setCodeOp1_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_DW1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_DK1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_DN1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DW1DW2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DK1DW2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DK1DK2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DN1DW2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DW1DN2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp2_DBK1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DBK1DW2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeOp3_DBK1DBK2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputOp2_Val32_DW1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32_DW1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32p_DW1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32_DW1DN2_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32_DW1DN2_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32_DK1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32_DK1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32p_DK1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32_DN1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32_DN1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32p_DN1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputOp1_Val32_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp1_Val32_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp1_Val32p_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp1_Val32_DN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp1_Val32p_DN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp1_Val32_DN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp1_Val32p_DN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputOp3_Val32_DWDWDN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DWDWDN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DWDWDN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DWDWDN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputOp3_Val32_DNDWDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DNDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DNDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DWDNDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32_DWDNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_Val32p_DWDNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputOp2_BCD8_DW1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8_DW1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8p_DW1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8_DW1DN2_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8p_DW1DN2_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8_DW1DN2_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8p_DW1DN2_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8_DK1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8_DK1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8p_DK1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8_DN1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8_DN1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_BCD8p_DN1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInput2DIn_BCD8_DWDWDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD8_DWDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD8p_DWDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD8_DWDWDN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD8p_DWDWDN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD8_DWDWDN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInput2DIn_BCD8p_DWDWDN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD8_DK1DW2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD8_DK1DW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_BCD8p_DK1DW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DNDWDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DNDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_DNDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DWDNDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8_DWDNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp3_BCD8p_DWDNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);


static int show_log=1;

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
	{0, ML_CODE_DADD, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_off, verifyResultValueNibble8,
			"DADD off op1+nop2", 1, 123456},
	{1, ML_CODE_DADD, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_on, verifyResultValueNibble8,
			"DADD on op1+nop2", 1, 691346},
	{2, ML_CODE_DADD, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_over_on, verifyResultValueNibble8,
			"DADD on op1+nop2 over", 1, -2147483647},
	{3, ML_CODE_DADD, setCodeOp2_DK1DN2, setInputOp2_Val32_DK1DN2_off, verifyResultValueNibble8,
			"DADD off K+nop2", 1, 123456},
	{4, ML_CODE_DADD, setCodeOp2_DK1DN2, setInputOp2_Val32_DK1DN2_on, verifyResultValueNibble8,
			"DADD on K+nop1", 1, 691346},
	{5, ML_CODE_DADD, setCodeOp2_DN1DN2, setInputOp2_Val32_DN1DN2_off, verifyResultValueNibble8,
			"DADD off nop1+nop2", 1, 123456},
	{6, ML_CODE_DADD, setCodeOp2_DN1DN2, setInputOp2_Val32_DN1DN2_on, verifyResultValueNibble8,
			"DADD on nop1+nop2", 1, 691346},

	{7, ML_CODE_DADDP, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_off, verifyResultValueNibble8,
			"DADDP 0->0 op1+nop2", 2, 123456},
	{8, ML_CODE_DADDP, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_on, verifyResultValueNibble8,
			"DADDP 1->1 op1+nop2", 2, 123456},
	{9, ML_CODE_DADDP, setCodeOp2_DW1DN2, setInputOp2_Val32p_DW1DN2_on, verifyResultValueNibble8,
			"DADDP 0->1 op1+nop2", 2, 691346},
	{10, ML_CODE_DADDP, setCodeOp2_DK1DN2, setInputOp2_Val32_DK1DN2_off, verifyResultValueNibble8,
			"DADDP 0->0 K+nop2", 2, 123456},
	{11, ML_CODE_DADDP, setCodeOp2_DK1DN2, setInputOp2_Val32_DK1DN2_on, verifyResultValueNibble8,
			"DADDP 1->1 K+nop1", 2, 123456},
	{12, ML_CODE_DADDP, setCodeOp2_DK1DN2, setInputOp2_Val32p_DK1DN2_on, verifyResultValueNibble8,
			"DADDP 0->1 K+nop1", 2, 691346},
	{13, ML_CODE_DADDP, setCodeOp2_DN1DN2, setInputOp2_Val32_DN1DN2_off, verifyResultValueNibble8,
			"DADDP 0->0 nop1+nop2", 2, 123456},
	{14, ML_CODE_DADDP, setCodeOp2_DN1DN2, setInputOp2_Val32_DN1DN2_on, verifyResultValueNibble8,
			"DADDP 1->1 nop1+nop2", 2, 123456},
	{15, ML_CODE_DADDP, setCodeOp2_DN1DN2, setInputOp2_Val32p_DN1DN2_on, verifyResultValueNibble8,
			"DADDP 0->1 nop1+nop2", 2, 691346},

	{16, ML_CODE_DSUB, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_off, verifyResultValueNibble8,
			"DSUB off nop2-op1", 1, 123456},
	{17, ML_CODE_DSUB, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_on, verifyResultValueNibble8,
			"DSUB on nop2-op1", 1, -444434},
	{18, ML_CODE_DSUB, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_under_on, verifyResultValueNibble8,
			"DSUB on nop2-op1 under", 1, 2147483646},
	{19, ML_CODE_DSUB, setCodeOp2_DK1DN2, setInputOp2_Val32_DK1DN2_off, verifyResultValueNibble8,
			"DSUB off nop2-K", 1, 123456},
	{20, ML_CODE_DSUB, setCodeOp2_DK1DN2, setInputOp2_Val32_DK1DN2_on, verifyResultValueNibble8,
			"DSUB on nop2-K", 1, -444434},
	{21, ML_CODE_DSUB, setCodeOp2_DN1DN2, setInputOp2_Val32_DN1DN2_off, verifyResultValueNibble8,
			"DSUB off nop2-nop1", 1, 123456},
	{22, ML_CODE_DSUB, setCodeOp2_DN1DN2, setInputOp2_Val32_DN1DN2_on, verifyResultValueNibble8,
			"DSUB on nop2-nop1", 1, -444434},

	{23, ML_CODE_DSUBP, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_off, verifyResultValueNibble8,
			"DSUBP 0->0 nop2-op1", 2, 123456},
	{24, ML_CODE_DSUBP, setCodeOp2_DW1DN2, setInputOp2_Val32_DW1DN2_on, verifyResultValueNibble8,
			"DSUBP 1->1 nop2-op1", 2, 123456},
	{25, ML_CODE_DSUBP, setCodeOp2_DW1DN2, setInputOp2_Val32p_DW1DN2_on, verifyResultValueNibble8,
			"DSUBP 0->1 nop2-op1", 2, -444434},
	{26, ML_CODE_DSUBP, setCodeOp2_DK1DN2, setInputOp2_Val32_DK1DN2_off, verifyResultValueNibble8,
			"DSUBP 0->0 nop2-K", 2, 123456},
	{27, ML_CODE_DSUBP, setCodeOp2_DK1DN2, setInputOp2_Val32_DK1DN2_on, verifyResultValueNibble8,
			"DSUBP 1->1 nop2-K", 2, 123456},
	{28, ML_CODE_DSUBP, setCodeOp2_DK1DN2, setInputOp2_Val32p_DK1DN2_on, verifyResultValueNibble8,
			"DSUBP 0->1 nop2-K", 2, -444434},
	{29, ML_CODE_DSUBP, setCodeOp2_DN1DN2, setInputOp2_Val32_DN1DN2_off, verifyResultValueNibble8,
			"DSUBP 0->0 nop2-nop1", 2, 123456},
	{30, ML_CODE_DSUBP, setCodeOp2_DN1DN2, setInputOp2_Val32_DN1DN2_on, verifyResultValueNibble8,
			"DSUBP 1->1 nop2-nop1", 2, 123456},
	{31, ML_CODE_DSUBP, setCodeOp2_DN1DN2, setInputOp2_Val32p_DN1DN2_on, verifyResultValueNibble8,
			"DSUBP 0->1 nop2-nop1", 2, -444434},

	{32, ML_CODE_DINC, setCodeOp1_DN, setInputOp1_Val32_DN_off, verifyResultValueNibble8,
			"DINC off", 1, 123456},
	{33, ML_CODE_DINC, setCodeOp1_DN, setInputOp1_Val32_DN_on, verifyResultValueNibble8,
			"DINC on", 1, 123457},
	{34, ML_CODE_DINC, setCodeOp1_DN, setInputOp1_Val32_DN_over_on, verifyResultValueNibble8,
			"DINC on overflow", 1, -2147483648},

	{35, ML_CODE_DINCP, setCodeOp1_DN, setInputOp1_Val32_DN_off, verifyResultValueNibble8,
			"DINCP 0->0", 2, 123456},
	{36, ML_CODE_DINCP, setCodeOp1_DN, setInputOp1_Val32_DN_on, verifyResultValueNibble8,
			"DINCP 1->1", 2, 123456},
	{37, ML_CODE_DINCP, setCodeOp1_DN, setInputOp1_Val32p_DN_on, verifyResultValueNibble8,
			"DINCP 0->1", 2, 123457},
	{38, ML_CODE_DINCP, setCodeOp1_DN, setInputOp1_Val32p_DN_over_on, verifyResultValueNibble8,
			"DINCP 0->1 overflow", 2, -2147483648},

	{39, ML_CODE_DDEC, setCodeOp1_DN, setInputOp1_Val32_DN_off, verifyResultValueNibble8,
			"DDEC off", 1, 123456},
	{40, ML_CODE_DDEC, setCodeOp1_DN, setInputOp1_Val32_DN_on, verifyResultValueNibble8,
			"DDEC on", 1, 123455},
	{41, ML_CODE_DDEC, setCodeOp1_DN, setInputOp1_Val32_DN_under_on, verifyResultValueNibble8,
			"DDEC on underflow", 1, 2147483647},

	{42, ML_CODE_DDECP, setCodeOp1_DN, setInputOp1_Val32_DN_off, verifyResultValueNibble8,
			"DDECP 0->0", 2, 123456},
	{43, ML_CODE_DDECP, setCodeOp1_DN, setInputOp1_Val32_DN_on, verifyResultValueNibble8,
			"DDECP 1->1", 2, 123456},
	{44, ML_CODE_DDECP, setCodeOp1_DN, setInputOp1_Val32p_DN_on, verifyResultValueNibble8,
			"DDECP 0->1", 2, 123455},
	{45, ML_CODE_DDECP, setCodeOp1_DN, setInputOp1_Val32p_DN_under_on, verifyResultValueNibble8,
			"DDECP 0->1 underflow", 2, 2147483647},

	{46, ML_CODE_DADDS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32_off, verifyResultValueNibble8,
			"DADDS off nop3=op1+op2", 1, 0},
	{47, ML_CODE_DADDS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32_on, verifyResultValueNibble8,
			"DADDS on nop3=op1+op2", 1, 691346},
	{48, ML_CODE_DADDS, setCodeOp3_DW1DW2_DN3, setInputOp3_Val32_DWDWDN_over_on, verifyResultValueNibble8,
			"DADDS on nop3=op1+op2 over", 1, -2147483647},
	{49, ML_CODE_DADDS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32_K1W2_off, verifyResultValueNibble8,
			"DADDS off nop3=K+op2", 1, 0},
	{50, ML_CODE_DADDS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32_K1W2_on, verifyResultValueNibble8,
			"DADDS on nop3=K+op2", 1, 691346},
	{51, ML_CODE_DADDS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DADDS off nop3=K+K", 1, 0},
	{52, ML_CODE_DADDS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16_on, verifyResultValueNibble8,
			"DADDS on nop3=K+K", 1, 691346},
	{53, ML_CODE_DADDS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32_DNDWDN_off, verifyResultValueNibble8,
			"DADDS off nop3=op1+nop2", 1, 0},
	{54, ML_CODE_DADDS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32_DNDWDN_on, verifyResultValueNibble8,
			"DADDS on nop3=nop1+op2", 1, 691346},
	{55, ML_CODE_DADDS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32_DWDNDN_off, verifyResultValueNibble8,
			"DADDS off nop3=op1+nop2", 1, 0},
	{56, ML_CODE_DADDS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32_DWDNDN_on, verifyResultValueNibble8,
			"DADDS on nop3=op1+nop2", 1, 691346},

	{57, ML_CODE_DADDPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=op1+op2", 2, 0},
	{58, ML_CODE_DADDPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32_on, verifyResultValueNibble8,
			"DADDPS 1->1 nop3=op1+op2", 2, 0},
	{59, ML_CODE_DADDPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32p_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=op1+op2", 2, 691346},
	{60, ML_CODE_DADDPS, setCodeOp3_DW1DW2_DN3, setInputOp3_Val32p_DWDWDN_over_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=op1+op2 over", 2, -2147483647},
	{61, ML_CODE_DADDPS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32_K1W2_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=K+op2", 2, 0},
	{62, ML_CODE_DADDPS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32_K1W2_on, verifyResultValueNibble8,
			"DADDPS 1->1 nop3=K+op2", 2, 0},
	{63, ML_CODE_DADDPS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32p_K1W2_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=K+op2", 2, 691346},
	{64, ML_CODE_DADDPS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=K+K", 2, 0},
	{65, ML_CODE_DADDPS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16_on, verifyResultValueNibble8,
			"DADDPS 1->1 nop3=K+K", 2, 0},
	{66, ML_CODE_DADDPS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16p_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=K+K", 2, 691346},
	{67, ML_CODE_DADDPS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32_DNDWDN_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=op1+nop2", 2, 0},
	{68, ML_CODE_DADDPS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32_DNDWDN_on, verifyResultValueNibble8,
			"DADDPS 1->1 nop3=op1+nop2", 2, 0},
	{69, ML_CODE_DADDPS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32p_DNDWDN_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=op1+nop2", 2, 691346},
	{70, ML_CODE_DADDPS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32_DWDNDN_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=op1+nop2", 2, 0},
	{71, ML_CODE_DADDPS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32_DWDNDN_on, verifyResultValueNibble8,
			"DADDPS 1->1 nop3=op1+nop2", 2, 0},
	{72, ML_CODE_DADDPS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32p_DWDNDN_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=op1+nop2", 2, 691346},

	{73, ML_CODE_DSUBS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32_off, verifyResultValueNibble8,
			"DSUBS off nop3=op1-op2", 1, 0},
	{74, ML_CODE_DSUBS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32_on, verifyResultValueNibble8,
			"DSUBS on nop3=op1-op2", 1, 444434},
	{75, ML_CODE_DSUBS, setCodeOp3_DW1DW2_DN3, setInputOp3_Val32_DWDWDN_under_on, verifyResultValueNibble8,
			"DSUBS on nop3=op1-op2 over", 1, 2147483646},
	{76, ML_CODE_DSUBS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32_K1W2_off, verifyResultValueNibble8,
			"DSUBS off nop3=K-op2", 1, 0},
	{77, ML_CODE_DSUBS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32_K1W2_on, verifyResultValueNibble8,
			"DSUBS on nop3=K-op2", 1, 444434},
	{78, ML_CODE_DSUBS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DSUBS off nop3=K-K", 1, 0},
	{79, ML_CODE_DSUBS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16_on, verifyResultValueNibble8,
			"DSUBS on nop3=K-K", 1, 444434},
	{80, ML_CODE_DSUBS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32_DNDWDN_off, verifyResultValueNibble8,
			"DSUBS off nop3=op1-nop2", 1, 0},
	{81, ML_CODE_DSUBS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32_DNDWDN_on, verifyResultValueNibble8,
			"DSUBS on nop3=nop1-op2", 1, 444434},
	{82, ML_CODE_DSUBS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32_DWDNDN_off, verifyResultValueNibble8,
			"DSUBS off nop3=op1-nop2", 1, 0},
	{83, ML_CODE_DSUBS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32_DWDNDN_on, verifyResultValueNibble8,
			"DSUBS on nop3=op1-nop2", 1, 444434},

	{84, ML_CODE_DSUBPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=op1-op2", 2, 0},
	{85, ML_CODE_DSUBPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32_on, verifyResultValueNibble8,
			"DSUBPS 1->1 nop3=op1-op2", 2, 0},
	{86, ML_CODE_DSUBPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_Val32p_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=op1-op2", 2, 444434},
	{87, ML_CODE_DSUBPS, setCodeOp3_DW1DW2_DN3, setInputOp3_Val32p_DWDWDN_under_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=op1-op2 over", 2, 2147483646},
	{88, ML_CODE_DSUBPS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32_K1W2_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=K-op2", 2, 0},
	{89, ML_CODE_DSUBPS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32_K1W2_on, verifyResultValueNibble8,
			"DSUBPS 1->1 nop3=K-op2", 2, 0},
	{90, ML_CODE_DSUBPS, setCodeOp3_DK1DW2_DN3, setInputSIn_Val32p_K1W2_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=K-op2", 2, 444434},
	{91, ML_CODE_DSUBPS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=K-K", 2, 0},
	{92, ML_CODE_DSUBPS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16_on, verifyResultValueNibble8,
			"DSUBPS 1->1 nop3=K-K", 2, 0},
	{93, ML_CODE_DSUBPS, setCodeOp3_DK1DK2_DN3, setInputNIn_Val16p_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=K-K", 2, 444434},
	{94, ML_CODE_DSUBPS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32_DNDWDN_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=op1-nop2", 2, 0},
	{95, ML_CODE_DSUBPS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32_DNDWDN_on, verifyResultValueNibble8,
			"DSUBPS 1->1 nop3=op1-nop2", 2, 0},
	{96, ML_CODE_DSUBPS, setCodeOp3_DN1DW2_DN3, setInputOp3_Val32p_DNDWDN_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=op1-nop2", 2, 444434},
	{97, ML_CODE_DSUBPS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32_DWDNDN_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=op1-nop2", 2, 0},
	{98, ML_CODE_DSUBPS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32_DWDNDN_on, verifyResultValueNibble8,
			"DSUBPS 1->1 nop3=op1-nop2", 2, 0},
	{99, ML_CODE_DSUBPS, setCodeOp3_DW1DN2_DN3, setInputOp3_Val32p_DWDNDN_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=op1-nop2", 2, 444434},

	{100, ML_CODE_DBADD, setCodeOp2_DW1DN2, setInputOp2_BCD8_DW1DN2_off, verifyResultValueNibble8,
			"DBADD off op1+nop2", 1, 3290198}, //0x323456
	{101, ML_CODE_DBADD, setCodeOp2_DW1DN2, setInputOp2_BCD8_DW1DN2_on, verifyResultValueNibble8,
			"DBADD on op1+nop2", 1, 270091556}, //0x10194524
	{102, ML_CODE_DBADD, setCodeOp2_DW1DN2, setInputOp2_BCD8_DW1DN2_over_on, verifyResultValueNibble8,
			"DBADD on op1+nop2 over", 1, 0x654321},
	{103, ML_CODE_DBADD, setCodeOp2_DBK1DN2, setInputOp2_BCD8_DK1DN2_off, verifyResultValueNibble8,
			"DBADD off K+nop2", 1, 3290198}, //0x323456
	{104, ML_CODE_DBADD, setCodeOp2_DBK1DN2, setInputOp2_BCD8_DK1DN2_on, verifyResultValueNibble8,
			"DBADD on K+nop1", 1, 270091556}, //0x10194524
	{105, ML_CODE_DBADD, setCodeOp2_DN1DN2, setInputOp2_BCD8_DN1DN2_off, verifyResultValueNibble8,
			"DBADD off nop1+nop2", 1, 3290198}, //0x323456
	{106, ML_CODE_DBADD, setCodeOp2_DN1DN2, setInputOp2_BCD8_DN1DN2_on, verifyResultValueNibble8,
			"DBADD on nop1+nop2", 1, 270091556}, //0x10194524

	{107, ML_CODE_DBADDP, setCodeOp2_DW1DN2, setInputOp2_BCD8_DW1DN2_off, verifyResultValueNibble8,
			"DBADDP 0->0 op1+nop2", 2, 3290198}, //0x323456
	{108, ML_CODE_DBADDP, setCodeOp2_DW1DN2, setInputOp2_BCD8p_DW1DN2_on, verifyResultValueNibble8,
			"DBADDP 0->1 op1+nop2", 2, 270091556}, //0x10194524
	{109, ML_CODE_DBADDP, setCodeOp2_DW1DN2, setInputOp2_BCD8p_DW1DN2_over_on, verifyResultValueNibble8,
			"DBADDP 0->1 op1+nop2 over", 2, 0x654321},
	{110, ML_CODE_DBADDP, setCodeOp2_DBK1DN2, setInputOp2_BCD8_DK1DN2_off, verifyResultValueNibble8,
			"DBADDP 0->0 K+nop2", 2, 3290198}, //0x323456
	{111, ML_CODE_DBADDP, setCodeOp2_DBK1DN2, setInputOp2_BCD8p_DK1DN2_on, verifyResultValueNibble8,
			"DBADDP 0->1 K+nop1", 2, 270091556}, //0x10194524
	{112, ML_CODE_DBADDP, setCodeOp2_DN1DN2, setInputOp2_BCD8_DN1DN2_off, verifyResultValueNibble8,
			"DBADDP 0->0 nop1+nop2", 2, 3290198}, //0x323456
	{113, ML_CODE_DBADDP, setCodeOp2_DN1DN2, setInputOp2_BCD8p_DN1DN2_on, verifyResultValueNibble8,
			"DBADDP 0->1 nop1+nop2", 2, 270091556}, //0x10194524

	{114, ML_CODE_DBSUB, setCodeOp2_DW1DN2, setInputOp2_BCD8_DW1DN2_off, verifyResultValueNibble8,
			"DBSUB off nop2-op1", 1, 3290198}, //0x323456
	{115, ML_CODE_DBSUB, setCodeOp2_DW1DN2, setInputOp2_BCD8_DW1DN2_on, verifyResultValueNibble8,
			"DBSUB on nop2-op1", 1, -1874517112}, //0x90452388
	{116, ML_CODE_DBSUB, setCodeOp2_DW1DN2, setInputOp2_BCD8_DW1DN2_under_on, verifyResultValueNibble8,
			"DBSUB on nop2-op1 over", 1, 0x99999999},
	{117, ML_CODE_DBSUB, setCodeOp2_DBK1DN2, setInputOp2_BCD8_DK1DN2_off, verifyResultValueNibble8,
			"DBSUB off nop2-K", 1, 3290198}, //0x323456
	{118, ML_CODE_DBSUB, setCodeOp2_DBK1DN2, setInputOp2_BCD8_DK1DN2_on, verifyResultValueNibble8,
			"DBSUB on nop2-K", 1, -1874517112}, //0x90452388
	{119, ML_CODE_DBSUB, setCodeOp2_DN1DN2, setInputOp2_BCD8_DN1DN2_off, verifyResultValueNibble8,
			"DBSUB off nop2-nop1", 1, 3290198}, //0x323456
	{120, ML_CODE_DBSUB, setCodeOp2_DN1DN2, setInputOp2_BCD8_DN1DN2_on, verifyResultValueNibble8,
			"DBSUB on nop2-nop1", 1, -1874517112}, //0x90452388

	{121, ML_CODE_DBSUBP, setCodeOp2_DW1DN2, setInputOp2_BCD8_DW1DN2_off, verifyResultValueNibble8,
			"DBSUBP 0->0 nop2-op1", 2, 3290198}, //0x323456
	{122, ML_CODE_DBSUBP, setCodeOp2_DW1DN2, setInputOp2_BCD8p_DW1DN2_on, verifyResultValueNibble8,
			"DBSUBP 0->1 nop2-op1", 2, -1874517112}, //0x90452388
	{123, ML_CODE_DBSUBP, setCodeOp2_DW1DN2, setInputOp2_BCD8p_DW1DN2_under_on, verifyResultValueNibble8,
			"DBSUBP 0->1 nop2-op1 over", 2, 0x99999999},
	{124, ML_CODE_DBSUBP, setCodeOp2_DBK1DN2, setInputOp2_BCD8_DK1DN2_off, verifyResultValueNibble8,
			"DBSUBP 0->0 nop2-K", 2, 3290198}, //0x323456
	{125, ML_CODE_DBSUBP, setCodeOp2_DBK1DN2, setInputOp2_BCD8p_DK1DN2_on, verifyResultValueNibble8,
			"DBSUBP 0->1 nop2-K", 2, -1874517112}, //0x90452388
	{126, ML_CODE_DBSUBP, setCodeOp2_DN1DN2, setInputOp2_BCD8_DN1DN2_off, verifyResultValueNibble8,
			"DBSUBP 0->0 nop2-nop1", 2, 3290198}, //0x323456
	{127, ML_CODE_DBSUBP, setCodeOp2_DN1DN2, setInputOp2_BCD8p_DN1DN2_on, verifyResultValueNibble8,
			"DBSUBP 0->1 nop2-nop1", 2, -1874517112}, //0x90452388

	{128, ML_CODE_DBADDS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8_DWDWDN_off, verifyResultValueNibble8,
			"DBADDS off nop3=op1+op2", 1, 0},
	{129, ML_CODE_DBADDS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8_DWDWDN_on, verifyResultValueNibble8,
			"DBADDS on nop3=op1+op2", 1, 270091556}, //0x10194524
	{130, ML_CODE_DBADDS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8_DWDWDN_over_on, verifyResultValueNibble8,
			"DBADDS on nop3=op1+op2 over", 1, 0x654321},
	{131, ML_CODE_DBADDS, setCodeOp3_DBK1DW2_DN3, setInputSIn_BCD8_DK1DW2_off, verifyResultValueNibble8,
			"DBADDS off nop3=K+op2", 1, 0},
	{132, ML_CODE_DBADDS, setCodeOp3_DBK1DW2_DN3, setInputSIn_BCD8_DK1DW2_on, verifyResultValueNibble8,
			"DBADDS on nop3=K+op2", 1, 270091556}, //0x10194524
	{133, ML_CODE_DBADDS, setCodeOp3_DBK1DBK2_DN3, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DBADDS off nop3=K+K", 1, 0},
	{134, ML_CODE_DBADDS, setCodeOp3_DBK1DBK2_DN3, setInputNIn_Val16_on, verifyResultValueNibble8,
			"DBADDS on nop3=K+K", 1, 270091556}, //0x10194524
	{135, ML_CODE_DBADDS, setCodeOp3_DN1DW2_DN3, setInputOp3_BCD8_DNDWDN_off, verifyResultValueNibble8,
			"DBADDS off nop3=op1+nop2", 1, 0},
	{136, ML_CODE_DBADDS, setCodeOp3_DN1DW2_DN3, setInputOp3_BCD8_DNDWDN_on, verifyResultValueNibble8,
			"DBADDS on nop3=nop1+op2", 1, 270091556}, //0x10194524
	{137, ML_CODE_DBADDS, setCodeOp3_DW1DN2_DN3, setInputOp3_BCD8_DWDNDN_off, verifyResultValueNibble8,
			"DBADDS off nop3=op1+nop2", 1, 0},
	{138, ML_CODE_DBADDS, setCodeOp3_DW1DN2_DN3, setInputOp3_BCD8_DWDNDN_on, verifyResultValueNibble8,
			"DBADDS on nop3=op1+nop2", 1, 270091556}, //0x10194524

	{139, ML_CODE_DBADDPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8_DWDWDN_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=op1+op2", 2, 0},
	{140, ML_CODE_DBADDPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8p_DWDWDN_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=op1+op2", 2, 270091556}, //0x10194524
	{141, ML_CODE_DBADDPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8p_DWDWDN_over_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=op1+op2 over", 2, 0x654321},
	{142, ML_CODE_DBADDPS, setCodeOp3_DBK1DW2_DN3, setInputSIn_BCD8_DK1DW2_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=K+op2", 2, 0},
	{143, ML_CODE_DBADDPS, setCodeOp3_DBK1DW2_DN3, setInputSIn_BCD8p_DK1DW2_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=K+op2", 2, 270091556}, //0x10194524
	{144, ML_CODE_DBADDPS, setCodeOp3_DBK1DBK2_DN3, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=K+K", 2, 0},
	{145, ML_CODE_DBADDPS, setCodeOp3_DBK1DBK2_DN3, setInputNIn_Val16p_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=K+K", 2, 270091556}, //0x10194524
	{146, ML_CODE_DBADDPS, setCodeOp3_DN1DW2_DN3, setInputOp3_BCD8_DNDWDN_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=op1+nop2", 2, 0},
	{147, ML_CODE_DBADDPS, setCodeOp3_DN1DW2_DN3, setInputOp3_BCD8p_DNDWDN_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=nop1+op2", 2, 270091556}, //0x10194524
	{148, ML_CODE_DBADDPS, setCodeOp3_DW1DN2_DN3, setInputOp3_BCD8_DWDNDN_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=op1+nop2", 2, 0},
	{149, ML_CODE_DBADDPS, setCodeOp3_DW1DN2_DN3, setInputOp3_BCD8p_DWDNDN_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=op1+nop2", 2, 270091556}, //0x10194524

	{150, ML_CODE_DBSUBS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8_DWDWDN_off, verifyResultValueNibble8,
			"DBSUBS off nop3=op1-op2", 1, 0},
	{151, ML_CODE_DBSUBS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8_DWDWDN_on, verifyResultValueNibble8,
			"DBSUBS on nop3=op1-op2", 1, 156530194}, //0x9547612
	{152, ML_CODE_DBSUBS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8_DWDWDN_under_on, verifyResultValueNibble8,
			"DBSUBS on nop3=op1-op2 over", 1, 0x99999999},
	{153, ML_CODE_DBSUBS, setCodeOp3_DBK1DW2_DN3, setInputSIn_BCD8_DK1DW2_off, verifyResultValueNibble8,
			"DBSUBS off nop3=K-op2", 1, 0},
	{154, ML_CODE_DBSUBS, setCodeOp3_DBK1DW2_DN3, setInputSIn_BCD8_DK1DW2_on, verifyResultValueNibble8,
			"DBSUBS on nop3=K-op2", 1, 156530194}, //0x9547612
	{155, ML_CODE_DBSUBS, setCodeOp3_DBK1DBK2_DN3, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DBSUBS off nop3=K-K", 1, 0},
	{156, ML_CODE_DBSUBS, setCodeOp3_DBK1DBK2_DN3, setInputNIn_Val16_on, verifyResultValueNibble8,
			"DBSUBS on nop3=K-K", 1, 156530194}, //0x9547612
	{157, ML_CODE_DBSUBS, setCodeOp3_DN1DW2_DN3, setInputOp3_BCD8_DNDWDN_off, verifyResultValueNibble8,
			"DBSUBS off nop3=op1-nop2", 1, 0},
	{158, ML_CODE_DBSUBS, setCodeOp3_DN1DW2_DN3, setInputOp3_BCD8_DNDWDN_on, verifyResultValueNibble8,
			"DBSUBS on nop3=nop1-op2", 1, 156530194}, //0x9547612
	{159, ML_CODE_DBSUBS, setCodeOp3_DW1DN2_DN3, setInputOp3_BCD8_DWDNDN_off, verifyResultValueNibble8,
			"DBSUBS off nop3=op1-nop2", 1, 0},
	{160, ML_CODE_DBSUBS, setCodeOp3_DW1DN2_DN3, setInputOp3_BCD8_DWDNDN_on, verifyResultValueNibble8,
			"DBSUBS on nop3=op1-nop2", 1, 156530194}, //0x9547612

	{161, ML_CODE_DBSUBPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8_DWDWDN_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=op1-op2", 2, 0},
	{162, ML_CODE_DBSUBPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8p_DWDWDN_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=op1-op2", 2, 156530194}, //0x9547612
	{163, ML_CODE_DBSUBPS, setCodeOp3_DW1DW2_DN3, setInput2DIn_BCD8p_DWDWDN_under_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=op1-op2 over", 2, 0x99999999},
	{164, ML_CODE_DBSUBPS, setCodeOp3_DBK1DW2_DN3, setInputSIn_BCD8_DK1DW2_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=K-op2", 2, 0},
	{165, ML_CODE_DBSUBPS, setCodeOp3_DBK1DW2_DN3, setInputSIn_BCD8p_DK1DW2_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=K-op2", 2, 156530194}, //0x9547612
	{166, ML_CODE_DBSUBPS, setCodeOp3_DBK1DBK2_DN3, setInputNIn_Val16_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=K-K", 2, 0},
	{167, ML_CODE_DBSUBPS, setCodeOp3_DBK1DBK2_DN3, setInputNIn_Val16p_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=K-K", 2, 156530194}, //0x9547612
	{168, ML_CODE_DBSUBPS, setCodeOp3_DN1DW2_DN3, setInputOp3_BCD8_DNDWDN_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=op1-nop2", 2, 0},
	{169, ML_CODE_DBSUBPS, setCodeOp3_DN1DW2_DN3, setInputOp3_BCD8p_DNDWDN_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=nop1-op2", 2, 156530194}, //0x9547612
	{170, ML_CODE_DBSUBPS, setCodeOp3_DW1DN2_DN3, setInputOp3_BCD8_DWDNDN_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=op1-nop2", 2, 0},
	{171, ML_CODE_DBSUBPS, setCodeOp3_DW1DN2_DN3, setInputOp3_BCD8p_DWDNDN_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=op1-nop2", 2, 156530194}, //0x9547612

	{-1, 0xFFFF, NULL, NULL, NULL, " ", 0, 0 }
};


int total_basic_compute_dword_nb_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_dword_nb_test_number; i++)
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

int setCodeOp1_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_DW1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_DK1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 567890); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_DN1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DW1DW2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 160);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DK1DW2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 567890); addMLOperand(in_reg, in_pos);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DK1DK2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 567890); addMLOperand(OPERAND_ML_CODE_DK, 123456);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DN1DW2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( in_reg == out_reg && in_pos == out_pos ) return 0;


	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_D, 160);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DW1DN2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_D, in_pos); addMLOperandNibble(8, in_reg, 160);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_DBK1DN2(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x9871068); addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DBK1DW2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x9871068); addMLOperand(in_reg, in_pos);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_DBK1DBK2_DN3(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 0x9871068); addMLOperand(OPERAND_ML_CODE_DK, 0x323456);
		addMLOperandNibble(8, out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp2_Val32_DW1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_DW1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32p_DW1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 567890);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_DW1DN2_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=2;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 2147483647);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_DW1DN2_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=-2147483648;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 2);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_DK1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_DK1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32p_DK1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_DN1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=567890, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_DN1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=567890, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32p_DN1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=567890, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp1_Val32_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp1_Val32_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp1_Val32p_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp1_Val32_DN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=2147483647;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp1_Val32p_DN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=2147483647;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp1_Val32_DN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=-2147483648;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp1_Val32p_DN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=-2147483648;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_DWDWDN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 2147483647);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 2);

	TestCodeTearDown();
}

void setInputOp3_Val32p_DWDWDN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 2147483647);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 2);

	TestCodeTearDown();
}

void setInputOp3_Val32_DWDWDN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, -2147483648);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 2);

	TestCodeTearDown();
}

void setInputOp3_Val32p_DWDWDN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, -2147483648);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 2);

	TestCodeTearDown();
}

void setInputOp3_Val32_DNDWDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, 160, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32_DNDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, 160, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32p_DNDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=567890;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, 160, 123456);

	TestCodeTearDown();
}

void setInputOp3_Val32_DWDNDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, in_pos, 567890);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32_DWDNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, in_pos, 567890);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Val32p_DWDNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, in_pos, 567890);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_DW1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x9871068);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_DW1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x9871068);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DW1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x9871068);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_DW1DN2_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x1654321;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99000000);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DW1DN2_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x1654321;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99000000);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_DW1DN2_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x12345678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x12345679);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DW1DN2_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x12345678;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x12345679);

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_DK1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_DK1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DK1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, out_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_DN1DN2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x9871068, out_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_DN1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x9871068, out_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DN1DN2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x9871068, out_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput2DIn_BCD8_DWDWDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x9871068);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x323456);

	TestCodeTearDown();
}

void setInput2DIn_BCD8_DWDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x9871068);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x323456);

	TestCodeTearDown();
}

void setInput2DIn_BCD8p_DWDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x9871068);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x323456);

	TestCodeTearDown();
}

void setInput2DIn_BCD8_DWDWDN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99000000);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x1654321);

	TestCodeTearDown();
}

void setInput2DIn_BCD8p_DWDWDN_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x99000000);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x1654321);

	TestCodeTearDown();
}

void setInput2DIn_BCD8_DWDWDN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x12345678);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x12345679);

	TestCodeTearDown();
}

void setInput2DIn_BCD8p_DWDWDN_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x12345678);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, 0x12345679);

	TestCodeTearDown();
}

void setInputSIn_BCD8_DK1DW2_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);

	TestCodeTearDown();
}

void setInputSIn_BCD8_DK1DW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);

	TestCodeTearDown();
}

void setInputSIn_BCD8p_DK1DW2_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 0x323456);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNDWDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, 160, 0x323456);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, 160, 0x323456);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNDWDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, 160, 0x323456);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWDNDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, in_pos, 0x9871068);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWDNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, in_pos, 0x9871068);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DWDNDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=0x323456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)OPERAND_ML_CODE_D, in_pos, 0x9871068);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}


static uint16 getPos(int reg, int inx_pos)
{
	//uint16 pos[3][2]={ {0,0}, {6144,4096}, {12285,8189}}; // -2
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}};
	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_arithmetic_dword_nb(int tno, uint16 dummy)
{
	int i, rc=0, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//DBG_LOGPRINT("testBasicArithmaticDWordNibbleCommand: %d\n", tno);
	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in, i);

					//printf("%d\n", __LINE__);
					ml_rc=testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if(ml_rc==0) continue;

					//printf("%d\n", __LINE__);
					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

					//printf("%d\n", __LINE__);
					rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
					//printf("%d\n", __LINE__);
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
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
						}
					}
				}
			}
		}
	}
}

void testBasicArithmeticDWordNibbleCommand(void)
{
	int i, index=35;
	int start, end;
	char log[] = "err_arith_dword_nb.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic dword nibble LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0;index<5;index++)
		test_basic_arithmetic_dword_nb(index, 0);
#else
	total_basic_compute_dword_nb_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DADD); //ML_CODE_DADD
	end = getTestCaseNumberEnd(ML_CODE_DBSUBPS); //ML_CODE_DBSUBPS

	DBG_LOGPRINT("testBasicArithmaticDWordNibbleCommand: %d to %d total %d\n", start, end, total_basic_compute_dword_nb_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_dword_nb(index, 0); // out register position 0
	}
#endif
	fclose(flog);
}

#endif
