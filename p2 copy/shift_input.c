#include <stdio.h>

int main()
{
	int k = 0;
	int extra;
	char c;
	char shifted_c;
	printf("Enter k: ");
	scanf(" %d", &k);
	if(k < -500 || k > 500)
	{
		printf("k is outside acceptable range.");
		return 0;
	}else{
		while(1)
		{
			printf("Enter character: ");
			scanf(" %c", &c);
			if(c >= 48 && c <= 57)
			{
				shifted_c = c + (k % 10);
				if(shifted_c > 57)
				{
					extra = shifted_c - 57;
					shifted_c = 47 + extra;
				}
				else if(shifted_c < 48)
				{
					extra = 48 - shifted_c;
					shifted_c = 58 - extra;
					}
				printf("Shifted: %c\n", shifted_c);
			}
			else if(c >= 65 && c <= 90)
			{
				shifted_c = c + (k % 26);
				if(shifted_c > 90)
				{
					extra = shifted_c - 90;
					shifted_c = 64 + extra;
				}
				else if(shifted_c < 65)
				{
					extra = 65 - shifted_c;
					shifted_c = 91 - extra;
				}
				printf("Shifted: %c\n", shifted_c);
			}
			else if(c >= 97 && c <= 122)
			{
				shifted_c = c + (k % 26);
				if(shifted_c > 122)
				{
					extra = shifted_c - 122;
					shifted_c = 96 + extra;
				}
				else if(shifted_c < 97)
				{
					extra = 97 - shifted_c;
					shifted_c = 123 - extra;
				}
				printf("Shifted: %c\n", shifted_c);	
			}
			else
			{
				break;
			}
		}
	}
}