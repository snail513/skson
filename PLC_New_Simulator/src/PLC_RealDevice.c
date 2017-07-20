/*
 * PLC_RealDevice.c
 *
 *  Created on: 2016. 1. 29.
 *      Author: skson
 */
#ifndef PLC_REALDEVICE_H_
#include "PLC_RealDevice.h"
#include "PLC_OperandDictionary.h"
#endif
static uint8 realDevice[REAL_DEV_SIZE];

static uint8 realDeviceTarget[REAL_DEV_SIZE];//block this code!
//static uint8* realDeviceTarget = NULL;//block this code!

inline uint8* PLC_RealDevice_getRealDevice()
{
	return realDevice;
}

// Call this function to connect the MVRAM.
void PLC_RealDevice_setLatchPoint()
{
	//todo: Set your target device!
	//realDeviceTarget = target;
}

inline uint8* PLC_RealDevice_getLatchPoint()
{
	return realDeviceTarget;
}


/////////////////
inline uint8 PLC_RealDevice_setToIntelligenceModule(uint8 src[], uint16 deviceAddr, uint16 regAddr, int srcByteSize)
{
	//todo :: intelligence module communication
	//DBG_LOGPRINT("[TO] copy start to U%dG%d [byte size : %d]!\n", deviceAddr, regAddr, srcByteSize);
	return TRUE;
}

inline uint8 PLC_RealDevice_getFromIntelligenceModule(uint8 tar[], uint16 deviceAddr, uint16 regAddr, int tarByteSize)
{
	//todo :: intelligence module communication
	//DBG_LOGPRINT("[FROM] copy start from U%dG%d [byte size : %d!]\n", deviceAddr, regAddr, tarByteSize);
	return TRUE;
}

inline uint8 PLC_RealDevice_setUxGx(uint16 deviceAddr, uint16 regAddr, uint8* setValue)
{
	//todo :: intelligence module communication
	uint16* setValue16 = (uint16*)setValue;
	return FALSE;
}

inline uint8 PLC_RealDevice_setJxxx(uint16 deviceAddr, uint8 regML, uint16 regAddr, uint8* setValue)
{
	//todo :: intelligence module communication
	uint16* setValue16 = (uint16*)setValue;
	return FALSE;
}

inline uint8 PLC_RealDevice_getUxGx(uint16* tarValue, uint16 deviceAddr, uint16 regAddr)
{
	//todo :: network module communication
	*tarValue = 0;
	return FALSE;
}

inline uint8 PLC_RealDevice_getJxxx(uint16* tarValue, uint16 deviceAddr, uint8 regML, uint16 regAddr)
{
	//todo :: network module communication
	*tarValue = 0;
	return FALSE;
}
