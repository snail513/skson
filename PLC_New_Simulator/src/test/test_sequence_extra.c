/*
 * test_sequence_extra.c
 *
 *  Created on: Mar 26, 2015
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
extern int verifyResultValueWord(int tcase, uint8 dest_reg, uint16 pos, short expected);

void setCodeLD_SFT(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLD_2SFT(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
void setCodeLD_SFT_WB(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos, uint16 bit_pos);

void setInputSFT_SIn_SOut(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, int on_off);
void setInputSFT_SIn_WB_SOut(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 bit_pos, int on_off);

static int show_log=1;
static 	FILE *flog;

void setCodeLD_SFT(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_code); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLD_SFT_WB(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos, uint16 bit_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_code); addMLOperandWordBit(out_reg, out_pos, bit_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLD_2SFT(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_code); addMLOperand(out_reg, out_pos+1);
	addMLOperator(ml_code); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLD_2SFT_WB(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos, uint16 bit_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_code); addMLOperandWordBit(out_reg, out_pos, bit_pos+1);
	addMLOperator(ml_code); addMLOperandWordBit(out_reg, out_pos, bit_pos);
	addMLOperator(ML_CODE_END);
}

void setInputSFT_SIn_SOut(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, int on_off)
{
	if(on_off == 2)
	{
		addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, OPERAND_ML_CODE_X, 100, 1);
	}
	else if(on_off == 3)
	{
		addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
		addDeviceControlInstruction(1, OPERAND_ML_CODE_X, 100, 0);
	}
	else
		addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, on_off);

	addDeviceControlInstruction(0, out, out_pos-1, 1);
	addDeviceControlInstruction(0, out, out_pos, 0);

	TestCodeTearDown();
}

void setInputSFT_SIn_WB_SOut(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 bit_pos, int on_off)
{
	uint16 value=0;

	if(on_off == 2)
	{
		addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
		addDeviceControlInstruction(1, OPERAND_ML_CODE_X, 100, 1);
	}
	else if(on_off == 3)
	{
		addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
		addDeviceControlInstruction(1, OPERAND_ML_CODE_X, 100, 0);
	}
	else
		addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, on_off);

	//value = (1<<bit_pos) & ~(1<<(bit_pos-1));
	//addDeviceControlInstruction(0, out, out_pos, ~(1<<(bit_pos-1)));
	addDeviceControlInstruction(0, out, out_pos, (1<<(bit_pos-1)));

	TestCodeTearDown();
}


int verifyResultSFT_2(int tcase, uint8 dest_reg, uint16 pos, uint8 expected1, uint8 expected2)
{
	int rc1=0, rc2=0;
	uint8 result1, result2;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};

	if(!test_getBit(&result1, dest_reg, pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d 1st bit %c[%d]=%d %d\n", tcase, reg[dest_reg], pos, result1, expected1);
	CU_ASSERT_EQUAL(result1, expected1);
	if(result1 != expected1) rc1=1;

	if(!test_getBit(&result2, dest_reg, pos+1))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d 2nd bit %c[%d]=%d %d\n", tcase, reg[dest_reg], pos+1, result2, expected2);
	CU_ASSERT_EQUAL(result2, expected2);
	if(result2 != expected2) rc2=1;

	if(rc1 == 0 && rc2 == 0 ) return 0;
	else	return 1; //error
}

int verifyResultSFT_3(int tcase, uint8 dest_reg, uint16 pos, uint8 expected1, uint8 expected2, uint8 expected3)
{
	int rc1=0, rc2=0, rc3=0;
	uint8 result1, result2, result3;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};

	if(!test_getBit(&result1, dest_reg, pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d 1st bit %c[%d]=%d %d\n", tcase, reg[dest_reg], pos, result1, expected1);
	CU_ASSERT_EQUAL(result1, expected1);
	if(result1 != expected1) rc1=1;

	if(!test_getBit(&result2, dest_reg, pos+1))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d 2nd bit %c[%d]=%d %d\n", tcase, reg[dest_reg], pos+1, result2, expected2);
	CU_ASSERT_EQUAL(result2, expected2);
	if(result2 != expected2) rc2=1;
#if 1
	if(!test_getBit(&result3, dest_reg, pos+2))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d 3rd bit %c[%d]=%d %d\n", tcase, reg[dest_reg], pos+2, result3, expected3);
	CU_ASSERT_EQUAL(result3, expected3);
	if(result3 != expected3) rc3=1;
#endif
	if(rc1 == 0 && rc2 == 0 && rc3 == 0) return 0;
	else	return 1; //error
}

int verifyResultWordBit1(int tcase, uint8 dest_reg, uint16 pos, uint16 bit_pos, uint8 expected)
{
	int rc=0;
	uint8 result;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};

	if(!test_getWordBit(&result, dest_reg, pos, bit_pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d bit %c[%d].%d=%d %d\n", tcase, reg[dest_reg], pos, bit_pos, result, expected);
	CU_ASSERT_EQUAL(result, expected);
	if(result != expected) rc=1;

	return rc;
}

int verifyResultWordBit2(int tcase, uint8 dest_reg, uint16 pos, uint16 bit_pos, uint8 expected1, uint8 expected2)
{
	int rc1=0, rc2=0;
	uint8 result1, result2;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};

	if(!test_getWordBit(&result1, dest_reg, pos, bit_pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d bit %c[%d].%d=%d %d\n", tcase, reg[dest_reg], pos, bit_pos, result1, expected1);
	CU_ASSERT_EQUAL(result1, expected1);
	if(result1 != expected1) rc1=1;

	if(!test_getWordBit(&result2, dest_reg, pos, bit_pos+1))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d bit %c[%d].%d=%d %d\n", tcase, reg[dest_reg], pos, bit_pos+1, result2, expected2);
	CU_ASSERT_EQUAL(result2, expected2);
	if(result2 != expected2) rc2=1;

	if( rc1==0 && rc2==0 ) return 0;
	else
		return 1;
}

int verifyResultWordBit3(int tcase, uint8 dest_reg, uint16 pos, uint16 bit_pos, uint8 expected1, uint8 expected2, uint8 expected3)
{
	int rc1=0, rc2=0, rc3=0;
	uint8 result1, result2, result3;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};

	if(!test_getWordBit(&result1, dest_reg, pos, bit_pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d bit %c[%d].%d=%d %d\n", tcase, reg[dest_reg], pos, bit_pos, result1, expected1);
	CU_ASSERT_EQUAL(result1, expected1);
	if(result1 != expected1) rc1=1;

	if(!test_getWordBit(&result2, dest_reg, pos, bit_pos+1))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d bit %c[%d].%d=%d %d\n", tcase, reg[dest_reg], pos, bit_pos+1, result2, expected2);
	CU_ASSERT_EQUAL(result2, expected2);
	if(result2 != expected2) rc2=1;

	if(!test_getWordBit(&result3, dest_reg, pos, bit_pos+2))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d bit %c[%d].%d=%d %d\n", tcase, reg[dest_reg], pos, bit_pos+2, result3, expected3);
	CU_ASSERT_EQUAL(result3, expected3);
	if(result3 != expected3) rc3=1;

	if(rc1 == 0 && rc2 == 0 && rc3 == 0) return 0;
	else	return 1; //error

}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096},
			{8191,8191,8191,8191,2047,8191}};

	return pos[inx_pos][reg];
}

static uint16 getSFT_OutPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {1,1,1,1,1,1},
			{4096,4096,4096,4096,1024,4096},
			{8191,8191,8191,8191,2047,8191}};

	return pos[inx_pos][reg];
}

static uint16 get2SFT_OutPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {1,1,1,1,1,1},
			{4096,4096,4096,4096,1024,4096},
			{8190,8190,8190,8190,2046,8190}};

	return pos[inx_pos][reg];
}

static uint16 getSFT_WBOutPos(int reg, int inx_pos)
{
	uint16 pos[3][2]={ {0,0}, {6144,4096}, {12287,8191}};

	return pos[inx_pos][reg];
}


static uint16 getMPS_OutPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0, 0,0,0},
			{4096,4096,4096,4096,1024,4096, 0,6144,4096},
			{8190,8190,8190,8190,2046,8190, 0,12287,8191}}; //max-1

	return pos[inx_pos][reg];
}

static uint16 getMPS_2InPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096},
			{8189,8189,8189,8189,2045,8189}}; // max-2

	return pos[inx_pos][reg];
}

static uint16 getMPS_2OutPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096},
			{8189,8189,8189,8189,2045,8189}}; // max-2

	return pos[inx_pos][reg];
}

void test_1SFT(int tno, uint16 ml_cmd, int on_off, int run_step, uint8 expected)
{
	uint8 i, in, out;
	uint16 in_pos=OPERAND_ML_CODE_X, out_pos=OPERAND_ML_CODE_Y;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, olast=0;
	//uint8 expected=0;

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		out_pos = getSFT_OutPos(out, olast);
		{
			PLC_DEVICE_Init();

			setCodeLD_SFT(ml_cmd, in, in_pos, out, out_pos);
			setInputSFT_SIn_SOut(in, in_pos, out, out_pos, on_off);

			rc = runTestCode(run_step, "LD_SFT bit 1 step");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test case %d error cmd=%d out_%c[%d]\n",
						tno, ml_cmd, reg[out], out_pos);
			}
			else
			{
				rc = verifyResultNormal(tno, out, out_pos, expected);
				if(rc == 1)
				{
					fprintf(flog, "test case %d error cmd=%d out_%c[%d] exp=%d\n",
							tno, ml_cmd, reg[out], out_pos, expected);
				}
			}
		}
	}
	}
}


void test_2SFT(int tno, uint16 ml_cmd, int on_off, int run_step, uint8 expected[])
{
	uint8 i, in, out;
	uint16 in_pos, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, olast=0;
	//uint8 expected[]={1, 0};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			PLC_DEVICE_Init();

			out_pos = get2SFT_OutPos(out, olast);

			setCodeLD_2SFT(ml_cmd, in, in_pos, out, out_pos);
			setInputSFT_SIn_SOut(in, in_pos, out, out_pos, on_off);

			rc = runTestCode(run_step, "LD_SFT 2SFT on 1 step");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test case %d error cmd=%d out_%c[%d]\n",
						tno, ml_cmd, reg[out], out_pos);
			}
			else
			{
				rc = verifyResultSFT_2(tno, out, out_pos, expected[0], expected[1]);
				if(rc == 1)
				{
					fprintf(flog, "test case %d error cmd=%d out_%c[%d]\n",
							tno, ml_cmd, reg[out], out_pos);
				}
			}
		}
	}

}


void test_1SFT_WB(int tno, uint16 ml_cmd, int on_off, int run_step, int expected)
{
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D, bit;
	uint16 in_pos=0, out_pos, bit_pos[4]={1,7,8,14};
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};
	int rc, olast=0;
	//uint8 expected=0;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			for(bit=0; bit<4; bit++)
			{
				PLC_DEVICE_Init();

				out_pos = getSFT_WBOutPos(out-OPERAND_ML_CODE_D, olast);

				setCodeLD_SFT_WB(ml_cmd, in, in_pos, out, out_pos, bit_pos[bit]);
				setInputSFT_SIn_WB_SOut(in, in_pos, out, out_pos, bit_pos[bit], on_off);

				rc = runTestCode(run_step, "LD_SFT SFT off 1 step");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test case %d error cmd=%d out_%c[%d].%d\n",
							tno, ml_cmd, reg[out], out_pos, bit_pos[bit]);
				}
				else
				{
					//printf("out=%d out_pos=%d bit_pos=%d\n", out, out_pos, bit_pos[bit]);
					rc = verifyResultWordBit1(tno, out, out_pos, bit_pos[bit], expected);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=%d out_%c[%d].%d  exp=%d\n",
								tno, ml_cmd, reg[out], out_pos, bit_pos[bit], expected);
					}
				}
			}
		}
	}
}



void test_2SFT_WB(int tno, uint16 ml_cmd, int on_off, int run_step, uint8 expected[])
{
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D, bit;
	uint16 in_pos=0, out_pos, bit_pos[4]={1,7,8,14};
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};
	int rc, olast=0;
	//uint8 expected[]={1, 0};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			for(bit=0; bit<4; bit++)
			{
				PLC_DEVICE_Init();

				//in_pos = getPos(in, i);
				out_pos = getSFT_WBOutPos(out-OPERAND_ML_CODE_D, olast);

				setCodeLD_2SFT_WB(ml_cmd, in, in_pos, out, out_pos, bit_pos[bit]);
				setInputSFT_SIn_WB_SOut(in, in_pos, out, out_pos, bit_pos[bit], on_off);

				//printf("out=%d out_pos=%d bit_pos=%d\n", out, out_pos, bit_pos[bit]);
				rc = runTestCode(run_step, " 2SFT WB on 1 step");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test case %d run time error cmd=%d out_%c[%d].%d\n",
						tno, ml_cmd, reg[out], out_pos, bit_pos[bit]+1);
				}
				else
				{
					rc = verifyResultWordBit2(tno, out, out_pos, bit_pos[bit], expected[0], expected[1]);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=%d out_%c[%d].%d\n",
							tno, ml_cmd, reg[out], out_pos, bit_pos[bit]+1);
					}
				}
			}
		}
	}
}


void test_SFTP(int tno, uint16 ml_cmd, int on_off, int run_step, int expected)
{
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_X;
	uint16 in_pos=0, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, olast=0;
	//uint8 expected=0;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			PLC_DEVICE_Init();

			out_pos = getSFT_OutPos(out, olast);

			setCodeLD_SFT(ml_cmd, in, in_pos, out, out_pos);
			setInputSFT_SIn_SOut(in, in_pos, out, out_pos, on_off);

			rc = runTestCode(run_step, "LD_SFTP SFTP in 1->0 off");
			if(rc == 1)
			{
				CU_ASSERT_FALSE(rc); // run time failure
				fprintf(flog, "test case %d error cmd=%d out_%c[%d]\n",
						tno, ml_cmd, reg[out], out_pos);
			}
			else
			{
				rc = verifyResultNormal(tno, out, out_pos, expected);
				if(rc == 1)
				{
					fprintf(flog, "test case %d error cmd=%d out_%c[%d]\n",
							tno, ml_cmd, reg[out], out_pos);
				}
			}
		}
	}

}


/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////


void setCodeMPS_MPP(uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_MPS);
	addMLOperator(ML_CODE_AND);addMLOperand(in_reg, in_pos);
	addMLOperator(ML_CODE_OUT);addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_MPP);
	addMLOperator(ML_CODE_OUT);addMLOperand(out_reg, out_pos+1);
	addMLOperator(ML_CODE_END);

}

void setCodeMPS_MPP_WB(uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos, uint16 bit_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_MPS);
	addMLOperator(ML_CODE_AND);addMLOperand(in_reg, in_pos);
	addMLOperator(ML_CODE_OUT);addMLOperandWordBit(out_reg, out_pos, bit_pos);
	addMLOperator(ML_CODE_MPP);
	addMLOperator(ML_CODE_OUT);addMLOperandWordBit(out_reg, out_pos, bit_pos+1);
	addMLOperator(ML_CODE_END);

}

void setCodeMPS_MRD_MPP(uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_MPS);
	addMLOperator(ML_CODE_AND);addMLOperand(in_reg, in_pos);
	addMLOperator(ML_CODE_OUT);addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_MRD);
	addMLOperator(ML_CODE_AND);addMLOperand(in_reg, in_pos+1);
	addMLOperator(ML_CODE_OUT);addMLOperand(out_reg, out_pos+1);
	addMLOperator(ML_CODE_MPP);
	addMLOperator(ML_CODE_AND);addMLOperand(in_reg, in_pos+2);
	addMLOperator(ML_CODE_OUT);addMLOperand(out_reg, out_pos+2);
	addMLOperator(ML_CODE_END);

}

void setCodeMPS_MRD_MPP_WB(uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos, uint16 bit_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_MPS);
	addMLOperator(ML_CODE_AND);addMLOperand(in_reg, in_pos);
	addMLOperator(ML_CODE_OUT);addMLOperandWordBit(out_reg, out_pos, bit_pos);
	addMLOperator(ML_CODE_MRD);
	addMLOperator(ML_CODE_AND);addMLOperand(in_reg, in_pos+1);
	addMLOperator(ML_CODE_OUT);addMLOperandWordBit(out_reg, out_pos, bit_pos+1);
	addMLOperator(ML_CODE_MPP);
	addMLOperator(ML_CODE_AND);addMLOperand(in_reg, in_pos+2);
	addMLOperator(ML_CODE_OUT);addMLOperandWordBit(out_reg, out_pos, bit_pos+2);
	addMLOperator(ML_CODE_END);

}

void setInputMPS_SIn(uint8 in, uint16 in_pos, int in_val, uint8 out, uint16 out_pos, int on_off)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, on_off);
	addDeviceControlInstruction(0, in, in_pos, in_val);
	addDeviceControlInstruction(0, out, out_pos, 0);
	addDeviceControlInstruction(0, out, out_pos+1, 0);

	TestCodeTearDown();
}

void setInputMPS_WB_SIn(uint8 in, uint16 in_pos, int in_val, uint8 out, uint16 out_pos, uint16 bit_pos, int on_off)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, on_off);
	addDeviceControlInstruction(0, in, in_pos, in_val);

	addDeviceControlInstruction(0, out, out_pos, 0);

	TestCodeTearDown();
}

void setInputMPS_DIn(uint8 in, uint16 in_pos, int in_val, uint8 out, uint16 out_pos, int on_off)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, on_off);
	addDeviceControlInstruction(0, in, in_pos, in_val);
	addDeviceControlInstruction(0, in, in_pos+1, in_val);
	addDeviceControlInstruction(0, in, in_pos+2, in_val);
	addDeviceControlInstruction(0, out, out_pos, 0);
	addDeviceControlInstruction(0, out, out_pos+1, 0);

	TestCodeTearDown();
}

void setInputMPS_WB_DIn(uint8 in, uint16 in_pos, int in_val, uint8 out, uint16 out_pos, uint16 bit_pos, int on_off)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, on_off);
	addDeviceControlInstruction(0, in, in_pos, in_val);
	addDeviceControlInstruction(0, in, in_pos+1, in_val);
	addDeviceControlInstruction(0, in, in_pos+2, in_val);
	addDeviceControlInstruction(0, out, out_pos, 0);

	TestCodeTearDown();
}


void test_MPS_MPP_SIn(int tno, int on_off, int in_val, uint8 expected[])
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, run_step=1, olast=0;
	//uint8 expected[]={0,0};

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
		{
			for(i=0; i<3 ; i++ ) // input register position, 0, center, last
			{
				PLC_DEVICE_Init();

				in_pos = getPos(in, i);
				out_pos = getMPS_OutPos(out, olast);
				if(in == out && (in_pos == out_pos+1 || in_pos == out_pos))
				{
					//DBG_LOGPRINT("SKIP : test condition in=%d out=%d in_pos=%d, out_pos=%d\n", \
							in, out, in_pos, out_pos);
					continue;
				}

				setCodeMPS_MPP(in, in_pos, out, out_pos);
				setInputMPS_SIn(in, in_pos, in_val, out, out_pos, on_off);

				rc = runTestCode(run_step, "MPS-MPP test");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test case %d error cmd=%d in_%c[%d] out_%c[%d]\n",
							tno, ML_CODE_MPS, reg[in], in_pos, reg[out], out_pos);
				}
				else
				{
					rc = verifyResultSFT_2(tno, out, out_pos, expected[0], expected[1]);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=%d in_%c[%d] out_%c[%d]\n",
								tno, ML_CODE_MPS, reg[in], in_pos, reg[out], out_pos);
					}
				}
			}
		}
	}
	}
}

void test_MPS_MPP_WB_SIn(int tno, int on_off, int in_val, uint8 expected[])
{
	uint8 i, bit, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, bit_pos[4]={1,7,8,14};
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};
	int rc, run_step=1, olast=0;
	//uint8 expected[]={0,0};

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
	{
		for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
		{
			for(i=0; i<3 ; i++ ) // input register position, 0, center, last
			{
				for(bit=0; bit<4; bit++)
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in, i);
					out_pos = getMPS_OutPos(out, olast);

					setCodeMPS_MPP_WB(in, in_pos, out, out_pos, bit_pos[bit]);
					setInputMPS_WB_SIn(in, in_pos, in_val, out, out_pos, bit_pos[bit], on_off);

					rc = runTestCode(run_step, "MPS-MPP test");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test case %d runtime error cmd=%s in_%c[%d] out_%c[%d]\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ML_CODE_MPS)->strName, \
							reg[in], in_pos, reg[out], out_pos);
					}
					else
					{
						rc = verifyResultWordBit2(tno, out, out_pos, bit_pos[bit], expected[0], expected[1]);
						if(rc == 1)
						{
							fprintf(flog, "test case %d error cmd=%s in_%c[%d] out_%c[%d]\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ML_CODE_MPS)->strName, \
								reg[in], in_pos, reg[out], out_pos);
						}
					}
				}
			}
		}
	}
	}
}

void test_MPS_MPP_DIn(int tno, int on_off, int in_val, uint8 expected[])
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, run_step=1, olast=0;
	//uint8 expected[]={0,0,0};

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
		{
			for(i=0; i<3 ; i++ ) // input register position, 0, center, last
			{
				PLC_DEVICE_Init();

				in_pos = getMPS_2InPos(in, i);
				out_pos = getMPS_2OutPos(out, olast);
				if(in == out && (in_pos == out_pos+1 || in_pos == out_pos))
				{
					DBG_LOGPRINT("SKIP : test condition in=%d out=%d in_pos=%d, out_pos=%d\n",
							in, out, in_pos, out_pos);
					continue;
				}

				setCodeMPS_MRD_MPP(in, in_pos, out, out_pos);
				setInputMPS_DIn(in, in_pos, in_val, out, out_pos, on_off);

				rc = runTestCode(run_step, "MPS-MRD-MPP test");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test case %d runtime error cmd=%s in_%c[%d] out_%c[%d]\n", \
						tno, PLC_OPERATOR_DICTIONARY_findOperator(ML_CODE_MPS)->strName, \
						reg[in], in_pos, reg[out], out_pos);
				}
				else
				{
					rc = verifyResultSFT_3(tno, out, out_pos, expected[0], expected[1], expected[2]);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=%s in_%c[%d] out_%c[%d]\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ML_CODE_MPS)->strName, \
							reg[in], in_pos, reg[out], out_pos);
					}
				}
			}
		}
	}
	}
}

void test_MPS_MPP_WB_DIn(int tno, int on_off, int in_val, uint8 expected[])
{
	uint8 i, bit, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, bit_pos[4]={1,7,8,13};
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};
	int rc, run_step=1, olast=0;
	//uint8 expected[]={0,0,0};

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
	{
		for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
		{
			for(i=0; i<3 ; i++ ) // input register position, 0, center, last
			{
				for(bit=0; bit<4; bit++)
				{
					PLC_DEVICE_Init();

					in_pos = getMPS_2InPos(in, i);
					out_pos = getMPS_OutPos(out, olast);

					setCodeMPS_MRD_MPP_WB(in, in_pos, out, out_pos, bit_pos[bit]);
					setInputMPS_WB_DIn(in, in_pos, in_val, out, out_pos, bit_pos[bit], on_off);

					rc = runTestCode(run_step, "MPS-MRD-MPP test");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test case %d runtime error cmd=%s in_%c[%d] out_%c[%d]\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(ML_CODE_MPS)->strName, \
							reg[in], in_pos, reg[out], out_pos);
					}
					else
					{
						rc = verifyResultWordBit3(tno, out, out_pos, bit_pos[bit], expected[0], expected[1], expected[2]);
						if(rc == 1)
						{
							fprintf(flog, "test case %d error cmd=%s in_%c[%d] out_%c[%d]\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(ML_CODE_MPS)->strName, \
								reg[in], in_pos, reg[out], out_pos);
						}
					}
				}
			}
		}
	}
	}
}



void setCodeMC_MCR(uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_MC); addMLOperand(OPERAND_ML_CODE_K, 1); addMLOperand(in_reg, 50);
	addMLOperator(ML_CODE_SET); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_MCR); addMLOperand(OPERAND_ML_CODE_K, 1);
	addMLOperator(ML_CODE_END);
}


void setInputMC_MCR1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, int out_val, int on_off)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, on_off);
	addDeviceControlInstruction(0, out, out_pos, out_val);

	TestCodeTearDown();
}


void test_MC_MCR1(int tno, int on_off, int out_val, uint8 expected[])
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, run_step=1, olast=0;
	//uint8 expected[]={0,0};

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
		{
			for(i=0; i<3 ; i++ ) // input register position, 0, center, last
			{
				PLC_DEVICE_Init();

				in_pos = getPos(in, i);
				out_pos = getPos(out, olast);
				if(in == out && in_pos == out_pos)
				{
					DBG_LOGPRINT("SKIP : test condition in=%d out=%d in_pos=%d, out_pos=%d\n",
							in, out, in_pos, out_pos);
					continue;
				}

				setCodeMC_MCR(in, in_pos, out, out_pos);
				setInputMC_MCR1(in, in_pos, out, out_pos, out_val, on_off);

				rc = runTestCode(run_step, "MC-MCR off test");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test case %d error cmd=%d in_%c[%d] out_%c[%d]\n",
							tno, ML_CODE_MC, reg[in], in_pos, reg[out], out_pos);
				}
				else
				{
					rc = verifyResultNormal(tno, in, 50, expected[0]);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=MC, MCR in_%c[%d] out_%c[%d]\n",
								tno, reg[in], 50, reg[out], out_pos);
					}

					rc = verifyResultNormal(tno, out, out_pos, expected[1]);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=MC, MCR in_%c[%d] out_%c[%d]\n",
								tno, reg[in], in_pos, reg[out], out_pos);
					}

				}
			}
		}
	}
	}
}

void setTestCode2MC_MCR(uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_MC);addMLOperand(OPERAND_ML_CODE_K, 1);addMLOperand(in_reg, 50);
	addMLOperator(ML_CODE_LD);addMLOperand(in_reg, in_pos);
	addMLOperator(ML_CODE_MC);addMLOperand(OPERAND_ML_CODE_K, 2);addMLOperand(in_reg, 200);
	addMLOperator(ML_CODE_SET);addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_MCR);addMLOperand(OPERAND_ML_CODE_K, 2);
	addMLOperator(ML_CODE_MCR);addMLOperand(OPERAND_ML_CODE_K, 1);
	addMLOperator(ML_CODE_END);
}

void setInput2MC_MCR(uint8 in, uint16 in_pos, int in_val, uint8 out, uint16 out_pos, int out_val, int on_off)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, on_off);
	addDeviceControlInstruction(0, in, in_pos, in_val);
	addDeviceControlInstruction(0, out, out_pos, out_val);

	TestCodeTearDown();
}

void test_MC_MCR2(int tno, int on_off, int in_val, int out_val, uint8 expected[])
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};
	int rc, run_step=1, olast=0;
	//uint8 expected[]={0,0,0};

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
		{
			for(i=0; i<3 ; i++ ) // input register position, 0, center, last
			{
				PLC_DEVICE_Init();

				in_pos = getPos(in, i);
				out_pos = getPos(out, olast);
				if(in == out && in_pos == out_pos)
				{
					DBG_LOGPRINT("SKIP : test condition in=%d out=%d in_pos=%d, out_pos=%d\n",
							in, out, in_pos, out_pos);
					continue;
				}

				setTestCode2MC_MCR(in, in_pos, out, out_pos);
				setInput2MC_MCR(in, in_pos, in_val, out, out_pos, out_val, on_off);

				rc = runTestCode(run_step, "MC-MCR off off off test");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test case %d error cmd=%d in_%c[%d] out_%c[%d]\n",
							tno, ML_CODE_MC, reg[in], in_pos, reg[out], out_pos);
				}
				else
				{
					rc = verifyResultNormal(tno, in, 50, expected[0]);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=MC, MCR in_%c[%d] out_%c[%d]\n",
								tno, reg[in], 50, reg[out], out_pos);
					}

					rc = verifyResultNormal(tno, in, 200, expected[1]);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=MC, MCR in_%c[%d] out_%c[%d]\n",
								tno, reg[in], 200, reg[out], out_pos);
					}

					rc = verifyResultNormal(tno, out, out_pos, expected[2]);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=MC, MCR in_%c[%d] out_%c[%d]\n",
								tno, reg[in], in_pos, reg[out], out_pos);
					}

				}
			}
		}
	}
	}
}

static uint16 getPosWordReg(int reg, int inx_pos)
{
	uint16 pos[3][2]={ {0,0}, {6144,4096}, {12287,8191}};

	return pos[inx_pos][reg];
}

void setCodeOp1_RST_WD(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(in_reg, in_pos);
	addMLOperator(ml_code); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setInputRST_WD(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, int on_off)
{
	addDeviceControlInstruction(0, out, out_pos, 256);
	addDeviceControlInstruction(0, in, in_pos, on_off);

	TestCodeTearDown();
}

void test_RST_Word(int tno, int on_off, short expected)
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};
	int rc, run_step=1, olast=0;
	//short expected=256;

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
	{
		for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
		{
			for(i=0; i<3 ; i++ ) // input register position, 0, center, last
			{
				PLC_DEVICE_Init();

				in_pos = getPos(in, i);
				out_pos = getPosWordReg(out-OPERAND_ML_CODE_D, olast);
				if(in == out && in_pos == out_pos)
				{
					DBG_LOGPRINT("SKIP : test condition in=%d out=%d in_pos=%d, out_pos=%d\n",
							in, out, in_pos, out_pos);
					continue;
				}

				setCodeOp1_RST_WD(ML_CODE_RST, in, in_pos, out, out_pos); // RST word register
				setInputRST_WD(in, in_pos, out, out_pos, on_off);

				rc = runTestCode(run_step, "RST word off test");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test case %d error cmd=%d in_%c[%d] out_%c[%d]\n",
							tno, ML_CODE_RST, reg[in], in_pos, reg[out], out_pos);
				}
				else
				{
					rc = verifyResultValueWord(tno, out, out_pos, expected);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=RST, in_%c[%d] out_%c[%d]\n",
								tno, reg[in], in_pos, reg[out], out_pos);
					}
				}
			}
		}
	}
	}
}


void setCodeANB(uint8 in1, uint16 in1_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(in1, in1_pos);
	addMLOperator(ML_CODE_OR);addMLOperand(in2, 50);
	addMLOperator(ML_CODE_LD);addMLOperand(in1, 100);
	addMLOperator(ML_CODE_OR);addMLOperand(in2, 200);
	addMLOperator(ML_CODE_ANB);
	addMLOperator(ML_CODE_OUT);addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);
}

typedef struct
{
	uint8 	input1;
	uint8 	input2;
	uint8 	input3;
	uint8 	input4;
	uint8 	output;

} testANB_input_st;

testANB_input_st testANB[]=
{
		{0,0,0,0, 0}, //case 0
		{0,0,0,1, 0}, //case 1
		{0,1,0,0, 0}, //case 2
		{1,1,0,0, 0}, //case 3
		{0,0,1,1, 0}, //case 4
		{0,1,0,1, 1}, //case 5
		{1,0,1,0, 1}, //case 6
		{1,0,1,1, 1}, //case 7
		{1,1,0,1, 1}, //case 8
		{1,1,1,1, 1}, //case 9
};

void setInputANB(int tcase, uint8 in1, uint16 in1_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in1, in1_pos, testANB[tcase].input1);
	addDeviceControlInstruction(0, in2, 50, testANB[tcase].input2);
	addDeviceControlInstruction(0, in1, 100, testANB[tcase].input3);
	addDeviceControlInstruction(0, in2, 200, testANB[tcase].input4);

	TestCodeTearDown();
}

void test_ANB(int tno, int tcase)
{
	uint8 i, in1=OPERAND_ML_CODE_X, in2, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, run_step=1, olast=0;

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		for(in1=OPERAND_ML_CODE_X; in1<=OPERAND_ML_CODE_B; in1++)
		{
			for(in2=OPERAND_ML_CODE_X; in2<=OPERAND_ML_CODE_B; in2++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in1, i);
					out_pos = getPos(out, olast);
					if(in1 == out && in_pos == out_pos)
					{
						//DBG_LOGPRINT("SKIP : test condition in1=%d out=%d in_pos=%d, out_pos=%d\n", \
							in1, out, in_pos, out_pos);
						continue;
					}

					setCodeANB(in1, in_pos, in2, out, out_pos);
					setInputANB(tcase, in1, in_pos, in2, out, out_pos);

					rc = runTestCode(run_step, "ANB testcase 0~9");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test case %d for %d runtime error cmd=ANB in_%c[%d] %c[], out_%c[%d]\n", \
							tno, tcase, reg[in1], in_pos, reg[in2], reg[out], out_pos);
					}
					else
					{
						rc = verifyResultNormal(tno, out, out_pos, testANB[tcase].output);
						if(rc == 1)
						{
							fprintf(flog, "test case %d for %d error cmd=ANB in_%c[%d] %c[], out_%c[%d]\n", \
								tno, tcase, reg[in1], in_pos, reg[in2], reg[out], out_pos);
						}
					}
				}
			}
		}
	}
	}
}

void setCodeORB(uint8 in1, uint16 in1_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(in1, in1_pos);
	addMLOperator(ML_CODE_AND);addMLOperand(in2, 50);
	addMLOperator(ML_CODE_LD);addMLOperand(in1, 100);
	addMLOperator(ML_CODE_AND);addMLOperand(in2, 200);
	addMLOperator(ML_CODE_ORB);
	addMLOperator(ML_CODE_OUT);addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);
}

testANB_input_st testORB[]=
{
		{0,0,0,0, 0}, //case 0
		{0,0,0,1, 0}, //case 1
		{0,1,0,0, 0}, //case 2
		{1,1,0,0, 1}, //case 3
		{0,0,1,1, 1}, //case 4
		{0,1,0,1, 0}, //case 5
		{1,0,1,0, 0}, //case 6
		{1,0,1,1, 1}, //case 7
		{1,1,0,1, 1}, //case 8
		{1,1,1,1, 1}, //case 9
};

void setInputORB(int tcase, uint8 in1, uint16 in1_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in1, in1_pos, testORB[tcase].input1);
	addDeviceControlInstruction(0, in2, 50, testORB[tcase].input2);
	addDeviceControlInstruction(0, in1, 100, testORB[tcase].input3);
	addDeviceControlInstruction(0, in2, 200, testORB[tcase].input4);

	TestCodeTearDown();
}

void test_ANDORB(int tno, int tcase)
{
	uint8 i, in1=OPERAND_ML_CODE_X, in2, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, run_step=1, olast=0;

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		for(in1=OPERAND_ML_CODE_X; in1<=OPERAND_ML_CODE_B; in1++)
		{
			for(in2=OPERAND_ML_CODE_X; in2<=OPERAND_ML_CODE_B; in2++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in1, i);
					out_pos = getPos(out, olast);
					if(in1 == out && in_pos == out_pos)
					{
						//DBG_LOGPRINT("SKIP : test condition in1=%d out=%d in_pos=%d, out_pos=%d\n", \
							in1, out, in_pos, out_pos);
						continue;
					}

					setCodeORB(in1, in_pos, in2, out, out_pos);
					setInputORB(tcase, in1, in_pos, in2, out, out_pos);

					rc = runTestCode(run_step, "ORB testcase 0~9");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test case %d for %d runtime error cmd=ORB in_%c[%d] %c[], out_%c[%d]\n", \
							tno, tcase, reg[in1], in_pos, reg[in2], reg[out], out_pos);
					}
					else
					{
						rc = verifyResultNormal(tno, out, out_pos, testORB[tcase].output);
						if(rc == 1)
						{
							fprintf(flog, "test case %d for %d error cmd=ORB in_%c[%d] %c[], out_%c[%d]\n", \
								tno, tcase, reg[in1], in_pos, reg[in2], reg[out], out_pos);
						}
					}
				}
			}
		}
	}
	}
}

void setCodeANDORB(uint8 in1, uint16 in1_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(in1, in1_pos);
	addMLOperator(ML_CODE_OR);addMLOperand(in2, 50);
	addMLOperator(ML_CODE_LD);addMLOperand(in1, 100);
	addMLOperator(ML_CODE_OR);addMLOperand(in2, 200);
	addMLOperator(ML_CODE_ANB);
	addMLOperator(ML_CODE_LD);addMLOperand(in1, 300);
	addMLOperator(ML_CODE_AND);addMLOperand(in2, 400);
	addMLOperator(ML_CODE_ORB);
	addMLOperator(ML_CODE_OUT);addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);
}

typedef struct
{
	uint8 	input1;
	uint8 	input2;
	uint8 	input3;
	uint8 	input4;
	uint8 	input5;
	uint8 	input6;

	uint8 	output;

} testANORB_input_st;

testANORB_input_st testANDORB[]=
{
		{0,0,0,0,0,0, 0}, //case 0
		{0,0,0,1,0,1, 0}, //case 1
		{0,1,0,0,1,0, 0}, //case 2
		{1,1,0,0,1,0, 0}, //case 3
		{0,0,1,1,0,1, 0}, //case 4
		{0,1,0,1,0,0, 1}, //case 5
		{1,0,1,0,0,0, 1}, //case 6
		{0,0,0,0,1,1, 1}, //case 7
		{0,0,1,1,1,1, 1}, //case 8
		{1,1,0,0,1,1, 1}, //case 9
};

void setInputANDORB(int tcase, uint8 in1, uint16 in1_pos, uint8 in2, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in1, in1_pos, testANDORB[tcase].input1);
	addDeviceControlInstruction(0, in2, 50, testANDORB[tcase].input2);
	addDeviceControlInstruction(0, in1, 100, testANDORB[tcase].input3);
	addDeviceControlInstruction(0, in2, 200, testANDORB[tcase].input4);
	addDeviceControlInstruction(0, in1, 300, testANDORB[tcase].input5);
	addDeviceControlInstruction(0, in2, 400, testANDORB[tcase].input6);
	TestCodeTearDown();
}

void test_ORB(int tno, int tcase)
{
	uint8 i, in1=OPERAND_ML_CODE_X, in2, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, run_step=1, olast=0;

	for(olast=0; olast<3; olast++)
	{
	for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
	{
		out_pos = getPos(out, olast);
		for(in1=OPERAND_ML_CODE_X; in1<=OPERAND_ML_CODE_B; in1++)
		{
			for(in2=OPERAND_ML_CODE_X; in2<=OPERAND_ML_CODE_B; in2++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in1, i);
					if(in1 == out && in_pos == out_pos)
					{
						//DBG_LOGPRINT("SKIP : test condition in1=%d out=%d in_pos=%d, out_pos=%d\n",\
							in1, out, in_pos, out_pos);
						continue;
					}

					setCodeANDORB(in1, in_pos, in2, out, out_pos);
					setInputANDORB(tcase, in1, in_pos, in2, out, out_pos);

					rc = runTestCode(run_step, "ANB ORB testcase 0~9");
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test case %d for %d runtime error cmd=ANB_ORB in_%c[%d] %c[], out_%c[%d]\n", \
							tno, tcase, reg[in1], in_pos, reg[in2], reg[out], out_pos);
					}
					else
					{
						rc = verifyResultNormal(tno, out, out_pos, testANDORB[tcase].output);
						if(rc == 1)
						{
							fprintf(flog, "test case %d for %d error cmd=ANB_ORB in_%c[%d] %c[], out_%c[%d]\n", \
								tno, tcase, reg[in1], in_pos, reg[in2], reg[out], out_pos);
						}
					}
				}
			}
		}
	}
	}
}

/****************** test OUT C **********************/

void setCodeOut_C(uint16 ml_code, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_code); addMLOperand(in, in_pos); addMLOperand(OPERAND_ML_CODE_K, 5);
	addMLOperator(ML_CODE_LD);addMLOperand(in, in_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out, out_pos);

	addMLOperator(ML_CODE_END);
}

void setInputOut_C(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(2, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(3, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(4, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(5, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(6, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(7, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(8, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(9, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(10, OPERAND_ML_CODE_X, 100, 0);

	addDeviceControlInstruction(0, in, in_pos, 0);

	TestCodeTearDown();
}

void test_OUT_C(int tno, uint16 ml_code, int run_step, int expected)
{
	uint8 i, in=OPERAND_ML_CODE_C, out=OPERAND_ML_CODE_Y;
	uint16 in_pos, out_pos, C_pos[3]={0, 512, 1023};
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, olast=0;

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			if(out==OPERAND_ML_CODE_F) continue; //skip F

			out_pos = getPos(out, olast);
			for(i=0; i<3 ; i++ ) // input register position, 0, center, last
			{
				PLC_DEVICE_Init();

				in_pos = C_pos[i];

				setCodeOut_C(ml_code, in, in_pos, out, out_pos);
				setInputOut_C(in, in_pos, out, out_pos);

				rc = runTestCode(run_step, "OUT C ");
				if(rc == 1)
				{
					CU_ASSERT_FALSE(rc); // run time failure
					fprintf(flog, "test case %d runtime error cmd=OUT_C in_C[%d] K5 out_%c[%d]\n", \
						tno, in_pos, reg[out], out_pos);
				}
				else
				{
					rc = verifyResultNormal(tno, out, out_pos, expected);
					if(rc == 1)
					{
						fprintf(flog, "test case %d error cmd=OUT_C in_C[%d] K5 out_%c[%d]\n", \
							tno, in_pos, reg[out], out_pos);
					}
				}
			}
		}
	}
}

/****************** test SET F **********************/

void setCodeCtrl_F(uint16 ml_code, uint8 out, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_code); addMLOperand(out, out_pos);

	addMLOperator(ML_CODE_END);
}

void setCodeCtrl_2F(uint16 ml_code, uint8 out, uint16 out_pos1, uint16 out_pos2)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_code); addMLOperand(out, out_pos1);
	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_code); addMLOperand(out, out_pos2);

	addMLOperator(ML_CODE_END);
}

void setInputCtrl_F(uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}


int verifyResultSET_1F(int tcase, uint8 dest_reg, uint16 pos, uint8 expected)
{
	int rc=0;
	uint8 result, SM_bit;
	uint16 SD_annun_pos, SD_annun_cnt, SD_annun_val;

	test_getBit(&result, dest_reg, pos);
	test_getBit(&SM_bit, OPERAND_ML_CODE_SM, 40);

	test_getWord(&SD_annun_pos, OPERAND_ML_CODE_SD, 40);
	test_getWord(&SD_annun_cnt, OPERAND_ML_CODE_SD, 41);
	test_getWord(&SD_annun_val, OPERAND_ML_CODE_SD, 42);

	if( show_log ) DBG_LOGPRINT("test=%d Annunciator F[%d]=%d %d  SM=%d SD40=%d SD41=%d SD42=%d\n", \
			tcase, pos, result, expected, SM_bit, SD_annun_pos, SD_annun_cnt, SD_annun_val);

	CU_ASSERT_EQUAL(result, expected);
	CU_ASSERT_EQUAL(SM_bit, 1);
	CU_ASSERT_EQUAL(SD_annun_pos, pos);
	CU_ASSERT_EQUAL(SD_annun_cnt, 1);
	CU_ASSERT_EQUAL(SD_annun_val, pos);

	if(result != expected) rc=1;
	if(SM_bit != 1) rc=1;
	if(SD_annun_pos != pos) rc=1;
	if(SD_annun_cnt != 1) rc=1;
	if(SD_annun_val != pos) rc=1;

	return rc;
}

int verifyResultSET_2F(int tcase, uint8 dest_reg, uint16 pos, uint16 pos2, uint8 expected)
{
	int rc=0;
	uint8 result, SM_bit;
	uint16 SD_annun_pos, SD_annun_cnt, SD_annun_val, SD_annun_val2;

	test_getBit(&result, dest_reg, pos);
	test_getBit(&SM_bit, OPERAND_ML_CODE_SM, 40);

	test_getWord(&SD_annun_pos, OPERAND_ML_CODE_SD, 40);
	test_getWord(&SD_annun_cnt, OPERAND_ML_CODE_SD, 41);
	test_getWord(&SD_annun_val, OPERAND_ML_CODE_SD, 42);
	test_getWord(&SD_annun_val2, OPERAND_ML_CODE_SD, 43);

	if( show_log ) DBG_LOGPRINT("test=%d Annunciator F[%d]=%d %d  SM=%d SD40=%d SD41=%d SD42=%d SD43=%d\n", \
			tcase, pos, result, expected, SM_bit, SD_annun_pos, SD_annun_cnt, SD_annun_val, SD_annun_val2);

	CU_ASSERT_EQUAL(result, expected);
	CU_ASSERT_EQUAL(SM_bit, 1);
	CU_ASSERT_EQUAL(SD_annun_pos, pos2);
	CU_ASSERT_EQUAL(SD_annun_cnt, 2);
	CU_ASSERT_EQUAL(SD_annun_val, pos);
	CU_ASSERT_EQUAL(SD_annun_val2, pos2);

	if(result != expected) rc=1;
	if(SM_bit != 1) rc=1;
	if(SD_annun_pos != pos2) rc=1;
	if(SD_annun_cnt != 2) rc=1;
	if(SD_annun_val != pos) rc=1;
	if(SD_annun_val2 != pos2) rc=1;

	return rc;
}

void test_Annunciator(int tno, uint16 ml_code, int run_step, int expected)
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_F;
	uint16 in_pos, out_pos, F_pos[3]={0, 1024, 2047};
	//char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, olast=0;

	for(olast=0; olast<3; olast++)
	{
		out_pos = F_pos[olast];

		PLC_DEVICE_Init();

		setCodeCtrl_F(ml_code, out, out_pos);
		setInputCtrl_F(out, out_pos);

		rc = runTestCode(run_step, "SET F ");
		if(rc == 1)
		{
			CU_ASSERT_FALSE(rc); // run time failure
			fprintf(flog, "test case %d runtime error cmd=SET_F F[%d] \n", tno, out_pos);
		}
		else
		{
			rc = verifyResultSET_1F(tno, out, out_pos, expected);
			if(rc == 1)
			{
				fprintf(flog, "test case %d error cmd=SET_F F[%d] \n", tno, out_pos);
			}
		}
	}
}


void test_Annunciator_2F(int tno, uint16 ml_code, int run_step, int expected)
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_F;
	uint16 in_pos, out_pos1, out_pos2, F_pos1[3]={0, 1024, 2047}, F_pos2[3]={1, 1025, 2046};
	//char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, olast=0;

	for(olast=0; olast<3; olast++)
	{
		out_pos1 = F_pos1[olast];
		out_pos2 = F_pos2[olast];

		PLC_DEVICE_Init();

		setCodeCtrl_2F(ml_code, out, out_pos1, out_pos2);
		setInputCtrl_F(out, out_pos1);

		rc = runTestCode(run_step, "SET F ");
		if(rc == 1)
		{
			CU_ASSERT_FALSE(rc); // run time failure
			fprintf(flog, "test case %d runtime error cmd=SET_F F[%d] F[%d] \n", tno, out_pos1, out_pos2);
		}
		else
		{
			rc = verifyResultSET_2F(tno, out, out_pos1, out_pos2, expected);
			if(rc == 1)
			{
				fprintf(flog, "test case %d error cmd=SET_F F[%d] F[%d] \n", tno, out_pos1, out_pos2);
			}
		}
	}
}

void setCodeRST_F(uint16 ml_code, uint8 out, uint16 out_pos1, uint16 out_pos2)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_SET); addMLOperand(out, out_pos1);
	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ML_CODE_SET); addMLOperand(out, out_pos2);
	addMLOperator(ML_CODE_LD);addMLOperand(OPERAND_ML_CODE_X, 200);
	addMLOperator(ml_code); addMLOperand(out, out_pos1);

	addMLOperator(ML_CODE_END);
}

void setInputRST_F(uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, OPERAND_ML_CODE_X, 200, 0);

	addDeviceControlInstruction(1, OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, OPERAND_ML_CODE_X, 200, 1);

	TestCodeTearDown();
}


void test_RST_F(int tno, uint16 ml_code, int run_step, int expected)
{
	uint8 i, in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_F;
	uint16 in_pos, out_pos1, out_pos2, F_pos1[3]={0, 1024, 2047}, F_pos2[3]={1, 1025, 2046};
	//char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};
	int rc, olast=0;

	for(olast=0; olast<3; olast++)
	{
		out_pos1 = F_pos1[olast];
		out_pos2 = F_pos2[olast];

		PLC_DEVICE_Init();

		setCodeRST_F(ml_code, out, out_pos1, out_pos2);
		setInputRST_F(out, out_pos1);

		rc = runTestCode(run_step, "RST F ");
		if(rc == 1)
		{
			CU_ASSERT_FALSE(rc); // run time failure
			fprintf(flog, "test case %d runtime error cmd=RST_F F[%d] F[%d] \n", tno, out_pos1, out_pos2);
		}
		else
		{
			rc = verifyResultSET_1F(tno, out, out_pos2, expected);
			if(rc == 1)
			{
				fprintf(flog, "test case %d error cmd=RST_F F[%d] F[%d] \n", tno, out_pos1, out_pos2);
			}
		}
	}
}

void testSequenceCommandExtra(void)
{
	int i, tcase=0;
	char log[] = "err_seq_extra.txt";
	uint8 exp_2SFT_1step[]={1,0};
	uint8 exp_2SFT_2step[]={0,1};
	uint8 exp_MPS_SIn_off[]={0,0};
	uint8 exp_MPS_SIn_on_off[]={0,1};
	uint8 exp_MPS_SIn_on_on[]={1,1};
	uint8 exp_MPS_DIn_off[]={0,0,0};
	uint8 exp_MPS_DIn_on[]={1,1,1};
	uint8 exp_MC_SIn_off[]={0,0};
	uint8 exp_MC_SIn_off_on[]={0,1};
	uint8 exp_MC_SIn_on_off[]={1,1};
	uint8 exp_MC2_xxx[]={0,0,0};
	uint8 exp_MC2_xxo[]={0,0,1};
	uint8 exp_MC2_xox[]={0,0,0};
	uint8 exp_MC2_oxx[]={1,0,0};
	uint8 exp_MC2_xoo[]={0,0,1};
	uint8 exp_MC2_oxo[]={1,0,1};
	uint8 exp_MC2_oox[]={1,1,1};

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("sequence Extra LOG file open error !\n");
		exit(1);
	}

#if 1
	test_Annunciator(70, ML_CODE_OUT_F, 1, 1);
	test_Annunciator_2F(71, ML_CODE_OUT_F, 1, 1);

	test_Annunciator(72, ML_CODE_SET, 1, 1);
	test_Annunciator_2F(73, ML_CODE_SET, 1, 1);

#else

	test_1SFT(0, ML_CODE_SFT, 0, 1, 0);
	test_1SFT(1, ML_CODE_SFT, 1, 1, 1);
	test_1SFT(2, ML_CODE_SFT, 1, 2, 0);

	test_2SFT(3, ML_CODE_SFT, 1, 1, exp_2SFT_1step);
	test_2SFT(4, ML_CODE_SFT, 1, 2, exp_2SFT_2step);

	test_1SFT_WB(5, ML_CODE_SFT, 0, 1, 0);
	test_1SFT_WB(6, ML_CODE_SFT, 1, 1, 1);
	test_1SFT_WB(7, ML_CODE_SFT, 1, 2, 0);

	test_2SFT_WB(8, ML_CODE_SFT, 1, 1, exp_2SFT_1step);
	test_2SFT_WB(9, ML_CODE_SFT, 1, 2, exp_2SFT_2step);

	test_SFTP(10, ML_CODE_SFTP, 3, 2, 0);
	test_SFTP(11, ML_CODE_SFTP, 2, 2, 1);

	test_MPS_MPP_SIn(12, 0, 0, exp_MPS_SIn_off);
	test_MPS_MPP_SIn(13, 0, 1, exp_MPS_SIn_off);
	test_MPS_MPP_SIn(14, 1, 0, exp_MPS_SIn_on_off);
	test_MPS_MPP_SIn(15, 1, 1, exp_MPS_SIn_on_on);

	test_MPS_MPP_WB_SIn(16, 0, 0, exp_MPS_SIn_off);
	test_MPS_MPP_WB_SIn(17, 0, 1, exp_MPS_SIn_off);
	test_MPS_MPP_WB_SIn(18, 1, 0, exp_MPS_SIn_on_off);
	test_MPS_MPP_WB_SIn(19, 1, 1, exp_MPS_SIn_on_on);

	test_MPS_MPP_DIn(20, 0, 0, exp_MPS_DIn_off);
	test_MPS_MPP_DIn(21, 1, 0, exp_MPS_DIn_off);
	test_MPS_MPP_DIn(22, 1, 1, exp_MPS_DIn_on);

	test_MPS_MPP_WB_DIn(23, 0, 0, exp_MPS_DIn_off);
	test_MPS_MPP_WB_DIn(24, 1, 0, exp_MPS_DIn_off);
	test_MPS_MPP_WB_DIn(25, 1, 1, exp_MPS_DIn_on);

	test_MC_MCR1(26, 0, 0, exp_MC_SIn_off);
	test_MC_MCR1(27, 0, 1, exp_MC_SIn_off_on);
	test_MC_MCR1(28, 1, 0, exp_MC_SIn_on_off);

	test_MC_MCR2(29, 0, 0, 0, exp_MC2_xxx);
	test_MC_MCR2(30, 0, 0, 1, exp_MC2_xxo);
	test_MC_MCR2(31, 0, 1, 0, exp_MC2_xox);
	test_MC_MCR2(32, 1, 0, 0, exp_MC2_oxx);
	test_MC_MCR2(33, 0, 1, 1, exp_MC2_xoo);
	test_MC_MCR2(34, 1, 0, 1, exp_MC2_oxo);
	test_MC_MCR2(35, 1, 1, 0, exp_MC2_oox);

	test_RST_Word(36, 0, 256);
	test_RST_Word(37, 1, 0);

	for(tcase=0; tcase<10; tcase++)
		test_ANB(38+tcase, tcase);
	for(tcase=0; tcase<10; tcase++)
		test_ORB(48+tcase, tcase);
	for(tcase=0; tcase<10; tcase++)
		test_ANDORB(58+tcase, tcase);

	test_OUT_C(68, ML_CODE_OUT_C, 9, 0); // 9 step
	test_OUT_C(69, ML_CODE_OUT_C, 10, 1); // 10 step

	test_Annunciator(70, ML_CODE_OUT_F, 1, 1);
	test_Annunciator_2F(71, ML_CODE_OUT_F, 1, 1);

	test_Annunciator(72, ML_CODE_SET, 1, 1);
	test_Annunciator_2F(73, ML_CODE_SET, 1, 1);

	test_RST_F(74, ML_CODE_RST, 2, 1);
#endif
	fclose(flog);
}

#endif
