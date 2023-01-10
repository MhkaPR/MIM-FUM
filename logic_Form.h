#pragma once
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include <stdbool.h>
#define DOORCLOSED 0
#define COEF 1
#define LIMIT 2
#define DICEAGAIN 3

#define Direction 66
#define Player1PlaceFrist_X 355
#define Player1PlaceFrist_Y 630
//extern struct NUT
//{
//	int x;
//	int y;
//};

int DiceRand()
{
	int x;
	//srand(time(0));
	x = rand() % 6;
	return x;
}
int CardRand()
{
	int x;
	//srand(time(0));
	x = rand() % 4;
	return x;
}
void ConvertToDiceMIM(int* x)
{
	switch (*x)
	{
	case 0: *x = -3; break;
	case 1: *x = -2; break;
	case 2: *x = -1; break;
	case 3: *x = 1; break;
	case 4: *x = 2; break;
	case 5: *x = 3; break;
	};//convert to -3 +3
}
void CardPlacesRand(int ArrayCardsPlace[])
//daryaftmohre()
{
	int min = 0;
	for (int i = 0; i < 9; i++)
	{
		int cur = rand() % 9 + min;
		if (cur == 0 || cur == 80 || cur == 40)
		{
			i--;
			continue;
		}
		min += 9;
		ArrayCardsPlace[i] = cur;
	}

}
void CarridorPlacesRand(int ArrayCarridorsPlace[][2])
{
	int min = 0, cur;
	for (int i = 0; i < 8; i++)
	{
		cur = rand() % 9 + min;
		if (cur == 0 || cur == 80)
		{
			i--;
			continue;
		}
		if (cur > 35 && cur < 45)
		{
			i--;
			min += 9;
			continue;
		}
		min += 9;
		ArrayCarridorsPlace[i][0] = cur;
	}
	for (int i = 0; i < 8; i++)
	{
		if (!ArrayCarridorsPlace[i][1])
		{
			int j = rand() % 8;
			if (ArrayCarridorsPlace[j][1] || j == i)
			{
				i--;
				continue;
			}
			ArrayCarridorsPlace[i][1] = ArrayCarridorsPlace[j][0];
			ArrayCarridorsPlace[j][1] = ArrayCarridorsPlace[i][0];
		}
	}
}
int IsCarridorPlace(int* Position, int CarridorArray[][2])
{
	for (int i = 0; i < 8; i++)
	{
		if (*Position == CarridorArray[i][0])
		{
			*Position = CarridorArray[i][1];
			printf("??? 1");
			return 1;
		}
	}
	printf("??? 0");
	return 0;
}
int Is_Any_Card(const int ArrCard[])
{
	for (int i = 0; i < 4; i++)
	{
		if (ArrCard[i] != 0) return 1;
	}
	return 0;
}
int IsLuckyCardPlace(int Position, const int ArrayCardsPlace[])
{
	for (int i = 0; i < 9; i++)
	{
		if (Position == ArrayCardsPlace[i]) return 1;
	}
	return 0;
}
bool Is_DOORCLOSEDcard(const int CardsP1[])
{
	if (CardsP1[0]) return true;
	return false;
}
void MoveGraphic(const int Corresponding_number, int* x, int* y)
{
	switch (Corresponding_number)
	{
	case 0:
		*x = Player1PlaceFrist_X + 0 * Direction;
		*y = Player1PlaceFrist_Y + 0 * Direction;
		break;
	case 1:
		*x = Player1PlaceFrist_X + 1 * Direction;
		*y = Player1PlaceFrist_Y + 0 * Direction;
		break;
	case 2:
		*x = Player1PlaceFrist_X + 2 * Direction;
		*y = Player1PlaceFrist_Y + 0 * Direction;
		break;
	case 3:
		*x = Player1PlaceFrist_X + 3 * Direction;
		*y = Player1PlaceFrist_Y + 0 * Direction;
		break;
	case 4:
		*x = Player1PlaceFrist_X + 4 * Direction;
		*y = Player1PlaceFrist_Y + 0 * Direction;
		break;
	case 5:
		*x = Player1PlaceFrist_X + 5 * Direction;
		*y = Player1PlaceFrist_Y + 0 * Direction;
		break;
	case 6:
		*x = Player1PlaceFrist_X + 6 * Direction;
		*y = Player1PlaceFrist_Y + 0 * Direction;
		break;
	case 7:
		*x = Player1PlaceFrist_X + 7 * Direction;
		*y = Player1PlaceFrist_Y + 0 * Direction;

		break;
	case 8:
		*x = Player1PlaceFrist_X + 8 * Direction;
		*y = Player1PlaceFrist_Y + 0 * Direction;

		break;
	case 9:
		*x = Player1PlaceFrist_X + 8 * Direction;
		*y = Player1PlaceFrist_Y + -1 * Direction;

		break;
	case 10:
		*x = Player1PlaceFrist_X + 7 * Direction;
		*y = Player1PlaceFrist_Y + -1 * Direction;
		break;
	case 11:
		*x = Player1PlaceFrist_X + 6 * Direction;
		*y = Player1PlaceFrist_Y + -1 * Direction;
		break;
	case 12:
		*x = Player1PlaceFrist_X + 5 * Direction;
		*y = Player1PlaceFrist_Y + -1 * Direction;
		break;
	case 13:
		*x = Player1PlaceFrist_X + 4 * Direction;
		*y = Player1PlaceFrist_Y + -1 * Direction;
		break;
	case 14:
		*x = Player1PlaceFrist_X + 3 * Direction;
		*y = Player1PlaceFrist_Y + -1 * Direction;
		break;
	case 15:
		*x = Player1PlaceFrist_X + 2 * Direction;
		*y = Player1PlaceFrist_Y + -1 * Direction;
		break;
	case 16:
		*x = Player1PlaceFrist_X + 1 * Direction;
		*y = Player1PlaceFrist_Y + -1 * Direction;
		break;
	case 17:
		*x = Player1PlaceFrist_X + 0 * Direction;
		*y = Player1PlaceFrist_Y + -1 * Direction;

		break;
	case 18:
		*x = Player1PlaceFrist_X + 0 * Direction;
		*y = Player1PlaceFrist_Y + -2 * Direction;

		break;
	case 19:
		*x = Player1PlaceFrist_X + 1 * Direction;
		*y = Player1PlaceFrist_Y + -2 * Direction;

		break;
	case 20:
		*x = Player1PlaceFrist_X + 2 * Direction;
		*y = Player1PlaceFrist_Y + -2 * Direction;

		break;
	case 21:
		*x = Player1PlaceFrist_X + 3 * Direction;
		*y = Player1PlaceFrist_Y + -2 * Direction;

		break;
	case 22:
		*x = Player1PlaceFrist_X + 4 * Direction;
		*y = Player1PlaceFrist_Y + -2 * Direction;

		break;
	case 23:
		*x = Player1PlaceFrist_X + 5 * Direction;
		*y = Player1PlaceFrist_Y + -2 * Direction;

		break;
	case 24:
		*x = Player1PlaceFrist_X + 6 * Direction;
		*y = Player1PlaceFrist_Y + -2 * Direction;

		break;
	case 25:
		*x = Player1PlaceFrist_X + 7 * Direction;
		*y = Player1PlaceFrist_Y + -2 * Direction;

		break;
	case 26:
		*x = Player1PlaceFrist_X + 8 * Direction;
		*y = Player1PlaceFrist_Y + -2 * Direction;
		break;
	case 27:
		*x = Player1PlaceFrist_X + 8 * Direction;
		*y = Player1PlaceFrist_Y + -3 * Direction;

		break;

	case 28:
		*x = Player1PlaceFrist_X + 7 * Direction;
		*y = Player1PlaceFrist_Y + -3 * Direction;

		break;
	case 29:
		*x = Player1PlaceFrist_X + 6 * Direction;
		*y = Player1PlaceFrist_Y + -3 * Direction;

		break;
	case 30:
		*x = Player1PlaceFrist_X + 5 * Direction;
		*y = Player1PlaceFrist_Y + -3 * Direction;

		break;
	case 31:
		*x = Player1PlaceFrist_X + 4 * Direction;
		*y = Player1PlaceFrist_Y + -3 * Direction;

		break;
	case 32:
		*x = Player1PlaceFrist_X + 3 * Direction;
		*y = Player1PlaceFrist_Y + -3 * Direction;

		break;
	case 33:
		*x = Player1PlaceFrist_X + 2 * Direction;
		*y = Player1PlaceFrist_Y + -3 * Direction;

		break;
	case 34:
		*x = Player1PlaceFrist_X + 1 * Direction;
		*y = Player1PlaceFrist_Y + -3 * Direction;

		break;
	case 35:
		*x = Player1PlaceFrist_X + 0 * Direction;
		*y = Player1PlaceFrist_Y + -3 * Direction;

		break;
	case 36:
		*x = Player1PlaceFrist_X + 0 * Direction;
		*y = Player1PlaceFrist_Y + -4 * Direction;

		break;
	case 37:
		*x = Player1PlaceFrist_X + 1 * Direction;
		*y = Player1PlaceFrist_Y + -4 * Direction;

		break;
	case 38:
		*x = Player1PlaceFrist_X + 2 * Direction;
		*y = Player1PlaceFrist_Y + -4 * Direction;

		break;
	case 39:
		*x = Player1PlaceFrist_X + 3 * Direction;
		*y = Player1PlaceFrist_Y + -4 * Direction;

		break;
	case 40:
		*x = Player1PlaceFrist_X + 4 * Direction;
		*y = Player1PlaceFrist_Y + -4 * Direction;

		break;
	case 41:
		*x = Player1PlaceFrist_X + 5 * Direction;
		*y = Player1PlaceFrist_Y + -4 * Direction;

		break;
	case 42:
		*x = Player1PlaceFrist_X + 6 * Direction;
		*y = Player1PlaceFrist_Y + -4 * Direction;

		break;
	case 43:
		*x = Player1PlaceFrist_X + 7 * Direction;
		*y = Player1PlaceFrist_Y + -4 * Direction;

		break;
	case 44:
		*x = Player1PlaceFrist_X + 8 * Direction;
		*y = Player1PlaceFrist_Y + -4 * Direction;

		break;
	case 45:
		*x = Player1PlaceFrist_X + 8 * Direction;
		*y = Player1PlaceFrist_Y + -5 * Direction;

		break;
	case 46:
		*x = Player1PlaceFrist_X + 7 * Direction;
		*y = Player1PlaceFrist_Y + -5 * Direction;

		break;
	case 47:
		*x = Player1PlaceFrist_X + 6 * Direction;
		*y = Player1PlaceFrist_Y + -5 * Direction;

		break;
	case 48:
		*x = Player1PlaceFrist_X + 5 * Direction;
		*y = Player1PlaceFrist_Y + -5 * Direction;

		break;
	case 49:
		*x = Player1PlaceFrist_X + 4 * Direction;
		*y = Player1PlaceFrist_Y + -5 * Direction;

		break;
	case 50:
		*x = Player1PlaceFrist_X + 3 * Direction;
		*y = Player1PlaceFrist_Y + -5 * Direction;

		break;
	case 51:
		*x = Player1PlaceFrist_X + 2 * Direction;
		*y = Player1PlaceFrist_Y + -5 * Direction;

		break;
	case 52:
		*x = Player1PlaceFrist_X + 1 * Direction;
		*y = Player1PlaceFrist_Y + -5 * Direction;

		break;
	case 53:
		*x = Player1PlaceFrist_X + 0 * Direction;
		*y = Player1PlaceFrist_Y + -5 * Direction;

		break;
	case 54:
		*x = Player1PlaceFrist_X + 0 * Direction;
		*y = Player1PlaceFrist_Y + -6 * Direction;

		break;
	case 55:
		*x = Player1PlaceFrist_X + 1 * Direction;
		*y = Player1PlaceFrist_Y + -6 * Direction;

		break;
	case 56:
		*x = Player1PlaceFrist_X + 2 * Direction;
		*y = Player1PlaceFrist_Y + -6 * Direction;

		break;
	case 57:
		*x = Player1PlaceFrist_X + 3 * Direction;
		*y = Player1PlaceFrist_Y + -6 * Direction;

		break;
	case 58:
		*x = Player1PlaceFrist_X + 4 * Direction;
		*y = Player1PlaceFrist_Y + -6 * Direction;

		break;
	case 59:
		*x = Player1PlaceFrist_X + 5 * Direction;
		*y = Player1PlaceFrist_Y + -6 * Direction;

		break;
	case 60:
		*x = Player1PlaceFrist_X + 6 * Direction;
		*y = Player1PlaceFrist_Y + -6 * Direction;

		break;
	case 61:
		*x = Player1PlaceFrist_X + 7 * Direction;
		*y = Player1PlaceFrist_Y + -6 * Direction;

		break;
	case 62:
		*x = Player1PlaceFrist_X + 8 * Direction;
		*y = Player1PlaceFrist_Y + -6 * Direction;

		break;
	case 63:
		*x = Player1PlaceFrist_X + 8 * Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 64:
		*x = Player1PlaceFrist_X + 7* Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 65:
		*x = Player1PlaceFrist_X + 6* Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 66:
		*x = Player1PlaceFrist_X + 5* Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 67:
		*x = Player1PlaceFrist_X + 4* Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 68:
		*x = Player1PlaceFrist_X + 3* Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 69:
		*x = Player1PlaceFrist_X + 2* Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 70:
		*x = Player1PlaceFrist_X + 1 * Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 71:
		*x = Player1PlaceFrist_X + 0 * Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 72:
		*x = Player1PlaceFrist_X + 0 * Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 73:
		*x = Player1PlaceFrist_X + 1 * Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 74:
		*x = Player1PlaceFrist_X + 2* Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 75:
		*x = Player1PlaceFrist_X + 3* Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 76:
		*x = Player1PlaceFrist_X + 4* Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 77:
		*x = Player1PlaceFrist_X + 5* Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 78:
		*x = Player1PlaceFrist_X + 6* Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 79:
		*x = Player1PlaceFrist_X + 7* Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 80:
		*x = Player1PlaceFrist_X + 8 * Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	default:
		break;
	}
}
//Hello Mahdi
//aleik hello .


//Logic Branch added