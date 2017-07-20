/*
 * PLC_Point.c
 *
 *  Created on: 2015. 1. 13.
 *      Author: skson
 */


#ifndef PLC_POINT_H_
#include "PLC_Point.h"
#endif
#include "PLC_Device.h"

inline uint8 PLC_Point_isPoint(uint8 inst[],uint32* pos){
	uint16* value = (uint16*)&inst[*pos];
	return *value==ML_CODE_POINT;
}

inline uint8 PLC_Point_set(PLC_Point* point, uint8 taskIdx, uint16 label, uint32 pos, uint8 taskPriority){
	if(point==NULL)
		return FALSE;
	else
	{
		point->nLabel = label;
		point->nDevicePoint = pos;
	}
	return TRUE;
}

inline uint8 PLC_Point_init(PLC_Point* point){
	if(point==NULL)
		return FALSE;
	else
	{
		point->nLabel = 0;
		point->nDevicePoint = 0;
	}
	return TRUE;
}

inline uint16 PLC_Point_getLabel(PLC_Point* point){
	if(point==NULL)
		return 0xFFFF;
	return point->nLabel;
}

inline uint32 PLC_Point_getPoint(PLC_Point* point){
	if(point==NULL)
		return PLC_DEVICE_FALSE_32;
	return point->nDevicePoint;
}

inline uint32 PLC_Point_getPriority(PLC_Point* point)
{
	if(point==NULL)
		return PLC_DEVICE_FALSE_32;
	return point->taskPriority;
}
