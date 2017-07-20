/*
 * test_arithmetic_float_index.c
 *
 *  Created 1->1: Aug 13, 2015
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

extern int setCodeOp2_WWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
extern int setCodeOp2_WZW(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);

extern int verifyResultValueFloat(int tcase, uint8 dest_reg, uint16 pos, float expected);

int setCodeOp2_EinWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);

int setCodeOp3_WW_WZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp3_W_WWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_WEWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_WZEW(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp3_WZW_W(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp3_WWZ_W(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_WEWZ_div(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_WWEW(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_EEWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_EEWZ_div(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);
int setCodeOp2_WZEW_div(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos);

void setInputDIn_WWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_EWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_EWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_EWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZW_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZW_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZW_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputDIn_WW_WZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WW_WZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WW_WZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_W_WWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_W_WWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_W_WWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZW_W_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZW_W_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZW_W_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WWZ_W_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WWZ_W_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WWZ_W_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WEWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WEWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WEWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZEW_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZEW_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZEW_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_EEWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_EEWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_EEWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputDIn_WW_WZ_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WW_WZ_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WW_WZ_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_W_WWZ_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_W_WWZ_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_W_WWZ_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZW_W_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZW_W_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZW_W_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WWZ_W_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WWZ_W_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WWZ_W_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WEWZ_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WEWZ_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WEWZ_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZEW_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZEW_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputDIn_WZEW_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

static int verifyResultValueZFloat(int tcase, uint8 dest_reg, uint16 pos, float expected);

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

static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16, uint16, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, float);
	char str[40];
	//int count;
	int z_type; // 0 : out is index, 1: op1 is index
	int run_step;
	float expected;

} testFn_st;


static testFn_st testCase[]={
	{0, ML_CODE_EADD, setCodeOp2_WWZ, setInputDIn_WWZ_float_off, verifyResultValueZFloat,
			"ADD float off W+WZ", 0, 1, 12003.2f},
	{1, ML_CODE_EADD, setCodeOp2_WWZ, setInputDIn_WWZ_float_on, verifyResultValueZFloat,
			"ADD float on W+WZ", 0, 1, 17964.637f},
	{2, ML_CODE_EADD, setCodeOp2_EinWZ, setInputSIn_EWZ_float_off, verifyResultValueZFloat,
			"ADD float off E+WZ", 0, 1, 12003.2f},
	{3, ML_CODE_EADD, setCodeOp2_EinWZ, setInputSIn_EWZ_float_on, verifyResultValueZFloat,
			"ADD float on E+WZ", 0, 1, 17964.637f},
	{4, ML_CODE_EADD, setCodeOp2_WZW, setInputDIn_WZW_float_off, verifyResultValueFloat,
			"ADD float off WZ+W", 1, 1, 12003.2f},
	{5, ML_CODE_EADD, setCodeOp2_WZW, setInputDIn_WZW_float_on, verifyResultValueFloat,
			"ADD float on WZ+W", 1, 1, 17964.637f},

	{6, ML_CODE_EADDP, setCodeOp2_WWZ, setInputDIn_WWZ_float_off, verifyResultValueZFloat,
			"ADDP float 0->0 W+WZ", 0, 2, 12003.2f},
	{7, ML_CODE_EADDP, setCodeOp2_WWZ, setInputDIn_WWZ_float_on, verifyResultValueZFloat,
			"ADDP float 1->1 W+WZ", 0, 2, 12003.2f},
	{8, ML_CODE_EADDP, setCodeOp2_WWZ, setInputDIn_WWZ_floatp_on, verifyResultValueZFloat,
			"ADDP float 0->1 W+WZ", 0, 2, 17964.637f},
	{9, ML_CODE_EADDP, setCodeOp2_EinWZ, setInputSIn_EWZ_float_off, verifyResultValueZFloat,
			"ADDP float 0->0 E+WZ", 0, 2, 12003.2f},
	{10, ML_CODE_EADDP, setCodeOp2_EinWZ, setInputSIn_EWZ_float_on, verifyResultValueZFloat,
			"ADDP float 1->1 E+WZ", 0, 2, 12003.2f},
	{11, ML_CODE_EADDP, setCodeOp2_EinWZ, setInputSIn_EWZ_floatp_on, verifyResultValueZFloat,
			"ADDP float 0->1 E+WZ", 0, 2, 17964.637f},
	{12, ML_CODE_EADDP, setCodeOp2_WZW, setInputDIn_WZW_float_off, verifyResultValueFloat,
			"ADDP float 0->0 WZ+W", 1, 2, 12003.2f},
	{13, ML_CODE_EADDP, setCodeOp2_WZW, setInputDIn_WZW_float_on, verifyResultValueFloat,
			"ADDP float 1->1 WZ+W", 1, 2, 12003.2f},
	{14, ML_CODE_EADDP, setCodeOp2_WZW, setInputDIn_WZW_floatp_on, verifyResultValueFloat,
			"ADDP float 0->1 WZ+W", 1, 2, 17964.637f},

	{15, ML_CODE_ESUB, setCodeOp2_WWZ, setInputDIn_WWZ_float_off, verifyResultValueZFloat,
			"SUB float off WZ-W", 0, 1, 12003.2f},
	{16, ML_CODE_ESUB, setCodeOp2_WWZ, setInputDIn_WWZ_float_on, verifyResultValueZFloat,
			"SUB float on WZ-W", 0, 1, 6041.763f},
	{17, ML_CODE_ESUB, setCodeOp2_EinWZ, setInputSIn_EWZ_float_off, verifyResultValueZFloat,
			"SUB float off WZ-E", 0, 1, 12003.2f},
	{18, ML_CODE_ESUB, setCodeOp2_EinWZ, setInputSIn_EWZ_float_on, verifyResultValueZFloat,
			"SUB float on WZ-E", 0, 1, 6041.763f},
	{19, ML_CODE_ESUB, setCodeOp2_WZW, setInputDIn_WZW_float_off, verifyResultValueFloat,
			"SUB float off W-WZ", 1, 1, 12003.2f},
	{20, ML_CODE_ESUB, setCodeOp2_WZW, setInputDIn_WZW_float_on, verifyResultValueFloat,
			"SUB float on W-WZ", 1, 1, 6041.763f},

	{21, ML_CODE_ESUBP, setCodeOp2_WWZ, setInputDIn_WWZ_float_off, verifyResultValueZFloat,
			"SUBP float 0->0 WZ-W", 0, 2, 12003.2f},
	{22, ML_CODE_ESUBP, setCodeOp2_WWZ, setInputDIn_WWZ_float_on, verifyResultValueZFloat,
			"SUBP float 1->1 WZ-W", 0, 2, 12003.2f},
	{23, ML_CODE_ESUBP, setCodeOp2_WWZ, setInputDIn_WWZ_floatp_on, verifyResultValueZFloat,
			"SUBP float 0->1 WZ-W", 0, 2, 6041.763f},
	{24, ML_CODE_ESUBP, setCodeOp2_EinWZ, setInputSIn_EWZ_float_off, verifyResultValueZFloat,
			"SUBP float 0->0 WZ-E", 0, 2, 12003.2f},
	{25, ML_CODE_ESUBP, setCodeOp2_EinWZ, setInputSIn_EWZ_float_on, verifyResultValueZFloat,
			"SUBP float 1->1 WZ-E", 0, 2, 12003.2f},
	{26, ML_CODE_ESUBP, setCodeOp2_EinWZ, setInputSIn_EWZ_floatp_on, verifyResultValueZFloat,
			"SUBP float 0->1 WZ-E", 0, 2, 6041.763f},
	{27, ML_CODE_ESUBP, setCodeOp2_WZW, setInputDIn_WZW_float_off, verifyResultValueFloat,
			"SUBP float 0->0 W-WZ", 1, 2, 12003.2f},
	{28, ML_CODE_ESUBP, setCodeOp2_WZW, setInputDIn_WZW_float_on, verifyResultValueFloat,
			"SUBP float 1->1 W-WZ", 1, 2, 12003.2f},
	{29, ML_CODE_ESUBP, setCodeOp2_WZW, setInputDIn_WZW_floatp_on, verifyResultValueFloat,
			"SUBP float 0->1 W-WZ", 1, 2, 6041.763f},

	{30, ML_CODE_EADDS, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_float_off, verifyResultValueZFloat,
			"ADDS float off WZ=W+W", 0, 1, 0.0f},
	{31, ML_CODE_EADDS, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_float_on, verifyResultValueZFloat,
			"ADDS float on WZ=W+W", 0, 1, 17964.637},
	{32, ML_CODE_EADDS, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_float_off, verifyResultValueZFloat,
			"ADDS float off WZ=W+W", 0, 1, 0.0f},
	{33, ML_CODE_EADDS, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_float_on, verifyResultValueZFloat,
			"ADDS float on WZ=W+W", 0, 1, 17964.637},
	{34, ML_CODE_EADDS, setCodeOp3_WZW_W, setInputDIn_WZW_W_float_off, verifyResultValueFloat,
			"ADDS float off W=WZ+W", 1, 1, 0.0f},
	{35, ML_CODE_EADDS, setCodeOp3_WZW_W, setInputDIn_WZW_W_float_on, verifyResultValueFloat,
			"ADDS float on W=WZ+W", 1, 1, 17964.637},
	{36, ML_CODE_EADDS, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_float_off, verifyResultValueFloat,
			"ADDS float off W=W+WZ", 2, 1, 0.0f},
	{37, ML_CODE_EADDS, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_float_on, verifyResultValueFloat,
			"ADDS float on W=W+WZ", 2, 1, 17964.637},
	{38, ML_CODE_EADDS, setCodeOp2_WEWZ, setInputDIn_WEWZ_float_off, verifyResultValueZFloat,
			"ADDS float off WZ=W+E", 0, 1, 0.0f},
	{39, ML_CODE_EADDS, setCodeOp2_WEWZ, setInputDIn_WEWZ_float_on, verifyResultValueZFloat,
			"ADDS float on WZ=W+E", 0, 1, 17964.637},
	{40, ML_CODE_EADDS, setCodeOp2_WZEW, setInputDIn_WZEW_float_off, verifyResultValueFloat,
			"ADDS float off WZ=W+E", 1, 1, 0.0f},
	{41, ML_CODE_EADDS, setCodeOp2_WZEW, setInputDIn_WZEW_float_on, verifyResultValueFloat,
			"ADDS float on WZ=W+E", 1, 1, 17964.637},
	{42, ML_CODE_EADDS, setCodeOp2_EEWZ, setInputDIn_EEWZ_float_off, verifyResultValueZFloat,
			"ADDS float off WZ=E+E", 0, 1, 0.0f},
	{43, ML_CODE_EADDS, setCodeOp2_EEWZ, setInputDIn_EEWZ_float_on, verifyResultValueZFloat,
			"ADDS float on WZ=E+E", 0, 1, 17964.637},

	{44, ML_CODE_EADDPS, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_float_off, verifyResultValueZFloat,
			"ADDPS float 0->0 WZ=W+W", 0, 2, 0.0f},
	{45, ML_CODE_EADDPS, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_floatp_on, verifyResultValueZFloat,
			"ADDPS float 0->1 WZ=W+W", 0, 2, 17964.637},
	{46, ML_CODE_EADDPS, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_float_off, verifyResultValueZFloat,
			"ADDPS float 0->0 WZ=W+W", 0, 2, 0.0f},
	{47, ML_CODE_EADDPS, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_floatp_on, verifyResultValueZFloat,
			"ADDPS float 0->1 WZ=W+W", 0, 2, 17964.637},
	{48, ML_CODE_EADDPS, setCodeOp3_WZW_W, setInputDIn_WZW_W_float_off, verifyResultValueFloat,
			"ADDPS float 0->0 W=WZ+W", 1, 2, 0.0f},
	{49, ML_CODE_EADDPS, setCodeOp3_WZW_W, setInputDIn_WZW_W_floatp_on, verifyResultValueFloat,
			"ADDPS float 0->1 W=WZ+W", 1, 2, 17964.637},
	{50, ML_CODE_EADDPS, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_float_off, verifyResultValueFloat,
			"ADDPS float 0->0 W=W+WZ", 2, 2, 0.0f},
	{51, ML_CODE_EADDPS, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_floatp_on, verifyResultValueFloat,
			"ADDPS float 0->1 W=W+WZ", 2, 2, 17964.637},
	{52, ML_CODE_EADDPS, setCodeOp2_WEWZ, setInputDIn_WEWZ_float_off, verifyResultValueZFloat,
			"ADDPS float 0->0 WZ=W+E", 0, 2, 0.0f},
	{53, ML_CODE_EADDPS, setCodeOp2_WEWZ, setInputDIn_WEWZ_floatp_on, verifyResultValueZFloat,
			"ADDPS float 0->1 WZ=W+E", 0, 2, 17964.637},
	{54, ML_CODE_EADDPS, setCodeOp2_WZEW, setInputDIn_WZEW_float_off, verifyResultValueFloat,
			"ADDPS float 0->0 WZ=W+E", 1, 2, 0.0f},
	{55, ML_CODE_EADDPS, setCodeOp2_WZEW, setInputDIn_WZEW_floatp_on, verifyResultValueFloat,
			"ADDPS float 0->1 WZ=W+E", 1, 2, 17964.637},
	{56, ML_CODE_EADDPS, setCodeOp2_EEWZ, setInputDIn_EEWZ_float_off, verifyResultValueZFloat,
			"ADDPS float 0->0 WZ=E+E", 0, 2, 0.0f},
	{57, ML_CODE_EADDPS, setCodeOp2_EEWZ, setInputDIn_EEWZ_floatp_on, verifyResultValueZFloat,
			"ADDPS float 0->1 WZ=E+E", 0, 2, 17964.637},

	{58, ML_CODE_ESUBS, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_float_off, verifyResultValueZFloat,
			"SUBS float off WZ=W-W", 0, 1, 0.0f},
	{59, ML_CODE_ESUBS, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_float_on, verifyResultValueZFloat,
			"SUBS float on WZ=W-W", 0, 1, 6041.763},
	{60, ML_CODE_ESUBS, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_float_off, verifyResultValueZFloat,
			"SUBS float off WZ=W-W", 0, 1, 0.0f},
	{61, ML_CODE_ESUBS, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_float_on, verifyResultValueZFloat,
			"SUBS float on WZ=W-W", 0, 1, 6041.763},
	{62, ML_CODE_ESUBS, setCodeOp3_WZW_W, setInputDIn_WZW_W_float_off, verifyResultValueFloat,
			"SUBS float off W=WZ-W", 1, 1, 0.0f},
	{63, ML_CODE_ESUBS, setCodeOp3_WZW_W, setInputDIn_WZW_W_float_on, verifyResultValueFloat,
			"SUBS float on W=WZ-W", 1, 1, 6041.763},
	{64, ML_CODE_ESUBS, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_float_off, verifyResultValueFloat,
			"SUBS float off W=W-WZ", 2, 1, 0.0f},
	{65, ML_CODE_ESUBS, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_float_on, verifyResultValueFloat,
			"SUBS float on W=W-WZ", 2, 1, 6041.763},
	{66, ML_CODE_ESUBS, setCodeOp2_WEWZ, setInputDIn_WEWZ_float_off, verifyResultValueZFloat,
			"SUBS float off WZ=W-E", 0, 1, 0.0f},
	{67, ML_CODE_ESUBS, setCodeOp2_WEWZ, setInputDIn_WEWZ_float_on, verifyResultValueZFloat,
			"SUBS float on WZ=W-E", 0, 1, 6041.763},
	{68, ML_CODE_ESUBS, setCodeOp2_WZEW, setInputDIn_WZEW_float_off, verifyResultValueFloat,
			"SUBS float off WZ=W-E", 1, 1, 0.0f},
	{69, ML_CODE_ESUBS, setCodeOp2_WZEW, setInputDIn_WZEW_float_on, verifyResultValueFloat,
			"SUBS float on WZ=W-E", 1, 1, 6041.763},
	{70, ML_CODE_ESUBS, setCodeOp2_EEWZ, setInputDIn_EEWZ_float_off, verifyResultValueZFloat,
			"SUBS float off WZ=E-E", 0, 1, 0.0f},
	{71, ML_CODE_ESUBS, setCodeOp2_EEWZ, setInputDIn_EEWZ_float_on, verifyResultValueZFloat,
			"SUBS float on WZ=E-E", 0, 1, 6041.763},

	{72, ML_CODE_ESUBPS, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_float_off, verifyResultValueZFloat,
			"SUBPS float 0->0 WZ=W-W", 0, 2, 0.0f},
	{73, ML_CODE_ESUBPS, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_floatp_on, verifyResultValueZFloat,
			"SUBPS float 0->1 WZ=W-W", 0, 2, 6041.763},
	{74, ML_CODE_ESUBPS, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_float_off, verifyResultValueZFloat,
			"SUBPS float 0->0 WZ=W-W", 0, 2, 0.0f},
	{75, ML_CODE_ESUBPS, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_floatp_on, verifyResultValueZFloat,
			"SUBPS float 0->1 WZ=W-W", 0, 2, 6041.763},
	{76, ML_CODE_ESUBPS, setCodeOp3_WZW_W, setInputDIn_WZW_W_float_off, verifyResultValueFloat,
			"SUBPS float 0->0 W=WZ-W", 1, 2, 0.0f},
	{77, ML_CODE_ESUBPS, setCodeOp3_WZW_W, setInputDIn_WZW_W_floatp_on, verifyResultValueFloat,
			"SUBPS float 0->1 W=WZ-W", 1, 2, 6041.763},
	{78, ML_CODE_ESUBPS, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_float_off, verifyResultValueFloat,
			"SUBPS float 0->0 W=W-WZ", 2, 2, 0.0f},
	{79, ML_CODE_ESUBPS, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_floatp_on, verifyResultValueFloat,
			"SUBPS float 0->1 W=W-WZ", 2, 2, 6041.763},
	{80, ML_CODE_ESUBPS, setCodeOp2_WEWZ, setInputDIn_WEWZ_float_off, verifyResultValueZFloat,
			"SUBPS float 0->0 WZ=W-E", 0, 2, 0.0f},
	{81, ML_CODE_ESUBPS, setCodeOp2_WEWZ, setInputDIn_WEWZ_floatp_on, verifyResultValueZFloat,
			"SUBPS float 0->1 WZ=W-E", 0, 2, 6041.763},
	{82, ML_CODE_ESUBPS, setCodeOp2_WZEW, setInputDIn_WZEW_float_off, verifyResultValueFloat,
			"SUBPS float 0->0 WZ=W-E", 1, 2, 0.0f},
	{83, ML_CODE_ESUBPS, setCodeOp2_WZEW, setInputDIn_WZEW_floatp_on, verifyResultValueFloat,
			"SUBPS float 0->1 WZ=W-E", 1, 2, 6041.763},
	{84, ML_CODE_ESUBPS, setCodeOp2_EEWZ, setInputDIn_EEWZ_float_off, verifyResultValueZFloat,
			"SUBPS float 0->0 WZ=E-E", 0, 2, 0.0f},
	{85, ML_CODE_ESUBPS, setCodeOp2_EEWZ, setInputDIn_EEWZ_floatp_on, verifyResultValueZFloat,
			"SUBPS float 0->1 WZ=E-E", 0, 2, 6041.763},

	{86, ML_CODE_EMLT, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_float_off, verifyResultValueZFloat,
			"Multiply float off WZ=W*W", 0, 1, 0.0f},
	{87, ML_CODE_EMLT, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_float_on, verifyResultValueZFloat,
			"Multiply float on WZ=W*W", 0, 1, 71556320.5984},
	{88, ML_CODE_EMLT, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_float_off, verifyResultValueZFloat,
			"Multiply float off WZ=W*W", 0, 1, 0.0f},
	{89, ML_CODE_EMLT, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_float_on, verifyResultValueZFloat,
			"Multiply float on WZ=W*W", 0, 1, 71556320.5984},
	{90, ML_CODE_EMLT, setCodeOp3_WZW_W, setInputDIn_WZW_W_float_off, verifyResultValueFloat,
			"Multiply float off W=WZ*W", 1, 1, 0.0f},
	{91, ML_CODE_EMLT, setCodeOp3_WZW_W, setInputDIn_WZW_W_float_on, verifyResultValueFloat,
			"Multiply float on W=WZ*W", 1, 1, 71556320.5984},
	{92, ML_CODE_EMLT, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_float_off, verifyResultValueFloat,
			"Multiply float off W=W*WZ", 2, 1, 0.0f},
	{93, ML_CODE_EMLT, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_float_on, verifyResultValueFloat,
			"Multiply float on W=W*WZ", 2, 1, 71556320.5984},
	{94, ML_CODE_EMLT, setCodeOp2_WEWZ, setInputDIn_WEWZ_float_off, verifyResultValueZFloat,
			"Multiply float off WZ=W*E", 0, 1, 0.0f},
	{95, ML_CODE_EMLT, setCodeOp2_WEWZ, setInputDIn_WEWZ_float_on, verifyResultValueZFloat,
			"Multiply float on WZ=W*E", 0, 1, 71556320.5984},
	{96, ML_CODE_EMLT, setCodeOp2_WZEW, setInputDIn_WZEW_float_off, verifyResultValueFloat,
			"Multiply float off WZ=W*E", 1, 1, 0.0f},
	{97, ML_CODE_EMLT, setCodeOp2_WZEW, setInputDIn_WZEW_float_on, verifyResultValueFloat,
			"Multiply float on WZ=W/E", 1, 1, 71556320.5984},
	{98, ML_CODE_EMLT, setCodeOp2_EEWZ, setInputDIn_EEWZ_float_off, verifyResultValueZFloat,
			"Multiply float off WZ=E*E", 0, 1, 0.0f},
	{99, ML_CODE_EMLT, setCodeOp2_EEWZ, setInputDIn_EEWZ_float_on, verifyResultValueZFloat,
			"Multiply float on WZ=E*E", 0, 1, 71556320.5984},

	{100, ML_CODE_EMLTP, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_float_off, verifyResultValueZFloat,
			"MultiplyP float 0->0 WZ=W*W", 0, 2, 0.0f},
	{101, ML_CODE_EMLTP, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_floatp_on, verifyResultValueZFloat,
			"MultiplyP float 0->1 WZ=W*W", 0, 2, 71556320.5984},
	{102, ML_CODE_EMLTP, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_float_off, verifyResultValueZFloat,
			"MultiplyP float 0->0 WZ=W*W", 0, 2, 0.0f},
	{103, ML_CODE_EMLTP, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_floatp_on, verifyResultValueZFloat,
			"MultiplyP float 0->1 WZ=W*W", 0, 2, 71556320.5984},
	{104, ML_CODE_EMLTP, setCodeOp3_WZW_W, setInputDIn_WZW_W_float_off, verifyResultValueFloat,
			"MultiplyP float 0->0 W=WZ*W", 1, 2, 0.0f},
	{105, ML_CODE_EMLTP, setCodeOp3_WZW_W, setInputDIn_WZW_W_floatp_on, verifyResultValueFloat,
			"MultiplyP float 0->1 W=WZ*W", 1, 2, 71556320.5984},
	{106, ML_CODE_EMLTP, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_float_off, verifyResultValueFloat,
			"MultiplyP float 0->0 W=W*WZ", 2, 2, 0.0f},
	{107, ML_CODE_EMLTP, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_floatp_on, verifyResultValueFloat,
			"MultiplyP float 0->1 W=W*WZ", 2, 2, 71556320.5984},
	{108, ML_CODE_EMLTP, setCodeOp2_WEWZ, setInputDIn_WEWZ_float_off, verifyResultValueZFloat,
			"MultiplyP float 0->0 WZ=W*E", 0, 2, 0.0f},
	{109, ML_CODE_EMLTP, setCodeOp2_WEWZ, setInputDIn_WEWZ_floatp_on, verifyResultValueZFloat,
			"MultiplyP float 0->1 WZ=W*E", 0, 2, 71556320.5984},
	{110, ML_CODE_EMLTP, setCodeOp2_WZEW, setInputDIn_WZEW_float_off, verifyResultValueFloat,
			"MultiplyP float 0->0 WZ=W*E", 1, 2, 0.0f},
	{111, ML_CODE_EMLTP, setCodeOp2_WZEW, setInputDIn_WZEW_floatp_on, verifyResultValueFloat,
			"MultiplyP float 0->1 WZ=W*E", 1, 2, 71556320.5984},
	{112, ML_CODE_EMLTP, setCodeOp2_EEWZ, setInputDIn_EEWZ_float_off, verifyResultValueZFloat,
			"MultiplyP float 0->0 WZ=E*E", 0, 2, 0.0f},
	{113, ML_CODE_EMLTP, setCodeOp2_EEWZ, setInputDIn_EEWZ_floatp_on, verifyResultValueZFloat,
			"MultiplyP float 0->1 WZ=E*E", 0, 2, 71556320.5984},

	{114, ML_CODE_EDIV, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_div_float_off, verifyResultValueZFloat,
			"DIV float off WZ=W/W", 0, 1, 0.0f},
	{115, ML_CODE_EDIV, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_div_float_on, verifyResultValueZFloat,
			"DIV float on WZ=W/W", 0, 1, 5359.041},
	{116, ML_CODE_EDIV, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_div_float_off, verifyResultValueZFloat,
			"DIV float off WZ=W/W", 0, 1, 0.0f},
	{117, ML_CODE_EDIV, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_div_float_on, verifyResultValueZFloat,
			"DIV float on WZ=W/W", 0, 1, 5359.041},
	{118, ML_CODE_EDIV, setCodeOp3_WZW_W, setInputDIn_WZW_W_div_float_off, verifyResultValueFloat,
			"DIV float off W=WZ/W", 1, 1, 0.0f},
	{119, ML_CODE_EDIV, setCodeOp3_WZW_W, setInputDIn_WZW_W_div_float_on, verifyResultValueFloat,
			"DIV float on W=WZ/W", 1, 1, 5359.041},
	{120, ML_CODE_EDIV, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_div_float_off, verifyResultValueFloat,
			"DIV float off W=W/WZ", 2, 1, 0.0f},
	{121, ML_CODE_EDIV, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_div_float_on, verifyResultValueFloat,
			"DIV float on W=W/WZ", 2, 1, 5359.041},
	{122, ML_CODE_EDIV, setCodeOp2_WEWZ_div, setInputDIn_WEWZ_div_float_off, verifyResultValueZFloat,
			"DIV float off WZ=W/E", 0, 1, 0.0f},
	{123, ML_CODE_EDIV, setCodeOp2_WEWZ_div, setInputDIn_WEWZ_div_float_on, verifyResultValueZFloat,
			"DIV float on WZ=W/E", 0, 1, 5359.041},
	{124, ML_CODE_EDIV, setCodeOp2_WZEW_div, setInputDIn_WZEW_div_float_off, verifyResultValueFloat,
			"DIV float off WZ=W/E", 1, 1, 0.0f},
	{125, ML_CODE_EDIV, setCodeOp2_WZEW_div, setInputDIn_WZEW_div_float_on, verifyResultValueFloat,
			"DIV float on WZ=W/E", 1, 1, 5359.041},
	{126, ML_CODE_EDIV, setCodeOp2_EEWZ_div, setInputDIn_EEWZ_float_off, verifyResultValueZFloat,
			"DIV float off WZ=E/E", 0, 1, 0.0f},
	{127, ML_CODE_EDIV, setCodeOp2_EEWZ_div, setInputDIn_EEWZ_float_on, verifyResultValueZFloat,
			"DIV float on WZ=E/E", 0, 1, 5359.041},

	{128, ML_CODE_EDIVP, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_div_float_off, verifyResultValueZFloat,
			"DIVP float 0->0 WZ=W/W", 0, 2, 0.0f},
	{129, ML_CODE_EDIVP, setCodeOp3_WW_WZ, setInputDIn_WW_WZ_div_floatp_on, verifyResultValueZFloat,
			"DIVP float 0->1 WZ=W/W", 0, 2, 5359.041},
	{130, ML_CODE_EDIVP, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_div_float_off, verifyResultValueZFloat,
			"DIVP float 0->0 WZ=W/W", 0, 2, 0.0f},
	{131, ML_CODE_EDIVP, setCodeOp3_W_WWZ, setInputDIn_W_WWZ_div_floatp_on, verifyResultValueZFloat,
			"DIVP float 0->1 WZ=W/W", 0, 2, 5359.041},
	{132, ML_CODE_EDIVP, setCodeOp3_WZW_W, setInputDIn_WZW_W_div_float_off, verifyResultValueFloat,
			"DIVP float 0->0 W=WZ/W", 1, 2, 0.0f},
	{133, ML_CODE_EDIVP, setCodeOp3_WZW_W, setInputDIn_WZW_W_div_floatp_on, verifyResultValueFloat,
			"DIVP float 0->1 W=WZ/W", 1, 2, 5359.041},
	{134, ML_CODE_EDIVP, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_div_float_off, verifyResultValueFloat,
			"DIVP float 0->0 W=W/WZ", 2, 2, 0.0f},
	{135, ML_CODE_EDIVP, setCodeOp3_WWZ_W, setInputDIn_WWZ_W_div_floatp_on, verifyResultValueFloat,
			"DIVP float 0->1 W=W/WZ", 2, 2, 5359.041},
	{136, ML_CODE_EDIVP, setCodeOp2_WEWZ_div, setInputDIn_WEWZ_div_float_off, verifyResultValueZFloat,
			"DIVP float 0->0 WZ=W/E", 0, 2, 0.0f},
	{137, ML_CODE_EDIVP, setCodeOp2_WEWZ_div, setInputDIn_WEWZ_div_floatp_on, verifyResultValueZFloat,
			"DIVP float 0->1 WZ=W/E", 0, 2, 5359.041},
	{138, ML_CODE_EDIVP, setCodeOp2_WZEW_div, setInputDIn_WZEW_div_float_off, verifyResultValueFloat,
			"DIVP float 0->0 WZ=W/E", 1, 2, 0.0f},
	{139, ML_CODE_EDIVP, setCodeOp2_WZEW_div, setInputDIn_WZEW_div_floatp_on, verifyResultValueFloat,
			"DIVP float 0->1 WZ=W/E", 1, 2, 5359.041},
	{140, ML_CODE_EDIVP, setCodeOp2_EEWZ_div, setInputDIn_EEWZ_float_off, verifyResultValueZFloat,
			"DIVP float 0->0 WZ=E/E", 0, 2, 0.0f},
	{141, ML_CODE_EDIVP, setCodeOp2_EEWZ_div, setInputDIn_EEWZ_floatp_on, verifyResultValueZFloat,
			"DIVP float 0->1 WZ=E/E", 0, 2, 5359.041},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0, 0 }
};


int total_arithmetic_float_idx_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_arithmetic_float_idx_test_number; i++)
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

int setCodeOp2_EinWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 5961.437); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WW_WZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperand(in, 50);
	      addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_W_WWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos);
	      addMLOperand(out, 50); addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WZW_W(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperand(in, 50);
	      addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3_WWZ_W(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandZIndex(in, 50, idx_pos);
	      addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_WEWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandFloat(OPERAND_ML_CODE_E, 5961.437);
	     addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_WEWZ_div(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandFloat(OPERAND_ML_CODE_E, 9.73521);
	     addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_WZEW(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperandFloat(OPERAND_ML_CODE_E, 5961.437);
	      addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_WZEW_div(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperandFloat(OPERAND_ML_CODE_E, 9.73521);
	      addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_EEWZ(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 12003.2); addMLOperandFloat(OPERAND_ML_CODE_E, 5961.437);
		addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_EEWZ_div(uint16 ml_cmd, uint8 in, uint16 in_pos,uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 52171.39); addMLOperandFloat(OPERAND_ML_CODE_E, 9.73521);
		addMLOperandZIndex(out, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputDIn_WWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 5961.437);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_WWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 5961.437);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_WWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 5961.437);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 12003.2);

	TestCodeTearDown();
}

void setInputSIn_EWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 12003.2);

	TestCodeTearDown();
}

void setInputSIn_EWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 12003.2);

	TestCodeTearDown();
}

void setInputSIn_EWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_WZW_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 5961.437);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_WZW_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 5961.437);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_WZW_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 5961.437);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_WW_WZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 5961.437);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WW_WZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 5961.437);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WW_WZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 5961.437);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_W_WWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 5961.437);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_W_WWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 5961.437);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_W_WWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 5961.437);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WZW_W_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 5961.437);

	TestCodeTearDown();
}

void setInputDIn_WZW_W_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 5961.437);

	TestCodeTearDown();
}

void setInputDIn_WZW_W_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 5961.437);

	TestCodeTearDown();
}

void setInputDIn_WWZ_W_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50+z_val, 5961.437);

	TestCodeTearDown();
}

void setInputDIn_WWZ_W_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50+z_val, 5961.437);

	TestCodeTearDown();
}

void setInputDIn_WWZ_W_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50+z_val, 5961.437);

	TestCodeTearDown();
}

void setInputDIn_WEWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WEWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WEWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WZEW_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_WZEW_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_WZEW_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_EEWZ_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_EEWZ_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_EEWZ_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WW_WZ_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 9.73521);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WW_WZ_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 9.73521);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WW_WZ_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 9.73521);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_W_WWZ_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 9.73521);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_W_WWZ_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 9.73521);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_W_WWZ_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 9.73521);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WZW_W_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 9.73521);

	TestCodeTearDown();
}

void setInputDIn_WZW_W_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 9.73521);

	TestCodeTearDown();
}

void setInputDIn_WZW_W_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 9.73521);

	TestCodeTearDown();
}

void setInputDIn_WWZ_W_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50+z_val, 9.73521);

	TestCodeTearDown();
}

void setInputDIn_WWZ_W_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50+z_val, 9.73521);

	TestCodeTearDown();
}

void setInputDIn_WWZ_W_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50+z_val, 9.73521);

	TestCodeTearDown();
}

void setInputDIn_WEWZ_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WEWZ_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WEWZ_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos+z_val, 0.0);

	TestCodeTearDown();
}

void setInputDIn_WZEW_div_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 52171.39);

	TestCodeTearDown();
}

void setInputDIn_WZEW_div_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 52171.39);

	TestCodeTearDown();
}

void setInputDIn_WZEW_div_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 52171.39);

	TestCodeTearDown();
}



static short z_index;
static short getIndexVal(void)
{
	return z_index;
}

static void setIndexVal(short zVal)
{
	z_index = zVal;
}

static int verifyResultValueZFloat(int tcase, uint8 dest_reg, uint16 pos, float expected)
{
	int rc=0;
	float result;
	short zVal;
	char reg[] = {'D', 'W'};

	//result = (double)PLC_Register_getFloat(dest_reg, pos);
	zVal = getIndexVal();
	if(!test_getFloat(&result, dest_reg, pos+zVal))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d Index Reg %c[%d+%d]=%f %f\n", tcase, reg[dest_reg-OPERAND_ML_CODE_D], pos, zVal, result, expected);
	CU_ASSERT_EQUAL(result, expected);
	if(result != expected) rc=1;

	return rc;
}

static int isIndexRangeOver(int type, uint16 in, uint16 in_pos, uint16 out, uint16 out_pos, short idx_val)
{
	// X,Y,R,L,F,B,SM,D,W
	uint16 lastIndex[] = {8190,8190,8190,8190,2046,8190,0,12286,8190};

	//DBG_LOGPRINT("isIndexRangeOver ty=%d, in(%d:%d) out(%d:%d) index=%d\n", type, in, in_pos, out, out_pos, idx_val );
	if(type == 0 ) // out is index
	{
		if( out < OPERAND_ML_CODE_D) return 1;

		if( out_pos+idx_val > lastIndex[out] || out_pos+idx_val < 0 )
			return 1;

		if( in == out && in_pos == out_pos+idx_val )
			return 1;
	}
	else if(type == 1) // op1 is index
	{
		if( in < OPERAND_ML_CODE_D) return 1;

		if( in_pos+idx_val > lastIndex[in] || in_pos+idx_val < 0 )
			return 1;

		if( in == out && in_pos+idx_val == out_pos )
				return 1;
	}
	else if(type == 2) // op2 is index
	{
		if( in < OPERAND_ML_CODE_D) return 1;

		if( 50+idx_val > lastIndex[in] || 50+idx_val < 0 )
			return 1;

		if( in == out && in_pos == out_pos )
			return 1;
	}
	return 0;
}

static uint16 getInPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}};

	return pos[inx_pos][reg];
}

static uint16 getOutPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; // 2 word

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_arithmetic_float_index(int tno, uint16 dummy)
{
	int i, rc=0, rc2=1, inx, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	short z_index;
	float res_float;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getOutPos(out, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				if(in==out)
					continue;
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getInPos(in, i);
					for(inx=0; inx<15; inx++) // testidx
					{
						if( isIndexRangeOver(testCase[tno].z_type, in, in_pos, out, out_pos, testidx[inx].val) )
						{
							//DBG_LOGPRINT(" SKIP test range over type=%d inx=%d %s[%d], %s[%d] Z[%d]=%d \n", \
								testCase[tno].z_type, inx, reg[in], in_pos, reg[out], out_pos, testidx[inx].pos, testidx[inx].val);
							continue; // skip test
						}

						rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos, testidx[inx].pos);
						if( rc2 == 0 ) continue;

						testCase[tno].setTestInput_fn(in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);

						rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error!  ty=%d %s[%d] %s[%d] inx=%d Z[%d]=%d\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								testCase[tno].z_type, reg[in], in_pos, reg[out], out_pos, inx, testidx[inx].pos, testidx[inx].val);
						}
						else
						{
							setIndexVal(testidx[inx].val);
							rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
							if(rc == 1)
							{
								if(testCase[tno].z_type==0) // out is index
								{
									test_getFloat(&res_float, out, out_pos+testidx[inx].val);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d] in_%s[50], out_%s[%d+%d]=%f exp=%f\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
										reg[in], in_pos, reg[in], reg[out], out_pos, testidx[inx].val, res_float, testCase[tno].expected);
								}
								else if(testCase[tno].z_type==1) // op1 is index
								{
									test_getFloat(&res_float, out, out_pos);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] in_%s[50], out_%s[%d]=%f exp=%f\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
										reg[in], in_pos, testidx[inx].val, reg[in], reg[out], out_pos, res_float, testCase[tno].expected);
								}
								else // op2 is index
								{
									test_getFloat(&res_float, out, out_pos);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d] in_%s[50+%d] out_%s[%d]=%f exp=%f\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
										reg[in], in_pos, reg[in], testidx[inx].val, reg[out], out_pos, res_float, testCase[tno].expected);
								}
							}
						}
					}
				}
			}
		}
	}
}


void testBasicArithmeticFloatIndexCommand(void)
{
	int i, index=43;
	int start, end;
	char log[] = "err_arith_float_index.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic float index LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
	test_basic_arithmetic_float_index(index, 0);

#else
	total_arithmetic_float_idx_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_EADD); //ML_CODE_EADD
	end = getTestCaseNumberEnd(ML_CODE_EDIV); //ML_CODE_EDIV

	DBG_LOGPRINT("testArithmeticFloatIndexCommand: %d to %d total %d\n", start, end, total_arithmetic_float_idx_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_float_index(index, 0);
	}
#endif
	fclose(flog);
}
#endif
