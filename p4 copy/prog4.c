#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUF_LEN 100

int findLastMismatch(const char* s1, const char* s2)
{
	int lastIndex;
	if(!s1 || !s2)
	{
		return -2;
	}else if(strlen(s1) == 0 || strlen(s2) == 0)
	{
		return -3;
	}else if(strlen(s1) != strlen(s2))
	{
		return -1;
	}else if(!strcmp(s1, s2))
	{
		return -4;
	}else
	{
		for(int i = 0; i < strlen(s1); ++i)
		{
			if(s1[i] != s2[i])
				lastIndex = i;
		}
		return lastIndex;
	}
}

int getLongestStretch(const char* s, char ch)
{
	int longest = 0;
	int current = 0;
	if(!s)
	{
		return -1;
	}
	
	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] == ch)
		{
			current += 1;
		}else
		{
			if(current > longest)
				longest = current;
			current = 0;
		}
	}
	return longest;
}

int parseForHighest(char* s, int* highest)
{
	if(!s)
		return 0;

	char* current;
	int num = 0;
	int numColons = 0;
	int numInts = 0;
	*highest = -1;

	for(int i = 0; i < strlen(s); ++i)
	{
		if(s[i] == ';')
			numColons += 1;
	}

	numInts = numColons + 1;

	for(int i = 0; i < numInts; ++i)
	{
		if(i == 0)
		{
			current = strtok(s, ";");
			num = atoi(current);
			*highest = num;
		}else{
			current = strtok(NULL, ";");
			num = atoi(current);
		}

		if(num > *highest)
			*highest = num;
	}

	return 1;
}

int getLines(char* lines)
{
	if(!lines)
		return 0;

	lines[0] = '\0';

	char input[BUF_LEN];
	int containsXYZ = 0;

	while(!containsXYZ)
	{
		
		printf("Enter: ");
		fgets(input, BUF_LEN, stdin);
		for(int i = 0; i < strlen(input); ++i)
		{
			if(input[i] == 'x' || input[i] == 'y' || input[i] == 'z')
			{
				containsXYZ = 1;
				return 1;
			}
		}

		lines = strncat(lines, input, (strlen(input) - 1));
	}

	return 1;
}