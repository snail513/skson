/*
 * test_basic_transfer_dword_index.c
 *
 *  Created on: Aug 31, 2015
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

extern int setCodeOp2_W_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_N_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp2_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected);
extern int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected);

int setCodeOp2_medK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_maxintDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_DN8_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_DWZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

void setInputSIn_sval32_DW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_sval32_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_sval32p_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_sval32_maxDW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_sval32p_maxDW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_med_DN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_med_DN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_medp_DN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_max_DN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputSIn_maxp_DN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_Val32_4N_5555_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_Val32_4N_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_Val32p_4N_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_med_WZ_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_med_WZ_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_medp_WZ_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

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
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16, uint16, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16, uint16, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, int);
	char str[40];
	//int count;
	int z_type; // 0 : op2 is index, 1: op1 is index
	int run_step;
	int expected;

} testFn_st;


static testFn_st testCase[]={
	{0, ML_CODE_DMOV, setCodeOp2_W_WZ, setInputSIn_sval32_DW_WZ_off, verifyResultValueDWord,
			"DMOV off 0x55555555", 0, 1, 0},
	{1, ML_CODE_DMOV, setCodeOp2_W_WZ, setInputSIn_sval32_DW_WZ_on, verifyResultValueDWord,
			"DMOV on 0x55555555", 0, 1, 1431655765},
	{2, ML_CODE_DMOV, setCodeOp2_W_WZ, setInputSIn_sval32_maxDW_WZ_on, verifyResultValueDWord,
			"DMOV on 32767", 0, 1, 2147483647},
	{3, ML_CODE_DMOV, setCodeOp2_medK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DMOV off K0x55555555", 0, 1, 0},
	{4, ML_CODE_DMOV, setCodeOp2_medK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"DMOV on K0x55555555", 0, 1, 1431655765},
	{5, ML_CODE_DMOV, setCodeOp2_maxintDK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"DMOV on K2147483647", 0, 1, 2147483647},
	{6, ML_CODE_DMOV, setCodeOp2_DN8_WZ, setInputSIn_med_DN_WZ_off, verifyResultValueDWord,
			"DMOV off N0x55555555", 0, 1, 0},
	{7, ML_CODE_DMOV, setCodeOp2_DN8_WZ, setInputSIn_med_DN_WZ_on, verifyResultValueDWord,
			"DMOV on N0x55555555", 0, 1, 1431655765},
	{8, ML_CODE_DMOV, setCodeOp2_DN8_WZ, setInputSIn_max_DN_WZ_on, verifyResultValueDWord,
			"DMOV on N2147483647", 0, 1, 2147483647},
	{9, ML_CODE_DMOV, setCodeOp2_N_WZ, setInputOp2_Val32_4N_5555_off, verifyResultValueDWord,
			"DMOV off N0x5555", 0, 1, 0},
	{10, ML_CODE_DMOV, setCodeOp2_N_WZ, setInputOp2_Val32_4N_5555_on, verifyResultValueDWord,
			"DMOV on N0x5555", 0, 1, 21845}, //0x5555
	{11, ML_CODE_DMOV, setCodeOp2_WZ_W, setInputOp2_med_WZ_DW_off, verifyResultValueDWord,
			"DMOV off WZ0x55555555", 1, 1, 0},
	{12, ML_CODE_DMOV, setCodeOp2_WZ_W, setInputOp2_med_WZ_DW_on, verifyResultValueDWord,
			"DMOV on WZ0x55555555", 1, 1, 1431655765},
	{13, ML_CODE_DMOV, setCodeOp2_DWZ_DN, setInputOp2_med_WZ_DW_off, verifyResultValueNibble8,
			"DMOV off WZ0x55555555", 3, 1, 0},
	{14, ML_CODE_DMOV, setCodeOp2_DWZ_DN, setInputOp2_med_WZ_DW_on, verifyResultValueNibble8,
			"DMOV on WZ0x55555555", 3, 1, 1431655765},
	{15, ML_CODE_DMOV, setCodeOp2_WZ_WZ, setInputOp2_med_WZ_DW_off, verifyResultValueDWord,
			"DMOV off WZ0x55555555", 2, 1, 0},
	{16, ML_CODE_DMOV, setCodeOp2_WZ_WZ, setInputOp2_med_WZ_DW_on, verifyResultValueDWord,
			"DMOV on WZ0x55555555", 2, 1, 1431655765},

	{17, ML_CODE_DMOVP, setCodeOp2_W_WZ, setInputSIn_sval32_DW_WZ_off, verifyResultValueDWord,
			"DMOVP 0->0 0x55555555", 0, 2, 0},
	{18, ML_CODE_DMOVP, setCodeOp2_W_WZ, setInputSIn_sval32p_DW_WZ_on, verifyResultValueDWord,
			"DMOVP 0->1 0x55555555", 0, 2, 1431655765},
	{19, ML_CODE_DMOVP, setCodeOp2_W_WZ, setInputSIn_sval32p_maxDW_WZ_on, verifyResultValueDWord,
			"DMOVP 0->1 32767", 0, 2, 2147483647},
	{20, ML_CODE_DMOVP, setCodeOp2_medK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DMOVP 0->0 K0x55555555", 0, 2, 0},
	{21, ML_CODE_DMOVP, setCodeOp2_medK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"DMOVP 0->1 K0x55555555", 0, 2, 1431655765},
	{22, ML_CODE_DMOVP, setCodeOp2_maxintDK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"DMOVP 0->1 K2147483647", 0, 2, 2147483647},
	{23, ML_CODE_DMOVP, setCodeOp2_DN8_WZ, setInputSIn_med_DN_WZ_off, verifyResultValueDWord,
			"DMOVP 0->0 N0x55555555", 0, 2, 0},
	{24, ML_CODE_DMOVP, setCodeOp2_DN8_WZ, setInputSIn_medp_DN_WZ_on, verifyResultValueDWord,
			"DMOVP 0->1 N0x55555555", 0, 2, 1431655765},
	{25, ML_CODE_DMOVP, setCodeOp2_DN8_WZ, setInputSIn_maxp_DN_WZ_on, verifyResultValueDWord,
			"DMOVP 0->1 N2147483647", 0, 2, 2147483647},
	{26, ML_CODE_DMOVP, setCodeOp2_N_WZ, setInputOp2_Val32_4N_5555_off, verifyResultValueDWord,
			"DMOVP 0->0 N0x5555", 0, 2, 0},
	{27, ML_CODE_DMOVP, setCodeOp2_N_WZ, setInputOp2_Val32p_4N_5555_on, verifyResultValueDWord,
			"DMOVP 0->1 N0x5555", 0, 2, 21845}, //0x5555
	{28, ML_CODE_DMOVP, setCodeOp2_WZ_W, setInputOp2_med_WZ_DW_off, verifyResultValueDWord,
			"DMOVP 0->0 WZ0x55555555", 1, 2, 0},
	{29, ML_CODE_DMOVP, setCodeOp2_WZ_W, setInputOp2_medp_WZ_DW_on, verifyResultValueDWord,
			"DMOVP 0->1 WZ0x55555555", 1, 2, 1431655765}, //0x55555555
	{30, ML_CODE_DMOVP, setCodeOp2_DWZ_DN, setInputOp2_med_WZ_DW_off, verifyResultValueNibble8,
			"DMOVP 0->0 WZ0x55555555", 3, 2, 0},
	{31, ML_CODE_DMOVP, setCodeOp2_DWZ_DN, setInputOp2_medp_WZ_DW_on, verifyResultValueNibble8,
			"DMOVP 0->1 WZ0x55555555", 3, 2, 1431655765},
	{32, ML_CODE_DMOVP, setCodeOp2_WZ_WZ, setInputOp2_med_WZ_DW_off, verifyResultValueDWord,
			"DMOVP 0->0 WZ0x55555555", 2, 2, 0},
	{33, ML_CODE_DMOVP, setCodeOp2_WZ_WZ, setInputOp2_medp_WZ_DW_on, verifyResultValueDWord,
			"DMOVP 0->1 WZ0x55555555", 2, 2, 1431655765},

	{34, ML_CODE_DCML, setCodeOp2_W_WZ, setInputSIn_sval32_DW_WZ_off, verifyResultValueDWord,
		"DCML off 0x55555555", 0, 1, 0},
	{35, ML_CODE_DCML, setCodeOp2_W_WZ, setInputSIn_sval32_DW_WZ_on, verifyResultValueDWord,
		"DCML on 0x55555555", 0, 1, -1431655766}, //0xAAAA AAAA
	{36, ML_CODE_DCML, setCodeOp2_W_WZ, setInputSIn_sval32_maxDW_WZ_on, verifyResultValueDWord,
		"DCML on 2147483647", 0, 1, -2147483648}, //0x100000000
	{37, ML_CODE_DCML, setCodeOp2_medK_WZ, setInputOp2_none_off, verifyResultValueDWord,
		"DCML off K0x55555555", 0, 1, 0},
	{38, ML_CODE_DCML, setCodeOp2_medK_WZ, setInputOp2_none_on, verifyResultValueDWord,
		"DCML on K0x55555555", 0, 1, -1431655766}, //0xAAAA AAAA
	{39, ML_CODE_DCML, setCodeOp2_maxintDK_WZ, setInputOp2_none_on, verifyResultValueDWord,
		"DCML on K2147483647", 0, 1, -2147483648}, //0x100000000
	{40, ML_CODE_DCML, setCodeOp2_DN8_WZ, setInputOp2_Val32_4N_5555_off, verifyResultValueDWord,
		"DCML off N2 0x5555", 0, 1, 0},
	{41, ML_CODE_DCML, setCodeOp2_DN8_WZ, setInputOp2_Val32_4N_5555_on, verifyResultValueDWord,
		"DCML on N8 0x55555555", 0, 1, -1431655766}, //0xAAAAAAAA
	{42, ML_CODE_DCML, setCodeOp2_DN8_WZ, setInputSIn_max_DN_WZ_on, verifyResultValueDWord,
		"DCML on N2147483647", 0, 1, -2147483648}, //0x10000000
	{43, ML_CODE_DCML, setCodeOp2_N_WZ, setInputSIn_med_DN_WZ_off, verifyResultValueDWord,
		"DCML off N0x55555555", 0, 1, 0},
	{44, ML_CODE_DCML, setCodeOp2_N_WZ, setInputSIn_med_DN_WZ_on, verifyResultValueDWord,
		"DCML on N0x55555555", 0, 1, -21846}, //0xFFFF AAAA
	{45, ML_CODE_DCML, setCodeOp2_WZ_W, setInputOp2_med_WZ_DW_off, verifyResultValueDWord,
		"DCML off WZ0x55555555", 1, 1, 0},
	{46, ML_CODE_DCML, setCodeOp2_WZ_W, setInputOp2_med_WZ_DW_on, verifyResultValueDWord,
		"DCML on WZ0x55555555", 1, 1, -1431655766}, //0xAAAA AAAA
	{47, ML_CODE_DCML, setCodeOp2_DWZ_DN, setInputOp2_med_WZ_DW_off, verifyResultValueNibble8,
		"DCML off WZ0x55555555", 3, 1, 0},
	{48, ML_CODE_DCML, setCodeOp2_DWZ_DN, setInputOp2_med_WZ_DW_on, verifyResultValueNibble8,
		"DCML on WZ0x55555555", 3, 1, -1431655766}, //0xAAAA AAAA
	{49, ML_CODE_DCML, setCodeOp2_WZ_WZ, setInputOp2_med_WZ_DW_off, verifyResultValueDWord,
		"DCML off WZ0x55555555", 2, 1, 0},
	{50, ML_CODE_DCML, setCodeOp2_WZ_WZ, setInputOp2_med_WZ_DW_on, verifyResultValueDWord,
		"DCML on WZ0x55555555", 2, 1, -1431655766}, //0xAAAA AAAA

	{51, ML_CODE_DCMLP, setCodeOp2_W_WZ, setInputSIn_sval32_DW_WZ_off, verifyResultValueDWord,
		"DCMLP 0->0 0x55555555", 0, 2, 0},
	{52, ML_CODE_DCMLP, setCodeOp2_W_WZ, setInputSIn_sval32p_DW_WZ_on, verifyResultValueDWord,
		"DCMLP 0->1 0x55555555", 0, 2, -1431655766}, //0xAAAA AAAA
	{53, ML_CODE_DCMLP, setCodeOp2_W_WZ, setInputSIn_sval32p_maxDW_WZ_on, verifyResultValueDWord,
		"DCMLP 0->1 2147483647", 0, 2, -2147483648}, //0x10000000
	{54, ML_CODE_DCMLP, setCodeOp2_medK_WZ, setInputOp2_none_off, verifyResultValueDWord,
		"DCMLP 0->0 K0x55555555", 0, 2, 0},
	{55, ML_CODE_DCMLP, setCodeOp2_medK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
		"DCMLP 0->1 K0x55555555", 0, 2, -1431655766}, //0xAAAA AAAA
	{56, ML_CODE_DCMLP, setCodeOp2_maxintDK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
		"DCMLP 0->1 K2147483647", 0, 2, -2147483648}, //0x10000000
	{57, ML_CODE_DCMLP, setCodeOp2_DN8_WZ, setInputOp2_Val32_4N_5555_off, verifyResultValueDWord,
		"DCMLP 0->0 N2 0x55555555", 0, 2, 0},
	{58, ML_CODE_DCMLP, setCodeOp2_DN8_WZ, setInputOp2_Val32p_4N_5555_on, verifyResultValueDWord,
		"DCMLP 0->1 N2 0x55555555", 0, 2, -1431655766}, //0xAAAA AAAA
	{59, ML_CODE_DCMLP, setCodeOp2_DN8_WZ, setInputSIn_maxp_DN_WZ_on, verifyResultValueDWord,
		"DCMLP 0->1 N2147483647", 0, 2, -2147483648}, //0x10000000
	{60, ML_CODE_DCMLP, setCodeOp2_N_WZ, setInputSIn_med_DN_WZ_off, verifyResultValueDWord,
		"DCMLP 0->0 N0x5555", 0, 2, 0},
	{61, ML_CODE_DCMLP, setCodeOp2_N_WZ, setInputSIn_medp_DN_WZ_on, verifyResultValueDWord,
		"DCMLP 0->1 N0x5555", 0, 2, -21846}, //0xFFFF AAAA
	{62, ML_CODE_DCMLP, setCodeOp2_WZ_W, setInputOp2_med_WZ_DW_off, verifyResultValueDWord,
		"DCMLP 0->0 WZ0x55555555", 1, 2, 0},
	{63, ML_CODE_DCMLP, setCodeOp2_WZ_W, setInputOp2_medp_WZ_DW_on, verifyResultValueDWord,
		"DCMLP 0->1 WZ0x55555555", 1, 2, -1431655766}, //0xAAAA AAAA
	{64, ML_CODE_DCMLP, setCodeOp2_DWZ_DN, setInputOp2_med_WZ_DW_off, verifyResultValueNibble8,
		"DCMLP 0->0 WZ0x55555555", 3, 2, 0},
	{65, ML_CODE_DCMLP, setCodeOp2_DWZ_DN, setInputOp2_medp_WZ_DW_on, verifyResultValueNibble8,
		"DCMLP 0->1 WZ0x55555555", 3, 2, -1431655766}, //0xAAAA AAAA
	{66, ML_CODE_DCMLP, setCodeOp2_WZ_WZ, setInputOp2_med_WZ_DW_off, verifyResultValueDWord,
		"DCMLP 0->0 WZ0x55555555", 2, 2, 0},
	{67, ML_CODE_DCMLP, setCodeOp2_WZ_WZ, setInputOp2_medp_WZ_DW_on, verifyResultValueDWord,
		"DCMLP 0->1 WZ0x55555555", 2, 2, -1431655766}, //0xAAAA AAAA

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};



int total_transfer_dwd_idx_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_transfer_dwd_idx_test_number; i++)
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

int setCodeOp2_medK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1431655765;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxintDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=2147483647;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_DN8_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_DWZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputSIn_sval32_DW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1431655765; //0x55555555

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_sval32_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1431655765;//0x55555555

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_sval32p_DW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1431655765;//0x55555555

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_sval32_maxDW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=2147483647;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_sval32p_maxDW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=2147483647;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_med_DN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1431655765;//0x55555555

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_med_DN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1431655765;//0x55555555

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_medp_DN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1431655765;//0x55555555

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_max_DN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=2147483647;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputSIn_maxp_DN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=2147483647;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_4N_5555_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x55555555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_4N_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x55555555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32p_4N_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x55555555;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_med_WZ_DW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1431655765;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_med_WZ_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1431655765;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp2_medp_WZ_DW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1431655765;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; // for Dword input

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_transfer_dword_idx(int tno, uint16 dummy)
{
	int i=1, inx=7, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	int res_word;
	long long res_nword;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					//for(inx=0; inx<15; inx++) // testidx
					{
						PLC_DEVICE_Init();

						in_pos = getPos(in, i);

						rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos, testidx[inx].pos, testidx[inx].val);
						if( rc2 == 0 ) continue;

						testCase[tno].setTestInput_fn(in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);

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
							if(testCase[tno].z_type==1 || testCase[tno].z_type==3) //op1 is index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
								if(rc == 1)
								{
									if(testCase[tno].z_type==1)
									{
										test_getDWord(&res_word, out, out_pos);
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d]=%d exp=%d\n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_word, testCase[tno].expected);
									}
									else
									{
										test_getNibble(&res_word, out, out_pos, 8);
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_N_%s[%d]=%d exp=%d\n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, res_word, testCase[tno].expected);
									}
								}
							}
							else // op2 is index or both are index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos+testidx[inx].val, testCase[tno].expected);
								if(rc == 1)
								{
									test_getDWord(&res_word, out, out_pos+testidx[inx].val);
									if(testCase[tno].z_type==0)
									{
										fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d+%d]=%d exp=%d \n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, reg[out], out_pos, testidx[inx].val, res_word, testCase[tno].expected);
									}
									else
									{
										fprintf(flog, "test case %d error cmd=%s in_%s[%d+%d] out_%s[%d+%d]=%d exp=%d \n", \
											tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
											reg[in], in_pos, testidx[inx].val, reg[out], out_pos, testidx[inx].val, res_word, testCase[tno].expected);
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

void testTransferDWordIndexCommand(void)
{
	int i, index=52;
	int start, end;
	char log[] = "err_trans_dword_idx.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("transfer dword index LOG file open error !\n");
		exit(1);
	}
#if 0
	for(index=56; index<62; index++)
	test_basic_transfer_dword_idx(index, 0);

#else
	total_transfer_dwd_idx_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DMOV);
	end = getTestCaseNumberEnd(ML_CODE_DCMLP); //ML_CODE_DCMLP

	DBG_LOGPRINT("testTransferDWordIndexCommand: %d to %d total %d\n", start, end, total_transfer_dwd_idx_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_transfer_dword_idx(index, 0);
	}
#endif
	fclose(flog);
}
#endif
