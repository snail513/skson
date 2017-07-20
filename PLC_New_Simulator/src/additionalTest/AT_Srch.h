/*
 * AT_Srch.h
 *
 *  Created on: 2016. 5. 9.
 *      Author: skson
 */

#ifndef AT_SRCH_H_
#define AT_SRCH_H_

#include "../PLC_ListOfTestSuite.h"
#include "AddTest.h"

uint8 ATest_Srch();
uint8 ATest_Sum();
uint8 ATest_Max();
uint8 ATest_Min();
uint8 ATest_Sort();
//uint8 ATest_Mean();

uint8 ATest_Limit();
uint8 ATest_Band();
uint8 ATest_Zone();

uint8 ATest_Daterd();
uint8 ATest_Second();
uint8 ATest_Hour();
uint8 ATest_DAToB();
uint8 ATest_HAToB();
uint8 ATest_BToDA();
uint8 ATest_BToHA();
uint8 ATest_Len();
uint8 ATest_Rotation();
uint8 ATest_BtoStr();
uint8 ATest_StrToB();
uint8 ATest_BToAsc();
uint8 ATest_AscToB();
#endif /* AT_SRCH_H_ */
