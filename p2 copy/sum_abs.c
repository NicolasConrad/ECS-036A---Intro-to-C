#include <stdio.h>

int main()
{
	int input;
	int sum = 0;
	while(input != 0)
	{
		printf("Enter: ");
		scanf(" %d", &input);
		if(input < 0)
			input *= -1;
		sum += input;
	}	
	printf("Sum of absolute values: %d.", sum);
}