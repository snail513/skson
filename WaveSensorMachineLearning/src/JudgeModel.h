/*
 * JudgeModel.h
 *
 *  Created on: 2017. 5. 12.
 *      Author: skson
 */

#ifndef JUDGEMODEL_H_
#define JUDGEMODEL_H_

#include "Definitions.h"
#define PASS 1
#define FAIL 0
#define ERROR -1

//static uint16 arrCurrData[DATA_SIZE][AXIS_SIZE];
typedef struct JudgeModel {
	float arrCurrFFTData[FFT_SIZE];
	float arrMaxBoundary[FFT_SIZE];
	float arrMinBoundary[FFT_SIZE];
	float arrModelSum[FFT_SIZE];
	float arrModelAvg[FFT_SIZE];
	int nDataCount;
}JModel;

void JudgeModel_init(JModel* jmodel);
void JudgeModel_addData(JModel* jmodel, const float data[DATA_SIZE]);
float JudgeModel_getTotalFFT(JModel* jmodel);
float JudgeModel_getUnderPower(JModel* jmodel, const float tar[FFT_SIZE]);
float JudgeModel_getOverPower(JModel* jmodel, const float tar[FFT_SIZE]);
float JudgeModel_getPartialOverPower(JModel* jmodel, const float tar[FFT_SIZE], int frequencyInterval/*from 0 to 7*/);
float JudgeModel_getPartialUnderPower(JModel* jmodel, const float tar[FFT_SIZE], int frequencyInterval/*from 0 to 7*/);
float JudgeModel_getErrorPowerRate(JModel* jmodel, const float tar[FFT_SIZE]);
float* JudgeModel_getCurrFFTData(JModel* jmodel);
void testJudgeModel();

void JudgeModel_init3D();
void JudgeModel_addData3D(const float dataX[], const float dataY[], const float dataZ[]);
JModel* JudgeModel_selectByAxis(int axis);
void printData3D();
float JudgeModel_getPartialOverPowerByAxis(int axis, const float tar[FFT_SIZE], int frequencyInterval/*from 0 to 7*/);
float JudgeModel_getPartialUnderPowerByAxis(int axis, const float tar[FFT_SIZE], int frequencyInterval/*from 0 to 7*/);
float JudgeModel_getErrorRateByAxis(int axis, const float tar[FFT_SIZE]);
int JudgeModel_isError(float errorJudgementValue, const float tar[FFT_SIZE][AXIS_SIZE] );

#endif /* JUDGEMODEL_H_ */
