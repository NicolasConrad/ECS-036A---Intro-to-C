#include "prog6.c"
#include <stdio.h>
#include <stdlib.h>
#define GUARD_RAIL "======\n"

void printIfNull(struct Date* d)
{   
	if (d)
		printf("Not null.\n");    
	else      
		printf("Null.\n");
}

int main()
{    
	struct Date* d1 = createDate("Jan", -5, 1970);    
	printIfNull(d1);  // Null    
	d1 = createDate("blah", 25, 2010);    
	printIfNull(d1);  // Null  

	printf(GUARD_RAIL);    
	d1 = createDate("Mar", 25, 2010);    
	char* month = getMonth(d1);    
	printf("%s\n", month);  // Mar    
	free(month);    
	printf("%d\n", getDay(d1));  // 25
	printf("%d\n", getYear(d1));  // 2010    
	setMonth(d1, "Apr");    
	month = getMonth(d1);    
	printf("%s\n", month);  // Apr    
	free(month);    
	int retval = setYear(d1, 2008);    
	printf("%d\n", retval);  // 1    
	printf("%d\n", getYear(d1));  // 2008    
	retval = setYear(d1, -5);    
	printf("%d\n", retval);  // 0    
	destroyDate(d1);    
	printf(GUARD_RAIL);    
	d1 = createDate("Jun", 1, 1438);    
	printf("%d\n", compareDay(d1, d1));  // 0    
	struct Date* d2 = createDate("May", 31, 1438);    
	printf("%d\n", compareDay(d1, d2));  // 1    
	printf("%d\n", compareDay(d2, d1));  // -1    
	printf("%d\n", compareDay(NULL, d1));  // -2    
	destroyDate(d1);   
	destroyDate(d2);   
	printf(GUARD_RAIL);    
	d1 = createDate("Nov", 5, 2105);    
	nextDay(d1);    
	printf("%d\n", getDay(d1));  // 6    
	destroyDate(d1);   
	d1 = createDate("Dec", 31, 1573);    
	nextDay(d1);   
	month = getMonth(d1);
    printf("%s\n", month);  // Jan    
    free(month);    
    printf("%d\n", getDay(d1));  // 1    
    printf("%d\n", getYear(d1));  // 1574    
    destroyDate(d1);
}
