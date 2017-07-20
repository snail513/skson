/*
 * test_basic_compare_str.c
 *
 *  Created on: Apr 15, 2015
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

extern void setCodeAND_OR(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int verifyResultNormal(int tcase, uint8 dest_reg, uint16 pos, uint8 expected);

void setCodeLDx_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDx_Str_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDx_lStr_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDx_shStr_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDx_big2Str_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDx_same2Str_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDx_less2Str_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeAND_OR_Str(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeAND_OR_big2Str(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeAND_OR_same2Str(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeAND_OR_less2Str(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputDIn_bigStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_sameStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_lessStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_bigStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sameStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_lessStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_off_bigValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_sameValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_lessValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_bigValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_sameValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_lessValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);


void setInputSIn_off_bigStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_sameStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_lessStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_bigStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_sameStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_lessStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputNIn_off_Str(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputNIn_on_Str(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

typedef struct
{
	int 	no;
	uint16 ml_code;
	void (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, uint8);
	char str[50];
	int run_step;
	int expected;
} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_LDSTREQ, setCodeLDx_OUT, setInputDIn_bigStr, verifyResultNormal,
			"LDSTREQ_OUT op1 > op2", 1, 0},
	{1, ML_CODE_LDSTREQ, setCodeLDx_OUT, setInputDIn_sameStr, verifyResultNormal,
			"LDSTREQ_OUT op1 == op2", 1, 1},
	{2, ML_CODE_LDSTREQ, setCodeLDx_OUT, setInputDIn_lessStr, verifyResultNormal,
			"LDSTREQ_OUT op1 < op2", 1, 0},
	{3, ML_CODE_LDSTREQ, setCodeLDx_OUT, setInputDIn_longStr, verifyResultNormal,
			"LDSTREQ_OUT op1 longer than op2", 1, 0},
	{4, ML_CODE_LDSTREQ, setCodeLDx_OUT, setInputDIn_shortStr, verifyResultNormal,
			"LDSTREQ_OUT op1 shorter than op2", 1, 0},
	{5, ML_CODE_LDSTREQ, setCodeLDx_Str_OUT, setInputSIn_bigStr, verifyResultNormal,
			"LDSTREQ_OUT op1 > op2", 1, 0},
	{6, ML_CODE_LDSTREQ, setCodeLDx_Str_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTREQ_OUT op1 == op2", 1, 1},
	{7, ML_CODE_LDSTREQ, setCodeLDx_Str_OUT, setInputSIn_lessStr, verifyResultNormal,
			"LDSTREQ_OUT op1 < op2", 1, 0},
	{8, ML_CODE_LDSTREQ, setCodeLDx_shStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTREQ_OUT op1 longer than $", 1, 0},
	{9, ML_CODE_LDSTREQ, setCodeLDx_lStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTREQ_OUT op1 shorter than $", 1, 0},
	{10, ML_CODE_LDSTREQ, setCodeLDx_big2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTREQ_OUT $1 > $2", 1, 0},
	{11, ML_CODE_LDSTREQ, setCodeLDx_same2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTREQ_OUT $1 == $2", 1, 1},
	{12, ML_CODE_LDSTREQ, setCodeLDx_less2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTREQ_OUT $1 < $2", 1, 0},

	{13, ML_CODE_LDSTRNE, setCodeLDx_OUT, setInputDIn_bigStr, verifyResultNormal,
			"LDSTRNE_OUT op1 > op2", 1, 1},
	{14, ML_CODE_LDSTRNE, setCodeLDx_OUT, setInputDIn_sameStr, verifyResultNormal,
			"LDSTRNE_OUT op1 == op2", 1, 0},
	{15, ML_CODE_LDSTRNE, setCodeLDx_OUT, setInputDIn_lessStr, verifyResultNormal,
			"LDSTRNE_OUT op1 < op2", 1, 1},
	{16, ML_CODE_LDSTRNE, setCodeLDx_OUT, setInputDIn_longStr, verifyResultNormal,
			"LDSTRNE_OUT op1 longer than op2", 1, 1},
	{17, ML_CODE_LDSTRNE, setCodeLDx_OUT, setInputDIn_shortStr, verifyResultNormal,
			"LDSTRNE_OUT op1 shorter than op2", 1, 1},
	{18, ML_CODE_LDSTRNE, setCodeLDx_Str_OUT, setInputSIn_bigStr, verifyResultNormal,
			"LDSTRNE_OUT op1 > op2", 1, 1},
	{19, ML_CODE_LDSTRNE, setCodeLDx_Str_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRNE_OUT op1 == op2", 1, 0},
	{20, ML_CODE_LDSTRNE, setCodeLDx_Str_OUT, setInputSIn_lessStr, verifyResultNormal,
			"LDSTRNE_OUT op1 < op2", 1, 1},
	{21, ML_CODE_LDSTRNE, setCodeLDx_shStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRNE_OUT op1 longer than $", 1, 1},
	{22, ML_CODE_LDSTRNE, setCodeLDx_lStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRNE_OUT op1 shorter than $", 1, 1},
	{23, ML_CODE_LDSTRNE, setCodeLDx_big2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRNE_OUT $1 > $2", 1, 1},
	{24, ML_CODE_LDSTRNE, setCodeLDx_same2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRNE_OUT $1 == $2", 1, 0},
	{25, ML_CODE_LDSTRNE, setCodeLDx_less2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRNE_OUT $1 < $2", 1, 1},

	{26, ML_CODE_LDSTRGT, setCodeLDx_OUT, setInputDIn_bigStr, verifyResultNormal,
			"LDSTRGT_OUT op1 > op2", 1, 1},
	{27, ML_CODE_LDSTRGT, setCodeLDx_OUT, setInputDIn_sameStr, verifyResultNormal,
			"LDSTRGT_OUT op1 == op2", 1, 0},
	{28, ML_CODE_LDSTRGT, setCodeLDx_OUT, setInputDIn_lessStr, verifyResultNormal,
			"LDSTRGT_OUT op1 < op2", 1, 0},
	{29, ML_CODE_LDSTRGT, setCodeLDx_OUT, setInputDIn_longStr, verifyResultNormal,
			"LDSTRGT_OUT op1 longer than op2", 1, 1},
	{30, ML_CODE_LDSTRGT, setCodeLDx_OUT, setInputDIn_shortStr, verifyResultNormal,
			"LDSTRGT_OUT op1 shorter than op2", 1, 0},
	{31, ML_CODE_LDSTRGT, setCodeLDx_Str_OUT, setInputSIn_bigStr, verifyResultNormal,
			"LDSTRGT_OUT op1 > op2", 1, 1},
	{32, ML_CODE_LDSTRGT, setCodeLDx_Str_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRGT_OUT op1 == op2", 1, 0},
	{33, ML_CODE_LDSTRGT, setCodeLDx_Str_OUT, setInputSIn_lessStr, verifyResultNormal,
			"LDSTRGT_OUT op1 < op2", 1, 0},
	{34, ML_CODE_LDSTRGT, setCodeLDx_shStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRGT_OUT op1 longer than $", 1, 1},
	{35, ML_CODE_LDSTRGT, setCodeLDx_lStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRGT_OUT op1 shorter than $", 1, 0},
	{36, ML_CODE_LDSTRGT, setCodeLDx_big2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRGT_OUT $1 > $2", 1, 1},
	{37, ML_CODE_LDSTRGT, setCodeLDx_same2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRGT_OUT $1 == $2", 1, 0},
	{38, ML_CODE_LDSTRGT, setCodeLDx_less2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRGT_OUT $1 < $2", 1, 0},

	{39, ML_CODE_LDSTRGE, setCodeLDx_OUT, setInputDIn_bigStr, verifyResultNormal,
			"LDSTRGE_OUT op1 > op2", 1, 1},
	{40, ML_CODE_LDSTRGE, setCodeLDx_OUT, setInputDIn_sameStr, verifyResultNormal,
			"LDSTRGE_OUT op1 == op2", 1, 1},
	{41, ML_CODE_LDSTRGE, setCodeLDx_OUT, setInputDIn_lessStr, verifyResultNormal,
			"LDSTRGE_OUT op1 < op2", 1, 0},
	{42, ML_CODE_LDSTRGE, setCodeLDx_OUT, setInputDIn_longStr, verifyResultNormal,
			"LDSTRGE_OUT op1 longer than op2", 1, 1},
	{43, ML_CODE_LDSTRGE, setCodeLDx_OUT, setInputDIn_shortStr, verifyResultNormal,
			"LDSTRGE_OUT op1 shorter than op2", 1, 0},
	{44, ML_CODE_LDSTRGE, setCodeLDx_Str_OUT, setInputSIn_bigStr, verifyResultNormal,
			"LDSTRGE_OUT op1 > op2", 1, 1},
	{45, ML_CODE_LDSTRGE, setCodeLDx_Str_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRGE_OUT op1 == op2", 1, 1},
	{46, ML_CODE_LDSTRGE, setCodeLDx_Str_OUT, setInputSIn_lessStr, verifyResultNormal,
			"LDSTRGE_OUT op1 < op2", 1, 0},
	{47, ML_CODE_LDSTRGE, setCodeLDx_shStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRGE_OUT op1 longer than $", 1, 1},
	{48, ML_CODE_LDSTRGE, setCodeLDx_lStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRGE_OUT op1 shorter than $", 1, 0},
	{49, ML_CODE_LDSTRGE, setCodeLDx_big2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRGE_OUT $1 > $2", 1, 1},
	{50, ML_CODE_LDSTRGE, setCodeLDx_same2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRGE_OUT $1 == $2", 1, 1},
	{51, ML_CODE_LDSTRGE, setCodeLDx_less2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRGE_OUT $1 < $2", 1, 0},

	{52, ML_CODE_LDSTRLT, setCodeLDx_OUT, setInputDIn_bigStr, verifyResultNormal,
			"LDSTRLT_OUT op1 > op2", 1, 0},
	{53, ML_CODE_LDSTRLT, setCodeLDx_OUT, setInputDIn_sameStr, verifyResultNormal,
			"LDSTRLT_OUT op1 == op2", 1, 0},
	{54, ML_CODE_LDSTRLT, setCodeLDx_OUT, setInputDIn_lessStr, verifyResultNormal,
			"LDSTRLT_OUT op1 < op2", 1, 1},
	{55, ML_CODE_LDSTRLT, setCodeLDx_OUT, setInputDIn_longStr, verifyResultNormal,
			"LDSTRLT_OUT op1 longer than op2", 1, 0},
	{56, ML_CODE_LDSTRLT, setCodeLDx_OUT, setInputDIn_shortStr, verifyResultNormal,
			"LDSTRLT_OUT op1 shorter than op2", 1, 1},
	{57, ML_CODE_LDSTRLT, setCodeLDx_Str_OUT, setInputSIn_bigStr, verifyResultNormal,
			"LDSTRLT_OUT op1 > op2", 1, 0},
	{58, ML_CODE_LDSTRLT, setCodeLDx_Str_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRLT_OUT op1 == op2", 1, 0},
	{59, ML_CODE_LDSTRLT, setCodeLDx_Str_OUT, setInputSIn_lessStr, verifyResultNormal,
			"LDSTRLT_OUT op1 < op2", 1, 1},
	{60, ML_CODE_LDSTRLT, setCodeLDx_shStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRLT_OUT op1 longer than $", 1, 0},
	{61, ML_CODE_LDSTRLT, setCodeLDx_lStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRLT_OUT op1 shorter than $", 1, 1},
	{62, ML_CODE_LDSTRLT, setCodeLDx_big2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRLT_OUT $1 > $2", 1, 0},
	{63, ML_CODE_LDSTRLT, setCodeLDx_same2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRLT_OUT $1 == $2", 1, 0},
	{64, ML_CODE_LDSTRLT, setCodeLDx_less2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRLT_OUT $1 < $2", 1, 1},

	{65, ML_CODE_LDSTRLE, setCodeLDx_OUT, setInputDIn_bigStr, verifyResultNormal,
			"LDSTRLE_OUT op1 > op2", 1, 0},
	{66, ML_CODE_LDSTRLE, setCodeLDx_OUT, setInputDIn_sameStr, verifyResultNormal,
			"LDSTRLE_OUT op1 == op2", 1, 1},
	{67, ML_CODE_LDSTRLE, setCodeLDx_OUT, setInputDIn_lessStr, verifyResultNormal,
			"LDSTRLE_OUT op1 < op2", 1, 1},
	{68, ML_CODE_LDSTRLE, setCodeLDx_OUT, setInputDIn_longStr, verifyResultNormal,
			"LDSTRLE_OUT op1 longer than op2", 1, 0},
	{69, ML_CODE_LDSTRLE, setCodeLDx_OUT, setInputDIn_shortStr, verifyResultNormal,
			"LDSTRLE_OUT op1 shorter than op2", 1, 1},
	{70, ML_CODE_LDSTRLE, setCodeLDx_Str_OUT, setInputSIn_bigStr, verifyResultNormal,
			"LDSTRLE_OUT op1 > op2", 1, 0},
	{71, ML_CODE_LDSTRLE, setCodeLDx_Str_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRLE_OUT op1 == op2", 1, 1},
	{72, ML_CODE_LDSTRLE, setCodeLDx_Str_OUT, setInputSIn_lessStr, verifyResultNormal,
			"LDSTRLE_OUT op1 < op2", 1, 1},
	{73, ML_CODE_LDSTRLE, setCodeLDx_shStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRLE_OUT op1 longer than $", 1, 0},
	{74, ML_CODE_LDSTRLE, setCodeLDx_lStr_OUT, setInputSIn_sameStr, verifyResultNormal,
			"LDSTRLE_OUT op1 shorter than $", 1, 1},
	{75, ML_CODE_LDSTRLE, setCodeLDx_big2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRLE_OUT $1 > $2", 1, 0},
	{76, ML_CODE_LDSTRLE, setCodeLDx_same2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRLE_OUT $1 == $2", 1, 1},
	{77, ML_CODE_LDSTRLE, setCodeLDx_less2Str_OUT, setInputNIn_on_Str, verifyResultNormal,
			"LDSTRLE_OUT $1 < $2", 1, 1},

	{78, ML_CODE_ANDSTREQ, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ANDSTREQ_OUT off op1 > op2", 1, 0},
	{79, ML_CODE_ANDSTREQ, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ANDSTREQ_OUT off op1 == op2", 1, 0},
	{80, ML_CODE_ANDSTREQ, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ANDSTREQ_OUT off op1 < op2", 1, 0},
	{81, ML_CODE_ANDSTREQ, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ANDSTREQ_OUT on op1 > op2", 1, 0},
	{82, ML_CODE_ANDSTREQ, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ANDSTREQ_OUT on op1 == op2", 1, 1},
	{83, ML_CODE_ANDSTREQ, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ANDSTREQ_OUT on op1 < op2", 1, 0},
	{84, ML_CODE_ANDSTREQ, setCodeAND_OR, setInputDIn_on_longStr, verifyResultNormal,
			"ANDSTREQ_OUT op1 shorter than op2", 1, 0},
	{85, ML_CODE_ANDSTREQ, setCodeAND_OR, setInputDIn_on_shortStr, verifyResultNormal,
			"ANDSTREQ_OUT op1 longer than op2", 1, 0},
	{86, ML_CODE_ANDSTREQ, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ANDSTREQ_OUT off op1 > $", 1, 0},
	{87, ML_CODE_ANDSTREQ, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ANDSTREQ_OUT off op1 == $", 1, 0},
	{88, ML_CODE_ANDSTREQ, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ANDSTREQ_OUT off op1 < $", 1, 0},
	{89, ML_CODE_ANDSTREQ, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ANDSTREQ_OUT on op1 > $", 1, 0},
	{90, ML_CODE_ANDSTREQ, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ANDSTREQ_OUT on op1 == $", 1, 1},
	{91, ML_CODE_ANDSTREQ, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ANDSTREQ_OUT on op1 < $", 1, 0},
	{92, ML_CODE_ANDSTREQ, setCodeAND_OR_Str, setInputSIn_on_longStr, verifyResultNormal,
			"ANDSTREQ_OUT on op1 longer than $", 1, 0},
	{93, ML_CODE_ANDSTREQ, setCodeAND_OR_Str, setInputSIn_on_shortStr, verifyResultNormal,
			"ANDSTREQ_OUT on op1 shorter than $", 1, 0},
	{94, ML_CODE_ANDSTREQ, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTREQ_OUT off op1 > $", 1, 0},
	{95, ML_CODE_ANDSTREQ, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTREQ_OUT on op1 > $", 1, 0},
	{96, ML_CODE_ANDSTREQ, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTREQ_OUT off op1 == $", 1, 0},
	{97, ML_CODE_ANDSTREQ, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTREQ_OUT on op1 == $", 1, 1},
	{98, ML_CODE_ANDSTREQ, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTREQ_OUT off op1 < $", 1, 0},
	{99, ML_CODE_ANDSTREQ, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTREQ_OUT on op1 < $", 1, 0},

	{100, ML_CODE_ANDSTRNE, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ANDSTRNE_OUT off op1 > op2", 1, 0},
	{101, ML_CODE_ANDSTRNE, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ANDSTRNE_OUT off op1 == op2", 1, 0},
	{102, ML_CODE_ANDSTRNE, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ANDSTRNE_OUT off op1 < op2", 1, 0},
	{103, ML_CODE_ANDSTRNE, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ANDSTRNE_OUT on op1 > op2", 1, 1},
	{104, ML_CODE_ANDSTRNE, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ANDSTRNE_OUT on op1 == op2", 1, 0},
	{105, ML_CODE_ANDSTRNE, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ANDSTRNE_OUT on op1 < op2", 1, 1},
	{106, ML_CODE_ANDSTRNE, setCodeAND_OR, setInputDIn_on_longStr, verifyResultNormal,
			"ANDSTRNE_OUT op1 shorter than op2", 1, 1},
	{107, ML_CODE_ANDSTRNE, setCodeAND_OR, setInputDIn_on_shortStr, verifyResultNormal,
			"ANDSTRNE_OUT op1 longer than op2", 1, 1},
	{108, ML_CODE_ANDSTRNE, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ANDSTRNE_OUT off op1 > $", 1, 0},
	{109, ML_CODE_ANDSTRNE, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ANDSTRNE_OUT off op1 == $", 1, 0},
	{110, ML_CODE_ANDSTRNE, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ANDSTRNE_OUT off op1 < $", 1, 0},
	{111, ML_CODE_ANDSTRNE, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ANDSTRNE_OUT on op1 > $", 1, 1},
	{112, ML_CODE_ANDSTRNE, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ANDSTRNE_OUT on op1 == $", 1, 0},
	{113, ML_CODE_ANDSTRNE, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ANDSTRNE_OUT on op1 < $", 1, 1},
	{114, ML_CODE_ANDSTRNE, setCodeAND_OR_Str, setInputSIn_on_longStr, verifyResultNormal,
			"ANDSTRNE_OUT on op1 longer than $", 1, 1},
	{115, ML_CODE_ANDSTRNE, setCodeAND_OR_Str, setInputSIn_on_shortStr, verifyResultNormal,
			"ANDSTRNE_OUT on op1 shorter than $", 1, 1},
	{116, ML_CODE_ANDSTRNE, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRNE_OUT off op1 > $", 1, 0},
	{117, ML_CODE_ANDSTRNE, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRNE_OUT on op1 > $", 1, 1},
	{118, ML_CODE_ANDSTRNE, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRNE_OUT off op1 == $", 1, 0},
	{119, ML_CODE_ANDSTRNE, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRNE_OUT on op1 == $", 1, 0},
	{120, ML_CODE_ANDSTRNE, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRNE_OUT off op1 < $", 1, 0},
	{121, ML_CODE_ANDSTRNE, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRNE_OUT on op1 < $", 1, 1},

	{122, ML_CODE_ANDSTRGT, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ANDSTRGT_OUT off op1 > op2", 1, 0},
	{123, ML_CODE_ANDSTRGT, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ANDSTRGT_OUT off op1 == op2", 1, 0},
	{124, ML_CODE_ANDSTRGT, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ANDSTRGT_OUT off op1 < op2", 1, 0},
	{125, ML_CODE_ANDSTRGT, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ANDSTRGT_OUT on op1 > op2", 1, 1},
	{126, ML_CODE_ANDSTRGT, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ANDSTRGT_OUT on op1 == op2", 1, 0},
	{127, ML_CODE_ANDSTRGT, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ANDSTRGT_OUT on op1 < op2", 1, 0},
	{128, ML_CODE_ANDSTRGT, setCodeAND_OR, setInputDIn_on_longStr, verifyResultNormal,
			"ANDSTRGT_OUT op1 shorter than op2", 1, 1},
	{129, ML_CODE_ANDSTRGT, setCodeAND_OR, setInputDIn_on_shortStr, verifyResultNormal,
			"ANDSTRGT_OUT op1 longer than op2", 1, 0},
	{130, ML_CODE_ANDSTRGT, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ANDSTRGT_OUT off op1 > $", 1, 0},
	{131, ML_CODE_ANDSTRGT, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ANDSTRGT_OUT off op1 == $", 1, 0},
	{132, ML_CODE_ANDSTRGT, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ANDSTRGT_OUT off op1 < $", 1, 0},
	{133, ML_CODE_ANDSTRGT, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ANDSTRGT_OUT on op1 > $", 1, 1},
	{134, ML_CODE_ANDSTRGT, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ANDSTRGT_OUT on op1 == $", 1, 0},
	{135, ML_CODE_ANDSTRGT, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ANDSTRGT_OUT on op1 < $", 1, 0},
	{136, ML_CODE_ANDSTRGT, setCodeAND_OR_Str, setInputSIn_on_longStr, verifyResultNormal,
			"ANDSTRGT_OUT on op1 longer than $", 1, 1},
	{137, ML_CODE_ANDSTRGT, setCodeAND_OR_Str, setInputSIn_on_shortStr, verifyResultNormal,
			"ANDSTRGT_OUT on op1 shorter than $", 1, 0},
	{138, ML_CODE_ANDSTRGT, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRGT_OUT off op1 > $", 1, 0},
	{139, ML_CODE_ANDSTRGT, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRGT_OUT on op1 > $", 1, 1},
	{140, ML_CODE_ANDSTRGT, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRGT_OUT off op1 == $", 1, 0},
	{141, ML_CODE_ANDSTRGT, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRGT_OUT on op1 == $", 1, 0},
	{142, ML_CODE_ANDSTRGT, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRGT_OUT off op1 < $", 1, 0},
	{143, ML_CODE_ANDSTRGT, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRGT_OUT on op1 < $", 1, 0},

	{144, ML_CODE_ANDSTRGE, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ANDSTRGE_OUT off op1 > op2", 1, 0},
	{145, ML_CODE_ANDSTRGE, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ANDSTRGE_OUT off op1 == op2", 1, 0},
	{146, ML_CODE_ANDSTRGE, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ANDSTRGE_OUT off op1 < op2", 1, 0},
	{147, ML_CODE_ANDSTRGE, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ANDSTRGE_OUT on op1 > op2", 1, 1},
	{148, ML_CODE_ANDSTRGE, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ANDSTRGE_OUT on op1 == op2", 1, 1},
	{149, ML_CODE_ANDSTRGE, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ANDSTRGE_OUT on op1 < op2", 1, 0},
	{150, ML_CODE_ANDSTRGE, setCodeAND_OR, setInputDIn_on_longStr, verifyResultNormal,
			"ANDSTRGE_OUT op1 shorter than op2", 1, 1},
	{151, ML_CODE_ANDSTRGE, setCodeAND_OR, setInputDIn_on_shortStr, verifyResultNormal,
			"ANDSTRGE_OUT op1 longer than op2", 1, 0},
	{152, ML_CODE_ANDSTRGE, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ANDSTRGE_OUT off op1 > $", 1, 0},
	{153, ML_CODE_ANDSTRGE, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ANDSTRGE_OUT off op1 == $", 1, 0},
	{154, ML_CODE_ANDSTRGE, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ANDSTRGE_OUT off op1 < $", 1, 0},
	{155, ML_CODE_ANDSTRGE, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ANDSTRGE_OUT on op1 > $", 1, 1},
	{156, ML_CODE_ANDSTRGE, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ANDSTRGE_OUT on op1 == $", 1, 1},
	{157, ML_CODE_ANDSTRGE, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ANDSTRGE_OUT on op1 < $", 1, 0},
	{158, ML_CODE_ANDSTRGE, setCodeAND_OR_Str, setInputSIn_on_longStr, verifyResultNormal,
			"ANDSTRGE_OUT on op1 longer than $", 1, 1},
	{159, ML_CODE_ANDSTRGE, setCodeAND_OR_Str, setInputSIn_on_shortStr, verifyResultNormal,
			"ANDSTRGE_OUT on op1 shorter than $", 1, 0},
	{160, ML_CODE_ANDSTRGE, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRGE_OUT off op1 > $", 1, 0},
	{161, ML_CODE_ANDSTRGE, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRGE_OUT on op1 > $", 1, 1},
	{162, ML_CODE_ANDSTRGE, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRGE_OUT off op1 == $", 1, 0},
	{163, ML_CODE_ANDSTRGE, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRGE_OUT on op1 == $", 1, 1},
	{164, ML_CODE_ANDSTRGE, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRGE_OUT off op1 < $", 1, 0},
	{165, ML_CODE_ANDSTRGE, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRGE_OUT on op1 < $", 1, 0},

	{166, ML_CODE_ANDSTRLT, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ANDSTRLT_OUT off op1 > op2", 1, 0},
	{167, ML_CODE_ANDSTRLT, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ANDSTRLT_OUT off op1 == op2", 1, 0},
	{168, ML_CODE_ANDSTRLT, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ANDSTRLT_OUT off op1 < op2", 1, 0},
	{169, ML_CODE_ANDSTRLT, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ANDSTRLT_OUT on op1 > op2", 1, 0},
	{170, ML_CODE_ANDSTRLT, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ANDSTRLT_OUT on op1 == op2", 1, 0},
	{171, ML_CODE_ANDSTRLT, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ANDSTRLT_OUT on op1 < op2", 1, 1},
	{172, ML_CODE_ANDSTRLT, setCodeAND_OR, setInputDIn_on_longStr, verifyResultNormal,
			"ANDSTRLT_OUT op1 longer than op2", 1, 0},
	{173, ML_CODE_ANDSTRLT, setCodeAND_OR, setInputDIn_on_shortStr, verifyResultNormal,
			"ANDSTRLT_OUT op1 shorter than op2", 1, 1},
	{174, ML_CODE_ANDSTRLT, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ANDSTRLT_OUT off op1 > $", 1, 0},
	{175, ML_CODE_ANDSTRLT, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ANDSTRLT_OUT off op1 == $", 1, 0},
	{176, ML_CODE_ANDSTRLT, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ANDSTRLT_OUT off op1 < $", 1, 0},
	{177, ML_CODE_ANDSTRLT, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ANDSTRLT_OUT on op1 > $", 1, 0},
	{178, ML_CODE_ANDSTRLT, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ANDSTRLT_OUT on op1 == $", 1, 0},
	{179, ML_CODE_ANDSTRLT, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ANDSTRLT_OUT on op1 < $", 1, 1},
	{180, ML_CODE_ANDSTRLT, setCodeAND_OR_Str, setInputSIn_on_longStr, verifyResultNormal,
			"ANDSTRLT_OUT on op1 longer than $", 1, 0},
	{181, ML_CODE_ANDSTRLT, setCodeAND_OR_Str, setInputSIn_on_shortStr, verifyResultNormal,
			"ANDSTRLT_OUT on op1 shorter than $", 1, 1},
	{182, ML_CODE_ANDSTRLT, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRLT_OUT off op1 > $", 1, 0},
	{183, ML_CODE_ANDSTRLT, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRLT_OUT on op1 > $", 1, 0},
	{184, ML_CODE_ANDSTRLT, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRLT_OUT off op1 == $", 1, 0},
	{185, ML_CODE_ANDSTRLT, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRLT_OUT on op1 == $", 1, 0},
	{186, ML_CODE_ANDSTRLT, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRLT_OUT off op1 < $", 1, 0},
	{187, ML_CODE_ANDSTRLT, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRLT_OUT on op1 < $", 1, 1},

	{188, ML_CODE_ANDSTRLE, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ANDSTRLE_OUT off op1 > op2", 1, 0},
	{189, ML_CODE_ANDSTRLE, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ANDSTRLE_OUT off op1 == op2", 1, 0},
	{190, ML_CODE_ANDSTRLE, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ANDSTRLE_OUT off op1 < op2", 1, 0},
	{191, ML_CODE_ANDSTRLE, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ANDSTRLE_OUT on op1 > op2", 1, 0},
	{192, ML_CODE_ANDSTRLE, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ANDSTRLE_OUT on op1 == op2", 1, 1},
	{193, ML_CODE_ANDSTRLE, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ANDSTRLE_OUT on op1 < op2", 1, 1},
	{194, ML_CODE_ANDSTRLE, setCodeAND_OR, setInputDIn_on_longStr, verifyResultNormal,
			"ANDSTRLE_OUT op1 longer than op2", 1, 0},
	{195, ML_CODE_ANDSTRLE, setCodeAND_OR, setInputDIn_on_shortStr, verifyResultNormal,
			"ANDSTRLE_OUT op1 shorter than op2", 1, 1},
	{196, ML_CODE_ANDSTRLE, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ANDSTRLE_OUT off op1 > $", 1, 0},
	{197, ML_CODE_ANDSTRLE, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ANDSTRLE_OUT off op1 == $", 1, 0},
	{198, ML_CODE_ANDSTRLE, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ANDSTRLE_OUT off op1 < $", 1, 0},
	{199, ML_CODE_ANDSTRLE, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ANDSTRLE_OUT on op1 > $", 1, 0},
	{200, ML_CODE_ANDSTRLE, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ANDSTRLE_OUT on op1 == $", 1, 1},
	{201, ML_CODE_ANDSTRLE, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ANDSTRLE_OUT on op1 < $", 1, 1},
	{202, ML_CODE_ANDSTRLE, setCodeAND_OR_Str, setInputSIn_on_longStr, verifyResultNormal,
			"ANDSTRLE_OUT on op1 longer than $", 1, 0},
	{203, ML_CODE_ANDSTRLE, setCodeAND_OR_Str, setInputSIn_on_shortStr, verifyResultNormal,
			"ANDSTRLE_OUT on op1 shorter than $", 1, 1},
	{204, ML_CODE_ANDSTRLE, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRLE_OUT off op1 > $", 1, 0},
	{205, ML_CODE_ANDSTRLE, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRLE_OUT on op1 > $", 1, 0},
	{206, ML_CODE_ANDSTRLE, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRLE_OUT off op1 == $", 1, 0},
	{207, ML_CODE_ANDSTRLE, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRLE_OUT on op1 == $", 1, 1},
	{208, ML_CODE_ANDSTRLE, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ANDSTRLE_OUT off op1 < $", 1, 0},
	{209, ML_CODE_ANDSTRLE, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ANDSTRLE_OUT on op1 < $", 1, 1},

	{210, ML_CODE_ORSTREQ, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ORSTREQ_OUT off op1 > op2", 1, 0},
	{211, ML_CODE_ORSTREQ, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ORSTREQ_OUT off op1 == op2", 1, 1},
	{212, ML_CODE_ORSTREQ, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ORSTREQ_OUT off op1 < op2", 1, 0},
	{213, ML_CODE_ORSTREQ, setCodeAND_OR, setInputDIn_off_longStr, verifyResultNormal,
			"ORSTREQ_OUT op1 shorter than op2", 1, 0},
	{214, ML_CODE_ORSTREQ, setCodeAND_OR, setInputDIn_off_shortStr, verifyResultNormal,
			"ORSTREQ_OUT op1 longer than op2", 1, 0},
	{215, ML_CODE_ORSTREQ, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ORSTREQ_OUT on op1 > op2", 1, 1},
	{216, ML_CODE_ORSTREQ, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ORSTREQ_OUT on op1 == op2", 1, 1},
	{217, ML_CODE_ORSTREQ, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ORSTREQ_OUT on op1 < op2", 1, 1},
	{218, ML_CODE_ORSTREQ, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ORSTREQ_OUT off op1 > $", 1, 0},
	{219, ML_CODE_ORSTREQ, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ORSTREQ_OUT off op1 == $", 1, 1},
	{220, ML_CODE_ORSTREQ, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ORSTREQ_OUT off op1 < $", 1, 0},
	{221, ML_CODE_ORSTREQ, setCodeAND_OR_Str, setInputSIn_off_shortStr, verifyResultNormal,
			"ORSTREQ_OUT on op1 longer than $", 1, 0},
	{222, ML_CODE_ORSTREQ, setCodeAND_OR_Str, setInputSIn_off_longStr, verifyResultNormal,
			"ORSTREQ_OUT on op1 shorter than $", 1, 0},
	{223, ML_CODE_ORSTREQ, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ORSTREQ_OUT on op1 > $", 1, 1},
	{224, ML_CODE_ORSTREQ, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ORSTREQ_OUT on op1 == $", 1, 1},
	{225, ML_CODE_ORSTREQ, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ORSTREQ_OUT on op1 < $", 1, 1},
	{226, ML_CODE_ORSTREQ, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTREQ_OUT off op1 > $", 1, 0},
	{227, ML_CODE_ORSTREQ, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTREQ_OUT on op1 > $", 1, 1},
	{228, ML_CODE_ORSTREQ, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTREQ_OUT off op1 == $", 1, 1},
	{229, ML_CODE_ORSTREQ, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTREQ_OUT on op1 == $", 1, 1},
	{230, ML_CODE_ORSTREQ, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTREQ_OUT off op1 < $", 1, 0},
	{231, ML_CODE_ORSTREQ, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTREQ_OUT on op1 < $", 1, 1},

	{232, ML_CODE_ORSTRNE, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ORSTRNE_OUT off op1 > op2", 1, 1},
	{233, ML_CODE_ORSTRNE, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ORSTRNE_OUT off op1 == op2", 1, 0},
	{234, ML_CODE_ORSTRNE, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ORSTRNE_OUT off op1 < op2", 1, 1},
	{235, ML_CODE_ORSTRNE, setCodeAND_OR, setInputDIn_off_longStr, verifyResultNormal,
			"ORSTRNE_OUT op1 shorter than op2", 1, 1},
	{236, ML_CODE_ORSTRNE, setCodeAND_OR, setInputDIn_off_shortStr, verifyResultNormal,
			"ORSTRNE_OUT op1 longer than op2", 1, 1},
	{237, ML_CODE_ORSTRNE, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ORSTRNE_OUT on op1 > op2", 1, 1},
	{238, ML_CODE_ORSTRNE, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ORSTRNE_OUT on op1 == op2", 1, 1},
	{239, ML_CODE_ORSTRNE, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ORSTRNE_OUT on op1 < op2", 1, 1},
	{240, ML_CODE_ORSTRNE, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ORSTRNE_OUT off op1 > $", 1, 1},
	{241, ML_CODE_ORSTRNE, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ORSTRNE_OUT off op1 == $", 1, 0},
	{242, ML_CODE_ORSTRNE, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ORSTRNE_OUT off op1 < $", 1, 1},
	{243, ML_CODE_ORSTRNE, setCodeAND_OR_Str, setInputSIn_off_shortStr, verifyResultNormal,
			"ORSTRNE_OUT on op1 longer than $", 1, 1},
	{244, ML_CODE_ORSTRNE, setCodeAND_OR_Str, setInputSIn_off_longStr, verifyResultNormal,
			"ORSTRNE_OUT on op1 shorter than $", 1, 1},
	{245, ML_CODE_ORSTRNE, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ORSTRNE_OUT on op1 > $", 1, 1},
	{246, ML_CODE_ORSTRNE, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ORSTRNE_OUT on op1 == $", 1, 1},
	{247, ML_CODE_ORSTRNE, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ORSTRNE_OUT on op1 < $", 1, 1},
	{248, ML_CODE_ORSTRNE, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRNE_OUT off op1 > $", 1, 1},
	{249, ML_CODE_ORSTRNE, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRNE_OUT on op1 > $", 1, 1},
	{250, ML_CODE_ORSTRNE, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRNE_OUT off op1 == $", 1, 0},
	{251, ML_CODE_ORSTRNE, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRNE_OUT on op1 == $", 1, 1},
	{252, ML_CODE_ORSTRNE, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRNE_OUT off op1 < $", 1, 1},
	{253, ML_CODE_ORSTRNE, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRNE_OUT on op1 < $", 1, 1},

	{254, ML_CODE_ORSTRGT, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ORSTRGT_OUT off op1 > op2", 1, 1},
	{255, ML_CODE_ORSTRGT, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ORSTRGT_OUT off op1 == op2", 1, 0},
	{256, ML_CODE_ORSTRGT, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ORSTRGT_OUT off op1 < op2", 1, 0},
	{257, ML_CODE_ORSTRGT, setCodeAND_OR, setInputDIn_off_longStr, verifyResultNormal,
			"ORSTRGT_OUT op1 shorter than op2", 1, 1},
	{258, ML_CODE_ORSTRGT, setCodeAND_OR, setInputDIn_off_shortStr, verifyResultNormal,
			"ORSTRGT_OUT op1 longer than op2", 1, 0},
	{259, ML_CODE_ORSTRGT, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ORSTRGT_OUT on op1 > op2", 1, 1},
	{260, ML_CODE_ORSTRGT, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ORSTRGT_OUT on op1 == op2", 1, 1},
	{261, ML_CODE_ORSTRGT, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ORSTRGT_OUT on op1 < op2", 1, 1},
	{262, ML_CODE_ORSTRGT, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ORSTRGT_OUT off op1 > $", 1, 1},
	{263, ML_CODE_ORSTRGT, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ORSTRGT_OUT off op1 == $", 1, 0},
	{264, ML_CODE_ORSTRGT, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ORSTRGT_OUT off op1 < $", 1, 0},
	{265, ML_CODE_ORSTRGT, setCodeAND_OR_Str, setInputSIn_off_shortStr, verifyResultNormal,
			"ORSTRGT_OUT on op1 longer than $", 1, 1},
	{266, ML_CODE_ORSTRGT, setCodeAND_OR_Str, setInputSIn_off_longStr, verifyResultNormal,
			"ORSTRGT_OUT on op1 shorter than $", 1, 0},
	{267, ML_CODE_ORSTRGT, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ORSTRGT_OUT on op1 > $", 1, 1},
	{268, ML_CODE_ORSTRGT, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ORSTRGT_OUT on op1 == $", 1, 1},
	{269, ML_CODE_ORSTRGT, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ORSTRGT_OUT on op1 < $", 1, 1},
	{270, ML_CODE_ORSTRGT, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRGT_OUT off op1 > $", 1, 1},
	{271, ML_CODE_ORSTRGT, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRGT_OUT on op1 > $", 1, 1},
	{272, ML_CODE_ORSTRGT, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRGT_OUT off op1 == $", 1, 0},
	{273, ML_CODE_ORSTRGT, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRGT_OUT on op1 == $", 1, 1},
	{274, ML_CODE_ORSTRGT, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRGT_OUT off op1 < $", 1, 0},
	{275, ML_CODE_ORSTRGT, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRGT_OUT on op1 < $", 1, 1},

	{276, ML_CODE_ORSTRGE, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ORSTRGE_OUT off op1 > op2", 1, 1},
	{277, ML_CODE_ORSTRGE, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ORSTRGE_OUT off op1 == op2", 1, 1},
	{278, ML_CODE_ORSTRGE, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ORSTRGE_OUT off op1 < op2", 1, 0},
	{279, ML_CODE_ORSTRGE, setCodeAND_OR, setInputDIn_off_longStr, verifyResultNormal,
			"ORSTRGE_OUT op1 shorter than op2", 1, 1},
	{280, ML_CODE_ORSTRGE, setCodeAND_OR, setInputDIn_off_shortStr, verifyResultNormal,
			"ORSTRGE_OUT op1 longer than op2", 1, 0},
	{281, ML_CODE_ORSTRGE, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ORSTRGE_OUT on op1 > op2", 1, 1},
	{282, ML_CODE_ORSTRGE, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ORSTRGE_OUT on op1 == op2", 1, 1},
	{283, ML_CODE_ORSTRGE, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ORSTRGE_OUT on op1 < op2", 1, 1},
	{284, ML_CODE_ORSTRGE, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ORSTRGE_OUT off op1 > $", 1, 1},
	{285, ML_CODE_ORSTRGE, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ORSTRGE_OUT off op1 == $", 1, 1},
	{286, ML_CODE_ORSTRGE, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ORSTRGE_OUT off op1 < $", 1, 0},
	{287, ML_CODE_ORSTRGE, setCodeAND_OR_Str, setInputSIn_off_shortStr, verifyResultNormal,
			"ORSTRGE_OUT on op1 longer than $", 1, 1},
	{288, ML_CODE_ORSTRGE, setCodeAND_OR_Str, setInputSIn_off_longStr, verifyResultNormal,
			"ORSTRGE_OUT on op1 shorter than $", 1, 0},
	{289, ML_CODE_ORSTRGE, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ORSTRGE_OUT on op1 > $", 1, 1},
	{290, ML_CODE_ORSTRGE, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ORSTRGE_OUT on op1 == $", 1, 1},
	{291, ML_CODE_ORSTRGE, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ORSTRGE_OUT on op1 < $", 1, 1},
	{292, ML_CODE_ORSTRGE, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRGE_OUT off op1 > $", 1, 1},
	{293, ML_CODE_ORSTRGE, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRGE_OUT on op1 > $", 1, 1},
	{294, ML_CODE_ORSTRGE, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRGE_OUT off op1 == $", 1, 1},
	{295, ML_CODE_ORSTRGE, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRGE_OUT on op1 == $", 1, 1},
	{296, ML_CODE_ORSTRGE, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRGE_OUT off op1 < $", 1, 0},
	{297, ML_CODE_ORSTRGE, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRGE_OUT on op1 < $", 1, 1},

	{298, ML_CODE_ORSTRLT, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ORSTRLT_OUT off op1 > op2", 1, 0},
	{299, ML_CODE_ORSTRLT, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ORSTRLT_OUT off op1 == op2", 1, 0},
	{300, ML_CODE_ORSTRLT, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ORSTRLT_OUT off op1 < op2", 1, 1},
	{301, ML_CODE_ORSTRLT, setCodeAND_OR, setInputDIn_off_longStr, verifyResultNormal,
			"ORSTRLT_OUT op1 shorter than op2", 1, 0},
	{302, ML_CODE_ORSTRLT, setCodeAND_OR, setInputDIn_off_shortStr, verifyResultNormal,
			"ORSTRLT_OUT op1 longer than op2", 1, 1},
	{303, ML_CODE_ORSTRLT, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ORSTRLT_OUT on op1 > op2", 1, 1},
	{304, ML_CODE_ORSTRLT, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ORSTRLT_OUT on op1 == op2", 1, 1},
	{305, ML_CODE_ORSTRLT, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ORSTRLT_OUT on op1 < op2", 1, 1},
	{306, ML_CODE_ORSTRLT, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ORSTRLT_OUT off op1 > $", 1, 0},
	{307, ML_CODE_ORSTRLT, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ORSTRLT_OUT off op1 == $", 1, 0},
	{308, ML_CODE_ORSTRLT, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ORSTRLT_OUT off op1 < $", 1, 1},
	{309, ML_CODE_ORSTRLT, setCodeAND_OR_Str, setInputSIn_off_shortStr, verifyResultNormal,
			"ORSTRLT_OUT on op1 longer than $", 1, 0},
	{310, ML_CODE_ORSTRLT, setCodeAND_OR_Str, setInputSIn_off_longStr, verifyResultNormal,
			"ORSTRLT_OUT on op1 shorter than $", 1, 1},
	{311, ML_CODE_ORSTRLT, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ORSTRLT_OUT on op1 > $", 1, 1},
	{312, ML_CODE_ORSTRLT, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ORSTRLT_OUT on op1 == $", 1, 1},
	{313, ML_CODE_ORSTRLT, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ORSTRLT_OUT on op1 < $", 1, 1},
	{314, ML_CODE_ORSTRLT, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRLT_OUT off op1 > $", 1, 0},
	{315, ML_CODE_ORSTRLT, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRLT_OUT on op1 > $", 1, 1},
	{316, ML_CODE_ORSTRLT, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRLT_OUT off op1 == $", 1, 0},
	{317, ML_CODE_ORSTRLT, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRLT_OUT on op1 == $", 1, 1},
	{318, ML_CODE_ORSTRLT, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRLT_OUT off op1 < $", 1, 1},
	{319, ML_CODE_ORSTRLT, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRLT_OUT on op1 < $", 1, 1},

	{320, ML_CODE_ORSTRLE, setCodeAND_OR, setInputDIn_off_bigValStr, verifyResultNormal,
			"ORSTRLE_OUT off op1 > op2", 1, 0},
	{321, ML_CODE_ORSTRLE, setCodeAND_OR, setInputDIn_off_sameValStr, verifyResultNormal,
			"ORSTRLE_OUT off op1 == op2", 1, 1},
	{322, ML_CODE_ORSTRLE, setCodeAND_OR, setInputDIn_off_lessValStr, verifyResultNormal,
			"ORSTRLE_OUT off op1 < op2", 1, 1},
	{323, ML_CODE_ORSTRLE, setCodeAND_OR, setInputDIn_off_longStr, verifyResultNormal,
			"ORSTRLE_OUT op1 shorter than op2", 1, 0},
	{324, ML_CODE_ORSTRLE, setCodeAND_OR, setInputDIn_off_shortStr, verifyResultNormal,
			"ORSTRLE_OUT op1 longer than op2", 1, 1},
	{325, ML_CODE_ORSTRLE, setCodeAND_OR, setInputDIn_on_bigValStr, verifyResultNormal,
			"ORSTRLE_OUT on op1 > op2", 1, 1},
	{326, ML_CODE_ORSTRLE, setCodeAND_OR, setInputDIn_on_sameValStr, verifyResultNormal,
			"ORSTRLE_OUT on op1 == op2", 1, 1},
	{327, ML_CODE_ORSTRLE, setCodeAND_OR, setInputDIn_on_lessValStr, verifyResultNormal,
			"ORSTRLE_OUT on op1 < op2", 1, 1},
	{328, ML_CODE_ORSTRLE, setCodeAND_OR_Str, setInputSIn_off_bigStr, verifyResultNormal,
			"ORSTRLE_OUT off op1 > $", 1, 0},
	{329, ML_CODE_ORSTRLE, setCodeAND_OR_Str, setInputSIn_off_sameStr, verifyResultNormal,
			"ORSTRLE_OUT off op1 == $", 1, 1},
	{330, ML_CODE_ORSTRLE, setCodeAND_OR_Str, setInputSIn_off_lessStr, verifyResultNormal,
			"ORSTRLE_OUT off op1 < $", 1, 1},
	{331, ML_CODE_ORSTRLE, setCodeAND_OR_Str, setInputSIn_off_shortStr, verifyResultNormal,
			"ORSTRLE_OUT on op1 longer than $", 1, 0},
	{332, ML_CODE_ORSTRLE, setCodeAND_OR_Str, setInputSIn_off_longStr, verifyResultNormal,
			"ORSTRLE_OUT on op1 shorter than $", 1, 1},
	{333, ML_CODE_ORSTRLE, setCodeAND_OR_Str, setInputSIn_on_bigStr, verifyResultNormal,
			"ORSTRLE_OUT on op1 > $", 1, 1},
	{334, ML_CODE_ORSTRLE, setCodeAND_OR_Str, setInputSIn_on_sameStr, verifyResultNormal,
			"ORSTRLE_OUT on op1 == $", 1, 1},
	{335, ML_CODE_ORSTRLE, setCodeAND_OR_Str, setInputSIn_on_lessStr, verifyResultNormal,
			"ORSTRLE_OUT on op1 < $", 1, 1},
	{336, ML_CODE_ORSTRLE, setCodeAND_OR_big2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRLE_OUT off op1 > $", 1, 0},
	{337, ML_CODE_ORSTRLE, setCodeAND_OR_big2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRLE_OUT on op1 > $", 1, 1},
	{338, ML_CODE_ORSTRLE, setCodeAND_OR_same2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRLE_OUT off op1 == $", 1, 1},
	{339, ML_CODE_ORSTRLE, setCodeAND_OR_same2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRLE_OUT on op1 == $", 1, 1},
	{340, ML_CODE_ORSTRLE, setCodeAND_OR_less2Str, setInputNIn_off_Str, verifyResultNormal,
			"ORSTRLE_OUT off op1 < $", 1, 1},
	{341, ML_CODE_ORSTRLE, setCodeAND_OR_less2Str, setInputNIn_on_Str, verifyResultNormal,
			"ORSTRLE_OUT on op1 < $", 1, 1},

	{-1, 0xFFFF, NULL, NULL, NULL, NULL, 0, 0 }
};

int total_basic_comp_string_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_comp_string_test_number; i++)
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

void setCodeLDx_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 50);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDx_Str_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addConstantStringoperand("ABCDE");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDx_lStr_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addConstantStringoperand("ABCDEFG");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDx_shStr_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addConstantStringoperand("ABC");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDx_same2Str_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addConstantStringoperand("ABCDE"); addConstantStringoperand("ABCDE");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDx_big2Str_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addConstantStringoperand("ABCDF"); addConstantStringoperand("ABCDE");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDx_less2Str_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addConstantStringoperand("ABCDD"); addConstantStringoperand("ABCDE");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeAND_OR_Str(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addConstantStringoperand("ABCDE");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeAND_OR_big2Str(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addConstantStringoperand("ABCDF"); addConstantStringoperand("ABCDE");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeAND_OR_same2Str(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addConstantStringoperand("ABCDE"); addConstantStringoperand("ABCDE");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeAND_OR_less2Str(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addConstantStringoperand("ABCDD"); addConstantStringoperand("ABCDE");
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setInputDIn_bigStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDF");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_sameStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_lessStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDD");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}


void setInputDIn_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABC");

	TestCodeTearDown();
}


void setInputDIn_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDEGH");

	TestCodeTearDown();
}

void setInputSIn_bigStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDF");

	TestCodeTearDown();
}

void setInputSIn_sameStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_lessStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDD"); // compare 10 and 20

	TestCodeTearDown();
}

void setInputSIn_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE"); // compare 10 and 20

	TestCodeTearDown();
}

void setInputSIn_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABC"); // compare 10 and 20

	TestCodeTearDown();
}

void setInputDIn_off_bigValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDF");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_off_sameValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_off_lessValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDD");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_on_bigValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDF");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_on_sameValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_on_lessValStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDD");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDE");

	TestCodeTearDown();
}

void setInputDIn_on_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABC");

	TestCodeTearDown();
}

void setInputDIn_on_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDEGH");

	TestCodeTearDown();
}

void setInputDIn_off_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABC");

	TestCodeTearDown();
}

void setInputDIn_off_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");
	addDeviceControlInstructionToString(0, (uint8)in, 50, "ABCDEGH");

	TestCodeTearDown();
}

void setInputSIn_off_bigStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDF");

	TestCodeTearDown();
}

void setInputSIn_off_sameStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_off_lessStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDD"); // compare 10 and 20

	TestCodeTearDown();
}

void setInputSIn_on_bigStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDF");

	TestCodeTearDown();
}

void setInputSIn_on_sameStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDE");

	TestCodeTearDown();
}

void setInputSIn_on_lessStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDD"); // compare 10 and 20

	TestCodeTearDown();
}

void setInputSIn_on_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDEGH");

	TestCodeTearDown();
}

void setInputSIn_on_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABC");

	TestCodeTearDown();
}

void setInputSIn_off_longStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABC");

	TestCodeTearDown();
}

void setInputSIn_off_shortStr(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToString(0, (uint8)in, in_pos, "ABCDEGH");

	TestCodeTearDown();
}

void setInputNIn_off_Str(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);

	TestCodeTearDown();
}

void setInputNIn_on_Str(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);

	TestCodeTearDown();
}

static uint16 getInPos(int reg, int inx_pos)
{
	//uint16 pos[3][2]={ {0,0}, {6144,4096}, {12281,8185}};
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12281,8185}}; // 6 byte required

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
void test_basic_compare_string(int tno, uint16 dummy)
{
	int i, rc=0, olast=0;
	uint8 in=0, out=0;
	uint16 in_pos, out_pos;
	uint8 res_bit;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			if(out==OPERAND_ML_CODE_F) continue;

			out_pos = getOutPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getInPos(in, i);

					testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

					rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s command error! in_%s[%d], out_%s[%d] expected=%d\n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
							reg[in], in_pos, reg[out], out_pos, testCase[tno].expected);
					}
					else
					{
						rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
						if(rc == 1)
						{
							test_getBit(&res_bit, out, out_pos);
							fprintf(flog, "test_no[%d]: %s command error! in_%s[%d], out_%s[%d]=%d exp=%d\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_bit, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testBasicCompareStringCommand(void)
{
	int index=10;
	int start, end;
	char log[] = "err_comp_str.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare string LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=52;index<57;index++)
		test_basic_compare_string(index, 0);
#else
	total_basic_comp_string_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LDSTREQ);
	end = getTestCaseNumberEnd(ML_CODE_ORSTRLE);

	DBG_LOGPRINT("testBasicCompareStringCommand: %d to %d total %d\n", start, end, total_basic_comp_string_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_compare_string(index, 0);
	}
#endif
	fclose(flog);
}
#endif
