/*
 * PLC_Operator.c
 *
 *  Created on: 2014. 10. 27.
 *      Author: skson
 */
#ifndef PLC_OPERATOR_H_
#include "PLC_Operator.h"
#endif

inline uint8 PLC_OPERATOR_isMyCode(PLC_Operator* this, uint16 mlCode){
	return PLC_OPERATOR_getMLCode(this)==mlCode?TRUE:FALSE;
}
