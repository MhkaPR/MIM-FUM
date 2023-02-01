#pragma once
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
#include <stdbool.h>
#include <string.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"

#define DOORCLOSED 0
#define COEF 1
#define LIMIT 2
#define DICEAGAIN 3

#define SIMPLE -1
#define LIMIT_1_AND_COEF 211
#define LIMIT_2_AND_COEF 221
#define SIMPLE_AND_LIMIT_1 -121
#define SIMPLE_AND_LIMIT_2 -122

#define Direction 66
#define Player1PlaceFrist_X 355
#define Player1PlaceFrist_Y 630

#define Target 40
#define BestScore1 100000000
#define BetterScore2 10000000

#define Enemy1IsVeryNearToTarget 10
#define Enemy2IsVeryNearToTarget 10
#define Enemy1IsLittleNearToTarget 9
#define Enemy2IsLittleNearToTarget 9
#define Enemy1IsVeryNearToENEMY 7
#define Enemy2IsVeryNearToENEMY 7


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
void ConvertToDiceArray(int* x)
{
	switch (*x)
	{
	case -3: *x = 0; break;
	case -2: *x = 1; break;
	case -1: *x = 2; break;
	case 1: *x = 3; break;
	case 2: *x = 4; break;
	case 3: *x = 5; break;
	};//convert to 0 5
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
int IsCarridorPlace(int* Position, int CarridorArray[][2], bool Apply_Changes)
{
	for (int i = 0; i < 8; i++)
	{
		if (*Position == CarridorArray[i][0])
		{

			if (Apply_Changes) *Position = CarridorArray[i][1];

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
int MoveVertically(int x, int y, int arrayStateVerticall_UP[][2], int arrayStateVerticall_DOWN[][2], int* I_ARR, int Dice)
{
	for (int i = 0; i < 8; i++)
	{
		if (x == arrayStateVerticall_UP[i][0] && y == arrayStateVerticall_UP[i][1])
		{
			*I_ARR = i;
			if (Dice < 0)return 0;
			return 1;
		}
	}
	for (int i = 0; i < 8; i++)
		if (x == arrayStateVerticall_DOWN[i][0] && y == arrayStateVerticall_DOWN[i][1])
		{
			*I_ARR = i;
			if (Dice > 0)return 0;
			return -1;
		}
	return 0;
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
		*x = Player1PlaceFrist_X + 7 * Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 65:
		*x = Player1PlaceFrist_X + 6 * Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 66:
		*x = Player1PlaceFrist_X + 5 * Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 67:
		*x = Player1PlaceFrist_X + 4 * Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 68:
		*x = Player1PlaceFrist_X + 3 * Direction;
		*y = Player1PlaceFrist_Y + -7 * Direction;

		break;
	case 69:
		*x = Player1PlaceFrist_X + 2 * Direction;
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
		*x = Player1PlaceFrist_X + 2 * Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 75:
		*x = Player1PlaceFrist_X + 3 * Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 76:
		*x = Player1PlaceFrist_X + 4 * Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 77:
		*x = Player1PlaceFrist_X + 5 * Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 78:
		*x = Player1PlaceFrist_X + 6 * Direction;
		*y = Player1PlaceFrist_Y + -8 * Direction;

		break;
	case 79:
		*x = Player1PlaceFrist_X + 7 * Direction;
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
int KeepCenterNUMBER(int DistanceFromLeft[], int ArrayOfCriterion[], int Cards[][8], int Model)//array of MeYar
{
	int count;
	for (int i = 0; i < 4; i++)
	{
		if (Cards[i][Model] < 10)count = 0;
		else if (Cards[i][Model] < 100)count = 1;
		else count = 2;
		DistanceFromLeft[i] = ArrayOfCriterion[count];
	}
}

void AudioRun(ALLEGRO_AUDIO_STREAM* audio, char* FileName)
{

	audio = al_load_audio_stream(FileName, 2, 2048);
	al_attach_audio_stream_to_mixer(audio, al_get_default_mixer());
}
//------------------------



//ai----
float ScorePlaces(int Dice, int Position, const int Enemy_Positions[])
{
	long float SCORE = 0;
	if (Position + Dice == Target)return BestScore1;
	if (Position + Dice == Enemy_Positions[0])return BetterScore2;
	if (Position + Dice == Enemy_Positions[1])return BetterScore2;
	SCORE = (-1) * abs(pow(Dice, 3));
	if (abs(Position + Dice - Target) < abs(Position - Target))SCORE *= -1;
	return SCORE;
}
float CoefMove(int Dice, int Nut_Position, const int Enemy_Position[], const int ArrayCardsMe[][8], int charTemp)
{
	srand(time(0));
	int DiceCopy = Dice;
	int NutCopy = Nut_Position;
	DiceCopy *= 2;
	NutCopy += DiceCopy;
	if (ArrayCardsMe[COEF][charTemp] > 0)
	{

		if (Nut_Position > Target)
		{

			if (DiceCopy > 0)
			{

				if (NutCopy == Enemy_Position[0])return BetterScore2;
				if (NutCopy == Enemy_Position[1])return BetterScore2;
			}
			else
			{

				bool STOPCoef;
				if (NutCopy == Target)return BestScore1;//Best Score
				if (NutCopy == Enemy_Position[0])return BetterScore2;
				if (NutCopy == Enemy_Position[1])return BetterScore2;
				STOPCoef = rand() % 6;
				if (STOPCoef)
				{
					if (DiceCopy < -3)
					{
						printf("\n!!!COEF!!!\n");
						return 2 * ScorePlaces(Dice, Nut_Position, Enemy_Position);

					}
				}
			}
		}
		else
		{
			if (DiceCopy < 0)
			{
				if (NutCopy == Enemy_Position[0])return BetterScore2;
				if (NutCopy == Enemy_Position[1])return BetterScore2;
			}
			else
			{
				bool STOPCoef;
				if (NutCopy == Target)return BestScore1;//Best Score
				if (NutCopy == Enemy_Position[0])return BetterScore2;
				if (NutCopy == Enemy_Position[1])return BetterScore2;
				STOPCoef = rand() % 4;
				if (!STOPCoef)
					if (DiceCopy > +3)
						return ScorePlaces(Dice, Nut_Position, Enemy_Position);
			}
		}
	}
	else return ((-1) * BestScore1);
}
int Limitation(int Dice, int Nut_Position, const int Enemy_Position[], const int ArrayCardsMe[][8], int charTemp, const int ArrayCardsEnemy[][8],int charTempENEMY)
{
	Nut_Position += Dice;
	if (ArrayCardsMe[LIMIT][charTemp] > 0)
	{
		if ((abs(Enemy_Position[0] - Target) <= 3))
		{
			bool LIMIT_YES = rand() % 3;
			if (LIMIT_YES)
			{
				if (Enemy_Position[0] != Nut_Position + Dice)
					return Enemy1IsVeryNearToTarget;
			}
		}
		else if (abs(Enemy_Position[0] - Target) > 3 && abs(Enemy_Position[0] - Target) <= 6)
		{
			if (ArrayCardsEnemy[COEF][charTempENEMY] > 0)
			{
				bool LIMIT_NO = rand() % 2;
				if (!LIMIT_NO)
				{
					if (Enemy_Position[0] != Nut_Position + Dice)
						return Enemy1IsLittleNearToTarget;
				}
			}
			else
			{
				bool StopLimitation = rand() % 6;
				if (!StopLimitation)
				{
					if (Enemy_Position[0] != Nut_Position + Dice)
						return Enemy1IsLittleNearToTarget;
				}
			}
		}
		else if (abs(Enemy_Position[1] - Target) <= 3)
		{
			bool LIMIT_YES = rand() % 3;
			if (LIMIT_YES)
			{
				if (Enemy_Position[1] != Nut_Position + Dice)
					return Enemy2IsVeryNearToTarget;
			}
		}
		else if (abs(Enemy_Position[1] - Target) > 3 && abs(Enemy_Position[1] - Target) <= 6)
		{
			if (ArrayCardsEnemy[COEF][charTempENEMY] > 0)
			{
				bool LIMIT_NO = rand() % 2;
				if (!LIMIT_NO)
				{
					if (Enemy_Position[1] != Nut_Position + Dice)
						return Enemy2IsLittleNearToTarget;
				}
			}
			else
			{
				bool STOPLimitation = rand() % 6;
				if (!STOPLimitation)
				{
					if (Enemy_Position[1] != Nut_Position + Dice)
						return Enemy2IsLittleNearToTarget;
				}
			}
		}
		else if ((abs(Enemy_Position[0] - Nut_Position) <= 3))
		{
			bool STOPLimitation = rand() % 3;
			if (!STOPLimitation)
			{
				if (Enemy_Position[0] != Nut_Position + Dice)
					return Enemy1IsVeryNearToENEMY;
			}
		}
		else if ((abs(Enemy_Position[1] - Nut_Position) <= 3))
		{
			bool STOPLimitation = rand() % 3;
			if (!STOPLimitation)
			{
				if (Enemy_Position[1] != Nut_Position + Dice)
					return Enemy1IsVeryNearToENEMY;
			}
		}
	}

	return 0;

}
int CarridorMove(int Data[][2], int ArrayCardMe[][8],int charTemp, int Nut_position)
{
	if (ArrayCardMe[DOORCLOSED][charTemp] > 0)
	{
		if (Nut_position >= 27 || Nut_position <= 53)return false;
		else if (Nut_position <= 8 || Nut_position >= 72)return true;
		else
		{
			bool StopCarridor = rand() % 4;
			if (!StopCarridor)
			{
				for (int i = 0; i < 8; i++)
				{
					if (Nut_position == Data[i][0])
					{
						if (Data[i][1] == -1)return true;
						else
						{
							printf("checked Carridor\n");
							if (abs(Data[i][1] - Target) < abs(Data[i][0] - Target))return true;
							return false;
						}

					}
				}
			}
		}
	}
	return false;
}
int MaxScore(bool* CoefPalse, int Dice, int Nut_Position, const int Enemy_Position[], const int ArrayCardsMe[][8], int charTemp)
{
	bool UseCoef = false;
	long long int SCORE = ScorePlaces(Dice, Nut_Position, Enemy_Position);
	long long int SCORE_COEF = CoefMove(Dice, Nut_Position, Enemy_Position, ArrayCardsMe, charTemp);

	if (SCORE < SCORE_COEF)
	{
		*CoefPalse = true;
		return SCORE_COEF;
	}
	return SCORE;
	/*
	if (UseCoef)return COEF;
	return SIMPLE;*/
}
//---------------




//Logic Branch added