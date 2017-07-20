/*
 * test_basic_arithmetic_dword_index.c
 *
 *  Created on: Sep 1, 2015
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

extern int setCodeOp1_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_W_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_W(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp2_WZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

extern int setCodeOp3S_WW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_W_WWZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_BKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_BKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZBK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZBK_N(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZW_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
extern int setCodeOp3S_WZWZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

extern void setInputOp2_none_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
extern void setInputOp2_none_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);


extern int verifyResultValueDWord(int tcase, uint8 dest_reg, uint16 pos, int expected);
extern int verifyResultValueNibble8(int tcase, uint8 dest_reg, uint16 pos, int expected);


int setCodeOp2_DK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp2_DN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DNW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DWN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DNWZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DNWZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);

int setCodeOp2_BDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DBKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_DBKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDBK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);
int setCodeOp3S_WZDBK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val);


void setInputOp2_val32_DWWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DWWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DWWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DWWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DWWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DWWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DWWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DKWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DKWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DKWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DNWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DNWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DNWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DWZW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DWZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DWZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_WZDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_WZDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_WZDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DWZWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32_DWZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_val32p_DWZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val32_DWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val32p_DWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val32_DWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp1_val32p_DWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp3_val32_DWW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DW_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DKW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_DKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DNW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DWN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DWN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_DWN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DWZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DWZK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DWZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_DWZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_WZDN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DNWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_WZN_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_WZN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_WZN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DNWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_WZWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32_WZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_val32p_WZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp2_BCD8_DWWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_DWWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8p_DWWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_DWWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8p_DWWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_DWWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8p_DWWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_BDKWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_BDKWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8p_BDKWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_DNWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_DNWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8p_DNWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_DWZW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_DWZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8p_DWZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_WZDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_WZDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8p_WZDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_DWZWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8_DWZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp2_BCD8p_DWZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

void setInputOp3_BCD8_DWW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DW_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DBKW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DBKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DBKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WDN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_WDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDBK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDBK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_WZDBK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDN_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_WZDN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_WZDN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWZWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8_DWZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);
void setInputOp3_BCD8p_DWZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val);

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
	int z_type; // 0 : out is index, 1: op1 is index
	int run_step;
	int expected;

} testFn_st;

static testFn_st testCase[]={
	{0, ML_CODE_DADD, setCodeOp2_W_WZ, setInputOp2_val32_DWWZ_off, verifyResultValueDWord,
			"DADD off op1+zop2", 0, 1, 123456},
	{1, ML_CODE_DADD, setCodeOp2_W_WZ, setInputOp2_val32_DWWZ_on, verifyResultValueDWord,
			"DADD on op1+zop2", 0, 1, 691346},
	{2, ML_CODE_DADD, setCodeOp2_W_WZ, setInputOp2_val32_DWWZ_over_on, verifyResultValueDWord,
			"DADD on op1+zop2 over", 0, 1, -2147483647},
	{3, ML_CODE_DADD, setCodeOp2_DK_WZ, setInputOp2_val32_DKWZ_off, verifyResultValueDWord,
			"DADD off K+zop2", 0, 1, 123456},
	{4, ML_CODE_DADD, setCodeOp2_DK_WZ, setInputOp2_val32_DKWZ_on, verifyResultValueDWord,
			"DADD on K+zop2", 0, 1, 691346},
	{5, ML_CODE_DADD, setCodeOp2_DN_WZ, setInputOp2_val32_DNWZ_off, verifyResultValueDWord,
			"DADD off nop1+zop2", 0, 1, 123456},
	{6, ML_CODE_DADD, setCodeOp2_DN_WZ, setInputOp2_val32_DNWZ_on, verifyResultValueDWord,
			"DADD on nop1+zop2", 0, 1, 691346},
	{7, ML_CODE_DADD, setCodeOp2_WZ_W, setInputOp2_val32_DWZW_off, verifyResultValueDWord,
			"DADD off zop1+op2", 1, 1, 123456},
	{8, ML_CODE_DADD, setCodeOp2_WZ_W, setInputOp2_val32_DWZW_on, verifyResultValueDWord,
			"DADD on zop1+op2", 1, 1, 691346},
	{9, ML_CODE_DADD, setCodeOp2_WZ_DN, setInputOp2_val32_WZDN_off, verifyResultValueNibble8,
			"DADD off zop1+nop2", 1, 1, 123456},
	{10, ML_CODE_DADD, setCodeOp2_WZ_DN, setInputOp2_val32_WZDN_on, verifyResultValueNibble8,
			"DADD on zop1+nop2", 1, 1, 691346},
	{11, ML_CODE_DADD, setCodeOp2_WZ_WZ, setInputOp2_val32_DWZWZ_off, verifyResultValueDWord,
			"DADD off zop1+zop2", 2, 1, 123456},
	{12, ML_CODE_DADD, setCodeOp2_WZ_WZ, setInputOp2_val32_DWZWZ_on, verifyResultValueDWord,
			"DADD on zop1+zop2", 2, 1, 691346},

	{13, ML_CODE_DADDP, setCodeOp2_W_WZ, setInputOp2_val32_DWWZ_off, verifyResultValueDWord,
			"DADDP 0->0 op1+zop2", 0, 2, 123456},
	{14, ML_CODE_DADDP, setCodeOp2_W_WZ, setInputOp2_val32p_DWWZ_on, verifyResultValueDWord,
			"DADDP 0->1 op1+zop2", 0, 2, 691346},
	{15, ML_CODE_DADDP, setCodeOp2_W_WZ, setInputOp2_val32p_DWWZ_over_on, verifyResultValueDWord,
			"DADDP 0->1 op1+zop2 over", 0, 2, -2147483647},
	{16, ML_CODE_DADDP, setCodeOp2_DK_WZ, setInputOp2_val32_DKWZ_off, verifyResultValueDWord,
			"DADDP 0->0 K+zop2", 0, 2, 123456},
	{17, ML_CODE_DADDP, setCodeOp2_DK_WZ, setInputOp2_val32p_DKWZ_on, verifyResultValueDWord,
			"DADDP 0->1 K+zop2", 0, 2, 691346},
	{18, ML_CODE_DADDP, setCodeOp2_DN_WZ, setInputOp2_val32_DNWZ_off, verifyResultValueDWord,
			"DADDP 0->0 nop1+zop2", 0, 2, 123456},
	{19, ML_CODE_DADDP, setCodeOp2_DN_WZ, setInputOp2_val32p_DNWZ_on, verifyResultValueDWord,
			"DADDP 0->1 nop1+zop2", 0, 2, 691346},
	{20, ML_CODE_DADDP, setCodeOp2_WZ_W, setInputOp2_val32_DWZW_off, verifyResultValueDWord,
			"DADDP 0->0 zop1+op2", 1, 2, 123456},
	{21, ML_CODE_DADDP, setCodeOp2_WZ_W, setInputOp2_val32p_DWZW_on, verifyResultValueDWord,
			"DADDP 0->1 zop1+op2", 1, 2, 691346},
	{22, ML_CODE_DADDP, setCodeOp2_WZ_DN, setInputOp2_val32_WZDN_off, verifyResultValueNibble8,
			"DADDP 0->0 zop1+nop2", 1, 2, 123456},
	{23, ML_CODE_DADDP, setCodeOp2_WZ_DN, setInputOp2_val32p_WZDN_on, verifyResultValueNibble8,
			"DADDP 0->1 zop1+nop2", 1, 2, 691346},
	{24, ML_CODE_DADDP, setCodeOp2_WZ_WZ, setInputOp2_val32_DWZWZ_off, verifyResultValueDWord,
			"DADDP 0->0 zop1+zop2", 2, 2, 123456},
	{25, ML_CODE_DADDP, setCodeOp2_WZ_WZ, setInputOp2_val32p_DWZWZ_on, verifyResultValueDWord,
			"DADDP 0->1 zop1+zop2", 2, 2, 691346},

	{26, ML_CODE_DSUB, setCodeOp2_W_WZ, setInputOp2_val32_DWWZ_off, verifyResultValueDWord,
			"DSUB off zop2-op1", 0, 1, 123456},
	{27, ML_CODE_DSUB, setCodeOp2_W_WZ, setInputOp2_val32_DWWZ_on, verifyResultValueDWord,
			"DSUB on zop2-op1", 0, 1, -444434},
	{28, ML_CODE_DSUB, setCodeOp2_W_WZ, setInputOp2_val32_DWWZ_under_on, verifyResultValueDWord,
			"DSUB on zop2-op1 over", 0, 1, -2147483647},
	{29, ML_CODE_DSUB, setCodeOp2_DK_WZ, setInputOp2_val32_DKWZ_off, verifyResultValueDWord,
			"DSUB off zop2-K", 0, 1, 123456},
	{30, ML_CODE_DSUB, setCodeOp2_DK_WZ, setInputOp2_val32_DKWZ_on, verifyResultValueDWord,
			"DSUB on zop2-K", 0, 1, -444434},
	{31, ML_CODE_DSUB, setCodeOp2_DN_WZ, setInputOp2_val32_DNWZ_off, verifyResultValueDWord,
			"DSUB off zop2-nop1", 0, 1, 123456},
	{32, ML_CODE_DSUB, setCodeOp2_DN_WZ, setInputOp2_val32_DNWZ_on, verifyResultValueDWord,
			"DSUB on zop2-nop1", 0, 1, -444434},
	{33, ML_CODE_DSUB, setCodeOp2_WZ_W, setInputOp2_val32_DWZW_off, verifyResultValueDWord,
			"DSUB off op2-zop1", 1, 1, 123456},
	{34, ML_CODE_DSUB, setCodeOp2_WZ_W, setInputOp2_val32_DWZW_on, verifyResultValueDWord,
			"DSUB on op2-zop1", 1, 1, -444434},
	{35, ML_CODE_DSUB, setCodeOp2_WZ_DN, setInputOp2_val32_WZDN_off, verifyResultValueNibble8,
			"DSUB off nop2-zop1", 1, 1, 123456},
	{36, ML_CODE_DSUB, setCodeOp2_WZ_DN, setInputOp2_val32_WZDN_on, verifyResultValueNibble8,
			"DSUB on nop2-zop1", 1, 1, -444434},
	{37, ML_CODE_DSUB, setCodeOp2_WZ_WZ, setInputOp2_val32_DWZWZ_off, verifyResultValueDWord,
			"DSUB off zop2-zop1", 2, 1, 123456},
	{38, ML_CODE_DSUB, setCodeOp2_WZ_WZ, setInputOp2_val32_DWZWZ_on, verifyResultValueDWord,
			"DSUB on zop2-zop1", 2, 1, -444434},

	{39, ML_CODE_DSUBP, setCodeOp2_W_WZ, setInputOp2_val32_DWWZ_off, verifyResultValueDWord,
			"DSUBP 0->0 zop2-op1", 0, 2, 123456},
	{40, ML_CODE_DSUBP, setCodeOp2_W_WZ, setInputOp2_val32p_DWWZ_on, verifyResultValueDWord,
			"DSUBP 0->1 zop2-op1", 0, 2, -444434},
	{41, ML_CODE_DSUBP, setCodeOp2_W_WZ, setInputOp2_val32p_DWWZ_under_on, verifyResultValueDWord,
			"DSUBP 0->1 zop2-op1 over", 0, 2, -2147483647},
	{42, ML_CODE_DSUBP, setCodeOp2_DK_WZ, setInputOp2_val32_DKWZ_off, verifyResultValueDWord,
			"DSUBP 0->0 zop2-K", 0, 2, 123456},
	{43, ML_CODE_DSUBP, setCodeOp2_DK_WZ, setInputOp2_val32p_DKWZ_on, verifyResultValueDWord,
			"DSUBP 0->1 zop2-K", 0, 2, -444434},
	{44, ML_CODE_DSUBP, setCodeOp2_DN_WZ, setInputOp2_val32_DNWZ_off, verifyResultValueDWord,
			"DSUBP 0->0 zop2-nop1", 0, 2, 123456},
	{45, ML_CODE_DSUBP, setCodeOp2_DN_WZ, setInputOp2_val32p_DNWZ_on, verifyResultValueDWord,
			"DSUBP 0->1 zop2-nop1", 0, 2, -444434},
	{46, ML_CODE_DSUBP, setCodeOp2_WZ_W, setInputOp2_val32_DWZW_off, verifyResultValueDWord,
			"DSUBP 0->0 op2-zop1", 1, 2, 123456},
	{47, ML_CODE_DSUBP, setCodeOp2_WZ_W, setInputOp2_val32p_DWZW_on, verifyResultValueDWord,
			"DSUBP 0->1 op2-zop1", 1, 2, -444434},
	{48, ML_CODE_DSUBP, setCodeOp2_WZ_DN, setInputOp2_val32_WZDN_off, verifyResultValueNibble8,
			"DSUBP 0->0 nop2-zop1", 1, 2, 123456},
	{49, ML_CODE_DSUBP, setCodeOp2_WZ_DN, setInputOp2_val32p_WZDN_on, verifyResultValueNibble8,
			"DSUBP 0->1 nop2-zop1", 1, 2, -444434},
	{50, ML_CODE_DSUBP, setCodeOp2_WZ_WZ, setInputOp2_val32_DWZWZ_off, verifyResultValueDWord,
			"DSUBP 0->0 zop2-zop1", 2, 2, 123456},
	{51, ML_CODE_DSUBP, setCodeOp2_WZ_WZ, setInputOp2_val32p_DWZWZ_on, verifyResultValueDWord,
			"DSUBP 0->1 zop2-zop1", 2, 2, -444434},

	{52, ML_CODE_DINC, setCodeOp1_WZ, setInputOp2_val32_DKWZ_off, verifyResultValueDWord,
			"DINC off", 0, 1, 123456},
	{53, ML_CODE_DINC, setCodeOp1_WZ, setInputOp2_val32_DKWZ_on, verifyResultValueDWord,
			"DINC on", 0, 1, 123457},
	{54, ML_CODE_DINC, setCodeOp1_WZ, setInputOp1_val32_DWZ_over_on, verifyResultValueDWord,
			"DINC on over", 0, 1, -2147483648},

	{55, ML_CODE_DINCP, setCodeOp1_WZ, setInputOp2_val32_DKWZ_off, verifyResultValueDWord,
			"DINCP 0->0", 0, 2, 123456},
	{56, ML_CODE_DINCP, setCodeOp1_WZ, setInputOp2_val32p_DKWZ_on, verifyResultValueDWord,
			"DINCP 0->1", 0, 2, 123457},
	{57, ML_CODE_DINCP, setCodeOp1_WZ, setInputOp1_val32p_DWZ_over_on, verifyResultValueDWord,
			"DINCP 0->1 over", 0, 2, -2147483648},

	{58, ML_CODE_DDEC, setCodeOp1_WZ, setInputOp2_val32_DKWZ_off, verifyResultValueDWord,
			"DDEC off", 0, 1, 123456},
	{59, ML_CODE_DDEC, setCodeOp1_WZ, setInputOp2_val32_DKWZ_on, verifyResultValueDWord,
			"DDEC on", 0, 1, 123455},
	{60, ML_CODE_DDEC, setCodeOp1_WZ, setInputOp1_val32_DWZ_under_on, verifyResultValueDWord,
			"DDEC on over", 0, 1, 2147483647},

	{61, ML_CODE_DDECP, setCodeOp1_WZ, setInputOp2_val32_DKWZ_off, verifyResultValueDWord,
			"DDECP 0->0", 0, 2, 123456},
	{62, ML_CODE_DDECP, setCodeOp1_WZ, setInputOp2_val32p_DKWZ_on, verifyResultValueDWord,
			"DDECP 0->1", 0, 2, 123455},
	{63, ML_CODE_DDECP, setCodeOp1_WZ, setInputOp1_val32p_DWZ_under_on, verifyResultValueDWord,
			"DDECP 0->1 under", 0, 2, 2147483647},

	{64, ML_CODE_DADDS, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_off, verifyResultValueDWord,
			"DADDS off zop3=op1+op2", 0, 1, 0},
	{65, ML_CODE_DADDS, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_on, verifyResultValueDWord,
			"DADDS on zop3=op1+op2", 0, 1, 691346},
	{66, ML_CODE_DADDS, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_off, verifyResultValueDWord,
			"DADDS off zop3=op1+op2", 0, 1, 0},
	{67, ML_CODE_DADDS, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_on, verifyResultValueDWord,
			"DADDS on zop3=op1+op2", 0, 1, 691346},
	{68, ML_CODE_DADDS, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_off, verifyResultValueDWord,
			"DADDS off zop3=K+op2", 0, 1, 0},
	{69, ML_CODE_DADDS, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_on, verifyResultValueDWord,
			"DADDS on zop3=K+op2", 0, 1, 691346},
	{70, ML_CODE_DADDS, setCodeOp3S_DKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DADDS off zop3=K+K", 0, 1, 0},
	{71, ML_CODE_DADDS, setCodeOp3S_DKK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"DADDS on zop3=K+K", 0, 1, 691346},
	{72, ML_CODE_DADDS, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_off, verifyResultValueDWord,
			"DADDS off zop3=nop1+op2", 0, 1, 0},
	{73, ML_CODE_DADDS, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_on, verifyResultValueDWord,
			"DADDS on zop3=nop1+op2", 0, 1, 691346},
	{74, ML_CODE_DADDS, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_off, verifyResultValueDWord,
			"DADDS off zop3=op1+nop2", 0, 1, 0},
	{75, ML_CODE_DADDS, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_on, verifyResultValueDWord,
			"DADDS on zop3=op1+nop2", 0, 1, 691346},
	{76, ML_CODE_DADDS, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_off, verifyResultValueDWord,
			"DADDS off zop3=zop1+op2", 2, 1, 0},
	{77, ML_CODE_DADDS, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_on, verifyResultValueDWord,
			"DADDS on zop3=zop1+op2", 2, 1, 691346},
	{78, ML_CODE_DADDS, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_off, verifyResultValueDWord,
			"DADDS off zop3=zop1+K", 2, 1, 0},
	{79, ML_CODE_DADDS, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_on, verifyResultValueDWord,
			"DADDS on zop3=zop1+K", 2, 1, 691346},
	{80, ML_CODE_DADDS, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_off, verifyResultValueDWord,
			"DADDS off zop3=zop1+nop2", 2, 1, 0},
	{81, ML_CODE_DADDS, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_on, verifyResultValueDWord,
			"DADDS on zop3=zop1+nop2", 2, 1, 691346},
	{82, ML_CODE_DADDS, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_off, verifyResultValueDWord,
			"DADDS off zop3=nop1+zop2", 2, 1, 0},
	{83, ML_CODE_DADDS, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_on, verifyResultValueDWord,
			"DADDS on zop3=nop1+zop2", 2, 1, 691346},
	{84, ML_CODE_DADDS, setCodeOp3S_WZW_DN, setInputOp3_val32_DWZW_WZ_off, verifyResultValueNibble8,
			"DADDS off nop3=zop1+op2", 1, 1, 0},
	{85, ML_CODE_DADDS, setCodeOp3S_WZW_DN, setInputOp3_val32_DWZW_WZ_on, verifyResultValueNibble8,
			"DADDS on nop3=zop1+op2", 1, 1, 691346},
	{86, ML_CODE_DADDS, setCodeOp3S_WZDK_DN, setInputOp3_val32_DWZK_WZ_off, verifyResultValueNibble8,
			"DADDS off nop3=zop1+K", 1, 1, 0},
	{87, ML_CODE_DADDS, setCodeOp3S_WZDK_DN, setInputOp3_val32_DWZK_WZ_on, verifyResultValueNibble8,
			"DADDS on nop3=zop1+K", 1, 1, 691346},
	{88, ML_CODE_DADDS, setCodeOp3S_WZDN_DN, setInputOp3_val32_WZN_DN_off, verifyResultValueNibble8,
			"DADDS off nop3=zop1+nop2", 1, 1, 0},
	{89, ML_CODE_DADDS, setCodeOp3S_WZDN_DN, setInputOp3_val32_WZN_DN_on, verifyResultValueNibble8,
			"DADDS on nop3=zop1+nop2", 1, 1, 691346},
	{90, ML_CODE_DADDS, setCodeOp3S_DNWZ_DN, setInputOp3_val32_DNWZ_DN_off, verifyResultValueNibble8,
			"DADDS off nop3=nop1+zop2", 1, 1, 0},
	{91, ML_CODE_DADDS, setCodeOp3S_DNWZ_DN, setInputOp3_val32_DNWZ_DN_on, verifyResultValueNibble8,
			"DADDS on nop3=nop1+zop2", 1, 1, 691346},
	{92, ML_CODE_DADDS, setCodeOp3S_WZWZ_DN, setInputOp3_val32_WZWZ_DN_off, verifyResultValueNibble8,
			"DADDS off nop3=zop1+zop2", 1, 1, 0},
	{93, ML_CODE_DADDS, setCodeOp3S_WZWZ_DN, setInputOp3_val32_WZWZ_DN_on, verifyResultValueNibble8,
			"DADDS on nop3=zop1+zop2", 1, 1, 691346},

	{94, ML_CODE_DADDPS, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=op1+op2", 0, 2, 0},
	{95, ML_CODE_DADDPS, setCodeOp3S_WW_WZ, setInputOp3_val32p_DWW_WZ_on, verifyResultValueDWord,
			"DADDPS 0->1 zop3=op1+op2", 0, 2, 691346},
	{96, ML_CODE_DADDPS, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=op1+op2", 0, 2, 0},
	{97, ML_CODE_DADDPS, setCodeOp3S_W_WWZ, setInputOp3_val32p_DW_WWZ_on, verifyResultValueDWord,
			"DADDPS 0->1 zop3=op1+op2", 0, 2, 691346},
	{98, ML_CODE_DADDPS, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=K+op2", 0, 2, 0},
	{99, ML_CODE_DADDPS, setCodeOp3S_DKW_WZ, setInputOp3_val32p_DKW_WZ_on, verifyResultValueDWord,
			"DADDPS 0->1 zop3=K+op2", 0, 2, 691346},
	{100, ML_CODE_DADDPS, setCodeOp3S_DKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=K+K", 0, 2, 0},
	{101, ML_CODE_DADDPS, setCodeOp3S_DKK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"DADDPS 0->1 zop3=K+K", 0, 2, 691346},
	{102, ML_CODE_DADDPS, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=nop1+op2", 0, 2, 0},
	{103, ML_CODE_DADDPS, setCodeOp3S_DNW_WZ, setInputOp3_val32p_DNW_WZ_on, verifyResultValueDWord,
			"DADDPS 0->1 zop3=nop1+op2", 0, 2, 691346},
	{104, ML_CODE_DADDPS, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=op1+nop2", 0, 2, 0},
	{105, ML_CODE_DADDPS, setCodeOp3S_DWN_WZ, setInputOp3_val32p_DWN_WZ_on, verifyResultValueDWord,
			"DADDPS 0->1 zop3=op1+nop2", 0, 2, 691346},
	{106, ML_CODE_DADDPS, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=zop1+op2", 2, 2, 0},
	{107, ML_CODE_DADDPS, setCodeOp3S_WZW_WZ, setInputOp3_val32p_DWZW_WZ_on, verifyResultValueDWord,
			"DADDPS 0->1 zop3=zop1+op2", 2, 2, 691346},
	{108, ML_CODE_DADDPS, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=zop1+K", 2, 2, 0},
	{109, ML_CODE_DADDPS, setCodeOp3S_WZDK_WZ, setInputOp3_val32p_DWZK_WZ_on, verifyResultValueDWord,
			"DADDPS 0->1 zop3=zop1+K", 2, 2, 691346},
	{110, ML_CODE_DADDPS, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=zop1+nop2", 2, 2, 0},
	{111, ML_CODE_DADDPS, setCodeOp3S_WZDN_WZ, setInputOp3_val32p_WZDN_WZ_on, verifyResultValueDWord,
			"DADDPS 0->1 zop3=zop1+nop2", 2, 2, 691346},
	{112, ML_CODE_DADDPS, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_off, verifyResultValueDWord,
			"DADDPS 0->0 zop3=nop1+zop2", 2, 2, 0},
	{113, ML_CODE_DADDPS, setCodeOp3S_DNWZ_WZ, setInputOp3_val32p_DNWZ_WZ_on, verifyResultValueDWord,
			"DADDPS 0->1 zop3=nop1+zop2", 2, 2, 691346},
	{114, ML_CODE_DADDPS, setCodeOp3S_WZW_DN, setInputOp3_val32_DWZW_WZ_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=zop1+op2", 1, 2, 0},
	{115, ML_CODE_DADDPS, setCodeOp3S_WZW_DN, setInputOp3_val32p_DWZW_WZ_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=zop1+op2", 1, 2, 691346},
	{116, ML_CODE_DADDPS, setCodeOp3S_WZDK_DN, setInputOp3_val32_DWZK_WZ_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=zop1+K", 1, 2, 0},
	{117, ML_CODE_DADDPS, setCodeOp3S_WZDK_DN, setInputOp3_val32p_DWZK_WZ_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=zop1+K", 1, 2, 691346},
	{118, ML_CODE_DADDPS, setCodeOp3S_WZDN_DN, setInputOp3_val32_WZN_DN_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=zop1+nop2", 1, 2, 0},
	{119, ML_CODE_DADDPS, setCodeOp3S_WZDN_DN, setInputOp3_val32p_WZN_DN_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=zop1+nop2", 1, 2, 691346},
	{120, ML_CODE_DADDPS, setCodeOp3S_DNWZ_DN, setInputOp3_val32_DNWZ_DN_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=nop1+zop2", 1, 2, 0},
	{121, ML_CODE_DADDPS, setCodeOp3S_DNWZ_DN, setInputOp3_val32p_DNWZ_DN_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=nop1+zop2", 1, 2, 691346},
	{122, ML_CODE_DADDPS, setCodeOp3S_WZWZ_DN, setInputOp3_val32_WZWZ_DN_off, verifyResultValueNibble8,
			"DADDPS 0->0 nop3=zop1+zop2", 1, 2, 0},
	{123, ML_CODE_DADDPS, setCodeOp3S_WZWZ_DN, setInputOp3_val32p_WZWZ_DN_on, verifyResultValueNibble8,
			"DADDPS 0->1 nop3=zop1+zop2", 1, 2, 691346},

	{124, ML_CODE_DSUBS, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_off, verifyResultValueDWord,
			"DSUBS off zop3=op1-op2", 0, 1, 0},
	{125, ML_CODE_DSUBS, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_on, verifyResultValueDWord,
			"DSUBS on zop3=op1-op2", 0, 1, 444434},
	{126, ML_CODE_DSUBS, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_off, verifyResultValueDWord,
			"DSUBS off zop3=op1-op2", 0, 1, 0},
	{127, ML_CODE_DSUBS, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_on, verifyResultValueDWord,
			"DSUBS on zop3=op1-op2", 0, 1, 444434},
	{128, ML_CODE_DSUBS, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_off, verifyResultValueDWord,
			"DSUBS off zop3=K-op2", 0, 1, 0},
	{129, ML_CODE_DSUBS, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_on, verifyResultValueDWord,
			"DSUBS on zop3=K-op2", 0, 1, 444434},
	{130, ML_CODE_DSUBS, setCodeOp3S_DKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DSUBS off zop3=K-K", 0, 1, 0},
	{131, ML_CODE_DSUBS, setCodeOp3S_DKK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"DSUBS on zop3=K-K", 0, 1, 444434},
	{132, ML_CODE_DSUBS, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_off, verifyResultValueDWord,
			"DSUBS off zop3=nop1-op2", 0, 1, 0},
	{133, ML_CODE_DSUBS, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_on, verifyResultValueDWord,
			"DSUBS on zop3=nop1-op2", 0, 1, 444434},
	{134, ML_CODE_DSUBS, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_off, verifyResultValueDWord,
			"DSUBS off zop3=op1-nop2", 0, 1, 0},
	{135, ML_CODE_DSUBS, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_on, verifyResultValueDWord,
			"DSUBS on zop3=op1-nop2", 0, 1, 444434},
	{136, ML_CODE_DSUBS, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_off, verifyResultValueDWord,
			"DSUBS off zop3=zop1-op2", 2, 1, 0},
	{137, ML_CODE_DSUBS, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_on, verifyResultValueDWord,
			"DSUBS on zop3=zop1-op2", 2, 1, 444434},
	{138, ML_CODE_DSUBS, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_off, verifyResultValueDWord,
			"DSUBS off zop3=zop1-K", 2, 1, 0},
	{139, ML_CODE_DSUBS, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_on, verifyResultValueDWord,
			"DSUBS on zop3=zop1-K", 2, 1, 444434},
	{140, ML_CODE_DSUBS, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_off, verifyResultValueDWord,
			"DSUBS off zop3=zop1-nop2", 2, 1, 0},
	{141, ML_CODE_DSUBS, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_on, verifyResultValueDWord,
			"DSUBS on zop3=zop1-nop2", 2, 1, 444434},
	{142, ML_CODE_DSUBS, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_off, verifyResultValueDWord,
			"DSUBS off zop3=nop1-zop2", 2, 1, 0},
	{143, ML_CODE_DSUBS, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_on, verifyResultValueDWord,
			"DSUBS on zop3=nop1-zop2", 2, 1, 444434},
	{144, ML_CODE_DSUBS, setCodeOp3S_WZW_DN, setInputOp3_val32_DWZW_WZ_off, verifyResultValueNibble8,
			"DSUBS off nop3=zop1-op2", 1, 1, 0},
	{145, ML_CODE_DSUBS, setCodeOp3S_WZW_DN, setInputOp3_val32_DWZW_WZ_on, verifyResultValueNibble8,
			"DSUBS on nop3=zop1-op2", 1, 1, 444434},
	{146, ML_CODE_DSUBS, setCodeOp3S_WZDK_DN, setInputOp3_val32_DWZK_WZ_off, verifyResultValueNibble8,
			"DSUBS off nop3=zop1-K", 1, 1, 0},
	{147, ML_CODE_DSUBS, setCodeOp3S_WZDK_DN, setInputOp3_val32_DWZK_WZ_on, verifyResultValueNibble8,
			"DSUBS on nop3=zop1-K", 1, 1, 444434},
	{148, ML_CODE_DSUBS, setCodeOp3S_WZDN_DN, setInputOp3_val32_WZN_DN_off, verifyResultValueNibble8,
			"DSUBS off nop3=zop1-nop2", 1, 1, 0},
	{149, ML_CODE_DSUBS, setCodeOp3S_WZDN_DN, setInputOp3_val32_WZN_DN_on, verifyResultValueNibble8,
			"DSUBS on nop3=zop1-nop2", 1, 1, 444434},
	{150, ML_CODE_DSUBS, setCodeOp3S_DNWZ_DN, setInputOp3_val32_DNWZ_DN_off, verifyResultValueNibble8,
			"DSUBS off nop3=nop1-zop2", 1, 1, 0},
	{151, ML_CODE_DSUBS, setCodeOp3S_DNWZ_DN, setInputOp3_val32_DNWZ_DN_on, verifyResultValueNibble8,
			"DSUBS on nop3=nop1-zop2", 1, 1, 444434},
	{152, ML_CODE_DSUBS, setCodeOp3S_WZWZ_DN, setInputOp3_val32_WZWZ_DN_off, verifyResultValueNibble8,
			"DSUBS off nop3=zop1-zop2", 1, 1, 0},
	{153, ML_CODE_DSUBS, setCodeOp3S_WZWZ_DN, setInputOp3_val32_WZWZ_DN_on, verifyResultValueNibble8,
			"DSUBS on nop3=zop1-zop2", 1, 1, 444434},

	{154, ML_CODE_DSUBPS, setCodeOp3S_WW_WZ, setInputOp3_val32_DWW_WZ_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=op1-op2", 0, 2, 0},
	{155, ML_CODE_DSUBPS, setCodeOp3S_WW_WZ, setInputOp3_val32p_DWW_WZ_on, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=op1-op2", 0, 2, 444434},
	{156, ML_CODE_DSUBPS, setCodeOp3S_W_WWZ, setInputOp3_val32_DW_WWZ_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=op1-op2", 0, 2, 0},
	{157, ML_CODE_DSUBPS, setCodeOp3S_W_WWZ, setInputOp3_val32p_DW_WWZ_on, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=op1-op2", 0, 2, 444434},
	{158, ML_CODE_DSUBPS, setCodeOp3S_DKW_WZ, setInputOp3_val32_DKW_WZ_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=K-op2", 0, 2, 0},
	{159, ML_CODE_DSUBPS, setCodeOp3S_DKW_WZ, setInputOp3_val32p_DKW_WZ_on, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=K-op2", 0, 2, 444434},
	{160, ML_CODE_DSUBPS, setCodeOp3S_DKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=K-K", 0, 2, 0},
	{161, ML_CODE_DSUBPS, setCodeOp3S_DKK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=K-K", 0, 2, 444434},
	{162, ML_CODE_DSUBPS, setCodeOp3S_DNW_WZ, setInputOp3_val32_DNW_WZ_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=nop1-op2", 0, 2, 0},
	{163, ML_CODE_DSUBPS, setCodeOp3S_DNW_WZ, setInputOp3_val32p_DNW_WZ_on, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=nop1-op2", 0, 2, 444434},
	{164, ML_CODE_DSUBPS, setCodeOp3S_DWN_WZ, setInputOp3_val32_DWN_WZ_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=op1-nop2", 0, 2, 0},
	{165, ML_CODE_DSUBPS, setCodeOp3S_DWN_WZ, setInputOp3_val32p_DWN_WZ_on, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=op1-nop2", 0, 2, 444434},
	{166, ML_CODE_DSUBPS, setCodeOp3S_WZW_WZ, setInputOp3_val32_DWZW_WZ_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=zop1-op2", 2, 2, 0},
	{167, ML_CODE_DSUBPS, setCodeOp3S_WZW_WZ, setInputOp3_val32p_DWZW_WZ_on, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=zop1-op2", 2, 2, 444434},
	{168, ML_CODE_DSUBPS, setCodeOp3S_WZDK_WZ, setInputOp3_val32_DWZK_WZ_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=zop1-K", 2, 2, 0},
	{169, ML_CODE_DSUBPS, setCodeOp3S_WZDK_WZ, setInputOp3_val32p_DWZK_WZ_on, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=zop1-K", 2, 2, 444434},
	{170, ML_CODE_DSUBPS, setCodeOp3S_WZDN_WZ, setInputOp3_val32_WZDN_WZ_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=zop1-nop2", 2, 2, 0},
	{171, ML_CODE_DSUBPS, setCodeOp3S_WZDN_WZ, setInputOp3_val32p_WZDN_WZ_on, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=zop1-nop2", 2, 2, 444434},
	{172, ML_CODE_DSUBPS, setCodeOp3S_DNWZ_WZ, setInputOp3_val32_DNWZ_WZ_off, verifyResultValueDWord,
			"DSUBPS 0->0 zop3=nop1-zop2", 2, 2, 0},
	{173, ML_CODE_DSUBPS, setCodeOp3S_DNWZ_WZ, setInputOp3_val32p_DNWZ_WZ_on, verifyResultValueDWord,
			"DSUBPS 0->1 zop3=nop1-zop2", 2, 2, 444434},
	{174, ML_CODE_DSUBPS, setCodeOp3S_WZW_DN, setInputOp3_val32_DWZW_WZ_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=zop1-op2", 1, 2, 0},
	{175, ML_CODE_DSUBPS, setCodeOp3S_WZW_DN, setInputOp3_val32p_DWZW_WZ_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=zop1-op2", 1, 2, 444434},
	{176, ML_CODE_DSUBPS, setCodeOp3S_WZDK_DN, setInputOp3_val32_DWZK_WZ_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=zop1-K", 1, 2, 0},
	{177, ML_CODE_DSUBPS, setCodeOp3S_WZDK_DN, setInputOp3_val32p_DWZK_WZ_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=zop1-K", 1, 2, 444434},
	{178, ML_CODE_DSUBPS, setCodeOp3S_WZDN_DN, setInputOp3_val32_WZN_DN_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=zop1-nop2", 1, 2, 0},
	{179, ML_CODE_DSUBPS, setCodeOp3S_WZDN_DN, setInputOp3_val32p_WZN_DN_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=zop1-nop2", 1, 2, 444434},
	{180, ML_CODE_DSUBPS, setCodeOp3S_DNWZ_DN, setInputOp3_val32_DNWZ_DN_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=nop1-zop2", 1, 2, 0},
	{181, ML_CODE_DSUBPS, setCodeOp3S_DNWZ_DN, setInputOp3_val32p_DNWZ_DN_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=nop1-zop2", 1, 2, 444434},
	{182, ML_CODE_DSUBPS, setCodeOp3S_WZWZ_DN, setInputOp3_val32_WZWZ_DN_off, verifyResultValueNibble8,
			"DSUBPS 0->0 nop3=zop1-zop2", 1, 2, 0},
	{183, ML_CODE_DSUBPS, setCodeOp3S_WZWZ_DN, setInputOp3_val32p_WZWZ_DN_on, verifyResultValueNibble8,
			"DSUBPS 0->1 nop3=zop1-zop2", 1, 2, 444434},

	{184, ML_CODE_DBADD, setCodeOp2_W_WZ, setInputOp2_BCD8_DWWZ_off, verifyResultValueDWord,
			"DBADD off op1+zop2", 0, 1, 0x9871068},
	{185, ML_CODE_DBADD, setCodeOp2_W_WZ, setInputOp2_BCD8_DWWZ_on, verifyResultValueDWord,
			"DBADD on op1+zop2", 0, 1, 0x10194524},
	{186, ML_CODE_DBADD, setCodeOp2_W_WZ, setInputOp2_BCD8_DWWZ_over_on, verifyResultValueDWord,
			"DBADD on op1+zop2 over", 0, 1, 0x654321},
	{187, ML_CODE_DBADD, setCodeOp2_BDK_WZ, setInputOp2_BCD8_BDKWZ_off, verifyResultValueDWord,
			"DBADD off K+zop2", 0, 1, 0x9871068},
	{188, ML_CODE_DBADD, setCodeOp2_BDK_WZ, setInputOp2_BCD8_BDKWZ_on, verifyResultValueDWord,
			"DBADD on K+zop2", 0, 1, 0x10194524},
	{189, ML_CODE_DBADD, setCodeOp2_DN_WZ, setInputOp2_BCD8_DNWZ_off, verifyResultValueDWord,
			"DBADD off nop1+zop2", 0, 1, 0x9871068},
	{190, ML_CODE_DBADD, setCodeOp2_DN_WZ, setInputOp2_BCD8_DNWZ_on, verifyResultValueDWord,
			"DBADD on nop1+zop2", 0, 1, 0x10194524},
	{191, ML_CODE_DBADD, setCodeOp2_WZ_W, setInputOp2_BCD8_DWZW_off, verifyResultValueDWord,
			"DBADD off zop1+op2", 1, 1, 0x9871068},
	{192, ML_CODE_DBADD, setCodeOp2_WZ_W, setInputOp2_BCD8_DWZW_on, verifyResultValueDWord,
			"DBADD on zop1+op2", 1, 1, 0x10194524},
	{193, ML_CODE_DBADD, setCodeOp2_WZ_DN, setInputOp2_BCD8_WZDN_off, verifyResultValueNibble8,
			"DBADD off zop1+nop2", 1, 1, 0x9871068},
	{194, ML_CODE_DBADD, setCodeOp2_WZ_DN, setInputOp2_BCD8_WZDN_on, verifyResultValueNibble8,
			"DBADD on zop1+nop2", 1, 1, 0x10194524},
	{195, ML_CODE_DBADD, setCodeOp2_WZ_WZ, setInputOp2_BCD8_DWZWZ_off, verifyResultValueDWord,
			"DBADD off zop1+zop2", 2, 1, 0x9871068},
	{196, ML_CODE_DBADD, setCodeOp2_WZ_WZ, setInputOp2_BCD8_DWZWZ_on, verifyResultValueDWord,
			"DBADD on zop1+zop2", 2, 1, 0x10194524},

	{197, ML_CODE_DBADDP, setCodeOp2_W_WZ, setInputOp2_BCD8_DWWZ_off, verifyResultValueDWord,
			"DBADDP 0->0 op1+zop2", 0, 2, 0x9871068},
	{198, ML_CODE_DBADDP, setCodeOp2_W_WZ, setInputOp2_BCD8p_DWWZ_on, verifyResultValueDWord,
			"DBADDP 0->1 op1+zop2", 0, 2, 0x10194524},
	{199, ML_CODE_DBADDP, setCodeOp2_W_WZ, setInputOp2_BCD8p_DWWZ_over_on, verifyResultValueDWord,
			"DBADDP 0->1 op1+zop2 over", 0, 2, 0x654321},
	{200, ML_CODE_DBADDP, setCodeOp2_BDK_WZ, setInputOp2_BCD8_BDKWZ_off, verifyResultValueDWord,
			"DBADDP 0->0 K+zop2", 0, 2, 0x9871068},
	{201, ML_CODE_DBADDP, setCodeOp2_BDK_WZ, setInputOp2_BCD8p_BDKWZ_on, verifyResultValueDWord,
			"DBADDP 0->1 K+zop2", 0, 2, 0x10194524},
	{202, ML_CODE_DBADDP, setCodeOp2_DN_WZ, setInputOp2_BCD8_DNWZ_off, verifyResultValueDWord,
			"DBADDP 0->0 nop1+zop2", 0, 2, 0x9871068},
	{203, ML_CODE_DBADDP, setCodeOp2_DN_WZ, setInputOp2_BCD8p_DNWZ_on, verifyResultValueDWord,
			"DBADDP 0->1 nop1+zop2", 0, 2, 0x10194524},
	{204, ML_CODE_DBADDP, setCodeOp2_WZ_W, setInputOp2_BCD8_DWZW_off, verifyResultValueDWord,
			"DBADDP 0->0 zop1+op2", 1, 2, 0x9871068},
	{205, ML_CODE_DBADDP, setCodeOp2_WZ_W, setInputOp2_BCD8p_DWZW_on, verifyResultValueDWord,
			"DBADDP 0->1 zop1+op2", 1, 2, 0x10194524},
	{206, ML_CODE_DBADDP, setCodeOp2_WZ_DN, setInputOp2_BCD8_WZDN_off, verifyResultValueNibble8,
			"DBADDP 0->0 zop1+nop2", 1, 2, 0x9871068},
	{207, ML_CODE_DBADDP, setCodeOp2_WZ_DN, setInputOp2_BCD8p_WZDN_on, verifyResultValueNibble8,
			"DBADDP 0->1 zop1+nop2", 1, 2, 0x10194524},
	{208, ML_CODE_DBADDP, setCodeOp2_WZ_WZ, setInputOp2_BCD8_DWZWZ_off, verifyResultValueDWord,
			"DBADDP 0->0 zop1+zop2", 2, 2, 0x9871068},
	{209, ML_CODE_DBADDP, setCodeOp2_WZ_WZ, setInputOp2_BCD8p_DWZWZ_on, verifyResultValueDWord,
			"DBADDP 0->1 zop1+zop2", 2, 2, 0x10194524},

	{210, ML_CODE_DBSUB, setCodeOp2_W_WZ, setInputOp2_BCD8_DWWZ_off, verifyResultValueDWord,
			"DBSUB off zop2-op1", 0, 1, 0x9871068},
	{211, ML_CODE_DBSUB, setCodeOp2_W_WZ, setInputOp2_BCD8_DWWZ_on, verifyResultValueDWord,
			"DBSUB on zop2-op1", 0, 1, 0x9547612},
	{212, ML_CODE_DBSUB, setCodeOp2_W_WZ, setInputOp2_BCD8_DWWZ_under_on, verifyResultValueDWord,
			"DBSUB on zop2-op1 over", 0, 1, 0x99999999},
	{213, ML_CODE_DBSUB, setCodeOp2_BDK_WZ, setInputOp2_BCD8_BDKWZ_off, verifyResultValueDWord,
			"DBSUB off zop2-K", 0, 1, 0x9871068},
	{214, ML_CODE_DBSUB, setCodeOp2_BDK_WZ, setInputOp2_BCD8_BDKWZ_on, verifyResultValueDWord,
			"DBSUB on zop2-K", 0, 1, 0x9547612},
	{215, ML_CODE_DBSUB, setCodeOp2_DN_WZ, setInputOp2_BCD8_DNWZ_off, verifyResultValueDWord,
			"DBSUB off zop2-nop1", 0, 1, 0x9871068},
	{216, ML_CODE_DBSUB, setCodeOp2_DN_WZ, setInputOp2_BCD8_DNWZ_on, verifyResultValueDWord,
			"DBSUB on zop2-nop1", 0, 1, 0x9547612},
	{217, ML_CODE_DBSUB, setCodeOp2_WZ_W, setInputOp2_BCD8_DWZW_off, verifyResultValueDWord,
			"DBSUB off op2-zop1", 1, 1, 0x9871068},
	{218, ML_CODE_DBSUB, setCodeOp2_WZ_W, setInputOp2_BCD8_DWZW_on, verifyResultValueDWord,
			"DBSUB on op2-zop1", 1, 1, 0x9547612},
	{219, ML_CODE_DBSUB, setCodeOp2_WZ_DN, setInputOp2_BCD8_WZDN_off, verifyResultValueNibble8,
			"DBSUB off nop2-zop1", 1, 1, 0x9871068},
	{220, ML_CODE_DBSUB, setCodeOp2_WZ_DN, setInputOp2_BCD8_WZDN_on, verifyResultValueNibble8,
			"DBSUB on nop2-zop1", 1, 1, 0x9547612},
	{221, ML_CODE_DBSUB, setCodeOp2_WZ_WZ, setInputOp2_BCD8_DWZWZ_off, verifyResultValueDWord,
			"DBSUB off zop2-zop1", 2, 1, 0x9871068},
	{222, ML_CODE_DBSUB, setCodeOp2_WZ_WZ, setInputOp2_BCD8_DWZWZ_on, verifyResultValueDWord,
			"DBSUB on zop2-zop1", 2, 1, 0x9547612},

	{223, ML_CODE_DBSUBP, setCodeOp2_W_WZ, setInputOp2_BCD8_DWWZ_off, verifyResultValueDWord,
			"DBSUBP 0->0 zop2-op1", 0, 2, 0x9871068},
	{224, ML_CODE_DBSUBP, setCodeOp2_W_WZ, setInputOp2_BCD8p_DWWZ_on, verifyResultValueDWord,
			"DBSUBP 0->1 zop2-op1", 0, 2, 0x9547612},
	{225, ML_CODE_DBSUBP, setCodeOp2_W_WZ, setInputOp2_BCD8p_DWWZ_under_on, verifyResultValueDWord,
			"DBSUBP 0->1 zop2-op1 over", 0, 2, 0x99999999},
	{226, ML_CODE_DBSUBP, setCodeOp2_BDK_WZ, setInputOp2_BCD8_BDKWZ_off, verifyResultValueDWord,
			"DBSUBP 0->0 zop2-K", 0, 2, 0x9871068},
	{227, ML_CODE_DBSUBP, setCodeOp2_BDK_WZ, setInputOp2_BCD8p_BDKWZ_on, verifyResultValueDWord,
			"DBSUBP 0->1 zop2-K", 0, 2, 0x9547612},
	{228, ML_CODE_DBSUBP, setCodeOp2_DN_WZ, setInputOp2_BCD8_DNWZ_off, verifyResultValueDWord,
			"DBSUBP 0->0 zop2-nop1", 0, 2, 0x9871068},
	{229, ML_CODE_DBSUBP, setCodeOp2_DN_WZ, setInputOp2_BCD8p_DNWZ_on, verifyResultValueDWord,
			"DBSUBP 0->1 zop2-nop1", 0, 2, 0x9547612},
	{230, ML_CODE_DBSUBP, setCodeOp2_WZ_W, setInputOp2_BCD8_DWZW_off, verifyResultValueDWord,
			"DBSUBP 0->0 op2-zop1", 1, 2, 0x9871068},
	{231, ML_CODE_DBSUBP, setCodeOp2_WZ_W, setInputOp2_BCD8p_DWZW_on, verifyResultValueDWord,
			"DBSUBP 0->1 op2-zop1", 1, 2, 0x9547612},
	{232, ML_CODE_DBSUBP, setCodeOp2_WZ_DN, setInputOp2_BCD8_WZDN_off, verifyResultValueNibble8,
			"DBSUBP 0->0 nop2zop1", 1, 2, 0x9871068},
	{233, ML_CODE_DBSUBP, setCodeOp2_WZ_DN, setInputOp2_BCD8p_WZDN_on, verifyResultValueNibble8,
			"DBSUBP 0->1 nop2-zop1", 1, 2, 0x9547612},
	{234, ML_CODE_DBSUBP, setCodeOp2_WZ_WZ, setInputOp2_BCD8_DWZWZ_off, verifyResultValueDWord,
			"DBSUBP 0->0 zop2-zop1", 2, 2, 0x9871068},
	{235, ML_CODE_DBSUBP, setCodeOp2_WZ_WZ, setInputOp2_BCD8p_DWZWZ_on, verifyResultValueDWord,
			"DBSUBP 0->1 zop2-zop1", 2, 2, 0x9547612},

	{236, ML_CODE_DBADDS, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_WZ_off, verifyResultValueDWord,
			"DBADDS off zop3=op1+op2", 0, 1, 0},
	{237, ML_CODE_DBADDS, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_WZ_on, verifyResultValueDWord,
			"DBADDS on zop3=op1+op2", 0, 1, 0x10194524},
	{238, ML_CODE_DBADDS, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WWZ_off, verifyResultValueDWord,
			"DBADDS off zop3=op1+op2", 0, 1, 0},
	{239, ML_CODE_DBADDS, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WWZ_on, verifyResultValueDWord,
			"DBADDS on zop3=op1+op2", 0, 1, 0x10194524},
	{240, ML_CODE_DBADDS, setCodeOp3S_DBKW_WZ, setInputOp3_BCD8_DBKW_WZ_off, verifyResultValueDWord,
			"DBADDS off zop3=K+op2", 0, 1, 0},
	{241, ML_CODE_DBADDS, setCodeOp3S_DBKW_WZ, setInputOp3_BCD8_DBKW_WZ_on, verifyResultValueDWord,
			"DBADDS on zop3=K+op2", 0, 1, 0x10194524},
	{242, ML_CODE_DBADDS, setCodeOp3S_DBKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DBADDS off zop3=K+K", 0, 1, 0},
	{243, ML_CODE_DBADDS, setCodeOp3S_DBKK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"DBADDS on zop3=K+K", 0, 1, 0x10194524},
	{244, ML_CODE_DBADDS, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_WZ_off, verifyResultValueDWord,
			"DBADDS off zop3=nop1+op2", 0, 1, 0},
	{245, ML_CODE_DBADDS, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_WZ_on, verifyResultValueDWord,
			"DBADDS on zop3=nop1+op2", 0, 1, 0x10194524},
	{246, ML_CODE_DBADDS, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_WZ_off, verifyResultValueDWord,
			"DBADDS off zop3=op1+nop2", 0, 1, 0},
	{247, ML_CODE_DBADDS, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_WZ_on, verifyResultValueDWord,
			"DBADDS on zop3=op1+nop2", 0, 1, 0x10194524},
	{248, ML_CODE_DBADDS, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_WZ_off, verifyResultValueDWord,
			"DBADDS off zop3=zop1+op2", 2, 1, 0},
	{249, ML_CODE_DBADDS, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_WZ_on, verifyResultValueDWord,
			"DBADDS on zop3=zop1+op2", 2, 1, 0x10194524},
	{250, ML_CODE_DBADDS, setCodeOp3S_WZDBK_WZ, setInputOp3_BCD8_WZDBK_WZ_off, verifyResultValueDWord,
			"DBADDS off zop3=zop1+K", 2, 1, 0},
	{251, ML_CODE_DBADDS, setCodeOp3S_WZDBK_WZ, setInputOp3_BCD8_WZDBK_WZ_on, verifyResultValueDWord,
			"DBADDS on zop3=zop1+K", 2, 1, 0x10194524},
	{252, ML_CODE_DBADDS, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_WZ_off, verifyResultValueDWord,
			"DBADDS off zop3=zop1+nop2", 2, 1, 0},
	{253, ML_CODE_DBADDS, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_WZ_on, verifyResultValueDWord,
			"DBADDS on zop3=zop1+nop2", 2, 1, 0x10194524},
	{254, ML_CODE_DBADDS, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_WZ_off, verifyResultValueDWord,
			"DBADDS off zop3=nop1+zop2", 2, 1, 0},
	{255, ML_CODE_DBADDS, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_WZ_on, verifyResultValueDWord,
			"DBADDS on zop3=nop1+zop2", 2, 1, 0x10194524},
	{256, ML_CODE_DBADDS, setCodeOp3S_WZW_DN, setInputOp3_BCD8_DWZW_WZ_off, verifyResultValueNibble8,
			"DBADDS off nop3=zop1+op2", 1, 1, 0},
	{257, ML_CODE_DBADDS, setCodeOp3S_WZW_DN, setInputOp3_BCD8_DWZW_WZ_on, verifyResultValueNibble8,
			"DBADDS on nop3=zop1+op2", 1, 1, 0x10194524},
	{258, ML_CODE_DBADDS, setCodeOp3S_WZDBK_DN, setInputOp3_BCD8_WZDBK_WZ_off, verifyResultValueNibble8,
			"DBADDS off nop3=zop1+K", 1, 1, 0},
	{259, ML_CODE_DBADDS, setCodeOp3S_WZDBK_DN, setInputOp3_BCD8_WZDBK_WZ_on, verifyResultValueNibble8,
			"DBADDS on nop3=zop1+K", 1, 1, 0x10194524},
	{260, ML_CODE_DBADDS, setCodeOp3S_WZDN_DN, setInputOp3_BCD8_WZDN_DN_off, verifyResultValueNibble8,
			"DBADDS off nop3=zop1+nop2", 1, 1, 0},
	{261, ML_CODE_DBADDS, setCodeOp3S_WZDN_DN, setInputOp3_BCD8_WZDN_DN_on, verifyResultValueNibble8,
			"DBADDS on nop3=zop1+nop2", 1, 1, 0x10194524},
	{262, ML_CODE_DBADDS, setCodeOp3S_DNWZ_DN, setInputOp3_BCD8_DNWZ_DN_off, verifyResultValueNibble8,
			"DBADDS off nop3=nop1+zop2", 1, 1, 0},
	{263, ML_CODE_DBADDS, setCodeOp3S_DNWZ_DN, setInputOp3_BCD8_DNWZ_DN_on, verifyResultValueNibble8,
			"DBADDS on nop3=nop1+zop2", 1, 1, 0x10194524},
	{264, ML_CODE_DBADDS, setCodeOp3S_WZWZ_DN, setInputOp3_BCD8_DWZWZ_DN_off, verifyResultValueNibble8,
			"DBADDS off nop3=zop1+zop2", 1, 1, 0},
	{265, ML_CODE_DBADDS, setCodeOp3S_WZWZ_DN, setInputOp3_BCD8_DWZWZ_DN_on, verifyResultValueNibble8,
			"DBADDS on nop3=zop1+zop2", 1, 1, 0x10194524},

	{266, ML_CODE_DBADDPS, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_WZ_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=op1+op2", 0, 2, 0},
	{267, ML_CODE_DBADDPS, setCodeOp3S_WW_WZ, setInputOp3_BCD8p_DWW_WZ_on, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=op1+op2", 0, 2, 0x10194524},
	{268, ML_CODE_DBADDPS, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WWZ_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=op1+op2", 0, 2, 0},
	{269, ML_CODE_DBADDPS, setCodeOp3S_W_WWZ, setInputOp3_BCD8p_DW_WWZ_on, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=op1+op2", 0, 2, 0x10194524},
	{270, ML_CODE_DBADDPS, setCodeOp3S_DBKW_WZ, setInputOp3_BCD8_DBKW_WZ_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=K+op2", 0, 2, 0},
	{271, ML_CODE_DBADDPS, setCodeOp3S_DBKW_WZ, setInputOp3_BCD8p_DBKW_WZ_on, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=K+op2", 0, 2, 0x10194524},
	{272, ML_CODE_DBADDPS, setCodeOp3S_DBKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=K+K", 0, 2, 0},
	{273, ML_CODE_DBADDPS, setCodeOp3S_DBKK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=K+K", 0, 2, 0x10194524},
	{274, ML_CODE_DBADDPS, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_WZ_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=nop1+op2", 0, 2, 0},
	{275, ML_CODE_DBADDPS, setCodeOp3S_DNW_WZ, setInputOp3_BCD8p_DNW_WZ_on, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=nop1+op2", 0, 2, 0x10194524},
	{276, ML_CODE_DBADDPS, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_WZ_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=op1+nop2", 0, 2, 0},
	{277, ML_CODE_DBADDPS, setCodeOp3S_DWN_WZ, setInputOp3_BCD8p_WDN_WZ_on, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=op1+nop2", 0, 2, 0x10194524},
	{278, ML_CODE_DBADDPS, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_WZ_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=zop1+op2", 2, 2, 0},
	{279, ML_CODE_DBADDPS, setCodeOp3S_WZW_WZ, setInputOp3_BCD8p_DWZW_WZ_on, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=zop1+op2", 2, 2, 0x10194524},
	{280, ML_CODE_DBADDPS, setCodeOp3S_WZDBK_WZ, setInputOp3_BCD8_WZDBK_WZ_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=zop1+K", 2, 2, 0},
	{281, ML_CODE_DBADDPS, setCodeOp3S_WZDBK_WZ, setInputOp3_BCD8p_WZDBK_WZ_on, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=zop1+K", 2, 2, 0x10194524},
	{282, ML_CODE_DBADDPS, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_WZ_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=zop1+nop2", 2, 2, 0},
	{283, ML_CODE_DBADDPS, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8p_WZDN_WZ_on, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=zop1+nop2", 2, 2, 0x10194524},
	{284, ML_CODE_DBADDPS, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_WZ_off, verifyResultValueDWord,
			"DBADDPS 0->0 zop3=nop1+zop2", 2, 2, 0},
	{285, ML_CODE_DBADDPS, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8p_DNWZ_WZ_on, verifyResultValueDWord,
			"DBADDPS 0->1 zop3=nop1+zop2", 2, 2, 0x10194524},
	{286, ML_CODE_DBADDPS, setCodeOp3S_WZW_DN, setInputOp3_BCD8_DWZW_WZ_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=zop1+op2", 1, 2, 0},
	{287, ML_CODE_DBADDPS, setCodeOp3S_WZW_DN, setInputOp3_BCD8p_DWZW_WZ_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=zop1+op2", 1, 2, 0x10194524},
	{288, ML_CODE_DBADDPS, setCodeOp3S_WZDBK_DN, setInputOp3_BCD8_WZDBK_WZ_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=zop1+K", 1, 2, 0},
	{289, ML_CODE_DBADDPS, setCodeOp3S_WZDBK_DN, setInputOp3_BCD8p_WZDBK_WZ_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=zop1+K", 1, 2, 0x10194524},
	{290, ML_CODE_DBADDPS, setCodeOp3S_WZDN_DN, setInputOp3_BCD8_WZDN_DN_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=zop1+nop2", 1, 2, 0},
	{291, ML_CODE_DBADDPS, setCodeOp3S_WZDN_DN, setInputOp3_BCD8p_WZDN_DN_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=zop1+nop2", 1, 2, 0x10194524},
	{292, ML_CODE_DBADDPS, setCodeOp3S_DNWZ_DN, setInputOp3_BCD8_DNWZ_DN_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=nop1+zop2", 1, 2, 0},
	{293, ML_CODE_DBADDPS, setCodeOp3S_DNWZ_DN, setInputOp3_BCD8p_DNWZ_DN_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=nop1+zop2", 1, 2, 0x10194524},
	{294, ML_CODE_DBADDPS, setCodeOp3S_WZWZ_DN, setInputOp3_BCD8_DWZWZ_DN_off, verifyResultValueNibble8,
			"DBADDPS 0->0 nop3=zop1+zop2", 1, 2, 0},
	{295, ML_CODE_DBADDPS, setCodeOp3S_WZWZ_DN, setInputOp3_BCD8p_DWZWZ_DN_on, verifyResultValueNibble8,
			"DBADDPS 0->1 nop3=zop1+zop2", 1, 2, 0x10194524},

	{296, ML_CODE_DBSUBS, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_WZ_off, verifyResultValueDWord,
			"DBSUBS off zop3=op1-op2", 0, 1, 0},
	{297, ML_CODE_DBSUBS, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_WZ_on, verifyResultValueDWord,
			"DBSUBS on zop3=op1-op2", 0, 1, 0x90452388}, //0x90452388
	{298, ML_CODE_DBSUBS, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WWZ_off, verifyResultValueDWord,
			"DBSUBS off zop3=op1-op2", 0, 1, 0},
	{299, ML_CODE_DBSUBS, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WWZ_on, verifyResultValueDWord,
			"DBSUBS on zop3=op1-op2", 0, 1, 0x90452388},
	{300, ML_CODE_DBSUBS, setCodeOp3S_DBKW_WZ, setInputOp3_BCD8_DBKW_WZ_off, verifyResultValueDWord,
			"DBSUBS off zop3=K-op2", 0, 1, 0},
	{301, ML_CODE_DBSUBS, setCodeOp3S_DBKW_WZ, setInputOp3_BCD8_DBKW_WZ_on, verifyResultValueDWord,
			"DBSUBS on zop3=K-op2", 0, 1, 0x90452388},
	{302, ML_CODE_DBSUBS, setCodeOp3S_DBKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DBSUBS off zop3=K-K", 0, 1, 0},
	{303, ML_CODE_DBSUBS, setCodeOp3S_DBKK_WZ, setInputOp2_none_on, verifyResultValueDWord,
			"DBSUBS on zop3=K-K", 0, 1, 0x90452388},
	{304, ML_CODE_DBSUBS, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_WZ_off, verifyResultValueDWord,
			"DBSUBS off zop3=nop1-op2", 0, 1, 0},
	{305, ML_CODE_DBSUBS, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_WZ_on, verifyResultValueDWord,
			"DBSUBS on zop3=nop1-op2", 0, 1, 0x90452388},
	{306, ML_CODE_DBSUBS, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_WZ_off, verifyResultValueDWord,
			"DBSUBS off zop3=op1-nop2", 0, 1, 0},
	{307, ML_CODE_DBSUBS, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_WZ_on, verifyResultValueDWord,
			"DBSUBS on zop3=op1-nop2", 0, 1, 0x90452388},
	{308, ML_CODE_DBSUBS, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_WZ_off, verifyResultValueDWord,
			"DBSUBS off zop3=zop1-op2", 2, 1, 0},
	{309, ML_CODE_DBSUBS, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_WZ_on, verifyResultValueDWord,
			"DBSUBS on zop3=zop1-op2", 2, 1, 0x90452388},
	{310, ML_CODE_DBSUBS, setCodeOp3S_WZDBK_WZ, setInputOp3_BCD8_WZDBK_WZ_off, verifyResultValueDWord,
			"DBSUBS off zop3=zop1-K", 2, 1, 0},
	{311, ML_CODE_DBSUBS, setCodeOp3S_WZDBK_WZ, setInputOp3_BCD8_WZDBK_WZ_on, verifyResultValueDWord,
			"DBSUBS on zop3=zop1-K", 2, 1, 0x90452388},
	{312, ML_CODE_DBSUBS, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_WZ_off, verifyResultValueDWord,
			"DBSUBS off zop3=zop1-nop2", 2, 1, 0},
	{313, ML_CODE_DBSUBS, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_WZ_on, verifyResultValueDWord,
			"DBSUBS on zop3=zop1-nop2", 2, 1, 0x90452388},
	{314, ML_CODE_DBSUBS, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_WZ_off, verifyResultValueDWord,
			"DBSUBS off zop3=nop1-zop2", 2, 1, 0},
	{315, ML_CODE_DBSUBS, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_WZ_on, verifyResultValueDWord,
			"DBSUBS on zop3=nop1-zop2", 2, 1, 0x90452388},
	{316, ML_CODE_DBSUBS, setCodeOp3S_WZW_DN, setInputOp3_BCD8_DWZW_WZ_off, verifyResultValueNibble8,
			"DBSUBS off nop3=zop1-op2", 1, 1, 0},
	{317, ML_CODE_DBSUBS, setCodeOp3S_WZW_DN, setInputOp3_BCD8_DWZW_WZ_on, verifyResultValueNibble8,
			"DBSUBS on nop3=zop1-op2", 1, 1, 0x90452388},
	{318, ML_CODE_DBSUBS, setCodeOp3S_WZDBK_DN, setInputOp3_BCD8_WZDBK_WZ_off, verifyResultValueNibble8,
			"DBSUBS off nop3=zop1-K", 1, 1, 0},
	{319, ML_CODE_DBSUBS, setCodeOp3S_WZDBK_DN, setInputOp3_BCD8_WZDBK_WZ_on, verifyResultValueNibble8,
			"DBSUBS on nop3=zop1-K", 1, 1, 0x90452388},
	{320, ML_CODE_DBSUBS, setCodeOp3S_WZDN_DN, setInputOp3_BCD8_WZDN_DN_off, verifyResultValueNibble8,
			"DBSUBS off nop3=zop1-nop2", 1, 1, 0},
	{321, ML_CODE_DBSUBS, setCodeOp3S_WZDN_DN, setInputOp3_BCD8_WZDN_DN_on, verifyResultValueNibble8,
			"DBSUBS on nop3=zop1-nop2", 1, 1, 0x90452388},
	{322, ML_CODE_DBSUBS, setCodeOp3S_DNWZ_DN, setInputOp3_BCD8_DNWZ_DN_off, verifyResultValueNibble8,
			"DBSUBS off nop3=nop1-zop2", 1, 1, 0},
	{323, ML_CODE_DBSUBS, setCodeOp3S_DNWZ_DN, setInputOp3_BCD8_DNWZ_DN_on, verifyResultValueNibble8,
			"DBSUBS on nop3=nop1-zop2", 1, 1, 0x90452388},
	{324, ML_CODE_DBSUBS, setCodeOp3S_WZWZ_DN, setInputOp3_BCD8_DWZWZ_DN_off, verifyResultValueNibble8,
			"DBSUBS off nop3=zop1-zop2", 1, 1, 0},
	{325, ML_CODE_DBSUBS, setCodeOp3S_WZWZ_DN, setInputOp3_BCD8_DWZWZ_DN_on, verifyResultValueNibble8,
			"DBSUBS on nop3=zop1-zop2", 1, 1, 0x90452388},

	{326, ML_CODE_DBSUBPS, setCodeOp3S_WW_WZ, setInputOp3_BCD8_DWW_WZ_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=op1-op2", 0, 2, 0},
	{327, ML_CODE_DBSUBPS, setCodeOp3S_WW_WZ, setInputOp3_BCD8p_DWW_WZ_on, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=op1-op2", 0, 2, 0x90452388},
	{328, ML_CODE_DBSUBPS, setCodeOp3S_W_WWZ, setInputOp3_BCD8_DW_WWZ_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=op1-op2", 0, 2, 0},
	{329, ML_CODE_DBSUBPS, setCodeOp3S_W_WWZ, setInputOp3_BCD8p_DW_WWZ_on, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=op1-op2", 0, 2, 0x90452388},
	{330, ML_CODE_DBSUBPS, setCodeOp3S_DBKW_WZ, setInputOp3_BCD8_DBKW_WZ_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=K-op2", 0, 2, 0},
	{331, ML_CODE_DBSUBPS, setCodeOp3S_DBKW_WZ, setInputOp3_BCD8p_DBKW_WZ_on, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=K-op2", 0, 2, 0x90452388},
	{332, ML_CODE_DBSUBPS, setCodeOp3S_DBKK_WZ, setInputOp2_none_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=K-K", 0, 2, 0},
	{333, ML_CODE_DBSUBPS, setCodeOp3S_DBKK_WZ, setInputOp2_none_tr1, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=K-K", 0, 2, 0x90452388},
	{334, ML_CODE_DBSUBPS, setCodeOp3S_DNW_WZ, setInputOp3_BCD8_DNW_WZ_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=nop1-op2", 0, 2, 0},
	{335, ML_CODE_DBSUBPS, setCodeOp3S_DNW_WZ, setInputOp3_BCD8p_DNW_WZ_on, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=nop1-op2", 0, 2, 0x90452388},
	{336, ML_CODE_DBSUBPS, setCodeOp3S_DWN_WZ, setInputOp3_BCD8_WDN_WZ_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=op1-nop2", 0, 2, 0},
	{337, ML_CODE_DBSUBPS, setCodeOp3S_DWN_WZ, setInputOp3_BCD8p_WDN_WZ_on, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=op1-nop2", 0, 2, 0x90452388},
	{338, ML_CODE_DBSUBPS, setCodeOp3S_WZW_WZ, setInputOp3_BCD8_DWZW_WZ_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=zop1-op2", 2, 2, 0},
	{339, ML_CODE_DBSUBPS, setCodeOp3S_WZW_WZ, setInputOp3_BCD8p_DWZW_WZ_on, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=zop1-op2", 2, 2, 0x90452388},
	{340, ML_CODE_DBSUBPS, setCodeOp3S_WZDBK_WZ, setInputOp3_BCD8_WZDBK_WZ_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=zop1-K", 2, 2, 0},
	{341, ML_CODE_DBSUBPS, setCodeOp3S_WZDBK_WZ, setInputOp3_BCD8p_WZDBK_WZ_on, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=zop1-K", 2, 2, 0x90452388},
	{342, ML_CODE_DBSUBPS, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8_WZDN_WZ_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=zop1-nop2", 2, 2, 0},
	{343, ML_CODE_DBSUBPS, setCodeOp3S_WZDN_WZ, setInputOp3_BCD8p_WZDN_WZ_on, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=zop1-nop2", 2, 2, 0x90452388},
	{344, ML_CODE_DBSUBPS, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8_DNWZ_WZ_off, verifyResultValueDWord,
			"DBSUBPS 0->0 zop3=nop1-zop2", 2, 2, 0},
	{345, ML_CODE_DBSUBPS, setCodeOp3S_DNWZ_WZ, setInputOp3_BCD8p_DNWZ_WZ_on, verifyResultValueDWord,
			"DBSUBPS 0->1 zop3=nop1-zop2", 2, 2, 0x90452388},
	{346, ML_CODE_DBSUBPS, setCodeOp3S_WZW_DN, setInputOp3_BCD8_DWZW_WZ_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=zop1-op2", 1, 2, 0},
	{347, ML_CODE_DBSUBPS, setCodeOp3S_WZW_DN, setInputOp3_BCD8p_DWZW_WZ_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=zop1-op2", 1, 2, 0x90452388},
	{348, ML_CODE_DBSUBPS, setCodeOp3S_WZDBK_DN, setInputOp3_BCD8_WZDBK_WZ_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=zop1-K", 1, 2, 0},
	{349, ML_CODE_DBSUBPS, setCodeOp3S_WZDBK_DN, setInputOp3_BCD8p_WZDBK_WZ_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=zop1-K", 1, 2, 0x90452388},
	{350, ML_CODE_DBSUBPS, setCodeOp3S_WZDN_DN, setInputOp3_BCD8_WZDN_DN_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=zop1-nop2", 1, 2, 0},
	{351, ML_CODE_DBSUBPS, setCodeOp3S_WZDN_DN, setInputOp3_BCD8p_WZDN_DN_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=zop1-nop2", 1, 2, 0x90452388},
	{352, ML_CODE_DBSUBPS, setCodeOp3S_DNWZ_DN, setInputOp3_BCD8_DNWZ_DN_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=nop1-zop2", 1, 2, 0},
	{353, ML_CODE_DBSUBPS, setCodeOp3S_DNWZ_DN, setInputOp3_BCD8p_DNWZ_DN_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=nop1-zop2", 1, 2, 0x90452388},
	{354, ML_CODE_DBSUBPS, setCodeOp3S_WZWZ_DN, setInputOp3_BCD8_DWZWZ_DN_off, verifyResultValueNibble8,
			"DBSUBPS 0->0 nop3=zop1-zop2", 1, 2, 0},
	{355, ML_CODE_DBSUBPS, setCodeOp3S_WZWZ_DN, setInputOp3_BCD8p_DWZWZ_DN_on, verifyResultValueNibble8,
			"DBSUBPS 0->1 nop3=zop1-zop2", 1, 2, 0x90452388},

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0, 0 }
};



int total_basic_compute_dword_idx_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_basic_compute_dword_idx_test_number; i++)
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


int setCodeOp2_DK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos + idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos + idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperand(in_reg, in_pos);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in1_val); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DNW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperand(out_reg, 160);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DWN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(in_pos == pos + idx_val) return 0;
	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(isRangeOver(out_reg, in_pos, 0)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(out_reg, in_pos); addMLOperandNibble(8, in_reg, 160);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=123456;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZDN_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(isRangeOver(out_reg, in_pos, idx_val)) return 0;
	if(in_pos == pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(out_reg, in_pos, idx_pos); addMLOperandNibble(8, in_reg, 160);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DNWZ_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg > OPERAND_ML_CODE_B ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(isRangeOver(out_reg, 160, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, in_reg, in_pos); addMLOperandZIndex(out_reg, 160, idx_pos);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZDK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=123456;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZDN_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperandNibble(8, out_reg, 160);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DNWZ_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(in_pos == pos) return 0;
	if(isRangeOver(in_reg, 160, idx_val)) return 0;
	if(isRangeOver(out_reg, in_pos, 0)) return 0;
	if(isRangeOver(out_reg, pos, 0)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandNibble(8, out_reg, in_pos); addMLOperandZIndex(in_reg, 160, idx_pos);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp2_BDK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DBKW_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos + idx_val) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in_val); addMLOperand(in_reg, in_pos);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_DBKK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;

	if( in_reg > OPERAND_ML_CODE_X ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(out_reg, pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperand(OPERAND_ML_CODE_DK, in1_val); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZDBK_WZ(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x9871068;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg < OPERAND_ML_CODE_D ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;
	if(isRangeOver(out_reg, pos, idx_val)) return 0;
	if(in_reg == out_reg && in_pos == pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandZIndex(out_reg, pos, idx_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeOp3S_WZDBK_DN(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x9871068;

	if( in_reg < OPERAND_ML_CODE_D ) return 0;
	if( out_reg > OPERAND_ML_CODE_B ) return 0;

	if(isRangeOver(in_reg, in_pos, idx_val)) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(OPERAND_ML_CODE_X, 100);
	addMLOperator(ml_cmd); addMLOperandZIndex(in_reg, in_pos, idx_pos); addMLOperand(OPERAND_ML_CODE_DK, in2_val);
		addMLOperandNibble(8, out_reg, pos);
	addMLOperator(ML_CODE_END);

	return 1;
}


void setInputOp2_val32_DWWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DWWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_DWWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DWWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=2147483647, out_val=2;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_DWWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=2147483647, out_val=2;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DWWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=-2147483647, out_val=2;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_DWWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=-2147483647, out_val=2;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DKWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DKWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_DKWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DNWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DNWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_DNWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DWZW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DWZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_DWZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_WZDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val32_WZDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val32p_WZDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_val32_DWZWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32_DWZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_val32p_DWZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=567890, out_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val32_DWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, out_val=2147483647;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val32p_DWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, out_val=2147483647;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val32_DWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, out_val=-2147483648;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp1_val32p_DWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, out_val=-2147483648;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DWW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32p_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DW_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32p_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DKW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32p_DKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DNW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32p_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DWN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val32_DWN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val32p_DWN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val32_DWZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32p_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DWZK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DWZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_val32p_DWZK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_val32_WZDN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val32_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val32p_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val32_DNWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32p_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}




void setInputOp3_val32_WZN_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val32_WZN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val32p_WZN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_val32_DNWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32p_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_WZWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32_WZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_val32p_WZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=567890, in2_val=123456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_DWWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_DWWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DWWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_DWWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x99000000, out_val=0x1654321;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DWWZ_over_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x99000000, out_val=0x1654321;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_DWWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x12345679, out_val=0x12345678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DWWZ_under_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x12345679, out_val=0x12345678;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_BDKWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_BDKWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8p_BDKWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_DNWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_DNWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}
void setInputOp2_BCD8p_DNWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_DWZW_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_DWZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DWZW_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_WZDN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_WZDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8p_WZDN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, out_pos+i, ((out_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp2_BCD8_DWZWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8_DWZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp2_BCD8p_DWZWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in_val=0x323456, out_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, out_pos+z_val, out_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DWW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DW_WWZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DW_WWZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DBKW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DBKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DBKW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WDN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_WDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_WDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWZW_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DWZW_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDBK_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDBK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_WZDBK_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int in1_val=0x323456;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDN_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_WZDN_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)out, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNWZ_WZ_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNWZ_WZ_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)in, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)out, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDN_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_WZDN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8p_WZDN_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, 160+i, ((in2_val>>i)&0x01));
	}

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DNWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	for(i=0; i<32; i++)
	{
		addDeviceControlInstruction(0, (uint8)out, in_pos+i, ((in1_val>>i)&0x01));
	}
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWZWZ_DN_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8_DWZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

void setInputOp3_BCD8p_DWZWZ_DN_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos, uint16 idx_pos, uint16 idx_val)
{
	int i, in1_val=0x323456, in2_val=0x9871068;
	short z_val;

	addDeviceControlInstruction(0, (uint8)OPERAND_ML_CODE_X, 100, 0);
	addDeviceControlInstruction(1, (uint8)OPERAND_ML_CODE_X, 100, 1);
	PLC_setWordRegister((uint8)OPERAND_ML_CODE_Z, idx_pos, idx_val);
	test_getWord(&z_val, OPERAND_ML_CODE_Z, idx_pos);
	addDeviceControlInstructionToDWord(0, (uint8)in, in_pos+z_val, in1_val);
	addDeviceControlInstructionToDWord(0, (uint8)in, 160+z_val, in2_val);

	TestCodeTearDown();
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][9]={ {0,0,0,0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096,0,6144,4096},
			{8160,8160,8160,8160,2016,8160,0,12286,8190}}; //32bit

	return pos[inx_pos][reg];
}

static 	FILE *flog;
void test_basic_arithmetic_dword_index(int tno, uint16 dummy)
{
	int i=1, inx=7, rc=0, rc2=1, olast=0;
	uint8 in=OPERAND_ML_CODE_D, out=OPERAND_ML_CODE_W;
	uint16 in_pos, out_pos;
	int res_word;
	char *reg[] = { "X", "Y", "R", "L", "F", "B", "SM", "D", "W"};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_B; out<=OPERAND_ML_CODE_D; out++)
		{
			out_pos = getPos(out, olast);
			//for(in=OPERAND_ML_CODE_B; in<=OPERAND_ML_CODE_W; in++)
			{
				//if(out==in)
				//	continue;
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					//for(inx=0; inx<15; inx++) // testidx
					{
						PLC_DEVICE_Init();

						in_pos = getPos(in, i);

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
									test_getNibble(&res_word, out, out_pos, 8);
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
									test_getDWord(&res_word, out, out_pos+testidx[inx].val);
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

void testBasicArithmeticDWordIndexCommand(void)
{
	int i, index=225;
	int start, end;
	char log[] = "err_arith_dwrd_idx.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("arithmetic dword index LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=32;index<56;index++)
	test_basic_arithmetic_dword_index(90, 0);
	//for(i=0; i<230; i++)
	//	printf("testcase %d cmd=%s \n", i, PLC_OPERATOR_DICTIONARY_findOperator(testCase[i].ml_code)->strName);
#else
	total_basic_compute_dword_idx_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_DADD); //ML_CODE_DADD
	end = getTestCaseNumberEnd(ML_CODE_DBSUBPS); //ML_CODE_DBSUBPS

	DBG_LOGPRINT("testBasicArithmeticDWordIndexCommand: %d to %d total %d\n", start, end, total_basic_compute_dword_idx_test_number);
	for(index=start; index<=end; index++)
	{
		test_basic_arithmetic_dword_index(index, 0);
	}
#endif
	fclose(flog);
}

#endif

