#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int febDays = 28;

int checkMonth(const char* month)
{
	if(!month)
		return 0;
	else
	{
		if(!strcmp(month, "Jan"))
			return 1;
		else if(!strcmp(month, "Feb"))
			return 1;
		else if(!strcmp(month, "Mar"))
			return 1;
		else if(!strcmp(month, "Apr"))
			return 1;
		else if(!strcmp(month, "May"))
			return 1;
		else if(!strcmp(month, "Jun"))
			return 1;
		else if(!strcmp(month, "Jul"))
			return 1;
		else if(!strcmp(month, "Aug"))
			return 1;
		else if(!strcmp(month, "Sep"))
			return 1;
		else if(!strcmp(month, "Oct"))
			return 1;
		else if(!strcmp(month, "Nov"))
			return 1;
		else if(!strcmp(month, "Dec"))
			return 1;
		else
			return 0;
	}
	
		
}

int checkDay(int day, const char* month)
{
	if(day <= 0 || day > 31)
		return 0;
	else if(!strcmp(month, "Jan"))
	{
		if(day <= 31)
			return 1;
	}else if(!strcmp(month, "Feb"))
	{
		if(day <= febDays)
			return 1;
	}else if(!strcmp(month, "Mar"))
	{
		if(day <= 31)
			return 1;
	}else if(!strcmp(month, "Apr"))
	{
		if(day <= 30)
			return 1;
	}else if(!strcmp(month, "May"))
	{
		if(day <= 31)
			return 1;
	}else if(!strcmp(month, "Jun"))
	{
		if(day <= 30)
			return 1;
	}else if(!strcmp(month, "Jul"))
	{
		if(day <= 31)
			return 1;
	}else if(!strcmp(month, "Aug"))
	{
		if(day <= 31)
			return 1;
	}else if(!strcmp(month, "Sep"))
	{
		if(day <= 30)
			return 1;
	}else if(!strcmp(month, "Oct"))
	{
		if(day <= 31)
			return 1;
	}else if(!strcmp(month, "Nov"))
	{
		if(day <= 30)
			return 1;
	}else if(!strcmp(month, "Dec"))
	{
		if(day <= 31)
			return 1;
	}
		
	return 0;
}

int checkYear(int year)
{
	if(year < 0)
		return 0;
	else
	{
		febDays = 28;
		if(year % 4 == 0)
		{
			if(year % 100 == 0)
			{
				if(year % 400 == 0)
					febDays = 29;
			}
			febDays = 29;
		}
		return 1;
	}
}

int getMonthInt(char* month)
{
	if(!strcmp(month, "Jan"))
		return 1;
	else if(!strcmp(month, "Feb"))
		return 2;
	else if(!strcmp(month, "Mar"))
		return 3;
	else if(!strcmp(month, "Apr"))
		return 4;
	else if(!strcmp(month, "May"))
		return 5;
	else if(!strcmp(month, "Jun"))
		return 6;
	else if(!strcmp(month, "Jul"))
		return 7;
	else if(!strcmp(month, "Aug"))
		return 8;
	else if(!strcmp(month, "Sep"))
		return 9;
	else if(!strcmp(month, "Oct"))
		return 10;
	else if(!strcmp(month, "Nov"))
		return 11;
	else
		return 12;

}

struct Date
{
	char* month;
	int day;
	int year;
};

struct Date* createDate(const char* month, int day, int year)
{
	if(checkMonth(month) && checkYear(year) && checkDay(day, month))
	{
		struct Date* d = malloc(sizeof(struct Date));
		d->month = malloc((strlen(month)) * sizeof(char));
		strcpy(d->month, month);
		d->day = day;
		d->year = year;
		return d;
	}else
		return NULL; 
	
}

int destroyDate(struct Date* date)
{
	if(!date){
		return 0;
	}else{
		free(date->month);
		free(date);
		return 1;
	}
	
}

char* getMonth(struct Date* date)
{
	if(!date)
		return NULL;
	else
	{
		char* monthCopy = malloc(strlen(date->month) * sizeof(char));
		strcpy(monthCopy, date->month);
		return monthCopy;
	}
}

int getDay(struct Date* date)
{
	if(!date)
		return 0;
	else	
		return date->day;
}

int getYear(struct Date* date)
{
	if(!date)
		return 0;
	else
		return date->year;
}

int setMonth(struct Date* date, const char* month)
{
	if(!date)
		return 0;
	else if(checkMonth(month))
	{
		date->month = realloc(date->month, (strlen(month)+1) * sizeof(char));
		strcpy(date->month,month);
		return 1;
	}else
		return 0;
}

int setDay(struct Date* date, int day)
{
	if(!date)
		return 0;
	else if(checkDay(day, date->month))
	{
		date->day = day;
		return 1;
	}
	return 0;
}

int setYear(struct Date* date, int year)
{
	if(!date)
		return 0;
	else if(checkYear(year))
	{
		if(checkDay(date->day, date->month))
		{
			date->year = year;
			return 1;
		}
	}
		
	return 0;
}

int compareDay(struct Date* d1, struct Date* d2)
{
	if(!d1 || !d2)
		return -2;
	else if(d1->year < d2->year)
		return -1;
	else if(d1->year > d2->year)
		return 1;
	else if(d1->year == d2->year)
	{
		if(getMonthInt(d1->month) < getMonthInt(d2->month))
			return -1;
		else if(getMonthInt(d1->month) > getMonthInt(d2->month))
			return 1;
		else if(getMonthInt(d1->month) == getMonthInt(d2->month))
		{
			if(d1->day < d2->day)
				return -1;
			else if(d1->day > d2->day)
				return 1;
		}
	}

	return 0;
}

int nextDay(struct Date* date)
{
	if(!date)
		return 0;
	else
	{
		if(!strcmp(date->month, "Jan"))
		{
			if(date->day == 31)
			{
				setMonth(date, "Feb");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}else if(!strcmp(date->month, "Feb"))
		{
			if(date->day == febDays)
			{
				setMonth(date, "Mar");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}else if(!strcmp(date->month, "Mar"))
		{
			if(date->day == 31)
			{
				setMonth(date, "Apr");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day+1);
			}
		}else if(!strcmp(date->month, "Apr"))
		{
			if(date->day == 30)
			{
				setMonth(date, "May");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}else if(!strcmp(date->month, "May"))
		{
			if(date->day == 31)
			{
				setMonth(date, "Jun");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}else if(!strcmp(date->month, "Jun"))
		{
			if(date->day == 30)
			{
				setMonth(date, "Jul");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}else if(!strcmp(date->month, "Jul"))
		{
			if(date->day == 31)
			{
				setMonth(date, "Aug");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}else if(!strcmp(date->month, "Aug"))
		{
			if(date->day == 31)
			{
				setMonth(date, "Sep");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}else if(!strcmp(date->month, "Sep"))
		{
			if(date->day == 30)
			{
				setMonth(date, "Sep");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}	
		}else if(!strcmp(date->month, "Oct"))
		{
			if(date->day == 31)
			{
				setMonth(date, "Nov");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}else if(!strcmp(date->month, "Nov"))
		{
			if(date->day == 30)
			{
				setMonth(date, "Dec");
				setDay(date, 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}else if(!strcmp(date->month, "Dec"))
		{
			if(date->day == 31)
			{
				setMonth(date, "Jan");
				setDay(date, 1);
				setYear(date, date->year + 1);
			}else
			{
				setDay(date, date->day + 1);
			}
		}
		return 1;
	}
	
}