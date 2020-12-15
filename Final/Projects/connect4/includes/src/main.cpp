/**
* @file main.cpp
* @brief creates a discord bot that hosts Connect 4 games
*
* @author Zachary Schwab
* @assignment Final
* @date 12/14/2020
* @credits https://github.com/yourWaifu/sleepy-discord
*/

#include "../headers/client.h"


int main() {
	MyClientClass client("Nzg2OTU1NDgzMzU3MjQ5NTY2.X9N7aA.-62SNUKaT5Q4ZeLoX5SYGVOkPlk", SleepyDiscord::USER_CONTROLED_THREADS);
	client.run();
}
