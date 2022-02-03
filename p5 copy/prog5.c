#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_SIZE 100

int sumSubrectangle(int** arr, int numRows, int numCols, int rowStart, int rowEnd, int colStart, int colEnd, int* result)
{
	for(int i = 0; i < numRows; ++i)
	{
		if(!arr[i])
			return 0;
	}

	if(!arr || !result || rowStart > rowEnd || colStart > colEnd || rowEnd > (numRows-1) || colEnd > (numCols-1) || colStart < 0 || rowStart < 0)
	{
		return 0;
	}else
	{
		int sum = 0;
		for(int i = rowStart; i <= rowEnd; ++i)
		{
				for(int j = colStart; j <= colEnd; ++j)
				{
					sum += arr[i][j];
				}
		}

		*result = sum;
		return 1;
	}
	
}

int parseForHighest(char* filename, int* highest)
{
	if(!filename || !highest)
		return -1;

	FILE* fp = fopen(filename, "r");
	
	if(fp == NULL)
	{
		return -2;
	}
	else
	{
		int num = 0;
		char buf[MAX_LINE_SIZE];
		while(fgets(buf, MAX_LINE_SIZE, fp))
		{
			num = atoi(buf);
			if(num > *highest)
				*highest = num;
		}
		fclose(fp);
		return 0;
	}
}

int* getAllHigherThan(int* arr, unsigned arrlen, int threshold, unsigned* newArrlen)
{
	if(!arr)
	{
		return NULL;
	}else
	{
		int numHigher = 0;
		for(int i = 0; i < arrlen; ++i)
		{
			if(arr[i] > threshold)
				numHigher += 1;
		}
		*newArrlen = numHigher;
		int* newArr = malloc(*newArrlen * sizeof(int));
		int index = 0;
		for(int i = (arrlen - 1); i >= 0; --i)
		{
			if(arr[i] > threshold)
			{
				newArr[index] = arr[i];
				++index;
			}

		}

		return newArr;
	}
}

int* calculateRowSums(int** vals, int numRows, int* rowWidths)
{
	if(!vals || !rowWidths)
	{
		return NULL;
	}else
	{
		int* sumArr = malloc(numRows * sizeof(int));
		int sum = 0;
		for(int i = 0; i < numRows; ++i)
		{
			if(!vals[i])
			{
				return NULL;
			}
			sum = 0;
			for(int j = 0; j < rowWidths[i]; ++j)
			{
				sum += vals[i][j];
			}
			sumArr[i] = sum;
		}

		return sumArr;
	}
	
}

int* applyTransformation(char** strings, int numStrings, int (*transform)(char*))
{
	if(!strings)
	{
		return NULL;
	}else
	{
		int* nums = malloc(numStrings * sizeof(int));
		for(int i = 0; i < numStrings; ++i)
		{
			nums[i] = transform(strings[i]);
		}
		return nums;
	}
}
