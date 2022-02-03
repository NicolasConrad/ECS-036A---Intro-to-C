#include <stdio.h>

#include "prog3.c"

int main()
{
	char s1[] = "abracadabra";
	char s2[] = "arb";
	int num = getNumBackwards(s1, s2);
	printf("%d\n", num); //2
	char s3[] = "apple";
	char s4[] = "pa";
	num = getNumBackwards(s3, s4);
	printf("%d\n", num); //1
}