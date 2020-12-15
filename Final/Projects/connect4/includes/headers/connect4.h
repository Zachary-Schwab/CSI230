/**
* @file connect4.h
* @brief creates the game board as and manages it
* @author Zachary Schwab
* @assignment Final
* @date 12/14/2020
*/

#pragma once 

#include "constants.h"
#include <string>
using namespace std;

class Connect4
{
public:
	string PrintBoard();
	bool DropPiece(int);
	string ColorTurn();
	void EndTurn();

	string CheckForWin();
	string TieCheck();

	void Clear();
	string player1Name = "";
	string player2Name = "";
	string activePlayer = player1Name;
	bool started = false;
private:
	bool VertCheckWin(int, int);
	bool HorizCheckWin(int);
	bool LtRDiagCheckWin(int, int);
	bool RtLDiagCheckWin(int, int);

	pair<int,int> lastPlayedPiece;
	string currentPiece = "r";
	string board [ROW_COUNT][COL_COUNT] = 
	{
		{"w","w","w","w","w","w","w"},
		{"w","w","w","w","w","w","w"},
		{"w","w","w","w","w","w","w"},
		{"w","w","w","w","w","w","w"},
		{"w","w","w","w","w","w","w"},
		{"w","w","w","w","w","w","w"}
	};
};
