/*
 * test_basic_compare_dword.c
 *
 *  Created on: Feb 16, 2015
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

void setCodeLD32x_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);;
void setCodeLD32x_K_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);;
void setCodeLD32x_nK_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);;
void setCodeAND_OR_32x(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeAND_OR_32x_K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputDIn_hbigVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_hlessVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_lbigVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_llessVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_sameVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_hbigVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_lbigVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_hlessVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_llessVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sameVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_hbigVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_lbigVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_hlessVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_llessVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sameVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_hbigVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_hlessVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_lbigVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_llessVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_sameVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_hbigVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_hlessVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_lbigVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_llessVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_sameVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_hbigVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_hlessVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_lbigVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_llessVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sameVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_hbigVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_lbigVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_hlessVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_llessVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sameVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

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
	{0, ML_CODE_LDDEQ, setCodeLD32x_OUT, setInputDIn_hbigVal32, verifyResultNormal,
			"LDDEQ_OUT high op1 > op2", 1, 0 },
	{1, ML_CODE_LDDEQ, setCodeLD32x_OUT, setInputDIn_lbigVal32, verifyResultNormal,
			"LDDEQ_OUT low op1 > op2", 1, 0 },
	{2, ML_CODE_LDDEQ, setCodeLD32x_OUT, setInputDIn_hlessVal32, verifyResultNormal,
			"LDDEQ_OUT high op1 < op2", 1, 0 },
	{3, ML_CODE_LDDEQ, setCodeLD32x_OUT, setInputDIn_llessVal32, verifyResultNormal,
			"LDDEQ_OUT low op1 < op2", 1, 0 },
	{4, ML_CODE_LDDEQ, setCodeLD32x_OUT, setInputDIn_sameVal32, verifyResultNormal,
			"LDDEQ_OUT op1 == op2", 1, 1},
	{5, ML_CODE_LDDEQ, setCodeLD32x_K_OUT, setInputSIn_hbigVal32_K, verifyResultNormal,
			"LDDEQ_OUT high op1 > K", 1, 0},
	{6, ML_CODE_LDDEQ, setCodeLD32x_K_OUT, setInputSIn_lbigVal32_K, verifyResultNormal,
			"LDDEQ_OUT low op1 > K", 1, 0},
	{7, ML_CODE_LDDEQ, setCodeLD32x_K_OUT, setInputSIn_hlessVal32_K, verifyResultNormal,
			"LDDEQ_OUT high op1 < K", 1, 0},
	{8, ML_CODE_LDDEQ, setCodeLD32x_K_OUT, setInputSIn_llessVal32_K, verifyResultNormal,
			"LDDEQ_OUT low op1 < K", 1, 0},
	{9, ML_CODE_LDDEQ, setCodeLD32x_K_OUT, setInputSIn_sameVal32_K, verifyResultNormal,
			"LDDEQ_OUT op1 == K", 1, 1},
	{10, ML_CODE_LDDEQ, setCodeLD32x_nK_OUT, setInputSIn_hbigVal32_nK, verifyResultNormal,
			"LDDEQ_OUT high op1 > nK", 1, 0},
	{11, ML_CODE_LDDEQ, setCodeLD32x_nK_OUT, setInputSIn_lbigVal32_nK, verifyResultNormal,
			"LDDEQ_OUT low op1 > nK", 1, 0},
	{12, ML_CODE_LDDEQ, setCodeLD32x_nK_OUT, setInputSIn_hlessVal32_nK, verifyResultNormal,
			"LDDEQ_OUT high op1 < nK", 1, 0},
	{13, ML_CODE_LDDEQ, setCodeLD32x_nK_OUT, setInputSIn_llessVal32_nK, verifyResultNormal,
			"LDDEQ_OUT low op1 < nK", 1, 0},
	{14, ML_CODE_LDDEQ, setCodeLD32x_nK_OUT, setInputSIn_sameVal32_nK, verifyResultNormal,
			"LDDEQ_OUT op1 == nK", 1, 1},

	{15, ML_CODE_LDDNE, setCodeLD32x_OUT, setInputDIn_hbigVal32, verifyResultNormal,
			"LDDNE_OUT high op1 > op2", 1, 1 },
	{16, ML_CODE_LDDNE, setCodeLD32x_OUT, setInputDIn_lbigVal32, verifyResultNormal,
			"LDDNE_OUT low op1 > op2", 1, 1 },
	{17, ML_CODE_LDDNE, setCodeLD32x_OUT, setInputDIn_hlessVal32, verifyResultNormal,
			"LDDNE_OUT high op1 < op2", 1, 1 },
	{18, ML_CODE_LDDNE, setCodeLD32x_OUT, setInputDIn_llessVal32, verifyResultNormal,
			"LDDNE_OUT low op1 < op2", 1, 1 },
	{19, ML_CODE_LDDNE, setCodeLD32x_OUT, setInputDIn_sameVal32, verifyResultNormal,
			"LDDNE_OUT op1 == op2", 1, 0},
	{20, ML_CODE_LDDNE, setCodeLD32x_K_OUT, setInputSIn_hbigVal32_K, verifyResultNormal,
			"LDDNE_OUT high op1 > K", 1, 1},
	{21, ML_CODE_LDDNE, setCodeLD32x_K_OUT, setInputSIn_lbigVal32_K, verifyResultNormal,
			"LDDNE_OUT low op1 > K", 1, 1},
	{22, ML_CODE_LDDNE, setCodeLD32x_K_OUT, setInputSIn_hlessVal32_K, verifyResultNormal,
			"LDDNE_OUT high op1 < K", 1, 1},
	{23, ML_CODE_LDDNE, setCodeLD32x_K_OUT, setInputSIn_llessVal32_K, verifyResultNormal,
			"LDDNE_OUT low op1 < K", 1, 1},
	{24, ML_CODE_LDDNE, setCodeLD32x_K_OUT, setInputSIn_sameVal32_K, verifyResultNormal,
			"LDDNE_OUT op1 == K", 1, 0},
	{25, ML_CODE_LDDNE, setCodeLD32x_nK_OUT, setInputSIn_hbigVal32_nK, verifyResultNormal,
			"LDDNE_OUT high op1 > nK", 1, 1},
	{26, ML_CODE_LDDNE, setCodeLD32x_nK_OUT, setInputSIn_lbigVal32_nK, verifyResultNormal,
			"LDDNE_OUT low op1 > nK", 1, 1},
	{27, ML_CODE_LDDNE, setCodeLD32x_nK_OUT, setInputSIn_hlessVal32_nK, verifyResultNormal,
			"LDDNE_OUT high op1 < nK", 1, 1},
	{28, ML_CODE_LDDNE, setCodeLD32x_nK_OUT, setInputSIn_llessVal32_nK, verifyResultNormal,
			"LDDNE_OUT low op1 < nK", 1, 1},
	{29, ML_CODE_LDDNE, setCodeLD32x_nK_OUT, setInputSIn_sameVal32_nK, verifyResultNormal,
			"LDDNE_OUT op1 == nK", 1, 0},

	{30, ML_CODE_LDDGT, setCodeLD32x_OUT, setInputDIn_hbigVal32, verifyResultNormal,
			"LDDGT_OUT high op1 > op2", 1, 1 },
	{31, ML_CODE_LDDGT, setCodeLD32x_OUT, setInputDIn_lbigVal32, verifyResultNormal,
			"LDDGT_OUT low op1 > op2", 1, 1 },
	{32, ML_CODE_LDDGT, setCodeLD32x_OUT, setInputDIn_hlessVal32, verifyResultNormal,
			"LDDGT_OUT high op1 < op2", 1, 0 },
	{33, ML_CODE_LDDGT, setCodeLD32x_OUT, setInputDIn_llessVal32, verifyResultNormal,
			"LDDGT_OUT low op1 < op2", 1, 0 },
	{34, ML_CODE_LDDGT, setCodeLD32x_OUT, setInputDIn_sameVal32, verifyResultNormal,
			"LDDGT_OUT op1 == op2", 1, 0},
	{35, ML_CODE_LDDGT, setCodeLD32x_K_OUT, setInputSIn_hbigVal32_K, verifyResultNormal,
			"LDDGT_OUT high op1 > K", 1, 1},
	{36, ML_CODE_LDDGT, setCodeLD32x_K_OUT, setInputSIn_lbigVal32_K, verifyResultNormal,
			"LDDGT_OUT low op1 > K", 1, 1},
	{37, ML_CODE_LDDGT, setCodeLD32x_K_OUT, setInputSIn_hlessVal32_K, verifyResultNormal,
			"LDDGT_OUT high op1 < K", 1, 0},
	{38, ML_CODE_LDDGT, setCodeLD32x_K_OUT, setInputSIn_llessVal32_K, verifyResultNormal,
			"LDDGT_OUT low op1 < K", 1, 0},
	{39, ML_CODE_LDDGT, setCodeLD32x_K_OUT, setInputSIn_sameVal32_K, verifyResultNormal,
			"LDDGT_OUT op1 == K", 1, 0},
	{40, ML_CODE_LDDGT, setCodeLD32x_nK_OUT, setInputSIn_hbigVal32_nK, verifyResultNormal,
			"LDDGT_OUT high op1 > nK", 1, 0},
	{41, ML_CODE_LDDGT, setCodeLD32x_nK_OUT, setInputSIn_lbigVal32_nK, verifyResultNormal,
			"LDDGT_OUT low op1 > nK", 1, 0},
	{42, ML_CODE_LDDGT, setCodeLD32x_nK_OUT, setInputSIn_hlessVal32_nK, verifyResultNormal,
			"LDDGT_OUT high op1 < nK", 1, 1},
	{43, ML_CODE_LDDGT, setCodeLD32x_nK_OUT, setInputSIn_llessVal32_nK, verifyResultNormal,
			"LDDGT_OUT low op1 < nK", 1, 1},
	{44, ML_CODE_LDDGT, setCodeLD32x_nK_OUT, setInputSIn_sameVal32_nK, verifyResultNormal,
			"LDDGT_OUT op1 == nK", 1, 0},

	{45, ML_CODE_LDDGE, setCodeLD32x_OUT, setInputDIn_hbigVal32, verifyResultNormal,
			"LDDGE_OUT high op1 > op2", 1, 1 },
	{46, ML_CODE_LDDGE, setCodeLD32x_OUT, setInputDIn_lbigVal32, verifyResultNormal,
			"LDDGE_OUT low op1 > op2", 1, 1 },
	{47, ML_CODE_LDDGE, setCodeLD32x_OUT, setInputDIn_hlessVal32, verifyResultNormal,
			"LDDGE_OUT high op1 < op2", 1, 0 },
	{48, ML_CODE_LDDGE, setCodeLD32x_OUT, setInputDIn_llessVal32, verifyResultNormal,
			"LDDGE_OUT low op1 < op2", 1, 0 },
	{49, ML_CODE_LDDGE, setCodeLD32x_OUT, setInputDIn_sameVal32, verifyResultNormal,
			"LDDGE_OUT op1 == op2", 1, 1},
	{50, ML_CODE_LDDGE, setCodeLD32x_K_OUT, setInputSIn_hbigVal32_K, verifyResultNormal,
			"LDDGE_OUT high op1 > K", 1, 1},
	{51, ML_CODE_LDDGE, setCodeLD32x_K_OUT, setInputSIn_lbigVal32_K, verifyResultNormal,
			"LDDGE_OUT low op1 > K", 1, 1},
	{52, ML_CODE_LDDGE, setCodeLD32x_K_OUT, setInputSIn_hlessVal32_K, verifyResultNormal,
			"LDDGE_OUT high op1 < K", 1, 0},
	{53, ML_CODE_LDDGE, setCodeLD32x_K_OUT, setInputSIn_llessVal32_K, verifyResultNormal,
			"LDDGE_OUT low op1 < K", 1, 0},
	{54, ML_CODE_LDDGE, setCodeLD32x_K_OUT, setInputSIn_sameVal32_K, verifyResultNormal,
			"LDDGE_OUT op1 == K", 1, 1},
	{55, ML_CODE_LDDGE, setCodeLD32x_nK_OUT, setInputSIn_hbigVal32_nK, verifyResultNormal,
			"LDDGE_OUT high op1 > nK", 1, 0},
	{56, ML_CODE_LDDGE, setCodeLD32x_nK_OUT, setInputSIn_lbigVal32_nK, verifyResultNormal,
			"LDDGE_OUT low op1 > nK", 1, 0},
	{57, ML_CODE_LDDGE, setCodeLD32x_nK_OUT, setInputSIn_hlessVal32_nK, verifyResultNormal,
			"LDDGE_OUT high op1 < nK", 1, 1},
	{58, ML_CODE_LDDGE, setCodeLD32x_nK_OUT, setInputSIn_llessVal32_nK, verifyResultNormal,
			"LDDGE_OUT low op1 < nK", 1, 1},
	{59, ML_CODE_LDDGE, setCodeLD32x_nK_OUT, setInputSIn_sameVal32_nK, verifyResultNormal,
			"LDDGE_OUT op1 == nK", 1, 1},

	{60, ML_CODE_LDDLT, setCodeLD32x_OUT, setInputDIn_hbigVal32, verifyResultNormal,
			"LDDLT_OUT high op1 > op2", 1, 0 },
	{61, ML_CODE_LDDLT, setCodeLD32x_OUT, setInputDIn_lbigVal32, verifyResultNormal,
			"LDDLT_OUT low op1 > op2", 1, 0 },
	{62, ML_CODE_LDDLT, setCodeLD32x_OUT, setInputDIn_hlessVal32, verifyResultNormal,
			"LDDLT_OUT high op1 < op2", 1, 1 },
	{63, ML_CODE_LDDLT, setCodeLD32x_OUT, setInputDIn_llessVal32, verifyResultNormal,
			"LDDLT_OUT low op1 < op2", 1, 1 },
	{64, ML_CODE_LDDLT, setCodeLD32x_OUT, setInputDIn_sameVal32, verifyResultNormal,
			"LDDLT_OUT op1 == op2", 1, 0},
	{65, ML_CODE_LDDLT, setCodeLD32x_K_OUT, setInputSIn_hbigVal32_K, verifyResultNormal,
			"LDDLT_OUT high op1 > K", 1, 0},
	{66, ML_CODE_LDDLT, setCodeLD32x_K_OUT, setInputSIn_lbigVal32_K, verifyResultNormal,
			"LDDLT_OUT low op1 > K", 1, 0},
	{67, ML_CODE_LDDLT, setCodeLD32x_K_OUT, setInputSIn_hlessVal32_K, verifyResultNormal,
			"LDDLT_OUT high op1 < K", 1, 1},
	{68, ML_CODE_LDDLT, setCodeLD32x_K_OUT, setInputSIn_llessVal32_K, verifyResultNormal,
			"LDDLT_OUT low op1 < K", 1, 1},
	{69, ML_CODE_LDDLT, setCodeLD32x_K_OUT, setInputSIn_sameVal32_K, verifyResultNormal,
			"LDDLT_OUT op1 == K", 1, 0},
	{70, ML_CODE_LDDLT, setCodeLD32x_nK_OUT, setInputSIn_hbigVal32_nK, verifyResultNormal,
			"LDDLT_OUT high op1 > nK", 1, 1},
	{71, ML_CODE_LDDLT, setCodeLD32x_nK_OUT, setInputSIn_lbigVal32_nK, verifyResultNormal,
			"LDDLT_OUT low op1 > nK", 1, 1},
	{72, ML_CODE_LDDLT, setCodeLD32x_nK_OUT, setInputSIn_hlessVal32_nK, verifyResultNormal,
			"LDDLT_OUT high op1 < nK", 1, 0},
	{73, ML_CODE_LDDLT, setCodeLD32x_nK_OUT, setInputSIn_llessVal32_nK, verifyResultNormal,
			"LDDLT_OUT low op1 < nK", 1, 0},
	{74, ML_CODE_LDDLT, setCodeLD32x_nK_OUT, setInputSIn_sameVal32_nK, verifyResultNormal,
			"LDDLT_OUT op1 == nK", 1, 0},

	{75, ML_CODE_LDDLE, setCodeLD32x_OUT, setInputDIn_hbigVal32, verifyResultNormal,
			"LDDLE_OUT high op1 > op2", 1, 0 },
	{76, ML_CODE_LDDLE, setCodeLD32x_OUT, setInputDIn_lbigVal32, verifyResultNormal,
			"LDDLE_OUT low op1 > op2", 1, 0 },
	{77, ML_CODE_LDDLE, setCodeLD32x_OUT, setInputDIn_hlessVal32, verifyResultNormal,
			"LDDLE_OUT high op1 < op2", 1, 1 },
	{78, ML_CODE_LDDLE, setCodeLD32x_OUT, setInputDIn_llessVal32, verifyResultNormal,
			"LDDLE_OUT low op1 < op2", 1, 1 },
	{79, ML_CODE_LDDLE, setCodeLD32x_OUT, setInputDIn_sameVal32, verifyResultNormal,
			"LDDLE_OUT op1 == op2", 1, 1},
	{80, ML_CODE_LDDLE, setCodeLD32x_K_OUT, setInputSIn_hbigVal32_K, verifyResultNormal,
			"LDDLE_OUT high op1 > K", 1, 0},
	{81, ML_CODE_LDDLE, setCodeLD32x_K_OUT, setInputSIn_lbigVal32_K, verifyResultNormal,
			"LDDLE_OUT low op1 > K", 1, 0},
	{82, ML_CODE_LDDLE, setCodeLD32x_K_OUT, setInputSIn_hlessVal32_K, verifyResultNormal,
			"LDDLE_OUT high op1 < K", 1, 1},
	{83, ML_CODE_LDDLE, setCodeLD32x_K_OUT, setInputSIn_llessVal32_K, verifyResultNormal,
			"LDDLE_OUT low op1 < K", 1, 1},
	{84, ML_CODE_LDDLE, setCodeLD32x_K_OUT, setInputSIn_sameVal32_K, verifyResultNormal,
			"LDDLE_OUT op1 == K", 1, 1},
	{85, ML_CODE_LDDLE, setCodeLD32x_nK_OUT, setInputSIn_hbigVal32_nK, verifyResultNormal,
			"LDDLE_OUT high op1 > nK", 1, 1},
	{86, ML_CODE_LDDLE, setCodeLD32x_nK_OUT, setInputSIn_lbigVal32_nK, verifyResultNormal,
			"LDDLE_OUT low op1 > nK", 1, 1},
	{87, ML_CODE_LDDLE, setCodeLD32x_nK_OUT, setInputSIn_hlessVal32_nK, verifyResultNormal,
			"LDDLE_OUT high op1 < nK", 1, 0},
	{88, ML_CODE_LDDLE, setCodeLD32x_nK_OUT, setInputSIn_llessVal32_nK, verifyResultNormal,
			"LDDLE_OUT low op1 < nK", 1, 0},
	{89, ML_CODE_LDDLE, setCodeLD32x_nK_OUT, setInputSIn_sameVal32_nK, verifyResultNormal,
			"LDDLE_OUT op1 == nK", 1, 1},

	{90, ML_CODE_ANDDEQ, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1 > op2", 1, 0 },
	{91, ML_CODE_ANDDEQ, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1 < op2", 1, 0 },
	{92, ML_CODE_ANDDEQ, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ANDDEQ_OUT off op1 == op2", 1, 0 },
	{93, ML_CODE_ANDDEQ, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high op1 > op2", 1, 0 },
	{94, ML_CODE_ANDDEQ, setCodeAND_OR_32x, setInputDIn_lbigVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low op1 > op2", 1, 0 },
	{95, ML_CODE_ANDDEQ, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT high op1 < op2", 1, 0 },
	{96, ML_CODE_ANDDEQ, setCodeAND_OR_32x, setInputDIn_llessVal32_on, verifyResultNormal,
			"ANDDEQ_OUT low op1 < op2", 1, 0 },
	{97, ML_CODE_ANDDEQ, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ANDDEQ_OUT op1 == op2", 1, 1},
	{98, ML_CODE_ANDDEQ, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ANDDEQ_OUT high op1 > K", 1, 0},
	{99, ML_CODE_ANDDEQ, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ANDDEQ_OUT high op1 < K", 1, 0},
	{100, ML_CODE_ANDDEQ, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ANDDEQ_OUT op1 == K", 1, 0},
	{101, ML_CODE_ANDDEQ, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ANDDEQ_OUT high op1 > K", 1, 0},
	{102, ML_CODE_ANDDEQ, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_on, verifyResultNormal,
			"ANDDEQ_OUT low op1 > K", 1, 0},
	{103, ML_CODE_ANDDEQ, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ANDDEQ_OUT high op1 < K", 1, 0},
	{104, ML_CODE_ANDDEQ, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_on, verifyResultNormal,
			"ANDDEQ_OUT low op1 < K", 1, 0},
	{105, ML_CODE_ANDDEQ, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ANDDEQ_OUT op1 == K", 1, 1},

	{106, ML_CODE_ANDDNE, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1 > op2", 1, 0 },
	{107, ML_CODE_ANDDNE, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1 < op2", 1, 0 },
	{108, ML_CODE_ANDDNE, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ANDDNE_OUT off op1 == op2", 1, 0 },
	{109, ML_CODE_ANDDNE, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT high op1 > op2", 1, 1 },
	{110, ML_CODE_ANDDNE, setCodeAND_OR_32x, setInputDIn_lbigVal32_on, verifyResultNormal,
			"ANDDNE_OUT low op1 > op2", 1, 1 },
	{111, ML_CODE_ANDDNE, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ANDDNE_OUT high op1 < op2", 1, 1 },
	{112, ML_CODE_ANDDNE, setCodeAND_OR_32x, setInputDIn_llessVal32_on, verifyResultNormal,
			"ANDDNE_OUT low op1 < op2", 1, 1 },
	{113, ML_CODE_ANDDNE, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ANDDNE_OUT op1 == op2", 1, 0},
	{114, ML_CODE_ANDDNE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ANDDNE_OUT high op1 > K", 1, 0},
	{115, ML_CODE_ANDDNE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ANDDNE_OUT high op1 < K", 1, 0},
	{116, ML_CODE_ANDDNE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ANDDNE_OUT op1 == K", 1, 0},
	{117, ML_CODE_ANDDNE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ANDDNE_OUT high op1 > K", 1, 1},
	{118, ML_CODE_ANDDNE, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_on, verifyResultNormal,
			"ANDDNE_OUT low op1 > K", 1, 1},
	{119, ML_CODE_ANDDNE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ANDDNE_OUT high op1 < K", 1, 1},
	{120, ML_CODE_ANDDNE, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_on, verifyResultNormal,
			"ANDDNE_OUT low op1 < K", 1, 1},
	{121, ML_CODE_ANDDNE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ANDDNE_OUT op1 == K", 1, 0},

	{122, ML_CODE_ANDDGT, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1 > op2", 1, 0 },
	{123, ML_CODE_ANDDGT, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1 < op2", 1, 0 },
	{124, ML_CODE_ANDDGT, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ANDDGT_OUT off op1 == op2", 1, 0 },
	{125, ML_CODE_ANDDGT, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT high op1 > op2", 1, 1 },
	{126, ML_CODE_ANDDGT, setCodeAND_OR_32x, setInputDIn_lbigVal32_on, verifyResultNormal,
			"ANDDGT_OUT low op1 > op2", 1, 1 },
	{127, ML_CODE_ANDDGT, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ANDDGT_OUT high op1 < op2", 1, 0 },
	{128, ML_CODE_ANDDGT, setCodeAND_OR_32x, setInputDIn_llessVal32_on, verifyResultNormal,
			"ANDDGT_OUT low op1 < op2", 1, 0 },
	{129, ML_CODE_ANDDGT, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ANDDGT_OUT op1 == op2", 1, 0},
	{130, ML_CODE_ANDDGT, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ANDDGT_OUT high op1 > K", 1, 0},
	{131, ML_CODE_ANDDGT, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ANDDGT_OUT high op1 < K", 1, 0},
	{132, ML_CODE_ANDDGT, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ANDDGT_OUT op1 == K", 1, 0},
	{133, ML_CODE_ANDDGT, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ANDDGT_OUT high op1 > K", 1, 1},
	{134, ML_CODE_ANDDGT, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_on, verifyResultNormal,
			"ANDDGT_OUT low op1 > K", 1, 1},
	{135, ML_CODE_ANDDGT, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ANDDGT_OUT high op1 < K", 1, 0},
	{136, ML_CODE_ANDDGT, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_on, verifyResultNormal,
			"ANDDGT_OUT low op1 < K", 1, 0},
	{137, ML_CODE_ANDDGT, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ANDDGT_OUT op1 == K", 1, 0},

	{138, ML_CODE_ANDDGE, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1 > op2", 1, 0 },
	{139, ML_CODE_ANDDGE, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1 < op2", 1, 0 },
	{140, ML_CODE_ANDDGE, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ANDDGE_OUT off op1 == op2", 1, 0 },
	{141, ML_CODE_ANDDGE, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT high op1 > op2", 1, 1 },
	{142, ML_CODE_ANDDGE, setCodeAND_OR_32x, setInputDIn_lbigVal32_on, verifyResultNormal,
			"ANDDGE_OUT low op1 > op2", 1, 1 },
	{143, ML_CODE_ANDDGE, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ANDDGE_OUT high op1 < op2", 1, 0 },
	{144, ML_CODE_ANDDGE, setCodeAND_OR_32x, setInputDIn_llessVal32_on, verifyResultNormal,
			"ANDDGE_OUT low op1 < op2", 1, 0 },
	{145, ML_CODE_ANDDGE, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ANDDGE_OUT op1 == op2", 1, 1},
	{146, ML_CODE_ANDDGE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ANDDGE_OUT high op1 > K", 1, 0},
	{147, ML_CODE_ANDDGE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ANDDGE_OUT high op1 < K", 1, 0},
	{148, ML_CODE_ANDDGE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ANDDGE_OUT op1 == K", 1, 0},
	{149, ML_CODE_ANDDGE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ANDDGE_OUT high op1 > K", 1, 1},
	{150, ML_CODE_ANDDGE, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_on, verifyResultNormal,
			"ANDDGE_OUT low op1 > K", 1, 1},
	{151, ML_CODE_ANDDGE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ANDDGE_OUT high op1 < K", 1, 0},
	{152, ML_CODE_ANDDGE, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_on, verifyResultNormal,
			"ANDDGE_OUT low op1 < K", 1, 0},
	{153, ML_CODE_ANDDGE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ANDDGE_OUT op1 == K", 1, 1},

	{154, ML_CODE_ANDDLT, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1 > op2", 1, 0 },
	{155, ML_CODE_ANDDLT, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1 < op2", 1, 0 },
	{156, ML_CODE_ANDDLT, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ANDDLT_OUT off op1 == op2", 1, 0 },
	{157, ML_CODE_ANDDLT, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT high op1 > op2", 1, 0 },
	{158, ML_CODE_ANDDLT, setCodeAND_OR_32x, setInputDIn_lbigVal32_on, verifyResultNormal,
			"ANDDLT_OUT low op1 > op2", 1, 0 },
	{159, ML_CODE_ANDDLT, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ANDDLT_OUT high op1 < op2", 1, 1 },
	{160, ML_CODE_ANDDLT, setCodeAND_OR_32x, setInputDIn_llessVal32_on, verifyResultNormal,
			"ANDDLT_OUT low op1 < op2", 1, 1 },
	{161, ML_CODE_ANDDLT, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ANDDLT_OUT op1 == op2", 1, 0},
	{162, ML_CODE_ANDDLT, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ANDDLT_OUT high op1 > K", 1, 0},
	{163, ML_CODE_ANDDLT, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ANDDLT_OUT high op1 < K", 1, 0},
	{164, ML_CODE_ANDDLT, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ANDDLT_OUT op1 == K", 1, 0},
	{165, ML_CODE_ANDDLT, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ANDDLT_OUT high op1 > K", 1, 0},
	{166, ML_CODE_ANDDLT, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_on, verifyResultNormal,
			"ANDDLT_OUT low op1 > K", 1, 0},
	{167, ML_CODE_ANDDLT, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ANDDLT_OUT high op1 < K", 1, 1},
	{168, ML_CODE_ANDDLT, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_on, verifyResultNormal,
			"ANDDLT_OUT low op1 < K", 1, 1},
	{169, ML_CODE_ANDDLT, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ANDDLT_OUT op1 == K", 1, 0},

	{170, ML_CODE_ANDDLE, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1 > op2", 1, 0 },
	{171, ML_CODE_ANDDLE, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1 == op2", 1, 0 },
	{172, ML_CODE_ANDDLE, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ANDDLE_OUT off op1 < op2", 1, 0 },
	{173, ML_CODE_ANDDLE, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT high op1 > op2", 1, 0 },
	{174, ML_CODE_ANDDLE, setCodeAND_OR_32x, setInputDIn_lbigVal32_on, verifyResultNormal,
			"ANDDLE_OUT low op1 > op2", 1, 0 },
	{175, ML_CODE_ANDDLE, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ANDDLE_OUT high op1 < op2", 1, 1 },
	{176, ML_CODE_ANDDLE, setCodeAND_OR_32x, setInputDIn_llessVal32_on, verifyResultNormal,
			"ANDDLE_OUT low op1 < op2", 1, 1 },
	{177, ML_CODE_ANDDLE, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ANDDLE_OUT op1 == op2", 1, 1},
	{178, ML_CODE_ANDDLE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ANDDLE_OUT high op1 > K", 1, 0},
	{179, ML_CODE_ANDDLE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ANDDLE_OUT high op1 < K", 1, 0},
	{180, ML_CODE_ANDDLE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ANDDLE_OUT op1 == K", 1, 0},
	{181, ML_CODE_ANDDLE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ANDDLE_OUT high op1 > K", 1, 0},
	{182, ML_CODE_ANDDLE, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_on, verifyResultNormal,
			"ANDDLE_OUT low op1 > K", 1, 0},
	{183, ML_CODE_ANDDLE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ANDDLE_OUT high op1 < K", 1, 1},
	{184, ML_CODE_ANDDLE, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_on, verifyResultNormal,
			"ANDDLE_OUT low op1 < K", 1, 1},
	{185, ML_CODE_ANDDLE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ANDDLE_OUT op1 == K", 1, 1},

	{186, ML_CODE_ORDEQ, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 > op2", 1, 0 },
	{187, ML_CODE_ORDEQ, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 < op2", 1, 0 },
	{188, ML_CODE_ORDEQ, setCodeAND_OR_32x, setInputDIn_lbigVal32_off, verifyResultNormal,
			"ORDEQ_OUT low op1 > op2", 1, 0 },
	{189, ML_CODE_ORDEQ, setCodeAND_OR_32x, setInputDIn_llessVal32_off, verifyResultNormal,
			"ORDEQ_OUT high op1 < op2", 1, 0 },
	{190, ML_CODE_ORDEQ, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ORDEQ_OUT off op1 == op2", 1, 1 },
	{191, ML_CODE_ORDEQ, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ORDEQ_OUT high op1 > op2", 1, 1 },
	{192, ML_CODE_ORDEQ, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ORDEQ_OUT high op1 < op2", 1, 1 },
	{193, ML_CODE_ORDEQ, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ORDEQ_OUT op1 == op2", 1, 1},
	{194, ML_CODE_ORDEQ, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ORDEQ_OUT high op1 > K", 1, 0},
	{195, ML_CODE_ORDEQ, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ORDEQ_OUT high op1 < K", 1, 0},
	{196, ML_CODE_ORDEQ, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_off, verifyResultNormal,
			"ORDEQ_OUT low op1 > K", 1, 0},
	{197, ML_CODE_ORDEQ, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_off, verifyResultNormal,
			"ORDEQ_OUT low op1 < K", 1, 0},
	{198, ML_CODE_ORDEQ, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ORDEQ_OUT op1 == K", 1, 1},
	{199, ML_CODE_ORDEQ, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ORDEQ_OUT high op1 > K", 1, 1},
	{200, ML_CODE_ORDEQ, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ORDEQ_OUT high op1 < K", 1, 1},
	{201, ML_CODE_ORDEQ, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ORDEQ_OUT op1 == K", 1, 1},

	{202, ML_CODE_ORDNE, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 > op2", 1, 1 },
	{203, ML_CODE_ORDNE, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 < op2", 1, 1 },
	{204, ML_CODE_ORDNE, setCodeAND_OR_32x, setInputDIn_lbigVal32_off, verifyResultNormal,
			"ORDNE_OUT low op1 > op2", 1, 1 },
	{205, ML_CODE_ORDNE, setCodeAND_OR_32x, setInputDIn_llessVal32_off, verifyResultNormal,
			"ORDNE_OUT high op1 < op2", 1, 1 },
	{206, ML_CODE_ORDNE, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ORDNE_OUT off op1 == op2", 1, 0 },
	{207, ML_CODE_ORDNE, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ORDNE_OUT high op1 > op2", 1, 1 },
	{208, ML_CODE_ORDNE, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ORDNE_OUT high op1 < op2", 1, 1 },
	{209, ML_CODE_ORDNE, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ORDNE_OUT op1 == op2", 1, 1},
	{210, ML_CODE_ORDNE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ORDNE_OUT high op1 > K", 1, 1},
	{211, ML_CODE_ORDNE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ORDNE_OUT high op1 < K", 1, 1},
	{212, ML_CODE_ORDNE, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_off, verifyResultNormal,
			"ORDNE_OUT low op1 > K", 1, 1},
	{213, ML_CODE_ORDNE, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_off, verifyResultNormal,
			"ORDNE_OUT low op1 < K", 1, 1},
	{214, ML_CODE_ORDNE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ORDNE_OUT op1 == K", 1, 0},
	{215, ML_CODE_ORDNE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ORDNE_OUT high op1 > K", 1, 1},
	{216, ML_CODE_ORDNE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ORDNE_OUT high op1 < K", 1, 1},
	{217, ML_CODE_ORDNE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ORDNE_OUT op1 == K", 1, 1},

	{218, ML_CODE_ORDGT, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 > op2", 1, 1 },
	{219, ML_CODE_ORDGT, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 < op2", 1, 0 },
	{220, ML_CODE_ORDGT, setCodeAND_OR_32x, setInputDIn_lbigVal32_off, verifyResultNormal,
			"ORDGT_OUT low op1 > op2", 1, 1 },
	{221, ML_CODE_ORDGT, setCodeAND_OR_32x, setInputDIn_llessVal32_off, verifyResultNormal,
			"ORDGT_OUT high op1 < op2", 1, 0 },
	{222, ML_CODE_ORDGT, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ORDGT_OUT off op1 == op2", 1, 0 },
	{223, ML_CODE_ORDGT, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ORDGT_OUT high op1 > op2", 1, 1 },
	{224, ML_CODE_ORDGT, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ORDGT_OUT high op1 < op2", 1, 1 },
	{225, ML_CODE_ORDGT, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ORDGT_OUT op1 == op2", 1, 1},
	{226, ML_CODE_ORDGT, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ORDGT_OUT high op1 > K", 1, 1},
	{227, ML_CODE_ORDGT, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ORDGT_OUT high op1 < K", 1, 0},
	{228, ML_CODE_ORDGT, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_off, verifyResultNormal,
			"ORDGT_OUT low op1 > K", 1, 1},
	{229, ML_CODE_ORDGT, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_off, verifyResultNormal,
			"ORDGT_OUT low op1 < K", 1, 0},
	{230, ML_CODE_ORDGT, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ORDGT_OUT op1 == K", 1, 0},
	{231, ML_CODE_ORDGT, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ORDGT_OUT high op1 > K", 1, 1},
	{232, ML_CODE_ORDGT, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ORDGT_OUT high op1 < K", 1, 1},
	{233, ML_CODE_ORDGT, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ORDGT_OUT op1 == K", 1, 1},

	{234, ML_CODE_ORDGE, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 > op2", 1, 1 },
	{235, ML_CODE_ORDGE, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 < op2", 1, 0 },
	{236, ML_CODE_ORDGE, setCodeAND_OR_32x, setInputDIn_lbigVal32_off, verifyResultNormal,
			"ORDGE_OUT low op1 > op2", 1, 1 },
	{237, ML_CODE_ORDGE, setCodeAND_OR_32x, setInputDIn_llessVal32_off, verifyResultNormal,
			"ORDGE_OUT high op1 < op2", 1, 0 },
	{238, ML_CODE_ORDGE, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ORDGE_OUT off op1 == op2", 1, 1 },
	{239, ML_CODE_ORDGE, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ORDGE_OUT high op1 > op2", 1, 1 },
	{240, ML_CODE_ORDGE, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ORDGE_OUT high op1 < op2", 1, 1 },
	{241, ML_CODE_ORDGE, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ORDGE_OUT op1 == op2", 1, 1},
	{242, ML_CODE_ORDGE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ORDGE_OUT high op1 > K", 1, 1},
	{243, ML_CODE_ORDGE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ORDGE_OUT high op1 < K", 1, 0},
	{244, ML_CODE_ORDGE, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_off, verifyResultNormal,
			"ORDGE_OUT low op1 > K", 1, 1},
	{245, ML_CODE_ORDGE, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_off, verifyResultNormal,
			"ORDGE_OUT low op1 < K", 1, 0},
	{246, ML_CODE_ORDGE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ORDGE_OUT op1 == K", 1, 1},
	{247, ML_CODE_ORDGE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ORDGE_OUT high op1 > K", 1, 1},
	{248, ML_CODE_ORDGE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ORDGE_OUT high op1 < K", 1, 1},
	{249, ML_CODE_ORDGE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ORDGE_OUT op1 == K", 1, 1},

	{250, ML_CODE_ORDLT, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 > op2", 1, 0 },
	{251, ML_CODE_ORDLT, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 < op2", 1, 1 },
	{252, ML_CODE_ORDLT, setCodeAND_OR_32x, setInputDIn_lbigVal32_off, verifyResultNormal,
			"ORDLT_OUT low op1 > op2", 1, 0 },
	{253, ML_CODE_ORDLT, setCodeAND_OR_32x, setInputDIn_llessVal32_off, verifyResultNormal,
			"ORDLT_OUT high op1 < op2", 1, 1 },
	{254, ML_CODE_ORDLT, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ORDLT_OUT off op1 == op2", 1, 0 },
	{255, ML_CODE_ORDLT, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ORDLT_OUT high op1 > op2", 1, 1 },
	{256, ML_CODE_ORDLT, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ORDLT_OUT high op1 < op2", 1, 1 },
	{257, ML_CODE_ORDLT, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ORDLT_OUT op1 == op2", 1, 1},
	{258, ML_CODE_ORDLT, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ORDLT_OUT high op1 > K", 1, 0},
	{259, ML_CODE_ORDLT, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ORDLT_OUT high op1 < K", 1, 1},
	{260, ML_CODE_ORDLT, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_off, verifyResultNormal,
			"ORDLT_OUT low op1 > K", 1, 0},
	{261, ML_CODE_ORDLT, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_off, verifyResultNormal,
			"ORDLT_OUT low op1 < K", 1, 1},
	{262, ML_CODE_ORDLT, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ORDLT_OUT op1 == K", 1, 0},
	{263, ML_CODE_ORDLT, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ORDLT_OUT high op1 > K", 1, 1},
	{264, ML_CODE_ORDLT, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ORDLT_OUT high op1 < K", 1, 1},
	{265, ML_CODE_ORDLT, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ORDLT_OUT op1 == K", 1, 1},

	{266, ML_CODE_ORDLE, setCodeAND_OR_32x, setInputDIn_hbigVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 > op2", 1, 0 },
	{267, ML_CODE_ORDLE, setCodeAND_OR_32x, setInputDIn_hlessVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 < op2", 1, 1 },
	{268, ML_CODE_ORDLE, setCodeAND_OR_32x, setInputDIn_lbigVal32_off, verifyResultNormal,
			"ORDLE_OUT low op1 > op2", 1, 0 },
	{269, ML_CODE_ORDLE, setCodeAND_OR_32x, setInputDIn_llessVal32_off, verifyResultNormal,
			"ORDLE_OUT high op1 < op2", 1, 1 },
	{270, ML_CODE_ORDLE, setCodeAND_OR_32x, setInputDIn_sameVal32_off, verifyResultNormal,
			"ORDLE_OUT off op1 == op2", 1, 1 },
	{271, ML_CODE_ORDLE, setCodeAND_OR_32x, setInputDIn_hbigVal32_on, verifyResultNormal,
			"ORDLE_OUT high op1 > op2", 1, 1 },
	{272, ML_CODE_ORDLE, setCodeAND_OR_32x, setInputDIn_hlessVal32_on, verifyResultNormal,
			"ORDLE_OUT low op1 < op2", 1, 1 },
	{273, ML_CODE_ORDLE, setCodeAND_OR_32x, setInputDIn_sameVal32_on, verifyResultNormal,
			"ORDLE_OUT op1 == op2", 1, 1},
	{274, ML_CODE_ORDLE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_off, verifyResultNormal,
			"ORDLE_OUT high op1 > K", 1, 0},
	{275, ML_CODE_ORDLE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_off, verifyResultNormal,
			"ORDLE_OUT high op1 < K", 1, 1},
	{276, ML_CODE_ORDLE, setCodeAND_OR_32x_K, setInputSIn_lbigVal32_K_off, verifyResultNormal,
			"ORDLE_OUT low op1 > K", 1, 0},
	{277, ML_CODE_ORDLE, setCodeAND_OR_32x_K, setInputSIn_llessVal32_K_on, verifyResultNormal,
			"ORDLE_OUT low op1 < K", 1, 1},
	{278, ML_CODE_ORDLE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_off, verifyResultNormal,
			"ORDLE_OUT op1 == K", 1, 1},
	{279, ML_CODE_ORDLE, setCodeAND_OR_32x_K, setInputSIn_hbigVal32_K_on, verifyResultNormal,
			"ORDLE_OUT high op1 > K", 1, 1},
	{280, ML_CODE_ORDLE, setCodeAND_OR_32x_K, setInputSIn_hlessVal32_K_on, verifyResultNormal,
			"ORDLE_OUT high op1 < K", 1, 1},
	{281, ML_CODE_ORDLE, setCodeAND_OR_32x_K, setInputSIn_sameVal32_K_on, verifyResultNormal,
			"ORDLE_OUT op1 == K", 1, 1},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};

int total_basic_comp_dword_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_comp_dword_test_number; i++)
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

//compare with 2x 16bit registers
void setCodeLD32x_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 20);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

//compare with 32bit constant
void setCodeLD32x_K_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_DK, 16843009L); //0x101 0101
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}
//compare with 32bit negative constant
void setCodeLD32x_nK_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_DK, -2130640639L);//0x81010101
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

//compare with 2x 16bit registers
void setCodeAND_OR_32x(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 20);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeAND_OR_32x_K(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 10);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(OPERAND_ML_CODE_DK, 16843009L);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

// high word is different, low word is same
void setInputDIn_hbigVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009); //0x101 00101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16777473); //0x100 0101

	TestCodeTearDown();
}

// low word is different, high word is same
void setInputDIn_lbigVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009);//0x101 0101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843008); //0x101 0100

	TestCodeTearDown();
}

void setInputDIn_hlessVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16777473); //0x100 0101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843009); //0x101 00101

	TestCodeTearDown();
}

void setInputDIn_llessVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843008); //0x101 0100
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843009);//0x101 0101

	TestCodeTearDown();
}

void setInputDIn_sameVal32(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009); //0x101 0101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843009);

	TestCodeTearDown();
}

void setInputSIn_hbigVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16908545); //0x102 0101

	TestCodeTearDown();
}

void setInputSIn_lbigVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843010); //0x101 0102

	TestCodeTearDown();
}

void setInputSIn_hlessVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16777473); //0x100 0101

	TestCodeTearDown();
}

void setInputSIn_llessVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843008); //0x101 0100

	TestCodeTearDown();
}

void setInputSIn_sameVal32_K(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009); //0x101 0101

	TestCodeTearDown();
}

void setInputSIn_hbigVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, -2130706175); //0x8100 0101

	TestCodeTearDown();
}

void setInputSIn_lbigVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, -2130640640); //0x8101 0100

	TestCodeTearDown();
}

void setInputSIn_hlessVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, -2130575103); //0x8102 0101

	TestCodeTearDown();
}

void setInputSIn_llessVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, -2130640638); //0x8101 0102

	TestCodeTearDown();
}

void setInputSIn_sameVal32_nK(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, -2130640639); //0x8101 0101

	TestCodeTearDown();
}

// high word is different, low word is same
void setInputDIn_hbigVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009); //0x101 00101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16777473); //0x100 0101

	TestCodeTearDown();
}

void setInputDIn_hlessVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16777473); //0x100 0101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843009); //0x101 00101

	TestCodeTearDown();
}

void setInputDIn_lbigVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009);//0x101 0101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843008); //0x101 0100

	TestCodeTearDown();
}

void setInputDIn_llessVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843008); //0x101 0100
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843009);//0x101 0101

	TestCodeTearDown();
}

void setInputDIn_sameVal32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009); //0x101 0101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843009);

	TestCodeTearDown();
}

void setInputDIn_hbigVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009); //0x101 00101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16777473); //0x100 0101

	TestCodeTearDown();
}

// low word is different, high word is same
void setInputDIn_lbigVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009);//0x101 0101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843008); //0x101 0100

	TestCodeTearDown();
}

void setInputDIn_hlessVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16777473); //0x100 0101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843009); //0x101 00101

	TestCodeTearDown();
}

void setInputDIn_llessVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843008); //0x101 0100
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843009);//0x101 0101

	TestCodeTearDown();
}

void setInputDIn_sameVal32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009); //0x101 0101
	addDeviceControlInstructionToDWord(0, (uint8)in, 20, 16843009);

	TestCodeTearDown();
}

void setInputSIn_hbigVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16908545); //0x102 0101

	TestCodeTearDown();
}

void setInputSIn_hlessVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16777473); //0x100 0101

	TestCodeTearDown();
}

void setInputSIn_lbigVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843010); //0x101 0102

	TestCodeTearDown();
}

void setInputSIn_llessVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843008); //0x101 0100

	TestCodeTearDown();
}

void setInputSIn_sameVal32_K_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009); //0x101 0101

	TestCodeTearDown();
}

void setInputSIn_hbigVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16908545); //0x102 0101

	TestCodeTearDown();
}

void setInputSIn_lbigVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843010); //0x101 0102

	TestCodeTearDown();
}

void setInputSIn_hlessVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16777473); //0x100 0101

	TestCodeTearDown();
}

void setInputSIn_llessVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843008); //0x101 0100

	TestCodeTearDown();
}

void setInputSIn_sameVal32_K_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 10, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 16843009); //0x101 0101

	TestCodeTearDown();
}

static uint16 getInPos(int reg, int inx_pos)
{
	//uint16 pos[3][2]={ {0,0}, {6144,4096}, {12286,8190}};// 2 word
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12286,8190}};

	return pos[inx_pos][reg];
}

static uint16 getOutPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096},
			{8191,8191,8191,8191,2047,8191}};

	return pos[inx_pos][reg];
}


//test for specific test case
void test_singleCompareDword(int tno)
{
	uint8 in_reg=OPERAND_ML_CODE_D, out_reg=OPERAND_ML_CODE_Y;
	uint16 in_pos=0, out_pos=0;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc;

	PLC_DEVICE_Init();

	testCase[tno].setTestCode_fn(testCase[tno].ml_code, in_reg, in_pos, out_reg, out_pos );
	testCase[tno].setTestInput_fn(in_reg, in_pos, out_reg, out_pos);

	runTestCode(testCase[tno].run_step, testCase[tno].str);

	rc = testCase[tno].verifyResult_fn(tno, out_reg, out_pos, testCase[tno].expected);
	if(rc == 1)
	{
		DBG_LOGPRINT("test case %d error cmd=%d out_%c[%d]\n",
				tno, testCase[tno].ml_code, reg[out_reg], out_pos);
	}
}

static 	FILE *flog;
//normal test case
void test_compare_dword(int tno, uint16 olast)
{
	int i, rc=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_Y;
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
						fprintf(flog, "test_no[%d]: %s command error! in_%s[%d], out_%s[%d] expected=%d\n", \
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

void testBasicCompareDWordCommand(void)
{
	int index=9;
	int start, end;
	char log[] = "err_comp_dword.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("compare dword LOG file open error !\n");
		exit(1);
	}
#if 0
	for(index=0;index<5;index++)
		test_compare_dword(index, 0);
#else
	total_basic_comp_dword_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LDDEQ);
	end = getTestCaseNumberEnd(ML_CODE_ORDLE);

	DBG_LOGPRINT("testBasicCompareDWordCommand: %d to %d total %d\n", start, end, total_basic_comp_dword_test_number);
	for(index=start; index<=end; index++)
	{
		test_compare_dword(index, 0);
	}
#endif
	fclose(flog);
}

#endif
