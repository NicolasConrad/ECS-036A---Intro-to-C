#include "prog5.c"
#include <stdio.h>

int main()
{    
	int nr = 4, nc = 3;    
	int row1[] = {-2, 6, 1};    
	int row2[] = {-5, 3, 9};    
	int row3[] = {4,2,0};   
	int row4[] = {5, 10, -8};   
	int* arr[] = {row1, row2, row3, row4};    
	int result = -1;    
	printf("=== Case 1 ===\n");    
	printf("retval=%d\n", sumSubrectangle(arr, nr, nc, 1, 2, 1, 2, &result));   
	printf("result=%d\n", result);    
	printf("=== Case 2 ===\n");    
	printf("retval=%d\n", sumSubrectangle(arr, nr, nc, 0, nr-1, 0, nc-1, &result)); 
	printf("result=%d\n", result);   
	nr = 1;    
	nc = 5;    
	result = -1;    
	int row[] = {8, -5, 2, 5, 9};    
	int* arr2[] = {row};    
	printf("=== Case 3 ===\n");    
	printf("retval=%d\n", sumSubrectangle(arr2, nr, nc, 0, 0, 1, 3, &result));
	printf("result=%d\n", result);
}