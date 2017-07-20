/*
 * AT_Srch.c
 *
 *  Created on: 2016. 5. 9.
 *      Author: skson
 */

#ifndef AT_SRCH_H_
#include "AT_Srch.h"
#include "CUnit/CUnit.h"
#endif

static void* carrySet[] = {
		ATest_setCarryOff,
		ATest_setCarryOn,
};

uint8 ATest_Srch()
{
	uint16 searchCnt = 8;
	uint16 searchSrc1 = 3523;
	uint16 searchDst[] = {0, 0};
	uint16 searchSrc2[] = {10, 100, 230, 345,1455, 131, 3523, 3523};
	uint16 expected[] = {6, 2};
	uint16 expectedSize = 2;

	uint16* SRCH_Input[] = {&searchSrc1,searchSrc2,&searchDst,&searchCnt,NULL};
	uint16 SRCH_Input_size[] = {1,searchCnt,expectedSize,1,0};

	TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarConst};
	VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeK,};
	VType vBit[] = {VTypeBitDev, VTypeWordDev, VTypeWordDev, VTypeK,};
	IOType io[] = {IOTypeSRC, IOTypeSRC, IOTypeDST, IOTypeCNT};
	AT_setNibbleInclude(FALSE);

	int isOn;

	for(isOn=0; isOn<2; isOn++)
	{
		AT_testGeneralUnitTest(ML_CODE_SRCH, isOn, FALSE, tv, vWord, io, "SRCH WORD test", SRCH_Input, SRCH_Input_size, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_SRCHP, isOn, TRUE, tv, vWord, io, "SRCHP WORD test", SRCH_Input, SRCH_Input_size, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_SRCH, isOn, FALSE, tv, vBit, io, "SRCH BIT test", SRCH_Input, SRCH_Input_size, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_SRCHP, isOn, TRUE, tv, vBit, io, "SRCHP BIT test", SRCH_Input, SRCH_Input_size, expected, expectedSize, NULL);
	}

	return TRUE;
}

uint8 ATest_Sum()
{
	uint16 src = 0x0FF1;
	uint16 dst = 0;
	//uint16 searchDst = 0;
	//uint16 searchSrc2[] = {10, 100, 230, 345,1455, 131, 3523, 3523};

	uint16* CHKSUM_Input[] = {&src, &dst, NULL, NULL, NULL};
	uint16 CHKSUM_Input_size[] = {1, 1, 0, 0, 0};

	uint16 expected[] = {9};
	uint16 expectedSize = 1;


	TVarType tv[] = {TVarTest, TVarTest};
	VType vWord[] = {VTypeWordDev, VTypeWordDev};
	VType vBit[] = {VTypeBitDev, VTypeWordDev};
	IOType io[] = {IOTypeSRC, IOTypeDST};
	AT_setNibbleInclude(FALSE);

	int isOn;
	for(isOn=0; isOn<2; isOn++)
	{
		AT_testGeneralUnitTest(ML_CODE_CHKSUM, isOn, FALSE, tv, vWord, io, "CHSM WORD test", CHKSUM_Input, CHKSUM_Input_size, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_CHKSUMP, isOn, TRUE, tv, vWord, io, "CHSM WORD test", CHKSUM_Input, CHKSUM_Input_size, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_CHKSUM, isOn, FALSE, tv, vBit, io, "CHSM Bit test", CHKSUM_Input, CHKSUM_Input_size, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_CHKSUMP, isOn, TRUE, tv, vBit, io, "CHSM Bit test", CHKSUM_Input, CHKSUM_Input_size, expected, expectedSize, NULL);
	}

	return TRUE;

}

uint8 ATest_Max()
{
	uint16 src[] = {-10, 100, -230, -230, 3523, 131, 3523, 3523};
	uint16 dst = 0;
	uint16 cnt = 8;

	uint16 expected[] = {3523, 4, 3};
	uint16 expectedSize = 3;

	uint16* input[] = {src, &dst, &expectedSize, NULL, NULL};
	uint16 inputSize[] = {cnt, expectedSize, 1, 0, 0};

	TVarType tv[] = {TVarTest, TVarTest, TVarConst};
	VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeK};
	//VType vBit[] = {VTypeBitDev, VTypeWordDev, VTypeK};
	IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeCNT};
	AT_setNibbleInclude(FALSE);

	int isOn;
	for(isOn=0; isOn<2; isOn++)
	{
		AT_testGeneralUnitTest(ML_CODE_MAX, isOn, FALSE, tv, vWord, io, "MAX WORD test", input, inputSize, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_MAXP, isOn, TRUE, tv, vWord, io, "MAXP WORD test", input, inputSize, expected, expectedSize, NULL);
		//AT_testGeneralUnit(ML_CODE_MAX, isOn, FALSE, tv, vBit, io, "MAX Bit test", input, inputSize, expected, expectedSize);
		//AT_testGeneralUnit(ML_CODE_MAXP, isOn, TRUE, tv, vBit, io, "MAXP Bit test", input, inputSize, expected, expectedSize);
	}

	return TRUE;
}
uint8 ATest_Min()
{
	uint16 src[] = {-10, 100, -230, -230, 3523, 131, 3523, 3523};
	uint16 dst = 0;
	uint16 cnt = 8;

	uint16 expected[] = {-230, 2, 2};
	uint16 expectedSize = 3;

	uint16* input[] = {src, &dst, &expectedSize, NULL, NULL};
	uint16 inputSize[] = {cnt, expectedSize, 1, 0, 0};

	TVarType tv[] = {TVarTest, TVarTest, TVarConst};
	VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeK};
	//VType vBit[] = {VTypeBitDev, VTypeWordDev, VTypeK};
	IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeCNT};

	int isOn;
	for(isOn=0; isOn<2; isOn++)
	{
		AT_testGeneralUnitTest(ML_CODE_MIN, isOn, FALSE, tv, vWord, io, "MAX WORD test", input, inputSize, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_MINP, isOn, TRUE, tv, vWord, io, "MAXP WORD test", input, inputSize, expected, expectedSize, NULL);

	}

	return TRUE;
}
uint8 ATest_Sort()
{
	uint16 src[] = {-10, 100, 523, -230, -231, 3523, 131,  323};
	//uint16 dst = 0;
	uint16 cnt = 8;
	uint16 increase = 0;
	uint16 decrease = 1;
	uint16 parity = 0;
	//uint16 decrease = 1;

	uint16 expectedIncrease[] = {-231, -230, -10, 100, 131, 323, 523, 3523};
	uint16 expectedDecrease[] = {3523, 523, 323, 131, 100, -10, -230, -231, };
	uint16 expectedSize = cnt;

	uint16* inc[] = {src, &cnt, &increase, &parity, &parity };
	uint16* dec[] = {src, &cnt, &decrease, &parity, &parity };
	uint16 inputSize[] = {cnt, 1, 1, 1, 0};

	TVarType tv[] = {TVarTest, TVarConst, TVarConst, TVarConst, TVarConst};
	VType vWord[] = {VTypeWordDev, VTypeK, VTypeK, VTypeK, VTypeK};
	//VType vBit[] = {VTypeBitDev, VTypeWordDev, VTypeK};
	IOType io[] = {IOTypeDST, IOTypeConst, IOTypeConst, IOTypeConst, IOTypeConst};
	AT_setNibbleInclude(FALSE);

	int isOn;
	for(isOn=0; isOn<2; isOn++)
	{
		AT_testGeneralUnitTest(ML_CODE_SORT, isOn, FALSE, tv, vWord, io, "SORT inc test", inc, inputSize, expectedIncrease, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_SORT, isOn, FALSE, tv, vWord, io, "SORT dec test", dec, inputSize, expectedDecrease, expectedSize, NULL);
		//AT_testGeneralUnitAdditionalInput(ML_CODE_SORTP, isOn, TRUE, tv, vWord, io, "SORT inc test", inc, inputSize, expectedIncrease, expectedSize, NULL);
		//AT_testGeneralUnitAdditionalInput(ML_CODE_SORTP, isOn, TRUE, tv, vWord, io, "SORT dec test", dec, inputSize, expectedDecrease, expectedSize, NULL);
	}

	return TRUE;
}
/*uint8 ATest_Mean()
{
	uint16 src[] = {-10, 100, -230, -230, 3523, 131, 3523, 3523};
	uint16 dst = 0;
	uint16 cnt = 8;
	short value = (-10 + 100 -230 -230 + 3523 + 131 + 3523 + 3523)/8;

	uint16 expected[] = {value};
	uint16 expectedSize = 1;

	uint16* input[] = {src, &dst, &expectedSize, NULL, NULL};
	uint16 inputSize[] = {cnt, expectedSize, 1, 0, 0};

	TVarType tv[] = {TVarTest, TVarTest, TVarConst};
	VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeK};
	//VType vBit[] = {VTypeBitDev, VTypeWordDev, VTypeK};
	IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeCNT};

	int isOn;
	for(isOn=0; isOn<2; isOn++)
	{
		//AT_testGeneralUnit(ML_CODE_MIN, isOn, FALSE, tv, vWord, io, "MAX WORD test", input, inputSize, expected, expectedSize);
		//AT_testGeneralUnit(ML_CODE_MINP, isOn, TRUE, tv, vWord, io, "MAXP WORD test", input, inputSize, expected, expectedSize);
		//AT_testGeneralUnit(ML_CODE_MAX, isOn, FALSE, tv, vBit, io, "MAX Bit test", input, inputSize, expected, expectedSize);
		//AT_testGeneralUnit(ML_CODE_MAXP, isOn, TRUE, tv, vBit, io, "MAXP Bit test", input, inputSize, expected, expectedSize);
	}

	return TRUE;
}
*/
uint8 ATest_Limit()
{
	short src1 = -999;
	short src2 = 999;
	short src3[] = {-1000, -500, 1, 500, 1000};
	uint16 dst = 10;

	uint16 expectedLimit[] = {-999, -500, 1, 500, 999};
	uint16 expectedLimitSize = 1;
	uint16 inputSize[] = {1, 1, 1, 1, 0};
	int i;
	AT_setNibbleInclude(FALSE);

	for(i=0;i<5;i++)
	{
		uint16* input[] = {(uint16*)&src1, (uint16*)&src2, &src3[i], &dst, NULL};


		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		//VType vBit[] = {VTypeBitDev, VTypeWordDev, VTypeK};
		IOType io[] = {IOTypeSRC, IOTypeSRC, IOTypeSRC, IOTypeDST, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_LIMIT, isOn, FALSE, tv, vWord, io, "LIMIT test", input, inputSize, &expectedLimit[i], expectedLimitSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_LIMITP, isOn, TRUE, tv, vWord, io, "LIMITP test", input, inputSize, &expectedLimit[i], expectedLimitSize, NULL);
		}
	}
	return TRUE;

}

uint8 ATest_Band()
{
	short src1 = -999;
	short src2 = 999;
	short src3[] = {-1000, -500, 1, 500, 1000};
	uint16 dst = 10;

	uint16 expectedBand[] = {-1, 0, 0, 0, 1};
	uint16 expectedBandSize = 1;
	uint16 inputSize[] = {1, 1, 1, 1, 0};
	int i;
	AT_setNibbleInclude(FALSE);

	for(i=0;i<5;i++)
	{
		uint16* input[] = {(uint16*)&src1, (uint16*)&src2, &src3[i], &dst, NULL};


		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		//VType vBit[] = {VTypeBitDev, VTypeWordDev, VTypeK};
		IOType io[] = {IOTypeSRC, IOTypeSRC, IOTypeSRC, IOTypeDST, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_BAND, isOn, FALSE, tv, vWord, io, "BAND test", input, inputSize, &expectedBand[i], expectedBandSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_BANDP, isOn, TRUE, tv, vWord, io, "BANDP test", input, inputSize, &expectedBand[i], expectedBandSize, NULL);
		}
	}
	return TRUE;

}
uint8 ATest_Zone()
{
	short src1 = -999;
	short src2 = 999;
	short src3[] = {-1000, -500, 1, 500, 1000};
	uint16 dst = 10;

	uint16 expectedZone[] = {-1999, -1499, 1000, 1499, 1999};
	uint16 expectedZoneSize = 1;
	uint16 inputSize[] = {1, 1, 1, 1, 0};
	int i;
	AT_setNibbleInclude(FALSE);

	for(i=0;i<5;i++)
	{
		uint16* input[] = {(uint16*)&src1, (uint16*)&src2, &src3[i], &dst, NULL};


		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		//VType vBit[] = {VTypeBitDev, VTypeWordDev, VTypeK};
		IOType io[] = {IOTypeSRC, IOTypeSRC, IOTypeSRC, IOTypeDST, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_ZONE, isOn, FALSE, tv, vWord, io, "ZONE test", input, inputSize, &expectedZone[i], expectedZoneSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_ZONEP, isOn, TRUE, tv, vWord, io, "ZONEP test", input, inputSize, &expectedZone[i], expectedZoneSize, NULL);

		}
	}
	return TRUE;

}

void AT_setDateInput()
{
	addDeviceControlInstruction(0, OPERAND_ML_CODE_SD, PLC_SD_REG_DATE_TIME, 2000);
	addDeviceControlInstruction(0, OPERAND_ML_CODE_SD, PLC_SD_REG_DATE_TIME+1, 1);
	addDeviceControlInstruction(0, OPERAND_ML_CODE_SD, PLC_SD_REG_DATE_TIME+2, 2);
	addDeviceControlInstruction(0, OPERAND_ML_CODE_SD, PLC_SD_REG_DATE_TIME+3, 3);
	addDeviceControlInstruction(0, OPERAND_ML_CODE_SD, PLC_SD_REG_DATE_TIME+4, 4);
	addDeviceControlInstruction(0, OPERAND_ML_CODE_SD, PLC_SD_REG_DATE_TIME+5, 5);
	addDeviceControlInstruction(0, OPERAND_ML_CODE_SD, PLC_SD_REG_DATE_TIME+6, 6);
}

uint8 ATest_Daterd()
{
	uint16 dst[] = {-10,-10,-10,-10,-10,-10,-10,};
	uint16 dstCnt = 7;

	uint16 expectedSize = 7;
	uint16 inputSize[] = {dstCnt};
	uint16 expected[] = {2000, 1, 2, 3, 4, 5, 6};

	uint16* input[] = {(uint16*)dst, NULL, NULL, NULL, NULL};

	TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
	VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
	IOType io[] = {IOTypeDST, IOTypeSRC, IOTypeSRC, IOTypeDST, IOTypeConst};
	AT_setNibbleInclude(FALSE);

	int isOn;
	for(isOn=0; isOn<2; isOn++)
	{
		AT_testGeneralUnitTest(ML_CODE_DATERD, isOn, FALSE, tv, vWord, io, "DATERD test", input, inputSize, expected, expectedSize, AT_setDateInput);
		AT_testGeneralUnitTest(ML_CODE_DATERDP, isOn, TRUE, tv, vWord, io, "DATERDP test", input, inputSize, expected, expectedSize, AT_setDateInput);
	}

	return TRUE;
}
/*
uint8 ATest_Datewr()
{

	uint16 dst[] = {-10,-10,-10,-10,-10,-10,-10,};
	uint16 dstCnt = 7;

	uint16 expectedSize = 7;
	uint16 inputSize[] = {dstCnt};
	uint16 expected[] = {2000, 1, 2, 3, 4, 5, 6};

	uint16* input[] = {(uint16*)dst, NULL, NULL, NULL, NULL};

	TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
	VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
	IOType io[] = {IOTypeSRC, IOTypeSRC, IOTypeSRC, IOTypeDST, IOTypeConst};
	AT_setNibbleInclude(FALSE);

	int isOn;
	for(isOn=0; isOn<2; isOn++)
	{
		AT_testGeneralUnitTest(ML_CODE_DATEWR, isOn, FALSE, tv, vWord, io, "DATEWR test", input, inputSize, expected, expectedSize, AT_setDateInput);
		AT_testGeneralUnitTest(ML_CODE_DATEWRP, isOn, TRUE, tv, vWord, io, "DATEWRP test", input, inputSize, expected, expectedSize, AT_setDateInput);
	}

	return TRUE;
}
*/
uint8 ATest_Second()
{
	uint16 src[] = {10, 24, 56};
	uint16 dst[] = {10, 10};
	uint32 expectedInt = 10*3600+24*60+56;
	uint16* expected = &expectedInt;
	uint16 expectedSize = 2;
	uint16 inputSize[] = {3, 2};

	uint16* input[] = {src, &dst, NULL, NULL, NULL};
	AT_setNibbleInclude(FALSE);

	TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
	VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
	IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeSRC, IOTypeDST, IOTypeConst};

	int isOn;
	for(isOn=0; isOn<2; isOn++)
	{
		AT_testGeneralUnitTest(ML_CODE_SECOND, isOn, FALSE, tv, vWord, io, "SECOND test", input, inputSize, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_SECONDP, isOn, TRUE, tv, vWord, io, "SECONDP test", input, inputSize, expected, expectedSize, NULL);
	}

	return TRUE;
}

uint8 ATest_Hour()
{
	uint16 src[] = {10*3600+24*60+56, 0};
	uint16 dst[] = {100, 101, 102};
	uint32 expectedInt = 10*3600+24*60+56;
	uint16 expected[] = {10, 24, 56};
	uint16 expectedSize = 3;
	uint16 inputSize[] = {2, 3};

	uint16* input[] = {src, dst, NULL, NULL, NULL};

	TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
	VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
	IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeSRC, IOTypeDST, IOTypeConst};
	AT_setNibbleInclude(FALSE);

	int isOn;
	for(isOn=0; isOn<2; isOn++)
	{
		AT_testGeneralUnitTest(ML_CODE_HOUR, isOn, FALSE, tv, vWord, io, "HOUR test", input, inputSize, expected, expectedSize, NULL);
		AT_testGeneralUnitTest(ML_CODE_HOURP, isOn, TRUE, tv, vWord, io, "HOURP test", input, inputSize, expected, expectedSize, NULL);
	}

	return TRUE;

}

uint8 ATest_DAToB()
{
	uint8 *src[] = {
			"- 2345\0\0","  1234\0\0", "  8950\0\0", "-20343"
	};
	uint16 srcSize = 4;

	uint16 dst[] = {0, 0, 0, 0, 0};
	uint16 expected[] = {-2345, 1234, 8950, -20343};
	uint16 expectedSize = 1;
	uint16 inputSize[] = {srcSize, expectedSize, 0, 0, 0};
	AT_setNibbleInclude(FALSE);

	int i;
	for(i=0; i<4;i++)
	{
		uint16* input[] = {src[i], &dst[i], NULL, NULL, NULL};

		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeSRC, IOTypeDST, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_DATOB, isOn, FALSE, tv, vWord, io, "DATOB test", input, inputSize, &expected[i], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_DATOBP, isOn, TRUE, tv, vWord, io, "DATOBP test", input, inputSize, &expected[i], expectedSize, NULL);
		}
	}
	return TRUE;

}

uint8 ATest_HAToB()
{
	uint16 *src[] = {"AB12", "CD00", " 89A", " FF0"};
	uint16 srcSize = 2;

	uint16 dst[] = {0, 0, 0, 0, 0};
	uint16 expected[] = {0xAB12, 0xCD00, 0x89A, 0xFF0};
	uint16 expectedSize = 1;
	uint16 inputSize[] = {srcSize, expectedSize, 0, 0, 0};
	AT_setNibbleInclude(FALSE);

	int i;
	for(i=0; i<4;i++)
	{
		uint16* input[] = {src[i], &dst[i], NULL, NULL, NULL};

		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeSRC, IOTypeDST, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_HATOB, isOn, FALSE, tv, vWord, io, "HATOB test", input, inputSize, &expected[i], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_HATOBP, isOn, TRUE, tv, vWord, io, "HATOBP test", input, inputSize, &expected[i], expectedSize, NULL);
		}
	}
	return TRUE;

}

uint8 ATest_BToDA()
{
	uint16 src[] = {-2345, 1234, 8950, -20343};
	uint16 srcSize = 1;

	uint16 dst[] = {10, 10, 10, 10, 10, 10, 10, 10};
	uint16 *expected[] = {"- 2345\0\0", "  1234\0\0", "  8950\0\0", "-20343\0\0"};
	uint16 expectedSize = 4;
	uint16 inputSize[] = {srcSize, expectedSize, 0, 0, 0};
	AT_setNibbleInclude(FALSE);

	int i;
	for(i=0; i<4;i++)
	{
		uint16* input[] = {&src[i], &dst[i], NULL, NULL, NULL};

		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeSRC, IOTypeDST, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_BTODA, isOn, FALSE, tv, vWord, io, "BToDA test", input, inputSize, expected[i], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_BTODAP, isOn, TRUE, tv, vWord, io, "BToDAP test", input, inputSize, expected[i], expectedSize, NULL);
		}
	}
	return TRUE;

}

uint8 ATest_BToHA()
{
	uint16 src[] = {0xAB12, 0xCD00, 0x89A, 0xFF0};
	uint16 srcSize = 1;

	uint16 dst[] = {10, 10, 10, 10, 10, 10};
	uint16 *expected[] = {"AB12\0\0", "CD00\0\0", " 89A\0\0", " FF0\0\0"};
	uint16 expectedSize = 3;
	uint16 inputSize[] = {srcSize, expectedSize, 0, 0, 0};
	AT_setNibbleInclude(FALSE);

	int i;
	for(i=0; i<4;i++)
	{
		uint16* input[] = {&src[i], &dst[i], NULL, NULL, NULL};

		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeSRC, IOTypeDST, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_BTOHA, isOn, FALSE, tv, vWord, io, "BToHA test", input, inputSize, expected[i], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_BTOHAP, isOn, TRUE, tv, vWord, io, "BToHAP test", input, inputSize, expected[i], expectedSize, NULL);

			//DBG_LOGPRINT("isOn : %d, expected : %s\n",isOn, expected[i]);
		}
	}
	return TRUE;

}


uint8 ATest_Len()
{
	uint16 *src[] = {"AB12\0", "CDgerh00\0", " jtyk89A\0", "jrtykt FF0\0"};
	uint16 srcSize = 2;

	uint16 dst = 0;
	uint16 expected[] = {4, 8, 8, 10};
	uint16 expectedSize = 1;
	uint16 inputSize[] = {10, 1};
	AT_setNibbleInclude(FALSE);
	int i;
	for(i=0; i<4;i++)
	{
		uint16* input[] = {src[i], &dst, NULL, NULL, NULL};

		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeConst, IOTypeConst, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_LEN, isOn, FALSE, tv, vWord, io, "LEN test", input, inputSize, &expected[i], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_LENP, isOn, TRUE, tv, vWord, io, "LENP test", input, inputSize, &expected[i], expectedSize, NULL);

			//DBG_LOGPRINT("isOn : %d, expected : %s\n",isOn, expected[i]);
		}
	}
	return TRUE;
}


uint8 ATest_Rotation()
{
	uint16 src[] = {0xFFFE, 0x7FFF, 0x8000, 0x0001};
	uint16 rotation = 8;
	uint16 srcSize =2;

	//uint16 dst = 0;
	uint16 expectedROR[] = {0xFEFF, 0xFF7F, 0x0080, 0x0100};
	uint16 expectedRCR[][4] = {
			{0xFCFF, 0xFE7F, 0x0080, 0x0200},
			{0xFDFF, 0xFF7F, 0x0180, 0x0300},
	};

	uint16 expectedROL[] = {0xFEFF, 0xFF7F, 0x0080, 0x0100};
	uint16 expectedRCL[][4] = {
			{0xFE7F, 0xFF3F, 0x0040, 0x0100},
			{0xFEFF, 0xFFBF, 0x00C0, 0x0180}
	};
	AT_setNibbleInclude(FALSE);
	uint16 expectedSize = 1;
	uint16 inputSize[] = {1, 1, 1};
	int idxSrc, j;
	for(idxSrc = 0; idxSrc<4; idxSrc++)
	{
		uint16* input[] = {&src[idxSrc], &rotation, NULL, NULL, NULL};

		TVarType tv[] = {TVarTest, TVarTest, TVarConst, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeDST, IOTypeSRC, IOTypeConst, IOTypeConst, IOTypeConst};

		int isOn=1, isCarryOn=1;
		for(isOn=0; isOn<2; isOn++)
		{

			AT_testGeneralUnitTest(ML_CODE_ROR, isOn, FALSE, tv, vWord, io, "ROR test", input, inputSize, &expectedROR[idxSrc], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_RORP, isOn, TRUE, tv, vWord, io, "RORP test", input, inputSize, &expectedROR[idxSrc], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_ROL, isOn, FALSE, tv, vWord, io, "ROL test", input, inputSize, &expectedROL[idxSrc], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_ROLP, isOn, TRUE, tv, vWord, io, "ROLP test", input, inputSize, &expectedROL[idxSrc], expectedSize, NULL);


			for(isCarryOn=1; isCarryOn<2; isCarryOn++)
			{
				AT_testGeneralUnitTest(ML_CODE_RCR, isOn, FALSE, tv, vWord, io, "RCR test", input, inputSize, &expectedRCR[isCarryOn][idxSrc], expectedSize, carrySet[isCarryOn]);
				AT_testGeneralUnitTest(ML_CODE_RCRP, isOn, TRUE, tv, vWord, io, "RCRP test", input, inputSize, &expectedRCR[isCarryOn][idxSrc], expectedSize, carrySet[isCarryOn]);
				AT_testGeneralUnitTest(ML_CODE_RCL, isOn, FALSE, tv, vWord, io, "RCL test", input, inputSize, &expectedRCL[isCarryOn][idxSrc], expectedSize, carrySet[isCarryOn]);
				AT_testGeneralUnitTest(ML_CODE_RCLP, isOn, TRUE, tv, vWord, io, "RCLP test", input, inputSize, &expectedRCL[isCarryOn][idxSrc], expectedSize, carrySet[isCarryOn]);
			}
		}
	}

	return TRUE;
}

uint8 ATest_BtoStr()
{
	uint16 src1[][2] = {
			{4,2},
			{5,3},
			{5,2},
			{6,0},
	};
	uint16 *src2[] = {1100, -1535, 2615, 2275};
	uint16 src1Size = 2;
	uint16 src2Size = 1;

	uint16 dst[] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};
	uint16 *expected[] = {"11.00\0", "-1.535\0", "26.15\0\0", "  2275\0", };
	uint16 expectedSize = 3;
	AT_setNibbleInclude(FALSE);

	int i=3;
	for(i=0; i<4;i++)
	{
		uint16* input[] = {src1[i], &src2[i], dst, NULL, NULL};

		uint16 inputSize[] = {src1Size, src2Size, expectedSize};
		TVarType tv[] = {TVarTest, TVarConst, TVarConst, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeSRC, IOTypeSRC, IOTypeDST, IOTypeConst, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_BTOSTR, isOn, FALSE, tv, vWord, io, "BTOSTR test", input, inputSize, expected[i], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_BTOSTRP, isOn, TRUE, tv, vWord, io, "BTOSTRP test", input, inputSize, expected[i], expectedSize, NULL);

			//DBG_LOGPRINT("isOn : %d, expected : %s\n",isOn, expected[i]);
		}
	}
	return TRUE;
}


uint8 ATest_StrToB()
{
	uint16 *src1[] = {"11.00\0", "-1.535\0", "26.15\0\0", "  2275\0" };
	//uint16 src1Size[] ={3, 3, 3, 3 };
	uint16 dst1[] = {10, 10};
	uint16 dst2 = 0;
	uint16 src1Size = 3;
	uint16 dst1Size = 2;
	uint16 dst2Size = 1;

	//uint16 dst[] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};
	uint16 expected1[][2] = {
			{4,2},
			{5,3},
			{4,2},
			{6,0},
	};
	uint16 expected2[] = {
			1100,
			1535,
			2615,
			2275
		};
	AT_setNibbleInclude(FALSE);

	int i=3;
	for(i=0; i<4;i++)
	{
		uint16* input[] = {src1[i], dst1, &dst2, NULL, NULL};

		uint16 inputSize[] = {src1Size, 2, 1};
		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeSRC, IOTypeConst, IOTypeConst};
		uint16 expectedSize = inputSize[1];
		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_STRTOB, isOn, FALSE, tv, vWord, io, "STRTOB test", input, inputSize, expected1[i], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_STRTOBP, isOn, TRUE, tv, vWord, io, "STRTOBP test", input, inputSize, expected1[i], expectedSize, NULL);

			//DBG_LOGPRINT("isOn : %d, expected : %s\n",isOn, expected[i]);
		}
	}
	return TRUE;
}
uint8 ATest_BToAsc()
{
	uint16 src1[][3] =
	{
			{0x0010, 0x1234, 0x0010},
			{0x1234, 0x6790, 0xABDF},
			{0xFFFF, 0xF00F, 0xFF0F},
			{0x0000, 0x0000, 0x0000},
	};
	//uint16 src1Size[] ={3, 3, 3, 3 };
	uint16 dst[] = {0xDDDD ,0xDDDD, 0xDDDD, 0xDDDD, 0xDDDD, 0xDDDD};
	uint16 cnt = 3;
	uint16 srcSize = cnt;
	uint16 dstSize = 2*cnt;
	uint16 cntSize = 1;
	uint16 expectedSize = dstSize;
	//uint16 dst[] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};
	uint16 *expected[]= {
			"  1012340010",
			"12346790ABDF",
			"FFFFF00FFF0F",
			"           0",
	};
	AT_setNibbleInclude(FALSE);

	int i=0;
	for(i=0; i<4;i++)
	{
		uint16* input[] = {src1[i], dst, &cnt, NULL, NULL};

		uint16 inputSize[] = {srcSize, dstSize, cntSize};
		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeSRC, IOTypeConst, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_BTOASC, isOn, FALSE, tv, vWord, io, "BTOASC test", input, inputSize, expected[i], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_BTOASCP, isOn, TRUE, tv, vWord, io, "BTOASCP test", input, inputSize, expected[i], expectedSize, NULL);

			//DBG_LOGPRINT("isOn : %d, expected : %s\n",isOn, expected[i]);
		}
	}
	return TRUE;
}
uint8 ATest_AscToB()
{
	uint16 *src1[] =
	{
			"  1012340010",
			"12346790ABDF",
			"FFFFF00FF0FF",
			"           0",
	};
	//uint16 src1Size[] ={3, 3, 3, 3 };
	uint16 dst[] = {0xDDDD ,0xDDDD, 0xDDDD};
	uint16 cnt = 3;
	uint16 srcSize = cnt*2;
	uint16 dstSize = cnt;
	uint16 cntSize = 1;
	uint16 expectedSize = dstSize;
	//uint16 dst[] = {0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF};
	uint16 expected[][3]= {
			{0x0100, 0x4321, 0x0100},
			{0x4321, 0x0976, 0xFDBA},
			{0xFFFF, 0xF00F, 0xF0FF},
			{0x0000, 0x0000, 0x0000},
	};
	AT_setNibbleInclude(FALSE);

	int i=0;

	for(i=0; i<2;i++)
	{
		uint16* input[] = {src1[i], dst, &cnt, NULL, NULL};

		uint16 inputSize[] = {srcSize, dstSize, cntSize};
		TVarType tv[] = {TVarTest, TVarTest, TVarTest, TVarTest,TVarTest,};
		VType vWord[] = {VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, VTypeWordDev, };
		IOType io[] = {IOTypeSRC, IOTypeDST, IOTypeSRC, IOTypeConst, IOTypeConst};

		int isOn;
		for(isOn=0; isOn<2; isOn++)
		{
			AT_testGeneralUnitTest(ML_CODE_ASCTOB, isOn, FALSE, tv, vWord, io, "ASCTOB test", input, inputSize, expected[i], expectedSize, NULL);
			AT_testGeneralUnitTest(ML_CODE_ASCTOBP, isOn, TRUE, tv, vWord, io, "ASCTOBP test", input, inputSize, expected[i], expectedSize, NULL);

			//DBG_LOGPRINT("isOn : %d, expected : %s\n",isOn, expected[i]);
		}
	}
	return TRUE;
}