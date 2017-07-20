/*
 * test_basic_conversion_float.c
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

extern void TestCodeInit(void);
extern void TestCodeTearDown(void);
extern int runTestCode(int run_step, char *testFuncName);

extern int setCodeVal_W_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
extern int setCodeVal_N_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

extern void setInputSIn_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
extern void setInputSIn_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

extern int verifyResultValueFloat(int tcase, uint8 dest_reg, uint16 pos, float expected);

int setCodeVal_KW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);
int setCodeVal_nKW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos);

void setInputSIn_WW_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_WW_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_WW_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_WW_nVal16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_WW_nVal16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_NW_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_NW_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_NW_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_NW_nVal16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_NW_nVal16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, float);
	char str[40];
	//int count;
	int run_step;
	float expected;

} testFn_st;


static testFn_st testCase[]={
	{0, ML_CODE_BTOF, setCodeVal_W_W, setInputSIn_WW_Val16_off, verifyResultValueFloat,
			"BTOF condition off W", 1, 0.0},
	{1, ML_CODE_BTOF, setCodeVal_W_W, setInputSIn_WW_Val16_on, verifyResultValueFloat,
			"BTOF on W257", 1, 257.0},
	{2, ML_CODE_BTOF, setCodeVal_W_W, setInputSIn_WW_nVal16_on, verifyResultValueFloat,
			"BTOF on W-257", 1, -257.0},
	{3, ML_CODE_BTOF, setCodeVal_N_W, setInputSIn_NW_Val16_off, verifyResultValueFloat,
			"BTOF off N257", 1, 0.0},
	{4, ML_CODE_BTOF, setCodeVal_N_W, setInputSIn_NW_Val16_on, verifyResultValueFloat,
			"BTOF on N257", 1, 257.0},
	{5, ML_CODE_BTOF, setCodeVal_N_W, setInputSIn_NW_nVal16_on, verifyResultValueFloat,
			"BTOF on N-257", 1, -257.0},
	{6, ML_CODE_BTOF, setCodeVal_KW, setInputSIn_none_off, verifyResultValueFloat,
			"BTOF off K257", 1, 0.0},
	{7, ML_CODE_BTOF, setCodeVal_KW, setInputSIn_none_on, verifyResultValueFloat,
			"BTOF on K257", 1, 257.0},
	{8, ML_CODE_BTOF, setCodeVal_nKW, setInputSIn_none_on, verifyResultValueFloat,
			"BTOF on K-257", 1, -257.0},

	{9, ML_CODE_BTOFP, setCodeVal_W_W, setInputSIn_WW_Val16_off, verifyResultValueFloat,
			"BTOFP 0->0 W257", 2, 0.0},
	{10, ML_CODE_BTOFP, setCodeVal_W_W, setInputSIn_WW_Val16_on, verifyResultValueFloat,
			"BTOFP 1->1 W257", 2, 0.0},
	{11, ML_CODE_BTOFP, setCodeVal_W_W, setInputSIn_WW_Val16p_on, verifyResultValueFloat,
			"BTOFP 0->1 W257", 2, 257.0},
	{12, ML_CODE_BTOFP, setCodeVal_W_W, setInputSIn_WW_nVal16p_on, verifyResultValueFloat,
			"BTOFP 0->1 W-257", 2, -257.0},
	{13, ML_CODE_BTOFP, setCodeVal_N_W, setInputSIn_NW_Val16_off, verifyResultValueFloat,
			"BTOFP 0->0 N257", 2, 0.0},
	{14, ML_CODE_BTOFP, setCodeVal_N_W, setInputSIn_NW_Val16_on, verifyResultValueFloat,
			"BTOFP 1->1 N257", 2, 0.0},
	{15, ML_CODE_BTOFP, setCodeVal_N_W, setInputSIn_NW_Val16p_on, verifyResultValueFloat,
			"BTOFP 0->1 N257", 2, 257.0},
	{16, ML_CODE_BTOFP, setCodeVal_N_W, setInputSIn_NW_nVal16p_on, verifyResultValueFloat,
			"BTOFP 0->1 N-257", 2, -257.0},
	{17, ML_CODE_BTOFP, setCodeVal_KW, setInputSIn_none_off, verifyResultValueFloat,
			"BTOFP 0->0 K257", 2, 0.0},
	{18, ML_CODE_BTOFP, setCodeVal_KW, setInputSIn_none_on, verifyResultValueFloat,
			"BTOFP 1->1 K257", 2, 0.0},
	{19, ML_CODE_BTOFP, setCodeVal_KW, setInputSIn_none_tr1, verifyResultValueFloat,
			"BTOFP 0->1 K257", 2, 257.0},
	{20, ML_CODE_BTOFP, setCodeVal_nKW, setInputSIn_none_tr1, verifyResultValueFloat,
			"BTOFP 0->1 K-257", 2, -257.0},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};



int total_conversion_float_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_conversion_float_test_number; i++)
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

int setCodeVal_KW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 257); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeVal_nKW(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, -257); addMLOperand(out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputSIn_WW_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_WW_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_WW_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, 257);

	TestCodeTearDown();
}

void setInputSIn_WW_nVal16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, -257);

	TestCodeTearDown();
}

void setInputSIn_WW_nVal16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	addDeviceControlInstruction(0, (uint8)in, in_pos, -257);

	TestCodeTearDown();
}

void setInputSIn_NW_Val16_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);

	TestCodeTearDown();
}

void setInputSIn_NW_Val16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_NW_Val16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value=257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_NW_nVal16_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value=-257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

void setInputSIn_NW_nVal16p_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	int i;
	short value=-257;

	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((value>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);

	TestCodeTearDown();
}

static uint16 getInPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12287,8191}}; //16bit

	return pos[inx_pos][reg];
}

static uint16 getOutPos(int reg, int inx_pos)
{
	//uint16 pos[3][2]={ {0,0}, {6144,4096}, {12286,8190}}; // -2
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12286,8190}};

	return pos[inx_pos][reg];
}

static FILE *flog;
void test_basic_conversion_float(int tno, uint16 dummy)
{
	int i=1, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	float res_float;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SB", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_D; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getOutPos(out, olast);
			for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_D; in++)
			{
				//for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getInPos(in, i);

					if(in == out && (in_pos == out_pos || in_pos+16 == out_pos || in_pos == out_pos+1) )
					{
						continue;
					}

					rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if( rc2 == 0 ) continue;

					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

					rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error!\n",
							tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName);
					}
					else
					{
						rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
						if(rc == 1)
						{
							test_getFloat(&res_float, out, out_pos);
							fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%f exp=%f\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								reg[in], in_pos, reg[out], out_pos, res_float, testCase[tno].expected);
						}
					}
				}
			}
		}
	}
}


void testConversionFloatCommand(void)
{
	int i, index=2;
	int start, end;
	char log[] = "err_conv_float.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("conversion float LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
		test_basic_conversion_float(index, 0);

#else
	total_conversion_float_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_BTOF);
	end = getTestCaseNumberEnd(ML_CODE_BTOFP);

	DBG_LOGPRINT("testConversionFloatCommand: %d to %d total %d\n", start, end, total_conversion_float_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_conversion_float(index, 0);
	}
#endif
	fclose(flog);
}
#endif
