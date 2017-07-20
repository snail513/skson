/*
 * PLC_RealDevice.h
 *
 *  Created on: 2016. 1. 29.
 *      Author: skson
 */

#ifndef PLC_REALDEVICE_H_
#define PLC_REALDEVICE_H_
#include "PLC_Definitions.h";

#define REAL_DEV_SIZE 1024*150


uint8* PLC_RealDevice_getRealDevice();

void PLC_RealDevice_setLatchPoint();

uint8* PLC_RealDevice_getLatchPoint();
uint8 PLC_RealDevice_setToIntelligenceModule(uint8 src[], uint16 deviceAddr, uint16 regAddr, int srcByteSize);
uint8 PLC_RealDevice_getFromIntelligenceModule(uint8 tar[], uint16 deviceAddr, uint16 regAddr, int tarByteSize);
uint8 PLC_RealDevice_setUxGx(uint16 deviceAddr, uint16 regAddr, uint8* setValue);
uint8 PLC_RealDevice_setJxxx(uint16 deviceAddr, uint8 regML, uint16 regAddr, uint8* setValue);
uint8 PLC_RealDevice_getUxGx(uint16* tarValue, uint16 deviceAddr, uint16 regAddr);
uint8 PLC_RealDevice_getJxxx(uint16* tarValue, uint16 deviceAddr, uint8 regML, uint16 regAddr);
#endif /* PLC_REALDEVICE_H_ */
