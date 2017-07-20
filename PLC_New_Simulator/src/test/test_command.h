/*
 * test_command.h
 *
 *  Created on: Sep 4, 2015
 *      Author: hrjung
 */

#ifndef SRC_PLC_CODE_TEST_TEST_COMMAND_H_
#define SRC_PLC_CODE_TEST_TEST_COMMAND_H_

#include "../PLC_Definitions.h"


typedef struct
{
	uint16 cmd;
	int arg_cnt;
	uint8 cond;
	uint8 pulse;
/*
	uint8 op_bit;
	uint8 op_bit;
	uint8 op_word;
	uint8 op_dword;
	uint8 op_float;
	uint8 op_double;
	uint8 op_str;
	uint8 op_nb4;
	uint8 op_nb8; */
} cmdOpionts_st;


cmdOpionts_st cmdOpts[]=
{
	{ML_CODE_LD,   	1, 0, 0},
	{ML_CODE_LDI,  	1, 0, 0},
	{ML_CODE_LDP,  	1, 0, 2},
	{ML_CODE_LDF,  	1, 0, 3},
	{ML_CODE_LDIP, 	1, 0, 2},
	{ML_CODE_LDIF, 	1, 0, 3},
	{ML_CODE_AND,  	1, 1, 0},
	{ML_CODE_ANDI,	1, 1, 0},
	{ML_CODE_ANDP, 	1, 1, 2},
	{ML_CODE_ANDF, 	1, 1, 3},
	{ML_CODE_ANDIP, 1, 1, 2},
	{ML_CODE_ANDIF, 1, 1, 3},
	{ML_CODE_OR, 	1, 1, 0},
	{ML_CODE_ORI, 	1, 1, 0},
	{ML_CODE_ORP, 	1, 1, 2},
	{ML_CODE_ORF, 	1, 1, 3},
	{ML_CODE_ORIP, 	1, 1, 2},
	{ML_CODE_ORIF, 	1, 1, 3},
	{ML_CODE_OUT, 	1, 1, 0},
	{ML_CODE_SET, 	1, 1, 0},
	{ML_CODE_RST, 	1, 1, 0},
	{ML_CODE_PLS, 	1, 1, 2},
	{ML_CODE_PLF, 	1, 1, 3},
	{ML_CODE_FF, 	1, 1, 2},
	{ML_CODE_SFT, 	1, 1, 0},
	{ML_CODE_SFTP, 	1, 1, 2},
};



#endif /* SRC_PLC_CODE_TEST_TEST_COMMAND_H_ */
