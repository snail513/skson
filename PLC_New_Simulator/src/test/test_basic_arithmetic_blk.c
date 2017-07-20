/*
 * test_basic_arithmetic_blk.c
 *
 *  Created on: Aug 24, 2015
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

#define BLK_ARITH_CNT_MAX	6

extern void TestCodeInit(void);
extern void TestCodeTearDown(void);
extern int runTestCode(int run_step, char *testFuncName);



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

short none_val[] = {0,0,0,0, 0, 0};
uint16 op1_val[]={1234, 4567, -2000, -1234, 32767, -32768};
uint16 op2_val[]={4000, 1234, -1234, -5000, 2, 2};
short add_val[]={5234, 5801, -3234, -6234, -32767, -32766};
short add_kval[]={5556, 8889, 2322, 3088, 0, 0};
short sub_val[]={-2766, 3333, -766, -3766, 32765, 32766};
short sub_kval[]={-2998, 245, -6322, -5324, 0, 0};

/*
uint16 op1_dval[]={600000, -800000, -123456, 999999, 2147483647, -2147483647};
uint16 op2_dval[]={123456, -111111, 222222, 333333, 2, 2};
int add_dval[]={723456, -911111, 98766, 13333332, -2147483647, -2147483645};
int sub_dval[]={476544, -688889, -345678, 666666, 2147483645, 2147483647};
int add_dkval[]={723456, -676544, 0, 1123455};
int sub_dkval[]={476544, -923456, -246912, 876543};
*/

static uint16 getWordBlkPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12282,8186}}; //1 word 6 block

	return pos[inx_pos][reg];
}

static uint16 getDWordBlkPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12280,8184}}; //2 word 4 block

	return pos[inx_pos][reg];
}

int verifyResultValueWordBlkN(int tcase, uint8 dest_reg, uint16 pos, uint16 count, short expected[])
{
	int i, rc=0;
	short result[BLK_ARITH_CNT_MAX];
	char *reg[] = {"X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	DBG_LOGPRINT("test=%d %s[%d]=", tcase, reg[dest_reg], pos);
	for(i=0; i<count; i++)
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

int verifyResultValueDWordBlkN(int tcase, uint8 dest_reg, uint16 pos, uint16 count, int expected[])
{
	int i, rc=0;
	int result[BLK_ARITH_CNT_MAX];
	char *reg[] = {"X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	DBG_LOGPRINT("test=%d %s[%d]=", tcase, reg[dest_reg], pos);
	for(i=0; i<count; i++)
	{
		if(!test_getDWord(&result[i], dest_reg, pos+i))
			return 1;

		if( show_log ) DBG_LOGPRINT("(%d:%d) ", result[i], expected[i]);
		CU_ASSERT_EQUAL(result[i], expected[i]);
		if(result[i] != expected[i]) rc=1;
	}
	DBG_LOGPRINT("\n");
	return rc;
}

int setCodeOp4_W1W2W3W4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos)
{
	if(in1 < OPERAND_ML_CODE_D || in2 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in1 == in2 && in1_pos == in2_pos) return 0;
	if(in1 == out && in1_pos == out_pos) return 0;
	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperand(in2, in2_pos);
		addMLOperand(out, out_pos); addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp4_W1W2W3K4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 count)
{
	if(in1 < OPERAND_ML_CODE_D || in2 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in1 == in2 && in1_pos == in2_pos) return 0;
	if(in1 == out && in1_pos == out_pos) return 0;
	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperand(in2, in2_pos);
		addMLOperand(out, out_pos); addMLOperand(OPERAND_ML_CODE_K, count);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp4_W1W2W3N4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint8 c_reg, uint16 c_pos)
{
	if(in1 < OPERAND_ML_CODE_D || in2 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in1 == in2 && in1_pos == in2_pos) return 0;
	if(in1 == out && in1_pos == out_pos) return 0;
	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperand(in2, in2_pos);
		addMLOperand(out, out_pos); addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp4_W1W2W3Idx4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint8 in2, uint16 in2_pos,
 uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if(in1 < OPERAND_ML_CODE_D || in2 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in1 == in2 && in1_pos == in2_pos) return 0;
	if(in1 == out && in1_pos == out_pos) return 0;
	if(in2 == out && in2_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperand(in2, in2_pos);
		addMLOperand(out, out_pos); addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp4_W1K2W3W4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint16 in2_val, uint8 out, uint16 out_pos)
{
	if(in1 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in1 == out && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperand(OPERAND_ML_CODE_K, in2_val);
		addMLOperand(out, out_pos); addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp4_W1K2W3K4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint16 in2_val,
 uint8 out, uint16 out_pos, uint16 count)
{
	if(in1 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in1 == out && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperand(OPERAND_ML_CODE_K, in2_val);
		addMLOperand(out, out_pos); addMLOperand(OPERAND_ML_CODE_K, count);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp4_W1K2W3N4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint16 in2_val,
 uint8 out, uint16 out_pos, uint8 c_reg, uint16 c_pos)
{
	if(in1 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in1 == out && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperand(OPERAND_ML_CODE_K, in2_val);
		addMLOperand(out, out_pos); addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp4_W1K2W3Idx4
(uint16 ml_cmd, uint8 in1, uint16 in1_pos, uint16 in2_val,
 uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if(in1 < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in1 == out && in1_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in1, in1_pos); addMLOperand(OPERAND_ML_CODE_K, in2_val);
		addMLOperand(out, out_pos); addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputBlk_W1W2W3W4
(uint8 in1, uint16 in1_pos, uint16 *in1_val,
 uint8 in2, uint16 in2_pos, uint16 *in2_val, uint16 count, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	DBG_LOGPRINT("BKSET [%s]:[%s]: ", opndic[in1].strType, opndic[in2].strType);
	for(i=0; i<count; i++)
	{
		DBG_LOGPRINT("[%d]%d:[%d]%d | ", in1_pos+i, in1_val[i], in2_pos+i, in2_val[i]);
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, in1_val[i]);
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, in2_val[i]);
	}
	DBG_LOGPRINT("\n");
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, count);

	TestCodeTearDown();
}

void setInputBlk_W1W2W3K4
(uint8 in1, uint16 in1_pos, uint16 *in1_val,
 uint8 in2, uint16 in2_pos, uint16 *in2_val, uint16 count, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	DBG_LOGPRINT("BKSET [%s]:[%s]: ", opndic[in1].strType, opndic[in2].strType);
	for(i=0; i<count; i++)
	{
		DBG_LOGPRINT("[%d]%d:[%d]%d | ", in1_pos+i, in1_val[i], in2_pos+i, in2_val[i]);
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, in1_val[i]);
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, in2_val[i]);
	}
	DBG_LOGPRINT("\n");
	TestCodeTearDown();
}

void setInputBlk_W1W2W3N4
(uint8 in1, uint16 in1_pos, uint16 *in1_val, uint8 in2, uint16 in2_pos, uint16 *in2_val,
 uint8 c_reg, uint16 c_pos, uint16 count, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	DBG_LOGPRINT("BKSET [%s]:[%s]: ", opndic[in1].strType, opndic[in2].strType);
	for(i=0; i<count; i++)
	{
		DBG_LOGPRINT("[%d]%d:[%d]%d | ", in1_pos+i, in1_val[i], in2_pos+i, in2_val[i]);
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, in1_val[i]);
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, in2_val[i]);
	}
	DBG_LOGPRINT("\n");
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((count>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputBlk_W1W2W3Idx4
(uint8 in1, uint16 in1_pos, uint16 *in1_val, uint8 in2, uint16 in2_pos, uint16 *in2_val,
 uint16 idx_pos, uint16 idx_val, uint16 count, uint32 on_off)
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

	DBG_LOGPRINT("BKSET [%s]:[%s]: ", opndic[in1].strType, opndic[in2].strType);
	for(i=0; i<count; i++)
	{
		DBG_LOGPRINT("[%d]%d:[%d]%d | ", in1_pos+i, in1_val[i], in2_pos+i, in2_val[i]);
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, in1_val[i]);
		addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, in2_val[i]);
	}
	DBG_LOGPRINT("\n");
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, count);

	TestCodeTearDown();
}

void setInputBlk_W1K2W3W4
(uint8 in1, uint16 in1_pos, uint16 *in1_val, uint16 count, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	DBG_LOGPRINT("BKSET [%s]: ", opndic[in1].strType);
	for(i=0; i<count; i++)
	{
		DBG_LOGPRINT("[%d]%d | ", in1_pos+i, in1_val[i]);
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, in1_val[i]);
		//addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, in2_val[i]);
	}
	DBG_LOGPRINT("\n");
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, count);

	TestCodeTearDown();
}

void setInputBlk_W1K2W3K4
(uint8 in1, uint16 in1_pos, uint16 *in1_val, uint16 count, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	DBG_LOGPRINT("BKSET [%s]: ", opndic[in1].strType);
	for(i=0; i<count; i++)
	{
		DBG_LOGPRINT("[%d]%d | ", in1_pos+i, in1_val[i]);
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, in1_val[i]);
		//addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, in2_val[i]);
	}
	DBG_LOGPRINT("\n");

	TestCodeTearDown();
}

void setInputBlk_W1K2W3N4
(uint8 in1, uint16 in1_pos, uint16 *in1_val, uint8 c_reg, uint16 c_pos,
 uint16 count, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	DBG_LOGPRINT("BKSET [%s]: ", opndic[in1].strType);
	for(i=0; i<count; i++)
	{
		DBG_LOGPRINT("[%d]%d | ", in1_pos+i, in1_val[i]);
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, in1_val[i]);
		//addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, in2_val[i]);
	}
	DBG_LOGPRINT("\n");
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((count>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputBlk_W1K2W3Idx4
(uint8 in1, uint16 in1_pos, uint16 *in1_val, uint16 idx_pos, uint16 idx_val,
 uint16 count, uint32 on_off)
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

	DBG_LOGPRINT("BKSET [%s]: ", opndic[in1].strType);
	for(i=0; i<count; i++)
	{
		DBG_LOGPRINT("[%d]%d | ", in1_pos+i, in1_val[i]);
		addDeviceControlInstruction(0, (uint8)in1, in1_pos+i, in1_val[i]);
		//addDeviceControlInstruction(0, (uint8)in2, in2_pos+i, in2_val[i]);
	}
	DBG_LOGPRINT("\n");
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, count);

	TestCodeTearDown();
}

/*
void setInputBlk_DW1W2W3W4
(uint8 in1, uint16 in1_pos, int *in1_val,
 uint8 in2, uint16 in2_pos, int *in2_val, uint16 count, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<count; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, in1_val[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, in2_val[i]);
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, count);

	TestCodeTearDown();
}

void setInputBlk_DW1W2W3K4
(uint8 in1, uint16 in1_pos, int *in1_val,
 uint8 in2, uint16 in2_pos, int *in2_val, uint16 count, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<count; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, in1_val[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, in2_val[i]);
	}

	TestCodeTearDown();
}

void setInputBlk_DW1W2W3N4
(uint8 in1, uint16 in1_pos, int *in1_val, uint8 in2, uint16 in2_pos, int *in2_val,
 uint8 c_reg, uint16 c_pos, uint16 count, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<count; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, in1_val[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, in2_val[i]);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((count>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputBlk_DW1W2W3Idx4
(uint8 in1, uint16 in1_pos, int *in1_val, uint8 in2, uint16 in2_pos, int *in2_val,
 uint16 idx_pos, uint16 idx_val, uint16 count, uint32 on_off)
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

	for(i=0; i<count; i++)
	{
		addDeviceControlInstructionToDWord(0, (uint8)in1, in1_pos, in1_val[i]);
		addDeviceControlInstructionToDWord(0, (uint8)in2, in2_pos, in2_val[i]);
	}

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, count);

	TestCodeTearDown();
}
*/

void test_blk_arith_W1W2W3W4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, short *in1_val, short *in2_val, short *expected)
{
	int i=1, j=1, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	short result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);

			//for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
			{
			//for(j=0; j<3; j++)
			{
				in2_pos = getWordBlkPos(in2, j);
				for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
				{
				//for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in1_pos = getWordBlkPos(in1, i);
					ml_rc = setCodeOp4_W1W2W3W4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_W1W2W3W4(in1, in1_pos, in1_val, in2, in2_pos, in2_val, count, on_off);

					DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d in2=%d in2_pos=%d\n", out, out_pos, in1, in1_pos, in2, in2_pos);
					rc = runTestCode(run_step, "Arithmetic blk W1W2W3W4 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueWordBlkN(tno, out, out_pos, count, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos);
							for(k=0; k<count; k++)
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
}

void test_blk_arith_W1W2W3K4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, short *in1_val, short *in2_val, short expected[])
{
	int i=1, j=1, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	short result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);

			//for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
			{
			//for(j=0; j<3; j++)
			{
				in2_pos = getWordBlkPos(in2, j);
				//for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
				{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in1_pos = getWordBlkPos(in1, i);
					ml_rc = setCodeOp4_W1W2W3K4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, count);
					if(ml_rc == 0) continue;

					setInputBlk_W1W2W3K4(in1, in1_pos, in1_val, in2, in2_pos, in2_val, count, on_off);

					DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d in2=%d in2_pos=%d\n", out, out_pos, in1, in1_pos, in2, in2_pos);
					rc = runTestCode(run_step, "Arithmetic blk W1W2W3K4 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueWordBlkN(tno, out, out_pos, count, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] K%d : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, count);
							for(k=0; k<count; k++)
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
}

void test_blk_arith_W1W2W3N4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, short *in1_val, short *in2_val, short *expected)
{
	int i=1, j=1, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	short result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);

			//for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
			{
			//for(j=0; j<3; j++)
			{
				in2_pos = getWordBlkPos(in2, j);
				//for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
				{
				for(i=0; i<3; i++)
				{
					//for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
					{
						PLC_DEVICE_Init();

						in1_pos = getWordBlkPos(in1, i);
						ml_rc = setCodeOp4_W1W2W3N4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputBlk_W1W2W3N4(in1, in1_pos, in1_val, in2, in2_pos, in2_val, c_reg, c_pos, count, on_off);

						DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d in2=%d in2_pos=%d\n", out, out_pos, in1, in1_pos, in2, in2_pos);
						rc = runTestCode(run_step, "Arithmetic blk W1W2W3N4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWordBlkN(tno, out, out_pos, count, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] N_%s[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, reg[c_reg]);
								for(k=0; k<count; k++)
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
	}
}

void test_blk_arith_W1W2W3Idx4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, short *in1_val, short *in2_val, short *expected)
{
	int i=1, j=1, k, inx=7, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	short result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);

			//for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
			{
			//for(j=0; j<3; j++)
			{
				in2_pos = getWordBlkPos(in2, j);
				//for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
				{
				for(i=0; i<3; i++)
				{
					//for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in1_pos = getWordBlkPos(in1, i);
						ml_rc = setCodeOp4_W1W2W3Idx4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						//index range check for D (op4)
						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputBlk_W1W2W3Idx4(in1, in1_pos, in1_val, in2, in2_pos, in2_val, testidx[inx].pos, testidx[inx].val, count, on_off);

						DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d in2=%d in2_pos=%d\n", out, out_pos, in1, in1_pos, in2, in2_pos);
						rc = runTestCode(run_step, "Arithmetic blk W1W2W3Idx4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWordBlkN(tno, out, out_pos, count, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] D[500+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<count; k++)
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
	}
}

void test_blk_arith_W1K2W3W4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, short *in1_val, short in2_val, short *expected)
{
	int i=1, j=1, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	short result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			//for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in1_pos = getWordBlkPos(in1, i);
					ml_rc = setCodeOp4_W1K2W3W4(ml_code, in1, in1_pos, in2_val, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_W1K2W3W4(in1, in1_pos, in1_val, count, on_off);

					DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d\n", out, out_pos, in1, in1_pos);
					rc = runTestCode(run_step, "Arithmetic blk W1K2W3W4 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueWordBlkN(tno, out, out_pos, count, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] K%d %s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in1], in1_pos, in2_val, reg[out], out_pos);
							for(k=0; k<count; k++)
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


void test_blk_arith_W1K2W3K4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, short *in1_val, short in2_val, short *expected)
{
	int i=1, j=1, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	short result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			//for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in1_pos = getWordBlkPos(in1, i);
					ml_rc = setCodeOp4_W1K2W3K4(ml_code, in1, in1_pos, in2_val, out, out_pos, count);
					if(ml_rc == 0) continue;

					setInputBlk_W1K2W3K4(in1, in1_pos, in1_val, count, on_off);

					DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d\n", out, out_pos, in1, in1_pos);
					rc = runTestCode(run_step, "Arithmetic blk W1K2W3K4 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueWordBlkN(tno, out, out_pos, count, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] K%d %s[%d] K%d : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in1], in1_pos, in2_val, reg[out], out_pos, count);
							for(k=0; k<count; k++)
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

void test_blk_arith_W1K2W3N4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, short *in1_val, short in2_val, short *expected)
{
	int i=1, j=1, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	short result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			//for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{

				for(i=0; i<3; i++)
				{
					//for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
					{
						PLC_DEVICE_Init();

						in1_pos = getWordBlkPos(in1, i);
						ml_rc = setCodeOp4_W1K2W3N4(ml_code, in1, in1_pos, in2_val, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputBlk_W1K2W3N4(in1, in1_pos, in1_val, c_reg, c_pos, count, on_off);

						DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d\n", out, out_pos, in1, in1_pos);
						rc = runTestCode(run_step, "Arithmetic blk W1K2W3N4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWordBlkN(tno, out, out_pos, count, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] K%d %s[%d] N_%s[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in1], in1_pos, in2_val, reg[out], out_pos, reg[c_reg]);
								for(k=0; k<count; k++)
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

void test_blk_arith_W1K2W3Idx4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, short *in1_val, short in2_val, short *expected)
{
	int i=1, j=1, k, inx=7, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	short result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			//for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
			{
				for(i=0; i<3; i++)
				{
					//for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in1_pos = getWordBlkPos(in1, i);
						ml_rc = setCodeOp4_W1K2W3Idx4(ml_code, in1, in1_pos, in2_val, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputBlk_W1K2W3Idx4(in1, in1_pos, in1_val, testidx[inx].pos, testidx[inx].val, count, on_off);

						DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d\n", out, out_pos, in1, in1_pos);
						rc = runTestCode(run_step, "Arithmetic blk W1K2W3Idx4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueWordBlkN(tno, out, out_pos, count, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] K%d %s[%d] D[500+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in1], in1_pos, in2_val, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<count; k++)
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

/*
void test_blk_arith_DW1W2W3W4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, int *in1_val, int *in2_val, int *expected)
{
	int i=1, j=1, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	int result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordBlkPos(out, olast);

			//for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
			{
			for(j=0; j<3; j++)
			{
				in2_pos = getDWordBlkPos(in2, j);
				for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
				{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in1_pos = getDWordBlkPos(in1, i);
					ml_rc = setCodeOp4_W1W2W3W4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_DW1W2W3W4(in1, in1_pos, in1_val, in2, in2_pos, in2_val, count, on_off);

					DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d in2=%d in2_pos=%d\n", out, out_pos, in1, in1_pos, in2, in2_pos);
					rc = runTestCode(run_step, "Arithmetic Dword blk DW1W2W3W4 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueDWordBlkN(out, out_pos, count, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos);
							for(k=0; k<count; k++)
							{
								test_getDWord(&result[k], out, out_pos+k);
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
}

void test_blk_arith_DW1W2W3K4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, int *in1_val, int *in2_val, int *expected)
{
	int i=1, j=1, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	int result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordBlkPos(out, olast);

			for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
			{
			for(j=0; j<3; j++)
			{
				in2_pos = getDWordBlkPos(in2, j);
				for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
				{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in1_pos = getDWordBlkPos(in1, i);
					ml_rc = setCodeOp4_W1W2W3K4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, count);
					if(ml_rc == 0) continue;

					setInputBlk_DW1W2W3W4(in1, in1_pos, in1_val, in2, in2_pos, in2_val, count, on_off);

					DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d in2=%d in2_pos=%d\n", out, out_pos, in1, in1_pos, in2, in2_pos);
					rc = runTestCode(run_step, "Arithmetic Dword blk DW1W2W3W4 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueDWordBlkN(out, out_pos, count, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos);
							for(k=0; k<count; k++)
							{
								test_getDWord(&result[k], out, out_pos+k);
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
}

void test_blk_arith_DW1W2W3N4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, int *in1_val, int *in2_val, int *expected)
{
	int i=1, j=1, k, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	int result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordBlkPos(out, olast);

			for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
			{
			for(j=0; j<3; j++)
			{
				in2_pos = getDWordBlkPos(in2, j);
				for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
				{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in1_pos = getDWordBlkPos(in1, i);
					ml_rc = setCodeOp4_W1W2W3N4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, c_reg, c_pos);
					if(ml_rc == 0) continue;

					setInputBlk_DW1W2W3N4(in1, in1_pos, in1_val, in2, in2_pos, in2_val, c_reg, c_pos, count, on_off);

					DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d in2=%d in2_pos=%d\n", out, out_pos, in1, in1_pos, in2, in2_pos);
					rc = runTestCode(run_step, "Arithmetic Dword blk DW1W2W3N4 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueDWordBlkN(out, out_pos, count, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] N_%s[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, reg[c_reg]);
							for(k=0; k<count; k++)
							{
								test_getDWord(&result[k], out, out_pos+k);
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
}

void test_blk_arith_DW1W2W3Idx4
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 count, int *in1_val, int *in2_val, int *expected)
{
	int i=1, j=1, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in1=OPERAND_ML_CODE_D, in2=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_D;
	uint16 in1_pos, in2_pos, out_pos, c_pos=160;
	int result[BLK_ARITH_CNT_MAX];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getDWordBlkPos(out, olast);

			//for(in2=OPERAND_ML_CODE_D; in2<=OPERAND_ML_CODE_W; in2++)
			{
			for(j=0; j<3; j++)
			{
				in2_pos = getDWordBlkPos(in2, j);
				for(in1=OPERAND_ML_CODE_D; in1<=OPERAND_ML_CODE_W; in1++)
				{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in1_pos = getDWordBlkPos(in1, i);
						ml_rc = setCodeOp4_W1W2W3Idx4(ml_code, in1, in1_pos, in2, in2_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputBlk_DW1W2W3Idx4(in1, in1_pos, in1_val, in2, in2_pos, in2_val, testidx[inx].pos, testidx[inx].val, count, on_off);

						DBG_LOGPRINT("out=%d pos=%d in1=%d in1_pos=%d in2=%d in2_pos=%d\n", out, out_pos, in1, in1_pos, in2, in2_pos);
						rc = runTestCode(run_step, "Arithmetic Dword blk DW1W2W3Idx4 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueDWordBlkN(out, out_pos, count, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] %s[%d] D[500+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in1], in1_pos, reg[in2], in2_pos, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<count; k++)
								{
									test_getDWord(&result[k], out, out_pos+k);
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
	}
}

*/

void testBasicArithmeticBlockCommand(void)
{
	char log[] = "err_arith_blk.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic block LOG file open error !\n");
		exit(1);
	}

#if 0
	test_blk_arith_W1K2W3Idx4(67, ML_CODE_BKSUBP, 2, 2, 4, (uint16 *)op1_val, 4322, (short *)sub_kval);
#else
	//test_blk_arith_W1W2W3W4(0, ML_CODE_BKADD, 0, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	//test_blk_arith_W1W2W3W4(1, ML_CODE_BKADD, 1, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)add_val);
	//test_blk_arith_W1W2W3W4(2, ML_CODE_BKADD, 1, 1, 0, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	//test_blk_arith_W1W2W3K4(3, ML_CODE_BKADD, 0, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	/*	test_blk_arith_W1W2W3K4(4, ML_CODE_BKADD, 1, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)add_val);
	test_blk_arith_W1W2W3N4(5, ML_CODE_BKADD, 0, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3N4(6, ML_CODE_BKADD, 1, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)add_val);
	test_blk_arith_W1W2W3Idx4(7, ML_CODE_BKADD, 0, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3Idx4(8, ML_CODE_BKADD, 1, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)add_val);
	test_blk_arith_W1K2W3W4(9, ML_CODE_BKADD, 0, 1, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3W4(10, ML_CODE_BKADD, 1, 1, 4, (uint16 *)op1_val, 4322, (short *)add_kval);
	test_blk_arith_W1K2W3K4(11, ML_CODE_BKADD, 0, 1, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3K4(12, ML_CODE_BKADD, 1, 1, 4, (uint16 *)op1_val, 4322, (short *)add_kval);
	test_blk_arith_W1K2W3N4(13, ML_CODE_BKADD, 0, 1, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3N4(14, ML_CODE_BKADD, 1, 1, 4, (uint16 *)op1_val, 4322, (short *)add_kval);
	test_blk_arith_W1K2W3Idx4(15, ML_CODE_BKADD, 0, 1, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3Idx4(16, ML_CODE_BKADD, 1, 1, 4, (uint16 *)op1_val, 4322, (short *)add_kval);

	test_blk_arith_W1W2W3W4(17, ML_CODE_BKADDP, 0, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3W4(18, ML_CODE_BKADDP, 2, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)add_val);
	test_blk_arith_W1W2W3W4(19, ML_CODE_BKADDP, 2, 2, 0, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3K4(20, ML_CODE_BKADDP, 0, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3K4(21, ML_CODE_BKADDP, 2, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)add_val);
	test_blk_arith_W1W2W3N4(22, ML_CODE_BKADDP, 0, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3N4(23, ML_CODE_BKADDP, 2, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)add_val);
	test_blk_arith_W1W2W3Idx4(24, ML_CODE_BKADDP, 0, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3Idx4(25, ML_CODE_BKADDP, 2, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)add_val);
	test_blk_arith_W1K2W3W4(26, ML_CODE_BKADDP, 0, 2, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3W4(27, ML_CODE_BKADDP, 2, 2, 4, (uint16 *)op1_val, 4322, (short *)add_kval);
	test_blk_arith_W1K2W3K4(28, ML_CODE_BKADDP, 0, 2, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3K4(29, ML_CODE_BKADDP, 2, 2, 4, (uint16 *)op1_val, 4322, (short *)add_kval);
	test_blk_arith_W1K2W3N4(30, ML_CODE_BKADDP, 0, 2, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3N4(31, ML_CODE_BKADDP, 2, 2, 4, (uint16 *)op1_val, 4322, (short *)add_kval);
	test_blk_arith_W1K2W3Idx4(32, ML_CODE_BKADDP, 0, 2, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3Idx4(33, ML_CODE_BKADDP, 2, 2, 4, (uint16 *)op1_val, 4322, (short *)add_kval);

	test_blk_arith_W1W2W3W4(34, ML_CODE_BKSUB, 0, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3W4(35, ML_CODE_BKSUB, 1, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)sub_val);
	test_blk_arith_W1W2W3W4(36, ML_CODE_BKSUB, 1, 1, 0, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3K4(37, ML_CODE_BKSUB, 0, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3K4(38, ML_CODE_BKSUB, 1, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)sub_val);
	test_blk_arith_W1W2W3N4(39, ML_CODE_BKSUB, 0, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3N4(40, ML_CODE_BKSUB, 1, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)sub_val);
	test_blk_arith_W1W2W3Idx4(41, ML_CODE_BKSUB, 0, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3Idx4(42, ML_CODE_BKSUB, 1, 1, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)sub_val);
	test_blk_arith_W1K2W3W4(43, ML_CODE_BKSUB, 0, 1, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3W4(44, ML_CODE_BKSUB, 1, 1, 4, (uint16 *)op1_val, 4322, (short *)sub_kval);
	test_blk_arith_W1K2W3K4(45, ML_CODE_BKSUB, 0, 1, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3K4(46, ML_CODE_BKSUB, 1, 1, 4, (uint16 *)op1_val, 4322, (short *)sub_kval);
	test_blk_arith_W1K2W3N4(47, ML_CODE_BKSUB, 0, 1, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3N4(48, ML_CODE_BKSUB, 1, 1, 4, (uint16 *)op1_val, 4322, (short *)sub_kval);
	test_blk_arith_W1K2W3Idx4(49, ML_CODE_BKSUB, 0, 1, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3Idx4(50, ML_CODE_BKSUB, 1, 1, 4, (uint16 *)op1_val, 4322, (short *)sub_kval);
*/
	test_blk_arith_W1W2W3W4(51, ML_CODE_BKSUBP, 0, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3W4(52, ML_CODE_BKSUBP, 2, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)sub_val);
	test_blk_arith_W1W2W3W4(53, ML_CODE_BKSUBP, 2, 2, 0, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3K4(54, ML_CODE_BKSUBP, 0, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3K4(55, ML_CODE_BKSUBP, 2, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)sub_val);
	test_blk_arith_W1W2W3N4(56, ML_CODE_BKSUBP, 0, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3N4(57, ML_CODE_BKSUBP, 2, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)sub_val);
	test_blk_arith_W1W2W3Idx4(58, ML_CODE_BKSUBP, 0, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)none_val);
	test_blk_arith_W1W2W3Idx4(59, ML_CODE_BKSUBP, 2, 2, 6, (uint16 *)op1_val, (uint16 *)op2_val, (short *)sub_val);
	test_blk_arith_W1K2W3W4(60, ML_CODE_BKSUBP, 0, 2, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3W4(61, ML_CODE_BKSUBP, 2, 2, 4, (uint16 *)op1_val, 4322, (short *)sub_kval);
	test_blk_arith_W1K2W3K4(62, ML_CODE_BKSUBP, 0, 2, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3K4(63, ML_CODE_BKSUBP, 2, 2, 4, (uint16 *)op1_val, 4322, (short *)sub_kval);
	test_blk_arith_W1K2W3N4(64, ML_CODE_BKSUBP, 0, 2, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3N4(65, ML_CODE_BKSUBP, 2, 2, 4, (uint16 *)op1_val, 4322, (short *)sub_kval);
	test_blk_arith_W1K2W3Idx4(66, ML_CODE_BKSUBP, 0, 2, 4, (uint16 *)op1_val, 4322, (short *)none_val);
	test_blk_arith_W1K2W3Idx4(67, ML_CODE_BKSUBP, 2, 2, 4, (uint16 *)op1_val, 4322, (short *)sub_kval);

	/*
	test_blk_arith_DW1W2W3W4(68, ML_CODE_DBKADD, 0, 1, 6, (uint16 *)op1_dval, (uint16 *)op2_dval, (int *)none_val);
	test_blk_arith_DW1W2W3W4(69, ML_CODE_DBKADD, 1, 1, 6, (uint16 *)op1_dval, (uint16 *)op2_dval, (int *)add_dval);
	test_blk_arith_DW1W2W3W4(70, ML_CODE_DBKADD, 1, 1, 0, (uint16 *)op1_dval, (uint16 *)op2_dval, (int *)none_val);
	test_blk_arith_W1W2W3K4(71, ML_CODE_DBKADD, 0, 1, 6, (uint16 *)op1_dval, (uint16 *)op2_dval, (int *)none_val);
	test_blk_arith_W1W2W3K4(72, ML_CODE_DBKADD, 1, 1, 6, (uint16 *)op1_dval, (uint16 *)op2_dval, (int *)add_dval);
	test_blk_arith_W1W2W3N4(73, ML_CODE_DBKADD, 0, 1, 6, (uint16 *)op1_dval, (uint16 *)op2_dval, (int *)none_val);
	test_blk_arith_W1W2W3N4(74, ML_CODE_DBKADD, 1, 1, 6, (uint16 *)op1_dval, (uint16 *)op2_dval, (int *)add_dval);
	test_blk_arith_W1W2W3Idx4(75, ML_CODE_DBKADD, 0, 1, 6, (uint16 *)op1_dval, (uint16 *)op2_dval, (int *)none_val);
	test_blk_arith_W1W2W3Idx4(76, ML_CODE_DBKADD, 1, 1, 6, (uint16 *)op1_dval, (uint16 *)op2_dval, (int *)add_dval);
	test_blk_arith_W1K2W3W4(77, ML_CODE_DBKADD, 0, 1, 4, (uint16 *)op1_dval, 123456, (int *)none_val);
	test_blk_arith_W1K2W3W4(78, ML_CODE_DBKADD, 1, 1, 4, (uint16 *)op1_dval, 123456, (int *)add_dkval);
	test_blk_arith_W1K2W3K4(79, ML_CODE_DBKADD, 0, 1, 4, (uint16 *)op1_dval, 123456, (int *)none_val);
	test_blk_arith_W1K2W3K4(80, ML_CODE_DBKADD, 1, 1, 4, (uint16 *)op1_dval, 123456, (int *)add_dkval);
	test_blk_arith_W1K2W3N4(81, ML_CODE_DBKADD, 0, 1, 4, (uint16 *)op1_dval, 123456, (int *)none_val);
	test_blk_arith_W1K2W3N4(82, ML_CODE_DBKADD, 1, 1, 4, (uint16 *)op1_dval, 123456, (int *)add_dkval);
	test_blk_arith_W1K2W3Idx4(83, ML_CODE_DBKADD, 0, 1, 4, (uint16 *)op1_dval, 123456, (int *)none_val);
	test_blk_arith_W1K2W3Idx4(84, ML_CODE_DBKADD, 1, 1, 4, (uint16 *)op1_dval, 123456, (int *)add_dkval);
*/
#endif

	fclose(flog);
}
#endif