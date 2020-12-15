/**
* @file connect4.cpp
* @brief impliments the functions needed to run a connect 4 game
* @author Zachary Schwab
* @assignment Final
* @date 12/14/2020
*/

#include "../headers/connect4.h"
#include "../headers/constants.h"
//returns the board as a string of emojis
string Connect4::PrintBoard()
{
	string output = "";
	for (int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j++)
		{
			if(board[i][j] == "r")
				output += ":red_circle:";
			else if(board[i][j] == "b")
				output += ":blue_circle:";
			else if(board[i][j] == "w")
				output += ":white_circle:";
		}
		output += "\n";
	}
	output += "  1    2    3   4    5    6    7";
	return output;
}

//fills a circle by checking if the spot is white in the grid from bottom to top
bool Connect4::DropPiece(int col)
{
	bool placed = false;
	for(int i = ROW_COUNT-1; i >= 0; i--)
	{
		if(board[i][col] == "w")
		{
			board[i][col] = currentPiece;
			lastPlayedPiece.first = i;
			lastPlayedPiece.second = col;
			placed = true;
			break;
		}
	}
	return placed;
}

//swaps whos turn it is
void Connect4::EndTurn()
{
	if (currentPiece == "r")
	{
		currentPiece = "b";
		activePlayer = player2Name;
	}
	else
	{
		currentPiece = "r";
		activePlayer = player1Name;
	}
}

//returns as an emoji whos turn it is
string Connect4::ColorTurn()
{
	string returnVal = "";
	if (currentPiece == "r")
		returnVal = ":red_circle:";
	else
		returnVal = ":blue_circle:";
	return returnVal;
}

//calls the 4 specific win checkers and if those come back false checks for tie
string Connect4::CheckForWin()
{
	int row = lastPlayedPiece.first;
	int col = lastPlayedPiece.second;
	string returnVal = "";
	if (VertCheckWin(row, col))
	{
		returnVal = "\n " + ColorTurn() + " won!! :star2: VERT";
	}
	if (HorizCheckWin(row))
	{
		returnVal = "\n " + ColorTurn() + " won!! :star2: HOR";
	}
	if (LtRDiagCheckWin(row, col))
	{
		returnVal = "\n " + ColorTurn() + " won!! :star2: LtR";
	}
	if(RtLDiagCheckWin(row, col))
	{
		returnVal = "\n " + ColorTurn() + " won!! :star2: RtL";
	}
	if(returnVal == "")
		returnVal = TieCheck();
	if(returnVal != "")
	{
		returnVal += "\nIf your done playing dont forget to %leave \nTo reset the board do %reset";
		started = false;
	}
	return returnVal;
}
//checks if there are any vertical wins
bool Connect4::VertCheckWin(int row, int col)
{
	bool win = false;
	//if the piece is not placed high enough no reason to check for vertical wins
	if (row > 2)
		win = false;
	else
	{
		int count = 0;
		for(int i = row; i < ROW_COUNT; i++)
		{
			if(board[i][col] == currentPiece)
				count ++;
			if(board[i][col] != currentPiece)
				count = 0;
			if(count == 4)
				win = true;
		}
	}
	return win;
}
//checks the row that was just placed for horizontal win
bool Connect4::HorizCheckWin(int row)
{
	bool win = false;
	int count = 0;
	for(int i = 0; i < COL_COUNT; i++)
	{
		if(board[row][i] == currentPiece)
			count ++;
		if(board[row][i] != currentPiece)
			count = 0;
		if(count >= 4)
			win = true;
	}
	return win;	
}
//checks wins where the left side of the diagnal is higher than the right and if those are wins
bool Connect4::LtRDiagCheckWin(int row, int col)
{
        string diagonal [MIN_SIDE_SIZE];

        int maxRow = row;
        int maxCol = col;
		//leftmost position that the diagnal could be
        while (maxRow < 5 and maxCol < 6)
		{
            maxRow++;
            maxCol++;
		}
        
		int minRow = row;
        int minCol = col;

		//rightmost position that the diagnal could be
        while (minRow > 0 and minCol > 0)
		{
            minRow--;
            minCol--;
		}

		int currentRow = minRow;
		int currentCol = minCol;
		//add the whole diagnal to the diagonal array
		for(int i = 0; i < (maxRow-minRow + 1); i++)
		{
            diagonal[i] = board[currentRow][currentCol];
            currentRow++;
            currentCol++;
		}
		
		bool win = false;
		int count = 0;
		//iterate through the diagonal array and count number of the current turn piece in a row
        for(int j = 0; j < 6; j++)
		{
		if(diagonal[j] == currentPiece)
			count ++;
		if(diagonal[j] != currentPiece)
			count = 0;
		if(count == 4)
			win = true;
		}
		return win;
}
//checks wins where the right side of the diagnal is higher than the left and if those are wins
bool Connect4::RtLDiagCheckWin(int row, int col)
{
	string diagonal [MIN_SIDE_SIZE];

	int minRow = row;
	int maxCol = col;

	//leftmost position that the diagnal could be
	while (minRow > 0 && maxCol < 6)
	{
		minRow--;
		maxCol++;
	}

	int maxRow = row;
	int minCol = col;

	//rightmost position that the diagnal could be
	while (maxRow < 5 && minCol > 0)
	{
		maxRow++;
		minCol--;
	}

	int currentRow = minRow;
	int currentCol = maxCol;
	//add the whole diagnal to the diagonal array
	for(int i = 0; i < (maxRow-minRow+1); i++)
	{
		diagonal[i] = board[currentRow][currentCol];
		currentRow++;
		currentCol--;
	}

	bool win = false;
	int count = 0;
	//iterate through the diagonal array and count number of the current turn piece in a row
	for(int j = 0; j < 6; j++)
	{
	if(diagonal[j] == currentPiece)
		count ++;
	if(diagonal[j] != currentPiece)
		count = 0;
	if(count == 4)
		win = true;
	}
	return win;
}

//checks if the game has resulted in a tie
string Connect4::TieCheck()
{
	string returnVal = "\nIts a Tie!";
	for(int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j ++)
		{
			//if any pieces are white its not a tie yet
			if(board[i][j] == "w")
				returnVal = "";
		}
	}
	if(returnVal != "")
	{
		started = false;
	}
	return returnVal;
}

//resets the board
void Connect4::Clear()
{
	for(int i = 0; i < ROW_COUNT; i++)
	{
		for (int j = 0; j < COL_COUNT; j ++)
		{
			board[i][j] = "w";
		}
	}
}