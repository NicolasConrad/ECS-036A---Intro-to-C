#include <stdio.h>
#include "prog4.c"

int main()
{
	printf("%d\n", getLongestStretch("abcd", 'a'));
	printf("%d\n", getLongestStretch("abcd", 'e'));
	printf("%d\n", getLongestStretch("abccd", 'c'));
	printf("%d\n", getLongestStretch("Hello there", 'l'));
	printf("%d\n", getLongestStretch("xyyzyxyyyz", 'y'));
	printf("%d\n", getLongestStretch("effghggefhhhg", 'g'));
	printf("%d\n", getLongestStretch("effghggefhhhg", 'f'));
	printf("%d\n", getLongestStretch("effghggefhhhg", 'h'));
	printf("%d\n", getLongestStretch("effghggefhhhg", 'e'));
	printf("%d\n", getLongestStretch("effghggefhhhg", 'a'));
}