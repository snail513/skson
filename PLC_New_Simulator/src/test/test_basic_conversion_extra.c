/*
 * test_conversion_extra.c
 *
 *  Created on: Aug 11, 2015
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

#define BLK_CONV_CNT	4

extern void TestCodeInit(void);
extern void TestCodeTearDown(void);
extern int runTestCode(int run_step, char *testFuncName);

extern int verifyResultValueWord(int tcase, uint8 dest_reg, uint16 pos, short expected);
extern int verifyResultValueNibble4(int tcase, uint8 dest_reg, uint16 pos, short expected);
extern int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected);
extern int verifyResultValueFloat(int tcase, uint8 dest_reg, uint16 pos, float expected);

int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected);

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

static FILE *flog;

static int show_log=1;

static int isRangeOver(uint8 reg, uint16 pos, uint16 idx_val)
{
	uint16 lastpos[]={8191,8191,8191,8191,2047,8191,0, 12287, 8191};

	if(pos+idx_val < 0 || pos+idx_val > lastpos[reg]) return 1;

	return 0;
}

int setCodeOp_xNEG_W(uint16 ml_cmd, uint8 in, uint16 pos)
{
	if( in < OPERAND_ML_CODE_D ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_NEG_N16(uint16 ml_cmd, uint8 in, uint16 pos)
{
	if( in > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp_xNEG_WZ(uint16 ml_cmd, uint8 in, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in < OPERAND_ML_CODE_D ) return 0;
	if(isRangeOver(in, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_NEG_W16_off(uint8 in, uint16 in_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 21846);

	TestCodeTearDown();
}

void setInput_NEG_W16_on(uint8 in, uint16 in_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 21846);

	TestCodeTearDown();
}

void setInput_NEG_W16p_on(uint8 in, uint16 in_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 21846);

	TestCodeTearDown();
}

void setInput_NEG_N16_off(uint8 in, uint16 in_pos)
{
	int i;
	short value=21846;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput_NEG_N16_on(uint8 in, uint16 in_pos)
{
	int i;
	short value=21846;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput_NEG_N16p_on(uint8 in, uint16 in_pos)
{
	int i;
	short value=21846;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput_NEG_W16Z_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, 21846);

	TestCodeTearDown();
}

void setInput_NEG_W16Z_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, 21846);

	TestCodeTearDown();
}

void setInput_NEG_W16Zp_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, 21846);

	TestCodeTearDown();
}



int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected)
{
	int rc=0;
	int result;
	//int val;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};

	if(!test_getNibble(&result, dest_reg, pos, 8))
		return 1;
	//val = (short)result;
	if( show_log ) DBG_LOGPRINT("test=%d Nibble8 Reg %c[%d]=%d %d\n", tcase, reg[dest_reg], pos, result, expected);
	CU_ASSERT_EQUAL(result, expected);
	if(result != expected) rc=1;

	return rc;
}

static uint16 getWordPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12287,8191}}; //16bit

	return pos[inx_pos][reg];
}

static uint16 getDWordPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; //32bit

	return pos[inx_pos][reg];
}

void test_conv_NEG_W_off(int tno, uint16 ml_code, int run_step, short expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getWordPos(in, i);
			ml_rc = setCodeOp_xNEG_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_NEG_W16_off(in, in_pos);

			rc = runTestCode(run_step, "conversion word NEG off");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueWord(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getWord(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_NEG_W_on(int tno, uint16 ml_code, int run_step, short expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getWordPos(in, i);
			ml_rc = setCodeOp_xNEG_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_NEG_W16_on(in, in_pos);

			rc = runTestCode(run_step, "conversion word NEG on");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueWord(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getWord(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_NEGP_W_on(int tno, uint16 ml_code, int run_step, short expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getWordPos(in, i);
			ml_rc = setCodeOp_xNEG_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_NEG_W16p_on(in, in_pos);

			rc = runTestCode(run_step, "conversion word NEG on");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueWord(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getWord(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_NEG_N_off(int tno, uint16 ml_code, int run_step, short expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getWordPos(in, i);
			ml_rc = setCodeOp_NEG_N16(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_NEG_N16_off(in, in_pos);

			rc = runTestCode(run_step, "conversion nibble NEG off");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueNibble4(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getWord(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_NEG_N_on(int tno, uint16 ml_code, int run_step, short expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;
	long long res_nword;

	for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getWordPos(in, i);
			ml_rc = setCodeOp_NEG_N16(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_NEG_N16_on(in, in_pos);

			rc = runTestCode(run_step, "conversion nibble NEG on");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueNibble4(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getNibble(&res_nword, in, in_pos, 4);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_nword, expected);
				}
			}
		}
	}
}

void test_conv_NEGP_N_on(int tno, uint16 ml_code, int run_step, short expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getWordPos(in, i);
			ml_rc = setCodeOp_NEG_N16(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_NEG_N16p_on(in, in_pos);

			rc = runTestCode(run_step, "conversion nibble NEG on");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueNibble4(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getWord(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_NEG_Idx_off(int tno, uint16 ml_code, int run_step, short expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	short zVal;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getWordPos(in, i);
				ml_rc = setCodeOp_xNEG_WZ(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInput_NEG_W16Z_off(in, in_pos, testidx[inx].pos, testidx[inx].val);

				rc = runTestCode(run_step, "conversion index NEG off");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueWord(tno, in, in_pos+testidx[inx].val, expected);
					if(rc2 == 1)
					{
						test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
						test_getWord(&res_word, in, in_pos+zVal);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%d exp=%d\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, zVal, res_word, expected);
					}
				}
			}
		}
	}
}

void test_conv_NEG_Idx_on(int tno, uint16 ml_code, int run_step, short expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	short zVal;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getWordPos(in, i);
				ml_rc = setCodeOp_xNEG_WZ(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInput_NEG_W16Z_on(in, in_pos, testidx[inx].pos, testidx[inx].val);

				rc = runTestCode(run_step, "conversion index NEG on");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueWord(tno, in, in_pos+testidx[inx].val, expected);
					if(rc2 == 1)
					{
						test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
						test_getWord(&res_word, in, in_pos+zVal);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%d exp=%d\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, zVal, res_word, expected);
					}
				}
			}
		}
	}
}

void test_conv_NEGP_Idx_on(int tno, uint16 ml_code, int run_step, short expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	short zVal;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	short res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getWordPos(in, i);
				ml_rc = setCodeOp_xNEG_WZ(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInput_NEG_W16Zp_on(in, in_pos, testidx[inx].pos, testidx[inx].val);

				rc = runTestCode(run_step, "conversion index NEGP on");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueWord(tno, in, in_pos+testidx[inx].val, expected);
					if(rc2 == 1)
					{
						test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
						test_getWord(&res_word, in, in_pos+zVal);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%d exp=%d\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, zVal, res_word, expected);
					}
				}
			}
		}
	}
}

/*****************************************************************/

int setCodeOp_DNEG_N32(uint16 ml_cmd, uint8 in, uint16 pos)
{
	if( in > OPERAND_ML_CODE_B ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInput_DNEG_W32_off(uint8 in, uint16 in_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 218460);

	TestCodeTearDown();
}

void setInput_DNEG_W32_on(uint8 in, uint16 in_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 218460);

	TestCodeTearDown();
}

void setInput_DNEG_W32p_on(uint8 in, uint16 in_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, 218460);

	TestCodeTearDown();
}

void setInput_DNEG_N32_off(uint8 in, uint16 in_pos)
{
	int i;
	uint32 value=218460;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput_DNEG_N32_on(uint8 in, uint16 in_pos)
{
	int i;
	uint32 value=218460;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput_DNEG_N32p_on(uint8 in, uint16 in_pos)
{
	int i;
	uint32 value=218460;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInput_DNEG_W32Z_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, 218460);

	TestCodeTearDown();
}

void setInput_DNEG_W32Z_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, 218460);

	TestCodeTearDown();
}

void setInput_DNEG_W32Zp_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, 218460);

	TestCodeTearDown();
}

void test_conv_DNEG_W_off(int tno, uint16 ml_code, int run_step, int expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getDWordPos(in, i);
			ml_rc = setCodeOp_xNEG_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_DNEG_W32_off(in, in_pos);

			rc = runTestCode(run_step, "conversion word DNEG off");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueDWord(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getDWord(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_DNEG_W_on(int tno, uint16 ml_code, int run_step, int expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getDWordPos(in, i);
			ml_rc = setCodeOp_xNEG_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_DNEG_W32_on(in, in_pos);

			rc = runTestCode(run_step, "conversion word DNEG off");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueDWord(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getDWord(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_DNEGP_W_on(int tno, uint16 ml_code, int run_step, int expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getDWordPos(in, i);
			ml_rc = setCodeOp_xNEG_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_DNEG_W32p_on(in, in_pos);

			rc = runTestCode(run_step, "conversion word DNEGP on");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueDWord(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getDWord(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_DNEG_N_off(int tno, uint16 ml_code, int run_step, int expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;
	long long res_nword;

	for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getDWordPos(in, i);
			ml_rc = setCodeOp_DNEG_N32(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_DNEG_N32_off(in, in_pos);

			rc = runTestCode(run_step, "conversion nibble DNEG off");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueNibble8(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getNibble(&res_nword, in, in_pos, 8);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_nword, expected);
				}
			}
		}
	}
}

void test_conv_DNEG_N_on(int tno, uint16 ml_code, int run_step, int expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;
	long long res_nword;

	for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getDWordPos(in, i);
			ml_rc = setCodeOp_DNEG_N32(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_DNEG_N32_on(in, in_pos);

			rc = runTestCode(run_step, "conversion nibble DNEG on");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueNibble8(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getNibble(&res_nword, in, in_pos, 8);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_nword, expected);
				}
			}
		}
	}
}

void test_conv_DNEGP_N_on(int tno, uint16 ml_code, int run_step, int expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;
	long long res_nword;

	for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getDWordPos(in, i);
			ml_rc = setCodeOp_DNEG_N32(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_DNEG_N32p_on(in, in_pos);

			rc = runTestCode(run_step, "conversion nibble DNEGP 0->1");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueNibble8(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getNibble(&res_nword, in, in_pos, 8);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_nword, expected);
				}
			}
		}
	}
}

void test_conv_DNEG_Idx_off(int tno, uint16 ml_code, int run_step, int expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	short zVal;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getDWordPos(in, i);
				ml_rc = setCodeOp_xNEG_WZ(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInput_DNEG_W32Z_off(in, in_pos, testidx[inx].pos, testidx[inx].val);

				rc = runTestCode(run_step, "conversion index DNEG off");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueDWord(tno, in, in_pos+testidx[inx].val, expected);
					if(rc2 == 1)
					{
						test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
						test_getDWord(&res_word, in, in_pos+zVal);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%d exp=%d\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, zVal, res_word, expected);
					}
				}
			}
		}
	}
}

void test_conv_DNEG_Idx_on(int tno, uint16 ml_code, int run_step, int expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	short zVal;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getDWordPos(in, i);
				ml_rc = setCodeOp_xNEG_WZ(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInput_DNEG_W32Z_on(in, in_pos, testidx[inx].pos, testidx[inx].val);

				rc = runTestCode(run_step, "conversion index DNEG on");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueDWord(tno, in, in_pos+testidx[inx].val, expected);
					if(rc2 == 1)
					{
						test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
						test_getDWord(&res_word, in, in_pos+zVal);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%d exp=%d\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, zVal, res_word, expected);
					}
				}
			}
		}
	}
}

void test_conv_DNEGP_Idx_on(int tno, uint16 ml_code, int run_step, int expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	short zVal;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	int res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getDWordPos(in, i);
				ml_rc = setCodeOp_xNEG_WZ(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInput_DNEG_W32Zp_on(in, in_pos, testidx[inx].pos, testidx[inx].val);

				rc = runTestCode(run_step, "conversion index DNEGP on");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueDWord(tno, in, in_pos+testidx[inx].val, expected);
					if(rc2 == 1)
					{
						test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
						test_getDWord(&res_word, in, in_pos+zVal);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%d exp=%d\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, zVal, res_word, expected);
					}
				}
			}
		}
	}
}

/*****************************************************************/


void setInput_ENEG_W32_off(uint8 in, uint16 in_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 1.2345);

	TestCodeTearDown();
}

void setInput_ENEG_W32_on(uint8 in, uint16 in_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 1.2345);

	TestCodeTearDown();
}

void setInput_ENEG_W32p_on(uint8 in, uint16 in_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos, 1.2345);

	TestCodeTearDown();
}

void setInput_ENEG_W32Z_off(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 1.2345);

	TestCodeTearDown();
}

void setInput_ENEG_W32Z_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 1.2345);

	TestCodeTearDown();
}

void setInput_ENEG_W32Zp_on(uint8 in, uint16 in_pos, uint16 idx_pos, uint16 idx_val)
{
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToFloat(0, (uint8)in, in_pos+z_val, 1.2345);

	TestCodeTearDown();
}

void test_conv_ENEG_W_off(int tno, uint16 ml_code, int run_step, float expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getDWordPos(in, i);
			ml_rc = setCodeOp_xNEG_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_ENEG_W32_off(in, in_pos);

			rc = runTestCode(run_step, "conversion float ENEG off");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				printf("expected =%f\n", expected);
				rc2=verifyResultValueFloat(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getFloat(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_ENEG_W_on(int tno, uint16 ml_code, int run_step, float expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getDWordPos(in, i);
			ml_rc = setCodeOp_xNEG_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_ENEG_W32_on(in, in_pos);

			rc = runTestCode(run_step, "conversion float ENEG on");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueFloat(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getFloat(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_ENEGP_W_on(int tno, uint16 ml_code, int run_step, float expected)
{
	int i, j, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			PLC_DEVICE_Init();

			in_pos = getDWordPos(in, i);
			ml_rc = setCodeOp_xNEG_W(ml_code, in, in_pos);
			if(ml_rc == 0) continue;

			setInput_ENEG_W32p_on(in, in_pos);

			rc = runTestCode(run_step, "conversion float ENEG on");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueFloat(tno, in, in_pos, expected);
				if(rc2 == 1)
				{
					test_getFloat(&res_word, in, in_pos);
					fprintf(flog, "test case %d error cmd=%s %s[%d]=%d exp=%d\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[in], in_pos, res_word, expected);
				}
			}
		}
	}
}

void test_conv_ENEG_Idx_off(int tno, uint16 ml_code, int run_step, float expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	short zVal;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getDWordPos(in, i);
				ml_rc = setCodeOp_xNEG_WZ(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInput_ENEG_W32Z_off(in, in_pos, testidx[inx].pos, testidx[inx].val);

				rc = runTestCode(run_step, "conversion index ENEG off");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{	test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
					rc2=verifyResultValueFloat(tno, in, in_pos+zVal, expected);
					if(rc2 == 1)
					{
						test_getFloat(&res_word, in, in_pos+zVal);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%f exp=%f\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, zVal, res_word, expected);
					}
				}
			}
		}
	}
}

void test_conv_ENEG_Idx_on(int tno, uint16 ml_code, int run_step, float expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	short zVal;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getDWordPos(in, i);
				ml_rc = setCodeOp_xNEG_WZ(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInput_ENEG_W32Z_on(in, in_pos, testidx[inx].pos, testidx[inx].val);

				rc = runTestCode(run_step, "conversion index ENEG on");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
					rc2=verifyResultValueFloat(tno, in, in_pos+zVal, expected);
					if(rc2 == 1)
					{
						test_getFloat(&res_word, in, in_pos+zVal);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%f exp=%f\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, zVal, res_word, expected);
					}
				}
			}
		}
	}
}

void test_conv_ENEGP_Idx_on(int tno, uint16 ml_code, int run_step, float expected)
{
	int i, j, inx, rc, rc2, ml_rc;
	uint8 in;
	uint16 in_pos;
	short zVal;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};
	float res_word;

	for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
	{
		for(i=0; i<3; i++)
		{
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				in_pos = getDWordPos(in, i);
				ml_rc = setCodeOp_xNEG_WZ(ml_code, in, in_pos, testidx[inx].pos, testidx[inx].val);
				if(ml_rc == 0) continue;

				setInput_ENEG_W32Zp_on(in, in_pos, testidx[inx].pos, testidx[inx].val);

				rc = runTestCode(run_step, "conversion index ENEG on");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					test_getWord(&zVal, OPERAND_ML_CODE_Z, testidx[inx].pos);
					rc2=verifyResultValueFloat(tno, in, in_pos+zVal, expected);
					if(rc2 == 1)
					{
						test_getFloat(&res_word, in, in_pos+zVal);
						fprintf(flog, "test case %d error cmd=%s %s[%d+%d]=%f exp=%f\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[in], in_pos, zVal, res_word, expected);
					}
				}
			}
		}
	}
}

/*************************************************************/
uint16 blk_nop[BLK_CONV_CNT] = {0, 0, 0, 0};
uint16 blk_op1_bin[BLK_CONV_CNT] = {1234, 3456, 4567, 9999};
uint16 blk_op1_bcd[BLK_CONV_CNT] = {0x1234, 0x3456, 0x4567, 0x9999};

int setCodeOp3_W1W2W3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in == out && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperand(out, out_pos);
		addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_W1W2W3(uint8 in, uint16 in_pos, uint32 on_off, uint16 *src)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_CONV_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, src[i]);
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_CONV_CNT);

	TestCodeTearDown();
}

int setCodeOp3_W1W2N3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos
)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;
	if(c_reg > OPERAND_ML_CODE_B) return 0;

	if(in == out && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperand(out, out_pos);
		addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_W1W2N3(uint8 in, uint16 in_pos, uint8 c_reg, uint16 c_pos, uint32 on_off, uint16 *src)
{
	int i;
	short value=BLK_CONV_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_CONV_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, src[i]);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

int setCodeOp3_W1W2K3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in == out && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperand(out, out_pos);
		addMLOperand(OPERAND_ML_CODE_K, BLK_CONV_CNT);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_W1W2K3(uint8 in, uint16 in_pos, uint32 on_off, uint16 *src)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_CONV_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, src[i]);
	}

	TestCodeTearDown();
}

int setCodeOp3_W1W2Idx3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in == out && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperand(out, out_pos);
		addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInput_BK_W1W2Idx3(uint8 in, uint16 in_pos, uint8 idx_pos, uint16 idx_val,uint32 on_off, uint16 *src)
{
	int i;
	short z_val;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_CONV_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, src[i]);
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_CONV_CNT);

	TestCodeTearDown();
}

int verifyResultValueWordBlk(int tcase, uint8 dest_reg, uint16 pos, uint16 expected[])
{
	int i, rc=0;
	uint16 result[BLK_CONV_CNT];
	char *reg[] = {"X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	DBG_LOGPRINT("test=%d %s[%d]=", tcase, reg[dest_reg], pos);
	for(i=0; i<BLK_CONV_CNT; i++)
	{
		if(!test_getWord(&result[i], dest_reg, pos+i))
			return 1;

		if( show_log ) DBG_LOGPRINT("(%d:%d) ", result[i], expected[i]);
		CU_ASSERT_EQUAL(result[i], expected[i]);
		if(result[i] != expected[i]) rc=1;
	}
	DBG_LOGPRINT("\n");
	return rc;
}

static uint16 getWordBlkPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12284,8188}}; //1 word 4 block

	return pos[inx_pos][reg];
}

void test_blk_conv_W1W2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *src, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_CONV_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordBlkPos(in, i);
					ml_rc = setCodeOp3_W1W2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInput_BK_W1W2W3(in, in_pos, on_off, src);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block convert BTOBCD W1W2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueWordBlk(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] D[%d] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, c_pos);
							for(k=0; k<BLK_CONV_CNT; k++)
							{
								test_getWord(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], expected[k]);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_blk_conv_W1W2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *src, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_CONV_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordBlkPos(in, i);
						ml_rc = setCodeOp3_W1W2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInput_BK_W1W2N3(in, in_pos, c_reg, c_pos, on_off, src);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d c_reg=%d c_pos=%d\n", in, in_pos, out, out_pos, c_reg, c_pos);
						rc = runTestCode(run_step, "block convert BTOBCD W1W2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWordBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] N_%s[%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, reg[c_reg], c_pos);
								for(k=0; k<BLK_CONV_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected[k]);
								}
								fprintf(flog, "\n");
							}
						}
					}
				}
			}
		}
	}
}

void test_blk_conv_W1W2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *src, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_CONV_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordBlkPos(in, i);
					ml_rc = setCodeOp3_W1W2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInput_BK_W1W2K3(in, in_pos, on_off, src);

					DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block convert BTOBCD W1W2K3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueWordBlk(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] K4 : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_CONV_CNT; k++)
							{
								test_getWord(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], expected[k]);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_blk_conv_W1W2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *src, uint16 *expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_CONV_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordBlkPos(in, i);
						ml_rc = setCodeOp3_W1W2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						// max D(12288-5)
						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInput_BK_W1W2Idx3(in, in_pos, testidx[inx].pos, testidx[inx].val, on_off, src);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d c_reg=%d c_pos=%d\n", in, in_pos, out, out_pos, c_reg, c_pos);
						rc = runTestCode(run_step, "block convert BTOBCD W1W2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWordBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] D[%d+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, reg[c_reg], c_pos, testidx[inx].val);
								for(k=0; k<BLK_CONV_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected[k]);
								}
								fprintf(flog, "\n");
							}
						}
					}
				}
			}
		}
	}
}

void testConversionExtraCommand(void)
{
	char log[] = "err_conv_extra.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("conversion extra LOG file open error !\n");
		exit(1);
	}

#if 0
	test_conv_ENEGP_Idx_on(39, ML_CODE_ENEGP, 2, -1.2345);
#else
	test_conv_NEG_W_off(0, ML_CODE_NEG, 1, 21846);
	test_conv_NEG_W_on(1, ML_CODE_NEG, 1, -21846);
	test_conv_NEG_N_off(2, ML_CODE_NEG, 1, 21846);
	test_conv_NEG_N_on(3, ML_CODE_NEG, 1, -21846);
	test_conv_NEG_Idx_off(4, ML_CODE_NEG, 1, 21846);
	test_conv_NEG_Idx_on(5, ML_CODE_NEG, 1, -21846);

	test_conv_NEG_W_off(6, ML_CODE_NEGP, 2, 21846);
	test_conv_NEG_W_on(7, ML_CODE_NEGP, 2, 21846);
	test_conv_NEGP_W_on(8, ML_CODE_NEGP, 2, -21846);
	test_conv_NEG_N_off(9, ML_CODE_NEGP, 2, 21846);
	test_conv_NEG_N_on(10, ML_CODE_NEGP, 2, 21846);
	test_conv_NEGP_N_on(11, ML_CODE_NEGP, 2, -21846);
	test_conv_NEG_Idx_off(12, ML_CODE_NEGP, 2, 21846);
	test_conv_NEG_Idx_on(13, ML_CODE_NEGP, 2, 21846);
	test_conv_NEGP_Idx_on(14, ML_CODE_NEGP, 2, -21846);

	test_conv_DNEG_W_off(15, ML_CODE_DNEG, 1, 218460);
	test_conv_DNEG_W_on(16, ML_CODE_DNEG, 1, -218460);
	test_conv_DNEG_N_off(17, ML_CODE_DNEG, 1, 218460);
	test_conv_DNEG_N_on(18, ML_CODE_DNEG, 1, -218460);
	test_conv_DNEG_Idx_off(19, ML_CODE_DNEG, 1, 218460);
	test_conv_DNEG_Idx_on(20, ML_CODE_DNEG, 1, -218460);

	test_conv_DNEG_W_off(21, ML_CODE_DNEGP, 2, 218460);
	test_conv_DNEG_W_on(22, ML_CODE_DNEGP, 2, 218460);
	test_conv_DNEGP_W_on(23, ML_CODE_DNEGP, 2, -218460);
	test_conv_DNEG_N_off(24, ML_CODE_DNEGP, 2, 218460);
	test_conv_DNEG_N_on(25, ML_CODE_DNEGP, 2, 218460);
	test_conv_DNEGP_N_on(26, ML_CODE_DNEGP, 2, -218460);
	test_conv_DNEG_Idx_off(27, ML_CODE_DNEGP, 2, 218460);
	test_conv_DNEG_Idx_on(28, ML_CODE_DNEGP, 2, 218460);
	test_conv_DNEGP_Idx_on(29, ML_CODE_DNEGP, 2, -218460);

	test_conv_ENEG_W_off(30, ML_CODE_ENEG, 1, 1.2345);
	test_conv_ENEG_W_on(31, ML_CODE_ENEG, 1, -1.2345);
	test_conv_ENEG_Idx_off(32, ML_CODE_ENEG, 1, 1.2345);
	test_conv_ENEG_Idx_on(33, ML_CODE_ENEG, 1, -1.2345);

	test_conv_ENEG_W_off(34, ML_CODE_ENEGP, 2, 1.2345);
	test_conv_ENEG_W_on(35, ML_CODE_ENEGP, 2, 1.2345);
	test_conv_ENEGP_W_on(36, ML_CODE_ENEGP, 2, -1.2345);
	test_conv_ENEG_Idx_off(37, ML_CODE_ENEGP, 2, 1.2345);
	test_conv_ENEG_Idx_on(38, ML_CODE_ENEGP, 2, 1.2345);
	test_conv_ENEGP_Idx_on(39, ML_CODE_ENEGP, 2, -1.2345);

	test_blk_conv_W1W2W3(40, ML_CODE_BLKTOBCD, 0, 1, (uint16 *)blk_op1_bin, (uint16 *)blk_nop);
	test_blk_conv_W1W2W3(41, ML_CODE_BLKTOBCD, 1, 1, (uint16 *)blk_op1_bin, (uint16 *)blk_op1_bcd);
	test_blk_conv_W1W2N3(42, ML_CODE_BLKTOBCD, 0, 1, (uint16 *)blk_op1_bin, (uint16 *)blk_nop);
	test_blk_conv_W1W2N3(43, ML_CODE_BLKTOBCD, 1, 1, (uint16 *)blk_op1_bin, (uint16 *)blk_op1_bcd);
	test_blk_conv_W1W2K3(44, ML_CODE_BLKTOBCD, 0, 1, (uint16 *)blk_op1_bin, (uint16 *)blk_nop);
	test_blk_conv_W1W2K3(45, ML_CODE_BLKTOBCD, 1, 1, (uint16 *)blk_op1_bin, (uint16 *)blk_op1_bcd);
	test_blk_conv_W1W2Idx3(46, ML_CODE_BLKTOBCD, 0, 1, (uint16 *)blk_op1_bin, (uint16 *)blk_nop);
	test_blk_conv_W1W2Idx3(47, ML_CODE_BLKTOBCD, 1, 1, (uint16 *)blk_op1_bin, (uint16 *)blk_op1_bcd);

	test_blk_conv_W1W2W3(48, ML_CODE_BLKTOBCDP, 0, 2, (uint16 *)blk_op1_bin, (uint16 *)blk_nop);
	test_blk_conv_W1W2W3(49, ML_CODE_BLKTOBCDP, 2, 2, (uint16 *)blk_op1_bin, (uint16 *)blk_op1_bcd);
	test_blk_conv_W1W2N3(50, ML_CODE_BLKTOBCDP, 0, 2, (uint16 *)blk_op1_bin, (uint16 *)blk_nop);
	test_blk_conv_W1W2N3(51, ML_CODE_BLKTOBCDP, 2, 2, (uint16 *)blk_op1_bin, (uint16 *)blk_op1_bcd);
	test_blk_conv_W1W2K3(52, ML_CODE_BLKTOBCDP, 0, 2, (uint16 *)blk_op1_bin, (uint16 *)blk_nop);
	test_blk_conv_W1W2K3(53, ML_CODE_BLKTOBCDP, 2, 2, (uint16 *)blk_op1_bin, (uint16 *)blk_op1_bcd);
	test_blk_conv_W1W2Idx3(54, ML_CODE_BLKTOBCDP, 0, 2, (uint16 *)blk_op1_bin, (uint16 *)blk_nop);
	test_blk_conv_W1W2Idx3(55, ML_CODE_BLKTOBCDP, 2, 2, (uint16 *)blk_op1_bin, (uint16 *)blk_op1_bcd);

	test_blk_conv_W1W2W3(56, ML_CODE_BLKTOB, 0, 1, (uint16 *)blk_op1_bcd, (uint16 *)blk_nop);
	test_blk_conv_W1W2W3(57, ML_CODE_BLKTOB, 1, 1, (uint16 *)blk_op1_bcd, (uint16 *)blk_op1_bin);
	test_blk_conv_W1W2N3(58, ML_CODE_BLKTOB, 0, 1, (uint16 *)blk_op1_bcd, (uint16 *)blk_nop);
	test_blk_conv_W1W2N3(59, ML_CODE_BLKTOB, 1, 1, (uint16 *)blk_op1_bcd, (uint16 *)blk_op1_bin);
	test_blk_conv_W1W2K3(60, ML_CODE_BLKTOB, 0, 1, (uint16 *)blk_op1_bcd, (uint16 *)blk_nop);
	test_blk_conv_W1W2K3(61, ML_CODE_BLKTOB, 1, 1, (uint16 *)blk_op1_bcd, (uint16 *)blk_op1_bin);
	test_blk_conv_W1W2Idx3(62, ML_CODE_BLKTOB, 0, 1, (uint16 *)blk_op1_bcd, (uint16 *)blk_nop);
	test_blk_conv_W1W2Idx3(63, ML_CODE_BLKTOB, 1, 1, (uint16 *)blk_op1_bcd, (uint16 *)blk_op1_bin);

	test_blk_conv_W1W2W3(64, ML_CODE_BLKTOBP, 0, 2, (uint16 *)blk_op1_bcd, (uint16 *)blk_nop);
	test_blk_conv_W1W2W3(65, ML_CODE_BLKTOBP, 2, 2, (uint16 *)blk_op1_bcd, (uint16 *)blk_op1_bin);
	test_blk_conv_W1W2N3(66, ML_CODE_BLKTOBP, 0, 2, (uint16 *)blk_op1_bcd, (uint16 *)blk_nop);
	test_blk_conv_W1W2N3(67, ML_CODE_BLKTOBP, 2, 2, (uint16 *)blk_op1_bcd, (uint16 *)blk_op1_bin);
	test_blk_conv_W1W2K3(68, ML_CODE_BLKTOBP, 0, 2, (uint16 *)blk_op1_bcd, (uint16 *)blk_nop);
	test_blk_conv_W1W2K3(69, ML_CODE_BLKTOBP, 2, 2, (uint16 *)blk_op1_bcd, (uint16 *)blk_op1_bin);
	test_blk_conv_W1W2Idx3(70, ML_CODE_BLKTOBP, 0, 2, (uint16 *)blk_op1_bcd, (uint16 *)blk_nop);
	test_blk_conv_W1W2Idx3(71, ML_CODE_BLKTOBP, 2, 2, (uint16 *)blk_op1_bcd, (uint16 *)blk_op1_bin);
#endif

	fclose(flog);
}
#endif
