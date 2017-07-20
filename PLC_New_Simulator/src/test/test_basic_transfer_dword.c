/*
 * test_basic_transfer_dword.c
 *
 *  Created on: Aug 19, 2015
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

extern int setCodeLD_2op(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeOp_N8DW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
extern int setCodeOp_N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

extern void setInputNIn_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputNIn_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern void setInputOp2_Val16_N1_5555_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputOp2_Val16_N1_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputOp2_Val16p_N1_5555_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected);

int setCodeOp2_DK1DW2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
int setCodeOp2_maxDK1DW2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);


void setInputSIn_sval32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sval32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_sval32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_maxval32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_maxval32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputOp2_Val32_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32_maxN1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputOp2_Val32p_maxN1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

static FILE *flog;
static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, int);
	char str[40];
	//int count;
	int run_step;
	int expected;
} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_DMOV, setCodeLD_2op, setInputSIn_sval32_off, verifyResultValueDWord,
		"DMOV off ", 1, 0},
	{1, ML_CODE_DMOV, setCodeLD_2op, setInputSIn_sval32_on, verifyResultValueDWord,
		"DMOV on 1431655765", 1, 1431655765},
	{2, ML_CODE_DMOV, setCodeLD_2op, setInputSIn_maxval32_on, verifyResultValueDWord,
		"DMOV on 2147483647", 1, 2147483647},
	{3, ML_CODE_DMOV, setCodeOp2_DK1DW2, setInputNIn_Val16_off, verifyResultValueDWord,
		"DMOV off K1431655765", 1, 0},
	{4, ML_CODE_DMOV, setCodeOp2_DK1DW2, setInputNIn_Val16_on, verifyResultValueDWord,
		"DMOV on K1431655765", 1, 1431655765},
	{5, ML_CODE_DMOV, setCodeOp2_maxDK1DW2, setInputNIn_Val16_on, verifyResultValueDWord,
		"DMOV on K2147483647", 1, 2147483647},
	{6, ML_CODE_DMOV, setCodeOp_N8DW, setInputOp2_Val32_N1_off, verifyResultValueDWord,
		"DMOV off N1431655765", 1, 0},
	{7, ML_CODE_DMOV, setCodeOp_N8DW, setInputOp2_Val32_N1_on, verifyResultValueDWord,
		"DMOV on N1431655765", 1, 1431655765},
	{8, ML_CODE_DMOV, setCodeOp_N8DW, setInputOp2_Val32_maxN1_on, verifyResultValueDWord,
		"DMOV on N2147483647", 1, 2147483647},

	{9, ML_CODE_DMOVP, setCodeLD_2op, setInputSIn_sval32_off, verifyResultValueDWord,
		"DMOVP 0->0 1431655765", 2, 0},
	{10, ML_CODE_DMOVP, setCodeLD_2op, setInputSIn_sval32_on, verifyResultValueDWord,
		"DMOVP 1->1 1431655765", 2, 0},
	{11, ML_CODE_DMOVP, setCodeLD_2op, setInputSIn_sval32p_on, verifyResultValueDWord,
		"DMOVP 0->1 1431655765", 2, 1431655765},
	{12, ML_CODE_DMOVP, setCodeLD_2op, setInputSIn_maxval32p_on, verifyResultValueDWord,
		"DMOVP 0->1 2147483647", 2, 2147483647},
	{13, ML_CODE_DMOVP, setCodeOp2_DK1DW2, setInputNIn_Val16_off, verifyResultValueDWord,
		"DMOVP 0->0 K1431655765", 2, 0},
	{14, ML_CODE_DMOVP, setCodeOp2_DK1DW2, setInputNIn_Val16_on, verifyResultValueDWord,
		"DMOVP 1->1 K1431655765", 2, 0},
	{15, ML_CODE_DMOVP, setCodeOp2_DK1DW2, setInputNIn_Val16p_on, verifyResultValueDWord,
		"DMOVP 0->1 K1431655765", 2, 1431655765},
	{16, ML_CODE_DMOVP, setCodeOp2_maxDK1DW2, setInputNIn_Val16p_on, verifyResultValueDWord,
		"DMOVP 0->1 K2147483647", 2, 2147483647},
	{17, ML_CODE_DMOVP, setCodeOp_N8DW, setInputOp2_Val32_N1_off, verifyResultValueDWord,
		"DMOVP 0->0 N1431655765", 2, 0},
	{18, ML_CODE_DMOVP, setCodeOp_N8DW, setInputOp2_Val32_N1_on, verifyResultValueDWord,
		"DMOVP 1->1 N1431655765", 2, 0},
	{19, ML_CODE_DMOVP, setCodeOp_N8DW, setInputOp2_Val32p_N1_on, verifyResultValueDWord,
		"DMOVP 0->1 N1431655765", 2, 1431655765},
	{20, ML_CODE_DMOVP, setCodeOp_N8DW, setInputOp2_Val32p_maxN1_on, verifyResultValueDWord,
		"DMOVP 0->1 N2147483647", 2, 2147483647},

	{21, ML_CODE_DCML, setCodeLD_2op, setInputSIn_sval32_off, verifyResultValueDWord,
		"DCML off invert 0x55555555", 1, 0},
	{22, ML_CODE_DCML, setCodeLD_2op, setInputSIn_sval32_on, verifyResultValueDWord,
		"DCML on invert 0x55555555", 1, -1431655766}, //0xAAAA AAAA
	{23, ML_CODE_DCML, setCodeLD_2op, setInputSIn_maxval32_on, verifyResultValueDWord,
		"DCML on invert 0x7FFF FFFF", 1, -2147483648}, //0x1000 0000
	{24, ML_CODE_DCML, setCodeOp2_DK1DW2, setInputNIn_Val16_off, verifyResultValueDWord,
		"DCML off invert K0x55555555", 1, 0},
	{25, ML_CODE_DCML, setCodeOp2_DK1DW2, setInputNIn_Val16_on, verifyResultValueDWord,
		"DCML on invert K0x55555555", 1, -1431655766}, //0xAAAA AAAA
	{26, ML_CODE_DCML, setCodeOp2_maxDK1DW2, setInputNIn_Val16_on, verifyResultValueDWord,
		"DCML on invert K0x7FFF FFFF", 1, -2147483648}, //0x1000 0000
	{27, ML_CODE_DCML, setCodeOp_N8DW, setInputOp2_Val32_N1_off, verifyResultValueDWord,
		"DCML off invert N0x55555555", 1, 0},
	{28, ML_CODE_DCML, setCodeOp_N8DW, setInputOp2_Val32_N1_on, verifyResultValueDWord,
		"DCML on invert N0x55555555", 1, -1431655766}, //0xAAAA AAAA
	{29, ML_CODE_DCML, setCodeOp_N8DW, setInputOp2_Val32_maxN1_on, verifyResultValueDWord,
		"DCML on invert N 0x7FFF FFFF", 1, -2147483648}, //0x1000 0000
	{30, ML_CODE_DCML, setCodeOp_N_W, setInputOp2_Val32_N1_off, verifyResultValueDWord,
		"DCML off invert N4 0x5555", 1, 0},
	{31, ML_CODE_DCML, setCodeOp_N_W, setInputOp2_Val32_N1_on, verifyResultValueDWord,
		"DCML on invert N4 0x5555", 1, -21846}, //0xFFFFAAAA

	{32, ML_CODE_DCMLP, setCodeLD_2op, setInputSIn_sval32_off, verifyResultValueDWord,
		"DCMLP 0->0 invert 0x55555555", 2, 0},
	{33, ML_CODE_DCMLP, setCodeLD_2op, setInputSIn_sval32_on, verifyResultValueDWord,
		"DCMLP 1->1 invert 0x55555555", 2, 0},
	{34, ML_CODE_DCMLP, setCodeLD_2op, setInputSIn_sval32p_on, verifyResultValueDWord,
		"DCMLP 0->1 invert 0x55555555", 2, -1431655766}, //0xAAAA AAAA
	{35, ML_CODE_DCMLP, setCodeLD_2op, setInputSIn_maxval32p_on, verifyResultValueDWord,
		"DCMLP 0->1 invert 0x7FFF FFFF", 2, -2147483648}, //0x1000 0000
	{36, ML_CODE_DCMLP, setCodeOp2_DK1DW2, setInputNIn_Val16_off, verifyResultValueDWord,
		"DCMLP 0->0 invert K2 0x55555555", 2, 0},
	{37, ML_CODE_DCMLP, setCodeOp2_DK1DW2, setInputNIn_Val16_on, verifyResultValueDWord,
		"DCMLP 1->1 invert K 0x55555555", 2, 0}, //0xFEFE
	{38, ML_CODE_DCMLP, setCodeOp2_DK1DW2, setInputNIn_Val16p_on, verifyResultValueDWord,
		"DCMLP 0->1 invert K 0x55555555", 2, -1431655766}, //0xAAAA AAAA
	{39, ML_CODE_DCMLP, setCodeOp2_maxDK1DW2, setInputNIn_Val16p_on, verifyResultValueDWord,
		"DCMLP 0->1 invert K 0x7FFF FFFF", 2, -2147483648}, //0x1000 0000
	{40, ML_CODE_DCMLP, setCodeOp_N8DW, setInputOp2_Val32_N1_off, verifyResultValueDWord,
		"DCMLP 0->0 invert N 0x55555555", 2, 0},
	{41, ML_CODE_DCMLP, setCodeOp_N8DW, setInputOp2_Val32_N1_on, verifyResultValueDWord,
		"DCMLP 1->1 invert N 0x55555555", 2, 0}, //0xFEFE
	{42, ML_CODE_DCMLP, setCodeOp_N8DW, setInputOp2_Val32p_N1_on, verifyResultValueDWord,
		"DCMLP 0->1 invert N 0x55555555", 2, -1431655766}, //0xAAAA AAAA
	{43, ML_CODE_DCMLP, setCodeOp_N8DW, setInputOp2_Val32p_maxN1_on, verifyResultValueDWord,
		"DCMLP 0->1 invert N 0x7FFF FFFF", 2, -2147483648}, //0x1000 0000
	{44, ML_CODE_DCMLP, setCodeOp_N_W, setInputOp2_Val32_N1_off, verifyResultValueDWord,
		"DCMLP 0->0 invert N4 0x5555", 2, 0},
	{45, ML_CODE_DCMLP, setCodeOp_N_W, setInputOp2_Val32p_N1_on, verifyResultValueDWord,
		"DCMLP 0->1 invert N4 0x5555", 2, -21846}, //0xFFFFAAAA

	{-1, 0xFFFF, NULL, NULL, NULL, NULL, 0, 0 }
};


int total_transfer_dwd_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_transfer_dwd_test_number; i++)
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


int setCodeOp2_DK1DW2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in_val=1431655765;

	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_maxDK1DW2(uint16 ml_cmd, uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in_val=2147483647;

	if( in > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperand(out, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputSIn_sval32_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in_val=1431655765;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_sval32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in_val=1431655765;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_sval32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in_val=1431655765;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_maxval32_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in_val=2147483647;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputSIn_maxval32p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int in_val=2147483647;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);

	TestCodeTearDown();
}

void setInputOp2_Val32_N1_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=1431655765; // 0x55555555,

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=1431655765; // 0x55555555,

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32p_N1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=1431655765; // 0x55555555,

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32_maxN1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=2147483647; // 0x7FFF FFFF,

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_Val32p_maxN1_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i, in_val=2147483647; // 0x7FFF FFFF,

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}

	TestCodeTearDown();
}


static uint16 getInRegPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0, 6144,4096},
			{8160,8160,8160,8160,2016,8160,0, 12286,8190}};

	return pos[inx_pos][reg];
}

static uint16 getOutPos(int reg, int inx_pos)
{
	uint16 pos[3][2]={ {0,0}, {6144,4096}, {12286,8190}};

	return pos[inx_pos][reg];
}

void test_basic_transfer_dword(int tno, uint16 dummy)
{
	int i, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	int res_word;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getOutPos(out-OPERAND_ML_CODE_D, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getInRegPos(in, i);

					rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if( rc2 == 0 ) continue;

					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

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
						rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
						if(rc == 1)
						{
							test_getDWord(&res_word, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
								reg[in], in_pos, reg[out], out_pos, res_word, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}

void testTransferDWordCommand(void)
{
	int i, index=4;
	int start, end;
	char log[] = "err_trans_dwd.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("transfer dword LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
	test_basic_transfer_dword(index, 0);

#else
	total_transfer_dwd_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DMOV);
	end = getTestCaseNumberEnd(ML_CODE_DCMLP); //ML_CODE_DCMLP

	DBG_LOGPRINT("testBasicTransferDWordCommand: %d to %d total %d\n", start, end, total_transfer_dwd_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_transfer_dword(index, 0);
	}
#endif
	fclose(flog);
}

#endif //USE_CUNIT_TEST_DEF

