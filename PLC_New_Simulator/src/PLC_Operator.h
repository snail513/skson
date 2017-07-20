/*
 * PLC_Operator.h
 *
 *  Created on: 2014. 10. 27.
 *      Author: skson
 */

#ifndef PLC_OPERATOR_H_
#define PLC_OPERATOR_H_
#include "PLC_OperandDictionary.h"

#define MAX_OPERAND_COUNT 5

#define OPERATOR_STEP_PART_START 0
#define OPERATOR_STEP_PART_CONT 1
#define OPERATOR_STEP_PART_FINISH 2
#define OPERATOR_STEP_PART_WHOLE 3


typedef struct{
	char* strName;
	uint16 nMLCode;
	uint8 nOperandPosCount;
	void* pExecfunction;
	uint8 nStatus;
}PLC_Operator;

#define PLC_OPERATOR_getStrName(this) this->strName
#define PLC_OPERATOR_getMLCode(this) this->nMLCode
#define PLC_OPERATOR_getExecFunctions(this) this->pExecFunctions

uint8 PLC_OPERATOR_isMyCode(PLC_Operator* this, uint16 mlCode);

#endif /* PLC_OPERATOR_H_ */
