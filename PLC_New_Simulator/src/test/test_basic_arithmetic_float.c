/*
 * test_basic_arithmatic_float.c
 *
 *  Created on: Mar 31, 2015
 *      Author: hrjung
 */

#ifdef USE_CUNIT_TEST_DEF

#ifndef PLC_LISTOFTESTSUITE_H_
#include "../PLC_ListOfTestSuite.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

extern void TestCodeInit(void);
extern void TestCodeTearDown(void);
extern int runTestCode(int run_step, char *testFuncName);

extern int setCodeLD_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_E_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

int setCodeLD_3Eop_in(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_3Eop_out(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_Emlt_1E(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_Emlt_2E(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_Ediv_1E(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_Ediv_2E(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputDIn_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_emlt_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_emlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_emltp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_emlt_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_emlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_emltp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_emlt_1E_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_emlt_1E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_emltp_1E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
// test input for EDIV
void setInputDIn_ediv_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_ediv_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_edivp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_DOut_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_DOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_DOutp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_ediv_1E_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_ediv_1E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_edivp_1E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputNIn_2E_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputNIn_2E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputNIn_2Ep_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);


int verifyResultValueFloat(int tcase, uint8 dest_reg, uint16 pos, float expected);
//int verifyResultValueDouble(uint8 dest_reg, uint16 pos, double expected);

static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, float);
	char str[50];
	//int count;
	int run_step;
	float expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_EADD, setCodeLD_2op, setInputDIn_float_off, verifyResultValueFloat,
			"ADD float off", 1, 12003.2f},
	{1, ML_CODE_EADD, setCodeLD_2op, setInputDIn_float_on, verifyResultValueFloat,
			"ADD float op2 + op1", 1, 17964.637f},
	{2, ML_CODE_EADD, setCodeLD_E_1op, setInputSIn_float_off, verifyResultValueFloat,
			"ADD float off with E", 1, 12003.2f},
	{3, ML_CODE_EADD, setCodeLD_E_1op, setInputSIn_float_on, verifyResultValueFloat,
			"ADD float op1 + E", 1, 17964.637f},

	{4, ML_CODE_EADDP, setCodeLD_2op, setInputDIn_float_off, verifyResultValueFloat,
			"ADDP float off 0->0", 2, 12003.2f},
	{5, ML_CODE_EADDP, setCodeLD_2op, setInputDIn_float_on, verifyResultValueFloat,
			"ADDP float off 1->1", 2, 12003.2f},
	{6, ML_CODE_EADDP, setCodeLD_2op, setInputDIn_floatp_on, verifyResultValueFloat,
			"ADDP float op2 + op1", 2, 17964.637f},
	{7, ML_CODE_EADDP, setCodeLD_E_1op, setInputSIn_float_off, verifyResultValueFloat,
			"ADDP float off with E", 2, 12003.2f},
	{8, ML_CODE_EADDP, setCodeLD_E_1op, setInputSIn_floatp_on, verifyResultValueFloat,
			"ADDP float op1 + E", 2, 17964.637f},

	{9, ML_CODE_ESUB, setCodeLD_2op, setInputDIn_float_off, verifyResultValueFloat,
			"SUB float off", 1, 12003.2f},
	{10, ML_CODE_ESUB, setCodeLD_2op, setInputDIn_float_on, verifyResultValueFloat,
			"SUB float op2 - op1", 1, 6041.763f},
	{11, ML_CODE_ESUB, setCodeLD_E_1op, setInputSIn_float_off, verifyResultValueFloat,
			"SUB float off with E", 1, 12003.2f},
	{12, ML_CODE_ESUB, setCodeLD_E_1op, setInputSIn_float_on, verifyResultValueFloat,
			"SUB float op1 - E", 1, 6041.763f},

	{13, ML_CODE_ESUBP, setCodeLD_2op, setInputDIn_float_off, verifyResultValueFloat,
			"SUBP float off 0->0", 2, 12003.2f},
	{14, ML_CODE_ESUBP, setCodeLD_2op, setInputDIn_float_on, verifyResultValueFloat,
			"SUBP float off 1->1", 2, 12003.2f},
	{15, ML_CODE_ESUBP, setCodeLD_2op, setInputDIn_floatp_on, verifyResultValueFloat,
			"SUBP float op2 - op1", 2, 6041.763f},
	{16, ML_CODE_ESUBP, setCodeLD_E_1op, setInputSIn_float_off, verifyResultValueFloat,
			"SUBP float off with E", 2, 12003.2f},
	{17, ML_CODE_ESUBP, setCodeLD_E_1op, setInputSIn_floatp_on, verifyResultValueFloat,
			"SUBP float op1 - E", 2, 6041.763f},

	{18, ML_CODE_EADDS, setCodeLD_3Eop_in, setInputDIn_emlt_off, verifyResultValueFloat,
			"ADDS float off", 1, 0.0f},
	{19, ML_CODE_EADDS, setCodeLD_3Eop_in, setInputDIn_emlt_on, verifyResultValueFloat,
			"ADDS float op3 = op1 - op2", 1, 17964.637},
	{20, ML_CODE_EADDS, setCodeLD_3Eop_out, setInputSIn_emlt_off, verifyResultValueFloat,
			"ADDS float off", 1, 0.0f},
	{21, ML_CODE_EADDS, setCodeLD_3Eop_out, setInputSIn_emlt_on, verifyResultValueFloat,
			"ADDS float op3 = op1 - op2", 1, 17964.637},
	{22, ML_CODE_EADDS, setCodeLD_Emlt_1E, setInputSIn_emlt_1E_off, verifyResultValueFloat,
			"ADDS float off with E", 1, 0.0f},
	{23, ML_CODE_EADDS, setCodeLD_Emlt_1E, setInputSIn_emlt_1E_on, verifyResultValueFloat,
			"ADDS float op2 = op1 - E", 1, 17964.637},
	{24, ML_CODE_EADDS, setCodeLD_Emlt_2E, setInputNIn_2E_off, verifyResultValueFloat,
			"ADDS float off with E", 1, 0.0f},
	{25, ML_CODE_EADDS, setCodeLD_Emlt_2E, setInputNIn_2E_on, verifyResultValueFloat,
			"ADDS float op1 = E - E", 1, 17964.637},

	{26, ML_CODE_EADDPS, setCodeLD_3Eop_in, setInputDIn_emlt_off, verifyResultValueFloat,
			"ADDPS float off 0->0", 2, 0.0f},
	{27, ML_CODE_EADDPS, setCodeLD_3Eop_in, setInputDIn_emlt_on, verifyResultValueFloat,
			"ADDPS float off 1->1 ", 2, 0.0f},
	{28, ML_CODE_EADDPS, setCodeLD_3Eop_in, setInputDIn_emltp_on, verifyResultValueFloat,
			"ADDPS float op3 = op1 + op2", 2, 17964.637},
	{29, ML_CODE_EADDPS, setCodeLD_3Eop_out, setInputSIn_emlt_off, verifyResultValueFloat,
			"ADDPS float off", 2, 0.0f},
	{30, ML_CODE_EADDPS, setCodeLD_3Eop_out, setInputSIn_emlt_on, verifyResultValueFloat,
			"ADDPS float off 1->1 ", 2, 0.0f},
	{31, ML_CODE_EADDPS, setCodeLD_3Eop_out, setInputSIn_emltp_on, verifyResultValueFloat,
			"ADDPS float op3 = op1 + op2", 2, 17964.637},
	{32, ML_CODE_EADDPS, setCodeLD_Emlt_1E, setInputSIn_emlt_1E_off, verifyResultValueFloat,
			"ADDPS float off with E", 2, 0.0f},
	{33, ML_CODE_EADDPS, setCodeLD_Emlt_1E, setInputSIn_emltp_1E_on, verifyResultValueFloat,
			"ADDPS float op2 = op1 + E", 2, 17964.637},
	{34, ML_CODE_EADDPS, setCodeLD_Emlt_2E, setInputNIn_2E_off, verifyResultValueFloat,
			"ADDPS float off with E", 2, 0.0f},
	{35, ML_CODE_EADDPS, setCodeLD_Emlt_2E, setInputNIn_2Ep_on, verifyResultValueFloat,
			"ADDPS float op1 = E + E", 2, 17964.637},

	{36, ML_CODE_ESUBS, setCodeLD_3Eop_in, setInputDIn_emlt_off, verifyResultValueFloat,
			"SUBS float off", 1, 0.0f},
	{37, ML_CODE_ESUBS, setCodeLD_3Eop_in, setInputDIn_emlt_on, verifyResultValueFloat,
			"SUBS float op3 = op1 - op2", 1, 6041.763},
	{38, ML_CODE_ESUBS, setCodeLD_3Eop_out, setInputSIn_emlt_off, verifyResultValueFloat,
			"SUBS float off", 1, 0.0f},
	{39, ML_CODE_ESUBS, setCodeLD_3Eop_out, setInputSIn_emlt_on, verifyResultValueFloat,
			"SUBS float op3 = op1 - op2", 1, 6041.763},
	{40, ML_CODE_ESUBS, setCodeLD_Emlt_1E, setInputSIn_emlt_1E_off, verifyResultValueFloat,
			"SUBS float off with E", 1, 0.0f},
	{41, ML_CODE_ESUBS, setCodeLD_Emlt_1E, setInputSIn_emlt_1E_on, verifyResultValueFloat,
			"SUBS float op2 = op1 - E", 1, 6041.763},
	{42, ML_CODE_ESUBS, setCodeLD_Emlt_2E, setInputNIn_2E_off, verifyResultValueFloat,
			"SUBS float off with E", 1, 0.0f},
	{43, ML_CODE_ESUBS, setCodeLD_Emlt_2E, setInputNIn_2E_on, verifyResultValueFloat,
			"SUBS float op1 = E - E", 1, 6041.763},

	{44, ML_CODE_ESUBPS, setCodeLD_3Eop_in, setInputDIn_emlt_off, verifyResultValueFloat,
			"SUBPS float off 0->0", 2, 0.0f},
	{45, ML_CODE_ESUBPS, setCodeLD_3Eop_in, setInputDIn_emlt_on, verifyResultValueFloat,
			"SUBPS float off 1->1", 2, 0.0f},
	{46, ML_CODE_ESUBPS, setCodeLD_3Eop_in, setInputDIn_emltp_on, verifyResultValueFloat,
			"SUBPS float op3 = op1 - op2", 2, 6041.763},
	{47, ML_CODE_ESUBPS, setCodeLD_3Eop_out, setInputSIn_emlt_off, verifyResultValueFloat,
			"SUBPS float off 0->0", 2, 0.0f},
	{48, ML_CODE_ESUBPS, setCodeLD_3Eop_out, setInputSIn_emlt_on, verifyResultValueFloat,
			"SUBPS float off 1->1", 2, 0.0f},
	{49, ML_CODE_ESUBPS, setCodeLD_3Eop_out, setInputSIn_emltp_on, verifyResultValueFloat,
			"SUBPS float op3 = op1 - op2", 2, 6041.763},
	{50, ML_CODE_ESUBPS, setCodeLD_Emlt_1E, setInputSIn_emlt_1E_off, verifyResultValueFloat,
			"SUBPS float off with E", 2, 0.0f},
	{51, ML_CODE_ESUBPS, setCodeLD_Emlt_1E, setInputSIn_emltp_1E_on, verifyResultValueFloat,
			"SUBPS float op2 = op1 - E", 2, 6041.763},
	{52, ML_CODE_ESUBPS, setCodeLD_Emlt_2E, setInputNIn_2E_off, verifyResultValueFloat,
			"SUBPS float off with E", 2, 0.0f},
	{53, ML_CODE_ESUBPS, setCodeLD_Emlt_2E, setInputNIn_2Ep_on, verifyResultValueFloat,
			"SUBPS float op1 = E - E", 2, 6041.763},


	{54, ML_CODE_EMLT, setCodeLD_3Eop_in, setInputDIn_emlt_off, verifyResultValueFloat,
			"Multiply float off", 1, 0.0},
	{55, ML_CODE_EMLT, setCodeLD_3Eop_in, setInputDIn_emlt_on, verifyResultValueFloat,
			"Multiply float op3 = op2 * op1", 1, 71556320.5984},
	{56, ML_CODE_EMLT, setCodeLD_3Eop_out, setInputSIn_emlt_off, verifyResultValueFloat,
			"Multiply float off", 1, 0.0},
	{57, ML_CODE_EMLT, setCodeLD_3Eop_out, setInputSIn_emlt_on, verifyResultValueFloat,
			"Multiply float op3 = op2 * op1", 1, 71556320.5984},
	{58, ML_CODE_EMLT, setCodeLD_Emlt_1E, setInputSIn_emlt_1E_off, verifyResultValueFloat,
			"Multiply float off with 1E", 1, 0.0},
	{59, ML_CODE_EMLT, setCodeLD_Emlt_1E, setInputSIn_emlt_1E_on, verifyResultValueFloat,
			"Multiply float op2 = op1 * E", 1, 71556320.5984},
	{60, ML_CODE_EMLT, setCodeLD_Emlt_2E, setInputNIn_2E_off, verifyResultValueFloat,
			"Multiply float off with 2E", 1, 0.0},
	{61, ML_CODE_EMLT, setCodeLD_Emlt_2E, setInputNIn_2E_on, verifyResultValueFloat,
			"Multiply float op1 = E * E", 1, 71556320.5984},

	{62, ML_CODE_EMLTP, setCodeLD_3Eop_in, setInputDIn_emlt_off, verifyResultValueFloat,
			"MultiplyP float off 0->0", 2, 0.0},
	{63, ML_CODE_EMLTP, setCodeLD_3Eop_in, setInputDIn_emlt_on, verifyResultValueFloat,
			"MultiplyP float off 1->1", 2, 0.0},
	{64, ML_CODE_EMLTP, setCodeLD_3Eop_in, setInputDIn_emltp_on, verifyResultValueFloat,
			"MultiplyP float op2 * op1", 2, 71556320.5984},
	{65, ML_CODE_EMLTP, setCodeLD_3Eop_out, setInputSIn_emlt_off, verifyResultValueFloat,
			"MultiplyP float off 0->0", 2, 0.0},
	{66, ML_CODE_EMLTP, setCodeLD_3Eop_out, setInputSIn_emlt_on, verifyResultValueFloat,
			"MultiplyP float off 1->1", 2, 0.0},
	{67, ML_CODE_EMLTP, setCodeLD_3Eop_out, setInputSIn_emltp_on, verifyResultValueFloat,
			"MultiplyP float op2 * op1", 2, 71556320.5984},
	{68, ML_CODE_EMLTP, setCodeLD_Emlt_1E, setInputSIn_emlt_1E_off, verifyResultValueFloat,
			"MultiplyP float off with 1E", 2, 0.0},
	{69, ML_CODE_EMLTP, setCodeLD_Emlt_1E, setInputSIn_emltp_1E_on, verifyResultValueFloat,
			"MultiplyP float op2 = op1 * E", 2, 71556320.5984},
	{70, ML_CODE_EMLTP, setCodeLD_Emlt_2E, setInputNIn_2E_off, verifyResultValueFloat,
			"MultiplyP float off with 2E", 2, 0.0},
	{71, ML_CODE_EMLTP, setCodeLD_Emlt_2E, setInputNIn_2E_on, verifyResultValueFloat,
			"MultiplyP float off with 2E", 2, 0.0},
	{72, ML_CODE_EMLTP, setCodeLD_Emlt_2E, setInputNIn_2Ep_on, verifyResultValueFloat,
			"MultiplyP float op1 = E * E", 2, 71556320.5984},

	{73, ML_CODE_EDIV, setCodeLD_3Eop_in, setInputDIn_ediv_off, verifyResultValueFloat,
			"DIV float off", 1, 0.0},
	{74, ML_CODE_EDIV, setCodeLD_3Eop_in, setInputDIn_ediv_on, verifyResultValueFloat,
			"DIV float op3 = op2 / op1", 1, 5359.041},
	{75, ML_CODE_EDIV, setCodeLD_3Eop_out, setInputSIn_DOut_off, verifyResultValueFloat,
			"DIV float off", 1, 0.0},
	{76, ML_CODE_EDIV, setCodeLD_3Eop_out, setInputSIn_DOut_on, verifyResultValueFloat,
			"DIV float op3 = op2 / op1", 1, 5359.041},
	{77, ML_CODE_EDIV, setCodeLD_Ediv_1E, setInputSIn_ediv_1E_off, verifyResultValueFloat,
			"DIV float off with E", 1, 0.0},
	{78, ML_CODE_EDIV, setCodeLD_Ediv_1E, setInputSIn_ediv_1E_on, verifyResultValueFloat,
			"DIV float op2 = op1 / E", 1, 5359.041},
	{79, ML_CODE_EDIV, setCodeLD_Ediv_2E, setInputNIn_2E_off, verifyResultValueFloat,
			"DIV float off with E", 1, 0.0},
	{80, ML_CODE_EDIV, setCodeLD_Ediv_2E, setInputNIn_2E_on, verifyResultValueFloat,
			"DIV float op1 = E / E", 1, 5359.041},

	{81, ML_CODE_EDIVP, setCodeLD_3Eop_in, setInputDIn_ediv_off, verifyResultValueFloat,
			"DIVP float off 0->0", 2, 0.0},
	{82, ML_CODE_EDIVP, setCodeLD_3Eop_in, setInputDIn_ediv_on, verifyResultValueFloat,
			"DIVP float off 1->1", 2, 0.0},
	{83, ML_CODE_EDIVP, setCodeLD_3Eop_in, setInputDIn_edivp_on, verifyResultValueFloat,
			"DIVP float op2 * op1", 2, 5359.041},
	{84, ML_CODE_EDIVP, setCodeLD_3Eop_out, setInputSIn_DOut_off, verifyResultValueFloat,
			"DIVP float off 0->0", 2, 0.0},
	{85, ML_CODE_EDIVP, setCodeLD_3Eop_out, setInputSIn_DOut_on, verifyResultValueFloat,
			"DIVP float off 1->1", 2, 0.0},
	{86, ML_CODE_EDIVP, setCodeLD_3Eop_out, setInputSIn_DOutp_on, verifyResultValueFloat,
			"DIVP float op2 * op1", 2, 5359.041},
	{87, ML_CODE_EDIVP, setCodeLD_Ediv_1E, setInputSIn_ediv_1E_off, verifyResultValueFloat,
			"DIVP float off with E", 2, 0.0},
	{88, ML_CODE_EDIVP, setCodeLD_Ediv_1E, setInputSIn_ediv_1E_on, verifyResultValueFloat,
			"DIVP float op1 * E", 2, 0.0},
	{89, ML_CODE_EDIVP, setCodeLD_Ediv_1E, setInputSIn_edivp_1E_on, verifyResultValueFloat,
			"DIVP float op1 * E", 2, 5359.041},
	{90, ML_CODE_EDIVP, setCodeLD_Ediv_2E, setInputNIn_2E_off, verifyResultValueFloat,
			"DIVP float off with E", 2, 0.0},
	{91, ML_CODE_EDIVP, setCodeLD_Ediv_2E, setInputNIn_2E_on, verifyResultValueFloat,
			"DIVP float op1 = E / E", 2, 0.0},
	{92, ML_CODE_EDIVP, setCodeLD_Ediv_2E, setInputNIn_2Ep_on, verifyResultValueFloat,
			"DIVP float op1 = E / E", 2, 5359.041},

	{-1, 0xFFFF, NULL, NULL, NULL, " ", 0, 0 }
};


int total_basic_compute_float_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_float_test_number; i++)
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

int setCodeLD_3Eop_in(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 50);
		addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_3Eop_out(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos);
		addMLOperand(out_reg, 50); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_E_1op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 5961.437); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_Emlt_1E(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperandFloat(OPERAND_ML_CODE_E, 5961.437);
		 addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_Emlt_2E(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 12003.2); addMLOperandFloat(OPERAND_ML_CODE_E, 5961.437);
	 	 addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_Ediv_1E(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperandFloat(OPERAND_ML_CODE_E, 9.73521);
		 addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_Ediv_2E(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandFloat(OPERAND_ML_CODE_E, 52171.39);
		addMLOperandFloat(OPERAND_ML_CODE_E, 9.73521); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputDIn_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 5961.437);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 5961.437);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos, 12003.2);

	TestCodeTearDown();
}

void setInputDIn_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 5961.437);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos, 12003.2);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);


	TestCodeTearDown();
}

void setInputSIn_float_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos, 12003.2);

	TestCodeTearDown();
}

void setInputSIn_float_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos, 12003.2);

	TestCodeTearDown();
}

void setInputSIn_floatp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToFloat(0, (uint8)out, out_pos, 12003.2);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}
//input EMLT 2 input
void setInputDIn_emlt_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 5961.437);

	TestCodeTearDown();
}

void setInputDIn_emlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 5961.437);

	TestCodeTearDown();
}

void setInputDIn_emltp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 5961.437);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

//input EMLT 2 input
void setInputSIn_emlt_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 5961.437);

	TestCodeTearDown();
}

void setInputSIn_emlt_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 5961.437);

	TestCodeTearDown();
}

void setInputSIn_emltp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 5961.437);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_emlt_1E_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);

	TestCodeTearDown();
}

void setInputSIn_emlt_1E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);

	TestCodeTearDown();
}

void setInputSIn_emltp_1E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 12003.2);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

// input for EDIV 2 input
void setInputDIn_ediv_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 9.73521);


	TestCodeTearDown();
}

void setInputDIn_ediv_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 9.73521);

	TestCodeTearDown();
}

void setInputDIn_edivp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)in, 50, 9.73521);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);


	TestCodeTearDown();
}
// input for EDIV 1 E, 1 input
void setInputSIn_ediv_1E_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);

	TestCodeTearDown();
}

void setInputSIn_ediv_1E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);

	TestCodeTearDown();
}

void setInputSIn_edivp_1E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}
// for EDIV 1 in + 1 out + 1 out+2
void setInputSIn_DOut_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 9.73521);

	TestCodeTearDown();
}

void setInputSIn_DOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 9.73521);

	TestCodeTearDown();
}

void setInputSIn_DOutp_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 52171.39);
	addDeviceControlInstructionToFloat(0, (uint8)out, 50, 9.73521);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);


	TestCodeTearDown();
}

void setInputNIn_2E_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);

	TestCodeTearDown();
}

void setInputNIn_2E_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputNIn_2Ep_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

int verifyResultValueFloat(int tcase, uint8 dest_reg, uint16 pos, float expected)
{
	int rc=0;
	float result;
	char reg[] = {'D', 'W'};
	float granularity;

	//printf("verifyResultValueFloat() : expected=%f\n", expected);
	//result = (double)PLC_Register_getFloat(dest_reg, pos);
	if(!test_getFloat(&result, dest_reg, pos))
		return 1;

#if 1
	if( show_log ) DBG_LOGPRINT("test=%d Reg %c[%d]=%f %f \n", tcase, reg[dest_reg-OPERAND_ML_CODE_D], pos, result, expected);
	CU_ASSERT_DOUBLE_EQUAL(result, expected, FLT_EPSILON);
	if(result != expected) rc=1;
#else
	if( show_log ) DBG_LOGPRINT("Reg %c[%d]=%e %e eps=%e\n", reg[dest_reg-OPERAND_ML_CODE_D], pos, result, expected, FLT_EPSILON);
	if(result != expected)
	{
		CU_ASSERT_DOUBLE_EQUAL(result, expected, FLT_EPSILON);
		rc=1;
	}
	else
	{
		CU_ASSERT_EQUAL(result, expected);
	}
#endif
	return rc;
}

int verifyResultValueDouble(uint8 dest_reg, uint16 pos, double expected)
{
	int rc=0;
	double result;
	char reg[] = {'D', 'W'};

	if(!test_getDouble(&result, dest_reg, pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("Reg %c[%d]=%f %f\n", reg[dest_reg-OPERAND_ML_CODE_D], pos, result, expected);
	CU_ASSERT_DOUBLE_EQUAL(result, expected, DBL_EPSILON);
	if(result != expected) rc=1;

	return rc;
}


static uint16 getPos(int reg, int inx_pos)
{
	//uint16 pos[3][2]={ {0,0}, {6144,4096}, {12286,8190}}; // 2 word
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12286,8190}}; //16bit

	return pos[inx_pos][reg];
}

static 	FILE *flog;
void test_basic_arithmetic_float(int tno, uint16 dummy)
{
	int i, ml_rc, rc=0, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	float res_float;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getPos(out, olast);
			//for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in, i);

					if(in == out && (in_pos == out_pos || in_pos-2 == out_pos))
					{
						continue;
					}

					ml_rc=testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if(ml_rc==0) continue;

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
							test_getFloat(&res_float, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%f exp=%f \n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_float, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testBasicArithmeticFloatCommand(void)
{
	int i, index=19;
	int start, end;
	char log[] = "err_arith_float.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic float LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0;index<4;index++)
		test_basic_arithmetic_float(index, 0);
#else
	total_basic_compute_float_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_EADD);
	end = getTestCaseNumberEnd(ML_CODE_EDIV);

	DBG_LOGPRINT("testBasicArithmaticFloatCommand: %d to %d total %d\n", start, end, total_basic_compute_float_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_float(index, 0);
	}
#endif
	fclose(flog);
}


#endif
