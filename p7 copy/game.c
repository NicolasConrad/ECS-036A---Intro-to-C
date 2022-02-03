#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_SIZE 100

int height;
int width;
char leftKey;
char rightKey;
char upKey;
char downKey;
char quitKey;
char playerIcon;
char poweredIcon;
int playerXCoordinate;
int playerYCoordinate;
int numBuildings = 0;
int numEnemies = 0;
int numItems = 0;
int numOrbs = 0;
int* buildingX;
int* buildingY;
int* enemyX;
int* enemyY;
int* itemX;
int* itemY;
int* orbX;
int* orbY;
int score = 0;
int itemsRemaining = 0;
int isPowered = 0;
int powerTurns;

void initializeArrays()
{
	buildingX = malloc(0);
	buildingY = malloc(0);
	enemyX = malloc(0);
	enemyY = malloc(0);
	itemX = malloc(0);
	itemY = malloc(0);
	orbX = malloc(0);
	orbY = malloc(0);
}

void freeAllArrays()
{
	free(buildingX);
	free(buildingY);
	free(enemyX);
	free(enemyY);
	free(itemX);
	free(itemY);
	free(orbX);
	free(orbY);
}

void getInput(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	char str[MAX_LINE_SIZE];
	char currentStr[MAX_LINE_SIZE];
	int lineNum = 1;
	int num1;
	int num2;
	char type;
	
	initializeArrays();

	while(fgets(str, MAX_LINE_SIZE, fp) != NULL)
	{
		if(lineNum == 1)
		{
			height = atoi(strtok(str, " "));
			width = atoi(strtok(NULL, " "));
			lineNum += 1;
		}else if(lineNum == 2)
		{
			if(strcmp(str, "\0") == 0 || strcmp(str, "\n") == 0 || strcmp(str, "\r\n") == 0)
			{
				leftKey = 'a';
				rightKey = 'd';
				upKey = 'w';
				downKey = 's';
				quitKey = 'q';
				
			}else
			{
				strcpy(currentStr,strtok(str, " "));
				leftKey = currentStr[0];

				strcpy(currentStr, strtok(NULL, " "));
				rightKey = currentStr[0];

				strcpy(currentStr, strtok(NULL, " "));
				upKey = currentStr[0];

				strcpy(currentStr, strtok(NULL, " "));
				downKey = currentStr[0];

				strcpy(currentStr, strtok(NULL, " "));
				quitKey = currentStr[0];
			}
			lineNum += 1;
		}else if(lineNum == 3)
		{
			strcpy(currentStr, strtok(str, " "));
			playerIcon = currentStr[0];

			strcpy(currentStr, strtok(NULL, " "));
			poweredIcon = currentStr[0];

			playerYCoordinate = atoi(strtok(NULL, " "));
			playerXCoordinate = atoi(strtok(NULL, " "));
			lineNum+=1;
		}else
		{
			strcpy(currentStr, strtok(str, " "));
			type = currentStr[0];
			num1 = atoi(strtok(NULL, " "));
			num2 = atoi(strtok(NULL, " "));
			
			if(type == 'B')
			{
				//change size of the array
				numBuildings += 1;
				buildingX = realloc(buildingX, sizeof(int) * numBuildings);
				buildingY = realloc(buildingY, sizeof(int) * numBuildings);
				//assign Y coordinate
				buildingY[numBuildings - 1] = num1;
				//assign X coordinate
				buildingX[numBuildings - 1] = num2;
			}else if(type == 'E')
			{
				//change size of the array
				numEnemies += 1;
				enemyX = realloc(enemyX, sizeof(int) * numEnemies);
				enemyY = realloc(enemyY, sizeof(int) * numEnemies);
				//assign Y coordinate
				enemyY[numEnemies - 1] = num1;
				//assign X coordinate
				enemyX[numEnemies - 1] = num2;
			}else if(type == 'I')
			{
				//change the size of the array
				numItems += 1;
				itemsRemaining += 1;
				itemX = realloc(itemX, sizeof(int) * numItems);
				itemY = realloc(itemY, sizeof(int) * numItems);
				//assign Y coordinate
				itemY[numItems - 1] = num1;
				//assign X coordinate
				itemX[numItems - 1] = num2;
			}else
			{
				//change the size of the array
				numOrbs += 1;
				orbX = realloc(orbX, sizeof(int) * numOrbs);
				orbY = realloc(orbY, sizeof(int) * numOrbs);
				//get Y coordinate
				orbY[numOrbs - 1] = num1;
				//get X coordinate
				orbX[numOrbs - 1] = num2;
			}
		}
	}
	fclose(fp);
}

int isBuildingCoordinate(int y, int x)
{
	for(int i = 0; i < numBuildings; ++i)
	{
		if(buildingY[i] == y)
		{
			if(buildingX[i] == x || buildingX[i] + 1 == x || buildingX[i] + 2 == x || buildingX[i] + 3 == x || buildingX[i] + 4 == x || buildingX[i] + 5 == x)
				return 1;
		}else if(buildingY[i] + 1 == y)
		{
			if(buildingX[i] == x || buildingX[i] + 1 == x || buildingX[i] + 2 == x || buildingX[i] + 3 == x || buildingX[i] + 4 == x || buildingX[i] + 5 == x)
				return 1;
		}else if(buildingY[i] + 2 == y)
		{
			if(buildingX[i] == x || buildingX[i] + 1 == x || buildingX[i] + 4  == x || buildingX[i] + 5 == x)
				return 1;
			else if(buildingX[i] + 2 == x || buildingX[i] + 3 == x)
				return 2;
		}else if(buildingY[i] + 3 == y)
		{
			if(buildingX[i] == x || buildingX[i] + 1 == x || buildingX[i] + 4 == x || buildingX[i] + 5 == x)
				return 1;
			else if(buildingX[i] + 2 == x || buildingX[i] + 3 == x)
				return 2;
		}
	}
	return 0;
}

int isEnemyCoordinate(int y, int x)
{
	for(int i = 0; i < numEnemies; ++i)
	{
		if(enemyY[i] == y && enemyX[i] == x)
		{
			return 1;
		}
	}
	return 0;
}

int isItemCoordinate(int y, int x)
{
	for(int i = 0; i < numItems; ++i)
	{
		if(itemY[i] == y && itemX[i] == x)
			return 1;
	}
	return 0;
}

int isOrbCoordinate(int y, int x)
{
	for(int i = 0; i < numOrbs; ++i)
	{
		if(orbY[i] == y && orbX[i] == x)
			return 1;
	}
	return 0;
}

int playerCollideItem()
{
	for(int i = 0; i < numItems; ++i)
	{
		if(itemY[i] == playerYCoordinate && itemX[i] == playerXCoordinate)
		{
			itemY[i] = -2;
			itemX[i] = -2;
			return 1;
		}
	}
	return 0;
}

int playerCollideEnemy()
{
	for(int i = 0; i < numEnemies; ++i)
	{
		if(enemyY[i] == playerYCoordinate && enemyX[i] == playerXCoordinate)
		{
			enemyY[i] = -2;
			enemyX[i] = -2;
			return 1;
		}
	}
	return 0;
}


int playerCollideOrb()
{
	for(int i = 0; i < numEnemies; ++i)
	{
		if(orbY[i] == playerYCoordinate && orbX[i] == playerXCoordinate)
		{
			orbY[i] = -2;
			orbX[i] = -2;
			return 1;
		}
	}
	return 0;
}

void drawBoard()
{
	for(int i = -1; i < height + 1; ++i)
	{
		for(int j = -1; j < width + 1; ++j)
		{
			if(i == -1 || i == height || j == -1 || j == width)
				printf("*");
			else if(i == playerYCoordinate && j == playerXCoordinate)
			{
				if(isPowered)
					printf("%c", poweredIcon);
				else
					printf("%c", playerIcon);
			}
			else if(isBuildingCoordinate(i, j) == 1)
				printf("-");
			else if(isBuildingCoordinate(i, j) == 2)
				printf("&");
			else if(isEnemyCoordinate(i, j))
				printf("X");
			else if(isItemCoordinate(i, j))
				printf("$");
			else if(isOrbCoordinate(i, j))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}


}

int playGame(const char* filename)
{
	char input;
	int invalidInput = 1;
	getInput(filename);
	while(1)
	{
		printf("Score: %d\n", score);
		printf("Items remaining: %d\n", itemsRemaining);
		drawBoard();

		while(invalidInput)
		{
			printf("Enter input: ");
			scanf(" %c", &input);
			if(input == quitKey || input == leftKey || input == rightKey || input == upKey || input == downKey)
					invalidInput = 0;
			else
				printf("Invalid input.\n");
		}

		if(input == quitKey)
		{
			printf("You have quit.\nFinal score: %d\n", score);
			break;
		}else if(input == leftKey)
		{
			if(playerXCoordinate - 1 > -1 && !isBuildingCoordinate(playerYCoordinate, playerXCoordinate-1))
			{
				playerXCoordinate -= 1;
			}	
		}else if(input == rightKey)
		{
			if(playerXCoordinate + 1 < width && !isBuildingCoordinate(playerYCoordinate, playerXCoordinate+1))
			{
				playerXCoordinate += 1;
			}
		}else if(input == upKey)
		{
			if(playerYCoordinate - 1 > -1 && !isBuildingCoordinate(playerYCoordinate-1,playerXCoordinate))
			{
				playerYCoordinate -= 1;
			}
		}else if(input == downKey)
		{
			if(playerYCoordinate + 1 < height && !isBuildingCoordinate(playerYCoordinate+1,playerXCoordinate))
			{
				playerYCoordinate += 1;
			}
		}
		powerTurns -= 1;

		if(powerTurns == 0)
			isPowered = 0;

		if(playerCollideOrb())
		{
			isPowered = 1;
			powerTurns = 7;
		}else if(playerCollideItem())
		{
			score += 1;
			itemsRemaining -= 1;
		}else if(playerCollideEnemy())
		{
			if(!isPowered)
			{
				playerIcon = '@';
				printf("Score: %d\nItems remaining: %d\n",score,itemsRemaining);
				drawBoard();
				printf("You have died.\nFinal score: %d\n", score);
				break;
			}else
			{
				score += 1;
			}
		}

		if(itemsRemaining == 0)
		{
			printf("Congratulations! You have won.\nFinal score: %d\n", score);
			break;
		}

		invalidInput = 1;

	}	

	freeAllArrays();
	//once game ends deallocate the arrays
	return 1;
}
	
	