#include <stdio.h>
#include <stdlib.h>

unsigned enterUntilN(unsigned n)
{
	int x = 0;
	int numVals = 0;
	int sum = 0;
	while(abs(sum) < n)
	{
		printf("Entered: ");
		scanf(" %d", &x);
		sum += x;
		numVals += 1;
	}
	return numVals;
}

void sum3(int a, int b, int c, int* val)
{
	if(val)
	{
		*val = a+b+c;
	}
	else
		return;
}

int getNthOccurrence(int* arr, int arrlen, int target, int n)
{
	int numOccurences = 0;
	if(arr != NULL && n > 0)
	{
		for(int i = 0; i < arrlen; ++i)
		{
			if(arr[i] == target)
			{
				numOccurences += 1;
			}

			if(numOccurences == n)
			{
				return i;
			}
		}
		return -2;
	}else
	{
		return -1;
	}
}

int countOccurrences(int* arr, int arrlen, int target, int* first)
{
	int numOccurrences = 0;
	if(arr && first)
	{
		for(int i = 0; i < arrlen; ++i)
		{
			if(arr[i] == target)
			{
				*first = i;
				break;
			}
		}

		for(int i = 0; i < arrlen; ++i)
		{
			if(arr[i] == target)
				numOccurrences += 1;
		}
		return numOccurrences;
	}else
		return -1;
}

int getNumBackwards(char* str1, char* str2)
{
	if(str1 && str2)
	{
		int numBackwards = 0;
		int sameString = 1;

		int index = 0;
		while(str1[index] != 0)
			index++;
		int strlen1 = index;

		index = 0;
		while(str2[index] != 0)
			index++;
		int strlen2 = index;

		char strBackwards[strlen2 + 1];
		for(int i = strlen2 - 1, j = 0; i >= -1; --i, ++j)
		{
			if(i == -1)
				strBackwards[j] = 0;
			else
				strBackwards[j] = str2[i];
		}

		char subStr[strlen2];
		for(int i = 0; i < strlen1; ++i)
		{
			sameString = 1;
			for(int j = 0, k = i; j < strlen2; ++j, ++k)
			{
				subStr[j] = str1[k];
			}
			for(int l = 0; l < strlen2; ++l)
				if(subStr[l] != strBackwards[l])
				{
					sameString = 0;
					break;
				}
			if(sameString)
				numBackwards += 1;
		}

		return numBackwards;

	}else
		return -1;
}