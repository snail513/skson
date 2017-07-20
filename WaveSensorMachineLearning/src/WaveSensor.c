/*
 * WaveSensor.c
 *
 *  Created on: 2017. 5. 12.
 *      Author: skson
 */

#ifndef WAVESENSOR_H_
#include "WaveSensor.h"
#include <pthread.h>
#include <time.h>

#endif /* WAVESENSOR_H_ */


#define THREAD_SIZE 1
#define WAVESENSOR_LEARNING 0
#define WAVESENSOR_TESTING 1

pthread_t threads[THREAD_SIZE];
int done[THREAD_SIZE];
void *thread_main(void *);
void WaveSensor_init();
void WaveSensor_run();

static int IS_RUN = 1;
static int waveSensorState = 0;
static float ERROR_VALUE = 0.1f;


static float curr_input[FFT_SIZE][AXIS_SIZE];

static float error_rate;
static int over_value;
static int under_value;
static int under_value;


void WaveSensor_updateCurrInput()
{
	memset(curr_input, 0, sizeof(float) * FFT_SIZE * AXIS_SIZE);
}

void WaveSensor_setERROR_VALUE(float value)
{
	ERROR_VALUE = value;
}



void *thread_main(void *arg)
{

	WaveSensor_init();

	while(IS_RUN)
	{
		WaveSensor_run();
	}


	pthread_exit((void *) 0);
}

void WaveSensor_init()
{
	JudgeModel_init3D();
}
void WaveSensor_run()
{
	if(waveSensorState == WAVESENSOR_LEARNING)
	{
		JudgeModel_addData3D(curr_input[0], curr_input[1], curr_input[2]);
	}
	else
	{
		error_rate = JudgeModel_isError(ERROR_VALUE, curr_input);

		printf("ERROR RATE = %f\n", error_rate);
	}

}

int waveSensorTest()
{
	int i;
	int rc;
	int status;


	printf("pid=%d\n", getpid());

	for (i = 0; i < THREAD_SIZE; i++)
	{
		done[i] = 0;
		pthread_create(&threads[i], NULL, &thread_main, (void *)i);
		printf("[IDX]%d, [pthread_t]%d\n", i, threads[i]);
	}

	for (i = THREAD_SIZE-1; i >= 0; i--)
	{
		done[i] = 1;
	         rc = pthread_join(threads[i], (void **)&status);
		if (rc == 0)
		{
			printf("Completed join with thread %d status= %d\n",i, status);
		}
		else
		{
			printf("ERROR; return code from pthread_join() is %d, thread %d\n", rc, i);
         	return -1;
		}
	}

	return 0;
}
