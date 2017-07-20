/*
 * PLC_PointpointTable.c
 *
 *  Created on: 2015. 1. 13.
 *      Author: skson
 */

#ifndef PLC_POINTpointTable_H_
#include "PLC_PointTable.h"
#endif
#include "PLC_Definitions.h"
#include "PLC_Device.h"

#define SIZE_LOCAL_POINT 1024
#define SIZE_GLOBAL_POINT SIZE_LOCAL_POINT

static PLC_PointTable pointTable;
static PLC_PointTable GIPTable;
//static char buf[200];

inline uint8 PLC_PointTable_addToList(uint8 taskIdx, uint32 pos, uint16 label){

	if(label>=SIZE_LOCAL_POINT+SIZE_GLOBAL_POINT)
	{
		DBG_LOGPRINT("[ERROR %s]Out of range label=%d\n", __func__, label); //hrjung
		return FALSE;
	}
	else if(label>=SIZE_LOCAL_POINT && label<SIZE_LOCAL_POINT+SIZE_GLOBAL_POINT)
	{
		label -= SIZE_LOCAL_POINT;
		return PLC_PointTable_addGIPToList(taskIdx, pos, label);
	}

	uint8 tmpTaskIdx = 0;
	uint32 tmpPoint = 0;
	if(PLC_PointTable_getPointByLabel(&tmpTaskIdx, &tmpPoint, label))
	{
		//if(tmpTaskIdx != taskIdx)
		{
			DBG_LOGPRINT("[ERROR %s]Duplicate point point %d label=%d pos=%d\n", __func__, pointTable.nPointCount, label, pos); //hrjung
			return FALSE;
		}
	}
	pointTable.pointList[pointTable.nPointCount].nLabel = taskIdx;
	pointTable.pointList[pointTable.nPointCount].nLabel = label;
	pointTable.pointList[pointTable.nPointCount].nDevicePoint = pos;
	pointTable.nPointCount++;
	//DBG_LOGPRINT("%s point %d added label=%d pos=%d\n", __func__, pointTable.nPointCount, label, pos); //hrjung
	return TRUE;
}

inline void PLC_PointTable_init(){
	memset(&pointTable, 0, sizeof(PLC_PointTable));
	memset(&GIPTable, 0, sizeof(PLC_PointTable));
}

inline void PLC_PointTable_eraseTaskPoint(uint8 taskIdx)
{
	int i;
	for( i = pointTable.nPointCount-1; i>=0; i--)
	{
		if(pointTable.pointList[i].taskIdx == taskIdx)
		{
			printf("task %d .G%d!\n", pointTable.pointList[i].taskIdx,pointTable.pointList[i].nLabel);
			if(i != pointTable.nPointCount-1)
			{
				printf("task %d .G%d erased!\n", pointTable.pointList[i].taskIdx,pointTable.pointList[i].nLabel);
				pointTable.pointList[i].nDevicePoint = pointTable.pointList[pointTable.nPointCount-1].nDevicePoint;
				pointTable.pointList[i].nLabel = pointTable.pointList[pointTable.nPointCount-1].nLabel;
				pointTable.pointList[i].taskIdx = pointTable.pointList[pointTable.nPointCount-1].taskIdx;
				pointTable.pointList[i].taskPriority = pointTable.pointList[pointTable.nPointCount-1].taskPriority;
			}
			pointTable.nPointCount--;

		}
	}
}

inline void PLC_PointTable_print(){
	DBG_LOGPRINT("=======Point table=====\n");
	int i;
	DBG_LOGPRINT("\tPoint count = %d\n",pointTable.nPointCount);
	for(i=0;i<pointTable.nPointCount;i++)
	{
		DBG_LOGPRINT("\t[%d] P%d, Point: Task%d.Point%d\n",
				i,
				pointTable.pointList[i].nLabel,
				pointTable.pointList[i].taskIdx,
				pointTable.pointList[i].nDevicePoint);
	}
	DBG_LOGPRINT("=======================\n");

	DBG_LOGPRINT("=======G.I.Point table=====\n");
	DBG_LOGPRINT("\tPoint count = %d\n",GIPTable.nPointCount);
	for(i=0;i<GIPTable.nPointCount;i++)
	{
		DBG_LOGPRINT("\t[%d] G%d, Point: Task%d.Point%d\n",
				i,
				GIPTable.pointList[i].nLabel,
				GIPTable.pointList[i].taskIdx,
				GIPTable.pointList[i].nDevicePoint);
	}
	DBG_LOGPRINT("=======================\n");
}

inline uint8 PLC_PointTable_getPointByLabel(uint8* dstIdx, uint32* dstPos, uint16 srcLabel){
	int i;
	if(srcLabel>=SIZE_LOCAL_POINT+SIZE_GLOBAL_POINT)
	{
		DBG_LOGPRINT("[ERROR %s] SrcLabel %d is out of range!\n", __FUNCTION__, srcLabel);
		return FALSE;
	}
	else if(srcLabel>=SIZE_LOCAL_POINT && srcLabel<SIZE_LOCAL_POINT+SIZE_GLOBAL_POINT)
	{
		srcLabel -= SIZE_LOCAL_POINT;
		//DBG_LOGPRINT("get global point G%d!\n", srcLabel);
		return PLC_PointTable_getGIPByLabel(dstIdx, dstPos, srcLabel);
	}
	for(i=0;i<pointTable.nPointCount; i++)
	{
		if(pointTable.pointList[i].nLabel == srcLabel)
		{
			//DBG_LOGPRINT("get local point P%d!\n", srcLabel);
			*dstIdx = pointTable.pointList[i].taskIdx;
			*dstPos = pointTable.pointList[i].nDevicePoint;
			return TRUE;
		}
	}
	//DBG_LOGPRINT("[ERROR %s] SrcLabel cannot be found!(count = %d)\n", __FUNCTION__, pointTable.nPointCount);
	return FALSE;
}

inline uint8 PLC_PointTable_addGIPToList(uint8 taskIdx, uint32 pos, uint16 label)
{
	uint8 tmpTaskIdx = 0;
	uint32 tmpPoint = 0;
	if(PLC_PointTable_getGIPByLabel(&tmpTaskIdx, &tmpPoint, label))
	{
		if(tmpTaskIdx != taskIdx)
		{
			DBG_LOGPRINT("[ERROR %s]Duplicate G-point (Task %d - Task %d [G%d])\n", __func__, taskIdx, tmpTaskIdx, label); //hrjung
			return FALSE;
		}
	}
	GIPTable.pointList[GIPTable.nPointCount].taskIdx = taskIdx;
	GIPTable.pointList[GIPTable.nPointCount].nLabel = label;
	GIPTable.pointList[GIPTable.nPointCount].nDevicePoint = pos;
	GIPTable.nPointCount++;
	//DBG_LOGPRINT("[PointTable] GIP %d [T%d P%d]added!\n", label, taskIdx, pos);
	return TRUE;
}

inline uint8 PLC_PointTable_getGIPByLabel(uint8* dstIdx, uint32* dstPos, uint16 srcLabel)
{
	int i;
	for(i=0;i<GIPTable.nPointCount; i++)
	{
		if(GIPTable.pointList[i].nLabel == srcLabel)
		{
			*dstIdx = GIPTable.pointList[i].taskIdx;
			*dstPos = GIPTable.pointList[i].nDevicePoint;
			return TRUE;
		}
	}
	return FALSE;
}
