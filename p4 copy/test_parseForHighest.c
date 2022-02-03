#include <stdio.h>
#include "prog4.c"

int main()
{
	int highest = -1;
	char str1[] = "5;83;22;42";
	int retval = parseForHighest(str1, &highest);
	printf("retval=%d\n", retval);
	printf("highest=%d\n", highest);

	char str2[] = " 87  ; 92; 94 ; -5 ; 13 ";
	retval = parseForHighest(str2, &highest);
	printf("retval=%d\n", retval);
	printf("highest=%d\n", highest);

	char str3[] = "500;600;  700   ";
	retval = parseForHighest(str3, &highest);
	printf("retval=%d\n", retval);
	printf("highest=%d\n", highest);
	
}