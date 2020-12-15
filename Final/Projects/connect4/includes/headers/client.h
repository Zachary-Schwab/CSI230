/**
* @file client.h
* @brief creates a class to hold hte client
* @author Zachary Schwab
* @assignment Final
* @date 12/14/2020
* @credits https://github.com/yourWaifu/sleepy-discord
*/

#pragma once 

#include "sleepy_discord/sleepy_discord.h"

#include "../headers/connect4.h"

using namespace std;
//runs the bots main functions and hooks into the SleepyDiscord library
class MyClientClass : public SleepyDiscord::DiscordClient
{
public:
	Connect4 game;
	using SleepyDiscord::DiscordClient::DiscordClient;
	void onMessage(SleepyDiscord::Message message) override;
	string makeMove(int col, string username);
};