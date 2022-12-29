#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int DiceRand()
{
	int x;
	//srand(time(0));
	x = rand() % 6;
	return x;
}
int IsCarridorPlace(int* Position)
{
	switch (*Position)
	{
	case 10: *Position = 70;
		return 1;
		break;
	case 70: *Position = 10;
		return 1;
		break;
	case 25:*Position = 50;
		return 1;
		break;
	case 50:*Position = 25;
		return 1;
		break;
	case 3:*Position = 79;
		return 1;
		break;
	case 79:*Position = 3;
		return 1;
		break;
	case 33:*Position = 47;
		return 1;
		break;
	case 47:*Position = 33;
		return 1;
		break;
	default:
		return 0;
		break;
	}
}
unsigned short int Board[81];
void main()
{
	//11-71
	//26-51
	//4-80
	//34-48
	Board[10] = 70;
	Board[70] = 10;

	Board[25] = 50;
	Board[50] = 25;

	Board[3] = 79;
	Board[79] = 3;

	Board[33] = 47;
	Board[47] = 33;
	int Dice, count = 0, iP1 = 0, iP2 = 0;
	short int playerSW = 1;
	srand(time(0));
	int Player1[2] = { 0 }, Player2[2] = { 80,80 };

	while (1)
	{
		count++;
		if (playerSW % 2 == 1)
		{
			printf("P1 -->");
			iP1 = rand() % 2;
			if (Player1[iP1] == 40)
			{
				iP1++;
				iP1 %= 2;
			}
			printf(" Nut:%d\n", iP1 + 1);

		}
		else if (playerSW % 2 == 0)
		{
			printf("P2 -->");
			iP2 = rand() % 2;
			if (Player2[iP2] == 40)
			{
				iP2++;
				iP2 %= 2;
			}
			printf(" Nut:%d\n", iP2 + 1);

		}
		Dice = DiceRand();
		switch (Dice)
		{
		case 0: Dice = -3; break;
		case 1: Dice = -2; break;
		case 2: Dice = -1; break;
		case 3: Dice = 1; break;
		case 4: Dice = 2; break;
		case 5: Dice = 3; break;
		}
		printf("Dice:%d\n", Dice);
		switch (playerSW % 2)
		{
		case 1:
			if ((Player1[iP1] + Dice) > -1 && (Player1[iP1] + Dice) < 81)
			{
				Player1[iP1] += Dice;
				if (IsCarridorPlace(&Player1[iP1])) for (int i = 0; i < 20; i++) printf("$\n");
				if ((Player1[iP1] == Player2[0]) && (Player2[0] != 40))
				{
					Player2[0] = 80;
					for (int i = 0; i < 10; i++)printf("\n\n*** P1 Hit P2 ***\n\n");
				}
				if ((Player1[iP1] == Player2[1]) && (Player2[1] != 40))
				{
					Player2[1] = 80;
					for (int i = 0; i < 10; i++)printf("\n\n*** P1 Hit P2 ***\n\n");
				}

			}
			else printf("Over Board...\n");
			printf("Position of P1_1:%d\n", Player1[0] + 1);
			printf("Position of P1_2:%d\n", Player1[1] + 1);
			printf("Position of P2_1:%d\n", Player2[0] + 1);
			printf("Position of P2_2:%d\n", Player2[1] + 1);
			break;
		case 0:
			if ((Player2[iP2] + Dice) > -1 && (Player2[iP2] + Dice) < 81)
			{
				Player2[iP2] += Dice;
				if (IsCarridorPlace(&Player2[iP2])) for (int i = 0; i < 20; i++) printf("$\n");
				if ((Player2[iP2] == Player1[0]) && (Player1[0] != 40))
				{
					Player1[0] = 0;
					for (int i = 0; i < 10; i++)printf("\n\n*** P2 Hit P1 ***\n\n");
				}
				if ((Player2[iP2] == Player1[1]) && (Player1[1] != 40))
				{
					Player1[1] = 0;
					for (int i = 0; i < 10; i++)printf("\n\n*** P2 Hit P1 ***\n\n");
				}
			}
			else printf("Over Board...\n");
			printf("Position of P1_1:%d\n", Player1[0] + 1);
			printf("Position of P1_2:%d\n", Player1[1] + 1);
			printf("Position of P2_1:%d\n", Player2[0] + 1);
			printf("Position of P2_2:%d\n", Player2[1] + 1);
			break;
		default:
			break;
		}
		if (Player1[0] == 40 && Player1[1] == 40)
		{
			printf("P1 Won.");
			break;
		}
		if (Player2[0] == 40 && Player2[1] == 40)
		{
			printf("P2 Won.");
			break;
		}
		playerSW++;

	}
	printf("\n\n%d ...", count);
}