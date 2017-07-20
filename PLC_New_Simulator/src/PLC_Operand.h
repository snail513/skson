/*
 * PLC_Operand.h
 *
 *  Created on: 2014. 10. 27.
 *      Author: skson
 */

#ifndef PLC_OPERAND_H_
#define PLC_OPERAND_H_
#include "PLC_Definitions.h"

typedef struct {
	char* strType;
	uint16 nAddressCount;
	uint8 bIsConstant;
	uint8 nBitSize;
	uint16 nMLCode;

} PLC_Operand;


#define PLC_OPERAND_getStrType(this) (this->strType)
#define PLC_OPERAND_getAddressCount(this) (this->nAddressCount)
#define PLC_OPERAND_IsConstant(this) (this->bIsConstant)
#define PLC_OPERAND_getBitSize(this) (this->nBitSize)
#define PLC_OPERAND_getMLCode(this) (this->nMLCode)

uint8 PLC_OPERAND_isMyType(PLC_Operand* this, uint16 typeCode);

uint8 PLC_OPERAND_isValid(PLC_Operand* this, uint16 valueCode);
#endif /* PLC_OPERAND_H_ */
