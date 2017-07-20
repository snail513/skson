/*
 * test_sequence_cmd.c
 *
 *  Created on: Jan 29, 2015
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

int setCodeML1_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_ML1_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_ML0_OUT(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);
int setCodeLD_ML1(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos);

void setInputSIn_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_tr0(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_00(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_11(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_00(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_01(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_10(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_11(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_tr0(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_tr0_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_off_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_tr0(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_11(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_off_00(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputDIn_on_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_tr0(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_11(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_on_00(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputDIn_tr0_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);

void setInputSIn_off_SOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_on_SOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_tr1_SOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);
void setInputSIn_tr0_SOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos);


int verifyResultNormal(int tcase, uint8 dest_reg, uint16 pos, uint8 expected);

static int show_log=1;

typedef struct
{
	int 	no;
	uint16 ml_code;
	int (*setTestCode_fn)(uint16, uint8, uint16, uint8, uint16);
	void (*setTestInput_fn)(uint8, uint16, uint8, uint16);
	int (*verifyResult_fn)(int, uint8, uint16, uint8);
	char str[40];
	//int count;
	int run_step;
	int expected;

} testFn_seq_st;

static testFn_seq_st testCase[]={
	{0, ML_CODE_LD, setCodeML1_OUT, setInputSIn_off, verifyResultNormal,
			"LD_OUT off", 1, 0 },
	{1, ML_CODE_LD, setCodeML1_OUT, setInputSIn_on, verifyResultNormal,
			"LD_OUT on", 1, 1 },
	{2, ML_CODE_LD, setCodeML1_OUT, setInputSIn_tr0, verifyResultNormal,
			"LD_OUT 1->0", 2, 0 },
	{3, ML_CODE_LD, setCodeML1_OUT, setInputSIn_tr1, verifyResultNormal,
			"LD_OUT 0->1", 2, 1 },

	{4, ML_CODE_LDI, setCodeML1_OUT, setInputSIn_off, verifyResultNormal,
			"LDI_OUT off", 1, 1 },
	{5, ML_CODE_LDI, setCodeML1_OUT, setInputSIn_on, verifyResultNormal,
			"LDI_OUT on", 1, 0 },
	{6, ML_CODE_LDI, setCodeML1_OUT, setInputSIn_tr0, verifyResultNormal,
			"LDI_OUT 1->0", 2, 1 },
	{7, ML_CODE_LDI, setCodeML1_OUT, setInputSIn_tr1, verifyResultNormal,
			"LDI_OUT 0->1", 2, 0 },

	{8, ML_CODE_LDP, setCodeML1_OUT, setInputSIn_00, verifyResultNormal,
			"LDP_OUT 0->0", 2, 0 },
	{9, ML_CODE_LDP, setCodeML1_OUT, setInputSIn_tr1, verifyResultNormal,
			"LDP_OUT 0->1", 2, 1 },
	{10, ML_CODE_LDP, setCodeML1_OUT, setInputSIn_tr0, verifyResultNormal,
			"LDP_OUT 1->0", 2, 0 },
	{11, ML_CODE_LDP, setCodeML1_OUT, setInputSIn_11, verifyResultNormal,
			"LDP_OUT 1->1", 2, 0 },

	{12, ML_CODE_LDF, setCodeML1_OUT, setInputSIn_00, verifyResultNormal,
			"LDF_OUT 0->0", 2, 0 },
	{13, ML_CODE_LDF, setCodeML1_OUT, setInputSIn_tr1, verifyResultNormal,
			"LDF_OUT 0->1", 2, 0 },
	{14, ML_CODE_LDF, setCodeML1_OUT, setInputSIn_tr0, verifyResultNormal,
			"LDF_OUT 1->0", 2, 1 },
	{15, ML_CODE_LDF, setCodeML1_OUT, setInputSIn_11, verifyResultNormal,
			"LDF_OUT 1->1", 2, 0 },

	{16, ML_CODE_LDIP, setCodeML1_OUT, setInputSIn_00, verifyResultNormal,
			"LDPI_OUT 0->0", 2, 1 },
	{17, ML_CODE_LDIP, setCodeML1_OUT, setInputSIn_tr1, verifyResultNormal,
			"LDPI_OUT 0->1", 2, 0 },
	{18, ML_CODE_LDIP, setCodeML1_OUT, setInputSIn_tr0, verifyResultNormal,
			"LDPI_OUT 1->0", 2, 1 },
	{19, ML_CODE_LDIP, setCodeML1_OUT, setInputSIn_11, verifyResultNormal,
			"LDPI_OUT 1->1", 2, 1 },

	{20, ML_CODE_LDIF, setCodeML1_OUT, setInputSIn_00, verifyResultNormal,
			"LDFI_OUT 0->0", 2, 1 },
	{21, ML_CODE_LDIF, setCodeML1_OUT, setInputSIn_tr1, verifyResultNormal,
			"LDFI_OUT 0->1", 2, 1 },
	{22, ML_CODE_LDIF, setCodeML1_OUT, setInputSIn_tr0, verifyResultNormal,
			"LDFI_OUT 1->0", 2, 0 },
	{23, ML_CODE_LDIF, setCodeML1_OUT, setInputSIn_11, verifyResultNormal,
			"LDFI_OUT 1->1", 2, 1 },

	{24, ML_CODE_AND, setCodeLD_ML1_OUT, setInputDIn_00, verifyResultNormal,
			"AND_OUT 0 0", 1, 0 },
	{25, ML_CODE_AND, setCodeLD_ML1_OUT, setInputDIn_01, verifyResultNormal,
			"AND_OUT 0 1", 1, 0 },
	{26, ML_CODE_AND, setCodeLD_ML1_OUT, setInputDIn_10, verifyResultNormal,
			"AND_OUT 1 0", 1, 0 },
	{27, ML_CODE_AND, setCodeLD_ML1_OUT, setInputDIn_11, verifyResultNormal,
			"AND_OUT 1 1", 1, 1 },
	{28, ML_CODE_AND, setCodeLD_ML1_OUT, setInputDIn_tr0, verifyResultNormal,
			"AND_OUT 1 1 -> 0 0", 2, 0 },

	{29, ML_CODE_ANDI, setCodeLD_ML1_OUT, setInputDIn_00, verifyResultNormal,
			"ANDI_OUT 0 0", 1, 0 },
	{30, ML_CODE_ANDI, setCodeLD_ML1_OUT, setInputDIn_01, verifyResultNormal,
			"ANDI_OUT 0 1", 1, 0 },
	{31, ML_CODE_ANDI, setCodeLD_ML1_OUT, setInputDIn_10, verifyResultNormal,
			"ANDI_OUT 1 0", 1, 1 },
	{32, ML_CODE_ANDI, setCodeLD_ML1_OUT, setInputDIn_11, verifyResultNormal,
			"ANDI_OUT 1 1", 1, 0 },
	{33, ML_CODE_ANDI, setCodeLD_ML1_OUT, setInputDIn_tr0_on, verifyResultNormal,
			"ANDI_OUT 1 1 -> 0 0", 2, 1 },

	{34, ML_CODE_ANDP, setCodeLD_ML1_OUT, setInputDIn_off_tr1, verifyResultNormal,
			"ANDP_OUT 0 0->1", 2, 0 },
	{35, ML_CODE_ANDP, setCodeLD_ML1_OUT, setInputDIn_off_tr0, verifyResultNormal,
			"ANDP_OUT 0 1->0", 2, 0 },
	{36, ML_CODE_ANDP, setCodeLD_ML1_OUT, setInputDIn_on_tr1, verifyResultNormal,
			"ANDP_OUT 1 0->1", 2, 1 },
	{37, ML_CODE_ANDP, setCodeLD_ML1_OUT, setInputDIn_on_tr0, verifyResultNormal,
			"ANDP_OUT 1 1->0", 2, 0 },
	{38, ML_CODE_ANDP, setCodeLD_ML1_OUT, setInputDIn_on_11, verifyResultNormal,
			"ANDP_OUT 1 1->1", 2, 0 },
	{39, ML_CODE_ANDP, setCodeLD_ML1_OUT, setInputDIn_on_00, verifyResultNormal,
			"ANDP_OUT 1 0->0", 2, 0},

	{40, ML_CODE_ANDF, setCodeLD_ML1_OUT, setInputDIn_off_tr1, verifyResultNormal,
			"ANDF_OUT 0 0->1", 2, 0 },
	{41, ML_CODE_ANDF, setCodeLD_ML1_OUT, setInputDIn_off_tr0, verifyResultNormal,
			"ANDF_OUT 0 1->0", 2, 0 },
	{42, ML_CODE_ANDF, setCodeLD_ML1_OUT, setInputDIn_on_tr1, verifyResultNormal,
			"ANDF_OUT 1 0->1", 2, 0 },
	{43, ML_CODE_ANDF, setCodeLD_ML1_OUT, setInputDIn_on_tr0, verifyResultNormal,
			"ANDF_OUT 1 1->0", 2, 1 },
	{44, ML_CODE_ANDF, setCodeLD_ML1_OUT, setInputDIn_on_11, verifyResultNormal,
			"ANDF_OUT 1 1->1", 2, 0 },
	{45, ML_CODE_ANDF, setCodeLD_ML1_OUT, setInputDIn_on_00, verifyResultNormal,
			"ANDF_OUT 1 0->0", 2, 0 },

	{46, ML_CODE_ANDIP, setCodeLD_ML1_OUT, setInputDIn_off_tr1, verifyResultNormal,
			"ANDPI_OUT 0 0->1", 2, 0 },
	{47, ML_CODE_ANDIP, setCodeLD_ML1_OUT, setInputDIn_off_tr0, verifyResultNormal,
			"ANDPI_OUT 0 1->0", 2, 0 },
	{48, ML_CODE_ANDIP, setCodeLD_ML1_OUT, setInputDIn_on_tr1, verifyResultNormal,
			"ANDPI_OUT 1 0->1", 2, 0 },
	{49, ML_CODE_ANDIP, setCodeLD_ML1_OUT, setInputDIn_on_tr0, verifyResultNormal,
			"ANDPI_OUT 1 1->0", 2, 1 },
	{50, ML_CODE_ANDIP, setCodeLD_ML1_OUT, setInputDIn_on_11, verifyResultNormal,
			"ANDPI_OUT 1 1->1", 2, 1 },
	{51, ML_CODE_ANDIP, setCodeLD_ML1_OUT, setInputDIn_on_00, verifyResultNormal,
			"ANDPI_OUT 1 0->0", 2, 1 },

	{52, ML_CODE_ANDIF, setCodeLD_ML1_OUT, setInputDIn_off_tr1, verifyResultNormal,
			"ANDFI_OUT 0 0->1", 2, 0 },
	{53, ML_CODE_ANDIF, setCodeLD_ML1_OUT, setInputDIn_off_tr0, verifyResultNormal,
			"ANDFI_OUT 0 1->0", 2, 0 },
	{54, ML_CODE_ANDIF, setCodeLD_ML1_OUT, setInputDIn_on_tr1, verifyResultNormal,
			"ANDFI_OUT 1 0->1", 2, 1 },
	{55, ML_CODE_ANDIF, setCodeLD_ML1_OUT, setInputDIn_on_tr0, verifyResultNormal,
			"ANDFI_OUT 1 1->0", 2, 0 },
	{56, ML_CODE_ANDIF, setCodeLD_ML1_OUT, setInputDIn_on_11, verifyResultNormal,
			"ANDFI_OUT 1 1->1", 2, 1 },
	{57, ML_CODE_ANDIF, setCodeLD_ML1_OUT, setInputDIn_on_00, verifyResultNormal,
			"ANDFI_OUT 1 0->0", 2, 1 },

	{58, ML_CODE_OR, setCodeLD_ML1_OUT, setInputDIn_00, verifyResultNormal,
			"OR_OUT 0 0", 1, 0 },
	{59, ML_CODE_OR, setCodeLD_ML1_OUT, setInputDIn_01, verifyResultNormal,
			"OR_OUT 0 1", 1, 1 },
	{60, ML_CODE_OR, setCodeLD_ML1_OUT, setInputDIn_10, verifyResultNormal,
			"OR_OUT 1 0", 1, 1 },
	{61, ML_CODE_OR, setCodeLD_ML1_OUT, setInputDIn_11, verifyResultNormal,
			"OR_OUT 1 1", 1, 1 },
	{62, ML_CODE_OR, setCodeLD_ML1_OUT, setInputDIn_tr0, verifyResultNormal,
			"OR_OUT 1 1 -> 0 0", 2, 0 },

	{63, ML_CODE_ORI, setCodeLD_ML1_OUT, setInputDIn_00, verifyResultNormal,
			"ORI_OUT 0 0", 1, 1 },
	{64, ML_CODE_ORI, setCodeLD_ML1_OUT, setInputDIn_01, verifyResultNormal,
			"ORI_OUT 0 1", 1, 0 },
	{65, ML_CODE_ORI, setCodeLD_ML1_OUT, setInputDIn_10, verifyResultNormal,
			"ORI_OUT 1 0", 1, 1 },
	{66, ML_CODE_ORI, setCodeLD_ML1_OUT, setInputDIn_11, verifyResultNormal,
			"ORI_OUT 1 1", 1, 1 },
	{67, ML_CODE_ORI, setCodeLD_ML1_OUT, setInputDIn_tr0_tr1, verifyResultNormal,
			"ORI_OUT 1 0 -> 0 1", 2, 0},

	{68, ML_CODE_ORP, setCodeLD_ML1_OUT, setInputDIn_on_tr1, verifyResultNormal,
			"ORP_OUT 1 0->1", 2, 1 },
	{69, ML_CODE_ORP, setCodeLD_ML1_OUT, setInputDIn_on_tr0, verifyResultNormal,
			"ORP_OUT 1 1->0", 2, 1 },
	{70, ML_CODE_ORP, setCodeLD_ML1_OUT, setInputDIn_off_tr1, verifyResultNormal,
			"ORP_OUT 0 0->1", 2, 1 },
	{71, ML_CODE_ORP, setCodeLD_ML1_OUT, setInputDIn_off_tr0, verifyResultNormal,
			"ORP_OUT 0 1->0", 2, 0 },
	{72, ML_CODE_ORP, setCodeLD_ML1_OUT, setInputDIn_off_11, verifyResultNormal,
			"ORP_OUT 0 1->1", 2, 0 },
	{73, ML_CODE_ORP, setCodeLD_ML1_OUT, setInputDIn_off_00, verifyResultNormal,
			"ORP_OUT 0 0->0", 2, 0 },

	{74, ML_CODE_ORF, setCodeLD_ML1_OUT, setInputDIn_on_tr1, verifyResultNormal,
			"ORF_OUT 1 0->1", 2, 1 },
	{75, ML_CODE_ORF, setCodeLD_ML1_OUT, setInputDIn_on_tr0, verifyResultNormal,
			"ORF_OUT 1 1->0", 2, 1 },
	{76, ML_CODE_ORF, setCodeLD_ML1_OUT, setInputDIn_off_tr1, verifyResultNormal,
			"ORF_OUT 0 0->1", 2, 0 },
	{77, ML_CODE_ORF, setCodeLD_ML1_OUT, setInputDIn_off_tr0, verifyResultNormal,
			"ORF_OUT 0 1->0", 2, 1 },
	{78, ML_CODE_ORF, setCodeLD_ML1_OUT, setInputDIn_off_11, verifyResultNormal,
			"ORF_OUT 0 1->1", 2, 0 },
	{79, ML_CODE_ORF, setCodeLD_ML1_OUT, setInputDIn_off_00, verifyResultNormal,
			"ORF_OUT 0 0->0", 2, 0 },

	{80, ML_CODE_ORIP, setCodeLD_ML1_OUT, setInputDIn_on_tr1, verifyResultNormal,
			"ORPI_OUT 1 0->1", 2, 1 },
	{81, ML_CODE_ORIP, setCodeLD_ML1_OUT, setInputDIn_on_tr0, verifyResultNormal,
			"ORPI_OUT 1 1->0", 2, 1 },
	{82, ML_CODE_ORIP, setCodeLD_ML1_OUT, setInputDIn_off_tr1, verifyResultNormal,
			"ORPI_OUT 0 0->1", 2, 0 },
	{83, ML_CODE_ORIP, setCodeLD_ML1_OUT, setInputDIn_off_tr0, verifyResultNormal,
			"ORPI_OUT 0 1->0", 2, 1 },
	{84, ML_CODE_ORIP, setCodeLD_ML1_OUT, setInputDIn_off_11, verifyResultNormal,
			"ORPI_OUT 0 1->1", 2, 1 },
	{85, ML_CODE_ORIP, setCodeLD_ML1_OUT, setInputDIn_off_00, verifyResultNormal,
			"ORPI_OUT 0 0->0", 2, 1 },

	{86, ML_CODE_ORIF, setCodeLD_ML1_OUT, setInputDIn_on_tr1, verifyResultNormal,
			"ORFI_OUT 1 0->1", 2, 1 },
	{87, ML_CODE_ORIF, setCodeLD_ML1_OUT, setInputDIn_on_tr0, verifyResultNormal,
			"ORFI_OUT 1 1->0", 2, 1 },
	{88, ML_CODE_ORIF, setCodeLD_ML1_OUT, setInputDIn_off_tr1, verifyResultNormal,
			"ORFI_OUT 0 0->1", 2, 1 },
	{89, ML_CODE_ORIF, setCodeLD_ML1_OUT, setInputDIn_off_tr0, verifyResultNormal,
			"ORFI_OUT 0 1->0", 2, 0 },
	{90, ML_CODE_ORIF, setCodeLD_ML1_OUT, setInputDIn_off_11, verifyResultNormal,
			"ORFI_OUT 0 1->1", 2, 1 },
	{91, ML_CODE_ORIF, setCodeLD_ML1_OUT, setInputDIn_off_00, verifyResultNormal,
			"ORFI_OUT 0 0->0", 2, 1 },

	{92, ML_CODE_INV, setCodeLD_ML0_OUT, setInputSIn_off, verifyResultNormal,
			"INV_OUT 0", 1, 1 },
	{93, ML_CODE_INV, setCodeLD_ML0_OUT, setInputSIn_on, verifyResultNormal,
			"INV_OUT 1", 1, 0 },

	{94, ML_CODE_MEP, setCodeLD_ML0_OUT, setInputSIn_00, verifyResultNormal,
			"MEP_OUT 0->0", 2, 0 },
	{95, ML_CODE_MEP, setCodeLD_ML0_OUT, setInputSIn_tr1, verifyResultNormal,
			"MEP_OUT 0->1", 2, 1 },
	{96, ML_CODE_MEP, setCodeLD_ML0_OUT, setInputSIn_tr0, verifyResultNormal,
			"MEP_OUT 1->0", 2, 0 },
	{97, ML_CODE_MEP, setCodeLD_ML0_OUT, setInputSIn_11, verifyResultNormal,
			"MEP_OUT 1->1", 2, 0 },

	{98, ML_CODE_MEF, setCodeLD_ML0_OUT, setInputSIn_00, verifyResultNormal,
			"MEF_OUT 0->0", 2, 0 },
	{99, ML_CODE_MEF, setCodeLD_ML0_OUT, setInputSIn_tr1, verifyResultNormal,
			"MEF_OUT 0->1", 2, 0 },
	{100, ML_CODE_MEF, setCodeLD_ML0_OUT, setInputSIn_tr0, verifyResultNormal,
			"MEF_OUT 1->0", 2, 1 },
	{101, ML_CODE_MEF, setCodeLD_ML0_OUT, setInputSIn_11, verifyResultNormal,
			"MEF_OUT 1->1", 2, 0 },

	{102, ML_CODE_SET, setCodeLD_ML1, setInputSIn_off, verifyResultNormal,
			"SET_OUT 0", 1, 0 },
	{103, ML_CODE_SET, setCodeLD_ML1, setInputSIn_on, verifyResultNormal,
			"SET_OUT 1", 1, 1 },

	{104, ML_CODE_RST, setCodeLD_ML1, setInputSIn_off_SOut_on, verifyResultNormal,
			"RST_OUT 0", 1, 1 },
	{105, ML_CODE_RST, setCodeLD_ML1, setInputSIn_on_SOut_on, verifyResultNormal,
			"RST_OUT 1", 1, 0},

	{106, ML_CODE_PLS, setCodeLD_ML1, setInputSIn_00, verifyResultNormal,
			"LD_PLS 0->0", 2, 0 },
	{107, ML_CODE_PLS, setCodeLD_ML1, setInputSIn_tr1, verifyResultNormal,
			"LD_PLS 0->1", 2, 1 },
	{108, ML_CODE_PLS, setCodeLD_ML1, setInputSIn_tr0, verifyResultNormal,
			"LD_PLS 1->0", 2, 0 },
	{109, ML_CODE_PLS, setCodeLD_ML1, setInputSIn_11, verifyResultNormal,
			"LD_PLS 1->1", 2, 0 },
	{110, ML_CODE_PLS, setCodeLD_ML1, setInputSIn_tr1, verifyResultNormal,
			"LD_PLS 0->1->1", 3, 0 }, //

	{111, ML_CODE_PLF, setCodeLD_ML1, setInputSIn_00, verifyResultNormal,
			"LD_PLF 0->0", 2, 0 },
	{112, ML_CODE_PLF, setCodeLD_ML1, setInputSIn_tr1, verifyResultNormal,
			"LD_PLF 0->1", 2, 0 },
	{113, ML_CODE_PLF, setCodeLD_ML1, setInputSIn_tr0, verifyResultNormal,
			"LD_PLF 1->0", 2, 1 },
	{114, ML_CODE_PLF, setCodeLD_ML1, setInputSIn_11, verifyResultNormal,
			"LD_PLF 1->1", 2, 0 },
	{115, ML_CODE_PLF, setCodeLD_ML1, setInputSIn_tr0, verifyResultNormal,
			"LD_PLF 1->0->0", 3, 0 },

	{116, ML_CODE_FF, setCodeLD_ML1, setInputSIn_00, verifyResultNormal,
			"LD_FF 0->0", 2, 0 },
	{117, ML_CODE_FF, setCodeLD_ML1, setInputSIn_tr1, verifyResultNormal,
			"LD_FF 0->1", 2, 1 },
	{118, ML_CODE_FF, setCodeLD_ML1, setInputSIn_tr0, verifyResultNormal,
			"LD_FF 1->0", 2, 0 },
	{119, ML_CODE_FF, setCodeLD_ML1, setInputSIn_11, verifyResultNormal,
			"LD_FF 1->1", 2, 0 },
	{120, ML_CODE_FF, setCodeLD_ML1, setInputSIn_tr1_SOut_on, verifyResultNormal,
			"LD_FF 0->1", 2, 0 },
	{121, ML_CODE_FF, setCodeLD_ML1, setInputSIn_tr0_SOut_on, verifyResultNormal,
			"LD_FF 1->0", 2, 1 },

	{-1, 0xFFFF, NULL, NULL, NULL, "", 0, 0 }
};

int total_seq_test_number=0;
static int getTotalTestCaseNumber(void)
{
	int i=0;

	while(testCase[i++].no != -1);

	return i-1;
}

static int getTestCaseNumber(uint16 ml_code)
{
	int i;

	for(i=0; i<total_seq_test_number; i++)
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

//
//	LD, LDI - OUT test
//
int setCodeML1_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_ML1_OUT(uint16 ml_cmd, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(in_reg, 10);
	addMLOperator(ml_cmd); addMLOperand(in_reg, in_pos);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_ML0_OUT(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(in_reg, in_pos);
	addMLOperator(ml_code);
	addMLOperator(ML_CODE_OUT); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

int setCodeLD_ML1(uint16 ml_code, uint8 in_reg, uint16 in_pos, uint8 out_reg, uint16 out_pos)
{
	if(in_reg == out_reg && in_pos == out_pos) return 0;

	TestCodeInit();

	addMLOperator(ML_CODE_LD); addMLOperand(in_reg, in_pos);
	addMLOperator(ml_code); addMLOperand(out_reg, out_pos);
	addMLOperator(ML_CODE_END);

	return 1;
}

void setInputSIn_off(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0);

	TestCodeTearDown();
}

void setInputSIn_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1);

	TestCodeTearDown();
}

void setInputSIn_tr0(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 1); // 10
	addDeviceControlInstruction(1, (uint8)in, in_pos, 0);

	TestCodeTearDown();
}

void setInputSIn_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, (uint8)in, in_pos, 0); // 10
	addDeviceControlInstruction(1, (uint8)in, in_pos, 1);

	TestCodeTearDown();
}


void setInputSIn_00(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, in_pos, 0);
	addDeviceControlInstruction(1, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputSIn_11(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, in_pos, 1);
	addDeviceControlInstruction(1, in, in_pos, 1);

	TestCodeTearDown();
}

void setInputDIn_00(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputDIn_01(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, 1);

	TestCodeTearDown();
}

void setInputDIn_10(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputDIn_11(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, 1);

	TestCodeTearDown();
}

void setInputDIn_tr0(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, 1);
	addDeviceControlInstruction(1, in, 10, 0);
	addDeviceControlInstruction(1, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputDIn_tr0_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, 0);
	addDeviceControlInstruction(1, in, 10, 0);
	addDeviceControlInstruction(1, in, in_pos, 1);

	TestCodeTearDown();
}

void setInputDIn_tr0_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, 1);
	addDeviceControlInstruction(1, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputDIn_off_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, 0);
	addDeviceControlInstruction(1, in, in_pos, 1);

	TestCodeTearDown();
}

void setInputDIn_off_tr0(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, 1);
	addDeviceControlInstruction(1, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputDIn_off_11(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, 1);
	addDeviceControlInstruction(1, in, in_pos, 1);

	TestCodeTearDown();
}

void setInputDIn_off_00(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 0);
	addDeviceControlInstruction(0, in, in_pos, 0);
	addDeviceControlInstruction(1, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputDIn_on_tr1(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, 0);
	addDeviceControlInstruction(1, in, in_pos, 1);

	TestCodeTearDown();
}

void setInputDIn_on_tr0(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, 1);
	addDeviceControlInstruction(1, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputDIn_on_11(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, 1);
	addDeviceControlInstruction(1, in, in_pos, 1);

	TestCodeTearDown();
}

void setInputDIn_on_00(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, in, 10, 1);
	addDeviceControlInstruction(0, in, in_pos, 0);
	addDeviceControlInstruction(1, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputSIn_off_SOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 1);
	addDeviceControlInstruction(0, in, in_pos, 0);

	TestCodeTearDown();
}

void setInputSIn_on_SOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 1);
	addDeviceControlInstruction(0, in, in_pos, 1);

	TestCodeTearDown();
}


void setInputSIn_tr1_SOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 1);
	addDeviceControlInstruction(0, in, in_pos, 0);
	addDeviceControlInstruction(1, in, in_pos, 1);

	TestCodeTearDown();
}

void setInputSIn_tr0_SOut_on(uint8 in, uint16 in_pos, uint8 out, uint16 out_pos)
{
	addDeviceControlInstruction(0, out, out_pos, 1);
	addDeviceControlInstruction(0, in, in_pos, 1);
	addDeviceControlInstruction(1, in, in_pos, 0);

	TestCodeTearDown();
}


int verifyResultNormal(int tcase, uint8 dest_reg, uint16 pos, uint8 expected)
{
	int rc=0;
	uint8 result;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};

	if(!test_getBit(&result, dest_reg, pos))
		return 1;
	if( show_log ) DBG_LOGPRINT("test=%d bit %c[%d]=%d %d\n", tcase, reg[dest_reg], pos, result, expected);
	CU_ASSERT_EQUAL(result, expected);
	if(result != expected) rc=1;

	return rc;
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
void test_sequence(int tno, uint16 dummy)
{
	int i, rc=0, olast=0;
	uint16 in_pos, out_pos;
	uint8 in=OPERAND_ML_CODE_X, out=OPERAND_ML_CODE_Y, res_bit;
	char reg[] = { 'X', 'Y', 'R', 'L', 'F', 'B'};

	//for(olast=0; olast<3; olast++)
	{
		//for(out=OPERAND_ML_CODE_X; out<=OPERAND_ML_CODE_B; out++)
		{
			//if(out==OPERAND_ML_CODE_F) continue; //skip F

			out_pos = getPos(out, olast);
			//for(in=OPERAND_ML_CODE_X; in<=OPERAND_ML_CODE_B; in++)
			{
				//if(in==OPERAND_ML_CODE_F) continue; //skip F

				for(i=0; i<3 ; i++ ) // input register position, 0, center, last
				{
					PLC_DEVICE_Init();

					in_pos = getPos(in, i);

					rc=testCase[tno].setTestCode_fn(testCase[tno].ml_code, (uint8)in, in_pos, (uint8)out, out_pos);
					if(rc==0) continue;

					testCase[tno].setTestInput_fn(in, in_pos, out, out_pos);

					rc = runTestCode(testCase[tno].run_step, testCase[tno].str);
					if(rc == 1)
					{
						CU_ASSERT_FALSE(rc); // run time failure
						fprintf(flog, "test_no[%d]: %s runtime error!\n", \
							tno, PLC_OPERATOR_DICTIONARY_findOperator(testCase[tno].ml_code)->strName);
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

void testSequenceCommand(void)
{
	int i, index=0;
	int start, end;
	char log[] = "err_log_sequence.txt";

	flog = fopen(log, "w+t");
	if(flog == NULL)
	{
		DBG_LOGPRINT("sequence LOG file open error !\n");
		exit(1);
	}
#if 0
	//for(index=0; index<10; index++)
		test_sequence(index, 0);

#else
	total_seq_test_number = getTotalTestCaseNumber();
	start = getTestCaseNumber(ML_CODE_LD);
	end = getTestCaseNumberEnd(ML_CODE_FF);

	DBG_LOGPRINT("testSequenceCommand: %d to %d total %d\n", start, end, total_seq_test_number);
	for(index=start; index<=end; index++)
	{
		test_sequence(index, 0);
	}
#endif
	fclose(flog);
}

#endif
