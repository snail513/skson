/*
 * AddTest.c
 *
 *  Created on: 2016. 5. 4.
 *      Author: skson
 */


#ifndef ADDTEST_H_
#include "AddTest.h"
#include <CUnit/CUnit.h>
#endif


static uint8 secondaryDefaultOperand;
static uint8 secondaryDefaultAddr;
static uint8 includeNibble = FALSE;
static uint8 includeWordBit = FALSE;

static uint16 setBitSize[] = {7,8};
static uint16 setWordSize[] = {4,5};
static FILE *file = NULL;
//static char additionalLog[100] = ;

static uint8 setBit[] ={
		OPERAND_ML_CODE_X,
		OPERAND_ML_CODE_Y,
		OPERAND_ML_CODE_R,
		OPERAND_ML_CODE_L,
		OPERAND_ML_CODE_B,
		OPERAND_ML_CODE_F,
		OPERAND_ML_CODE_SM,
		OPERAND_ML_CODE_WB,
};

static uint8 setWord[] ={
		OPERAND_ML_CODE_D,
		OPERAND_ML_CODE_W,
		OPERAND_ML_CODE_SW,
		OPERAND_ML_CODE_SD,
		OPERAND_ML_CODE_N,
};

static uint8 setK[] = {
		OPERAND_ML_CODE_K
};
static uint8 setDK[] = {
		OPERAND_ML_CODE_DK
};
static uint8 setStr[] = {
		OPERAND_ML_CODE_STR
};
static uint8 setE[] = {
		OPERAND_ML_CODE_E
};
static uint8 setDE[] = {
		OPERAND_ML_CODE_DE
};

static uint8 sampleWordOperand[] = {
		OPERAND_ML_CODE_D,
		OPERAND_ML_CODE_W,
		OPERAND_ML_CODE_D,
		OPERAND_ML_CODE_W,
		OPERAND_ML_CODE_D,
};
static uint8 sampleBitOperand[] = {
		OPERAND_ML_CODE_X,
		OPERAND_ML_CODE_Y,
		OPERAND_ML_CODE_R,
		OPERAND_ML_CODE_L,
		OPERAND_ML_CODE_X
};
static uint16 sampleAddr[] = {150, 300, 450, 600, 750};



void AT_setNibbleInclude(uint8 isNInclude){
	includeNibble = isNInclude;
}
void AT_setWordBitInclude(uint8 isWBInclude){
	includeNibble = isWBInclude;
}
uint8* AT_getBitOperand(){
	return setBit;
}


void ATest_setCarryOn()
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_SM, 700, 1);
}
void ATest_setCarryOff()
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_SM, 700, 0);
}



//uint16 AT_getOperandAddr(uint8 type, uint8 pos, uint8 isBit, uint8 arraySize)
uint8 AT_getDefaultOperand(IOType* ioType, VType* vType, uint8 operandType[], uint16 operandAddr[], int operandcount, uint16** initValue)
{
	int idx;

	//DBG_LOGPRINT("[operandcount %d]\n", operandcount);
	for(idx = 0; idx<operandcount; idx++)
	{

		if(ioType[idx] == IOTypeCNT)
		{
			operandType[idx] = OPERAND_ML_CODE_K;
			operandAddr[idx] = 8;
			//DBG_LOGPRINT("[%d]<--[%s%d]\n", idx, opndic[OPERAND_ML_CODE_K].strType, 8);
			continue;
		}
		switch(vType[idx])
		{
			case VTypeBitDev:
			{
				operandType[idx] = sampleBitOperand[idx];
				operandAddr[idx] = sampleAddr[idx];
				break;
			}
			case VTypeWordDev:
			{
				operandType[idx] = sampleWordOperand[idx];
				operandAddr[idx] = sampleAddr[idx];
				break;
			}
			case VTypeK:
			{
				operandType[idx] = OPERAND_ML_CODE_K;
				operandAddr[idx] = initValue[idx][0];
				break;
			}
			default:
			{
				operandType[idx] = OPERAND_ML_CODE_K;
				operandAddr[idx] = 1;
				break;
			}

		}
		//DBG_LOGPRINT("[%d]<--[%s%d]\n", idx, opndic[operandType[idx]].strType, operandAddr[idx]);
	}
	return TRUE;
}

uint16 AT_getOperandAddr(uint8 type, uint8 pos, uint8 arraySize)
{
	switch(pos)
	{
		case 0:
		{
			return 0;
		}
		case 1:
		{
			return opndic[type].nAddressCount/2;
		}
		case 2:
		{
			uint16 offsetSize = (opndic[type].nBitSize==1?16:1);
			offsetSize*=arraySize;
			return opndic[type].nAddressCount-1-offsetSize;
		}
		case 3:
		{
			return 8;
		}
		default:
		{
			return 0xFFFF;
		}
	}
}
uint8* AT_getOperand(VType v){
	switch (v)
	{
		case VTypeWordDev:
			return setWord;
		case VTypeBitDev:
			return setBit;
		case VTypeK:
			return setK;
		case VTypeDK:
			return setDK;
		case VTypeE:
			return setE;
		case VTypeDE:
			return setDE;
		case VTypeStr:
			return setStr;
	}
	return setWord;
}


int AT_getOperandSize(VType v, TVarType tv)
{
	if(tv != TVarConst)
	{
		if(v == VTypeWordDev)
			return setWordSize[includeNibble];
		if(v == VTypeBitDev)
			return setBitSize[includeWordBit];
	}
	return 1;
}

uint8 AT_setMLCode(uint16 operatorML, uint8* operand, uint16* addr)
{
	int i;
	addMLOperator(ML_CODE_LD);addMLOperand(TRRIGER_DEVICE, TRRIGER_ADDRESS);
	addMLOperator(operatorML);
	if(operand==NULL)
	{
		DBG_LOGPRINT("[ERROR] Setting ML code failed! : %s, cause : operand pointer is NULL!\n", __func__);
		return FALSE;
	}
	if(addr==NULL)
	{
		DBG_LOGPRINT("[ERROR] Setting ML code failed! : %s, cause : addr pointer is NULL!\n", __func__);
		return FALSE;
	}
	PLC_Operator* opt = PLC_OPERATOR_DICTIONARY_findOperator(operatorML);
	if(opt==NULL)
	{
		DBG_LOGPRINT("[ERROR] Setting test code failed! : %s, cause : opt dues not exist(%d)!\n", __func__, operatorML);
		return FALSE;
	}
	for( i=0 ; i<opt->nOperandPosCount ; i++ )
	{
		if(operand[i] == OPERAND_ML_CODE_N)
		{
			addMLOperandNibble(addr[i], secondaryDefaultOperand, secondaryDefaultAddr);
		}
		else
			addMLOperand(operand[i], addr[i]);
	}

	return TRUE;
}


uint8 AT_setInputSwitch(uint8 isOn, uint8 isPulse)
{
	if(isPulse)
	{
		//DBG_LOGPRINT("Pulse type test!\n");
		addDeviceControlInstruction(0, TRRIGER_DEVICE, TRRIGER_ADDRESS, !isOn);
		addDeviceControlInstruction(1, TRRIGER_DEVICE, TRRIGER_ADDRESS, 1);
	}
	else
	{
		//DBG_LOGPRINT("Instant type test!\n");
		addDeviceControlInstruction(0, TRRIGER_DEVICE, TRRIGER_ADDRESS, isOn);
	}

	return TRUE;
}

uint8 AT_setInputSrcWord(uint8 type, uint16 addr, uint16* src, int addrSize)
{
	int i=0;
	//DBG_LOGPRINT("%s %d\n", __func__, __LINE__);
	if(src==NULL)
	{
		DBG_LOGPRINT("[ERROR] Setting test code failed! : %s, cause : src pointer is NULL!\n", __func__);
		return FALSE;
	}

	if(type==OPERAND_ML_CODE_N)
	{
	}
	//DBG_LOGPRINT("%s %d\n", __func__, __LINE__);
	else if(addr+addrSize>=opndic[type].nAddressCount)
	{
		DBG_LOGPRINT("[ERROR] Setting test code failed! : %s, cause : address overflow[%s%d>%d]!\n", __func__, opndic[type].strType, addr+addrSize, opndic[type].nAddressCount);
		return FALSE;
	}
	//DBG_LOGPRINT("%s %d\n", __func__, __LINE__);
	if(src==NULL)
	{
		DBG_LOGPRINT("[Error] src:NULL!\n");
		return FALSE;
	}
	//DBG_LOGPRINT("%s %d\n", __func__, __LINE__);

	if(type == OPERAND_ML_CODE_N)
	{
		DBG_LOGPRINT("Nibble case\n");
		int bitIdx;
		for(bitIdx = 0; bitIdx<16; bitIdx++)
		{
			//DBG_LOGPRINT("[%2s%4d]<--%5d[NIBBLE]\n", opndic[type].strType, secondaryDefaultOperand+16*i+bitIdx, (uint32)(1&(src[i]>>bitIdx)));
			addDeviceControlInstruction(0, secondaryDefaultOperand, secondaryDefaultAddr+i*16+bitIdx, (uint32)(1&(src[i]>>bitIdx)));
		}
	}
	else for(i=0;i<addrSize;i++)
	{
		if(opndic[type].nBitSize ==1)
		{
			int bitIdx;
			for(bitIdx = 0; bitIdx<16; bitIdx++)
			{
				//DBG_LOGPRINT("[%2s%4d]<--%5d\n", opndic[type].strType, addr+i+bitIdx, (uint32)(1&(src[i]>>bitIdx)));
				addDeviceControlInstruction(0, type, addr+i+bitIdx, (uint32)(1&(src[i]>>bitIdx)));
			}
		}
		else
		{//
			//DBG_LOGPRINT("[%2s%4d]<--%5d(0x%04X)\n", opndic[type].strType, addr+i, (uint32)(src[i]),  (uint32)(src[i]));
			addDeviceControlInstruction(0, type, addr+i, (uint32)src[i]);
		}
	}
	//DBG_LOGPRINT("%s %d\n", __func__, __LINE__);
	addMLOperator(ML_CODE_END);
	return TRUE;
}

uint8 AT_assertWordResult(uint8 type, uint16 addr, uint16* exp, int expSize, uint8 isEQ)
{

	int i;
	uint8 assertRst = TRUE;
	uint8 thisType = type;
	uint8 thisAddr = addr;
	for(i = 0; i< expSize; i++)
	{
		uint16 rst;
		if(type ==OPERAND_ML_CODE_N)
		{
			rst = PLC_Register_getNibble(secondaryDefaultOperand, secondaryDefaultAddr+i*16, 4);
		}
		else
			rst = PLC_Register_getWord(type, addr+i);
		if(isEQ)
		{
			CU_ASSERT_EQUAL(rst, exp[i]);

			DBG_LOGPRINT("[RST] [%2s%5d] %10d == %10d ( %04X == %04X )?\n", opndic[thisType].strType, addr+i, rst, exp[i], rst, exp[i]);
			if(rst != exp[i])
				assertRst = FALSE;
			if(rst != exp[i])
			{

				DBG_LOGPRINT("[Assert eq error] [%2s%5d] %10d:%10d [expected] ( %04X == %04X )\n", opndic[thisType].strType, addr+i, rst, exp[i], rst, exp[i]);
				fprintf(file, "[Assert eq error] [%2s%5d] %10d:%10d [expected] ( %04X == %04X )\n", opndic[thisType].strType, addr+i, rst, exp[i], rst, exp[i]);
			}
		}
		else
		{
			if(rst == exp[i])
				assertRst = FALSE;
			CU_ASSERT_NOT_EQUAL(rst, exp[i]);
			DBG_LOGPRINT("[RST] [%2s%5d] %10d != %10d ( %04X != %04X )?\n", opndic[thisType].strType, addr+i, rst, exp[i], rst, exp[i]);
			if(rst == exp[i])
			{
				DBG_LOGPRINT("[Assert noteq error] [%2s%5d] %10d:%10d [expected] ( %04X != %04X )\n", opndic[thisType].strType, addr+i, rst, exp[i], rst, exp[i]);
				fprintf(file, "[Assert noteq error] [%2s%5d] %10d:%10d [expected] ( %04X != %04X )\n", opndic[thisType].strType, addr+i, rst, exp[i], rst, exp[i]);
			}
		}
	}
	return assertRst;
}

uint8 AT_assertBitResult(uint8 type, uint16 addr, uint16* exp, int expSize)
{

	int i;
	uint8 rst;
	for(i = 0; i< expSize; i++)
	{
		rst = PLC_Register_getBit(type, addr+i);
		DBG_LOGPRINT("[AdditionalTest %s%d] result[%d]:[%d]expected\n", opndic[type].strType, addr+i, rst, exp[i]);
		CU_ASSERT_EQUAL(rst, exp[i]);
	}
	return TRUE;
}

uint8 AT_testGeneralUnitTest(
		uint16 cmd, uint8 runAsOn, uint8 runAsPls,
		TVarType* tvarType, VType* vType, IOType* ioType,
		char* testName,
		uint16** initialValue, uint16* initialValueSize, uint16* expected, uint16 expectedSize,
		void(*inputFunction)(void)
		)
{
	int idx;
	uint8* operands[5];
	file = fopen(testName, "w+");
	uint8 isSuccess =TRUE;
	//;
	//uint16* currInitialSize = initialValueSize;
	uint8 defaultOperand[5];
	uint16 defaultAddr[5];
	uint8 dstIDX;

	int operandCnt = PLC_OPERATOR_DICTIONARY_findOperator(cmd)->nOperandPosCount;
	AT_getDefaultOperand(ioType, vType, defaultOperand, defaultAddr, operandCnt, initialValue);
	//AT_setConstOperand(ioType, initialValue, defaultOperand, defaultAddr, operandCnt);
	PLC_DEVICE_Init();
	int operandKindCnt[5];


	for(idx = 0; idx<operandCnt ; idx++)
	{
		operandKindCnt[idx] = AT_getOperandSize(vType[idx], tvarType[idx]);
		operands[idx] = (uint8*)AT_getOperand(vType[idx]);
		if(ioType[idx]==IOTypeDST)
		{
			dstIDX = idx;
		}
	}
	//DBG_LOGPRINT("dstIDX %d\n", dstIDX);
	DBG_LOGPRINT("%s\n", testName);
	for(idx = 0; idx<operandCnt ; idx++)
	{
		if(tvarType[idx]==TVarConst)
			continue;

		int addrTestIdx;
		int srcIdx;

		uint8 mlOperands[] =
		{
				defaultOperand[0],
				defaultOperand[1],
				defaultOperand[2],
				defaultOperand[3],
				defaultOperand[4],
		};
		uint16 mlOperandAddrs[] = {
				defaultAddr[0],
				defaultAddr[1],
				defaultAddr[2],
				defaultAddr[3],
				defaultAddr[4],
		};

		for(addrTestIdx = 0; addrTestIdx<operandKindCnt[idx]; addrTestIdx++)
		{
			int addrPosIdx;
			mlOperands[idx] = operands[idx][addrTestIdx];

			for(addrPosIdx = 0; addrPosIdx<3; addrPosIdx++)
			{
				if(mlOperands[idx] == OPERAND_ML_CODE_N)
				{
					secondaryDefaultOperand = OPERAND_ML_CODE_X;
					if(addrPosIdx == 0)
					{
						secondaryDefaultAddr = 0;
					}
					else if(addrPosIdx == 1)
					{
						secondaryDefaultAddr = opndic[OPERAND_ML_CODE_X].nAddressCount/2;
					}
					else
					{
						secondaryDefaultAddr = opndic[OPERAND_ML_CODE_X].nAddressCount - 16*initialValueSize[idx]-1;
					}
					mlOperandAddrs[idx] = 4*initialValueSize[idx];
				}
				else
				{
					mlOperandAddrs[idx] = AT_getOperandAddr(mlOperands[idx], addrPosIdx, initialValueSize[idx]);
				}

				//DBG_LOGPRINT("[idx %d] <==[%s%d]\n",addrPosIdx, opndic[mlOperands[idx]].strType, mlOperandAddrs[idx]);
				TestCodeInit();
				AT_setInputSwitch(runAsOn, runAsPls);
				if(inputFunction!=NULL)
					inputFunction();
				AT_setMLCode(cmd, mlOperands, mlOperandAddrs);
				for(srcIdx = 0 ; srcIdx<operandCnt; srcIdx++)
				{
					if(ioType[srcIdx]==IOTypeSRC||ioType[srcIdx]==IOTypeDST)
					{
						if(!AT_setInputSrcWord(mlOperands[srcIdx], mlOperandAddrs[srcIdx],initialValue[srcIdx], initialValueSize[srcIdx]))
						{
							DBG_LOGPRINT("[Error] while srcIDx = %d < %d = operandCnt\n", srcIdx, operandCnt);
							int t =1, f = 0;
							CU_ASSERT_EQUAL(t, f);
							fclose(file);
							return FALSE;
						}
					}
				}

				TestCodeTearDownByTaskIdx(0);
				/*DBG_LOGPRINT("[IN ]");
				for(idxOP=0; idxOP<operandCnt; idxOP++)
				{
					DBG_LOGPRINT(" OP%d[%s%d]<-%d, ",idxOP, opndic[mlOperands[idxOP]].strType, mlOperandAddrs[idxOP],currInitialValue[idxOP][0]);
				}
				DBG_LOGPRINT("(isOn:%d)\n", runAsOn);
*/
				if(!runAdditionalTestCode(runAsPls+1, testName))
				{
					//DBG_LOGPRINT("---[F]\n");
					//DBG_LOGPRINT("!\n");
					int t =1, f = 0;
					CU_ASSERT_EQUAL(t, f);
					isSuccess = FALSE;
					continue;
				}
				if(!AT_assertWordResult(mlOperands[dstIDX], mlOperandAddrs[dstIDX], expected, expectedSize, runAsOn))
				{
					//DBG_LOGPRINT("----[F]\n");
					int t =1, f = 0;
					CU_ASSERT_EQUAL(t, f);
					isSuccess = FALSE;
					continue;
				}
				//DBG_LOGPRINT("----[P]\n");
			}
		}
	}
	fclose(file);
	if(isSuccess)
	{
		remove(testName);
	}
	return TRUE;
}
