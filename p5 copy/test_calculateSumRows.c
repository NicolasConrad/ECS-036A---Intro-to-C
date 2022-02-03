
#include <stdlib.h>
#include <stdio.h>
#include "prog5.c"

int main()
{    
	int row1[] = {5, 8, 3};    
	int row2[] = {9, 2};    
	int row3[] = {4, -2, 1, 8, 9};    
	int rowWidths[] = {3, 2, 5};    
	int numRows = 3;    
	int *rows[] = {row1, row2, row3};    
	int* sums = calculateRowSums(rows, numRows, rowWidths);    
	for (int i = 0; i < numRows; ++i)        
		printf("sums[%d]=%d\n", i, sums[i]);    
	free(sums);
}