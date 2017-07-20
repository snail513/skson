/*
 * JudgeModel.c
 *
 *  Created on: 2017. 5. 12.
 *      Author: skson
 */

#ifndef JUDGEMODEL_H_
#include "JudgeModel.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data.h"
#endif /* WAVESENSOR_H_ */

static JModel x;
static JModel y;
static JModel z;
static JModel s;


void JudgeModel_init3D()
{
	JudgeModel_init(&x);
	JudgeModel_init(&y);
	JudgeModel_init(&z);
	JudgeModel_init(&s);
}

void JudgeModel_addData3D(const float dataX[], const float dataY[], const float dataZ[])
{
	float dataS[FFT_SIZE];
	int i;
	for(i=0;i<FFT_SIZE;i++)
	{
		dataS[i] = sqrtf((float)(dataX[i]*dataX[i]+ dataY[i]*dataY[i] + dataZ[i]*dataZ[i]));
	}
	printf("add x : ");
	JudgeModel_addData(&x, dataX);
	printf("add y : ");
	JudgeModel_addData(&y, dataY);
	printf("add z : ");
	JudgeModel_addData(&z, dataZ);
	printf("add s : ");
	JudgeModel_addData(&s, dataS);
}

JModel* JudgeModel_selectByAxis(int axis)
{
	switch(axis)
	{
	case AXIS_X:
		return &x;
	case AXIS_Y:
		return &y;
	case AXIS_Z:
		return &z;
	default:
		return NULL;
	}
}

void JudgeModel_init(JModel* jmodel)
{

	//memset (arrCurrData, 0, DATA_SIZE*AXIS_SIZE);
	memset (jmodel->arrCurrFFTData, 0, sizeof(float) * FFT_SIZE);
	memset (jmodel->arrMaxBoundary, 0, sizeof(float) * FFT_SIZE);
	memset (jmodel->arrMinBoundary, 0, sizeof(float) * FFT_SIZE);
	int i;
	for(i=0;i<FFT_SIZE;i++)
	{
		jmodel->arrMinBoundary[i] = 1000.f;
	}

	memset (jmodel->arrModelSum, 0, sizeof(float) * FFT_SIZE);
	jmodel->nDataCount = 0;
}
void JudgeModel_addData(JModel* jmodel, const float data[])
{
	int i;
	memcpy(jmodel->arrCurrFFTData, data, sizeof(float) * FFT_SIZE);
	//JudgeModel_buildFFTData();
	jmodel->nDataCount ++;
	for(i=0; i < FFT_SIZE ; i++)
	{
		printf("[%d]%5.2f\t", i, jmodel->arrCurrFFTData[i]);
		if(jmodel->arrMaxBoundary[i] < jmodel->arrCurrFFTData[i])
		{
			jmodel->arrMaxBoundary[i] = jmodel->arrCurrFFTData[i];
		}
		if(jmodel->arrMinBoundary[i] > jmodel->arrCurrFFTData[i])
		{
			jmodel->arrMinBoundary[i] = jmodel->arrCurrFFTData[i];
		}

		jmodel->arrModelSum[i] += jmodel->arrCurrFFTData[i];
		jmodel->arrModelAvg[i] = jmodel->arrModelSum[i]/jmodel->nDataCount;
	}
	printf("\n");
}

float JudgeModel_getTotalFFT(JModel* jmodel)
{
	int i;
	float value = 0;
	for(i=0; i<FFT_SIZE; i++)
	{
		value +=jmodel->arrModelAvg[i];
	}
	return value;
}

float JudgeModel_getOverPower(JModel* jmodel, const float tar[FFT_SIZE])
{
	int i;
	float over= 0;
	uint16 max;
	uint16 curr;
	for(i=0; i<FFT_SIZE ; i++)
	{
		max = jmodel->arrMaxBoundary[i];
		curr = tar[i];
		if(curr>max)
		{
			over+= curr-max;
		}
	}

	return over;
}

float JudgeModel_getUnderPower(JModel* jmodel, const float tar[FFT_SIZE])
{
	int i;
	float under = 0;
	uint16 min;
	uint16 curr;
	for(i=0; i<FFT_SIZE ; i++)
	{

		min = jmodel->arrMinBoundary[i];
		curr = tar[i];

		if (curr<min)
		{
			under+= min-curr;
		}
	}
	return under;
}

float JudgeModel_getPartialOverPower(JModel* jmodel, const float tar[FFT_SIZE], int frequencyInterval/*from 0 to 7*/)
{
	int i;
	float over= 0;
	uint16 max;
	uint16 curr;
	int start = frequencyInterval*8;
	int end = (frequencyInterval+1)*8;
	for(i=start; i<end ; i++)
	{
		max = jmodel->arrMaxBoundary[i];
		curr = tar[i];
		if(curr>max)
		{
			over+= curr-max;
		}
	}

	return over;
}



float JudgeModel_getPartialUnderPower(JModel* jmodel, const float tar[FFT_SIZE], int frequencyInterval/*from 0 to 7*/)
{
	int i;
	float under= 0;
	uint16 min;
	uint16 curr;
	int start = frequencyInterval*8;
	int end = (frequencyInterval+1)*8;
	for(i=start; i<end ; i++)
	{
		min = jmodel->arrMinBoundary[i];
		curr = tar[i];

		if (curr<min)
		{
			under+= min-curr;
		}
	}

	return under;
}

float JudgeModel_getPartialOverPowerByAxis(int axis, const float tar[FFT_SIZE], int frequencyInterval/*from 0 to 7*/)
{
	return JudgeModel_getPartialOverPower(JudgeModel_selectByAxis(axis), tar, frequencyInterval);
}
float JudgeModel_getPartialUnderPowerByAxis(int axis, const float tar[FFT_SIZE], int frequencyInterval/*from 0 to 7*/)
{
	return JudgeModel_getPartialUnderPower(JudgeModel_selectByAxis(axis), tar, frequencyInterval);
}

float JudgeModel_getErrorPowerRate(JModel* jmodel, const float tar[FFT_SIZE])
{
	float under = JudgeModel_getUnderPower(jmodel, tar);
	float over = JudgeModel_getOverPower(jmodel, tar);
	float fftTotal = JudgeModel_getTotalFFT(jmodel);
	printf("over / total = %5.2f / %5.2f\n", under+over, fftTotal);
	return (under+over)/fftTotal;

}

float* JudgeModel_getCurrFFTData(JModel* jmodel)
{
	return jmodel->arrCurrFFTData;
}

void printData(JModel* jmodel)
{
	int i;
	printf("show :::::\n");
	printf("max / min / avg / sum\n");
	for(i=0; i<FFT_SIZE; i++)
	{
		printf("%5.2f\t%5.2f\t%5.2f\t%5.2f\n",
				jmodel->arrMaxBoundary[i],
				jmodel->arrMinBoundary[i],
				jmodel->arrModelAvg[i],
				jmodel->arrModelSum[i]
				            );

	}
	float overVal = JudgeModel_getErrorPowerRate(jmodel, data_test);
	printf("over value = %5.2f\n", overVal);
	printf("over value interval : \n");
	for(i = 0; i< 8; i++)
	{
		printf("[%d]%5.2f\t", i, JudgeModel_getPartialOverPower(jmodel, data_test, i)/JudgeModel_getTotalFFT(&x));
	}
	printf("\nunder value interval : \n");
	for(i = 0; i< 8; i++)
	{
		printf("[%d]%5.2f\t", i, JudgeModel_getPartialUnderPower(jmodel, data_test, i)/JudgeModel_getTotalFFT(&x));
	}
	printf("\n");
}


void printData3D()
{
	int i;
	for(i=0;i<AXIS_SIZE;i++)
	{
		printData(JudgeModel_selectByAxis(i));
	}
}

float JudgeModel_getErrorRateByAxis(int axis, const float tar[FFT_SIZE])
{
	return JudgeModel_getErrorPowerRate(JudgeModel_selectByAxis(axis), tar);
}

int JudgeModel_isError(float errorJudgementValue, const float tar[FFT_SIZE][AXIS_SIZE] )
{
	int i;
	for(i=0;i<AXIS_SIZE;i++)
	{
		float errorRate = JudgeModel_getErrorRateByAxis(i, tar[i]);
		if(errorRate > errorJudgementValue)
		{
			printf("Error!\n");
			return 1;
		}

	}
	printf("Not error!\n");
	return 0;
}

void testJudgeModel(){
	int i;
	JudgeModel_init3D();
	for(i=0; i<SAMPLE_DATA_SIZE-3; i++)
	{
		JudgeModel_addData3D(data[i], data[i+1], data[i+2]);
	}

	printData3D();

	printf("has Error? : %d\n", JudgeModel_isError(0.1f , data_test));

}