/*
 * PLC_Register.c
 *
 *  Created on: 2015. 2. 12.
 *      Author: skson
 */

#ifndef PLC_REGISTER_H_
#include "PLC_Register.h"
#endif

#include <sys/time.h>
#include <stdlib.h>
#include "PLC_Log.h"
#include "PLC_Register_Log.h"
#include "PLC_RealDevice.h"

static PLC_Register regPLC;
static char* changedLog=NULL;
static char buf[100];

inline uint8 PLC_Register_setAsLatch(uint8 regTypeAsMLOperand, uint16 latchStart, uint16 latchLast)
{
	//todo: myjob
	DBG_LOGPRINT("Setting as latch type : %s[%d-%d]\n", opndic[regTypeAsMLOperand].strType, latchStart, latchLast);
	if(latchLast<latchStart)
		return FALSE;
	if(opndic[regTypeAsMLOperand].nBitSize ==1)
	{
		if(latchStart%8!=0)
		{
			DBG_LOGPRINT("[ERROR] latchStart %d mod 8 != 0!\n", latchStart);
			return FALSE;
		}
		if(latchLast%8!=7)
		{
			DBG_LOGPRINT("[ERROR] latchLast %d mod 8 != 7!\n", latchLast);
			return FALSE;
		}
	}

	return PLC_Register_setLatch(regTypeAsMLOperand, latchStart, latchLast - latchStart + 1);
}

inline uint8 PLC_Register_setAsNonlatch(uint8 regTypeAsMLOperand)
{
	//todo: myjob
	if(regTypeAsMLOperand>=OPERAND_ML_CODE_MAX)
		return FALSE;
	PLC_Register_getRegister()->listRegister[regTypeAsMLOperand].hasLatch=FALSE;
	return TRUE;
}

inline int PLC_Register_getLatchByteSize(uint8 regTypeAsMLOperand)
{
	int operandSize = PLC_Register_getRegister()->listRegister[regTypeAsMLOperand].RefOperand->nBitSize;
	return (operandSize * PLC_Register_getRegister()->listRegister[regTypeAsMLOperand].latchSize)/ 8;
}

inline int PLC_Register_getTotalLatchByteSize()
{
	int i;
	int size = 0;
	for(i=0;i<OPERAND_ML_CODE_MAX;i++)
	{
		size +=  PLC_Register_getLatchByteSize(i);
	}
	return size;
}

inline uint8 PLC_Register_setLatch(uint8 operandML, uint16 latchHead, uint16 latchSize)
{
	//if(PLC_Register_getRegister()->listRegister[operandML].RefOperand->nBitSize!=1 )
	{
		if(PLC_Register_getRegister()->listRegister[operandML].RefOperand->nAddressCount<latchHead+latchSize)
			return FALSE;
	}
	/*else
	{
		if(PLC_Register_getRegister()->listRegister[operandML].RefOperand->nAddressCount<16*(latchHead+latchSize))
			return FALSE;
	}*/
	PLC_Register_getRegister()->listRegister[operandML].hasLatch=TRUE;
	PLC_Register_getRegister()->listRegister[operandML].latchHead = latchHead;
	PLC_Register_getRegister()->listRegister[operandML].latchSize = latchSize;
	DBG_LOGPRINT("[TOTAL SIZE OF LATCH] %d!\n", PLC_Register_getTotalLatchByteSize());
	return TRUE;
}

inline PLC_Register* PLC_Register_getRegister(){
	return &regPLC;
	//return (PLC_Register*)getFromMVRam();
}

inline void PLC_Register_init(){
	int i;
	uint8* realDevice = PLC_RealDevice_getRealDevice();
	for(i=0;i<OPERAND_ML_CODE_MAX;i++)
	{
		if(i == OPERAND_ML_CODE_Zin)
			continue;
		PLC_Register_getRegister()->listRegister[i].RefOperand = (void*)&opndic[i];
		PLC_Register_getRegister()->listRegister[i].registerHead = &realDevice[OPND_DICT_getOperandRegHeadOffset(i)];
		memset(PLC_Register_getRegister()->listRegister[i].registerHead, 0, OPND_DICT_getOperandRegByteSize(i));

		PLC_Register_getRegister()->listRegister_old[i].RefOperand = (void*)&opndic[i];

		PLC_Register_getRegister()->listRegister_old[i].registerHead = &realDevice[OPND_DICT_getOperandRegHeadOffset_old(i)];
		memset(PLC_Register_getRegister()->listRegister_old[i].registerHead, 0, OPND_DICT_getOperandRegByteSize(i));
		PLC_Register_getRegister()->listRegister[i].hasLatch=FALSE;
		//DBG_LOGPRINT("Reg init : %s\n", opndic[i].strType );
		//printf("%s [%d * %d / 16] Val = %d\n", opndic[i].strType, opndic[i].nAddressCount,opndic[i].nBitSize,((uint16)*(uint16*)(PLC_Register_getRegister()->listRegister[i].registerHead)));
	}
	//DBG_LOGPRINT("init : SM700 = %d\n", PLC_Register_getBit(OPERAND_ML_CODE_SM, 700));
	memset(PLC_Register_getRegister()->T_curr, 0, sizeof(unsigned long)*OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->T_remained, 0, sizeof(unsigned long)*OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->T_isOn, 0, sizeof(uint16)*OPERAND_SIZE_C);
	memset(PLC_Register_getRegister()->T_ret, 0, sizeof(uint16)*OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->T_set, 0, sizeof(long long)*OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->C_curr, 0, OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->C_isOn, 0, OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->C_ret, 0, OPERAND_SIZE_C);
	memset(PLC_Register_getRegister()->T_ret_old, 0, OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->C_ret_old, 0, OPERAND_SIZE_C);
	//PLC_Register_recoverLatch();
	QueueLog_Init();
	//PLC_Register_reset();
}

inline void PLC_Register_reset(){
	int i;
	for(i=0;i<OPERAND_ML_CODE_MAX;i++) if(i!=OPERAND_ML_CODE_L && i!=OPERAND_ML_CODE_W)
	{
		if(PLC_Register_getRegister()->listRegister[i].hasLatch==FALSE)
		{
			memset(PLC_Register_getRegister()->listRegister[i].registerHead, 0, OPND_DICT_getOperandRegByteSize(i));
			memset(PLC_Register_getRegister()->listRegister_old[i].registerHead, i, 0);
		}
		else
		{
			uint16 latchHeadPoint ;
			uint16 latchSize ;

			latchHeadPoint = PLC_Register_getRegister()->listRegister[i].latchHead;
			latchSize = PLC_Register_getRegister()->listRegister[i].latchSize;

			memcpy(
					&(PLC_Register_getRegister()->listRegister[i].registerHead[latchHeadPoint]),
					&(PLC_Register_getRegister()->listRegister_old[i].registerHead[latchHeadPoint]),
					latchSize*sizeof(uint16)
					);
			memset(PLC_Register_getRegister()->listRegister[i].registerHead, 0, OPND_DICT_getOperandRegByteSize(i));
			memcpy(
					&(PLC_Register_getRegister()->listRegister_old[i].registerHead[latchHeadPoint]),
					&(PLC_Register_getRegister()->listRegister[i].registerHead[latchHeadPoint]),
					latchSize*sizeof(uint16)
					);
			memset(PLC_Register_getRegister()->listRegister_old[i].registerHead, i, 0);
		}

	}
	memset(PLC_Register_getRegister()->T_curr, 0, sizeof(unsigned long)*OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->T_remained, 0, sizeof(unsigned long)*OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->T_isOn, 0, sizeof(uint16)*OPERAND_SIZE_C);
	memset(PLC_Register_getRegister()->T_ret, 0, sizeof(uint16)*OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->C_curr, 0, OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->C_isOn, 0, OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->C_ret, 0, OPERAND_SIZE_C);
	memset(PLC_Register_getRegister()->T_ret_old, 0, OPERAND_SIZE_T);
	memset(PLC_Register_getRegister()->C_ret_old, 0, OPERAND_SIZE_C);
	PLC_Register_recoverLatch();
	QueueLog_Init();
}

inline void PLC_Register_print(){
	int i, j;
	for(i=0;i<OPERAND_ML_CODE_MAX;i++)
	{
		uint16 regSize =opndic[i].nAddressCount * opndic[i].nBitSize / 16;
		printf("%s\n",opndic[i].strType);
		for(j=0;j<regSize;j++)
		{
			uint16* val = PLC_Register_getRegister()->listRegister[i].registerHead;
			printf("%d ",(uint16)val[j]);
			if(j%32==31)
				printf("\n");
			else if(j%8==7)
				printf("\t");
		}
		printf("\n");
	}
}
inline void PLC_Register_print_old(){
	int i, j;
	for(i=0;i<OPERAND_ML_CODE_MAX;i++)
	{
		uint16 regSize =opndic[i].nAddressCount * opndic[i].nBitSize / 16;
		printf("%s_old\n",opndic[i].strType);
		for(j=0;j<regSize;j++)
		{
			uint16* val = PLC_Register_getRegister()->listRegister_old[i].registerHead;
			printf("%d ",(uint16)val[j]);
			if(j%32==31)
				printf("\n");
			else if(j%8==7)
				printf("\t");
		}
		printf("\n");
	}
}
inline uint8 PLC_Register_set(uint8 ML_code, uint16 ML_Addr, uint8 ML_bit_Addr, uint8* setValue, uint8 setType){
	//DBG_LOGSCAN(buf, "\t[CHECK %s] input : %d, %d, %d, %d, %d\n",__FUNCTION__,ML_code, ML_Addr, ML_bit_Addr, *(uint16*)setValue, setType);PLC_LOG_addLog(buf);
	//printf("%s : %d\n", __FUNCTION__,__LINE__);
	/*DBG_LOGPRINT("input : [%s%d.%d]val = %d, setType = %d\n",
			opndic[ML_code].strType, ML_Addr, ML_bit_Addr, *setValue,
			setType);*/
	uint32 runtimeCount = PLC_DEVICE_getCurrTimeScan();
	uint16* setValue16 = (uint16*)setValue;
	if(ML_code >= OPERAND_ML_CODE_MAX)
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		//DBG_LOGSCAN(buf, "\t[ERROR %s] Line : %d\n", __FUNCTION__, __LINE__);PLC_LOG_addLog(buf);
		return FALSE;
	}
	if(ML_code == OPERAND_ML_CODE_Zin)
	{
		uint16* set = (uint16*)setValue;
		PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_Z].registerHead[ML_Addr]  = *set;
		return TRUE;
	}
	if(ML_code == OPERAND_ML_CODE_U)
	{
		return PLC_RealDevice_setUxGx(ML_bit_Addr, ML_Addr, setValue16);
	}
	if(setType == TYPE_LINKED_DEVICE)
	{
		return PLC_RealDevice_setJxxx(ML_bit_Addr, ML_code, ML_Addr, setValue16);
	}
	if(ML_code == OPERAND_ML_CODE_T)
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		if(ML_Addr>=OPERAND_SIZE_T)
		{
			//printf("%s : %d\n", __FUNCTION__,__LINE__);
			return FALSE;
		}
		PLC_Register_setTValue(ML_Addr, VALUE_TYPE_SET, *setValue16);
		//PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_T].registerHead[ML_Addr] = 0;
		return TRUE;
	}
	if(ML_code == OPERAND_ML_CODE_C)
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		if(ML_Addr>=OPERAND_SIZE_C)
		{
			//printf("%s : %d\n", __FUNCTION__,__LINE__);
			return TRUE;
		}
		PLC_Register_setCValue(ML_Addr, VALUE_TYPE_SET, *setValue16);
		//PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_C].registerHead[ML_Addr] = 0;
		return TRUE;
	}
	//printf("%s : %d\n", __FUNCTION__,__LINE__);
	if(setType == TYPE_BIT||setType ==TYPE_WORDBIT)
	{
		uint16 currShortValue;
		uint16 bytePos;
		uint16 bitPos;
		if(setType == TYPE_BIT)
		{
			bytePos = (ML_Addr)/16;
			bitPos = ML_Addr%16;
		}
		else
		{
			bytePos = ML_Addr;
			bitPos = ML_bit_Addr;
		}

		if(bytePos >= OPND_DICT_getOperandRegByteSize(ML_code))
		{
			//DBG_LOGPRINT("\t[ERROR %s] Line : %d\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		currShortValue = PLC_Register_getRegister()->listRegister[ML_code].registerHead[bytePos];

		if((currShortValue>>bitPos)%2==0  && *setValue==1)
		{

			PLC_Register_getRegister()->listRegister[ML_code].registerHead[bytePos] += (1<<bitPos);
			//DBG_LOGPRINT("%d\n",PLC_Register_getRegister()->listRegister[ML_code].registerHead[bytePos]);
		}
		else if((currShortValue>>bitPos)%2==1  && *setValue==0)
		{
			//DBG_LOGPRINT("[%s%d.%d] %d => ", opndic[ML_code].strType, bytePos, bitPos);
			PLC_Register_getRegister()->listRegister[ML_code].registerHead[bytePos] -= (1<<bitPos);
			//DBG_LOGPRINT("%d\n",PLC_Register_getRegister()->listRegister[ML_code].registerHead[bytePos]);
		}
		if(setType == TYPE_BIT)
			QueueLog_AddLog(ML_code, ML_Addr, currShortValue>>bitPos, *setValue, runtimeCount);
		else
			QueueLog_AddLog(ML_code, ML_Addr, currShortValue, PLC_Register_getRegister()->listRegister[ML_code].registerHead[bytePos], runtimeCount);
#if PLC_LOG_DEF
		uint8 val = 0;
		test_getBit(&val, ML_code, ML_Addr);
		DBG_LOGPRINT("[%s%d] <=%d\n",opndic[ML_code].strType, ML_Addr,  val);
#endif
//#if PLC_LOG_DEF
	//	DBG_LOGPRINT("Reg set : [%s%d]%04X\n", PLC_Register_getRegister()->listRegister[ML_code].RefOperand->strType, PLC_Register_getRegister()->listRegister[ML_code].registerHead[bytePos]);
//#endif
		//DBG_LOGSCAN(buf, "\t[ERROR %s] Line : %d\n", __FUNCTION__, __LINE__);PLC_LOG_addLog(buf);
		return TRUE;
	}
	else if(setType == TYPE_NIBBLE)
	{
		//DBG_LOGSCAN(buf, "\t[%s] Line : %d\n", __FUNCTION__, __LINE__);PLC_LOG_addLog(buf);
		return PLC_Register_setNibble(ML_code, ML_Addr, *setValue, 1);
	}

	else if(ML_Addr >= opndic[ML_code].nAddressCount)
	{
		DBG_LOGPRINT(buf, "\t[ERROR %s] Line : %d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	else if(setType == TYPE_WORD)
	{
		//DBG_LOGPRINT("\t[%s%d] <==%d, Line : %d\n", opndic[ML_code].strType, ML_Addr, *setValue, __LINE__);
		uint16* set = (uint16*)setValue;
		if(ML_code != OPERAND_ML_CODE_T && ML_code != OPERAND_ML_CODE_C)
			QueueLog_AddLog(ML_code, ML_Addr, PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr] , setValue16[0], runtimeCount);
		PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr]  = *set;
		return TRUE;
	}
	else if(setType == TYPE_DWORD || setType == TYPE_FLOAT)
	{

		//DBG_LOGSCAN(buf, "\t[%s] Line : %d\n", __FUNCTION__, __LINE__);PLC_LOG_addLog(buf);
		QueueLog_AddLog(ML_code, ML_Addr, PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr], setValue16[0], runtimeCount);
		QueueLog_AddLog(ML_code, ML_Addr+1, PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr+1], setValue16[1], runtimeCount);
		uint32* tar = (uint32*)&(PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr]);
		memcpy(tar ,setValue, 4);
		return TRUE;
	}
	else if(setType == TYPE_LONG || setType == TYPE_DOUBLE)
	{
		//DBG_LOGSCAN(buf, "\t[ERROR %s] Line : %d\n", __FUNCTION__, __LINE__);PLC_LOG_addLog(buf);
		if(ML_Addr*opndic[ML_code].nBitSize/8+8>OPND_DICT_getOperandRegByteSize(ML_code))
			return FALSE;
		uint8* tar = (uint8*)&(PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr]);
		QueueLog_AddLog(ML_code, ML_Addr, PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr], setValue16[0], runtimeCount);
		QueueLog_AddLog(ML_code, ML_Addr+1, PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr+1], setValue16[1], runtimeCount);
		QueueLog_AddLog(ML_code, ML_Addr+2, PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr+2], setValue16[2], runtimeCount);
		QueueLog_AddLog(ML_code, ML_Addr+3, PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr+3], setValue16[3], runtimeCount);

		memcpy(tar ,setValue, 8);
		return TRUE;
	}
	else if(setType == TYPE_STRING)
	{
		//DBG_LOGSCAN(buf, "\t[%s] Line : %d\n", __FUNCTION__, __LINE__);PLC_LOG_addLog(buf);
		int strLength = (strlen((char*)setValue)+1)/2*2;
		int idx;
		if(ML_Addr*opndic[ML_code].nBitSize/8+strlen((char*)setValue)>OPND_DICT_getOperandRegByteSize(ML_code))
			return FALSE;
		char* tar = (char*)&(PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr]);
		uint16* oldmemory = (uint16*)malloc(strLength);
		memcpy(oldmemory, tar, strLength);
		strcpy(tar ,(char*)setValue);
		for(idx= 0; idx<strLength/2; idx++)
		{
			QueueLog_AddLog(ML_code, ML_Addr+idx, oldmemory[idx], PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr+idx], runtimeCount);
		}
		free(oldmemory);
		return TRUE;
	}
	else
	{
		DBG_LOGPRINT("\t[%s] Line : %d\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
}

inline uint8 PLC_Register_setNibble(uint8 ML_code, uint16 ML_Addr, long long setValue, uint8 nibbleCount){
	if(opndic[ML_code].nBitSize!=1)
	{
		DBG_LOGPRINT("\t[ERROR %s] %s is not a bit register!\n", __FUNCTION__, opndic[ML_code].strType);
		return FALSE;
	}

	uint8 set;
	int idxNibble;
	//DBG_LOGPRINT("%s input : %s%d <= %d, N%d\n", __FUNCTION__, opndic[ML_code].strType, ML_Addr, setValue, nibbleCount);
	if(ML_Addr+4*nibbleCount> opndic[ML_code].nAddressCount)
	{
		DBG_LOGPRINT("\t[ERROR %s] Out of address! : %s %d(addr) > %d(MaxAddr)\n", __FUNCTION__, opndic[ML_code].strType, ML_Addr+4*nibbleCount, opndic[ML_code].nAddressCount-1);
		return FALSE;
	}
	for(idxNibble=0;idxNibble<4*nibbleCount;idxNibble++)
	{

		set=((setValue>>idxNibble)&0x01);

		PLC_Register_set(ML_code, ML_Addr+idxNibble, 0, &set, TYPE_BIT);

		//DBG_LOGPRINT("set nibble bit[%s %d]<==%d\n", opndic[ML_code].strType, ML_Addr+idxNibble,set);

	}
	return TRUE;
}

inline void* PLC_Register_getPos_old(uint8 ML_code, uint16 ML_Addr, uint8 getType){
	if(ML_code >= OPERAND_ML_CODE_MAX)
		return FALSE;
	if(ML_code==OPERAND_ML_CODE_C)
	{
		return &PLC_Register_getRegister()->C_ret_old[ML_Addr];
	}
	if(ML_code==OPERAND_ML_CODE_T)
	{
		return &PLC_Register_getRegister()->T_ret_old[ML_Addr];
	}
	if(getType == TYPE_BIT)
	{
		uint16 bytePos = ML_Addr/16;

		if(bytePos >= OPND_DICT_getOperandRegByteSize(ML_code))
			return NULL;

		return &PLC_Register_getRegister()->listRegister_old[ML_code].registerHead[bytePos];
	}

	if(ML_Addr >= opndic[ML_code].nAddressCount)
		return FALSE;

	if(getType == TYPE_WORD ||
			getType == TYPE_DWORD ||
			getType == TYPE_FLOAT ||
			getType == TYPE_LONG ||
			getType == TYPE_DOUBLE ||
			getType == TYPE_STRING)
	{
		return (void*)&(PLC_Register_getRegister()->listRegister_old[ML_code].registerHead[ML_Addr]);
	}
	return NULL;
}

inline void* PLC_Register_getPos(uint8 ML_code, uint16 ML_Addr, uint8 getType){
	//printf("__LINE__:%d\n",__LINE__);
	if(ML_code >= OPERAND_ML_CODE_MAX){
		printf("[ERROR %s] Error : ML_code %d >= OPERAND_ML_CODE_MAX=22!\n", __FUNCTION__, ML_code);
		return NULL;
	}
	if(ML_code==OPERAND_ML_CODE_C)
	{
		if(ML_Addr>=OPERAND_SIZE_C)
		{
			DBG_LOGPRINT("[ERROR] %s%d ML_Addr >= OPERAND_SIZE_C\n", __FUNCTION__, __LINE__);
			return NULL;
		}
		return &(PLC_Register_getRegister()->C_ret[ML_Addr]);
	}
	if(ML_code==OPERAND_ML_CODE_T)
	{
		if(ML_Addr>=OPERAND_SIZE_T)
		{
			DBG_LOGPRINT("[ERROR] %s%d ML_Addr >= OPERAND_SIZE_T\n", __FUNCTION__, __LINE__);
			return NULL;
		}
		return (void*)&(PLC_Register_getRegister()->T_ret[ML_Addr]);
	}
	if(PLC_OPERAND_DICTIONARY_findOperand(ML_code)->bIsConstant)
	{
		//printf("[ERROR %s] Error : is constant!\n", __FUNCTION__);
		return NULL;
	}

	if(getType == TYPE_BIT)
	{

		uint16 bytePos = (ML_Addr)/16;

		if(bytePos >= OPND_DICT_getOperandRegByteSize(ML_code)){
			//printf("[ERROR %s] Error : bitePos >= device size!\n", __FUNCTION__);
			DBG_LOGPRINT("[ERROR] %s%d bytePos >= OPND_DICT_getOperandRegByteSize(%d)\n", __FUNCTION__, __LINE__, ML_code);
			return NULL;
		}
		//printf("bytePos = %d\n",bytePos);
		return (void*)&(PLC_Register_getRegister()->listRegister[ML_code].registerHead[bytePos]);
	}

	if(getType == TYPE_NIBBLE)
	{
		//printf("[ERROR %s] Error : Nibble must be parsed!\n", __FUNCTION__);
		DBG_LOGPRINT("[ERROR] %s%d getType == TYPE_NIBBLE\n", __FUNCTION__, __LINE__);
		return NULL;
	}
	if(getType == TYPE_WORDBIT)
	{
		//printf("[ERROR %s] Error : Wordbit must be parsed!\n", __FUNCTION__);
		DBG_LOGPRINT("[ERROR] %s%d getType == TYPE_WORDBIT\n", __FUNCTION__, __LINE__);
		return NULL;
	}

	if(ML_Addr >= opndic[ML_code].nAddressCount)
	{
		//printf("[ERROR %s] Error : ML_Addr %s%d >= %d AddressCount !\n", __FUNCTION__, PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType, ML_Addr , opndic[ML_code].nAddressCount);
		DBG_LOGPRINT("[ERROR] %s%d ML_Addr >= %s.nAddressCount\n", __FUNCTION__, __LINE__, opndic[ML_code].strType);
		return NULL;
	}
	if(
			getType == TYPE_WORD ||
			getType == TYPE_DWORD ||
			getType == TYPE_FLOAT ||
			getType == TYPE_LONG ||
			getType == TYPE_DOUBLE ||
			getType == TYPE_STRING)
	{
		return (void*)&(PLC_Register_getRegister()->listRegister[ML_code].registerHead[ML_Addr]);
	}

	return NULL;
}

inline void PLC_Register_saveFast(){
	int i;
	for(i=0;i<OPERAND_ML_CODE_MAX;i++)
	{
		memcpy(PLC_Register_getRegister()->listRegister_old[i].registerHead, PLC_Register_getRegister()->listRegister[i].registerHead, OPND_DICT_getOperandRegByteSize(i));

	}
	memcpy(PLC_Register_getRegister()->C_ret_old, PLC_Register_getRegister()->C_ret, OPERAND_SIZE_C);
	memcpy(PLC_Register_getRegister()->T_ret_old, PLC_Register_getRegister()->T_ret, OPERAND_SIZE_T);
	PLC_Register_backupLatch();
}

inline void PLC_Register_backupLatch()
{
	int i;
	int realDevOffset = 0;
	uint8* latchTarget = (uint8*)PLC_RealDevice_getLatchPoint();
	for(i=0;i<OPERAND_ML_CODE_MAX;i++)
	if(latchTarget!=NULL && PLC_Register_getRegister()->listRegister[i].hasLatch)
	{

		int typeSize = PLC_Register_getRegister()->listRegister[i].RefOperand->nBitSize;
		int latchSize = PLC_Register_getRegister()->listRegister[i].latchSize;
		int byteSize = (latchSize * typeSize)/8;// + 7)/8;

		int latchStart = PLC_Register_getRegister()->listRegister[i].latchHead * typeSize / 8;
		uint8* src = (uint8*)&PLC_Register_getRegister()->listRegister[i].registerHead[latchStart];
		uint8* dst = (uint8*)&latchTarget[realDevOffset];
		memcpy(dst, src, byteSize);
		DBG_LOGPRINT("[Backup latch] [%s%d(ByteAddr = %d)] [byteSize : %d]\n",
				PLC_Register_getRegister()->listRegister[i].RefOperand->strType,
				PLC_Register_getRegister()->listRegister[i].latchHead, latchStart,
				byteSize);
		realDevOffset += byteSize;
	}
}

inline void PLC_Register_recoverLatch()
{

	int i;
	int realDevOffset = 0;
	uint8* latchTarget = (uint8*)PLC_RealDevice_getLatchPoint();
	for(i=0;i<OPERAND_ML_CODE_MAX;i++)
	{
		if(latchTarget!=NULL && PLC_Register_getRegister()->listRegister[i].hasLatch)
		{
			int typeSize = PLC_Register_getRegister()->listRegister[i].RefOperand->nBitSize;
			int latchSize = PLC_Register_getRegister()->listRegister[i].latchSize;
			int byteSize = (latchSize * typeSize)/8;// + 7)/8;

			int latchStart = PLC_Register_getRegister()->listRegister[i].latchHead * typeSize / 8;
			uint8* dst = (uint8*)&PLC_Register_getRegister()->listRegister[i].registerHead[latchStart];
			uint8* src = (uint8*)&latchTarget[realDevOffset];

			memcpy(dst, src, byteSize);
			DBG_LOGPRINT("[Recover latch] [%s%d(ByteAddr = %d)] [byteSize : %d]\n",
					PLC_Register_getRegister()->listRegister[i].RefOperand->strType,
					PLC_Register_getRegister()->listRegister[i].latchHead, latchStart,
					byteSize);
			realDevOffset += byteSize;
		}
	}
}

inline uint32 PLC_Register_isPulse(uint8 ML_code, uint16 ML_Addr, uint8 bitPosition){
	uint8 currValue = PLC_Register_getBit(ML_code, ML_Addr);
	uint8 oldValue = PLC_Register_getBit_old(ML_code, ML_Addr);
	if(currValue==0xFF || oldValue==0xFF)
		return PLC_FALSE_32;
	return (currValue==1) && (oldValue==0);
}

inline uint8 PLC_Register_getBit(uint8 ML_code, uint16 ML_Addr){
	uint16* value = (uint16*)PLC_Register_getPos(ML_code, ML_Addr, TYPE_BIT);
	if( value == NULL )
		return (uint8)ML_Addr;
	uint8 bitPos = ML_Addr%16;
	uint8 val = (*value>>bitPos) & 0x01;
	return val;
}

inline uint8 PLC_Register_getWordBit(uint8 ML_code, uint16 ML_Addr, uint8 bitAddr){
	//DBG_LOGSCAN(buf, "\t[%s%d]\n", __FUNCTION__, __LINE__);PLC_LOG_addLog(buf);
	uint32 value = PLC_Register_getWord(ML_code, ML_Addr);

	/*DBG_LOGSCAN(buf, "\t[%s%d] %s%d = %04X\n", __FUNCTION__, __LINE__, PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType,
				ML_Addr,value
		);PLC_LOG_addLog(buf);*/
	if(value==PLC_FALSE_32)
		return 0xFF;
	uint8 bitPos = bitAddr;
	uint8 val = (value>>bitPos) & 0x01;
	/*DBG_LOGPRINT("\t[%s%d] %s%d = %04X ==> LOAD %d\n", __FUNCTION__, __LINE__, PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType,
						ML_Addr,value,val
				);*/
	return val;
}

uint8 PLC_Register_getWordBit_old(uint8 ML_code, uint16 ML_Addr, uint8 bitAddr){
	//DBG_LOGSCAN(buf, "\t[%s%d]\n", __FUNCTION__, __LINE__);PLC_LOG_addLog(buf);
	uint32 value = PLC_Register_getWord_old(ML_code, ML_Addr);

	/*DBG_LOGSCAN(buf, "\t[%s%d] %s%d = %04X\n", __FUNCTION__, __LINE__, PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType,
				ML_Addr,value
		);PLC_LOG_addLog(buf);*/
	if(value==PLC_FALSE_32)
		return 0xFF;
	uint8 bitPos = bitAddr;
	uint8 val = (value>>bitPos) & 0x01;
	/*DBG_LOGPRINT("\t[%s%d] %s%d = %04X ==> LOAD %d\n", __FUNCTION__, __LINE__, PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType,
						ML_Addr,value,val
				);*/
	return val;
}

inline uint32 PLC_Register_getNibble(uint8 ML_code, uint16 ML_Addr, uint8 nibbleCount){
	uint32 val=0;
	if(opndic[ML_code].nBitSize==1)
	{
		int nibbleIdx;
		int binConst = 1;
		for(nibbleIdx = 0; nibbleIdx < 4*nibbleCount; nibbleIdx++)
		{
			val += binConst*PLC_Register_getBit(ML_code, ML_Addr+nibbleIdx);
			binConst*=2;
		}
		/*
		DBG_LOGPRINT("\t[%s%d]%s %X\n"
							,PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType, ML_Addr
							,__FUNCTION__
							,val
							);*/
	}
	else{
		/*
		val = PLC_Register_getWord(ML_code, ML_Addr);
		val = (val>>nibbleCount) & 0x0F;
		*/
		DBG_LOGPRINT("[ERROR]in %s %d :: %s%d\n", __FUNCTION__, __LINE__, opndic[ML_code].strType, ML_Addr);
		return PLC_FALSE_32;
	}


	return val;
}

inline uint8 PLC_Register_getNibble_old(uint8 ML_code, uint16 ML_Addr, uint8 wordBit){
	uint8 val;
	if(PLC_OPERAND_DICTIONARY_findOperand(ML_code)->nBitSize==1)
	{

		val = PLC_Register_getBit_old(ML_code, ML_Addr)+
				PLC_Register_getBit_old(ML_code, ML_Addr+1)*2+
				PLC_Register_getBit_old(ML_code, ML_Addr+2)*4+
				PLC_Register_getBit_old(ML_code, ML_Addr+3)*8;
		/*DBG_LOGSCAN(buf,"\t[%s%d]%s %X\n"
							,PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType, ML_Addr
							,__FUNCTION__
							,val
							);PLC_LOG_addLog(buf);*/
	}
	else{
		val = PLC_Register_getWord_old(ML_code, ML_Addr);
		/*DBG_LOGSCAN(buf,"\t[%s%d]%s %X\n"
							,PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType, ML_Addr
							,__FUNCTION__
							,PLC_Register_getWord(ML_code, ML_Addr)
							);PLC_LOG_addLog(buf);*/
		val = (val>>wordBit) & 0x0F;
	}


	return val;
}

inline uint8* PLC_Register_getNibbleBlock(uint8 ML_code, uint16 ML_Addr, uint16 blockCount){
	return NULL;
}

inline uint8* PLC_Register_getString(uint8 ML_code, uint16* ML_Addr){
	if(PLC_OPERAND_DICTIONARY_findOperand(ML_code)->nMLCode == OPERAND_ML_CODE_STR)
		return (uint8*)ML_Addr;
	//DBG_LOGSCAN(buf, "\t[%s] ret = %s\n",__FUNCTION__, (char*)PLC_Register_getPos(ML_code, *ML_Addr, TYPE_STRING));
	return (uint8*)PLC_Register_getPos(ML_code, *ML_Addr, TYPE_STRING);
}

inline uint32 PLC_Register_getWord(uint8 ML_code, uint16 ML_Addr){
	if(PLC_OPERAND_DICTIONARY_findOperand(ML_code)->bIsConstant)
		return ML_Addr;
	uint16* val = (uint16*)PLC_Register_getPos(ML_code, ML_Addr, TYPE_WORD);
	if(val==NULL)
	{
		return PLC_FALSE_32;
	}
	return *val;
}

inline uint32 PLC_Register_getDWord(uint8 ML_code, uint16 ML_Addr){
	uint32 *val = (uint32*)PLC_Register_getPos(ML_code, ML_Addr, TYPE_DWORD);
	if(val==NULL)
		return PLC_FALSE_32;
	if(PLC_OPERAND_DICTIONARY_findOperand(ML_code)->bIsConstant)
		return ML_Addr;
	return *val;
}

inline uint16* PLC_Register_getBlock(uint8 ML_code, uint16 ML_Addr){
	return PLC_Register_getPos(ML_code, ML_Addr, TYPE_DWORD);
}

inline float PLC_Register_getFloat(uint8 ML_code, uint16 ML_Addr){
	//float* val = (float*)PLC_Register_getPos(ML_code, ML_Addr, TYPE_DWORD);



	uint32 ret = PLC_Register_getWord(ML_code, ML_Addr) +  PLC_Register_getWord(ML_code, ML_Addr+1)*0x10000;
	float* val = (float*)&ret;
	//uint8* val2 = (uint8*)val;

	if(val==NULL)
		return PLC_FALSE_32;

	return *val;
}


inline double PLC_Register_getDouble(uint8 ML_code, uint16 ML_Addr){
	double* val = PLC_Register_getPos(ML_code, ML_Addr, TYPE_DWORD);
	if(val==NULL)
		return PLC_FALSE_32;
	return *val;
}

inline uint8 test_getBit(uint8* tar, uint8 ML_code, uint16 ML_Addr){
	uint16* value = (uint16*)PLC_Register_getPos(ML_code, ML_Addr, TYPE_BIT);
	if( value == NULL )
		return FALSE;
	uint8 bitPos = ML_Addr%16;
	*tar = (*value>>bitPos) & 0x01;
	return TRUE;
}

inline uint8 test_getWordBit(uint8* tar, uint8 ML_code, uint16 ML_Addr, uint8 bitAddr){

	/*DBG_LOGSCAN(buf, "\t[%s%d] %s%d = %04X\n", __FUNCTION__, __LINE__, PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType,
				ML_Addr,value
		);PLC_LOG_addLog(buf);*/
	while(bitAddr>15)
	{
		bitAddr-=16;
		ML_Addr++;
	}
	uint32 value = PLC_Register_getWord(ML_code, ML_Addr);
	if(value==PLC_FALSE_32)
		return FALSE;
	uint8 bitPos = bitAddr;
	*tar = (value>>bitPos)&0x1;
	//DBG_LOGPRINT("\t[%s%d] %s%d = %04X >> %d shifted = %d \n", __FUNCTION__, __LINE__, PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType,
	//				ML_Addr,value, bitAddr, *tar);
	return TRUE;
}

inline uint8 test_getNibble(long long* tar, uint8 ML_code, uint16 ML_Addr, uint8 nibbleCount)
{
	/*
	uint8 val;
	if(PLC_OPERAND_DICTIONARY_findOperand(ML_code)->nBitSize==1)
	{

		*tar = PLC_Register_getBit(ML_code, ML_Addr)+
				PLC_Register_getBit(ML_code, ML_Addr+1)>>1+
				PLC_Register_getBit(ML_code, ML_Addr+2)>>2+
				PLC_Register_getBit(ML_code, ML_Addr+3)>>3;

	}
	else{
		val = PLC_Register_getWord(ML_code, ML_Addr);
		if(val==PLC_FALSE_32)
			return FALSE;
	}
	*/
	*tar=0;
	//long long ret=0;
	if(PLC_OPERAND_DICTIONARY_findOperand(ML_code)->nBitSize==1)
	{
		int nibbleIdx;
		long long binConst = 1;
		//printf("[%s%04d..+%04d]", opndic[ML_code].strType, ML_Addr, 4*nibbleCount);
		if( 4*nibbleCount +ML_Addr > opndic[ML_code].nAddressCount)
		{
			DBG_LOGPRINT("[ERROR] Address is overflowed : %s %d + 4*%d (addr) > %d(MaxAddr)\n",
					opndic[ML_code].strType, ML_Addr , nibbleCount, opndic[ML_code].nAddressCount
					);
			return FALSE;
		}
		for(nibbleIdx = 0; nibbleIdx < 4*nibbleCount; nibbleIdx++)
		{

			*tar += binConst*PLC_Register_getBit(ML_code, ML_Addr+nibbleIdx);
			//printf("[%s%d]%d\n", opndic[ML_code].strType, ML_Addr+nibbleIdx,PLC_Register_getBit(ML_code, ML_Addr+nibbleIdx));
			//printf("[%s%d]+(%d*%d)\n", opndic[ML_code].strType, ML_Addr+nibbleIdx,binConst , PLC_Register_getBit(ML_code, ML_Addr+nibbleIdx));
			//if(nibbleIdx%8==7)
			//	printf(" ");
			binConst*=2;
			//printf(", curr nibble ret_%dth = %lld\n", nibbleIdx, *tar);
		}
		//printf("\n");

	}
	else{
		DBG_LOGPRINT("[ERROR]in %s %d : ML_code = %s\n", __FUNCTION__, __LINE__, opndic[ML_code].strType);
		return FALSE;
	}
	//*tar = ret;
	/*if(nibbleCount == 16)
	{
		tar[1] = (ret>>32)&0x0FFFF;
	}*/
	//printf("get nibble [%s%d]ret_uint%d = %lld\n", opndic[ML_code].strType, ML_Addr , nibbleCount*4, *tar);
	return TRUE;
}

inline uint8 test_getWord(uint16* tar, uint8 ML_code, uint16 ML_Addr){
	//DBG_LOGPRINT("[%s%d] getWord\n", opndic[ML_code].strType, ML_Addr );
	PLC_Operand* operand = PLC_OPERAND_DICTIONARY_findOperand(ML_code);
	if(operand==NULL)
	{
		DBG_LOGPRINT("[ERROR]MLCode of operand = %d, in %s %d\n", ML_code, __FUNCTION__, __LINE__);
		return FALSE;
	}
	if(operand->bIsConstant)
	{

		*tar = ML_Addr;
		return TRUE;
	}

	uint16* val = (uint16*)PLC_Register_getPos(ML_code, ML_Addr, TYPE_WORD);

	if(val==NULL)
	{
		DBG_LOGPRINT("[ERROR] [%s%d]= NULL\n", opndic[ML_code].strType, ML_Addr );
		return FALSE;
	}

	*tar = *val;
	//printf("[LOAD] [%s%d] %d\n", opndic[ML_code].strType, ML_Addr, *tar );
	return TRUE;
}

inline uint8 test_getDWord(uint32* tar, uint8 ML_code, uint16 ML_Addr){

	uint32 *val = (uint32*)PLC_Register_getPos(ML_code, ML_Addr, TYPE_DWORD);
	//printf("test_getDWord : [%s%d] %d\n", PLC_OPERAND_DICTIONARY_findOperand(ML_code)->strType, ML_Addr, *val);
	if(val==NULL)
	{
		printf("[ERROR] getting position is failed!\n");
		return FALSE;
	}
	if(PLC_OPERAND_DICTIONARY_findOperand(ML_code)->bIsConstant)
	{
		*tar =  ML_Addr;
		return TRUE;
	}
	*tar = *val;
	return TRUE;
}

inline uint8 test_getFloat(float* tar, uint8 ML_code, uint16 ML_Addr){
	uint16 getValue1 =PLC_Register_getWord(ML_code, ML_Addr);
	uint16 getValue2 =PLC_Register_getWord(ML_code, ML_Addr+1);
	if(getValue1==PLC_FALSE_32 || getValue2 ==PLC_FALSE_32)
		return FALSE;
	uint32 ret = getValue1 +getValue2*0x10000;

	//uint8* val2 = (uint8*)val;


	float* val = (float*)&ret;
	*tar = *val;

	return TRUE;
}

inline uint8 test_getDouble(double* tar, uint8 ML_code, uint16 ML_Addr){
	double* val = PLC_Register_getPos(ML_code, ML_Addr, TYPE_DWORD);
	if(val==NULL)
		return FALSE;
	*tar = *val;
	return TRUE;
}

inline uint8 test_getLong(long long* tar, uint8 ML_code, uint16 ML_Addr){
	long long* val = PLC_Register_getPos(ML_code, ML_Addr, TYPE_LONG);
	if(val==NULL)
		return FALSE;
	*tar = *val;
	return TRUE;
}

inline uint8 test_getValue(long long *tar, uint8* rstBitSize, uint8 inst[], short offset){
	uint16 nibbleSize = 0;
	uint16 wordBitPos = 0xFF;
	uint16 ZIndex = 0;
	uint16 zValue = 0;
	uint8 type;
	uint16 val;
	int currPos=0;
	//uint8 bitSize;
	type = inst[currPos++];
	//DBG_LOGPRINT("%s %02X %02X\n", opndic[type].strType, inst[1], inst[2]);

	switch( type )
	{
		case OPERAND_ML_CODE_N :
		{
			//printf("\t%s %02X %02X\n",opndic[ inst[3]].strType, inst[4], inst[5]);
			memcpy(&nibbleSize, &inst[1], 2);
			type = inst[3];
			memcpy(&val, &inst[4], 2);
			*rstBitSize = nibbleSize*4;
			//printf("Nibble get : [%d]%s%d\n", nibbleSize, opndic[type].strType, val+offset);
			return test_getNibble(tar, type, val+offset, (uint8)nibbleSize);
		}
		case OPERAND_ML_CODE_WB :
		{

			uint8 rst;
			uint8 ret;

			memcpy(&wordBitPos, &inst[1], 2);
			type = inst[3];
			memcpy(&val, &inst[4], 2);
			*rstBitSize = 1;
			ret = test_getWordBit(&rst, type, val, wordBitPos+offset);
			//DBG_LOGPRINT("[%s%d.%d+%d]=>%d\n", opndic[type].strType, val, wordBitPos, offset, rst);
			*tar = rst;
			return ret;
		}
		case OPERAND_ML_CODE_STR :
		{

			*rstBitSize = 0;
			tar = (uint32*)&inst[1];
			return TRUE;
		}
		case OPERAND_ML_CODE_E :
		{

			*rstBitSize = 4;
			tar = (uint32*)&inst[1];
			return TRUE;
		}
		case OPERAND_ML_CODE_DE :
		{

			*rstBitSize = 8;
			tar = (uint32*)&inst[1];
			return TRUE;
		}
		case OPERAND_ML_CODE_DK :
		{

			long long valueInt= 0;
			*rstBitSize = 64;
			memcpy(&valueInt, &inst[1], 4);
			*tar = valueInt;
			//printf("tarVal in getFnction = %d\n", *tar);
			return TRUE;
		}
		case OPERAND_ML_CODE_K :
		{

			short valueShort;
			memcpy(&valueShort, &inst[1], 2);
			*tar = valueShort;
			return TRUE;
		}

		case OPERAND_ML_CODE_Z :
		{

			uint16 zValue=0;
			uint16 addrValue=0;
			uint8 rst = TRUE;
			short getVal = 0;
			memcpy(&ZIndex, &inst[currPos], 2);
			currPos+=2;
			type = inst[currPos++];
			memcpy(&addrValue, &inst[currPos], 2);
			//printf("Z %02X %02X %s %02X %02X\n", inst[1], inst[2], opndic[type].strType, inst[4], inst[5]);
			if(!test_getWord(&zValue, OPERAND_ML_CODE_Z, ZIndex))
				return FALSE;
			//printf("Z %02X %02X = %d\n", inst[1], inst[2], zValue);

			if(!test_getWord(&getVal, type, zValue+addrValue))
				return FALSE;
			*tar = getVal;
			return TRUE;
		}
		case OPERAND_ML_CODE_X:
		case OPERAND_ML_CODE_Y:
		case OPERAND_ML_CODE_R:
		case OPERAND_ML_CODE_L:
		case OPERAND_ML_CODE_F:
		case OPERAND_ML_CODE_B:
		case OPERAND_ML_CODE_SM:
		case OPERAND_ML_CODE_SB:
		{

			uint8 rst;
			uint8 ret;
			memcpy(&val, &inst[currPos], 2);
			val+=zValue;
			*rstBitSize = 1;
			ret = test_getBit(&rst, type, val+offset+ZIndex);
			*tar = rst;
			return ret;

		}
		case OPERAND_ML_CODE_D:
		case OPERAND_ML_CODE_W:
		case OPERAND_ML_CODE_SW:
		case OPERAND_ML_CODE_SD:
		{
			//
			uint16 rst;
			uint8 ret;
			memcpy(&val, &inst[currPos], 2);
			val+=zValue;
			*rstBitSize = 16;

			//printf("Loading Position : %d\n", val+offset+ZIndex);
			ret = test_getWord(&rst, type, val+offset+ZIndex);
			//DBG_LOGPRINT("[LOAD] [%s%d] %d\n", opndic[type].strType, val+offset+ZIndex, rst);
			*tar = rst;
			return ret;
		}
		case OPERAND_ML_CODE_T:

		{

			uint8 rst;

			memcpy(&val, &inst[1], 2);
			*rstBitSize = 1;
			rst = PLC_Register_getTimer(val+offset+ZIndex, VALUE_TYPE_RET);
			if(rst==0xFFFF)
				return FALSE;
			*tar = (int)rst;
			return TRUE;
		}
		case OPERAND_ML_CODE_C:
		{

			uint8 rst;
			memcpy(&val, &inst[1], 2);
			*rstBitSize = 1;
			rst = PLC_Register_getCount(val+offset+ZIndex, VALUE_TYPE_RET);
			if(rst==0xFFFF)
				return FALSE;
			*tar = rst;
			return TRUE;
		}
		default:
			return FALSE;
	}
}

inline uint8 test_getDValue(int *tar, uint8* rstBitSize, uint8 inst[], uint16 offset){
	uint16 nibbleSize = 0;
	uint16 wordBitPos = 0xFF;
	uint16 ZIndex = 0;
	uint16 zValue = 0;
	uint8 type;
	uint16 val;
	int currPos=0;
	//uint8 bitSize;
	type = inst[currPos++];
	//DBG_LOGPRINT("%s %d\n", opndic[type].strType, *(uint16*)&inst[1]);

	switch( type )
	{
		case OPERAND_ML_CODE_N :
		{
			//printf("\t%s %02X %02X\n",opndic[ inst[3]].strType, inst[4], inst[5]);
			memcpy(&nibbleSize, &inst[1], 2);
			type = inst[3];
			memcpy(&val, &inst[4], 2);
			*rstBitSize = nibbleSize*4;
			//printf("Nibble get : [%d]%s%d\n", nibbleSize, opndic[type].strType, val+offset);
			return test_getNibble(tar, type, val+offset, (uint8)nibbleSize);
		}
		case OPERAND_ML_CODE_WB :
		{

			uint8 rst;
			uint8 ret;

			memcpy(&wordBitPos, &inst[1], 2);
			type = inst[3];
			memcpy(&val, &inst[4], 2);
			*rstBitSize = 1;
			ret = test_getBit(&rst, type, val+offset);
			*tar = rst;
			return ret;
		}
		case OPERAND_ML_CODE_STR :
		{

			*rstBitSize = 0;
			tar = (uint32*)&inst[1];
			return TRUE;
		}
		case OPERAND_ML_CODE_E :
		{

			*rstBitSize = 4;
			tar = (uint32*)&inst[1];
			return TRUE;
		}
		case OPERAND_ML_CODE_DE :
		{

			*rstBitSize = 8;
			tar = (uint32*)&inst[1];
			return TRUE;
		}
		case OPERAND_ML_CODE_DK :
		{

			int valueInt;
			memcpy(&valueInt, &inst[1], 4);
			*tar = valueInt;
			return TRUE;
		}
		case OPERAND_ML_CODE_K :
		{

			short valueShort;
			memcpy(&valueShort, &inst[1], 2);
			*tar = valueShort;
			return TRUE;
		}

		case OPERAND_ML_CODE_Z :
		{

			short zValue=0;
			uint32 rst;
			uint8 ret;

			memcpy(&ZIndex, &inst[currPos], 2);
			currPos+=2;
			type = inst[currPos++];

			if(!test_getWord((uint16*)&zValue, OPERAND_ML_CODE_Z, ZIndex))
				return FALSE;
			//printf("Z load = [Z%d] = %d\n", ZIndex, (short)zValue);
					//
			memcpy(&val, &inst[currPos], 2);
			//val+=zValue;
			*rstBitSize = 32;

			if( type!=  OPERAND_ML_CODE_D&&
					type!=  OPERAND_ML_CODE_W&&
					type!=  OPERAND_ML_CODE_SW&&
					type!=  OPERAND_ML_CODE_SD)
				return FALSE;

			ret = test_getDWord(&rst, type, val+offset+zValue);
			//printf("Loading Position : %s %d = %d\n", opndic[type].strType, val+offset+ZIndex, rst);
			*tar = rst;
			return ret;
		}
		case OPERAND_ML_CODE_D:
		case OPERAND_ML_CODE_W:
		case OPERAND_ML_CODE_SW:
		case OPERAND_ML_CODE_SD:
		{
			//
			uint32 rst;
			uint8 ret;
			memcpy(&val, &inst[currPos], 2);
			//val+=zValue;
			*rstBitSize = 32;


			ret = test_getDWord(&rst, type, val+offset+zValue);
			//printf("Loading Position : %s %d = %d\n", opndic[type].strType, val+offset+ZIndex, rst);
			*tar = rst;
			return ret;
		}
		case OPERAND_ML_CODE_X:
		case OPERAND_ML_CODE_Y:
		case OPERAND_ML_CODE_R:
		case OPERAND_ML_CODE_L:
		case OPERAND_ML_CODE_F:
		case OPERAND_ML_CODE_B:
		case OPERAND_ML_CODE_SM:
		case OPERAND_ML_CODE_SB:
		{

			uint32 rst;
			uint8 ret;
			int i;
			memcpy(&val, &inst[currPos], 2);
			val+=zValue;
			*rstBitSize = 32;
			for(i=0;i<32;i++)
			{
				ret *= 2;
				ret += test_getBit(&rst, type, val+offset+ZIndex);
			}
			*tar = rst;
			return ret;

		}
		case OPERAND_ML_CODE_T:

		{

			uint8 rst;

			memcpy(&val, &inst[1], 2);
			*rstBitSize = 1;
			rst = PLC_Register_getTimer(val+offset+ZIndex, VALUE_TYPE_RET);
			if(rst==0xFFFF)
				return FALSE;
			*tar = (int)rst;
			return TRUE;
		}
		case OPERAND_ML_CODE_C:
		{

			uint8 rst;
			memcpy(&val, &inst[1], 2);
			*rstBitSize = 1;
			rst = PLC_Register_getCount(val+offset+ZIndex, VALUE_TYPE_RET);
			if(rst==0xFFFF)
				return FALSE;
			*tar = rst;
			return TRUE;
		}
		default:
			return FALSE;
	}

}

inline void TEST_PLC_Register(){
	//PLC_Register_init();
	//PLC_Register_print();

	char* val = "my life for Ioer!";
	uint16* i=0;
	int ml_code = OPERAND_ML_CODE_D;
	int type = TYPE_STRING;
	//for(*i=0;*i<OPND_DICT_getOperandRegByteSize(ml_code)/2;*i++)
	{
		//val = val+0.1f;
		PLC_Register_set(ml_code, *i, 0, (uint8*)val, type);
		printf("%s ",(char*)PLC_Register_getString(ml_code, i));
		if(*i%32==31) printf("\n");
		else if(*i%8==7) printf("\t");
	}
}

inline uint8 PLC_Register_getBit_old(uint8 ML_code, uint16 ML_Addr){
	uint16* value = (uint16*)PLC_Register_getPos_old(ML_code, ML_Addr, TYPE_BIT);
	if( value == NULL )
		return 0xFF;
	uint8 bitPos = ML_Addr%16;
	uint8 val = (*value>>bitPos) & 0x01;
	return val;
}

inline uint32 PLC_Register_getWord_old(uint8 ML_code, uint16 ML_Addr){
	uint16* val = (uint16*)PLC_Register_getPos_old(ML_code, ML_Addr, TYPE_WORD);
	if(val==NULL)
		return PLC_FALSE_32;
	return *val;
}

inline uint32 PLC_Register_getDWord_old(uint8 ML_code, uint16 ML_Addr){
	uint32 *val = (uint32*)PLC_Register_getPos_old(ML_code, ML_Addr, TYPE_DWORD);
	if(val==NULL)
		return PLC_FALSE_32;
	return *val;
}

inline uint8 PLC_Register_setCount(uint16 countIdx, uint8 countValue){
	if(countIdx>=OPERAND_SIZE_C)
	{
		PLC_LOG_addLog("[ERROR] Counter IDX must be smaller than counter register size.\n");
		return FALSE;
	}


	return PLC_Register_set(OPERAND_ML_CODE_C, 0, countIdx, &countValue, TYPE_DWORD);
}

inline uint8 PLC_Register_setTimer(uint16 timerIdx, uint8 timerMode, uint8 timerValue){
	if(timerIdx>=OPERAND_SIZE_T)
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		PLC_LOG_addLog("[ERROR] Timer IDX must be smaller than timer register size.\n");
		return FALSE;
	}

	return PLC_Register_set(OPERAND_ML_CODE_T, 0, timerIdx, &timerValue, TYPE_DWORD);
}

inline uint8 PLC_Register_setF(uint16 ML_ADDR_F){
	int errorCount;
	uint8 setSM = 1;
	PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD].registerHead[SPECIAL_REG_ADDR+1]++;
	errorCount = PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD].registerHead[SPECIAL_REG_ADDR+1];
	//DBG_LOGPRINT("prevErrorCount [SD%d]= %d\n", SPECIAL_REG_ADDR, errorCount);
	//if(errorCount == 1)
		PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD]
		          .registerHead[SPECIAL_REG_ADDR] = ML_ADDR_F;
	if(errorCount<16)
	{
		PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD]
		                    .registerHead[SPECIAL_REG_ADDR+1+errorCount] = ML_ADDR_F;
		//DBG_LOGPRINT("[SD%d]= %d\n", SPECIAL_REG_ADDR+1+errorCount, ML_ADDR_F);
	}
	if(!PLC_Register_set(OPERAND_ML_CODE_SM, SPECIAL_REG_ADDR, 0, &setSM, TYPE_BIT))
		return FALSE;
	return TRUE;
}

inline uint8 PLC_Register_resetF(uint16 ML_ADDR_F){
	uint8 setSM = 0;
	//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
	int errorCount = PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD].registerHead[SPECIAL_REG_ADDR+1];
	int i;
	//DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
	if(errorCount >=16)
		errorCount = 16;
	for(i = 0; i<errorCount; i++)
	{
	//	DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
	//	DBG_LOGPRINT("SD[%d+1+%d]\n", SPECIAL_REG_ADDR, i);
		uint16 currSDValue = PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD]
		             		                    .registerHead[SPECIAL_REG_ADDR+1+i];
	//	DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
		//DBG_LOGPRINT("[SD%d] => %d(=?%d)\n", SPECIAL_REG_ADDR+1+i, PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD].registerHead[SPECIAL_REG_ADDR+1+i], ML_ADDR_F);
		if(currSDValue == ML_ADDR_F)
		{
	//		DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
			int j;
			for(j = i ; j < errorCount ; j++ )
			{

				PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD].registerHead[SPECIAL_REG_ADDR+1+j] =
						errorCount==16? 0:
						PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD].registerHead[SPECIAL_REG_ADDR+1+j+1];
				//DBG_LOGPRINT("[SD%d] <= %d\n", SPECIAL_REG_ADDR+1+j, PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD].registerHead[SPECIAL_REG_ADDR+1+j]);
			}
	//		DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
			break;
		}
		/*if(i==errorCount-1)
		{
			DBG_LOGPRINT("[resetF] cannot found [F%d] address from SDs...\n", ML_ADDR_F);
			//return FALSE;
		}*/
	//	DBG_LOGPRINT("%s %d\n", __FUNCTION__, __LINE__);
	}
	PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD].registerHead[SPECIAL_REG_ADDR+1]--;
	if(PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_SD].registerHead[SPECIAL_REG_ADDR+1]==0)
	{
		if(!PLC_Register_set(OPERAND_ML_CODE_SM, SPECIAL_REG_ADDR, 0, &setSM, TYPE_BIT))
			return FALSE;
	}

	return TRUE;
}

inline uint16 PLC_Register_getCount(uint16 idx, uint8 valueType){
	if(idx>=OPERAND_SIZE_C)
	{
		PLC_LOG_addLog("\t[ERROR] Counter IDX must be smaller than counter register size.\n");
		return 0;
	}
	switch(valueType){
	case VALUE_TYPE_CURR :
		return PLC_Register_getRegister()->C_curr[idx];
	case VALUE_TYPE_ISON :
		return PLC_Register_getRegister()->C_isOn[idx];
	case VALUE_TYPE_RET :
		return PLC_Register_getRegister()->C_ret[idx];
	case VALUE_TYPE_SET :
		return PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_C].registerHead[idx];
	case VALUE_TYPE_SET_OLD :
		return PLC_Register_getRegister()->listRegister_old[OPERAND_ML_CODE_C].registerHead[idx];
	default :
		return 0xFFFF;
	}
}

inline uint8 PLC_getTimer(int idx)
{
	return regPLC.T_ret[idx];
}

inline unsigned long long PLC_Register_getTimer(uint16 idx, uint8 valueType){
	if(idx>=OPERAND_SIZE_T)
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		PLC_LOG_addLog("[ERROR] Timer IDX must be smaller than timer register size.\n");
		return 0;
	}
	switch(valueType){
	case VALUE_TYPE_CURR :
		return PLC_Register_getRegister()->T_curr[idx];
	case VALUE_TYPE_ISON :
		return PLC_Register_getRegister()->T_isOn[idx];
	case VALUE_TYPE_RET :
		return PLC_Register_getRegister()->T_ret[idx];
	case VALUE_TYPE_SET :
		//return PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_T].registerHead[idx];
		return PLC_Register_getRegister()->T_set[idx];
	case VALUE_TYPE_SET_OLD :
		return PLC_Register_getRegister()->listRegister_old[OPERAND_ML_CODE_T].registerHead[idx];
	case VALUE_TYPE_MODE :
		return PLC_Register_getRegister()->T_mode[idx];
	case VALUE_TYPE_REMAINED :
		return PLC_Register_getRegister()->T_remained[idx];
	default :
		return 0xFFFF;
	}
}

inline uint16 PLC_Register_setTValue(uint16 idx, uint8 valueType, unsigned long long value){
	if(idx>=OPERAND_SIZE_T)
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		PLC_LOG_addLog("[ERROR] Timer IDX must be smaller than timer register size.\n");
		return FALSE;
	}

	switch(valueType){
	case VALUE_TYPE_CURR :
		PLC_Register_getRegister()->T_curr[idx] = value;
		return TRUE;
	case VALUE_TYPE_ISON :
		PLC_Register_getRegister()->T_isOn[idx] = value;
		return TRUE;
	case VALUE_TYPE_RET :
		QueueLog_AddLog(OPERAND_ML_CODE_T, idx, PLC_Register_getRegister()->T_ret[idx], value, PLC_DEVICE_getCurrTimeScan());
		PLC_Register_getRegister()->T_ret[idx] = value;
		return TRUE;
	case VALUE_TYPE_SET :
		//printf("[%d] setVal = %d, old setVal = %d\n",__LINE__,PLC_Register_getTimer(idx, VALUE_TYPE_SET),PLC_Register_getTimer(idx, VALUE_TYPE_SET_OLD));
		//PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_T].registerHead[idx] = value;
		PLC_Register_getRegister()->T_set[idx] = value;
		//printf("[%d] setVal = %lld<==%lld, old setVal = %d\n",__LINE__,PLC_Register_getTimer(idx, VALUE_TYPE_SET),value, PLC_Register_getTimer(idx, VALUE_TYPE_SET_OLD));
		return TRUE;
	case VALUE_TYPE_REMAINED :
		PLC_Register_getRegister()->T_remained[idx] = value;
		return TRUE;
	//case VALUE_TYPE_SET_OLD :
	//	PLC_Register_getRegister()->listRegister_old[OPERAND_ML_CODE_T].registerHead[idx] = value;
	//	return TRUE;
	case VALUE_TYPE_MODE :
		PLC_Register_getRegister()->T_mode[idx] = value;
		return TRUE;
	default :
		PLC_LOG_addLog("\t[ERROR] Value Type is invalid.\n");
		return FALSE;
	}
}

inline uint8 PLC_Register_rstTValue(uint16 idx)
{
	if(idx>=OPERAND_SIZE_T)
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		DBG_LOGPRINT("[ERROR] Timer IDX must be smaller than timer register size.\n");
		return FALSE;
	}
	PLC_Register_getRegister()->T_isOn[idx] = 0;
	PLC_Register_getRegister()->T_ret[idx] = 0;
	PLC_Register_getRegister()->T_remained[idx] = 0;
	PLC_Register_getRegister()->T_curr[idx] = 0;
	DBG_LOGPRINT("[RST] [T%d]\n", idx);
	return TRUE;
}

inline uint16 PLC_Register_setCValue(uint16 idx, uint8 valueType, uint16 value){
	if(idx>=OPERAND_SIZE_C)
	{
		PLC_LOG_addLog("\t[ERROR] Counter IDX must be smaller than counter register size.\n");
		return FALSE;
	}
	switch(valueType){
	case VALUE_TYPE_CURR :
		PLC_Register_getRegister()->C_curr[idx] = value;
		return TRUE;
	case VALUE_TYPE_ISON :
		PLC_Register_getRegister()->C_isOn[idx] = value;
		return TRUE;
	case VALUE_TYPE_RET :
		QueueLog_AddLog(OPERAND_ML_CODE_T, idx, PLC_Register_getRegister()->T_ret[idx], value, PLC_DEVICE_getCurrTimeScan());
		PLC_Register_getRegister()->C_ret[idx] = value;
		return TRUE;
	case VALUE_TYPE_SET :
		PLC_Register_getRegister()->listRegister[OPERAND_ML_CODE_C].registerHead[idx] = value;
		return TRUE;
	//case VALUE_TYPE_SET_OLD :
	//	PLC_Register_getRegister()->listRegister_old[OPERAND_ML_CODE_C].registerHead[idx] = value;
	//	return TRUE;
	default :
		PLC_LOG_addLog("\t[ERROR] Value Type is invalid.\n");
		return FALSE;
	}
}

inline uint8 PLC_Register_rstCValue(uint16 idx)
{
	if(idx>=OPERAND_SIZE_C)
	{
		//printf("%s : %d\n", __FUNCTION__,__LINE__);
		PLC_LOG_addLog("[ERROR] Counter IDX must be smaller than counter register size.\n");
		return FALSE;
	}
	PLC_Register_getRegister()->C_isOn[idx] = 0;
	PLC_Register_getRegister()->C_ret[idx] = 0;
	return TRUE;
}

inline uint8 PLC_Register_increaseCount(uint16 idx, uint16 setValue){
	if(idx<OPERAND_SIZE_C)
	{
		//DBG_LOGPRINT("PLC_Register_getRegister()->C_curr[%d] = %d++ => ", idx, PLC_Register_getRegister()->C_curr[idx]);
		PLC_Register_getRegister()->C_curr[idx]++;
		if(PLC_Register_getRegister()->C_curr[idx] == setValue)
		{
			PLC_Register_getRegister()->C_ret[idx] = 1;
			PLC_Register_getRegister()->C_curr[idx] = 0;
		}
		//DBG_LOGPRINT("%d\n", PLC_Register_getRegister()->C_curr[idx]);
		return TRUE;
	}
	return FALSE;
}

inline void PLC_DEVICE_saveChangedRegisterLogEvent(uint32 scantime, uint8 operand[], long long setValue){
	/*if(changedLog==NULL)
		printf("\tWarning! debug buffer is not allocated!\n");

	char buf[200];
	memset(buf, 0, 200);
	int addlength = strlen(buf)+ strlen(changedLog)+2;
	if(addlength>=INITIAL_LOG_SIZE)
		changedLog=(char*)realloc(changedLog, addlength);
	strcat(changedLog, buf);
	QueueLog_AddLog(ml_code, j, fast, curr, scantime);
*/
	//developping!!!
}

inline void PLC_DEVICE_saveChangedRegisterLog(uint32 scantime){

	if(changedLog==NULL)
		printf("\tWarning! debug buffer is not allocated!\n");
	int i;
	//PLC_DEVICE_clearChangedRegisterLog();
	//char buf[300];
	//	int i;
	/*for(i=0;i<OPERAND_ML_CODE_MAX;i++)
	{
		DBG_LOGSCAN(buf, "[%s] AddrCount : %d, const : %d, size: %d, code : %d\n",
				opndic[i].strType,
				opndic[i].nAddressCount,
				opndic[i].bIsConstant,
				opndic[i].nBitSize,
				opndic[i].nMLCode
			);PLC_LOG_addLog(buf);
	}*/
	uint8 isChanged = FALSE;
	for(i=0; i<OPERAND_ML_CODE_MAX; i++)
	{

		uint8 checkConst = (opndic[i].bIsConstant==FALSE);
		PLC_Operand operand = opndic[i];
		uint16 addrCount = opndic[i].nAddressCount;
		uint8 ml_code = opndic[i].nMLCode;
		//char* strType = opndic[i].strType;
		if(checkConst)
		{
			/*DBG_LOGSCAN(buf,"\t[%s] constant = %d, addrCount = %d, ml_code = %d\n",
					operand.strType,
					checkConst,
					addrCount,
					ml_code
					);PLC_LOG_addLog(buf);*/
			uint32 curr;
			uint32 fast;
			//float curr_float= 0.f;
			//float fast_float= 0.f;
			int j;
			for(j=0;j<addrCount; j++)
			{
				if(operand.nMLCode == OPERAND_ML_CODE_T)
				{
					fast = PLC_Register_getRegister()->T_ret_old[j];
					curr = PLC_Register_getRegister()->T_ret[j];
					//fastSet = PLC_Register_getRegister()->
					//todo:onTimer & onCounter set
				}
				else if(operand.nMLCode == OPERAND_ML_CODE_C)
				{
					fast = PLC_Register_getRegister()->C_ret_old[j];
					curr = PLC_Register_getRegister()->C_ret[j];
				}
				else if(operand.nBitSize==1)
				{

					curr = PLC_Register_getBit(ml_code, j);
					fast = PLC_Register_getBit_old(ml_code, j);
					//currfloat = 0.f;
					//fastfloat = 0.f;

				}
				else //if(operand.nBitSize==16)
				{
					curr = PLC_Register_getWord(ml_code, j);
					fast = PLC_Register_getWord_old(ml_code, j);

				}

				if(curr!=fast)
				{
					isChanged=TRUE;
					char buf[200];
					memset(buf, 0, 200);
					//if(operand.nBitSize==16)
					//{
						//printf("[REG] [%2s%4d] [T%4d] %4X -> %4X\n", strType, j,scantime, fast, curr);

					//}
					//else if(operand.nBitSize==32)
					//{
					//	printf("[REG] [%2s%4d] [T%4d] %4X -> %4X\n", strType, j++,scantime, fast, curr);
					//}
					//else
					//	printf("[REG] [%2s%4d] [T%4d] %4X -> %4X\n", strType, j,scantime, fast, curr);
					int addlength = strlen(buf)+ strlen(changedLog)+2;
					if(addlength>=INITIAL_LOG_SIZE)
						changedLog=(char*)realloc(changedLog, addlength);
					strcat(changedLog, buf);
					QueueLog_AddLog(ml_code, j, fast, curr, scantime);
					continue;
				}
			}
		}
	}
	for(i = 0;i <OPERAND_SIZE_C;i++)
	{
		uint16 oldVal = PLC_Register_getCount(i, VALUE_TYPE_SET_OLD);
		uint16 curVal = PLC_Register_getCount(i, VALUE_TYPE_SET);
		if(curVal== oldVal)
			continue;
		isChanged=TRUE;
		printf("[REG] [ C%4d] [C%4d] %4X -> %4X (C-SET)\n", i, scantime, oldVal, curVal);
		//QueueLog_AddLog(ml_code, i, fast, curr, scantime);
	}
	for(i = 0;i <OPERAND_SIZE_T;i++)
	{
		uint16 oldVal = PLC_Register_getTimer(i, VALUE_TYPE_SET_OLD);
		uint16 curVal = PLC_Register_getTimer(i, VALUE_TYPE_SET);
		if(curVal== oldVal)
			continue;
		isChanged=TRUE;
		printf("[REG] [ T%4d] [T%4d] %4X -> %4X (T-SET)\n", i, scantime, oldVal, curVal);
	}
	if(!isChanged)
	{
		PLC_LOG_addLog("[REGISTER]No change have been detected.\n");
	}

}

inline void PLC_DEVICE_printChangedRegisterLog(){
	QueueLog_print();
}

inline void PLC_DEVICE_clearChangedRegisterLog(){
	if(changedLog!=NULL)
		free(changedLog);
	//if(changedLog==NULL)
	changedLog=(char*)malloc(INITIAL_LOG_SIZE);
	memset(changedLog, 0, INITIAL_LOG_SIZE);
}

inline void PLC_Register_printDev(uint8 devMLCode, uint16 devIdx){
	devIdx = 16*devIdx/PLC_Register_getRegister()->listRegister[devMLCode].RefOperand->nBitSize;
	//if(PLC_Register_getRegister()->listRegister[devMLCode].RefOperand->nBitSize==1)
	/*DBG_LOGSCAN(buf,"\t\t[%s%d]%s %X\n"
		,PLC_OPERAND_DICTIONARY_findOperand(devMLCode)->strType, devIdx
		,__FUNCTION__
		,PLC_Register_getRegister()->listRegister[devMLCode].registerHead[devIdx]
		);PLC_LOG_addLog(buf);*/
}

inline uint16 getOperandStrLength(uint8 inst[],uint32* pos){
	//char* str = ;
	return (uint16)(strlen((char*)&inst[*pos+1])+1);
}

inline void handleExecError(int errorCode){
	uint8 errorOn= 1;
	PLC_Register_set(OPERAND_ML_CODE_SM, 0, 0, &errorOn, TYPE_BIT);
	PLC_Register_set(OPERAND_ML_CODE_SD, 0, 0, (uint8*)&errorCode, TYPE_WORD);
}
