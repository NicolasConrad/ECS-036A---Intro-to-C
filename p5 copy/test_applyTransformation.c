#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "prog5.c"

int testTransform1(char* str)
{
	if(!strcmp(str, "abc")) return 0;
	else if(!strcmp(str, "def")) return 1;
	else return 2;
}

int testTransform2(char* str)
{
	if(strlen(str) < 3) return 0;
	else return str[2];
}

int main()
{
	{
		printf("=== Case 1 ===\n");
		int len = 4;
		char* terms[] = {"abc", "def", "ghi", "def"};
		int* arr = applyTransformation(terms, len, testTransform1);
		for(int i = 0; i < len; ++i)
			printf("arr[%d]=%d\n", i, arr[i]);
		free(arr);
	}
	{
		printf("=== Case 2 ===\n");
		int len = 5;
		char* terms[] = {"ab", "cde", "efgh", "", "ijk"};
		int* arr = applyTransformation(terms, len, testTransform2);
		for(int i = 0; i < len; ++i)
			printf("arr[%d]=%d\n", i, arr[i]);
		free(arr);
	}
}