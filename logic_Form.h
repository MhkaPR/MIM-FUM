#pragma once
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include <stdbool.h>
#define DOORCLOSED 0
#define COEF 1
#define LIMIT 2
#define DICEAGAIN 3
struct NUT
{
	int x;
	int y;
};
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
void ConvertToDiceMIM(int *x)
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
			return 1;
		}
	}
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
	if (Position == ArrayCardsPlace[0]) return 1;
	else if (Position == ArrayCardsPlace[1]) return 1;
	else if (Position == ArrayCardsPlace[2]) return 1;
	else if (Position == ArrayCardsPlace[3]) return 1;
	else if (Position == ArrayCardsPlace[4]) return 1;
	else if (Position == ArrayCardsPlace[5]) return 1;
	else if (Position == ArrayCardsPlace[6]) return 1;
	else if (Position == ArrayCardsPlace[7]) return 1;
	else if (Position == ArrayCardsPlace[8]) return 1;
	else return 0;
}
bool Is_DOORCLOSEDcard(const int CardsP1[])
{
	if (CardsP1[0]) return true;
	return false;
}
void MoveGraphic(int Corresponding_number,struct NUT *nut)
{
	switch (Corresponding_number)
	{
	case 0:	
		nut->x = 0;
		nut->y = 0;
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		break;
	case 19:
		break;
	case 20:
		break;
	case 21:
		break;
	case 22:
		break;
	case 23:
		break;
	case 24:
		break;
	case 25:
		break;
	case 26:
		break;
	case 27:
		break;
	case 28:
		break;
	case 29:
		break;
	case 30:
		break;
	case 31:
		break;
	case 32:
		break;
	case 33:
		break;
	case 34:
		break;
	case 35:
		break;
	case 36:
		break;
	case 37:
		break;
	case 38:
		break;
	case 39:
		break;
	case 40:
		break;
	case 41:
		break;
	case 42:
		break;
	case 43:
		break;
	case 44:
		break;
	case 45:
		break;
	case 46:
		break;
	case 47:
		break;
	case 48:
		break;
	case 49:
		break;
	case 50:
		break;
	case 51:
		break;
	case 52:
		break;
	case 53:
		break;
	case 54:
		break;
	case 55:
		break;
	case 56:
		break;
	case 57:
		break;
	case 58:
		break;
	case 59:
		break;
	case 60:
		break;
	case 61:
		break;
	case 62:
		break;
	case 63:
		break;
	case 64:
		break;
	case 65:
		break;
	case 66:
		break;
	case 67:
		break;
	case 68:
		break;
	case 69:
		break;
	case 70:
		break;
	case 71:
		break;
	case 72:
		break;
	case 73:
		break;
	case 74:
		break;
	case 75:
		break;
	case 76:
		break;
	case 77:
		break;
	case 78:
		break;
	case 79:
		break;
	case 80:
		break;
	default:
		break;
	}
}
//Hello Mahdi
//aleik hello