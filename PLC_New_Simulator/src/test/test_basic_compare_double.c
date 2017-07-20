/*
 * test_basic_compare_double.c
 *
 *  Created on: Mar 24, 2015
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

extern int verifyResultNormal(int tcase, uint8 dest_reg, uint16 pos, uint8 expected);

void setCodeLDx_double_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDx_DE_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDx_nDE_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeAND_OR_double(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeAND_OR_DE(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputDIn_bigValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_sameValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_lessValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_bigValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sameValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_lessValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_bigValdouble_nE(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sameValdouble_nE(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_lessValdouble_nE(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_off_bigValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_sameValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_lessValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_bigValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_sameValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_lessValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_bigValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_sameValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_lessValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_bigValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_sameValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_lessValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

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
	{0, ML_CODE_LDEDEQ, setCodeLDx_double_OUT, setInputDIn_bigValdouble, verifyResultNormal,
			"LDEDEQ_OUT op1 > op2", 1, 0},
	{1, ML_CODE_LDEDEQ, setCodeLDx_double_OUT, setInputDIn_sameValdouble, verifyResultNormal,
			"LDEDEQ_OUT op1 == op2", 1, 1},
	{2, ML_CODE_LDEDEQ, setCodeLDx_double_OUT, setInputDIn_lessValdouble, verifyResultNormal,
			"LDEDEQ_OUT op1 < op2", 1, 0},
	{3, ML_CODE_LDEDEQ, setCodeLDx_DE_OUT, setInputSIn_bigValdouble_E, verifyResultNormal,
			"LDEDEQ_OUT op1 > E", 1, 0},
	{4, ML_CODE_LDEDEQ, setCodeLDx_DE_OUT, setInputSIn_sameValdouble_E, verifyResultNormal,
			"LDEDEQ_OUT op1 == E", 1, 1},
	{5, ML_CODE_LDEDEQ, setCodeLDx_DE_OUT, setInputSIn_lessValdouble_E, verifyResultNormal,
			"LDEDEQ_OUT op1 < E", 1, 0},
	{6, ML_CODE_LDEDEQ, setCodeLDx_nDE_OUT, setInputSIn_bigValdouble_nE, verifyResultNormal,
			"LDEDEQ_OUT op1 > nE", 1, 0},
	{7, ML_CODE_LDEDEQ, setCodeLDx_nDE_OUT, setInputSIn_sameValdouble_nE, verifyResultNormal,
			"LDEDEQ_OUT op1 == nE", 1, 1},
	{8, ML_CODE_LDEDEQ, setCodeLDx_nDE_OUT, setInputSIn_lessValdouble_nE, verifyResultNormal,
			"LDEDEQ_OUT op1 < nE", 1, 0},

	{9, ML_CODE_LDEDNE, setCodeLDx_double_OUT, setInputDIn_bigValdouble, verifyResultNormal,
			"LDEDNE_OUT op1 > op2", 1, 1},
	{10, ML_CODE_LDEDNE, setCodeLDx_double_OUT, setInputDIn_sameValdouble, verifyResultNormal,
			"LDEDNE_OUT op1 == op2", 1, 0},
	{11, ML_CODE_LDEDNE, setCodeLDx_double_OUT, setInputDIn_lessValdouble, verifyResultNormal,
			"LDEDNE_OUT op1 < op2", 1, 1},
	{12, ML_CODE_LDEDNE, setCodeLDx_DE_OUT, setInputSIn_bigValdouble_E, verifyResultNormal,
			"LDEDNE_OUT op1 > E", 1, 1},
	{13, ML_CODE_LDEDNE, setCodeLDx_DE_OUT, setInputSIn_sameValdouble_E, verifyResultNormal,
			"LDEDNE_OUT op1 == E", 1, 0},
	{14, ML_CODE_LDEDNE, setCodeLDx_DE_OUT, setInputSIn_lessValdouble_E, verifyResultNormal,
			"LDEDNE_OUT op1 < E", 1, 1},
	{15, ML_CODE_LDEDNE, setCodeLDx_nDE_OUT, setInputSIn_bigValdouble_nE, verifyResultNormal,
			"LDEDNE_OUT op1 > nE", 1, 1},
	{16, ML_CODE_LDEDNE, setCodeLDx_nDE_OUT, setInputSIn_sameValdouble_nE, verifyResultNormal,
			"LDEDNE_OUT op1 == nE", 1, 0},
	{17, ML_CODE_LDEDNE, setCodeLDx_nDE_OUT, setInputSIn_lessValdouble_nE, verifyResultNormal,
			"LDEDNE_OUT op1 < nE", 1, 1},

	{18, ML_CODE_LDEDGT, setCodeLDx_double_OUT, setInputDIn_bigValdouble, verifyResultNormal,
			"LDEDGT_OUT op1 > op2", 1, 1},
	{19, ML_CODE_LDEDGT, setCodeLDx_double_OUT, setInputDIn_sameValdouble, verifyResultNormal,
			"LDEDGT_OUT op1 == op2", 1, 0},
	{20, ML_CODE_LDEDGT, setCodeLDx_double_OUT, setInputDIn_lessValdouble, verifyResultNormal,
			"LDEDGT_OUT op1 < op2", 1, 0},
	{21, ML_CODE_LDEDGT, setCodeLDx_DE_OUT, setInputSIn_bigValdouble_E, verifyResultNormal,
			"LDEDGT_OUT op1 > E", 1, 1},
	{22, ML_CODE_LDEDGT, setCodeLDx_DE_OUT, setInputSIn_sameValdouble_E, verifyResultNormal,
			"LDEDGT_OUT op1 == E", 1, 0},
	{23, ML_CODE_LDEDGT, setCodeLDx_DE_OUT, setInputSIn_lessValdouble_E, verifyResultNormal,
			"LDEDGT_OUT op1 < E", 1, 0},
	{24, ML_CODE_LDEDGT, setCodeLDx_nDE_OUT, setInputSIn_bigValdouble_nE, verifyResultNormal,
			"LDEDGT_OUT op1 > nE", 1, 1},
	{25, ML_CODE_LDEDGT, setCodeLDx_nDE_OUT, setInputSIn_sameValdouble_nE, verifyResultNormal,
			"LDEDGT_OUT op1 == nE", 1, 0},
	{26, ML_CODE_LDEDGT, setCodeLDx_nDE_OUT, setInputSIn_lessValdouble_nE, verifyResultNormal,
			"LDEDGT_OUT op1 < nE", 1, 0},

	{27, ML_CODE_LDEDGE, setCodeLDx_double_OUT, setInputDIn_bigValdouble, verifyResultNormal,
			"LDEDGE_OUT op1 > op2", 1, 1},
	{28, ML_CODE_LDEDGE, setCodeLDx_double_OUT, setInputDIn_sameValdouble, verifyResultNormal,
			"LDEDGE_OUT op1 == op2", 1, 1},
	{29, ML_CODE_LDEDGE, setCodeLDx_double_OUT, setInputDIn_lessValdouble, verifyResultNormal,
			"LDEDGE_OUT op1 < op2", 1, 0},
	{30, ML_CODE_LDEDGE, setCodeLDx_DE_OUT, setInputSIn_bigValdouble_E, verifyResultNormal,
			"LDEDGE_OUT op1 > E", 1, 1},
	{31, ML_CODE_LDEDGE, setCodeLDx_DE_OUT, setInputSIn_sameValdouble_E, verifyResultNormal,
			"LDEDGE_OUT op1 == E", 1, 1},
	{32, ML_CODE_LDEDGE, setCodeLDx_DE_OUT, setInputSIn_lessValdouble_E, verifyResultNormal,
			"LDEDGE_OUT op1 > E", 1, 0},
	{33, ML_CODE_LDEDGE, setCodeLDx_nDE_OUT, setInputSIn_bigValdouble_nE, verifyResultNormal,
			"LDEDGE_OUT op1 > nE", 1, 1},
	{34, ML_CODE_LDEDGE, setCodeLDx_nDE_OUT, setInputSIn_sameValdouble_nE, verifyResultNormal,
			"LDEDGE_OUT op1 == nE", 1, 1},
	{35, ML_CODE_LDEDGE, setCodeLDx_nDE_OUT, setInputSIn_lessValdouble_nE, verifyResultNormal,
			"LDEDGE_OUT op1 < nE", 1, 0},

	{36, ML_CODE_LDEDLT, setCodeLDx_double_OUT, setInputDIn_bigValdouble, verifyResultNormal,
			"LDEDLT_OUT op1 > op2", 1, 0},
	{37, ML_CODE_LDEDLT, setCodeLDx_double_OUT, setInputDIn_sameValdouble, verifyResultNormal,
			"LDEDLT_OUT op1 == op2", 1, 0},
	{38, ML_CODE_LDEDLT, setCodeLDx_double_OUT, setInputDIn_lessValdouble, verifyResultNormal,
			"LDEDLT_OUT op1 < op2", 1, 1},
	{39, ML_CODE_LDEDLT, setCodeLDx_DE_OUT, setInputSIn_bigValdouble_E, verifyResultNormal,
			"LDEDLT_OUT op1 > E", 1, 0},
	{40, ML_CODE_LDEDLT, setCodeLDx_DE_OUT, setInputSIn_sameValdouble_E, verifyResultNormal,
			"LDEDLT_OUT op1 == E", 1, 0},
	{41, ML_CODE_LDEDLT, setCodeLDx_DE_OUT, setInputSIn_lessValdouble_E, verifyResultNormal,
			"LDEDLT_OUT op1 < E", 1, 1},
	{42, ML_CODE_LDEDLT, setCodeLDx_nDE_OUT, setInputSIn_bigValdouble_nE, verifyResultNormal,
			"LDEDLT_OUT op1 > nE", 1, 0},
	{43, ML_CODE_LDEDLT, setCodeLDx_nDE_OUT, setInputSIn_sameValdouble_nE, verifyResultNormal,
			"LDEDLT_OUT op1 == nE", 1, 0},
	{44, ML_CODE_LDEDLT, setCodeLDx_nDE_OUT, setInputSIn_lessValdouble_nE, verifyResultNormal,
			"LDEDLT_OUT op1 < nE", 1, 1},

	{45, ML_CODE_LDEDLE, setCodeLDx_double_OUT, setInputDIn_bigValdouble, verifyResultNormal,
			"LDEDLE_OUT op1 > op2", 1, 0},
	{46, ML_CODE_LDEDLE, setCodeLDx_double_OUT, setInputDIn_sameValdouble, verifyResultNormal,
			"LDEDLE_OUT op1 == op2", 1, 1},
	{47, ML_CODE_LDEDLE, setCodeLDx_double_OUT, setInputDIn_lessValdouble, verifyResultNormal,
			"LDEDLE_OUT op1 < op2", 1, 1},
	{48, ML_CODE_LDEDLE, setCodeLDx_DE_OUT, setInputSIn_bigValdouble_E, verifyResultNormal,
			"LDEDLE_OUT op1 > E", 1, 0},
	{49, ML_CODE_LDEDLE, setCodeLDx_DE_OUT, setInputSIn_sameValdouble_E, verifyResultNormal,
			"LDEDLE_OUT op1 == E", 1, 1},
	{50, ML_CODE_LDEDLE, setCodeLDx_DE_OUT, setInputSIn_lessValdouble_E, verifyResultNormal,
			"LDEDLE_OUT op1 < E", 1, 1},
	{51, ML_CODE_LDEDLE, setCodeLDx_nDE_OUT, setInputSIn_bigValdouble_nE, verifyResultNormal,
			"LDEDLE_OUT op1 > nE", 1, 0},
	{52, ML_CODE_LDEDLE, setCodeLDx_nDE_OUT, setInputSIn_sameValdouble_nE, verifyResultNormal,
			"LDEDLE_OUT op1 == nE", 1, 1},
	{53, ML_CODE_LDEDLE, setCodeLDx_nDE_OUT, setInputSIn_lessValdouble_nE, verifyResultNormal,
			"LDEDLE_OUT op1 < nE", 1, 1},

	{54, ML_CODE_ANDEDEQ, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"ANDEDEQ_OUT off S > D", 1, 0},
	{55, ML_CODE_ANDEDEQ, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"ANDEDEQ_OUT off S = D", 1, 0},
	{56, ML_CODE_ANDEDEQ, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"ANDEDEQ_OUT off S < D", 1, 0},
	{57, ML_CODE_ANDEDEQ, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"ANDEDEQ_OUT on S > D", 1, 0},
	{58, ML_CODE_ANDEDEQ, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"ANDEDEQ_OUT on S = D", 1, 1},
	{59, ML_CODE_ANDEDEQ, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"ANDEDEQ_OUT on S < D", 1, 0},
	{60, ML_CODE_ANDEDEQ, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"ANDEDEQ_OUT off K > D", 1, 0},
	{61, ML_CODE_ANDEDEQ, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"ANDEDEQ_OUT off K = D", 1, 0},
	{62, ML_CODE_ANDEDEQ, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"ANDEDEQ_OUT off K < D", 1, 0},
	{63, ML_CODE_ANDEDEQ, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"ANDEDEQ_OUT on K > D", 1, 0},
	{64, ML_CODE_ANDEDEQ, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"ANDEDEQ_OUT on K = D", 1, 1},
	{65, ML_CODE_ANDEDEQ, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"ANDEDEQ_OUT on K < D", 1, 0},

	{66, ML_CODE_ANDEDNE, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"ANDEDNE_OUT off S > D", 1, 0},
	{67, ML_CODE_ANDEDNE, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"ANDEDNE_OUT off S = D", 1, 0},
	{68, ML_CODE_ANDEDNE, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"ANDEDNE_OUT off S < D", 1, 0},
	{69, ML_CODE_ANDEDNE, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"ANDEDNE_OUT on S > D", 1, 1},
	{70, ML_CODE_ANDEDNE, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"ANDEDNE_OUT on S = D", 1, 0},
	{71, ML_CODE_ANDEDNE, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"ANDEDNE_OUT on S < D", 1, 1},
	{72, ML_CODE_ANDEDNE, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"ANDEDNE_OUT off K > D", 1, 0},
	{73, ML_CODE_ANDEDNE, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"ANDEDNE_OUT off K = D", 1, 0},
	{74, ML_CODE_ANDEDNE, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"ANDEDNE_OUT off K < D", 1, 0},
	{75, ML_CODE_ANDEDNE, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"ANDEDNE_OUT on K > D", 1, 1},
	{76, ML_CODE_ANDEDNE, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"ANDEDNE_OUT on K = D", 1, 0},
	{77, ML_CODE_ANDEDNE, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"ANDEDNE_OUT on K < D", 1, 1},

	{78, ML_CODE_ANDEDGT, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"ANDEDGT_OUT off S > D", 1, 0},
	{79, ML_CODE_ANDEDGT, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"ANDEDGT_OUT off S = D", 1, 0},
	{80, ML_CODE_ANDEDGT, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"ANDEDGT_OUT off S < D", 1, 0},
	{81, ML_CODE_ANDEDGT, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"ANDEDGT_OUT on S > D", 1, 1},
	{82, ML_CODE_ANDEDGT, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"ANDEDGT_OUT on S = D", 1, 0},
	{83, ML_CODE_ANDEDGT, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"ANDEDGT_OUT on S < D", 1, 0},
	{84, ML_CODE_ANDEDGT, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"ANDEDGT_OUT off K > D", 1, 0},
	{85, ML_CODE_ANDEDGT, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"ANDEDGT_OUT off K = D", 1, 0},
	{86, ML_CODE_ANDEDGT, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"ANDEDGT_OUT off K < D", 1, 0},
	{87, ML_CODE_ANDEDGT, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"ANDEDGT_OUT on K > D", 1, 1},
	{88, ML_CODE_ANDEDGT, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"ANDEDGT_OUT on K = D", 1, 0},
	{89, ML_CODE_ANDEDGT, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"ANDEDGT_OUT on K < D", 1, 0},

	{90, ML_CODE_ANDEDGE, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"ANDEDGE_OUT off S > D", 1, 0},
	{91, ML_CODE_ANDEDGE, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"ANDEDGE_OUT off S = D", 1, 0},
	{92, ML_CODE_ANDEDGE, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"ANDEDGE_OUT off S < D", 1, 0},
	{93, ML_CODE_ANDEDGE, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"ANDEDGE_OUT on S > D", 1, 1},
	{94, ML_CODE_ANDEDGE, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"ANDEDGE_OUT on S = D", 1, 1},
	{95, ML_CODE_ANDEDGE, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"ANDEDGE_OUT on S < D", 1, 0},
	{96, ML_CODE_ANDEDGE, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"ANDEDGE_OUT off K > D", 1, 0},
	{97, ML_CODE_ANDEDGE, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"ANDEDGE_OUT off K = D", 1, 0},
	{98, ML_CODE_ANDEDGE, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"ANDEDGE_OUT off K < D", 1, 0},
	{99, ML_CODE_ANDEDGE, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"ANDEDGE_OUT on K > D", 1, 1},
	{100, ML_CODE_ANDEDGE, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"ANDEDGE_OUT on K = D", 1, 1},
	{101, ML_CODE_ANDEDGE, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"ANDEDGE_OUT on K < D", 1, 0},

	{102, ML_CODE_ANDEDLT, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"ANDEDLT_OUT off S > D", 1, 0},
	{103, ML_CODE_ANDEDLT, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"ANDEDLT_OUT off S = D", 1, 0},
	{104, ML_CODE_ANDEDLT, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"ANDEDLT_OUT off S < D", 1, 0},
	{105, ML_CODE_ANDEDLT, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"ANDEDLT_OUT on S > D", 1, 0},
	{106, ML_CODE_ANDEDLT, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"ANDEDLT_OUT on S = D", 1, 0},
	{107, ML_CODE_ANDEDLT, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"ANDEDLT_OUT on S < D", 1, 1},
	{108, ML_CODE_ANDEDLT, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"ANDEDLT_OUT off K > D", 1, 0},
	{109, ML_CODE_ANDEDLT, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"ANDEDLT_OUT off K = D", 1, 0},
	{110, ML_CODE_ANDEDLT, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"ANDEDLT_OUT off K < D", 1, 0},
	{111, ML_CODE_ANDEDLT, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"ANDEDLT_OUT on K > D", 1, 0},
	{112, ML_CODE_ANDEDLT, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"ANDEDLT_OUT on K = D", 1, 0},
	{113, ML_CODE_ANDEDLT, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"ANDEDLT_OUT on K < D", 1, 1},

	{114, ML_CODE_ANDEDLE, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"ANDEDLE_OUT off S > D", 1, 0},
	{115, ML_CODE_ANDEDLE, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"ANDEDLE_OUT off S = D", 1, 0},
	{116, ML_CODE_ANDEDLE, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"ANDEDLE_OUT off S < D", 1, 0},
	{117, ML_CODE_ANDEDLE, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"ANDEDLE_OUT on S > D", 1, 0},
	{118, ML_CODE_ANDEDLE, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"ANDEDLE_OUT on S = D", 1, 1},
	{119, ML_CODE_ANDEDLE, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"ANDEDLE_OUT on S < D", 1, 1},
	{120, ML_CODE_ANDEDLE, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"ANDEDLE_OUT off K > D", 1, 0},
	{121, ML_CODE_ANDEDLE, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"ANDEDLE_OUT off K = D", 1, 0},
	{122, ML_CODE_ANDEDLE, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"ANDEDLE_OUT off K < D", 1, 0},
	{123, ML_CODE_ANDEDLE, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"ANDEDLE_OUT on K > D", 1, 0},
	{124, ML_CODE_ANDEDLE, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"ANDEDLE_OUT on K = D", 1, 1},
	{125, ML_CODE_ANDEDLE, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"ANDEDLE_OUT on K < D", 1, 1},

	{126, ML_CODE_OREDEQ, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"OREDEQ_OUT off S > D", 1, 0},
	{127, ML_CODE_OREDEQ, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"OREDEQ_OUT off S = D", 1, 1},
	{128, ML_CODE_OREDEQ, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"OREDEQ_OUT off S < D", 1, 0},
	{129, ML_CODE_OREDEQ, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"OREDEQ_OUT on S > D", 1, 1},
	{130, ML_CODE_OREDEQ, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"OREDEQ_OUT on S = D", 1, 1},
	{131, ML_CODE_OREDEQ, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"OREDEQ_OUT on S < D", 1, 1},
	{132, ML_CODE_OREDEQ, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"OREDEQ_OUT off K > D", 1, 0},
	{133, ML_CODE_OREDEQ, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"OREDEQ_OUT off K = D", 1, 1},
	{134, ML_CODE_OREDEQ, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"OREDEQ_OUT off K < D", 1, 0},
	{135, ML_CODE_OREDEQ, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"OREDEQ_OUT on K > D", 1, 1},
	{136, ML_CODE_OREDEQ, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"OREDEQ_OUT on K = D", 1, 1},
	{137, ML_CODE_OREDEQ, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"OREDEQ_OUT on K < D", 1, 1},

	{138, ML_CODE_OREDNE, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"OREDNE_OUT off S > D", 1, 1},
	{139, ML_CODE_OREDNE, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"OREDNE_OUT off S = D", 1, 0},
	{140, ML_CODE_OREDNE, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"OREDNE_OUT off S < D", 1, 1},
	{141, ML_CODE_OREDNE, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"OREDNE_OUT on S > D", 1, 1},
	{142, ML_CODE_OREDNE, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"OREDNE_OUT on S = D", 1, 1},
	{143, ML_CODE_OREDNE, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"OREDNE_OUT on S < D", 1, 1},
	{144, ML_CODE_OREDNE, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"OREDNE_OUT off K > D", 1, 1},
	{145, ML_CODE_OREDNE, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"OREDNE_OUT off K = D", 1, 0},
	{146, ML_CODE_OREDNE, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"OREDNE_OUT off K < D", 1, 1},
	{147, ML_CODE_OREDNE, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"OREDNE_OUT on K > D", 1, 1},
	{148, ML_CODE_OREDNE, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"OREDNE_OUT on K = D", 1, 1},
	{149, ML_CODE_OREDNE, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"OREDNE_OUT on K < D", 1, 1},

	{150, ML_CODE_OREDGT, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"OREDGT_OUT off S > D", 1, 1},
	{151, ML_CODE_OREDGT, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"OREDGT_OUT off S = D", 1, 0},
	{152, ML_CODE_OREDGT, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"OREDGT_OUT off S < D", 1, 0},
	{153, ML_CODE_OREDGT, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"OREDGT_OUT on S > D", 1, 1},
	{154, ML_CODE_OREDGT, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"OREDGT_OUT on S = D", 1, 1},
	{155, ML_CODE_OREDGT, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"OREDGT_OUT on S < D", 1, 1},
	{156, ML_CODE_OREDGT, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"OREDGT_OUT off K > D", 1, 1},
	{157, ML_CODE_OREDGT, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"OREDGT_OUT off K = D", 1, 0},
	{158, ML_CODE_OREDGT, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"OREDGT_OUT off K < D", 1, 0},
	{159, ML_CODE_OREDGT, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"OREDGT_OUT on K > D", 1, 1},
	{160, ML_CODE_OREDGT, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"OREDGT_OUT on K = D", 1, 1},
	{161, ML_CODE_OREDGT, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"OREDGT_OUT on K < D", 1, 1},

	{162, ML_CODE_OREDGE, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"OREDGE_OUT off S > D", 1, 1},
	{163, ML_CODE_OREDGE, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"OREDGE_OUT off S = D", 1, 1},
	{164, ML_CODE_OREDGE, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"OREDGE_OUT off S < D", 1, 0},
	{165, ML_CODE_OREDGE, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"OREDGE_OUT on S > D", 1, 1},
	{166, ML_CODE_OREDGE, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"OREDGE_OUT on S = D", 1, 1},
	{167, ML_CODE_OREDGE, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"OREDGE_OUT on S < D", 1, 1},
	{168, ML_CODE_OREDGE, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"OREDGE_OUT off K > D", 1, 1},
	{169, ML_CODE_OREDGE, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"OREDGE_OUT off K = D", 1, 1},
	{170, ML_CODE_OREDGE, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"OREDGE_OUT off K < D", 1, 0},
	{171, ML_CODE_OREDGE, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"OREDGE_OUT on K > D", 1, 1},
	{172, ML_CODE_OREDGE, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"OREDGE_OUT on K = D", 1, 1},
	{173, ML_CODE_OREDGE, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"OREDGE_OUT on K < D", 1, 1},

	{174, ML_CODE_OREDLT, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"OREDLT_OUT off S > D", 1, 0},
	{175, ML_CODE_OREDLT, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"OREDLT_OUT off S = D", 1, 0},
	{176, ML_CODE_OREDLT, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"OREDLT_OUT off S < D", 1, 1},
	{177, ML_CODE_OREDLT, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"OREDLT_OUT on S > D", 1, 1},
	{178, ML_CODE_OREDLT, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"OREDLT_OUT on S = D", 1, 1},
	{179, ML_CODE_OREDLT, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"OREDLT_OUT on S < D", 1, 1},
	{180, ML_CODE_OREDLT, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"OREDLT_OUT off K > D", 1, 0},
	{181, ML_CODE_OREDLT, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"OREDLT_OUT off K = D", 1, 0},
	{182, ML_CODE_OREDLT, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"OREDLT_OUT off K < D", 1, 1},
	{183, ML_CODE_OREDLT, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"OREDLT_OUT on K > D", 1, 1},
	{184, ML_CODE_OREDLT, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"OREDLT_OUT on K = D", 1, 1},
	{185, ML_CODE_OREDLT, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"OREDLT_OUT on K < D", 1, 1},

	{186, ML_CODE_OREDLE, setCodeAND_OR_double, setInputDIn_off_bigValdouble, verifyResultNormal,
			"OREDLE_OUT off S > D", 1, 0},
	{187, ML_CODE_OREDLE, setCodeAND_OR_double, setInputDIn_off_sameValdouble, verifyResultNormal,
			"OREDLE_OUT off S = D", 1, 1},
	{188, ML_CODE_OREDLE, setCodeAND_OR_double, setInputDIn_off_lessValdouble, verifyResultNormal,
			"OREDLE_OUT off S < D", 1, 1},
	{189, ML_CODE_OREDLE, setCodeAND_OR_double, setInputDIn_on_bigValdouble, verifyResultNormal,
			"OREDLE_OUT on S > D", 1, 1},
	{190, ML_CODE_OREDLE, setCodeAND_OR_double, setInputDIn_on_sameValdouble, verifyResultNormal,
			"OREDLE_OUT on S = D", 1, 1},
	{191, ML_CODE_OREDLE, setCodeAND_OR_double, setInputDIn_on_lessValdouble, verifyResultNormal,
			"OREDLE_OUT on S < D", 1, 1},
	{192, ML_CODE_OREDLE, setCodeAND_OR_DE, setInputSIn_off_bigValdouble_E, verifyResultNormal,
			"OREDLE_OUT off K > D", 1, 0},
	{193, ML_CODE_OREDLE, setCodeAND_OR_DE, setInputSIn_off_sameValdouble_E, verifyResultNormal,
			"OREDLE_OUT off K = D", 1, 1},
	{194, ML_CODE_OREDLE, setCodeAND_OR_DE, setInputSIn_off_lessValdouble_E, verifyResultNormal,
			"OREDLE_OUT off K < D", 1, 1},
	{195, ML_CODE_OREDLE, setCodeAND_OR_DE, setInputSIn_on_bigValdouble_E, verifyResultNormal,
			"OREDLE_OUT on K > D", 1, 1},
	{196, ML_CODE_OREDLE, setCodeAND_OR_DE, setInputSIn_on_sameValdouble_E, verifyResultNormal,
			"OREDLE_OUT on K = D", 1, 1},
	{197, ML_CODE_OREDLE, setCodeAND_OR_DE, setInputSIn_on_lessValdouble_E, verifyResultNormal,
			"OREDLE_OUT on K < D", 1, 1},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};

int total_basic_comp_double_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_comp_double_test_number; i++)
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

void setCodeLDx_double_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 20);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDx_DE_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperandDouble(OPERAND_ML_CODE_DE, 1.23f);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDx_nDE_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperandDouble(OPERAND_ML_CODE_DE, -1.23f);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeAND_OR_double(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 50);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeAND_OR_DE(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addMLOperandDouble(OPERAND_ML_CODE_DE, 1.23f); addMLOperand(in_reg, in_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setInputDIn_bigValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.23f);
	addDeviceControlInstructionToDouble(0, (uint8)in, 20, 1.22f);

	TestCodeTearDown();
}

void setInputDIn_sameValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.23f);
	addDeviceControlInstructionToDouble(0, (uint8)in, 20, 1.23f);

	TestCodeTearDown();
}

void setInputDIn_lessValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.22f);
	addDeviceControlInstructionToDouble(0, (uint8)in, 20, 1.23f);

	TestCodeTearDown();
}

void setInputSIn_bigValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.24f);

	TestCodeTearDown();
}

void setInputSIn_sameValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.23f);

	TestCodeTearDown();
}

void setInputSIn_lessValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.22f);

	TestCodeTearDown();
}

void setInputSIn_bigValdouble_nE(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, -1.22f);

	TestCodeTearDown();
}

void setInputSIn_sameValdouble_nE(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, -1.23f);

	TestCodeTearDown();
}

void setInputSIn_lessValdouble_nE(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, -1.24f);

	TestCodeTearDown();
}

void setInputDIn_off_bigValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.23f);
	addDeviceControlInstructionToDouble(0, (uint8)in, 50, 1.22f);

	TestCodeTearDown();
}

void setInputDIn_off_sameValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.23f);
	addDeviceControlInstructionToDouble(0, (uint8)in, 50, 1.23f);

	TestCodeTearDown();
}

void setInputDIn_off_lessValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.22f);
	addDeviceControlInstructionToDouble(0, (uint8)in, 50, 1.23f);

	TestCodeTearDown();
}

void setInputDIn_on_bigValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.23f);
	addDeviceControlInstructionToDouble(0, (uint8)in, 50, 1.22f);

	TestCodeTearDown();
}

void setInputDIn_on_sameValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.23f);
	addDeviceControlInstructionToDouble(0, (uint8)in, 50, 1.23f);

	TestCodeTearDown();
}

void setInputDIn_on_lessValdouble(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.22f);
	addDeviceControlInstructionToDouble(0, (uint8)in, 50, 1.23f);

	TestCodeTearDown();
}

void setInputSIn_off_bigValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.22f);

	TestCodeTearDown();
}

void setInputSIn_on_bigValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.22f);

	TestCodeTearDown();
}


void setInputSIn_off_sameValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.23f);

	TestCodeTearDown();
}

void setInputSIn_on_sameValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.23f);

	TestCodeTearDown();
}

void setInputSIn_off_lessValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.24f);

	TestCodeTearDown();
}

void setInputSIn_on_lessValdouble_E(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDouble(0, (uint8)in, in_pos, 1.24f);

	TestCodeTearDown();
}

//test for specific test case
void test_singleCompareDouble(uint8 tno)
{
	uint8 in_reg=OPERAND_ML_CODE_D, out_reg=OPERAND_ML_CODE_Y;
	uint16 in_pos=0, out_pos=0;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int rc;

	PLC_DEVICE_Init();

	testCase[tno].setTestCode_fn(testCase[tno].ml_code, in_reg, in_pos, out_reg, out_pos );
	testCase[tno].setTestInput_fn(in_reg, in_pos, out_reg, out_pos);

	rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
	if(rc == 1)
	{
		CU_ASSERT_FALSE(rc); // run time failure
		DBG_LOGPRINT("test_no[%d]: %d command error!  in_%s[%d], out_%s[%d] expected=%d\n",
				tno, testCase[tno].ml_code, reg[in_reg], in_pos, reg[out_reg], out_pos, testCase[tno].expected);
	}
	else
	{
		rc = testCase[tno].verifyResult_fn(tno, out_reg, out_pos, testCase[tno].expected);
		if(rc == 1)
		{
			DBG_LOGPRINT("test_no[%d]: %d command error! in_%s[%d], out_%s[%d] expected=%d\n",
				tno, testCase[tno].ml_code, reg[in_reg], in_pos, reg[out_reg], out_pos, testCase[tno].expected);
		}
	}
}

static uint16 getInPos(int reg, int inx_pos)
{
	uint16 pos[3][2]={ {0,0}, {6144,4096}, {12284,8188}}; // 4 word required

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
void test_basic_compare_double(uint8 tno, uint16 dummy)
{
	int i, in=0, out=0, rc=0, olast=0;
	uint16 in_pos, out_pos;
	uint8 res_bit;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			if(out==OPERAND_ML_CODE_F) continue;

			out_pos = getOutPos(out, olast);
			for( in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getInPos(in-OPERAND_ML_CODE_D, i);

					testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
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
							test_getBit(&res_bit, out, out_pos);
							fprintf(flog, "test_no[%d]: %d command error! in_%s[%d], out_%s[%d]=%d exp=%d\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_bit, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testBasicCompareDoubleCommand(void)
{
	int index=188;
	int start, end;
	char log[] = "err_comp_double.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare double LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=9;index<13;index++)
		test_basic_compare_double(index, 0);
#else
	total_basic_comp_double_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LDEDEQ);
	end = getTestCaseNumberEnd(ML_CODE_OREDLE);

	DBG_LOGPRINT("testBasicCompareDoubleCommand: %d to %d total %d\n", start, end, total_basic_comp_double_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_compare_double(index, 0);
	}
#endif
	fclose(flog);
}
#endif
