#include <stdio.h>

int getProduct(int* arr, int arrLen)
{
	if(arrLen == 0)
		return 1;
	else
		return arr[0] * getProduct(arr + 1, arrLen - 1);
}

int linearSearch(int* arr, int arrLen, int target)
{
	if(arr[0] == target)
		return 1;

	if(arrLen == 0)
		return 0;
	else
		return linearSearch(arr + 1, arrLen - 1, target); 
}
