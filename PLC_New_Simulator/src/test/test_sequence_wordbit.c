/*
 * test_sequence_wordbit.c
 *
 *  Created on: Jun 22, 2015
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

void setCodeLDWB_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint16 bit_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDWB0_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint16 bit_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDWB1_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint16 bit_pos, uint8 out_reg, uint16 out_pos);
void setCodeLDWB_ML1(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint16 bit_pos, uint8 out_reg, uint16 out_pos);

void setInputSInWB_off(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_tr1(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_tr0(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_11(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_00(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_tr0_no(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_tr1_no(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);

void setInputSInWB_off_no(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_on_no(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_off_SOut_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_on_SOut_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_tr1_SOut_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputSInWB_tr0_SOut_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);

void setInputDInWB_00(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_01(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_10(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_11(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_tr0(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_tr0_tr1(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_off_tr1(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_off_tr0(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_on_tr1(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_on_tr0(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_on_11(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_on_00(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_off_11(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);
void setInputDInWB_off_00(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos);

static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	void (*setTestCode_fn)(uint16, uint8, uint16, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, uint8);
	char str[50];
	//int count;
	int run_step;
	int expected;

} testFn_seq_st;

static testFn_seq_st testCase[]={
	{0, ML_CODE_LD, setCodeLDWB_OUT, setInputSInWB_off, verifyResultNormal,
			"LD_OUT wordbit condition off", 1, 0 },
	{1, ML_CODE_LD, setCodeLDWB_OUT, setInputSInWB_on, verifyResultNormal,
			"LD_OUT wordbit condition on", 1, 1 },
	{2, ML_CODE_LD, setCodeLDWB_OUT, setInputSInWB_tr1, verifyResultNormal,
			"LD_OUT wordbit 0->1", 2, 1 },
	{3, ML_CODE_LD, setCodeLDWB_OUT, setInputSInWB_tr0, verifyResultNormal,
			"LD_OUT wordbit 1->0", 2, 0 },

	{4, ML_CODE_LDI, setCodeLDWB_OUT, setInputSInWB_off, verifyResultNormal,
			"LDI_OUT wordbit condition off", 1, 1 },
	{5, ML_CODE_LDI, setCodeLDWB_OUT, setInputSInWB_on, verifyResultNormal,
			"LDI_OUT wordbit condition on", 1, 0 },
	{6, ML_CODE_LDI, setCodeLDWB_OUT, setInputSInWB_tr1, verifyResultNormal,
			"LDI_OUT wordbit 0->1", 2, 0 },
	{7, ML_CODE_LDI, setCodeLDWB_OUT, setInputSInWB_tr0, verifyResultNormal,
			"LDI_OUT wordbit 1->0", 2, 1 },

	{8, ML_CODE_LDP, setCodeLDWB_OUT, setInputSInWB_off, verifyResultNormal,
			"LDP_OUT wordbit 0->0", 2, 0 },
	{9, ML_CODE_LDP, setCodeLDWB_OUT, setInputSInWB_tr1, verifyResultNormal,
			"LDP_OUT wordbit 0->1", 2, 1 },
	{10, ML_CODE_LDP, setCodeLDWB_OUT, setInputSInWB_tr0, verifyResultNormal,
			"LDP_OUT wordbit 1->0", 2, 0 },
	{11, ML_CODE_LDP, setCodeLDWB_OUT, setInputSInWB_on, verifyResultNormal,
			"LDP_OUT wordbit 1->1", 2, 0 },

	{12, ML_CODE_LDF, setCodeLDWB_OUT, setInputSInWB_off, verifyResultNormal,
			"LDF_OUT wordbit 0->0", 2, 0 },
	{13, ML_CODE_LDF, setCodeLDWB_OUT, setInputSInWB_tr1, verifyResultNormal,
			"LDF_OUT wordbit 0->1", 2, 0 },
	{14, ML_CODE_LDF, setCodeLDWB_OUT, setInputSInWB_tr0, verifyResultNormal,
			"LDF_OUT wordbit 1->0", 2, 1 },
	{15, ML_CODE_LDF, setCodeLDWB_OUT, setInputSInWB_on, verifyResultNormal,
			"LDF_OUT wordbit 1->1", 2, 0 },

	{16, ML_CODE_LDIP, setCodeLDWB_OUT, setInputSInWB_off, verifyResultNormal,
			"LDPI_OUT wordbit 0->0", 2, 1 },
	{17, ML_CODE_LDIP, setCodeLDWB_OUT, setInputSInWB_tr1, verifyResultNormal,
			"LDPI_OUT wordbit 0->1", 2, 0 },
	{18, ML_CODE_LDIP, setCodeLDWB_OUT, setInputSInWB_tr0, verifyResultNormal,
			"LDPI_OUT wordbit 1->0", 2, 1 },
	{19, ML_CODE_LDIP, setCodeLDWB_OUT, setInputSInWB_on, verifyResultNormal,
			"LDPI_OUT wordbit 1->1", 2, 1 },

	{20, ML_CODE_LDIF, setCodeLDWB_OUT, setInputSInWB_off, verifyResultNormal,
			"LDFI_OUT wordbit 0->0", 2, 1 },
	{21, ML_CODE_LDIF, setCodeLDWB_OUT, setInputSInWB_tr1, verifyResultNormal,
			"LDFI_OUT wordbit 0->1", 2, 1 },
	{22, ML_CODE_LDIF, setCodeLDWB_OUT, setInputSInWB_tr0, verifyResultNormal,
			"LDFI_OUT wordbit 1->0", 2, 0 },
	{23, ML_CODE_LDIF, setCodeLDWB_OUT, setInputSInWB_on, verifyResultNormal,
			"LDFI_OUT wordbit 1->1", 2, 1 },

	{24, ML_CODE_AND, setCodeLDWB1_OUT, setInputDInWB_00, verifyResultNormal,
			"AND_OUT wordbit 0 0", 1, 0 },
	{25, ML_CODE_AND, setCodeLDWB1_OUT, setInputDInWB_01, verifyResultNormal,
			"AND_OUT wordbit 0 1", 1, 0 },
	{26, ML_CODE_AND, setCodeLDWB1_OUT, setInputDInWB_10, verifyResultNormal,
			"AND_OUT wordbit 1 0", 1, 0 },
	{27, ML_CODE_AND, setCodeLDWB1_OUT, setInputDInWB_11, verifyResultNormal,
			"AND_OUT wordbit 1 1", 1, 1 },
	{28, ML_CODE_AND, setCodeLDWB1_OUT, setInputDInWB_tr0, verifyResultNormal,
			"AND_OUT wordbit 1 1 -> 0 0", 2, 0 },

	{29, ML_CODE_ANDI, setCodeLDWB1_OUT, setInputDInWB_00, verifyResultNormal,
			"ANDI_OUT wordbit 0 0", 1, 0 },
	{30, ML_CODE_ANDI, setCodeLDWB1_OUT, setInputDInWB_01, verifyResultNormal,
			"ANDI_OUT wordbit 0 1", 1, 0 },
	{31, ML_CODE_ANDI, setCodeLDWB1_OUT, setInputDInWB_10, verifyResultNormal,
			"ANDI_OUT wordbit 1 0", 1, 1 },
	{32, ML_CODE_ANDI, setCodeLDWB1_OUT, setInputDInWB_11, verifyResultNormal,
			"ANDI_OUT wordbit 1 1", 1, 0 },
	{33, ML_CODE_ANDI, setCodeLDWB1_OUT, setInputDInWB_on_tr0, verifyResultNormal,
			"ANDI_OUT wordbit 1 1 -> 0 0", 2, 1 },

	{34, ML_CODE_ANDP, setCodeLDWB1_OUT, setInputDInWB_off_tr1, verifyResultNormal,
			"ANDP_OUT wordbit 0 0->1", 2, 0 },
	{35, ML_CODE_ANDP, setCodeLDWB1_OUT, setInputDInWB_off_tr0, verifyResultNormal,
			"ANDP_OUT wordbit 0 1->0", 2, 0 },
	{36, ML_CODE_ANDP, setCodeLDWB1_OUT, setInputDInWB_on_tr1, verifyResultNormal,
			"ANDP_OUT wordbit 1 0->1", 2, 1 },
	{37, ML_CODE_ANDP, setCodeLDWB1_OUT, setInputDInWB_on_tr0, verifyResultNormal,
			"ANDP_OUT wordbit 1 1->0", 2, 0 },
	{38, ML_CODE_ANDP, setCodeLDWB1_OUT, setInputDInWB_on_11, verifyResultNormal,
			"ANDP_OUT wordbit 1 1->1", 2, 0 },
	{39, ML_CODE_ANDP, setCodeLDWB1_OUT, setInputDInWB_on_00, verifyResultNormal,
			"ANDP_OUT wordbit 1 0->0", 2, 0},

	{40, ML_CODE_ANDF, setCodeLDWB1_OUT, setInputDInWB_off_tr1, verifyResultNormal,
			"ANDF_OUT wordbit 0 0->1", 2, 0 },
	{41, ML_CODE_ANDF, setCodeLDWB1_OUT, setInputDInWB_off_tr0, verifyResultNormal,
			"ANDF_OUT wordbit 0 1->0", 2, 0 },
	{42, ML_CODE_ANDF, setCodeLDWB1_OUT, setInputDInWB_on_tr1, verifyResultNormal,
			"ANDF_OUT wordbit 1 0->1", 2, 0 },
	{43, ML_CODE_ANDF, setCodeLDWB1_OUT, setInputDInWB_on_tr0, verifyResultNormal,
			"ANDF_OUT wordbit 1 1->0", 2, 1 },
	{44, ML_CODE_ANDF, setCodeLDWB1_OUT, setInputDInWB_on_11, verifyResultNormal,
			"ANDF_OUT wordbit 1 1->1", 2, 0 },
	{45, ML_CODE_ANDF, setCodeLDWB1_OUT, setInputDInWB_on_00, verifyResultNormal,
			"ANDF_OUT wordbit 1 0->0", 2, 0 },

	{46, ML_CODE_ANDIP, setCodeLDWB1_OUT, setInputDInWB_off_tr1, verifyResultNormal,
			"ANDPI_OUT wordbit 0 0->1", 2, 0 },
	{47, ML_CODE_ANDIP, setCodeLDWB1_OUT, setInputDInWB_off_tr0, verifyResultNormal,
			"ANDPI_OUT wordbit 0 1->0", 2, 0 },
	{48, ML_CODE_ANDIP, setCodeLDWB1_OUT, setInputDInWB_on_tr1, verifyResultNormal,
			"ANDPI_OUT wordbit 1 0->1", 2, 0 },
	{49, ML_CODE_ANDIP, setCodeLDWB1_OUT, setInputDInWB_on_tr0, verifyResultNormal,
			"ANDPI_OUT wordbit 1 1->0", 2, 1 },
	{50, ML_CODE_ANDIP, setCodeLDWB1_OUT, setInputDInWB_on_11, verifyResultNormal,
			"ANDPI_OUT wordbit 1 1->1", 2, 1 },
	{51, ML_CODE_ANDIP, setCodeLDWB1_OUT, setInputDInWB_on_00, verifyResultNormal,
			"ANDPI_OUT wordbit 1 0->0", 2, 1 },

	{52, ML_CODE_ANDIF, setCodeLDWB1_OUT, setInputDInWB_off_tr1, verifyResultNormal,
			"ANDFI_OUT wordbit 0 0->1", 2, 0 },
	{53, ML_CODE_ANDIF, setCodeLDWB1_OUT, setInputDInWB_off_tr0, verifyResultNormal,
			"ANDFI_OUT wordbit 0 1->0", 2, 0 },
	{54, ML_CODE_ANDIF, setCodeLDWB1_OUT, setInputDInWB_on_tr1, verifyResultNormal,
			"ANDFI_OUT wordbit 1 0->1", 2, 1 },
	{55, ML_CODE_ANDIF, setCodeLDWB1_OUT, setInputDInWB_on_tr0, verifyResultNormal,
			"ANDFI_OUT wordbit 1 1->0", 2, 0 },
	{56, ML_CODE_ANDIF, setCodeLDWB1_OUT, setInputDInWB_on_11, verifyResultNormal,
			"ANDFI_OUT wordbit 1 1->1", 2, 1 },
	{57, ML_CODE_ANDIF, setCodeLDWB1_OUT, setInputDInWB_on_00, verifyResultNormal,
			"ANDFI_OUT wordbit 1 0->0", 2, 1 },

	{58, ML_CODE_OR, setCodeLDWB1_OUT, setInputDInWB_00, verifyResultNormal,
			"OR_OUT wordbit 0 0", 1, 0 },
	{59, ML_CODE_OR, setCodeLDWB1_OUT, setInputDInWB_01, verifyResultNormal,
			"OR_OUT wordbit 0 1", 1, 1 },
	{60, ML_CODE_OR, setCodeLDWB1_OUT, setInputDInWB_10, verifyResultNormal,
			"OR_OUT wordbit 1 0", 1, 1 },
	{61, ML_CODE_OR, setCodeLDWB1_OUT, setInputDInWB_11, verifyResultNormal,
			"OR_OUT wordbit 1 1", 1, 1 },
	{62, ML_CODE_OR, setCodeLDWB1_OUT, setInputDInWB_tr0, verifyResultNormal,
			"OR_OUT wordbit 1 1 -> 0 0", 2, 0 },

	{63, ML_CODE_ORI, setCodeLDWB1_OUT, setInputDInWB_00, verifyResultNormal,
			"ORI_OUT wordbit 0 0", 1, 1 },
	{64, ML_CODE_ORI, setCodeLDWB1_OUT, setInputDInWB_01, verifyResultNormal,
			"ORI_OUT wordbit 0 1", 1, 0 },
	{65, ML_CODE_ORI, setCodeLDWB1_OUT, setInputDInWB_10, verifyResultNormal,
			"ORI_OUT wordbit 1 0", 1, 1 },
	{66, ML_CODE_ORI, setCodeLDWB1_OUT, setInputDInWB_11, verifyResultNormal,
			"ORI_OUT wordbit 1 1", 1, 1 },
	{67, ML_CODE_ORI, setCodeLDWB1_OUT, setInputDInWB_tr0_tr1, verifyResultNormal,
			"ORI_OUT wordbit 1 0 -> 0 1", 2, 0},

	{68, ML_CODE_ORP, setCodeLDWB1_OUT, setInputDInWB_on_tr1, verifyResultNormal,
			"ORP_OUT wordbit 1 0->1", 2, 1 },
	{69, ML_CODE_ORP, setCodeLDWB1_OUT, setInputDInWB_on_tr0, verifyResultNormal,
			"ORP_OUT wordbit 1 1->0", 2, 1 },
	{70, ML_CODE_ORP, setCodeLDWB1_OUT, setInputDInWB_off_tr1, verifyResultNormal,
			"ORP_OUT wordbit 0 0->1", 2, 1 },
	{71, ML_CODE_ORP, setCodeLDWB1_OUT, setInputDInWB_off_tr0, verifyResultNormal,
			"ORP_OUT wordbit 0 1->0", 2, 0 },
	{72, ML_CODE_ORP, setCodeLDWB1_OUT, setInputDInWB_off_11, verifyResultNormal,
			"ORP_OUT wordbit 0 1->1", 2, 0 },
	{73, ML_CODE_ORP, setCodeLDWB1_OUT, setInputDInWB_off_00, verifyResultNormal,
			"ORP_OUT wordbit 0 0->0", 2, 0 },

	{74, ML_CODE_ORF, setCodeLDWB1_OUT, setInputDInWB_on_tr1, verifyResultNormal,
			"ORF_OUT wordbit 1 0->1", 2, 1 },
	{75, ML_CODE_ORF, setCodeLDWB1_OUT, setInputDInWB_on_tr0, verifyResultNormal,
			"ORF_OUT wordbit 1 1->0", 2, 1 },
	{76, ML_CODE_ORF, setCodeLDWB1_OUT, setInputDInWB_off_tr1, verifyResultNormal,
			"ORF_OUT wordbit 0 0->1", 2, 0 },
	{77, ML_CODE_ORF, setCodeLDWB1_OUT, setInputDInWB_off_tr0, verifyResultNormal,
			"ORF_OUT wordbit 0 1->0", 2, 1 },
	{78, ML_CODE_ORF, setCodeLDWB1_OUT, setInputDInWB_off_11, verifyResultNormal,
			"ORF_OUT wordbit 0 1->1", 2, 0 },
	{79, ML_CODE_ORF, setCodeLDWB1_OUT, setInputDInWB_off_00, verifyResultNormal,
			"ORF_OUT wordbit 0 0->0", 2, 0 },

	{80, ML_CODE_ORIP, setCodeLDWB1_OUT, setInputDInWB_on_tr1, verifyResultNormal,
			"ORPI_OUT wordbit 1 0->1", 2, 1 },
	{81, ML_CODE_ORIP, setCodeLDWB1_OUT, setInputDInWB_on_tr0, verifyResultNormal,
			"ORPI_OUT wordbit 1 1->0", 2, 1 },
	{82, ML_CODE_ORIP, setCodeLDWB1_OUT, setInputDInWB_off_tr1, verifyResultNormal,
			"ORPI_OUT wordbit 0 0->1", 2, 0 },
	{83, ML_CODE_ORIP, setCodeLDWB1_OUT, setInputDInWB_off_tr0, verifyResultNormal,
			"ORPI_OUT wordbit 0 1->0", 2, 1 },
	{84, ML_CODE_ORIP, setCodeLDWB1_OUT, setInputDInWB_off_11, verifyResultNormal,
			"ORPI_OUT wordbit 0 1->1", 2, 1 },
	{85, ML_CODE_ORIP, setCodeLDWB1_OUT, setInputDInWB_off_00, verifyResultNormal,
			"ORPI_OUT wordbit 0 0->0", 2, 1 },

	{86, ML_CODE_ORIF, setCodeLDWB1_OUT, setInputDInWB_on_tr1, verifyResultNormal,
			"ORFI_OUT wordbit 1 0->1", 2, 1 },
	{87, ML_CODE_ORIF, setCodeLDWB1_OUT, setInputDInWB_on_tr0, verifyResultNormal,
			"ORFI_OUT wordbit 1 1->0", 2, 1 },
	{88, ML_CODE_ORIF, setCodeLDWB1_OUT, setInputDInWB_off_tr1, verifyResultNormal,
			"ORFI_OUT wordbit 0 0->1", 2, 1 },
	{89, ML_CODE_ORIF, setCodeLDWB1_OUT, setInputDInWB_off_tr0, verifyResultNormal,
			"ORFI_OUT wordbit 0 1->0", 2, 0 },
	{90, ML_CODE_ORIF, setCodeLDWB1_OUT, setInputDInWB_off_11, verifyResultNormal,
			"ORFI_OUT wordbit 0 1->1", 2, 1 },
	{91, ML_CODE_ORIF, setCodeLDWB1_OUT, setInputDInWB_off_00, verifyResultNormal,
			"ORFI_OUT wordbit 0 0->0", 2, 1 },

	{92, ML_CODE_INV, setCodeLDWB0_OUT, setInputSInWB_off, verifyResultNormal,
			"INV_OUT wordbit 0", 1, 1 },
	{93, ML_CODE_INV, setCodeLDWB0_OUT, setInputSInWB_on, verifyResultNormal,
			"INV_OUT wordbit 1", 1, 0 },

	{94, ML_CODE_MEP, setCodeLDWB0_OUT, setInputSInWB_00, verifyResultNormal,
			"MEP_OUT wordbit 0->0", 2, 0 },
	{95, ML_CODE_MEP, setCodeLDWB0_OUT, setInputSInWB_tr1, verifyResultNormal,
			"MEP_OUT wordbit 0->1", 2, 1 },
	{96, ML_CODE_MEP, setCodeLDWB0_OUT, setInputSInWB_tr0, verifyResultNormal,
			"MEP_OUT wordbit 1->0", 2, 0 },
	{97, ML_CODE_MEP, setCodeLDWB0_OUT, setInputSInWB_11, verifyResultNormal,
			"MEP_OUT wordbit 1->1", 2, 0 },

	{98, ML_CODE_MEF, setCodeLDWB0_OUT, setInputSInWB_00, verifyResultNormal,
			"MEF_OUT wordbit 0->0", 2, 0 },
	{99, ML_CODE_MEF, setCodeLDWB0_OUT, setInputSInWB_tr1, verifyResultNormal,
			"MEF_OUT wordbit 0->1", 2, 0 },
	{100, ML_CODE_MEF, setCodeLDWB0_OUT, setInputSInWB_tr0, verifyResultNormal,
			"MEF_OUT wordbit 1->0", 2, 1 },
	{101, ML_CODE_MEF, setCodeLDWB0_OUT, setInputSInWB_11, verifyResultNormal,
			"MEF_OUT wordbit 1->1", 2, 0 },

	{102, ML_CODE_SET, setCodeLDWB_ML1, setInputSInWB_off_no, verifyResultNormal,
			"SET_OUT wordbit 0", 1, 0 },
	{103, ML_CODE_SET, setCodeLDWB_ML1, setInputSInWB_on_no, verifyResultNormal,
			"SET_OUT wordbit 1", 1, 1 },

	{104, ML_CODE_RST, setCodeLDWB_ML1, setInputSInWB_off_SOut_on, verifyResultNormal,
			"RST_OUT wordbit 0", 1, 1 },
	{105, ML_CODE_RST, setCodeLDWB_ML1, setInputSInWB_on_SOut_on, verifyResultNormal,
			"RST_OUT wordbit 1", 1, 0},

	{106, ML_CODE_PLS, setCodeLDWB_ML1, setInputSInWB_00, verifyResultNormal,
			"LD_PLS wordbit 0->0", 2, 0 },
	{107, ML_CODE_PLS, setCodeLDWB_ML1, setInputSInWB_tr1_no, verifyResultNormal,
			"LD_PLS wordbit 0->1", 2, 1 },
	{108, ML_CODE_PLS, setCodeLDWB_ML1, setInputSInWB_tr0_no, verifyResultNormal,
			"LD_PLS wordbit 1->0", 2, 0 },
	{109, ML_CODE_PLS, setCodeLDWB_ML1, setInputSInWB_11, verifyResultNormal,
			"LD_PLS wordbit 1->1", 2, 0 },
	{110, ML_CODE_PLS, setCodeLDWB_ML1, setInputSInWB_tr1_no, verifyResultNormal,
			"LD_PLS wordbit 0->1->1", 3, 0 }, //

	{111, ML_CODE_PLF, setCodeLDWB_ML1, setInputSInWB_00, verifyResultNormal,
			"LD_PLF wordbit 0->0", 2, 0 },
	{112, ML_CODE_PLF, setCodeLDWB_ML1, setInputSInWB_tr1_no, verifyResultNormal,
			"LD_PLF wordbit 0->1", 2, 0 },
	{113, ML_CODE_PLF, setCodeLDWB_ML1, setInputSInWB_tr0_no, verifyResultNormal,
			"LD_PLF wordbit 1->0", 2, 1 },
	{114, ML_CODE_PLF, setCodeLDWB_ML1, setInputSInWB_11, verifyResultNormal,
			"LD_PLF wordbit 1->1", 2, 0 },
	{115, ML_CODE_PLF, setCodeLDWB_ML1, setInputSInWB_tr0_no, verifyResultNormal,
			"LD_PLF wordbit 1->0->0", 3, 0 },

	{116, ML_CODE_FF, setCodeLDWB_ML1, setInputSInWB_00, verifyResultNormal,
			"LD_FF wordbit 0->0", 2, 0 },
	{117, ML_CODE_FF, setCodeLDWB_ML1, setInputSInWB_tr1_no, verifyResultNormal,
			"LD_FF wordbit 0->1", 2, 1 },
	{118, ML_CODE_FF, setCodeLDWB_ML1, setInputSInWB_tr0_no, verifyResultNormal,
			"LD_FF wordbit 1->0", 2, 0 },
	{119, ML_CODE_FF, setCodeLDWB_ML1, setInputSInWB_11, verifyResultNormal,
			"LD_FF wordbit 1->1", 2, 0 },
	{120, ML_CODE_FF, setCodeLDWB_ML1, setInputSInWB_tr1_SOut_on, verifyResultNormal,
			"LD_FF wordbit 0->1", 2, 0 },
	{121, ML_CODE_FF, setCodeLDWB_ML1, setInputSInWB_tr0_SOut_on, verifyResultNormal,
			"LD_FF wordbit 1->0", 2, 1 },


	{-1, 0xFFFF, NULL, NULL, NULL, NULL, 0, 0 }
};

int total_seq_wb_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_seq_wb_test_number; i++)
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

void setCodeLDWB_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint16 bit_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperandWordBit(in_reg, in_pos, bit_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDWB0_OUT(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint16 bit_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperandWordBit(in_reg, in_pos, bit_pos);
	addMLOperator(ml_code);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setCodeLDWB1_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint16 bit_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(in_reg, 10);
	addMLOperator(ml_cmd); addMLOperandWordBit(in_reg, in_pos, bit_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}


void setCodeLDWB_ML1(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint16 bit_pos, uint8 out_reg, uint16 out_pos)
{
	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperandWordBit(in_reg, in_pos, bit_pos);
	addMLOperator(ml_code); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);
}

void setInputSInWB_off(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 0);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 0);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_tr1(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 0);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_tr0(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 0);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_tr0_no(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, (1<<bit_pos));
	addDeviceControlInstruction(1, (uint8)in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_tr1_no(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, ~(1<<bit_pos));
	addDeviceControlInstruction(1, (uint8)in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}


void setInputSInWB_00(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_11(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_off_no(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_on_no(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_off_SOut_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 1);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_on_SOut_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 1);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_tr1_SOut_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 1);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputSInWB_tr0_SOut_on(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 1);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}


void setInputDInWB_00(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_01(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_10(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_11(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_tr0(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));
	addDeviceControlInstruction(1, in, 10, 0);
	addDeviceControlInstruction(1, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_tr0_tr1(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));
	addDeviceControlInstruction(1, in, 10, 0);
	addDeviceControlInstruction(1, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_off_tr1(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_off_tr0(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}


void setInputDInWB_on_tr1(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_on_tr0(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_on_11(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_on_00(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}


void setInputDInWB_off_11(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, (1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, (1<<bit_pos));

	TestCodeTearDown();
}

void setInputDInWB_off_00(uint8 in, uint16 in_pos, uint16 bit_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, ~(1<<bit_pos));
	addDeviceControlInstruction(1, in, in_pos, ~(1<<bit_pos));

	TestCodeTearDown();
}


static uint16 getPosWordReg(int reg, int inx_pos)
{
	uint16 pos[3][2]={ {0,0}, {6144,4096}, {12287,8191}};

	return pos[inx_pos][reg];
}

static uint16 getPos(int reg, int inx_pos)
{
	uint16 pos[3][6]={ {0,0,0,0,0,0},
			{4096,4096,4096,4096,1024,4096},
			{8191,8191,8191,8191,2047,8191}};

	return pos[inx_pos][reg];
}

static 	FILE *flog;
//normal test case
void test_sequence_wb(int tno, uint16 dummy)
{
	int i, j, rc=0, olast=0;
	uint8 in=0, out=0;
	uint8 res_bit;
	uint16 in_pos, out_pos, bit_pos[4]={0,7,8,15};
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B', 'S', 'D', 'W'};

	for(olast=0; olast<3; olast++)
	{
		for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			if(out==OPERAND_ML_CODE_F) continue; //skip F

			out_pos = getPos(out, olast);
			for(in=OPERAND_ML_CODE_D; in<=OPERAND_ML_CODE_W; in++)
			{
				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					for(j=0; j<4; j++) // bit position for word bit
					{
						PLC_DEVICE_Init();

						in_pos = getPosWordReg(in-OPERAND_ML_CODE_D, i);

						if(in == out && in_pos == out_pos)
						{
							continue;
						}

						testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, bit_pos[j], (uint8)out, out_pos);
						testCase[tno].setTestInput_fn(in, in_pos, bit_pos[j], out, out_pos);

						rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
						if(rc == 1)
						{
							CU_ASSERT_FALSE(rc); // run time failure
							fprintf(flog, "test_no[%d]: %s runtime error! in=(%d,%d,%d) out(%d,%d)\n", \
								tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
								in, in_pos, bit_pos[j], out, out_pos);
						}
						else
						{
							rc = testCase[tno].verifyResult_fn(tno, out, out_pos, testCase[tno].expected);
							if(rc == 1)
							{
								test_getBit(&res_bit, out, out_pos);
								fprintf(flog, "test case %d error cmd=%s in_%c[%d] out_%c[%d]=%d exp=%d\n", \
									tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName, \
									reg[in], in_pos, reg[out], out_pos, res_bit, testCase[tno].expected);
							}
						}
					}
				}
			}
		}
	}
}

void testSequenceWB2BRCommand(void)
{
	int i, index=0;
	int start, end;
	char log[] = "err_seq_wordbit.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("sequence wordbit LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
		test_sequence_wb(index, 0);

#else
	total_seq_wb_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LD);
	end = getTestCaseNumberEnd(ML_CODE_FF);

	DBG_LOGPRINT("testSequenceWordbit2BitRegister: %d to %d total %d\n", start, end, total_seq_wb_test_number);
	for(index=start; index<=end; index++)
	{
		test_sequence_wb(index, 0); // out register position 0
	}
#endif
	fclose(flog);
}

#endif
