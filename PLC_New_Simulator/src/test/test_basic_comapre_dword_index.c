/*
 * test_basic_comapre_dword_index.c
 *
 *  Created on: Jul 23, 2015
 *      Author: hrjung
 */


#ifdef USE_CUNIT_TEST_DEF

#ifndef PLC_LISTOFTESTSUITE_H_
#include "../PLC_ListOfTestSuite.h"
#endif
#include "../testPlatform/PLC_Platform.h"

#include <stdio.h>
#include <stdlib.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

extern void TestCodeInit(void);
extern void TestCodeTearDown(void);
extern int runTestCode(int run_step, char *testFuncName);

extern int setCodeOp_Idx_WWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp_Idx_WZW(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_Idx_WWZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_Idx_WZW(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern int verifyResultNormal(int tcase, uint8 dest_reg, uint16 pos, uint8 expected);

int setCodeOp_Idx_N2WZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp_Idx_K2WZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp_Idx_WZN2(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp_Idx_WZK2(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

int setCodeOp2_Idx_N2WZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_Idx_K2WZ(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_Idx_WZN2(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_Idx_WZK2(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_WWZ_hbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_lbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_hlessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_llessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_sameVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_hbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_lbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_hlessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_llessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_sameVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_hbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_lbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_hlessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_llessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_sameVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_hbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_lbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_hlessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_llessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_sameVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_hbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_lbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_hlessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_llessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_sameVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_hbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_lbigVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_hlessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_llessVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_sameVal32(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);

void setInputIdx_WWZ_hbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_lbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_hlessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_llessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_sameVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_hbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_lbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_hlessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_llessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WWZ_sameVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_hbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_lbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_hlessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_llessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_sameVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_hbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_lbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_hlessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_llessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_NWZ_sameVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_hbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_lbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_hlessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_llessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_sameVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_hbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_lbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_hlessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_llessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_KWZ_sameVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_hbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_lbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_hlessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_llessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_sameVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_hbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_lbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_hlessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_llessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZW_sameVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_hbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_lbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_hlessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_llessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_sameVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_hbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_lbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_hlessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_llessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZN_sameVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_hbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_lbigVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_hlessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_llessVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_sameVal32_off(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_hbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_lbigVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_hlessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_llessVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);
void setInputIdx_WZK_sameVal32_on(uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos, uint16 idx_pos, uint16 idx_val);



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
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16, uint8, uint16, uint16, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16, uint16, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, uint8);
	char str[40];
	int z_type; // 0 : op2 is index, 1: op1 is index
	int run_step;
	int expected;
} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_LDDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT op1 > op2z", 0, 1, 0},
	{1, ML_CODE_LDDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT op1 > op2z", 0, 1, 0},
	{2, ML_CODE_LDDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT op1 < op2z", 0, 1, 0},
	{3, ML_CODE_LDDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_llessVal32, verifyResultNormal,
			"LDDEQ_OUT op1 < op2z", 0, 1, 0},
	{4, ML_CODE_LDDEQ, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal32, verifyResultNormal,
			"LDDEQ_OUT op1 == op2z", 0, 1, 1},
	{5, ML_CODE_LDDEQ, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT nop1 > op2z", 0, 1, 0},
	{6, ML_CODE_LDDEQ, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT nop1 > op2z", 0, 1, 0},
	{7, ML_CODE_LDDEQ, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT nop1 < op2z", 0, 1, 0},
	{8, ML_CODE_LDDEQ, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_llessVal32, verifyResultNormal,
			"LDDEQ_OUT nop1 < op2z", 0, 1, 0},
	{9, ML_CODE_LDDEQ, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_sameVal32, verifyResultNormal,
			"LDDEQ_OUT nop1 == op2z", 0, 1, 1},
	{10, ML_CODE_LDDEQ, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT K > op2z", 0, 1, 0},
	{11, ML_CODE_LDDEQ, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT K > op2z", 0, 1, 0},
	{12, ML_CODE_LDDEQ, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT K < op2z", 0, 1, 0},
	{13, ML_CODE_LDDEQ, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_llessVal32, verifyResultNormal,
			"LDDEQ_OUT K < op2z", 0, 1, 0},
	{14, ML_CODE_LDDEQ, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_sameVal32, verifyResultNormal,
			"LDDEQ_OUT K == op2z", 0, 1, 1},
	{15, ML_CODE_LDDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT op1z > op2", 1, 1, 0},
	{16, ML_CODE_LDDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT op1z == op2", 1, 1, 0},
	{17, ML_CODE_LDDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT op1z < op2", 1, 1, 0},
	{18, ML_CODE_LDDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_llessVal32, verifyResultNormal,
			"LDDEQ_OUT op1z == op2", 1, 1, 0},
	{19, ML_CODE_LDDEQ, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal32, verifyResultNormal,
			"LDDEQ_OUT op1z < op2", 1, 1, 1},
	{20, ML_CODE_LDDEQ, setCodeOp_Idx_WZN2, setInputIdx_WZN_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT op1z > nop2", 1, 1, 0},
	{21, ML_CODE_LDDEQ, setCodeOp_Idx_WZN2, setInputIdx_WZN_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT op1z > nop2", 1, 1, 0},
	{22, ML_CODE_LDDEQ, setCodeOp_Idx_WZN2, setInputIdx_WZN_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT op1z < nop2", 1, 1, 0},
	{23, ML_CODE_LDDEQ, setCodeOp_Idx_WZN2, setInputIdx_WZN_llessVal32, verifyResultNormal,
			"LDDEQ_OUT op1z < nop2", 1, 1, 0},
	{24, ML_CODE_LDDEQ, setCodeOp_Idx_WZN2, setInputIdx_WZN_sameVal32, verifyResultNormal,
			"LDDEQ_OUT op1z == nop2", 1, 1, 1},
	{25, ML_CODE_LDDEQ, setCodeOp_Idx_WZK2, setInputIdx_WZK_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT op1z > K", 1, 1, 0},
	{26, ML_CODE_LDDEQ, setCodeOp_Idx_WZK2, setInputIdx_WZK_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT op1z > K", 1, 1, 0},
	{27, ML_CODE_LDDEQ, setCodeOp_Idx_WZK2, setInputIdx_WZK_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT op1z < K", 1, 1, 0},
	{28, ML_CODE_LDDEQ, setCodeOp_Idx_WZK2, setInputIdx_WZK_llessVal32, verifyResultNormal,
			"LDDEQ_OUT op1z < K", 1, 1, 0},
	{29, ML_CODE_LDDEQ, setCodeOp_Idx_WZK2, setInputIdx_WZK_sameVal32, verifyResultNormal,
			"LDDEQ_OUT op1z == K", 1, 1, 1},

	{30, ML_CODE_LDDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hbigVal32, verifyResultNormal,
			"LDDNE_OUT op1 > op2z", 0, 1, 1},
	{31, ML_CODE_LDDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lbigVal32, verifyResultNormal,
			"LDDNE_OUT op1 > op2z", 0, 1, 1},
	{32, ML_CODE_LDDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hlessVal32, verifyResultNormal,
			"LDDNE_OUT op1 < op2z", 0, 1, 1},
	{33, ML_CODE_LDDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_llessVal32, verifyResultNormal,
			"LDDNE_OUT op1 < op2z", 0, 1, 1},
	{34, ML_CODE_LDDNE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal32, verifyResultNormal,
			"LDDNE_OUT op1 == op2z", 0, 1, 0},
	{35, ML_CODE_LDDNE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDNE_OUT nop1 > op2z", 0, 1, 1},
	{36, ML_CODE_LDDNE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDNE_OUT nop1 > op2z", 0, 1, 1},
	{37, ML_CODE_LDDNE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hlessVal32, verifyResultNormal,
			"LDDNE_OUT nop1 < op2z", 0, 1, 1},
	{38, ML_CODE_LDDNE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_llessVal32, verifyResultNormal,
			"LDDNE_OUT nop1 < op2z", 0, 1, 1},
	{39, ML_CODE_LDDNE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_sameVal32, verifyResultNormal,
			"LDDNE_OUT nop1 == op2z", 0, 1, 0},
	{40, ML_CODE_LDDNE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hbigVal32, verifyResultNormal,
			"LDDNE_OUT K > op2z", 0, 1, 1},
	{41, ML_CODE_LDDNE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_lbigVal32, verifyResultNormal,
			"LDDNE_OUT K > op2z", 0, 1, 1},
	{42, ML_CODE_LDDNE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hlessVal32, verifyResultNormal,
			"LDDNE_OUT K < op2z", 0, 1, 1},
	{43, ML_CODE_LDDNE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_llessVal32, verifyResultNormal,
			"LDDNE_OUT K < op2z", 0, 1, 1},
	{44, ML_CODE_LDDNE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_sameVal32, verifyResultNormal,
			"LDDNE_OUT K == op2z", 0, 1, 0},
	{45, ML_CODE_LDDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_hbigVal32, verifyResultNormal,
			"LDDNE_OUT op1z > op2", 1, 1, 1},
	{46, ML_CODE_LDDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_lbigVal32, verifyResultNormal,
			"LDDNE_OUT op1z == op2", 1, 1, 1},
	{47, ML_CODE_LDDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_hlessVal32, verifyResultNormal,
			"LDDNE_OUT op1z < op2", 1, 1, 1},
	{48, ML_CODE_LDDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_llessVal32, verifyResultNormal,
			"LDDNE_OUT op1z == op2", 1, 1, 1},
	{49, ML_CODE_LDDNE, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal32, verifyResultNormal,
			"LDDNE_OUT op1z < op2", 1, 1, 0},
	{50, ML_CODE_LDDNE, setCodeOp_Idx_WZN2, setInputIdx_WZN_hbigVal32, verifyResultNormal,
			"LDDNE_OUT op1z > nop2", 1, 1, 1},
	{51, ML_CODE_LDDNE, setCodeOp_Idx_WZN2, setInputIdx_WZN_lbigVal32, verifyResultNormal,
			"LDDNE_OUT op1z > nop2", 1, 1, 1},
	{52, ML_CODE_LDDNE, setCodeOp_Idx_WZN2, setInputIdx_WZN_hlessVal32, verifyResultNormal,
			"LDDNE_OUT op1z < nop2", 1, 1, 1},
	{53, ML_CODE_LDDNE, setCodeOp_Idx_WZN2, setInputIdx_WZN_llessVal32, verifyResultNormal,
			"LDDNE_OUT op1z < nop2", 1, 1, 1},
	{54, ML_CODE_LDDNE, setCodeOp_Idx_WZN2, setInputIdx_WZN_sameVal32, verifyResultNormal,
			"LDDNE_OUT op1z == nop2", 1, 1, 0},
	{55, ML_CODE_LDDNE, setCodeOp_Idx_WZK2, setInputIdx_WZK_hbigVal32, verifyResultNormal,
			"LDDNE_OUT op1z > K", 1, 1, 1},
	{56, ML_CODE_LDDNE, setCodeOp_Idx_WZK2, setInputIdx_WZK_lbigVal32, verifyResultNormal,
			"LDDNE_OUT op1z > K", 1, 1, 1},
	{57, ML_CODE_LDDNE, setCodeOp_Idx_WZK2, setInputIdx_WZK_hlessVal32, verifyResultNormal,
			"LDDNE_OUT op1z < K", 1, 1, 1},
	{58, ML_CODE_LDDNE, setCodeOp_Idx_WZK2, setInputIdx_WZK_llessVal32, verifyResultNormal,
			"LDDNE_OUT op1z < K", 1, 1, 1},
	{59, ML_CODE_LDDNE, setCodeOp_Idx_WZK2, setInputIdx_WZK_sameVal32, verifyResultNormal,
			"LDDNE_OUT op1z == K", 1, 1, 0},

	{60, ML_CODE_LDDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hbigVal32, verifyResultNormal,
			"LDDGT_OUT op1 > op2z", 0, 1, 1},
	{61, ML_CODE_LDDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lbigVal32, verifyResultNormal,
			"LDDGT_OUT op1 > op2z", 0, 1, 1},
	{62, ML_CODE_LDDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hlessVal32, verifyResultNormal,
			"LDDGT_OUT op1 < op2z", 0, 1, 0},
	{63, ML_CODE_LDDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_llessVal32, verifyResultNormal,
			"LDDGT_OUT op1 < op2z", 0, 1, 0},
	{64, ML_CODE_LDDGT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal32, verifyResultNormal,
			"LDDGT_OUT op1 == op2z", 0, 1, 0},
	{65, ML_CODE_LDDGT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDGT_OUT nop1 > op2z", 0, 1, 1},
	{66, ML_CODE_LDDGT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDGT_OUT nop1 > op2z", 0, 1, 1},
	{67, ML_CODE_LDDGT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hlessVal32, verifyResultNormal,
			"LDDGT_OUT nop1 < op2z", 0, 1, 0},
	{68, ML_CODE_LDDGT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_llessVal32, verifyResultNormal,
			"LDDGT_OUT nop1 < op2z", 0, 1, 0},
	{69, ML_CODE_LDDGT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_sameVal32, verifyResultNormal,
			"LDDGT_OUT nop1 == op2z", 0, 1, 0},
	{70, ML_CODE_LDDGT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hbigVal32, verifyResultNormal,
			"LDDGT_OUT K > op2z", 0, 1, 0},
	{71, ML_CODE_LDDGT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_lbigVal32, verifyResultNormal,
			"LDDGT_OUT K > op2z", 0, 1, 0},
	{72, ML_CODE_LDDGT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hlessVal32, verifyResultNormal,
			"LDDGT_OUT K < op2z", 0, 1, 1},
	{73, ML_CODE_LDDGT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_llessVal32, verifyResultNormal,
			"LDDGT_OUT K < op2z", 0, 1, 1},
	{74, ML_CODE_LDDGT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_sameVal32, verifyResultNormal,
			"LDDGT_OUT K == op2z", 0, 1, 0},
	{75, ML_CODE_LDDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_hbigVal32, verifyResultNormal,
			"LDDGT_OUT op1z > op2", 1, 1, 1},
	{76, ML_CODE_LDDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_lbigVal32, verifyResultNormal,
			"LDDGT_OUT op1z == op2", 1, 1, 1},
	{77, ML_CODE_LDDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_hlessVal32, verifyResultNormal,
			"LDDGT_OUT op1z < op2", 1, 1, 0},
	{78, ML_CODE_LDDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_llessVal32, verifyResultNormal,
			"LDDGT_OUT op1z == op2", 1, 1, 0},
	{79, ML_CODE_LDDGT, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal32, verifyResultNormal,
			"LDDGT_OUT op1z < op2", 1, 1, 0},
	{80, ML_CODE_LDDGT, setCodeOp_Idx_WZN2, setInputIdx_WZN_hbigVal32, verifyResultNormal,
			"LDDGT_OUT op1z > nop2", 1, 1, 1},
	{81, ML_CODE_LDDGT, setCodeOp_Idx_WZN2, setInputIdx_WZN_lbigVal32, verifyResultNormal,
			"LDDGT_OUT op1z > nop2", 1, 1, 1},
	{82, ML_CODE_LDDGT, setCodeOp_Idx_WZN2, setInputIdx_WZN_hlessVal32, verifyResultNormal,
			"LDDGT_OUT op1z < nop2", 1, 1, 0},
	{83, ML_CODE_LDDGT, setCodeOp_Idx_WZN2, setInputIdx_WZN_llessVal32, verifyResultNormal,
			"LDDGT_OUT op1z < nop2", 1, 1, 0},
	{84, ML_CODE_LDDGT, setCodeOp_Idx_WZN2, setInputIdx_WZN_sameVal32, verifyResultNormal,
			"LDDGT_OUT op1z == nop2", 1, 1, 0},
	{85, ML_CODE_LDDGT, setCodeOp_Idx_WZK2, setInputIdx_WZK_hbigVal32, verifyResultNormal,
			"LDDGT_OUT op1z > K", 1, 1, 1},
	{86, ML_CODE_LDDGT, setCodeOp_Idx_WZK2, setInputIdx_WZK_lbigVal32, verifyResultNormal,
			"LDDGT_OUT op1z > K", 1, 1, 1},
	{87, ML_CODE_LDDGT, setCodeOp_Idx_WZK2, setInputIdx_WZK_hlessVal32, verifyResultNormal,
			"LDDGT_OUT op1z < K", 1, 1, 0},
	{88, ML_CODE_LDDGT, setCodeOp_Idx_WZK2, setInputIdx_WZK_llessVal32, verifyResultNormal,
			"LDDGT_OUT op1z < K", 1, 1, 0},
	{89, ML_CODE_LDDGT, setCodeOp_Idx_WZK2, setInputIdx_WZK_sameVal32, verifyResultNormal,
			"LDDGT_OUT op1z == K", 1, 1, 0},

	{90, ML_CODE_LDDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hbigVal32, verifyResultNormal,
			"LDDGE_OUT op1 > op2z", 0, 1, 1},
	{91, ML_CODE_LDDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lbigVal32, verifyResultNormal,
			"LDDGE_OUT op1 > op2z", 0, 1, 1},
	{92, ML_CODE_LDDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hlessVal32, verifyResultNormal,
			"LDDGE_OUT op1 < op2z", 0, 1, 0},
	{93, ML_CODE_LDDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_llessVal32, verifyResultNormal,
			"LDDGE_OUT op1 < op2z", 0, 1, 0},
	{94, ML_CODE_LDDGE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal32, verifyResultNormal,
			"LDDGE_OUT op1 == op2z", 0, 1, 1},
	{95, ML_CODE_LDDGE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDGE_OUT nop1 > op2z", 0, 1, 1},
	{96, ML_CODE_LDDGE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDGE_OUT nop1 > op2z", 0, 1, 1},
	{97, ML_CODE_LDDGE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hlessVal32, verifyResultNormal,
			"LDDGE_OUT nop1 < op2z", 0, 1, 0},
	{98, ML_CODE_LDDGE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_llessVal32, verifyResultNormal,
			"LDDGE_OUT nop1 < op2z", 0, 1, 0},
	{99, ML_CODE_LDDGE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_sameVal32, verifyResultNormal,
			"LDDGE_OUT nop1 == op2z", 0, 1, 1},
	{100, ML_CODE_LDDGE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hbigVal32, verifyResultNormal,
			"LDDGE_OUT K > op2z", 0, 1, 0},
	{101, ML_CODE_LDDGE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_lbigVal32, verifyResultNormal,
			"LDDGE_OUT K > op2z", 0, 1, 0},
	{102, ML_CODE_LDDGE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hlessVal32, verifyResultNormal,
			"LDDGE_OUT K < op2z", 0, 1, 1},
	{103, ML_CODE_LDDGE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_llessVal32, verifyResultNormal,
			"LDDGE_OUT K < op2z", 0, 1, 1},
	{104, ML_CODE_LDDGE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_sameVal32, verifyResultNormal,
			"LDDGE_OUT K == op2z", 0, 1, 1},
	{105, ML_CODE_LDDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_hbigVal32, verifyResultNormal,
			"LDDGE_OUT op1z > op2", 1, 1, 1},
	{106, ML_CODE_LDDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_lbigVal32, verifyResultNormal,
			"LDDGE_OUT op1z == op2", 1, 1, 1},
	{107, ML_CODE_LDDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_hlessVal32, verifyResultNormal,
			"LDDGE_OUT op1z < op2", 1, 1, 0},
	{108, ML_CODE_LDDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_llessVal32, verifyResultNormal,
			"LDDGE_OUT op1z == op2", 1, 1, 0},
	{109, ML_CODE_LDDGE, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal32, verifyResultNormal,
			"LDDGE_OUT op1z < op2", 1, 1, 1},
	{110, ML_CODE_LDDGE, setCodeOp_Idx_WZN2, setInputIdx_WZN_hbigVal32, verifyResultNormal,
			"LDDGE_OUT op1z > nop2", 1, 1, 1},
	{111, ML_CODE_LDDGE, setCodeOp_Idx_WZN2, setInputIdx_WZN_lbigVal32, verifyResultNormal,
			"LDDGE_OUT op1z > nop2", 1, 1, 1},
	{112, ML_CODE_LDDGE, setCodeOp_Idx_WZN2, setInputIdx_WZN_hlessVal32, verifyResultNormal,
			"LDDGE_OUT op1z < nop2", 1, 1, 0},
	{113, ML_CODE_LDDGE, setCodeOp_Idx_WZN2, setInputIdx_WZN_llessVal32, verifyResultNormal,
			"LDDGE_OUT op1z < nop2", 1, 1, 0},
	{114, ML_CODE_LDDGE, setCodeOp_Idx_WZN2, setInputIdx_WZN_sameVal32, verifyResultNormal,
			"LDDGE_OUT op1z == nop2", 1, 1, 1},
	{115, ML_CODE_LDDGE, setCodeOp_Idx_WZK2, setInputIdx_WZK_hbigVal32, verifyResultNormal,
			"LDDGE_OUT op1z > K", 1, 1, 1},
	{116, ML_CODE_LDDGE, setCodeOp_Idx_WZK2, setInputIdx_WZK_lbigVal32, verifyResultNormal,
			"LDDGE_OUT op1z > K", 1, 1, 1},
	{117, ML_CODE_LDDGE, setCodeOp_Idx_WZK2, setInputIdx_WZK_hlessVal32, verifyResultNormal,
			"LDDGE_OUT op1z < K", 1, 1, 0},
	{118, ML_CODE_LDDGE, setCodeOp_Idx_WZK2, setInputIdx_WZK_llessVal32, verifyResultNormal,
			"LDDGE_OUT op1z < K", 1, 1, 0},
	{119, ML_CODE_LDDGE, setCodeOp_Idx_WZK2, setInputIdx_WZK_sameVal32, verifyResultNormal,
			"LDDGE_OUT op1z == K", 1, 1, 1},

	{120, ML_CODE_LDDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hbigVal32, verifyResultNormal,
			"LDDLT_OUT op1 > op2z", 0, 1, 0},
	{121, ML_CODE_LDDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lbigVal32, verifyResultNormal,
			"LDDLT_OUT op1 > op2z", 0, 1, 0},
	{122, ML_CODE_LDDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hlessVal32, verifyResultNormal,
			"LDDLT_OUT op1 < op2z", 0, 1, 1},
	{123, ML_CODE_LDDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_llessVal32, verifyResultNormal,
			"LDDLT_OUT op1 < op2z", 0, 1, 1},
	{124, ML_CODE_LDDLT, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal32, verifyResultNormal,
			"LDDLT_OUT op1 == op2z", 0, 1, 0},
	{125, ML_CODE_LDDLT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDLT_OUT nop1 > op2z", 0, 1, 0},
	{126, ML_CODE_LDDLT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDLT_OUT nop1 > op2z", 0, 1, 0},
	{127, ML_CODE_LDDLT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hlessVal32, verifyResultNormal,
			"LDDLT_OUT nop1 < op2z", 0, 1, 1},
	{128, ML_CODE_LDDLT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_llessVal32, verifyResultNormal,
			"LDDLT_OUT nop1 < op2z", 0, 1, 1},
	{129, ML_CODE_LDDLT, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_sameVal32, verifyResultNormal,
			"LDDLT_OUT nop1 == op2z", 0, 1, 0},
	{130, ML_CODE_LDDLT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hbigVal32, verifyResultNormal,
			"LDDLT_OUT K > op2z", 0, 1, 1},
	{131, ML_CODE_LDDLT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_lbigVal32, verifyResultNormal,
			"LDDLT_OUT K > op2z", 0, 1, 1},
	{132, ML_CODE_LDDLT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hlessVal32, verifyResultNormal,
			"LDDLT_OUT K < op2z", 0, 1, 0},
	{133, ML_CODE_LDDLT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_llessVal32, verifyResultNormal,
			"LDDLT_OUT K < op2z", 0, 1, 0},
	{134, ML_CODE_LDDLT, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_sameVal32, verifyResultNormal,
			"LDDLT_OUT K == op2z", 0, 1, 0},
	{135, ML_CODE_LDDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_hbigVal32, verifyResultNormal,
			"LDDLT_OUT op1z > op2", 1, 1, 0},
	{136, ML_CODE_LDDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_lbigVal32, verifyResultNormal,
			"LDDLT_OUT op1z == op2", 1, 1, 0},
	{137, ML_CODE_LDDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_hlessVal32, verifyResultNormal,
			"LDDLT_OUT op1z < op2", 1, 1, 1},
	{138, ML_CODE_LDDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_llessVal32, verifyResultNormal,
			"LDDLT_OUT op1z == op2", 1, 1, 1},
	{139, ML_CODE_LDDLT, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal32, verifyResultNormal,
			"LDDLT_OUT op1z < op2", 1, 1, 0},
	{140, ML_CODE_LDDLT, setCodeOp_Idx_WZN2, setInputIdx_WZN_hbigVal32, verifyResultNormal,
			"LDDLT_OUT op1z > nop2", 1, 1, 0},
	{141, ML_CODE_LDDLT, setCodeOp_Idx_WZN2, setInputIdx_WZN_lbigVal32, verifyResultNormal,
			"LDDLT_OUT op1z > nop2", 1, 1, 0},
	{142, ML_CODE_LDDLT, setCodeOp_Idx_WZN2, setInputIdx_WZN_hlessVal32, verifyResultNormal,
			"LDDLT_OUT op1z < nop2", 1, 1, 1},
	{143, ML_CODE_LDDLT, setCodeOp_Idx_WZN2, setInputIdx_WZN_llessVal32, verifyResultNormal,
			"LDDLT_OUT op1z < nop2", 1, 1, 1},
	{144, ML_CODE_LDDLT, setCodeOp_Idx_WZN2, setInputIdx_WZN_sameVal32, verifyResultNormal,
			"LDDLT_OUT op1z == nop2", 1, 1, 0},
	{145, ML_CODE_LDDLT, setCodeOp_Idx_WZK2, setInputIdx_WZK_hbigVal32, verifyResultNormal,
			"LDDLT_OUT op1z > K", 1, 1, 1},
	{146, ML_CODE_LDDLT, setCodeOp_Idx_WZK2, setInputIdx_WZK_lbigVal32, verifyResultNormal,
			"LDDLT_OUT op1z > K", 1, 1, 0},
	{147, ML_CODE_LDDLT, setCodeOp_Idx_WZK2, setInputIdx_WZK_hlessVal32, verifyResultNormal,
			"LDDLT_OUT op1z < K", 1, 1, 1},
	{148, ML_CODE_LDDLT, setCodeOp_Idx_WZK2, setInputIdx_WZK_llessVal32, verifyResultNormal,
			"LDDLT_OUT op1z < K", 1, 1, 1},
	{149, ML_CODE_LDDLT, setCodeOp_Idx_WZK2, setInputIdx_WZK_sameVal32, verifyResultNormal,
			"LDDLT_OUT op1z == K", 1, 1, 0},

	{150, ML_CODE_LDDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hbigVal32, verifyResultNormal,
			"LDDLE_OUT op1 > op2z", 0, 1, 0},
	{151, ML_CODE_LDDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_lbigVal32, verifyResultNormal,
			"LDDLE_OUT op1 > op2z", 0, 1, 0},
	{152, ML_CODE_LDDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_hlessVal32, verifyResultNormal,
			"LDDLE_OUT op1 < op2z", 0, 1, 1},
	{153, ML_CODE_LDDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_llessVal32, verifyResultNormal,
			"LDDLE_OUT op1 < op2z", 0, 1, 1},
	{154, ML_CODE_LDDLE, setCodeOp_Idx_WWZ, setInputIdx_WWZ_sameVal32, verifyResultNormal,
			"LDDLE_OUT op1 == op2z", 0, 1, 1},
	{155, ML_CODE_LDDLE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDLE_OUT nop1 > op2z", 0, 1, 0},
	{156, ML_CODE_LDDLE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hbigVal32, verifyResultNormal,
			"LDDLE_OUT nop1 > op2z", 0, 1, 0},
	{157, ML_CODE_LDDLE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_hlessVal32, verifyResultNormal,
			"LDDLE_OUT nop1 < op2z", 0, 1, 1},
	{158, ML_CODE_LDDLE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_llessVal32, verifyResultNormal,
			"LDDLE_OUT nop1 < op2z", 0, 1, 1},
	{159, ML_CODE_LDDLE, setCodeOp_Idx_N2WZ, setInputIdx_NWZ_sameVal32, verifyResultNormal,
			"LDDLE_OUT nop1 == op2z", 0, 1, 1},
	{160, ML_CODE_LDDLE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hbigVal32, verifyResultNormal,
			"LDDLE_OUT K > op2z", 0, 1, 1},
	{161, ML_CODE_LDDLE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_lbigVal32, verifyResultNormal,
			"LDDLE_OUT K > op2z", 0, 1, 1},
	{162, ML_CODE_LDDLE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_hlessVal32, verifyResultNormal,
			"LDDLE_OUT K < op2z", 0, 1, 0},
	{163, ML_CODE_LDDLE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_llessVal32, verifyResultNormal,
			"LDDLE_OUT K < op2z", 0, 1, 0},
	{164, ML_CODE_LDDLE, setCodeOp_Idx_K2WZ, setInputIdx_KWZ_sameVal32, verifyResultNormal,
			"LDDLE_OUT K == op2z", 0, 1, 1},
	{165, ML_CODE_LDDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_hbigVal32, verifyResultNormal,
			"LDDLE_OUT op1z > op2", 1, 1, 0},
	{166, ML_CODE_LDDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_lbigVal32, verifyResultNormal,
			"LDDLE_OUT op1z == op2", 1, 1, 0},
	{167, ML_CODE_LDDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_hlessVal32, verifyResultNormal,
			"LDDLE_OUT op1z < op2", 1, 1, 1},
	{168, ML_CODE_LDDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_llessVal32, verifyResultNormal,
			"LDDLE_OUT op1z == op2", 1, 1, 1},
	{169, ML_CODE_LDDLE, setCodeOp_Idx_WZW, setInputIdx_WZW_sameVal32, verifyResultNormal,
			"LDDLE_OUT op1z < op2", 1, 1, 1},
	{170, ML_CODE_LDDLE, setCodeOp_Idx_WZN2, setInputIdx_WZN_hbigVal32, verifyResultNormal,
			"LDDLE_OUT op1z > nop2", 1, 1, 0},
	{171, ML_CODE_LDDLE, setCodeOp_Idx_WZN2, setInputIdx_WZN_lbigVal32, verifyResultNormal,
			"LDDLE_OUT op1z > nop2", 1, 1, 0},
	{172, ML_CODE_LDDLE, setCodeOp_Idx_WZN2, setInputIdx_WZN_hlessVal32, verifyResultNormal,
			"LDDLE_OUT op1z < nop2", 1, 1, 1},
	{173, ML_CODE_LDDLE, setCodeOp_Idx_WZN2, setInputIdx_WZN_llessVal32, verifyResultNormal,
			"LDDLE_OUT op1z < nop2", 1, 1, 1},
	{174, ML_CODE_LDDLE, setCodeOp_Idx_WZN2, setInputIdx_WZN_sameVal32, verifyResultNormal,
			"LDDLE_OUT op1z == nop2", 1, 1, 1},
	{175, ML_CODE_LDDLE, setCodeOp_Idx_WZK2, setInputIdx_WZK_hbigVal32, verifyResultNormal,
			"LDDLE_OUT op1z > K", 1, 1, 1},
	{176, ML_CODE_LDDLE, setCodeOp_Idx_WZK2, setInputIdx_WZK_lbigVal32, verifyResultNormal,
			"LDDLE_OUT op1z > K", 1, 1, 0},
	{177, ML_CODE_LDDLE, setCodeOp_Idx_WZK2, setInputIdx_WZK_hlessVal32, verifyResultNormal,
			"LDDLE_OUT op1z < K", 1, 1, 1},
	{178, ML_CODE_LDDLE, setCodeOp_Idx_WZK2, setInputIdx_WZK_llessVal32, verifyResultNormal,
			"LDDLE_OUT op1z < K", 1, 1, 1},
	{179, ML_CODE_LDDLE, setCodeOp_Idx_WZK2, setInputIdx_WZK_sameVal32, verifyResultNormal,
			"LDDLE_OUT op1z == K", 1, 1, 1},

	{180, ML_CODE_ANDDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1 > op2z", 0, 1, 0},
	{181, ML_CODE_ANDDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1 < op2z", 0, 1, 0},
	{182, ML_CODE_ANDDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1 == op2z", 0, 1, 0},
	{183, ML_CODE_ANDDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1 > op2z", 0, 1, 0},
	{184, ML_CODE_ANDDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1 > op2z", 0, 1, 0},
	{185, ML_CODE_ANDDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1 < op2z", 0, 1, 0},
	{186, ML_CODE_ANDDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1 < op2z", 0, 1, 0},
	{177, ML_CODE_ANDDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1 == op2z", 0, 1, 1},
	{188, ML_CODE_ANDDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off nop1 > op2z", 0, 1, 0},
	{189, ML_CODE_ANDDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off nop1 < op2z", 0, 1, 0},
	{190, ML_CODE_ANDDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off nop1 == op2z", 0, 1, 0},
	{191, ML_CODE_ANDDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on nop1 > op2z", 0, 1, 0},
	{192, ML_CODE_ANDDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on nop1 > op2z", 0, 1, 0},
	{193, ML_CODE_ANDDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on nop1 < op2z", 0, 1, 0},
	{194, ML_CODE_ANDDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on nop1 < op2z", 0, 1, 0},
	{195, ML_CODE_ANDDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on nop1 == op2z", 0, 1, 1},
	{196, ML_CODE_ANDDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off K > op2z", 0, 1, 0},
	{197, ML_CODE_ANDDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off K == op2z", 0, 1, 0},
	{198, ML_CODE_ANDDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off K < op2z", 0, 1, 0},
	{199, ML_CODE_ANDDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on K > op2z", 0, 1, 0},
	{200, ML_CODE_ANDDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on K == op2z", 0, 1, 0},
	{201, ML_CODE_ANDDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on K < op2z", 0, 1, 0},
	{202, ML_CODE_ANDDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on K == op2z", 0, 1, 0},
	{203, ML_CODE_ANDDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on K < op2z", 0, 1, 1},
	{204, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1z > op2", 1, 1, 0},
	{205, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1z < op2", 1, 1, 0},
	{206, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1z == op2", 1, 1, 0},
	{207, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z > op2", 1, 1, 0},
	{208, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z > op2", 1, 1, 0},
	{209, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z < op2", 1, 1, 0},
	{210, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z < op2", 1, 1, 0},
	{211, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z == op2", 1, 1, 1},
	{212, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1z > nop2", 1, 1, 0},
	{213, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1z < nop2", 1, 1, 0},
	{214, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1z == nop2", 1, 1, 0},
	{215, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z > nop2", 1, 1, 0},
	{216, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z > nop2", 1, 1, 0},
	{217, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z < nop2", 1, 1, 0},
	{218, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z < nop2", 1, 1, 0},
	{219, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z == nop2", 1, 1, 1},
	{220, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1z > K", 1, 1, 0},
	{221, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1z < K", 1, 1, 0},
	{222, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1z == K", 1, 1, 0},
	{223, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z > K", 1, 1, 0},
	{224, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z > K", 1, 1, 0},
	{225, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z < K", 1, 1, 0},
	{226, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z < K", 1, 1, 0},
	{227, ML_CODE_ANDDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT on op1z == K", 1, 1, 1},

	{228, ML_CODE_ANDDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1 > op2z", 0, 1, 0},
	{229, ML_CODE_ANDDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1 < op2z", 0, 1, 0},
	{230, ML_CODE_ANDDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1 == op2z", 0, 1, 0},
	{231, ML_CODE_ANDDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1 > op2z", 0, 1, 1},
	{232, ML_CODE_ANDDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1 > op2z", 0, 1, 1},
	{233, ML_CODE_ANDDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1 < op2z", 0, 1, 1},
	{234, ML_CODE_ANDDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1 < op2z", 0, 1, 1},
	{235, ML_CODE_ANDDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1 == op2z", 0, 1, 0},
	{236, ML_CODE_ANDDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off nop1 > op2z", 0, 1, 0},
	{237, ML_CODE_ANDDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off nop1 < op2z", 0, 1, 0},
	{238, ML_CODE_ANDDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off nop1 == op2z", 0, 1, 0},
	{239, ML_CODE_ANDDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on nop1 > op2z", 0, 1, 1},
	{240, ML_CODE_ANDDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on nop1 > op2z", 0, 1, 1},
	{241, ML_CODE_ANDDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on nop1 < op2z", 0, 1, 1},
	{242, ML_CODE_ANDDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on nop1 < op2z", 0, 1, 1},
	{243, ML_CODE_ANDDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT on nop1 == op2z", 0, 1, 0},
	{244, ML_CODE_ANDDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off K > op2z", 0, 1, 0},
	{245, ML_CODE_ANDDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off K == op2z", 0, 1, 0},
	{246, ML_CODE_ANDDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off K < op2z", 0, 1, 0},
	{247, ML_CODE_ANDDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on K > op2z", 0, 1, 1},
	{248, ML_CODE_ANDDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on K == op2z", 0, 1, 1},
	{249, ML_CODE_ANDDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on K < op2z", 0, 1, 1},
	{250, ML_CODE_ANDDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on K == op2z", 0, 1, 1},
	{251, ML_CODE_ANDDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT on K < op2z", 0, 1, 0},
	{252, ML_CODE_ANDDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1z > op2", 1, 1, 0},
	{253, ML_CODE_ANDDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1z < op2", 1, 1, 0},
	{254, ML_CODE_ANDDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1z == op2", 1, 1, 0},
	{255, ML_CODE_ANDDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z > op2", 1, 1, 1},
	{256, ML_CODE_ANDDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z > op2", 1, 1, 1},
	{257, ML_CODE_ANDDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z < op2", 1, 1, 1},
	{258, ML_CODE_ANDDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z < op2", 1, 1, 1},
	{259, ML_CODE_ANDDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z == op2", 1, 1, 0},
	{260, ML_CODE_ANDDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1z > nop2", 1, 1, 0},
	{261, ML_CODE_ANDDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1z < nop2", 1, 1, 0},
	{262, ML_CODE_ANDDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1z == nop2", 1, 1, 0},
	{263, ML_CODE_ANDDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z > nop2", 1, 1, 1},
	{264, ML_CODE_ANDDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z > nop2", 1, 1, 1},
	{265, ML_CODE_ANDDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z < nop2", 1, 1, 1},
	{266, ML_CODE_ANDDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z < nop2", 1, 1, 1},
	{267, ML_CODE_ANDDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z == nop2", 1, 1, 0},
	{268, ML_CODE_ANDDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1z > K", 1, 1, 0},
	{269, ML_CODE_ANDDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1z < K", 1, 1, 0},
	{270, ML_CODE_ANDDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1z == K", 1, 1, 0},
	{271, ML_CODE_ANDDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z > K", 1, 1, 1},
	{272, ML_CODE_ANDDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z > K", 1, 1, 1},
	{273, ML_CODE_ANDDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z < K", 1, 1, 1},
	{274, ML_CODE_ANDDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z < K", 1, 1, 1},
	{275, ML_CODE_ANDDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT on op1z == K", 1, 1, 0},

	{276, ML_CODE_ANDDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1 > op2z", 0, 1, 0},
	{277, ML_CODE_ANDDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1 < op2z", 0, 1, 0},
	{278, ML_CODE_ANDDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1 == op2z", 0, 1, 0},
	{279, ML_CODE_ANDDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1 > op2z", 0, 1, 1},
	{280, ML_CODE_ANDDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1 > op2z", 0, 1, 1},
	{281, ML_CODE_ANDDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1 < op2z", 0, 1, 0},
	{282, ML_CODE_ANDDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1 < op2z", 0, 1, 0},
	{283, ML_CODE_ANDDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1 == op2z", 0, 1, 0},
	{284, ML_CODE_ANDDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off nop1 > op2z", 0, 1, 0},
	{285, ML_CODE_ANDDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off nop1 < op2z", 0, 1, 0},
	{286, ML_CODE_ANDDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off nop1 == op2z", 0, 1, 0},
	{287, ML_CODE_ANDDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on nop1 > op2z", 0, 1, 1},
	{288, ML_CODE_ANDDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on nop1 > op2z", 0, 1, 1},
	{289, ML_CODE_ANDDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on nop1 < op2z", 0, 1, 0},
	{290, ML_CODE_ANDDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on nop1 < op2z", 0, 1, 0},
	{291, ML_CODE_ANDDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT on nop1 == op2z", 0, 1, 0},
	{292, ML_CODE_ANDDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off K > op2z", 0, 1, 0},
	{293, ML_CODE_ANDDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off K == op2z", 0, 1, 0},
	{294, ML_CODE_ANDDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off K < op2z", 0, 1, 0},
	{295, ML_CODE_ANDDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on K > op2z", 0, 1, 0},
	{296, ML_CODE_ANDDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on K == op2z", 0, 1, 0},
	{297, ML_CODE_ANDDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on K < op2z", 0, 1, 1},
	{298, ML_CODE_ANDDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on K == op2z", 0, 1, 1},
	{299, ML_CODE_ANDDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT on K < op2z", 0, 1, 0},
	{300, ML_CODE_ANDDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1z > op2", 1, 1, 0},
	{301, ML_CODE_ANDDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1z < op2", 1, 1, 0},
	{302, ML_CODE_ANDDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1z == op2", 1, 1, 0},
	{303, ML_CODE_ANDDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z > op2", 1, 1, 1},
	{304, ML_CODE_ANDDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z > op2", 1, 1, 1},
	{305, ML_CODE_ANDDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z < op2", 1, 1, 0},
	{306, ML_CODE_ANDDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z < op2", 1, 1, 0},
	{307, ML_CODE_ANDDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z == op2", 1, 1, 0},
	{308, ML_CODE_ANDDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1z > nop2", 1, 1, 0},
	{309, ML_CODE_ANDDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1z < nop2", 1, 1, 0},
	{310, ML_CODE_ANDDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1z == nop2", 1, 1, 0},
	{311, ML_CODE_ANDDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z > nop2", 1, 1, 1},
	{312, ML_CODE_ANDDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z > nop2", 1, 1, 1},
	{313, ML_CODE_ANDDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z < nop2", 1, 1, 0},
	{314, ML_CODE_ANDDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z < nop2", 1, 1, 0},
	{315, ML_CODE_ANDDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z == nop2", 1, 1, 0},
	{316, ML_CODE_ANDDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1z > K", 1, 1, 0},
	{317, ML_CODE_ANDDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1z < K", 1, 1, 0},
	{318, ML_CODE_ANDDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1z == K", 1, 1, 0},
	{319, ML_CODE_ANDDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z > K", 1, 1, 1},
	{320, ML_CODE_ANDDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z > K", 1, 1, 1},
	{321, ML_CODE_ANDDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z < K", 1, 1, 0},
	{322, ML_CODE_ANDDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z < K", 1, 1, 0},
	{323, ML_CODE_ANDDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT on op1z == K", 1, 1, 0},

	{324, ML_CODE_ANDDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1 > op2z", 0, 1, 0},
	{325, ML_CODE_ANDDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1 < op2z", 0, 1, 0},
	{326, ML_CODE_ANDDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1 == op2z", 0, 1, 0},
	{327, ML_CODE_ANDDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1 > op2z", 0, 1, 1},
	{328, ML_CODE_ANDDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1 > op2z", 0, 1, 1},
	{329, ML_CODE_ANDDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1 < op2z", 0, 1, 0},
	{330, ML_CODE_ANDDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1 < op2z", 0, 1, 0},
	{331, ML_CODE_ANDDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1 == op2z", 0, 1, 1},
	{332, ML_CODE_ANDDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off nop1 > op2z", 0, 1, 0},
	{333, ML_CODE_ANDDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off nop1 < op2z", 0, 1, 0},
	{334, ML_CODE_ANDDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off nop1 == op2z", 0, 1, 0},
	{335, ML_CODE_ANDDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on nop1 > op2z", 0, 1, 1},
	{336, ML_CODE_ANDDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on nop1 > op2z", 0, 1, 1},
	{337, ML_CODE_ANDDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on nop1 < op2z", 0, 1, 0},
	{338, ML_CODE_ANDDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on nop1 < op2z", 0, 1, 0},
	{339, ML_CODE_ANDDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT on nop1 == op2z", 0, 1, 1},
	{340, ML_CODE_ANDDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off K > op2z", 0, 1, 0},
	{341, ML_CODE_ANDDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off K == op2z", 0, 1, 0},
	{342, ML_CODE_ANDDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off K < op2z", 0, 1, 0},
	{343, ML_CODE_ANDDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on K > op2z", 0, 1, 0},
	{344, ML_CODE_ANDDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on K == op2z", 0, 1, 0},
	{345, ML_CODE_ANDDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on K < op2z", 0, 1, 1},
	{346, ML_CODE_ANDDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on K == op2z", 0, 1, 1},
	{347, ML_CODE_ANDDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT on K < op2z", 0, 1, 1},
	{348, ML_CODE_ANDDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1z > op2", 1, 1, 0},
	{349, ML_CODE_ANDDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1z < op2", 1, 1, 0},
	{350, ML_CODE_ANDDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1z == op2", 1, 1, 0},
	{351, ML_CODE_ANDDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z > op2", 1, 1, 1},
	{352, ML_CODE_ANDDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z > op2", 1, 1, 1},
	{353, ML_CODE_ANDDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z < op2", 1, 1, 0},
	{354, ML_CODE_ANDDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z < op2", 1, 1, 0},
	{355, ML_CODE_ANDDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z == op2", 1, 1, 1},
	{356, ML_CODE_ANDDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1z > nop2", 1, 1, 0},
	{357, ML_CODE_ANDDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1z < nop2", 1, 1, 0},
	{358, ML_CODE_ANDDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1z == nop2", 1, 1, 0},
	{359, ML_CODE_ANDDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z > nop2", 1, 1, 1},
	{360, ML_CODE_ANDDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z > nop2", 1, 1, 1},
	{361, ML_CODE_ANDDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z < nop2", 1, 1, 0},
	{362, ML_CODE_ANDDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z < nop2", 1, 1, 0},
	{363, ML_CODE_ANDDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z == nop2", 1, 1, 1},
	{364, ML_CODE_ANDDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1z > K", 1, 1, 0},
	{365, ML_CODE_ANDDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1z < K", 1, 1, 0},
	{366, ML_CODE_ANDDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1z == K", 1, 1, 0},
	{367, ML_CODE_ANDDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z > K", 1, 1, 1},
	{368, ML_CODE_ANDDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z > K", 1, 1, 1},
	{369, ML_CODE_ANDDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z < K", 1, 1, 0},
	{370, ML_CODE_ANDDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z < K", 1, 1, 0},
	{371, ML_CODE_ANDDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT on op1z == K", 1, 1, 1},

	{372, ML_CODE_ANDDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1 > op2z", 0, 1, 0},
	{363, ML_CODE_ANDDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1 < op2z", 0, 1, 0},
	{374, ML_CODE_ANDDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1 == op2z", 0, 1, 0},
	{375, ML_CODE_ANDDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1 > op2z", 0, 1, 0},
	{376, ML_CODE_ANDDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1 > op2z", 0, 1, 0},
	{377, ML_CODE_ANDDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1 < op2z", 0, 1, 1},
	{378, ML_CODE_ANDDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1 < op2z", 0, 1, 1},
	{379, ML_CODE_ANDDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1 == op2z", 0, 1, 0},
	{380, ML_CODE_ANDDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off nop1 > op2z", 0, 1, 0},
	{381, ML_CODE_ANDDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off nop1 < op2z", 0, 1, 0},
	{382, ML_CODE_ANDDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off nop1 == op2z", 0, 1, 0},
	{383, ML_CODE_ANDDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on nop1 > op2z", 0, 1, 0},
	{384, ML_CODE_ANDDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on nop1 > op2z", 0, 1, 0},
	{385, ML_CODE_ANDDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on nop1 < op2z", 0, 1, 1},
	{386, ML_CODE_ANDDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on nop1 < op2z", 0, 1, 1},
	{387, ML_CODE_ANDDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT on nop1 == op2z", 0, 1, 0},
	{388, ML_CODE_ANDDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off K > op2z", 0, 1, 0},
	{389, ML_CODE_ANDDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off K == op2z", 0, 1, 0},
	{390, ML_CODE_ANDDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off K < op2z", 0, 1, 0},
	{391, ML_CODE_ANDDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on K > op2z", 0, 1, 1},
	{392, ML_CODE_ANDDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on K == op2z", 0, 1, 1},
	{393, ML_CODE_ANDDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on K < op2z", 0, 1, 0},
	{394, ML_CODE_ANDDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on K == op2z", 0, 1, 0},
	{395, ML_CODE_ANDDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT on K < op2z", 0, 1, 0},
	{396, ML_CODE_ANDDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1z > op2", 1, 1, 0},
	{397, ML_CODE_ANDDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1z < op2", 1, 1, 0},
	{398, ML_CODE_ANDDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1z == op2", 1, 1, 0},
	{399, ML_CODE_ANDDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z > op2", 1, 1, 0},
	{400, ML_CODE_ANDDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z > op2", 1, 1, 0},
	{401, ML_CODE_ANDDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z < op2", 1, 1, 1},
	{402, ML_CODE_ANDDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z < op2", 1, 1, 1},
	{403, ML_CODE_ANDDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z == op2", 1, 1, 0},
	{404, ML_CODE_ANDDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1z > nop2", 1, 1, 0},
	{405, ML_CODE_ANDDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1z < nop2", 1, 1, 0},
	{406, ML_CODE_ANDDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1z == nop2", 1, 1, 0},
	{407, ML_CODE_ANDDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z > nop2", 1, 1, 0},
	{408, ML_CODE_ANDDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z > nop2", 1, 1, 0},
	{409, ML_CODE_ANDDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z < nop2", 1, 1, 1},
	{410, ML_CODE_ANDDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z < nop2", 1, 1, 1},
	{411, ML_CODE_ANDDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z == nop2", 1, 1, 0},
	{412, ML_CODE_ANDDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1z > K", 1, 1, 0},
	{413, ML_CODE_ANDDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1z < K", 1, 1, 0},
	{414, ML_CODE_ANDDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1z == K", 1, 1, 0},
	{415, ML_CODE_ANDDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z > K", 1, 1, 0},
	{416, ML_CODE_ANDDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z > K", 1, 1, 0},
	{417, ML_CODE_ANDDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z < K", 1, 1, 1},
	{418, ML_CODE_ANDDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z < K", 1, 1, 1},
	{419, ML_CODE_ANDDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT on op1z == K", 1, 1, 0},

	{420, ML_CODE_ANDDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1 > op2z", 0, 1, 0},
	{421, ML_CODE_ANDDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1 < op2z", 0, 1, 0},
	{422, ML_CODE_ANDDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1 == op2z", 0, 1, 0},
	{423, ML_CODE_ANDDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1 > op2z", 0, 1, 0},
	{424, ML_CODE_ANDDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1 > op2z", 0, 1, 0},
	{425, ML_CODE_ANDDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1 < op2z", 0, 1, 1},
	{426, ML_CODE_ANDDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1 < op2z", 0, 1, 1},
	{427, ML_CODE_ANDDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1 == op2z", 0, 1, 1},
	{428, ML_CODE_ANDDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off nop1 > op2z", 0, 1, 0},
	{429, ML_CODE_ANDDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off nop1 < op2z", 0, 1, 0},
	{430, ML_CODE_ANDDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off nop1 == op2z", 0, 1, 0},
	{431, ML_CODE_ANDDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on nop1 > op2z", 0, 1, 0},
	{432, ML_CODE_ANDDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on nop1 > op2z", 0, 1, 0},
	{433, ML_CODE_ANDDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on nop1 < op2z", 0, 1, 1},
	{434, ML_CODE_ANDDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on nop1 < op2z", 0, 1, 1},
	{435, ML_CODE_ANDDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT on nop1 == op2z", 0, 1, 1},
	{436, ML_CODE_ANDDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off K > op2z", 0, 1, 0},
	{437, ML_CODE_ANDDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off K == op2z", 0, 1, 0},
	{438, ML_CODE_ANDDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off K < op2z", 0, 1, 0},
	{439, ML_CODE_ANDDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on K > op2z", 0, 1, 1},
	{440, ML_CODE_ANDDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on K == op2z", 0, 1, 1},
	{441, ML_CODE_ANDDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on K < op2z", 0, 1, 0},
	{442, ML_CODE_ANDDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on K == op2z", 0, 1, 0},
	{443, ML_CODE_ANDDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT on K < op2z", 0, 1, 1},
	{444, ML_CODE_ANDDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1z > op2", 1, 1, 0},
	{445, ML_CODE_ANDDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1z < op2", 1, 1, 0},
	{446, ML_CODE_ANDDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1z == op2", 1, 1, 0},
	{447, ML_CODE_ANDDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z > op2", 1, 1, 0},
	{448, ML_CODE_ANDDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z > op2", 1, 1, 0},
	{449, ML_CODE_ANDDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z < op2", 1, 1, 1},
	{450, ML_CODE_ANDDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z < op2", 1, 1, 1},
	{451, ML_CODE_ANDDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z == op2", 1, 1, 1},
	{452, ML_CODE_ANDDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1z > nop2", 1, 1, 0},
	{453, ML_CODE_ANDDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1z < nop2", 1, 1, 0},
	{454, ML_CODE_ANDDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1z == nop2", 1, 1, 0},
	{455, ML_CODE_ANDDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z > nop2", 1, 1, 0},
	{456, ML_CODE_ANDDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z > nop2", 1, 1, 0},
	{457, ML_CODE_ANDDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z < nop2", 1, 1, 1},
	{458, ML_CODE_ANDDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z < nop2", 1, 1, 1},
	{459, ML_CODE_ANDDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z == nop2", 1, 1, 1},
	{460, ML_CODE_ANDDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1z > K", 1, 1, 0},
	{461, ML_CODE_ANDDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1z < K", 1, 1, 0},
	{462, ML_CODE_ANDDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1z == K", 1, 1, 0},
	{463, ML_CODE_ANDDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z > K", 1, 1, 0},
	{464, ML_CODE_ANDDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z > K", 1, 1, 0},
	{465, ML_CODE_ANDDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z < K", 1, 1, 1},
	{466, ML_CODE_ANDDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z < K", 1, 1, 1},
	{467, ML_CODE_ANDDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT on op1z == K", 1, 1, 1},

	{468, ML_CODE_ORDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 > op2z", 0, 1, 0},
	{469, ML_CODE_ORDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 > op2z", 0, 1, 0},
	{470, ML_CODE_ORDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 < op2z", 0, 1, 0},
	{471, ML_CODE_ORDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 < op2z", 0, 1, 0},
	{472, ML_CODE_ORDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 == op2z", 0, 1, 1},
	{473, ML_CODE_ORDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1 > op2z", 0, 1, 1},
	{474, ML_CODE_ORDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1 < op2z", 0, 1, 1},
	{475, ML_CODE_ORDEQ, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1 == op2z", 0, 1, 1},
	{476, ML_CODE_ORDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 > op2z", 0, 1, 0},
	{477, ML_CODE_ORDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 == op2z", 0, 1, 0},
	{478, ML_CODE_ORDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 < op2z", 0, 1, 0},
	{479, ML_CODE_ORDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 == op2z", 0, 1, 0},
	{480, ML_CODE_ORDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off nop1 < op2z", 0, 1, 1},
	{481, ML_CODE_ORDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT on nop1 > op2z", 0, 1, 1},
	{482, ML_CODE_ORDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT on nop1 == op2z", 0, 1, 1},
	{483, ML_CODE_ORDEQ, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT on nop1 < op2z", 0, 1, 1},
	{484, ML_CODE_ORDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off K > op2z", 0, 1, 0},
	{485, ML_CODE_ORDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off K > op2z", 0, 1, 0},
	{486, ML_CODE_ORDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off K < op2z", 0, 1, 0},
	{487, ML_CODE_ORDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off K < op2z", 0, 1, 0},
	{488, ML_CODE_ORDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off K == op2z", 0, 1, 1},
	{489, ML_CODE_ORDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT on K > op2z", 0, 1, 1},
	{490, ML_CODE_ORDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT on K < op2z", 0, 1, 1},
	{491, ML_CODE_ORDEQ, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT on K == op2z", 0, 1, 1},
	{492, ML_CODE_ORDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z > op2", 1, 1, 0},
	{493, ML_CODE_ORDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z > op2", 1, 1, 0},
	{494, ML_CODE_ORDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z < op2", 1, 1, 0},
	{495, ML_CODE_ORDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z < op2", 1, 1, 0},
	{496, ML_CODE_ORDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z == op2", 1, 1, 1},
	{497, ML_CODE_ORDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1z > op2", 1, 1, 1},
	{498, ML_CODE_ORDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1z < op2", 1, 1, 1},
	{499, ML_CODE_ORDEQ, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1z ==op2", 1, 1, 1},
	{500, ML_CODE_ORDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z > nop2", 1, 1, 0},
	{501, ML_CODE_ORDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z > nop2", 1, 1, 0},
	{502, ML_CODE_ORDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z < nop2", 1, 1, 0},
	{503, ML_CODE_ORDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z < nop2", 1, 1, 0},
	{504, ML_CODE_ORDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z == nop2", 1, 1, 1},
	{505, ML_CODE_ORDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1z > nop2", 1, 1, 1},
	{506, ML_CODE_ORDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1z < nop2", 1, 1, 1},
	{507, ML_CODE_ORDEQ, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1z == nop2", 1, 1, 1},
	{508, ML_CODE_ORDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z > K", 1, 1, 0},
	{509, ML_CODE_ORDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z == K", 1, 1, 0},
	{510, ML_CODE_ORDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z < K", 1, 1, 0},
	{511, ML_CODE_ORDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z == K", 1, 1, 0},
	{512, ML_CODE_ORDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1z < K", 1, 1, 1},
	{513, ML_CODE_ORDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1z > K", 1, 1, 1},
	{514, ML_CODE_ORDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1z == K", 1, 1, 1},
	{515, ML_CODE_ORDEQ, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT on op1z < K", 1, 1, 1},

	{516, ML_CODE_ORDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 > op2z", 0, 1, 1},
	{517, ML_CODE_ORDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 > op2z", 0, 1, 1},
	{518, ML_CODE_ORDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 < op2z", 0, 1, 1},
	{519, ML_CODE_ORDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 < op2z", 0, 1, 1},
	{520, ML_CODE_ORDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 == op2z", 0, 1, 0},
	{521, ML_CODE_ORDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1 > op2z", 0, 1, 1},
	{522, ML_CODE_ORDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1 < op2z", 0, 1, 1},
	{523, ML_CODE_ORDNE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1 == op2z", 0, 1, 1},
	{524, ML_CODE_ORDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 > op2z", 0, 1, 1},
	{525, ML_CODE_ORDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 == op2z", 0, 1, 1},
	{526, ML_CODE_ORDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 < op2z", 0, 1, 1},
	{527, ML_CODE_ORDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 == op2z", 0, 1, 1},
	{528, ML_CODE_ORDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off nop1 < op2z", 0, 1, 0},
	{529, ML_CODE_ORDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT on nop1 > op2z", 0, 1, 1},
	{530, ML_CODE_ORDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT on nop1 == op2z", 0, 1, 1},
	{531, ML_CODE_ORDNE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT on nop1 < op2z", 0, 1, 1},
	{532, ML_CODE_ORDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off K > op2z", 0, 1, 1},
	{533, ML_CODE_ORDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off K > op2z", 0, 1, 1},
	{534, ML_CODE_ORDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off K < op2z", 0, 1, 1},
	{535, ML_CODE_ORDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT off K < op2z", 0, 1, 1},
	{536, ML_CODE_ORDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off K == op2z", 0, 1, 0},
	{537, ML_CODE_ORDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT on K > op2z", 0, 1, 1},
	{538, ML_CODE_ORDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT on K < op2z", 0, 1, 1},
	{539, ML_CODE_ORDNE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT on K == op2z", 0, 1, 1},
	{540, ML_CODE_ORDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z > op2", 1, 1, 1},
	{541, ML_CODE_ORDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z > op2", 1, 1, 1},
	{542, ML_CODE_ORDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z < op2", 1, 1, 1},
	{543, ML_CODE_ORDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z < op2", 1, 1, 1},
	{544, ML_CODE_ORDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z == op2", 1, 1, 0},
	{545, ML_CODE_ORDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1z > op2", 1, 1, 1},
	{546, ML_CODE_ORDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1z < op2", 1, 1, 1},
	{547, ML_CODE_ORDNE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1z ==op2", 1, 1, 1},
	{548, ML_CODE_ORDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z > nop2", 1, 1, 1},
	{549, ML_CODE_ORDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z > nop2", 1, 1, 1},
	{550, ML_CODE_ORDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z < nop2", 1, 1, 1},
	{551, ML_CODE_ORDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z < nop2", 1, 1, 1},
	{552, ML_CODE_ORDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z == nop2", 1, 1, 0},
	{553, ML_CODE_ORDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1z > nop2", 1, 1, 1},
	{554, ML_CODE_ORDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1z < nop2", 1, 1, 1},
	{555, ML_CODE_ORDNE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1z == nop2", 1, 1, 1},
	{556, ML_CODE_ORDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z > K", 1, 1, 1},
	{557, ML_CODE_ORDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z == K", 1, 1, 1},
	{558, ML_CODE_ORDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z < K", 1, 1, 1},
	{559, ML_CODE_ORDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z == K", 1, 1, 1},
	{560, ML_CODE_ORDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1z < K", 1, 1, 0},
	{561, ML_CODE_ORDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1z > K", 1, 1, 1},
	{562, ML_CODE_ORDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1z == K", 1, 1, 1},
	{563, ML_CODE_ORDNE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT on op1z < K", 1, 1, 1},

	{564, ML_CODE_ORDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 > op2z", 0, 1, 1},
	{565, ML_CODE_ORDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 > op2z", 0, 1, 1},
	{566, ML_CODE_ORDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 < op2z", 0, 1, 0},
	{567, ML_CODE_ORDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 < op2z", 0, 1, 0},
	{568, ML_CODE_ORDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 == op2z", 0, 1, 0},
	{569, ML_CODE_ORDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1 > op2z", 0, 1, 1},
	{570, ML_CODE_ORDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1 < op2z", 0, 1, 1},
	{571, ML_CODE_ORDGT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1 == op2z", 0, 1, 1},
	{572, ML_CODE_ORDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 > op2z", 0, 1, 1},
	{573, ML_CODE_ORDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 == op2z", 0, 1, 1},
	{574, ML_CODE_ORDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 < op2z", 0, 1, 0},
	{575, ML_CODE_ORDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 == op2z", 0, 1, 0},
	{576, ML_CODE_ORDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off nop1 < op2z", 0, 1, 0},
	{577, ML_CODE_ORDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT on nop1 > op2z", 0, 1, 1},
	{578, ML_CODE_ORDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT on nop1 == op2z", 0, 1, 1},
	{579, ML_CODE_ORDGT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT on nop1 < op2z", 0, 1, 1},
	{580, ML_CODE_ORDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off K > op2z", 0, 1, 0},
	{581, ML_CODE_ORDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off K > op2z", 0, 1, 0},
	{582, ML_CODE_ORDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off K < op2z", 0, 1, 1},
	{583, ML_CODE_ORDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT off K < op2z", 0, 1, 1},
	{584, ML_CODE_ORDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off K == op2z", 0, 1, 0},
	{585, ML_CODE_ORDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT on K > op2z", 0, 1, 1},
	{586, ML_CODE_ORDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT on K < op2z", 0, 1, 1},
	{587, ML_CODE_ORDGT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT on K == op2z", 0, 1, 1},
	{588, ML_CODE_ORDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z > op2", 1, 1, 1},
	{589, ML_CODE_ORDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z > op2", 1, 1, 1},
	{590, ML_CODE_ORDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z < op2", 1, 1, 0},
	{591, ML_CODE_ORDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z < op2", 1, 1, 0},
	{592, ML_CODE_ORDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z == op2", 1, 1, 0},
	{593, ML_CODE_ORDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1z > op2", 1, 1, 1},
	{594, ML_CODE_ORDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1z < op2", 1, 1, 1},
	{595, ML_CODE_ORDGT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1z ==op2", 1, 1, 1},
	{596, ML_CODE_ORDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z > nop2", 1, 1, 1},
	{597, ML_CODE_ORDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z > nop2", 1, 1, 1},
	{598, ML_CODE_ORDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z < nop2", 1, 1, 0},
	{599, ML_CODE_ORDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z < nop2", 1, 1, 0},
	{600, ML_CODE_ORDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z == nop2", 1, 1, 0},
	{601, ML_CODE_ORDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1z > nop2", 1, 1, 1},
	{602, ML_CODE_ORDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1z < nop2", 1, 1, 1},
	{603, ML_CODE_ORDGT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1z == nop2", 1, 1, 1},
	{604, ML_CODE_ORDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z > K", 1, 1, 1},
	{605, ML_CODE_ORDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z == K", 1, 1, 1},
	{606, ML_CODE_ORDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z < K", 1, 1, 0},
	{607, ML_CODE_ORDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z == K", 1, 1, 0},
	{608, ML_CODE_ORDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1z < K", 1, 1, 0},
	{609, ML_CODE_ORDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1z > K", 1, 1, 1},
	{610, ML_CODE_ORDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1z == K", 1, 1, 1},
	{611, ML_CODE_ORDGT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT on op1z < K", 1, 1, 1},

	{612, ML_CODE_ORDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 > op2z", 0, 1, 1},
	{613, ML_CODE_ORDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 > op2z", 0, 1, 1},
	{614, ML_CODE_ORDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 < op2z", 0, 1, 0},
	{615, ML_CODE_ORDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 < op2z", 0, 1, 0},
	{616, ML_CODE_ORDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 == op2z", 0, 1, 1},
	{617, ML_CODE_ORDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1 > op2z", 0, 1, 1},
	{618, ML_CODE_ORDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1 < op2z", 0, 1, 1},
	{619, ML_CODE_ORDGE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1 == op2z", 0, 1, 1},
	{620, ML_CODE_ORDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 > op2z", 0, 1, 1},
	{621, ML_CODE_ORDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 == op2z", 0, 1, 1},
	{622, ML_CODE_ORDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 < op2z", 0, 1, 0},
	{623, ML_CODE_ORDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 == op2z", 0, 1, 0},
	{624, ML_CODE_ORDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off nop1 < op2z", 0, 1, 1},
	{625, ML_CODE_ORDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT on nop1 > op2z", 0, 1, 1},
	{626, ML_CODE_ORDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT on nop1 == op2z", 0, 1, 1},
	{627, ML_CODE_ORDGE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT on nop1 < op2z", 0, 1, 1},
	{628, ML_CODE_ORDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off K > op2z", 0, 1, 0},
	{629, ML_CODE_ORDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off K > op2z", 0, 1, 0},
	{630, ML_CODE_ORDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off K < op2z", 0, 1, 1},
	{631, ML_CODE_ORDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT off K < op2z", 0, 1, 1},
	{632, ML_CODE_ORDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off K == op2z", 0, 1, 1},
	{633, ML_CODE_ORDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT on K > op2z", 0, 1, 1},
	{634, ML_CODE_ORDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT on K < op2z", 0, 1, 1},
	{635, ML_CODE_ORDGE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT on K == op2z", 0, 1, 1},
	{636, ML_CODE_ORDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z > op2", 1, 1, 1},
	{637, ML_CODE_ORDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z > op2", 1, 1, 1},
	{638, ML_CODE_ORDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z < op2", 1, 1, 0},
	{639, ML_CODE_ORDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z < op2", 1, 1, 0},
	{640, ML_CODE_ORDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z == op2", 1, 1, 1},
	{641, ML_CODE_ORDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1z > op2", 1, 1, 1},
	{642, ML_CODE_ORDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1z < op2", 1, 1, 1},
	{643, ML_CODE_ORDGE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1z ==op2", 1, 1, 1},
	{644, ML_CODE_ORDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z > nop2", 1, 1, 1},
	{645, ML_CODE_ORDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z > nop2", 1, 1, 1},
	{646, ML_CODE_ORDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z < nop2", 1, 1, 0},
	{647, ML_CODE_ORDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z < nop2", 1, 1, 0},
	{648, ML_CODE_ORDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z == nop2", 1, 1, 1},
	{649, ML_CODE_ORDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1z > nop2", 1, 1, 1},
	{650, ML_CODE_ORDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1z < nop2", 1, 1, 1},
	{651, ML_CODE_ORDGE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1z == nop2", 1, 1, 1},
	{652, ML_CODE_ORDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z > K", 1, 1, 1},
	{653, ML_CODE_ORDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z == K", 1, 1, 1},
	{654, ML_CODE_ORDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z < K", 1, 1, 0},
	{655, ML_CODE_ORDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z == K", 1, 1, 0},
	{656, ML_CODE_ORDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1z < K", 1, 1, 1},
	{657, ML_CODE_ORDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1z > K", 1, 1, 1},
	{658, ML_CODE_ORDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1z == K", 1, 1, 1},
	{659, ML_CODE_ORDGE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT on op1z < K", 1, 1, 1},

	{660, ML_CODE_ORDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 > op2z", 0, 1, 0},
	{661, ML_CODE_ORDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 > op2z", 0, 1, 0},
	{662, ML_CODE_ORDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 < op2z", 0, 1, 1},
	{663, ML_CODE_ORDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 < op2z", 0, 1, 1},
	{664, ML_CODE_ORDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 == op2z", 0, 1, 0},
	{665, ML_CODE_ORDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1 > op2z", 0, 1, 1},
	{666, ML_CODE_ORDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1 < op2z", 0, 1, 1},
	{667, ML_CODE_ORDLT, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1 == op2z", 0, 1, 1},
	{668, ML_CODE_ORDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 > op2z", 0, 1, 0},
	{669, ML_CODE_ORDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 == op2z", 0, 1, 0},
	{670, ML_CODE_ORDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 < op2z", 0, 1, 1},
	{671, ML_CODE_ORDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 == op2z", 0, 1, 1},
	{672, ML_CODE_ORDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off nop1 < op2z", 0, 1, 0},
	{673, ML_CODE_ORDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT on nop1 > op2z", 0, 1, 1},
	{674, ML_CODE_ORDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT on nop1 == op2z", 0, 1, 1},
	{675, ML_CODE_ORDLT, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT on nop1 < op2z", 0, 1, 1},
	{676, ML_CODE_ORDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off K > op2z", 0, 1, 1},
	{677, ML_CODE_ORDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off K > op2z", 0, 1, 1},
	{678, ML_CODE_ORDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off K < op2z", 0, 1, 0},
	{679, ML_CODE_ORDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT off K < op2z", 0, 1, 0},
	{680, ML_CODE_ORDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off K == op2z", 0, 1, 0},
	{681, ML_CODE_ORDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT on K > op2z", 0, 1, 1},
	{682, ML_CODE_ORDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT on K < op2z", 0, 1, 1},
	{683, ML_CODE_ORDLT, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT on K == op2z", 0, 1, 1},
	{684, ML_CODE_ORDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z > op2", 1, 1, 0},
	{685, ML_CODE_ORDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z > op2", 1, 1, 0},
	{686, ML_CODE_ORDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z < op2", 1, 1, 1},
	{687, ML_CODE_ORDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z < op2", 1, 1, 1},
	{688, ML_CODE_ORDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z == op2", 1, 1, 0},
	{689, ML_CODE_ORDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1z > op2", 1, 1, 1},
	{690, ML_CODE_ORDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1z < op2", 1, 1, 1},
	{691, ML_CODE_ORDLT, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1z ==op2", 1, 1, 1},
	{692, ML_CODE_ORDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z > nop2", 1, 1, 0},
	{693, ML_CODE_ORDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z > nop2", 1, 1, 0},
	{694, ML_CODE_ORDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z < nop2", 1, 1, 1},
	{695, ML_CODE_ORDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z < nop2", 1, 1, 1},
	{696, ML_CODE_ORDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z == nop2", 1, 1, 0},
	{697, ML_CODE_ORDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1z > nop2", 1, 1, 1},
	{698, ML_CODE_ORDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1z < nop2", 1, 1, 1},
	{699, ML_CODE_ORDLT, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1z == nop2", 1, 1, 1},
	{700, ML_CODE_ORDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z > K", 1, 1, 0},
	{701, ML_CODE_ORDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z == K", 1, 1, 0},
	{702, ML_CODE_ORDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z < K", 1, 1, 1},
	{703, ML_CODE_ORDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z == K", 1, 1, 1},
	{704, ML_CODE_ORDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1z < K", 1, 1, 0},
	{705, ML_CODE_ORDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1z > K", 1, 1, 1},
	{706, ML_CODE_ORDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1z == K", 1, 1, 1},
	{707, ML_CODE_ORDLT, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT on op1z < K", 1, 1, 1},

	{708, ML_CODE_ORDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 > op2z", 0, 1, 0},
	{709, ML_CODE_ORDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 > op2z", 0, 1, 0},
	{710, ML_CODE_ORDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 < op2z", 0, 1, 1},
	{711, ML_CODE_ORDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 < op2z", 0, 1, 1},
	{712, ML_CODE_ORDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 == op2z", 0, 1, 1},
	{713, ML_CODE_ORDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1 > op2z", 0, 1, 1},
	{714, ML_CODE_ORDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1 < op2z", 0, 1, 1},
	{715, ML_CODE_ORDLE, setCodeOp2_Idx_WWZ, setInputIdx_WWZ_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1 == op2z", 0, 1, 1},
	{716, ML_CODE_ORDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 > op2z", 0, 1, 0},
	{717, ML_CODE_ORDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 == op2z", 0, 1, 0},
	{718, ML_CODE_ORDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 < op2z", 0, 1, 1},
	{719, ML_CODE_ORDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 == op2z", 0, 1, 1},
	{720, ML_CODE_ORDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off nop1 < op2z", 0, 1, 1},
	{721, ML_CODE_ORDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT on nop1 > op2z", 0, 1, 1},
	{722, ML_CODE_ORDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT on nop1 == op2z", 0, 1, 1},
	{723, ML_CODE_ORDLE, setCodeOp2_Idx_N2WZ, setInputIdx_NWZ_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT on nop1 < op2z", 0, 1, 1},
	{724, ML_CODE_ORDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off K > op2z", 0, 1, 1},
	{725, ML_CODE_ORDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off K > op2z", 0, 1, 1},
	{726, ML_CODE_ORDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off K < op2z", 0, 1, 0},
	{727, ML_CODE_ORDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT off K < op2z", 0, 1, 0},
	{728, ML_CODE_ORDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off K == op2z", 0, 1, 1},
	{729, ML_CODE_ORDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT on K > op2z", 0, 1, 1},
	{730, ML_CODE_ORDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT on K < op2z", 0, 1, 1},
	{731, ML_CODE_ORDLE, setCodeOp2_Idx_K2WZ, setInputIdx_KWZ_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT on K == op2z", 0, 1, 1},
	{732, ML_CODE_ORDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z > op2", 1, 1, 0},
	{733, ML_CODE_ORDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z > op2", 1, 1, 0},
	{734, ML_CODE_ORDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z < op2", 1, 1, 1},
	{735, ML_CODE_ORDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z < op2", 1, 1, 1},
	{736, ML_CODE_ORDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z == op2", 1, 1, 1},
	{737, ML_CODE_ORDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1z > op2", 1, 1, 1},
	{738, ML_CODE_ORDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1z < op2", 1, 1, 1},
	{739, ML_CODE_ORDLE, setCodeOp2_Idx_WZW, setInputIdx_WZW_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1z ==op2", 1, 1, 1},
	{740, ML_CODE_ORDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z > nop2", 1, 1, 0},
	{741, ML_CODE_ORDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z > nop2", 1, 1, 0},
	{742, ML_CODE_ORDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z < nop2", 1, 1, 1},
	{743, ML_CODE_ORDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z < nop2", 1, 1, 1},
	{744, ML_CODE_ORDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z == nop2", 1, 1, 1},
	{745, ML_CODE_ORDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1z > nop2", 1, 1, 1},
	{746, ML_CODE_ORDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1z < nop2", 1, 1, 1},
	{747, ML_CODE_ORDLE, setCodeOp2_Idx_WZN2, setInputIdx_WZN_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1z == nop2", 1, 1, 1},
	{748, ML_CODE_ORDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z > K", 1, 1, 0},
	{749, ML_CODE_ORDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z == K", 1, 1, 0},
	{750, ML_CODE_ORDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z < K", 1, 1, 1},
	{751, ML_CODE_ORDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z == K", 1, 1, 1},
	{752, ML_CODE_ORDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1z < K", 1, 1, 1},
	{753, ML_CODE_ORDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1z > K", 1, 1, 1},
	{754, ML_CODE_ORDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1z == K", 1, 1, 1},
	{755, ML_CODE_ORDLE, setCodeOp2_Idx_WZK2, setInputIdx_WZK_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT on op1z < K", 1, 1, 1},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};


int total_basic_comp_dword_index_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_comp_dword_index_test_number; i++)
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

// op1 : bit nibble register
// op2 : word + index register
// out : bit register
int setCodeOp_Idx_N2WZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_B || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;
	if(in1 == out && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandNibble(8, in1, in1_pos); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : K constant
// op2 : word + index register
// out : bit register
int setCodeOp_Idx_K2WZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_X || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : bit nibble register
// op2 : word + index register
// out : bit register
int setCodeOp_Idx_WZN2
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_B ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;
	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperandNibble(8, in2, in2_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : K constant
// op2 : word + index register
// out : bit register
int setCodeOp_Idx_WZK2
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_X ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_DK, 16843009);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


// op1 : bit nibble register
// op2 : word + index register
// out : bit register
int setCodeOp2_Idx_N2WZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_B || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;
	if(in1 == out && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in1, in1_pos); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : K constant
// op2 : word + index register
// out : bit register
int setCodeOp2_Idx_K2WZ
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 > OPERAND_ML_CODE_X || in2 < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in2, in2_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, 16843009); addMLOperandZIndex(in2, in2_pos, idx_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word + index register
// op2 : bit nibble register
// out : bit register
int setCodeOp2_Idx_WZN2
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_B ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;
	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperandNibble(8, in2, in2_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

// op1 : word + index register
// op2 : K constant
// out : bit register
int setCodeOp2_Idx_WZK2
(uint16 ml_cmd, uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in1 < OPERAND_ML_CODE_D || in2 > OPERAND_ML_CODE_X ) return 0;
	if(isRangeOver(in1, in1_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in1, in1_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_DK, 16843009);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputIdx_WWZ_hbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843009);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_lbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843009);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_hlessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16777473);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_llessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843008);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_sameVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843009);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_hbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; //0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_lbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_hlessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16777473; // 0x100 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_llessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843008; // 0x101 0100

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_sameVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_hbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16908545);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_lbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843010);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_hlessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_llessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_sameVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_hbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_lbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_hlessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16777473);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_llessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843008);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_sameVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_hbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16777473; // 0x100 0101

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_lbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843008; // 0x101 0100

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_hlessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16777473);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_llessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843008);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_sameVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_hbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16908545);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_lbigVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843010);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_hlessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_llessVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_sameVal32
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}


void setInputIdx_WWZ_hbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843009);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_lbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843009);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_hlessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16777473);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_llessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843008);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_sameVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843009);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}


void setInputIdx_WWZ_hbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843009);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_lbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843009);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_hlessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16777473);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_llessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843008);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WWZ_sameVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, 16843009);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_hbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_lbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_hlessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16777473; // 0x100 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_llessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_sameVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_hbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_lbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_hlessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16777473; // 0x100 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_llessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_NWZ_sameVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, ((value>>i)&0x01));
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_hbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16908545);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_lbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843010);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_hlessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_llessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_sameVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_hbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16908545);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_lbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843010);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_hlessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_llessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_KWZ_sameVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_hbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_lbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_hlessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16777473);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_llessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843008);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_sameVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_hbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_lbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_hlessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16777473);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_llessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843008);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZW_sameVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_hbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16777473; // 0x100 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_lbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_hlessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16777473);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_llessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843008);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_sameVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}


void setInputIdx_WZN_hbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16777473; //  0x100 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_lbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843008; // 0x101 0100

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_hlessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16777473);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_llessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843008);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZN_sameVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;
	int i;
	uint32 value=16843009; // 0x101 0101

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, ((value>>i)&0x01));
	}
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_hbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16908545);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_lbigVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843010);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_hlessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_llessVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_sameVal32_off
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_hbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16908545);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_lbigVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843010);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_hlessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16777473);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_llessVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843008);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

void setInputIdx_WZK_sameVal32_on
(uint8 in1, uint16 in1_pos,
 uint8 in2, uint16 in2_pos,
 uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos+z_val, 16843009);
	//DBG_LOGPRINT("index[%d] z_val=%d %d\n", idx_pos, z_val, idx_val);

	TestCodeTearDown();
}

/*
static int isIndexRangeOver(int type, uint16 in1_reg, uint16 in1_pos, uint16 in2_reg, uint16 in2_pos, short idx_val)
{
	// X,Y,R,L,F,B,SM,D,W
	uint16 lastIndex[] = {8190,8190,8190,8190,2046,8190,0,12286,8190};

	if(type == 0 ) // op2 is index
	{
		if( in2_reg < OPERAND_ML_CODE_D) return 1;

		if( in2_pos+idx_val > lastIndex[in2_reg] || in2_pos+idx_val < 0 )
			return 1;
	}
	else if(type == 1) // op1 is index
	{
		if( in1_reg < OPERAND_ML_CODE_D) return 1;

		if( in1_pos+idx_val > lastIndex[in1_reg] || in1_pos+idx_val < 0 )
			return 1;
	}
	return 0;
}
*/
static uint16 getInPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; // 32 bit

	return pos[inx_pos][reg];
}

static uint16 getOutPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096},
			{8191,8191,8191,8191,2047,8191}};

	return pos[inx_pos][reg];
}

static 	FILE *flog;
void test_basic_compare_dword_index(int tno, uint16 dummy)
{
	int rc=0, vc=0, ml_rc=1, i=0, j=1, inx=0, olast=0;
	short zVal;
	int Dreg_val1, Dreg_val2;
	//long long Dreg_nval1, Dreg_nval2;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_B;
	uint16 in1_pos=0, in2_pos=0, out_pos=0;
	//uint16 idx_pos[]={0,7,15};
	//uint32 in1_val=257, in2_val=257, out_val=0;
	//short expected=1;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
	//for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		//if(out==OPERAND_ML_CODE_F) continue;

		out_pos = getOutPos(out, olast);
		for(in1=OPERAND_ML_CODE_X; in1<=OPERAND_ML_CODE_W; in1++)
		{
			for(i=0; i<3; i++) // index pos of in1
			{
				in1_pos = getInPos(in1, i);
				for(in2=OPERAND_ML_CODE_X; in2<=OPERAND_ML_CODE_W; in2++)
				{
					for(j=0; j<3; j++) //index pos of in2
					{
						in2_pos = getInPos(in2, j);
						for(inx=0; inx<15; inx++) // testidx
						{
							PLC_DEVICE_Init();

							ml_rc = testCase[tno].setTestCode_fn(testCase[tno].ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, \
									testidx[inx].pos, testidx[inx].val);
							if(ml_rc==0)
							{
								//DBG_LOGPRINT(" SKIP test invalid operand op1=%s[%d] op2=%s[%d]\n", reg[in1], in1_pos, reg[in2], in2_pos);
								continue;
							}

							//DBG_LOGPRINT("test proceed ! %s[%d] = %s[%d] %s[%d] Z[%d]=%d\n", \
								reg[out], out_pos, reg[in1], in1_pos, reg[in2], in2_pos, testidx[inx].pos, testidx[inx].val);

							testCase[tno].setTestInput_fn(in1,in1_pos,in2,in2_pos, testidx[inx].pos,testidx[inx].val);

							test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
							rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								if(testCase[tno].z_type == 0)
								{
									if(in1 > OPERAND_ML_CODE_B)
										test_getDWord(&Dreg_val1, in1, in1_pos);
									else
										test_getNibble(&Dreg_val1, in1, in1_pos, 8);
									test_getDWord(&Dreg_val2, in2, in2_pos+zVal);
									fprintf(flog, "test_no[%d] run time error Z[%d]=%d, %s[%d]=%d %s[%d+%d]=%d\n",
										tno, testidx[inx].pos, zVal, reg[in1], in1_pos, Dreg_val1, reg[in2], in2_pos, zVal, Dreg_val2);
								}
								else if(testCase[tno].z_type == 1)
								{

									test_getWord(&Dreg_val1, in1, in1_pos+zVal);
									if(in1 > OPERAND_ML_CODE_B)
										test_getDWord(&Dreg_val2, in2, in2_pos);
									else
										test_getNibble(&Dreg_val2, in2, in2_pos, 8);
									fprintf(flog, "test_no[%d] run time error Z[%d]=%d, %s[%d+%d]=%d %s[%d]=%d\n",
										tno, testidx[inx].pos, zVal, reg[in1], in1_pos, zVal, Dreg_val1, reg[in2], in2_pos, Dreg_val2);
								}
							}
							else
							{
								vc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
								if( vc == 1)
								{
									if(testCase[tno].z_type == 0)
									{
										if(in1 > OPERAND_ML_CODE_B)
											test_getDWord(&Dreg_val1, in1, in1_pos);
										else
											test_getNibble(&Dreg_val1, in1, in1_pos, 8);
										test_getWord(&Dreg_val2, in2, in2_pos+zVal);
										fprintf(flog, "test_no[%d] error index Z[%d]=%d, %s[%d]=%d %s[%d+%d]=%d\n",
											tno, testidx[inx].pos, zVal, reg[in1], in1_pos, Dreg_val1, reg[in2], in2_pos, zVal, Dreg_val2);
									}
									else if(testCase[tno].z_type == 1)
									{
										test_getDWord(&Dreg_val1, in1, in1_pos+zVal);
										if(in1 > OPERAND_ML_CODE_B)
											test_getDWord(&Dreg_val2, in2, in2_pos);
										else
											test_getNibble(&Dreg_val2, in2, in2_pos, 8);
										fprintf(flog, "test_no[%d] error index Z[%d]=%d, %s[%d+%d]=%d %s[%d]=%d\n",
											tno, testidx[inx].pos, zVal, reg[in1], in1_pos, zVal, Dreg_val1, reg[in2], in2_pos, Dreg_val2);
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

}

void testBasicCompareDwordIndexCommand(void)
{
	int i, index=1;
	int start, end;
	char log[] = "err_comp_dword_index.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare dword index LOG file open error !\n");
		exit(1);
	}

#if 0
	test_basic_compare_dword_index(index, 0);

#else
	total_basic_comp_dword_index_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LDDEQ); //ML_CODE_LDDEQ
	end = getTestCaseNumberEnd(ML_CODE_ANDDEQ); //ML_CODE_ORDLE

	DBG_LOGPRINT("testBasicCompareDWordIndexCommand: %d to %d total %d\n", start, end, total_basic_comp_dword_index_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_compare_dword_index(index, 0);
	}
#endif
	fclose(flog);
}

#endif
