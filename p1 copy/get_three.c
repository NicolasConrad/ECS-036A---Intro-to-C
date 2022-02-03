#include <stdio.h>

int main()
{
	char a;
	char b;
	char c;
	printf("Enter first character: ");
	scanf(" %c", &a);
	printf("You just entered %c. Enter second character: ", a);
	scanf(" %c", &b);
	printf("You just entered %c. Enter third character: ", b);
	scanf(" %c", &c);
	printf("Backwards, the three characters are %c%c%c.\n", c, b, a);
}