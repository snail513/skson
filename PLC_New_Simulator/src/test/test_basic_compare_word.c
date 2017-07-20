/*
 * test_basic_calculation.c
 *
 *  Created on: Feb 2, 2015
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


void setCodeLD16x_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLD16x_K_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLD16x_nK_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeAND_OR(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeAND_OR_K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputDIn_bigVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_sameVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_lessVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_bigVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sameVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_lessVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_bigVal16_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sameVal16_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_lessVal16_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_off_bigVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_sameVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_lessVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_bigVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_sameVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_lessVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_bigVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_sameVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_off_lessVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_bigVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_sameVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_lessVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);


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
	{0, ML_CODE_LDEQ, setCodeLD16x_OUT, setInputDIn_bigVal16, verifyResultNormal,
			"LDEQ_OUT op1 > op2", 1, 0},
	{1, ML_CODE_LDEQ, setCodeLD16x_OUT, setInputDIn_sameVal16, verifyResultNormal,
			"LDEQ_OUT op1 == op2", 1, 1},
	{2, ML_CODE_LDEQ, setCodeLD16x_OUT, setInputDIn_lessVal16, verifyResultNormal,
			"LDEQ_OUT op1 < op2", 1, 0},
	{3, ML_CODE_LDEQ, setCodeLD16x_K_OUT, setInputSIn_bigVal16, verifyResultNormal,
			"LDEQ_OUT op1 > K", 1, 0},
	{4, ML_CODE_LDEQ, setCodeLD16x_K_OUT, setInputSIn_sameVal16, verifyResultNormal,
			"LDEQ_OUT op1 == K", 1, 1},
	{5, ML_CODE_LDEQ, setCodeLD16x_K_OUT, setInputSIn_lessVal16, verifyResultNormal,
			"LDEQ_OUT op1 < K", 1, 0},
	{6, ML_CODE_LDEQ, setCodeLD16x_nK_OUT, setInputSIn_bigVal16_nK, verifyResultNormal,
			"LDEQ_OUT op1 > nK", 1, 0},
	{7, ML_CODE_LDEQ, setCodeLD16x_nK_OUT, setInputSIn_sameVal16_nK, verifyResultNormal,
			"LDEQ_OUT op1 == nK", 1, 1},
	{8, ML_CODE_LDEQ, setCodeLD16x_nK_OUT, setInputSIn_lessVal16_nK, verifyResultNormal,
			"LDEQ_OUT op1 < nK", 1, 0},

	{9, ML_CODE_LDNE, setCodeLD16x_OUT, setInputDIn_bigVal16, verifyResultNormal,
			"LDNE_OUT op1 > op2", 1, 1},
	{10, ML_CODE_LDNE, setCodeLD16x_OUT, setInputDIn_sameVal16, verifyResultNormal,
			"LDNE_OUT op1 == op2", 1, 0},
	{11, ML_CODE_LDNE, setCodeLD16x_OUT, setInputDIn_lessVal16, verifyResultNormal,
			"LDNE_OUT op1 < op2", 1, 1},
	{12, ML_CODE_LDNE, setCodeLD16x_K_OUT, setInputSIn_bigVal16, verifyResultNormal,
			"LDNE_OUT op1 > K", 1, 1},
	{13, ML_CODE_LDNE, setCodeLD16x_K_OUT, setInputSIn_sameVal16, verifyResultNormal,
			"LDNE_OUT op1 == K", 1, 0},
	{14, ML_CODE_LDNE, setCodeLD16x_K_OUT, setInputSIn_lessVal16, verifyResultNormal,
			"LDNE_OUT op1 < K", 1, 1},
	{15, ML_CODE_LDNE, setCodeLD16x_nK_OUT, setInputSIn_bigVal16_nK, verifyResultNormal,
			"LDNE_OUT op1 > nK", 1, 1},
	{16, ML_CODE_LDNE, setCodeLD16x_nK_OUT, setInputSIn_sameVal16_nK, verifyResultNormal,
			"LDNE_OUT op1 == nK", 1, 0},
	{17, ML_CODE_LDNE, setCodeLD16x_nK_OUT, setInputSIn_lessVal16_nK, verifyResultNormal,
			"LDNE_OUT op1 < nK", 1, 1},

	{18, ML_CODE_LDGT, setCodeLD16x_OUT, setInputDIn_bigVal16, verifyResultNormal,
			"LDGT_OUT op1 > op2", 1, 1},
	{19, ML_CODE_LDGT, setCodeLD16x_OUT, setInputDIn_sameVal16, verifyResultNormal,
			"LDGT_OUT op1 == op2", 1, 0},
	{20, ML_CODE_LDGT, setCodeLD16x_OUT, setInputDIn_lessVal16, verifyResultNormal,
			"LDGT_OUT op1 < op2", 1, 0},
	{21, ML_CODE_LDGT, setCodeLD16x_K_OUT, setInputSIn_bigVal16, verifyResultNormal,
			"LDGT_OUT op1 > K", 1, 1},
	{22, ML_CODE_LDGT, setCodeLD16x_K_OUT, setInputSIn_sameVal16, verifyResultNormal,
			"LDGT_OUT op1 == K", 1, 0},
	{23, ML_CODE_LDGT, setCodeLD16x_K_OUT, setInputSIn_lessVal16, verifyResultNormal,
			"LDGT_OUT op1 < K", 1, 0},
	{24, ML_CODE_LDGT, setCodeLD16x_nK_OUT, setInputSIn_bigVal16_nK, verifyResultNormal,
			"LDGT_OUT op1 > nK", 1, 1},
	{25, ML_CODE_LDGT, setCodeLD16x_nK_OUT, setInputSIn_sameVal16_nK, verifyResultNormal,
			"LDGT_OUT op1 == nK", 1, 0},
	{26, ML_CODE_LDGT, setCodeLD16x_nK_OUT, setInputSIn_lessVal16_nK, verifyResultNormal,
			"LDGT_OUT op1 < nK", 1, 0},

	{27, ML_CODE_LDGE, setCodeLD16x_OUT, setInputDIn_bigVal16, verifyResultNormal,
			"LDGE_OUT op1 > op2", 1, 1},
	{28, ML_CODE_LDGE, setCodeLD16x_OUT, setInputDIn_sameVal16, verifyResultNormal,
			"LDGE_OUT op1 == op2", 1, 1},
	{29, ML_CODE_LDGE, setCodeLD16x_OUT, setInputDIn_lessVal16, verifyResultNormal,
			"LDGE_OUT op1 < op2", 1, 0},
	{30, ML_CODE_LDGE, setCodeLD16x_K_OUT, setInputSIn_bigVal16, verifyResultNormal,
			"LDGE_OUT op1 > K", 1, 1},
	{31, ML_CODE_LDGE, setCodeLD16x_K_OUT, setInputSIn_sameVal16, verifyResultNormal,
			"LDGE_OUT op1 == K", 1, 1},
	{32, ML_CODE_LDGE, setCodeLD16x_K_OUT, setInputSIn_lessVal16, verifyResultNormal,
			"LDGE_OUT op1 < K", 1, 0},
	{33, ML_CODE_LDGE, setCodeLD16x_nK_OUT, setInputSIn_bigVal16_nK, verifyResultNormal,
			"LDGE_OUT op1 > nK", 1, 1},
	{34, ML_CODE_LDGE, setCodeLD16x_nK_OUT, setInputSIn_sameVal16_nK, verifyResultNormal,
			"LDGE_OUT op1 == nK", 1, 1},
	{35, ML_CODE_LDGE, setCodeLD16x_nK_OUT, setInputSIn_lessVal16_nK, verifyResultNormal,
			"LDGE_OUT op1 < nK", 1, 0},

	{36, ML_CODE_LDLT, setCodeLD16x_OUT, setInputDIn_bigVal16, verifyResultNormal,
			"LDLT_OUT op1 > op2", 1, 0},
	{37, ML_CODE_LDLT, setCodeLD16x_OUT, setInputDIn_sameVal16, verifyResultNormal,
			"LDLT_OUT op1 == op2", 1, 0},
	{38, ML_CODE_LDLT, setCodeLD16x_OUT, setInputDIn_lessVal16, verifyResultNormal,
			"LDLT_OUT op1 < op2", 1, 1},
	{39, ML_CODE_LDLT, setCodeLD16x_K_OUT, setInputSIn_bigVal16, verifyResultNormal,
			"LDLT_OUT op1 > K", 1, 0},
	{40, ML_CODE_LDLT, setCodeLD16x_K_OUT, setInputSIn_sameVal16, verifyResultNormal,
			"LDLT_OUT op1 == K", 1, 0},
	{41, ML_CODE_LDLT, setCodeLD16x_K_OUT, setInputSIn_lessVal16, verifyResultNormal,
			"LDLT_OUT op1 < K", 1, 1},
	{42, ML_CODE_LDLT, setCodeLD16x_nK_OUT, setInputSIn_bigVal16_nK, verifyResultNormal,
			"LDLT_OUT op1 > nK", 1, 0},
	{43, ML_CODE_LDLT, setCodeLD16x_nK_OUT, setInputSIn_sameVal16_nK, verifyResultNormal,
			"LDLT_OUT op1 == nK", 1, 0},
	{44, ML_CODE_LDLT, setCodeLD16x_nK_OUT, setInputSIn_lessVal16_nK, verifyResultNormal,
			"LDLT_OUT op1 < nK", 1, 1},

	{45, ML_CODE_LDLE, setCodeLD16x_OUT, setInputDIn_bigVal16, verifyResultNormal,
			"LDLE_OUT op1 > op2", 1, 0},
	{46, ML_CODE_LDLE, setCodeLD16x_OUT, setInputDIn_sameVal16, verifyResultNormal,
			"LDLE_OUT op1 == op2", 1, 1},
	{47, ML_CODE_LDLE, setCodeLD16x_OUT, setInputDIn_lessVal16, verifyResultNormal,
			"LDLE_OUT op1 < op2", 1, 1},
	{48, ML_CODE_LDLE, setCodeLD16x_K_OUT, setInputSIn_bigVal16, verifyResultNormal,
			"LDLE_OUT op1 > K", 1, 0},
	{49, ML_CODE_LDLE, setCodeLD16x_K_OUT, setInputSIn_sameVal16, verifyResultNormal,
			"LDLE_OUT op1 == K", 1, 1},
	{50, ML_CODE_LDLE, setCodeLD16x_K_OUT, setInputSIn_lessVal16, verifyResultNormal,
			"LDLE_OUT op1 < K", 1, 1},
	{51, ML_CODE_LDLE, setCodeLD16x_nK_OUT, setInputSIn_bigVal16_nK, verifyResultNormal,
			"LDLE_OUT op1 > nK", 1, 0},
	{52, ML_CODE_LDLE, setCodeLD16x_nK_OUT, setInputSIn_sameVal16_nK, verifyResultNormal,
			"LDLE_OUT op1 < nK", 1, 1},
	{53, ML_CODE_LDLE, setCodeLD16x_nK_OUT, setInputSIn_lessVal16_nK, verifyResultNormal,
			"LDLE_OUT op1 < nK", 1, 1},

	{54, ML_CODE_ANDEQ, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ANDEQ_OUT off S > D", 1, 0},
	{55, ML_CODE_ANDEQ, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ANDEQ_OUT off S = D", 1, 0},
	{56, ML_CODE_ANDEQ, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ANDEQ_OUT off S < D", 1, 0},
	{57, ML_CODE_ANDEQ, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ANDEQ_OUT on S > D", 1, 0},
	{58, ML_CODE_ANDEQ, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ANDEQ_OUT on S = D", 1, 1},
	{59, ML_CODE_ANDEQ, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ANDEQ_OUT on S < D", 1, 0},
	{60, ML_CODE_ANDEQ, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ANDEQ_OUT off K > D", 1, 0},
	{61, ML_CODE_ANDEQ, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ANDEQ_OUT off K = D", 1, 0},
	{62, ML_CODE_ANDEQ, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ANDEQ_OUT off K < D", 1, 0},
	{63, ML_CODE_ANDEQ, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ANDEQ_OUT on K > D", 1, 0},
	{64, ML_CODE_ANDEQ, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ANDEQ_OUT on K = D", 1, 1},
	{65, ML_CODE_ANDEQ, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ANDEQ_OUT on K < D", 1, 0},

	{66, ML_CODE_ANDNE, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ANDNE_OUT off S > D", 1, 0},
	{67, ML_CODE_ANDNE, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ANDNE_OUT off S = D", 1, 0},
	{68, ML_CODE_ANDNE, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ANDNE_OUT off S < D", 1, 0},
	{69, ML_CODE_ANDNE, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ANDNE_OUT on S > D", 1, 1},
	{70, ML_CODE_ANDNE, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ANDNE_OUT on S = D", 1, 0},
	{71, ML_CODE_ANDNE, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ANDNE_OUT on S < D", 1, 1},
	{72, ML_CODE_ANDNE, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ANDNE_OUT off K > D", 1, 0},
	{73, ML_CODE_ANDNE, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ANDNE_OUT off K = D", 1, 0},
	{74, ML_CODE_ANDNE, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ANDNE_OUT off K < D", 1, 0},
	{75, ML_CODE_ANDNE, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ANDNE_OUT on K > D", 1, 1},
	{76, ML_CODE_ANDNE, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ANDNE_OUT on K = D", 1, 0},
	{77, ML_CODE_ANDNE, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ANDNE_OUT on K < D", 1, 1},

	{78, ML_CODE_ANDGT, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ANDGT_OUT off S > D", 1, 0},
	{79, ML_CODE_ANDGT, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ANDGT_OUT off S = D", 1, 0},
	{80, ML_CODE_ANDGT, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ANDGT_OUT off S < D", 1, 0},
	{81, ML_CODE_ANDGT, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ANDGT_OUT on S > D", 1, 1},
	{82, ML_CODE_ANDGT, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ANDGT_OUT on S = D", 1, 0},
	{83, ML_CODE_ANDGT, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ANDGT_OUT on S < D", 1, 0},
	{84, ML_CODE_ANDGT, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ANDGT_OUT off K > D", 1, 0},
	{85, ML_CODE_ANDGT, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ANDGT_OUT off K = D", 1, 0},
	{86, ML_CODE_ANDGT, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ANDGT_OUT off K < D", 1, 0},
	{87, ML_CODE_ANDGT, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ANDGT_OUT on K > D", 1, 1},
	{88, ML_CODE_ANDGT, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ANDGT_OUT on K = D", 1, 0},
	{89, ML_CODE_ANDGT, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ANDGT_OUT on K < D", 1, 0},

	{90, ML_CODE_ANDGE, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ANDGE_OUT off S > D", 1, 0},
	{91, ML_CODE_ANDGE, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ANDGE_OUT off S = D", 1, 0},
	{92, ML_CODE_ANDGE, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ANDGE_OUT off S < D", 1, 0},
	{93, ML_CODE_ANDGE, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ANDGE_OUT on S > D", 1, 1},
	{94, ML_CODE_ANDGE, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ANDGE_OUT on S = D", 1, 1},
	{95, ML_CODE_ANDGE, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ANDGE_OUT on S < D", 1, 0},
	{96, ML_CODE_ANDGE, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ANDGE_OUT off K > D", 1, 0},
	{97, ML_CODE_ANDGE, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ANDGE_OUT off K = D", 1, 0},
	{98, ML_CODE_ANDGE, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ANDGE_OUT off K < D", 1, 0},
	{99, ML_CODE_ANDGE, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ANDGE_OUT on K > D", 1, 1},
	{100, ML_CODE_ANDGE, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ANDGE_OUT on K = D", 1, 1},
	{101, ML_CODE_ANDGE, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ANDGE_OUT on K < D", 1, 0},

	{102, ML_CODE_ANDLT, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ANDLT_OUT off S > D", 1, 0},
	{103, ML_CODE_ANDLT, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ANDLT_OUT off S = D", 1, 0},
	{104, ML_CODE_ANDLT, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ANDLT_OUT off S < D", 1, 0},
	{105, ML_CODE_ANDLT, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ANDLT_OUT on S > D", 1, 0},
	{106, ML_CODE_ANDLT, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ANDLT_OUT on S = D", 1, 0},
	{107, ML_CODE_ANDLT, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ANDLT_OUT on S < D", 1, 1},
	{108, ML_CODE_ANDLT, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ANDLT_OUT off K > D", 1, 0},
	{109, ML_CODE_ANDLT, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ANDLT_OUT off K = D", 1, 0},
	{110, ML_CODE_ANDLT, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ANDLT_OUT off K < D", 1, 0},
	{111, ML_CODE_ANDLT, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ANDLT_OUT on K > D", 1, 0},
	{112, ML_CODE_ANDLT, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ANDLT_OUT on K = D", 1, 0},
	{113, ML_CODE_ANDLT, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ANDLT_OUT on K < D", 1, 1},

	{114, ML_CODE_ANDLE, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ANDLE_OUT off S > D", 1, 0},
	{115, ML_CODE_ANDLE, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ANDLE_OUT off S = D", 1, 0},
	{116, ML_CODE_ANDLE, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ANDLE_OUT off S < D", 1, 0},
	{117, ML_CODE_ANDLE, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ANDLE_OUT on S > D", 1, 0},
	{118, ML_CODE_ANDLE, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ANDLE_OUT on S = D", 1, 1},
	{119, ML_CODE_ANDLE, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ANDLE_OUT on S < D", 1, 1},
	{120, ML_CODE_ANDLE, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ANDLE_OUT off K > D", 1, 0},
	{121, ML_CODE_ANDLE, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ANDLE_OUT off K = D", 1, 0},
	{122, ML_CODE_ANDLE, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ANDLE_OUT off K < D", 1, 0},
	{123, ML_CODE_ANDLE, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ANDLE_OUT on K > D", 1, 0},
	{124, ML_CODE_ANDLE, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ANDLE_OUT on K = D", 1, 1},
	{125, ML_CODE_ANDLE, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ANDLE_OUT on K < D", 1, 1},

	{126, ML_CODE_OREQ, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"OREQ_OUT off S > D", 1, 0},
	{127, ML_CODE_OREQ, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"OREQ_OUT off S = D", 1, 1},
	{128, ML_CODE_OREQ, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"OREQ_OUT off S < D", 1, 0},
	{129, ML_CODE_OREQ, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"OREQ_OUT on S > D", 1, 1},
	{130, ML_CODE_OREQ, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"OREQ_OUT on S = D", 1, 1},
	{131, ML_CODE_OREQ, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"OREQ_OUT on S < D", 1, 1},
	{132, ML_CODE_OREQ, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"OREQ_OUT off K > D", 1, 0},
	{133, ML_CODE_OREQ, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"OREQ_OUT off K = D", 1, 1},
	{134, ML_CODE_OREQ, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"OREQ_OUT off K < D", 1, 0},
	{135, ML_CODE_OREQ, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"OREQ_OUT on K > D", 1, 1},
	{136, ML_CODE_OREQ, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"OREQ_OUT on K = D", 1, 1},
	{137, ML_CODE_OREQ, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"OREQ_OUT on K < D", 1, 1},

	{138, ML_CODE_ORNE, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ORNE_OUT off S > D", 1, 1},
	{139, ML_CODE_ORNE, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ORNE_OUT off S = D", 1, 0},
	{140, ML_CODE_ORNE, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ORNE_OUT off S < D", 1, 1},
	{141, ML_CODE_ORNE, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ORNE_OUT on S > D", 1, 1},
	{142, ML_CODE_ORNE, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ORNE_OUT on S = D", 1, 1},
	{143, ML_CODE_ORNE, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ORNE_OUT on S < D", 1, 1},
	{144, ML_CODE_ORNE, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ORNE_OUT off K > D", 1, 1},
	{145, ML_CODE_ORNE, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ORNE_OUT off K = D", 1, 0},
	{146, ML_CODE_ORNE, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ORNE_OUT off K < D", 1, 1},
	{147, ML_CODE_ORNE, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ORNE_OUT on K > D", 1, 1},
	{148, ML_CODE_ORNE, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ORNE_OUT on K = D", 1, 1},
	{149, ML_CODE_ORNE, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ORNE_OUT on K < D", 1, 1},

	{150, ML_CODE_ORGT, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ORGT_OUT off S > D", 1, 1},
	{151, ML_CODE_ORGT, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ORGT_OUT off S = D", 1, 0},
	{152, ML_CODE_ORGT, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ORGT_OUT off S < D", 1, 0},
	{153, ML_CODE_ORGT, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ORGT_OUT on S > D", 1, 1},
	{154, ML_CODE_ORGT, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ORGT_OUT on S = D", 1, 1},
	{155, ML_CODE_ORGT, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ORGT_OUT on S < D", 1, 1},
	{156, ML_CODE_ORGT, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ORGT_OUT off K > D", 1, 1},
	{157, ML_CODE_ORGT, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ORGT_OUT off K = D", 1, 0},
	{158, ML_CODE_ORGT, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ORGT_OUT off K < D", 1, 0},
	{159, ML_CODE_ORGT, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ORGT_OUT on K > D", 1, 1},
	{160, ML_CODE_ORGT, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ORGT_OUT on K = D", 1, 1},
	{161, ML_CODE_ORGT, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ORGT_OUT on K < D", 1, 1},

	{162, ML_CODE_ORGE, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ORGE_OUT off S > D", 1, 1},
	{163, ML_CODE_ORGE, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ORGE_OUT off S = D", 1, 1},
	{164, ML_CODE_ORGE, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ORGE_OUT off S < D", 1, 0},
	{165, ML_CODE_ORGE, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ORGE_OUT on S > D", 1, 1},
	{166, ML_CODE_ORGE, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ORGE_OUT on S = D", 1, 1},
	{167, ML_CODE_ORGE, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ORGE_OUT on S < D", 1, 1},
	{168, ML_CODE_ORGE, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ORGE_OUT off K > D", 1, 1},
	{169, ML_CODE_ORGE, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ORGE_OUT off K = D", 1, 1},
	{170, ML_CODE_ORGE, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ORGE_OUT off K < D", 1, 0},
	{171, ML_CODE_ORGE, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ORGE_OUT on K > D", 1, 1},
	{172, ML_CODE_ORGE, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ORGE_OUT on K = D", 1, 1},
	{173, ML_CODE_ORGE, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ORGE_OUT on K < D", 1, 1},

	{174, ML_CODE_ORLT, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ORLT_OUT off S > D", 1, 0},
	{175, ML_CODE_ORLT, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ORLT_OUT off S = D", 1, 0},
	{176, ML_CODE_ORLT, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ORLT_OUT off S < D", 1, 1},
	{177, ML_CODE_ORLT, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ORLT_OUT on S > D", 1, 1},
	{178, ML_CODE_ORLT, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ORLT_OUT on S = D", 1, 1},
	{179, ML_CODE_ORLT, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ORLT_OUT on S < D", 1, 1},
	{180, ML_CODE_ORLT, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ORLT_OUT off K > D", 1, 0},
	{181, ML_CODE_ORLT, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ORLT_OUT off K = D", 1, 0},
	{182, ML_CODE_ORLT, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ORLT_OUT off K < D", 1, 1},
	{183, ML_CODE_ORLT, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ORLT_OUT on K > D", 1, 1},
	{184, ML_CODE_ORLT, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ORLT_OUT on K = D", 1, 1},
	{185, ML_CODE_ORLT, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ORLT_OUT on K < D", 1, 1},

	{186, ML_CODE_ORLE, setCodeAND_OR, setInputDIn_off_bigVal16, verifyResultNormal,
			"ORLE_OUT off S > D", 1, 0},
	{187, ML_CODE_ORLE, setCodeAND_OR, setInputDIn_off_sameVal16, verifyResultNormal,
			"ORLE_OUT off S = D", 1, 1},
	{188, ML_CODE_ORLE, setCodeAND_OR, setInputDIn_off_lessVal16, verifyResultNormal,
			"ORLE_OUT off S < D", 1, 1},
	{189, ML_CODE_ORLE, setCodeAND_OR, setInputDIn_on_bigVal16, verifyResultNormal,
			"ORLE_OUT on S > D", 1, 1},
	{190, ML_CODE_ORLE, setCodeAND_OR, setInputDIn_on_sameVal16, verifyResultNormal,
			"ORLE_OUT on S = D", 1, 1},
	{191, ML_CODE_ORLE, setCodeAND_OR, setInputDIn_on_lessVal16, verifyResultNormal,
			"ORLE_OUT on S < D", 1, 1},
	{192, ML_CODE_ORLE, setCodeAND_OR_K, setInputSIn_off_bigVal16_K, verifyResultNormal,
			"ORLE_OUT off K > D", 1, 0},
	{193, ML_CODE_ORLE, setCodeAND_OR_K, setInputSIn_off_sameVal16_K, verifyResultNormal,
			"ORLE_OUT off K = D", 1, 1},
	{194, ML_CODE_ORLE, setCodeAND_OR_K, setInputSIn_off_lessVal16_K, verifyResultNormal,
			"ORLE_OUT off K < D", 1, 1},
	{195, ML_CODE_ORLE, setCodeAND_OR_K, setInputSIn_on_bigVal16_K, verifyResultNormal,
			"ORLE_OUT on K > D", 1, 1},
	{197, ML_CODE_ORLE, setCodeAND_OR_K, setInputSIn_on_sameVal16_K, verifyResultNormal,
			"ORLE_OUT on K = D", 1, 1},
	{198, ML_CODE_ORLE, setCodeAND_OR_K, setInputSIn_on_lessVal16_K, verifyResultNormal,
			"ORLE_OUT on K < D", 1, 1},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};

int total_basic_comp_word_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_comp_word_test_number; i++)
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

//compare with 16bit registers
void setCodeLD16x_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 20);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}
//compare with 16bit constant
void setCodeLD16x_K_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_K, 257);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}
//compare with 16bit negative constant
void setCodeLD16x_nK_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_K, -257);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeAND_OR(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 50);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeAND_OR_K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 256); addMLOperand(in_reg, in_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setInputDIn_bigVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257); // compare 10 and 20
	addDeviceControlInstruction(0, (uint8)in, 20, 256);

	TestCodeTearDown();
}

void setInputDIn_sameVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257); // compare 10 and 20
	addDeviceControlInstruction(0, (uint8)in, 20, 257);

	TestCodeTearDown();
}

void setInputDIn_lessVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 256); // compare 10 and 20
	addDeviceControlInstruction(0, (uint8)in, 20, 257);

	TestCodeTearDown();
}

void setInputSIn_bigVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 258);

	TestCodeTearDown();
}

void setInputSIn_sameVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_lessVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 256);

	TestCodeTearDown();
}

void setInputSIn_bigVal16_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, -256);

	TestCodeTearDown();
}

void setInputSIn_sameVal16_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, -257);

	TestCodeTearDown();
}

void setInputSIn_lessVal16_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, -258);

	TestCodeTearDown();
}

void setInputDIn_off_bigVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);
	addDeviceControlInstruction(0, (uint8)in, 50, 256);

	TestCodeTearDown();
}

void setInputDIn_off_sameVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);
	addDeviceControlInstruction(0, (uint8)in, 50, 257);

	TestCodeTearDown();
}

void setInputDIn_off_lessVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 256);
	addDeviceControlInstruction(0, (uint8)in, 50, 257);

	TestCodeTearDown();
}

void setInputDIn_on_bigVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);
	addDeviceControlInstruction(0, (uint8)in, 50, 256);

	TestCodeTearDown();
}

void setInputDIn_on_sameVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);
	addDeviceControlInstruction(0, (uint8)in, 50, 257);

	TestCodeTearDown();
}

void setInputDIn_on_lessVal16(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 256);
	addDeviceControlInstruction(0, (uint8)in, 50, 257);

	TestCodeTearDown();
}

void setInputSIn_off_bigVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 255);

	TestCodeTearDown();
}

void setInputSIn_on_bigVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 255);

	TestCodeTearDown();
}


void setInputSIn_off_sameVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 256);

	TestCodeTearDown();
}

void setInputSIn_on_sameVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 256);

	TestCodeTearDown();
}

void setInputSIn_off_lessVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_on_lessVal16_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

//test for specific test case
void test_singleCompareWord(int tno)
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
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12287,8191}};

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
void test_basic_compare_word(int tno, uint16 dummy)
{
	int i, rc=0, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=0;
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
						fprintf(flog, "test_no[%d]: %s runtime error!\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName);
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

void testBasicCompareWordCommand(void)
{
	int index=0;
	int start, end;
	char log[] = "err_comp_word.txt";

#if 0
	//for(index=0; index<10; index++)
		test_basic_compare_word(index, 0);
#else
	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare word LOG file open error !\n");
		exit(1);
	}

	total_basic_comp_word_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LDEQ);
	end = getTestCaseNumberEnd(ML_CODE_ORLE);

	DBG_LOGPRINT("testBasicCompareWordCommand: %d to %d total %d\n", start, end, total_basic_comp_word_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_compare_word(index, 0);
	}

	fclose(flog);
#endif
}

#endif //USE_CUNIT_DEF
