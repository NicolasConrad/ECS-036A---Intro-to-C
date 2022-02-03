#include "prog5.c"
#include <stdio.h>

int main()
{
	int highest = 0;
	int retval = parseForHighest("values.txt", &highest);
	printf("retval: %d\n", retval);
	printf("highest: %d\n", highest);
	retval = parseForHighest(NULL, &highest);
	printf("retval: %d\n", retval);
	retval = parseForHighest("values.txt", NULL);
	printf("retval: %d\n", retval);
}