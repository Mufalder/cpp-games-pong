#include "Game.h"

int Game::score_1 = 0;
int Game::score_2 = 0;

void Game::incScore(bool player)
{
	if (player)
		score_2++;
	else score_1++;

	if (score_1 > 99 || score_2 > 99)
		score_1 = score_2 = 0;
}

std::string Game::scoreToString(int score)
{
	std::string result;
	result = std::to_string(score);
	if (score < 10)
		result = "0" + result;
	return result;
}

std::string Game::getScore(bool player)
{
	return player ? scoreToString(score_2) : scoreToString(score_1);
}