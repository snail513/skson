/*
 * test_basic_arithmetic_index.c
 *
 *  Created on: Aug 27, 2015
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
extern int setCodeOp2_K1234_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_N_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp2_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

extern int verifyResultValueWord(int tcase, uint8 dest_reg, uint16 pos, short expected);
extern int verifyResultValueNibble4(int tcase, uint8 dest_reg, uint16 pos, short expected);

int setCodeOp1_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_K0x1234_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_W_WWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_KW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_KK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_NW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_NWZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZW_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZK_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZN_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_NWZ_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZWZ_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_BKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_BKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZBK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZBK_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);


void setInputOp2_val16_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_KWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_NWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val16p_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp1_val16_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val16_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val16p_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val16_WZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val16p_WZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val16_WZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val16p_WZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp3_val16_WW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_W_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_KW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_NW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_NWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZN_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_NWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val16p_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp2_BCD4_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_KWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_NWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WZW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WZN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WZWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD4p_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp3_BCD4_WW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_W_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_KW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_NW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_NWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZN_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_NWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD4p_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);


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
	int (*verifyResult_fn)(int, uint8, uint16, short);
	char str[40];
	//int count;
	int z_type; // 0 : out is index, 1: op1 is index
	int run_step;
	short expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_ADD, setCodeOp2_W_WZ, setInputOp2_val16_WWZ_off, verifyResultValueWord,
			"ADD off op1+zop2", 0, 1, 5678},
	{1, ML_CODE_ADD, setCodeOp2_W_WZ, setInputOp2_val16_WWZ_on, verifyResultValueWord,
			"ADD on op1+zop2", 0, 1, 6912},
	{2, ML_CODE_ADD, setCodeOp2_W_WZ, setInputOp2_val16_WWZ_over_on, verifyResultValueWord,
			"ADD on op1+zop2 over", 0, 1, -32767},
	{3, ML_CODE_ADD, setCodeOp2_K1234_WZ, setInputOp2_val16_KWZ_off, verifyResultValueWord,
			"ADD off K+zop2", 0, 1, 5678},
	{4, ML_CODE_ADD, setCodeOp2_K1234_WZ, setInputOp2_val16_KWZ_on, verifyResultValueWord,
			"ADD on K+zop2", 0, 1, 6912},
	{5, ML_CODE_ADD, setCodeOp2_N_WZ, setInputOp2_val16_NWZ_off, verifyResultValueWord,
			"ADD off nop1+zop2", 0, 1, 5678},
	{6, ML_CODE_ADD, setCodeOp2_N_WZ, setInputOp2_val16_NWZ_on, verifyResultValueWord,
			"ADD on nop1+zop2", 0, 1, 6912},
	{7, ML_CODE_ADD, setCodeOp2_WZ_W, setInputOp2_val16_WZW_off, verifyResultValueWord,
			"ADD off zop1+op2", 1, 1, 5678},
	{8, ML_CODE_ADD, setCodeOp2_WZ_W, setInputOp2_val16_WZW_on, verifyResultValueWord,
			"ADD on zop1+op2", 1, 1, 6912},
	{9, ML_CODE_ADD, setCodeOp2_WZ_N, setInputOp2_val16_WZN_off, verifyResultValueNibble4,
			"ADD off zop1+nop2", 1, 1, 5678},
	{10, ML_CODE_ADD, setCodeOp2_WZ_N, setInputOp2_val16_WZN_on, verifyResultValueNibble4,
			"ADD on zop1+nop2", 1, 1, 6912},
	{11, ML_CODE_ADD, setCodeOp2_WZ_WZ, setInputOp2_val16_WZWZ_off, verifyResultValueWord,
			"ADD off zop1+zop2", 2, 1, 5678},
	{12, ML_CODE_ADD, setCodeOp2_WZ_WZ, setInputOp2_val16_WZWZ_on, verifyResultValueWord,
			"ADD on zop1+zop2", 2, 1, 6912},

	{13, ML_CODE_ADDP, setCodeOp2_W_WZ, setInputOp2_val16_WWZ_off, verifyResultValueWord,
			"ADDP 0->0 op1+zop2", 0, 2, 5678},
	{14, ML_CODE_ADDP, setCodeOp2_W_WZ, setInputOp2_val16p_WWZ_on, verifyResultValueWord,
			"ADDP 0->1 op1+zop2", 0, 2, 6912},
	{15, ML_CODE_ADDP, setCodeOp2_W_WZ, setInputOp2_val16p_WWZ_over_on, verifyResultValueWord,
			"ADDP 0->1 op1+zop2 over", 0, 2, -32767},
	{16, ML_CODE_ADDP, setCodeOp2_K1234_WZ, setInputOp2_val16_KWZ_off, verifyResultValueWord,
			"ADDP 0->0 K+zop2", 0, 2, 5678},
	{17, ML_CODE_ADDP, setCodeOp2_K1234_WZ, setInputOp2_val16p_KWZ_on, verifyResultValueWord,
			"ADDP 0->1 K+zop2", 0, 2, 6912},
	{18, ML_CODE_ADDP, setCodeOp2_N_WZ, setInputOp2_val16_NWZ_off, verifyResultValueWord,
			"ADDP 0->0 nop1+zop2", 0, 2, 5678},
	{19, ML_CODE_ADDP, setCodeOp2_N_WZ, setInputOp2_val16p_NWZ_on, verifyResultValueWord,
			"ADDP 0->1 nop1+zop2", 0, 2, 6912},
	{20, ML_CODE_ADDP, setCodeOp2_WZ_W, setInputOp2_val16_WZW_off, verifyResultValueWord,
			"ADDP 0->0 zop1+op2", 1, 2, 5678},
	{21, ML_CODE_ADDP, setCodeOp2_WZ_W, setInputOp2_val16p_WZW_on, verifyResultValueWord,
			"ADDP 0->1 zop1+op2", 1, 2, 6912},
	{22, ML_CODE_ADDP, setCodeOp2_WZ_N, setInputOp2_val16_WZN_off, verifyResultValueNibble4,
			"ADDP 0->0 zop1+nop2", 1, 2, 5678},
	{23, ML_CODE_ADDP, setCodeOp2_WZ_N, setInputOp2_val16p_WZN_on, verifyResultValueNibble4,
			"ADDP 0->1 zop1+nop2", 1, 2, 6912},
	{24, ML_CODE_ADDP, setCodeOp2_WZ_WZ, setInputOp2_val16_WZWZ_off, verifyResultValueWord,
			"ADDP 0->0 zop1+zop2", 2, 2, 5678},
	{25, ML_CODE_ADDP, setCodeOp2_WZ_WZ, setInputOp2_val16p_WZWZ_on, verifyResultValueWord,
			"ADDP 0->1 zop1+zop2", 2, 2, 6912},

	{26, ML_CODE_SUB, setCodeOp2_W_WZ, setInputOp2_val16_WWZ_off, verifyResultValueWord,
			"SUB off zop2-op1", 0, 1, 5678},
	{27, ML_CODE_SUB, setCodeOp2_W_WZ, setInputOp2_val16_WWZ_on, verifyResultValueWord,
			"SUB on zop2-op1", 0, 1, 4444},
	{28, ML_CODE_SUB, setCodeOp2_W_WZ, setInputOp2_val16_WWZ_under_on, verifyResultValueWord,
			"SUB on zop2-op1 over", 0, 1, 32766},
	{29, ML_CODE_SUB, setCodeOp2_K1234_WZ, setInputOp2_val16_KWZ_off, verifyResultValueWord,
			"SUB off zop2-K", 0, 1, 5678},
	{30, ML_CODE_SUB, setCodeOp2_K1234_WZ, setInputOp2_val16_KWZ_on, verifyResultValueWord,
			"SUB on zop2-K", 0, 1, 4444},
	{31, ML_CODE_SUB, setCodeOp2_N_WZ, setInputOp2_val16_NWZ_off, verifyResultValueWord,
			"SUB off zop2-nop1", 0, 1, 5678},
	{32, ML_CODE_SUB, setCodeOp2_N_WZ, setInputOp2_val16_NWZ_on, verifyResultValueWord,
			"SUB on zop2-nop1", 0, 1, 4444},
	{33, ML_CODE_SUB, setCodeOp2_WZ_W, setInputOp2_val16_WZW_off, verifyResultValueWord,
			"SUB off op2-zop1", 1, 1, 5678},
	{34, ML_CODE_SUB, setCodeOp2_WZ_W, setInputOp2_val16_WZW_on, verifyResultValueWord,
			"SUB on op2-zop1", 1, 1, 4444},
	{35, ML_CODE_SUB, setCodeOp2_WZ_N, setInputOp2_val16_WZN_off, verifyResultValueNibble4,
			"SUB off nop2-zop1", 1, 1, 5678},
	{36, ML_CODE_SUB, setCodeOp2_WZ_N, setInputOp2_val16_WZN_on, verifyResultValueNibble4,
			"SUB on nop2-zop1", 1, 1, 4444},
	{37, ML_CODE_SUB, setCodeOp2_WZ_WZ, setInputOp2_val16_WZWZ_off, verifyResultValueWord,
			"SUB off zop2-zop1", 2, 1, 5678},
	{38, ML_CODE_SUB, setCodeOp2_WZ_WZ, setInputOp2_val16_WZWZ_on, verifyResultValueWord,
			"SUB on zop2-zop1", 2, 1, 4444},

	{39, ML_CODE_SUBP, setCodeOp2_W_WZ, setInputOp2_val16_WWZ_off, verifyResultValueWord,
			"SUBP 0->0 zop2-op1", 0, 2, 5678},
	{40, ML_CODE_SUBP, setCodeOp2_W_WZ, setInputOp2_val16p_WWZ_on, verifyResultValueWord,
			"SUBP 0->1 zop2-op1", 0, 2, 4444},
	{41, ML_CODE_SUBP, setCodeOp2_W_WZ, setInputOp2_val16p_WWZ_under_on, verifyResultValueWord,
			"SUBP 0->1 zop2-op1 over", 0, 2, 32766},
	{42, ML_CODE_SUBP, setCodeOp2_K1234_WZ, setInputOp2_val16_KWZ_off, verifyResultValueWord,
			"SUBP 0->0 zop2-K", 0, 2, 5678},
	{43, ML_CODE_SUBP, setCodeOp2_K1234_WZ, setInputOp2_val16p_KWZ_on, verifyResultValueWord,
			"SUBP 0->1 zop2-K", 0, 2, 4444},
	{44, ML_CODE_SUBP, setCodeOp2_N_WZ, setInputOp2_val16_NWZ_off, verifyResultValueWord,
			"SUBP 0->0 zop2-nop1", 0, 2, 5678},
	{45, ML_CODE_SUBP, setCodeOp2_N_WZ, setInputOp2_val16p_NWZ_on, verifyResultValueWord,
			"SUBP 0->1 zop2-nop1", 0, 2, 4444},
	{46, ML_CODE_SUBP, setCodeOp2_WZ_W, setInputOp2_val16_WZW_off, verifyResultValueWord,
			"SUBP 0->0 op2-zop1", 1, 2, 5678},
	{47, ML_CODE_SUBP, setCodeOp2_WZ_W, setInputOp2_val16p_WZW_on, verifyResultValueWord,
			"SUBP 0->1 op2-zop1", 1, 2, 4444},
	{48, ML_CODE_SUBP, setCodeOp2_WZ_N, setInputOp2_val16_WZN_off, verifyResultValueNibble4,
			"SUBP 0->0 nop2-zop1", 1, 2, 5678},
	{49, ML_CODE_SUBP, setCodeOp2_WZ_N, setInputOp2_val16p_WZN_on, verifyResultValueNibble4,
			"SUBP 0->1 nop2-zop1", 1, 2, 4444},
	{50, ML_CODE_SUBP, setCodeOp2_WZ_WZ, setInputOp2_val16_WZWZ_off, verifyResultValueWord,
			"SUBP 0->0 zop2-zop1", 2, 2, 5678},
	{51, ML_CODE_SUBP, setCodeOp2_WZ_WZ, setInputOp2_val16p_WZWZ_on, verifyResultValueWord,
			"SUBP 0->1 zop2-zop1", 2, 2, 4444},

	{52, ML_CODE_INC, setCodeOp1_WZ, setInputOp1_val16_WZ_off, verifyResultValueWord,
			"INC off", 0, 1, 5678},
	{53, ML_CODE_INC, setCodeOp1_WZ, setInputOp1_val16_WZ_on, verifyResultValueWord,
			"INC on", 0, 1, 5679},
	{54, ML_CODE_INC, setCodeOp1_WZ, setInputOp1_val16_WZ_over_on, verifyResultValueWord,
			"INC on over", 0, 1, -32768},

	{55, ML_CODE_INCP, setCodeOp1_WZ, setInputOp1_val16_WZ_off, verifyResultValueWord,
			"INCP 0->0", 0, 2, 5678},
	{56, ML_CODE_INCP, setCodeOp1_WZ, setInputOp1_val16p_WZ_on, verifyResultValueWord,
			"INCP 0->1", 0, 2, 5679},
	{57, ML_CODE_INCP, setCodeOp1_WZ, setInputOp1_val16p_WZ_over_on, verifyResultValueWord,
			"INCP 0->1 over", 0, 2, -32768},

	{58, ML_CODE_DEC, setCodeOp1_WZ, setInputOp1_val16_WZ_off, verifyResultValueWord,
			"DEC off", 0, 1, 5678},
	{59, ML_CODE_DEC, setCodeOp1_WZ, setInputOp1_val16_WZ_on, verifyResultValueWord,
			"DEC on", 0, 1, 5677},
	{60, ML_CODE_DEC, setCodeOp1_WZ, setInputOp1_val16_WZ_under_on, verifyResultValueWord,
			"DEC on over", 0, 1, 32767},

	{61, ML_CODE_DECP, setCodeOp1_WZ, setInputOp1_val16_WZ_off, verifyResultValueWord,
			"DECP 0->0", 0, 2, 5678},
	{62, ML_CODE_DECP, setCodeOp1_WZ, setInputOp1_val16p_WZ_on, verifyResultValueWord,
			"DECP 0->1", 0, 2, 5677},
	{63, ML_CODE_DECP, setCodeOp1_WZ, setInputOp1_val16p_WZ_under_on, verifyResultValueWord,
			"DECP 0->1 over", 0, 2, 32767},

	{64, ML_CODE_ADDS, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_off, verifyResultValueWord,
			"ADDS off zop3=op1+op2", 0, 1, 0},
	{65, ML_CODE_ADDS, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_on, verifyResultValueWord,
			"ADDS on zop3=op1+op2", 0, 1, 6912},
	{66, ML_CODE_ADDS, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_off, verifyResultValueWord,
			"ADDS off zop3=op1+op2", 0, 1, 0},
	{67, ML_CODE_ADDS, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_on, verifyResultValueWord,
			"ADDS on zop3=op1+op2", 0, 1, 6912},
	{68, ML_CODE_ADDS, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_off, verifyResultValueWord,
			"ADDS off zop3=K+op2", 0, 1, 0},
	{69, ML_CODE_ADDS, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_on, verifyResultValueWord,
			"ADDS on zop3=K+op2", 0, 1, 6912},
	{70, ML_CODE_ADDS, setCodeOp3S_KK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"ADDS off zop3=K+K", 0, 1, 0},
	{71, ML_CODE_ADDS, setCodeOp3S_KK_WZ, setInputOp2_none_on, verifyResultValueWord,
			"ADDS on zop3=K+K", 0, 1, 6912},
	{72, ML_CODE_ADDS, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_off, verifyResultValueWord,
			"ADDS off zop3=nop1+op2", 0, 1, 0},
	{73, ML_CODE_ADDS, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_on, verifyResultValueWord,
			"ADDS on zop3=nop1+op2", 0, 1, 6912},
	{74, ML_CODE_ADDS, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_off, verifyResultValueWord,
			"ADDS off zop3=op1+nop2", 0, 1, 0},
	{75, ML_CODE_ADDS, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_on, verifyResultValueWord,
			"ADDS on zop3=op1+nop2", 0, 1, 6912},
	{76, ML_CODE_ADDS, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_off, verifyResultValueWord,
			"ADDS off zop3=zop1+op2", 2, 1, 0},
	{77, ML_CODE_ADDS, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_on, verifyResultValueWord,
			"ADDS on zop3=zop1+op2", 2, 1, 6912},
	{78, ML_CODE_ADDS, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_off, verifyResultValueWord,
			"ADDS off zop3=zop1+K", 2, 1, 0},
	{79, ML_CODE_ADDS, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_on, verifyResultValueWord,
			"ADDS on zop3=zop1+K", 2, 1, 6912},
	{80, ML_CODE_ADDS, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_off, verifyResultValueWord,
			"ADDS off zop3=zop1+nop2", 2, 1, 0},
	{81, ML_CODE_ADDS, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_on, verifyResultValueWord,
			"ADDS on zop3=zop1+nop2", 2, 1, 6912},
	{82, ML_CODE_ADDS, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_off, verifyResultValueWord,
			"ADDS off zop3=nop1+zop2", 2, 1, 0},
	{83, ML_CODE_ADDS, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_on, verifyResultValueWord,
			"ADDS on zop3=nop1+zop2", 2, 1, 6912},
	{84, ML_CODE_ADDS, setCodeOp3S_WZW_N, setInputOp3_val16_WZW_WZ_off, verifyResultValueNibble4,
			"ADDS off nop3=zop1+op2", 1, 1, 0},
	{85, ML_CODE_ADDS, setCodeOp3S_WZW_N, setInputOp3_val16_WZW_WZ_on, verifyResultValueNibble4,
			"ADDS on nop3=zop1+op2", 1, 1, 6912},
	{86, ML_CODE_ADDS, setCodeOp3S_WZK_N, setInputOp3_val16_WZK_WZ_off, verifyResultValueNibble4,
			"ADDS off nop3=zop1+K", 1, 1, 0},
	{87, ML_CODE_ADDS, setCodeOp3S_WZK_N, setInputOp3_val16_WZK_WZ_on, verifyResultValueNibble4,
			"ADDS on nop3=zop1+K", 1, 1, 6912},
	{88, ML_CODE_ADDS, setCodeOp3S_WZN_N, setInputOp3_val16_WZN_N_off, verifyResultValueNibble4,
			"ADDS off nop3=zop1+nop2", 1, 1, 0},
	{89, ML_CODE_ADDS, setCodeOp3S_WZN_N, setInputOp3_val16_WZN_N_on, verifyResultValueNibble4,
			"ADDS on nop3=zop1+nop2", 1, 1, 6912},
	{90, ML_CODE_ADDS, setCodeOp3S_NWZ_N, setInputOp3_val16_NWZ_N_off, verifyResultValueNibble4,
			"ADDS off nop3=nop1+zop2", 1, 1, 0},
	{91, ML_CODE_ADDS, setCodeOp3S_NWZ_N, setInputOp3_val16_NWZ_N_on, verifyResultValueNibble4,
			"ADDS on nop3=nop1+zop2", 1, 1, 6912},
	{92, ML_CODE_ADDS, setCodeOp3S_WZWZ_N, setInputOp3_val16_WZWZ_N_off, verifyResultValueNibble4,
			"ADDS off nop3=zop1+zop2", 1, 1, 0},
	{93, ML_CODE_ADDS, setCodeOp3S_WZWZ_N, setInputOp3_val16_WZWZ_N_on, verifyResultValueNibble4,
			"ADDS on nop3=zop1+zop2", 1, 1, 6912},

	{94, ML_CODE_ADDPS, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=op1+op2", 0, 2, 0},
	{95, ML_CODE_ADDPS, setCodeOp3S_WW_WZ, setInputOp3_val16p_WW_WZ_on, verifyResultValueWord,
			"ADDPS 0->1 zop3=op1+op2", 0, 2, 6912},
	{96, ML_CODE_ADDPS, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=op1+op2", 0, 2, 0},
	{97, ML_CODE_ADDPS, setCodeOp3S_W_WWZ, setInputOp3_val16p_W_WWZ_on, verifyResultValueWord,
			"ADDPS 0->1 zop3=op1+op2", 0, 2, 6912},
	{98, ML_CODE_ADDPS, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=K+op2", 0, 2, 0},
	{99, ML_CODE_ADDPS, setCodeOp3S_KW_WZ, setInputOp3_val16p_KW_WZ_on, verifyResultValueWord,
			"ADDPS 0->1 zop3=K+op2", 0, 2, 6912},
	{100, ML_CODE_ADDPS, setCodeOp3S_KK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=K+K", 0, 2, 0},
	{101, ML_CODE_ADDPS, setCodeOp3S_KK_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"ADDPS 0->1 zop3=K+K", 0, 2, 6912},
	{102, ML_CODE_ADDPS, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=nop1+op2", 0, 2, 0},
	{103, ML_CODE_ADDPS, setCodeOp3S_NW_WZ, setInputOp3_val16p_NW_WZ_on, verifyResultValueWord,
			"ADDPS 0->1 zop3=nop1+op2", 0, 2, 6912},
	{104, ML_CODE_ADDPS, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=op1+nop2", 0, 2, 0},
	{105, ML_CODE_ADDPS, setCodeOp3S_WN_WZ, setInputOp3_val16p_WN_WZ_on, verifyResultValueWord,
			"ADDPS 0->1 zop3=op1+nop2", 0, 2, 6912},
	{106, ML_CODE_ADDPS, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=zop1+op2", 2, 2, 0},
	{107, ML_CODE_ADDPS, setCodeOp3S_WZW_WZ, setInputOp3_val16p_WZW_WZ_on, verifyResultValueWord,
			"ADDPS 0->1 zop3=zop1+op2", 2, 2, 6912},
	{108, ML_CODE_ADDPS, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=zop1+K", 2, 2, 0},
	{109, ML_CODE_ADDPS, setCodeOp3S_WZK_WZ, setInputOp3_val16p_WZK_WZ_on, verifyResultValueWord,
			"ADDPS 0->1 zop3=zop1+K", 2, 2, 6912},
	{110, ML_CODE_ADDPS, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=zop1+nop2", 2, 2, 0},
	{111, ML_CODE_ADDPS, setCodeOp3S_WZN_WZ, setInputOp3_val16p_WZN_WZ_on, verifyResultValueWord,
			"ADDPS 0->1 zop3=zop1+nop2", 2, 2, 6912},
	{112, ML_CODE_ADDPS, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_off, verifyResultValueWord,
			"ADDPS 0->0 zop3=nop1+zop2", 2, 2, 0},
	{113, ML_CODE_ADDPS, setCodeOp3S_NWZ_WZ, setInputOp3_val16p_NWZ_WZ_on, verifyResultValueWord,
			"ADDPS 0->1 zop3=nop1+zop2", 2, 2, 6912},
	{114, ML_CODE_ADDPS, setCodeOp3S_WZW_N, setInputOp3_val16_WZW_WZ_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop3=zop1+op2", 1, 2, 0},
	{115, ML_CODE_ADDPS, setCodeOp3S_WZW_N, setInputOp3_val16p_WZW_WZ_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop3=zop1+op2", 1, 2, 6912},
	{116, ML_CODE_ADDPS, setCodeOp3S_WZK_N, setInputOp3_val16_WZK_WZ_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop3=zop1+K", 1, 2, 0},
	{117, ML_CODE_ADDPS, setCodeOp3S_WZK_N, setInputOp3_val16p_WZK_WZ_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop3=zop1+K", 1, 2, 6912},
	{118, ML_CODE_ADDPS, setCodeOp3S_WZN_N, setInputOp3_val16_WZN_N_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop3=zop1+nop2", 1, 2, 0},
	{119, ML_CODE_ADDPS, setCodeOp3S_WZN_N, setInputOp3_val16p_WZN_N_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop3=zop1+nop2", 1, 2, 6912},
	{120, ML_CODE_ADDPS, setCodeOp3S_NWZ_N, setInputOp3_val16_NWZ_N_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop3=nop1+zop2", 1, 2, 0},
	{121, ML_CODE_ADDPS, setCodeOp3S_NWZ_N, setInputOp3_val16p_NWZ_N_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop3=nop1+zop2", 1, 2, 6912},
	{122, ML_CODE_ADDPS, setCodeOp3S_WZWZ_N, setInputOp3_val16_WZWZ_N_off, verifyResultValueNibble4,
			"ADDPS 0->0 nop3=zop1+zop2", 1, 2, 0},
	{123, ML_CODE_ADDPS, setCodeOp3S_WZWZ_N, setInputOp3_val16p_WZWZ_N_on, verifyResultValueNibble4,
			"ADDPS 0->1 nop3=zop1+zop2", 1, 2, 6912},

	{124, ML_CODE_SUBS, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_off, verifyResultValueWord,
			"SUBS off zop3=op1-op2", 0, 1, 0},
	{125, ML_CODE_SUBS, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_on, verifyResultValueWord,
			"SUBS on zop3=op1-op2", 0, 1, 4444},
	{126, ML_CODE_SUBS, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_off, verifyResultValueWord,
			"SUBS off zop3=op1-op2", 0, 1, 0},
	{127, ML_CODE_SUBS, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_on, verifyResultValueWord,
			"SUBS on zop3=op1-op2", 0, 1, 4444},
	{128, ML_CODE_SUBS, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_off, verifyResultValueWord,
			"SUBS off zop3=K-op2", 0, 1, 0},
	{129, ML_CODE_SUBS, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_on, verifyResultValueWord,
			"SUBS on zop3=K-op2", 0, 1, 4444},
	{130, ML_CODE_SUBS, setCodeOp3S_KK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"SUBS off zop3=K-K", 0, 1, 0},
	{131, ML_CODE_SUBS, setCodeOp3S_KK_WZ, setInputOp2_none_on, verifyResultValueWord,
			"SUBS on zop3=K-K", 0, 1, 4444},
	{132, ML_CODE_SUBS, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_off, verifyResultValueWord,
			"SUBS off zop3=nop1-op2", 0, 1, 0},
	{133, ML_CODE_SUBS, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_on, verifyResultValueWord,
			"SUBS on zop3=nop1-op2", 0, 1, 4444},
	{134, ML_CODE_SUBS, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_off, verifyResultValueWord,
			"SUBS off zop3=op1-nop2", 0, 1, 0},
	{135, ML_CODE_SUBS, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_on, verifyResultValueWord,
			"SUBS on zop3=op1-nop2", 0, 1, 4444},
	{136, ML_CODE_SUBS, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_off, verifyResultValueWord,
			"SUBS off zop3=zop1-op2", 2, 1, 0},
	{137, ML_CODE_SUBS, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_on, verifyResultValueWord,
			"SUBS on zop3=zop1-op2", 2, 1, 4444},
	{138, ML_CODE_SUBS, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_off, verifyResultValueWord,
			"SUBS off zop3=zop1-K", 2, 1, 0},
	{139, ML_CODE_SUBS, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_on, verifyResultValueWord,
			"SUBS on zop3=zop1-K", 2, 1, 4444},
	{140, ML_CODE_SUBS, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_off, verifyResultValueWord,
			"SUBS off zop3=zop1-nop2", 2, 1, 0},
	{141, ML_CODE_SUBS, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_on, verifyResultValueWord,
			"SUBS on zop3=zop1-nop2", 2, 1, 4444},
	{142, ML_CODE_SUBS, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_off, verifyResultValueWord,
			"SUBS off zop3=nop1-zop2", 2, 1, 0},
	{143, ML_CODE_SUBS, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_on, verifyResultValueWord,
			"SUBS on zop3=nop1-zop2", 2, 1, 4444},
	{144, ML_CODE_SUBS, setCodeOp3S_WZW_N, setInputOp3_val16_WZW_WZ_off, verifyResultValueNibble4,
			"SUBS off nop3=zop1-op2", 1, 1, 0},
	{145, ML_CODE_SUBS, setCodeOp3S_WZW_N, setInputOp3_val16_WZW_WZ_on, verifyResultValueNibble4,
			"SUBS on nop3=zop1-op2", 1, 1, 4444},
	{146, ML_CODE_SUBS, setCodeOp3S_WZK_N, setInputOp3_val16_WZK_WZ_off, verifyResultValueNibble4,
			"SUBS off nop3=zop1-K", 1, 1, 0},
	{147, ML_CODE_SUBS, setCodeOp3S_WZK_N, setInputOp3_val16_WZK_WZ_on, verifyResultValueNibble4,
			"SUBS on nop3=zop1-K", 1, 1, 4444},
	{148, ML_CODE_SUBS, setCodeOp3S_WZN_N, setInputOp3_val16_WZN_N_off, verifyResultValueNibble4,
			"SUBS off nop3=zop1-nop2", 1, 1, 0},
	{149, ML_CODE_SUBS, setCodeOp3S_WZN_N, setInputOp3_val16_WZN_N_on, verifyResultValueNibble4,
			"SUBS on nop3=zop1-nop2", 1, 1, 4444},
	{150, ML_CODE_SUBS, setCodeOp3S_NWZ_N, setInputOp3_val16_NWZ_N_off, verifyResultValueNibble4,
			"SUBS off nop3=nop1-zop2", 1, 1, 0},
	{151, ML_CODE_SUBS, setCodeOp3S_NWZ_N, setInputOp3_val16_NWZ_N_on, verifyResultValueNibble4,
			"SUBS on nop3=nop1-zop2", 1, 1, 4444},
	{152, ML_CODE_SUBS, setCodeOp3S_WZWZ_N, setInputOp3_val16_WZWZ_N_off, verifyResultValueNibble4,
			"SUBS off nop3=zop1-zop2", 1, 1, 0},
	{153, ML_CODE_SUBS, setCodeOp3S_WZWZ_N, setInputOp3_val16_WZWZ_N_on, verifyResultValueNibble4,
			"SUBS on nop3=zop1-zop2", 1, 1, 4444},

	{154, ML_CODE_SUBPS, setCodeOp3S_WW_WZ, setInputOp3_val16_WW_WZ_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=op1-op2", 0, 2, 0},
	{155, ML_CODE_SUBPS, setCodeOp3S_WW_WZ, setInputOp3_val16p_WW_WZ_on, verifyResultValueWord,
			"SUBPS 0->1 zop3=op1-op2", 0, 2, 4444},
	{156, ML_CODE_SUBPS, setCodeOp3S_W_WWZ, setInputOp3_val16_W_WWZ_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=op1-op2", 0, 2, 0},
	{157, ML_CODE_SUBPS, setCodeOp3S_W_WWZ, setInputOp3_val16p_W_WWZ_on, verifyResultValueWord,
			"SUBPS 0->1 zop3=op1-op2", 0, 2, 4444},
	{158, ML_CODE_SUBPS, setCodeOp3S_KW_WZ, setInputOp3_val16_KW_WZ_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=K-op2", 0, 2, 0},
	{159, ML_CODE_SUBPS, setCodeOp3S_KW_WZ, setInputOp3_val16p_KW_WZ_on, verifyResultValueWord,
			"SUBPS 0->1 zop3=K-op2", 0, 2, 4444},
	{160, ML_CODE_SUBPS, setCodeOp3S_KK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=K-K", 0, 2, 0},
	{161, ML_CODE_SUBPS, setCodeOp3S_KK_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"SUBPS 0->1 zop3=K-K", 0, 2, 4444},
	{162, ML_CODE_SUBPS, setCodeOp3S_NW_WZ, setInputOp3_val16_NW_WZ_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=nop1-op2", 0, 2, 0},
	{163, ML_CODE_SUBPS, setCodeOp3S_NW_WZ, setInputOp3_val16p_NW_WZ_on, verifyResultValueWord,
			"SUBPS 0->1 zop3=nop1-op2", 0, 2, 4444},
	{164, ML_CODE_SUBPS, setCodeOp3S_WN_WZ, setInputOp3_val16_WN_WZ_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=op1-nop2", 0, 2, 0},
	{165, ML_CODE_SUBPS, setCodeOp3S_WN_WZ, setInputOp3_val16p_WN_WZ_on, verifyResultValueWord,
			"SUBPS 0->1 zop3=op1-nop2", 0, 2, 4444},
	{166, ML_CODE_SUBPS, setCodeOp3S_WZW_WZ, setInputOp3_val16_WZW_WZ_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=zop1-op2", 2, 2, 0},
	{167, ML_CODE_SUBPS, setCodeOp3S_WZW_WZ, setInputOp3_val16p_WZW_WZ_on, verifyResultValueWord,
			"SUBPS 0->1 zop3=zop1-op2", 2, 2, 4444},
	{168, ML_CODE_SUBPS, setCodeOp3S_WZK_WZ, setInputOp3_val16_WZK_WZ_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=zop1-K", 2, 2, 0},
	{169, ML_CODE_SUBPS, setCodeOp3S_WZK_WZ, setInputOp3_val16p_WZK_WZ_on, verifyResultValueWord,
			"SUBPS 0->1 zop3=zop1-K", 2, 2, 4444},
	{170, ML_CODE_SUBPS, setCodeOp3S_WZN_WZ, setInputOp3_val16_WZN_WZ_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=zop1-nop2", 2, 2, 0},
	{171, ML_CODE_SUBPS, setCodeOp3S_WZN_WZ, setInputOp3_val16p_WZN_WZ_on, verifyResultValueWord,
			"SUBPS 0->1 zop3=zop1-nop2", 2, 2, 4444},
	{172, ML_CODE_SUBPS, setCodeOp3S_NWZ_WZ, setInputOp3_val16_NWZ_WZ_off, verifyResultValueWord,
			"SUBPS 0->0 zop3=nop1-zop2", 2, 2, 0},
	{173, ML_CODE_SUBPS, setCodeOp3S_NWZ_WZ, setInputOp3_val16p_NWZ_WZ_on, verifyResultValueWord,
			"SUBPS 0->1 zop3=nop1-zop2", 2, 2, 4444},
	{174, ML_CODE_SUBPS, setCodeOp3S_WZW_N, setInputOp3_val16_WZW_WZ_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop3=zop1-op2", 1, 2, 0},
	{175, ML_CODE_SUBPS, setCodeOp3S_WZW_N, setInputOp3_val16p_WZW_WZ_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop3=zop1-op2", 1, 2, 4444},
	{176, ML_CODE_SUBPS, setCodeOp3S_WZK_N, setInputOp3_val16_WZK_WZ_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop3=zop1-K", 1, 2, 0},
	{177, ML_CODE_SUBPS, setCodeOp3S_WZK_N, setInputOp3_val16p_WZK_WZ_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop3=zop1-K", 1, 2, 4444},
	{178, ML_CODE_SUBPS, setCodeOp3S_WZN_N, setInputOp3_val16_WZN_N_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop3=zop1-nop2", 1, 2, 0},
	{179, ML_CODE_SUBPS, setCodeOp3S_WZN_N, setInputOp3_val16p_WZN_N_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop3=zop1-nop2", 1, 2, 4444},
	{180, ML_CODE_SUBPS, setCodeOp3S_NWZ_N, setInputOp3_val16_NWZ_N_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop3=nop1-zop2", 1, 2, 0},
	{181, ML_CODE_SUBPS, setCodeOp3S_NWZ_N, setInputOp3_val16p_NWZ_N_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop3=nop1-zop2", 1, 2, 4444},
	{182, ML_CODE_SUBPS, setCodeOp3S_WZWZ_N, setInputOp3_val16_WZWZ_N_off, verifyResultValueNibble4,
			"SUBPS 0->0 nop3=zop1-zop2", 1, 2, 0},
	{183, ML_CODE_SUBPS, setCodeOp3S_WZWZ_N, setInputOp3_val16p_WZWZ_N_on, verifyResultValueNibble4,
			"SUBPS 0->1 nop3=zop1-zop2", 1, 2, 4444},

	{184, ML_CODE_BADD, setCodeOp2_W_WZ, setInputOp2_BCD4_WWZ_off, verifyResultValueWord,
			"BADD off op1+zop2", 0, 1, 0x5678},
	{185, ML_CODE_BADD, setCodeOp2_W_WZ, setInputOp2_BCD4_WWZ_on, verifyResultValueWord,
			"BADD on op1+zop2", 0, 1, 0x6912},
	{186, ML_CODE_BADD, setCodeOp2_W_WZ, setInputOp2_BCD4_WWZ_over_on, verifyResultValueWord,
			"BADD on op1+zop2 over", 0, 1, 0x15},
	{187, ML_CODE_BADD, setCodeOp2_K0x1234_WZ, setInputOp2_BCD4_KWZ_off, verifyResultValueWord,
			"BADD off K+zop2", 0, 1, 0x5678},
	{188, ML_CODE_BADD, setCodeOp2_K0x1234_WZ, setInputOp2_BCD4_KWZ_on, verifyResultValueWord,
			"BADD on K+zop2", 0, 1, 0x6912},
	{189, ML_CODE_BADD, setCodeOp2_N_WZ, setInputOp2_BCD4_NWZ_off, verifyResultValueWord,
			"BADD off nop1+zop2", 0, 1, 0x5678},
	{190, ML_CODE_BADD, setCodeOp2_N_WZ, setInputOp2_BCD4_NWZ_on, verifyResultValueWord,
			"BADD on nop1+zop2", 0, 1, 0x6912},
	{191, ML_CODE_BADD, setCodeOp2_WZ_W, setInputOp2_BCD4_WZW_off, verifyResultValueWord,
			"BADD off zop1+op2", 1, 1, 0x5678},
	{192, ML_CODE_BADD, setCodeOp2_WZ_W, setInputOp2_BCD4_WZW_on, verifyResultValueWord,
			"BADD on zop1+op2", 1, 1, 0x6912},
	{193, ML_CODE_BADD, setCodeOp2_WZ_N, setInputOp2_BCD4_WZN_off, verifyResultValueNibble4,
			"BADD off zop1+nop2", 1, 1, 0x5678},
	{194, ML_CODE_BADD, setCodeOp2_WZ_N, setInputOp2_BCD4_WZN_on, verifyResultValueNibble4,
			"BADD on zop1+nop2", 1, 1, 0x6912},
	{195, ML_CODE_BADD, setCodeOp2_WZ_WZ, setInputOp2_BCD4_WZWZ_off, verifyResultValueWord,
			"BADD off zop1+zop2", 2, 1, 0x5678},
	{196, ML_CODE_BADD, setCodeOp2_WZ_WZ, setInputOp2_BCD4_WZWZ_on, verifyResultValueWord,
			"BADD on zop1+zop2", 2, 1, 0x6912},

	{197, ML_CODE_BADDP, setCodeOp2_W_WZ, setInputOp2_BCD4_WWZ_off, verifyResultValueWord,
			"BADDP 0->0 op1+zop2", 0, 2, 0x5678},
	{198, ML_CODE_BADDP, setCodeOp2_W_WZ, setInputOp2_BCD4p_WWZ_on, verifyResultValueWord,
			"BADDP 0->1 op1+zop2", 0, 2, 0x6912},
	{199, ML_CODE_BADDP, setCodeOp2_W_WZ, setInputOp2_BCD4p_WWZ_over_on, verifyResultValueWord,
			"BADDP 0->1 op1+zop2 over", 0, 2, 0x15},
	{200, ML_CODE_BADDP, setCodeOp2_K0x1234_WZ, setInputOp2_BCD4_KWZ_off, verifyResultValueWord,
			"BADDP 0->0 K+zop2", 0, 2, 0x5678},
	{201, ML_CODE_BADDP, setCodeOp2_K0x1234_WZ, setInputOp2_BCD4p_KWZ_on, verifyResultValueWord,
			"BADDP 0->1 K+zop2", 0, 2, 0x6912},
	{202, ML_CODE_BADDP, setCodeOp2_N_WZ, setInputOp2_BCD4_NWZ_off, verifyResultValueWord,
			"BADDP 0->0 nop1+zop2", 0, 2, 0x5678},
	{203, ML_CODE_BADDP, setCodeOp2_N_WZ, setInputOp2_BCD4p_NWZ_on, verifyResultValueWord,
			"BADDP 0->1 nop1+zop2", 0, 2, 0x6912},
	{204, ML_CODE_BADDP, setCodeOp2_WZ_W, setInputOp2_BCD4_WZW_off, verifyResultValueWord,
			"BADDP 0->0 zop1+op2", 1, 2, 0x5678},
	{205, ML_CODE_BADDP, setCodeOp2_WZ_W, setInputOp2_BCD4p_WZW_on, verifyResultValueWord,
			"BADDP 0->1 zop1+op2", 1, 2, 0x6912},
	{206, ML_CODE_BADDP, setCodeOp2_WZ_N, setInputOp2_BCD4_WZN_off, verifyResultValueNibble4,
			"BADDP 0->0 zop1+nop2", 1, 2, 0x5678},
	{207, ML_CODE_BADDP, setCodeOp2_WZ_N, setInputOp2_BCD4p_WZN_on, verifyResultValueNibble4,
			"BADDP 0->1 zop1+nop2", 1, 2, 0x6912},
	{208, ML_CODE_BADDP, setCodeOp2_WZ_WZ, setInputOp2_BCD4_WZWZ_off, verifyResultValueWord,
			"BADDP 0->0 zop1+zop2", 2, 2, 0x5678},
	{209, ML_CODE_BADDP, setCodeOp2_WZ_WZ, setInputOp2_BCD4p_WZWZ_on, verifyResultValueWord,
			"BADDP 0->1 zop1+zop2", 2, 2, 0x6912},

	{210, ML_CODE_BSUB, setCodeOp2_W_WZ, setInputOp2_BCD4_WWZ_off, verifyResultValueWord,
			"BSUB off zop2-op1", 0, 1, 0x5678},
	{211, ML_CODE_BSUB, setCodeOp2_W_WZ, setInputOp2_BCD4_WWZ_on, verifyResultValueWord,
			"BSUB on zop2-op1", 0, 1, 0x4444},
	{212, ML_CODE_BSUB, setCodeOp2_W_WZ, setInputOp2_BCD4_WWZ_under_on, verifyResultValueWord,
			"BSUB on zop2-op1 over", 0, 1, 0x9998},
	{213, ML_CODE_BSUB, setCodeOp2_K0x1234_WZ, setInputOp2_BCD4_KWZ_off, verifyResultValueWord,
			"BSUB off zop2-K", 0, 1, 0x5678},
	{214, ML_CODE_BSUB, setCodeOp2_K0x1234_WZ, setInputOp2_BCD4_KWZ_on, verifyResultValueWord,
			"BSUB on zop2-K", 0, 1, 0x4444},
	{215, ML_CODE_BSUB, setCodeOp2_N_WZ, setInputOp2_BCD4_NWZ_off, verifyResultValueWord,
			"BSUB off zop2-nop1", 0, 1, 0x5678},
	{216, ML_CODE_BSUB, setCodeOp2_N_WZ, setInputOp2_BCD4_NWZ_on, verifyResultValueWord,
			"BSUB on zop2-nop1", 0, 1, 0x4444},
	{217, ML_CODE_BSUB, setCodeOp2_WZ_W, setInputOp2_BCD4_WZW_off, verifyResultValueWord,
			"BSUB off op2-zop1", 1, 1, 0x5678},
	{218, ML_CODE_BSUB, setCodeOp2_WZ_W, setInputOp2_BCD4_WZW_on, verifyResultValueWord,
			"BSUB on op2-zop1", 1, 1, 0x4444},
	{219, ML_CODE_BSUB, setCodeOp2_WZ_N, setInputOp2_BCD4_WZN_off, verifyResultValueNibble4,
			"BSUB off nop2-zop1", 1, 1, 0x5678},
	{220, ML_CODE_BSUB, setCodeOp2_WZ_N, setInputOp2_BCD4_WZN_on, verifyResultValueNibble4,
			"BSUB on nop2-zop1", 1, 1, 0x4444},
	{221, ML_CODE_BSUB, setCodeOp2_WZ_WZ, setInputOp2_BCD4_WZWZ_off, verifyResultValueWord,
			"BSUB off zop2-zop1", 2, 1, 0x5678},
	{222, ML_CODE_BSUB, setCodeOp2_WZ_WZ, setInputOp2_BCD4_WZWZ_on, verifyResultValueWord,
			"BSUB on zop2-zop1", 2, 1, 0x4444},

	{223, ML_CODE_BSUBP, setCodeOp2_W_WZ, setInputOp2_BCD4_WWZ_off, verifyResultValueWord,
			"BSUBP 0->0 zop2-op1", 0, 2, 0x5678},
	{224, ML_CODE_BSUBP, setCodeOp2_W_WZ, setInputOp2_BCD4p_WWZ_on, verifyResultValueWord,
			"BSUBP 0->1 zop2-op1", 0, 2, 0x4444},
	{225, ML_CODE_BSUBP, setCodeOp2_W_WZ, setInputOp2_BCD4p_WWZ_under_on, verifyResultValueWord,
			"BSUBP 0->1 zop2-op1 over", 0, 2, 0x9998},
	{226, ML_CODE_BSUBP, setCodeOp2_K0x1234_WZ, setInputOp2_BCD4_KWZ_off, verifyResultValueWord,
			"BSUBP 0->0 zop2-K", 0, 2, 0x5678},
	{227, ML_CODE_BSUBP, setCodeOp2_K0x1234_WZ, setInputOp2_BCD4p_KWZ_on, verifyResultValueWord,
			"BSUBP 0->1 zop2-K", 0, 2, 0x4444},
	{228, ML_CODE_BSUBP, setCodeOp2_N_WZ, setInputOp2_BCD4_NWZ_off, verifyResultValueWord,
			"BSUBP 0->0 zop2-nop1", 0, 2, 0x5678},
	{229, ML_CODE_BSUBP, setCodeOp2_N_WZ, setInputOp2_BCD4p_NWZ_on, verifyResultValueWord,
			"BSUBP 0->1 zop2-nop1", 0, 2, 0x4444},
	{230, ML_CODE_BSUBP, setCodeOp2_WZ_W, setInputOp2_BCD4_WZW_off, verifyResultValueWord,
			"BSUBP 0->0 op2-zop1", 1, 2, 0x5678},
	{231, ML_CODE_BSUBP, setCodeOp2_WZ_W, setInputOp2_BCD4p_WZW_on, verifyResultValueWord,
			"BSUBP 0->1 op2-zop1", 1, 2, 0x4444},
	{232, ML_CODE_BSUBP, setCodeOp2_WZ_N, setInputOp2_BCD4_WZN_off, verifyResultValueNibble4,
			"BSUBP 0->0 nop2-zop1", 1, 2, 0x5678},
	{233, ML_CODE_BSUBP, setCodeOp2_WZ_N, setInputOp2_BCD4p_WZN_on, verifyResultValueNibble4,
			"BSUBP 0->1 nop2-zop1", 1, 2, 0x4444},
	{234, ML_CODE_BSUBP, setCodeOp2_WZ_WZ, setInputOp2_BCD4_WZWZ_off, verifyResultValueWord,
			"BSUBP 0->0 zop2-zop1", 2, 2, 0x5678},
	{235, ML_CODE_BSUBP, setCodeOp2_WZ_WZ, setInputOp2_BCD4p_WZWZ_on, verifyResultValueWord,
			"BSUBP 0->1 zop2-zop1", 2, 2, 0x4444},

	{236, ML_CODE_BADDS, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_off, verifyResultValueWord,
			"BADDS off zop3=op1+op2", 0, 1, 0},
	{237, ML_CODE_BADDS, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_on, verifyResultValueWord,
			"BADDS on zop3=op1+op2", 0, 1, 0x6912},
	{238, ML_CODE_BADDS, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_off, verifyResultValueWord,
			"BADDS off zop3=op1+op2", 0, 1, 0},
	{239, ML_CODE_BADDS, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_on, verifyResultValueWord,
			"BADDS on zop3=op1+op2", 0, 1, 0x6912},
	{240, ML_CODE_BADDS, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_off, verifyResultValueWord,
			"BADDS off zop3=K+op2", 0, 1, 0},
	{241, ML_CODE_BADDS, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_on, verifyResultValueWord,
			"BADDS on zop3=K+op2", 0, 1, 0x6912},
	{242, ML_CODE_BADDS, setCodeOp3S_BKK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"BADDS off zop3=K+K", 0, 1, 0},
	{243, ML_CODE_BADDS, setCodeOp3S_BKK_WZ, setInputOp2_none_on, verifyResultValueWord,
			"BADDS on zop3=K+K", 0, 1, 0x6912},
	{244, ML_CODE_BADDS, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_off, verifyResultValueWord,
			"BADDS off zop3=nop1+op2", 0, 1, 0},
	{245, ML_CODE_BADDS, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_on, verifyResultValueWord,
			"BADDS on zop3=nop1+op2", 0, 1, 0x6912},
	{246, ML_CODE_BADDS, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_off, verifyResultValueWord,
			"BADDS off zop3=op1+nop2", 0, 1, 0},
	{247, ML_CODE_BADDS, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_on, verifyResultValueWord,
			"BADDS on zop3=op1+nop2", 0, 1, 0x6912},
	{248, ML_CODE_BADDS, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueWord,
			"BADDS off zop3=zop1+op2", 2, 1, 0},
	{249, ML_CODE_BADDS, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_on, verifyResultValueWord,
			"BADDS on zop3=zop1+op2", 2, 1, 0x6912},
	{250, ML_CODE_BADDS, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueWord,
			"BADDS off zop3=zop1+K", 2, 1, 0},
	{251, ML_CODE_BADDS, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_on, verifyResultValueWord,
			"BADDS on zop3=zop1+K", 2, 1, 0x6912},
	{252, ML_CODE_BADDS, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_off, verifyResultValueWord,
			"BADDS off zop3=zop1+nop2", 2, 1, 0},
	{253, ML_CODE_BADDS, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_on, verifyResultValueWord,
			"BADDS on zop3=zop1+nop2", 2, 1, 0x6912},
	{254, ML_CODE_BADDS, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_off, verifyResultValueWord,
			"BADDS off zop3=nop1+zop2", 2, 1, 0},
	{255, ML_CODE_BADDS, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_on, verifyResultValueWord,
			"BADDS on zop3=nop1+zop2", 2, 1, 0x6912},
	{256, ML_CODE_BADDS, setCodeOp3S_WZW_N, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueNibble4,
			"BADDS off nop3=zop1+op2", 1, 1, 0},
	{257, ML_CODE_BADDS, setCodeOp3S_WZW_N, setInputOp3_BCD4_WZW_WZ_on, verifyResultValueNibble4,
			"BADDS on nop3=zop1+op2", 1, 1, 0x6912},
	{258, ML_CODE_BADDS, setCodeOp3S_WZBK_N, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueNibble4,
			"BADDS off nop3=zop1+K", 1, 1, 0},
	{259, ML_CODE_BADDS, setCodeOp3S_WZBK_N, setInputOp3_BCD4_WZK_WZ_on, verifyResultValueNibble4,
			"BADDS on nop3=zop1+K", 1, 1, 0x6912},
	{260, ML_CODE_BADDS, setCodeOp3S_WZN_N, setInputOp3_BCD4_WZN_N_off, verifyResultValueNibble4,
			"BADDS off nop3=zop1+nop2", 1, 1, 0},
	{261, ML_CODE_BADDS, setCodeOp3S_WZN_N, setInputOp3_BCD4_WZN_N_on, verifyResultValueNibble4,
			"BADDS on nop3=zop1+nop2", 1, 1, 0x6912},
	{262, ML_CODE_BADDS, setCodeOp3S_NWZ_N, setInputOp3_BCD4_NWZ_N_off, verifyResultValueNibble4,
			"BADDS off nop3=nop1+zop2", 1, 1, 0},
	{263, ML_CODE_BADDS, setCodeOp3S_NWZ_N, setInputOp3_BCD4_NWZ_N_on, verifyResultValueNibble4,
			"BADDS on nop3=nop1+zop2", 1, 1, 0x6912},
	{264, ML_CODE_BADDS, setCodeOp3S_WZWZ_N, setInputOp3_BCD4_WZWZ_N_off, verifyResultValueNibble4,
			"BADDS off nop3=zop1+zop2", 1, 1, 0},
	{265, ML_CODE_BADDS, setCodeOp3S_WZWZ_N, setInputOp3_BCD4_WZWZ_N_on, verifyResultValueNibble4,
			"BADDS on nop3=zop1+zop2", 1, 1, 0x6912},

	{266, ML_CODE_BADDPS, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=op1+op2", 0, 2, 0},
	{267, ML_CODE_BADDPS, setCodeOp3S_WW_WZ, setInputOp3_BCD4p_WW_WZ_on, verifyResultValueWord,
			"BADDPS 0->1 zop3=op1+op2", 0, 2, 0x6912},
	{268, ML_CODE_BADDPS, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=op1+op2", 0, 2, 0},
	{269, ML_CODE_BADDPS, setCodeOp3S_W_WWZ, setInputOp3_BCD4p_W_WWZ_on, verifyResultValueWord,
			"BADDPS 0->1 zop3=op1+op2", 0, 2, 0x6912},
	{270, ML_CODE_BADDPS, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=K+op2", 0, 2, 0},
	{271, ML_CODE_BADDPS, setCodeOp3S_BKW_WZ, setInputOp3_BCD4p_KW_WZ_on, verifyResultValueWord,
			"BADDPS 0->1 zop3=K+op2", 0, 2, 0x6912},
	{272, ML_CODE_BADDPS, setCodeOp3S_BKK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=K+K", 0, 2, 0},
	{273, ML_CODE_BADDPS, setCodeOp3S_BKK_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"BADDPS 0->1 zop3=K+K", 0, 2, 0x6912},
	{274, ML_CODE_BADDPS, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=nop1+op2", 0, 2, 0},
	{275, ML_CODE_BADDPS, setCodeOp3S_NW_WZ, setInputOp3_BCD4p_NW_WZ_on, verifyResultValueWord,
			"BADDPS 0->1 zop3=nop1+op2", 0, 2, 0x6912},
	{276, ML_CODE_BADDPS, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=op1+nop2", 0, 2, 0},
	{277, ML_CODE_BADDPS, setCodeOp3S_WN_WZ, setInputOp3_BCD4p_WN_WZ_on, verifyResultValueWord,
			"BADDPS 0->1 zop3=op1+nop2", 0, 2, 0x6912},
	{278, ML_CODE_BADDPS, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=zop1+op2", 2, 2, 0},
	{279, ML_CODE_BADDPS, setCodeOp3S_WZW_WZ, setInputOp3_BCD4p_WZW_WZ_on, verifyResultValueWord,
			"BADDPS 0->1 zop3=zop1+op2", 2, 2, 0x6912},
	{280, ML_CODE_BADDPS, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=zop1+K", 2, 2, 0},
	{281, ML_CODE_BADDPS, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4p_WZK_WZ_on, verifyResultValueWord,
			"BADDPS 0->1 zop3=zop1+K", 2, 2, 0x6912},
	{282, ML_CODE_BADDPS, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=zop1+nop2", 2, 2, 0},
	{283, ML_CODE_BADDPS, setCodeOp3S_WZN_WZ, setInputOp3_BCD4p_WZN_WZ_on, verifyResultValueWord,
			"BADDPS 0->1 zop3=zop1+nop2", 2, 2, 0x6912},
	{284, ML_CODE_BADDPS, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_off, verifyResultValueWord,
			"BADDPS 0->0 zop3=nop1+zop2", 2, 2, 0},
	{285, ML_CODE_BADDPS, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4p_NWZ_WZ_on, verifyResultValueWord,
			"BADDPS 0->1 zop3=nop1+zop2", 2, 2, 0x6912},
	{286, ML_CODE_BADDPS, setCodeOp3S_WZW_N, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueNibble4,
			"BADDPS 0->0 nop3=zop1+op2", 1, 2, 0},
	{287, ML_CODE_BADDPS, setCodeOp3S_WZW_N, setInputOp3_BCD4p_WZW_WZ_on, verifyResultValueNibble4,
			"BADDPS 0->1 nop3=zop1+op2", 1, 2, 0x6912},
	{288, ML_CODE_BADDPS, setCodeOp3S_WZBK_N, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueNibble4,
			"BADDPS 0->0 nop3=zop1+K", 1, 2, 0},
	{289, ML_CODE_BADDPS, setCodeOp3S_WZBK_N, setInputOp3_BCD4p_WZK_WZ_on, verifyResultValueNibble4,
			"BADDPS 0->1 nop3=zop1+K", 1, 2, 0x6912},
	{290, ML_CODE_BADDPS, setCodeOp3S_WZN_N, setInputOp3_BCD4_WZN_N_off, verifyResultValueNibble4,
			"BADDPS 0->0 nop3=zop1+nop2", 1, 2, 0},
	{291, ML_CODE_BADDPS, setCodeOp3S_WZN_N, setInputOp3_BCD4p_WZN_N_on, verifyResultValueNibble4,
			"BADDPS 0->1 nop3=zop1+nop2", 1, 2, 0x6912},
	{292, ML_CODE_BADDPS, setCodeOp3S_NWZ_N, setInputOp3_BCD4_NWZ_N_off, verifyResultValueNibble4,
			"BADDPS 0->0 nop3=nop1+zop2", 1, 2, 0},
	{293, ML_CODE_BADDPS, setCodeOp3S_NWZ_N, setInputOp3_BCD4p_NWZ_N_on, verifyResultValueNibble4,
			"BADDPS 0->1 nop3=nop1+zop2", 1, 2, 0x6912},
	{294, ML_CODE_BADDPS, setCodeOp3S_WZWZ_N, setInputOp3_BCD4_WZWZ_N_off, verifyResultValueNibble4,
			"BADDPS 0->0 nop3=zop1+zop2", 1, 2, 0},
	{295, ML_CODE_BADDPS, setCodeOp3S_WZWZ_N, setInputOp3_BCD4p_WZWZ_N_on, verifyResultValueNibble4,
			"BADDPS 0->1 nop3=zop1+zop2", 1, 2, 0x6912},

	{296, ML_CODE_BSUBS, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_off, verifyResultValueWord,
			"BSUBS off zop3=op1-op2", 0, 1, 0},
	{297, ML_CODE_BSUBS, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_on, verifyResultValueWord,
			"BSUBS on zop3=op1-op2", 0, 1, 0x4444},
	{298, ML_CODE_BSUBS, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_off, verifyResultValueWord,
			"BSUBS off zop3=op1-op2", 0, 1, 0},
	{299, ML_CODE_BSUBS, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_on, verifyResultValueWord,
			"BSUBS on zop3=op1-op2", 0, 1, 0x4444},
	{300, ML_CODE_BSUBS, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_off, verifyResultValueWord,
			"BSUBS off zop3=K-op2", 0, 1, 0},
	{301, ML_CODE_BSUBS, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_on, verifyResultValueWord,
			"BSUBS on zop3=K-op2", 0, 1, 0x4444},
	{302, ML_CODE_BSUBS, setCodeOp3S_BKK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"BSUBS off zop3=K-K", 0, 1, 0},
	{303, ML_CODE_BSUBS, setCodeOp3S_BKK_WZ, setInputOp2_none_on, verifyResultValueWord,
			"BSUBS on zop3=K-K", 0, 1, 0x4444},
	{304, ML_CODE_BSUBS, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_off, verifyResultValueWord,
			"BSUBS off zop3=nop1-op2", 0, 1, 0},
	{305, ML_CODE_BSUBS, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_on, verifyResultValueWord,
			"BSUBS on zop3=nop1-op2", 0, 1, 0x4444},
	{306, ML_CODE_BSUBS, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_off, verifyResultValueWord,
			"BSUBS off zop3=op1-nop2", 0, 1, 0},
	{307, ML_CODE_BSUBS, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_on, verifyResultValueWord,
			"BSUBS on zop3=op1-nop2", 0, 1, 0x4444},
	{308, ML_CODE_BSUBS, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueWord,
			"BSUBS off zop3=zop1-op2", 2, 1, 0},
	{309, ML_CODE_BSUBS, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_on, verifyResultValueWord,
			"BSUBS on zop3=zop1-op2", 2, 1, 0x4444},
	{310, ML_CODE_BSUBS, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueWord,
			"BSUBS off zop3=zop1-K", 2, 1, 0},
	{311, ML_CODE_BSUBS, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_on, verifyResultValueWord,
			"BSUBS on zop3=zop1-K", 2, 1, 0x4444},
	{312, ML_CODE_BSUBS, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_off, verifyResultValueWord,
			"BSUBS off zop3=zop1-nop2", 2, 1, 0},
	{313, ML_CODE_BSUBS, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_on, verifyResultValueWord,
			"BSUBS on zop3=zop1-nop2", 2, 1, 0x4444},
	{314, ML_CODE_BSUBS, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_off, verifyResultValueWord,
			"BSUBS off zop3=nop1-zop2", 2, 1, 0},
	{315, ML_CODE_BSUBS, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_on, verifyResultValueWord,
			"BSUBS on zop3=nop1-zop2", 2, 1, 0x4444},
	{316, ML_CODE_BSUBS, setCodeOp3S_WZW_N, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueNibble4,
			"BSUBS off nop3=zop1-op2", 1, 1, 0},
	{317, ML_CODE_BSUBS, setCodeOp3S_WZW_N, setInputOp3_BCD4_WZW_WZ_on, verifyResultValueNibble4,
			"BSUBS on nop3=zop1-op2", 1, 1, 0x4444},
	{318, ML_CODE_BSUBS, setCodeOp3S_WZBK_N, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueNibble4,
			"BSUBS off nop3=zop1-K", 1, 1, 0},
	{319, ML_CODE_BSUBS, setCodeOp3S_WZBK_N, setInputOp3_BCD4_WZK_WZ_on, verifyResultValueNibble4,
			"BSUBS on nop3=zop1-K", 1, 1, 0x4444},
	{320, ML_CODE_BSUBS, setCodeOp3S_WZN_N, setInputOp3_BCD4_WZN_N_off, verifyResultValueNibble4,
			"BSUBS off nop3=zop1-nop2", 1, 1, 0},
	{321, ML_CODE_BSUBS, setCodeOp3S_WZN_N, setInputOp3_BCD4_WZN_N_on, verifyResultValueNibble4,
			"BSUBS on nop3=zop1-nop2", 1, 1, 0x4444},
	{322, ML_CODE_BSUBS, setCodeOp3S_NWZ_N, setInputOp3_BCD4_NWZ_N_off, verifyResultValueNibble4,
			"BSUBS off nop3=nop1-zop2", 1, 1, 0},
	{323, ML_CODE_BSUBS, setCodeOp3S_NWZ_N, setInputOp3_BCD4_NWZ_N_on, verifyResultValueNibble4,
			"BSUBS on nop3=nop1-zop2", 1, 1, 0x4444},
	{324, ML_CODE_BSUBS, setCodeOp3S_WZWZ_N, setInputOp3_BCD4_WZWZ_N_off, verifyResultValueNibble4,
			"BSUBS off nop3=zop1-zop2", 1, 1, 0},
	{325, ML_CODE_BSUBS, setCodeOp3S_WZWZ_N, setInputOp3_BCD4_WZWZ_N_on, verifyResultValueNibble4,
			"BSUBS on nop3=zop1-zop2", 1, 1, 0x4444},

	{326, ML_CODE_BSUBPS, setCodeOp3S_WW_WZ, setInputOp3_BCD4_WW_WZ_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=op1-op2", 0, 2, 0},
	{327, ML_CODE_BSUBPS, setCodeOp3S_WW_WZ, setInputOp3_BCD4p_WW_WZ_on, verifyResultValueWord,
			"BSUBPS 0->1 zop3=op1-op2", 0, 2, 0x4444},
	{328, ML_CODE_BSUBPS, setCodeOp3S_W_WWZ, setInputOp3_BCD4_W_WWZ_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=op1-op2", 0, 2, 0},
	{329, ML_CODE_BSUBPS, setCodeOp3S_W_WWZ, setInputOp3_BCD4p_W_WWZ_on, verifyResultValueWord,
			"BSUBPS 0->1 zop3=op1-op2", 0, 2, 0x4444},
	{330, ML_CODE_BSUBPS, setCodeOp3S_BKW_WZ, setInputOp3_BCD4_KW_WZ_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=K-op2", 0, 2, 0},
	{331, ML_CODE_BSUBPS, setCodeOp3S_BKW_WZ, setInputOp3_BCD4p_KW_WZ_on, verifyResultValueWord,
			"BSUBPS 0->1 zop3=K-op2", 0, 2, 0x4444},
	{332, ML_CODE_BSUBPS, setCodeOp3S_BKK_WZ, setInputOp2_none_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=K-K", 0, 2, 0},
	{333, ML_CODE_BSUBPS, setCodeOp3S_BKK_WZ, setInputOp2_none_tr1, verifyResultValueWord,
			"BSUBPS 0->1 zop3=K-K", 0, 2, 0x4444},
	{334, ML_CODE_BSUBPS, setCodeOp3S_NW_WZ, setInputOp3_BCD4_NW_WZ_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=nop1-op2", 0, 2, 0},
	{335, ML_CODE_BSUBPS, setCodeOp3S_NW_WZ, setInputOp3_BCD4p_NW_WZ_on, verifyResultValueWord,
			"BSUBPS 0->1 zop3=nop1-op2", 0, 2, 0x4444},
	{336, ML_CODE_BSUBPS, setCodeOp3S_WN_WZ, setInputOp3_BCD4_WN_WZ_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=op1-nop2", 0, 2, 0},
	{337, ML_CODE_BSUBPS, setCodeOp3S_WN_WZ, setInputOp3_BCD4p_WN_WZ_on, verifyResultValueWord,
			"BSUBPS 0->1 zop3=op1-nop2", 0, 2, 0x4444},
	{338, ML_CODE_BSUBPS, setCodeOp3S_WZW_WZ, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=zop1-op2", 2, 2, 0},
	{339, ML_CODE_BSUBPS, setCodeOp3S_WZW_WZ, setInputOp3_BCD4p_WZW_WZ_on, verifyResultValueWord,
			"BSUBPS 0->1 zop3=zop1-op2", 2, 2, 0x4444},
	{340, ML_CODE_BSUBPS, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=zop1-K", 2, 2, 0},
	{341, ML_CODE_BSUBPS, setCodeOp3S_WZBK_WZ, setInputOp3_BCD4p_WZK_WZ_on, verifyResultValueWord,
			"BSUBPS 0->1 zop3=zop1-K", 2, 2, 0x4444},
	{342, ML_CODE_BSUBPS, setCodeOp3S_WZN_WZ, setInputOp3_BCD4_WZN_WZ_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=zop1-nop2", 2, 2, 0},
	{343, ML_CODE_BSUBPS, setCodeOp3S_WZN_WZ, setInputOp3_BCD4p_WZN_WZ_on, verifyResultValueWord,
			"BSUBPS 0->1 zop3=zop1-nop2", 2, 2, 0x4444},
	{344, ML_CODE_BSUBPS, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4_NWZ_WZ_off, verifyResultValueWord,
			"BSUBPS 0->0 zop3=nop1-zop2", 2, 2, 0},
	{345, ML_CODE_BSUBPS, setCodeOp3S_NWZ_WZ, setInputOp3_BCD4p_NWZ_WZ_on, verifyResultValueWord,
			"BSUBPS 0->1 zop3=nop1-zop2", 2, 2, 0x4444},
	{346, ML_CODE_BSUBPS, setCodeOp3S_WZW_N, setInputOp3_BCD4_WZW_WZ_off, verifyResultValueNibble4,
			"BSUBPS 0->0 nop3=zop1-op2", 1, 2, 0},
	{347, ML_CODE_BSUBPS, setCodeOp3S_WZW_N, setInputOp3_BCD4p_WZW_WZ_on, verifyResultValueNibble4,
			"BSUBPS 0->1 nop3=zop1-op2", 1, 2, 0x4444},
	{348, ML_CODE_BSUBPS, setCodeOp3S_WZBK_N, setInputOp3_BCD4_WZK_WZ_off, verifyResultValueNibble4,
			"BSUBPS 0->0 nop3=zop1-K", 1, 2, 0},
	{349, ML_CODE_BSUBPS, setCodeOp3S_WZBK_N, setInputOp3_BCD4p_WZK_WZ_on, verifyResultValueNibble4,
			"BSUBPS 0->1 nop3=zop1-K", 1, 2, 0x4444},
	{350, ML_CODE_BSUBPS, setCodeOp3S_WZN_N, setInputOp3_BCD4_WZN_N_off, verifyResultValueNibble4,
			"BSUBPS 0->0 nop3=zop1-nop2", 1, 2, 0},
	{351, ML_CODE_BSUBPS, setCodeOp3S_WZN_N, setInputOp3_BCD4p_WZN_N_on, verifyResultValueNibble4,
			"BSUBPS 0->1 nop3=zop1-nop2", 1, 2, 0x4444},
	{352, ML_CODE_BSUBPS, setCodeOp3S_NWZ_N, setInputOp3_BCD4_NWZ_N_off, verifyResultValueNibble4,
			"BSUBPS 0->0 nop3=nop1-zop2", 1, 2, 0},
	{353, ML_CODE_BSUBPS, setCodeOp3S_NWZ_N, setInputOp3_BCD4p_NWZ_N_on, verifyResultValueNibble4,
			"BSUBPS 0->1 nop3=nop1-zop2", 1, 2, 0x4444},
	{354, ML_CODE_BSUBPS, setCodeOp3S_WZWZ_N, setInputOp3_BCD4_WZWZ_N_off, verifyResultValueNibble4,
			"BSUBPS 0->0 nop3=zop1-zop2", 1, 2, 0},
	{355, ML_CODE_BSUBPS, setCodeOp3S_WZWZ_N, setInputOp3_BCD4p_WZWZ_N_on, verifyResultValueNibble4,
			"BSUBPS 0->1 nop3=zop1-zop2", 1, 2, 0x4444},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0, 0 }
};


int total_basic_compute_word_idx_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_word_idx_test_number; i++)
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

int setCodeOp1_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, out_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(out_reg, out_pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_K0x1234_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x1234); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos + idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(in_reg, 160);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_W_WWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos + idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos); addMLOperand(out_reg, 160);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_KW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos + idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 5678); addMLOperand(in_reg, in_pos);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_KK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 5678); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_BKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos + idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x5678); addMLOperand(in_reg, in_pos);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_BKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_K, 0x5678); addMLOperand(OPERAND_ML_CODE_K, 0x1234);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_NW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperand(out_reg, 160);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(isRangeOver(out_reg, in_pos, 0)) return 0;
	if(in_pos == pos+idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(out_reg, in_pos); addMLOperandNibble(4, in_reg, 160);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(in_reg, 160);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZBK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_K, 0x1234);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(isRangeOver(out_reg, in_pos, idx_val)) return 0;
	if(in_pos == pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(out_reg, in_pos, idx_pos); addMLOperandNibble(4, in_reg, 160);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_NWZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(isRangeOver(out_reg, 160, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, in_reg, in_pos); addMLOperandZIndex(out_reg, 160, idx_pos);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZW_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(in_reg, 160);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZK_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_K, 1234);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZBK_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_K, 0x1234);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


int setCodeOp3S_WZN_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandNibble(4, out_reg, 160);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_NWZ_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, 160, idx_val)) return 0;
	if(isRangeOver(out_reg, in_pos, 0)) return 0;
	if(isRangeOver(out_reg, pos, 0)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(4, out_reg, in_pos); addMLOperandZIndex(in_reg, 160, idx_pos);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZWZ_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(in_reg, 160, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandZIndex(in_reg, 160, idx_pos);
		addMLOperandNibble(4, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputOp2_val16_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=32767, out_val=2;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=32767, out_val=2;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=2, out_val=-32768;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=2, out_val=-32768;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_KWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_NWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WZW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WZN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16p_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val16_WZWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val16p_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val16_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val16_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val16p_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val16_WZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=32767;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val16p_WZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=32767;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val16_WZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=-32768;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val16p_WZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=1234, out_val=-32768;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16p_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_W_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16p_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_KW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16p_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_NW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16p_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val16_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val16p_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val16_WZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16p_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WZK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_val16p_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WZN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val16_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val16p_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val16_NWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16p_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WZWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16p_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_WZN_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val16_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val16p_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val16_NWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val16p_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=5678, in2_val=1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x6432, out_val=0x3583;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_WWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x6432, out_val=0x3583;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x3, out_val=0x1;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_WWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x3, out_val=0x1;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_KWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_KWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_NWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_NWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_WZW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_WZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_WZN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD4_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD4p_WZN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD4_WZWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD4p_WZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x1234, out_val=0x5678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstruction(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4p_WW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_W_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4p_W_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_KW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4p_KW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_NW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4p_NW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD4_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD4p_WN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstruction(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4p_WZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4p_WZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD4p_WZN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD4_NWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4p_NWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4p_WZWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZN_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD4_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD4p_WZN_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstruction(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD4_NWZ_N_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD4p_NWZ_N_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x5678, in2_val=0x1234;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<16; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstruction(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8176,8176,8176,8176,2032,8176,0,12287,8191}}; //16bit

	return pos[inx_pos][reg];
}

static 	FILE *flog;
void test_basic_arithmetic_word_index(int tno, uint16 dummy)
{
	int i, inx, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_D;
	uint16 in_pos, out_pos, res_word;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_W; out++)
		{
			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					in_pos = getPos(in, i);
					for(inx=0; inx<15; inx++) // testidx
					{
						PLC_DEVICE_Init();

						rc2 = testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos, \
								testidx[inx].pos, testidx[inx].val);
						if(rc2 == 0) continue;

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
							if(testCase[tno].z_type==1) //op1 is index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
								if(rc == 1)
								{
									test_getWord(&res_word, out, out_pos);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d Z[%d]=%d\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
										reg[in], in_pos, reg[out], out_pos, res_word, testCase[tno].expected, testidx[inx].pos, testidx[inx].val);
								}
							}
							else // op2 is index or both are index
							{
								rc = testCase[tno].verifyResult_fn(tno, out, out_pos+testidx[inx].val, testCase[tno].expected);
								if(rc == 1)
								{
									test_getWord(&res_word, out, out_pos+testidx[inx].val);
									fprintf(flog, "test case %d error cmd=%s in_%s[%d] out_%s[%d]=%d exp=%d Z[%d]=%d\n", \
										tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName,
										reg[in], in_pos, reg[out], out_pos, res_word, testCase[tno].expected, testidx[inx].pos, testidx[inx].val);
								}
							}
						}
					}
				}
			}
		}
	}
}

void testBasicArithmeticWordIndexCommand(void)
{
	int i, index=80;
	int start, end;
	char log[] = "err_arith_word_idx.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic word index LOG file open error !\n");
		exit(1);
	}
#if 1
	//for(index=32;index<56;index++)
	test_basic_arithmetic_word_index(90, 0);
	//for(i=0; i<230; i++)
	//	printf("testcase %d cmd=%s \n", i, PLC_OPERATOR_DICTIONARY_findOperator(testCase[i].ml_code)->strName);
#else
	total_basic_compute_word_idx_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_ADD);
	end = getTestCaseNumberEnd(ML_CODE_BSUBPS); //ML_CODE_BSUBPS

	DBG_LOGPRINT("testBasicArithmeticWordIndexCommand: %d to %d total %d\n", start, end, total_basic_compute_word_idx_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_word_index(index, 0);
	}
#endif
	fclose(flog);
}

#endif
