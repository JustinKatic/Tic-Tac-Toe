#include <iostream>
#include "Variables.h"

Player player;

//checks elements in array and if all 3 conditions are correct return true
bool WinSpots(int col0, int row0, int col1, int row1, int col2, int row2)
{
	if (grid[col0][row0] == player.Player1 && grid[col1][row1] == player.Player1 && grid[col2][row2] == player.Player1)
	{
		return true;
	}
	else if (grid[col0][row0] == player.Player2 && grid[col1][row1] == player.Player2 && grid[col2][row2] == player.Player2)
	{
		return true;
	}
	return false;
}

//checks each of the possible win conditions and if any returned true cout which player as won and call gameover to exit loop
bool WinConditions()
{
	// row win spaces	
	if (WinSpots(0, 0, 0, 1, 0, 2) || WinSpots(1, 0, 1, 1, 1, 2) || WinSpots(2, 0, 2, 1, 2, 2) ||
		//column win spaces
		WinSpots(0, 0, 1, 0, 2, 0) || WinSpots(0, 1, 1, 1, 2, 1) || WinSpots(0, 2, 1, 2, 2, 2) ||
		//diagonal win spaces
		WinSpots(0, 0, 1, 1, 2, 2) || WinSpots(0, 2, 1, 1, 2, 0) == true)
	{
		if (playerTurn == true)
		{
			cout << "Player X Wins";
		}
		else
		{
			cout << "Player O Wins";
		}
		gameOver = true;
	}
	return false;
}

//draws current Gameboard
void DrawGameBoard()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << grid[row][col] << "|";
		}
		cout << endl;
	}
}

//gets users input and checks if any of the elements in array are the same as the users choice if true replace that element in array with players 'X' or 'O'
void UserInput(char WhichPlayer)
{
	bool correctChoice = false;
	char userChoice;
	if (playerTurn == true)
	{
		WhichPlayer = player.Player1;
	}
	else
	{
		WhichPlayer = player.Player2;
	}
	cin >> userChoice;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (userChoice == grid[row][col])
			{
				grid[row][col] = WhichPlayer;
				correctChoice = true;
			}
			if (correctChoice == true)
			{
				break;
			}
		}
		cout << endl;
	}
	system("cls");
	cout << endl; cout << endl;
	DrawGameBoard();
	if (correctChoice == false)
	{
		cout << "incorrect input please enter valid position: " << endl;
		UserInput(player.Player1);
	}
}

int main()
{
	cout << endl; cout << endl;
	DrawGameBoard();
	//game loop
	while (!gameOver)
	{
		//gets users input
		UserInput(player.Player1);
		//checks if either play has won
		WinConditions();
		//changes the players turn to whoevers turn it wasnt before
		playerTurn = !playerTurn;
	}
}


