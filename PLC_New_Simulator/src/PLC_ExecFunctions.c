/*
 * PLC_ExecFunctions.c
 *
 *  Created on: 2014. 10. 27.
 *      Author: skson
 */


#ifndef PLC_EXECFUNCTIONS_H_
#include "PLC_ExecFunctions.h"

#endif
#include "PLC_PointTable.h"
#include "PLC_OperatorDictionary.h"
#include <stdlib.h>
#include <time.h>



/**
 * Almost of functions has common structure ::
 * [Load from]
 * [Calculate Logically]
 * [Store at]
 */
//static char buf[100];
//static int idxLD = 0;
inline uint32 execNOP(uint8 inst[], uint32* pos, PLC_Operator* opt){

	//PLC_LOG_addLog("\tConfirm NOP.");

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execNOPLF(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execPAGE(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execSTOP(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execLD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_load(inst, pos, opt, 0, FALSE);
}

inline uint32 execLDI(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_load(inst, pos, opt, 0, TRUE);
}

inline uint32 execLDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_load(inst, pos, opt, 1, FALSE);
}
inline uint32 execLDF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_load(inst, pos, opt, -1, FALSE);
}
inline uint32 execLDIP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_load(inst, pos, opt, 1, TRUE);
}
inline uint32 execLDIF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_load(inst, pos, opt, -1, TRUE);
}

inline uint32 execAND(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_AND;
	uint8 pulse = FUNCTION_PULSETYPE_NORMAL;
	uint8 inv = FUNCTION_OUTTYPE_NORMAL;
	//uint32 getValue = inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
	//save
	//return postProcess_changeCurrentBranchValue(inst, pos, opt, getValue);
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execANDI(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_AND;
	uint8 pulse = FUNCTION_PULSETYPE_NORMAL;
	uint8 inv = FUNCTION_OUTTYPE_INVERT;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execANDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_AND;
	uint8 pulse = FUNCTION_PULSETYPE_RAISING;
	uint8 inv = FUNCTION_OUTTYPE_NORMAL;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execANDF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_AND;
	uint8 pulse = FUNCTION_PULSETYPE_FALLING;
	uint8 inv = FUNCTION_OUTTYPE_NORMAL;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execANDIP(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint8 logic = FUNCTION_TYPE_AND;
	uint8 pulse = FUNCTION_PULSETYPE_RAISING;
	uint8 inv = FUNCTION_OUTTYPE_INVERT;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execANDIF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint8 logic = FUNCTION_TYPE_AND;
	uint8 pulse = FUNCTION_PULSETYPE_FALLING;
	uint8 inv = FUNCTION_OUTTYPE_INVERT;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execOR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_OR;
	uint8 pulse = FUNCTION_PULSETYPE_NORMAL;
	uint8 inv = FUNCTION_OUTTYPE_NORMAL;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execORI(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_OR;
	uint8 pulse = FUNCTION_PULSETYPE_NORMAL;
	uint8 inv = FUNCTION_OUTTYPE_INVERT;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execORP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_OR;
	uint8 pulse = FUNCTION_PULSETYPE_RAISING;
	uint8 inv = FUNCTION_OUTTYPE_NORMAL;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execORF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_OR;
	uint8 pulse = FUNCTION_PULSETYPE_FALLING;
	uint8 inv = FUNCTION_OUTTYPE_NORMAL;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execORIP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_OR;
	uint8 pulse = FUNCTION_PULSETYPE_RAISING;
	uint8 inv = FUNCTION_OUTTYPE_INVERT;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execORIF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint8 logic = FUNCTION_TYPE_OR;
	uint8 pulse = FUNCTION_PULSETYPE_FALLING;
	uint8 inv = FUNCTION_OUTTYPE_INVERT;
	return inProcess_logicSequence(inst, pos, opt, logic, pulse, inv);
}
inline uint32 execANB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getValue2 = PLC_DEVICE_pullBlockResult();
	uint32 getValue1 = PLC_DEVICE_pickBlockResult();

	if(getValue1==STACK_FALSE)
	{

		DBG_LOGPRINT("\t[ERROR ORB] getValue1 returns STACK_FALSE!!!\n");

		return FALSE;
	}
	if(getValue2==STACK_FALSE)
	{

		DBG_LOGPRINT("\t[ERROR ORB] getValue2 returns STACK_FALSE!!!\n");

		return FALSE;
	}
	//DBG_LOGPRINT("\t[ANB] getValue1 = %d, getValue2 = %d, ANB = %d\n",getValue1, getValue2, getValue1& getValue2);
	return postProcess_changeCurrentBranchValue(inst, pos, opt, getValue1& getValue2);

}
inline uint32 execORB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint32 getValue2 = PLC_DEVICE_pullBlockResult();
	uint32 getValue1 = PLC_DEVICE_pickBlockResult();

	if(getValue1==STACK_FALSE)
	{

		DBG_LOGPRINT("\t[ERROR ORB] getValue1 returns STACK_FALSE!!!\n");

		return FALSE;
	}
	if(getValue2==STACK_FALSE)
	{

		DBG_LOGPRINT("\t[ERROR ORB] getValue2 returns STACK_FALSE!!!\n");
		return FALSE;
	}

	//DBG_LOGPRINT("\t[ORB] getValue1 = %d, getValue2 = %d, ORB = %d\n",  getValue1, getValue2, getValue1 | getValue2);
	return postProcess_changeCurrentBranchValue(inst, pos, opt, getValue1 | getValue2);
}
inline uint32 execMPS(uint8 inst[], uint32* pos, PLC_Operator* opt)//make new branch from a new point
{

	//load
	uint8 getValue = (uint8)getCurrBitValue(*pos);
#if PLC_LOG_DEF
	DBG_LOGPRINT("Current sequence value = %d\n", getValue);
#endif
	//logic
	if(getValue == PLC_DEVICE_FALSE_32 )
		return FALSE;
	//getValue = inProcess_detectRaisingEdge(getValue);

	//save
	//printf("MPS branched: %d\n", getValue);
	if(!TaskList_MPSBranch(getValue))
	{
		DBG_LOGPRINT("[ERROR] MPs Branch writing failed!\n");
		return FALSE;
	}
	return postProcess_pushNewBranchedValue(inst, pos, opt, getValue);

}
inline uint32 execMRD(uint8 inst[], uint32* pos, PLC_Operator* opt)//make new branch from a branched point
{
	//load
	uint8 getValue;// = getCurrBitValue(*pos);
	if(!TaskList_MRDBranch(&getValue))
		return FALSE;
#if PLC_LOG_DEF
	DBG_LOGPRINT("Current sequence value = %d\n", getValue);
#endif

	//logic
	/*if(getValue == PLC_DEVICE_FALSE_32 )
	{
		DBG_LOGPRINT("[ERROR] MRD Branch loading failed!\n");
		return FALSE;
	}*/
	//getValue = inProcess_detectRaisingEdge(getValue);

	//save
	//printf("MRD branched: %d\n", getValue);
	return postProcess_pushNewBranchedValue(inst, pos, opt, getValue);
}
inline uint32 execMPP(uint8 inst[], uint32* pos, PLC_Operator* opt)//make last branch from a branched point
{
	//load
	uint8 getValue;// getCurrBitValue(*pos);
	if(!TaskList_MPPBranch(&getValue))
	{
		DBG_LOGPRINT("[ERROR] MPP Branch loading failed!\n");
		return FALSE;
	}
#if PLC_LOG_DEF
	DBG_LOGPRINT("Current sequence value = %d\n", getValue);
#endif
	//logic
	//if(getValue == PLC_DEVICE_FALSE_32 )
	//	return FALSE;
	//getValue = inProcess_detectRaisingEdge(getValue);

	//save
	//printf("MPP branched: %d\n", getValue);
	return postProcess_changeCurrentBranchValue(inst, pos, opt, getValue);
}
inline uint32 execINV(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint32 getValue = getCurrBitValue(*pos);

	//logic
	if(getValue == PLC_DEVICE_FALSE_32 )
		return FALSE;
	getValue = inProcess_inv(getValue);

	//save
	return postProcess_changeCurrentBranchValue(inst, pos, opt, getValue);
}
inline uint32 execMEP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint32 plsValue = preProcess_pick(*pos);
	uint32 getValue = getCurrBitValue(*pos);
	uint32 rstValue;
	plsValue&=0x01;



	//logic
	//printf("%d(%d) %d(%d) :%d\n", getValue,getValue&0x01, plsValue,plsValue&0x02, ((getValue&0x01) | (plsValue&0x02)));
	if(getValue == PLC_DEVICE_FALSE_32 || plsValue == PLC_DEVICE_FALSE_32)
		return FALSE;
	if(getValue && !plsValue)
		rstValue=1;
	else
		rstValue=0;

	//DBG_LOGPRINT("\t[getValue]%d,[plsValue]%d\n",getValue,plsValue);


	//save
	//DBG_LOGPRINT("pls : %d\n",STACK_get(&(dev.device_pulse_stack), 0));
	return postProcess_changeCurrentBranchValue(inst, pos, opt, rstValue);
}
inline uint32 execMEF(uint8 inst[], uint32* pos, PLC_Operator* opt){//load
	uint32 plsValue = preProcess_pick(*pos);
	uint32 getValue = getCurrBitValue(*pos);
	uint32 rstValue;
	plsValue&=0x01;

	//printf("%d -> %d\n", plsValue, getValue);

	//logic
	//printf("%d(%d) %d(%d) :%d\n", getValue,getValue&0x01, plsValue,plsValue&0x02, ((getValue&0x01) | (plsValue&0x02)));
	if(getValue == PLC_DEVICE_FALSE_32 || plsValue == PLC_DEVICE_FALSE_32)
		return FALSE;
	if(!getValue && plsValue)
		rstValue=1;
	else
		rstValue=0;

	return postProcess_changeCurrentBranchValue(inst, pos, opt, rstValue);
}
inline uint32 execEGP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint32 getValue = getCurrBitValue(*pos);
	uint32 plsValue = preProcess_loadPulse();
	if(inProcess_savePulse(getValue)==PLC_DEVICE_FALSE_32)
			return FALSE;
	//logic
	//printf("%d(%d) %d(%d) :%d\n", getValue,getValue&0x01, plsValue,plsValue&0x02, ((getValue&0x01) | (plsValue&0x02)));
	if(getValue == PLC_DEVICE_FALSE_32 || plsValue == PLC_DEVICE_FALSE_32)
		return FALSE;
	if(((getValue&0x01) | (plsValue&0x02)) ==1)
		getValue = 1;
	else
		getValue = 0;
	return postProcess_changeCurrentBranchValue(inst, pos, opt, getValue);
}
inline uint32 execEGF(uint8 inst[], uint32* pos, PLC_Operator* opt){//load
	uint32 getValue = getCurrBitValue(*pos);
	uint32 plsValue = preProcess_loadPulse();
	if(inProcess_savePulse(getValue)==PLC_DEVICE_FALSE_32)
			return FALSE;
	//logic
	//printf("%d(%d) %d(%d) :%d\n", getValue,getValue&0x01, plsValue,plsValue&0x02, ((getValue&0x01) | (plsValue&0x02)));
	if(getValue == PLC_DEVICE_FALSE_32 || plsValue == PLC_DEVICE_FALSE_32)
		return FALSE;
	if(((getValue&0x01) | (plsValue&0x02)) ==2)
		getValue = 1;
	else
		getValue = 0;
	return postProcess_changeCurrentBranchValue(inst, pos, opt, getValue);
}
inline uint32 execOUT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getValue = getCurrBitValue(*pos);

	return postProcess_out(inst, pos, opt, getValue);;
}
inline uint32 execSET(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint32 getValue = getCurrBitValue(*pos);
	//if(inProcess_savePulse(getValue)==PLC_DEVICE_FALSE_32)
//		return FALSE;
	//printf("getValue = %d\n", getValue);
	if((getValue&0x01)== 1)
	{

		return postProcess_out(inst, pos, opt, 1);
		//else do nothing
	}
	//save
	//DBG_LOGPRINT("pls : %d\n",STACK_get(&(dev.device_pulse_stack), 0));
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execRST(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint32 getValue = getCurrBitValue(*pos);
	if(inProcess_savePulse(getValue)==PLC_DEVICE_FALSE_32)
		return FALSE;
	if((getValue&0x01)== 1)
	{
		//handle if F reg is reset
		//uint8* operand = inProcess_getIndexedOperand(inst, *pos, 0);
		return postProcess_out(inst, pos, opt, 0);
		//else do nothing
	}
	//save
	//DBG_LOGPRINT("pls : %d\n",STACK_get(&(dev.device_pulse_stack), 0));
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execPLS(uint8 inst[], uint32* pos, PLC_Operator* opt){

	//load
	uint32 plsValue = preProcess_pick(*pos);
	uint32 getValue = getCurrBitValue(*pos);
	if(getValue == PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[%s] error while loading current value!", opt->strName);
		return FALSE;
	}
	if(plsValue ==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[%s] error while loading current value!", opt->strName);
		return FALSE;
	}
	return postProcess_out(inst, pos, opt, inProcess_detectRaisingEdge(getValue, plsValue));


}
inline uint32 execPLF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint32 plsValue = preProcess_pick(*pos);
	uint32 getValue = getCurrBitValue(*pos);
	if(getValue == PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[%s] error while loading current value!", opt->strName);
		return FALSE;
	}
	if(plsValue ==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[%s] error while loading current value!", opt->strName);
		return FALSE;
	}
	return postProcess_out(inst, pos, opt, inProcess_detectFallingEdge(getValue, plsValue));
}
inline uint32 execFF(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 plsValue = preProcess_pick(*pos);
	uint32 getValue = getCurrBitValue(*pos);


	uint32 getOperandValue = preProcess_load(inst, *pos, opt, 0);

	if(inProcess_detectRaisingEdge(getValue, plsValue))
	{
		//printf("act raising \n");
		//printf("%s op. old : %d, new : %d, in = %d, !in = %d\n", __FUNCTION__, plsValue, getValue,getOperandValue, !getOperandValue);
		return postProcess_out(inst, pos, opt, !getOperandValue);
		//getOperandValue = !getOperandValue;//(getOperandValue& 0xFD) | ((getOperandValue&0x01)==0?1:0);
	}
	//printf("%s nop. old : %d, new : %d, in = %d, !in = %d\n", __FUNCTION__, plsValue, getValue,getOperandValue, !getOperandValue);
	return postProcess_nop(inst, pos, opt);

}
inline uint32 execDELTA(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint32 plsValue = preProcess_pick(*pos);
	uint32 getValue = getCurrBitValue(*pos);
	//uint32 getFastValue = preProcess_loadDelta();
	//logic
	if(getValue == PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[%s] error while loading current value!", opt->strName);
		return FALSE;
	}
	if(plsValue ==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[%s] error while loading current value!", opt->strName);

		return FALSE;
	}


	return postProcess_out(inst, pos, opt, inProcess_detectFallingEdge(getValue, plsValue));
}
inline uint32 execDELTAP(uint8 inst[], uint32* pos, PLC_Operator* opt){//load
	uint32 getValue = getCurrBitValue(*pos);
	uint32 getDeltaActivated = preProcess_loadDelta();
	//logic
	if(getValue == PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_isPulse(getValue) && getDeltaActivated==0)
	{
		getValue = 1;
		if(inProcess_saveDelta(getValue)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	else
		getValue = 0;

	return postProcess_out(inst, pos, opt, getValue);
}
inline uint32 execSFT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue)
	{
		uint32 getTargetValue = preProcess_loadFront(inst, *pos, opt, 1);
		if(getTargetValue==PLC_DEVICE_FALSE_32)
		{
			return FALSE;
		}
	}
	return postProcess_nop(inst, pos, opt);

}
inline uint32 execSFTP(uint8 inst[], uint32* pos, PLC_Operator* opt){//load
	uint32 plsValue = preProcess_pick(*pos);
	uint32 getValue = getCurrBitValue(*pos);

	//logic
	if(inProcess_detectRaisingEdge(getValue,plsValue))
	{
		uint32 getTargetValue = preProcess_loadFront(inst, *pos, opt, 1);
		if(getTargetValue==PLC_DEVICE_FALSE_32)
			return FALSE;
	}

	return postProcess_nop(inst, pos, opt);

}
inline uint32 execMC(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load
	//uint32 getValue = preProcess_load(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);
	//logic
	if(getCurrValue == PLC_DEVICE_FALSE_32 )
		return FALSE;


	uint16 firstOperand = preProcess_load(inst, *pos, opt, 0);
	uint8* secondOperand = inProcess_getIndexedOperand(inst, *pos, 1);



	if(getCurrValue)
	{
		if(!PLC_TaskExecutor_enterMCLegion((uint8)firstOperand))
			return FALSE;

		if(!PLC_DEVICE_setDeviceValue(secondOperand, 1, 0))
			return FALSE;
	}
	else
	{
		if(!PLC_TaskExecutor_turnOffMCLegion((uint8)firstOperand))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);

}
inline uint32 execMCR(uint8 inst[], uint32* pos, PLC_Operator* opt){//load
	//uint32 getValue = preProcess_load(inst, pos, opt);

	uint16 firstOperand = preProcess_load(inst, *pos, opt, 0);


	if(!PLC_TaskExecutor_exitMCLegion((uint8)firstOperand))
		return FALSE;
	//save
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFEND(uint8 inst[], uint32* pos, PLC_Operator* opt){
	inProcess_rewindPulseDeltaStack();

	if(dev.forStack.count>0)
	{
		handleExecError(4200);
	}
	return postProcess_nop(inst, pos, opt);
}

inline uint32 execEND(uint8 inst[], uint32* pos, PLC_Operator* opt){
	inProcess_rewindPulseDeltaStack();
	if(dev.forStack.count>0)
	{
		handleExecError(4200);
	}
	return postProcess_nop(inst, pos, opt);
}

inline uint32 execLDEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){

	return inProcess_compareValue(inst, pos, opt,
			inProcess_isEqual, 2, FUNCTION_TYPE_LD
			);
}
inline uint32 execLDNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
				inProcess_isNotEqual, 2, FUNCTION_TYPE_LD
				);
}
inline uint32 execLDGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
				inProcess_isGreaterThan, 2, FUNCTION_TYPE_LD
				);
}
inline uint32 execLDLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
				inProcess_isLesserThan, 2, FUNCTION_TYPE_LD
				);
}
inline uint32 execLDGE(uint8 inst[], uint32* pos, PLC_Operator* opt){

	return inProcess_compareValue(inst, pos, opt,
				inProcess_isGreaterOrEqual, 2, FUNCTION_TYPE_LD
				);
}
inline uint32 execLDLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
				inProcess_isLesserOrEqual, 2, FUNCTION_TYPE_LD
				);
}
inline uint32 execLDDEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
					inProcess_isDWordEqual, 4, FUNCTION_TYPE_LD
					);
}
inline uint32 execLDDNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
						inProcess_isDWordNotEqual, 4, FUNCTION_TYPE_LD
						);
}
inline uint32 execLDDGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordGreaterThan, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDDLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordLesserThan, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDDGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordGreaterOrEqual, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDDLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordLesserOrEqual, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDEEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleEqual, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDENE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleNotEqual, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDEGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterThan, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDELT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserThan, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDEGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterOrEqual, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDELE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserOrEqual, 4, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDEDEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleEqual, 8, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDEDNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleNotEqual, 8, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDEDGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterThan, 8, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDEDLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserThan, 8, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDEDGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterOrEqual, 8, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDEDLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserOrEqual, 8, FUNCTION_TYPE_LD
		);
}
inline uint32 execLDSTREQ(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 ret;
	//preprocess
	//printf("%s %d\n", __FUNCTION__, __LINE__);
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	//printf("%s %d\n", __FUNCTION__, __LINE__);
	//logic
	if(compareResult == COMPARE_RESULT_EQUAL)
		ret = 1;
	else
		ret = 0;
	//printf("%s %d\n", __FUNCTION__, __LINE__);
	//return
	return postProcess_pushNewBranchedValue(inst, pos, opt, ret);
}
inline uint32 execLDSTRNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;
	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);

	//logic
	if(compareResult == COMPARE_RESULT_EQUAL)
		ret = 0;
	else
		ret = 1;

	//return
	return postProcess_pushNewBranchedValue(inst, pos, opt, ret);

}
inline uint32 execLDSTRGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;
	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_BIG)
		ret = 1;
	else
		ret = 0;

	//return
	return postProcess_pushNewBranchedValue(inst, pos, opt, ret);
}
inline uint32 execLDSTRLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;
	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_SMALL)
		ret = 1;
	else
		ret = 0;

	//return
	return postProcess_pushNewBranchedValue(inst, pos, opt, ret);
}
inline uint32 execLDSTRGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;
	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_SMALL)
		ret = 0;
	else
		ret = 1;

	//return
	return postProcess_pushNewBranchedValue(inst, pos, opt, ret);
}
inline uint32 execLDSTRLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;
	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_BIG)
		ret = 0;
	else
		ret = 1;

	//return
	return postProcess_pushNewBranchedValue(inst, pos, opt, ret);
}
inline uint32 execANDEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isEqual, 2, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isNotEqual, 2, FUNCTION_TYPE_AND
		);

}
inline uint32 execANDGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isGreaterThan, 2, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isLesserThan, 2, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isGreaterOrEqual, 2, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isLesserOrEqual, 2, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDDEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordEqual, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDDNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordNotEqual, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDDGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordGreaterThan, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDDLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordLesserThan, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDDGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordGreaterOrEqual, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDDLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordLesserOrEqual, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDEEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleEqual, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDENE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleNotEqual, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDEGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterThan, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDELT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserThan, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDEGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterOrEqual, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDELE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserOrEqual, 4, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDEDEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleEqual, 8, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDEDNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleNotEqual, 8, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDEDGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterThan, 8, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDEDLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserThan, 8, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDEDGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterOrEqual, 8, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDEDLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserOrEqual, 8, FUNCTION_TYPE_AND
		);
}
inline uint32 execANDSTREQ(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_EQUAL)
		ret = 1;
	else
		ret = 0;

	ret &= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execANDSTRNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_EQUAL)
		ret = 0;
	else
		ret = 1;

	ret &= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execANDSTRGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_BIG)
		ret = 1;
	else
		ret = 0;

	ret &= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execANDSTRLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_SMALL)
		ret = 1;
	else
		ret = 0;

	ret &= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execANDSTRGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_SMALL)
		ret = 0;
	else
		ret = 1;

	ret &= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execANDSTRLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_BIG)
		ret = 0;
	else
		ret = 1;

	ret &= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execOREQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isEqual, 2, FUNCTION_TYPE_OR
		);
}
inline uint32 execORNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isNotEqual, 2, FUNCTION_TYPE_OR
		);
}
inline uint32 execORGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isGreaterThan, 2, FUNCTION_TYPE_OR
		);
}
inline uint32 execORLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isLesserThan, 2, FUNCTION_TYPE_OR
		);
}
inline uint32 execORGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isGreaterOrEqual, 2, FUNCTION_TYPE_OR
		);
}
inline uint32 execORLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isLesserOrEqual, 2, FUNCTION_TYPE_OR
		);
}
inline uint32 execORDEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordEqual, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execORDNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordNotEqual, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execORDGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordGreaterThan, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execORDLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordLesserThan, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execORDGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordGreaterOrEqual, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execORDLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareValue(inst, pos, opt,
		inProcess_isDWordLesserOrEqual, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execOREEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleEqual, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execORENE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleNotEqual, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execOREGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterThan, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execORELT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserThan, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execOREGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleGreaterOrEqual, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execORELE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
		inProcess_isDoubleLesserOrEqual, 4, FUNCTION_TYPE_OR
		);
}
inline uint32 execOREDEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
			inProcess_isDoubleEqual, 8, FUNCTION_TYPE_OR
			);
}
inline uint32 execOREDNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
			inProcess_isDoubleNotEqual, 8, FUNCTION_TYPE_OR
			);
}
inline uint32 execOREDGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
			inProcess_isDoubleGreaterThan, 8, FUNCTION_TYPE_OR
			);
}
inline uint32 execOREDLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
			inProcess_isDoubleLesserThan, 8, FUNCTION_TYPE_OR
			);
}
inline uint32 execOREDGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
			inProcess_isDoubleGreaterOrEqual, 8, FUNCTION_TYPE_OR
			);
}
inline uint32 execOREDLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_compareFloatValue(inst, pos, opt,
			inProcess_isDoubleLesserOrEqual, 8, FUNCTION_TYPE_OR
			);
}

inline uint32 execORSTREQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_EQUAL)
		ret = 1;
	else
		ret = 0;

	ret |= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execORSTRNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_EQUAL)
		ret = 0;
	else
		ret = 1;

	ret |= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execORSTRGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_BIG)
		ret = 1;
	else
		ret = 0;

	ret |= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execORSTRLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_SMALL)
		ret = 1;
	else
		ret = 0;

	ret |= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execORSTRGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_SMALL)
		ret = 0;
	else
		ret = 1;

	ret |= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}
inline uint32 execORSTRLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 ret;

	//preprocess
	uint32 compareResult = preProcess_compareString(inst, pos, opt);
	uint32 getCurrValue = getCurrBitValue(*pos);

	//logic
	if(compareResult == COMPARE_RESULT_FIRST_IS_BIG)
		ret = 0;
	else
		ret = 1;

	ret |= getCurrValue;
	//return
	return postProcess_changeCurrentBranchValue(inst, pos, opt, ret);
}

inline uint32 execBKCMPEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	//printf("%s %d\n", __FUNCTION__, __LINE__);
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isEqual, FALSE)==PLC_DEVICE_FALSE_32)
	{
		return FALSE;
	}

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isNotEqual, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isGreaterThan, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isLesserThan, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isGreaterOrEqual, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isLesserOrEqual, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPEQP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isEqual, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPNEP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isNotEqual, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPGTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isGreaterThan, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPLTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isLesserThan, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPGEP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isGreaterOrEqual, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKCMPLEP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareWordBlock(inst, pos, opt, inProcess_isLesserOrEqual, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPEQ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordEqual, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPNE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordNotEqual, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPGT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordGreaterThan, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordLesserThan, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPGE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordGreaterOrEqual, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPLE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordLesserOrEqual, FALSE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPEQP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordEqual, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPNEP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordNotEqual, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPGTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isGreaterThan, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPLTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordLesserThan, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPGEP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordGreaterOrEqual, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBKCMPLEP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//preprocess	//logic
	if( preProcess_compareDoubleWordBlock(inst, pos, opt, inProcess_isDWordLesserOrEqual, TRUE)==PLC_DEVICE_FALSE_32)
		return FALSE;

	//return
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execADD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//printf("execADD\n");
	if( preProcess_calculate(inst, pos, opt, inProcess_addInt, FALSE, FALSE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execADDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addInt, TRUE, FALSE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSUB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subInt, FALSE, FALSE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSUBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subInt, TRUE, FALSE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execADDS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addInt, FALSE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execADDPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addInt, TRUE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSUBS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subInt, FALSE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSUBPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subInt, TRUE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execMLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_mltInt, FALSE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execMLTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_mltInt, TRUE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDIV(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_divInt, FALSE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDIVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_divInt, TRUE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDADD(uint8 inst[], uint32* pos, PLC_Operator* opt){

	if( preProcess_calculate(inst, pos, opt, inProcess_addInt, FALSE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDADDP(uint8 inst[], uint32* pos, PLC_Operator* opt){

	if( preProcess_calculate(inst, pos, opt, inProcess_addInt, TRUE, FALSE, 4)==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\texecDADDP:preProcess_calculate Error!\n");
		return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDSUB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subInt, FALSE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDSUBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subInt, TRUE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDADDS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addInt, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDADDPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addInt, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDSUBS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subInt, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDSUBPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subInt, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDMLT(uint8 inst[], uint32* pos, PLC_Operator* opt){

	if( preProcess_calculate(inst, pos, opt, inProcess_mltInt, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
	{
		//printf("fail to calculate DMLT\n");
		return FALSE;
	}

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDMLTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_mltInt, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDDIV(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_divInt, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDDIVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_divInt, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBADD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, (*inProcess_addBCD), FALSE, FALSE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBADDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addBCD, TRUE, FALSE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBSUB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subBCD, FALSE, FALSE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBSUBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subBCD, TRUE, FALSE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBADDS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addBCD, FALSE, TRUE, 2)==PLC_DEVICE_FALSE_32)
	{
		//printf("\t[Error] while executing %s!\n",__FUNCTION__);
		return FALSE;
	}
	//printf("\t[Pass] while executing %s!\n",__FUNCTION__);
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBADDPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addBCD, TRUE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBSUBS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subBCD, FALSE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBSUBPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subBCD, TRUE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBMLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_mltBCD, FALSE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBMLTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_mltBCD, TRUE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBDIV(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_divBCD, FALSE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBDIVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_divBCD, TRUE, TRUE, 2)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBADD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addBCD, FALSE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBADDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addBCD, TRUE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBSUB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subBCD, FALSE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBSUBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subBCD, TRUE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBADDS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addBCD, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBADDPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_addBCD, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBSUBS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subBCD, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBSUBPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_subBCD, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBMLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_mltBCD, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBMLTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_mltBCD, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBDIV(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_divBCD, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDBDIVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculate(inst, pos, opt, inProcess_divBCD, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEADD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_addFloat, FALSE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEADDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_addFloat, TRUE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execESUB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_subFloat, FALSE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execESUBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_subFloat, TRUE, FALSE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEADDS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_addFloat, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEADDPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_addFloat, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execESUBS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_subFloat, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execESUBPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_subFloat, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEMLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_mltFloat, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEMLTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_mltFloat, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDIV(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_divFloat, FALSE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDIVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_divFloat, TRUE, TRUE, 4)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDADD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_addFloat, FALSE, FALSE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDADDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_addFloat, TRUE, FALSE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDSUB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_subFloat, FALSE, FALSE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDSUBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_subFloat, TRUE, FALSE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDADDS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_addFloat, FALSE, TRUE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDADDPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_addFloat, TRUE, TRUE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDSUBS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_subFloat, FALSE, TRUE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDSUBPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_subFloat, TRUE, TRUE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDMLT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_mltFloat, FALSE, TRUE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDMLTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_mltFloat, TRUE, TRUE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDDIV(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_divFloat, FALSE, TRUE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEDDIVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	if( preProcess_calculateFloat(inst, pos, opt, inProcess_divFloat, TRUE, TRUE, 8)==PLC_DEVICE_FALSE_32)
		return FALSE;
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKADD(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue&0x01){
		if(!inProcess_calculateBK(inst, *pos, inProcess_addInt))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
	/*

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue&0x01)
	{
		uint8 rstSize;
		uint8 *s1Opnd = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8 *s2Opnd = inProcess_getIndexedOperand(inst, *pos, 1);
		uint8 *dOpnd = inProcess_getIndexedOperand(inst, *pos, 2);
		uint8 *nOpnd = inProcess_getIndexedOperand(inst, *pos, 3);
		int idx;
		uint16 nVal ;//= PLC_DEVICE_getDeviceValue(nOpnd);
		if(!test_getValue(&nVal, &rstSize, nOpnd, 0))
			return FALSE;
		if(nVal ==PLC_DEVICE_FALSE_32)
			return FALSE;
		//DBG_LOGPRINT("nVal %d\n", nVal);
		for(idx=0;idx<nVal;idx++)
		{
			long long src1=0, src2=0, dst=0;

			if(!test_getValue(&src1, &rstSize, s1Opnd, idx))
				return FALSE;
			if(!test_getValue(&src2, &rstSize, s2Opnd, idx))
				return FALSE;
			if(!inProcess_addInt(&dst, &src1, &src2, 2))
				return FALSE;

			//DBG_LOGPRINT("[idx%d]%d+%d => %d\n", idx, src1, src2, dst);

			if(!PLC_DEVICE_setDeviceValue(dOpnd, dst, idx))
				return FALSE;
		}

	}*/

}
inline uint32 execBKADDP(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue))
	{
		if(!inProcess_calculateBK(inst, *pos, inProcess_addInt))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKSUB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue&0x01)
	{
		if(!inProcess_calculateBK(inst, *pos, inProcess_subInt))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKSUBP(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue))
	{
		if(!inProcess_calculateBK(inst, *pos, inProcess_subInt))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBKADDS(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execBKADDPS(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execBKSUBS(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execBKSUBPS(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execSTRADD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre
	uint32 getCurrValue = getCurrBitValue(*pos);
	//in
	if(getCurrValue==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
		return FALSE;
	}

	if((getCurrValue&0x01) ==1)
	{
		uint8* getFirstOperand = preProcess_loadString(inst, *pos, opt, 0);
		uint8* getSecondOperand = preProcess_loadString(inst, *pos, opt, 1);
		if(getFirstOperand==NULL)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getSecondOperand==NULL)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		if(!inProcess_addString(getSecondOperand, getSecondOperand , getFirstOperand))
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

	}
	//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSTRADDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre
	//uint32 ret=TRUE;
	uint32 getFastValue = preProcess_pick(*pos);
	if(getFastValue==PLC_DEVICE_FALSE_32){
		DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
		return FALSE;
	}

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32){
		DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
		return FALSE;
	}

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue))
	{
		uint8* getFirstOperand = preProcess_loadString(inst, *pos, opt, 0);
		if(getFirstOperand==NULL){
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		uint8* getSecondOperand = preProcess_loadString(inst, *pos, opt, 1);
		if(getSecondOperand==NULL){
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		if(!inProcess_addString(getSecondOperand, getSecondOperand , getFirstOperand))
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		//DBG_LOGPRINT("\t[END]\n");
	}
	//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSTRADDS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre
	//uint32 ret;

	uint32 getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	if((getCurrValue&0x01) ==1)
	{
		//in
		uint8* getFirstOperand = preProcess_loadString(inst, *pos, opt, 0);
		if(getFirstOperand==NULL)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		uint8* getSecondOperand = preProcess_loadString(inst, *pos, opt, 1);
		if(getSecondOperand==NULL)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		uint8* getThirdOperand = preProcess_loadString(inst, *pos, opt, 2);
		if(getThirdOperand==NULL)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		if(!inProcess_addString(getThirdOperand, getFirstOperand, getSecondOperand))
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
	}
	//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSTRADDPS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre
	uint32 getFastValue = preProcess_pick(*pos);
	if(getFastValue==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
		return FALSE;
	}

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
		return FALSE;
	}
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		//in
		uint8* getFirstOperand = preProcess_loadString(inst, *pos, opt, 0);
		if(getFirstOperand==NULL)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		uint8* getSecondOperand = preProcess_loadString(inst, *pos, opt, 1);
		if(getSecondOperand==NULL)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		uint8* getThirdOperand = preProcess_loadString(inst, *pos, opt, 2);
		if(getThirdOperand==NULL)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		if(inProcess_addString(getThirdOperand, getFirstOperand, getSecondOperand)==FALSE)
		{
			return FALSE;
		}
	}
	//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execINC(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre

	uint32 getCurrValue = getCurrBitValue(*pos);
	if((getCurrValue&0x01) ==1){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);

		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		inProcess_saveToDev(inst, pos, opt, getFirstOperand+1, 0, 2);
	}
	else
	{
		DBG_LOGPRINT("Turn off!\n");
	}
		//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execINCP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);

		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		inProcess_saveToDev(inst, pos, opt, getFirstOperand+1, 0, 2);
	}
		//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDEC(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre

	uint32 getCurrValue = getCurrBitValue(*pos);
	if((getCurrValue&0x01) ==1){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);

		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		inProcess_saveToDev(inst, pos, opt, getFirstOperand-1, 0, 2);
	}
		//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDECP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);

		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		inProcess_saveToDev(inst, pos, opt, getFirstOperand-1, 0, 2);
	}
		//post
	return postProcess_nop(inst, pos, opt);

}
inline uint32 execDINC(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre

	uint32 getCurrValue = getCurrBitValue(*pos);

	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);

		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		inProcess_saveToDev(inst, pos, opt, getFirstOperand+1, 0, 4);
	}
		//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDINCP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		//printf("getFirstOperand = %d\n");
		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		//printf("save getFirstOperand = %d\n", getFirstOperand+1 );
		inProcess_saveToDev(inst, pos, opt, getFirstOperand+1, 0, 4);
	}
		//post
	return postProcess_nop(inst, pos, opt);
}

inline uint32 execDDEC(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre

	uint32 getCurrValue = getCurrBitValue(*pos);
	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);

		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		inProcess_saveToDev(inst, pos, opt, getFirstOperand-1, 0, 4);
	}
		//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDDECP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);

		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		inProcess_saveToDev(inst, pos, opt, getFirstOperand-1, 0, 4);
	}
	//post
	return postProcess_nop(inst, pos, opt);

}
inline uint32 execBCDTOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//pre

	uint32 getCurrValue = getCurrBitValue(*pos);

	if((getCurrValue&0x01) ==1){

		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		uint32 getRst = 0;
		//DBG_LOGPRINT("getFirstOperand = %d\n", getFirstOperand);
		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		if(!inprocess_convertBCDToBin(&getRst, &getFirstOperand, 2))
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		//DBG_LOGPRINT("getRst = %d\n", getRst);
		inProcess_saveToDev(inst, pos, opt, getRst, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBCDTOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){//pre
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		//printf("%s %d \n", __FUNCTION__, __LINE__);
		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		if(!inprocess_convertBCDToBin(&getFirstOperand, &getFirstOperand, 2))
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}

inline uint32 execBCDTOD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);
	uint32 ret = 0;
	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);

		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		if(!inprocess_convertBCDToBin(&ret, &getFirstOperand, 4))
		{
			DBG_LOGPRINT("\t[ERROR %s%d]\n", __FUNCTION__, __LINE__);
			return FALSE;
		}

		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBCDTODP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	uint32 ret = 0;

	//DBG_LOGPRINT("get previous value : %d-->%d\n", getFastValue,getCurrValue);
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		//printf("ML_CODE_BCDTODP\n");
		//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;

		//printf("ML_CODE_BCDTODP = ret %d\n", ret);
		if(!inprocess_convertBCDToBin(&ret, &getFirstOperand, 4))
			return FALSE;
		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBLKTOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getCount = preProcess_loadWord(inst, *pos, opt, 2);
		uint16* dstPoint = (uint16*)preProcess_loadString(inst, *pos, opt, 1);
		uint16* srcPoint = (uint16*)preProcess_loadString(inst, *pos, opt, 0);
		if(dstPoint==NULL || srcPoint==NULL)
			return FALSE;
		int index;
		for(index=0;index<getCount;index++)
		{
			if(!inprocess_convertBCDToBin(&dstPoint[index], &srcPoint[index], 2))
				return FALSE;

		}
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBLKTOBCD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getCount = preProcess_loadWord(inst, *pos, opt, 2);
		uint16* dstPoint = (uint16*)preProcess_loadString(inst, *pos, opt, 1);
		uint16* srcPoint = (uint16*)preProcess_loadString(inst, *pos, opt, 0);
		if(dstPoint==NULL || srcPoint==NULL)
			return FALSE;
		int index;
		for(index=0;index<getCount;index++)
		{
			if(!inprocess_convertBinToBCD(&dstPoint[index], &srcPoint[index], 2))
				return FALSE;

		}
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBLKTOBCDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getCount = preProcess_loadWord(inst, *pos, opt, 2);
		uint16* dstPoint = (uint16*)preProcess_loadString(inst, *pos, opt, 1);
		uint16* srcPoint = (uint16*)preProcess_loadString(inst, *pos, opt, 0);
		if(dstPoint==NULL || srcPoint==NULL)
			return FALSE;
		int index;
		for(index=0;index<getCount;index++)
		{

			if(!inprocess_convertBinToBCD(&dstPoint[index], &srcPoint[index], 2))
				return FALSE;
		}
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBLKTOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getCount = preProcess_loadWord(inst, *pos, opt, 2);
		uint16* dstPoint = (uint16*)preProcess_loadString(inst, *pos, opt, 1);
		uint16* srcPoint = (uint16*)preProcess_loadString(inst, *pos, opt, 0);
		if(dstPoint==NULL || srcPoint==NULL)
			return FALSE;
		int index;
		for(index=0;index<getCount;index++)
		{

			if(!inprocess_convertBCDToBin(&dstPoint[index], &srcPoint[index], 2))
				return FALSE;
		}
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTOBCD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);

			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\tgetCurrValue Error!");
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\tgetFirstOperand Error!");
			return FALSE;
		}

		if(!inprocess_convertBinToBCD(&getFirstOperand, &getFirstOperand, 2))
		{
			DBG_LOGPRINT("\tinprocess_convertBinToBCD Error!");
			return FALSE;
		}
		inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}

inline uint32 execBTOBCDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = (short)preProcess_loadWord(inst, *pos, opt, 0);

			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		if(!inprocess_convertBinToBCD(&getFirstOperand, &getFirstOperand, 2))
			return FALSE;
		inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTOD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue & 0x01)==1){
		uint32 getFirstOperand = (short)preProcess_loadWord(inst, *pos, opt, 0);

			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;

		//DBG_LOGPRINT("execBTOD : getFirstOperand = %d \n", getFirstOperand);
		inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 4);
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTODF(uint8 inst[], uint32* pos, PLC_Operator* opt){/*
	uint32 getCurrValue = getCurrBitValue(*pos);

	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		long rst=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToDouble(&rst, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, rst, 1, 8);
	}
	//post
*/
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTODFP(uint8 inst[], uint32* pos, PLC_Operator* opt){/*
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		long rst=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToDouble(&rst, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, rst, 1, 8);
	}*/
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTODP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = (short)preProcess_loadWord(inst, *pos, opt, 0);

			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTOF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		uint32 rst=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToFloat((void*)&rst, &getFirstOperand, 2);

		inProcess_saveToDev(inst, pos, opt, rst, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTOFP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		uint32 rst=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToFloat(&rst, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, rst, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTOGRY(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToGray(&ret, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTOGRYP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToGray(&ret, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDFTOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	/*
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		uint32 rst=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertDoubleToBin(&rst, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, rst, 1, 4);
	}
	//post
*/
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDFTOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
/*
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		uint32 rst=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertDoubleToBin(&rst, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, rst, 1, 2);
	}
	//post
*/
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDFTOD(uint8 inst[], uint32* pos, PLC_Operator* opt){
/*
	uint32 getCurrValue = getCurrBitValue(*pos);

	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		uint32 rst=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertDoubleToBin(&rst, &getFirstOperand, 4);
		inProcess_saveToDev(inst, pos, opt, rst, 1, 4);
	}
	//post
*/
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDFTODP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}// no implement
inline uint32 execDFTOF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}// no implement
inline uint32 execDFTOFP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}// no implement
inline uint32 execDTOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);

	//printf("execDTOB : %s %02X%02X \n", opndic[inst[0]].strType, inst[1], inst[2]);
	if((getCurrValue&0x01) ==1){

		int getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		//printf("%s %d getFirstOperand : %d\n", __FUNCTION__, __LINE__, getFirstOperand);
		uint16 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("Curr value error\n");
			return FALSE;
		}


		if(getFirstOperand>(int)0x00007FFF )
		{
			DBG_LOGPRINT("DWord value is out of WORD range = %d>%d!\n", getFirstOperand, (int)0x00007FFF);
			handleExecError(4100);
			return FALSE;
		}else if(getFirstOperand<(int)0xFFFF8000)
		{
			DBG_LOGPRINT("DWord value is out of WORD range = %d<%d!\n", getFirstOperand, (int)0xFFFF8000);
			handleExecError(4100);
			return FALSE;
		}

		ret = (uint16)getFirstOperand;
		//DBG_LOGPRINT("ret = %d\n",ret);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 2);
		//DBG_LOGPRINT("DTOB ret = %d!\n", ret);
	}
	//DBG_LOGPRINT("DTOB getCurrValue = %d!\n", getCurrValue);
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTOBCD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);

	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in

		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;

		if(!inprocess_convertBinToBCD(&ret, &getFirstOperand, 4))
			return FALSE;

		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTOBCDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret = 0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;

		if(!inprocess_convertBinToBCD(&ret, &getFirstOperand, 4))
			return FALSE;
		//DBG_LOGPRINT("DTOBCDP ret= %d\n",ret);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		int getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint16 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("Curr value error\n");
			return FALSE;
		}
		if(getFirstOperand>(int)0x00007FFF )
		{
			DBG_LOGPRINT("DWord value is out of WORD range = %d>%d!\n", getFirstOperand, (int)0x00007FFF);
			handleExecError(4100);
			return FALSE;
		}else if(getFirstOperand<(int)0xFFFF8000)
		{
			DBG_LOGPRINT("DWord value is out of WORD range = %d<%d!\n", getFirstOperand, (int)0xFFFF8000);
			handleExecError(4100);
			return FALSE;
		}

		ret = (uint16)getFirstOperand;
		//DBG_LOGPRINT("ret = %d\n",ret);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTODF(uint8 inst[], uint32* pos, PLC_Operator* opt){/*
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);

			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		//inprocess_convertBinToBCD(&getFirstOperand, getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 2);
	}
	//post
*/
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTODFP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTOF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToFloat(&ret, &getFirstOperand, 4);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTOFP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToFloat(&ret, &getFirstOperand, 4);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTOGRY(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToGray(&ret, &getFirstOperand, 4);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTOGRYP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertBinToGray(&ret, &getFirstOperand, 4);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFTOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t getCurrValue Error!\n");
			return FALSE;
		}
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t getFirstOperand Error!\n");
			return FALSE;
		}

		inprocess_convertFloatToBin(&ret, &getFirstOperand, 2);

		inProcess_saveToDev(inst, pos, opt, ret, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFTOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertFloatToBin(&ret, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFTOD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		//printf("getFirstOperand = %d(%f)\n", getFirstOperand, *(float*)&getFirstOperand);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertFloatToBin(&ret, &getFirstOperand, 4);
		//printf("ret = %X(%f)<==getValue %d(%f)\n", ret, ret, getFirstOperand, getFirstOperand);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFTODF(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFTODFP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFTODP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertFloatToBin(&ret, &getFirstOperand, 4);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execGRYTOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertGrayToBin(&ret, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execGRYTOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;

		//DBG_LOGPRINT("getFirstOperand : %04X\n",getFirstOperand);
		inprocess_convertGrayToBin(&ret, &getFirstOperand, 2);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 2);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execGRYTOD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		/*if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;
		 */
		//DBG_LOGPRINT("getFirstOperand : %08X\n",getFirstOperand);
		inprocess_convertGrayToBin(&ret, &getFirstOperand, 4);
		inProcess_saveToDev(inst, pos, opt, ret, 1, 4);
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execGRYTODP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		inprocess_convertGrayToBin(&ret, &getFirstOperand, 4);
		if(inProcess_saveToDev(inst, pos, opt, ret, 1, 4)==PLC_DEVICE_FALSE_32){
			return FALSE;
		}
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execNEG(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if((getCurrValue&0x01)==1){
		short getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		int ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		ret = -getFirstOperand;
		//printf("execENG : %d =>%d(%08X)\n",getFirstOperand, ret, ret);
		if(inProcess_saveToDev(inst, pos, opt, (uint32)ret, 0, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execNEGP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);


	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		short ret=0;
			//in
		if(getCurrValue==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		ret = -getFirstOperand;
		if(inProcess_saveToDev(inst, pos, opt, (uint32)ret, 0, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDNEG(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		int ret=0;
			//in
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		ret = -getFirstOperand;
		if(inProcess_saveToDev(inst, pos, opt, (uint32)ret, 0, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDNEGP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		int ret=0;
			//in
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		ret = -getFirstOperand;
		if(inProcess_saveToDev(inst, pos, opt, (uint32)ret, 0, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execENEG(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		float* ret=(float*)&getFirstOperand;
			//in
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		*ret = -(*ret);
		if(inProcess_saveToDev(inst, pos, opt, *(uint32*)ret, 0, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execENEGP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		float* ret=(float*)&getFirstOperand;
			//in
		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		*ret = -(*ret);
		if(inProcess_saveToDev(inst, pos, opt, *(uint32*)ret, 0, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDENEG(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDENEGP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execMOV(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
	{
		return FALSE;
	}
	if((getCurrValue&0x01) ==1){
		//printf("Function : %s, LINE : %d\\n", __FUNCTION__, __LINE__);
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		//printf("Function : %s, LINE : %d\\n", __FUNCTION__, __LINE__);
			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			return FALSE;
		}

		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 2)==PLC_DEVICE_FALSE_32)
		{
			return FALSE;
		}
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDMOV(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);

			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEMOV(uint8 inst[], uint32* pos, PLC_Operator* opt){

	return execDMOV(inst, pos, opt);
}
inline uint32 execEDMOV(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSTRMOV(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint8* src = preProcess_loadString(inst, *pos, opt, 0);
		uint8* srcOpnd = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8* dstOpnd = inProcess_getIndexedOperand(inst, *pos, 1);
			//in

		if(src==NULL || dstOpnd == NULL)
		{
			DBG_LOGPRINT("[ERROR %s] LINE = %d\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
		DBG_LOGPRINT("ready to [%s%d]%s -> [%s%d]\n", opndic[srcOpnd[0]].strType, *(uint16*)&srcOpnd[1], src, opndic[dstOpnd[0]].strType, *(uint16*)&dstOpnd[1]);
		if(!PLC_DEVICE_copyDeviceBLKs(dstOpnd,src,1+strlen((char*)src)))
		{
			DBG_LOGPRINT("[ERROR %s] LINE = %d\n", __FUNCTION__, __LINE__);
			return FALSE;
		}
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBMOV(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("[Error BMOV] getCurrValue==PLC_DEVICE_FALSE_32!\n");
		return FALSE;
	}
	if((getCurrValue&0x01) ==1){
		if(!inProcess_transperBlock(inst, *pos, 1, BLOCK_COPY_TYPE_BMOV))
			return FALSE;
		/*uint8* dstOpnd = inProcess_getIndexedOperand(inst, *pos, 1);
		uint8* srcOpnd = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8* thirdOpnd = inProcess_getIndexedOperand(inst, *pos, 2);

		uint16 srcLength = PLC_DEVICE_getDeviceWordValue(thirdOpnd);
		if(srcLength ==0xFFFF)
		{
			DBG_LOGPRINT("[Error BMOV] invalid 3rd operand is loaded!\n");
			return FALSE;
		}

			//in

		if(srcOpnd==NULL || dstOpnd == NULL)
		{
			DBG_LOGPRINT("[Error BMOV]Null operand is loaded!\n");
			return FALSE;
		}
		if(!PLC_DEVICE_copyDeviceBLK_new(dstOpnd,srcOpnd,srcLength, 1, BLOCK_COPY_TYPE_BMOV))
		{
			DBG_LOGPRINT("[Error BMOV] PLC_DEVICE_copyDeviceBLK_new returns Error!\n");
			return FALSE;
		}*/
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFMOV(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		if(!inProcess_transperBlock(inst, *pos, 1, BLOCK_COPY_TYPE_FMOV))
			return FALSE;
		/*uint8* dstOpnd = inProcess_getIndexedOperand(inst, *pos, 1);
		uint8* srcOpnd = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8* thirdOpnd = inProcess_getIndexedOperand(inst, *pos, 2);

		uint16 srcLength = PLC_DEVICE_getDeviceWordValue(thirdOpnd);
		if(srcLength ==0xFFFF)
		{
			DBG_LOGPRINT("[Error BMOV] invalid 3rd operand is loaded!\n");
			return FALSE;
		}

			//in

		if(srcOpnd==NULL || dstOpnd == NULL)
		{
			DBG_LOGPRINT("[Error BMOV]Null operand is loaded!\n");
			return FALSE;
		}
		if(!PLC_DEVICE_copyDeviceBLK_new(dstOpnd,srcOpnd,srcLength, 2, BLOCK_COPY_TYPE_FMOV))
		{
			DBG_LOGPRINT("[Error BMOV] PLC_DEVICE_copyDeviceBLK_new returns Error!\n");
			return FALSE;
		}*/
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDFMOV(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		if(!inProcess_transperBlock(inst, *pos, 2, BLOCK_COPY_TYPE_FMOV))
			return FALSE;
		/*uint8* dstOpnd = inProcess_getIndexedOperand(inst, *pos, 1);
		uint8* srcOpnd = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8* thirdOpnd = inProcess_getIndexedOperand(inst, *pos, 2);

		uint16 srcLength = PLC_DEVICE_getDeviceWordValue(thirdOpnd);
		if(srcLength ==0xFFFF)
		{
			DBG_LOGPRINT("[Error BMOV] invalid 3rd operand is loaded!\n");
			return FALSE;
		}

			//in

		if(srcOpnd==NULL || dstOpnd == NULL)
		{
			DBG_LOGPRINT("[Error BMOV]Null operand is loaded!\n");
			return FALSE;
		}
		if(!PLC_DEVICE_copyDeviceBLK_new(dstOpnd,srcOpnd,srcLength, 4, BLOCK_COPY_TYPE_FMOV))
		{
			DBG_LOGPRINT("[Error BMOV] PLC_DEVICE_copyDeviceBLK_new returns Error!\n");
			return FALSE;
		}*/
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execMOVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);

			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDMOVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);

			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEMOVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return execDMOVP(inst, pos, opt);
}
inline uint32 execEDMOVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSTRMOVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint8* src = preProcess_loadString(inst, *pos, opt, 0);
		uint8* dstOpnd = inProcess_getIndexedOperand(inst, *pos, 1);
			//in

		if(src==NULL || dstOpnd == NULL)
			return FALSE;
		if(!PLC_DEVICE_copyDeviceBLKs(dstOpnd,src,strlen((char*)src)))
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBMOVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		if(!inProcess_transperBlock(inst, *pos, 1, BLOCK_COPY_TYPE_BMOV))
			return FALSE;
		/*
		uint8* dstOpnd = inProcess_getIndexedOperand(inst, *pos, 1);
		uint8* srcOpnd = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8* thirdOpnd = inProcess_getIndexedOperand(inst, *pos, 2);

		uint16 srcLength = PLC_DEVICE_getDeviceWordValue(thirdOpnd);
		if(srcLength ==0xFFFF)
		{
			DBG_LOGPRINT("[Error BMOV] invalid 3rd operand is loaded!\n");
			return FALSE;
		}

			//in

		if(srcOpnd==NULL || dstOpnd == NULL)
		{
			DBG_LOGPRINT("[Error BMOV]Null operand is loaded!\n");
			return FALSE;
		}
		if(!PLC_DEVICE_copyDeviceBLK_new(dstOpnd,srcOpnd,srcLength, 1, BLOCK_COPY_TYPE_BMOV))
		{
			DBG_LOGPRINT("[Error BMOV] PLC_DEVICE_copyDeviceBLK_new returns Error!\n");
			return FALSE;
		}
		*/
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFMOVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		if(!inProcess_transperBlock(inst, *pos, 1, BLOCK_COPY_TYPE_FMOV))
			return FALSE;
		/*
		uint8* dstOpnd = inProcess_getIndexedOperand(inst, *pos, 1);
		uint8* srcOpnd = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8* thirdOpnd = inProcess_getIndexedOperand(inst, *pos, 2);

		uint16 srcLength = PLC_DEVICE_getDeviceWordValue(thirdOpnd);
		if(srcLength ==0xFFFF)
		{
			DBG_LOGPRINT("[Error BMOV] invalid 3rd operand is loaded!\n");
			return FALSE;
		}

			//in

		if(srcOpnd==NULL || dstOpnd == NULL)
		{
			DBG_LOGPRINT("[Error BMOV]Null operand is loaded!\n");
			return FALSE;
		}
		if(!PLC_DEVICE_copyDeviceBLK_new(dstOpnd,srcOpnd,srcLength, 2, BLOCK_COPY_TYPE_FMOV))
		{
			DBG_LOGPRINT("[Error BMOV] PLC_DEVICE_copyDeviceBLK_new returns Error!\n");
			return FALSE;
		}*/
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDFMOVP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		if(!inProcess_transperBlock(inst, *pos, 2, BLOCK_COPY_TYPE_FMOV))
			return FALSE;
		/*uint8* dstOpnd = inProcess_getIndexedOperand(inst, *pos, 1);
		uint8* srcOpnd = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8* thirdOpnd = inProcess_getIndexedOperand(inst, *pos, 2);

		uint16 srcLength = PLC_DEVICE_getDeviceWordValue(thirdOpnd);
		if(srcLength ==0xFFFF)
		{
			DBG_LOGPRINT("[Error BMOV] invalid 3rd operand is loaded!\n");
			return FALSE;
		}

			//in

		if(srcOpnd==NULL || dstOpnd == NULL)
		{
			DBG_LOGPRINT("[Error BMOV]Null operand is loaded!\n");
			return FALSE;
		}
		if(!PLC_DEVICE_copyDeviceBLK_new(dstOpnd,srcOpnd,srcLength, 4, BLOCK_COPY_TYPE_FMOV))
		{
			DBG_LOGPRINT("[Error BMOV] PLC_DEVICE_copyDeviceBLK_new returns Error!\n");
			return FALSE;
		}*/
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execCML(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);

			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, ~getFirstOperand, 1, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDCML(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);

			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, ~getFirstOperand, 1, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execCMLP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);

			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, ~getFirstOperand, 1, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDCMLP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);

			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, ~getFirstOperand, 1, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execXCH(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		uint16 getSecondOperand = preProcess_loadWord(inst, *pos, opt, 1);
			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(inProcess_saveToDev(inst, pos, opt, getSecondOperand, 0, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDXCH(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 getSecondOperand = preProcess_loadDoubleWord(inst, *pos, opt, 1);
			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(inProcess_saveToDev(inst, pos, opt, getSecondOperand, 0, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBXCH(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		//uint16 srcLength = 2*preProcess_load(inst, *pos, opt, 2);

		uint8* dstOpnd1 = inProcess_getIndexedOperand(inst, *pos, 1);
		uint8* dstOpnd2 = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8* lengthOpnd = inProcess_getIndexedOperand(inst, *pos, 2);
		uint8 t;
		uint16 length = PLC_DEVICE_getDeviceValue(lengthOpnd);
			//in
		int idx=0;
		if(dstOpnd1 ==NULL || dstOpnd2 ==NULL)
			return FALSE;

		for(idx=0 ; idx<length ; idx++)
		{
			long long tmp1, tmp2;
			if(!test_getValue(&tmp1, &t, dstOpnd1, idx))
				return FALSE;
			if(!test_getValue(&tmp2, &t, dstOpnd2, idx))
				return FALSE;
			if(!PLC_DEVICE_setDeviceValue(dstOpnd1, tmp2, idx))
				return FALSE;
			if(!PLC_DEVICE_setDeviceValue(dstOpnd2, tmp1, idx))
				return FALSE;
		}
	}


	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execXCHP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
		uint16 getSecondOperand = preProcess_loadWord(inst, *pos, opt, 1);
			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(inProcess_saveToDev(inst, pos, opt, getSecondOperand, 0, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDXCHP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint32 getFirstOperand = preProcess_loadDoubleWord(inst, *pos, opt, 0);
		uint32 getSecondOperand = preProcess_loadDoubleWord(inst, *pos, opt, 1);
			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;


		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 1, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
		if(inProcess_saveToDev(inst, pos, opt, getSecondOperand, 0, 4)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBXCHP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		//uint16 srcLength = 2*preProcess_load(inst, *pos, opt, 2);

		uint8* dstOpnd1 = inProcess_getIndexedOperand(inst, *pos, 1);
		uint8* dstOpnd2 = inProcess_getIndexedOperand(inst, *pos, 0);
		uint8* lengthOpnd = inProcess_getIndexedOperand(inst, *pos, 2);
		uint8 t;
		uint16 length = PLC_DEVICE_getDeviceValue(lengthOpnd);
			//in
		int idx=0;
		if(dstOpnd1 ==NULL || dstOpnd2 ==NULL)
			return FALSE;

		for(idx=0 ; idx<length ; idx++)
		{
			long long tmp1, tmp2;
			if(!test_getValue(&tmp1, &t, dstOpnd1, idx))
				return FALSE;
			if(!test_getValue(&tmp2, &t, dstOpnd2, idx))
				return FALSE;
			if(!PLC_DEVICE_setDeviceValue(dstOpnd1, tmp2, idx))
				return FALSE;
			if(!PLC_DEVICE_setDeviceValue(dstOpnd2, tmp1, idx))
				return FALSE;
		}
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSWAP(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		if(inProcess_swapByte(&getFirstOperand)==PLC_DEVICE_FALSE_32)
			return FALSE;

		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 0, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execSWAPP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint16 getFirstOperand = preProcess_loadWord(inst, *pos, opt, 0);
			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		if(inProcess_swapByte(&getFirstOperand)==PLC_DEVICE_FALSE_32)
			return FALSE;

		if(inProcess_saveToDev(inst, pos, opt, getFirstOperand, 0, 2)==PLC_DEVICE_FALSE_32)
			return FALSE;
	}
	//post

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execCJ(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;
	//DBG_LOGPRINT("\t CJ getCurrVal = %d\n", getCurrValue);
	if((getCurrValue&0x01) ==1){
		uint16 getFirstOperand = preProcess_load(inst, *pos, opt, 0);
			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
		{
			DBG_LOGPRINT("\t [ERROR in CJ] preProcess_load error!\n");
			return FALSE;
		}
		uint16 taskIdx = 0;
		uint32 point = 0;
		if(!PLC_PointTable_getPointByLabel((uint8*)&taskIdx, &point, getFirstOperand))
		{
			DBG_LOGPRINT("\t [ERROR in CJ] PLC_PointTable_getPointByLabel error!\n");
			PLC_PointTable_print();
			return FALSE;
		}
		//if(point==0)
		//	return FALSE;
		//PLC_PointTable_print();
#if PLC_LOG_DEF
		DBG_LOGPRINT("\t CJ pos %d->%d\n", *pos, point);
#endif
		*pos = point;
		return TRUE;
	}
	else{
		return postProcess_nop(inst, pos, opt);
	}
	//post

}
inline uint32 execSCJ(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint16 getFirstOperand = preProcess_load(inst, *pos, opt, 0);
			//in

		if(getFirstOperand==PLC_DEVICE_FALSE_32)
			return FALSE;

		uint16 taskIdx = 0;
		uint32 point = 0;
		if(!PLC_PointTable_getPointByLabel((uint8*)&taskIdx, &point, getFirstOperand))
		{
			PLC_PointTable_print();
			return FALSE;
		}
		//if(point==0)
		//	return FALSE;

		//printf("\tpoint : %d. getFirstOperand: %d\n", point, getFirstOperand);
		*pos = point;
		return TRUE;
	}
	//post
	else{
		return postProcess_nop(inst, pos, opt);
	}
}
inline uint32 execJMP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint16 getFirstOperand = preProcess_load(inst, *pos, opt, 0);
		//in

	if(getFirstOperand==PLC_DEVICE_FALSE_32)
		return FALSE;

	uint16 taskIdx = 0;
	uint32 point = 0;
	if(!PLC_PointTable_getPointByLabel((uint8*)&taskIdx, &point, getFirstOperand))
	{
		PLC_PointTable_print();
		return FALSE;
	}
	//if(point==0)
	//	return FALSE;

	//printf("\tpoint : %d. getFirstOperand: %d\n", point, getFirstOperand);
	*pos = point;
	return TRUE;
}
inline uint32 execGOEND(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(dev.forStack.count>0)
	{
		handleExecError(4200);
	}
	if(getCurrValue==PLC_DEVICE_FALSE_32)
	{
		DBG_LOGPRINT("GOEND ERROR!\n");
		return FALSE;
	}
	if((getCurrValue&0x01) ==1){

		/*while((*pos)<getMemSize()){
			//DBG_LOGPRINT( "MLCode = %s\n", opt->strName);
			(*pos) += OPERATOR_LENGTH+opt->nOperandPosCount*OPERAND_LENGTH;

			//uint16 instructionOperator = inst[*pos]*256+ inst[*pos+1];
			uint16 instructionOperator;
			memcpy(&instructionOperator,  &inst[*pos], sizeof(uint16));
			opt = (PLC_Operator*)PLC_OPERATOR_DICTIONARY_findOperator(instructionOperator);
			PLC_DEVICE_increaseStep();
			if(opt->nMLCode==ML_CODE_END||opt->nMLCode==ML_CODE_FEND )
			{
				return TRUE;
			}
		}*/
		uint32 ret = TaskList_getCurrTaskEnd(*pos);
		if(ret == PLC_DEVICE_FALSE_32)
		{
			//DBG_LOGPRINT("GOEND ERROR!\n");
			return FALSE;
		}
		{
			//DBG_LOGPRINT("GOEND :ENDPOS = %d!\n", ret);
			*pos = ret;
		}
	}
	else{

		return postProcess_nop(inst, pos, opt);
	}
	return TRUE;
}
inline uint32 execDI(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//PLC_InterruptionModule_setGlobalInterruption(0);
	PLC_EventHandler_disableInterruption();
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execEI(uint8 inst[], uint32* pos, PLC_Operator* opt){
	PLC_EventHandler_enableInterruption();
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execIMASK(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint16 getFirstOperand = preProcess_load(inst, *pos, opt, 0);

	uint8 type = inProcess_getOperandType(inst, pos, 0);
	uint8* value = inProcess_getOperandValue(inst, pos, 0);
	uint16* value16 = (uint16*)value;
	if( opndic[type].nBitSize != 16 || *value16 + 8 >= opndic[type].nAddressCount)
		return FALSE;

	uint16* gettableArray = preProcess_loadString(inst, *pos, opt, 0);

		//in
	if(getFirstOperand==PLC_DEVICE_FALSE_32 || getFirstOperand+8>=INTERRUPTION_SIZE)
		return FALSE;
	//int i;
	//for(i=0;i<8;i++)
	//{
		//uint8 currEnableValue = (getFirstOperand>>i )& 0x01;
	PLC_EventHandler_imask(gettableArray);
		//PLC_InterruptionModule_setInterruption(getFirstOperand+i, currEnableValue);
	//}
	//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execIRET(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//uint16 point = PLC_InterruptionModule_pullInterruptionPoint();
	//*pos = point;
	//uint8 taskidx = 0xFF;
	//uint16 taskPos = 0xFFFF;
	//if(!PLC_EventHandler_callbackPosition(&taskidx, &taskPos))
	//	return FALSE;

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execRFS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if((getCurrValue&0x01) ==1){
		uint8* getFirstOperand = preProcess_loadString(inst, *pos, opt, 0);
		uint8* getOperand = inProcess_getIndexedOperand(inst, *pos, 0);
		uint32 getSecondValue = preProcess_load(inst, *pos, opt, 1);
		int i;
		if(getSecondValue ==PLC_DEVICE_FALSE_32 || getFirstOperand==NULL )
			return FALSE;
		for(i=0; i<getSecondValue;i++)
		{
			uint16 getOperandValue;
			memcpy(&getOperandValue, &getOperand[1], sizeof(uint16));
			if(getOperandValue+i>=PLC_OPERAND_DICTIONARY_findOperandByName("X")->nAddressCount)
				return FALSE;
			if(getOperand[0] == PLC_OPERAND_DICTIONARY_findOperandByName("X")->nAddressCount)
				for(i=0;i<getSecondValue;i++)
				{
					uint8* getFirstOperand = preProcess_loadString(inst, *pos, opt, 0);
					uint8 val=PLC_DEVICE_loadToIn(getOperandValue+i);
					if(val==FALSE)
						return FALSE;
					*getFirstOperand = val;
				}
			else if(getOperand[0] == PLC_OPERAND_DICTIONARY_findOperandByName("Y")->nAddressCount)
				for(i=0;i<getSecondValue;i++)
				{

					if(PLC_DEVICE_loadToOut(*getFirstOperand, getOperandValue)+i==FALSE)
						return FALSE;
				}

			else return FALSE;
		}
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execRFSP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint8* getFirstOperand = preProcess_loadString(inst, *pos, opt, 0);
		uint8* getOperand = inProcess_getIndexedOperand(inst, *pos, 0);
		uint32 getSecondValue = preProcess_load(inst, *pos, opt, 1);
		int i;
		if(getSecondValue ==PLC_DEVICE_FALSE_32 || getFirstOperand==NULL )
			return FALSE;
		for(i=0; i<getSecondValue;i++)
		{
			uint16 getOperandValue;
			memcpy(&getOperandValue, &getOperand[1], sizeof(uint16));
			if(getOperandValue+i>=PLC_OPERAND_DICTIONARY_findOperandByName("X")->nAddressCount)
				return FALSE;

			if(getOperand[0] == PLC_OPERAND_DICTIONARY_findOperandByName("X")->nMLCode)
				for(i=0;i<getSecondValue;i++)
				{
					uint8* getFirstOperand = preProcess_loadString(inst, *pos, opt, 0);
					uint8 val=PLC_DEVICE_loadToIn(getOperandValue+i);
					if(val==FALSE)
						return FALSE;
					*getFirstOperand = val;
				}
			else if(getOperand[0] == PLC_OPERAND_DICTIONARY_findOperandByName("Y")->nMLCode)
				for(i=0;i<getSecondValue;i++)
				{

					if(PLC_DEVICE_loadToOut(*getFirstOperand, getOperandValue)+i==FALSE)
						return FALSE;
				}

			else return FALSE;
		}
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execCNT(uint8 inst[], uint32* pos, PLC_Operator* opt){

	//uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;
	//printf("__LINE__ : %d\n",__LINE__);
	if(getCurrValue){
		uint8 src = preProcess_load(inst, *pos, opt, 0);
		uint16 countValue = preProcess_load(inst, *pos, opt, 2);
		uint16* dstPos = (uint16*)preProcess_loadString(inst, *pos, opt, 1);
		uint8* dstOperand = inProcess_getIndexedOperand(inst, *pos, 1);
		uint16 dstIdx;
		memcpy(&dstIdx, &dstOperand[1], sizeof(uint16));
			//in

		if(dstPos == NULL)
		{
			//printf("__LINE__ : %d\n",__LINE__);
			return FALSE;
		}

		if(!src){
			//count-up

			(*dstPos)--;
			if(*dstPos == countValue)
				PLC_DEVICE_setCountValue(dstIdx,1);
		}else{
			//printf("__LINE__ : %d\n",__LINE__);
			//count-down
			(*dstPos)++;
			if(*dstPos == countValue)
				PLC_DEVICE_setCountValue(dstIdx,0);

		}
	}
	//post

	uint32 ret = postProcess_nop(inst, pos, opt);
	//printf("ret : %d\n",ret);
	//printf("__LINE__ : %d, ret: %d\n", __LINE__, ret);
	return ret;
}
inline uint32 execCNTP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;
	//printf("__LINE__ : %d\n",__LINE__);
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint8 src = preProcess_load(inst, *pos, opt, 0);
		uint16 countValue = preProcess_load(inst, *pos, opt, 2);
		uint16* dstPos = (uint16*)preProcess_loadString(inst, *pos, opt, 1);
		uint8* dstOperand = inProcess_getIndexedOperand(inst, *pos, 1);
		uint16 dstIdx;
		memcpy(&dstIdx, &dstOperand[1], sizeof(uint16));
			//in

		if(dstPos == NULL)
		{
			//printf("__LINE__ : %d\n",__LINE__);
			return FALSE;
		}

		if(!src){
			//count-up

			(*dstPos)--;
			if(*dstPos == countValue)
				PLC_DEVICE_setCountValue(dstIdx,1);
		}else{
			//printf("__LINE__ : %d\n",__LINE__);
			//count-down
			(*dstPos)++;
			if(*dstPos == countValue)
				PLC_DEVICE_setCountValue(dstIdx,0);

		}
	}
	//post

	uint32 ret = postProcess_nop(inst, pos, opt);
	//printf("ret : %d\n",ret);
	return ret;
}
inline uint32 execTTMR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//implementing...
	/*uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);
	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;
	//printf("__LINE__ : %d\n",__LINE__);
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
		uint8 src = preProcess_load(inst, *pos, opt, 0);
		uint16 countValue = preProcess_load(inst, *pos, opt, 2);
		uint16* dstPos = (uint16*)preProcess_loadString(inst, *pos, opt, 1);
		uint8* dstOperand = inProcess_getIndexedOperand(inst, *pos, 1);
		uint16 dstIdx;
		memcpy(&dstIdx, &dstOperand[1], sizeof(uint16));
			//in

		if(dstPos == NULL)
		{
			printf("__LINE__ : %d\n",__LINE__);
			return FALSE;
		}

		if(!src){
			//count-up

			(*dstPos)--;
			if(*dstPos == countValue)
				PLC_DEVICE_setCountValue(dstIdx,1);
		}else{
			//printf("__LINE__ : %d\n",__LINE__);
			//count-down
			(*dstPos)++;
			if(*dstPos == countValue)
				PLC_DEVICE_setCountValue(dstIdx,0);

		}
	}
	else if(inProcess_detectRaisingEdge(getCurrValue, getFastValue)){
			uint8 src = preProcess_load(inst, *pos, opt, 0);
			uint16 countValue = preProcess_load(inst, *pos, opt, 2);
			uint16* dstPos = (uint16*)preProcess_loadString(inst, *pos, opt, 1);
			uint8* dstOperand = inProcess_getIndexedOperand(inst, *pos, 1);
		uint16 dstIdx;
		memcpy(&dstIdx, &dstOperand[1], sizeof(uint16));
				//in

			if(dstPos == NULL)
			{
				printf("__LINE__ : %d\n",__LINE__);
				return FALSE;
			}

			if(!src){
				//count-up

				(*dstPos)--;
				if(*dstPos == countValue)
					PLC_DEVICE_setCountValue(dstIdx,1);
			}else{
				//printf("__LINE__ : %d\n",__LINE__);
				//count-down
				(*dstPos)++;
				if(*dstPos == countValue)
					PLC_DEVICE_setCountValue(dstIdx,0);

			}
		}
	//post

	uint32 ret = postProcess_nop(inst, pos, opt);
	//printf("ret : %d\n",ret);
	//printf("__LINE__ : %d, ret: %d\n", __LINE__, ret);
	return ret;*/
	return FALSE;
}
inline uint32 execSTMR(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execROTC(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execRAMP(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execSPD(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execPLSY(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execPWM(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}
inline uint32 execMTR(uint8 inst[], uint32* pos, PLC_Operator* opt){return FALSE;}

//fast implement
inline uint32 execOUT_T(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//load

	/*uint8 opnd1 = inst[*pos+2]&0x0FF;
	long tarVal = preProcess_load(inst, *pos, opt, 1);
	uint16 addr1;
	memcpy(&addr1, &inst[*pos+3], sizeof(uint16));
*/
	uint8* operandTime = inProcess_getIndexedOperand(inst, *pos, 0);
	uint8* operandTarget = inProcess_getIndexedOperand(inst, *pos, 1);
	uint16 addr1 = *(uint16*)&operandTime[1];
	long long tarVal = 0;
	uint8 bitSize = 0;
	if(!test_getValue(&tarVal, &bitSize, operandTarget, 0))
	{
		return FALSE;
	}
	if(operandTime[0] !=OPERAND_ML_CODE_T)
	{
		return FALSE;
	}

	inProcess_outT(getCurrBitValue(*pos), addr1, tarVal, TIMER_MODE_NORMAL);
/*
	uint8* getCurrBit = getCurrBitValue(*pos);
	uint8* opnd1 = inProcess_getIndexedOperand(inst, *pos, 0);
	uint8* opnd2 = inProcess_getIndexedOperand(inst, *pos, 0);
	uint16 cValue = PLC_DEVICE_getDeviceValue(opnd1);
	uint16 tarValue = PLC_DEVICE_getDeviceValue(opnd2);
	inProcess_outT(*getCurrBit, );
*/
	return postProcess_nop(inst, pos, opt);

}
inline uint32 execOUT_TP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint8 opnd1 = inst[*pos+2]&0x0FF;
	uint32 tarVal = preProcess_load(inst, *pos, opt, 1);
	uint16 addr1;
	memcpy(&addr1, &inst[*pos+3], sizeof(uint16));


	if(opnd1 !=OPERAND_ML_CODE_T)
	{
		return FALSE;
	}

	inProcess_outT(getCurrBitValue(*pos), addr1, tarVal, TIMER_MODE_NORMAL);

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execOUTH_T(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint8 opnd1 = inst[*pos+2]&0x0FF;
	uint16 addr1;
	memcpy(&addr1, &inst[*pos+3], sizeof(uint16));
	uint32 tarVal = preProcess_load(inst, *pos, opt, 1);

	if(opnd1 !=OPERAND_ML_CODE_T)
	{
		return FALSE;
	}

	inProcess_outT(getCurrBitValue(*pos), addr1, tarVal, TIMER_MODE_HIGH);

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execOUTH_TP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint8 opnd1 = inst[*pos+2]&0x0FF;
	uint16 addr1;
	memcpy(&addr1, &inst[*pos+3], sizeof(uint16));
	uint32 tarVal = preProcess_load(inst, *pos, opt, 1);
	//printf("tarVal: %d\n", tarVal );
	if(opnd1 !=OPERAND_ML_CODE_T)
	{

		return FALSE;
	}

	inProcess_outT(getCurrBitValue(*pos), addr1, tarVal, TIMER_MODE_HIGH);

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execOUT_ST(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint8 opnd1 = inst[*pos+2]&0x0FF;
	uint16 addr1;
	memcpy(&addr1, &inst[*pos+3], sizeof(uint16));
	uint32 tarVal = preProcess_load(inst, *pos, opt, 1);
	//printf("tarVal: %d\n", tarVal );
	if(opnd1 !=OPERAND_ML_CODE_T)
	{

		return FALSE;
	}

	inProcess_outT(getCurrBitValue(*pos), addr1, tarVal, TIMER_MODE_STORE);

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execOUT_STP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint8 opnd1 = inst[*pos+2]&0x0FF;
	uint16 addr1;
	memcpy(&addr1, &inst[*pos+3], sizeof(uint16));
	uint32 tarVal = preProcess_load(inst, *pos, opt, 1);
	//printf("tarVal: %d\n", tarVal );
	if(opnd1 !=OPERAND_ML_CODE_T)
	{

		return FALSE;
	}

	inProcess_outT(getCurrBitValue(*pos), addr1, tarVal, TIMER_MODE_STORE);

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execOUTH_ST(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint8 opnd1 = inst[*pos+2]&0x0FF;
	uint16 addr1;
	memcpy(&addr1, &inst[*pos+3], sizeof(uint16));
	uint32 tarVal = preProcess_load(inst, *pos, opt, 1);
	//printf("tarVal: %d\n", tarVal );
	if(opnd1 !=OPERAND_ML_CODE_T)
	{

		return FALSE;
	}

	inProcess_outT(getCurrBitValue(*pos), addr1, tarVal, TIMER_MODE_HIGH_STORE);

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execOUTH_STP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint8 opnd1 = inst[*pos+2]&0x0FF;
	uint16 addr1;
	memcpy(&addr1, &inst[*pos+3], sizeof(uint16));
	uint32 tarVal = preProcess_load(inst, *pos, opt, 1);
	//printf("tarVal: %d\n", tarVal );
	if(opnd1 !=OPERAND_ML_CODE_T)
	{

		return FALSE;
	}

	inProcess_outT(getCurrBitValue(*pos), addr1, tarVal, TIMER_MODE_HIGH_STORE);

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execOUT_C(uint8 inst[], uint32* pos, PLC_Operator* opt){
	//uint8 opnd1 = inst[*pos+2]&0x0FF;
	uint8 fastValue = preProcess_pick(*pos);
	uint8 currValue = getCurrBitValue(*pos);

	uint8* opnd1 = inProcess_getIndexedOperand(inst, *pos, 0);
	uint8* opnd2 = inProcess_getIndexedOperand(inst, *pos, 1);
	if(opnd1[0]!=OPERAND_ML_CODE_C)
	{
		DBG_LOGPRINT("[ERROR] Count is not actevated in count device[%s]!\n", opndic[opnd1[0]].strType);
		return FALSE;
	}
	uint16 addr1;
	memcpy(&addr1, &opnd1[1], sizeof(uint16));


	uint32 tarVal = PLC_DEVICE_getDeviceValue(opnd2);
	//DBG_LOGPRINT("[OUT_C] input : r-edge = %d, countIdx = %d, tarVal = %d\n", inProcess_detectRaisingEdge(currValue, fastValue), addr1, tarVal );

	inProcess_outC(inProcess_detectRaisingEdge(currValue, fastValue), addr1, tarVal);

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execOUT_CP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	uint8 opnd1 = inst[*pos+2]&0x0FF;
	uint16 addr1;
	memcpy(&addr1, &inst[*pos+3], sizeof(uint16));
	uint32 tarVal = preProcess_load(inst, *pos, opt, 1);


	if(opnd1 !=OPERAND_ML_CODE_C)
	{
		return FALSE;
	}
	inProcess_outC(getCurrBitValue(*pos), addr1, tarVal);

	return postProcess_nop(inst, pos, opt);
}
inline uint32 execOUT_F(uint8 inst[], uint32* pos, PLC_Operator* opt){

	return execOUT(inst, pos, opt);
}
inline uint32 execOUT_FP(uint8 inst[], uint32* pos, PLC_Operator* opt){

	uint16 fastVal = preProcess_pick(*pos);
	uint16 currVal = getCurrBitValue(*pos);
	if(inProcess_detectRaisingEdge(currVal, fastVal))
		execOUT(inst, pos, opt);
		//save
	return postProcess_out(inst, pos, opt, currVal);
}

inline uint32 execPOINT(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	//uint8* currOperand = inProcess_getIndexedOperand(inst, *pos, 0);
	long long val = 0;
	uint8 size = 0;
	if(!(test_getValue(&val, &size, inst, 0)))
		return FALSE;
	(*pos) += (uint16)val;
	return TRUE;
}
inline uint32 execWAND(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	/**pos+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);
	uint16 dst, src;

	src = PLC_DEVICE_getDeviceWordValue(opnd1);
	if(src == PLC_DEVICE_FALSE_32)
		return FALSE;

	dst = PLC_DEVICE_getDeviceWordValue(opnd2);
	if(dst == PLC_DEVICE_FALSE_32)
		return FALSE;
	dst &= src;
	PLC_DEVICE_setDeviceValue(opnd2, dst, 0);
	return PLC_DEVICE_increaseStep(TRUE);
	*/
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicAnd, FALSE, FALSE);
}
inline uint32 execWOR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicOr, FALSE, FALSE);
}
inline uint32 execWXOR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicXor, FALSE, FALSE);
}
inline uint32 execWXNR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicXnr, FALSE, FALSE);
}
inline uint32 execDAND(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicAnd, FALSE, TRUE);
}
inline uint32 execDOR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicOr, FALSE, TRUE);
}
inline uint32 execDXOR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicXor, FALSE, TRUE);
}
inline uint32 execDXNR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicXnr, FALSE, TRUE);
}
inline uint32 execBKAND(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_blockLogics(inst, pos, FALSE, inProcess_logicAnd);
}
inline uint32 execBKOR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_blockLogics(inst, pos, FALSE, inProcess_logicOr);
}
inline uint32 execBKXOR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_blockLogics(inst, pos, FALSE, inProcess_logicXor);
}
inline uint32 execBKXNR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_blockLogics(inst, pos, FALSE, inProcess_logicXnr);
}
inline uint32 execWANDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicAnd, FALSE, FALSE);
}
inline uint32 execWORP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicOr, FALSE, FALSE);
}
inline uint32 execWXORP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicXor, FALSE, FALSE);
}
inline uint32 execWXNRP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicXnr, FALSE, FALSE);
}
inline uint32 execDANDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicAnd, FALSE, TRUE);
}
inline uint32 execDORP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicOr, FALSE, TRUE);
}
inline uint32 execDXORP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicXor, FALSE, TRUE);
}
inline uint32 execDXNRP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicXnr, FALSE, TRUE);
}
inline uint32 execBKANDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_blockLogics(inst, pos, TRUE, inProcess_logicAnd);
}
inline uint32 execBKORP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_blockLogics(inst, pos, TRUE, inProcess_logicOr);
}
inline uint32 execBKXORP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_blockLogics(inst, pos, TRUE, inProcess_logicXor);
}
inline uint32 execBKXNRP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_blockLogics(inst, pos, TRUE, inProcess_logicXnr);
}
inline uint32 execWANDS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicAnd, TRUE, FALSE);
}
inline uint32 execWORS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicOr, TRUE, FALSE);
}
inline uint32 execWXORS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicXor, TRUE, FALSE);
}
inline uint32 execWXNRS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicXnr, TRUE, FALSE);
}
inline uint32 execDANDS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicAnd, TRUE, TRUE);
}
inline uint32 execDORS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicOr, TRUE, TRUE);
}
inline uint32 execDXORS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicXor, TRUE, TRUE);
}
inline uint32 execDXNRS(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, FALSE, inProcess_logicXnr, TRUE, TRUE);
}
inline uint32 execWANDSP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicAnd, TRUE, FALSE);
}
inline uint32 execWORSP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicOr, TRUE, FALSE);
}
inline uint32 execWXORSP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicXor, TRUE, FALSE);
}
inline uint32 execWXNRSP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicXnr, TRUE, FALSE);
}
inline uint32 execDANDSP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicAnd, TRUE, TRUE);
}
inline uint32 execDORSP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicOr, TRUE, TRUE);
}
inline uint32 execDXORSP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicXor, TRUE, TRUE);
}
inline uint32 execDXNRSP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_wordLogics(inst, pos, TRUE, inProcess_logicXnr, TRUE, TRUE);
}
inline uint32 execROR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, TRUE, FALSE, FALSE, TRUE);
}
inline uint32 execRCR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, TRUE, TRUE, FALSE, TRUE);
}
inline uint32 execROL(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, TRUE, FALSE, FALSE, FALSE);
}
inline uint32 execRCL(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, TRUE, TRUE, FALSE, FALSE);
}
inline uint32 execDROR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, FALSE, FALSE, FALSE, TRUE);
}
inline uint32 execDRCR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, FALSE, TRUE, FALSE, TRUE);
}
inline uint32 execDROL(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, FALSE, FALSE, FALSE, FALSE);
}
inline uint32 execDRCL(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, FALSE, TRUE, FALSE, FALSE);
}
inline uint32 execRORP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, TRUE, FALSE, TRUE, TRUE);
}
inline uint32 execRCRP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, TRUE, TRUE, TRUE, TRUE);
}
inline uint32 execROLP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, TRUE, FALSE, TRUE, FALSE);
}
inline uint32 execRCLP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, TRUE, TRUE, TRUE, FALSE);
}
inline uint32 execDRORP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, FALSE, FALSE, TRUE, TRUE);
}
inline uint32 execDRCRP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, FALSE, TRUE, TRUE, TRUE);
}
inline uint32 execDROLP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, FALSE, FALSE, TRUE, FALSE);
}
inline uint32 execDRCLP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_rotationBitInTargetWord(inst, pos, FALSE, TRUE, TRUE, FALSE);
}
inline uint32 execSFR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSFL(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSFR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSFL(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execWSFR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execWSFL(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSFRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSFLP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSFRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSFLP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execWSFRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execWSFLP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSET(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBRST(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSETP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBRSTP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execTEST(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execTESTP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDTEST(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDTESTP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBKRST(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBKRSTP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSRCH(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_searchAndCount(inst, pos, FALSE, FALSE);
}
inline uint32 execDSRCH(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_searchAndCount(inst, pos, FALSE, TRUE);
}
inline uint32 execSRCHP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_searchAndCount(inst, pos, TRUE, FALSE);
}
inline uint32 execDSRCHP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_searchAndCount(inst, pos, TRUE, TRUE);
}
inline uint32 execCHKSUM(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_sumBit(inst, pos, FALSE, FALSE);
}
inline uint32 execDCHKSUM(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_sumBit(inst, pos, FALSE, TRUE);
}
inline uint32 execCHKSUMP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_sumBit(inst, pos, TRUE, FALSE);
}
inline uint32 execDCHKSUMP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_sumBit(inst, pos, TRUE, TRUE);
}
inline uint32 execENCODE(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDECODE(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execENCODEP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDECODEP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSEG(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSEGP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDIS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDISP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execUNI(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execUNIP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execNDIS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execNDISP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execNUNI(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execNUNIP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execWTOB(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBTOW(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execWTOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBTOWP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execMAX(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	return inProcess_searchMaxMinCount(inst, pos, FALSE, FALSE, TRUE);
}
inline uint32 execMAXP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_searchMaxMinCount(inst, pos, TRUE, FALSE, TRUE);
}
inline uint32 execMIN(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_searchMaxMinCount(inst, pos, FALSE, FALSE, FALSE);
}
inline uint32 execMINP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_searchMaxMinCount(inst, pos, TRUE, FALSE, FALSE);
}
inline uint32 execSORT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_sort(inst, pos, FALSE, FALSE);
}
inline uint32 execDSORT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_sort(inst, pos, FALSE, TRUE);
}
inline uint32 execWSUM(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDWSUM(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execWSUMP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDWSUMP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFOR(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	return inProcess_visitFor(inst, pos);
}
inline uint32 execNEXT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_visitNext(inst, pos);
}
inline uint32 execBREAK(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_visitBreak(inst, pos, FALSE);
}
inline uint32 execBREAKP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_visitBreak(inst, pos, TRUE);
}
inline uint32 execCALL(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	return inProcess_call(inst, pos, FALSE);
}
inline uint32 execCALLP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_call(inst, pos, TRUE);
}
inline uint32 execCALLS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execCALLSP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execRET(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return execEND(inst, pos, opt);
}
inline uint32 execFCALL(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFCALLP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFCALLS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFCALLSP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execXCALL(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execCOM(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execIX(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execIXEND(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execIXDEV(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execIXSET(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFIFW(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFIFWP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFIFR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFIFRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFPOP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFPOPP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFPDEL(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFPDELP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFINS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFINSP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFROM(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(getCurrValue)
	{
		if(!inProcess_from(inst, *pos, opt, 2))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execFROMP(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;
	if(getFastValue == PLC_DEVICE_FALSE_32)
		return FALSE;
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue))
	{
		if(!inProcess_from(inst, *pos, opt, 2))
			return FALSE;
	}
	//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDFROM(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(getCurrValue)
	{
		if(!inProcess_from(inst, *pos, opt, 4))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDFROMP(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;
	if(getFastValue == PLC_DEVICE_FALSE_32)
		return FALSE;
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue))
	{
		if(!inProcess_from(inst, *pos, opt, 4))
			return FALSE;
	}
	//post
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execTO(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(getCurrValue)
	{
		if(!inProcess_to(inst, *pos, opt, 2))
		{
			//PLC_Register_set(OPERAND_ML_CODE_SMERR_IO_MODULE_COMM);
			return FALSE;
		}
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execTOP(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;
	if(getFastValue == PLC_DEVICE_FALSE_32)
		return FALSE;
	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue))
	{
		if(!inProcess_to(inst, *pos, opt, 2))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTO(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;

	if(getCurrValue)
	{
		if(!inProcess_to(inst, *pos, opt, 4))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execDTOP(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	uint32 getFastValue = preProcess_pick(*pos);
	uint32 getCurrValue = getCurrBitValue(*pos);

	if(getCurrValue==PLC_DEVICE_FALSE_32)
		return FALSE;
	if(getFastValue == PLC_DEVICE_FALSE_32)
		return FALSE;

	if(inProcess_detectRaisingEdge(getCurrValue, getFastValue))
	{
		if(!inProcess_to(inst, *pos, opt, 4))
			return FALSE;
	}
	return postProcess_nop(inst, pos, opt);
}
inline uint32 execBTODA(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, FALSE, TRUE, FALSE, FALSE);
}
inline uint32 execBTOHA(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, FALSE, FALSE, FALSE, FALSE);
}
inline uint32 execDTODA(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, FALSE, TRUE, TRUE, FALSE);
}
inline uint32 execDTOHA(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, FALSE, FALSE, TRUE, FALSE);
}
inline uint32 execBCDTODA(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, FALSE, TRUE, FALSE, TRUE);
}
inline uint32 execBCDTOHA(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, FALSE, FALSE, FALSE, TRUE);
}
inline uint32 execDBCDTODA(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, FALSE, TRUE, TRUE, TRUE);
}
inline uint32 execDBCDTOHA(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, FALSE, FALSE, TRUE, TRUE);
}
inline uint32 execDATOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, FALSE, TRUE, FALSE, FALSE);
}
inline uint32 execDATOD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, FALSE, TRUE, TRUE, FALSE);
}
inline uint32 execDATOBCD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, FALSE, TRUE, FALSE, TRUE);
}
inline uint32 execDATODBCD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, FALSE, TRUE, TRUE, TRUE);
}
inline uint32 execHATOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, FALSE, FALSE, FALSE, FALSE);
}
inline uint32 execHATOD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, FALSE, FALSE, TRUE, FALSE);
}
inline uint32 execBTODAP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, TRUE, TRUE, FALSE, FALSE);
}
inline uint32 execBTOHAP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, TRUE, FALSE, FALSE, FALSE);
}
inline uint32 execDTODAP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, TRUE, TRUE, TRUE, FALSE);
}
inline uint32 execDTOHAP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, TRUE, FALSE, TRUE, FALSE);
}
inline uint32 execBCDTODAP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, TRUE, TRUE, FALSE, TRUE);
}
inline uint32 execBCDTOHAP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, TRUE, FALSE, FALSE, TRUE);
}
inline uint32 execDBCDTODAP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, TRUE, TRUE, TRUE, TRUE);
}
inline uint32 execDBCDTOHAP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_BINToASCII(inst, pos, TRUE, FALSE, TRUE, TRUE);
}
inline uint32 execDATOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, TRUE, TRUE, FALSE, FALSE);
}
inline uint32 execDATODP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, TRUE, TRUE, TRUE, FALSE);
}
inline uint32 execDATOBCDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, TRUE, TRUE, FALSE, TRUE);
}
inline uint32 execDATODBCDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, TRUE, TRUE, TRUE, TRUE);
}
inline uint32 execHATOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, TRUE, FALSE, FALSE, FALSE);
}
inline uint32 execHATODP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIToBIN(inst, pos, TRUE, FALSE, TRUE, FALSE);
}
inline uint32 execCOMRD(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execCOMRDP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execLEN(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);

	if(getCurrBitValue(*pos))
	{
		char* str = (char*)PLC_DEVICE_getDeviceString(opnd1);
		if(!PLC_DEVICE_isDeviceAddrRange(inst, strlen((char*)str)+1))
		{
			return PLC_DEVICE_increaseStep(FALSE);
		}
		if(!PLC_DEVICE_setDeviceValue(opnd2, strlen(str), 0))
		{
			return PLC_DEVICE_increaseStep(FALSE);
		}
		//DBG_LOGPRINT("%d<==len(%s)\n", (int)strlen(str),str);
	}
	return PLC_DEVICE_increaseStep(TRUE);
}
inline uint32 execLENP(uint8 inst[], uint32* pos, PLC_Operator* opt){

	(*pos)+= OPERATOR_LENGTH;
	uint8* opnd1 = inProcess_getNextIndexedOperand(inst, pos);
	uint8* opnd2 = inProcess_getNextIndexedOperand(inst, pos);

	uint8 past = preProcess_pick(*pos);
	uint8 curr = getCurrBitValue(*pos);

	if(inProcess_detectRaisingEdge(curr, past))
	{
		char* str = (char*)PLC_DEVICE_getDeviceString(opnd1);
		if(!PLC_DEVICE_isDeviceAddrRange(inst, strlen(str)+1))
		{
			return PLC_DEVICE_increaseStep(FALSE);
		}
		if(!PLC_DEVICE_setDeviceValue(opnd2, strlen(str), 0))
		{
			return PLC_DEVICE_increaseStep(FALSE);
		}
		//DBG_LOGPRINT("%d<==len(%s)\n", (int)strlen(str),str);
	}
	return PLC_DEVICE_increaseStep(TRUE);
}
inline uint32 execBTOSTR(uint8 inst[], uint32* pos, PLC_Operator* opt)
{
	return inProcess_intIntToStr(inst, pos, FALSE, FALSE);
}
inline uint32 execBTOSTRP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_intIntToStr(inst, pos, TRUE, FALSE);
}
inline uint32 execDTOSTR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_intIntToStr(inst, pos, FALSE, TRUE);
}
inline uint32 execDTOSTRP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_intIntToStr(inst, pos, TRUE, TRUE);
}
inline uint32 execSTRTOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_strToIntInt(inst, pos, FALSE, FALSE);
}
inline uint32 execSTRTOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_strToIntInt(inst, pos, TRUE, FALSE);
}
inline uint32 execSTRTOD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_strToIntInt(inst, pos, FALSE, TRUE);
}
inline uint32 execSTRTODP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_strToIntInt(inst, pos, TRUE, TRUE);
}
inline uint32 execFTOSTR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFTOSTRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSTRTOF(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSTRTOFP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBTOASC(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_intToASCIIArr(inst, pos, FALSE);
}
inline uint32 execBTOASCP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_intToASCIIArr(inst, pos, TRUE);
}
inline uint32 execASCTOB(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIArrToInt(inst, pos, FALSE);
}
inline uint32 execASCTOBP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_ASCIIArrToInt(inst, pos, TRUE);
}
inline uint32 execRIGHT(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execLEFT(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execMIDR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execMIDW(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execINSTR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSTRINS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSTRDEL(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execRIGHTP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execLEFTP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execMIDRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execMIDWP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execINSTRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSTRINSP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSTRDELP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFTOBCD(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execFTOBCDP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBCDTOF(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBCDTOFP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSIN(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execCOS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execTAN(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execASIN(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execACOS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execATAN(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSINP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execCOSP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execTANP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execASINP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execACOSP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execATANP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execRAD(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execRADP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSQR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSQRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execEXP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execEXPP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execLOG(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execLOGP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execPOW(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execPOWP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execLOG10(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execLOG10P(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execRANDOM(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execRANDOMP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSRANDOM(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execSRANDOMP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSQR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDSQR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSQRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDSQRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSIN(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBCOS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBTAN(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBASIN(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBACOS(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBATAN(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBSINP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBCOSP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBTANP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBASINP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBACOSP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execBATANP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execLIMIT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_limit(inst, pos, FALSE, FALSE);
}
inline uint32 execDLIMIT(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_limit(inst, pos, FALSE, TRUE);
}
inline uint32 execLIMITP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_limit(inst, pos, TRUE, FALSE);
}
inline uint32 execDLIMITP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_limit(inst, pos, TRUE, TRUE);
}
inline uint32 execBAND(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_band(inst, pos, FALSE, FALSE);
}
inline uint32 execBANDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_band(inst, pos, TRUE, FALSE);
}
inline uint32 execDBAND(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_band(inst, pos, FALSE, TRUE);
}
inline uint32 execDBANDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_band(inst, pos, TRUE, TRUE);
}
inline uint32 execZONE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_zone(inst, pos, FALSE, FALSE);
}
inline uint32 execZONEP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_zone(inst, pos, TRUE, FALSE);
}
inline uint32 execDZONE(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_zone(inst, pos, FALSE, TRUE);
}
inline uint32 execDZONEP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_zone(inst, pos, TRUE, TRUE);
}
inline uint32 execRSET(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execRSETP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDATERD(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_daterd(inst, pos, FALSE);
}
inline uint32 execDATERDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_daterd(inst, pos, TRUE);
}
inline uint32 execDATEWR(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDATEWRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDATEADD(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDATEADDP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDATESUB(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDATESUBP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}

inline uint32 execSECOND(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_toSecond(inst, pos, FALSE);
}
inline uint32 execSECONDP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_toSecond(inst, pos, TRUE);
}
inline uint32 execHOUR(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_toHour(inst, pos, FALSE);
}
inline uint32 execHOURP(uint8 inst[], uint32* pos, PLC_Operator* opt){
	return inProcess_toHour(inst, pos, TRUE);
}
inline uint32 execWDT(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execWDTP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execDUTY(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execTIMCHK(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execZRRDB(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execZRRDBP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execZRWRP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execZRWRBP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execADRSET(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execADRSETP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execZPUSH(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execZPUSHP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execZPOP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execZPOPP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execUNIRD(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}
inline uint32 execUNIRDP(uint8 inst[], uint32* pos, PLC_Operator* opt){return 0;}

