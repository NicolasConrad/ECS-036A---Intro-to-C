#include <stdio.h>

#include "prog3.c"

int main()
{
	int arr[] = {17, 11, 14, 17, 19, 11, 15, 17};
	int x = getNthOccurrence(arr, 8, 17, 2);
	printf("%d\n", x); //3
	x = getNthOccurrence(arr, 8, 17, 3);
	printf("%d\n", x); //7
	x = getNthOccurrence(arr, 8, 11, 1);
	printf("%d\n", x); //1
	x = getNthOccurrence(arr, 8, 14, 2);
	printf("%d\n", x); //-2
	x = getNthOccurrence(arr, 8, 14, -1);
	printf("%d\n", x);

	int arr2[10];
	int y = getNthOccurrence(arr2, 10, 8, 2);
	printf("%d\n", y);
}