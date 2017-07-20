/*
 * test_Op1_template.c
 *
 *  Created on: Sep 1, 2015
 *      Author: hrjung
 */

#if 0 //#ifdef USE_CUNIT_TEST_DEF

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


void setCodeOp1_word(int cond_type, uint8 cond_reg, uint16 cond_pos, uint16 ml_cmd, uint8 reg, uint16 pos)
{
	addMLOperator(ML_CODE_LD); addMLOperand(cond_reg, cond_pos);
	addMLOperator(ml_cmd); addMLOperand(reg, pos);
	addMLOperator(ML_CODE_END);
}

void setCodeOp1_Nibble(int cond_type, uint8 cond_reg, uint16 cond_pos, uint16 ml_cmd, uint8 reg, uint16 pos, uint16 nNibble)
{
	addMLOperator(ML_CODE_LD); addMLOperand(cond_reg, cond_pos);
	addMLOperator(ml_cmd); addMLOperandNibble(reg, pos, nNibble);
	addMLOperator(ML_CODE_END);
}



#endif
