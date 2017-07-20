/*
 * PLC_Device.c
 *
 *  Created on: 2014. 10. 28.
 *      Author: skson
 */

#ifndef PLC_DEVICE_H_
#include "PLC_Device.h"
#include "PLC_TaskExecutor.h"
#endif

#ifndef PLC_OPERATORDICTIONARY_H_
#include "PLC_OperatorDictionary.h"
#include "PLC_PointTable.h"
#include "PLC_RealDevice.h"
#endif

#include <string.h>


//static char buf[100];

inline void PLC_DEVICE_Init(){
	//DBG_LOGPRINT("init dev : %l size\n", sizeof(dev));
	memset(&dev, 0, sizeof(dev));

	STACK_clear(&(dev.device_block_stack));
	STACK_clear(&(dev.device_pulse_stack));
	STACK_clear(&(dev.device_mc_stack));
	memset(dev.isMCOn, 0, MC_SIZE);

	//memset(dev.internalInstructions,0, INSTRUCTION_MEMORY_SIZE);
	PLC_InterruptionModule_resetInterruptionPointers();
	PLC_InterruptionModule_init();
	PLC_PointTable_init();
	//PLC_RealDevice_setLatchPoint();
	PLC_Register_init();
	dev.currStepIdx = 0;
	PLC_TaskExecutor_init();
	dev.forStack.count = 0;
	//dev.C_value = dev.C_val;
	//dev.T_value = dev.T_val;
}
inline void PLC_DEVICE_initExceptRegAndPointTable(){
	//memset(&dev, 0, sizeof(dev));
	STACK_clear(&(dev.device_block_stack));
	STACK_clear(&(dev.device_pulse_stack));
	STACK_clear(&(dev.device_mc_stack));

	PLC_InterruptionModule_resetInterruptionPointers();
	PLC_InterruptionModule_init();
	dev.currStepIdx = 0;
}
inline uint32 PLC_DEVICE_getCurrTimeScan(){
	return dev.nCurrTimeScan;
}


inline uint8 PLC_DEVICE_loadToOut(uint8 value, uint8 idx){
	//uint8 in=0;
	//set variable to in!
	DBG_LOGPRINT("[SYSTEM] Unimplemented loading from input!\n");

	return TRUE;
}
inline uint8 PLC_DEVICE_loadToIn(uint8 idx){
	//uint8 out = dev.Y[idx];
	//set device value to out!
	DBG_LOGPRINT("[SYSTEM] Unimplemented loading from input!\n");
	return TRUE;
}

inline uint8 PLC_DEVICE_setCountValue(uint8 C_idx, uint8 C_value){
	if(C_idx>=PLC_OPERAND_DICTIONARY_findOperandByName("C")->nAddressCount)
	{
		DBG_LOGPRINT("[SYSTEM] Error on setCountValue :C_idx is out of range!\n");
		return FALSE;
	}
	if(C_value>1){
		DBG_LOGPRINT("[SYSTEM] Error on setCountValue :C_Value is out of range!\n");
		return FALSE;
	}


	//dev.C_value[C_idx] = (0xFE & dev.C_value[C_idx]) | (0x01 &C_value);
	return PLC_Register_setCount(C_idx, C_value);
}
inline uint8 PLC_DEVICE_setTimerValue(uint8 T_idx, uint8 timerMode, uint8 T_value){
	if(T_idx>=PLC_OPERAND_DICTIONARY_findOperandByName("C")->nAddressCount)
	{
		DBG_LOGPRINT("[SYSTEM] Error on setCountValue :C_idx is out of range!\n");
		return FALSE;
	}
	if(T_value>1){
		DBG_LOGPRINT("[SYSTEM] Error on setCountValue :C_Value is out of range!\n");
		return FALSE;
	}
	//dev.T_value[T_idx] = (0xFE & dev.C_value[T_idx]) | (0x01 &T_value);
	return PLC_Register_setTimer(T_idx, timerMode, T_value);
}

inline uint32 PLC_DEVICE_getDeviceValue(uint8 operand[]){

	uint32 ret;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;

	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	uint16* valPoint = (uint16*)&operand[1+indexOffset];
	val += *valPoint & 0x0FFFF;


	if(PLC_OPERAND_IsConstant(opnd))
	{
		return *valPoint;
	}
	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return PLC_DEVICE_FALSE_32;
	}
	if(bitSize == 1)
	{
		//if(type==PLC_OPERAND_DICTIONARY_findOperandByName(OPND_DIC_SYMBOL_WB)->nMLCode)
		if(type==OPERAND_ML_CODE_WB)
		{

			uint8 extType = operand[3+indexOffset];
			uint16* extPoint = (uint16*)&operand[4+indexOffset];
			//uint16 extVal = (0x0FF&operand[4+indexOffset])*256 + (0x0FF&operand[5+indexOffset]);
			uint16 extVal = *extPoint;
			ret = PLC_Register_getWordBit(extType, extVal, val);
			//DBG_LOGPRINT("[F %s] L %d - %s%d %d!\n", __FUNCTION__, __LINE__, opndic[extType].strType, extVal, val);
		}
		else{
			//DBG_LOGPRINT("[F %s] L %d!\n", __FUNCTION__, __LINE__);
			ret = PLC_Register_getBit(type, val);
		}
	}
	else if(bitSize == 4)
	{
		uint8 devType = operand[3+indexOffset];
		uint16* devPoint = (uint16*)&operand[4+indexOffset];
		//uint16 nibbleVal = (0x0FF&operand[4+indexOffset])*256 + (0x0FF&operand[5+indexOffset]);
		uint16 devAddr = *devPoint;
		//printf("Function : %s, LINE : %d, opnd : %s%d\n", __FUNCTION__, __LINE__, opnd->strType, val);
		ret = PLC_Register_getNibble(devType, devAddr, val);
	}
	else if(bitSize == 16)
	{

		ret = PLC_Register_getWord(type, val);
		//uint16* deviceWPointer =(uint16*)devicePointer[type];
		//ret = deviceWPointer[val];
	}
	else if(bitSize == 32)
	{
		ret = PLC_Register_getDWord(type, val);
		//uint32* deviceWPointer =(uint32*)devicePointer[type];
		//ret = deviceWPointer[val];
	}
	else{
		DBG_LOGPRINT("[ERROR %s] Invalid bit size/type = %d!\n", __FUNCTION__, bitSize);
		ret = PLC_DEVICE_FALSE_32;
	}
#if PLC_LOG_DEF
	DBG_LOGPRINT("\tLoad : [%s%d]%d\n", opndic[type].strType, val, ret);
#endif
	return ret;

}

inline uint32 PLC_DEVICE_getPastDeviceValue(uint8 operand[]){

	uint32 ret;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)&operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += (0x0FFFF)&(*valPoint);
	//memcpy(val, &operand[1], sizeof(val));


	if(PLC_OPERAND_IsConstant(opnd))
	{
		return PLC_DEVICE_FALSE_32;
	}
	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return PLC_DEVICE_FALSE_32;
	}

	if(bitSize == 1)
	{
		if(type==OPERAND_ML_CODE_WB)
		{

			uint8 extType = operand[3+indexOffset];
			uint16* extPoint = (uint16*)&operand[4+indexOffset];
			//uint16 extVal = (0x0FF&operand[4+indexOffset])*256 + (0x0FF&operand[5+indexOffset]);
			uint16 extVal = *extPoint;
			ret = PLC_Register_getWordBit_old(extType, extVal, val);
			//DBG_LOGPRINT("[F %s] L %d - %s%d %d!\n", __FUNCTION__, __LINE__, opndic[extType].strType, extVal, val);
		}
		else{
			//DBG_LOGPRINT("[F %s] L %d!\n", __FUNCTION__, __LINE__);
			ret = PLC_Register_getBit_old(type, val);
		}
	}
	else if(bitSize == 4)
	{
		uint8 nibbleType = operand[3+indexOffset];
		uint16 *nibblePoint = (uint16*)&operand[4+indexOffset];
		//uint16 nibbleVal = (0x0FF&operand[4+indexOffset])*256 + (0x0FF&operand[5+indexOffset]);
		uint16 nibbleVal = *nibblePoint;
		//printf("Function : %s, LINE : %d, opnd : %s%d\n", __FUNCTION__, __LINE__, opnd->strType, val);
		ret = PLC_Register_getNibble_old(nibbleType, nibbleVal, val);
	}
	else if(bitSize == 16)
	{

		ret = PLC_Register_getWord_old(type, val);
		//uint16* deviceWPointer =(uint16*)devicePointer[type];
		//ret = deviceWPointer[val];
	}
	else if(bitSize == 32)
	{
		ret = PLC_Register_getDWord_old(type, val);
		//uint32* deviceWPointer =(uint32*)devicePointer[type];
		//ret = deviceWPointer[val];
	}
	else{
		DBG_LOGPRINT("[ERROR %s] Invalid bit size/type = %d!\n", __FUNCTION__, bitSize);
		ret = PLC_DEVICE_FALSE_32;
	}

	return ret;

}

inline uint32 PLC_DEVICE_getDeviceWordValue(uint8 operand[]){
	//DBG_LOGPRINT("\t[%s] start\n", __FUNCTION__);
	uint32 ret=0;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		short* zVal = (short*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)&operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += *valPoint&0x0FFFF;
	//printf("%s %s%d\n", __FUNCTION__, opnd->strType, val);
	//char buf[100];

	if(PLC_OPERAND_IsConstant(opnd))
	{
		//DBG_LOGPRINT("LOAD FROM CNS: [%s%d] %d\n", opndic[type].strType, val, *valPoint & (0x0FFFF));
		//return operand[1+indexOffset]+operand[2+indexOffset]*256;
		return *valPoint & (0x0FFFF);
	}
	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR] Function : %s, LINE : %d\n", __FUNCTION__, __LINE__);
		return PLC_DEVICE_FALSE_32;
	}
	if(bitSize == 1)
	{
		/*uint32* ret1;
		if(type==OPERAND_ML_CODE_WB)
		{
			type =  0x0FF& operand[3+indexOffset];
			uint16* valPoint = &operand[4+indexOffset];
			//val = val*16+ (0x0FF& operand[4+indexOffset])*256+(0x0FF&operand[5+indexOffset]);
			val = val*16+ *valPoint;
			ret1 = PLC_Register_getPos(type, val, TYPE_BIT);
		}
		ret1 = PLC_Register_getPos(type, val, TYPE_BIT);
		if(ret1==NULL){
			printf("[ERROR] Function : %s, LINE : %d\n", __FUNCTION__, __LINE__);
			return PLC_DEVICE_FALSE_32;
		}*/
		int i=0;
		int currVal = 1;

		for(i=0;i<16;i++)
		{
			int addVal = 0;
			if(!test_getBit((uint8*)&addVal, type, val+i))
			{
				return PLC_DEVICE_FALSE_32;
			}

			ret+=(currVal*addVal);
			//DBG_LOGPRINT(" loading bitValue = %d(val+i=%d)\n", addVal, val+i);
			currVal*=2;
		}


		//ret = 0;
		//DBG_LOGPRINT("LOAD FROM BIT: [%s%d] %d\n", opndic[type].strType, val, ret);
		//DBG_LOGPRINT("\t[device] load word value(%d, bitsize = %d) from %s%d\n",ret, bitSize, opnd->strType, val);
		//printf("\t[device] load word value(%d, bitsize = %d) from %s%d\n",ret, bitSize, opnd->strType, val);
	}
	else if(bitSize ==4)
	{
		if(val>8)
		{
			DBG_LOGPRINT("[ERROR] Function : %s, LINE : %d\n", __FUNCTION__, __LINE__);
			return PLC_FALSE_32;
		}
		uint8 devType =  0x0FF& operand[3+indexOffset];
		uint16* nibblePoint = (uint16*)& operand[4+indexOffset];
		//uint16 nibbleVal = (0x0FF& operand[4+indexOffset])*256+(0x0FF&operand[5+indexOffset]);
		uint16 devAddr = *nibblePoint;
		ret = PLC_Register_getNibble(devType, devAddr, val);

		//DBG_LOGPRINT("LOAD FROM BIT-Nibble: [%s%d] %d\n", opndic[type].strType, val, ret);
	}
	else
	{
		uint16* ret1 = PLC_Register_getPos(type, val, TYPE_WORD);//value[val];
		if(ret1==NULL)
		{
			DBG_LOGPRINT("[ERROR] Function : %s, LINE : %d\n", __FUNCTION__, __LINE__);
			ret = PLC_FALSE_32;
		}
		ret = *ret1;
		//DBG_LOGPRINT("LOAD FROM WORD: [%s%d] %d\n", opndic[type].strType, val, ret);
	}
	//DBG_LOGPRINT("LOAD : [%s%d] %d\n", opndic[type].strType, val, ret);
	return ret;

}

inline uint32 PLC_DEVICE_getDeviceNibbleValue(uint8 operand[]){

	uint32 ret=0;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += *valPoint;
	//char buf[100];
	if(opnd==NULL)
	{
		DBG_LOGPRINT("[ERROR %s] Invalid operand value: not in dictionary!\n", __FUNCTION__);
		return PLC_DEVICE_FALSE_32;
	}

	if(bitSize == 4)
	{
		uint8 nType = (0x0FF&operand[3+indexOffset]);
		uint16* nValuePoint =(uint16*) & operand[4+indexOffset];
		//uint16 nValue =(0x0FF& operand[4+indexOffset])*256+(0x0FF&operand[5+indexOffset]);
		uint16 nValue = *nValuePoint;
		if(!PLC_OPERAND_isValid(PLC_OPERAND_DICTIONARY_findOperand(nType), val*16 + nValue+3))
			return PLC_DEVICE_FALSE_32;
		ret = PLC_Register_getBit(nType, val*16 + nValue)+
				PLC_Register_getBit(nType, val*16 + nValue+1)*2+
				PLC_Register_getBit(nType, val*16 + nValue+2)*4+
				PLC_Register_getBit(nType, val*16 + nValue+3)*8;
		return ret;
	}
	else
	{
		return PLC_DEVICE_FALSE_32;
	}

}
inline uint32 PLC_DEVICE_getDeviceDoubleWordValue(uint8 operand[]){
	uint32 ret=0;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;

	if(type == OPERAND_ML_CODE_Z)
	{
		//printf("Z %02X%02X\n", operand[2], operand[1]);
		uint16 zVal = operand[1]+operand[2]*256;
		if(!test_getWord(&val, OPERAND_ML_CODE_Z, zVal))
			return FALSE;
		indexOffset=3;
		type = operand[indexOffset];
		//printf("Z load Z %d ", opndic[type].strType, val);
	}

	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1+indexOffset];
	val += 0x0FFFF & *valPoint;
	//printf("%s %d\n", opndic[type].strType, val);
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);




	if(PLC_OPERAND_IsConstant(opnd))
	{
		/*DBG_LOGPRINT("[device] operand:[%d %d %d %d %d]\n"
						, operand[0], operand[1], operand[2], operand[3], operand[4] );
						*/
		/*
		ret = (0x0FF& operand[1+indexOffset])+
				(0x0FF&operand[2+indexOffset])*256+
				(0x0FF& operand[3+indexOffset])*256*256+
				(0x0FF&operand[4+indexOffset])*256*256*256;
				*/
		uint32* retPoint =(uint32*) & operand[1+indexOffset];
		ret = *retPoint;
		/*DBG_LOGPRINT(buf, "[device] load constant:[%s%d]\n"
				, PLC_OPERAND_DICTIONARY_findOperand(type)->strType, ret);*/
		//return (uint32)ret;
	}
	else  if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return PLC_DEVICE_FALSE_32;
	}
	else if(bitSize == 1)
	{
		int i;
		int currVal = 0;
		for(i=0;i<32;i++)
		{
			int addVal = 0;

			if(!test_getBit((uint8*)&addVal, type, val+i))
			{
				return PLC_DEVICE_FALSE_32;
			}
			//printf("[%s%d]%d\n", opndic[type].strType, val+i, addVal);
			ret+=(currVal*addVal);
			//DBG_LOGPRINT(" loading bitValue = %d(val+i=%d)\n", addVal, val+i);
			currVal*=2;
		}
		//printf("\n");
	}
	else if(bitSize == 4)
	{
		uint8 extType = operand[3+indexOffset];
		uint16* extPoint = (uint16*)&operand[4+indexOffset];
		//uint16 extVal =(0x0FF& operand[4+indexOffset])*256+(0x0FF&operand[5+indexOffset]);
		uint16 extVal = *extPoint;
		ret = PLC_Register_getNibble(extType, extVal, val);
	}
	else
	{

		uint32* ret1 = PLC_Register_getPos(type, val, TYPE_DWORD);//value[val];
		//DBG_LOGPRINT("[%s%d]%d|%f\n",opndic[type].strType, val, *ret1, *(float*)ret1);
		if(ret1==NULL)
		{
			//DBG_LOGPRINT("[ERROR]in %s %d\n", __FUNCTION__, __LINE__);
			ret = PLC_FALSE_32;
		}
		else
			ret = *ret1;
		//DBG_LOGPRINT("[%s%d]%d\n",opndic[type].strType, val, ret);
	}
	//DBG_LOGPRINT("PLC_DEVICE_getDeviceDoubleWordValue [%s%d]%X = %f\n",opnd->strType, val,ret, *(float*)&ret);
	//DBG_LOGPRINT("\t[device] load doubleword value(%d) from %s%d\n",ret, opnd->strType, val);
	return ret;

}
inline float PLC_DEVICE_getDeviceFloatValue(uint8 operand[]){
	float ret=0.f;
	//uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}

	//PLC_Operand* opnd = (PLC_Operand*)PLC_OPERAND_DICTIONARY_findOperand(type);
	//bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += *valPoint;
	//printf("%s%d\n", __FUNCTION__, __LINE__);
	if(type==OPERAND_ML_CODE_E)
	{
		float* retVal = (float*)&operand[1+indexOffset];
		ret = *retVal;
		/*DBG_LOGPRINT("\t\t[getFloatValue] %s%f = %02X %02X %02X %02X %02X\n",
				opnd->strType, ret, operand[4+indexOffset], operand[3+indexOffset], operand[2+indexOffset], operand[1+indexOffset], operand[0+indexOffset] );
				*/
		//printf("\t\t[%s] ret = %f / %02X %02X %02X %02X\n", __FUNCTION__, ret, operand[4], operand[3], operand[2], operand[1]);

	}
	else
	{
		ret = PLC_Register_getFloat(type, val);
		//printf("\t\t[%s] ret = %f\n", __FUNCTION__, ret);
		//DBG_LOGPRINT("\t\t[getFloatValue] %s%d = %f\n", opnd->strType, val, ret);
	}
	//printf("%s%d\n", __FUNCTION__, __LINE__);
	return ret;
}
inline double PLC_DEVICE_getDeviceDoubleValue(uint8 operand[]){
	double ret=0.f;
	//uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}

	//PLC_Operand* opnd = (PLC_Operand*)PLC_OPERAND_DICTIONARY_findOperand(type);
	//bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += *valPoint;
	if(type==OPERAND_ML_CODE_DE)
	{
		double* retVal = (double*)&operand[1+indexOffset];
		ret = *retVal;
		//DBG_LOGPRINT("\t\t[getDoubleValue] %s%f\n", opnd->strType, ret);
	}
	else
	{
		ret = PLC_Register_getDouble(type, val);
		//DBG_LOGPRINT("\t\t[getDoubleValue] %s%d = %f\n", opnd->strType, val, ret);
	}

	return ret;
}
///////
inline uint32 PLC_DEVICE_getOffsetDeviceValue(uint8 operand[], uint16 offset){

	uint32 ret;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;

	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	uint16* valPoint = (uint16*)&operand[1+indexOffset];
	val += *valPoint & 0x0FFFF;
	val += offset;

	if(PLC_OPERAND_IsConstant(opnd))
	{
		return *valPoint;
	}
	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return PLC_DEVICE_FALSE_32;
	}
	if(bitSize == 1)
	{
		//if(type==PLC_OPERAND_DICTIONARY_findOperandByName(OPND_DIC_SYMBOL_WB)->nMLCode)
		if(type==OPERAND_ML_CODE_WB)
		{

			uint8 extType = operand[3+indexOffset];
			uint16* extPoint = (uint16*)&operand[4+indexOffset];
			//uint16 extVal = (0x0FF&operand[4+indexOffset])*256 + (0x0FF&operand[5+indexOffset]);
			uint16 extVal = *extPoint;
			ret = PLC_Register_getWordBit(extType, extVal, val);
			//DBG_LOGPRINT("[F %s] L %d - %s%d %d!\n", __FUNCTION__, __LINE__, opndic[extType].strType, extVal, val);
		}
		else{
			//DBG_LOGPRINT("[F %s] L %d!\n", __FUNCTION__, __LINE__);
			ret = PLC_Register_getBit(type, val);
		}
	}
	else if(bitSize == 4)
	{
		uint8 devType = operand[3+indexOffset];
		uint16* devPoint = (uint16*)&operand[4+indexOffset];
		//uint16 nibbleVal = (0x0FF&operand[4+indexOffset])*256 + (0x0FF&operand[5+indexOffset]);
		uint16 devAddr = *devPoint;
		//printf("Function : %s, LINE : %d, opnd : %s%d\n", __FUNCTION__, __LINE__, opnd->strType, val);
		ret = PLC_Register_getNibble(devType, devAddr, val);
	}
	else if(bitSize == 16)
	{

		ret = PLC_Register_getWord(type, val);
		//uint16* deviceWPointer =(uint16*)devicePointer[type];
		//ret = deviceWPointer[val];
	}
	else if(bitSize == 32)
	{
		ret = PLC_Register_getDWord(type, val);
		//uint32* deviceWPointer =(uint32*)devicePointer[type];
		//ret = deviceWPointer[val];
	}
	else{
		DBG_LOGPRINT("[ERROR %s] Invalid bit size/type = %d!\n", __FUNCTION__, bitSize);
		ret = PLC_DEVICE_FALSE_32;
	}
#if PLC_LOG_DEF
	DBG_LOGPRINT("\tLoad : [%s%d]%d\n", opndic[type].strType, val, ret);
#endif
	return ret;

}

inline uint32 PLC_DEVICE_getOffsetPastDeviceValue(uint8 operand[], uint16 offset){

	uint32 ret;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)&operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += (0x0FFFF)&(*valPoint);
	val += offset;
	//memcpy(val, &operand[1], sizeof(val));


	if(PLC_OPERAND_IsConstant(opnd))
	{
		return PLC_DEVICE_FALSE_32;
	}
	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return PLC_DEVICE_FALSE_32;
	}

	if(bitSize == 1)
	{
		if(type==OPERAND_ML_CODE_WB)
		{

			uint8 extType = operand[3+indexOffset];
			uint16* extPoint = (uint16*)&operand[4+indexOffset];
			//uint16 extVal = (0x0FF&operand[4+indexOffset])*256 + (0x0FF&operand[5+indexOffset]);
			uint16 extVal = *extPoint;
			ret = PLC_Register_getWordBit_old(extType, extVal, val);
			//DBG_LOGPRINT("[F %s] L %d - %s%d %d!\n", __FUNCTION__, __LINE__, opndic[extType].strType, extVal, val);
		}
		else{
			//DBG_LOGPRINT("[F %s] L %d!\n", __FUNCTION__, __LINE__);
			ret = PLC_Register_getBit_old(type, val);
		}
	}
	else if(bitSize == 4)
	{
		uint8 nibbleType = operand[3+indexOffset];
		uint16 *nibblePoint = (uint16*)&operand[4+indexOffset];
		//uint16 nibbleVal = (0x0FF&operand[4+indexOffset])*256 + (0x0FF&operand[5+indexOffset]);
		uint16 nibbleVal = *nibblePoint;
		//printf("Function : %s, LINE : %d, opnd : %s%d\n", __FUNCTION__, __LINE__, opnd->strType, val);
		ret = PLC_Register_getNibble_old(nibbleType, nibbleVal, val);
	}
	else if(bitSize == 16)
	{

		ret = PLC_Register_getWord_old(type, val);
		//uint16* deviceWPointer =(uint16*)devicePointer[type];
		//ret = deviceWPointer[val];
	}
	else if(bitSize == 32)
	{
		ret = PLC_Register_getDWord_old(type, val);
		//uint32* deviceWPointer =(uint32*)devicePointer[type];
		//ret = deviceWPointer[val];
	}
	else{
		DBG_LOGPRINT("[ERROR %s] Invalid bit size/type = %d!\n", __FUNCTION__, bitSize);
		ret = PLC_DEVICE_FALSE_32;
	}

	return ret;

}

inline uint8 PLC_DEVICE_getOffsetDeviceWordValue(uint16* tar, uint8 operand[], uint16 offset){
	//DBG_LOGPRINT("\t[%s] start\n", __FUNCTION__);
	uint32 ret=0;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		short* zVal = (short*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)&operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += *valPoint&0x0FFFF;
	val += offset;
	//printf("%s %s%d\n", __FUNCTION__, opnd->strType, val);
	//char buf[100];

	if(PLC_OPERAND_IsConstant(opnd))
	{
		//DBG_LOGPRINT("LOAD FROM CNS: [%s%d] %d\n", opndic[type].strType, val, *valPoint & (0x0FFFF));
		//return operand[1+indexOffset]+operand[2+indexOffset]*256;
		*tar = *valPoint & (0x0FFFF);
		return TRUE;
	}
	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR] Function : %s, LINE : %d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	if(bitSize == 1)
	{
		/*uint32* ret1;
		if(type==OPERAND_ML_CODE_WB)
		{
			type =  0x0FF& operand[3+indexOffset];
			uint16* valPoint = &operand[4+indexOffset];
			//val = val*16+ (0x0FF& operand[4+indexOffset])*256+(0x0FF&operand[5+indexOffset]);
			val = val*16+ *valPoint;
			ret1 = PLC_Register_getPos(type, val, TYPE_BIT);
		}
		ret1 = PLC_Register_getPos(type, val, TYPE_BIT);
		if(ret1==NULL){
			printf("[ERROR] Function : %s, LINE : %d\n", __FUNCTION__, __LINE__);
			return PLC_DEVICE_FALSE_32;
		}*/
		int i=0;
		int currVal = 1;

		for(i=0;i<16;i++)
		{
			int addVal = 0;
			if(!test_getBit((uint8*)&addVal, type, val+i))
			{
				return FALSE;
			}

			ret+=(currVal*addVal);
			//DBG_LOGPRINT(" loading bitValue = %d(val+i=%d)\n", addVal, val+i);
			currVal*=2;
		}


		//ret = 0;
		//DBG_LOGPRINT("LOAD FROM BIT: [%s%d] %d\n", opndic[type].strType, val, ret);
		//DBG_LOGPRINT("\t[device] load word value(%d, bitsize = %d) from %s%d\n",ret, bitSize, opnd->strType, val);
		//printf("\t[device] load word value(%d, bitsize = %d) from %s%d\n",ret, bitSize, opnd->strType, val);
	}
	else if(bitSize ==4)
	{
		if(val>8)
		{
			DBG_LOGPRINT("[ERROR] Function : %s, LINE : %d\n", __FUNCTION__, __LINE__);
			return PLC_FALSE_32;
		}
		uint8 devType =  0x0FF& operand[3+indexOffset];
		uint16* nibblePoint = (uint16*)& operand[4+indexOffset];
		//uint16 nibbleVal = (0x0FF& operand[4+indexOffset])*256+(0x0FF&operand[5+indexOffset]);
		uint16 devAddr = *nibblePoint;
		ret = PLC_Register_getNibble(devType, devAddr, val);
		if(ret == PLC_FALSE_32)
			return FALSE;

		//DBG_LOGPRINT("LOAD FROM BIT-Nibble: [%s%d] %d\n", opndic[type].strType, val, ret);
	}
	else
	{
		uint16* ret1 = PLC_Register_getPos(type, val, TYPE_WORD);//value[val];
		if(ret1==NULL)
		{
			DBG_LOGPRINT("[ERROR] Function : %s, LINE : %d\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		ret = *ret1;
		//DBG_LOGPRINT("LOAD FROM WORD: [%s%d] %d\n", opndic[type].strType, val, ret);
	}
	//DBG_LOGPRINT("LOAD : [%s%d] %d\n", opndic[type].strType, val, ret);
	*tar = ret;
	return TRUE;

}

inline uint32 PLC_DEVICE_getOffsetDeviceNibbleValue(uint8 operand[], uint16 offset){

	uint32 ret=0;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += *valPoint;
	val += offset;
	//char buf[100];
	if(opnd==NULL)
	{
		DBG_LOGPRINT("[ERROR %s] Invalid operand value: not in dictionary!\n", __FUNCTION__);
		return PLC_DEVICE_FALSE_32;
	}

	if(bitSize == 4)
	{
		uint8 nType = (0x0FF&operand[3+indexOffset]);
		uint16* nValuePoint =(uint16*) & operand[4+indexOffset];
		//uint16 nValue =(0x0FF& operand[4+indexOffset])*256+(0x0FF&operand[5+indexOffset]);
		uint16 nValue = *nValuePoint;
		if(!PLC_OPERAND_isValid(PLC_OPERAND_DICTIONARY_findOperand(nType), val*16 + nValue+3))
			return PLC_DEVICE_FALSE_32;
		ret = PLC_Register_getBit(nType, val*16 + nValue)+
				PLC_Register_getBit(nType, val*16 + nValue+1)*2+
				PLC_Register_getBit(nType, val*16 + nValue+2)*4+
				PLC_Register_getBit(nType, val*16 + nValue+3)*8;
		return ret;
	}
	else
	{
		return PLC_DEVICE_FALSE_32;
	}

}
inline uint8 PLC_DEVICE_getOffsetDeviceDoubleWordValue(uint32* tar, uint8 operand[], uint16 offset){
	uint32 ret=0;
	uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;

	if(type == OPERAND_ML_CODE_Z)
	{
		//printf("Z %02X%02X\n", operand[2], operand[1]);
		uint16 zVal = operand[1]+operand[2]*256;
		if(!test_getWord(&val, OPERAND_ML_CODE_Z, zVal))
			return FALSE;
		indexOffset=3;
		type = operand[indexOffset];
		//printf("Z load Z %d ", opndic[type].strType, val);
	}

	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1+indexOffset];
	val += 0x0FFFF & *valPoint;
	val += offset;
	//printf("%s %d\n", opndic[type].strType, val);
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);




	if(PLC_OPERAND_IsConstant(opnd))
	{
		/*DBG_LOGPRINT("[device] operand:[%d %d %d %d %d]\n"
						, operand[0], operand[1], operand[2], operand[3], operand[4] );
						*/
		/*
		ret = (0x0FF& operand[1+indexOffset])+
				(0x0FF&operand[2+indexOffset])*256+
				(0x0FF& operand[3+indexOffset])*256*256+
				(0x0FF&operand[4+indexOffset])*256*256*256;
				*/
		*tar =(uint32*) & operand[1+indexOffset];
		return TRUE;
		/*DBG_LOGPRINT(buf, "[device] load constant:[%s%d]\n"
				, PLC_OPERAND_DICTIONARY_findOperand(type)->strType, ret);*/
		//return (uint32)ret;
	}
	else  if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	else if(bitSize == 1)
	{
		int i;
		int currVal = 0;
		for(i=0;i<32;i++)
		{
			int addVal = 0;

			if(!test_getBit((uint8*)&addVal, type, val+i))
			{
				return PLC_DEVICE_FALSE_32;
			}
			//printf("[%s%d]%d\n", opndic[type].strType, val+i, addVal);
			ret+=(currVal*addVal);
			//DBG_LOGPRINT(" loading bitValue = %d(val+i=%d)\n", addVal, val+i);
			currVal*=2;
		}
		//printf("\n");
	}
	else if(bitSize == 4)
	{
		uint8 extType = operand[3+indexOffset];
		uint16* extPoint = (uint16*)&operand[4+indexOffset];
		//uint16 extVal =(0x0FF& operand[4+indexOffset])*256+(0x0FF&operand[5+indexOffset]);
		uint16 extVal = *extPoint;
		ret = PLC_Register_getNibble(extType, extVal, val);
	}
	else
	{

		uint32* ret1 = PLC_Register_getPos(type, val, TYPE_DWORD);//value[val];
		//DBG_LOGPRINT("[%s%d]%d|%f\n",opndic[type].strType, val, *ret1, *(float*)ret1);
		if(ret1==NULL)
		{
			//DBG_LOGPRINT("[ERROR]in %s %d\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		else
			ret = *ret1;
		//DBG_LOGPRINT("[%s%d]%d\n",opndic[type].strType, val, ret);
	}
	//DBG_LOGPRINT("PLC_DEVICE_getDeviceDoubleWordValue [%s%d]%X = %f\n",opnd->strType, val,ret, *(float*)&ret);
	//DBG_LOGPRINT("\t[device] load doubleword value(%d) from %s%d\n",ret, opnd->strType, val);
	*tar = ret;
	return TRUE;

}
inline float PLC_DEVICE_getOffsetDeviceFloatValue(uint8 operand[], uint16 offset){
	float ret=0.f;
	//uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}

	//PLC_Operand* opnd = (PLC_Operand*)PLC_OPERAND_DICTIONARY_findOperand(type);
	//bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += *valPoint;
	val += offset;
	//printf("%s%d\n", __FUNCTION__, __LINE__);
	if(type==OPERAND_ML_CODE_E)
	{
		float* retVal = (float*)&operand[1+indexOffset];
		ret = *retVal;
		/*DBG_LOGPRINT("\t\t[getFloatValue] %s%f = %02X %02X %02X %02X %02X\n",
				opnd->strType, ret, operand[4+indexOffset], operand[3+indexOffset], operand[2+indexOffset], operand[1+indexOffset], operand[0+indexOffset] );
				*/
		//printf("\t\t[%s] ret = %f / %02X %02X %02X %02X\n", __FUNCTION__, ret, operand[4], operand[3], operand[2], operand[1]);

	}
	else
	{
		ret = PLC_Register_getFloat(type, val);
		//printf("\t\t[%s] ret = %f\n", __FUNCTION__, ret);
		//DBG_LOGPRINT("\t\t[getFloatValue] %s%d = %f\n", opnd->strType, val, ret);
	}
	//printf("%s%d\n", __FUNCTION__, __LINE__);
	return ret;
}
inline double PLC_DEVICE_getOffsetDeviceDoubleValue(uint8 operand[], uint16 offset){
	double ret=0.f;
	//uint8 bitSize;
	uint8 type  = operand[0];
	uint8 indexOffset=0;
	uint16 val=0;
	if(type == OPERAND_ML_CODE_Z)
	{
		uint16* zVal = (uint16*)&operand[1];
		test_getWord(&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}

	//PLC_Operand* opnd = (PLC_Operand*)PLC_OPERAND_DICTIONARY_findOperand(type);
	//bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1+indexOffset];
	//val +=(0x0FF& operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);
	val += *valPoint;
	val += offset;
	if(type==OPERAND_ML_CODE_DE)
	{
		double* retVal = (double*)&operand[1+indexOffset];
		ret = *retVal;
		//DBG_LOGPRINT("\t\t[getDoubleValue] %s%f\n", opnd->strType, ret);
	}
	else
	{
		ret = PLC_Register_getDouble(type, val);
		//DBG_LOGPRINT("\t\t[getDoubleValue] %s%d = %f\n", opnd->strType, val, ret);
	}

	return ret;
}

////////
inline uint8 PLC_DEVICE_isDeviceAddrRange(uint8 operand[], uint16 addrOffset)
{

	short val=0;
	uint8 indexOffset = 0;
	uint8 type  = operand[0];

	if(type == OPERAND_ML_CODE_Z)
	{

		uint16* zVal = (uint16*)&operand[1];
		test_getWord((uint16*)&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	else if(type == OPERAND_ML_CODE_N)
	{
		//uint16* nVal = (uint16*)&operand[1];
		//printf("Nibble detect\n");
		//test_getWord(&val, OPERAND_ML_CODE_Z, *nVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	short* valPoint = (short*)&operand[1+indexOffset];

	val += *valPoint;
	//printf("loadAddr = [%s %d]\n",opndic[type].strType, val);
	//val+=(0x0FF&operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);

	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	if(PLC_OPERAND_IsConstant(opnd))
	{
		return FALSE;
	}
	//DBG_LOGPRINT("[%s%d+%d]\n", opnd->strType, val, addrOffset);
	return checkErrorFromOperand(opnd, val+addrOffset);
}
inline uint16* PLC_DEVICE_getDeviceString(uint8 operand[]){
	uint16* ret;
	short val=0;
	uint8 indexOffset = 0;
	uint8 type  = operand[0];

	if(type == OPERAND_ML_CODE_Z)
	{

		uint16* zVal = (uint16*)&operand[1];
		test_getWord((uint16*)&val, OPERAND_ML_CODE_Z, *zVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	else if(type == OPERAND_ML_CODE_N)
	{
		//uint16* nVal = (uint16*)&operand[1];
		//printf("Nibble detect\n");
		//test_getWord(&val, OPERAND_ML_CODE_Z, *nVal);
		indexOffset=3;
		type = operand[indexOffset];
	}
	short* valPoint = (short*)&operand[1+indexOffset];

	val += *valPoint;
	//printf("loadAddr = [%s %d]\n",opndic[type].strType, val);
	//val+=(0x0FF&operand[1+indexOffset])*256+(0x0FF&operand[2+indexOffset]);

	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);

	if(PLC_OPERAND_IsConstant(opnd))
	{

		/*if((opnd->nMLCode!=PLC_OPERAND_DICTIONARY_findOperandByName("$")->nMLCode))
		{
			DBG_LOGPRINT("[ERROR %s] Invalid Device Address Type: Constant type, but not string type!\n", __FUNCTION__);
			printf("[ERROR %s] Invalid Device Address Type: Constant type, but not string type!\n", __FUNCTION__);
			return NULL;
		}*/
		//printf("[%s]Getting Constant Value : %02X %02X\n", __FUNCTION__, *((short*)&operand[1+indexOffset]));
		if(operand[0]!=OPERAND_ML_CODE_STR)
			return NULL;
		return (uint16*)&operand[1+indexOffset];
	}

	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		//printf("[ERROR %s] Invalid Operand value: value is out of range!\n", __FUNCTION__);
		return NULL;
	}

	if(opnd->nBitSize==1)
	{
		//DBG_LOGPRINT("[ERROR %s] Unable to load string from bit device!\n", __FUNCTION__);
		//printf("[ERROR %s] Invalid BitSize : value is out of range!\n", __FUNCTION__);
		ret = (uint16*)PLC_Register_getPos(type, val, TYPE_BIT);
		//return NULL;
	}
	else if(opnd->nBitSize==16)
	{
		//get from value
		ret = (uint16*)PLC_Register_getPos(type, val, TYPE_WORD);
	}

	if(ret==NULL)
	{
		printf("[ERROR] %s PLC_Register_getPos(type, val, TYPE_BIT)\n", __FUNCTION__);
	}
	//DBG_LOGPRINT("[%s] load : [%s%d]%s!\n", __FUNCTION__, opnd->strType, val, (char*)ret);
	//printf("%s%d = %d\n",opndic[type].strType, val, *(uint16*)ret);
	return ret;
}


inline uint8 PLC_DEVICE_setDeviceValue(uint8 operand[], uint32 in, short offset)
{
	//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
	uint8 bitSize;
	uint8 type  = operand[0];
	uint16 val;
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1];
	val = * valPoint;


	if(PLC_OPERAND_IsConstant(opnd))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
	if(type == OPERAND_ML_CODE_Z)
	{

		uint16 zIdx = *(uint16*)&operand[1];
		uint16 tarAddr = *(uint16*)&operand[4];
		type = operand[3];
		short zAddr = 0;

		uint8 in_Bitsize = opndic[type].nBitSize;
		//opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
		//int typeSize = (opnd->nBitSize==1)? TYPE_BIT : (opnd->nBitSize==16)? TYPE_WORD :(opnd->nBitSize==32)? TYPE_DWORD : TYPE_LONG;
		if(!test_getWord((uint16*)&zAddr, OPERAND_ML_CODE_Z, zIdx))
			return FALSE;

		int typeSize =  (in_Bitsize==1)? TYPE_BIT : (in_Bitsize==16)? TYPE_WORD :(in_Bitsize==32)? TYPE_DWORD : TYPE_LONG;
		//printf("input : type %s%d in %d bitSize %d\n", opndic[type].strType,zAddr+tarAddr, in, typeSize);
		if(!PLC_Register_set(type, zAddr+tarAddr+offset, 0, (uint8*)&in, typeSize))
		{
			return FALSE;
		}
		return TRUE;
	}
	if(type == OPERAND_ML_CODE_U)
	{
		uint16 devIdx = *(uint16*)&operand[1];
		uint16 tarAddr = *(uint16*)&operand[4];
		//short zAddr = 0;
		type = operand[3];
		//int typeSize =  TYPE_WORD;
		if(type!=OPERAND_ML_CODE_K)
			return FALSE;
		if(!PLC_RealDevice_setUxGx(devIdx, type, (uint8*)&in))
			return FALSE;
		return TRUE;

	}
	if(type == OPERAND_ML_CODE_J)
	{
		uint16 devIdx = *(uint16*)&operand[1];
		uint16 tarAddr = *(uint16*)&operand[4];
		type = operand[3];
		if(!PLC_RealDevice_setJxxx(devIdx, type, tarAddr, (uint8*)&in))
			return FALSE;
		return TRUE;

	}
	if(type == OPERAND_ML_CODE_T)
	{
		if(in == 0)
		{
			if(!PLC_Register_rstTValue(val+offset))

			{
				return FALSE;
			}
		}
		else if(!PLC_Register_setTValue(val+offset, VALUE_TYPE_SET, in))
		{
			DBG_LOGPRINT("[ERROR %s] line = %d\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		return TRUE;
	}
	if(type == OPERAND_ML_CODE_C)
	{
		if(in == 0)
		{
			if(!PLC_Register_rstCValue(val+offset))

			{
				return FALSE;
			}
		}
		else if(!PLC_Register_setCValue(val+offset, VALUE_TYPE_SET, in))
		{
			DBG_LOGPRINT("[ERROR %s] line = %d\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		return TRUE;
	}
	if(bitSize ==4 || type==OPERAND_ML_CODE_N)
	{
		//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
		//DBG_LOGPRINT("set nibble\n");
		uint8 ret = 0x0F & in;
		uint8 devType = operand[3];
		uint16 devAddr =  *(uint16*)&operand[4] + offset;
		uint16 nibbleIdx;
		for(nibbleIdx = 0; nibbleIdx<val; nibbleIdx++)
		{
			if(!PLC_Register_set(devType, devAddr+nibbleIdx*4, 0, (uint8*)&ret, TYPE_NIBBLE))
			{
				DBG_LOGPRINT("[ERROR %s] line = %d\n", __FUNCTION__, __LINE__);
				return FALSE;
			}
		}
	}
	if(bitSize == 1){
		//int i;
		//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
		if(type == OPERAND_ML_CODE_WB)
		{
			//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
			return PLC_DEVICE_setDeviceWordBit( operand, 0, offset, (uint8)in);
/*
			uint8 devType = 0x0FF& operand[3];
			uint16* bitValPoint = (uint16*)& operand[1];
			uint16 bitVal = *bitValPoint;
			val = (uint16*)& operand[4];
			if(!PLC_Register_set(devType, val, bitVal, &in, TYPE_WORDBIT))
			{
				DBG_LOGPRINT("[ERROR %s] line = %d\n", __FUNCTION__, __LINE__);
				//DBG_LOGPRINT("[ERROR %s] PLC_Register_set failed!\n", __FUNCTION__);
				return FALSE;
			}*/
		}
		else //for(i=0;i<16;i++)
		{
			val +=offset;
			//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
			/*uint32 ret =(in>>i)&0x01;
			if(!PLC_Register_set(type, val+i, 0, (uint8*)&ret, TYPE_BIT))
			{
				DBG_LOGPRINT("[ERROR %s] line = %d\n", __FUNCTION__, __LINE__);
				//DBG_LOGPRINT("[ERROR %s] PLC_Register_set failed!\n", __FUNCTION__);
				return FALSE;
			}*/
#if PLC_LOG_DEF
			DBG_LOGPRINT("\t[Reg set] %s%d = %d\n", opndic[type].strType, val, in);
#endif
			//DBG_LOGPRINT("[%s%d] <== %d\n", opndic[type].strType, val, in);
			if(!PLC_Register_set(type, val, 0, (uint8*)&in, TYPE_BIT))
			{
				DBG_LOGPRINT("[ERROR %s] line = %d\n", __FUNCTION__, __LINE__);
				return FALSE;
			}
			//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
			if(type == OPERAND_ML_CODE_F)
			{
				//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
				if(in==1)
				{
					//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
					//DBG_LOGPRINT("[SET F] F%d\n", val);
					if(!PLC_Register_setF(val))
					{
						DBG_LOGPRINT("[ERROR %s] line = %d\n", __FUNCTION__, __LINE__);
						return FALSE;
					}
				}
				else
				{
					//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
					//DBG_LOGPRINT("[RST F] F%d\n", val);
					if(!PLC_Register_resetF(val))
					{
						DBG_LOGPRINT("[ERROR %s] line = %d\n", __FUNCTION__, __LINE__);
						return FALSE;
					}
					//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
				}
				//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
			}
			//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
		}
		return TRUE;
	}
	else if(bitSize == 16 || bitSize == 32)
	{
		val+=offset;
		//DBG_LOGPRINT("[%s%d] <== %d\n", opndic[type].strType, val, in);
		if(!PLC_Register_set(type, val, 0, (uint8*)&in, TYPE_WORD))
		{
			DBG_LOGPRINT("[ERROR %s] line = %d\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		return TRUE;
	}
	else{
		DBG_LOGPRINT("[ERROR %s] line = %d, bitSize exception : bitSize = %d\n", __FUNCTION__, __LINE__, bitSize);
		return FALSE;
	}
	//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
	return TRUE;
}

inline uint8 PLC_DEVICE_setDeviceDoubleWordValue(uint8 operand[], uint32 in){
	uint8 bitSize;
	uint8 type  = operand[0];
	uint16 val;
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	bitSize = opnd->nBitSize;
	uint16* valPoint = (uint16*)& operand[1];
	//val =(0x0FF& operand[1])*256+(0x0FF&operand[2]);
	val =  *valPoint;
	if(PLC_OPERAND_IsConstant(opnd))
	{
		DBG_LOGPRINT("[ERROR %s] Invalid Device Address Type: Constant Type!\n", __FUNCTION__);
		return FALSE;
	}

	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return FALSE;
	}

	if(bitSize == 1)
	{
		int i;
		for(i=0;i<32;i++)
		{
			uint32 ret =(in>>i)&0x01;
			if(!PLC_Register_set(type, val+i, 0, (uint8*)&ret, TYPE_BIT))
				return FALSE;
		}

		//uint16* dst = (uint16*)devicePointer[type];
		//dst[val] = ret%(256*256);
		//dst[val+1] = ret/256/256;
		//DBG_LOGPRINT("\t%d - %d\n",dst[val] , dst[val+1] );
		//devicePointer[type][val+1] = ret%256;
	}
	else if(bitSize == 16|| bitSize == 32)
	{
		//uint32* dst = (uint32*)devicePointer[type];
		//dst[val] = ret;
		//DBG_LOGPRINT("\t%d\n",dst[val] );
		if(!PLC_Register_set(type, val, 0, (uint8*)&in, TYPE_DWORD))
			return FALSE;
	}
	else{
		//DBG_LOG("\t[ERROR %s] Unknown type of bit size...");
		return FALSE;
	}
	//DBG_LOGPRINT("\t[device] set DWord-value(%d) to %s%d\n", in , opnd->strType, val);
	return TRUE;


}

inline uint8 PLC_DEVICE_setDeviceValueBySize(uint8 operand[], long long in, uint8 in_Bitsize){
	int i;
	uint8 bitSize = in_Bitsize;
	uint8 type  = operand[0];
	uint16 addr;
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
	uint16* valPoint = (uint16*)& operand[1];
	addr = *valPoint;

	if(type==OPERAND_ML_CODE_N)
	{

		type = operand[3];
		opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
		bitSize =  4*addr;
		valPoint = (uint16*)& operand[4];
		addr = *valPoint;
		//printf("set nibble : type %d addr %d size %d\n", type, addr, bitSize);
		if(opnd->nBitSize!=1)
		{
			DBG_LOGPRINT("\t[ERROR %s] Nibble is not set in bit device! :%s\n", __func__, opnd->strType);
			return FALSE;
		}
		if(addr%16==0)
		{
			addr/=16;
			if(bitSize == 16)
			{
				uint16 ret = (uint16)in;
				if(!PLC_Register_set(type, addr, 0, (uint8*)&ret, TYPE_WORD))
				{
					//DBG_LOGPRINT("\t[ERROR %s] Setting Register has failed!\n", __FUNCTION__);
					return FALSE;
				}
				return TRUE;
			}
			else if(bitSize == 32)
			{
				uint32 ret = (uint32)in;
				if(!PLC_Register_set(type, addr, 0, (uint8*)&ret, TYPE_DWORD))
				{
					//DBG_LOGPRINT("\t[ERROR %s] Setting Register has failed!\n", __FUNCTION__);
					return FALSE;
				}
				return TRUE;
			}else if(bitSize == 64)
			{
				long long ret = (long long)in;
				if(!PLC_Register_set(type, addr, 0, (uint8*)&ret, TYPE_LONG))
				{
					//DBG_LOGPRINT("\t[ERROR %s] Setting Register has failed!\n", __FUNCTION__);
					return FALSE;
				}
				return TRUE;
			}
			return FALSE;
		}
		for(i=0;i<bitSize;i++)
		{
			uint8 ret = (in>>i)&0x01;
			if(!PLC_Register_set(type, addr+i, 0, (uint8*)&ret, TYPE_BIT))
				return FALSE;
		}
		return TRUE;
	}
	else if(type == OPERAND_ML_CODE_WB)
	{
		/*//printf("WB\n");
		type = operand[3];
		opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
		bitSize = 1;
		uint16* valPoint2 = (uint16*)& operand[4];
		addr = addr+16*(*valPoint2);
		uint8 ret = (uint8)(in&0x01);
		if(!PLC_Register_set(type, addr, 0, (uint8*)&ret, TYPE_BIT))
			return FALSE;
		return TRUE;*/
		return PLC_DEVICE_setDeviceWordBit( operand, 0, 0, (uint8)in);
	}else if(type == OPERAND_ML_CODE_Z)
	{

		uint16 zIdx = *(uint16*)&operand[1];
		uint16 tarAddr = *(uint16*)&operand[4];
		short zAddr = 0;
		//short in_value = in;
		type = operand[3];
		opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
		//int typeSize = (opnd->nBitSize==1)? TYPE_BIT : (opnd->nBitSize==16)? TYPE_WORD :(opnd->nBitSize==32)? TYPE_DWORD : TYPE_LONG;
		if(!test_getWord((uint16*)&zAddr, OPERAND_ML_CODE_Z, zIdx))
			return FALSE;

		int typeSize =  (in_Bitsize==1)? TYPE_BIT : (in_Bitsize==16)? TYPE_WORD :(in_Bitsize==32)? TYPE_DWORD : TYPE_LONG;
		//printf("input : type %s%d in %d bitSize %d\n", opndic[type].strType,zAddr+tarAddr, in, typeSize);
		if(!PLC_Register_set(type, zAddr+tarAddr, 0, (uint8*)&in, typeSize))
			return FALSE;
		return TRUE;
	}

	if(PLC_OPERAND_IsConstant(opnd))
	{
		//DBG_LOGPRINT("\t[ERROR %s] Invalid Device Address Type: Constant Type!\n", __FUNCTION__);
		return FALSE;
	}
	if(!checkErrorFromOperand(opnd, addr))
	{
		DBG_LOGPRINT("\t[ERROR %s] range: Constant Type!\n", __FUNCTION__);
		return FALSE;
	}
	if(bitSize == 1){
		uint16 ret = (uint16)in;
		if(in>1)
		{
			DBG_LOGPRINT("\t[ERROR %s] Invalid Device Type: bit type value > 1!\n", __FUNCTION__);
			return FALSE;
		}
		if(!PLC_Register_set(type, addr, 0, (uint8*)&ret, TYPE_BIT))
		{
			DBG_LOGPRINT("\t[ERROR %s] Setting Register has failed!\n", __FUNCTION__);
			return FALSE;
		}

	}
	else if(bitSize == 16)
	{
		uint16 ret = (uint16)in;
		//DBG_LOGPRINT("set type = %d, addr = %d, ret = %d\n", type, val, ret);
		if(!PLC_Register_set(type, addr, 0, (uint8*)&ret, TYPE_WORD))
		{
			DBG_LOGPRINT("\t[ERROR %s] Setting Register has failed!\n", __FUNCTION__);
			return FALSE;
		}
		//DBG_LOGPRINT("\t[device] set %d bit-size value(%ld) to %s%d\n",in_Bitsize, in, opnd->strType, val);
	}
	else if(bitSize == 32)
	{

		//uint32 ret = (uint16)in;
		//printf("in: %d\n", in);
		if(!PLC_Register_set(type, addr, 0, (uint8*)&in, TYPE_DWORD))
		{
			DBG_LOGPRINT("\t[ERROR %s] Setting Register has failed!\n", __FUNCTION__);
			return FALSE;
		}
		//DBG_LOGPRINT("\t[device] set %d bit-size value(%ld) to %s%d\n",in_Bitsize, in, opnd->strType, val);
	}
	else if(bitSize == 64)
	{
		long long ret =in;
		if(!PLC_Register_set(type, addr, 0, (uint8*)&ret, TYPE_LONG))
		{
			DBG_LOGPRINT("\t[ERROR %s] Setting Register has failed!\n", __FUNCTION__);
			return FALSE;
		}
		//DBG_LOGPRINT("\t[device] set %d bit-size value(%ld) to %s%d\n",in_Bitsize, in, opnd->strType, val);
	}
	else{
		DBG_LOGPRINT("\t[ERROR %s] Unknown type of bit size!\n", __FUNCTION__);
		return FALSE;
	}

	return TRUE;
}

inline uint8 PLC_DEVICE_copyDeviceBLKs(uint8* operand, uint8* in, uint16 length){
	uint8 bitSize;
	uint8 type  = operand[0];
	uint16 val;
	PLC_Operand* opnd;


	uint16* valPoint = (uint16*)& operand[1];
	//val =(0x0FF& operand[1])*256+(0x0FF&operand[2]);
	val = *valPoint;
	if(type == OPERAND_ML_CODE_N)
	{
		opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
		bitSize = val*4;
		type = operand[3];
		val = *(uint16*)& operand[4];
	}
	else if(type == OPERAND_ML_CODE_Z)
	{
		opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
		type = operand[3];
		val += *(uint16*)& operand[4];
		bitSize = opnd->nBitSize;
	}
	else
	{
		opnd = PLC_OPERAND_DICTIONARY_findOperand(type);
		bitSize = opnd->nBitSize;
	}


	if(PLC_OPERAND_IsConstant(opnd))
	{
		DBG_LOGPRINT("\t[ERROR %s] Invalid Device Address Type: Constant Type!\n", __FUNCTION__);
		return FALSE;
	}
	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return FALSE;
	}

	if(bitSize == 16|| bitSize == 32 || bitSize == 64)
	{

		uint8* dst = PLC_Register_getString(type, &val);

		//dst = &dst[val*bitSize/8];
		if((length+1)/2+val>opnd->nAddressCount)
		{
			handleExecError(ERROR_CODE_OUT_OF_DEVICE_RANGE);
			DBG_LOGPRINT("\t[ERROR %s] Address range error!", __FUNCTION__);

			return FALSE;
		}
		//DBG_LOGPRINT("[before]%s ==> [%s%d]%s\n", in, opndic[type].strType, val, dst);

		char* tempStringIn = (char*)malloc(strlen((char*)in)+1);
		strcpy(tempStringIn, (char*)in);
		memcpy(dst, tempStringIn, 2*((length+1)/2));
		free(tempStringIn);
		//DBG_LOGPRINT("[after]%s ==> [%s%d]%s\n", in, opndic[type].strType, val, dst);
		//DBG_LOGPRINT("\t[device] set %s%d to <String format :\"%s\">\n", opnd->strType, val, dst);
	}
	else{
		DBG_LOGPRINT("\t[ERROR %s] Unknown/mismatching type of bit size : %d <- %s...", __FUNCTION__, bitSize, opnd->strType);
		return FALSE;
	}
	return TRUE;
}

inline uint8 PLC_DEVICE_copyDeviceBLK_new(uint8 dstOpnd[], uint8 srcOpnd[], uint16 blockCount, uint8 blockWordSize, uint8 copyType){
	uint8 dstType, srcType;
	uint16 dstAddr, srcAddr;
	uint8 isDstNibble=FALSE, isSrcNibble = FALSE;

	uint8 dstBitSize;
	uint8 srcBitSize;
	//uint16 blockSize = length;
	int idxBlock;


	dstType = dstOpnd[0];
	srcType = srcOpnd[0];


	if(srcType == OPERAND_ML_CODE_Z)
	{
		if(!test_getWord(&srcAddr, OPERAND_ML_CODE_Z, *(uint16*)&srcOpnd[1]))
		{
			DBG_LOGPRINT("\t[ERROR %s] test_getWord src idx!\n",__FUNCTION__);
			return FALSE;
		}
		srcType = srcOpnd[3];
		srcAddr += *(uint16*)&srcOpnd[4];
		srcBitSize = blockWordSize*16;
	}
	else if(srcType == OPERAND_ML_CODE_N)
	{
		isSrcNibble = TRUE;
		srcBitSize = 4*(*(uint16*)&srcOpnd[1]);
		srcType = srcOpnd[3];
		srcAddr = *(uint16*)&srcOpnd[4];
	}
	else
	{
		srcAddr = *(uint16*)&srcOpnd[1];
		srcBitSize = blockWordSize*16;
	}

	if(dstType == OPERAND_ML_CODE_Z)
	{
		if(!test_getWord(&dstAddr, OPERAND_ML_CODE_Z, *(uint16*)&dstOpnd[1]))
		{
			DBG_LOGPRINT("\t[ERROR %s] test_getWord dst idx!\n",__FUNCTION__);
			return FALSE;
		}
		dstType = dstOpnd[3];
		dstAddr += *(uint16*)&dstOpnd[4];
		dstBitSize = blockWordSize*16;
	}
	else if(dstType == OPERAND_ML_CODE_N)
	{
		isDstNibble = TRUE;
		dstBitSize = 4*(*(uint16*)&dstOpnd[1]);
		dstType = dstOpnd[3];
		dstAddr = *(uint16*)&dstOpnd[4];

	}
	else
	{
		dstAddr = *(uint16*)&dstOpnd[1];
		dstBitSize = blockWordSize*16;
	}




	/*DBG_LOGPRINT("[in %s input]\n\t[%s%d] -> [%s%d] (size * count = %d * %d)\n\t\tisNibble = %d|%d, copyType : %d\n",
			__FUNCTION__,
			opndic[srcType].strType, srcAddr,
			opndic[dstType].strType, dstAddr,
			srcBitSize, blockCount,
			isSrcNibble, isDstNibble,
			copyType
			);*/

	for(idxBlock=0;idxBlock<blockCount;idxBlock++)
	{
		long long value=0;
		if(isSrcNibble)
		{
			//DBG_LOGPRINT("before value = %d\n" , value);
			if(!test_getNibble(&value, srcType, srcAddr+idxBlock*copyType*srcBitSize, srcBitSize/4))
			{
				DBG_LOGPRINT("\t[ERROR %s] test_getNibble src value!\n", __FUNCTION__);
				return FALSE;;
			}
			//DBG_LOGPRINT("From [N%d%s%d]\n", srcBitSize/4, opndic[srcType].strType,  srcAddr+idxBlock*copyType*srcBitSize);
		}
		else
		{
			if(srcBitSize==16)
			{
				if(!test_getWord((uint16*)&value, srcType, srcAddr+idxBlock*copyType))
				{
					DBG_LOGPRINT("\t[ERROR %s] test_getWord 16 src value : [%s%d]blockCount:%d!\n", __FUNCTION__, opndic[srcType].strType, srcAddr+idxBlock*copyType, blockCount);
					return FALSE;
				}
			}
			else if(srcBitSize == 32)
			{
				if(!test_getDWord((uint32*)&value, srcType, srcAddr+idxBlock*2*copyType))
				{
					DBG_LOGPRINT("\t[ERROR %s] test_getWord 32 src value : [%s%d]blockCount : %d!\n", __FUNCTION__, opndic[srcType].strType, srcAddr+idxBlock*copyType, blockCount);
					return FALSE;
				}
			}

			else if(srcBitSize == 64)
			{
				if(!test_getLong(&value, srcType, srcAddr+idxBlock*4*copyType))
				{
					DBG_LOGPRINT("\t[ERROR %s] test_getWord 64 src value : [%s%d]blockCount : %d!\n",__FUNCTION__, opndic[srcType].strType, srcAddr+idxBlock*copyType,blockCount);
					return FALSE;
				}
			}
			else
			{
				DBG_LOGPRINT("\t[ERROR %s] test_get: unable to load src bit size = %d!\n",__FUNCTION__, srcBitSize);
				return FALSE;
			}
			//DBG_LOGPRINT("From [%s%d+byte%d]==>%lld\n", opndic[srcType].strType,  srcAddr, idxBlock*copyType, value);
		}

		if(isDstNibble)
		{
			//char nibbleValue = value;
			if(!PLC_Register_setNibble(dstType, dstAddr+dstBitSize*idxBlock, value, dstBitSize/4))
			{
				DBG_LOGPRINT("\t[ERROR %s] setNibble : unable to save nibble!\n",__FUNCTION__);
				return FALSE;
			}
			//DBG_LOGPRINT("%lld => [N%d%s%d]\n", value, dstBitSize/4, opndic[dstType].strType,  dstAddr+4*idxBlock*copyType);

		}
		else
		{
			if(dstBitSize == 16)
			{
				value &=0x0FFFF;
				if(!PLC_Register_set(dstType, dstAddr+idxBlock, 0, (uint8*)&value, TYPE_WORD))
				{
					DBG_LOGPRINT("\t[ERROR %s] set 16: unable to save!\n",__FUNCTION__);
					return FALSE;
				}
			}
			else if(dstBitSize == 32)
			{
				value &=0x0FFFFFFFF;
				if(!PLC_Register_set(dstType, dstAddr+idxBlock*2, 0, (uint8*)&value, TYPE_DWORD))
				{
					DBG_LOGPRINT("\t[ERROR %s] set 32: unable to save!\n",__FUNCTION__);
					return FALSE;
				}
			}
			else if(dstBitSize == 64)
			{
				if(!PLC_Register_set(dstType, dstAddr+idxBlock*4, 0, (uint8*)&value, TYPE_LONG))
				{
					DBG_LOGPRINT("\t[ERROR %s] set 64: unable to save!\n",__FUNCTION__);
					return FALSE;
				}
			}
			else
			{
				DBG_LOGPRINT("\t[ERROR %s] set unrecognized size %d: unable to save!\n",__FUNCTION__, dstBitSize);
				return FALSE;
			}
			//DBG_LOGPRINT(" %lld => [%s%d+offset%d]\n", value, opndic[dstType].strType,  dstAddr, idxBlock*copyType);
		}
	}
	return TRUE;

}

inline uint8 PLC_DEVICE_setDeviceWordBit(uint8 operand[], short byteOffset, short bitOffset, uint8 setValue)
{

	if(operand[0]!=OPERAND_ML_CODE_WB)
	{
		DBG_LOGPRINT("[ERROR %s] not wordbit!\n", __FUNCTION__);
		return FALSE;
	}
	//DBG_LOGPRINT("bit Addr %d+%d, byte Addr %d %d\n", *(uint16*)&operand[1] , bitOffset, *(uint16*)&operand[4], byteOffset);
	short bitAddr = *(uint16*)&operand[1] + bitOffset;
	uint8 operandType = operand[3];
	uint16 byteAddr = *(uint16*)&operand[4] + byteOffset;
	if(bitAddr<0)
	{
		byteAddr--;
		bitAddr += 16;
	}
	else if(bitAddr>=16)
	{
		byteAddr++;
		bitAddr -=16;
	}
	//DBG_LOGPRINT("[PLC_DEVICE_setDeviceWordBit %s%d.%d]<==%d\n", opndic[operandType].strType, byteAddr, bitAddr, setValue);
	return PLC_Register_set(operandType, byteAddr, bitAddr, &setValue, TYPE_WORDBIT);
}

inline uint8 PLC_DEVICE_setDeviceBLKs(uint8 operand[], uint32 in, uint16 length, uint8 byteSize)
{

	uint8 type  = operand[0];
	uint16 val;
	PLC_Operand* opnd = PLC_OPERAND_DICTIONARY_findOperand(type);

	//val =(0x0FF& operand[1])*256+(0x0FF&operand[2]);
	uint16* valPoint =(uint16*)&operand[1];
	val = *valPoint;

	if(PLC_OPERAND_IsConstant(opnd))
	{
		DBG_LOGPRINT("\t[ERROR %s] Invalid Device Address Type: Constant Type!\n", __FUNCTION__);
		return FALSE;
	}
	if(!checkErrorFromOperand(opnd, val))
	{
		DBG_LOGPRINT("[ERROR %s] Line : %d!\n", __FUNCTION__, __LINE__);
		return FALSE;
	}

	if(byteSize == 2)
	{
		uint16* dst = (uint16*)PLC_Register_getString(type, &val);
		if(dst==NULL)
			return FALSE;
		int i;
		for(i=0;i<length;i++)
		{
			dst[i]=in;
		}
		//DBG_LOGPRINT("\t[device] set %s%d-%s%d to %d\n", opnd->strType, val, opnd->strType,val+length, in);
	}else if(byteSize == 4)
	{
		uint32* dst = (uint32*)PLC_Register_getString(type, &val);
		if(dst==NULL)
			return FALSE;
		int i;
		for(i=0;i<length;i++)
		{
			dst[i]=in;
		}
		//DBG_LOGPRINT("\t[device] set %s%d-%s%d to %d\n", opnd->strType, val, opnd->strType,val+length, in);
	}
	else if(byteSize == 8)
	{
		long* dst = (long*)PLC_Register_getString(type, &val);
		if(dst==NULL)
			return FALSE;
		int i;
		for(i=0;i<length;i++)
		{
			dst[i]=in;
		}
		//DBG_LOGPRINT("\t[device] set %s%d-%s%d to %d\n", opnd->strType, val, opnd->strType,val+length, in);
	}
	else{
		DBG_LOGPRINT("\t[ERROR %s] Unknown/mismatching type of bit size...", __FUNCTION__);
		return FALSE;
	}
	return TRUE;
}


inline uint8 PLC_DEVICE_getStepValue(){
	return dev.nStep[dev.currStepIdx];
}
inline uint8 PLC_DEVICE_setStepValue(uint8 stepValue){
	if(dev.currStepIdx >=PLC_DEFINITION_MAX_STEP)
		return FALSE;
	dev.nStep[dev.currStepIdx]= stepValue;
	return TRUE;
}
inline uint8 PLC_DEVICE_increaseStep(uint8 result){
	if(dev.currStepIdx >=PLC_DEFINITION_MAX_STEP)
	{
		DBG_LOGPRINT("\tPLC_DEVICE_increaseStep: step overflowed!\n");
		return FALSE;
	}
	dev.currStepIdx++;
	return result;
}
inline uint8 PLC_DEVICE_saveBlockResult(uint8 in)
{
	return STACK_push(&(dev.device_block_stack), in)==STACK_TRUE;
}
inline uint8 PLC_DEVICE_overWirteBlockResult(uint8 in)
{
	if(dev.device_block_stack.size==STACK_SIZE)
		return FALSE;
	STACK_overwrite(&(dev.device_block_stack), in);
#if PLC_LOG_DEF
	DBG_LOGPRINT("STACK OVERWRITE : %d\n", in);
#endif
	//DBG_LOGPRINT("Overwriting block stack when size is %d!\n",dev.device_block_stack.size);
	return TRUE;
}
inline uint16 PLC_DEVICE_pickBlockResult(){
	if(dev.device_block_stack.size==0)
		return STACK_FALSE;
	//DBG_LOGPRINT("Picking block stack when size is %d!\n",dev.device_block_stack.size);
	return STACK_pick(&(dev.device_block_stack));
}
inline uint16 PLC_DEVICE_pullBlockResult(){
	//uint8 out;
	if(dev.device_block_stack.size==0)
		return STACK_FALSE;
	//DBG_LOGPRINT("blockStackPulling : size = %d-1\n", dev.device_block_stack.size);
	//DBG_LOGPRINT("Pulling block stack when size is %d!\n",dev.device_block_stack.size);
	return STACK_pull(&(dev.device_block_stack));
}
inline uint32 checkErrorFromOperand(PLC_Operand* opnd, uint16 val){
	if(opnd==NULL)
	{
		printf("function = %s, line = %d\n", __FUNCTION__, __LINE__);
		DBG_LOGPRINT("[ERROR %s] Invalid operand value: not in dictionary!\n", __FUNCTION__);
		return FALSE;
	}
	if(!PLC_OPERAND_isValid(opnd, val) && opnd->nMLCode!=OPERAND_ML_CODE_N && opnd->nMLCode!=OPERAND_ML_CODE_WB )
	{

		//printf("function = %s, line = %d\n", __FUNCTION__, __LINE__);
		DBG_LOGPRINT("[ERROR %s] Invalid Device Address Value: Out of range!(opnd:%s, val:%d)\n", __FUNCTION__,opnd->strType, val);
		//DBG_LOGPRINT("[ERROR %s] Invalid Device Address Value: Out of range!(opnd:%s, val:%d)\n", __FUNCTION__,opnd->strType, val);
		return FALSE;
	}
	return TRUE;
}