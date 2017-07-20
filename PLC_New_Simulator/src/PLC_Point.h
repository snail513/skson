/*
 * PLC_Point.h
 *
 *  Created on: 2015. 1. 13.
 *      Author: skson
 */

#ifndef PLC_POINT_H_
#define PLC_POINT_H_
#include "PLC_Definitions.h"
#define PLC_INTERRUPTION_EVENT_FLAG_COUNT 32

typedef enum {
	EVENT_NONE=0,
	EVENT_ERROR_TYPE_1,
	EVENT_ERROR_TYPE_2,
	EVENT_ERROR_TYPE_3,
	EVENT_ERROR_TYPE_4,
	EVENT_ERROR_TYPE_5,
	EVENT_ERROR_TYPE_6,
	EVENT_ERROR_TYPE_7,
	EVENT_ERROR_TYPE_8,
	EVENT_ERROR_TYPE_9,
	EVENT_ERROR_TYPE_10,
	EVENT_ERROR_TYPE_11,
	EVENT_ERROR_TYPE_12,
	EVENT_ERROR_TYPE_13,
	EVENT_ERROR_TYPE_14,
	EVENT_ERROR_TYPE_15,
	EVENT_ERROR_TYPE_16,
	EVENT_ERROR_TYPE_17,
	EVENT_ERROR_TYPE_18,
	EVENT_ERROR_TYPE_19,
	EVENT_ERROR_TYPE_20,
	EVENT_ERROR_TYPE_21,
	EVENT_ERROR_TYPE_22,
	EVENT_ERROR_TYPE_23,
	EVENT_ERROR_TYPE_24,
	EVENT_ERROR_TYPE_25,
	EVENT_ERROR_TYPE_26,
	EVENT_ERROR_TYPE_27,
	EVENT_ERROR_TYPE_28,
	EVENT_ERROR_TYPE_29,
	EVENT_ERROR_TYPE_30,
	EVENT_ERROR_TYPE_31,
	EVENT_ERROR_TYPE_32,
}EventFlag;


typedef struct{
	uint8 taskIdx;
	uint16 nLabel;
	uint32 nDevicePoint;
	EventFlag taskPriority;
}PLC_Point;

uint8 PLC_Point_isPoint(uint8 inst[],uint32* pos);
uint8 PLC_Point_set(PLC_Point* point, uint8 taskIdx, uint16 label, uint32 pos, uint8 taskPriority);
uint8 PLC_Point_init(PLC_Point* point);
uint16 PLC_Point_getLabel(PLC_Point* point);
uint32 PLC_Point_getPoint(PLC_Point* point);
uint32 PLC_Point_getPriority(PLC_Point* point);

#endif /* PLC_POINT_H_ */
