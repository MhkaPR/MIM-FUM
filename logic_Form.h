#pragma once
#include "time.h"
#include "stdlib.h"
#include "stdio.h"
enum Cards
{
	CloseDoor=1,
	Coefficient,
	Limitation,
	AgainDice,
};
enum Abilitys
{
	Zero,
	Carridor,
	LuckyHome,
};
int DiceRand()
{
	int x;
	srand(time(0));
	x=rand()%6;
	return x;
}
unsigned short int Board[81];
int p1,p2;
void Game(short int turn)
{
	int Dice;
	//switch (Dice)
	//{
	//case 0: Move = -3; break;
	//case 1: Move = -2; break;
	//case 2: Move = -1; break;
	//case 3: Move = 1; break;
	//case 4: Move = 2; break;
	//case 5: Move = 3; break;
	//}

}
//Hello Mahdi