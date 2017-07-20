/*
 * fft.c
 *
 *  Created on: 2017. 5. 16.
 *      Author: skson
 */

#ifndef FFT_H_

#include "fft.h"

#endif

static int N = 16;
#define PI2 6.2832


int fft_test()
{
	int n, k;             // indices for time and frequency domains
	float x[N];           // discrete-time signal, x
	float Xre[N], Xim[N]; // DFT of x (real and imaginary parts)
	float P[N];           // power spectrum of x

	// Generate random discrete-time signal x in range (-1,+1)
	srand(time(0));
	for (n=0 ; n<N ; ++n) x[n] = ((2.0 * rand()) / RAND_MAX) - 1.0;

	// Calculate DFT of x using brute force
	for (k=0 ; k<N ; ++k)
	{
		// Real part of X[k]
		Xre[k] = 0;
		for (n=0 ; n<N ; ++n) Xre[k] += x[n] * cos(n * k * PI2 / N);

		// Imaginary part of X[k]
		Xim[k] = 0;
		for (n=0 ; n<N ; ++n) Xim[k] -= x[n] * sin(n * k * PI2 / N);

		// Power at kth frequency bin
		P[k] = Xre[k]*Xre[k] + Xim[k]*Xim[k];
	}

	// Output results to MATLAB / Octave M-file for plotting
	//FILE *f = fopen("dftplots.m", "w");
	/*
	fprintf(f, "n = [0:%d];\n", N-1);
	fprintf(f, "x = [ ");
	for (n=0 ; n<N ; ++n) fprintf(f, "%f ", x[n]);
	fprintf(f, "];\n");
	fprintf(f, "Xre = [ ");
	for (k=0 ; k<N ; ++k) fprintf(f, "%f ", Xre[k]);
	fprintf(f, "];\n");
	fprintf(f, "Xim = [ ");
	for (k=0 ; k<N ; ++k) fprintf(f, "%f ", Xim[k]);
	fprintf(f, "];\n");
	fprintf(f, "P = [ ");
	for (k=0 ; k<N ; ++k) fprintf(f, "%f ", P[k]);
	fprintf(f, "];\n");
	fprintf(f, "subplot(3,1,1)\nplot(n,x)\n");
	fprintf(f, "xlim([0 %d])\n", N-1);
	fprintf(f, "subplot(3,1,2)\nplot(n,Xre,n,Xim)\n");
	fprintf(f, "xlim([0 %d])\n", N-1);
	fprintf(f, "subplot(3,1,3)\nstem(n,P)\n");
	fprintf(f, "xlim([0 %d])\n", N-1);
	fclose(f);
	 */
	printf("Real : ");
	for(k=0 ; k<N ; ++k)
	{
		if(k%20 == 19)
			printf("\nn");
		else if(k%5 == 4)
			printf("\n");
		printf("%4.2f ", Xre[k]);
	}
	printf("\ntime signal : ");
	for(k=0 ; k<N ; ++k)
	{
		if(k%20 == 19)
			printf("\nn");
		else if(k%5 == 4)
			printf("\n");
		printf("%4.2f ", x[k]);
	}
	printf("\n");
	// exit normally


	return 0;
}
