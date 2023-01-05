#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <stdbool.h>
#define DOORCLOSED 0
#define COEF 1
#define LIMIT 2
#define DICEAGAIN 3
int DiceRand()
{
	int x;
	//srand(time(0));
	x = rand() % 6;
	switch (x)
	{
	case 0: x = -3; break;
	case 1: x = -2; break;
	case 2: x = -1; break;
	case 3: x = 1; break;
	case 4: x = 2; break;
	case 5: x = 3; break;
	};//convert to -3 +3
	return x;
}
int CardRand()
{
	int x;
	//srand(time(0));
	x = rand() % 4;
	return x;
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
void CardPlacesRand(int ArrayCardsPlace[])
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
			if (ArrayCarridorsPlace[j][1] || j==i)
			{
				i--;
				continue;
			}
			ArrayCarridorsPlace[i][1] = ArrayCarridorsPlace[j][0];
			ArrayCarridorsPlace[j][1] = ArrayCarridorsPlace[i][0];
		}
	}
}
short int Q_Pleyer()
{
	int NUT_LOCK;
	printf("what Nut you want to Lock it:\n");
	printf("1-Nut1\n");
	printf("2-Nut2\n?: ");
	scanf_s("%d", &NUT_LOCK);
	return NUT_LOCK;
}
bool Is_DOORCLOSEDcard(const int CardsP1[])
{
	if (CardsP1[0]) return true;
	return false;
}
unsigned short int Board[81];
void main()
{

	//11-71
	//26-51
	//4-80
	//34-48
	int ArrayCardsPlace[9];
	int ArrayCarridorsPlace[9][2]={0};
	int CardsP1[4] = { 0 }, CardsP2[4] = { 0 };
	int Player1[2] = { 0 }, Player2[2] = { 80,80 };
	int Dice, count = 0, iP1 = 0, iP2 = 0;
	int CardChoosed;
	short int IsDoorClosed = 0;
	short int CoefDice = 1;
	short int Is_VETO = 0;
	short int sw_AgainDice = 0;
	short int playerSW = 1;
	short int IsLimitP1 = 0;
	short int IsLimitP2 = 0;


	srand(time(0));

	CardPlacesRand(ArrayCardsPlace);
	CarridorPlacesRand(ArrayCarridorsPlace);

	for (int i = 0; i < 9; i++)
	{
		printf("%d\n", ArrayCardsPlace[i] + 1);
	}
	printf("Carridors\n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", ArrayCarridorsPlace[i][j] + 1);
		}
		printf("\n");
	}
	scanf_s("%d", &Dice);
	while (1)
	{
		count++;
		if (playerSW % 2 == 1)//choose random a nut from P1
		{
			if (IsLimitP1 == 1)
			{
				iP1 = 0;
				printf("Nut1 is LOCKED\nP1 -->Nut 1\n");
			}
			else if (IsLimitP1 == 2)
			{
				iP1 = 1;
				printf("Nut2 is LOCKED\nP1 -->Nut 2\n");
			}
			else
			{
				printf("P1 -->Nut?:");
				scanf_s("%d", &iP1);

			}
			/*iP1 = rand() % 2;
			if (Player1[iP1] == 40)
			{
				iP1++;
				iP1 %= 2;
			}*/
		}
		else if (playerSW % 2 == 0)//choose random a nut from P2
		{

			if (IsLimitP2 == 1)
			{
				iP2 = 0;
				printf("Nut1 is LOCKED\nP2 -->Nut 1\n");
			}
			else if (IsLimitP2 == 2)
			{
				iP2 = 1;
				printf("Nut2 is LOCKED\nP2 -->Nut 2\n");
			}
			else
			{
				printf("P2 -->Nut?:");
				scanf_s("%d", &iP1);

			}

		}

		switch (playerSW % 2)
		{

		case 1://P1
			Dice = DiceRand();//random Dice
			printf("Dice:%d\n", Dice);
			for (int i = 0; i < 4; i++)
			{
				printf("%d ", CardsP1[i]);
			}
			printf("\n");
			//if (IsLuckyCardPlace(Player1[iP1], ArrayCardsPlace))//Be in the Lucy places
			//{
			//	CardChoosed = CardRand();
			//	CardsP1[CardChoosed]++;
			//	//print card
			//	switch (CardChoosed)
			//	{
			//	case DOORCLOSED:
			//		printf("a DOOR_CLOSED card added.\n");
			//		break;
			//	case COEF:
			//		printf("a COEF card added.\n");
			//		break;
			//	case LIMIT:
			//		printf("a LIMIT card added.\n");
			//		break;
			//	case DICEAGAIN:
			//		printf("a DICE_AGAIN card added.\n");
			//		break;
			//	}
			//}
			//if (Is_Any_Card(CardsP1))//check number of cards
			//{
			//	int sw;
			//	for (int i = 0; i < 4; i++)
			//	{
			//		printf("%d ", CardsP1[i]);
			//	}
			//	printf("Do you want to use your cards? 1-yes 0-no : ");
			//	scanf_s("%d", &sw);
			//	int cur;
			//	if (sw) {
			//		printf(">>>>>>>>>>>>>> Enter Code of card:\n");
			//		printf("DOOR_CLOSED 0\n");
			//		printf("COEF 1\n");
			//		printf("LIMIT 2\n");
			//		printf("DICE_AGAIN 3\n?: ");
			//		scanf_s("%d", &cur);
			//		printf("\n");
			//		//Imapct of cards
			//		switch (cur)
			//		{
			//		case DOORCLOSED:
			//			if (CardsP1[DOORCLOSED])
			//			{
			//				CardsP1[DOORCLOSED]--;
			//				IsDoorClosed = 1;
			//			}
			//			else printf("DOOR CLOSED is empty!\n");
			//			break;
			//		case COEF:
			//			if (CardsP1[COEF])
			//			{
			//				CardsP1[COEF]--;
			//				CoefDice = 2;
			//			}
			//			else printf("COEF is empty!\n");
			//			break;
			//		case LIMIT:
			//			if (CardsP1[LIMIT])
			//			{
			//				CardsP1[LIMIT]--;
			//				Is_VETO = 1;
			//			}
			//			else printf("LIMIT is empty!\n");
			//			break;
			//		case DICEAGAIN:
			//			if (CardsP1[DICEAGAIN])
			//			{
			//				CardsP1[DICEAGAIN]--;
			//				sw_AgainDice = 1;
			//			}
			//			else printf("DICEAGAIN is empty!\n");
			//			break;
			//		default:
			//			printf("Number ERORE!\n");
			//			break;
			//		}
			//		//------------------------
			//	}
			//}
			//Dice *= CoefDice;
			//Impact of COEF
			//Impact of AGAINDICE

			if ((Player1[iP1] + Dice) > -1 && (Player1[iP1] + Dice) < 81)//check for Being to period
			{
				if (IsLuckyCardPlace(Player1[iP1], ArrayCardsPlace))//Be in the Lucy places
				{
					CardChoosed = CardRand();
					CardsP1[CardChoosed]++;
					//print card
					switch (CardChoosed)
					{
					case DOORCLOSED:
						printf("a DOOR_CLOSED card added.\n");
						break;
					case COEF:
						printf("a COEF card added.\n");
						break;
					case LIMIT:
						printf("a LIMIT card added.\n");
						break;
					case DICEAGAIN:
						printf("a DICE_AGAIN card added.\n");
						break;
					}
				}
				if (Is_Any_Card(CardsP1))//check number of cards
				{
					int sw;
					for (int i = 0; i < 4; i++)
					{
						printf("%d ", CardsP1[i]);
					}
					printf("Do you want to use your cards? 1-yes 0-no : ");
					scanf_s("%d", &sw);
					int cur;
					if (sw) {
						printf(">>>>>>>>>>>>>> Enter Code of card:\n");
						printf("DOOR_CLOSED 0\n");
						printf("COEF 1\n");
						printf("LIMIT 2\n");
						printf("DICE_AGAIN 3\n?: ");
						scanf_s("%d", &cur);
						printf("\n");
						//Imapct of cards
						switch (cur)
						{
						case DOORCLOSED:
							if (CardsP1[DOORCLOSED])
							{
								CardsP1[DOORCLOSED]--;
								IsDoorClosed = 1;
							}
							else printf("DOOR CLOSED is empty!\n");
							break;
						case COEF:
							if (CardsP1[COEF])
							{
								CardsP1[COEF]--;
								CoefDice = 2;
							}
							else printf("COEF is empty!\n");
							break;
						case LIMIT:
							if (CardsP1[LIMIT])
							{
								CardsP1[LIMIT]--;
								IsLimitP2 = Q_Pleyer();
							}
							else printf("LIMIT is empty!\n");
							break;
						case DICEAGAIN:
							if (CardsP1[DICEAGAIN])
							{
								CardsP1[DICEAGAIN]--;
								sw_AgainDice = 1;
							}
							else printf("DICEAGAIN is empty!\n");
							break;
						default:
							printf("Number ERORE!\n");
							break;
						}
						//------------------------
					}
				}

				if (sw_AgainDice)
				{
					Dice = DiceRand();
					sw_AgainDice = 0;
					printf("The Dice was thrown again: %d\n", Dice);
				}
				else if (CoefDice == 2)
				{
					Dice *= CoefDice;
					printf("The Dice chenged:%d\n", Dice);
					CoefDice = 1;
				}
				Player1[iP1] += Dice;
				if (!IsDoorClosed)//check DOORCLOSED
				{
					if (IsCarridorPlace(&Player1[iP1], ArrayCarridorsPlace))
						if (Is_DOORCLOSEDcard(CardsP1))
						{
							int sw;
							printf("are you want to use youre DOOR CLOSED card?\n0No\n1-Yes\n");
							scanf_s("%d", &sw);
							if (!sw) for (int i = 0; i < 20; i++) printf("$\n");//in the Carridor
							else IsCarridorPlace(&Player1[iP1], ArrayCarridorsPlace);
							CardsP1[0]--;
						}
						else for (int i = 0; i < 20; i++) printf("$\n");//in the Carridor
				}
				else IsDoorClosed = 0;
				//Hiting
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
				//--------------------------
			}
			else printf("Over Board...\n");
			printf("Position of P1_1:%d\n", Player1[0] + 1);
			printf("Position of P1_2:%d\n", Player1[1] + 1);
			printf("Position of P2_1:%d\n", Player2[0] + 1);
			printf("Position of P2_2:%d\n", Player2[1] + 1);
			/*if (Is_VETO)
			{
				playerSW++;
				Is_VETO = 0;
			}*/
			break;
		case 0://P2
			Dice = DiceRand();//random Dice
			printf("Dice:%d\n", Dice);
			for (int i = 0; i < 4; i++)
			{
				printf("%d ", CardsP2[i]);
			}
			printf("\n");
			//if (IsLuckyCardPlace(Player2[iP2], ArrayCardsPlace))//Be in the Lucy places
			//{
			//	CardChoosed = CardRand();
			//	CardsP2[CardChoosed]++;
			//	//print card
			//	switch (CardChoosed)
			//	{
			//	case DOORCLOSED:
			//		printf("a DOOR_CLOSED card added.\n");
			//		break;
			//	case COEF:
			//		printf("a COEF card added.\n");
			//		break;
			//	case LIMIT:
			//		printf("a LIMIT card added.\n");
			//		break;
			//	case DICEAGAIN:
			//		printf("a DICE_AGAIN card added.\n");
			//		break;
			//	}
			//}
			//if (Is_Any_Card(CardsP2))//check number of cards
			//{
			//	int sw;
			//	for (int i = 0; i < 4; i++)
			//	{
			//		printf("%d ", CardsP2[i]);
			//	}
			//	printf("Do you want to use your cards? 1-yes 0-no :\n");
			//	scanf_s("%d", &sw);
			//	int cur;
			//	if (sw)
			//	{
			//		printf(">>>>>>>>>>>>>> Enter Code of card:\n");
			//		printf("DOOR_CLOSED 0\n");
			//		printf("COEF 1\n");
			//		printf("LIMIT 2\n");
			//		printf("DICE_AGAIN 3\n?: ");
			//		scanf_s("%d", &cur);
			//		printf("\n");
			//		//Imapct of cards
			//		switch (cur)
			//		{
			//		case DOORCLOSED:
			//			if (CardsP2[DOORCLOSED])
			//			{
			//				CardsP2[DOORCLOSED]--;
			//				IsDoorClosed = 1;
			//			}
			//			else printf("DOOR CLOSED is empty!\n");
			//			break;
			//		case COEF:
			//			if (CardsP2[COEF])
			//			{
			//				CardsP2[COEF]--;
			//				CoefDice = 2;
			//			}
			//			else printf("COEF is empty!\n");
			//			break;
			//		case LIMIT:
			//			if (CardsP2[LIMIT])
			//			{
			//				CardsP2[LIMIT]--;
			//				Is_VETO = 1;
			//			}
			//			else printf("LIMIT is empty!\n");
			//			break;
			//		case DICEAGAIN:
			//			if (CardsP2[DICEAGAIN])
			//			{
			//				CardsP2[DICEAGAIN]--;
			//				sw_AgainDice = 1;
			//			}
			//			else printf("DICEAGAIN is empty!\n");
			//			break;
			//		default:
			//			printf("Number ERORE!\n");
			//			break;
			//		}
			//		//---------------------
			//	}
			//}
			

			if ((Player2[iP2] + Dice) > -1 && (Player2[iP2] + Dice) < 81)//check for Being to period
			{
				Player2[iP2] += Dice;
				//coming card
				if (IsLuckyCardPlace(Player2[iP2], ArrayCardsPlace))//Be in the Lucy places
				{
					CardChoosed = CardRand();
					CardsP2[CardChoosed]++;
					//print card
					switch (CardChoosed)
					{
					case DOORCLOSED:
						printf("a DOOR_CLOSED card added.\n");
						break;
					case COEF:
						printf("a COEF card added.\n");
						break;
					case LIMIT:
						printf("a LIMIT card added.\n");
						break;
					case DICEAGAIN:
						printf("a DICE_AGAIN card added.\n");
						break;
					}
				}
				if (Is_Any_Card(CardsP2))//check number of cards
				{
					int sw;
					for (int i = 0; i < 4; i++)
					{
						printf("%d ", CardsP2[i]);
					}
					printf("Do you want to use your cards? 1-yes 0-no :\n");
					scanf_s("%d", &sw);
					int cur;
					if (sw)
					{
						printf(">>>>>>>>>>>>>> Enter Code of card:\n");
						printf("DOOR_CLOSED 0\n");
						printf("COEF 1\n");
						printf("LIMIT 2\n");
						printf("DICE_AGAIN 3\n?: ");
						scanf_s("%d", &cur);
						printf("\n");
						//Imapct of cards
						switch (cur)
						{
						case DOORCLOSED:
							if (CardsP2[DOORCLOSED])
							{
								CardsP2[DOORCLOSED]--;
								IsDoorClosed = 1;
							}
							else printf("DOOR CLOSED is empty!\n");
							break;
						case COEF:
							if (CardsP2[COEF])
							{
								CardsP2[COEF]--;
								CoefDice = 2;
							}
							else printf("COEF is empty!\n");
							break;
						case LIMIT:
							if (CardsP2[LIMIT])
							{
								CardsP2[LIMIT]--;
								IsLimitP1 = Q_Pleyer();
							}
							else printf("LIMIT is empty!\n");
							break;
						case DICEAGAIN:
							if (CardsP2[DICEAGAIN])
							{
								CardsP2[DICEAGAIN]--;
								sw_AgainDice = 1;
							}
							else printf("DICEAGAIN is empty!\n");
							break;
						default:
							printf("Number ERORE!\n");
							break;
						}
						//---------------------
					}
				}
				
				if (sw_AgainDice)
				{
					Dice = DiceRand();
					sw_AgainDice = 0;
					printf("The Dice was thrown again: %d\n", Dice);
				}
				else if (CoefDice == 2)
				{
					Dice *= CoefDice;
					printf("The Dice chenged:%d\n", Dice);
					CoefDice = 1;
				}
				Player2[iP2] += Dice;
				//----------------------------------

				//check DOORCLOSED
				if (!IsDoorClosed)//check DOORCLOSED
				{
					if (IsCarridorPlace(&Player2[iP2], ArrayCarridorsPlace))
						if (Is_DOORCLOSEDcard(CardsP2))
						{
							int sw;
							printf("are you want to use youre DOOR CLOSED card?\n0No\n1-Yes\n");
							scanf_s("%d", &sw);
							if (!sw) for (int i = 0; i < 20; i++) printf("$\n");//in the Carridor
							else IsCarridorPlace(&Player2[iP2], ArrayCarridorsPlace);
							CardsP2[0]--;
						}
						else for (int i = 0; i < 20; i++) printf("$\n");//in the Carridor
				}
				else IsDoorClosed = 0;

				//Hitting
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
				//-------------------------

			}
			else printf("Over Board...\n");
			printf("Position of P1_1:%d\n", Player1[0] + 1);
			printf("Position of P1_2:%d\n", Player1[1] + 1);
			printf("Position of P2_1:%d\n", Player2[0] + 1);
			printf("Position of P2_2:%d\n", Player2[1] + 1);
			// if (Is_VETO)
			// {
			// 	playerSW++;
			// 	Is_VETO = 0;
			// }
			break;
		default:
			break;
		}
		//Woning...
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
		//-----------------------------
		playerSW++;
		playerSW %= 2;
	}
	printf("\n\n%d ...", count);
}