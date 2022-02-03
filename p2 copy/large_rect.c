#include <stdio.h>

int main()
{
	int width = 1;
	int height = 1;
	int max_width = 0;
	int max_height = 0;
	int num_rect = 1;
	int current_area;
	int max_area = 0;
	while(width > 0 && height > 0)
	{
		printf("Enter width of rectangle #%d: ", num_rect);
		scanf(" %d", &width);
		if(width <= 0)
			break;
		printf("Enter its height: ");
		scanf(" %d", &height);
		if(height <= 0)
			break;
		current_area = width*height;
		if(current_area > max_area)
		{
			max_area = current_area;
			max_width = width;
			max_height = height;
		}
		num_rect += 1;
	}
	if(max_area == 0)
		printf("No valid rectangle was given.");
	else
		printf("The largest rectangle was %d-by-%d with an area of %d.", max_width, max_height, max_area);
}