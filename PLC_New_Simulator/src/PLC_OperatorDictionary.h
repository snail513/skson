/*
 * PLC_OperatorDictionary.h
 *
 *  Created on: 2014. 10. 27.
 *      Author: skson
 */

#ifndef PLC_OPERATORDICTIONARY_H_
#define PLC_OPERATORDICTIONARY_H_

#include "PLC_Operator.h"
#include "PLC_ExecFunctions.h"

PLC_Operator* PLC_OPERATOR_DICTIONARY_findOperator(uint16 mlCode);
//uint8 PLC_OPERATOR_DICTIONARY_getOperandCount(uint16 mlCode);
char* PLC_OPERATOR_DICTIONARY_getOperatorName(uint16 mlCode);
uint8 PLC_OPERATOR_getOperandMap(uint16 operatorML, uint8 operandIdx, uint8 operandML);
uint8 isValid(uint16 opt, uint8 opndPos, uint8  opnd);
void printDictionary();

#endif /* PLC_OPERATORDICTIONARY_H_ */
