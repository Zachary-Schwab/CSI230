/**
* @file client.cpp
* @brief manages messages that are sent from discord.
* @author Zachary Schwab
* @assignment Final
* @date 12/14/2020
* @credits https://github.com/yourWaifu/sleepy-discord
*/

#include "../headers/client.h"
#include "../headers/connect4.h"
//called when messages are sent in discord
void MyClientClass::onMessage(SleepyDiscord::Message message) 
{
	if (message.startsWith("%board"))
		sendMessage(message.channelID,  game.PrintBoard());
	if (message.startsWith("%join"))
	{
		if(game.player1Name == "")
		{
			game.player1Name = message.author.username;
			game.activePlayer = game.player1Name;
			sendMessage(message.channelID, "Your pieces are the: :red_circle:, " + message.author.username);
		}
		else if(game.player2Name == "")
		{
			game.player2Name = message.author.username;
			game.started = true;
			game.activePlayer = game.player1Name;
			sendMessage(message.channelID, "Your pieces are the: :blue_circle:");
		}
		else
		{
			sendMessage(message.channelID, "Two users are already playing");
		}
	}
	if (message.startsWith("%leave"))
	{
		if(game.player1Name == message.author.username)
		{
			game.started = false;
			game.player1Name = "";
			sendMessage(message.channelID, "Thanks for playing!");
		}
		else if(game.player2Name == message.author.username)
		{
			game.started = false;
			game.player2Name = "";
			sendMessage(message.channelID, "Thanks for playing!");
		}
		else
		{
			sendMessage(message.channelID, "You are not currently Playing");
		}
		game.Clear();
	}

	if (message.startsWith("%turn"))
		sendMessage(message.channelID,  game.ColorTurn());
	if (message.startsWith("%forfeit"))
	{
		if(message.author.username == game.activePlayer)
		{
			game.Clear();
			game.EndTurn();
			sendMessage(message.channelID, "\n " + game.ColorTurn() + " won!! :star2:\nIf your done playing dont forget to %leave \nTo reset the board do %reset");
		}
	}
	if (message.startsWith("%reset"))
	{
		if(message.author.username == game.player1Name || message.author.username == game.player2Name)
		{
			game.started = true;
			game.Clear();
			sendMessage(message.channelID, game.PrintBoard());
		}
	}
	if (message.startsWith("%1"))
	{
		sendMessage(message.channelID, makeMove(0, message.author.username));
	}
	if (message.startsWith("%2"))
	{
		sendMessage(message.channelID, makeMove(1, message.author.username));
	}
	if (message.startsWith("%3"))
	{
		sendMessage(message.channelID, makeMove(2, message.author.username));
	}
	if (message.startsWith("%4"))
	{
		sendMessage(message.channelID, makeMove(3, message.author.username));
	}
	if (message.startsWith("%5"))
	{
		sendMessage(message.channelID, makeMove(4, message.author.username));
	}
	if (message.startsWith("%6"))
	{
		sendMessage(message.channelID, makeMove(5, message.author.username));
	}
	if (message.startsWith("%7"))
	{
		sendMessage(message.channelID, makeMove(6, message.author.username));
	}
}

string MyClientClass::makeMove(int col, string username)
{
	string returnVal;
	if(game.started)
	{
		if(username == game.activePlayer)
		{
			if(game.DropPiece(col))
			{
				returnVal = game.PrintBoard();
				
				returnVal += game.CheckForWin();
				game.EndTurn();
			}
			else
			{
				returnVal = "Invalid move";
			}
		}
		else
		{
			returnVal = "Its not your turn, " + username;
		}
	}
	else
	{
		if(game.player1Name == "" || game.player2Name == "")
			returnVal = "A game has not started yet, %join to be one of the players";
		else
			returnVal = "%reset to start a new game, or %leave to leave";
	}
	return returnVal;
}
