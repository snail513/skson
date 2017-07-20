/*
 * test_basic_transfer_blk.c
 *
 *  Created on: Aug 21, 2015
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

#define BLK_XCH_CNT 	4

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

uint16 bxch_in[BLK_XCH_CNT] = {0x0F0F,0xFF00,0x00FF,0xAAAA};
uint16 bxch_out[BLK_XCH_CNT] = {0x3333,0xC3C3,0xFF00,0xFFFF};

static FILE *flog;

static int show_log=1;

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

static uint16 getWordBlkPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12284,8188}}; //1 word 4 block

	return pos[inx_pos][reg];
}

static uint16 getWordN2BlkPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12284,8188}}; //N2X

	return pos[inx_pos][reg];
}

static uint16 getWordN4BlkPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8128,8128,8128,8128,1984,8128,0,12284,8188}}; //N4X

	return pos[inx_pos][reg];
}

int setCodeOp3Blk_W1W2W3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
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


void setInputBlk_W1W2W3_all
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint16 *out_val, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, in_val[i]);
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, out_val[i]);
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_XCH_CNT);

	TestCodeTearDown();
}

int setCodeOp3Blk_W1W2N3
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

void setInputBlk_W1W2N3_all
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint16 *out_val,
 uint8 c_reg, uint16 c_pos, uint32 on_off)
{
	int i;
	short value=BLK_XCH_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, in_val[i]);
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, out_val[i]);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

int setCodeOp3Blk_W1W2K3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in == out && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperand(out, out_pos);
		addMLOperand(OPERAND_ML_CODE_K, BLK_XCH_CNT);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputBlk_W1W2K3_all
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint16 *out_val, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, in_val[i]);
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, out_val[i]);
	}

	TestCodeTearDown();
}

int setCodeOp3Blk_W1W2Idx3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos)
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

void setInputBlk_W1W2Idx3_all
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint16 *out_val,
 uint16 idx_pos, uint16 idx_val, uint32 on_off)
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

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, in_val[i]);
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, out_val[i]);
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_XCH_CNT);

	TestCodeTearDown();
}



int verifyResultValueBlkXCH(int tcase, uint8 dest_reg, uint16 pos, uint16 expected[])
{
	int i, rc=0;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = {"X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	DBG_LOGPRINT("test=%d %s[%d]=", tcase, reg[dest_reg], pos);
	for(i=0; i<BLK_XCH_CNT; i++)
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

/*************** BMOV, BMOVP  **************************/

uint16 bmov_in[]={0x1234, 0x5678, 0xFF00, 0x553F};
uint16 bmov_none[]={0,0,0,0};
uint16 bmov_N2[]={0x34, 0x78, 0x00, 0x3F};

int setCodeOp3Blk_W1N2W3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandNibble(2, out, out_pos);
		addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_W1N2N3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandNibble(2, out, out_pos);
		addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_W1N2K3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandNibble(2, out, out_pos);
		addMLOperand(OPERAND_ML_CODE_K, BLK_XCH_CNT);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_W1N2Idx3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in, in_pos); addMLOperandNibble(2, out, out_pos);
		addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_N1W2W3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;
	if(in > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(2, in, in_pos); addMLOperand(out, out_pos);
		addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_N1W2N3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;
	if(in > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(2, in, in_pos); addMLOperand(out, out_pos);
		addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_N1W2K3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;
	if(in > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(2, in, in_pos); addMLOperand(out, out_pos);
		addMLOperand(OPERAND_ML_CODE_K, BLK_XCH_CNT);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_N1W2Idx3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;
	if(in > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(2, in, in_pos); addMLOperand(out, out_pos);
		addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_N1N2W3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(out > OPERAND_ML_CODE_B) return 0;
	if(in > OPERAND_ML_CODE_B) return 0;

	if(in==out && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, in_pos); addMLOperandNibble(4, out, out_pos);
		addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_N1N2N3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos)
{
	if(out > OPERAND_ML_CODE_B) return 0;
	if(in > OPERAND_ML_CODE_B) return 0;

	if(in==out && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, in_pos); addMLOperandNibble(4, out, out_pos);
		addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_N1N2K3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	if(out > OPERAND_ML_CODE_B) return 0;
	if(in > OPERAND_ML_CODE_B) return 0;

	if(in==out && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, in_pos); addMLOperandNibble(4, out, out_pos);
		addMLOperand(OPERAND_ML_CODE_K, BLK_XCH_CNT);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_N1N2Idx3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if(out > OPERAND_ML_CODE_B) return 0;
	if(in > OPERAND_ML_CODE_B) return 0;

	if(in==out && in_pos == out_pos ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in, in_pos); addMLOperandNibble(4, out, out_pos);
		addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_K1W2W3(uint16 ml_cmd, uint8 out, uint16 out_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperand(out, out_pos);
		addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_K1W2N3(uint16 ml_cmd, uint8 out, uint16 out_pos, uint8 c_reg, uint16 c_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperand(out, out_pos);
		addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_K1W2K3(uint16 ml_cmd, uint8 out, uint16 out_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperand(out, out_pos);
		addMLOperand(OPERAND_ML_CODE_K, BLK_XCH_CNT);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_K1W2Idx3(uint16 ml_cmd, uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if(out < OPERAND_ML_CODE_D) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperand(out, out_pos);
		addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_K1N2W3(uint16 ml_cmd, uint8 out, uint16 out_pos)
{
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperandNibble(4, out, out_pos);
		addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_K1N2N3(uint16 ml_cmd, uint8 out, uint16 out_pos, uint8 c_reg, uint16 c_pos)
{
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperandNibble(4, out, out_pos);
		addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_K1N2K3(uint16 ml_cmd, uint8 out, uint16 out_pos)
{
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperandNibble(4, out, out_pos);
		addMLOperand(OPERAND_ML_CODE_K, BLK_XCH_CNT);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_K1N2Idx3(uint16 ml_cmd, uint8 out, uint16 out_pos, uint16 idx_pos)
{
	if(out > OPERAND_ML_CODE_B) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperandNibble(4, out, out_pos);
		addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_Idx1W2W3(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	uint16 lastpos[]={12287, 8191};

	if(in < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in_pos+idx_val < 0 || in_pos+idx_val > lastpos[in-OPERAND_ML_CODE_D]) return 0;
	if(in == out && in_pos+idx_val == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperand(out, out_pos);
		addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_Idx1W2N3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val, uint8 c_reg, uint16 c_pos)
{
	uint16 lastpos[]={12287, 8191};

	if(in < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in_pos+idx_val < 0 || in_pos+idx_val > lastpos[in-OPERAND_ML_CODE_D]) return 0;
	if(in == out && in_pos+idx_val == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos); addMLOperand(out, out_pos);
		addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_Idx1W2K3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val)
{
	uint16 lastpos[]={12287, 8191};

	if(in < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in_pos+idx_val < 0 || in_pos+idx_val > lastpos[in-OPERAND_ML_CODE_D]) return 0;
	if(in == out && in_pos+idx_val == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos);	addMLOperand(out, out_pos);
		addMLOperand(OPERAND_ML_CODE_K, BLK_XCH_CNT);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_Idx1W2Idx3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val)
{
	uint16 lastpos[]={12287, 8191};

	if(in < OPERAND_ML_CODE_D) return 0;
	if(out < OPERAND_ML_CODE_D) return 0;

	if(in_pos+idx_val < 0 || in_pos+idx_val > lastpos[in-OPERAND_ML_CODE_D]) return 0;
	if(500+idx_val < 0 || 500+idx_val > lastpos[0]) return 0;
	if(in == out && in_pos+idx_val == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos);	addMLOperand(out, out_pos);
		addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_Idx1N2W3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val)
{
	uint16 lastpos[]={12287, 8191};

	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	if(in_pos+idx_val < 0 || in_pos+idx_val > lastpos[in-OPERAND_ML_CODE_D]) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos);	addMLOperandNibble(2, out, out_pos);
		addMLOperand(OPERAND_ML_CODE_D, 160);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_Idx1N2N3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val, uint8 c_reg, uint16 c_pos)
{
	uint16 lastpos[]={12287, 8191};

	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	if(in_pos+idx_val < 0 || in_pos+idx_val > lastpos[in-OPERAND_ML_CODE_D]) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos);	addMLOperandNibble(2, out, out_pos);
		addMLOperandNibble(4, c_reg, c_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_Idx1N2K3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val)
{
	uint16 lastpos[]={12287, 8191};

	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	if(in_pos+idx_val < 0 || in_pos+idx_val > lastpos[in-OPERAND_ML_CODE_D]) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos);	addMLOperandNibble(2, out, out_pos);
		addMLOperand(OPERAND_ML_CODE_K, BLK_XCH_CNT);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3Blk_Idx1N2Idx3
(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val)
{
	uint16 lastpos[]={12287, 8191};

	if(in < OPERAND_ML_CODE_D) return 0;
	if(out > OPERAND_ML_CODE_B) return 0;

	if(in_pos+idx_val < 0 || in_pos+idx_val > lastpos[in-OPERAND_ML_CODE_D]) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in, in_pos, idx_pos);	addMLOperandNibble(2, out, out_pos);
		addMLOperandZIndex(OPERAND_ML_CODE_D, 500, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputBlk_W1W2W3
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, in_val[i]);
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputBlk_W1W2N3
(uint8 in, uint16 in_pos, uint16 *in_val, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos, uint32 on_off)
{
	int i;
	short value=BLK_XCH_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, in_val[i]);
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}


void setInputBlk_W1W2K3
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, in_val[i]);
	}

	TestCodeTearDown();
}

void setInputBlk_W1W2Idx3
(uint8 in, uint16 in_pos, uint16 *in_val, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val, uint32 on_off)
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

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, in_val[i]);
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputBlk_N1W2W3
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i, j;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		for(j=0;j<8;j++)
		{
			addDeviceControlInstruction(0, (uint8)in, in_pos+i*8+j, ((in_val[i]>>j)&0x01) );
		}
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputBlk_N1W2N3
(uint8 in, uint16 in_pos, uint16 *in_val, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos, uint32 on_off)
{
	int i, j;
	short value=BLK_XCH_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		for(j=0;j<8;j++)
		{
			addDeviceControlInstruction(0, (uint8)in, in_pos+i*8+j, ((in_val[i]>>j)&0x01) );
		}
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputBlk_N1W2K3
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i, j;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		for(j=0;j<8;j++)
		{
			addDeviceControlInstruction(0, (uint8)in, in_pos+i*8+j, ((in_val[i]>>j)&0x01) );
		}
	}

	TestCodeTearDown();
}

void setInputBlk_N1W2Idx3
(uint8 in, uint16 in_pos, uint16 *in_val, uint8 out, uint16 out_pos,
 uint16 idx_pos, uint16 idx_val, uint32 on_off)
{
	int i, j;
	short z_val;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		for(j=0;j<8;j++)
		{
			addDeviceControlInstruction(0, (uint8)in, in_pos+i*8+j, ((in_val[i]>>j)&0x01) );
		}
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputBlk_N1N2W3
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i, j;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		for(j=0;j<16;j++)
		{
			addDeviceControlInstruction(0, (uint8)in, in_pos+i*16+j, ((in_val[i]>>j)&0x01) );
		}
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputBlk_N1N2N3
(uint8 in, uint16 in_pos, uint16 *in_val, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos, uint32 on_off)
{
	int i, j;
	short value=BLK_XCH_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		for(j=0;j<16;j++)
		{
			addDeviceControlInstruction(0, (uint8)in, in_pos+i*16+j, ((in_val[i]>>j)&0x01) );
		}
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputBlk_N1N2K3
(uint8 in, uint16 in_pos, uint16 *in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i, j;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		for(j=0;j<16;j++)
		{
			addDeviceControlInstruction(0, (uint8)in, in_pos+i*16+j, ((in_val[i]>>j)&0x01) );
		}
	}

	TestCodeTearDown();
}

void setInputBlk_N1N2Idx3
(uint8 in, uint16 in_pos, uint16 *in_val, uint8 out, uint16 out_pos,
 uint8 idx_pos, uint16 idx_val, uint32 on_off)
{
	int i, j;
	short z_val;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0; i<BLK_XCH_CNT; i++)
	{
		for(j=0;j<16;j++)
		{
			addDeviceControlInstruction(0, (uint8)in, in_pos+i*16+j, ((in_val[i]>>j)&0x01) );
		}
	}
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_XCH_CNT);

	TestCodeTearDown();
}



int verifyResultValueBlkNibble2(int tcase, uint8 dest_reg, uint16 pos, uint16 expected[])
{
	int i, rc=0;
	long long n_val;
	uint8 result[BLK_XCH_CNT];
	char *reg[] = {"X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	DBG_LOGPRINT("test=%d %s[%d]=", tcase, reg[dest_reg], pos);
	for(i=0; i<BLK_XCH_CNT; i++)
	{
		if(!test_getNibble(&n_val, dest_reg, pos+i*8, 2))
			return 1;

		result[i] = (uint8)(n_val&0xFF);
		if( show_log ) DBG_LOGPRINT("(%d:%d) ", result[i], expected[i]);
		CU_ASSERT_EQUAL(result[i], expected[i]);
		if(result[i] != expected[i]) rc=1;
	}
	DBG_LOGPRINT("\n");
	return rc;
}

int verifyResultValueBlkNibble4(int tcase, uint8 dest_reg, uint16 pos, uint16 expected[])
{
	int i, rc=0;
	long long n_val;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = {"X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	DBG_LOGPRINT("test=%d %s[%d]=", tcase, reg[dest_reg], pos);
	for(i=0; i<BLK_XCH_CNT; i++)
	{
		if(!test_getNibble(&n_val, dest_reg, pos+i*16, 4))
			return 1;

		result[i] = (uint16)(n_val&0xFFFF);
		if( show_log ) DBG_LOGPRINT("(%d:%d) ", result[i], expected[i]);
		CU_ASSERT_EQUAL(result[i], expected[i]);
		if(result[i] != expected[i]) rc=1;
	}
	DBG_LOGPRINT("\n");
	return rc;
}

/******************** FMOV, FMOVP *************************/

void setInputOp3_W1W2W3
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputOp3_W1W2N3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos, uint32 on_off)
{
	int i;
	short value=BLK_XCH_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_W1W2K3
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp3_W1W2Idx3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 idx_pos, uint16 idx_val, uint32 on_off)
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

	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputOp3_N1W2W3
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0;i<8;i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputOp3_N1W2N3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos, uint32 on_off)
{
	int i, j;
	short value=BLK_XCH_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0;i<8;i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
	}

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_N1W2Idx3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 idx_pos, uint16 idx_val, uint32 on_off)
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

	for(i=0;i<8;i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
	}

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputOp3_N1W2K3
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0;i<8;i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
	}

	TestCodeTearDown();
}

void setInputOp3_N1N2W3
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0;i<16;i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputOp3_N1N2N3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 c_reg, uint16 c_pos, uint32 on_off)
{
	int i;
	short value=BLK_XCH_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0;i<16;i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_N1N2K3
(uint8 in, uint16 in_pos, uint16 in_val,
 uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0;i<16;i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
	}

	TestCodeTearDown();
}

void setInputOp3_N1N2Idx3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 idx_pos, uint16 idx_val, uint32 on_off)
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

	for(i=0;i<16;i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01) );
	}

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputOp3_K1W2W3(uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputOp3_K1W2N3(uint8 out, uint16 out_pos, uint8 c_reg, uint16 c_pos, uint32 on_off)
{
	int i;
	short value=BLK_XCH_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	for(i=0;i<16;i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_K1W2K3(uint8 out, uint16 out_pos, uint32 on_off)
{
	int i;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	TestCodeTearDown();
}

void setInputOp3_K1W2Idx3(uint8 out, uint16 out_pos, uint8 idx_pos, uint16 idx_val, uint32 on_off)
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

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputOp3_Idx1W2W3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 idx_pos, uint16 idx_val, uint32 on_off)
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

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 160, BLK_XCH_CNT);

	TestCodeTearDown();
}

void setInputOp3_Idx1W2N3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 idx_pos, uint16 idx_val, uint8 c_reg, uint16 c_pos, uint32 on_off)
{
	int i;
	short z_val;
	short value=BLK_XCH_CNT;

	if(on_off==2)
	{
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	for(i=0;i<16;i++)
	{
		addDeviceControlInstruction(0, (uint8)c_reg, c_pos+i, ((value>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_Idx1W2K3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 idx_pos, uint16 idx_val, uint32 on_off)
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

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);

	TestCodeTearDown();
}

void setInputOp3_Idx1W2Idx3
(uint8 in, uint16 in_pos, uint16 in_val, uint8 out, uint16 out_pos,
 uint8 idx_pos, uint16 idx_val, uint32 on_off)
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

	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_D, 500+z_val, BLK_XCH_CNT);

	TestCodeTearDown();
}

int verifyResultValueBlk(int tcase, uint8 dest_reg, uint16 pos, uint16 expected)
{
	int i, rc=0;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = {"X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	DBG_LOGPRINT("test=%d %s[%d]=", tcase, reg[dest_reg], pos);
	for(i=0; i<BLK_XCH_CNT; i++)
	{
		if(!test_getWord(&result[i], dest_reg, pos+i))
			return 1;

		if( show_log ) DBG_LOGPRINT("(%d:%d) ", result[i], expected);
		CU_ASSERT_EQUAL(result[i], expected);
		if(result[i] != expected) rc=1;
	}
	DBG_LOGPRINT("\n");
	return rc;
}

int verifyResultValueBlkN2(int tcase, uint8 dest_reg, uint16 pos, uint16 expected)
{
	int i=0, rc=0;
	long long n_val;
	uint8 result[BLK_XCH_CNT];
	char *reg[] = {"X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	DBG_LOGPRINT("test=%d %s[%d]= exp=%d", tcase, reg[dest_reg], pos, expected);
	for(i=0; i<BLK_XCH_CNT; i++)
	{
		//if(!test_getNibble(&result[i], dest_reg, pos+i*8, 2))
		if(!test_getNibble(&n_val, dest_reg, pos+i*8, 2))
			return 1;

		result[i] = (uint8)(n_val&0xFF);
		if( show_log ) DBG_LOGPRINT("(%d:%d) ", result[i], expected);
		CU_ASSERT_EQUAL(result[i], expected);
		if(result[i] != expected) rc=1;
	}
	DBG_LOGPRINT("\n");
	return rc;
}

int verifyResultValueBlkN4(int tcase, uint8 dest_reg, uint16 pos, uint16 expected)
{
	int i, rc=0;
	long long n_val;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = {"X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	DBG_LOGPRINT("test=%d %s[%d]=", tcase, reg[dest_reg], pos);
	for(i=0; i<BLK_XCH_CNT; i++)
	{
		//if(!test_getNibble(&result[i], dest_reg, pos+i*16, 4))
		if(!test_getNibble(&n_val, dest_reg, pos+i*16, 4))
			return 1;

		result[i] = (uint16)(n_val&0xFFFF);
		if( show_log ) DBG_LOGPRINT("(%d:%d) ", result[i], expected);
		CU_ASSERT_EQUAL(result[i], expected);
		if(result[i] != expected) rc=1;
	}
	DBG_LOGPRINT("\n");
	return rc;
}

void test_BXCH_W1W2W3
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 *in_val, uint16 *out_val, uint16 *in_exp, uint16 *out_exp)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
					ml_rc = setCodeOp3Blk_W1W2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_W1W2W3_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block XCH W1W2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkXCH(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s out_%s[%d] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getWord(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], out_exp[k]);
							}
							fprintf(flog, "\n");
						}

						rc2=verifyResultValueBlkXCH(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getWord(&result[k], in, in_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], in_exp[k]);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_BXCH_W1W2N3
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 *in_val, uint16 *out_val, uint16 *in_exp, uint16 *out_exp)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						ml_rc = setCodeOp3Blk_W1W2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputBlk_W1W2N3_all(in, in_pos, in_val, out, out_pos, out_val, c_reg, c_pos, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block XCH W1W2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkXCH(tno, out, out_pos, out_exp);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s out_%s[%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], out_exp[k]);
								}
								fprintf(flog, "\n");
							}

							rc2=verifyResultValueBlkXCH(tno, in, in_pos, in_exp);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s in_%s[%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], in, in_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], in_exp[k]);
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

void test_BXCH_W1W2K3
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 *in_val, uint16 *out_val, uint16 *in_exp, uint16 *out_exp)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
					ml_rc = setCodeOp3Blk_W1W2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_W1W2K3_all(in, in_pos, in_val, out, out_pos, out_val, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block XCH W1W2K3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkXCH(tno, out, out_pos, out_exp);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s out_%s[%d] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getWord(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], out_exp[k]);
							}
							fprintf(flog, "\n");
						}

						rc2=verifyResultValueBlkXCH(tno, in, in_pos, in_exp);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getWord(&result[k], in, in_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], in_exp[k]);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_BXCH_W1W2Idx3
(int tno, uint16 ml_code, uint32 on_off, int run_step,
 uint16 *in_val, uint16 *out_val, uint16 *in_exp, uint16 *out_exp)
{
	int i, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						ml_rc = setCodeOp3Blk_W1W2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputBlk_W1W2Idx3_all(in, in_pos, in_val, out, out_pos, out_val, testidx[inx].pos, testidx[inx].val, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block XCH W1W2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkXCH(tno, out, out_pos, out_exp);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s out_%s[%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[out], out_pos);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], out_exp[k]);
								}
								fprintf(flog, "\n");
							}

							rc2=verifyResultValueBlkXCH(tno, in, in_pos, in_exp);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s in_%s[%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], in, in_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], in_exp[k]);
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

void test_BMOV_W1W2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
					ml_rc = setCodeOp3Blk_W1W2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_W1W2W3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block BMOV W1W2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkXCH(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
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

void test_BMOV_W1W2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						ml_rc = setCodeOp3Blk_W1W2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputBlk_W1W2N3(in, in_pos, in_val, out, out_pos, c_reg, c_pos, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block BMOV W1W2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkXCH(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] N_%s[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, reg[c_reg]);
								for(k=0; k<BLK_XCH_CNT; k++)
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

void test_BMOV_W1W2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
					ml_rc = setCodeOp3Blk_W1W2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_W1W2K3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block BMOV W1W2K3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkXCH(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] K%d : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, BLK_XCH_CNT);
							for(k=0; k<BLK_XCH_CNT; k++)
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

void test_BMOV_W1W2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						ml_rc = setCodeOp3Blk_W1W2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputBlk_W1W2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block BMOV W1W2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkXCH(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] D[160+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<BLK_XCH_CNT; k++)
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

void test_BMOV_W1N2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordN2BlkPos(in, i);
					ml_rc = setCodeOp3Blk_W1N2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					// no need to initialize N2X[out]
					setInputBlk_W1W2W3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block BMOV W1N2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkNibble2(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] N_%s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getNibble(&result[k], out, out_pos+k*8, 2);
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

void test_BMOV_W1N2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_W1N2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						// no need to initialize N2X[out]
						setInputBlk_W1W2N3(in, in_pos, in_val, out, out_pos, c_reg, c_pos, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block BMOV W1N2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkNibble2(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] N_%s[%d] D[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*8, 2);
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

void test_BMOV_W1N2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordBlkPos(in, i);
					ml_rc = setCodeOp3Blk_W1N2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					// no need to initialize N2X[out]
					setInputBlk_W1W2K3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block BMOV W1N2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkNibble2(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] N_%s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getNibble(&result[k], out, out_pos+k*8, 2);
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

void test_BMOV_W1N2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16* expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_W1N2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						// no need to initialize N2X[out]
						setInputBlk_W1W2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block BMOV W1N2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkNibble2(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] N_%s[%d] D[160+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*8, 2);
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

void test_BMOV_N1W2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordN2BlkPos(in, i);
					ml_rc = setCodeOp3Blk_N1W2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_N1W2W3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block BMOV N1W2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkXCH(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s N_%s[%d] %s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
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

void test_BMOV_N1W2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_N1W2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputBlk_N1W2N3(in, in_pos, in_val, out, out_pos, c_reg, c_pos, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block BMOV N1W2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkXCH(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s N_%s[%d] %s[%d] N_%s[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, reg[c_reg]);
								for(k=0; k<BLK_XCH_CNT; k++)
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

void test_BMOV_N1W2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordN2BlkPos(in, i);
					ml_rc = setCodeOp3Blk_N1W2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_N1W2K3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block BMOV N1W2K3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkXCH(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s N_%s[%d] %s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
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

void test_BMOV_N1W2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_N1W2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputBlk_N1W2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block BMOV N1W2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkXCH(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s N_%s[%d] %s[%d] D[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos);
								for(k=0; k<BLK_XCH_CNT; k++)
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

void test_BMOV_N1N2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y, c_reg=OPERAND_ML_CODE_R;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordN4BlkPos(in, i);
					ml_rc = setCodeOp3Blk_N1N2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_N1N2W3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block BMOV N1N2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkNibble4(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s N_%s[%d] N_%s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getNibble(&result[k], out, out_pos+k*16, 4);
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

void test_BMOV_N1N2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y, c_reg=OPERAND_ML_CODE_R;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN4BlkPos(in, i);
						ml_rc = setCodeOp3Blk_N1N2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputBlk_N1N2N3(in, in_pos, in_val, out, out_pos, c_reg, c_pos, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block BMOV N1N2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkNibble4(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s N_%s[%d] N_%s[%d] N_%s[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, reg[c_reg]);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*16, 4);
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



void test_BMOV_N1N2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y, c_reg=OPERAND_ML_CODE_R;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordN4BlkPos(in, i);
					ml_rc = setCodeOp3Blk_N1N2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputBlk_N1N2K3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
					rc = runTestCode(run_step, "block BMOV N1N2K3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkNibble4(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s N_%s[%d] N_%s[%d] K%d : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, BLK_XCH_CNT);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getNibble(&result[k], out, out_pos+k*16, 4);
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

void test_BMOV_N1N2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 *in_val, uint16 *expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=0;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y, c_reg=OPERAND_ML_CODE_R;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN4BlkPos(in, i);
						ml_rc = setCodeOp3Blk_N1N2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputBlk_N1N2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						//DBG_LOGPRINT("in=%d pos=%d out=%d pos=%d\n", in, in_pos, out, out_pos);
						rc = runTestCode(run_step, "block BMOV N1N2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkNibble4(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s N_%s[%d] N_%s[%d] D[160+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*16, 4);
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

void test_FMOV_W1W2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
					ml_rc = setCodeOp3Blk_W1W2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp3_W1W2W3(in, in_pos, in_val, out, out_pos, on_off);

					DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
					rc = runTestCode(run_step, "block FMOV W1W2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlk(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getWord(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], expected);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_FMOV_W1W2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_X;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						ml_rc = setCodeOp3Blk_W1W2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputOp3_W1W2N3(in, in_pos, in_val, out, out_pos, c_reg, c_pos, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV W1W2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] N_%s[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, reg[c_reg]);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_W1W2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
					ml_rc = setCodeOp3Blk_W1W2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp3_W1W2K3(in, in_pos, in_val, out, out_pos, on_off);

					DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
					rc = runTestCode(run_step, "block FMOV W1W2K3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlk(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] K4 : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getWord(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], expected);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_FMOV_W1W2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						ml_rc = setCodeOp3Blk_W1W2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputOp3_W1W2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV W1W2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] %s[%d] D[500+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_W1N2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordBlkPos(in, i);
					ml_rc = setCodeOp3Blk_W1N2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp3_W1W2W3(in, in_pos, in_val, out, out_pos, on_off);

					DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
					rc = runTestCode(run_step, "block FMOV W1N2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkN2(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							//fprintf("test case %d error cmd=%s %s[%d] N_%s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getNibble(&result[k], out, out_pos+k*8, 2);
								//fprintf(flog, "(%d:%d), ", result[k], expected);
								printf("(%d:%d), ", result[k], expected);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_FMOV_W1N2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos, c_pos=160;
	uint8 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_W1N2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputOp3_W1W2N3(in, in_pos, in_val, out, out_pos, c_reg, c_pos, on_off);


						rc = runTestCode(run_step, "block FMOV W1N2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkN2(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] N_%s[%d] D[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*8, 2);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_W1N2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint8 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordBlkPos(in, i);
					ml_rc = setCodeOp3Blk_W1N2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp3_W1W2K3(in, in_pos, in_val, out, out_pos, on_off);

					DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
					rc = runTestCode(run_step, "block FMOV W1N2K3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkN2(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s %s[%d] N_%s[%d] K4 : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getNibble(&result[k], out, out_pos+k*8, 2);
								fprintf(flog, "(%d:%d), ", result[k], expected);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_FMOV_W1N2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint8 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordBlkPos(in, i);
						ml_rc = setCodeOp3Blk_W1N2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputOp3_W1W2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV W1N2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkN2(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d] N_%s[%d] D[160+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*8, 2);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_N1W2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordN2BlkPos(in, i);
					ml_rc = setCodeOp3Blk_N1W2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp3_N1W2W3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
					rc = runTestCode(run_step, "block FMOV N1W2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlk(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s N_%s[%d] %s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getWord(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], expected);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_FMOV_N1W2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_N1W2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputOp3_N1W2N3(in, in_pos, in_val, out, out_pos, c_reg, c_pos, on_off);

						//DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV N1W2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s N_%s[%d] %s[%d] N_%s[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, reg[c_reg]);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_N1W2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordN2BlkPos(in, i);
					ml_rc = setCodeOp3Blk_N1W2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp3_N1W2W3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
					rc = runTestCode(run_step, "block FMOV N1W2K3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlk(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s N_%s[%d] %s[%d] K%d : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, BLK_XCH_CNT);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getWord(&result[k], out, out_pos+k);
								fprintf(flog, "(%d:%d), ", result[k], expected);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_FMOV_N1W2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_N1W2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputOp3_N1W2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV N1W2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s N_%s[%d] %s[%d] D[500+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_N1N2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordN4BlkPos(in, i);
					ml_rc = setCodeOp3Blk_N1N2W3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp3_N1N2W3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
					rc = runTestCode(run_step, "block FMOV N1N2W3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkN4(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s N_%s[%d] N_%s[%d] D[160] : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getNibble(&result[k], out, out_pos+k*16, 4);
								fprintf(flog, "(%d:%d), ", result[k], expected);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_FMOV_N1N2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN4BlkPos(in, i);
						ml_rc = setCodeOp3Blk_N1N2N3(ml_code, in, in_pos, out, out_pos, c_reg, c_pos);
						if(ml_rc == 0) continue;

						setInputOp3_N1N2N3(in, in_pos, in_val, out, out_pos, c_reg, c_pos, on_off);

						//DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV N1N2N3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkN4(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s N_%s[%d] N_%s[%d] N_%s[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, reg[c_reg]);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*16, 4);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_N1N2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{

				for(i=0; i<3; i++)
				{
					PLC_DEVICE_Init();

					in_pos = getWordN4BlkPos(in, i);
					ml_rc = setCodeOp3Blk_N1N2K3(ml_code, in, in_pos, out, out_pos);
					if(ml_rc == 0) continue;

					setInputOp3_N1N2K3(in, in_pos, in_val, out, out_pos, on_off);

					//DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
					rc = runTestCode(run_step, "block FMOV N1N2K3 ");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error! \n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
					}
					else
					{
						rc2=verifyResultValueBlkN4(tno, out, out_pos, expected);
						if(rc2 == 1)
						{
							fprintf(flog, "test case %d error cmd=%s N_%s[%d] N_%s[%d] K%d : ", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, BLK_XCH_CNT);
							for(k=0; k<BLK_XCH_CNT; k++)
							{
								test_getNibble(&result[k], out, out_pos+k*16, 4);
								fprintf(flog, "(%d:%d), ", result[k], expected);
							}
							fprintf(flog, "\n");
						}
					}
				}
			}
		}
	}
}

void test_FMOV_N1N2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN4BlkPos(in, i);
						ml_rc = setCodeOp3Blk_N1N2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos);
						if(ml_rc == 0) continue;

						if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

						setInputOp3_N1N2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV N1N2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkN4(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s N_%s[%d] N_%s[%d] D[500+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*16, 4);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_K1W2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);

			PLC_DEVICE_Init();

			ml_rc = setCodeOp3Blk_K1W2W3(ml_code, out, out_pos);
			if(ml_rc == 0) continue;

			setInputOp3_K1W2W3(out, out_pos, on_off);

			//DBG_LOGPRINT("out=%d pos=%d\n", out, out_pos);
			rc = runTestCode(run_step, "block FMOV K1W2W3 ");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueBlk(tno, out, out_pos, expected);
				if(rc2 == 1)
				{
					fprintf(flog, "test case %d error cmd=%s K0x1024 %s[%d] D[160] : ", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[out], out_pos);
					for(k=0; k<BLK_XCH_CNT; k++)
					{
						test_getWord(&result[k], out, out_pos+k);
						fprintf(flog, "(%d:%d), ", result[k], expected);
					}
					fprintf(flog, "\n");
				}
			}
		}
	}
}

void test_FMOV_K1W2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
			{
				PLC_DEVICE_Init();

				ml_rc = setCodeOp3Blk_K1W2N3(ml_code, out, out_pos, c_reg, c_pos);
				if(ml_rc == 0) continue;

				setInputOp3_K1W2N3(out, out_pos, c_reg, c_pos, on_off);

				//DBG_LOGPRINT("out=%d pos=%d\n", out, out_pos);
				rc = runTestCode(run_step, "block FMOV K1W2N3 ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueBlk(tno, out, out_pos, expected);
					if(rc2 == 1)
					{
						fprintf(flog, "test case %d error cmd=%s K0x1024 %s[%d] D[160] : ", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[out], out_pos);
						for(k=0; k<BLK_XCH_CNT; k++)
						{
							test_getWord(&result[k], out, out_pos+k);
							fprintf(flog, "(%d:%d), ", result[k], expected);
						}
						fprintf(flog, "\n");
					}
				}
			}
		}
	}
}

void test_FMOV_K1W2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);

			PLC_DEVICE_Init();

			ml_rc = setCodeOp3Blk_K1W2K3(ml_code, out, out_pos);
			if(ml_rc == 0) continue;

			setInputOp3_K1W2K3(out, out_pos, on_off);

			//DBG_LOGPRINT("out=%d pos=%d\n", out, out_pos);
			rc = runTestCode(run_step, "block FMOV K1W2K3 ");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueBlk(tno, out, out_pos, expected);
				if(rc2 == 1)
				{
					fprintf(flog, "test case %d error cmd=%s K0x1024 %s[%d] K%d : ", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[out], out_pos, BLK_XCH_CNT);
					for(k=0; k<BLK_XCH_CNT; k++)
					{
						test_getWord(&result[k], out, out_pos+k);
						fprintf(flog, "(%d:%d), ", result[k], expected);
					}
					fprintf(flog, "\n");
				}
			}
		}
	}
}

void test_FMOV_K1W2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getWordBlkPos(out, olast);
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				ml_rc = setCodeOp3Blk_K1W2Idx3(ml_code, out, out_pos, testidx[inx].pos);
				if(ml_rc == 0) continue;

				if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

				setInputOp3_K1W2Idx3(out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

				DBG_LOGPRINT("out=%d pos=%d\n", out, out_pos);
				rc = runTestCode(run_step, "block FMOV K1W2Idx3 ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueBlk(tno, out, out_pos, expected);
					if(rc2 == 1)
					{
						fprintf(flog, "test case %d error cmd=%s K0x1234 %s[%d] D[500+%d] : ", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[out], out_pos, testidx[inx].val);
						for(k=0; k<BLK_XCH_CNT; k++)
						{
							test_getWord(&result[k], out, out_pos+k);
							fprintf(flog, "(%d:%d), ", result[k], expected);
						}
						fprintf(flog, "\n");
					}
				}
			}
		}
	}
}

void test_FMOV_K1N2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);

			PLC_DEVICE_Init();

			ml_rc = setCodeOp3Blk_K1N2W3(ml_code, out, out_pos);
			if(ml_rc == 0) continue;

			setInputOp3_K1W2W3(out, out_pos, on_off);

			DBG_LOGPRINT("out=%d pos=%d exp=%d\n", out, out_pos, expected);
			rc = runTestCode(run_step, "block FMOV K1N2W3 ");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueBlkN4(tno, out, out_pos, expected);
				if(rc2 == 1)
				{
					fprintf(flog, "test case %d error cmd=%s K0x1234 N_%s[%d] D[160] : ", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[out], out_pos);
					for(k=0; k<BLK_XCH_CNT; k++)
					{
						test_getNibble(&result[k], out, out_pos+k*8, 2);
						fprintf(flog, "(%d:%d), ", result[k], expected);
					}
					fprintf(flog, "\n");
				}
			}
		}
	}
}

void test_FMOV_K1N2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
			{
				PLC_DEVICE_Init();

				ml_rc = setCodeOp3Blk_K1N2N3(ml_code, out, out_pos, c_reg, c_pos);
				if(ml_rc == 0) continue;

				setInputOp3_K1W2N3(out, out_pos, c_reg, c_pos, on_off);

				DBG_LOGPRINT("out=%d pos=%d\n", out, out_pos);
				rc = runTestCode(run_step, "block FMOV K1N2N3 ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueBlkN4(tno, out, out_pos, expected);
					if(rc2 == 1)
					{
						fprintf(flog, "test case %d error cmd=%s K0x1234 N_%s[%d] N_%s[160] : ", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[out], out_pos, reg[c_reg]);
						for(k=0; k<BLK_XCH_CNT; k++)
						{
							test_getNibble(&result[k], out, out_pos+k*16, 4);
							fprintf(flog, "(%d:%d), ", result[k], expected);
						}
						fprintf(flog, "\n");
					}
				}
			}
		}
	}
}

void test_FMOV_K1N2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 expected)
{
	int i, k, rc, rc2, ml_rc, olast=2;
	uint8 out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);

			PLC_DEVICE_Init();

			ml_rc = setCodeOp3Blk_K1N2K3(ml_code, out, out_pos);
			if(ml_rc == 0) continue;

			setInputOp3_K1W2K3(out, out_pos, on_off);

			DBG_LOGPRINT("out=%d pos=%d\n", out, out_pos);
			rc = runTestCode(run_step, "block FMOV K1N2K3 ");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test_no[%d]: %s runtime error! \n",
					tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
			}
			else
			{
				rc2=verifyResultValueBlkN4(tno, out, out_pos, expected);
				if(rc2 == 1)
				{
					fprintf(flog, "test case %d error cmd=%s K0x1234 N_%s[%d] K%d : ", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
						reg[out], out_pos, BLK_XCH_CNT);
					for(k=0; k<BLK_XCH_CNT; k++)
					{
						test_getNibble(&result[k], out, out_pos+k*16, 4);
						fprintf(flog, "(%d:%d), ", result[k], expected);
					}
					fprintf(flog, "\n");
				}
			}
		}
	}
}

void test_FMOV_K1N2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN4BlkPos(out, olast);
			for(inx=0; inx<15; inx++)
			{
				PLC_DEVICE_Init();

				ml_rc = setCodeOp3Blk_K1N2Idx3(ml_code, out, out_pos, testidx[inx].pos);
				if(ml_rc == 0) continue;

				if(testidx[inx].val+500 < 0 || testidx[inx].val+500 > 12284 ) continue;

				setInputOp3_K1W2Idx3(out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

				DBG_LOGPRINT("out=%d pos=%d\n", out, out_pos);
				rc = runTestCode(run_step, "block FMOV K1N2Idx3 ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test_no[%d]: %s runtime error! \n",
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
				}
				else
				{
					rc2=verifyResultValueBlkN4(tno, out, out_pos, expected);
					if(rc2 == 1)
					{
						fprintf(flog, "test case %d error cmd=%s K0x1234 N_%s[%d] D[500+%d] : ", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
							reg[out], out_pos, testidx[inx].val);
						for(k=0; k<BLK_XCH_CNT; k++)
						{
							test_getNibble(&result[k], out, out_pos+k*16, 4);
							fprintf(flog, "(%d:%d), ", result[k], expected);
						}
						fprintf(flog, "\n");
					}
				}
			}
		}
	}
}

void test_FMOV_Idx1W2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						ml_rc = setCodeOp3Blk_Idx1W2W3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						setInputOp3_Idx1W2W3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV Idx1W2W3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d+%d] %s[%d] D[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, reg[out], out_pos);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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



void test_FMOV_Idx1W2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						for(inx=0; inx<15; inx++)
						{
							PLC_DEVICE_Init();

							in_pos = getWordBlkPos(in, i);
							ml_rc = setCodeOp3Blk_Idx1W2N3(ml_code, in, in_pos, out, out_pos, \
										testidx[inx].pos, testidx[inx].val, c_reg, c_pos);
							if(ml_rc == 0) continue;

							setInputOp3_Idx1W2N3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, c_reg, c_pos, on_off);

							DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
							rc = runTestCode(run_step, "block FMOV Idx1W2N3 ");
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								fprintf(flog, "test_no[%d]: %s runtime error! \n",
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
							}
							else
							{
								rc2=verifyResultValueBlk(tno, out, out_pos, expected);
								if(rc2 == 1)
								{
									fprintf(flog, "test case %d error cmd=%s %s[%d+%d] %s[%d] N_%s[160] : ", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
										reg[in], in_pos, testidx[inx].val, reg[out], out_pos, reg[c_reg]);
									for(k=0; k<BLK_XCH_CNT; k++)
									{
										test_getWord(&result[k], out, out_pos+k);
										fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_Idx1W2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						ml_rc = setCodeOp3Blk_Idx1W2K3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						setInputOp3_Idx1W2K3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV Idx1W2K3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d+%d] %s[%d] K%d : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, reg[out], out_pos, BLK_XCH_CNT);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_Idx1W2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_W, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	uint16 result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
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
						ml_rc = setCodeOp3Blk_Idx1W2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						setInputOp3_Idx1W2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=(%d:%d), in=(%d:%d)=%d idx(%d:%d)\n", \
								out, out_pos, in, in_pos, in_val, testidx[inx].pos, testidx[inx].val);
						rc = runTestCode(run_step, "block FMOV Idx1W2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlk(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d+%d] %s[%d] D[500+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getWord(&result[k], out, out_pos+k);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_Idx1N2W3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_Idx1N2W3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						setInputOp3_Idx1W2W3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV Idx1N2W3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkN2(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d+%d] N_%s[%d] D[160] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, reg[out], out_pos);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*8, 2);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_Idx1N2N3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(c_reg=OPERAND_ML_CODE_X; c_reg<=OPERAND_ML_CODE_B; c_reg++)
				{
					for(i=0; i<3; i++)
					{
						for(inx=0; inx<15; inx++)
						{
							PLC_DEVICE_Init();

							in_pos = getWordBlkPos(in, i);
							ml_rc = setCodeOp3Blk_Idx1N2N3(ml_code, in, in_pos, out, out_pos, \
										testidx[inx].pos, testidx[inx].val, c_reg, c_pos);
							if(ml_rc == 0) continue;

							setInputOp3_Idx1W2N3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, c_reg, c_pos, on_off);

							DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
							rc = runTestCode(run_step, "block FMOV Idx1N2N3 ");
							if(rc == 1)
							{
								CU_ASSERT_FALSE(rc); // run time failure
								fprintf(flog, "test_no[%d]: %s runtime error! \n",
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
							}
							else
							{
								rc2=verifyResultValueBlkN2(tno, out, out_pos, expected);
								if(rc2 == 1)
								{
									fprintf(flog, "test case %d error cmd=%s %s[%d+%d] N_%s[%d] N_%s[160] : ", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
										reg[in], in_pos, testidx[inx].val, reg[out], out_pos, reg[c_reg]);
									for(k=0; k<BLK_XCH_CNT; k++)
									{
										test_getNibble(&result[k], out, out_pos+k*8, 2);
										fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_Idx1N2K3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_Idx1N2K3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						setInputOp3_Idx1W2K3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV Idx1N2K3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkN2(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d+%d] N_%s[%d] K%d : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, reg[out], out_pos, BLK_XCH_CNT);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*8, 2);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void test_FMOV_Idx1N2Idx3(int tno, uint16 ml_code, uint32 on_off, int run_step, uint16 in_val, uint16 expected)
{
	int i, k, inx, rc, rc2, ml_rc, olast=2;
	uint8 in=OPERAND_ML_CODE_W, out=OPERAND_ML_CODE_X, c_reg=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, c_pos=160;
	long long result[BLK_XCH_CNT];
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			out_pos = getWordN2BlkPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3; i++)
				{
					for(inx=0; inx<15; inx++)
					{
						PLC_DEVICE_Init();

						in_pos = getWordN2BlkPos(in, i);
						ml_rc = setCodeOp3Blk_Idx1N2Idx3(ml_code, in, in_pos, out, out_pos, testidx[inx].pos, testidx[inx].val);
						if(ml_rc == 0) continue;

						setInputOp3_Idx1W2Idx3(in, in_pos, in_val, out, out_pos, testidx[inx].pos, testidx[inx].val, on_off);

						DBG_LOGPRINT("out=%d pos=%d, in=%d pos=%d in_val=%d\n", out, out_pos, in, in_pos, in_val);
						rc = runTestCode(run_step, "block FMOV Idx1N2Idx3 ");
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! \n",
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName);
						}
						else
						{
							rc2=verifyResultValueBlkN2(tno, out, out_pos, expected);
							if(rc2 == 1)
							{
								fprintf(flog, "test case %d error cmd=%s %s[%d+%d] N_%s[%d] D[500+%d] : ", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(ml_code)->strName, \
									reg[in], in_pos, testidx[inx].val, reg[out], out_pos, testidx[inx].val);
								for(k=0; k<BLK_XCH_CNT; k++)
								{
									test_getNibble(&result[k], out, out_pos+k*8, 2);
									fprintf(flog, "(%d:%d), ", result[k], expected);
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

void testTransferBlockCommand(void)
{
	char log[] = "err_trans_blk.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("transfer block LOG file open error !\n");
		exit(1);
	}

#if 0
	test_FMOV_N1N2N3(171, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
#else

	test_BXCH_W1W2W3(0, ML_CODE_BXCH, 0, 1, bxch_in, bxch_out, bxch_in, bxch_out);
	test_BXCH_W1W2W3(1, ML_CODE_BXCH, 1, 1, bxch_in, bxch_out, bxch_out, bxch_in);
	test_BXCH_W1W2N3(2, ML_CODE_BXCH, 0, 1, bxch_in, bxch_out, bxch_in, bxch_out);
	test_BXCH_W1W2N3(3, ML_CODE_BXCH, 1, 1, bxch_in, bxch_out, bxch_out, bxch_in);
	test_BXCH_W1W2K3(4, ML_CODE_BXCH, 0, 1, bxch_in, bxch_out, bxch_in, bxch_out);
	test_BXCH_W1W2K3(5, ML_CODE_BXCH, 1, 1, bxch_in, bxch_out, bxch_out, bxch_in);
	test_BXCH_W1W2Idx3(6, ML_CODE_BXCH, 0, 1, bxch_in, bxch_out, bxch_in, bxch_out);
	test_BXCH_W1W2Idx3(7, ML_CODE_BXCH, 1, 1, bxch_in, bxch_out, bxch_out, bxch_in);

	test_BXCH_W1W2W3(8, ML_CODE_BXCHP, 0, 2, bxch_in, bxch_out, bxch_in, bxch_out);
	test_BXCH_W1W2W3(9, ML_CODE_BXCHP, 2, 2, bxch_in, bxch_out, bxch_out, bxch_in);
	test_BXCH_W1W2N3(10, ML_CODE_BXCHP, 0, 2, bxch_in, bxch_out, bxch_in, bxch_out);
	test_BXCH_W1W2N3(11, ML_CODE_BXCHP, 2, 2, bxch_in, bxch_out, bxch_out, bxch_in);
	test_BXCH_W1W2K3(12, ML_CODE_BXCHP, 0, 2, bxch_in, bxch_out, bxch_in, bxch_out);
	test_BXCH_W1W2K3(13, ML_CODE_BXCHP, 2, 2, bxch_in, bxch_out, bxch_out, bxch_in);
	test_BXCH_W1W2Idx3(14, ML_CODE_BXCHP, 0, 2, bxch_in, bxch_out, bxch_in, bxch_out);
	test_BXCH_W1W2Idx3(15, ML_CODE_BXCHP, 2, 2, bxch_in, bxch_out, bxch_out, bxch_in);

	test_BMOV_W1W2W3(16, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_W1W2W3(17, ML_CODE_BMOV, 1, 1, bmov_in, bmov_in);
	test_BMOV_W1W2N3(18, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_W1W2N3(19, ML_CODE_BMOV, 1, 1, bmov_in, bmov_in);
	test_BMOV_W1W2K3(20, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_W1W2K3(21, ML_CODE_BMOV, 1, 1, bmov_in, bmov_in);
	test_BMOV_W1W2Idx3(22, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_W1W2Idx3(23, ML_CODE_BMOV, 1, 1, bmov_in, bmov_in);

	test_BMOV_W1N2W3(24, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_W1N2W3(25, ML_CODE_BMOV, 1, 1, bmov_in, bmov_N2);
	test_BMOV_W1N2N3(26, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_W1N2N3(27, ML_CODE_BMOV, 1, 1, bmov_in, bmov_N2);
	test_BMOV_W1N2K3(28, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_W1N2K3(29, ML_CODE_BMOV, 1, 1, bmov_in, bmov_N2);
	test_BMOV_W1N2Idx3(30, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_W1N2Idx3(31, ML_CODE_BMOV, 1, 1, bmov_in, bmov_N2);

	test_BMOV_N1W2W3(32, ML_CODE_BMOV, 0, 1, bmov_N2, bmov_none);
	test_BMOV_N1W2W3(33, ML_CODE_BMOV, 1, 1, bmov_N2, bmov_N2);
	test_BMOV_N1W2N3(34, ML_CODE_BMOV, 0, 1, bmov_N2, bmov_none);
	test_BMOV_N1W2N3(35, ML_CODE_BMOV, 1, 1, bmov_N2, bmov_N2);
	test_BMOV_N1W2K3(36, ML_CODE_BMOV, 0, 1, bmov_N2, bmov_none);
	test_BMOV_N1W2K3(37, ML_CODE_BMOV, 1, 1, bmov_N2, bmov_N2);
	test_BMOV_N1W2Idx3(38, ML_CODE_BMOV, 0, 1, bmov_N2, bmov_none);
	test_BMOV_N1W2Idx3(39, ML_CODE_BMOV, 1, 1, bmov_N2, bmov_N2);

	test_BMOV_N1N2W3(40, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_N1N2W3(41, ML_CODE_BMOV, 1, 1, bmov_in, bmov_in);
	test_BMOV_N1N2N3(42, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_N1N2N3(43, ML_CODE_BMOV, 1, 1, bmov_in, bmov_in);
	test_BMOV_N1N2K3(44, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_N1N2K3(45, ML_CODE_BMOV, 1, 1, bmov_in, bmov_in);
	test_BMOV_N1N2Idx3(46, ML_CODE_BMOV, 0, 1, bmov_in, bmov_none);
	test_BMOV_N1N2Idx3(47, ML_CODE_BMOV, 1, 1, bmov_in, bmov_in);

	test_BMOV_W1W2W3(48, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_W1W2W3(49, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_in);
	test_BMOV_W1W2N3(50, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_W1W2N3(51, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_in);
	test_BMOV_W1W2K3(52, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_W1W2K3(53, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_in);
	test_BMOV_W1W2Idx3(54, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_W1W2Idx3(55, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_in);

	test_BMOV_W1N2W3(56, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_W1N2W3(57, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_N2);
	test_BMOV_W1N2N3(58, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_W1N2N3(59, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_N2);
	test_BMOV_W1N2K3(60, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_W1N2K3(61, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_N2);
	test_BMOV_W1N2Idx3(62, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_W1N2Idx3(63, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_N2);

	test_BMOV_N1W2W3(64, ML_CODE_BMOVP, 0, 2, bmov_N2, bmov_none);
	test_BMOV_N1W2W3(65, ML_CODE_BMOVP, 2, 2, bmov_N2, bmov_N2);
	test_BMOV_N1W2N3(66, ML_CODE_BMOVP, 0, 2, bmov_N2, bmov_none);
	test_BMOV_N1W2N3(67, ML_CODE_BMOVP, 2, 2, bmov_N2, bmov_N2);
	test_BMOV_N1W2K3(68, ML_CODE_BMOVP, 0, 2, bmov_N2, bmov_none);
	test_BMOV_N1W2K3(69, ML_CODE_BMOVP, 2, 2, bmov_N2, bmov_N2);
	test_BMOV_N1W2Idx3(70, ML_CODE_BMOVP, 0, 2, bmov_N2, bmov_none);
	test_BMOV_N1W2Idx3(71, ML_CODE_BMOVP, 2, 2, bmov_N2, bmov_N2);

	test_BMOV_N1N2W3(72, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_N1N2W3(73, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_in);
	test_BMOV_N1N2N3(74, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_N1N2N3(75, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_in);
	test_BMOV_N1N2K3(76, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_N1N2K3(77, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_in);
	test_BMOV_N1N2Idx3(78, ML_CODE_BMOVP, 0, 2, bmov_in, bmov_none);
	test_BMOV_N1N2Idx3(79, ML_CODE_BMOVP, 2, 2, bmov_in, bmov_in);

	test_FMOV_W1W2W3(80, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_W1W2W3(81, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);
	test_FMOV_W1W2N3(82, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_W1W2N3(83, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);
	test_FMOV_W1W2K3(84, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_W1W2K3(85, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);
	test_FMOV_W1W2Idx3(86, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_W1W2Idx3(87, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);

	test_FMOV_W1N2W3(88, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_W1N2W3(89, ML_CODE_FMOV, 1, 1, 0x1234, 0x34);
	test_FMOV_W1N2N3(90, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_W1N2N3(91, ML_CODE_FMOV, 1, 1, 0x1234, 0x34);
	test_FMOV_W1N2K3(92, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_W1N2K3(93, ML_CODE_FMOV, 1, 1, 0x1234, 0x34);
	test_FMOV_W1N2Idx3(94, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_W1N2Idx3(95, ML_CODE_FMOV, 1, 1, 0x1234, 0x34);

	test_FMOV_N1W2W3(96, ML_CODE_FMOV, 0, 1, 0x34, 0);
	test_FMOV_N1W2W3(97, ML_CODE_FMOV, 1, 1, 0x34, 0x34);
	test_FMOV_N1W2N3(98, ML_CODE_FMOV, 0, 1, 0x34, 0);
	test_FMOV_N1W2N3(99, ML_CODE_FMOV, 1, 1, 0x34, 0x34);
	test_FMOV_N1W2K3(100, ML_CODE_FMOV, 0, 1, 0x34, 0);
	test_FMOV_N1W2K3(101, ML_CODE_FMOV, 1, 1, 0x34, 0x34);
	test_FMOV_N1W2Idx3(102, ML_CODE_FMOV, 0, 1, 0x34, 0);
	test_FMOV_N1W2Idx3(103, ML_CODE_FMOV, 1, 1, 0x34, 0x34);

	test_FMOV_N1N2W3(104, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_N1N2W3(105, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);
	test_FMOV_N1N2N3(106, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_N1N2N3(107, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);
	test_FMOV_N1N2K3(108, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_N1N2K3(109, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);
	test_FMOV_N1N2Idx3(110, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_N1N2Idx3(111, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);

	test_FMOV_K1W2W3(112, ML_CODE_FMOV, 0, 1, 0);
	test_FMOV_K1W2W3(113, ML_CODE_FMOV, 1, 1, 0x1234);
	test_FMOV_K1W2N3(114, ML_CODE_FMOV, 0, 1, 0);
	test_FMOV_K1W2N3(115, ML_CODE_FMOV, 1, 1, 0x1234);
	test_FMOV_K1W2K3(116, ML_CODE_FMOV, 0, 1, 0);
	test_FMOV_K1W2K3(117, ML_CODE_FMOV, 1, 1, 0x1234);
	test_FMOV_K1W2Idx3(118, ML_CODE_FMOV, 0, 1, 0);
	test_FMOV_K1W2Idx3(119, ML_CODE_FMOV, 1, 1, 0x1234);

	test_FMOV_K1N2W3(120, ML_CODE_FMOV, 0, 1, 0);
	test_FMOV_K1N2W3(121, ML_CODE_FMOV, 1, 1, 0x1234);
	test_FMOV_K1N2N3(122, ML_CODE_FMOV, 0, 1, 0);
	test_FMOV_K1N2N3(123, ML_CODE_FMOV, 1, 1, 0x1234);
	test_FMOV_K1N2K3(124, ML_CODE_FMOV, 0, 1, 0);
	test_FMOV_K1N2K3(125, ML_CODE_FMOV, 1, 1, 0x1234);
	test_FMOV_K1N2Idx3(126, ML_CODE_FMOV, 0, 1, 0);
	test_FMOV_K1N2Idx3(127, ML_CODE_FMOV, 1, 1, 0x1234);

	test_FMOV_Idx1W2W3(128, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_Idx1W2W3(129, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);
	test_FMOV_Idx1W2N3(130, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_Idx1W2N3(131, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);
	test_FMOV_Idx1W2K3(132, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_Idx1W2K3(133, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);
	test_FMOV_Idx1W2Idx3(134, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_Idx1W2Idx3(135, ML_CODE_FMOV, 1, 1, 0x1234, 0x1234);


	test_FMOV_Idx1N2W3(136, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_Idx1N2W3(137, ML_CODE_FMOV, 1, 1, 0x1234, 0x34);
	test_FMOV_Idx1N2N3(138, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_Idx1N2N3(139, ML_CODE_FMOV, 1, 1, 0x1234, 0x34);
	test_FMOV_Idx1N2K3(140, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_Idx1N2K3(141, ML_CODE_FMOV, 1, 1, 0x1234, 0x34);
	test_FMOV_Idx1N2Idx3(142, ML_CODE_FMOV, 0, 1, 0x1234, 0);
	test_FMOV_Idx1N2Idx3(143, ML_CODE_FMOV, 1, 1, 0x1234, 0x34);

	test_FMOV_W1W2W3(144, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_W1W2W3(145, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
	test_FMOV_W1W2N3(146, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_W1W2N3(147, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
	test_FMOV_W1W2K3(148, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_W1W2K3(149, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
	test_FMOV_W1W2Idx3(150, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_W1W2Idx3(151, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);

	test_FMOV_W1N2W3(152, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_W1N2W3(153, ML_CODE_FMOVP, 2, 2, 0x1234, 0x34);
	test_FMOV_W1N2N3(154, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_W1N2N3(155, ML_CODE_FMOVP, 2, 2, 0x1234, 0x34);
	test_FMOV_W1N2K3(156, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_W1N2K3(157, ML_CODE_FMOVP, 2, 2, 0x1234, 0x34);
	test_FMOV_W1N2Idx3(158, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_W1N2Idx3(159, ML_CODE_FMOVP, 2, 2, 0x1234, 0x34);

	test_FMOV_N1W2W3(160, ML_CODE_FMOVP, 0, 2, 0x34, 0);
	test_FMOV_N1W2W3(161, ML_CODE_FMOVP, 2, 2, 0x34, 0x34);
	test_FMOV_N1W2N3(162, ML_CODE_FMOVP, 0, 2, 0x34, 0);
	test_FMOV_N1W2N3(163, ML_CODE_FMOVP, 2, 2, 0x34, 0x34);
	test_FMOV_N1W2K3(164, ML_CODE_FMOVP, 0, 2, 0x34, 0);
	test_FMOV_N1W2K3(165, ML_CODE_FMOVP, 2, 2, 0x34, 0x34);
	test_FMOV_N1W2Idx3(166, ML_CODE_FMOVP, 0, 2, 0x34, 0);
	test_FMOV_N1W2Idx3(167, ML_CODE_FMOVP, 2, 2, 0x34, 0x34);

	test_FMOV_N1N2W3(168, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_N1N2W3(169, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
	test_FMOV_N1N2N3(170, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_N1N2N3(171, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
	test_FMOV_N1N2K3(172, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_N1N2K3(173, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
	test_FMOV_N1N2Idx3(174, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_N1N2Idx3(175, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);

	test_FMOV_K1W2W3(176, ML_CODE_FMOVP, 0, 2, 0);
	test_FMOV_K1W2W3(177, ML_CODE_FMOVP, 2, 2, 0x1234);
	test_FMOV_K1W2N3(178, ML_CODE_FMOVP, 0, 2, 0);
	test_FMOV_K1W2N3(179, ML_CODE_FMOVP, 2, 2, 0x1234);
	test_FMOV_K1W2K3(180, ML_CODE_FMOVP, 0, 2, 0);
	test_FMOV_K1W2K3(181, ML_CODE_FMOVP, 2, 2, 0x1234);
	test_FMOV_K1W2Idx3(182, ML_CODE_FMOVP, 0, 2, 0);
	test_FMOV_K1W2Idx3(183, ML_CODE_FMOVP, 2, 2, 0x1234);

	test_FMOV_K1N2W3(184, ML_CODE_FMOVP, 0, 2, 0);
	test_FMOV_K1N2W3(185, ML_CODE_FMOVP, 2, 2, 0x1234);
	test_FMOV_K1N2N3(186, ML_CODE_FMOVP, 0, 2, 0);
	test_FMOV_K1N2N3(187, ML_CODE_FMOVP, 2, 2, 0x1234);
	test_FMOV_K1N2K3(188, ML_CODE_FMOVP, 0, 2, 0);
	test_FMOV_K1N2K3(189, ML_CODE_FMOVP, 2, 2, 0x1234);
	test_FMOV_K1N2Idx3(190, ML_CODE_FMOVP, 0, 2, 0);
	test_FMOV_K1N2Idx3(191, ML_CODE_FMOVP, 2, 2, 0x1234);

	test_FMOV_Idx1W2W3(192, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_Idx1W2W3(193, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
	test_FMOV_Idx1W2N3(194, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_Idx1W2N3(195, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
	test_FMOV_Idx1W2K3(196, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_Idx1W2K3(197, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);
	test_FMOV_Idx1W2Idx3(198, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_Idx1W2Idx3(199, ML_CODE_FMOVP, 2, 2, 0x1234, 0x1234);

	test_FMOV_Idx1N2W3(200, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_Idx1N2W3(201, ML_CODE_FMOVP, 2, 2, 0x1234, 0x34);
	test_FMOV_Idx1N2N3(202, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_Idx1N2N3(203, ML_CODE_FMOVP, 2, 2, 0x1234, 0x34);
	test_FMOV_Idx1N2K3(204, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_Idx1N2K3(205, ML_CODE_FMOVP, 2, 2, 0x1234, 0x34);
	test_FMOV_Idx1N2Idx3(206, ML_CODE_FMOVP, 0, 2, 0x1234, 0);
	test_FMOV_Idx1N2Idx3(207, ML_CODE_FMOVP, 2, 2, 0x1234, 0x34);

#endif

	fclose(flog);
}
#endif