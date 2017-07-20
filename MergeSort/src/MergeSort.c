/*
 ============================================================================
 Name        : MergeSort.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/* c program for heap sorting method*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char inProcess_intToArr( char* dst, int src, int onePos);
unsigned char inProcess_intToArrHex( char* dst, int src, int onePos);

unsigned char inProcess_arrToInt( int* dst, char* src);
unsigned char inProcess_hexArrToInt( int* dst, char* src);
int main()
{

	int nVal = -100;
	int hVal = 1000;
	char strVal[30];
	char strHVal[30];
	inProcess_intToArr(strVal, nVal, 10);
	inProcess_intToArrHex(strHVal, hVal, 10);
	printf("[strVal] %s <==> %d [nVal]\n", strVal, nVal);
	printf("[strHVal] %s <==> %4X [hVal]\n", strHVal, hVal);

	int rValue =0;
	int rhValue =0;
	if(!inProcess_arrToInt(&rValue, strVal))
		printf("FAILED while inProcess_arrToInt\n");
	if(!inProcess_hexArrToInt(&rhValue, strHVal))
		printf("FAILED while inProcess_hexArrToInt\n");
	printf("[strVal] %s <==> %d [rValue]\n", strVal, rValue);
	printf("[strHVal] %s <==> %4X [rhValue]\n", strHVal, rhValue);

	printf("\nSUCCESS!\n");
	return 1;
}

unsigned char inProcess_intToArr( char* dst, int src, int onePos)
{
	int j;
	if(src<0)
	{
		dst[0] = '-';
		src = -src;
	}
	else
		dst[0] = ' ';


	for(j = onePos; j>0; j--)
	{
		if(src==0)
		{
			dst[j] = ' ';
		}
		else
		{
			dst[j] = src%10+'0';
			src/=10;
		}
	}
	if(onePos%2 ==1)
	{
		dst[onePos+2] = 0;
	}
	dst[onePos+1] = 0;

	return 1;
}


unsigned char inProcess_intToArrHex( char* dst, int src, int onePos)
{
	int j;
	for(j = onePos; j>=0; j--)
	{
		if(src==0)
		{
			dst[j] = ' ';
		}
		else
		{
			int curr = src %16;
			if(curr<10)
			{
				dst[j] = src%16+'0';
			}
			else
			{
				dst[j] = src%16 -10 + 'A';
			}
			src/=16;
		}
	}
	if(onePos%2 ==1)
	{
		dst[onePos+2] = 0;
	}
	dst[onePos+1] = 0;

	return 1;
}


unsigned char inProcess_arrToInt( int* dst, char* src)
{
	*dst = 0;
	char isUnderZero;
	int i=0;
	if(src[i]=='-')
	{
		isUnderZero = 1;
	}
	else if(src[i]==' ')
	{
		isUnderZero = 0;
	}
	else
	{
		printf("sign error!\n");
		return 0;
	}
	i++;
	while(src[i]!=0)
	{
		(*dst)*=10;
		if(src[i]<='9' && src[i]>='0')
		{
			*dst+=src[i]-'0';
		}
		else if(src[i]==0)
		{
			break;
		}
		else if(src[i]==' ')
		{

		}
		else
		{
			printf("value error i = %d[%c]!\n", i, src[i]);
			return 0;
		}
		i++;
	}
	if(isUnderZero)
		*dst = -(*dst);
	return 1;
}
unsigned char inProcess_hexArrToInt( int* dst, char* src)
{
	*dst = 0;
	int i=0;
	while(src[i]!=0)
	{
		(*dst)*=16;
		if(src[i]<='9' && src[i]>='0')
		{
			*dst+=src[i]-'0';
		}
		else if(src[i]<='F' && src[i]>='A')
		{
			*dst+=10 + src[i]-'A';
		}
		else if(src[i]==0)
		{
			break;
		}
		else if(src[i]==' ')
		{

		}
		else
		{
			printf("value error i = %d[%c]!\n", i, src[i]);
			return 0;
		}
		i++;
	}
	return 1;

}
