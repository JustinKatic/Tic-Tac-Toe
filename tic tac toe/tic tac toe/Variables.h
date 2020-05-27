#pragma once
#include <iostream>
using namespace std;

bool gameOver = false;
int numberOfTurns = 0;
//player characters
struct Player
{
	char Player1 = 'X';
	char Player2 = 'O';
};
//bool to check players turn
bool playerTurn = true;

//initialising grid
char grid[3][3] =
{
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
};

